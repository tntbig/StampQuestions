//
//  CupidoNotificationResponseType.h
//  CupidoKit
//
//  Created by Leonis&Co. on 2013/10/11.
//  Copyright (c) 2013年 Leonis&Co. All rights reserved.
//

/// 通知に対するユーザのレスポンスを指定するために使用します。
/// @see CupidoNotification
typedef NS_ENUM(NSInteger, CupidoNotificationResponseType ) {
    /// PUSH通知を受信したときのレスポンスですが、現在は対応環境がないため使用しないでください。
    CupidoNotificationResponseTypeReceive,
    /// ユーザがPUSH通知をダイアログや通知センターから開いたときに使用してください。
    CupidoNotificationResponseTypeOpen,
    /// ユーザがPUSH通知の詳細をリクエストしたときに使用してください。
    CupidoNotificationResponseTypeView,
    /// ユーザがPUSH通知を削除したときに使用してください。
    CupidoNotificationResponseTypeDelete,
    /// ユーザがPUSH通知に設定されているコンバージョン条件を達成したときに使用してください。
    CupidoNotificationResponseTypeConversion
};