//
//  Twikee.h
//  TwikeeBasicTest
//
//  Created by Yaman JAIOUCH on 02/04/2014.
//  Copyright (c) 2014 Yaman JAIOUCH. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TwikeeErrorCode)
{
    TwikeeErrorCodeTwitterUnavailable,
    TwikeeErrorCodeEmptyTweet,
};

@protocol TwikeeDelegate <NSObject>

@optional
- (BOOL)twikeeShouldDisplay;
- (void)twikeeWillDisplay;
- (void)twikeeDidDisplay;
- (void)twikeeDidCancel;
- (void)twikeeDidSendTweet:(NSString *)tweet;
- (void)twikeeDidFailWithError:(NSError *)error;

@end

@interface Twikee : NSObject

@property (weak, nonatomic) id<TwikeeDelegate> delegate;

+ (instancetype)sharedInstance;

- (void)showWithTitle:(NSString *)title tweetMessage:(NSString *)tweetMessage;

@end