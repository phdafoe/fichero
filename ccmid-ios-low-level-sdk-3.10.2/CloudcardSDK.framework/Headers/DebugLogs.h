//
//  DebugLogs.h
//  CloudcardCoreAPI
//
//  Created by Cristiana Dogaru on 12/10/2015.
//  Copyright © 2015 Dictao. All rights reserved.
//

#ifdef DEBUG
    #define DebugLog(...) NSLog(__VA_ARGS__);
#else
    #define DebugLog(...) ;
#endif
