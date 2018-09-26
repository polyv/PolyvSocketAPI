//
//  PLVSocketObject.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 默认用户昵称
//extern NSString *const PLVSocketObjectDefaultUserNick;
/// 默认用户头像地址
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
    ///答题卡对象
    PLVSocketObjectTypeTriviaCard,
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
/// 用户Id
@property (nonatomic, readonly) NSString *userId;
/// 用户 IP
@property (nonatomic, readonly) NSString *clientIp;
/// 是否被禁言
@property (nonatomic, getter=isBanned) BOOL banned;

/// 默认用户，登录时未设置昵称(即设置为nil)时为默认用户
@property (nonatomic, assign) BOOL defaultUser;

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

/**
 重命名昵称 **重置昵称成功后调用**
 
 @param newNickname 新昵称
 */
- (void)renameNickname:(NSString *)newNickname;

@end

/// 聊天室事件
typedef NS_ENUM(NSUInteger, PLVSocketChatRoomEventType) {
    /// 登录消息，登录房间的时候服务器会广播这一消息
    PLVSocketChatRoomEventType_LOGIN            = 0,
    /// 退出消息，断开连接服务器广播的消息
    PLVSocketChatRoomEventType_LOGOUT           = 1,
    /// 公告消息，如有公告，登录房间的时候服务器会广播这一消息，公告即为管理员的发言信息
    PLVSocketChatRoomEventType_GONGGAO          = 2,
    /// 公告消息，POLYV 后台聊天室管理中，发布公告的内容
    PLVSocketChatRoomEventType_BULLETIN         = 3,
    /// 发言，接收别人的发言消息和严禁词消息(不包括自己)
    PLVSocketChatRoomEventType_SPEAK            = 4,
    /// 昵称设置
    PLVSocketChatRoomEventType_SET_NICK         = 5,
    
    /// 送花事件
    PLVSocketChatRoomEventType_FLOWERS          = 6,
    /// 点赞事件
    PLVSocketChatRoomEventType_LIKES            = 7,
    /// 打赏事件，目前需要通过HTTP接口进行支付后，由后台通知服务器
    PLVSocketChatRoomEventType_REWARD           = 8,
    /// 发红包，和打赏的情况类似，也是通过HTTP接口支付后由后台通知服务器
    PLVSocketChatRoomEventType_REDPAPER         = 9,
    
    /// 删除某条聊天记录，目前需要通过HTTP接口调用
    PLVSocketChatRoomEventType_REMOVE_CONTENT   = 10,
    /// 清空聊天记录
    PLVSocketChatRoomEventType_REMOVE_HISTORY   = 11,
    /// 关闭聊天室
    PLVSocketChatRoomEventType_CLOSEROOM        = 12,
    /// 关闭弹幕
    PLVSocketChatRoomEventType_CLOSE_DANMU      = 13,
    
    /// 禁言事件
    PLVSocketChatRoomEventType_ADD_SHIELD       = 14,
    PLVSocketChatRoomEventType_BANIP            = 15, // 旧版
    /// 解禁言事件
    PLVSocketChatRoomEventType_REMOVE_SHIELD    = 16,
    PLVSocketChatRoomEventType_UNSHIELD         = 17, // 旧版
    /// 踢人事件
    PLVSocketChatRoomEventType_KICK             = 18,
    
    /// 调试模式，调试模式的开关在助教页面
    PLVSocketChatRoomEventType_DEBUG            = 19,
    /// 聊天室管理操作事件（关闭欢迎语、关闭点赞语）
    PLVSocketChatRoomEventType_CHATROOM_CONTROL = 20,
    
    /* 私聊事件*/
    /// 学生在观看端提问
    PLVSocketChatRoomEventType_S_QUESTION       = 21,
    /// 老师回答学生的提问
    PLVSocketChatRoomEventType_T_ANSWER         = 22,
    
    /// 老师在客户端发起问答，参考：http://dev.polyv.net/2016/08/clientchat/ 2.3问答功能
    PLVSocketChatRoomEventType_QUESTION         = 23,
    /// 老师在客户端关闭问答
    PLVSocketChatRoomEventType_CLOSE_QUESTION   = 24,
    /// 学员在观看端回答老师的问答
    PLVSocketChatRoomEventType_ANSWER           = 25,
    
    /// 自定义消息接收事件，目前只能通过后台管理员调用HTTP接口发送消息，可参考http://dev.polyv.net/2016/12/send-chat/
    PLVSocketChatRoomEventType_CUSTOMER_MESSAGE = 26,
    
    /// 其他事件
    PLVSocketChatRoomEventType_ELSE             = 27
};

