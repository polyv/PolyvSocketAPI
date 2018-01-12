# PolyvSocketAPI

当前版本：
- PolyvSocketAPI ~ [0.3.0](http://repo.polyv.net/ios/download/socketAPI/0.3.0/PLVSocketAPI.framework-full.zip)（包含依赖库）

依赖库版本：
- Socket.IO-Client-Swift ~ 12.1.3
- Starscream ~ 2.1.1

Podfile 中添加

```ruby
platform :ios, "8.0"

use_frameworks!

target 'YourApp' do
    
    pod 'PolyvSocketAPI', '~> 0.3.0'
end

# 以下设置 Pods 子 Target 的 Swift 版本为 4.0
post_install do |installer|
    installer.pods_project.targets.each do |target|
        target.build_configurations.each do |configuration|
            configuration.build_settings['SWIFT_VERSION'] = "4.0"
        end
    end
end
```



## 历史版本

### v0.3.0

`#import <PLVSocketAPI/PLVSocketAPI.h>`

依赖库版本：

- Socket.IO-Client-Swift ~ 12.1.3
- Starscream ~ 2.1.1



直接下载：[0.3.0](http://repo.polyv.net/ios/download/socketAPI/0.3.0/PLVSocketAPI.framework-full.zip)

CocoaPods： `pod 'PolyvSocketAPI', '~> 0.3.0'`



###  v0.2.1 

`#import <PLVChatManager/PLVChatManager.h>`

依赖库版本：

- Socket.IO-Client-Swift ~ 12.0.0
- StarscreamSocketIO ~ 8.0.7



直接下载：[0.2.1](http://repo.polyv.net/ios/download/socketAPI/0.2.1/PLVChatManager.framework.zip)

CocoaPods： `pod 'PolyvLiveAPI', '~> 0.2.1'`