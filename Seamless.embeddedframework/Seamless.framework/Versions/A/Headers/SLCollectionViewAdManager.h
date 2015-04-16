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

@protocol SLCollectionViewAdManagerDelegate
-(void)adInsertedCollectionViewAtIndexPath:(NSIndexPath *)indexPath;
@end

@interface SLCollectionViewAdManager : SLBaseAdManager

@property (nonatomic, weak) id delegate;

-(id)initWithCollectionView:(UICollectionView*)collectionView
                 dataSource:(NSMutableArray*)dataSource
             viewController:(id)viewController;

-(void)getAdsWithEntity:(NSString*)entity
               category:(SLCategory)category
           successBlock:(void(^)(void))successBlock
           failureBlock:(void(^)(NSError * error))failureBlock;

-(BOOL)shouldShowAdAtIndexPath:(NSIndexPath*)indexPath;

-(UICollectionViewCell *)cellForItemAtIndexPath:(NSIndexPath *)indexPath;

-(CGSize)sizeForItemAtIndexPath:(NSIndexPath *)indexPath;

-(void)changeDataSource:(NSMutableArray *)dataSource;

-(void)didSelectItemAtIndexPath:(NSIndexPath *)indexPath;

-(void)cleanDataSource;

-(NSInteger)indexWithoutAds:(NSInteger)index;

-(void)clean;

@end
