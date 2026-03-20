# Directory Description

View Chinese description | [查看中文说明](README.cn.md)

Some files required for compiling FnNAS are stored in the relevant directories.

## fnnas-files

The files stored here are relevant files required when packaging FnNAS. Among them, the `common-files` directory contains general files, the `platform-files` directory contains files for various platforms, and the `different-files` directory contains files specific to different devices.

- Required system files will be automatically downloaded from the [ophub/amlogic-s9xxx-armbian](https://github.com/ophub/amlogic-s9xxx-armbian/tree/main/build-armbian/armbian-files) repository to the `platform-files` and `different-files` directories.

- Required firmware will be automatically downloaded from the [ophub/firmware](https://github.com/ophub/firmware) repository to the `common-files/usr/lib/firmware` directory.

## kernel

Create directories to store kernel files under the `kernel` directory, such as `6.12.41/6.12.41-amlogic`. If you have multiple kernels, create directories sequentially and place the corresponding kernel files in them. Kernel files can be downloaded from the [kernel_fnnas](https://github.com/ophub/fnnas/releases/tag/kernel_fnnas) repository, or you can refer to the kernel compilation instructions on the homepage to compile them yourself. If kernel files are not downloaded and stored manually, the script will automatically download them from the kernel repository during compilation.

## u-boot

System boot loader files. Depending on the kernel version, these will be handled automatically by installation/update scripts when needed. The required u-boot files will be automatically downloaded from the [ophub/u-boot](https://github.com/ophub/u-boot) repository to the `u-boot` directory.

## scripts

Dependency packages required for the current server environment will be automatically installed when executing `renas` and `remake`. Other script files are used to assist in compiling or creating the FnNAS system.
