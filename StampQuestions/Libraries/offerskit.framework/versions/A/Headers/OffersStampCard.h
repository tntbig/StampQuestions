//
//  OffersStampCard.h
//  OffersKit
//
//  Created by Kaneko Yoshio on 2014/10/06.
//  Copyright (c) 2014年 Leonis&Co. All rights reserved.
//

#import "OffersObject.h"

@interface OffersStampCard : OffersObject
{
    NSString*       _description;
}

#pragma mark - properties

/// @name スタンプカードの主要なプロパティ

/// 管理ID
@property(nonatomic,assign) NSUInteger  stampCardId;

/// タイトル
@property(nonatomic,strong) NSString*   title;

/// スタンプカードの説明文(簡単な一文)が設定されます。
@property(nonatomic,strong) NSString*   mainDescription;

/// 配布店舗
@property(nonatomic,strong) NSArray*    shops;

/// クーポンの利用条件が設定されます。
@property(nonatomic, strong)    NSString*           useConditionDescription;

/// スタンプカードの使用可能上限数が設定されます。 -(BOOL)hasAvailableLimitの結果がYESのときのみ参照してください。それ以外のときに設定される値は未定義です。
@property(nonatomic, strong)    NSNumber*           availableLimit;

/// スタンプカードを使用した後に表示するメッセージが設定されます。
@property(nonatomic, strong)    NSString*           afterUseMessage;

/// スタンプカードの使用可能開始日が設定されます。
@property(nonatomic, strong)    NSDate*             availableFromDate;
/// スタンプカードの使用可能終了日が設定されます。
@property(nonatomic, strong)    NSDate*             availableToDate;

/// 配信開始日時
@property(nonatomic,strong) NSDate*     deliveryFromDate;

/// 配信終了日時
@property(nonatomic,strong) NSDate*     deliveryToDate;

///グリッドの順番にスタンプを押印するかの真偽値
@property(nonatomic,assign) BOOL   keepOrder;

/// 消し込みがオンライン必須かどうかを示す真偽値が設定されます。
@property(nonatomic, assign)    BOOL                onlineRequired;


/// スタンプカードの残り枚数が設定されます。 -(BOOL)hasAvailableLimitの結果がYESのときのみ参照してください。それ以外のときに設定される値は未定義です。
@property(nonatomic, strong)    NSNumber*           quantity;
/// スタンプカードの残り枚数が更新された日時が設定されます。-(BOOL)hasAvailableLimitの結果がYESのときのみ参照してください。それ以外のときに設定される値は未定義です。
@property(nonatomic, strong)    NSDate*             quantityUpdatedDate;

/// 背景画像の幅
@property(nonatomic, strong)    NSNumber*           width;

/// 背景画像の高さ
@property(nonatomic, strong)    NSNumber*           height;

/// スタンプカードのオリジナルサイズの画像
/// インスタンスに対してloadDetailメソッドを実行し、詳細を読み込むと設定されます。
@property(nonatomic,strong) NSString*   imageUrlString;
@property(nonatomic,strong) UIImage*    image;

/// スタンプカードのオリジナルサイズの背景画像
/// インスタンスに対してloadDetailメソッドを実行し、詳細を読み込むと設定されます。
@property(nonatomic,strong) NSString*   backgroundImageUrlString;
@property(nonatomic,strong) UIImage*    backgroundImage;



/// スタンプカードを部分よみとりしたときの情報の最終更新日が設定されます。
@property(nonatomic,strong) NSDate*     partialUpdatedDate;


/// 更新日時
@property(nonatomic,strong) NSDate*     updatedDate;


/// 詳細情報がすでに読み込まれているかどうか
/// @see loadDetail loadDetailWithOnlineFlag: loadDetailWithCallbackBlock: loadDetailWithOnlineFlag:withCallbackBlock:
@property(nonatomic,assign) BOOL        isLoadedDetail;

/// グリッド情報
@property(nonatomic,strong) NSArray*   grids;

/// アクション情報
@property(nonatomic,strong) NSArray*   actions;

/// コンテンツID
@property(nonatomic,strong) NSNumber*   contentId;

/// スタンプグループ情報
@property(nonatomic,strong) NSArray*   stampGroups;

/// 押印履歴情報
@property(nonatomic,strong) NSArray*   histories;

/// 押印履歴の最終更新日が設定されます。
@property(nonatomic,strong) NSDate*     historiesUpdatedDate;



#pragma mark - class methods

/**
 スタンプカード一覧
 
 APIサーバからスタンプカードの一覧を取得してOffersStampCardインスタンスの配列を返します。
 
 @return スタンプカード情報の配列
 */
+(NSArray*)stampCards;

/**
 スタンプカード一覧
 
 APIサーバからスタンプカードの一覧を取得してOffersStampCardインスタンスの配列を返します。
 
 @param code メソッドの処理結果をあらわすステータスコードを格納するOffersKitStatusCode型の変数へのポインタ
 @return スタンプカード情報の配列
 */
+(NSArray*)stampCardsWithStatus:(OffersKitStatusCode*)code;

/**
 
 現在配布されているスタンプカードの一覧取得
 
 APIサーバへの接続の有無を指定してスタンプカードの一覧を取得します。その後、ブロックを実行します。
 
 @param block メソッドの実行後に呼び出される処理を記述したブロックを指定します。このブロックは実行結果を表すステータスコードと配布されているスタンプカードの一覧を受け取ります。
 
 @see OffersKitStatusCode
 
 */
