//
//  StampView.h
//  stampLib
//
//  Created by Kaneko Yoshio on 2014/01/20.
//  Copyright (c) 2014年 Leonis&Co. All rights reserved.
//


#import <Leonis/LeonisStampView.h>

/**
 
 StampView用のデリゲート
 
 */
@protocol StampViewDelegate <LeonisStampViewDelegate>


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

@optional
-(void) stampAction:(NSDictionary*)result;

@end

/**
 
 スタンプView
 
 */
@interface StampView : LeonisStampView


/**
 
 初期化
 
*/
-(id)init;

/**
 
 デバッグ情報を表示するか否かの真偽値デフォルトはfalse
 
 @warning 運用時には利用しないでください。
 
*/
@property BOOL debug;

/**
 
 デリゲート
 
 */
@property (nonatomic, assign) id<StampViewDelegate> delegate;


/**
 
 捻り認証をするか否かの真偽値デフォルトはfalse
 
 */
@property BOOL twistMatch;

/**
 
 捻り認証をする時の捻り角度デフォルトは30.0f
 
 */
@property float twistAngle;

 
/**
 
 スタンプグループ情報をセットします。
 
 @param groups スタンプグループ情報
 
 */
-(void)setGroups:(NSArray *)groups;

/**
 
 スタンプグループ情報とスタンプ履歴情報をセットします。
 
 setHistoriesより後に実行して下さい。
 

 @param groups スタンプグループ情報
 @param histories スタンプ履歴情報
 
 */
-(void)setGroupsWithHistories:(NSArray *)groups histories:(NSArray *)histories;

/**
 
 スタンプ履歴情報をセットします。
 
 @param histories スタンプ履歴情報
 
 */
-(void)setHistories:(NSArray *)histories;

/**
 * 描画されている最後のスタンプを取り除きます。
 
 @param content_id コンテンツID
 
 @warning このメソッドは運用時には利用しないでください。
 
 */
-(void)lastStampedDelete:(int)content_id;


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
 
 @param animation デフォルトはtrue
 
 */
-(void)setAnimation:(BOOL) animation;


@end