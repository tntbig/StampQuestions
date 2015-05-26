//
//  CupidoAttachment.h
//  CupidoKit
//
//  Created by Leonis&Co. on 2013/12/11.
//  Copyright (c) 2013年 Leonis&Co. All rights reserved.
//

#import <Foundation/Foundation.h>

/// PUSH通知に添付されているリソースを管理します。
@interface CupidoAttachment : NSObject

/// 添付リソースの管理ID
@property(nonatomic,assign) NSUInteger      attachmentId;

/// 添付リソースが保存されているURL
@property(nonatomic,strong) NSString*       urlString;

/// 添付リソースのタイトル
@property(nonatomic,strong) NSString*       title;

/// 添付リソースの最終更新日時
@property(nonatomic,strong) NSDate*         updateDate;

/**
 添付リソースのファイル名を取得
 
 @return 添付リソースのファイル名
 */
-(NSString*)fileName;

@end
