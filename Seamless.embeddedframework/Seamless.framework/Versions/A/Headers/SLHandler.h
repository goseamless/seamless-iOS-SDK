//
//  SLHandlers.h
//  Woodo Project iOS
//
//  Created by Gökhan Barış Aker on 16/04/14.
//  Copyright (c) 2014 Woodo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>

@interface SLHandler : NSObject

@property (nonatomic, readwrite, strong) dispatch_block_t presentation;
@property (nonatomic, readwrite, strong) dispatch_block_t start;
@property (nonatomic, readwrite, strong) void(^progress)(CGFloat currentTime, CGFloat duration);
@property (nonatomic, readwrite, strong) dispatch_block_t finish;
@property (nonatomic, readwrite, strong) dispatch_block_t error;

@end
