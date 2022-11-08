//
//  CCMIDKeyringHistory.h
//  CloudcardCoreAPI
//
//  Created by ZHANG Lei - EXT-PURPLEDECK (MORPHO) on 29/01/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCMIDKeyringHistory : NSObject

@property (nonatomic, readonly) NSInteger total;
@property (nonatomic, readonly) NSInteger pageNumber;
@property (nonatomic, readonly) NSDate *lastUpdate;
@property (nonatomic, readonly) NSArray *historyItems;

- (instancetype) initWithDictionary:(NSDictionary *)dictionary;

@end
