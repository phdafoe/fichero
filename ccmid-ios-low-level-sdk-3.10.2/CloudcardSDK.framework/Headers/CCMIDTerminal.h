//
//  CCMIDTerminal.h
//  CloudcardCoreAPI
//
//  Created by Cristiana Dogaru on 15/09/2015.
//  Copyright (c) 2015 Dictao. All rights reserved.
//

//Server Requests Time Out
#define kDefaultTimeOutServerRequest 90.0f

//ExtraOptions
#define kEncryptedTemplateOption                                @"encryptedTemplate"
#define kEncryptedPhotoOption                                   @"encryptedPhoto"
#define kFacialAlgorithmOption                                  @"facialAlgorithm"
#define kLivenessPredictionOption                               @"livenessPrediction"
#define kResetStoreOption                                       @"resetStore"
#define kVerifyAfterFaceUpdated                                 @"shouldVerifyAfterFaceUpdated" //this is used only in CCIMIAFTransaction to differentiate between face authentication and face verification scenario

#define CC_SHA256_DIGEST_LENGTH     32          /* digest length in bytes */
#define CC_SHA256_BLOCK_BYTES       64          /* block size in bytes */

#import "CCMIDNetworkBlocks.h"
#import "CCMIDQRCodeData.h"
#import "CCMIDMetadata.h"
#import "CCMIDIdp.h"

typedef uint32_t CC_LONG;       /* 32 bit unsigned integer */
typedef uint64_t CC_LONG64;     /* 64 bit unsigned integer */
extern unsigned char *CC_SHA256(const void *data, CC_LONG len, unsigned char *md)
__OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

@interface CCMIDTerminal : NSObject

@property (nonatomic, assign) CGFloat timeoutServerRequest;

+ (CCMIDTerminal *)sharedInstance;

/** DEPRECATED */
- (NSString *)terminalID __attribute((deprecated("use APIs without terminalID value instead")));
/** DEPRECATED */
- (NSString *)terminalID:(NSString *)serverHost __attribute((deprecated("use APIs without terminalID value instead")));

/**
 * Returns a data buffer uniquely identifying this device.
 * Value should be converted to Base64 string to match server value.
 */
- (NSData *)getDeviceStaticId;

