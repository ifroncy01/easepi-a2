# FNNAS 项目文档

## 项目概述

FNNAS (Friendly NAS) 是一个专为 ARM 设备设计的固件构建系统，主要用于生成适用于各种 ARM 开发板的 NAS 固件镜像。该项目基于 Rockchip 平台，提供了完整的固件构建、配置和部署解决方案。

### 主要功能
- 自动构建 ARM 设备的 NAS 固件镜像
- 支持多种 Rockchip 平台设备
- 包含完整的系统配置和服务
- 提供丰富的固件和驱动支持
- 集成 GitHub Actions 自动化构建流程

## 目录结构

```
├── .github/            # GitHub 相关配置
│   ├── ISSUE_TEMPLATE/ # 问题模板
│   └── workflows/      # GitHub Actions 工作流
├── docs/               # 文档目录
├── download/           # 下载目录（包含引导加载程序等）
├── fnnas/              # 主项目目录
│   └── out/            # 生成的固件镜像输出目录
├── fnnas-arm64/        # ARM64 相关文件
├── make-fnnas/         # 构建脚本和配置文件
│   └── fnnas-files/    # 固件文件和配置
├── .gitignore          # Git 忽略文件
├── LICENSE             # 许可证文件
├── README.cn.md        # 中文 README
├── README.md           # 英文 README
└── action.yml          # GitHub Action 配置
```

## 构建流程

### 1. 环境准备

确保系统已安装以下依赖：
- Git
- Docker
- 构建工具链
- 必要的开发库

### 2. 克隆仓库

```bash
git clone https://github.com/ifroncy01/easepi-a2.git
cd easepi-a2
```

### 3. 构建固件

项目使用 GitHub Actions 进行自动化构建，主要工作流包括：

- `build-fnnas-image.yml` - 构建 FNNAS 固件镜像
- `build-fnnas-kernel.yml` - 构建 FNNAS 内核
- `delete-older-releases-workflows.yml` - 清理旧版本发布

也可以在本地手动构建，具体步骤参考 `make-fnnas` 目录中的构建脚本。

### 4. 固件输出

构建完成后，固件镜像会生成在 `fnnas/out/` 目录中，命名格式为：
```
fnnas_rockchip_<设备型号>_k<内核版本>_<日期>_<描述>.img.gz
```

## 使用方法

### 1. 烧录固件

使用 BalenaEtcher 或其他烧录工具将生成的 `.img.gz` 镜像烧录到 SD 卡或 eMMC 中。

### 2. 启动设备

将烧录好的存储设备插入设备，启动设备。首次启动会自动扩展根文件系统。

### 3. 访问系统

设备启动后，可以通过以下方式访问：
- SSH: `ssh root@<设备IP>`（默认密码：1234）
- Web 界面: `http://<设备IP>`

### 4. 挂载外部存储

系统支持自动挂载 USB 存储设备和网络共享。可以在 Web 界面中配置存储选项。

## 设备支持

当前支持的主要设备：
- EasePI-A2 (Rockchip RK3568)
- 其他 Rockchip 平台设备（需相应配置）

## 配置文件

主要配置文件位于 `make-fnnas/fnnas-files/common-files/` 目录：

- `etc/fnnas.conf` - FNNAS 主配置文件
- `etc/fstab` - 文件系统挂载配置
- `etc/rc.local` - 启动脚本
- `etc/systemd/system/resize-rootfs.service` - 根文件系统自动扩展服务

## 常见问题

### 1. 固件烧录失败
- 检查镜像文件是否完整
- 尝试使用不同的烧录工具
- 检查存储设备是否损坏

### 2. 设备无法启动
- 检查引导加载程序是否正确
- 确认设备硬件是否兼容
- 查看串口输出以获取详细错误信息

### 3. 网络连接问题
- 检查网线连接
- 确认网络配置正确
- 查看网络服务状态：`systemctl status networking`

## 贡献指南

1. Fork 本仓库
2. 创建功能分支：`git checkout -b feature/your-feature`
3. 提交更改：`git commit -m 'Add some feature'`
4. 推送到分支：`git push origin feature/your-feature`
5. 打开 Pull Request

## 许可证

本项目采用 MIT 许可证，详情请查看 `LICENSE` 文件。

## 联系方式

