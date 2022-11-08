//
//  CCMIDEnhancedSecurity.h
//  CloudcardCoreAPI
//
//  Created by lei on 24/08/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCMIDEnhancedSecurity : NSObject

@property (nonatomic, readonly) BOOL enhancedKeyEncryption;
@property (nonatomic, readonly) NSString *srpKey;
@property (nonatomic, readonly) BOOL certificatePinning;
@property (nonatomic, readonly) BOOL useHttps,shuffleKeyboard;

- (instancetype) initWithDictionary:(NSDictionary *)dictionary;

@end
