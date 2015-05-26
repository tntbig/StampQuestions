//
//  Leonis.h
//  Leonis
//
//  Created by Leonis&Co. on 2013/11/01.
//  Copyright (c) 2013年 Leonis&Co. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "LeonisTools.h"
#import "LeonisStatusCode.h"

@interface Leonis : NSObject
{
    BOOL    _initialized;
}

/**
 Leonis共通プラットフォームの共有インスタンスを取得します。
 
 @return Leonisプラットフォームの共有インスタンス
 */
+(Leonis*)sharedInstance;

/**
 Documentsパスを取得します。
 
 @return appのDocumentsパス
 */
+(NSString*)documentsPath;

/**
 Cachesパスを取得します。
 
 @return appのCachesパス
 */
+(NSString*)cachesPath;

/**
 Leonisの共有インスタンス初期化が完了しているかどうかを返します。

 @return Leonisが初期化されているかどうかを示す真偽値
 */
-(BOOL)isInitialized;

/**
 APIサーバへの接続情報を設定します。
 
 @param hostName 接続するAPIサーバのホスト名
 @param httpProtocolString APIサーバに接続する際に使用するプロトコル。通常はhttpsとなります。
 @param apiVersion 使用するWeb APIのバージョン番号を文字列で指定します。
 @param applicationKey APIサーバ管理者から発行されたアプリケーションキーを指定します。
 */
-(void)setServerHost:(NSString*)hostName protocol:(NSString*)httpProtocolString apiVersion:(NSString*)versionString applicationKey:(NSString*)applicationKey;

/**
 APIサーバへの接続情報を設定して実際に接続し初期化します。
 
 @param hostName 接続するAPIサーバのホスト名
 @param httpProtocolString APIサーバに接続する際に使用するプロトコル。通常はhttpsとなります。
 @param apiVersion 使用するWeb APIのバージョン番号を文字列で指定します。
 @param applicationKey APIサーバ管理者から発行されたアプリケーションキーを指定します。
 */
-(void)connectServerHost:(NSString*)hostName protocol:(NSString*)httpProtocolString apiVersion:(NSString*)versionString applicationKey:(NSString*)applicationKey;

/**
 バックグラウンドでAPIサーバへの接続情報を設定して実際に接続し初期化します。
 
 @param hostName 接続するAPIサーバのホスト名
 @param httpProtocolString APIサーバに接続する際に使用するプロトコル。通常はhttpsとなります。
 @param apiVersion 使用するWeb APIのバージョン番号を文字列で指定します。
 @param applicationKey APIサーバ管理者から発行されたアプリケーションキーを指定します。
 @param block 初期化が完了した場合に実行する処理を記述したブロックを指定します。
 */
-(void)connectServerHost:(NSString*)hostName protocol:(NSString*)httpProtocolString apiVersion:(NSString*)versionString applicationKey:(NSString*)applicationKey onComplete:(void(^)())block;

/**
 APIサーバへのリクエストのタイムアウトを指定します。
 
 @param requestTimeoutInterval リクエストがタイムアウトするまでの時間を秒単位で指定します。
 */
-(void)setRequestTimeoutInterval:(double)requestTimeoutInterval;

/**
 認証トークンのリクエスト
 
 サーバとの間で認証処理を行いアクセストークンを新規に取得します。
 
 @return メソッドの実行結果を示す結果コードです。
 @see authenticationToken
 */
-(LeonisStatus)requestAuthenticationToken;

/**
 認証トークンのリクエスト
 
 サーバとの間で認証処理を行いアクセストークンをリクエストします。
 
 @param block APIサーバからのレスポンスを受信したあとで呼ばれる処理を記述します。
 @see authenticationToken
 */
-(void)requestAuthenticationTokenWithCallbackBlock:(void(^)(LeonisStatus code))block;

/**
 現在のアクセストークン確認
 
 現在登録されているAPIサーバへのアクセストークンを取得します。
 
 @return アクセストークン文字列
 @see requestAuthenticationToken requestAuthenticationTokenWithCallbackBlock:
 */
-(NSString*)authenticationToken;

