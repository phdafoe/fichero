//
//  CCMIDKeyring.h
//  CloudcardCoreAPI
//
//  Created by Cristiana Dogaru on 9/17/15.
//  Copyright (c) 2015 Dictao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCMIDPolicy.h"
#import "CCMIDSignatureToken.h"
#import "CCMIDAuthenticationFactor.h"

@interface CCMIDKeyring : NSObject

@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, readonly) CCMIDPolicy *policy;
@property (nonatomic, readonly) NSInteger appInstanceCount;
@property (nonatomic, readonly) NSString *pan;
@property (nonatomic, readonly) NSString *status;
@property (nonatomic, readonly) CCMIDSignatureToken *signatureToken;

@property (nonatomic) NSArray *authenticationFactorsArray;
@property (nonatomic) NSArray *appInstanceMetadatasArray;

- (instancetype) initWithDictionary:(NSDictionary *)dictionary;
//CCMID-4676
- (instancetype) initWithDictionary:(NSDictionary *)dictionary andTerminalId:(NSString *)terminalId;

- (NSString*)getFriendlyNames;
//- (void)setAuthFactorByRegistraterTrans:(NSDictionary *) authDict;

- (NSArray *)getAuthenticatorFactor;

/** DEPRECATED */
- (NSArray *)getAuthenticatorFactorForTerminalId:(NSString *)terminalId __attribute((deprecated("Use getAuthenticatorFactor instead")));

- (CCMIDAuthenticationFactor *)getAuthenticatorFactorFor:(CCMIDAuthenticationFactorType)type;

/** DEPRECATED */
- (CCMIDAuthenticationFactor *)getAuthenticatorFactorFor:(CCMIDAuthenticationFactorType)type terminalId:(NSString *)terminalId __attribute((deprecated("Use getAuthenticatorFactorFor:(CCMIDAuthenticationFactorType)type instead")));

@end
