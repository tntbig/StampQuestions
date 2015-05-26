//
//  LeonisStampView.h
//  Leonis
//
//  Created by Leonis&Co on 2014/01/20.
//  Copyright (c) 2014年 Leonis&Co. All rights reserved.
//

#import <UIKit/UIKit.h>


/**
 
 LeonisStampView用のデリゲート
 
 */
@protocol LeonisStampViewDelegate <NSObject>


/**
 
 スタンプが認識されたことを通知します。
 
 スタンプがリリースされるまで、タッチイベントに連動して通知し続けます。
 
 @param result 認識されたスタンプ情報 { StampStamp stamp:StampStampオブジェクト }
 
 */
@optional
-(void) matchStamp:(NSDictionary*)result;


/**
 
 スタンプが離れたことを通知します。
 
 @param result 比較したスタンプ情報とマッチ数のNSArray
 {
 int match_count:一致した数
 StampStamp stamp:StampStampオブジェクト
 }
 
 */
@optional
-(void) releaseStamp:(NSArray*)result;


/**
 
 スタンプされる直前情報を通知します。
 
 @param result スタンプされた情報のNSDictionary
 
 CGPoint point:スタンプ座標
 float angle:スタンプ角度
 CGSize size:スタンプサイズ
 int index:スタンプのインデックス
 StampStamp stamp:StampStampオブジェクト
 
 */
@optional
-(void) beforeStamp:(NSDictionary*)result;

/**
 
 スタンプされた情報を通知します。
 
 @param result スタンプされた情報のNSDictionary
 
 CGPoint point:スタンプ座標
 float angle:スタンプ角度
 CGSize size:スタンプサイズ
 int index:スタンプのインデックス
 StampStamp stamp:StampStampオブジェクト
 double stamped_at:スタンプ日時
 
 */
@optional
-(void) afterStamp:(NSDictionary*)result;


/**
 
 スタンプされた画像の描画を通知します
 
 @method drawStamp
 @param {NSDictionary} result {values:{scale:スケール, image:スタンプ画像, stamp_id:スタンプID, x:X座標, y:Y座標, width:画像の幅, height:画像の高さ, angle:画像の角度, stamped_at:押印日時}}
 
 */
@optional
-(void) drawStamp:(NSDictionary*)result;


@end

/**
 
 スタンプView
 
 */
@interface LeonisStampView : UIView

/**
 
 デバッグ情報を表示するか否かの真偽値デフォルトはfalse
 
 @warning 運用時には利用しないでください。
 
 */
@property BOOL debug;

/**
 
 デリゲート
 
 */
@property (nonatomic, assign) id<LeonisStampViewDelegate> delegate;


/**
 
 捻り認証をするか否かの真偽値デフォルトはfalse
 
 */
@property BOOL twistMatch;

/**
 
 捻り認証をする時の捻り角度デフォルトは30.0f
 
 */
@property float twistAngle;


/**
 
 スタンプ履歴情報をセットします。
 
 @param histories スタンプ履歴情報
 
 */
-(void)setHistories:(NSArray *)histories block:(void(^)(BOOL result))block;
-(void)setHistories:(NSArray *)histories;

-(NSArray*)getHistories;


/**
 
 スタンプ情報をセットします。
 
 */
-(void)setStamps:(NSArray *)stamps block:(void(^)(BOOL result))block;
-(void)setStamps:(NSArray *)stamps;

-(NSArray*)getStamps;

/**
 
 スタンプされる際の描画オプションを設定します。
 
 @param params オプションのNSDictionary
 
 CGPoint point:スタンプ座標(省略時はスタンプされた座標)
 float angle:スタンプ角度(省略時はスタンプされた角度)
 CGSize size:スタンプサイズ(省略時はスタンプ画像のサイズ)
 
 */
-(void)setStampedOption:(NSDictionary *)params;

/**
 
 View内で描画するか否かを設定できます。
 
 @param draw デフォルトはtrue
 
 */
-(void)setDraw:(BOOL) draw;

@end