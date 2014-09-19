//
//  SLActivityIndicatorViewSourceProtocol.h
//  Woodo Project iOS
//
//  Created by Gökhan Barış Aker on 28/04/14.
//  Copyright (c) 2014 Woodo. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SLActivityIndicatorViewSource <NSObject>

@required

- (UIView *) activityIndicatorView;

@end
