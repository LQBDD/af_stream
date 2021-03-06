/*
 ******************************************************************************
 版权所有 (C), 2008-2009, 华为技术有限公司
 ******************************************************************************
  文 件 名   : egnapingfwuserdefineapp.h
  版 本 号   : 初稿
  作    者   : EGN项目组
  生成日期   : 2013年01月10日
  最近修改   :
  功能描述   : 公共宏定义
  函数列表   :
  修改历史   :
  1.日    期   : 2013年01月10日
    作    者   : EGN项目组
    修改内容   : 创建文件

******************************************************************************/
/**@file  egnapingfwuserdefineapp.h
  *    公共宏定义
*******************************************************/
/**
 * @defgroup egn  EGN自定义规则模块的API
 */

#ifndef __EGN_API_NGFW_USER_DEFINE_APP_H__
#define __EGN_API_NGFW_USER_DEFINE_APP_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*MACRO< NGFW自定义应用名支持的最大长度 >*/
#define EGN_NGFW_UD_APP_NAME_LEN_MAX  32

/*MACRO< NGFW自定义应用支持的数据模型最大长度 >*/
#define EGN_NGFW_UD_MODEL_NAME_LEN_MAX  32

/*MACRO< NGFW自定义规则名支持的最大长度 >*/
#define EGN_NGFW_UD_RULE_NAME_LEN_MAX  32

/*MACRO< NGFW自定义规则描述支持的最大长度 >*/
#define EGN_NGFW_UD_RULE_DESC_LEN_MAX  128

/*MACRO< NGFW自定义应用描述支持的最大长度 >*/
#define EGN_NGFW_UD_APP_DESC_LEN_MAX  128

/*MACRO< NGFW自定义规则中支持的ip条件最大个数 >*/
#define EGN_NGFW_UD_RULE_IP_COND_MAX  4

/*MACRO< NGFW自定义规则中支持的port条件最大个数 >*/
#define EGN_NGFW_UD_RULE_PORT_COND_MAX  4

/*MACRO< NGFW自定义规则中支持的模式串条件的最小长度 >*/
#define EGN_NGFW_UD_RULE_PATTERN_COND_LEN_MIN  3

/*MACRO< NGFW自定义规则中支持的模式串条件的最大长度 >*/
#define EGN_NGFW_UD_RULE_PATTERN_COND_LEN_MAX  128

/* 支持的Ngfw自定义应用的AppId最小值 >*/
#define EGN_NGFW_UD_APP_ID_MIN  60000

/*ENUM< NGFW自定义规则的监测方向 >*/
typedef enum
{
    EGN_NGFW_CHECK_DIR_BEGIN = EGN_EN_INVALID,
    EGN_NGFW_CHECK_DIR_REQ   = 0,   /* 请求 */
    EGN_NGFW_CHECK_DIR_RES   = 1,   /* 响应 */
    EGN_NGFW_CHECK_DIR_BOTH  = 2,   /* 双向 */
    EGN_NGFW_CHECK_DIR_END,

    EGN_NGFW_CHECK_DIR_BOTTOM = EGN_EN_BUTT
}EGN_NGFW_CHECK_DIR_EN;

/*ENUM< NGFW自定义规则的识别模式 >*/
typedef enum
{
    EGN_NGFW_INSPECT_MOD_BEGIN = EGN_EN_INVALID,
    EGN_NGFW_INSPECT_MOD_NONE   = 0,   /* 未知，初始状态 */
    EGN_NGFW_INSPECT_MOD_PACKET = 1,   /* 包式识别 */
    EGN_NGFW_INSPECT_MOD_FLOW   = 2,   /* 流式识别 */
    EGN_NGFW_INSPECT_MOD_END,

    EGN_NGFW_INSPECT_MOD_BOTTOM = EGN_EN_BUTT
}EGN_NGFW_INSPECT_MOD_EN;

/*ENUM< NGFW自定义规则的模式串类型 >*/
typedef enum
{
    EGN_NGFW_PATTERN_TYPE_BEGIN = EGN_EN_INVALID,
    EGN_NGFW_PATTERN_TYPE_NONE  = 0,   /* 未知，初始状态 */
    EGN_NGFW_PATTERN_TYPE_STR   = 1,   /* 字符串 */
    EGN_NGFW_PATTERN_TYPE_PCRE  = 2,   /* 正则 */
    EGN_NGFW_PATTERN_TYPE_END,

    EGN_NGFW_PATTERN_TYPE_BOTTOM = EGN_EN_BUTT
}EGN_NGFW_PATTERN_TYPE_EN;

