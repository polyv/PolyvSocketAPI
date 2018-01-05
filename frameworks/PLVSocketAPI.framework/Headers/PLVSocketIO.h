//
//  PLVSocketIO.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVSocketObject.h"
#import "PLVSocketChatRoomObject.h"
#import "PLVSocketLinkMicObject.h"
#import "PLVSocketPPTObject.h"
#import "PLVSocketClassObject.h"

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

@protocol PLVSocketIODelegate;

/**
 SocketIO 对象
 */
@interface PLVSocketIO : NSObject

/// SocketIO 代理人
@property (nonatomic, weak) id <PLVSocketIODelegate> delegate;
/// Socket id
@property (nonatomic, strong, readonly) NSString *socketId;
/// socketIO 连接状态
@property (nonatomic, assign, readonly) PLVSocketIOState socketIOState;
/// debug模式
@property (nonatomic, assign) BOOL debugMode;

/**
 初始化 SocketIO，使用 -connect 连接

 @param connetToken 连接 token，Socket、连麦授权接口中获取
 @param enableLog 是否输出调试信息
 @return SocketIO 实例对象
 */
- (instancetype)initSocketIOWithConnectToken:(NSString *)connetToken enableLog:(BOOL)enableLog;

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

/**
 SocketIO 代理消息
 */
@protocol PLVSocketIODelegate <NSObject>

@required
/** SocketIO 连接服务器成功*/
- (void)socketIO:(PLVSocketIO *)socketIO didConnectWithInfo:(NSString *)info;

@optional
/** SocketIO 收到聊天室消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveChatMessage:(PLVSocketChatRoomObject *)chatObject;

/** SocketIO 收到连麦消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveLinkMicMessage:(PLVSocketLinkMicObject *)linkMicObject;

/** SocketIO 收到云课堂消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceivePPTMessage:(PLVSocketPPTObject *)pptObject;

/** SocketIO 收到互动课堂消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveClassMessage:(PLVSocketClassObject *)classObject;

/** SocketIO 和服务器失去连接*/
- (void)socketIO:(PLVSocketIO *)socketIO didDisconnectWithInfo:(NSString *)info;

/** SocketIO 连接服务器出错*/
- (void)socketIO:(PLVSocketIO *)socketIO connectOnErrorWithInfo:(NSString *)info;

/** SocketIO 重新连接服务器*/
- (void)socketIO:(PLVSocketIO *)socketIO reconnectWithInfo:(NSString *)info;

/** 本地出错信息回调*/
- (void)socketIO:(PLVSocketIO *)socketIO localError:(NSString *)description;

@end
