//
//  CupidoNotification.h
//  CupidoKit
//
//  Created by Leonis&Co. on 2013/10/11.
//  Copyright (c) 2013年 Leonis&Co. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CupidoKitStatusCode.h"
#import "CupidoIcon.h"
#import "CupidoNotificationConversion.h"
#import "CupidoNotificationResponseType.h"

/// ユーザに対して送信済みのPUSH通知情報を管理します。
@interface CupidoNotification : NSObject
/// PUSH通知の管理ID
@property(nonatomic,assign) NSUInteger                          notificationId;
/// PUSH通知のタイトル
@property(nonatomic,strong) NSString*                           title;
/// PUSH通知で表示されるメッセージ。PUSH通知受信時に表示されるダイアログや通知センターで表示される内容となります。
@property(nonatomic,strong) NSString*                           payload;
/// PUSH通知の本文。payloadで表現しきれない通知の詳細情報がある場合に設定されます。
@property(nonatomic,strong) NSString*                           body;
/// PUSH通知に設定されているアイコン情報
/// @see CupidoIcon
@property(nonatomic,strong) CupidoIcon*                         icon;
/// このPUSH通知が既読かどうかを示す真偽値
@property(nonatomic,assign) BOOL                                unread;
/// このPUSH通知に添付されているリソースのリスト。各要素にCupidoAttachmentクラスのインスタンスが格納されます。
/// @see CupidoAttachment
@property(nonatomic,strong) NSArray*                            attachments;
/// このPUSH通知が属しているジャンルのリスト。各要素にCupidoCategoryクラスのインスタンスが格納されます。
/// @see CupidoCategory
@property(nonatomic,strong) NSArray*                            categories;
/// このPUSH通知に設定されたコンバージョン条件を示すCupidoNotificationConversionクラスのインスタンス。設定されていない場合は、nilとなります。
/// @see CupidoNotificationConversion
@property(nonatomic,strong) CupidoNotificationConversion*       conversion;
/// PUSH通知の最終更新日時
@property(nonatomic,strong) NSDate*                             updateDate;

/**
 現在このユーザに宛てて送信されているPUSH通知の履歴を取得
 
 現在このユーザに宛てて送信されたPUSH通知の履歴情報で初期化されたCupidoNotificationクラスのインスタンスの配列が返されます。
 配列の各要素は部分的な情報のみがAPIサーバからダウンロードされ、設定されています。
 各要素の完全な情報を取得するにはloadDetailメソッドを実行してください。
 
 @return CupidoNotificationクラスのインスタンスの配列
 */
+(NSArray*)notifications;

/**
 指定した管理IDに対応するPUSH通知を取得
 
 現在このユーザに宛てて送信されたPUSH通知の履歴のうち、引数で指定された管理IDに対応する通知情報で初期化されたCupidoNotificationクラスのインスタンスを取得します。
 このメソッドが返すCupidoNotificationクラスのインスタンスは完全な情報を読み込んでいます。
 
 @param notificationId PUSH通知の管理ID
 
 @return 管理IDで指定したPUSH通知の情報で初期化されたCupidoNotificationクラスのインスタンス
 */
+(CupidoNotification*)notificationForId:(NSUInteger)notificationId;

/**
 完全な通知情報の読み込み
 
 APIサーバに接続して、送信済みのPUSH通知の完全な情報を読み込みます。
 
 @return 実行結果を示すステータスコード
 */
-(CupidoKitStatusCode)loadDetail;

/**
 通知情報に対するエンドユーザのレスポンスを登録
 
 APIサーバに接続して、通知情報に対するエンドユーザのレスポンスを送信します。登録できるレスポンスの種類については、CupidoNotificationResponseType列挙体を参照してください。
 
 @return 実行結果を示すステータスコード
 
 @see CupidoNotificationResponseType
 */
-(CupidoKitStatusCode)setResponse:(CupidoNotificationResponseType)responseType;

@end
