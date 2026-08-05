# 侠客行2017 (xkx2017)

侠客行（"The Story of Hero"），MudOS v21 世系——和 110 `xkx100`、
111 `xkx2000zxb` 是同一核心代码库家族（`combatd.lpc`/`quest.h` 的
结构一眼就能看出来）。

## 内容亮点

- 和 `xkx100`/`xkx2000zxb` 同一核心代码库家族，但地图明显更精简
  （华山、武当、少林、丐帮、峨嵋、明教等门派齐全，缺少
  `xkx100`那种漠北/哈萨克/台湾式的边疆场景），更像是一个精简复刻
  版本。
- 客店留言板曾因存档文件损坏牵连整个房间初始化失败（`look`
  就崩溃），本次修复后不仅救回了这一间客店，也顺带保护了 mudlib
  里所有共享同一个 `bboard.lpc` 继承的留言板（详见下方 bug 修复第
  2 条）。
- 和同家族的 `xkx2000zxb` 不同，这份档案的管理员权限走的是标准的
  `wizlist` 文本文件机制，没有站点 IP 锁定检查，架设起来更省心。
- 深度测试发现这份档案和"金庸群侠传"系列（`jqxz2008`/`jqxz2008dlx`/
  `jqxz2008std`）共享同一套底层 bug（损坏存档崩溃、缺失
  `/log/nosave/` 导致的死亡死循环、括号位置错误、食物/饮水初始化检
  查错对象），全部一并修复；另外还修复了 3 处独立的死亡/复活软锁。
  实际打死过一次角色验证了完整的战斗→死亡→鬼门关流程，详见 NOTES.md。

## 本次修复的关键 bug

1. **和 `xkx2000zxb` 一模一样的 `#include` 路径错误**：
   `adm/daemons/combatd.lpc` 用 `#include </quest/quest.h>`（绝对
   路径写法），这个驱动的 `<...>` 语法认不得。改成
   `#include <quest.h>`，并挪到 `inherit F_DBASE;` 之后（避免"全局
   变量声明在 inherit 之前"的编译错误）——这两份档案是独立压缩包，
   所以分别修复。
2. **一个真实存在的连锁 bug**：`inherit/misc/bboard.lpc` 的
   `setup()` 对 `restore()` 没有做任何保护。`clone/board/kedian_b`
   （客店留言板）的存档文件本身已经损坏（"Illegal file format"），
   由于 `restore()` 是 `setup()` 里最后一行，这个异常一路往上抛，
   打断了调用者（`kedian_b.lpc` 的 `create()`）后面还没执行的
   `set()`/`replace_program()` 语句，导致这个留言板对象的名字/简称
   状态处于半初始化的坏状态——后续任何人在这个房间 `look` 都会崩
   溃，报"Bad argument 1 to capitalize()，Got: 0"（`feature/
   name.lpc` 的 `short()` 试图 capitalize 一个从未被正确设置的名
   字）。已经给 `bboard.lpc` 的 `restore()` 加上 `catch()`——这是个
   共享的 `inherit`，所以这一个修复能保护 mudlib 里所有的留言板分
   身，不只是 kedian_b 这一个。那个特定留言板的旧留言内容已经无法
   挽回，但房间本身现在能正常初始化了。

这份档案没有 `is_chinese()`/`check_legal_name()` bug——"小浮侠"（三
个字）第一次尝试就通过了，不用修。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（这份
  档案的 `securityd.lpc` 真的会在开机时读取 `WIZLIST`，不像
  `xkx2000zxb` 那样用存档文件；也没有类似 `xkx2000zxb` 的站点锁定
  检查），`wizlist` 命令确认显示"目前权限：(admin)"。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/xkx2017
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40145**。