#pragma mark - validation
/*!
 * @discussion It's the first step of the registration process, where after scanning a QRCode it validates the activation code.
 * @param activationData The CCMIDQRCodeData reads from QR code.
 * @param completionBlock The completion callback to be executed if success, the activation data and a CCMIDRegistrationTransaction will be returned.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)validateActivationCode:(CCMIDQRCodeData *)activationData completion:(CompletionBlockRegistrationTransaction)completionBlock error:(ErrorBlock)errorBlock;

/*!
 * @discussion Validate the authentication data provided for one authenticator factor (Authenticate).
 * @param authenticatorFactorType that could be one of followings
 
    CCMIDAuthenticationFactorTypeUNKWOWN,
    CCMIDAuthenticationFactorTypePIN_SRP,
    CCMIDAuthenticationFactorTypeOTP,
    CCMIDAuthenticationFactorTypeFACE_DEVICE,
    CCMIDAuthenticationFactorTypeFACE_SERVER,
    CCMIDAuthenticationFactorTypePASSWORD,
    CCMIDAuthenticationFactorTypePUK_SRP,
    CCMIDAuthenticationFactorTypeFINGER,
    CCMIDAuthenticationFactorTypeSENSOR,
    CCMIDAuthenticationFactorTypeDEVICE_ONLY

 * @param data The registration data.
 * @param extraOptions if necessary. The possible keys are: kEncryptedTemplateOption, kEncryptedPhotoOption, kLivenessPredictionOption,kFacialAlgorithmOption, kResetStoreOption and kVerifyAfterFaceUpdated.
 * @param completionBlock The completion callback to be executed if success.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)validateAuthenticationFactor:(CCMIDAuthenticationFactorType)authenticatorFactorType transaction:(CCMIDTransaction *)transaction data:(NSData *)data extraOptions:(NSDictionary *)extraOptions completion:(CompletionBlock)completionBlock error:(ErrorBlock)errorBlock;


- (void)synPinFactorOnRoaming:(CCMIDAuthenticationFactorType)type transaction:(CCMIDTransaction *)transaction data:(NSData *)data extraOptions:(NSDictionary *)extraOptions completion:(CompletionBlockEnrolmentData)completionBlock error:(ErrorBlock)errorBlock;

#pragma mark - register
/*!
 * @discussion Register a new authenticator factor.
 * @param type The authenticator factor type, that could be one of followings

    CCMIDAuthenticationFactorTypeUNKWOWN,
    CCMIDAuthenticationFactorTypePIN_SRP,
    CCMIDAuthenticationFactorTypeOTP,
    CCMIDAuthenticationFactorTypeFACE_DEVICE,
    CCMIDAuthenticationFactorTypeFACE_SERVER,
    CCMIDAuthenticationFactorTypePASSWORD,
    CCMIDAuthenticationFactorTypePUK_SRP,
    CCMIDAuthenticationFactorTypeFINGER,
    CCMIDAuthenticationFactorTypeSENSOR,
    CCMIDAuthenticationFactorTypeDEVICE_ONLY
 
 * @param transaction The transaction to use, at this moment only UpdateTransaction and RegistrationTransaction.
 * @param data The data to be verified.
 * @param completionBlock The completion callback to be executed if success.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)registerAuthenticatorFactor:(CCMIDAuthenticationFactorType)type transaction:(CCMIDTransaction *)transaction data:(NSData *)data extraOptions:(NSDictionary *)extraOptions completion:(CompletionBlockEnrolmentData)completionBlock error:(ErrorBlock)errorBlock;

/*!
 * @discussion Finalizes the registration process by setting the status of the Keyring to ACTIVE and the status of the RegistrationTransaction to FINISHED. It has to be called at the end of the registration process.
 * @param transaction The CCMIDRegistrationTransaction transaction.
 * @param completionBlock The completion callback to be executed if success.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)activate:(CCMIDRegistrationTransaction *)transaction completion:(CompletionBlockEnrolmentData)completionBlock error:(ErrorBlock)errorBlock;

#pragma mark - retrieve keyrings

 /** DEPRECATED */
