//
//  MPNativeAd.h
//  Copyright (c) 2013 MoPub. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <FBAudienceNetwork/FBAudienceNetwork.h>

@protocol MPNativeAdAdapter;
@protocol MPNativeAdDelegate;
@protocol MPNativeAdRenderer;
@class MPAdConfiguration;

/**
 * The `MPNativeAd` class is used to render and manage events for a native advertisement. The
 * class provides methods for accessing native ad properties returned by the server, as well as
 * convenience methods for URL navigation and metrics-gathering.
 */

@interface MPNativeAd : NSObject

@property (nonatomic, assign) BOOL visible;
- (void)willAttachToView:(UIView *)view;
- (void)displayAdContent;
- (void)trackImpression;
- (void)addGesture;

/** @name Ad Resources */

/**
 * The delegate of the `MPNativeAd` object.
 */
@property (nonatomic, weak) id<MPNativeAdDelegate> delegate;

/**
 * A dictionary representing the native ad properties.
 */
@property (nonatomic, readonly) NSDictionary *properties;

- (instancetype)initWithAdAdapter:(id<MPNativeAdAdapter>)adAdapter;

/** @name Retrieving Ad View */

/**
 * Retrieves a rendered view containing the ad.
 *
 * @param error A pointer to an error object. If an error occurs, this pointer will be set to an
 * actual error object containing the error information.
 *
 * @return If successful, the method will return a view containing the rendered ad. The method will
 * return nil if it cannot render the ad data to a view.
 */
- (UIView *)retrieveAdViewWithError:(NSError **)error;

- (void)trackMetricForURL:(NSURL *)URL;

/**
 * Loads the ad object's social context text into the provided label.
 *
 * @param label A label.
 */
- (void)loadsocialContextTextIntoLabel:(UILabel *)label;

/* Onur added */
- (UIView *)privacyInformationIconView;
@property (nonatomic, strong) FBNativeAd *nativeAd;

/**
 * Adds Facebook AdChoiceView to given parent view (parentView) if the MoPub ad is coming from Facebook ads.
 *
 * @param adViewComponents NSArray indicates all the subviews in the ad view. Please specify all the components which sould be clickable for the Facebook ad.
 * @param parentView UIView which the adChoiceView will be inserted as subview.
 * @param contentView UIView which is the Ad View.
 *
 */
- (void)setFBAdChoicesView:(NSArray *)adViewComponents
            withParentView:(UIView *)parentView
           withContentView:(UIView *)contentView;
- (void)loadIconIntoImageView:(UIImageView *)imageView;
- (void)loadImageIntoImageView:(UIImageView *)imageView;
- (void)loadTitleIntoLabel:(UILabel *)label;
- (void)loadTextIntoLabel:(UILabel *)label;
- (void)loadCallToActionTextIntoLabel:(UILabel *)label;
- (void)loadCallToActionTextIntoButton:(UIButton *)button;


@end
