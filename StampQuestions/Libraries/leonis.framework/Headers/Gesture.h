//
//  GestureView.h
//  Leonis
//
//  Created by Leonis&Co. on 2014/06/23.
//  Copyright (c) 2014年 Kaneko Yoshio. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 
 Gesture用のデリゲート
 
 */
@protocol GestureDelegate <NSObject>

/**
 
 ジェスチャーが認識されたことを通知します。
 
 @param result 認識されたジェスチャー情報 { x:中心位置X, y:中心位置Y, angle:角度 }
 
 */
@optional
-(void) gestureSuccess:(NSDictionary*)result;

@end

/**
 
 Gesture
 
 */
@interface Gesture: NSObject<GestureDelegate>

/**
 
 デリゲート
 
 */
@property (nonatomic, assign) id delegate;

/**
 
 初期化
 
 @param view ジェスチャー対象View
 
 */
-(id)initView:(UIView *)view;

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;

/**
 
 ジェスチャー面積を取得します
 
 @return float ジェスチャー面積
 
 */
-(float)getArea;

/**
 
 ジェスチャー面積のpxを設定します
 
 @param float ジェスチャー面積
 
 */
-(void)setArea:(float)area;

/**
 
 ジェスチャー認識タイプを取得します
 
 @return NSString ジェスチャー認識タイプ（px or %）
 
*/
-(NSString*)getAreaType;

/**
 
 ジェスチャー面積と認証タイプを設定します
 
 @param float ジェスチャー面積
 @param NSString ジェスチャー認識タイプ（px or %）
 */
-(void)setArea:(float)area type:(NSString*)type;


@end
