//
//  PLVSocketIO.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVSocketObject.h"

/// socketIO 连接状态
typedef NS_ENUM(NSInteger, PLVSocketIOState) {
    /// SocketIO 未连接
    PLVSocketIOStatusNotConnected = 0,
    /// SocketIO 失去连接
    PLVSocketIOStateDisconnected = 1,
    /// SocketIO 连接中
    PLVSocketIOStateConnecting = 2,
    /// SocketIO 连接成功
    PLVSocketIOStateConnected = 3,
    /// SocketIO 连接出错
    PLVSocketIOStateConnectError = 4,
};

/// 用户状态
typedef NS_ENUM(NSInteger, PLVSocketUserState) {
    /// 用户未登录
    PLVSocketUserStateNotLogin = 0,
    /// 用户退出登录
    PLVSocketUserStateLogout = 1,
    /// 用户登录中
    PLVSocketUserStateLogining = 2,
    /// 用户登录成功
    PLVSocketUserStateLogined = 3,
    /// 用户登录失败
    PLVSocketUserStateLoginError = 4,
};

NSString *PLVNameStringWithSocketUserState(PLVSocketUserState userState);

@class PLVSocketIO;

/**
 PLVSocketIO 代理回调消息
 */
@protocol PLVSocketIODelegate <NSObject>

@required
/** SocketIO 连接服务器成功*/
- (void)socketIO:(PLVSocketIO *)socketIO didConnectWithInfo:(NSString *)info;

@optional
/** SocketIO 用户状态改变*/
- (void)socketIO:(PLVSocketIO *)socketIO didUserStateChange:(PLVSocketUserState)userState;

/** SocketIO 收到聊天室（公聊）消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceivePublicChatMessage:(PLVSocketChatRoomObject *)chatObject;
/** SocketIO 收到聊天室（私聊）消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceivePrivateChatMessage:(PLVSocketChatRoomObject *)chatObject;
/** SocketIO 收到连麦消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveLinkMicMessage:(PLVSocketLinkMicObject *)linkMicObject;

/** SocketIO 收到互动课堂消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveClassMessage:(PLVSocketClassObject *)classObject;

/** SocketIO 收到云课堂消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceivePPTMessage:(NSString *)json;

/** SocketIO 收到答题卡问题 或 答案 信息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveQuestionMessage:(NSString *)json result:(int)result;

/** SocketIO 和服务器失去连接*/
- (void)socketIO:(PLVSocketIO *)socketIO didDisconnectWithInfo:(NSString *)info;
/** SocketIO 连接服务器出错*/
- (void)socketIO:(PLVSocketIO *)socketIO connectOnErrorWithInfo:(NSString *)info;
/** SocketIO 重新连接服务器*/
- (void)socketIO:(PLVSocketIO *)socketIO reconnectWithInfo:(NSString *)info;

/** 本地出错信息回调*/
- (void)socketIO:(PLVSocketIO *)socketIO localError:(NSString *)description;

#pragma mark Deprecated
/** SocketIO 收到聊天室消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveChatMessage:(PLVSocketChatRoomObject *)chatObject;

@end

/**
 SocketIO 对象
 */
@interface PLVSocketIO : NSObject

/// SocketIO 代理对象
@property (nonatomic, weak) id <PLVSocketIODelegate> delegate;
/// Socket id
@property (nonatomic, strong, readonly) NSString *socketId;
/// 房间号/频道号
@property (nonatomic, assign, readonly) NSUInteger roomId;
/// 用户Id（由PLVSocketObjec登录对象生成）
@property (nonatomic, strong, readonly) NSString *userId;
/// Socket 用户信息
@property (nonatomic, strong, readonly) PLVSocketObject *user;
/// socketIO 连接状态
@property (nonatomic, assign, readonly) PLVSocketIOState socketIOState;
/// socketIO 用户状态
@property (nonatomic, assign, readonly) PLVSocketUserState userState;

/// debug模式
@property (nonatomic, assign) BOOL debugMode;

/**
 初始化 SocketIO，使用 -connect 连接

 @param connectToken 连接 token，Socket、连麦授权接口中获取
 @param enableLog 是否输出调试信息
 @return SocketIO 实例对象
 */
- (instancetype)initSocketIOWithConnectToken:(NSString *)connectToken enableLog:(BOOL)enableLog;

/**
 初始化 SocketIO，使用 url 服务器地址
 */
- (instancetype)initSocketIOWithConnectToken:(NSString *)connectToken url:(NSString *)url enableLog:(BOOL)enableLog;

/**
 连接 SocketIO 服务器
 */
- (void)connect;

/**
 重新连接 SocketIO 服务器
 */
- (void)reconnect;

/**
 关闭 SocketIO 连接
 */
- (void)disconnect;

/**
 移除监听所有 SocketIO 事件
 */
- (void)removeAllHandlers;

/**
 发送消息

 @param socketObject Socket 对象
 */
- (void)emitMessageWithSocketObject:(PLVSocketObject *)socketObject;

/**
 发送消息(自定义)

 @param event 发送事件名
 @param dictContent 字典数据内容
 */
- (void)emitEvent:(NSString *)event withContent:(NSDictionary *)dictContent;

@end