/**
 現在のUID
 
 現在のUIDを取得します。
 
 @return UID
 */
-(NSString*)leonisUID;

/**
 現在のUIDを変更
 
 UIDを指定のものに変更します。
 
 本メソッドでは与えられたUIDの一意性は検証されません。
 呼び出す際は、パラメータの値が一意であることが保証されていることをあらかじめ検証してください。
 
 @param uid アプリにおいて一意の文字列
 @return UID登録成功時は真が返されます。
 */
-(BOOL)setUid:(NSString*)uid;
/**
 */

/**
 各プロダクトのAPIサーバ情報を取得
 
 各プロダクトのAPIサーバ情報を取得します。Leonisが提供する各プロダクトのSDK初期化に必要な接続情報などに利用されます。
 
 アプリ開発者はデバッグ用途の利用にとどめてください。
 
 @param serviceName OFFERs、Cupido、Stampのいずれかです。
 
 @return serviceNameに対応するAPIサーバ情報を取得できた場合はNSDictionaryが返されます。
 */
-(NSDictionary*)getServerAppInfoForServiceName:(NSString*)serviceName;

/**
 追加ユーザ情報の単一登録
 
 ユーザごとの追加情報を登録します。この情報は同じキーが指定されると上書きされます。
 
 このメソッドは内部的にリソース名"OffersExtensions"を使用します。
 
 @param value 追加ユーザ情報の値を指定します。
 @param key 追加ユーザ情報の値を設定するキーを指定します。
 */
-(void)setUserExtensionValue:(NSString*)value forKey:(NSString*)key;

/**
 追加ユーザ情報の単一登録
 
 ユーザごとの追加情報を登録します。この情報は同じリソース名、同じキーが指定されると上書きされます。
 
 @param value 追加ユーザ情報の値を指定します。
 @param key 追加ユーザ情報の値を設定するキーを指定します。
 @param section　キーと値のペアを設定するセクション名を指定します
 */
-(void)setUserExtensionValue:(NSString*)value forKey:(NSString*)key withSection:(NSString*)section;

/**
 追加ユーザ情報の複数一括登録
 
 @param extentions 追加ユーザ情報のキーと値のペアで構成されたNSDictionaryをネストしたリソース名ごとのNSDictionaryを指定します
 e.g.
 @{
    @"group_name1": @{
        @"key1": @"value1",
        @"key2": @"value2",
    },
    @"group_name2": @{
        @"key1": @"value1"
    }
 }
 
 @return extensionsが正しくない場合、APIサーバとは通信せず偽が返されます。
 */
-(BOOL)setUserExtensions:(NSDictionary*)extentions;

/**
 追加ユーザ情報の単一登録
 
 ユーザごとの追加情報を登録します。この情報は同じキーが指定されると上書きされます。
 
 このメソッドは内部的にリソース名"OffersExtensions"を使用します。
 
 @param value 追加ユーザ情報の値を指定します。
 @param key 追加ユーザ情報の値を設定するキーを指定します。
 @param block APIサーバからレスポンスが返されたあとで実行する処理を記述したブロックを指定します。
 */
-(void)setUserExtensionValue:(NSString*)value forKey:(NSString*)key withCallbackBlock:(void(^)(LeonisStatus code))block;

/**
 追加ユーザ情報の単一登録
 
 ユーザごとの追加情報を登録します。この情報は同じリソース名、同じキーが指定されると上書きされます。
 @param value 追加ユーザ情報の値を指定します。
 @param key 追加ユーザ情報の値を設定するキーを指定します。
 @param section　キーと値のペアを配置するセクション名を指定します
 @param block APIサーバからレスポンスが返されたあとで実行する処理を記述したブロックを指定します。
 */
-(void)setUserExtensionValue:(NSString*)value forKey:(NSString*)key withSection:(NSString*)section withCallbackBlock:(void(^)(LeonisStatus code))block;

/**
 追加ユーザ情報の複数一括登録
 
 @param extensions 追加ユーザ情報のキーと値のペアで構成されたNSDictionaryをネストしたリソース名ごとのNSDictionaryを指定します。指定方法の例はsetUserExtensions:をご参照ください。
 @param block APIサーバからレスポンスが返されたあとで実行する処理を記述したブロックを指定します。
 
 @return extensionsが正しくない場合、APIサーバとは通信せず偽が返されます。このときは、blockも実行されません。
 */
