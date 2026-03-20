# easepi-a2
为EasePi-A2 打包fnnas镜像
来自：htts://github.com/ophub/fnnas
# 使用方法


### fnos 镜像构建 ###
sudo ./renas -b easepi-a2 -k 6.12.y -s 256/3000 -e 17

在ubuntu中刷写飞牛固件

### 安装rkdeveloptool ###
git https://github.com/rockchip-linux/rkdeveloptool.git
cd rkdeveloptool
默认情况下普通用户无法访问 RK 设备，需添加 udev 规则：
# 创建 udev 规则文件
sudo nano /etc/udev/rules.d/50-rockchip.rules
在文件中写入以下内容（适配 RK35xx 设备的 USB ID）：
# Rockchip USB Device (Maskrom/Loader 模式)
SUBSYSTEM=="usb", ATTR{idVendor}=="2207", MODE="0666"
SUBSYSTEM=="usb", ATTR{idVendor}=="18d1", MODE="0666"
保存后重启 udev 服务：
sudo udevadm control --reload-rules
sudo udevadm trigger
# 验证安装是否成功 看版本，能输出版本号即成功
rkdeveloptool -v

EasePi-A2 进入ROM模式
# 检测设备（先将 RK35xx 设备进入 Maskrom/Loader 模式，再执行）
rkdeveloptool ld
rkdeveloptool db MiniLoaderAll.bin  # 先加载加载器（RK35xx 专用 MiniLoader）
rkdeveloptool wl 0 your/fnnas.img   # 从 0 地址开始刷写飞牛镜像
rkdeveloptool rd                    # 刷写完成后重启设备

刷写其他文件的方法：
rkdeveloptool wl 0x40000 u-boot-rockchip.bin
dd if=u-boot-rockchip.bin of=/dev/mmcblk0p1 bs=32k seek=1 conv=notrunc status=none
dd if=idbloader.img of=飞牛镜像包名 conv=fsync,notrunc bs=512 seek=64
dd if=u-boot.itb of=飞牛镜像包名 conv=fsync,notrunc bs=512 seek=16384
