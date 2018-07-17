# PolyvSocketAPI

当前版本：0.4.1

 `pod 'PolyvSocketAPI', '~> 0.4.1'`

依赖库版本：
- Socket.IO-Client-Swift ~ 13.2
- Starscream ~ 3.0



导入头文件

`#import <PLVSocketAPI/PLVSocketAPI.h>`



Podfile 中配置

```ruby
platform :ios, "8.0"

use_frameworks!

target 'YourApp' do
    pod 'PolyvSocketAPI', '~> 0.4.0'
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



## 历史版本

### 0.4.1+180630

- 修复连麦时提交数据格式不正确的问题

直接下载：[0.4.1+180630](http://repo.polyv.net/ios/download/socketAPI/PLVSocketAPI_0.4.1+180630_2.zip)

### 0.4.0+180614

- 升级 socket.io 库至 13.2 版本
- PLVSocketIO 类新增 userId、roomId 属性

CocoaPods： `pod 'PolyvSocketAPI', '~> 0.4.0'`

直接下载：[0.4.0+180614](http://repo.polyv.net/ios/download/socketAPI/PLVSocketAPI_0.4.0+180614.zip)

依赖库版本：

- [Socket.IO-Client-Swift ~ 13.2.1](http://repo.polyv.net/ios/download/socket.io/SocketIO.framework_13.2.1.zip)
- [Starscream ~ 3.0.5](http://repo.polyv.net/ios/download/starscream/Starscream.framework_3.0.5.zip)

### 0.3.0

`#import <PLVSocketAPI/PLVSocketAPI.h>`

依赖库版本：

- Socket.IO-Client-Swift ~ 12.1.3
- Starscream ~ 2.1.1

CocoaPods： `pod 'PolyvSocketAPI', '~> 0.3.0'`

直接下载（包含Socket.IO和Starscream）：[0.3.0](http://repo.polyv.net/ios/download/socketAPI/0.3.0/PLVSocketAPI.framework-full.zip)

###  0.2.1 

`#import <PLVChatManager/PLVChatManager.h>`

依赖库版本：

- Socket.IO-Client-Swift ~ 12.0.0
- StarscreamSocketIO ~ 8.0.7

CocoaPods： `pod 'PolyvLiveAPI', '~> 0.2.1'`

直接下载：[0.2.1](http://repo.polyv.net/ios/download/socketAPI/0.2.1/PLVChatManager.framework.zip)