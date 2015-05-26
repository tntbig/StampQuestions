//
//  DetailsStampViewController.m
//  StampQuestions
//
//  Created by Nguyen Truong Nguyen on 5/22/15.
//  Copyright (c) 2015 Nguyen Truong Nguyen. All rights reserved.
//

#import "DetailsStampViewController.h"
#import "SWRevealViewController.h"
#import <offerskit/OffersStampAction.h>

#import <AudioToolbox/AudioServices.h>
#import <AVFoundation/AVFoundation.h>

@interface DetailsStampViewController ()

@property (nonatomic) OffersCoupon *coupon;
@property (nonatomic) OffersCouponView *stampKitView;
@property(nonatomic,strong) NSArray* itemList;

@end

@implementation DetailsStampViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    // Load Menu
    SWRevealViewController *revealViewController = self.revealViewController;
    if ( revealViewController )
    {
        [self.sidebarButton setTarget: self.revealViewController];
        [self.sidebarButton setAction: @selector( revealToggle: )];
        [self.view addGestureRecognizer:self.revealViewController.panGestureRecognizer];
    }
    
    self.stampCardView = [[OffersStampCardView alloc] init];
    self.stampCardView.delegate = self;
    self.stampCardView.debug = false;
    
    [self.view addSubview:self.stampCardView];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    NSDictionary* params = @{
                             @"offset":         @"0",
                             @"limit":          @"1",
                             @"sort_target":    @"delivery_from",
                             @"sort_direction": @"descending"
                             };
    [OffersStampCard stampCardsWithOnlineFlag:YES withParameter:params withCallbackBlock:^(OffersKitStatusCode code, NSArray *stampCards) {
        dispatch_async(dispatch_get_main_queue(), ^{
            self.itemList = stampCards;
            NSLog(@"Count: %ld", (long)self.itemList.count );
            NSLog(@"StatusCode: %ld", (long)code );
            if(self.itemList.count>0){
                self.stampCard = [self.itemList objectAtIndex:0];
            }
            [self.stampCard loadDetailWithOnlineFlag:YES withCallbackBlock:^( OffersKitStatusCode code ){
                
                if( code == OffersKitStatusSuccess ) {
                    if(self.stampCard.isLoadedDetail == YES){
                        dispatch_async(dispatch_get_main_queue(), ^{
                            if(self.stampCard.backgroundImage != nil){
                                CGRect frame = AVMakeRectWithAspectRatioInsideRect(self.stampCard.backgroundImage.size, self.imgStamp.bounds);
                                frame.origin.x = 0;
                                frame.origin.y = 0;
                                self.imgStamp.frame = frame;
                            }
                            self.imgStamp.image = self.stampCard.backgroundImage;
                        });
                        
                        [self setStampCard];
                        
                    }else{
                        [MessageHelper showOkOnlyAlertWithTitle:@"Detail Error" message:@"Detail Error"];
                    }
                    
                }else{
                    [MessageHelper showOkOnlyAlertWithTitle:@"Error" message:@"Download Error"];
                }
            }];
        });
    }];
    self.imgStamp.image = self.stampCard.backgroundImage;
}
-(void)setStampCard{
    
    [self.stampCardView setCard:self.stampCard.grids keepOrder:self.stampCard.keepOrder groups:self.stampCard.stampGroups histories:self.stampCard.histories];
    
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
