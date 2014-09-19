//
//  SLShare.h
//  Woodo Project iOS
//
//  Created by Gökhan Barış Aker on 16/04/14.
//  Copyright (c) 2014 Woodo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SLShare : NSObject

#pragma mark Facebook, Twitter

@property (nonatomic, readwrite, copy) NSString *socialText;
@property (nonatomic, readwrite, copy) NSArray *socialUrls;
@property (nonatomic, readwrite, copy) NSArray *socialImages;


#pragma mark Mail

@property (nonatomic, readwrite, copy) NSString *mailBody;
@property (nonatomic, readwrite, copy) NSString *mailTitle;
@property (nonatomic, readwrite, copy) NSArray *mailRecipients;


#pragma mark Sms

@property (nonatomic, readwrite, copy) NSString *smsBody;
@property (nonatomic, readwrite, copy) NSArray *smsRecipients;

@end