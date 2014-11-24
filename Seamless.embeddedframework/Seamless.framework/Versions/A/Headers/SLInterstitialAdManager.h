//
//  SLInterstitialAdManager.h
//  Seamless
//
//  Created by Mehmet Can Yavuz on 3.06.2014.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MPInterstitialAdController.h"
#import "SLManager.h"

@protocol SLInterstitialAdManagerDelegate
-(void)interstitialDidLoad:(MPInterstitialAdController *)interstitial;
-(void)interstitialDidFailToLoad:(MPInterstitialAdController *)interstitial;
@end

@interface SLInterstitialAdManager : NSObject <MPInterstitialAdControllerDelegate>
@property (nonatomic) BOOL landscapeModeEnabled;
@property (nonatomic, weak) id delegate;

- (id)initWithEntity:(NSString *)entity
            category:(SLCategory)category;

- (void)loadAd;
@end
