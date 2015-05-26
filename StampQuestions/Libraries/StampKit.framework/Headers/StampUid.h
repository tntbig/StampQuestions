//
//  StampUid.h
//  StampKit
//
//  Created by Kaneko Yoshio on 2014/03/18.
//  Copyright (c) 2014年 Kaneko Yoshio. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface StampUid : NSObject

@property NSString * uid;
@property NSString * token;

- (id) initWithDictionary:(NSDictionary*)dictionary;
-(void)save;

@end
