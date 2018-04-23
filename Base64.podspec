Pod::Spec.new do |s|
    s.summary          = "base64 - forked from git ncb000gt/base64 and translated to obj-c"
    s.homepage         = "http://iharder.sourceforge.net/current/java/base64"
    s.name             = "Base64"
    s.version          = '2.3.8-j2obj2.0.5'
    s.author           = { "Marcus Smith" => "marcus@laundrapp.com" }
    s.source           = { :git => "https://github.com/laundrapp/base64.git" }
    s.platform         = :ios, '8.0'
    s.compiler_flags = '-Wno-nullability-completeness'
    
    s.requires_arc = false
    s.public_header_files =   'gen/objc/**/*.h'
    s.header_mappings_dir =   'gen/objc'
    s.source_files =          'gen/objc/**/*.{h,m}'
    s.compiler_flags = '-Wno-nullability-completeness'
    
end
    