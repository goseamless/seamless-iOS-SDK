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

@interface SLInterstitialAdManager : NSObject <MPInterstitialAdControllerDelegate>

-(id)initWithDelegate:(id)delegate;

-(void)getAdWithEntity:(NSString*)entity
              category:(SLCategory)category
          successBlock:(void(^)(MPInterstitialAdController * adController))successBlock
          failureBlock:(void(^)(NSError * error))failureBlock;
@end
