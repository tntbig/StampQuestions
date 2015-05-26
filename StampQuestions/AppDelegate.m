//
//  AppDelegate.m
//  StampQuestions
//
//  Created by Nguyen Truong Nguyen on 5/21/15.
//  Copyright (c) 2015 Nguyen Truong Nguyen. All rights reserved.
//

#import "AppDelegate.h"

//cupido
#import <OffersKit/OffersKit.h>

//cupido
#import <CupidoKit/CupidoKit.h>

//stamp
#import <StampKit/StampKit.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [self initSDKs:nil];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

- (void) initSDKs:(CCAfter)block{
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(void) {
        BOOL rs = [self initLeonisSDK];
        
        if (rs == NO) {
            return ;
        }
        
        [self initOfferkitSDK];
        
        [self initCupidoSDK];
        
        //    [self connectOfferAndCupido];
    });
}

-(BOOL)initLeonisSDK{
    
//    NSString * app_id = [OfferHelper getPlatformApiKey];
    NSString * app_id = @"xygAagrSegaaL";//dev
    
    [[Leonis sharedInstance] connectServerHost:LEONIS_API_SERVER_HOSTNAME
                                      protocol:LEONIS_API_SERVER_PROTOCOL
                                    apiVersion:LEONIS_API_SERVER_API_VERSION
                                applicationKey:app_id
     ];
    
    [[Leonis sharedInstance] setRequestTimeoutInterval:COUPON_SEVER_REQUEST_TIME_OUT];
    
    [self checkLeonisTokenHaveBeenTaken];
    
    return YES;
    
}

-(BOOL)checkLeonisTokenHaveBeenTaken{
    
    if ([[Leonis sharedInstance] authenticationToken] == nil) {
        NSLog(@"waiting for leonis token");
        [NSThread sleepForTimeInterval:TOKEN_REQUEST_TIME];
        [self checkLeonisTokenHaveBeenTaken];
    }
    
    NSLog(@"Leonis token : %@",[[Leonis sharedInstance] authenticationToken]);
    
    return YES;
}

// OffersKit initial


-(void)initOfferkitSDK{
    
    [[OffersKit sharedInstance] setupWithPlatform];
    
    [[OffersKit sharedInstance] setRequestTimeoutInterval:COUPON_SEVER_REQUEST_TIME_OUT];
    
    [[OffersKit sharedInstance] setBackgroundSyncTimeInterval:COUPON_LOCAL_SENDTO_SERVER_TIME syncType:OffersKitSyncTypeSubmit];
    [OffersCoupon setCouponsCapacity:COUPON_LOCAL_MAX_SAVE_COUNT];
    
    [[OffersKit sharedInstance] start];
    
    NSLog(@"UID: %@", [[OffersKit sharedInstance] offersUID]);
}


// Cupido initial

-(void)initCupidoSDK{
    
//    [[CupidoKit sharedInstance] setupWithPlatform];
//    [[CupidoKit sharedInstance] setRequestTimeoutInterval:PUSH_SEVER_REQUEST_TIME_OUT];
}


-(void)connectOfferAndCupido{
    [[OffersKit sharedInstance] linkUserWithCupido:[CupidoKit sharedInstance]];
}


#pragma mark - Push
-(void)setPushWithApplication:(UIApplication *)application withOptions:(NSDictionary *)launchOptions{
    
    CupidoNotification* notification = nil;
    NSDictionary *userInfo = [launchOptions objectForKey:UIApplicationLaunchOptionsRemoteNotificationKey];
    if (userInfo != nil) {
        // Push通知から起動された
        NSUInteger notificationId = [CupidoKit notificationIdFromUserInfo:userInfo];
        // 画面遷移させるための情報をセットする
        notification = [CupidoNotification notificationForId:notificationId];
        [notification setResponse:CupidoNotificationResponseTypeOpen];
    }
    else {
        
        // Push通知デバイストークンのリクエスト
//        if ([application respondsToSelector:@selector(registerUserNotificationSettings:)]) {
            // use registerUserNotificationSettings
            UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeBadge
                                                                                                 |UIUserNotificationTypeSound
                                                                                                 |UIUserNotificationTypeAlert) categories:nil];
            [application registerUserNotificationSettings:settings];
            [application registerForRemoteNotifications];
//        } else {
//            // use registerForRemoteNotifications
//            [application registerForRemoteNotificationTypes:(UIUserNotificationTypeBadge|
//                                                             UIUserNotificationTypeSound|
//                                                             UIUserNotificationTypeAlert
//                                                             )
//             ];
//            
//        }
    }
}

// デバイストークン発行成功 処理
-(void)setPushToken:(NSData*)deviceToken{
    //NSLog(@"device token :  %@",deviceToken);
    [[CupidoKit sharedInstance] setDeviceToken:deviceToken];
}

// アプリ起動中(フォアグラウンド、バックグラウンド)でpush通知を受けた場合 処理
-(void)showPushWhenLoadingWithApplication:(UIApplication*)application withInfor:(NSDictionary*)userInfo{
    NSUInteger notificationId = [CupidoKit notificationIdFromUserInfo:userInfo];
    CupidoNotification* notification = [CupidoNotification notificationForId:notificationId];
    if( notificationId > 0 ) {
        switch( application.applicationState ) {
            case UIApplicationStateActive:
            {
                //NSLog(@"push active code %d noti %@",notificationId,notification);
                // Activeのときは通知センターにはのこらない
                UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:notification.title
                                                                    message:notification.payload
                                                                   delegate:self
                                                          cancelButtonTitle:@"閉じる"
                                                          otherButtonTitles:@"表示", nil
                                          ];
                alertView.tag = notificationId;
                [alertView show];
                break;
            }
            case UIApplicationStateBackground:
            default:
            {
                [notification setResponse:CupidoNotificationResponseTypeOpen];
                //                NSDictionary * dic = [NSDictionary dictionaryWithObject:[NSNumber numberWithLong:notificationId] forKey:@"push"];
                //                [[NSNotificationCenter defaultCenter] postNotificationName:@"Notification_Push" object:nil userInfo:dic];
                NSLog(@"UIApplicationStateBackgroundプッシュ");
                break;
            }
        }
    }
}

// UIAlertViewDelegate
-(void)alertView:(UIAlertView*)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex
{
    NSString* buttonTitle = [alertView buttonTitleAtIndex:buttonIndex];
    if( [buttonTitle isEqualToString:@"表示"] == YES ) {
        // ユーザから表示要求があった
        NSUInteger notificationId = alertView.tag;
        CupidoNotification* notification = [CupidoNotification notificationForId:notificationId];
        // PUSH通知に応答してくれたことをサーバに通知する
        [notification setResponse:CupidoNotificationResponseTypeOpen];
        // プッシュ通知履歴を表示する
        //        NSDictionary * dic = [NSDictionary dictionaryWithObject:[NSNumber numberWithLong:notificationId] forKey:@"push"];
        //        [[NSNotificationCenter defaultCenter] postNotificationName:@"Notification_Push" object:nil userInfo:dic];
    }
    else if( [buttonTitle isEqualToString:@"閉じる"] == YES) {
        // なにもしない
    }
    else {
        // なにもしない
    }
}


@end
