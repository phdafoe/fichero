//
//  CCMIDSuspendAFSRPRequest.h
//  CloudcardSDK
//
//  Created by Brian J Doyle on 13/11/2017.
//  Copyright © 2017 Morpho. All rights reserved.
//

#import "CCMIDApiRequest.h"

@interface CCMIDSuspendAFSRPRequest : CCMIDApiRequest


- (id)initWithContext:(SRPContext*)tkContext identifier:(NSString*)identifier keyringID:(NSString *)keyringID terminalKey:(NSString *)tk appInstanceSessionID:(NSString *)appInstanceSessionID authenticationFactorType:(CCMIDAuthenticationFactorType)factorType suspend:(BOOL)alreadySuspended;

@end
