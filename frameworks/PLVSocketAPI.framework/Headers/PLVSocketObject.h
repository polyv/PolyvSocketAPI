//
//  PLVSocketObject.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 默认用户昵称
extern NSString *const PLVSocketObjectDefaultUserNick;
/// 默认用户头像
extern NSString *const PLVSocketObjectDefaultUserPic;

/// SocketIO 事件对象类型
typedef NS_ENUM(NSUInteger, PLVSocketObjectType) {
    /// 聊天室对象
    PLVSocketObjectTypeChatRoom = 1,
    /// 连麦对象
    PLVSocketObjectTypeLinkMic,
    /// 云课堂对象
    PLVSocketObjectTypePPT,
    /// 互动课堂对象
    PLVSocketObjectTypeClass,
};

/// SocketIO 对象用户类型
typedef NS_ENUM(NSUInteger, PLVSocketObjectUserType) {
    /// 学生（普通直播观看下用户类型）
    PLVSocketObjectUserTypeStudent,
    /// 云课堂学员（PPT模式下用户类型）
    PLVSocketObjectUserTypeSlice,
    /// 教师（推流端用户类型）
    PLVSocketObjectUserTypeTeacher
};

/** 返回 SocketIO 对象用户类型对应的字符串符号*/
NSString *NameStringWithSocketObjectUserType(PLVSocketObjectUserType userType);

/**
 SocketObject 对象的基类
 */
@interface PLVSocketObject : NSObject

/// 房间号/频道号
@property (nonatomic, readonly) NSUInteger roomId;

/// 用户昵称
@property (nonatomic, readonly) NSString *nickName;

/// 用户头像
@property (nonatomic, readonly) NSString *avatar;

/// 用户Id（生成登录对象时生成）
@property (nonatomic, readonly) NSUInteger userId;

/// socket 对象类型
@property (nonatomic, readonly) PLVSocketObjectType objectType;

/// 客户端用户类型
@property (nonatomic, readonly) PLVSocketObjectUserType userType;

/// 消息/事件名
@property (nonatomic, strong) NSString *event;

/// 消息/事件内容
@property (nonatomic, strong) NSDictionary *jsonDict;

/// 是否本地消息/事件（本地生成的对象）
@property (nonatomic, getter=isLocalMessage) BOOL localMessage;

/**
 生成一个登录对象
 
 @param roomId 房间号/频道号
 @param nickName 用户昵称，为空或教师角色时使用默认昵称
 @param avatar 用户头像，为空时使用默认头像
 @param userType 用户类型：普通直播观看端使用 TypeStudent；云课堂直播观看端使用 TypeSlice；推流登录使用 TypeTeacher
 @return PLVSocketObject 的登录对象
 */
+ (instancetype)socketObjectForLoginEventWithRoomId:(NSUInteger)roomId nickName:(NSString *)nickName avatar:(NSString *)avatar userType:(PLVSocketObjectUserType)userType;

/**
 便利初始化方法，使用子类调用

 @param jsonDict 消息/事件内容
 @return PLVSocketObject 子类对象
 */
+ (instancetype)socketObjectWithJsonDict:(NSDictionary *)jsonDict;

@end