/*ENUM< Ngfw自定义应用的状态 >*/
typedef enum
{
    EGN_NGFW_APP_STATUS_BEGIN               = EGN_EN_INVALID,
    EGN_NGFW_APP_STATUS_INIT                = 0,   /* 初始化       */
    EGN_NGFW_APP_STATUS_MODIFIED_NOTACTIVED = 1,   /* 修改,未激活  */
    EGN_NGFW_APP_STATUS_DELETE_NOTACTIVED   = 2,   /* 删除, 未激活 */
    EGN_NGFW_APP_STATUS_ACTIVE              = 3,   /* 激活         */
    EGN_NGFW_APP_STATUS_END,
    EGN_NGFW_APP_STATUS_BOTTOM              = EGN_EN_BUTT
} EGN_NGFW_APP_STATUS_EN;

/*ENUM<Ngfw自定义应用的查询方式> */
typedef enum
{
    EGN_NGFW_APP_QUERY_MODEL_BEGIN           = EGN_EN_INVALID,
    EGN_NGFW_APP_QUERY_MODEL_ONLY_ACTIVED    = 0,   /* 只查询激活APP         */
    EGN_NGFW_APP_QUERY_MODEL_ONLY_NOTACTIVED = 1,   /* 查询未激活的APP       */
    EGN_NGFW_APP_QUERY_ALL                   = 2,   /* 查询激活和未激活的APP */
    EGN_NGFW_APP_QUERY_MODEL_END,
    EGN_NGFW_APP_QUERY_MODEL_BOTTOM          = EGN_EN_BUTT
} EGN_NGFW_APP_QUERY_MODEL_EN;

/*ENUM<应用属性字段类型 >*/
typedef enum
{
    EGN_NGFW_APP_ATTR_TYPE_BEGIN           = EGN_EN_INVALID,
    EGN_NGFW_APP_ATTR_TYPE_CATEGORY        = 0,   /* 子类类别   */
    EGN_NGFW_APP_ATTR_TYPE_DATAMODEL       = 1,   /* 数据模型   */
    EGN_NGFW_APP_ATTR_TYPE_RISK            = 2,   /* 风险等级   */
    EGN_NGFW_APP_ATTR_TYPE_DESC            = 3,   /* 中英文描述 */
    EGN_NGFW_APP_ATTR_TYPE_ALL             = 4,   /* 所有字段   */
    EGN_NGFW_APP_ATTR_TYPE_END,
    EGN_NGFW_APP_ATTR_TYPE_BOTTOM          = EGN_EN_BUTT
}EGN_NGFW_APP_ATTR_TYPE_EN;

/*ENUM< NGFW自定义规则中的成员类型，用于删除或修改 >*/
typedef enum
{
    EGN_NGFW_UD_RULE_CONTENT_TYPE_BEGIN         = EGN_EN_INVALID,
    EGN_NGFW_UD_RULE_CONTENT_TYPE_TRANS_TYPE    = 1,
    EGN_NGFW_UD_RULE_CONTENT_TYPE_IPV4          = 2,
    EGN_NGFW_UD_RULE_CONTENT_TYPE_IPV6          = 3,
    EGN_NGFW_UD_RULE_CONTENT_TYPE_PORT          = 4,
    EGN_NGFW_UD_RULE_CONTENT_TYPE_SIGNATURE     = 5,
    EGN_NGFW_UD_RULE_CONTENT_TYPE_DESC          = 6,
    EGN_NGFW_UD_RULE_CONTENT_TYPE_IPV4_ALL      = 7,
    EGN_NGFW_UD_RULE_CONTENT_TYPE_IPV6_ALL      = 8,
    EGN_NGFW_UD_RULE_CONTENT_TYPE_PORT_ALL      = 9,
    EGN_NGFW_UD_RULE_CONTENT_TYPE_ALL           = 10,
    EGN_NGFW_UD_RULE_CONTENT_TYPE_END,
    EGN_NGFW_UD_RULE_CONTENT_TYPE_BOTTOM        = EGN_EN_BUTT
}EGN_NGFW_UD_RULE_CONTENT_TYPE_EN;

