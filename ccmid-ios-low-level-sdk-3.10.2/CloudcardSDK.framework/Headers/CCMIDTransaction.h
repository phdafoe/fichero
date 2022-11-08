//
//  CCMIDTransaction.h
//  CloudcardCoreAPI
//
//  Created by Cristiana Dogaru on 06/10/2015.
//  Copyright © 2015 Dictao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCMIDKeyring.h"
#import "SRPContext.h"

typedef NS_ENUM(NSInteger, CCMIDTransactionType)
{
    CCMIDTransactionTypeRegistration,
    CCMIDTransactionTypeAuthentication,
    CCMIDTransactionTypeSignature,
    CCMIDTransactionTypeUpdate,
    CCMIDTransactionTypeDelete,
    CCMIDTransactionTypeRoaming,
    CCMIDTransactionTypeOfflineAuthentication,
    CCMIDTransactionTypeDefault
};

@interface CCMIDTransaction : NSObject

@property (nonatomic, readonly) NSString *challenge;
@property (nonatomic, readonly) BOOL requiresConfirmation;

@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, readonly) NSString *status;
@property (nonatomic, readonly) NSDate *creation;
@property (nonatomic, readonly) NSDate *update;
@property (nonatomic, readonly) CCMIDKeyring *keyring;
@property (nonatomic, readonly) NSDate *expiration;
//CCMID-4290
@property (nonatomic, readonly) NSDate *currentDate;
@property (nonatomic) SRPContext *context;
@property (nonatomic) id sessionContext;
//unique id
@property  (nonatomic) NSString* uniqueId;
@property  (nonatomic) NSString* facialAlgorithm;


@property (nonatomic) BOOL faceVerification;

//TODO move to a dedicated Suspend Transaction Class
@property (nonatomic) BOOL suspendActivateUpdateAF;
@property (nonatomic) NSInteger factorToSuspendActivate;
@property (nonatomic) BOOL suspendAFAlreadySuspended;

@property (nonatomic, readonly) NSInteger otpSize;

@property (nonatomic) CCMIDAuthenticationFactor * updateAuthFactor;

+ (NSArray *)transactionTypeAllNames;
+ (CCMIDTransactionType)typeByString:(NSString*)transactionTypeName;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (CCMIDTransactionType)type;

- (NSTimeInterval)expirationInterval;

- (NSTimeInterval)ttl;
- (NSString *)ttlAsString;
- (NSString *)formatCreationDateString;

- (NSArray *)authenticatorFactors;
- (NSArray *)authenticatorFactorSettings;
- (NSArray *)authenticationFactorsCombinationsArray;

- (NSArray *)updateAuthenticationFactors:(CCMIDAuthenticationFactorType)type;

- (CCMIDAuthenticationFactorSettings *)authenticationFactorSettingsForType:(CCMIDAuthenticationFactorType)type;
- (CCMIDAuthenticationFactor *)authenticatorFactorForType:(CCMIDAuthenticationFactorType)type;

@end

