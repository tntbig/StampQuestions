//
//  CupidoNotificationConversion.h
//  CupidoKit
//
//  Created by Leonis&Co. on 2013/12/11.
//  Copyright (c) 2013年 Leonis&Co. All rights reserved.
//

#import <Foundation/Foundation.h>

/// コンバージョンの種類を管理します。
/// @see CupidoNotification
typedef NS_ENUM( NSInteger, CupidoNotificationConversionType ) {
    /// コンバージョンの種類が特に設定されていない場合にこの値をとります。
    CupidoNotificationConversionTypeNone,
    /// PUSH通知が開かれたことでコンバージョン成立とする場合に、この値をとります。
    CupidoNotificationConversionTypeNotificationOpened,
    /// PUSH通知に添付されているリソースを開いたときにコンバージョン成立とする場合に、この値をとります。
    CupidoNotificationConversionTypeAttachmentOpened,
    /// PUSH通知本文に含まれているリンクをクリックしたときにコンバージョン成立とする場合に、この値をとります。
    CupidoNotificationConversionTypeLinkClicked,
};

/// PUSH通知ごとに設定されることがあるコンバージョン条件を管理します。
@interface CupidoNotificationConversion : NSObject
/// コンバージョンの種類が設定されます。
@property(nonatomic, assign)    CupidoNotificationConversionType conversionType;

@end
