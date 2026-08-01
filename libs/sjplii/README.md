# 书剑飘零II (sjplii)

和 097（`sjplgfjxb`，书剑飘零官方教学版）同属飞白工作室的《书剑飘
零》ES II 引擎家族，这份档案用的是 `adm/daemons/securityd.lpc`（没
有 097 那种 `securd`/`securityd` 双档案混淆的问题）。

## 本次修复的 bug

**没有**——这份档案的 WASM 启动、注册流程、`look`/`score`/`quit`
全部一次性顺利通过，`sjplgfjxb` 那三个 bug（`report_error()` 触发
`CHANNEL_D` 编译期递归崩溃、未定义的 `REMOTE_DIR`、损坏的 emote 存
档）在这个快照里都不存在。

管理员账号通过标准方式写入 `/adm/etc/wizlist`——需要注意的是这份档
案下还散落着好几个同名的 `securityd.lpc`/`wizlist`
（`adm/`、`adm/tmp/`、`adm/daemons/bak/`），已经用
`include/globals.h`/`login.h` 里的宏定义确认真正生效的是
`adm/daemons/securityd.lpc` + `adm/etc/wizlist` 这一对。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/sjplii
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40153**。
