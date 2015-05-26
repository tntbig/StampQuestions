//
//  WeblinkViewController.m
//  StampQuestions
//
//  Created by Nguyen Truong Nguyen on 5/26/15.
//  Copyright (c) 2015 Nguyen Truong Nguyen. All rights reserved.
//

#import "WeblinkViewController.h"

@interface WeblinkViewController ()

@end

@implementation WeblinkViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    // Load Menu
    SWRevealViewController *revealViewController = self.revealViewController;
    if ( revealViewController )
    {
        [self.barBtn setTarget: self.revealViewController];
        [self.barBtn setAction: @selector( revealToggle: )];
        [self.view addGestureRecognizer:self.revealViewController.panGestureRecognizer];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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
