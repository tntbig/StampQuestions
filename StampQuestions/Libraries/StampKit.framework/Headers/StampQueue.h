//
//  StampQueue.h
//  StampKit
//
//  Created by Kaneko Yoshio on 2014/01/28.
//  Copyright (c) 2014年 Kaneko Yoshio. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface StampQueue : NSObject

@property int idx;
@property NSString *api;
@property NSString *method;
@property NSString *token;
@property NSString *body;
@property NSString *uid;
@property NSString *created_at;
@property int *send_count;


+(void) save:(NSDictionary*)params;


@end
