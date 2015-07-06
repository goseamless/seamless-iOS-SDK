//
//  SLCollectionViewAdManager.h
//  Seamless
//
//  Created by Mehmet Can Yavuz on 29.05.2014.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UICollectionView.h>
#import <UIKit/UICollectionViewCell.h>
#import "SLBaseAdManager.h"
#import "SLManager.h"
#import "SLNativeAdRendering.h"

@protocol SLCollectionViewAdManagerDelegate
@optional
-(void)adInsertedCollectionViewAtIndexPath:(NSIndexPath *)indexPath;
-(void)setSeamlessAd:(SLAd*)ad viewController:(id)viewController;
@end

@interface SLCollectionViewAdManager : SLBaseAdManager

@property (nonatomic, weak) id delegate;
@property(nonatomic, assign) SLGender gender;
@property(nonatomic, copy) NSDate *birthday;
@property(nonatomic, copy) NSString *contentURL;
@property(assign) BOOL childDirectedTreatment;
@property(nonatomic, strong) CLLocation *location;


-(id)initWithCollectionView:(UICollectionView*)collectionView
                 dataSource:(NSMutableArray*)dataSource
             viewController:(id)viewController;

-(void)getAdsWithEntity:(NSString*)entity
               category:(SLCategory)category
           successBlock:(void(^)(void))successBlock
           failureBlock:(void(^)(NSError * error))failureBlock;

-(void)setCustomNativeView:(UIView<SLNativeAdRendering> *)customView;

-(BOOL)shouldShowAdAtIndexPath:(NSIndexPath*)indexPath;

-(UICollectionViewCell *)cellForItemAtIndexPath:(NSIndexPath *)indexPath;

-(CGSize)sizeForItemAtIndexPath:(NSIndexPath *)indexPath;

-(void)changeDataSource:(NSMutableArray *)dataSource;

-(void)didSelectItemAtIndexPath:(NSIndexPath *)indexPath;

-(void)cleanDataSource;

-(NSInteger)indexWithoutAds:(NSInteger)index;

-(void)clean;

@end
