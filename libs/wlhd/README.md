# 武林浩荡 (wlhd)

游戏内品牌为《金庸梦II》/《武林浩荡》。这份档案和 104 `tybxjh`
（天涯之碧血江湖）明显是同源代码——`master.lpc`/`securityd.lpc`/
`logind.lpc` 结构几乎一致，注册提示文字相同，`wiz_levels` 权限阶
梯一样到 `(ceo)` 为止，`globals.h` 里连"决定用哪个 `SECURITY_D`"
的注释掉的备用行都相同。同一个"天涯"代码家族还有 `xhcii`
（笑红尘Ⅱ）、`zxty`（再现天涯）、`ffxymud`（非凡夕阳MUD，登入
横幅完全不提"天涯"二字）和 `jhfy2`（江湖风云2），这几份档案的
"世界之巅"跳崖场景
（`d/city/sj.lpc`）逐字节相同；这份档案（`wlhd`）自己把同一个房
间的玩法独立改写过（指令改成 `jump`，加了 `valid_leave()`），但
核心系统档案的同源关系不受影响。

## 内容亮点

- 和 104 `tybxjh` 共享同一套金庸门派/地图世界观（华山、武当、峨嵋、
  丐帮、明教、逍遥、天龙寺等一应俱全，城池覆盖长安、荆州、大理、
  西夏等地），但游戏内品牌不同，打的是《金庸梦II》/《武林浩荡》
  的旗号。
- 权限阶梯比常见的 `(admin)` 更进一步，顶层是 `(ceo)`，档案里已经
  预置了三个 `(ceo)` 级创始人账号（`rock`/`jerry`/`kjh`），对应
  `d/rock`/`d/jerry` 等专属场景目录。
- 同样有 `job`/`working`（打工赚钱）与结构化的悬赏/团队任务目录，
  和 `tybxjh` 的经济玩法一脉相承。

## 本次处理内容

没有发现需要修复的程序 bug——在 WASM 下编译、注册、进入游戏全程
干净无错误。唯一做的事情是在 `/adm/etc/wizlist` 里加入管理员账号
（已有 `rock`/`jerry`/`kjh` 三个 `(ceo)` 级创始人账号，
`SECURITY_D` 正确指向 `/adm/daemons/securityd`）。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **管理密码 / Admin password**: 注册时自设（至少 5 位，且不能与
  普通密码相同）
- **普通密码 / Regular password**: 注册时自设（双密码机制）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  横幅直接显示"您目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/wlhd
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40121**。
