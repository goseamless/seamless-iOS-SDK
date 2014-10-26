//
//  SLBaseAdManager.h
//  Seamless
//
//  Created by Mehmet Can Yavuz on 29.05.2014.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MPAdView.h"
#import "SLManager.h"

@class SLAd;
@class SLAdRequestManager;
@class SLAppearance;

@interface SLBaseAdManager : NSObject <MPAdViewDelegate>

@property (nonatomic, strong) SLAppearance * appearance;
@property (nonatomic, weak, readwrite) NSMutableArray * dataSource;
@property (nonatomic, weak, readwrite) id viewController;
@property (nonatomic) BOOL notInsert;
@property (nonatomic, strong) NSMutableArray * ads;
@property (nonatomic, strong) NSMutableArray * notInsertedAds;
@property (nonatomic, strong) NSMutableArray * insertQueue;
@property (nonatomic, strong) NSMutableArray * reloadQueue;
@property (nonatomic, strong) NSTimer * insertTimer;
@property (nonatomic, strong) NSMutableSet *insertedAds;
@property (nonatomic, strong) NSMutableSet *maiaAds;
@property (nonatomic, strong) NSMutableSet *cells;
@property (nonatomic, strong) SLAdRequestManager * adRequestManager;
@property (nonatomic, strong) NSArray * initialVisibleCells;

-(void)getAdsWithEntity:(NSString*)entity
               category:(SLCategory)category
           successBlock:(void(^)(void))successBlock
           failureBlock:(void(^)(NSError * error))failureBlock;
-(void)setSeamlessAds:(NSMutableArray*)ads;
-(BOOL)shouldShowAdAtIndexPath:(NSIndexPath*)indexPath;
-(void)changeDataSource:(NSMutableArray *)dataSource;
-(void)didDetectVisibleRowsAtIndexPaths:(NSArray *)indexPaths;
-(void)cleanDataSource;
-(void)insertAvailableAds;
-(void)finishReloading;
-(void)clean;

@end