/*STRUCT< NGFW自定义应用信息 >*/
typedef struct _EgnNgfwUDApp
{
    EGN_UINT32  ulAppId;                                     /* 应用ID */
    EGN_UINT16  usCategoryId;                                /* 大类ID */
    EGN_UINT16  usSubCategoryId;                             /* 小类ID */
    EGN_UINT16  usVfwId;                                     /* 虚拟防火墙ID */

    EGN_UINT16  usEnable:1;                                  /* 使能标识 */
    EGN_UINT16  usIsTransportSig:1;                          /* 是否承载应用，默认：NO */

    EGN_UINT16  usRiskValue:5;                               /* 风险等级 */
    EGN_UINT16  usRiskType:7;                                /* 风险类型 */

    EGN_UINT16  ucStatus:3;                                  /* 应用状态，激活、未激活 */
    EGN_UCHAR   aucReserved1[2];

    EGN_UCHAR   aucName[EGN_NGFW_UD_APP_NAME_LEN_MAX + 1];   /* 应用名 */
    EGN_UCHAR   aucDataModel[EGN_NGFW_UD_MODEL_NAME_LEN_MAX + 1];   /* 数据模型 */

    EGN_UCHAR   aucAppDesc[EGN_NGFW_UD_APP_DESC_LEN_MAX + 1]; /* APP描述 */
    EGN_UCHAR   aucReserved2[1];

#ifdef EGN_64
    EGN_UCHAR   aucReserved3[4];
#endif
} EgnNgfwUDApp;

/*STRUCT< NGFW自定义应用信息 >*/
typedef struct _EgnNgfwUDAppS
{
    EgnNgfwUDApp stNotActivedApp;    /* 未激活的App */
    EgnNgfwUDApp stActivedApp;       /* 已激活的App */
}EgnNgfwUDAppS;

/*STRUCT< NGFW自定义规则中的signature信息 >*/
typedef struct _EgnNgfwUDSignature
{
    EGN_UCHAR  ucPatternLen;    /* 字符串或正则长度，最小长度为EGN_NGFW_UD_RULE_PATTERN_COND_LEN_MIN, 最大长度为EGN_NGFW_UD_RULE_PATTERN_COND_LEN_MAX */
    EGN_UCHAR  ucMode;          /* 识别模式，包识别、流识别、模式不定，见EGN_NGFW_INSPECT_MOD_EN */
    EGN_UCHAR  ucDir;           /* 模式串的监测方向，对流式识别有效，请求、响应、请求或响应，见EGN_NGFW_CHECK_DIR_EN */
    EGN_UCHAR  ucPatternType;   /* 字符串还是正则，见EGN_NGFW_PATTERN_TYPE_EN */
#ifdef EGN_64
    EGN_UCHAR  aucReserved[4];  /* 8字节对齐保留 */
#endif
    EGN_UCHAR  aucPattern[EGN_NGFW_UD_RULE_PATTERN_COND_LEN_MAX]; /* 模式串，以ucPatternLen为长度 */
} EgnNgfwUDSignature;

/*ENUM< 某条NGFW自定义规则的传输类型定义 >*/
typedef enum
{
    EGN_NGFW_TRANS_TYPE_BEGIN = EGN_EN_INVALID,
    EGN_NGFW_TRANS_TYPE_ANY   = 0X0,    /* 未指定类型，TCP或UDP */
    EGN_NGFW_TRANS_TYPE_TCP   = 0x6,    /* TCP  类型 */
    EGN_NGFW_TRANS_TYPE_UDP   = 0x11,   /* UDP  类型 */
    EGN_NGFW_TRANS_TYPE_END,

    EGN_NGFW_TRANS_TYPE_BOTTOM = EGN_EN_BUTT
}EGN_NGFW_TRANS_TYPE_EN;

/*ENUM< NGFW自定义规则的风险等级定义 >*/
typedef enum
{
    EGN_NGFW_APP_RISK_TYPE_VALUE_BEGIN           =  EGN_EN_INVALID,
    EGN_NGFW_APP_RISK_TYPE_VALUE_UNKNOWN         =  0x0000U,
    EGN_NGFW_APP_RISK_TYPE_VALUE_EXPLOITABLE     =  0x0001U,
    EGN_NGFW_APP_RISK_TYPE_VALUE_MAL_VEHICLE     =  0x0002U,
    EGN_NGFW_APP_RISK_TYPE_VALUE_PROD_LOSS       =  0x0004U,
    EGN_NGFW_APP_RISK_TYPE_VALUE_DATA_LEAK       =  0x0008U,
    EGN_NGFW_APP_RISK_TYPE_VALUE_BANDWIDTH       =  0x0010U,
    EGN_NGFW_APP_RISK_TYPE_VALUE_EVASIVE         =  0x0020U,
    EGN_NGFW_APP_RISK_TYPE_VALUE_TUNNELING       =  0x0040U,
    EGN_NGFW_APP_RISK_TYPE_VALUE_END,
    EGN_NGFW_APP_RISK_TYPE_VALUE_BOTTOM          = EGN_EN_BUTT
}EGN_NGFW_APP_RISK_TYPE_VALUE_EN;

