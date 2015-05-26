//
//  CouponsViewController.m
//  
//
//  Created by Nguyen Truong Nguyen on 5/26/15.
//
//

#import "CouponsViewController.h"
#import <OffersKit/OffersKit.h>
#import "CouponViewCell.h"

@interface CouponsViewController ()

@end

@implementation CouponsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    // Load Menu
    SWRevealViewController *revealViewController = self.revealViewController;
    if ( revealViewController )
    {
        [self.menuSlide setTarget: self.revealViewController];
        [self.menuSlide setAction: @selector( revealToggle: )];
        [self.view addGestureRecognizer:self.revealViewController.panGestureRecognizer];
    }

}

-(void) viewDidAppear:(BOOL)animated{
    if(self.couponList == nil){
        [self loadCoupons];
    }
}

- (void) viewWillDisappear:(BOOL)animated{
    [self.updateTimer invalidate];
    self.updateTimer = nil;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) loadCoupons{
    [self.updateTimer invalidate];
    
    OffersCouponsCallback block = ^( OffersKitStatusCode code, NSArray *coupons) {
        NSLog(@"%lu",coupons.count);
        self.couponList = coupons;
        [self startTimer];
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.couponsTbl reloadData];
//            if( self.updateTimer != nil ) {
//                [self.updateTimer invalidate];
//            }
//            self.updateTimer = [NSTimer scheduledTimerWithTimeInterval:3.0f
//                                                                target:self
//                                                              selector:@selector(updateRemaingTime:)
//                                                              userInfo:nil
//                                                               repeats:YES
//                                ];
        });
    };
    
    if( [self.targetGroups count] == 0 ) {
        [OffersCoupon couponsWithCallbackBlock:block];
    }
    else {
        [OffersCoupon couponsForShops:self.targetGroups withCallbackBlock:block];
    }

}

-(void)startTimer
{
    if( [self.couponList count] > 0 ) {
        self.updateTimer =
        [NSTimer scheduledTimerWithTimeInterval:3.0f
                                         target:self
                                       selector:@selector(updateRemaingTime:)
                                       userInfo:nil
                                        repeats:YES
         ];
    }
}

-(void)updateRemaingTime:(id)sender
{
    if( self.couponsTbl.dragging == NO && self.couponsTbl.decelerating == NO ) {
        for( NSIndexPath* indexPath in [self.couponsTbl indexPathsForVisibleRows] ) {
            OffersCoupon* aCoupon = [self.couponList objectAtIndex:indexPath.row];
            [aCoupon loadImagesWithCallbackBlock:^( BOOL result ) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self.couponsTbl reloadData];
                });
            }];
            [aCoupon loadLiveDataWithCallbackBlock:^(OffersKitStatusCode code) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    if( self.couponsTbl.dragging == NO && self.couponsTbl.decelerating == NO ) {
#ifdef SHOW_REMAINING_TIME
                        [self setRemainingTime:aCoupon
                                          cell:[self.couponsTbl cellForRowAtIndexPath:indexPath]
                         ];
#endif
                        [self.couponsTbl reloadRowsAtIndexPaths:[NSArray arrayWithObject:indexPath]
                                              withRowAnimation:UITableViewRowAnimationNone
                         ];
                    }
                });
            }
             ];
        }
    }
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.couponList.count;
}

// Row display. Implementers should *always* try to reuse cells by setting each cell's reuseIdentifier and querying for available reusable cells with dequeueReusableCellWithIdentifier:
// Cell gets various attributes set automatically based on table (separators) and data source (accessory views, editing controls)

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    static NSString *simpleTableIdentifier = @"CouponViewCell";
    CouponViewCell *cell = (CouponViewCell *)[tableView dequeueReusableHeaderFooterViewWithIdentifier:simpleTableIdentifier];
    if (cell == nil)
    {
        NSArray *nib = [[NSBundle mainBundle] loadNibNamed:@"CouponsCell" owner:self options:nil];
        cell = [nib objectAtIndex:0];
    }
    cell.couponIMG.image = nil;
    
    return nil;
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
