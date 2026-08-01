# 小雪初晴 (xxcq)

小雪初晴，游戏内品牌为"SnowMud"，以温瑞安小说为背景，CuteRabbit
Studio（JackyBoy）为 CCTX & SDXL 开发。

## 本次修复的关键 bug

**真正会挡住每一次连线的 bug**：这份档案里根本没有 `adm/etc/` 这
个目录（连原始压缩包里都没有）。`logind.lpc` 一连线就会呼叫
`write_file(USERS, ...)`（访问人次计数器，每次连线都会执行，在英
文名字提示之前），但 `write_file()` 能自动创建缺失的**文件**，创
建不了缺失的**目录**，所以这一步每次都会报"Wrong permissions for
opening file /adm/etc/users for overwrite, No such file or
directory"。这个错误没有被任何地方拦截，驱动就静默把连线直接扔进
了裸的指令提示符——注册流程的 `input_to()` 根本没被呼叫过，之后
输入什么都是"什么？"（无法识别指令）。这个 bug 在原生开机下也会一
模一样地发生，不只是 WASM 下的问题。已经创建 `adm/etc/` 目录，附
带初始化的 `users`/`iduser` 计数器文件（都是"0"）。

顺带确认（§7.56 双档案陷阱）：`SECURITY_D` 真正指向的是
`/adm/daemons/securd`，**不是**那份引用（这份代码库里其实没用到
的）`WIZLIST` 文本文件的分身档案 `securityd.lpc`。`securd.lpc` 通
过 `restore_list()` 里硬编码的 `set("wiz_status/jackyboy",
"(admin)")` 来引导管理员账号（和这一轮之前修的 `sj` 是同一个模
式），已经在旁边加上 `set("wiz_status/fluffos", "(admin)")`。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设（临时密码 + 确认）
- **权限 / Level**: `(admin)`，注册完成时连线横幅已经直接显示"目
  前权限：(admin)"，人物称号也是最高级的"【天神】"。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/xxcq
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40135**。
