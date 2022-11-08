//
//  VersionsUtils.h
//  CloudcardSDK
//
//  Created by lei on 25/08/2017.
//  Copyright © 2017 Morpho. All rights reserved.
//

/*
#define kVersionV8 @"v8"
#define kVersionV7 @"v7"
#define kVersionV6 @"v6"
#define kVersionV5 @"v5"
#define kVersionV4 @"v4"
*/

typedef NS_ENUM(NSUInteger,CCMIDServerVersions)
{
    CCMIDVersion4 = 4,
    CCMIDVersion5 = 5,
    CCMIDVersion6 = 6,
    CCMIDVersion7 = 7,
    CCMIDVersion8 = 8,
    CCMIDVersion9 = 9,
    CCMIDVersion10 = 10,
    CCMIDVersion11 = 11,
    CCMIDVersion12 = 12
};


#import <Foundation/Foundation.h>

@interface VersionsUtils : NSObject

+ (BOOL)isKeyDerivationSupported:(NSURL*)serverURL;
+ (BOOL)serverVersionIsSupport:(NSUInteger)serverVersion;

+ (BOOL)serverSupportsSHA256:(NSURL*)serverUrl;
+ (BOOL)serverSupportsPSS:(NSURL*)serverUrl;
+ (BOOL)appInstanceSupportsSHA256:(NSURL*)serverUrl;
+ (BOOL)appInstanceSupportsPSS:(NSURL*)serverUrl;

+ (void)writeServerApiVersion:(NSURL*)serverUrl apiVersion:(NSUInteger)apiVersion;
+ (BOOL)hasServerApiVersion:(NSURL*)serverUrl;
+ (NSUInteger)readServerApiVersion:(NSURL*)serverUrl;

+ (void)writeAppInstanceApiVersion:(NSURL*)serverUrl apiVersion:(NSUInteger)apiVersion;
+ (BOOL)hasAppInstanceApiVersion:(NSURL*)serverUrl;
+ (NSUInteger)readAppInstanceApiVersion:(NSURL*)serverUrl;

@end