/*STRUCT< NGFW自定义规则信息 >*/
typedef struct _EgnNgfwUDRule
{
    EGN_UCHAR  aucName[EGN_NGFW_UD_RULE_NAME_LEN_MAX + 4];    /* 规则名称，有效长度为32，以\0作为结束符 */
    EGN_UINT32 ulAppID;           /* 应用ID */
    EGN_UINT32 ulRuleId;          /* 规则ID */
    EGN_UINT16 usVfwId;           /* 虚拟防火墙ID */
    EGN_UCHAR  ucTransType;       /* 传输层协议，对应EGN_NGFW_TRANS_TYPE_EN */
    EGN_UCHAR  ucDescLen;         /* 规则描述长度，最大长度为EGN_NGFW_UD_RULE_DESC_LEN_MAX */
    EGN_UCHAR  ucIPNum;           /* IP个数，最大个数为EGN_NGFW_UD_RULE_IP_COND_MAX */
    EGN_UCHAR  ucPortNum;         /* 端口个数，最大个数为EGN_NGFW_UD_RULE_PORT_COND_MAX */
    EGN_UCHAR  ucNeedAddPeerList; /* 是否必要关联下发，0不必要，1必要*/
    EGN_UCHAR  ucReserved;        /* 字节对齐 */
#ifdef EGN_64
    EGN_UCHAR  aucReserved2[4];   /* 字节对齐 */
#endif
    EgnNgfwUDSignature stSignature; /* signature信息 */
    EgnIpAddrCond      astIPCond[EGN_NGFW_UD_RULE_IP_COND_MAX];      /* ip条件列表 */
    EgnPortCond        astPortCond[EGN_NGFW_UD_RULE_PORT_COND_MAX];  /* 端口条件列表。注意:只能是目的端口 */
    EGN_UCHAR          aucDesc[EGN_NGFW_UD_RULE_DESC_LEN_MAX];       /* 描述，以ucDescLen为长度，最大长度为EGN_NGFW_UD_RULE_DESC_LEN_MAX */
} EgnNgfwUDRule;

/*******************************************************************************
*    Func Name: EgnApiNgfwUDAddApp
*      Purpose: 添加NGFW自定义应用
*  Description: 添加NGFW自定义应用，按照结构体方式添加自定义应用，待激活后才能生效。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能添加应用。
*        Input: NA
*        InOut: EgnNgfwUDApp  *pstNgfwUDApp:自定义应用结构体指针<非空>
*       Output: NA
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution: 1、EGN内部为自定义应用分配ID，通过修改参数里面的ulAppId带出，AppID范围:[0x10000000, 0x1FFFFFFF]
                2、支持的自定义应用最大数量 1024
                3、支持的自定义应用名的最大长度为39
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDAddApp
(
   INOUT     EgnNgfwUDApp  *pstNgfwUDApp
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDGetAppState
*      Purpose: 查询NGFW自定义应用状态
*  Description: 根据AppId查询对应自定义应用的状态。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能查询应用状态。
*        Input: EGN_UINT32   ulAppId:   AppId
*        InOut:
*       Output: EGN_UINT16  *pusStatus: 要查询的应用的状态<非空>
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution: 应用状态值的含义请参见EGN_NGFW_APP_STATUS_EN
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDGetAppState
(
   IN   EGN_UINT32  ulAppId,
   OUT  EGN_UINT16 *pusStatus
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDGetAppIDByName
*      Purpose: 查询自定义应用的Appid
*  Description: 根据应用名以及虚拟防火墙ID查询对应自定义应用的AppId。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始查询
*        Input: EGN_UCHAR   *pucAppName:   自定义应用名
                EGN_UINT16   usVfwId:      虚拟防火墙ID
*        InOut: EGN_UINT32  *pulAppId:     查询结果:AppId
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN�
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDGetAppIDByName
(
    IN    EGN_UCHAR          *pucAppName,      /* 自定义应用名  */
    IN    EGN_UINT16          usVfwId,         /* 虚拟防火墙ID  */
    INOUT EGN_UINT32         *pulAppId         /* 查询结果AppId */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDGetCommitedAppIDByName
*      Purpose: 查询已生效的自定义应用的Appid
*  Description: 根据应用名以及虚拟防火墙ID查询已生效的自定义应用的AppId。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始查询。
*        Input:   EGN_UCHAR   *pucAppName:   自定义应用名<非空>
                  EGN_UINT16   usVfwId:      虚拟防火墙ID