/*!
 * @discussion This method is a convenience for the mobile application to retrieve the list of keyrings associated to an AppInstance. It requires a session in which the AppInstance has previously been authenticated.
 
 * @param serverURL The server url
 * @param keyringID The keyring ID of a registered Keyring
 * @param completionBlock The completion callback to be executed if success, and a list of keyrings returned.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
 - (void)retrieveKeyrings:(NSURL *)serverURL keyringID:(NSString*)keyringID completion:(CompletionBlockArray)completionBlock error:(ErrorBlock)errorBlock __attribute__((deprecated("Use APIs without keyringID value instead.")));

/*!
 * @discussion This method is a convenience for the mobile application to retrieve the list of keyrings associated to an AppInstance. It requires a session in which the AppInstance has previously been authenticated.
 
 * @param serverURL The server url
 * @param completionBlock The completion callback to be executed if success, and a list of keyrings returned.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)retrieveKeyrings:(NSURL *)serverURL completion:(CompletionBlockArray)completionBlock error:(ErrorBlock)errorBlock;

#pragma mark - retrieve transactions
/*!
 * @discussion This method is a convenience for the mobile application to retrieve the list of transactions that are waiting to be processed. It requires a session in which the AppInstance has previously been authenticated.
 * @param serverURL The request server url.
 * @param keyringID The keyring identifier.
 * @param completionBlock The completion callback to be executed if success, and a list of pending transactions returned.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)retrievePendingTransactions:(NSURL *)serverURL keyringID:(NSString *)keyringID completion:(CompletionBlockArray)completionBlock error:(ErrorBlock)errorBlock;

/*!
 * @discussion This method is a convenience for the mobile application to retrieve information about an authentication transaction.
 * @param serverURL The request server url.
 * @param keyringID The keyring identifier.
 * @param completionBlock The completion callback to be executed if success, and a CCMIDAuthenticationTransaction returned.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)retrieveAuthenticationTransaction:(NSURL *)serverURL keyringID:(NSString *)keyringID completion:(CompletionBlockAuthenticationTransaction)completionBlock error:(ErrorBlock)errorBlock;

/*!
 * @discussion This method is a convenience for the mobile application to retrieve information about a UpdateAf transaction.
 * @param serverURL The request server url.
 * @param keyringID The keyring identifier.
 * @param completionBlock The completion callback to be executed if success, and a CCMIDUpdateAFTransaction returned.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)retrieveUpdateTransaction:(NSURL *)serverURL keyringID:(NSString *)keyringID completion:(CompletionBlockUpdateAFTransaction)completionBlock error:(ErrorBlock)errorBlock;

/*!
 * @discussion This method is a convenience for the mobile application to retrieve information about a DeleteKeyring transaction.
 * @param serverURL The request server url.
 * @param keyringID The keyring identifier.
 * @param completionBlock The completion callback to be executed if sucess, and a CCMIDDeleteKeyringTransaction returned.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)retrieveDeleteTransaction:(NSURL *)serverURL keyringID:(NSString *)keyringID completion:(CompletionBlockDeleteKeyringTransaction)completionBlock error:(ErrorBlock)errorBlock;

#pragma mark - delete keyring
/*!
 * @discussion Delete a Keyring or to detach it from an AppInstance.
 * @param transaction The CCMIDDeleteKeyringTransaction transaction to use.
 * @param isDetached  The account is detached from keyring if true, otherwise delete keyring on server.
 * @param completionBlock The completion callback to be executed if sucess.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)deleteKeyring:(CCMIDDeleteKeyringTransaction *)transaction detachAccount:(BOOL)isDetached completion:(CompletionBlock)completionBlock error:(ErrorBlock)errorBlock;

#pragma mark - get roaming package
/*!
 * @discussion Get the roaming transaction at the end of the roaming process
 * @param transaction The transaction to be used to retrieve a CCMIDRoamingTransaction object.
 * @param extraOptions if necessary. The possible keys are: kEncryptedTemplateOption, kEncryptedPhotoOption, kFacialAlgorithmOption
 * @param completionBlock The completion callback to be executed if success, and a CompletionBlockRoamingTransaction contains a CCMIDRoamingTransaction object returned
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)retrieveRoamingTransaction:(CCMIDAuthenticationTransaction *)transaction extraOptions:(NSDictionary *)extraOptions completion:(CompletionBlockRoamingTransaction)completionBlock error:(ErrorBlock)errorBlock;

- (void)retrieveRoamingTransaction:(CCMIDAuthenticationTransaction *)transaction completion:(CompletionBlockRoamingTransaction)completionBlock error:(ErrorBlock)errorBlock __attribute((deprecated(("Use '(void)retrieveRoamingTransaction:transaction:extraOptions:completionBlock:errorBlock' instead"))));

#pragma mark - retrieve oauth token from IDP server
/*!
 * @discussion Initiate an OAUTH2 authentication in the IDP server.
 * @param idp The Idp necessary info.
 * @param keyringID The keyring identifier.
 * @param completionBlock The completion callback to be executed if success, and a CCMIDAuthenticationTransaction object returned.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)createIDPAuthenticationTransaction:(CCMIDIdp *)idp keyringID:(NSString *)keyringID completion:(CompletionBlockAuthenticationTransaction)completionBlock error:(ErrorBlock)errorBlock;

/*!
 * @discussion Retrieves an OAUTH2 token from the IDP server after perform an authentication.
 * @param idp The Idp necessary info.
 * @param transaction The CCMIDAuthenticationTransaction transaction.
 * @param completionBlock The completion callback to be executed if success, and an OAUTH2 token returned
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)retrieveOAUTH2Token:(CCMIDIdp *)idp transaction:(CCMIDAuthenticationTransaction *)transaction completion:(CompletionBlockString)completionBlock error:(ErrorBlock)errorBlock;

/*!
 * @discussion The CANCEL_TRANSACTION event has to be sent if the user wants to dismiss the transaction.
 * @param transaction The transaction to be cancelled.
 * @param completionBlock The completion callback to be executed if success.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)cancelTransaction:(CCMIDTransaction *)transaction completion:(CompletionBlock)completionBlock error:(ErrorBlock)errorBlock;

/** DEPRECATED */
/*!
 * @discussion The CANCEL_TRANSACTION event has to be sent if the user wants to dismiss the transaction.
 * @param transaction The transaction to be cancelled.
 * @param keyringId The Keyring ID.
 * @param txnId The txnId.
 * @param cancellationReason The cancellationReason.
 * @param completionBlock The completion callback to be executed if success.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)cancelRegisterTransactionWithQCPNReason:(CCMIDRegistrationTransaction *)transaction pinning:(BOOL)pinning txnId:(NSString*)txnId cancellationReason:(NSString *)cancellationReason keyringId:(NSString*)keyringId completion:(CompletionBlockEnrolmentData)completionBlock error:(ErrorBlock)errorBlock __attribute__((deprecated("Use APIs without keyringID value instead.")));

/*!
 * @discussion The CANCEL_TRANSACTION event has to be sent if the user wants to dismiss the transaction.
 * @param transaction The transaction to be cancelled.
 * @param txnId The txnId.
 * @param cancellationReason The cancellationReason.
 * @param completionBlock The completion callback to be executed if success.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)cancelRegisterTransactionWithQCPNReason:(CCMIDRegistrationTransaction *)transaction txnId:(NSString*)txnId cancellationReason:(NSString *)cancellationReason completion:(CompletionBlockEnrolmentData)completionBlock error:(ErrorBlock)errorBlock;

/** DEPRECATED */
/*!
 * @discussion Send mobile meta data to server.
 * @param url The request server url
 * @param metadata will be sent to server, and set 'apnToken' in CCMIDMetadata with deviceToken from push notification.
 * @param keyringID The keyring identifier
 */
