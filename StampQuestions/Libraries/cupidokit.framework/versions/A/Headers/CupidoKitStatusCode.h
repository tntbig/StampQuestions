//
//  CupidoKitStatusCode.h
//  CupidoKit
//
//  Created by Leonis&Co. on 2013/06/14.
//  Copyright (c) 2013年 Leonis&Co. All rights reserved.
//

/// SDK共通のステータスコード
typedef NS_ENUM(NSInteger, CupidoKitStatusCode ) {
    /// APIサーバへのリクエストが成功しました
    CupidoKitStatusSuccess                      = 0,
    /// 指定された条件でAPIサーバからデータを取得できなかったときに返されます。
    CupidoKitStatusNotFound                     = 100,
    /// APIサーバに与えられたパラメータが正しくないときに返されます。仕様書どおりの形式でパラメータを与えているにも関わらずこのコードが返される場合は、Leonis&Co.までお問い合わせください。
    CupidoKitStatusInvalidParameter             = 300,
    /// APIサーバとの認証が失敗したときに返されます。
    CupidoKitStatusAuthenticationFailed         = 400,
    /// APIサーバにユーザが登録されていない場合に返されます。時間をおいても解消されない場合は、Leonis&Co.までお問い合わせください。
    CupidoKitStatusUserNotFound                 = 420,
    /// APIサーバにおいてエラーが発生した場合に返されます。時間をおいても解消されない場合は、Leonis&Co.までお問い合わせください。
    CupidoKitStatusServerError                  = 500,
    /// APIサーバに対してリクエストされたデータに差分変更がなかった場合に返されます。
    CupidoKitStatusNotModified                  = 800,
    /// 一時的にAPIサーバがリクエストを処理できない状態になったときに返されます。時間をおいて再度リクエストするようコーディングしてください。
    CupidoKitStatusPleaseRetry                  = 950,
    /// Cupidoシステムで定義されていない未知のエラーが発生した場合に返されます。時間をおいても解消されない場合は、Leonis&Co.までお問い合わせください。
    CupidoKitStatusUnknownError                 = 999,
    
    /* 以下はローカルで問題が発生したときのコードとなります。(ユーザインタフェースではエラーの内容を詳しく説明しすぎないようにしてください) */
    /// ローカルデータベースのエラーが発生したときに返されます。
    CupidoKitStatusLocalDatabaseError           = -100,
    /// サーバレスポンスエラーが発生したときに返されます。時間をおいても解消されない場合は、Leonis&Co.までお問い合わせください。
    CupidoKitStatusServerResponseError          = -200,
    /// CupidoKit SDKの各種初期化メソッドが手順通りに実行されなかったときなどに発生します。
    CupidoKitStatusImplementError               = -256,
    /// CupidoKit SDKのエラー
    CupidoKitStatusLocalLibraryError            = -1024,
};
