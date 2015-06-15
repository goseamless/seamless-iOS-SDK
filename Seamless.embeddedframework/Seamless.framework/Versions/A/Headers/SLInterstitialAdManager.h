//
//  SLInterstitialAdManager.h
//  Seamless
//
//  Created by Mehmet Can Yavuz on 3.06.2014.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MPInterstitialAdController.h"
#import <GoogleMobileAds/GADInterstitialDelegate.h>
#import "SLManager.h"

@class SLInterstitialAdManager;
@protocol SLInterstitialAdManagerDelegate

@required
- (void)interstitialDidLoad:(SLInterstitialAdManager *)interstitial;

@optional
- (void)interstitialDidFailToLoad:(SLInterstitialAdManager *)interstitial;

- (void)interstitialWillPresent:(SLInterstitialAdManager *)interstitial;

- (void)interstitialWillDismiss:(SLInterstitialAdManager *)interstitial;

- (void)interstitialDidDismiss:(SLInterstitialAdManager* )interstitial;

@end

@interface SLInterstitialAdManager : NSObject <MPInterstitialAdControllerDelegate, GADInterstitialDelegate>
@property (nonatomic) BOOL landscapeModeEnabled;
@property (nonatomic, weak) id delegate;
@property(nonatomic, assign) SLGender gender;
@property(nonatomic, copy) NSDate *birthday;
@property(nonatomic, copy) NSString *contentURL;
@property(assign) BOOL childDirectedTreatment;
@property(nonatomic, strong) CLLocation *location;

- (id)initWithEntity:(NSString *)entity
            category:(SLCategory)category;

- (void)loadAd;

- (void)showFromViewController:(UIViewController *)controller;

@end
