//
//  SLCustomNativeAdManager.h
//  Seamless
//
//  Created by Suzy Kang on 25/06/15.
//  Copyright (c) 2015 Mobilike. All rights reserved.
//

#import "SLManager.h"
#import "SLBaseAdManager.h"
#import "MPNativeAdDelegate.h"
#import "SLNativeAdRendering.h"

@class SLCustomNativeView;

@protocol SLCustomNativeAdDelegate
@optional
- (void)customNativeAdDidLoad:(UIView<SLNativeAdRendering>*)adView;

- (void)customNativeAdDidFailToLoad:(UIView<SLNativeAdRendering>*)adView;

@end


@interface SLCustomNativeAdManager : SLBaseAdManager <MPNativeAdDelegate>

@property (nonatomic, weak) id delegate;

- (instancetype)initWithEntity:(NSString *)entity
                      category:(SLCategory)category
                    customView:(UIView<SLNativeAdRendering> *)customView
            rootViewController:(UIViewController *)viewController;

-(void)loadAd;

@end
