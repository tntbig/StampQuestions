//
//  ViewController.m
//  StampQuestions
//
//  Created by Nguyen Truong Nguyen on 5/21/15.
//  Copyright (c) 2015 Nguyen Truong Nguyen. All rights reserved.
//

#import "ViewController.h"
#import "SWRevealViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIWebView *webView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self loadWebView];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)loadWebView {
    // Remember that bundle resources do *not* have directories so all filenames must be unique.
    NSBundle *mainBundle = [NSBundle mainBundle];
    NSURL *homeIndexUrl = [mainBundle URLForResource:@"options" withExtension:@"html"];
    
    // The magic is loading a request, *not* using loadHTMLString:baseURL:
    NSURLRequest *urlReq = [NSURLRequest requestWithURL:homeIndexUrl];
    [self.webView loadRequest:urlReq];
}

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType{
//        NSString *result = [webView stringByEvaluatingJavaScriptFromString:@"callAct()"];
//        if ([result isEqualToString:@"true"]){
//            UIStoryboard *storyBoard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
//            DetailsStampViewController *mainView = [storyBoard instantiateViewControllerWithIdentifier:@"DetailsStampViewController"];
//            [[UIApplication sharedApplication].keyWindow setRootViewController:mainView];
//        }
    NSURL *URL = [request URL];
    if ([[URL scheme] isEqualToString:@"callbacktomain"]) {
        NSString *urlString = [[request URL] absoluteString];
        NSArray *urlParts = [urlString componentsSeparatedByString:@":"];
        //check to see if we just got the scheme
        if ([urlParts count] > 1) {
            NSArray *parameters = [[urlParts objectAtIndex:1] componentsSeparatedByString:@"&"];
            NSString *job = [parameters objectAtIndex:0];
            NSString *age = [parameters objectAtIndex:1];
            NSString *gender = [parameters objectAtIndex:2];
            NSString *city = [parameters objectAtIndex:3];
            
            NSString *message = [NSString stringWithFormat:@"%@ === %@ === %@ === %@", job, age, gender, city];
            
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Great" message:message delegate: self cancelButtonTitle: nil otherButtonTitles: @"OK",nil, nil];
    
            UIStoryboard * storyboard = self.storyboard;
            SWRevealViewController *rvControl = (SWRevealViewController *) [storyboard instantiateViewControllerWithIdentifier:@"SWRevealViewController"];
            [self presentViewController:rvControl animated:false completion:nil];
            
        }
    }
    
    return true;
}
@end
