/*
 * sketch_maj.c
 * - random partition table
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "../HeavyHitterCommon.h"
#include "sketch_maj.hpp"

/*
 * calloc with error message
 */
static void* safe_calloc(size_t nmemb, size_t size, const char* name) {
	void* ret;
	ret = calloc(nmemb, size);
	if (ret == NULL) {
		fprintf(stderr, "ERR: cannot alloc %s\n", name);
		exit(-1);
	}
	return ret;
}

/*
 * hash function
 */
static unsigned int AwareHash(const char* data, unsigned int n) {
	unsigned int hash = 388650253;
	unsigned int scale = 388650319;
	unsigned int hardener  = 1176845762;
	while( n ) {
		hash *= scale;
		hash += *data++;
		n--;
	}
	return hash ^ hardener;
}

/*
 * mangle
 */
/*
static void mangle(const unsigned char* key, unsigned char* ret_key,
		int nbytes) {
	unsigned long long new_key = 0;
	int i;
	for (i=0; i<nbytes; ++i) {
		new_key |= key[nbytes-i-1] << (i * 8);
	}
	new_key = (new_key * 3054961753) & (0xffffffff);
	for (i=0; i<nbytes; ++i) {
		ret_key[i] = (new_key >> (i * 8)) & 0xff;
	}
}
*/

/*
 * unmangle
 */                                                           
/*
static void unmangle(const unsigned char* key, unsigned char* ret_key,       
		int nbytes) {                                         
	// 10001^-1 mod 2^32 = 3472992753                         
	// 1001^-1 mod 2^32 = 3054961753                          
	unsigned long long new_key = 0;                           
	int i;                                                    
	for (i=0; i<nbytes; ++i) {                                
		new_key |= key[i] << (i * 8);                         
	}                                                         
	new_key = (new_key * 1001) & (0xffffffff);                
	for (i=0; i<nbytes; ++i) {                                
		ret_key[nbytes-i-1] = (new_key >> (i * 8)) & 0xff;    
	}                                                         
}
*/

/*
 * Initialize the hh table
 */
sketch_maj_p_t sketch_maj_init(int w, int h, int l, int n, double thresh_abs, unsigned int tbl_id) {
	sketch_maj_p_t sketch_maj;

	// error checking
	if (n / 8 > 13 || n % 8 != 0) {		// maximum # of bits of a key = 104
		fprintf(stderr, "ERR: n too large or n not multiple of 8\n");
		exit(-1);
	}

	// safe calloc
	sketch_maj = (sketch_maj_p_t)safe_calloc(1, sizeof(sketch_maj_t), std::string("sketch_maj").c_str());
	//sketch_maj->T = (long long*)safe_calloc(h * w, sizeof(long long), std::string("tbl->T").c_str());
	sketch_maj->tbl = (dyn_tbl_p_t*)safe_calloc(h * w, sizeof(long long), std::string("tbl->tbl").c_str());
    for (int i=0; i<h*w; ++i) {
        sketch_maj->tbl[i] = dyn_tbl_init(l, n);
    }

	// set parameters
    sketch_maj->h = h;
	sketch_maj->w = w;
    sketch_maj->l = l;
    sketch_maj->size = h * w;
	sketch_maj->n = n;
    sketch_maj->tbl_id = tbl_id;
    sketch_maj->thresh_abs = thresh_abs;
    //sketch_maj->total = 0;

	// return
	return sketch_maj;
}

/*
 * Operate - return a random bucket
 */
unsigned int sketch_maj_find(sketch_maj_p_t tbl, const unsigned char* key, int start_bit,
		int end_bit, int row_no) {
	unsigned char key_str[50];		// assume n/8 + 4 <= 50
	unsigned int oper;
	char bit;
	unsigned int ret_bucket;

	int i;

	// set the key string
	memset(key_str, 0, sizeof(key_str));
	i = start_bit;		// start_bit == 0 in all cases
	while (i <= end_bit) {
		if (end_bit - i + 1 >= 8) {
			key_str[i/8] = key[i/8];	
			i += 8;
		} else {
			bit = (key[i/8] & (1 << (8 - ((i%8) + 1)))) > 0 ?  1 : 0;
			key_str[i/8] |= (bit << (8 - ((i%8) + 1)));
			i++;
		}
	}

	// set the operator and add it to key string
	//oper = part_no * tbl->[part_no] + array_no;
	oper = tbl->h * tbl->tbl_id + row_no;
	//oper = row_no;
	memcpy(key_str + tbl->n/8, &oper, sizeof(unsigned int));

	/*
	// hash
	MD5_CTX md5;
	unsigned char digest[16];
	MD5_Init(&md5);
	MD5_Update(&md5, key_str, tbl->n/8 + sizeof(unsigned int));
	MD5_Final(digest, &md5);
	memcpy(&ret_bucket, digest, sizeof(unsigned int));	// take 1st 4 bytes
	ret_bucket = (ret_bucket % tbl->K);
	*/

	ret_bucket = AwareHash((char*)key_str, 
			(unsigned int)(tbl->n/8 + sizeof(unsigned int))) % (tbl->w);

	// return
	return ret_bucket;
}


