//
//  QuickWebInvokedCommand.h
//  QuickWebKit
//
//  Created by pcjbird on 2017/12/24.
//  Copyright © 2017年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface QuickWebInvokedCommand : NSObject
{
    NSString* _secretId;
    NSString* _callbackId;
    NSDictionary* _arguments;
}

@property (nonatomic, readonly) NSString* secretId;
@property (nonatomic, readonly) NSString* callbackId;
@property (nonatomic, readonly) NSDictionary* arguments;

+ (QuickWebInvokedCommand*)commandFromSecretId:(NSString *)secretId callbackId:(NSString*)callbackId jsonArgs:(NSString*)argString;

@end
