//
//  OffersStampCardView.h
//  OffersKit
//
//  Created by Kaneko Yoshio on 2014/11/18.
//  Copyright (c) 2014年 Leonis&Co. All rights reserved.
//

#import <Leonis/LeonisStampView.h>

@protocol OffersStampCardViewDelegate <LeonisStampViewDelegate>

/**
 
 スタンプが認識されたことを通知します。
 
 スタンプがリリースされるまで、タッチイベントに連動して通知し続けます。
 
 @param result 認識されたスタンプ情報 { NSDictionary stamp:スタンプ情報 }
 
 */
@optional
-(void) matchStamp:(NSDictionary*)result;


/**
 
 スタンプが離れたことを通知します。
 
 @param result 比較したスタンプ情報とマッチ数のNSArray
 {
 int match_count:一致した数
 NSDictionary stamp:スタンプ情報
 }
 
 */
@optional
-(void) releaseStamp:(NSArray*)result;


/**
 
 スタンプされる直前情報を通知します。
 
 @param result スタンプされた情報のNSDictionary
 
 float x:スタンプ座標X
 float x:スタンプ座標Y
 float width:スタンプサイズ幅
 float height:スタンプサイズ高さ
 float angle:スタンプ角度
 int stamp_id:スタンプID
 int grid_id:グリッドID
 
 */
@optional
-(void) beforeStamp:(NSDictionary*)result;

/**
 
 スタンプされた情報を通知します。
 
 @param result スタンプされた情報のNSDictionary
 
 float x:スタンプ座標X
 float x:スタンプ座標Y
 float width:スタンプサイズ幅
 float height:スタンプサイズ高さ
 float angle:スタンプ角度
 int stamp_id:スタンプID
 int grid_id:グリッドID
 
 */
@optional
-(void) afterStamp:(NSDictionary*)result;

@end


@interface OffersStampCardView : LeonisStampView

/**
 
 デリゲート
 
 */
@property (nonatomic, assign) id<LeonisStampViewDelegate> delegate;

/*
 
 スタンプカード情報を設定します。
 
 @param grids OffersSDKから取得したスタンプカードのグリッド情報
 @param keepOrder OffersSDKから取得したスタンプカードの押印順情報
 @param groups StampGroupの配列
 @param histories StampStampedの配列
 
 */
-(void)setCard:(NSArray*)grids keepOrder:(BOOL)keepOrder groups:(NSArray*)groups histories:(NSArray*)histories;



@end