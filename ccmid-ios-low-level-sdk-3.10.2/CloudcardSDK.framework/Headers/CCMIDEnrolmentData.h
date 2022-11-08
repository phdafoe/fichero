//
//  CCMIDEnrolmentData.h
//  CloudcardCoreAPI
//
//  Created by DOGARU Cristiana - EXT-CF (MORPHO) on 30/03/2016.
//  Copyright © 2016 Dictao. All rights reserved.
//

typedef NS_ENUM(NSInteger, CCMIDStatusEnrolment)
{
    CCMIDStatusEnrolmentUNKWOWN,
    CCMIDStatusEnrolmentINSUFFICIENT_SAMPLE,
    CCMIDStatusEnrolmentACCEPTED
};

@interface CCMIDEnrolmentData : NSObject

@property (nonatomic, copy) NSString *encryptedTemplate;
@property (nonatomic) CCMIDStatusEnrolment status;

//CCMID-4219
@property (nonatomic, copy) NSString *encryptedPhoto;
@property (nonatomic, copy) NSString* facialAlgorithm;

@end