-(BOOL)setUserExtensions:(NSDictionary*)extentions withCallbackBlock:(void(^)( LeonisStatus code ))block;

/**
 追加ユーザ情報の単一削除
 
 ユーザごとの追加情報を削除します。
 
 このメソッドは内部的にリソース名"OffersExtensions"を対象として削除処理を行います。
 
 @param key 追加ユーザ情報の値を設定するキーを指定します。
 @param block APIサーバからレスポンスが返されたあとで実行する処理を記述したブロックを指定します。
 */
-(void)removeUserExtensionForKey:(NSString*)key;

/**
 追加ユーザ情報の単一削除
 
 @param key 追加ユーザ情報の値を設定するキーを指定します。
 @param section　キーと値のペアを配置するセクション名を指定します
 @param block APIサーバからレスポンスが返されたあとで実行する処理を記述したブロックを指定します。
 */
-(void)removeUserExtensionForKey:(NSString*)key withSection:(NSString*)section;

/**
 追加ユーザ情報の複数一括削除
 
 @param extensions 追加ユーザ情報のキーで構成されるNSArrayをネストしたリソース名ごとのNSDictionaryを指定します。
 e.g.
 @{
    @"group_name1": @[
        @"key1",
        @"key2"
    ],
    @"group_name2": @{
        @"key1"
    ]
 }
 
 @return extensionsが正しくない場合、APIサーバとは通信せず偽が返されます。このときは、blockも実行されません。 
 */
-(BOOL)removeUserExtensions:(NSDictionary*)extensions;

/**
 追加ユーザ情報の単一削除
 
 ユーザごとの追加情報を削除します。
 
 このメソッドは内部的にリソース名"OffersExtensions"を対象として削除処理を行います。
 
 @param key 追加ユーザ情報の値を設定するキーを指定します。
 @param block APIサーバからレスポンスが返されたあとで実行する処理を記述したブロックを指定します。
 */
-(void)removeUserExtensionForKey:(NSString*)key withCallbackBlock:(void(^)(LeonisStatus code))block;

/**
 追加ユーザ情報の単一削除
 
 @param key 追加ユーザ情報の値を設定するキーを指定します。
 @param section　キーと値のペアを配置するセクション名を指定します
 @param block APIサーバからレスポンスが返されたあとで実行する処理を記述したブロックを指定します。
 */
-(void)removeUserExtensionForKey:(NSString*)key withSection:(NSString*)section withCallbackBlock:(void(^)(LeonisStatus code))block;

/**
 追加ユーザ情報の複数一括削除
 
 @param extensions 追加ユーザ情報のキーで構成されるNSArrayをネストしたリソース名ごとのNSDictionaryを指定します。指定方法の例はremoveUserExtensions:をご参照ください。
 @param block APIサーバからレスポンスが返されたあとで実行する処理を記述したブロックを指定します。
 
 @return extensionsが正しくない場合、APIサーバとは通信せず偽が返されます。このときは、blockも実行されません。
 
 */
-(BOOL)removeUserExtensions:(NSDictionary*)extensions withCallbackBlock:(void(^)(LeonisStatus code))block;

#pragma mark - reset

/**
 認証トークンをリセット

 */
-(void)resetToken;

/**
 全接続設定をリセット
 
 @return リセットが成功した場合は真が返されます。
 
 resetAll:のneedResetUidパラメータにNOを与えたときと同様の挙動をとります。

 @see resetAll:
 */
-(BOOL)resetAll;

/**
 全接続設定をリセット
 
 製品版では、needResetUidパラメータに真を指定しないでください。
 
 @param needResetUid 真のとき、UIDをリセットします。UIDは任意のランダムな値となります。

 @return リセットが成功した場合は真が返されます。
 */
-(BOOL)resetAll:(BOOL)needResetUid;

/**
 
 バージョン情報取得
 
 @return バージョン
 */
+(NSString*)version;

@end