//
//  CCMIDRoamingTransaction.h
//  CloudcardCoreAPI
//
//  Created by ZHANG Lei - EXT-PURPLEDECK (MORPHO) on 23/03/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

#import "CCMIDAuthenticationTransaction.h"

@interface CCMIDRoamingTransaction : CCMIDTransaction

- (instancetype)initWithDictionary:(NSDictionary *)dictionary andContext:(SRPContext *)context transcipherKey:(NSData *) transcipherKey;

- (NSString *)generateRoamingQrCodeString;

@end
