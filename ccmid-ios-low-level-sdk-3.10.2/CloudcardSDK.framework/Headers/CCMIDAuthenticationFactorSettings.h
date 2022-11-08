//
//  CCMIDAuthenticationFactorSettings.h
//  CloudcardCoreAPI
//
//  Created by DOGARU Cristiana - EXT-CF (MORPHO) on 28/10/2015.
//  Copyright © 2015 Dictao. All rights reserved.
//

typedef NS_ENUM(NSInteger, CCMIDAuthenticationFactorType)
{
    CCMIDAuthenticationFactorTypeUNKWOWN,
    CCMIDAuthenticationFactorTypePIN_SRP,
    CCMIDAuthenticationFactorTypeOTP,
    CCMIDAuthenticationFactorTypeFACE_DEVICE,
    CCMIDAuthenticationFactorTypeFACE_SERVER,
    CCMIDAuthenticationFactorTypePASSWORD,
    CCMIDAuthenticationFactorTypePUK_SRP,
    CCMIDAuthenticationFactorTypeFINGER,
    CCMIDAuthenticationFactorTypeSENSOR,
    CCMIDAuthenticationFactorTypeDEVICE_ONLY
};

#define kRegistrationRequired                                   @"registrationRequired"

#define kAuthenticationFactorTypeUnknown                        @""
#define kAuthenticationFactorTypePIN_SRP                        @"PIN_SRP"
#define kAuthenticationFactorTypeOTP                            @"OTP"
#define kAuthenticationFactorTypeFACE_DEVICE                    @"FACE_DEVICE"
#define kAuthenticationFactorTypeFACE_SERVER                    @"FACE_SERVER"
#define kAuthenticationFactorTypePUK_SRP                        @"PUK_SRP"
#define kAuthenticationFactorTypeFINGER                         @"FINGER_DEVICE"
#define kAuthenticationFactorTypeSENSOR                         @"SENSOR_DEVICE"
#define kAuthenticationFactorTypeDEVICE_ONLY                    @"DEVICE_ONLY"

@interface CCMIDAuthenticationFactorSettings : NSObject

@property (nonatomic, readonly) BOOL registrationRequired;
@property (nonatomic, readonly) BOOL signatureAllowed;
@property (nonatomic, readonly) BOOL updateAllowed;
@property (nonatomic, readonly) NSArray *updateAuthenticationFactors;
@property (nonatomic, readonly) NSArray *authenticationAttemptDelays;
@property (nonatomic, readonly) NSArray *verificationAttemptDelays;
@property (nonatomic, readonly) BOOL resetAfterLastAttempt;

@property (nonatomic, readonly) NSInteger pinMinSize;
@property (nonatomic, readonly) NSInteger pinMaxSize;
@property (nonatomic, readonly) BOOL pinResetAllowed;

@property (nonatomic, readonly) BOOL offlineAuthenticationAllowed;
@property (nonatomic, readonly) int hotpResynch;
@property (nonatomic, readonly) int hotpMinSize;
@property (nonatomic, readonly) int hotpMaxSize;


@property (nonatomic, readonly) NSInteger faceRegistrationCaptures;
@property (nonatomic, readonly) NSInteger faceRegistrationMaxAttempts;
@property (nonatomic, readonly) BOOL faceVerifyAfterRegister;
@property (nonatomic, readonly) BOOL faceDeviceBiometricProvided;
@property (nonatomic, readonly) NSInteger registrationAttemptDelay;

@property (nonatomic, readonly) NSInteger pukTimeToLive;
@property (nonatomic, readonly) NSInteger pukSize;

@property (nonatomic, readonly) CCMIDAuthenticationFactorType authenticationFactorType;

@property (nonatomic, readonly) NSInteger maxAuthenticationRetriesAllowed;
@property (nonatomic, readonly) NSInteger maxVerificationRetriesAllowed;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary key:(NSString *)key;

+ (NSString *)keyForAuthenticationFactorType:(CCMIDAuthenticationFactorType)authenticationFactorType;
+ (CCMIDAuthenticationFactorType)authenticationFactorTypeForKey:(NSString *)key;

@end
