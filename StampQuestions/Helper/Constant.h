//
//  Constant.h
//  LeonisSaleDemo
//
//  Created by leo-mobile-lily on 12/24/14.
//  Copyright (c) 2014 Leonis&Co. All rights reserved.
//

typedef enum {
    IphoneSoftWare_SDK7 = 1,
    IphoneSoftWare_SDK7_LESS = 2,
    IphoneSoftWare_SDK6 = 3,
    IphoneSoftWare_SDK5 = 4,
    IphoneSoftWare_SDK5_LESS = 5
}IphoneSoftWare;

typedef enum {
    PageType_Reset = 1,
    PageType_Offer = 2,
    PageType_Coupon = 3,
    PageType_Reco = 4,
    PageType_Stamp = 5,
    PageType_Push = 6,
    PageType_Reminder = 7,
    PageType_UserGroup = 8,
    PageType_UserNo = 9,
    PageType_UserStyle = 10,
    PageType_UserPhone = 11,
    PageType_Guide = 12,
    PageType_Site = 13,
    PageType_MyShop = 14,
    PageType_Home = 15,
    PageType_Campaign = 16,
    PageType_Campaign_Code = 17,
}PageType;

typedef enum {
    DataType_Shop = 20,
    Datatype_Categroy = 21,
//    DataType_Coupon_UseType = 22,
    DataType_Push = 23,
    DataType_Offer = 24,
    DataType_Coupon = 25,
    DataType_Reco = 26,
    DataType_Stamp = 27,
    DataType_Coupon_Shop = 28,
    DataType_Reco_Shop = 29,
    DataType_Stamp_Shop = 30,
    DataType_Coupon_Categroy = 31,
    DataType_Stamp_Categroy = 32,
    DataType_Coupon_Campaign = 33,
    DataType_Coupon_Campaign_Code = 34,
    DataType_Coupon_UseType_Code = 35,
    DataType_Coupon_UseType_Stamp = 36,
    DataType_Coupon_UnblockLimit = 37
    
}DataType;

typedef enum {
    MenuType_Shop = 2,
    MenuType_Category = 3,
    MenuType_UseType = 1
}MenuType;

typedef enum{
    SocialTypeTwitter = 0,
    SocialTypeFackbook = 1
}SocialType;

typedef enum{
    ReminderType_Reminder = 1,
    ReminderType_Calendar = 2
}ReminderType;

typedef enum {
//    LeoCouponStampType_Simple,
    LeoCouponStampType_StampCard,
    LeoCouponStampType_StampCoupon,
    LeoCouponStampType_None
}LeoCouponStampType;

typedef enum{
    LeoCouponStampUseType_Normal = 1,
    LeoCouponStampUseType_PopBack = 2,
    LeoCouponStampUseType_None = 3
}LeoCouponStampUseType;

typedef void (^CCAfter)();

#define INDEX_UNSELECTED -1
#define NUMBER_INVALID -1

#define TOPBAR_BTN_SIZE_HOME CGSizeMake(45, 30)
#define TOPBAR_BTN_SIZE_BACK CGSizeMake(40, 40)
#define TOPBAR_BTN_SIZE_CLOSE CGSizeMake(45,40)

/*ローカル保存キー*/
#define USERDEFALUTS_SETTING_PLATFORM_APP_KEY @"Setting_Leonis_Platform_Api_Key"
#define USERDEFALUTS_SETTING_PLATFORM_GROUP_PW @"Setting_Leonis_Platform_Group_PW"
#define USERDEFALUTS_SETTING_PLATFORM_GROUP @"Setting_Leonis_Platform_Group"
#define USERDEFALUTS_SETTING_USER_NO @"Setting_User_No"

/*Noti*/
#define NOTI_KEY_TOKEN_REFRESH @"Noti_Token_New"
#define NOTI_KEY_COUPON_REFRESH @"Noti_Coupon_Refresh"

/*表示文字*/
#define MOJI_BTN_OK NSLocalizedString(@"BTN_CC_0001", @"OK")
#define MOJI_BTN_CANCEL NSLocalizedString(@"BTN_CC_0002", @"キャンセル")
#define MOJI_BTN_CLOSE NSLocalizedString(@"BTN_CC_0003", @"閉じる")

//一覧タイプ表示
#define OFFER_TYPE_NAME_COUPON NSLocalizedString(@"LBL_OF_0090", @"クーポン")
#define OFFER_TYPE_NAME_RECOM NSLocalizedString(@"LBL_OF_0091", @"レコメンデーション")
#define OFFER_TYPE_NAME_STAMP NSLocalizedString(@"LBL_OF_0092", @"スタンプラリー")
#define OFFER_TYPE_NAME_CAMPAIN NSLocalizedString(@"LBL_OF_0096", @"キャンペーン")

#define ALL_SHOP_TXT @"全店"
#define DEVICE_TYPE_IPHONE @"iPhone"
#define COMA @","

//60*60*24
#define SECOND_ONE_DAY 86400
//60*60
#define SECOND_ONE_HOUR 3600
//60
#define SECOND_ONE_MIN 60

#define TOKEN_REQUEST_TIME 2.0
