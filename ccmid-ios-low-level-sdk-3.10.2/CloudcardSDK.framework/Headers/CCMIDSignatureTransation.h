//
//  CCMIDSignatureTransation.h
//  CloudcardCoreAPI
//
//  Created by lei_zhang on 10/2/15.
//  Copyright © 2015 Dictao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCMIDAuthenticationTransaction.h"

@interface CCMIDSignatureTransation : CCMIDAuthenticationTransaction

@property (nonatomic, readonly) NSData *dataToSignRepresentation;
@property (nonatomic, readonly) NSData *encryptedSignatureResult;

- (NSData *)visualizedData;

@end
