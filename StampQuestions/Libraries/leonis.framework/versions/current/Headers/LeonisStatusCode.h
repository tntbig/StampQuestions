//
//  LeonisStatusCode.h
//  Leonis
//
//  Created by Leonis&Co. on 2014/05/30.
//  Copyright (c) 2014年 Leonis&Co. All rights reserved.
//

typedef NS_ENUM( NSUInteger, LeonisStatus ) {
    /// 成功
    LeonisStatusSuccess                 = 0,
    /// 該当するリソースが見つからなかった
    LeonisStatusNotFound                = 100,
    /// パラメータが不正
    LeonisStatusInvalidParameter        = 300,
    /// 認証失敗
    LeonisStatusAuthenticationFailured  = 400,
    /// アクセス権限なし
    LeonisStatusForbidden               = 403,
    /// 不正なユーザ
    LeonisStatusInvalidUser             = 408,
    /// 不明なユーザ
    LeonisStatusUnkownUser              = 420,
    /// APIサーバの内部エラー
    LeonisStatusInternalServerError     = 500,
    /// アプリは可能ならば再度同じ処理を行うべき
    LeonisStatusPleaseRetry             = 950,
    /// APIサーバと通信できなかった
    LeonisStatusServerResponseError     = -1,
    /// SDK内部のエラー
    LeonisStatusLocalLibraryError       = -100,
};
