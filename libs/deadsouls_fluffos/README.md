# DeadSouls-FluffOS2019

`fluffos` GitHub 组织自己维护的 Dead Souls 3.8.6 fork （<https://github.com/fluffos/dead-souls>），已经预先适配现代 FluffOS （`v2019` 驱动分支）——不是从老式压缩包提取的传统档案，是这批语料库里少数几个"英文原版、本身就来自 FluffOS 生态"的收录对象之一。

## 和 `ds386` 的关系

本项目还收录了另一份 Dead Souls——`libs/ds386`，来自一份完全独立的、
老式压缩包归档，代表的是未经 FluffOS 生态改造的原始 Dead Souls 3.8.6
快照。两者按本项目"同一游戏不同来源快照各自保留独立 slug"的一贯做法
分别收录（参见 `bxsj`/`bxsj1`、`xiyouji` 系列等先例），并未合并或去
重。这一份的显著特征：仓库自带 `driver/` git submodule 跟踪
`fluffos/fluffos` 的 `v2019` 分支、已经内置 AUTO_WIZ（注册时可直接
选择成为创造者）、websocket 监听支持、以及一套 `www/` 网页客户端——
是"已经被 FluffOS 生态本身认领和现代化"的一支。

## 内容说明

- 经典 Dead Souls 教学向内容：出生在校园（Praxis）附近的新手小屋
  （The start room），`enter town`进入主城区，可选种族
  `dwarf`/`elf`/`half-elf`/`half-orc`/`halfling`/`human`/`orc`/
  `poleepkwa`。
- 完整的种族/职业/技能/法术/公会体系，`domains/` 下有 `town`、
  `campus`、`Praxis`、`amigara`、`learning`、`Ylsrim`、`cave`、
  `examples` 等多个示范区域，是 Dead Souls 官方长期用作"如何写一个
  区域"的教学素材。
- 注册流程支持 AUTO_WIZ：种族选定后会直接询问"作为玩家还是创造者
  加入"，无需额外后台操作即可获得建造权限。
- 新角色手册：`read chapter 1 in handbook` 是官方推荐的新手上手方式。

## WASM / 驱动兼容说明

上游仓库使用的是"现代"编辑器 efun 组合
（`ed_start()`/`ed_cmd()`/`query_ed_mode()`），而本项目共享的驱动
构建是以 `OLD_ED`（服务语料库里占多数的老 MudOS 时代 mudlib）编译
的，这三个 efun 在这个驱动构建里并不存在——直接导致玩家类
（`/lib/player.lpc`）完全无法编译。已经用纯 LPC 从零实现了一套自包含
的兼容 shim（`secure/sefun/ed_compat.lpc`，覆盖经典 `ed(1)` 命令子
集），详见 `NOTES.md` 的完整说明。另外还发现并修复了一处影响面很广
的真实 bug：`.c`→`.lpc` 改名后残留的定宽切片错误，最严重的一处让
**全局命令派发表**（`daemon/command.lpc`）把每一条命令都注册错了
文件名（多出一个 `.l` 尾巴），导致 `score` 等所有走标准命令派发路径
的指令全部报错——已经系统性排查并修复了同一根因的全部 ~30 处实例，
详见 `NOTES.md`。

## 在线试玩

本地测试端口如下。

## 管理员 / creator 账号

这份 lib 没有预先播种的固定管理员账号——Dead Souls 的惯例是通过两条
路径任选其一获得建造权限：

1. **AUTO_WIZ（推荐）**：注册新角色时，选定种族后会被问到
   "作为玩家还是创造者加入"，直接输入 `creator` 即可在登录后不久自动
   被提升为创造者。
2. **`groups.cfg`**：`secure/cfg/groups.cfg` 里已经把账号名
   `sunyc` 写入了 `SECURE`/`ASSIST`/`ELDER`/`TEST`/`INTERMUD`/
   `TELNET`/`EMOTES` 等全部权限组——把这个名字改成你要用的账号名
   （小写），或者新增一行，即可让该账号获得对应权限，无需走 AUTO_WIZ
   流程。

> 若要正式对外开放主机，请根据实际需要调整 `groups.cfg` 的账号名单。

## 本地运行

```
cd libs/deadsouls_fluffos
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40207**。
