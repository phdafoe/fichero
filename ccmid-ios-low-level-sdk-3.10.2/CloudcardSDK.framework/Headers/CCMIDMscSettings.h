//
//  CCMIDMscSettings.h
//  CloudcardCoreAPI
//
//  Created by BABU Kiran on 08/09/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum MSC_RT_LOGLEVEL
{
    MSC_RT_LOGLEVEL_DEBUG,          ///< Debug message
    MSC_RT_LOGLEVEL_INFO,           ///< Informative message
    MSC_RT_LOGLEVEL_WARNING,        ///< Warning message
    MSC_RT_LOGLEVEL_ERROR,          ///< Error message         
    MSC_RT_LOGLEVEL_INVALID = (int32_t)0xFFFFFFFF ///< Do not use
} msc_rt_loglevel;


@interface CCMIDMscRegistration : NSObject
  @property (nonatomic, readonly) char *preset,*subpreset;
  @property (nonatomic, readonly) NSString *app;
  @property (nonatomic, readonly) NSString *liveness;

- (instancetype) initWithDictionary:(NSDictionary *)dictionary;

@end

@interface CCMIDMscAuthentication : NSObject
  @property (nonatomic, readonly) char *preset,*subpreset;
  @property (nonatomic, readonly) NSString *app;
  @property (nonatomic, readonly) NSString *liveness;


- (instancetype) initWithDictionary:(NSDictionary *)dictionary;

@end

@interface CCMIDMscSettings : NSObject

@property (nonatomic, readonly) CCMIDMscAuthentication *mscAuthentication;
@property (nonatomic, readonly) CCMIDMscRegistration *mscregistration;
@property (nonatomic, readonly) BOOL isMscEnabled;
@property (nonatomic, readonly) msc_rt_loglevel RT_Log_Level;

- (instancetype) initWithDictionary:(NSDictionary *)dictionary;
+ (char *) getMscSettings : (NSString *) liveness;

@end
