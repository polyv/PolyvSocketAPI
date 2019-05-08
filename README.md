# PolyvSocketAPI

## 使用说明

### 版本信息

 - 最新版本：0.6.1
 - 初始化接口后会在控制台输出，搜索关键字 `PLVSocketAPI version`

依赖库版本：

 - Socket.IO-Client-Swift '~>13.2.0'
   - Starscream ~ 3.0

### 导入头文件

`#import <PLVSocketAPI/PLVSocketAPI.h>`

### Podfile 中配置

```ruby
platform :ios, "8.0"

use_frameworks!

target 'YourApp' do
    pod 'PolyvSocketAPI', '~> 0.6.0'
end

```

0.4.0 以下版本 PolyvSocketAPI 需要在 Podfile 中添加以下配置

```ruby
# 以下设置 Pods 子 Target 的 Swift 版本为 4.0（PolyvSocketAPI 0.4.0版本下）
post_install do |installer|
    installer.pods_project.targets.each do |target|
        target.build_configurations.each do |configuration|
            configuration.build_settings['SWIFT_VERSION'] = "4.0"
        end
    end
end
```

### 手动下载

 - 在下表中找到对应的 Socket.IO 和 Starscream 版本手动下载
    - 将 SocketIO.framework 、Starscream.framework 库添加至项目的 `Embeded Binaries`中
    - 设置 `Build Settings` -> `Always Embed Swift Standard Libraries` 为 `YES
- 如果集成中出现 ` Reason: image not found：` 错误，可检查是否 Swift 版本问题
- 或者直接下载 [Socket.IO 源码](https://github.com/socketio/socket.io-client-swift/releases)（包含项目)、[Starscream](https://github.com/daltoniam/Starscream/releases)，手动在自己编译器上进行编译调试

| Swift version\framework |                           SocketIO                           |                          Starscream                          | PolyvSocketAPI |
| :---------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: | :------------: |
|    4.0.3 / Xcode 9.2    | [v13.2.1](http://repo.polyv.net/ios/download/socket.io/SocketIO.framework_13.2.1.zip) | [v3.0.5](http://repo.polyv.net/ios/download/starscream/Starscream.framework_3.0.5.zip) |    >= 0.4.0    |
|   4.1.2/ Xcode 9.4.1    | [v13.2.1](http://repo.polyv.net/ios/download/socket.io/swift4.1.2_SocketIO.framework_13.2.1.zip) | [v3.0.5](http://repo.polyv.net/ios/download/starscream/swift4.1.2_Starscream.framework_3.0.5.zip) |    >= 0.4.0    |

## 历史版本

### 0.6.1+190508

- 支持 Bitcode

### 0.6.0+181019

- 添加聊天室 “CHAT_IMG” 图片事件
- 添加新的登录接口：可设置自定义授权参数及 userId
- 更新 renameNickname 方法
- 代码优化，缓存代理方法信息

直接下载：[PLVSocketAPI_0.5.0+180912](http://repo.polyv.net/ios/download/socketAPI/PLVSocketAPI_0.6.0+181019.zip)

### 0.5.0+180912

- 新增 “昵称设置” 事件及消息对象

- 新增 “用户登录状态” 属性及状态改变回调

- 聊天室回调区分公聊和私聊方法

- 移除冗余 SocketObject 类文件，添加至 PLVSocketObject 类中

  直接下载：[PLVSocketAPI_0.5.0+180912](http://repo.polyv.net/ios/download/socketAPI/PLVSocketAPI_0.5.0+180912.zip)

### 0.4.1+180630

- 修复连麦时提交数据格式不正确的问题

直接下载：[PLVSocketAPI_0.4.1+180630](http://repo.polyv.net/ios/download/socketAPI/PLVSocketAPI_0.4.1+180630_2.zip)

### 0.4.0+180614

- 升级 socket.io 库至 13.2 版本
- PLVSocketIO 类新增 userId、roomId 属性

CocoaPods： `pod 'PolyvSocketAPI', '~> 0.4.0'`

直接下载：[PLVSocketAPI_0.4.0+180614](http://repo.polyv.net/ios/download/socketAPI/PLVSocketAPI_0.4.0+180614.zip)

依赖库版本：

- [Socket.IO-Client-Swift ~ 13.2.1](http://repo.polyv.net/ios/download/socket.io/SocketIO.framework_13.2.1.zip)
- [Starscream ~ 3.0.5](http://repo.polyv.net/ios/download/starscream/Starscream.framework_3.0.5.zip)

### 0.3.0+180105

`#import <PLVSocketAPI/PLVSocketAPI.h>`

依赖库版本：

- Socket.IO-Client-Swift ~ 12.1.3
- Starscream ~ 2.1.1

CocoaPods： `pod 'PolyvSocketAPI', '~> 0.3.0'`

直接下载（包含 PLVSocketAPI、SocketIO 和 Starscream 的 Framework）：[PLVSocketAPI-full_0.3.0](http://repo.polyv.net/ios/download/socketAPI/0.3.0/PLVSocketAPI.framework-full.zip)

###  0.2.1

`#import <PLVChatManager/PLVChatManager.h>`

依赖库版本：

- Socket.IO-Client-Swift ~ 12.0.0
- StarscreamSocketIO ~ 8.0.7

CocoaPods： `pod 'PolyvLiveAPI', '~> 0.2.1'`

直接下载：[PLVChatManager_0.2.1](http://repo.polyv.net/ios/download/socketAPI/0.2.1/PLVChatManager.framework.zip)
