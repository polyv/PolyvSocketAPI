//
//  PLVSocketClassObject.h
//  PLVLiveSDK
//
//  Created by ftao on 22/12/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVSocketObject.h"

/// 互动课堂事件
typedef NS_ENUM(NSUInteger, PLVSocketClassEventType) {
    /// 开始上课事件
    PLVSocketClassEventTypeOnClassStart = 0,
    /// 结束上课事件
    PLVSocketClassEventTypeOnClassEnd,
    /// 课堂控制事件
    PLVSocketClassEventTypeOnClassControl,
    /// 其他事件
    PLVSocketClassEventTypeElse,
};

@interface PLVSocketClassObject : PLVSocketObject

/// 消息/事件类型
@property (nonatomic, assign, readonly) PLVSocketClassEventType eventType;

@end
