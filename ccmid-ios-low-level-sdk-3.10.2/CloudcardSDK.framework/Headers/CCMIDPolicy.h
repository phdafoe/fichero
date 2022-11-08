//
//  CCMIDPolicy.h
//  CloudcardCoreAPI
//
//  Created by Cristiana Dogaru on 9/17/15.
//  Copyright (c) 2015 Dictao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCMIDAuthenticationFactorSettings.h"
#import "CCMIDEnhancedSecurity.h"
#import "CCMIDMscSettings.h"


@interface CCMIDPolicy : NSObject

@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, readonly) NSString *providerName;
@property (nonatomic, readonly) NSString *issuerLogoUrl;
@property (nonatomic, readonly) NSString *issuerLicenseUrl;
@property (nonatomic, readonly) NSInteger pinMinSize;
@property (nonatomic, readonly) NSInteger pinMaxSize;
@property (nonatomic, readonly) NSInteger pinMaxAttempts;
@property (nonatomic, readonly) NSInteger allowedAppInstanceCount;
@property (nonatomic, readonly) BOOL keyringDeletionAllowed;
@property (nonatomic, readonly) BOOL pinChangeAllowed;
@property (nonatomic, readonly) BOOL pinResetAllowed;
@property (nonatomic, readonly) BOOL keyringMovedOnRoaming;
@property (nonatomic, readonly) BOOL activationKeptOnDelete;

//CCMID-2501
@property (nonatomic, readonly) BOOL otpRequiredOnActivation;
@property (nonatomic, readonly) NSInteger otpActivationSize;
@property (nonatomic, readonly) NSInteger otpAuthorizationSize;

@property (nonatomic, readonly) CCMIDEnhancedSecurity *enhancedSecurity;
@property (nonatomic, readwrite) CCMIDMscSettings *mscSettings;

@property (nonatomic, readonly) NSArray *authenticationFactorSettingsArray;

- (instancetype) initWithDictionary:(NSDictionary *)dictionary;

//CCMID-3363
@property (nonatomic, readonly) BOOL displayTermsAndConditions;
@property (nonatomic, readonly) BOOL displayTerminalFriendlyName;

//CCMID-4072
@property (nonatomic, readonly) BOOL generateQCPNCert;
//@property (nonatomic, readonly) NSInteger generateQCPNCert;
@property (nonatomic, readonly) NSString *certTermsAndConditionsUrl;
@property (nonatomic, readonly) NSString *certDisclosureStatementUrl;

@property (nonatomic, readonly) NSString *transactionVisualUrl;

@end
