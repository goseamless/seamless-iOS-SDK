//
//  SLManager.h
//  Woodo Project iOS
//
//  Created by Gokhan Baris Aker on 05/03/14.
//  Copyright (c) 2014 Woodo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <CoreGraphics/CGBase.h>
#import "SLActivityIndicatorViewSource.h"

@class SLRemoteControl;
@class SLShare;
@class SLHandler;

@interface SLPlayerManager : NSObject

// Singleton instance provider
+ (instancetype)sharedManager;

+ (NSString *) version;
+ (id<SLActivityIndicatorViewSource>) activityIndicatorViewSource;
+ (void) setActivityIndicatorViewSource:(id<SLActivityIndicatorViewSource>) source;

// Woodo view controller presenter
// TODO: This method is deprecated. Instead use;
// - (SLRemoteControl *) presentPlayerWithUrl:(NSURL *) url
//                                     entity:(NSString *) entity
//                             attachmentView:(UIView *) attachmentView
//                                      share:(SLShare *) share
//                                    handler:(SLHandler *) handler;
//
- (SLRemoteControl *) presentPlayerWithUrl:(NSURL *) url
                                  entity:(NSString *) entity
                           attachmentView:(UIView *) attachmentView
                                shareText:(NSString *) shareText
                                shareUrls:(NSArray *) shareUrls
                              shareImages:(NSArray *) shareImages
                               shareTitle:(NSString *) shareTitle
                      shareRecipientsMail:(NSArray *) shareRecipientsMail
                       shareRecipientsSms:(NSArray *) shareRecipientsSms
                      presentationHandler:(dispatch_block_t) presentationHandler
                             startHandler:(dispatch_block_t) startHandler
                          progressHandler:(void(^)(CGFloat currentTime, CGFloat duration)) progressHandler
                            finishHandler:(dispatch_block_t) finishHandler
                             errorHandler:(dispatch_block_t) errorHandler;

// TODO: This method is deprecated. Instead use;
// - (SLRemoteControl *) addPlayerToView:(UIView *) view
//                                   url:(NSURL *) url
//                                entity:(NSString *) entity
//                        attachmentView:(UIView *) attachmentView
//                                 share:(SLShare *) share
//                               handler:(SLHandler *) handler;
//
- (SLRemoteControl *) addPlayerToView:(UIView *) view
                                 url:(NSURL *) url
                              entity:(NSString *) entity
                      attachmentView:(UIView *) attachmentView
                           shareText:(NSString *) shareText
                           shareUrls:(NSArray *) shareUrls
                         shareImages:(NSArray *) shareImages
                          shareTitle:(NSString *) shareTitle
                 shareRecipientsMail:(NSArray *) shareRecipientsMail
                  shareRecipientsSms:(NSArray *) shareRecipientsSms
                 presentationHandler:(dispatch_block_t) presentationHandler
                        startHandler:(dispatch_block_t) startHandler
                     progressHandler:(void(^)(CGFloat currentTime, CGFloat duration)) progressHandler
                       finishHandler:(dispatch_block_t) finishHandler
                        errorHandler:(dispatch_block_t) errorHandler;


#pragma mark Single

- (SLRemoteControl *) presentPlayerWithUrl:(NSURL *) url
                                    entity:(NSString *) entity;


- (SLRemoteControl *) addPlayerToView:(UIView *) view
                                  url:(NSURL *) url
                               entity:(NSString *) entity;

- (SLRemoteControl *) presentPlayerWithUrl:(NSURL *) url
                                    entity:(NSString *) entity
                            attachmentView:(UIView *) attachmentView
                                     share:(SLShare *) share
                                   handler:(SLHandler *) handler;


- (SLRemoteControl *) addPlayerToView:(UIView *) view
                                  url:(NSURL *) url
                               entity:(NSString *) entity
                      attachmentView:(UIView *) attachmentView
                               share:(SLShare *) share
                             handler:(SLHandler *) handler;


@end
