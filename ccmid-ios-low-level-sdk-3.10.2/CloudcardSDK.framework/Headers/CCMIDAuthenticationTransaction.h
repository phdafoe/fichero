//
//  CCMIDTransaction.h
//  CloudcardCoreAPI
//
//  Created by lei_zhang on 10/2/15.
//  Copyright © 2015 Dictao. All rights reserved.
//

#import "CCMIDTransaction.h"
#import "CCMIDAppInstance.h"

@interface CCMIDAuthenticationTransaction : CCMIDTransaction

@property (nonatomic, readonly) NSData *visual;
@property (nonatomic, readonly) NSString *senderName;
@property (nonatomic, readonly) NSString *desc;
//CCMID-4044
@property (nonatomic, readonly) NSData   *dataToSignRepresentationParam;

@property (nonatomic, readonly) NSData *encryptedOtp;
@property (nonatomic, readonly) NSData *encryptedAuthenticationResult;
@property (nonatomic, readonly) BOOL outOfBand;
@property (nonatomic, readonly) NSArray *verifiedAuthenticationFactors;

@property (nonatomic, readonly) CCMIDAppInstance *appInstance;
@property (nonatomic) BOOL isIDP;
@property (nonatomic) BOOL isRoaming;
@property (nonatomic) BOOL requiresOtp;

//CCMID-4044
- (NSData *)visualizedInfoData;

@end
