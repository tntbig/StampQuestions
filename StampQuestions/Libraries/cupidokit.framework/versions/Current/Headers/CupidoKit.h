//
//  CupidoKit.h
//
//  Created by Leonis & Co., Inc. on 2013/04/10.
//  Copyright (c) 2013年 Leonis & Co., Inc. All rights reserved.
//

#import "CupidoKitStatusCode.h"
#import "CupidoNotification.h"

#pragma mark - CupidoKit defination

/**
 CupidoKitクラスはCupidoKitフレームワークの根幹をなすサーバ接続情報等を管理します。
 シングルトンであり、共有インスタンスの取得にはsharedInstanceメソッドを使用してください。
*/
@interface CupidoKit : NSObject

#pragma mark - properties

/// APIサーバへの接続情報

/**
 APIサーバへの接続に使用するプロトコルが設定されます。

 setServerHost:protocol:apiVersion:applicationKey:sandbox:で指定したプロトコルが設定されます。
 
 @see setServerHost:protocol:apiVersion:applicationKey:sandbox:
 */
@property(nonatomic,readonly) NSString*               httpProtocol;

/**
 現在接続しているAPIサーバのホスト名が設定されます。

 setServerHost:protocol:apiVersion:applicationKey:sandbox:で指定したホスト名が設定されます。

 @see setServerHost:protocol:apiVersion:applicationKey:sandbox:
 */
@property(nonatomic,readonly) NSString*               applicationServerHost;

/**
 現在使用中のAPIバージョンが設定されます。
 
 setServerHost:protocol:apiVersion:applicationKey:sandbox:で指定したAPIバージョンが設定されます。
 
 @see setServerHost:protocol:apiVersion:applicationKey:sandbox:
 */
@property(nonatomic,readonly) NSString*               apiVersion;

/** 
 アプリケーションサーバのバージョンが設定されます。
 
 setServerHost:protocol:apiVersion:applicationKey:sandbox:が成功するまでnilです。
 
 @see setServerHost:protocol:apiVersion:applicationKey:sandbox:
*/
@property(nonatomic,readonly) NSString*               applicationServerVersion;

/** 
 アプリケーションサーバのステータスが設定されます。
 
 setServerHost:protocol:apiVersion:applicationKey:sandbox:が成功するまでnilです。
 
 @see setServerHost:protocol:apiVersion:applicationKey:sandbox:
 */
@property(nonatomic,readonly) NSUInteger              applicationServerStatus;

/**
 APIの各種情報が設定されます。

 setServerHost:protocol:apiVersion:applicationKey:sandbox:が成功するまでnilとなります。
 
 @see setServerHost:protocol:apiVersion:applicationKey:sandbox:
 */
@property(nonatomic,readonly) NSDictionary*           apiInfo;

/**
 サーバ定義のアプリ情報が設定されます。
 
 loadClientAppConfigメソッドで読み込まれます。loadClientAppConfigメソッドが失敗した場合はnilとなります。
 
 @see loadClientAppConfig
 */
@property(nonatomic,readonly) NSDictionary*           clientAppConfig;

/** 
 現在のAPI接続タイムアウトが設定されます。
 
 setRequestTimeoutInterval:メソッドで設定された値となります。デフォルト値は15秒です。
 
 @see setRequestTimeoutInterval:
 */
@property(nonatomic,readonly) double                  requestTimeoutInterval;

/** 
 サーバ時間計算時に使用される遅延時間です。
 
 @see setSystemDelay:
*/
@property(nonatomic,readonly) double                  systemDelay;

/** 
 参照するサムネイル名前
*/
@property(nonatomic,strong) NSString*                 thumbnailImageName;

/**
 sandboxかどうかを制御する
 */
@property(nonatomic,assign) BOOL                      isSandbox;


#pragma mark - methods

/** 
 CupidoKit共有インスタンス取得。
 
 @return CupidoKit共有インスタンス
*/
+(CupidoKit*)sharedInstance;