/*
 * Sequential hashign algorithm - encode keys (a.k.a. update step)
 */
void sketch_maj_update(sketch_maj_p_t tbl, unsigned char* key, long long val) {
	int j, k;

	// mangle
	// mangle(key, key_to_add, tbl->n/8);

	// add key/val to table
	for (j=0; j<tbl->h; ++j) {
		k = sketch_maj_find(tbl, key, 0, tbl->n - 1, j);
		//tbl->T[j*tbl->w+k] += val;
		dyn_tbl_update(tbl->tbl[j*tbl->w+k], key, val, tbl->thresh_abs);
	}
    //tbl->total += val;
}

/*
 * Copy the content from one hh-tbl to another (they should have same params)
 */
void sketch_maj_copy(sketch_maj_p_t tbl, sketch_maj_p_t ret_tbl) {

	if (ret_tbl == NULL) {
		fprintf(stderr, "ERR: ret_tbl in sketch_maj_copy() is NULL\n");
		return;
	}

	//memcpy(ret_tbl->T, tbl->T, tbl->size * sizeof(long long));
    for (int i=0; i<tbl->h*tbl->w; ++i) {
        dyn_tbl_copy(tbl->tbl[i], ret_tbl->tbl[i]);
    }
    //ret_tbl->total = tbl->total;
}

/*
 * reset the counters
 */
void sketch_maj_reset(sketch_maj_p_t sketch_maj) {
	//memset(sketch_maj->T, 0, sketch_maj->size * sizeof(long long)); 
    for (int i=0; i<sketch_maj->h*sketch_maj->w; ++i) {
        dyn_tbl_reset(sketch_maj->tbl[i]);
    }
    //sketch_maj->total = 0;
}

/*
 * Destroy
 */
void sketch_maj_destroy(sketch_maj_p_t sketch_maj) {
	//free(sketch_maj->T);
    for (int i=0; i<sketch_maj->size; ++i) {
        dyn_tbl_destroy(sketch_maj->tbl[i]);
    }
	free(sketch_maj->tbl);
	free(sketch_maj);
}

/*
 *
 * Write to a file without encoding
 * used for test
 * by qhuang 20130618
 *
 */
void sketch_maj_write_plaintext(sketch_maj_p_t tbl, const char* outfile) {
	FILE* fp; 
	int i, j;

	// open a file
	if ((fp = fopen(outfile, "w")) == NULL) {
		fprintf(stderr, "ERR: cannot open %s\n", outfile);
		exit(-1);
	}

	// write to a file (including n and bd???)
    fprintf(fp, "Worker: %u, length of key: %d\n", tbl->tbl_id, tbl->n);
	fprintf(fp, "# of hash row: %d\n", tbl->h);
    fprintf(fp, "# of buckets: %d\n", tbl->w);

    uint64_t key_int = 0x0102030405060708;
    unsigned char* key = (unsigned char*)&key_int;
    for (i=0; i<tbl->h; ++i) {
        unsigned int k = sketch_maj_find(tbl, key, 0, tbl->n - 1, i);
        fprintf(fp, "%u ", k);
    }
    fprintf(fp, "\n");

	for (i=0; i<tbl->h; ++i) {
		for (j=0; j<tbl->w; ++j) {
            //fprintf(fp, "%lld ", tbl->T[tbl->w*i + j]);
            unsigned int index = tbl->w*i + j;
            fprintf(fp, "%lld %lu, ", tbl->tbl[index]->total, tbl->tbl[index]->data.size());
		}
        fprintf(fp, "\n");
	}

	// close the file
	fclose(fp);
}

void sketch_maj_get_heavy_keys(sketch_maj_p_t sk, double thresh,
        myset& ret) {
    for (int i=0; i<sk->w*sk->h; ++i) {
        if (sk->tbl[i]->max_value >= thresh) {
            dyn_tbl_get_heavy_key(sk->tbl[i], thresh, ret);
        }
    }
}

long long sketch_maj_low_estimate(sketch_maj_p_t sk, dyn_tbl_key_t key) {
    long long ret = 0;
    for (int i=0; i<sk->h; ++i) {
		int k = sketch_maj_find(sk, key.key, 0, sk->n - 1, i);
        int index = i*sk->w+k;
        ret = MAX(ret, dyn_tbl_low_estimate(sk->tbl[index], key));
    }
    return ret;
} 

long long sketch_maj_up_estimate(sketch_maj_p_t sk, dyn_tbl_key_t key) {
    long long ret = 99999999999;
    for (int i=0; i<sk->h; ++i) {
		int k = sketch_maj_find(sk, key.key, 0, sk->n - 1, i);
        int index = i*sk->w+k;
        ret = MIN(ret, dyn_tbl_up_estimate(sk->tbl[index], key));
    }
    return ret;
} 

/*
unsigned int sketch_maj_find_cand(sketch_maj_p_t sk, sketch_maj_p_t sk_old, double thresh, unsigned char** cand_list, unsigned int MAX_CAND) {
    std::set<dyn_tbl_key_s> ret;
}
*/
