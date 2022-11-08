//
//  CCMIDRegistrationTransaction.h
//  CloudcardCoreAPI
//
//  Created by Cristiana Dogaru on 9/17/15.
//  Copyright (c) 2015 Dictao. All rights reserved.
//

#import "CCMIDTransaction.h"

@interface CCMIDRegistrationTransaction : CCMIDTransaction

@property (nonatomic, readonly) NSString *encryptedIdentity;
@property (nonatomic) BOOL requiresOtp;
@property (nonatomic, copy) NSString *transcipherKey;

@property (nonatomic, readonly) NSString *serverUrl;

@property (nonatomic) NSString *subjectIdentity;
@property (nonatomic, assign) BOOL cardAlreadyActivated;

@property (nonatomic, readonly) NSArray *authenticationFactors;

- (BOOL)isRoamingRegistrationTransaction __attribute((deprecated("use isRoamingKeyring instead")));
- (BOOL)isRoamingKeyring;

@end
