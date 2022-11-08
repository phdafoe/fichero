//
//  CCMIDIdp.h
//  CloudcardCoreAPI
//
//  Created by DOGARU Cristiana - EXT-CF (MORPHO) on 24/03/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

@interface CCMIDIdp : NSObject

@property (nonatomic, readonly) NSURL *serverURL;
@property (nonatomic, readonly) NSString *idpURL;
@property (nonatomic, readonly) NSString *idpClientID;
@property (nonatomic, readonly) NSString *idpRedirectValue;

- (id)initWithServerURL:(NSURL *)serverURL idpURL:(NSString *)idpURL idpClientID:(NSString *)idpClientID idpRedirectValue:(NSString *)idpRedirectValue;

@end
