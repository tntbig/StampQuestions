//
//  CupidoIcon.h
//  CupidoKit
//
//  Created by Leonis&Co. on 2013/12/11.
//  Copyright (c) 2013年 Leonis&Co. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// Cupidoシステムで使用されるアイコン情報を管理します。
@interface CupidoIcon : NSObject

/// アイコンの管理ID
@property(nonatomic,assign) NSUInteger  iconId;

/// アイコン画像が配置されているURL
@property(nonatomic,strong) NSString*   imageUrl;

/// 二倍の解像度をもつアイコン画像が配置されているURL
@property(nonatomic,strong) NSString*   imagex2Url;

/// アイコン画像
@property(nonatomic,strong) UIImage*    image;

/// 二倍の解像度を持つアイコン画像
@property(nonatomic,strong) UIImage*    imagex2;

/// 最終更新日時
@property(nonatomic,strong) NSDate*     updatedDate;

/**
 APIサーバに登録されているアイコン情報をダウンロードし、インスタンスの配列を生成します。
 
 @return CupidoIconインスタンスが格納されたNSArrayオブジェクト
 
 */
+(NSArray*)icons;

/**
 指定された管理IDに対応するクーポンの情報をAPIサーバからダウンロードし、インスタンスを生成します。
 
 @param iconId  アイコンの管理ID
 
 @return 管理IDに対応するCupidoIconクラスのインスタンス
 
 */
+(CupidoIcon*)iconForId:(NSUInteger)iconId;

/**
 インスタンスに設定されたアイコン画像URLからアイコン画像をダウンロードし読み込みます。
 
 @see imageUrl imagex2Url image imagex2

 */
-(void)loadImages;

/**
 インスタンスに設定されたアイコン画像URLからアイコン画像をダウンロードし読み込みます。
 
 @param callbackBlock アイコン画像ダウンロードが完了したときに呼び出されるブロック
 
 @see imageUrl imagex2Url image imagex2
 
 */
-(void)loadImagesWithCallback:(void(^)())callbackBlock;

/**
 インスタンスに設定されたアイコン画像をデバイス解像度にあわせて取得します。
 
 @return デバイス解像度に適合したアイコン画像。デバイスがRetina対応のときはimagex2、そうでないときはimage
 
 @see image imagex2
 
 */
-(UIImage*)iconImage;

@end