/**
 聊天室消息对象
 */
@interface PLVSocketChatRoomObject : PLVSocketObject

/// 私聊事件
@property (nonatomic, getter=isPrivateChat, readonly) BOOL privateChat;

/// 消息/事件类型
@property (nonatomic, assign, readonly) PLVSocketChatRoomEventType eventType;

/**
 生成一个新的昵称对象
 
 @param login 登录对象
 @param nickName 新昵称
 @return PLVSocketChatRoomObject 的新昵称对象
 */
+ (instancetype)chatRoomObjectForNewNickNameWithLoginObject:(PLVSocketObject *)login nickName:(NSString *)nickName;

#pragma mark - 公共聊天

/**
 生成一个发言对象
 
 @param roomId 发言内容
 @param content 当前房间号
 @return PLVSocketChatRoomObject 的发言事件对象
 */
+ (instancetype)chatRoomObjectForSpeakEventTypeWithRoomId:(NSUInteger)roomId content:(NSString *)content;

/**
 生成一个送花对象
 
 @param roomId 当前房间号
 @param nickName 送花人昵称，为空时使用默认昵称
 @param userImg 送花人头像地址，为空时使用默认头像
 @return PLVSocketChatRoomObject 的送花事件对象
 */
+ (instancetype)chatRoomObjectForFlowersEventTypeWithRoomId:(NSUInteger)roomId nickName:(NSString *)nickName userImg:(NSString *)userImg;

/**
 生成一个点赞对象
 
 @param roomId 当前房间号
 @param nickName 点赞人昵称，为空时使用默认昵称
 @return PLVSocketChatRoomObject 的点赞事件对象
 */
+ (instancetype)chatRoomObjectForLikesEventTypeWithRoomId:(NSUInteger)roomId nickName:(NSString *)nickName;

#pragma mark - 私有聊天

/**
 生成一个学生提问对象
 
 @param login 登录对象
 @param content 发言内容
 @return PLVSocketChatRoomObject 的学生提问对象
 */
+ (instancetype)chatRoomObjectForStudentQuestionEventTypeWithLoginObject:(PLVSocketObject *)login content:(NSString *)content;

@end

/// 连麦事件
typedef NS_ENUM(NSUInteger, PLVSocketLinkMicEventType) {
    /// 老师开启关闭连麦
    PLVSocketLinkMicEventType_OPEN_MICROPHONE = 0,
    
    /// 举手事件
    PLVSocketLinkMicEventType_JOIN_REQUEST,
    /// 老师同意通话事件
    PLVSocketLinkMicEventType_JOIN_RESPONSE,
    /// 加入声网成功事件
    PLVSocketLinkMicEventType_JOIN_SUCCESS,
    /// 结束发言事件
    PLVSocketLinkMicEventType_JOIN_LEAVE,
};

/**
 连麦消息对象
 */
@interface PLVSocketLinkMicObject : PLVSocketObject

/// 消息/事件类型
@property (nonatomic, assign) PLVSocketLinkMicEventType eventType;


/**
 生成一个连麦事件对象
 
 @param eventType 事件类型：只支持 PLVSocketLinkMicEventType_JOIN_REQUEST(举手) 和 PLVSocketLinkMicEventType_JOIN_LEAVE(结束发言) 两个类型
 @param roomId 房间号/频道号
 @param userNick 举手学员昵称
 @param userPic 举手学员头像
 @param userId 举手学员id(32位无符号整数,详见声网API)
 @param userType 用户类型：普通直播观看端使用 TypeStudent；云课堂直播观看端使用 TypeSlice；暂不支持 TypeTeacher 类型
 @return PLVSocketLinkMicObject 实例对象
 */
+ (instancetype)linkMicObjectWithEventType:(PLVSocketLinkMicEventType)eventType roomId:(NSUInteger)roomId userNick:(NSString *)userNick userPic:(NSString *)userPic userId:(NSUInteger)userId userType:(PLVSocketObjectUserType)userType;

@end

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

/**
 云课堂答题卡对象
 */
@interface PLVSocketTriviaCardObject : PLVSocketObject

@end
