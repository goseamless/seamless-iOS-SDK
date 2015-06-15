//
//  SLTableViewAdManager.h
//  Seamless
//
//  Created by Mehmet Can Yavuz on 26.05.2014.
//  Copyright (c) 2014 mobilike. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MPAdView.h"
#import "SLBaseAdManager.h"
#import "SLManager.h"
#import "SLAppearance.h"
@class SLAd;

@protocol SLTableViewAdManagerDelegate
@optional
-(void)adInsertedTableViewAtIndexPath:(NSIndexPath *)indexPath;
@end

@interface SLTableViewAdManager : SLBaseAdManager

@property (nonatomic, weak) id delegate;
@property(nonatomic, assign) SLGender gender;
@property(nonatomic, copy) NSDate *birthday;
@property(nonatomic, copy) NSString *contentURL;
@property(assign) BOOL childDirectedTreatment;
@property(nonatomic, strong) CLLocation *location;


-(id)initWithTableView:(UITableView*)tableView
            dataSource:(NSMutableArray*)dataSource
        viewController:(id)viewController;

-(void)getAdsWithEntity:(NSString*)entity
               category:(SLCategory)category
           successBlock:(void(^)(void))successBlock
           failureBlock:(void(^)(NSError * error))failureBlock;

-(BOOL)shouldShowAdAtIndexPath:(NSIndexPath*)indexPath;

-(UITableViewCell*)cellForRowAtIndexPath:(NSIndexPath *)indexPath;

-(CGFloat)heightForRowAtIndexPath:(NSIndexPath *)indexPath;

-(void)didSelectRowAtIndexPath:(NSIndexPath *)indexPath;

-(void)changeDataSource:(NSMutableArray *)dataSource;

-(void)cleanDataSource;

-(NSInteger)indexWithoutAds:(NSInteger)index;

-(void)clean;
@end
