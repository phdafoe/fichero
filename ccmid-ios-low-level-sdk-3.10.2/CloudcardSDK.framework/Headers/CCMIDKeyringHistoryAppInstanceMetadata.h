//
//  CCMIDKeyringHistoryAppInstanceMetadata.h
//  CloudcardCoreAPI
//
//  Created by DOGARU Cristiana - EXT-CF (MORPHO) on 01/06/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

@interface CCMIDKeyringHistoryAppInstanceMetadata : NSObject

@property (nonatomic, readonly) NSString *itemID;
@property (nonatomic, readonly) NSString *friendlyName;
@property (nonatomic, readonly) NSString *model;
@property (nonatomic, readonly) NSString *manufacturer;
@property (nonatomic, readonly) NSString *os;
@property (nonatomic, readonly) NSString *appId;
@property (nonatomic, readonly) NSString *pushNotificationProvider;
@property (nonatomic, readonly) NSString *pushNotificationId;

- (instancetype) initWithDictionary:(NSDictionary *)dictionary;

@end
