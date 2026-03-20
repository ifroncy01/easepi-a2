/*
 * (C) Copyright 2018 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __EVB_RK3308_H
#define __EVB_RK3308_H

#include <configs/rk3308_common.h>

#define CONFIG_SYS_MMC_ENV_DEV 0

#define ROCKCHIP_DEVICE_SETTINGS \
			"stdout=serial,vidconsole\0" \
			"stderr=serial,vidconsole\0"
#undef CONFIG_CONSOLE_SCROLL_LINES
#define CONFIG_CONSOLE_SCROLL_LINES            10

#ifndef CONFIG_SPL_BUILD
#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND RKIMG_BOOTCOMMAND
#endif

/*
 * TFTP speed up, by enable ip fragment, and set default blksize to MTU.
 * Use `env set tftpblocksize 16384` to override blksize, max CONFIG_NET_MAXDEFRAG.
 * MUST: CONFIG_TFTP_BLOCKSIZE <= CONFIG_NET_MAXDEFRAG
 */
#define CONFIG_IP_DEFRAG
/* ip fragment, CONFIG_NET_MAXDEFRAG , default 16384, max 65536 */
/* #define CONFIG_NET_MAXDEFRAG		16384 */
#define CONFIG_UDP_CHECKSUM
#define CONFIG_TFTP_BLOCKSIZE		1468

#endif
