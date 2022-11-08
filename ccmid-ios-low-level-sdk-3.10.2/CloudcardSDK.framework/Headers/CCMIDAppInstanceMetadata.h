//
//  CCMIDAppInstanceMetadata.h
//  CloudcardCoreAPI
//
//  Created by ZHANG Lei - EXT-PURPLEDECK (MORPHO) on 01/06/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCMIDAppInstanceMetadata : NSObject

@property (nonatomic, readonly) NSString *appInstanceMetadataId;
@property (nonatomic, readonly) NSString *friendlyName;
@property (nonatomic, readonly) NSString *manufacturer;
@property (nonatomic, readonly) NSString *model;
@property (nonatomic, readonly) NSString *os;
@property (nonatomic, readonly) NSString *appId;
@property (nonatomic, readonly) NSString *pushNotificationProvider;
@property (nonatomic, readonly) NSString *pushNotificationId;

- (instancetype) initWithDictionary:(NSDictionary *)dictionary;


@end
