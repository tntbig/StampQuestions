//
//  CouponViewCell.h
//  StampQuestions
//
//  Created by Nguyen Truong Nguyen on 5/26/15.
//  Copyright (c) 2015 Nguyen Truong Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CouponViewCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UILabel *couponTitle;
@property (weak, nonatomic) IBOutlet UIImageView *couponIMG;
@property (weak, nonatomic) IBOutlet UILabel *couponDescription;
@property (weak, nonatomic) IBOutlet UILabel *couponTime;
@property (weak, nonatomic) IBOutlet UILabel *couponCondition;

@end
