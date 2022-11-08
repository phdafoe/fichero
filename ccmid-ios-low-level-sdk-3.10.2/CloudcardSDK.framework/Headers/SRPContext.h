//
//  SRPContext.h
//  Signature
//
//  Created by Houned Chopra on 5/23/12.
//  Copyright (c) 2012 Dictao. All rights reserved.
//

#define TK_CONTEXT @"TK"
#define PIN_CONTEXT @"PIN"
#define ACODE_CONTEXT @"ACODE"
#define PUK_CONTEXT @"PUK"
#define OTP_CONTEXT @"OTP"

#define DEFAULT_SRP_KEY_SIZE @"1024"

#import "CCMIDQRCodeData.h"


@interface SRPContext : NSObject

@property (nonatomic) NSURL *smsURL;
@property (nonatomic, readonly) NSString *srpKeySize;

+ (SRPContext *)contextWithURL:(NSURL *)smsURL;
+ (NSData *)computeKDFWithKey:(NSData *)_nsDataKey1 andKey:(NSData *)_nsDataKey2;
+ (NSData *)verifierForID:(NSString *)identity andKey:(NSString *)key andSalt:(NSData **)salt andSrpKeySize:(NSString *)srpKeySize;
+ (void)savePinSalt:(NSData*)pinSalt andKeyringID:(NSString*)keyringId;
+ (NSData*)getPinSalt:(NSString*)keyringId;

+ (BOOL)hasSrpKeySize:(NSURL*)serverUrl;
+ (NSString *)readSrpKeySize:(NSURL*)serverUrl;
+ (void)writeSrpKeySize:(NSURL*)serverUrl srpKeySize:(NSString *)srpKeySize;

- (id)initSrpTK;
- (id)initSrpWithOTP:(NSString *)nsAcode previousSRP:(SRPContext *)poPreviousSRP;
- (id)initSrpWithQRCode:(CCMIDQRCodeData *)qrCodeData;


//- (id)initSrpWithType:(NSString *)nsTypePassword password:(NSString *)nsPassword;
- (id)initSrpWithPin:(NSString *)nsPIN previousSRP:(SRPContext *)poPreviousSRP;
- (id)initSrpWithType:(NSString *)nsType ident:(NSString *)nsIdentHex password:(NSString *)nsPassword previousSRP:(SRPContext *)poPreviousSRP;

- (NSError *)processInitSRPResponseWithBpub:(NSString *)aBpub andSalt:(NSString *)aSalt;
- (void)computeClientChallenge;
- (BOOL)verifyServerChallenge:(NSData *)serverChallenge;
- (void)computeVerifier;
- (void)genSalt;
- (NSData *)decryptServerData:(NSData *)nsJSONBase64EncryptData error:(NSError **)pnsError errorDomain:(NSString *)nsErrorDomain;

- (NSString *)getApub;
- (NSString *)getClientChallenge;
- (NSString *)getClientChallengeBase64;
- (NSString *)getContextID;
- (NSString *)getIdentifier;
- (NSData *)getVerifier;
- (NSData *)getSalt;
- (NSData *)getK;
- (NSData *)getPassword;
- (NSString *)getType;
- (NSString *)getPasswordIDHex;
- (NSString *)getHmacClientPublicKey;
- (NSString *)getHmacClientChallenge;

- (NSURL *)getPerformInitURL;
- (NSURL *)getPerformChallengeURL;

- (SRPContext*)getPreviousSRPContext;

+ (void)testDecryptData;

/**
 *  Erase the data and secrets after use
 */
- (void)clearSrp;

@end
