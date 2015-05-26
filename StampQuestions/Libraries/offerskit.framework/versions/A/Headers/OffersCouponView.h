//
//  OffersCouponView.h
//  OffersKit
//
//  Created by Kaneko Yoshio on 2015/02/19.
//  Copyright (c) 2015年 Leonis&Co. All rights reserved.
//

#import <Leonis/LeonisStampView.h>
#import <Leonis/Gesture.h>



/**
 
 OffersCouponViewのデリゲート
 */
@protocol OffersCouponViewDelegate <LeonisStampViewDelegate, GestureDelegate>

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
    NSString stamped_at:スタンプ日付(YYYYMMDDHHIISS)
 
 */
@optional
-(void) afterStamp:(NSDictionary*)result;

/**
 
 ジェスチャー認識した際に通知します。
 
 
 */
@optional
-(void) gestureSuccess:(NSDictionary*)result;

/**
 
 使用しません
 
 */
@optional
-(void) drawStamp:(NSDictionary*)result;


@end

/**
 
 設定されたクーポンIDのスタンプ及びジェスチャーに対応したView
 
 */
@interface OffersCouponView : LeonisStampView

/**
 
 デリゲート
 
 */
@property (nonatomic, assign) id<OffersCouponViewDelegate> delegate;


/// クーポンID
@property (nonatomic, assign) NSUInteger couponId;

/**
 
 ジェスチャー面積を取得します
 
 @return float ジェスチャー面積
 
 */
-(float)getArea;

/**
 
 ジェスチャー面積を設定します(deprecated)
 
 @param area ジェスチャー面積
 */
-(void)setArea:(float)area DEPRECATED_ATTRIBUTE;


/**
 
 ジェスチャー面積を割合で設定します
 
 @param ratio 割合
 
 */
-(void)setGestureRecognitionAreaRatio:(float)ratio;


/**
 
 使用しません
 
 */
-(void)syncCoupon;

@end