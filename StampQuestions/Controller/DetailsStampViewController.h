//
//  DetailsStampViewController.h
//  StampQuestions
//
//  Created by Nguyen Truong Nguyen on 5/22/15.
//  Copyright (c) 2015 Nguyen Truong Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Offerskit/Offerskit.h>
#import <leonis/leonis.h>
#import <Offerskit/OffersStampCardView.h>

@interface DetailsStampViewController : UIViewController

@property (weak, nonatomic) IBOutlet UIImageView *imgStamp;
@property (nonatomic, weak) IBOutlet UIBarButtonItem *sidebarButton;
@property (nonatomic,strong) OffersStampCard * stampCard;
@property (nonatomic) OffersStampCardView * stampCardView;

@end
