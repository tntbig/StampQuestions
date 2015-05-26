//
//  MessageHelper.m
//  StampQuestions
//
//  Created by Nguyen Truong Nguyen on 5/26/15.
//  Copyright (c) 2015 Nguyen Truong Nguyen. All rights reserved.
//

#import "MessageHelper.h"

static NSMutableArray* alertControllerList;

@interface MessageHelper()
{
    id          _alertPresenter;
    BOOL        _acceptTextInput;
    NSString*   _placeHolder;
}
@end

@implementation MessageHelper

#pragma mark - Initializers

-(id)init
{
    self = [super init];
    if(self) {
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
            alertControllerList = [[NSMutableArray alloc] init];
        });
        [alertControllerList addObject:self];
        _positiveButtonTitle = @"OK";
    }
    return self;
}

-(id)initWithTitle:(NSString*)title message:(NSString*)message
{
    self = [self init];
    if(self) {
        _title      = title;
        _message    = message;
    }
    return self;
}

-(id)initWithTitle:(NSString*)title message:(NSString*)message
positiveButtonTitle:(NSString*)positiveButtonTitle
    possitiveBlock:(MessageHelperCallback)positiveBlock
negativeButtonTitle:(NSString*)negativeButtonTitle
     negativeBlock:(MessageHelperCallback)negativeBlock
{
    self = [self init];
    if(self) {
        _title                  = title;
        _message                = message;
        _positiveButtonTitle    = positiveButtonTitle;
        _positiveBlock          = positiveBlock;
        _negativeButtonTitle    = negativeButtonTitle;
        _negativeBlock          = negativeBlock;
    }
    return self;
}

#pragma mark - Convenience Methods

+(void)showOkOnlyAlertWithTitle:(NSString*)title message:(NSString*)message
{
    [self showPositiveOnlyAlertWithTitle:title message:message positiveButtonTitle:@"OK"];
}

+(void)showPositiveOnlyAlertWithTitle:(NSString*)title message:(NSString*)message positiveButtonTitle:(NSString*)positiveButtonTitle
{
    MessageHelper* controller = [[MessageHelper alloc] initWithTitle:title message:message];
    controller.positiveButtonTitle = positiveButtonTitle;
    [controller showAlert];
}

#pragma mark - Public methods

-(void)acceptTextInput
{
    [self acceptTextInputWithPlaceholder:nil];
}

-(void)acceptTextInputWithPlaceholder:(NSString*)placeHolder
{
    _acceptTextInput = YES;
    _placeHolder     = placeHolder;
}

-(void)showAlert
{
    Class alertControllerClass = NSClassFromString(@"UIAlertController");
    if(alertControllerClass == nil) {
        // UIAlertController未対応
        [self showAlertView];
    }
    else {
        // UIAlertController対応
        [self showAlertController];
    }
}

-(void)showAlertView
{
    UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:self.title
                                                        message:self.message
                                                       delegate:self
                                              cancelButtonTitle:self.negativeButtonTitle
                                              otherButtonTitles:self.positiveButtonTitle, nil
                              ];
    if( _acceptTextInput == YES ) {
        alertView.alertViewStyle = UIAlertViewStylePlainTextInput;
        [alertView textFieldAtIndex:0].placeholder = _placeHolder;
    }
    _alertPresenter = alertView;
    dispatch_async(dispatch_get_main_queue(), ^{
        [alertView show];
    });
}

-(void)showAlertController
{
    UIAlertController* alertController =
    [UIAlertController alertControllerWithTitle:self.title
                                        message:self.message
                                 preferredStyle:UIAlertControllerStyleAlert
     ];
    if( self.positiveButtonTitle != nil ) {
        UIAlertAction* positiveAction = [UIAlertAction actionWithTitle:self.positiveButtonTitle
                                                                 style:UIAlertActionStyleDefault
                                                               handler:^(UIAlertAction* action){
                                                                   [self positiveButtonPressed];
                                                               }
                                         ];
        [alertController addAction:positiveAction];
    }
    if(self.negativeButtonTitle != nil) {
        UIAlertAction* negativeAction = [UIAlertAction actionWithTitle:self.negativeButtonTitle
                                                                 style:UIAlertActionStyleDefault
                                                               handler:^(UIAlertAction* action){
                                                                   [self negativeButtonPressed];
                                                               }
                                         ];
        [alertController addAction:negativeAction];
    }
    if( _acceptTextInput == YES ) {
        [alertController addTextFieldWithConfigurationHandler:^(UITextField *textField) {
            if( _placeHolder != nil ) {
                textField.placeholder = _placeHolder;
            }
        }];
    }
    _alertPresenter = alertController;
    dispatch_async(dispatch_get_main_queue(), ^{
        [[self rootViewController] presentViewController:alertController
                                                animated:YES
                                              completion:nil];
    });
}

-(NSString*)stringOfTextField
{
    NSString* result = nil;
    if( _acceptTextInput == NO ) {
        return result;
    }
    if( [_alertPresenter isKindOfClass:[UIAlertController class]] == YES ) {
        // UIAlertController
        UIAlertController* alertController = _alertPresenter;
        UITextField* textField = (UITextField*)alertController.textFields.firstObject;
        result = textField.text;
    }
    else if( [_alertPresenter isKindOfClass:[UIAlertView class]] == YES ) {
        // UIAlertView
        UIAlertView* alertView = _alertPresenter;
        UITextField* textField = [alertView textFieldAtIndex:0];
        result = textField.text;
    }
    return result;
}

#pragma mark - Private methods

-(void)positiveButtonPressed
{
    if(self.positiveBlock != nil) {
        self.positiveBlock(self);
    }
    [self didClose];
}

-(void)negativeButtonPressed
{
    if(self.negativeBlock != nil) {
        self.negativeBlock(self);
    }
    [self didClose];
}

-(void)didClose
{
    [alertControllerList removeObject:self];
}

#pragma mark - Tools

-(UIViewController*)rootViewController
{
    return [[[UIApplication sharedApplication] keyWindow] rootViewController];
}

#pragma mark - UIAlertViewDelegate

-(void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex
{
    NSString* buttonTitle = [alertView buttonTitleAtIndex:buttonIndex];
    if([buttonTitle isEqualToString:self.positiveButtonTitle] == YES) {
        [self positiveButtonPressed];
    }
    else {
        [self negativeButtonPressed];
    }
}

@end
