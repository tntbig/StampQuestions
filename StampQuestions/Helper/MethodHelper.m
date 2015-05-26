//
//  MethodHelper.m
//  LeonisSaleDemo
//
//  Created by leo-mobile-lily on 12/24/14.
//  Copyright (c) 2014 Leonis&Co. All rights reserved.
//

#import "MethodHelper.h"

@implementation MethodHelper

+(NSString*)dateFormatDateToString:(NSDate*)date forCalendarFormat:(NSString *) format{
    if (!format) {
        format = @"%d/%02d/%02d %02d:%02d:%02d";
    }
    NSCalendar *calendar = [[NSCalendar alloc]
                            initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    NSDateComponents *dateComps = [calendar components:NSCalendarUnitYear |
                                   NSCalendarUnitMonth  |
                                   NSCalendarUnitDay    |
                                   NSCalendarUnitHour   |
                                   NSCalendarUnitMinute |
                                   NSCalendarUnitSecond
                                              fromDate:date];
    NSString *dt = [NSString stringWithFormat:format,
                    dateComps.year,
                    dateComps.month,
                    dateComps.day,
                    dateComps.hour,
                    dateComps.minute,
                    dateComps.second];
    
    return dt;
}

+(NSDate*)dateFormatStringToDate:(NSString *)dateString format:(NSString *) format locale:(NSString*)locale{
    NSDateFormatter *df = [[NSDateFormatter alloc] init];
    [df setDateFormat:format];
    [df setLocale:[[NSLocale alloc] initWithLocaleIdentifier:locale]];//重要！
    NSDate *date = [df dateFromString:dateString];
    
    return date;
}

+(void)showErrorMessage:(NSString*)txt{
//    CCCustomContentAlertView * alert = [[CCCustomContentAlertView alloc] initWithTitle:nil withType:CCCustomContentAlertViewType_ErrorMsg withText:txt];
//    [alert show];
}

+(NSURL*)url:(NSString*)strUrl{
    if (!strUrl) {
        return nil;
    }
    return [NSURL URLWithString:
            [strUrl stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
}

//-------url response-------------
+(NSDictionary*)requestResponseData:(NSData*)responseData{
    NSDictionary* rs;
    if (responseData)
    {
        NSError *parseError = nil;
        id json = [NSJSONSerialization JSONObjectWithData:responseData options:NSJSONReadingMutableContainers error:&parseError];
        
        if (json != nil)
        {
            rs = json;
        }
    }
    
    return rs;
}

+(NSString*)stringTrim:(NSString*)string{
    return [string stringByTrimmingCharactersInSet:
            [NSCharacterSet whitespaceCharacterSet]];
    
}

@end
