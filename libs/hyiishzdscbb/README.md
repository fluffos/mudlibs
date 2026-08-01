# 海洋II上海站第三次版本 (hyiishzdscbb)

游戏内标题为"海洋II"（Ocean II），是 [hy2000](../hy2000/)/
[hy2002](../hy2002/) 的另一个兄弟版本（约 9600/10253 个文件按路径
与两者分别重合）——同一套 ES2/金庸题材代码血统的上海站第三次版本
快照。

## 注册流程

连线后选择编码 GB/BIG5（本次验证两种选项都能正常显示中文，只有一
处 `gb_b5d.lpc` 转换表内的无害编译警告，不影响功能）→ 英文 id
（3-12 个小写英文字母）→ 确认建立新角色（y/n）→ 中文名字（直接输
入完整姓名，无需拆分姓氏/名字）→ 密码（设定 + 确认两次）→ 天赋数
值（输入 0 交由系统随机产生，随后需再输入 y 确认这组数值）→ 电子
邮件地址 → 性别（m/f）→ 进入游戏世界。

## 本次修复的关键 bug

和 [hy2000](../hy2000/)/[hy2002](../hy2002/) 完全相同的代码血统，
本次直接照搬已知修法后再逐一用真实连线验证：

- `include/globals.h` 的 `MASTER_OB`/`SIMUL_EFUN_OB` 宏指向了
  `/adm/single/` 下的死代码副本（AGENTS.md §7.56）。
- `adm/daemons/logind.lpc` 的 `howmany_visitor()`/`howmany_card()`
  以及 `cmds/usr/uptime.lpc` 的"上次当机原因"显示：经典的
  `sscanf`/`write(read_file(缺失文件), ...)` 在全新档案下崩溃
  （AGENTS.md §7.54）。
- `adm/daemons/network/dns_master.lpc`：纯 socket 功能的互连守护
  进程在 WASM 下无法编译，按"禁用整个文件的入口点"方式清空为
  no-op（AGENTS.md §7.52）：`startup_udp()`/`send_udp()` 以及
  `send_shutdown()` 里的 `socket_close()` 那一行。
- `adm/daemons/logind.lpc` 的 `check_legal_name()`：经典的 GBK 字
  节区间长度假设 bug（AGENTS.md §8.1）。
- `cmds/usr/quit.lpc` 的 `new("/clone/topten/magic-rice")`：缺少
  和其余调用处（`top10.lpc`、`topboard.lpc`、`topten.lpc`、
  `topdel.lpc`）一样的 `if(ob=new(...))` 防御性判断（AGENTS.md
  §7.63），已比照补上。

## 管理员账号 / Admin account

这份档案的管理员认证机制和 [hy2002](../hy2002/) 类似：
`adm/daemons/securd.lpc` 的 `restore_list()` 硬编码了一个后门 id
`titny`——但这个 id **已经是档案里一个真实存在的旧玩家账号**（密
码未知，无法通过正常注册流程认领）。因此在 `titny` 那一行旁边追加
了一行 `set("wiz_status/fluffos","(admin)")`，让标准的 `fluffos`
账号也能获得管理员权限。

- **id**: `fluffos`
- **密码 / password**: `loginpass1`
- **权限 / level**: `(admin)`

管理员账号通过正常注册流程创建，已在游戏内确认 "目前权限：(admin)"
显示正确。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/hyiishzdscbb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40147**。
