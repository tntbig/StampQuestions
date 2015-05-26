//
//  MessageHelper.h
//  StampQuestions
//
//  Created by Nguyen Truong Nguyen on 5/26/15.
//  Copyright (c) 2015 Nguyen Truong Nguyen. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MessageHelper;

typedef void (^MessageHelperCallback)(MessageHelper* controller);

@interface MessageHelper : NSObject<UIAlertViewDelegate>

@property(nonatomic, strong) NSString* title;
@property(nonatomic, strong) NSString* message;

@property(nonatomic, strong) NSString* positiveButtonTitle;
@property(nonatomic, strong) MessageHelperCallback positiveBlock;

@property(nonatomic, strong) NSString* negativeButtonTitle;
@property(nonatomic, strong) MessageHelperCallback negativeBlock;

+(void)showOkOnlyAlertWithTitle:(NSString*)title message:(NSString*)message;
+(void)showPositiveOnlyAlertWithTitle:(NSString*)title message:(NSString*)message positiveButtonTitle:(NSString*)positiveButtonTitle;

-(id)initWithTitle:(NSString*)title message:(NSString*)message;

-(id)initWithTitle:(NSString*)title message:(NSString*)message
positiveButtonTitle:(NSString*)positiveButtonTitle possitiveBlock:(MessageHelperCallback)positiveBlock
negativeButtonTitle:(NSString*)negativeButtonTitle negativeBlock:(MessageHelperCallback)negativeBlock;

-(void)acceptTextInput;
-(void)acceptTextInputWithPlaceholder:(NSString*)placeHolder;

-(void)showAlert;

-(void)showAlertView;
-(void)showAlertController;

-(NSString*)stringOfTextField;


@end
