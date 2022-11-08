//
//  NSDate+String.h
//  Signature
//
//  Created by Cyril on 1/21/13.
//  Copyright (c) 2013 Dictao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (String)

+ (NSDate*)dateFromString: (NSString *) string;
+ (NSDate*)dateFromTString:(NSString*)dateString;
+ (NSString*)formatStringFromDate:(NSDate*)date;
+ (NSString*)dateFormatStringFromDate:(NSDate*)date;

@end
