# FnNAS for EasePi-A2 完整使用指南

适用于 **fnOS 固件构建、Ubuntu 刷机、Maskrom 模式刷写、自定义 U-Boot 镜像** 全流程

---

## 📖 项目简介

基于 [ophub/fnnas](https://github.com/ophub/fnnas/blob/main/README.cn.md) 构建适配 **EasePi-A2 (RK35xx)** 的 fnNAS 固件，提供完整的编译、刷机、自定义镜像教程，支持 Linux 环境一键操作。

## ✨ 核心特性

- 专为 EasePi-A2 硬件优化

- 支持 Linux 环境编译与刷机

- 提供 Maskrom / 系统内双模式刷写

- 自定义 U-Boot、定制镜像一站式教程

- 适配 Rockchip RK35xx 平台

---

## 🛠️ 一、fnOS 镜像构建（编译固件）

### 环境要求

Ubuntu 系统，已安装基础编译依赖

### 构建命令

```Bash

# 克隆源码（本项目仓库）
git clone https://github.com/ifroncy01/easepi-a2.git
cd easepi-a2

# 为 EasePi-A2 构建固件
sudo ./renas -b easepi-a2 -k 6.12.y -s 256/3000 -e 17
```

### 参数说明

|参数|作用|
|---|---|
|`-b easepi-a2`|指定设备型号：EasePi-A2|
|`-k 6.12.y`|使用 Linux 6.12.y 内核|
|`-s 256/3000`|分区/空间配置|
|`-e 17`|版本/扩展参数|
---

## 🖥️ 二、Ubuntu 环境配置（RK 刷机工具）

### 1. 安装 rkdeveloptool

```Bash

# 克隆源码
git clone https://github.com/rockchip-linux/rkdeveloptool.git
cd rkdeveloptool

# 编译安装（先安装依赖：libusb-1.0-0-dev libudev-dev）
sudo apt install -y libusb-1.0-0-dev libudev-dev
make
sudo make install
```

### 2. 添加 udev 规则（普通用户权限）

```Bash

# 创建规则文件
sudo nano /etc/udev/rules.d/50-rockchip.rules
```

写入以下内容：

```Plain Text

# Rockchip USB Device (Maskrom/Loader 模式)
SUBSYSTEM=="usb", ATTR{idVendor}=="2207", MODE="0666"
SUBSYSTEM=="usb", ATTR{idVendor}=="18d1", MODE="0666"
```

重启 udev 服务：

```Bash

sudo udevadm control --reload-rules
sudo udevadm trigger
```

### 3. 验证安装

```Bash

rkdeveloptool -v
```

输出版本号即安装成功

---

## 🔌 三、EasePi-A2 进入 Maskrom/Loader 模式

1. 断开设备电源

2. 短接 **Maskrom 触点**

3. 连接 USB 线到电脑

4. 保持短接直至设备被识别

5. 松开短接，进入刷机模式

---

## 🚀 四、Maskrom 模式刷写 fnNAS 固件

### 完整刷机命令

```Bash

# 1. 检测设备
rkdeveloptool ld

# 2. 加载 RK35xx 专用 MiniLoader
rkdeveloptool db MiniLoaderAll.bin

# 3. 刷写 fnNAS 镜像（从 0 地址写入）
rkdeveloptool wl 0 your/fnnas.img

# 4. 刷写完成，重启设备
rkdeveloptool rd
```

---

## 📦 五、单独刷写 U-Boot 固件

### 方法 1：使用 rkdeveloptool 刷写

```Bash

rkdeveloptool wl 0x40000 u-boot-rockchip.bin
```

### 方法 2：Linux 系统内直接刷写

```Bash

dd if=u-boot-rockchip.bin of=/dev/mmcblk0p1 bs=32k seek=1 conv=notrunc status=none
```

---

## 🔧 六、自定义镜像：内置 U-Boot 到固件

直接将 U-Boot 写入 fnNAS 镜像文件，**刷机后自动生效**：

```Bash

# 写入 idbloader.img
dd if=idbloader.img of=fnnas-x.x.x-easepi-a2.img conv=fsync,notrunc bs=512 seek=64

# 写入 u-boot.itb
dd if=u-boot.itb of=fnnas-x.x.x-easepi-a2.img conv=fsync,notrunc bs=512 seek=16384
```

---

## 📌 常用命令速查表

|用途|命令|
|---|---|
|编译 EasePi-A2 固件|`sudo ./renas -b easepi-a2 -k 6.12.y -s 256/3000 -e 17`|
|检测 RK 设备|`rkdeveloptool ld`|
|加载 MiniLoader|`rkdeveloptool db MiniLoaderAll.bin`|
|刷写系统镜像|`rkdeveloptool wl 0 fnnas.img`|
|重启设备|`rkdeveloptool rd`|
|刷写 u-boot|`rkdeveloptool wl 0x40000 u-boot-rockchip.bin`|
|系统内刷写 uboot|`dd if=u-boot-rockchip.bin of=/dev/mmcblk0p1 bs=32k seek=1 conv=notrunc status=none`|
---

## ⚠️ 注意事项

1. 刷机前**备份重要数据**，避免丢失

2. Maskrom 模式下必须使用 **RK35xx 专用 MiniLoaderAll.bin**

3. 自定义镜像时，确保文件名与路径正确

4. 刷写过程中**不要断开 USB/电源**

5. Ubuntu 环境必须配置 udev 规则，否则无法识别设备

---

## 📞 相关链接...

- 官方源码：[ophub/fnnas](https://github.com/ophub/fnnas)

- 刷机工具：[rockchip-linux/rkdeveloptool](https://github.com/rockchip-linux/rkdeveloptool)

- 设备平台：Rockchip RK35xx

---