*        InOut:   EGN_UINT32  *pulAppId:     查询结果:AppId<非空>
*       Output:
*       Return:   EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDGetCommitedAppIDByName
(
    IN    EGN_UCHAR          *pucAppName,      /* 自定义应用名  */
    IN    EGN_UINT16          usVfwId,         /* 虚拟防火墙ID  */
    INOUT EGN_UINT32         *pulAppId         /* 查询结果AppId */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDGetAppCount
*      Purpose: 查询自定义应用数量
*  Description: 根据虚拟防火墙ID查询未激活的自定义应用数量以及已激活的自定义应用数量。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始查询。
*        Input: EGN_UINT16   usVfwId:              虚拟防火墙ID
*       Output: EGN_UINT32  *pulAppNum:            所有App数量<非空>
                EGN_UINT32  *pulNotActivedAppNum:  未激活的App数量<非空>
                EGN_UINT32  *pulActivedAppNum:     已经激活的App数量<非空>
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDGetAppCount
(
    IN   EGN_UINT16          usVfwId,               /* 虚拟防火墙ID      */
    OUT  EGN_UINT32         *pulAppNum,             /* 所有App数量       */
    OUT  EGN_UINT32         *pulNotActivedAppNum,   /* 未激活的App数量   */
    OUT  EGN_UINT32         *pulActivedAppNum       /* 已经激活的App数量 */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDGetAppInfoByID
*      Purpose: 通过AppId查找自定义App信息
*  Description: 通过AppId查找自定义App信息
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNGFWUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始查询。
*        Input: EGN_UINT32    ulAppId:       AppId
*       Output: EgnNgfwUDApp  *pstAppInfo:    App信息<非空>
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDGetAppInfoByID
(
    IN     EGN_UINT32         ulAppId,      /* AppId   */
    INOUT  EgnNgfwUDApp      *pstAppInfo    /* App信息 */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDGetCommitedAppInfoByID
*      Purpose: 通过AppId查找激活状态下的自定义App信息
*  Description: 通过AppId查找激活状态下的自定义App信息。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNGFWUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始查询。
*        Input: EGN_UINT32    ulAppId:        AppId
*       Output: EgnNgfwUDApp  *pstAppInfo:    App信息<非空>
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDGetCommitedAppInfoByID
(
    IN     EGN_UINT32         ulAppId,      /* AppId */
    INOUT  EgnNgfwUDApp      *pstAppInfo    /* App信息 */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDGetAppInfoByName
*      Purpose: 通过应用名以及防火墙ID来查找自定义App信息
*  Description: 通过应用名以及防火墙ID来查找自定义App信息。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始查询。
*        Input: EGN_UCHAR    *pucAppName  :    自定义应用名<非空>
                EGN_UINT16    usVfwId     :    虚拟防火墙ID
*        InOut: EgnNgfwUDApp *pstAppInfo  :    App信息<非空>
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDGetAppInfoByName
(
    IN     EGN_UCHAR     *pucAppName,  /* 自定义应用名 */
    IN     EGN_UINT16     usVfwId,     /* 虚拟防火墙ID */
    INOUT  EgnNgfwUDApp  *pstAppInfo   /* App信息      */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDGetAllAppInfo
*      Purpose: 查找同一防火墙下的所有自定义应用信息
*  Description: 查找同一防火墙下的所有自定义应用信息，返回结果有未激活的App信息或者已激活的App信息。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始查询。
*        Input: EGN_UINT16                     usVfwId             :  虚拟防火墙ID
                EGN_UINT32                     ulQueryFlag         :  查询模式<EGN_NGFW_APP_QUERY_MODEL_EN>
*        InOut: EgnNgfwUDAppS                 *pstUserDefineAppS   :  App信息数组<非空>
                EGN_UINT32                    *pulItemNum          :  App信息数组大小<非空>
                EGN_UINT32                    *pulNotActivedAppNum :  未激活的App数量<非空>
                EGN_UINT32                    *pulActivedAppNum    :  已经激活的App数量<非空>
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDGetAllAppInfo
(
    IN    EGN_UINT16      usVfwId,              /* 虚拟防火墙ID */
    IN    EGN_UINT32      ulQueryFlag,          /* 查询模式，是查激活的或者未激活的或者两者都查 */
    INOUT EgnNgfwUDAppS  *pstUserDefineAppS,    /* App信息数组 */
    INOUT EGN_UINT32     *pulItemNum,           /* App信息数组大小 */
    INOUT EGN_UINT32     *pulNotActivedAppNum,  /* 未激活的App数量  */
    INOUT EGN_UINT32     *pulActivedAppNum      /* 已经激活的App数量 */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDModifyApp
*      Purpose: 修改自定义应用的信息(应用名除外)
*  Description: 修改完后，要激活才能生效
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始修改。
*        Input: EgnNgfwUDApp    *pstNgfwUDApp       :      要修改的应用<非空>
                EGN_UINT32      ulModifyAppType     :      修改应用的字段<对应EGN_NGFW_APP_ATTR_TYPE_EN枚举>
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDModifyApp
(
    IN    EgnNgfwUDApp   *pstNgfwUDApp,
    IN    EGN_UINT32      ulModifyAppType
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDModifyAppName
*      Purpose: 修改自定义应用名
*  Description: 修改自定义应用名，修改完后，要激活才能生效。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始修改。
*        Input: EGN_UINT32    ulAppId          :    要修改的应用的ID
                EGN_UCHAR    *pucNewAppName    :    应用名<非空>
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDModifyAppName
(
    IN     EGN_UINT32 ulAppId,         /* AppId */
    IN     EGN_UCHAR *pucNewAppName    /* 新的自定义应用名  */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDDelAllApps
*      Purpose: 删除同一防火墙ID下的所有自定义应用
*  Description: 删除同一防火墙ID下的所有自定义应用，删除后，要激活才能生效。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始删除。
*        Input: EGN_UINT16      usVfwId : 虚拟防火墙ID
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDDelAllApps
(
    IN     EGN_UINT16 usVfwId   /* 虚拟防火墙ID  */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDDeleteApp
*      Purpose: 删除一个自定义应用或者删除一个自定义应用的某个字段(修改为默认值)
*  Description: 删除一个自定义应用或者删除一个自定义应用的某个字段，删除后，要激活才能生效。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始删除。
*        Input: EgnNgfwUDApp   *pstNgfwUDApp        :      要删除的应用<非空>
                EGN_UINT32      ulDelAttrAppType    :      要删除应用的字段<对应EGN_NGFW_APP_ATTR_TYPE_EN枚举>
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDDeleteApp
(
    IN EGN_CONST EgnNgfwUDApp   *pstNgfwUDApp,
    IN           EGN_UINT32      ulDelAttrAppType
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDMngIncAppRefCount
*      Purpose: 增加自定义应用的引用计数(管理面使用)
*  Description: 增加自定义应用的引用计数。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始修改。
*        Input: EGN_UCHAR   *pucModuleName  : 调用模块名<非空>
                EGN_UINT32   ulAppId        : AppId
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDMngIncAppRefCount
(
    IN EGN_CONST EGN_UCHAR     *pucModuleName,    /* 调用模块名 */
    IN           EGN_UINT32     ulAppId           /* AppId */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDNgeIncAppRefCount
*      Purpose: 增加自定义应用的引用计数(NGE平面使用)
*  Description: 增加自定义应用的引用计数。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始修改
*        Input: EGN_UCHAR   *pucModuleName  : 调用模块名<非空>
                EGN_UINT32   ulAppId        : AppId
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDNgeIncAppRefCount
(
    IN EGN_CONST EGN_UCHAR  *pucModuleName,    /* 调用模块名 */
    IN           EGN_UINT32  ulAppId           /* AppId */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDMngDecAppRefCount
*      Purpose: 减少自定义应用的引用计数(管理平面使用)
*  Description: 减少自定义应用的引用计数。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始修改
*        Input: EGN_UCHAR   *pucModuleName :  调用模块名<非空>
                EGN_UINT32  ulAppId        :  AppId
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDMngDecAppRefCount
(
    IN EGN_CONST EGN_UCHAR  *pucModuleName,    /* 调用模块名 */
    IN           EGN_UINT32  ulAppId           /* AppId */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDNgeDecAppRefCount
*      Purpose: 减少自定义应用的引用计数(Nge平面使用)
*  Description: 减少自定义应用的引用计数。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始修改
*        Input: EGN_UCHAR   *pucModuleName  : 调用模块名<非空>
                EGN_UINT32  ulAppId         : AppId
*       Output:
*       Return:   EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDNgeDecAppRefCount
(
    IN EGN_CONST EGN_UCHAR     *pucModuleName,    /* 调用模块名 */
    IN           EGN_UINT32     ulAppId           /* AppId */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDNeedCommit
*      Purpose: 判断防火墙下是否有需要提交的自定义应用
*  Description: 根据虚拟防火墙ID，判断该防火墙下是否有需要提交的自定义应用。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始查询。
*        Input: EGN_UINT16   usVfwId      : 虚拟防火墙ID
*        InOut: EGN_BOOL    *bIsNeedCommit: 是否需要提交 <1:需要提交
                                                          0:不需要提交>
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDNeedCommit
(
    IN    EGN_UINT16  usVfwId,        /* 虚拟防火墙ID */
    INOUT EGN_BOOL   *pbIsNeedCommit  /* 是否需要提交 */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDNeedReCompile
*      Purpose: 判断所有防火墙下是否有需要重新编译的自定义应用
*  Description: 判断所有防火墙下是否有需要重新编译的自定义应用,当有新的自定义应用需要激活时，需要重新编译。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始查询。
*        InOut: EGN_BOOL  *pbIsNeedReCompile       是否需要编译<非空>
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDNeedReCompile
(
    INOUT EGN_BOOL *pbIsNeedReCompile  /* 是否需要编译 */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDSetCompileFlag
*      Purpose: 设置虚拟防火墙是否提交编译标志
*  Description: 设置虚拟防火墙是否提交编译标志。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能开始修改
*        Input: EGN_UCHAR  *paucCompFlagArray : 编译标记数组<非空>
                EGN_UINT32  ulArraySize       : 数组大小
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDSetCompileFlag
(
    IN  EGN_UCHAR  *paucCompFlagArray,  /* 编译标记数组 */
    IN  EGN_UINT32  ulArraySize         /* 数组大小 */
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDAddAppForceID
*      Purpose: 添加自定义应用信息，强制指定应用ID
*  Description: 按照结构体方式添加自定义应用，待激活后才能生效。该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能添加应用
                    该接口仅供系统重启过程中使用。
*        Input: EgnNgfwUDApp  *pstNgfwUDApp:自定义应用结构体指针<非空>
*        InOut: NA
*       Output: NA
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution: 1、AppID范围:[0x10000000, 0x1FFFFFFF]
                2、支持的自定义应用最大数量 1024
                3、支持的自定义应用名的最大长度为39
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDAddAppForceID
(
   IN EgnNgfwUDApp *pstNgfwUDApp
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDNgeActiveAllApps
*      Purpose: 激活所有自定义应用( 仅Nge面使用)
*  Description: 激活所有自定义应用。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能添加应用。
*        InOut: NA
*       Output: NA
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDNgeActiveAllApps
(
    EGN_VOID
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDMngActiveAllApps
*      Purpose: 激活所有自定义应用( 仅供管理面使用)
*  Description: 激活所有自定义应用
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能添加应用。
*        InOut: NA
*       Output: NA
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDMngActiveAllApps
(
    EGN_VOID
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDNgeActiveRule
*      Purpose: 激活所有自定义应用下的规则(Nge平面使用)
*  Description: 激活所有自定义应用下的规则。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能添加应用。
*        InOut: NA
*       Output: NA
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDNgeActiveRule
(
    EGN_VOID
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDMngActiveRule
*      Purpose: 激活所有自定义应用下的规则(管理平面使用)
*  Description: 激活所有自定义应用下的规则。
                该接口必须在初始化时开启NGFW自定义功能开关
                    （设置EgnInitCfgParam.bNgfwUserDefineSwitch为EGN_TRUE），且初始化成功后，才能添加应用。
*        InOut: NA
*       Output: NA
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDMngActiveRule
(
    EGN_VOID
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDAddRule
*      Purpose: 添加自定义规则
*  Description: 根据自定义应用ID，添加自定义规则。
                引擎初始化完成，且知识库明文信息导入后，才能调用。
*        Input: EGN_UINT32      ulAppId        :  待添加的自定义规则对应的自定义应用
                EgnNgfwUDRule  *pstUdRule      :  待添加的自定义规则<非空>
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDAddRule
(
    IN   EGN_UINT32     ulAppId,
    IN   EgnNgfwUDRule *pstUdRule
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDModifyRule
*      Purpose: 修改自定义规则
*  Description: 根据自定义应用ID、自定义规则、修改类型，修改相应的自定义规则。
                引擎初始化完成，且知识库明文信息导入后，才能调用。
*        Input: EGN_UINT32     ulAppId      : 待修改的自定义规则对应的自定义应用
                EgnNgfwUDRule  *pstUdRule   : 待修改的自定义规则<非空>
                EGN_UINT32     ulModifyType : 修改的类型<EGN_NGFW_UD_RULE_CONTENT_TYPE_EN>
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDModifyRule
(
    IN   EGN_UINT32     ulAppId,
    IN   EgnNgfwUDRule *pstUdRule,
    IN   EGN_UINT32     ulModifyType
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDModifyRuleName
*      Purpose: 修改规则名字
*  Description: 根据自定义应用ID、自定义规则的名字，修改自定义规则名为新的名字。
                引擎初始化完成，且知识库明文信息导入后，才能调用。
*        Input: EGN_UINT32     ulAppId    : 自定义应用ID
                EGN_UCHAR     *pucOldName : 待修改的自定义规则的名字<非空>
                EGN_UCHAR     *pucNewName : 修改后的自定义规则的名字<非空>
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDModifyRuleName
(
    IN   EGN_UINT32     ulAppId,
    IN   EGN_UCHAR     *pucOldName,
    IN   EGN_UCHAR     *pucNewName
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDDelAllRule
*      Purpose: 删除所有自定义规则
*  Description: 根据自定义应用ID，删除其对应的所有自定义规则。
                引擎初始化完成，且知识库明文信息导入后，才能调用。
*        Input: EGN_UINT32     ulAppId   :  自定义应用ID
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDDelAllRule
(
    IN   EGN_UINT32     ulAppId
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDDelOneRule
*      Purpose: 删除自定义规则
*  Description: 根据自定义应用ID，自定义规则，根据删除类型，删除其对应的自定义规则。
                引擎初始化完成，且知识库明文信息导入后，才能调用
*        Input: EGN_UINT32      ulAppId        :  待删除的自定义规则对应的自定义应用ID
*               EgnNgfwUDRule  *pstUdRule      :  待删除的自定义规则<非空>
*               EGN_UINT32      ulDeleteType   :  删除的类型<非空>
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDDelOneRule
(
    IN   EGN_UINT32     ulAppId,
    IN   EgnNgfwUDRule *pstUdRule,
    IN   EGN_UINT32     ulDeleteType
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDGetRuleNum
*      Purpose: 查找规则个数
*  Description: 根据自定义应用ID，查找对应的规则个数。
                引擎初始化完成，且知识库明文信息导入后，才能调用。
*        Input: EGN_UINT32     ulAppId       :    待查询的自定义应用ID
*       Output: EGN_UINT32    *pulRuleNum    :    自定义规则个数<非空>
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDGetRuleNum
(
    IN   EGN_UINT32     ulAppId,
    OUT  EGN_UINT32    *pulRuleNum
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDGetRuleInfo
*      Purpose: 查找规则信息和个数
*  Description: 根据自定义应用ID，查找对应的规则信息和个数。
                引擎初始化完成，且知识库明文信息导入后，才能调用。
*        Input: EGN_UINT32     ulAppId         :  待查询的自定义应用ID
*        Inout: EGN_UINT32    *pulRuleNum      :  自定义规则信息数组<非空>
*               EgnNgfwUDRule *pstUdRuleArray  :  自定义规则个数<非空>
*       Output:
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDGetRuleInfo
(
    IN     EGN_UINT32     ulAppId,
    INOUT  EGN_UINT32    *pulRuleNum,
    INOUT  EgnNgfwUDRule *pstUdRuleArray
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDGetOneRule
*      Purpose: 查找规则信息
*  Description: 根据自定义应用ID和规则名，查找对应的规则信息。
                引擎初始化完成，且知识库明文信息导入后，才能调用。
*        Input: EGN_UINT32      ulAppId       :   待查询的自定义应用ID
                EGN_UCHAR      *pucRuleName   :   自定义规则名<非空>
*       Output: EgnNgfwUDRule  *pstUdRule     :   自定义规则信息<非空>
*       Return: EGN_UINT32，成功或者失败的错误码，具体请参见EGN_RET_RESULT_EN。
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT32 EgnApiNgfwUDGetOneRule
(
    IN   EGN_UINT32     ulAppId,
    IN   EGN_UCHAR     *pucRuleName,
    OUT  EgnNgfwUDRule *pstUdRule
);

/*******************************************************************************
*    Func Name: EgnApiNgfwUDGetRiskValue
*      Purpose: 根据应用的风险，计算其风险级别。
*  Description: 该API接口会根据风险类别个数来计算出对应的风险等级，
                   风险类型个数目前最多是7个，即用户最多可以设置7个风险类别。
*               计算原则如下:
*               风险类型个数     风险等级
*               6 or 7       ->     5
*               5            ->     4
*               4 or 3       ->     3
*               2            ->     2
*               1 or 0       ->     1
*        Input: EGN_UINT16      usRiskType  :    风险类型，低7位有效，用低7位来标志7种不同的风险类型
*       Output:
*       Return: EGN_UINT16      对应的风险级别
*      Caution:
*        Since: V300R006C00SPC200
*    Reference: 无
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*------------------------------------------------------------------------------
*
*******************************************************************************/
EGN_UINT16 EgnApiNgfwUDGetRiskValue
(
    IN EGN_UINT16 usRiskType
);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __EGN_API_USER_DEFINE_RULE_H__ */

