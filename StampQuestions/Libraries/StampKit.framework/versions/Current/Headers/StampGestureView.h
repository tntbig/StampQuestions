//
//  StampGestureView.h
//  StampKit
//
//  Created by Kaneko Yoshio on 2014/06/23.
//  Copyright (c) 2014年 Kaneko Yoshio. All rights reserved.
//

#import "StampKit.h"
#import "StampView.h"
#import <Leonis/Gesture.h>

/*
@protocol StampGestureViewDelegate <NSObject>

@optional
-(void) gestureSuccess:(NSDictionary*)result;

@optional
-(void) matchStamp:(NSDictionary*)result;

@optional
-(void) releaseStamp:(NSArray*)result;

@optional
-(void) beforeStamp:(NSDictionary*)result;

@optional
-(void) afterStamp:(NSDictionary*)result;

@end


@interface StampGestureView : StampView<GestureDelegate, StampGestureViewDelegate>

@property (nonatomic, assign) id<StampGestureViewDelegate> delegate;

@end
*/

/**
 
 StampGestureView用のデリゲート
 
 */
@protocol StampGestureViewDelegate <GestureDelegate, StampViewDelegate>

@optional
-(void) gestureSuccess:(NSDictionary*)result;
 
@optional
-(void) matchStamp:(NSDictionary*)result;

@optional
-(void) releaseStamp:(NSArray*)result;
 
@optional
-(void) beforeStamp:(NSDictionary*)result;
 
@optional
-(void) afterStamp:(NSDictionary*)result;

@end

/**
 
 StampGestureView
 
 */
@interface StampGestureView : StampView

/**
 
 初期化
 
 */
-(id)init;


/**
 
 デリゲート
 
 */
@property (nonatomic, assign) id<StampGestureViewDelegate> delegate;

/**
 
 ジェスチャー面積を取得します
 
 @return float ジェスチャー面積
 
 */
-(float)getArea;

/**
 
 ジェスチャー面積を設定します
 
 @param float ジェスチャー面積
 
 */
-(void)setArea:(float)area;

@end