- (void)sendMetadata:(NSURL *)url terminalData:(CCMIDMetadata *)metadata keyringID:(NSString*)keyringID __attribute__((deprecated("Use APIs without keyringID value instead.")));

/*!
 * @discussion Send mobile meta data to server with callbacks
 * @param url The request server url
 * @param metadata will be sent to server, and set 'apnToken' in CCMIDMetadata with deviceToken from push notification.
 * @param keyringID The keyring identifier
 * @param completionBlock The completion callback to be executed if success.
 * @param errorBlock The error callback to be executed if an error occurred.
*/
- (void)sendMetadata:(NSURL *)url terminalData:(CCMIDMetadata *)metadata keyringID:(NSString*)keyringID completion:(CompletionBlock)completionBlock error:(ErrorBlock)errorBlock __attribute__((deprecated("Use APIs without keyringID value instead.")));

/*!
 * @discussion Send mobile meta data to server.
 * @param url The request server url
 * @param metadata will be sent to server, and set 'apnToken' in CCMIDMetadata with deviceToken from push notification.
 */
- (void)sendMetadata:(NSURL *)url terminalData:(CCMIDMetadata *)metadata;

/*!
 * @discussion Send mobile meta data to server with callbacks
 * @param url The request server url
 * @param metadata will be sent to server, and set 'apnToken' in CCMIDMetadata with deviceToken from push notification.
 * @param completionBlock The completion callback to be executed if success.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)sendMetadata:(NSURL *)url terminalData:(CCMIDMetadata *)metadata completion:(CompletionBlock)completionBlock error:(ErrorBlock)errorBlock;

/** DEPRECATED */
/*!
 * @discussion Retrieves the API level for the server URL.
 * @param serverURL The server url.
 * @param completionBlock The completion callback to be executed if success, and a API level integer value returned.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)retrieveServerApiLevel:(NSURL *)serverURL completion:(CompletionBlockInteger)completionBlock andError:(ErrorBlock)errorBlock __attribute__((deprecated("This method should not be used and will be removed in an upcoming release.")));

/*!
 * @discussion Retrieve the transaction history list for the keyring id, the returned CCMIDKeyringHistory object that contains a list of keyring transaction history records, which is a type of CCMIDKeyringHistoryItem.
 * @param serverUrl The server url.
 * @param keyringId The keyring identifier.
 * @param page The page number.
 * @param filter The filter object. If it is nil, all the history transactions are returned by the page at the ascending order. Set filter.sort to CCMIDTransactionHistorySortDesc if you want recent items first
 * @param completionBlock The completion callback to be executed if success, and a CCMIDKeyringHistory object returned.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)retrieveTransactionHistory:(NSURL *)serverUrl keyringId:(NSString *)keyringId page:(NSInteger)page filter:(CCMIDKeyringHistoryFilter*)filter completion:(CompletionBlockKeyringHistory)completionBlock error:(ErrorBlock)errorBlock;

/** DEPRECATED */
/*!
 * @discussion Retrieve an existing transaction from the server
 * @param serverUrl The server url.
 * @param transactionId The transaction identifier.
 * @param transactionType The transaction type.
 * @param keyringID The keyring identifier.
 * @param completionBlock The completion callback to be executed if success, and a CCMIDTransaction object returned.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)retrieveExistingTransaction:(NSURL *)serverUrl transactionId:(NSString *)transactionId transactionType:(CCMIDTransactionType)transactionType keyringID:(NSString *)keyringID completion:(CompletionBlockTransaction)completionBlock error:(ErrorBlock)errorBlock __attribute__((deprecated("Use APIs without keyringID value instead.")));

/*!
 * @discussion Retrieve an existing transaction from the server
 * @param serverUrl The server url.
 * @param transactionId The transaction identifier.
 * @param transactionType The transaction type.
 * @param completionBlock The completion callback to be executed if success, and a CCMIDTransaction object returned.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)retrieveExistingTransaction:(NSURL *)serverUrl transactionId:(NSString *)transactionId transactionType:(CCMIDTransactionType)transactionType completion:(CompletionBlockTransaction)completionBlock error:(ErrorBlock)errorBlock;

/*!
 * @discussion Save server url string with certificate data
 * @param certsData The certificate data.
 * @param serverUrlString The server url string.
 */
