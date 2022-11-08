//
//  CCMIDQCPNData.h
//  CloudcardSDK
//
//  Created by Satya on 06/04/18.
//  Copyright © 2018 Morpho. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCMIDQCPNData : NSObject

@property (nonatomic, readonly) NSString *x509IssuerName;
@property (nonatomic, readonly) NSString *creationDate;
@property (nonatomic, readonly) NSDate *updateDate;
@property (nonatomic, readonly) NSString *expirationDate;

@property (nonatomic, readonly) NSString *x509CN;
@property (nonatomic, readonly) NSString *x509DN;
@property (nonatomic, readonly) NSString *x509SerialNo;

@property (nonatomic, readonly) NSData *x509CertificateData;
@property (nonatomic, readonly) NSString *x509State;

- (instancetype) initWithDictionary:(NSDictionary *)dictionary;

@end
