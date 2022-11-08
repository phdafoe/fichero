//
//  CCMIDQRCodeData.h
//  CloudcardCoreAPI
//
//  Created by DOGARU Cristiana - EXT-CF (MORPHO) on 23/03/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

typedef NS_ENUM(NSUInteger,QRCodeType)
{
    QRCODE_ACODE,
    QRCODE_RCODE,
    QRCODE_ACODE2,
    QRCODE_RCODE2
};

typedef NS_ENUM(NSUInteger,ConnectionType)
{
    ConnectionType_HTTP,
    ConnectionType_HTTPS,
    ConnectionType_NO_SPECIFIED
};

@interface CCMIDQRCodeData : NSObject

@property(nonatomic) QRCodeType qrCodeType;
@property(nonatomic, readonly) NSString *activationCode;
@property(nonatomic, readonly) NSString *activationCodeID;
@property(nonatomic, readonly) NSString *keyRingID;
@property(nonatomic, readonly) NSString *keySize;
@property(nonatomic, readonly) ConnectionType connType;
@property(nonatomic, readonly) NSURL *serverURL;
@property(nonatomic, readonly) NSString *transcipherKey;
@property(nonatomic) BOOL isCertificatePinning;

+ (CCMIDQRCodeData *)qrCodeDataWithActivationCode:(NSString *)code error:(NSError **)error;
- (instancetype)initWithActivationData:(NSString*)activationCode serverUrl:(NSURL*)serverUrl transcipherKey:(NSString*)transciperKey;
- (instancetype)initWithActivationData:(NSString*)activationCode activationCodeID:(NSString*)activationCodeID keySize:(NSString*)keySize connectionType:(ConnectionType)connType serverUrl:(NSURL*)serverUrl transcipherKey:(NSString*)transciperKey isPinning : (BOOL) isPinning;

@end