- (void)addCertificate:(NSData*)certsData againstServerUrlString:(NSString*)serverUrlString __attribute__((deprecated("Use static configuration for certificate pinning instead")));

/** DEPRECATED */
/*!
 * @discussion Download X509 Certificate from server for the QCPN
 * @param pinning certificate pinning allowed or not
 * @param keyringID related to this operation.
 */
- (void)downloadX509Certificate:(CCMIDRegistrationTransaction *)transaction pinning:(BOOL)pinning keyringID:(NSString*)keyringID completion:(CompletionBlockQCPNData)completionBlock error:(ErrorBlock)errorBlock __attribute__((deprecated("Use APIs without pinning value instead.")));

/*!
 * @discussion Download X509 Certificate from server for the QCPN
 * @param keyringID related to this operation.
 */
- (void)downloadX509Certificate:(CCMIDRegistrationTransaction *)transaction keyringID:(NSString*)keyringID completion:(CompletionBlockQCPNData)completionBlock error:(ErrorBlock)errorBlock;

/*!
 * @discussion Confirm Authentication after Validating AF
 * @param transaction related to this operation.
 */
- (void)confirmAuthenticationTransaction:(CCMIDAuthenticationTransaction *)transaction completion:(CompletionBlockAuthenticationTransaction)completionBlock error:(ErrorBlock)errorBlock;

/*!
 * @discussion check If All AF Completed after Validating AF
 * @param transaction related to this operation.
 */

- (BOOL)checkIfAllAFCompleted:(CCMIDAuthenticationTransaction *)transaction;

/** DEPRECATED */
/*!
 * @discussion Update friendly terminal name
 * @param terminalName The updated terminal name.
 * @param keyringID The keyring identifier.
 * @param serverUrlString The server url string.
 */
- (void)updateTerminalFriendlyName:(NSString *)terminalName serverUrlString:(NSURL *)serverUrlString keyringID:(NSString *)keyringID __attribute__((deprecated("Use APIs without keyringID value instead.")));

/*!
 * @discussion Update friendly terminal name
 * @param terminalName The updated terminal name.
 * @param serverUrlString The server url string.
 */
- (void)updateTerminalFriendlyName:(NSString *)terminalName serverUrlString:(NSURL *)serverUrlString;

/** DEPRECATED */
- (void)retrieveDeleteTransactions:(NSURL *)serverURL transactionID:(NSString *)transactionID keyringID:(NSString*)keyringID completion:(CompletionBlockDeleteKeyringTransaction)completionBlock error:(ErrorBlock)errorBlock __attribute__((deprecated("Use APIs without keyringID value instead.")));

