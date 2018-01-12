//
//  PLVSocketPPTObject.h
//  PLVLiveSDK
//
//  Created by ftao on 05/12/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVSocketObject.h"

/// 云课堂事件
typedef NS_ENUM(NSUInteger, PLVSocketPPTEventType) {
    /// 登录Socket后服务器传值
    PLVSocketPPTEventTypeOnSliceID = 0,

    /// 客户端打开PPT操作事件
    PLVSocketPPTEventTypeOnSliceOpen,
    /// 客户端点击上课推流事件
    PLVSocketPPTEventTypeOnSliceStart,
    /// 画笔格式事件
    PLVSocketPPTEventTypeOnSliceDraw,
    /// PPT控制命令
    PLVSocketPPTEventTypeOnSliceControl,
    
    /// 其他事件(出错)
    PLVSocketPPTEventTypeElse,
};

/**
 云课堂消息对象
 */
@interface PLVSocketPPTObject : PLVSocketObject

/// 消息/事件类型
@property (nonatomic, assign, readonly) PLVSocketPPTEventType eventType;

@end
