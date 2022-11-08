//
//  CCMIDCoreDataManager.h
//  CloudcardCoreAPI
//
//  Created by ZHANG Lei - EXT-PURPLEDECK (MORPHO) on 14/03/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCMIDCoreDataManager : NSObject

+ (CCMIDCoreDataManager*)sharedCoreDataManager;

// Saves changes in the application's managed object context before the application terminates.
- (void)saveContext;

- (NSString *)getAuthenticationData:(NSString *)keyringId andType:(NSInteger)type;
- (NSString *)getAuthenticationImageData:(NSString*)keyringId andType:(NSInteger)type;
- (NSString *)getAuthenticationFacialAlgorithmData:(NSString*)keyringId andType:(NSInteger)type;
- (void)saveAuthenticationData:(NSString *)keyringId type:(NSInteger)type andData:(NSString *)data;
- (void)updateAuthenticationData:(NSString *)keyringId type:(NSInteger)type andData:(NSString *)data;
- (void)deleteAuthenticationData:(NSString *)keyringId type:(NSInteger)type;

//CCMID-4219
- (void)saveEncryptedPhotoData:(NSString *)keyringId type:(NSInteger)type facialAlgorithm:(NSString *)facialAlgorithm andData:(NSString *)data;

//srp key
- (NSString *)getSrpKeyData;
- (void)saveSrpKeyData:(NSString *)srpKey;
- (void)deleteSrpKeyData;

//certificate
- (void)saveCertificateData:(NSData *)data againstServerUrlString:(NSString *)serverUrlString;
- (NSData *)getCertificateDataOnServerUrlString:(NSString *)serverUrlString;
- (BOOL)updateCertificateData:(NSData *)data againstServerUrlString:(NSString *)serverUrlString;
- (void)deleteCertificateWithServerUrlString:(NSString *)serverUrlString;

//offline data
- (void)saveCounter:(NSData*)counter andKeyringId:(NSString*)keyringId;
- (NSData *)getCounter:(NSString*)keyringId;
- (BOOL)updateCounter:(NSData*)counter andKeyringId:(NSString*)keyringId;
- (void)deleteOfflineAuthenticationData:(NSString *)keyringId;


@end