- (void)retrieveDeleteTransactions:(NSURL *)serverURL transactionID:(NSString *)transactionID completion:(CompletionBlockDeleteKeyringTransaction)completionBlock error:(ErrorBlock)errorBlock;

/** DEPRECATED */
- (void)retrieveUpdateTransactions:(NSURL *)serverURL transactionID:(NSString *)transactionID keyringID:(NSString*)keyringID completion:(CompletionBlockUpdateAFTransaction)completionBlock error:(ErrorBlock)errorBlock __attribute__((deprecated("Use APIs without keyringID value instead.")));

- (void)retrieveUpdateTransactions:(NSURL *)serverURL transactionID:(NSString *)transactionID completion:(CompletionBlockUpdateAFTransaction)completionBlock error:(ErrorBlock)errorBlock;

/** DEPRECATED */
- (void)retrieveSignatureTransactions:(NSURL *)serverURL transactionID:(NSString *)transactionID keyringID:(NSString *)keyringID completion:(CompletionBlockSignatureTransaction)completionBlock error:(ErrorBlock)errorBlock __attribute__((deprecated("Use APIs without keyringID value instead.")));

- (void)retrieveSignatureTransactions:(NSURL *)serverURL transactionID:(NSString *)transactionID completion:(CompletionBlockSignatureTransaction)completionBlock error:(ErrorBlock)errorBlock;

/** DEPRECATED */
- (void)retrieveAuthenticationTransactions:(NSURL *)serverURL transactionID:(NSString *)transactionID keyringID:(NSString *)keyringID completion:(CompletionBlockAuthenticationTransaction)completionBlock error:(ErrorBlock)errorBlock __attribute__((deprecated("Use APIs without keyringID value instead.")));

- (void)retrieveAuthenticationTransactions:(NSURL *)serverURL transactionID:(NSString *)transactionID completion:(CompletionBlockAuthenticationTransaction)completionBlock error:(ErrorBlock)errorBlock;

/*!
 * @discussion Checks if an app instance is valid. Returns nil if valid or a NSError object with localizedDescription set to:
 * "NOT_FOUND", "DEVICE_CHANGED_OR_DATA_RESTORED" or "UNKNOWN".
 * @param serverUrl the server url on which the app instance is bound
 */
- (NSError*)checkAppInstance:(NSURL *)serverUrl;

/*!
 * @discussion generate HMAC OTP value
 */
- (NSString*)generateHOTPWithPin:(NSString*)pin andKeyringId:(NSString*)keyringId;


- (void)suspendAuthenticatorFactor:(CCMIDAuthenticationFactorType)type transaction:(CCMIDTransaction *)transaction completion:(CompletionBlockEnrolmentData)completionBlock error:(ErrorBlock)errorBlock __attribute__((deprecated("Use `-(void)updateAuthenticatorFactorStatus:authenticatorFactorType:newStatus:extraOptions:completion:error:` instead.")));

#pragma mark - Re-Activate Authentication Factor
/*!
 * @discussion Re-Activate authenticator factor.
 * @param transaction The transaction to use, at this moment only.
 * @param authenticatorFactorType that could be one of followings
 
 CCMIDAuthenticationFactorTypePIN_SRP,
 CCMIDAuthenticationFactorTypeFACE_DEVICE,
 CCMIDAuthenticationFactorTypeFINGER,
 CCMIDAuthenticationFactorTypeSENSOR,
 CCMIDAuthenticationFactorTypeDEVICE_ONLY
 
 * @param newStatus The authenticator factor status type, that could be one of followings
 
 CCMIDStatusTypeValid,
 CCMIDStatusTypeSuspended
 
 * @param extraOptions if necessary. The possible keys are: kEncryptedTemplateOption, kLivenessPredictionOption, kResetStoreOption and kVerifyAfterFaceUpdated.
 * @param completionBlock The completion callback to be executed if success.
 * @param errorBlock The error callback to be executed if an error occurred.
 */
- (void)updateAuthenticatorFactorStatus:(CCMIDTransaction *)transaction authenticatorFactorType:(CCMIDAuthenticationFactorType)authenticatorFactorType newStatus:(CCMIDStatusType)newStatus extraOptions:(NSDictionary *)extraOptions completion:(CompletionBlockString)completionBlock error:(ErrorBlock)errorBlock;

@end
