//
//  CCMIDUpdateAFTransaction.h
//  CloudcardCoreAPI
//
//  Created by DOGARU Cristiana - EXT-CF (MORPHO) on 28/10/2015.
//  Copyright © 2015 Dictao. All rights reserved.
//

#import "CCMIDTransaction.h"

@interface CCMIDUpdateAFTransaction : CCMIDTransaction

@property (nonatomic) CCMIDAuthenticationFactorType factorTypeToUpdate;
@property (nonatomic) BOOL shouldValidate;
@property (nonatomic) BOOL pukAuthenticated;

- (NSArray *)getUpdateAuthenticationFactors:(CCMIDAuthenticationFactorSettings *)settings;


@end
