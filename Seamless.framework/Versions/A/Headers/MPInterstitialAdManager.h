//
//  MPInterstitialAdManager.h
//  MoPub
//
//  Copyright (c) 2012 MoPub, Inc. All rights reserved.
//

#import "MPAdServerCommunicator.h"
#import "MPBaseInterstitialAdapter.h"

@class CLLocation, MPAdWebView;
@protocol MPInterstitialAdManagerDelegate;

@interface MPInterstitialAdManager : NSObject <MPAdServerCommunicatorDelegate,
    MPInterstitialAdapterDelegate>

@property (nonatomic, weak) id<MPInterstitialAdManagerDelegate> delegate;
@property (nonatomic, assign, readonly) BOOL ready;

- (id)initWithDelegate:(id<MPInterstitialAdManagerDelegate>)delegate;

- (void)loadInterstitialWithAdUnitID:(NSString *)ID
                            keywords:(NSString *)keywords
                            location:(CLLocation *)location
                             testing:(BOOL)testing;
- (void)presentInterstitialFromViewController:(UIViewController *)controller;

- (void)dismissInterstitial;
- (MPAdWebView *)getWebView;

@end
