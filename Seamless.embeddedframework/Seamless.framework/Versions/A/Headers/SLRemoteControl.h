//
//  SLRemoteControl.h
//  Woodo Project iOS
//
//  Created by Gokhan Baris Aker on 07/03/14.
//  Copyright (c) 2014 Woodo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>

typedef NS_ENUM(NSInteger, RemoteControlPlayerState){
    
    RemoteControlPlayerStateMintFresh,
    RemoteControlPlayerStatePlaying,
    RemoteControlPlayerStatePaused,
    RemoteControlPlayerStateFinished
};

typedef void(^RemoteControlAsyncHandler)(id data);

@interface SLRemoteControl : NSObject

// Player state
@property (nonatomic, readwrite) RemoteControlPlayerState playerState;

// Full screen
@property (nonatomic, readwrite) BOOL fullscreenModeEnabled;

// TODO: Add play
- (void) pauseThen:(RemoteControlAsyncHandler) asyncHandler;
- (void) resumeThen:(RemoteControlAsyncHandler) asyncHandler;
- (void) seekTo:(CGFloat) percentage then:(RemoteControlAsyncHandler) asyncHandler;
- (void) setVolume:(CGFloat) percentage then:(RemoteControlAsyncHandler) asyncHandler;

- (void) toggleFullscreenThen:(RemoteControlAsyncHandler) asyncHandler;
- (void) saveState;
- (void) loadState;
- (void) close;

- (void) isContentSeekable:(void(^)(BOOL)) asyncGetter;

@end