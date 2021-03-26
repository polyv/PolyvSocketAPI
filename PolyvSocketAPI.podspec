Pod::Spec.new do |s|
  s.name         = "PolyvSocketAPI"
  s.version      = "0.15.0"
  s.summary      = "Polyv iOS Socket组件；对齐 0.x BusinessSDK Socket 功能"

  s.homepage     = "https://github.com/polyv/PolyvSocketAPI"
  s.license      = { :type => "MIT" }
  s.author       = { "LLH" => "luolinhao@polyv.net" }

  s.source       = { :git => "https://github.com/polyv/PolyvSocketAPI.git", :tag => "#{s.version}" }
  s.platform     = :ios, "8.0"
  s.requires_arc = true

  s.subspec 'Core' do |cs|
	cs.vendored_frameworks = 'frameworks/PLVSocketAPI.framework'	
  end

  s.subspec 'Socket' do |ss|
  	ss.dependency "Socket.IO-Client-Swift", "~>14.0.0"	
  end

  s.default_subspec = 'Core', 'Socket'
end