/**
 APIサーバへの接続情報を設定します。
 
 @param hostName 接続するAPIサーバのホスト名
 @param httpProtocolString APIサーバに接続する際に使用するプロトコル。通常はhttpsとなります。
 @param apiVersion 使用するWeb APIのバージョン番号。文字列で指定します。
 @param applicationKey APIサーバ管理者から発行されたアプリケーションキー
 @param sandboxFlag 接続先APNsが開発用(サンドボックス)かどうかを真偽値で指定
 */
-(void)setServerHost:(NSString*)hostName protocol:(NSString*)httpProtocolString apiVersion:(NSString*)versionString applicationKey:(NSString*)applicationKey sandbox:(BOOL)sandboxFlag;

/**
 アプリケーションをCupidoに対応させます
 
 @param application 使用しているアプリケーションのインスタンス
 @param launchOptions アプリケーションの起動オプション
 
 @return アプリケーションが通知ダイアログや通知センターから起動されたときは、その通知情報を格納したCupidoNotificationクラスのインスタンス。通常起動されたときは、nilが返されます。
 */
-(CupidoNotification*)startWithApplication:(UIApplication*)application withLaunchOptions:(NSDictionary*)launchOptions;

/**
 Cupidoシステムの当該ユーザのタイムゾーンを更新
 
 @return 処理結果を示すステータスコード
 */
-(CupidoKitStatusCode)uploadCurrentTimezone;

/** 
 デバイストークンを設定
 
 @param deviceToken 接続先APNsが発行したデバイストークンのデータ
*/
-(void)setDeviceToken:(NSData*)deviceToken;

/**
 Cupidoシステムの当該ユーザのサーバに登録しているデバイストークンを更新
 
 @return 処理結果を示すステータスコード
 */
-(CupidoKitStatusCode)updateDeviceTokenOnServer;

/**
 サーバに登録しているトークンを更新する
 
 @param newDeviceToken 更新するデバイストークンの文字列表現
 @return 処理結果を示すステータスコード
 */
-(CupidoKitStatusCode)updateDeviceTokenOnServer:(NSString*)newDeviceToken;

/**
 サーバに登録しているトークンをリセットし、PUSH通知を受け取らなくする
 
 @return 処理結果を示すステータスコード
 */
-(CupidoKitStatusCode)deleteDeviceTokenOnServer;

/** 
 ローカルデータベースが指定したサイズ上限範囲内か判定します。
 
 @return サイズ上限を超過したかどうかを示す真偽値。真ならば超過、偽ならば範囲内です。
 */
-(BOOL)isLocalDatabaseSizeOver;

/**
 リクエストタイムアウト設定
 
 APIサーバとのリクエストタイムアウトまでの時間を設定します。
 
 @param requestTimeoutInterval リクエストタイムアウトまでの秒数を指定します。
 */
-(void)setRequestTimeoutInterval:(double)requestTimeoutInterval;

/*
 クーポンシステム標準時間からの遅延時間を設定します。
 デフォルト値は0.0fです。不要なら、変更なしで問題ありません。
 
 @param systemDelay クーポンシステム標準時間からの遅延時間を秒単位で指定します。
 
 @see systemDelay
 */
-(void)setSystemDelay:(double)systemDelay;

/**
 CupidoKitのリセット
 
 CupidoKitが生成したキャッシュデータをリセットして初期状態に戻します。
 
 @return リセット成功の有無を表す真偽値です。真ならば成功、偽ならば失敗です。
 */
-(BOOL)resetAll;

/** 
 サーバ定義のアプリ設定
 
 APIサーバにアクセスして、現在サーバ上で定義されているアプリの設定を読み込みます。

 ただし、初期化時に適切なアプリケーションキーを設定していないと失敗します。
 
 @return アプリ設定の読み込み状態を表す真偽値です。真ならば成功、偽ならば失敗です。
 */
-(BOOL)loadClientAppConfig;

/** 
 クーポンシステムにおける現在時刻
 
 クーポンシステムにおける現在時刻を取得します。この時刻は、オンライン時は端末に依存しないAPIサーバ準拠の時刻となります。
 戻り値がnilのときは使用できません。
 
 @return クーポンシステムにおける現在時刻
 */
