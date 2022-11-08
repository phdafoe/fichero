//
//  CCMIDKeyringHistoryFilter.h
//  CloudcardSDK
//
//  Created by lei on 28/06/2017.
//  Copyright © 2017 Morpho. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "CCMIDTransaction.h"

/*
typedef NS_ENUM(NSInteger,CCMIDTransactionHistoryType)
{
    CCMIDTransactionHistoryTypeAuthentication,
    CCMIDTransactionHistoryTypeSignature,
    CCMIDTransactionHistoryTypeUpdateAF,
    CCMIDTransactionHistoryTypeDeleteKeyring,
    CCMIDTransactionHistoryTypeRegistration,
    CCMIDTransactionHistoryTypeRoaming,
    CCMIDTransactionHistoryTypeOfflineAuthentication,
    CCMIDTransactionHistoryTypeAll
};
 */

typedef NS_ENUM(NSInteger, CCMIDTransactionHistorySort)
{
    CCMIDTransactionHistorySortAsc,
    CCMIDTransactionHistorySortDesc
};

typedef NS_ENUM(NSInteger, CCMIDTransactionHistoryStatus)
{
    CCMIDTransactionHistoryStatusFinished,
    CCMIDTransactionHistoryStatusCreated,
    CCMIDTransactionHistoryStatusCanceled,
    CCMIDTransactionHistoryStatusALL
};

@interface CCMIDKeyringHistoryFilter : NSObject

@property (nonatomic) CCMIDTransactionHistoryStatus transactionHistoryStatus;
@property (nonatomic) CCMIDTransactionType transactionType;
@property (nonatomic) NSDate *startDate;
@property (nonatomic) NSDate *endDate;
@property (nonatomic) CCMIDTransactionHistorySort sort;

- (NSString*)startDateToString;
- (NSString*)endDateToString;

- (NSArray*)getTransactionTypeItems;
- (NSArray*)getTransactionStatusItems;
- (NSArray*)getTransactionSortingItems;

@end
