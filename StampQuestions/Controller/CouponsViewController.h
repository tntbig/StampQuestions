//
//  CouponsViewController.h
//  
//
//  Created by Nguyen Truong Nguyen on 5/26/15.
//
//

#import <UIKit/UIKit.h>

@interface CouponsViewController : UIViewController

@property (strong, nonatomic) IBOutlet UITableView *couponsTbl;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *menuSlide;

@property (strong, nonatomic) NSArray *couponList;
@property(nonatomic,strong) NSTimer *updateTimer;
@property(nonatomic,strong) NSArray *targetGroups;

@end