- GitHub: [ifroncy01/easepi-a2](https://github.com/ifroncy01/easepi-a2)
- 问题反馈：请在 GitHub 仓库中提交 Issue

---

*文档生成时间：2026-03-20*
# FNNAS 项目文档

## 项目概述

FNNAS (Friendly NAS) 是一个专为 ARM 设备设计的固件构建系统，主要用于生成适用于各种 ARM 开发板的 NAS 固件镜像。该项目基于 Rockchip 平台，提供了完整的固件构建、配置和部署解决方案。

### 主要功能
- 自动构建 ARM 设备的 NAS 固件镜像
- 支持多种 Rockchip 平台设备
- 包含完整的系统配置和服务
- 提供丰富的固件和驱动支持
- 集成 GitHub Actions 自动化构建流程

## 目录结构

```
├── .github/            # GitHub 相关配置
│   ├── ISSUE_TEMPLATE/ # 问题模板
│   └── workflows/      # GitHub Actions 工作流
├── docs/               # 文档目录
├── download/           # 下载目录（包含引导加载程序等）
├── fnnas/              # 主项目目录
│   └── out/            # 生成的固件镜像输出目录
├── fnnas-arm64/        # ARM64 相关文件
├── make-fnnas/         # 构建脚本和配置文件
│   └── fnnas-files/    # 固件文件和配置
├── .gitignore          # Git 忽略文件
├── LICENSE             # 许可证文件
├── README.cn.md        # 中文 README
├── README.md           # 英文 README
└── action.yml          # GitHub Action 配置
```

## 构建流程

### 1. 环境准备

确保系统已安装以下依赖：
- Git
- Docker
- 构建工具链
- 必要的开发库

### 2. 克隆仓库

```bash
git clone https://github.com/ifroncy01/easepi-a2.git
cd easepi-a2
```

### 3. 构建固件

项目使用 GitHub Actions 进行自动化构建，主要工作流包括：

- `build-fnnas-image.yml` - 构建 FNNAS 固件镜像
- `build-fnnas-kernel.yml` - 构建 FNNAS 内核
- `delete-older-releases-workflows.yml` - 清理旧版本发布

也可以在本地手动构建，具体步骤参考 `make-fnnas` 目录中的构建脚本。

### 4. 固件输出

构建完成后，固件镜像会生成在 `fnnas/out/` 目录中，命名格式为：
```
fnnas_rockchip_<设备型号>_k<内核版本>_<日期>_<描述>.img.gz
```

## 使用方法

### 1. 烧录固件

使用 BalenaEtcher 或其他烧录工具将生成的 `.img.gz` 镜像烧录到 SD 卡或 eMMC 中。

### 2. 启动设备

将烧录好的存储设备插入设备，启动设备。首次启动会自动扩展根文件系统。

### 3. 访问系统

设备启动后，可以通过以下方式访问：
- SSH: `ssh root@<设备IP>`（默认密码：1234）
- Web 界面: `http://<设备IP>`

### 4. 挂载外部存储

系统支持自动挂载 USB 存储设备和网络共享。可以在 Web 界面中配置存储选项。

## 设备支持

当前支持的主要设备：
- EasePI-A2 (Rockchip RK3568)
- 其他 Rockchip 平台设备（需相应配置）

## 配置文件

主要配置文件位于 `make-fnnas/fnnas-files/common-files/` 目录：

- `etc/fnnas.conf` - FNNAS 主配置文件
- `etc/fstab` - 文件系统挂载配置
- `etc/rc.local` - 启动脚本
- `etc/systemd/system/resize-rootfs.service` - 根文件系统自动扩展服务

## 常见问题

### 1. 固件烧录失败
- 检查镜像文件是否完整
- 尝试使用不同的烧录工具
- 检查存储设备是否损坏

### 2. 设备无法启动
- 检查引导加载程序是否正确
- 确认设备硬件是否兼容
- 查看串口输出以获取详细错误信息

### 3. 网络连接问题
- 检查网线连接
- 确认网络配置正确
- 查看网络服务状态：`systemctl status networking`

## 贡献指南

1. Fork 本仓库
2. 创建功能分支：`git checkout -b feature/your-feature`
3. 提交更改：`git commit -m 'Add some feature'`
4. 推送到分支：`git push origin feature/your-feature`
5. 打开 Pull Request

## 许可证

本项目采用 MIT 许可证，详情请查看 `LICENSE` 文件。

## 联系方式

- GitHub: [ifroncy01/easepi-a2](https://github.com/ifroncy01/easepi-a2)
- 问题反馈：请在 GitHub 仓库中提交 Issue

---

*文档生成时间：2026-03-20*