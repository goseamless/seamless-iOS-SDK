//
//  SLCustomNativeView.h
//  Seamless
//
//  Created by Suzy Kang on 16/06/15.
//  Copyright (c) 2015 Mobilike. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SLCustomNativeView : UIView

// star rating could be nil.
@property (nonatomic, strong) NSNumber *starRating;
@property (nonatomic, strong) NSURL *iconImageUrl;
@property (nonatomic, strong) NSURL *mainImageUrl;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *mainText;
@property (nonatomic, strong) NSString *callToAction;
@property (nonatomic, strong) NSString *socialContext;

///////
// Override this method to set images and text.
-(void)layoutAdAssets;
///////

// Use this method to load icon efficiently.
- (void)loadIconIntoImageView:(UIImageView *)imageView;

// Use this method to load main image efficiently.
- (void)loadImageIntoImageView:(UIImageView *)imageView;

-(CGRect)getContainerFrame;


@end
