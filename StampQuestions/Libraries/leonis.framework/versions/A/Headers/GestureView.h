//
//  GestureView.h
//  Leonis
//
//  Created by Kaneko Yoshio on 2014/06/24.
//  Copyright (c) 2014年 Kaneko Yoshio. All rights reserved.
//

#import "Gesture.h"

/**
 
 GestureView用デリゲート
 
 */
@protocol GestureViewDelegate <GestureDelegate>

@optional
-(void) gestureSuccess:(NSDictionary*)result;

@end

/**
 
 GestureView
 
 */
@interface GestureView : UIView<GestureViewDelegate>

/**
 
 デリゲート
 
 */
@property (nonatomic, assign) id<GestureViewDelegate> delegate;

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
