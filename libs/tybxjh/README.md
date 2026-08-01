# 天涯之碧血江湖 (tybxjh)

天涯泥潭（Tianya MUD Wizard Group）的"碧血江湖"档案，自 2002 年建
站运行至今的老牌武侠 MUD。这份档案在 WASM 下**完全无需修复**——
没有编译错误，没有执行时段错误，整个登录/注册流程一次跑通。

## 本次处理内容

没有发现需要修复的程序 bug。唯一做的事情是在 `/adm/etc/wizlist`
里加入管理员账号（`SECURITY_D` 正确指向 `/adm/daemons/securityd`，
`u/zjb/securityd.lpc` 是没有被实际引用的分身档案）。

顺带一提，`securityd.lpc` 的 `get_status()` 对四个特定账号
（`daniel`/`zjb`/`kjh`/`jiji`）写死返回最高的 `(boss)` 权限，不受
wizlist 内容影响——这是站方创始人账号的既有设计，不是 bug，也不
影响 `fluffos` 账号的权限。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **管理密码 / Admin password**: 注册时自设（至少 5 位，且不能与
  普通密码相同）
- **普通密码 / Regular password**: 注册时自设（双密码机制）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  横幅直接显示"您目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 测试注意事项

这份档案有一个真实存在、非测试artifact的 **150 秒注册超时**
（`clone/user/login.lpc` 的 `time_out()`，`LOGIN_TIMEOUT` 定义在
`include/login.h`，从连线那一刻就开始计时，不是每个提示符重置）。
`get_email()`/`get_gender()` 阶段会触发 `/inherit/char/char` 极其
庞大的一次性编译警告洪流，如果测试脚本用较长的 `--idle`（比如
6-15 秒）等待这些警告刷完，反而会撞上这个 150 秒的整体超时被系统
踢下线（显示"您花在连线进入手续的时间太久了"）。用较短的
`--idle 2` 反而能够顺利在超时窗口内完成整个注册流程。

## 本地运行

```
cd libs/tybxjh
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40158**。
