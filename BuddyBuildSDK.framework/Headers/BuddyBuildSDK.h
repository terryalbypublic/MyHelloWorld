//  Copyright (c) 2015 Doe Pics Hit, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIApplication.h>

typedef NSString*(^BBReturnNSStringCallback)();

@interface BuddyBuildSDK : NSObject

// Deprecated
+ (void)setup:(id<UIApplicationDelegate>)bbAppDelegate;

/**
 * Initialize the SDK
 *
 * This should be called at (or near) the start of the appdelegate
 */
+ (void)setup;

/*
 * If you distribute a build to someone with their email address, buddybuild can 
 * figure out who they are and attach their info to feedback and crash reports.
 *
 * However, if you send out a build to a mailing list, or through TestFlight or 
 * the App Store we are unable to infer who they are. If you see 'Unknown User' 
 * this is likely the cause.

 * Often you'll know the identity of your user, for example, after they've 
 * logged in. You can provide buddybuild a callback to identify the current user.
 */
+ (void)setUserDisplayNameCallback:(BBReturnNSStringCallback)bbCallback;

/*
 * You might have API keys and other secrets that your app needs to consume. 
 * However, you may not want to check these secrets into the source code.
 *
 * You can provide your secrets to buddybuild. Buddybuild can then expose them 
 * to you at build time through environment variables. These secrets can also be
 * configured to be included into built app. We obfuscate the device keys to 
 * prevent unauthorized access.
 */
+ (NSString*)valueForDeviceKey:(NSString*)bbKey;
@end
