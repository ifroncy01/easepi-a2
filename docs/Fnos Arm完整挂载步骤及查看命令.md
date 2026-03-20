# Fnos Arm 1.1.19 完整挂载步骤及查看命令

# 完整、无坑、可直接复制的挂载步骤（含所有查看命令）

我给你整理**最标准、最稳妥**的流程，你照着一步执行即可，所有命令都给你标注清楚。

---

## 一、先进入镜像目录

```Bash

cd ~/windts/fnnas/download
```

## 二、创建挂载目录（你已经建了，执行也没事）

```Bash

sudo mkdir -p /mnt/fnos_boot /mnt/fnos_root
```

## 三、挂载镜像到 loop 设备（自动分配 + 扫描分区）

```Bash

sudo losetup -f -P fnos_Mainland-PE_arm_1.1.19_dg-tn3568.img
```

---

# 🔥 重点：各种查看命令（你必须会用）

## 1. 查看 loop 设备（只能看到 loop27，看不到 p1/p2 → 正常）

```Bash

losetup -a
```

输出示例：

```Plain Text

/dev/loop27: [xxxx]:xxxx (fnos_Mainland-PE_arm_1.1.19_dg-tn3568.img)
```

## 2. 查看分区（真正能看到 p1、p2）

```Bash

lsblk /dev/loop27
```

你会看到：

```Plain Text

loop27    7:0    0  xxxxx  0 loop
├─loop27p1 7:1    0  xxxx  0 loop  → boot
└─loop27p2 7:2    0  xxxx  0 loop  → root
```

## 3. 查看分区详细信息（可选）

```Bash

fdisk -l /dev/loop27
```

---

## 四、强制刷新分区表（解决看不到 p1/p2 的问题）

```Bash

sudo partprobe /dev/loop27
```

---

## 五、正式挂载 boot 和 root

```Bash

sudo mount /dev/loop27p1 /mnt/fnos_boot
sudo mount /dev/loop27p2 /mnt/fnos_root
```

---

## 六、验证是否挂载成功

```Bash

df -h | grep fnos
```

看到下面内容就是成功：

```Plain Text

/dev/loop27p1   xxxM  xxxM  xxxM  xx% /mnt/fnos_boot
/dev/loop27p2   xxxG  xxxM  xxxG  xx% /mnt/fnos_root
```

---

## 七、查看挂载后的文件

```Bash

ls /mnt/fnos_boot
ls /mnt/fnos_root
```

---

# 用完卸载（完整卸载命令）

```Bash

sudo umount /mnt/fnos_boot
sudo umount /mnt/fnos_root
sudo losetup -d /dev/loop27
```

---

# 一句话总结

- **losetup -a** = 看磁盘（loop27）

- **lsblk /dev/loop27** = 看分区（p1、p2）

- **mount** 用 `/dev/loop27p1` 和 `p2`

你现在直接按上面步骤复制执行，100%成功。
> （注：文档部分内容可能由 AI 生成）