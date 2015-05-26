//
//  OfferHelper.m
//  StampQuestions
//
//  Created by Nguyen Truong Nguyen on 5/25/15.
//  Copyright (c) 2015 Nguyen Truong Nguyen. All rights reserved.
//

#import "OfferHelper.h"

@implementation OfferHelper

+(BOOL)isPlatformApiKeyValid{
    if([[NSUserDefaults standardUserDefaults] objectForKey:USERDEFALUTS_SETTING_PLATFORM_APP_KEY] == nil){
        return false;
    }
    return true;
}

+(NSString *)getPlatformApiKey{
    if ([self isPlatformApiKeyValid]) {
        return [[NSUserDefaults standardUserDefaults] objectForKey:USERDEFALUTS_SETTING_PLATFORM_APP_KEY];
    }
    return nil;
}

+(NSString *)getPlatformGroupName{
    NSString * groupName = [[[NSUserDefaults standardUserDefaults] objectForKey:USERDEFALUTS_SETTING_PLATFORM_GROUP] objectForKey:@"name"];
    return groupName;
}

+(NSString *)getPlatformScheme{
    NSString * scheme = [[[NSUserDefaults standardUserDefaults] objectForKey:USERDEFALUTS_SETTING_PLATFORM_GROUP] objectForKey:@"scheme"];
    return scheme;
}
@end
