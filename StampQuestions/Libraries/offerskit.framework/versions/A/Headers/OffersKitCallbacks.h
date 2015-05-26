//
//  OffersKitCallbacks.h
//  OffersKit
//
//  Created by Leonis&Co. on 2015/03/17.
//  Copyright (c) 2015年 Leonis&Co. All rights reserved.
//

#ifndef OffersKit_Callbacks_h
#define OffersKit_Callbacks_h

#import "OffersKitStatusCode.h"

/// OffersKitの標準的なコールバック。
typedef void (^OffersKitCallback)(OffersKitStatusCode code);

/// OffersCouponの一覧を受け取るコールバック
typedef void (^OffersCouponsCallback)(OffersKitStatusCode code, NSArray* coupons);

/// OffersCategoryの一覧を受け取るコールバック
typedef void (^OffersCategoriesCallback)( OffersKitStatusCode code, NSArray* categories );

/// OffersRecommendationの一覧を受け取るコールバック
typedef void (^OffersRecommendationsCallback)(OffersKitStatusCode code, NSArray *recommendations);

/// OffersGroupの一覧を受け取るコールバック
typedef void (^OffersGroupsCallback)(OffersKitStatusCode code, NSArray* groups);

#endif
