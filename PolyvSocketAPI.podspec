#
#  Be sure to run `pod spec lint PolyvSocketAPI.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name         = "PolyvSocketAPI"
  s.version      = "0.6.2"
  s.summary      = "Polyv iOS 直播观看、推流、聊天室相关接口"
  # s.description  = <<-DESC
                   # DESC

  s.homepage     = "https://github.com/polyv/PolyvSocketAPI"
  s.license      = { :type => "MIT" }
  s.author             = { "ftao" => "fft1026@163.com" }
  s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/polyv/PolyvSocketAPI.git", :tag => "#{s.version}" }

  # s.source_files  = "Classes", "Classes/**/*.{h,m}"
  # s.exclude_files = "Classes/Exclude"

  # s.public_header_files = "Classes/**/*.h"

  # s.framework  = "SomeFramework"
  # s.frameworks = "SomeFramework", "AnotherFramework"

  s.requires_arc = true

  # s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  s.subspec 'Core' do |cs|
  	cs.vendored_frameworks = 'frameworks/PLVSocketAPI.framework'	
  end

  s.subspec 'Socket' do |ss|
  	ss.dependency "Socket.IO-Client-Swift", "~>13.2.0"	
  end

end
