//
//  CCMIDKeyringHistoryItem.h
//  CloudcardCoreAPI
//
//  Created by ZHANG Lei - EXT-PURPLEDECK (MORPHO) on 01/02/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

#define kTransactionStatusTypeFinished      @"FINISHED"
#define kTransactionStatusTypeCreated       @"CREATED"
#define kTransactionStatusTypeCanceled      @"CANCELED"
#define kTransactionStatusTypeALL           @"ALL"


#import "CCMIDKeyringHistoryAppInstanceMetadata.h"
#import "CCMIDTransaction.h"
#import "CCMIDKeyringHistoryFilter.h"

@interface CCMIDKeyringHistoryItem : NSObject

@property (nonatomic, readonly) NSString *transactionId;
@property (nonatomic, readonly) NSDate *creation;
@property (nonatomic, readonly) NSDate *update;
@property (nonatomic, readonly) NSString *transactionStatus;
@property (nonatomic, readonly) NSString *transactionType;
@property (nonatomic, readonly) NSString *appInstanceId;
@property (nonatomic, readonly) CCMIDKeyringHistoryAppInstanceMetadata *appInstanceMetadata;

@property (nonatomic, readonly) NSString *roamingAppInstanceId;
@property (nonatomic, readonly) CCMIDKeyringHistoryAppInstanceMetadata *roamingAppInstanceMetadata;

- (instancetype) initWithDictionary:(NSDictionary *)dictionary;

- (CCMIDTransactionHistoryStatus)transactionStatusType;
- (CCMIDTransactionType)getTransactionType;

@end
