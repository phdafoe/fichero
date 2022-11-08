//
//  NSError+Utils.h
//  CloudcardCoreAPI
//
//  Created by Cristiana Dogaru on 25/09/2015.
//  Copyright (c) 2015 Dictao. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Custom Error Codes
 */
#define kConnectionLost                                         @"CONNECTION_LOST"
#define kConnectionTimedOut                                     @"CONNECTION_TIMED_OUT"
#define kNotComplianceToPolicy                                  @"SERVER_URL_NOT_CONFORM_TO_POLICY"

/**
 *  Error codes for all of the server errors that can be returned.
 */
typedef NS_ENUM(NSInteger, CCMIDErrorCode)
{
    CCMIDErrorUnknown = -1,
    
    CCMIDErrorRequestValidationFailure,
    CCMIDErrorRegistrationFailure,
    CCMIDErrorPolicyNotFound,
    CCMIDErrorAllowedApplicationNotFound,
    CCMIDErrorAppInstanceNotFound,
    CCMIDErrorAppInstanceSRPNotSupport,
    CCMIDErrorTransactionNotFound,
    CCMIDErrorInvalidRegistrationSession,
    CCMIDErrorInvalidAppInstanceSession,
    CCMIDErrorUnathorizedState,
    CCMIDErrorAppInstanceAlreadyAssociated,
    
    CCMIDErrorKeyringNotFound,
    CCMIDErrorKeyringNotActive,
    
    CCMIDErrorInvalidCredentials,
    CCMIDErrorCredentialsBlocked,
    CCMIDErrorCredentialsLocked,
    
    CCMIDErrorConnectionLost,
    CCMIDErrorConnectionTimedOut,
    
    CCMIDErrorKeyringDeleteNotAuthorized,
    CCMIDErrorUnauthorizedOperation,
    CCMIDErrorKeyringRoamMaxAppInstance,
    
    CCMIDErrorPolicyIncompliance,
    CCMIDErrorPolicyExists,
    CCMIDErrorPolicyDeleteNotAuthorized,
    
    CCMIDErrorAllowedApplicationExists,
    
    CCMIDErrorDeviceRegistrationFailure,
    CCMIDErrorDeviceAuthenticationFailure,
    CCMIDErrorDeviceAuthenticationUpdateDeviceTokenFailed,
    CCMIDErrorDeviceAuthenticationDecryptFailed,
    CCMIDErrorDeviceAuthenticationVerifyFailed,
    CCMIDErrorDeviceAuthenticationDataNotFound,
    CCMIDErrorDeviceNotEligible,
    
    CCMIDErrorNotificationConfigNotFound,
    CCMIDErrorPinMismatch,
    CCMIDErrorRegistrationBlocked,
    CCMIDErrorRegistrationLocked,
    
    CCMIDErrorBiometricsFailure
};

typedef NS_ENUM(NSInteger, CCMIDErrorCodeType)
{
    CCMIDErrorCodeTypeNetwork,
    CCMIDErrorCodeTypeAuthentication,
    CCMIDErrorCodeTypeBiometricFailure,
    CCMIDErrorCodeTypeService
};

@interface NSError (Utils)

/**
 *  Get the localized error message string for NSError.
 */
- (NSString *) errorMessage;

/**
 *  Get the CCMIDErrorCode for NSError.
 */
- (CCMIDErrorCode) errorCode;

- (CCMIDErrorCodeType) errorType;

/**
 *  Initialize NSError with a JSON dictionary.
 */
+ (NSError *)errorWithJSONDictionary:(NSDictionary *)JSONDictionary;
/**
 *  Initialize NSError with a custom message and custom error code.
 */
+ (NSError *)errorWithMessageString:(NSString *)serverErrorMessage errorCodeString:(NSString *)serverErrorCodeString;

+ (NSError *)errorWithServerMsg:(NSData *)nsServerMsg domain:(NSString *)nsDomain;
+ (NSError *)errorWithInternalMsg:(NSString *)nsInternalMsg domain:(NSString *)nsDomain;
+ (NSError *) exceptionInfoWithInternalMsgAndExtraObjects:(NSString *)nsInternalMsg exception:(NSException *)nsException domain:(NSString *)nsDomain extraObjects:(NSMutableDictionary *)extraObjects;

@end
