//
//  SLAppearance.h
//  Seamless
//
//  Created by Mehmet Can Yavuz on 16.07.2014.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface SLAppearance : NSObject
@property (nonatomic, strong) UIColor * cellBackgroundColor;

@property (nonatomic, strong) UIColor * containerBackgroundColor;
@property (nonatomic, strong) UIColor * containerBorderLineColor;
@property (nonatomic) UIEdgeInsets containerEdgeInsets;
@property (nonatomic) CGFloat containerBorderWidth;
@property (nonatomic) CGFloat containerCornerRadius;

@property (nonatomic, strong) UIColor * maiaAdHeaderBackgroundColor;
@property (nonatomic, strong) UIColor * maiaAdFooterBackgroundColor;
@property (nonatomic, strong) UIColor * maiaAdBorderLineColor;
@property (nonatomic) CGFloat maiaAdBorderWidth;
@property (nonatomic) CGFloat maiaAdCornerRadius;

@property (nonatomic, strong) UIFont * maiaContainerTitleFont;
@property (nonatomic, strong) UIFont * maiaAppNameFont;
@property (nonatomic, strong) UIFont * maiaDescriptionFont;
@property (nonatomic, strong) UIFont * maiaSponsorFont;
@property (nonatomic, strong) UIFont * maiaCTAFont;
@property (nonatomic, strong) UIFont * maiaDownloadInfoFont;
@property (nonatomic, strong) UIFont * maiaTaglineFont;

@property (nonatomic, strong) UIColor * maiaContainerTitleTextColor;
@property (nonatomic, strong) UIColor * maiaAppNameTextColor;
@property (nonatomic, strong) UIColor * maiaDescriptionTextColor;
@property (nonatomic, strong) UIColor * maiaSponsorTextColor;
@property (nonatomic, strong) UIColor * maiaCTATextColor;
@property (nonatomic, strong) UIColor * maiaDownloadInfoTextColor;
@property (nonatomic, strong) UIColor * maiaTaglineTextColor;

@property (nonatomic) CGFloat displayAdTopInset;
@property (nonatomic) CGFloat displayAdBottomInset;

@property (nonatomic, strong) UIImage * ctaButtonImage;
@property (nonatomic, strong) UIColor * maiaCtaButtonBackgroundColor;

@property (nonatomic) UITableViewRowAnimation tableViewRowAnimation;

@property (nonatomic) CGSize collectionViewPortraitCellSize;
@property (nonatomic) CGSize collectionViewLandscapeCellSize;
@end
