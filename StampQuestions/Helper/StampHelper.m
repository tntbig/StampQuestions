//
//  StampHelper.m
//  StampQuestions
//
//  Created by Nguyen Truong Nguyen on 5/25/15.
//  Copyright (c) 2015 Nguyen Truong Nguyen. All rights reserved.
//

#import "StampHelper.h"
#import <OffersKit/OffersKit.h>

@implementation StampHelper

//
// Stamp request
//
+(void)requestStampCardsWithType{
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(void) {
        OffersKitStatusCode code;
        [OffersStampCard stampCardsWithOnlineFlag:YES withParameter:nil status:&code];
        
        [self checkRequestReslut:code withName:NSLocalizedString(@"TOP_TITLE_STAMP", nil)];
        
    });
}

+(BOOL)checkRequestReslut:(OffersKitStatusCode)code withName:(NSString*)name{
    
    if (code != OffersKitStatusSuccess) {
        
        if (code == OffersKitStatusNotFound) {
            [self showErrorMessage:[NSString stringWithFormat:NSLocalizedString(@"MSG_ERR_0042",nil),name,name]];
            
        }else{
            [self showErrorMessage:[NSString stringWithFormat:NSLocalizedString(@"MSG_ERR_0043",nil),name]];
        }
        
        return NO;
    }
    return YES;
    
}

+(void)showErrorMessage:(NSString*)msg{
    dispatch_async(dispatch_get_main_queue(), ^{
        UIAlertView * alertView = [[UIAlertView alloc] initWithTitle:nil message:msg delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:nil, nil];
        [alertView show];
    });
}
@end
