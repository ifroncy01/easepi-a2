# EasePi A2 项目

## 项目简介

EasePi A2 是一款基于 Rockchip RK3568B2 芯片的高性能 NAS/软路由设备，具有双 M.2 NVMe 接口、2.5G 网口、WiFi 5 + BT 4.2 等丰富功能，适合家庭和小型办公场景使用。

## 项目结构

- **主分支 (main)**：各类资料收集、编译说明文档、硬件规格等
- **fnnas 分支**：FN NAS 系统编译项目
- **armbian 分支**：(计划中) Armbian 系统编译项目

## 硬件规格

### 核心性能模块
- **处理器**：RockChip RK3568 B2 四核芯片，ARM Cortex-A55 架构，主频最高 2.0GHz
- **GPU**：ARM G52，支持图形加速
- **NPU**：1TOPS 算力，支持轻量级 AI 计算
- **内存**：4GB 美光 LPDDR4（型号 MT53D1024M32D4DT-053WT:D），速率 1866Mbps
- **存储**：32GB 闪迪 eMMC5.1（型号 SDINADF4-32G）
- **扩展存储**：2 条全尺寸 M.2 NVMe 接口（PCIe3.0 协议）

### 通信与接口配置
- **有线网络**：1 个 2.5G 速率网口，采用瑞昱 RTL8125B 芯片
- **无线网络**：正基 AP6255 模块，支持 802.11ac 无线协议与蓝牙 4.2
- **扩展接口**：
  - 1 个 USB-A 3.0 接口（5Gbps 速率）
  - 1 个 Type-C OTG 接口
  - 1 个 HDMI 2.0 接口
  - 板载 Debug TTL 调试接口

### 辅助硬件与电源管理
- **辅助组件**：
  - 128×64 单色 OLED 显示屏（SSD1306，I2C 接口）
  - 红外接收器（NEC 协议，PWM3 通道）
  - 实体按键（开关机键与 Mask ROM 键）
  - 双绿色 POW/RUN LED 指示灯
- **电源管理**：瑞芯微 RK809-5 PMIC 电源管理芯片
- **尺寸**：135×115×28mm 钣金折弯金属外壳

## PCIe 通道分配

- **PCIe2x1**：用于 2.5G 以太网控制器（RTL8125B）
- **PCIe3x1**：用于 M.2 NVMe 1
- **PCIe3x2**：用于 M.2 NVMe 2

## 编译指南

### 准备工作

1. **安装依赖**：
   ```bash
   sudo apt-get update
   sudo apt-get install build-essential git u-boot-tools libncurses5-dev libssl-dev flex bison bc device-tree-compiler
   ```

2. **克隆仓库**：
   ```bash
   git clone https://github.com/ifroncy01/easepi-a2.git
   cd easepi-a2
   ```

### 编译 FN NAS 系统

1. **切换到 fnnas 分支**：
   ```bash
   git checkout fnnas
   ```

2. **编译步骤**：
   ```bash
   # 配置编译环境
   ./build.sh config
   
   # 开始编译
   ./build.sh
   ```

3. **编译产物**：
   - 编译完成后，镜像文件将生成在 `output/` 目录

### 编译 Armbian 系统（计划中）

1. **切换到 armbian 分支**：
   ```bash
   git checkout armbian
   ```

2. **编译步骤**：
   ```bash
   # 配置编译环境
   ./compile.sh
   
   # 开始编译
   ./compile.sh easepi-a2
   ```

## 资料收集

- **硬件文档**：
  - [EasePi A2 完整硬件分析报告](docs/EasePi A2 完整硬件分析报告.md)
  - [RK3568B2 官方手册](docs/RK3568B2_manual.pdf)

- **设备树**：
  - [RK3568 EasePi A2 设备树](dts/linux-6.12.y/rk3568-easepi-a2.dts)

- **固件**：
  - 官方固件和第三方固件下载链接

## 刷写指南

1. **进入 MaskROM 模式**：
   - 短接 Mask ROM 键，然后上电
   - 或使用 Rockchip 工具进入刷机模式

2. **使用 Rockchip 刷机工具**：
   - 下载并安装 [RKDevTool](https://www.rockchip.com.cn/download.php?cat=69)
   - 加载编译好的固件
   - 点击 "下载固件" 开始刷写

3. **使用 TF 卡刷写**：
   - 将固件写入 TF 卡
   - 插入 TF 卡，上电自动刷写

## 调试指南

### TTL 调试
- **引脚定义**：板载 TTL 调试接口
- **波特率**：1500000
- **连接工具**：使用串口工具（如 Putty、SecureCRT 等）连接

### 常见问题排查

| 问题 | 可能原因 | 解决方案 |
|------|---------|----------|
| 无法启动 | 固件损坏 | 重新刷写固件 |
| 网络不通 | 驱动问题 | 检查网络驱动配置 |
| NVMe 不识别 | 电源问题 | 检查 NVMe 供电 |
| OLED 不显示 | I2C 驱动 | 检查 I2C 配置 |

## 贡献指南

1. **提交 Issue**：报告问题或提出新功能建议
2. **提交 Pull Request**：
   -  Fork 仓库
   -  创建分支
   -  提交更改
   -  发起 Pull Request

3. **代码规范**：
   - 遵循项目现有的代码风格
   - 提交前进行测试

## 许可证

本项目采用 MIT 许可证，详见 [LICENSE](LICENSE) 文件。

## 免责声明

- 本项目仅供学习和研究使用
- 刷写固件有风险，请谨慎操作
- 因使用本项目产生的任何问题，作者不承担责任

---

**更新日期**：2026-03-20
**项目主页**：https://github.com/ifroncy01/easepi-a2.git
