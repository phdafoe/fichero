//
//  CCMIDNetworkBlocks.h
//  CloudcardCoreAPI
//
//  Created by DOGARU Cristiana - EXT-CF (MORPHO) on 07/03/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

#import <CloudcardSDK/CCMIDRegistrationTransaction.h>
#import <CloudcardSDK/CCMIDAuthenticationTransaction.h>
#import <CloudcardSDK/CCMIDKeyringHistory.h>
#import <CloudcardSDK/CCMIDKeyringHistoryItem.h>
#import <CloudcardSDK/CCMIDSignatureTransation.h>
#import <CloudcardSDK/CCMIDDeleteKeyringTransaction.h>
//#import <CloudcardSDK/CCMIDSuspendAFTransaction.h>
#import <CloudcardSDK/CCMIDUpdateAFTransaction.h>
#import <CloudcardSDK/CCMIDAuthenticationFactor.h>
#import <CloudcardSDK/CCMIDRoamingTransaction.h>
#import <CloudcardSDK/CCMIDEnrolmentData.h>

//CCMID-4072
#import <CloudcardSDK/CCMIDQCPNData.h>

typedef void (^ErrorBlock)(NSError *error);

typedef void (^CompletionBlock)(void);
typedef void (^CompletionBlockResult)(NSDictionary *result);
typedef void (^CompletionBlockString)(NSString *resultString);
typedef void (^CompletionBlockInteger)(NSUInteger resultNr);
typedef void (^CompletionBlockArray)(NSArray *resultArray);
typedef void (^CompletionBlockEnrolmentData)(CCMIDEnrolmentData *enrolmentData);
typedef void (^CompletionBlockSmartBioSDKLicenseV10)(NSDictionary *licenseDict , NSString *serverUrl);
typedef void (^CompletionBlockSmartBioSDKLicense)(NSData *license , NSString *serverUrl);
typedef void (^CompletionBlockSmartBioSDKLicenseV10)(NSDictionary *licenseDict , NSString *serverUrl);
typedef void (^CompletionBlockTransaction)(CCMIDTransaction *transaction);
typedef void (^CompletionBlockRegistrationTransaction)(CCMIDRegistrationTransaction *transaction);
typedef void (^CompletionBlockAuthenticationTransaction)(CCMIDAuthenticationTransaction *transaction);
typedef void (^CompletionBlockSignatureTransaction)(CCMIDSignatureTransation *transaction);
typedef void (^CompletionBlockUpdateAFTransaction)(CCMIDUpdateAFTransaction *transaction);
typedef void (^CompletionBlockDeleteKeyringTransaction)(CCMIDDeleteKeyringTransaction *transaction);
//typedef void (^CompletionBlockSuspendAFTransaction)(CCMIDSuspendAFTransaction *transaction);
typedef void (^CompletionBlockRoamingTransaction)(CCMIDRoamingTransaction *roamingTransaction);
typedef void (^CompletionBlockKeyringHistory)(CCMIDKeyringHistory *keyringHistory);

//CCMID-4072
typedef void (^CompletionBlockQCPNData)(CCMIDQCPNData *qcpnData);

//CCMID-4352
typedef void(^AFUpdateCompletion)(BOOL isAllUpdate);
typedef void(^AFPairCompletion)(BOOL foundCompletedAFPair);
