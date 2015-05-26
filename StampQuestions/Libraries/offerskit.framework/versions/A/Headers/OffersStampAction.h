//
//  OffersStampAction.h
//  OffersKit
//
//  Created by Kaneko Yoshio on 2014/11/04.
//  Copyright (c) 2014年 Leonis&Co. All rights reserved.
//

#import "OffersObject.h"

@interface OffersStampAction : OffersObject

/// @name スタンプアクションの主要なプロパティ

/// 管理ID
@property(nonatomic,assign) NSUInteger  actionId;

/// タイトル
@property(nonatomic,strong) NSString*   title;

///　詳細
@property(nonatomic,strong) NSString*   mainDescription;

/// メッセージ
@property(nonatomic,strong) NSString*   message;

/// 画像情報
@property(nonatomic,strong) NSDictionary*   image;

/// プレゼント情報
@property(nonatomic,strong) NSDictionary*   presents;

/// オリジナルサイズの画像
@property(nonatomic,strong) NSString*   imageUrlString;
@property(nonatomic,strong) UIImage*    imageBitmap;

/**

 スタンプアクションにプレゼントが関連づけられているかどうか
 
 @return プレゼントが関連づけられている場合は真が返されます。関連づけられているプレゼントがない場合は偽が返されます。

 */
-(BOOL)hasPresents;

@end