-(NSDate*)couponSystemDate;

/**
 アクセストークンのリクエスト
 
 サーバとの間で認証処理を行いアクセストークンを新規に取得します。
 
 @return メソッドの実行結果を示す結果コードです。
 @see authenticationToken
 */
-(CupidoKitStatusCode)requestAuthenticationToken;

/**
 アクセストークンのリクエスト
 
 サーバとの間で認証処理を行いアクセストークンをリクエストします。
 
 @param block APIサーバからのレスポンスを受信したあとで呼ばれる処理を記述します。
 @see authenticationToken
 */
-(void)requestAuthenticationTokenWithCallbackBlock:(void(^)(CupidoKitStatusCode code))block;

/**
 アクセストークンの準備
 
 サーバとの間で認証処理を行いアクセストークンが正しいかどうか確認し、不正な場合は最新のトークンに更新します。
 */
-(void)prepareAuthenticationToken;

/**
 現在のアクセストークン確認

 現在登録されているAPIサーバへのアクセストークンを取得します。
 
 @return アクセストークン文字列
 @see requestAuthenticationToken requestAuthenticationTokenWithCallbackBlock:
 */
-(NSString*)authenticationToken;

/**
 ネットワーク接続状態の確認
 
 @return ネットワーク接続状態を表す真偽値です。真ならばネットワーク接続状態、偽ならば切断されています。
 */
-(BOOL)isOnline;

/**
 対応するURLスキームを開き、APIサーバからプレビュークーポン情報受信
 
 APIサーバから受信したプレビュークーポン情報は正しく処理されるとpreviewCouponプロパティに設定されます。失敗した場合や、このメソッドが呼ばれる前はpreviewCouponプロパティはnilです。

 @param url 事前にAPIサーバに登録されたURLスキームが指定されたURL
 @return ただしく処理されたかどうかを示す真偽値です。真ならば成功、偽ならば失敗です。
 @see previewCoupon
 */
-(BOOL)handleOpenURL:(NSURL*)url;

/**
 アプリケーションサーバ情報の読み込み
 
 @return Web APIのステータスコード
 */
-(CupidoKitStatusCode)setApplicationServerInfo;

/** 
 追加情報の登録
 
 @param externalInfo あらかじめAPIサーバで定義された追加情報のキーと値のペアで構成されたNSDictionary
 */
-(void)setExternalInfo:(NSDictionary*)externalInfo;

/**
 追加情報の登録
 
 @param externalInfo あらかじめAPIサーバで定義された追加情報のキーと値のペアで構成されたNSDictionary
 @param block APIサーバからレスポンスが返されたあとで実行する処理を記述したブロックを指定します。
 */
-(void)setExternalInfo:(NSDictionary*)externalInfo withCallbackBlock:(void(^)( CupidoKitStatusCode code ))block;

/**
 画像のURL変換
 
 APIサーバで定義されているサムネイル名とそのサイズに対応したサムネイル画像のURLを生成します。
 
 @param originalImageUrlString オリジナルとなる画像URLの文字列表現
 @param name APIサーバで定義されているサムネイル名
 @return nameで指定されたサムネイル画像のURL文字列
 */
+(NSString*)convertImageUrlString:(NSString*)originalImageUrlString withThumbnailName:(NSString*)name;

/**
 アプリケーションアイコンのバッジ更新 
 */
-(void)updateAppBadgeNumber;

/**
 ペイロードから通知IDをとりだす
 
 PUSH通知のペイロードから通知IDを取得します。
 
 @param userInfo PUSH通知のペイロード
 @return PUSH通知ペイロードに含まれる通知ID
 */
+(NSUInteger)notificationIdFromUserInfo:(NSDictionary*)userInfo;

/**
 ペイロードから通知メッセージをとりだす
 
 PUSH通知のペイロードから通知メッセージを取得します。
 
 @param userInfo PUSH通知のペイロード
 @return PUSH通知ペイロードに含まれる通知メッセージ
 */
+(NSString*)alertFromUserInfo:(NSDictionary*)userInfo;

@end
