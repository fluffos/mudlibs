# 侠客新传98书剑 (xkxc98sj)

「侠客新传」v0.1b，MudOS v22pre11，Xkxz MUD Wizard Group 2000-2001，
由 jjgod 维护。

## 本次修复的关键 bug

1. **`eventd.lpc` 的经典 off-by-one**：和 `wdxtym` 修的是同一个
   bug——`$1[0..<3]` 想去掉 `.lpc` 后缀（4 个字符），却只去掉了 2
   个（`emei.lpc` 变成 `emei.l`），导致 `collect_all_event()` 呼叫
   每一个事件文件全部失败。改成 `[0..<5]`。
2. **§8.1 GBK 字节区间 bug**：`adm/simul_efun/chinese.lpc` 的
   `is_chinese()` 只检查前两个原始字节，在 UTF8 码点索引下永远失
   败；`adm/daemons/logind.lpc` 自己的长度上限也是字节数写法（最小
   2、最大用 8 呼叫，实际应该是最小 1、最大 4，对应注册提示文字
   "名字的长度不能大于四个汉字"）。已把 `is_chinese()` 改成逐码点
   检查，并把 `check_legal_name(arg, 8)` 的呼叫改成 4。
3. **`is_killing()` 参数类型不匹配，波及 18 个文件**：
   `feature/attack.lpc` 声明 `is_killing(string id)`，但代码库里到
   处（各种武功技能、城市 NPC）直接传对象——`is_killing(me)`、
   `is_killing(who)`、`is_killing(ob)`、`is_killing(ob[i])`。这和之
   前在 `sjecl`/`sje` 修的是同一类 bug，只是这份档案里波及范围大得
   多。已把所有活跃调用点都改成传 `->query("id")`（`haotian-
   zhang/ju.lpc` 和 `quanzhen-jianfa/ding.lpc` 里各有一处已经被作者
   自己注释掉的调用，属于死代码，未做改动）。
4. **两处 §7.41 存档损坏 bug**：`adm/daemons/emoted.lpc` 的
   `create()` 对 `restore()` 没有保护，`emote.o` 存档确实已经损坏
   （"Illegal mapping format"）；`adm/daemons/newsd.lpc` 的
   `create()` 也是一样的问题，`dbase` 存档同样损坏。两处都加上
   `catch()`——从驱动的错误堆栈可以确认，现在异常在精灵自己的
   `create()` 里就地被拦截了（堆栈里出现了精灵自己的
   `CATCH()`），不再往外传播，后续也没有观察到任何连锁错误。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（这份档
  案的 `securityd.lpc` 真的会在开机时读取 `WIZLIST`），登录后显示
  "您目前的权限是：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/xkxc98sj
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40126**。
