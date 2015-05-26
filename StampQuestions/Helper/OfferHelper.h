//
//  OfferHelper.h
//  StampQuestions
//
//  Created by Nguyen Truong Nguyen on 5/25/15.
//  Copyright (c) 2015 Nguyen Truong Nguyen. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OfferHelper : NSObject

+(BOOL)isPlatformApiKeyValid;
+(NSString*)getPlatformApiKey;
+(NSString*)getPlatformScheme;
+(NSString*)getPlatformGroupName;

@end
