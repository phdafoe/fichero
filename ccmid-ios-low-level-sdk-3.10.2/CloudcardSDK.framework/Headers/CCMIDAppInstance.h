//
//  CCMIDAppInstance.h
//  CloudcardCoreAPI
//
//  Created by DOGARU Cristiana - EXT-CF (MORPHO) on 08/06/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

#import "CCMIDAppInstanceMetadata.h"
#import "CCMIDKeyring.h"

@interface CCMIDAppInstance : CCMIDAppInstanceMetadata

@property (nonatomic, readonly) NSDate *creation;
@property (nonatomic, readonly) NSDate *update;

@property (nonatomic, readonly) NSArray *keyringsArray;

@end
