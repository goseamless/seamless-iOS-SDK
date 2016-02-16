//
//  SLNativeAdRendering.h
//  Seamless
//
//  Created by Suzy Kang on 30/06/15.
//  Copyright (c) 2015 Mobilike. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MPNativeAd.h"
@import GoogleMobileAds;
#import <GoogleMobileAds/GADNativeCustomTemplateAd.h>

@protocol SLNativeAdRendering <NSObject>

/**
 * Populates a view's relevant subviews with MoPub ad content.
 *
 * Your implementation of this method should call one or more of the methods listed below.
 *
 * @param adObject An object loaded from MoPub server containing ad assets (text, images) which may be loaded
 * into appropriate subviews (UILabel, UIImageView) via convenience methods.
 * @see [MPNativeAd loadTextIntoLabel:]
 * @see [MPNativeAd loadTitleIntoLabel:]
 * @see [MPNativeAd loadIconIntoImageView:]
 * @see [MPNativeAd loadImageIntoImageView:]
 * @see [MPNativeAd loadCallToActionTextIntoLabel:]
 * @see [MPNativeAd loadCallToActionTextIntoButton:]
 * @see [MPNativeAd loadImageForURL:intoImageView:]
 */
- (void)layoutAdAssets:(MPNativeAd *)adObject;


/**
 * Populates a view's relevant subviews with DFP ad content.
 *
 * Your implementation of this method should call one or more of the methods listed below.
 *
 * @param dfpObject An object loaded from DFP server containing ad assets (text, images) which may be loaded
 * into appropriate subviews (UILabel, UIImageView) via convenience methods.
 * @see [dfpObject stringForKey:<key>]
 * @see [dfpObject imageForKey:<key>]
 */
- (void)layoutAdAssetsDFP:(GADNativeCustomTemplateAd *)dfpObject;


@end