+(void)stampCardsWithCallbackBlock:(void(^)(OffersKitStatusCode code, NSArray* stampCards))block;


/**
 現在配布されているスタンプカードの一覧を取得
 
 APIサーバへの接続の有無を指定してスタンプカードの一覧を取得します。
 
 @param onlineFlag APIサーバへの接続の有無を指定する真偽値を指定します。APIサーバに接続してスタンプカード一覧を取得する場合は真、キャッシュされているクーポン一覧を取得する場合は偽を指定します。
 @param parameter WebAPIに送信する追加のパラメータを指定します。
 
 @return OffersStampCardクラスのインスタンスが格納された配列
 
 */
+(NSArray*)stampCardsWithOnlineFlag:(BOOL)onlineFlag withParameter:(NSDictionary*)parameter;

/**
 現在配布されているスタンプカードの一覧を取得
 
 APIサーバへの接続の有無を指定してスタンプカードの一覧を取得します。
 
 @param onlineFlag APIサーバへの接続の有無を指定する真偽値を指定します。APIサーバに接続してスタンプカード一覧を取得する場合は真、キャッシュされているスタンプカード一覧を取得する場合は偽を指定します。
 @param parameter WebAPIに送信する追加のパラメータを指定します。
 @param code 実行結果を格納するOffersKitStatusCode変数へのポインタ。APIサーバからスタンプカード一覧を取得できたときもキャッシュされているスタンプカードの一覧を取得したときもOffersKitStatusSuccessが設定されます。
 
 @return OffersStampCardクラスのインスタンスが格納された配列
 
 @see OffersKitStatusCode
 
 */
+(NSArray*)stampCardsWithOnlineFlag:(BOOL)onlineFlag withParameter:(NSDictionary*)parameter status:(OffersKitStatusCode*)code;

/**
 現在配布されているスタンプカードの一覧を取得
 
 APIサーバへ接続してスタンプカードの一覧を取得します。
 
 @param parameter WebAPIに送信する追加のパラメータを指定します。
 @param block メソッドの実行後に呼び出される処理を記述したブロックを指定します。このブロックは実行結果を表すステータスコードと配布されているスタンプカードの一覧を受け取ります。
 
 @see OffersKitStatusCode
 
 */
+(void)stampCardsWithParameter:(NSDictionary*)parameter withCallbackBlock:(void(^)(OffersKitStatusCode code, NSArray* stampCards))block;

/**
 現在配布されているスタンプカードの一覧を取得
 
 APIサーバへの接続の有無を指定してスタンプカードの一覧を取得します。
 
 @param onlineFlag APIサーバへの接続の有無を指定する真偽値を指定します。APIサーバに接続してスタンプカード一覧を取得する場合は真、キャッシュされているスタンプカード一覧を取得する場合は偽を指定します。
 @param parameter WebAPIに送信する追加のパラメータを指定します。
 @param block メソッドの実行後に呼び出される処理を記述したブロックを指定します。このブロックは実行結果を表すステータスコードと配布されているスタンプカードの一覧を受け取ります。
 
 @see OffersKitStatusCode
 
 */
+(void)stampCardsWithOnlineFlag:(BOOL)onlineFlag withParameter:(NSDictionary*)parameter withCallbackBlock:(void(^)(OffersKitStatusCode code, NSArray* stampCards))block;


/**
 スタンプカード詳細情報の読み込み
 
 APIサーバへの接続の有無を指定してクーポンの詳細情報を読み込みます。
 
 @param onlineFlag 真を指定するとAPIサーバに接続して詳細情報を読み込みます。偽を指定するとローカルキャッシュから詳細情報を読み込みます。
 @param block メソッドの実行後に処理する内容を記述したブロックを指定します。このブロックはメソッドの実行結果を表すステータスコードを受け取ります。
 
 @see isLoadedDetail
 @see OffersKitStatusCode
 
 */
-(void)loadDetailWithOnlineFlag:(BOOL)onlineFlag withCallbackBlock:(OffersKitCallback)block;


    

/**

 プレゼント取得
 
 APIサーバーへ接続しプレゼントを取得します。
 
 @param stamp_card_id スタンプカードID
 @param block メソッドの実行後に処理する内容を記述したブロックを指定します。このブロックはメソッドの実行結果を表すステータスコードを受け取ります。

 */
+(void)presentsWithStampCardId:(int)stamp_card_id withCallbackBlock:(void(^)(OffersKitStatusCode code, NSDictionary* presents))block;



/**

 スタンプカード押印履歴登録
 
 APIサーバーヘ接続しスタンプカードの押印履歴を登録し、OffersStampActionの配列を返します。
 
 @param grid_id グリッドID
 @param x X座標
 @param y Y座標
 @param width 画像の幅
 @param height 画像の高さ
 @param angle 角度
 @param stamp_id スタンプID
 @param block メソッドの実行後に処理する内容を記述したブロックを指定します。このブロックはメソッドの実行結果を表すステータスコードを受け取ります。
 
 @see apply onlineRequired
 
 @warnning 当該スタンプカードのonlineRequiredプロパティが真の場合、オフライン状態では押印登録できません。
 
 @see OffersKitStatusCode
 
 */
-(void)stamp:(int)grid_id x:(int)x y:(int)y width:(int)width height:(int)height angle:(int)angle stamp_id:(int)stamp_id block:(void(^)(OffersKitStatusCode code, NSArray* actions ))block;

    
@end
