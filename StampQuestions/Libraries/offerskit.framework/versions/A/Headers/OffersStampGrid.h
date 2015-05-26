//
//  OffersStampGrid.h
//  OffersKit
//
//  Created by Kaneko Yoshio on 2014/11/04.
//  Copyright (c) 2014年 Leonis&Co. All rights reserved.
//

#import "OffersObject.h"

@interface OffersStampGrid : OffersObject

/// @name スタンプアクションの主要なプロパティ

/// 管理ID
@property(nonatomic,assign) NSUInteger  gridId;

/// グリッド番号
@property(nonatomic,assign) NSUInteger   no;

/// 画像の幅
@property(nonatomic,assign) NSUInteger   width;

/// 画像の高さ
@property(nonatomic,assign) NSUInteger   height;

/// X座標
@property(nonatomic,assign) NSUInteger   x;

/// Y座標
@property(nonatomic,assign) NSUInteger   y;

/// スタンプグループID
@property(nonatomic,assign) NSUInteger   stampGroupId;

/// アクション情報
@property(nonatomic,strong) NSArray*   actions;


@end
