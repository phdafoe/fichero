//
//  CCMIDAuthenticationFactor.h
//  CloudcardCoreAPI
//
//  Created by DOGARU Cristiana - EXT-CF (MORPHO) on 28/10/2015.
//  Copyright © 2015 Dictao. All rights reserved.
//

#import "CCMIDAuthenticationFactorSettings.h"

typedef NS_ENUM(NSInteger, CCMIDStatusType)
{
    CCMIDStatusTypeUnknown,
    CCMIDStatusTypeValid,
    CCMIDStatusTypeLocked,
    CCMIDStatusTypeBlocked,
    CCMIDStatusTypeMustChange,
    CCMIDStatusTypeRegistrationLocked,
    CCMIDStatusTypeRegistrationBlocked,
    CCMIDStatusTypeSuspended
};

@interface CCMIDAuthenticationFactor : NSObject

@property (nonatomic, readonly) NSString *appInstanceId;
@property (nonatomic) CCMIDAuthenticationFactorType authenticationFactorType;
@property (nonatomic, readonly) NSDate *creationDate;
@property (nonatomic, readonly) NSDate *updateDate;
@property (nonatomic) CCMIDStatusType statusType;
@property (nonatomic) NSDate *lockedUntil;
@property (nonatomic) NSDate *registrationLockedUntil;

@property (nonatomic) NSDate *lastAuthenticationAttemptTime;
@property (nonatomic) NSInteger remainingAuthenticationAttempts;
@property (nonatomic) NSInteger remainingRegistrationAttempts;
@property (nonatomic) NSInteger remainingVerificationAttempts;

@property (nonatomic, readonly) NSString *sensorDeviceChallenge;
@property (nonatomic) BOOL isCompleteAF;
@property (nonatomic) NSString *encryptedTemplate;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
- (instancetype)initWithDictionary:(NSDictionary *)dictionary andTerminalID:(NSString*)terminalID;
- (instancetype)initWithSettings:(CCMIDAuthenticationFactorSettings *)settings andTerminalID:(NSString*)terminalID;

- (NSString *)factorKeyString;
- (NSString *)statusKeyString;

- (BOOL)setLockedUntilForVerification:(CCMIDAuthenticationFactorSettings *)settings;
- (BOOL)setLockedUntilForAuthentication:(CCMIDAuthenticationFactorSettings *)settings;
- (BOOL)setLockedUntilForRegistration:(CCMIDAuthenticationFactorSettings *)settings;

@end
