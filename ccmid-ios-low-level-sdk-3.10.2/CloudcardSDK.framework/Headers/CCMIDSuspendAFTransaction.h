//
//  CCMIDSuspendAFTransaction.h
//  CloudcardSDK
//
//  Created by Brian J Doyle on 10/11/2017.
//  Copyright © 2017 Morpho. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "CCMIDTransaction.h"

@interface CCMIDSuspendAFTransaction : CCMIDTransaction

@property (nonatomic) CCMIDAuthenticationFactorType factorTypeToUpdate;
@property (nonatomic) BOOL shouldValidate;

- (NSArray *)getUpdateAuthenticationFactors:(CCMIDAuthenticationFactorSettings *)settings;

@end
