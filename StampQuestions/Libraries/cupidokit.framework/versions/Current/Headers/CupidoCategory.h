//
//  CupidoCategory.h
//  CupidoKit
//
//  Created by Leonis&Co. on 2013/12/11.
//  Copyright (c) 2013年 Leonis&Co. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CupidoIcon.h"

/// PUSH通知のジャンルを管理します。
@interface CupidoCategory : NSObject

/// ジャンルの管理ID
@property(nonatomic, assign)    NSUInteger      categoryId;

/// ジャンルに割り当てられているアイコン
/// @see CupidoIcon
@property(nonatomic, strong)    CupidoIcon*     icon;

/// ジャンルのタイトル
@property(nonatomic, strong)    NSString*       title;

/// ジャンルの最終更新日時
@property(nonatomic, strong)    NSDate*         updateDate;

@end
