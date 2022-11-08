//
//  CCMIDSignatureToken.h
//  CloudcardCoreAPI
//
//  Created by ZHANG Lei - EXT-PURPLEDECK (MORPHO) on 29/02/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCMIDSignatureToken : NSObject

@property (nonatomic, readonly) NSDate *creationDate;
@property (nonatomic, readonly) NSDate *updateDate;
@property (nonatomic, readonly) NSDate *expirationDate;

@property (nonatomic, readonly) NSData *x509CertificateData;
@property (nonatomic, readonly) NSString *x509State;

- (instancetype) initWithDictionary:(NSDictionary *)dictionary;

@end
