//
//  Config.h
//  LeonisSaleDemo
//
//  Created by leo-mobile-lily on 12/22/14.
//  Copyright (c) 2014 Leonis&Co. All rights reserved.
//

//------------------環境設定-----------------------
//LEONIS環境
//本番環境か
#define PLATFORM_IS_RELEASE NO

//FOR TEST
#define API_KEY_IS_USE_LOCAL NO
#define STAMP_CAN_CLEAR NO
#define STAMP_CAN_GESTURE YES


//------------Platform------------------
#define LEONIS_API_SERVER_HOSTNAME_DEV      (@"demo-platform-staging.leonisand.co")
#define LEONIS_API_SERVER_HOSTNAME_RELEASE  (@"demo-platform.leonisand.co")
#define LEONIS_API_SERVER_HOSTNAME           PLATFORM_IS_RELEASE ? LEONIS_API_SERVER_HOSTNAME_RELEASE : LEONIS_API_SERVER_HOSTNAME_DEV
#define LEONIS_API_SERVER_PROTOCOL                  (@"https")
#define LEONIS_API_SERVER_API_VERSION               (@"1.0")


#define COUPON_SEVER_REQUEST_TIME_OUT 30.0f
//--------------------------------------

//------------------Coupon-----------------------
#define COUPON_PROTOCOL @"https"
#define COUPON_API_VISIION @"1.0"


//クーポンローカルたまるMAX数
#define COUPON_LOCAL_MAX_SAVE_COUNT 500
#define COUPON_PAGING_ONE_PAGE_COUNT 10

//クーポンローカルにたまっているデータを送信する時間
#define COUPON_LOCAL_SENDTO_SERVER_TIME 20.0f
#define COUPON_SEVER_REQUEST_TIME_OUT 30.0f
#define COUPON_TOKEN_URL @"https://inhouse-app.s3.amazonaws.com/DemoGroupAndApikey3.json"

#define COUPON_CUSTOM_SHAKE_DETECT_COUNT 1

//------------------Coupon-----------------------


//------------------Push-----------------------
#define PUSH_SEVER_REQUEST_TIME_OUT 60.0f
//------------------Push-----------------------

//------------------Stamp-----------------------
#define STAMP_SEVER_REQUEST_TIME_OUT 30.0f
//------------------Stamp-----------------------

//------------------表示-----------------------
#define PAGE_DEFALUT PageType_Coupon
//site url
#define SITE_OFFER_URL @"http://www.trans-cosmos.co.jp/special/digitalmktg/offers.html"
//------------------表示-----------------------

#define DEPLOY_GATE_SDK_API_KEY @"b0a30357a7ed60c964cb6948c8f1f5374aad0868"
#define DEPLOY_GATE_SDK_AUTHOR @"Leonis"
