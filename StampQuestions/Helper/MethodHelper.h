//
//  MethodHelper.h
//  LeonisSaleDemo
//
//  Created by leo-mobile-lily on 12/24/14.
//  Copyright (c) 2014 Leonis&Co. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MethodHelper : NSObject

+(NSString*)dateFormatDateToString:(NSDate*)date forCalendarFormat:(NSString *) format;
+(NSDate*)dateFormatStringToDate:(NSString *)dateString format:(NSString *) format locale:(NSString*)locale;

+(void)showErrorMessage:(NSString*)txt;

/*文字列からNSUrlへ変換*/
+(NSURL*)url:(NSString*)strUrl;


//--------url response-------
+(NSDictionary*)requestResponseData:(NSData*)responseData;

+(NSString*)stringTrim:(NSString*)string;
@end
