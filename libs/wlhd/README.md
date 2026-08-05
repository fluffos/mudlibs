# 武林浩荡 (wlhd)

游戏内品牌为《金庸梦II》/《武林浩荡》。这份档案和 104 `tybxjh`
（天涯之碧血江湖）明显是同源代码——`master.lpc`/`securityd.lpc`/
`logind.lpc` 结构几乎一致，注册提示文字相同，`wiz_levels` 权限阶
梯一样到 `(ceo)` 为止，`globals.h` 里连"决定用哪个 `SECURITY_D`"
的注释掉的备用行都相同。同一个"天涯"代码家族还有 `xhcii`
（笑红尘Ⅱ）、`zxty`（再现天涯）、`ffxymud`（非凡夕阳MUD，登入
横幅完全不提"天涯"二字）、`jhfy2`（江湖风云2）、`xysylmhb`（夕
阳三-炎龙美化版）和 `xyzxiiylzymh`（夕阳再现II-炎龙专用美化客户
端，后两者标题都带"夕阳再现"却和这个家族同源）；`yxjh`（浴血江
湖）的地图和这份档案（`wlhd`）本身逐字节相同，用的正是这份档案独
立改写过的"jump"版跳崖场景，不是 `tybxjh` 的原始版本。这几份档案的
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

WASM 修复阶段没有发现需要修复的程序 bug——在 WASM 下编译、注册、
进入游戏全程干净无错误。唯一做的事情是在 `/adm/etc/wizlist` 里加入
管理员账号（已有 `rock`/`jerry`/`kjh` 三个 `(ceo)` 级创始人账号，
`SECURITY_D` 正确指向 `/adm/daemons/securityd`）。

深度功能测试（§10.7）发现这个结论过于乐观：和逐字节共享地图的手足
档案 `yxjh` 各自独立犯下了同样的 3 个 bug（两处 printf("%O") 调试
残留、§8.9 食物/饮水年龄检查错对象），照搬 `yxjh` 已验证的修法逐一
修复；另外发现一个 `yxjh` 自己没记录的独立新问题：`d/jerry/
saveme.lpc` 的 `exert_function(10)` 类型错误彻底压垮了武庙（巫师起
始房间之一）里的 NPC "江湖医生"；以及两处 `d/death/npc/{b,w}
gargoyle.lpc` 的 §7.68 复活软锁。详见 NOTES.md。

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
