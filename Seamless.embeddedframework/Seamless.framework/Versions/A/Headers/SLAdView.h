//
//  SLAdView.h
//  Seamless
//
//  Created by Mehmet Can Yavuz on 5.06.2014.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MPAdView.h"
#import "SLManager.h"
#import "GADBannerViewDelegate.h"

#define SLAdSizeMMA             CGSizeMake(320, 50)
#define SLAdSizeMRect           CGSizeMake(300, 250)
#define SLAdSizeLeaderboard     CGSizeMake(728, 90)

@class SLAdView;

@protocol SLAdViewDelegate
@optional
- (void)adViewDidLoad:(SLAdView *)adView;

- (void)adViewDidFailToLoad:(SLAdView *)adView;

@end

@interface SLAdView : UIView <MPAdViewDelegate, GADBannerViewDelegate>

@property (nonatomic, weak) id delegate;

- (instancetype)initWithEntity:(NSString *)entity
                      category:(SLCategory)category
                        adSize:(CGSize)adSize
            rootViewController:(UIViewController *)viewController;

- (void)loadAd;

- (void)stopAutomaticallyRefreshing;

- (void)startAutomaticallyRefreshing;

@end
