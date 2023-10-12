![f976633808e336bdcaab3d2c476dfdcb](https://github.com/zhizi01/android_zhizi/assets/88622750/5077202b-1a4c-4cb5-9643-314972426599)# DLL说明
android_zhizi.dll 是一个 通过adb获取android基本信息的dll，最初开发目的是为了适配易语言。

# 开发环境
IDE: Visual Sutdio 2022
C++: vc2022

# 生成方法
Win32平台(比如易语言)使用,请选择Relese X86生成方法。
Win64平台使用,推荐选择Relese X64生成方法,且Relese X86生成方法可用。

#易语言调用方法
1. 将android_zhizi.dll移动到同根目录下
2. 如下图调用
![F976633808E336BDCAAB3D2C476DFDCB](https://github.com/zhizi01/android_zhizi/assets/88622750/8b06a796-13b6-4fb0-9008-9e40b19bdcdc)
3. 使用方法 GetDeviceInformation(你的adb目录) 就可以了。
