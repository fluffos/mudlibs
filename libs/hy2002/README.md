# 海洋2002 (hy2002)

游戏内标题为"海洋II"（Ocean II），是 [hy2000](../hy2000/) 的后续/演
进版本——两者 10630/10632 个文件按路径完全重合，hy2002 在此基础上
新增了约 3000 个文件（新地图、新门派内容等）。

## 注册流程

连线后选择编码 GB/Big5（本次验证两种选项都能正常显示中文，未发现
编码问题）→ 英文 id（3-12 个小写英文字母）→ 确认建立新角色（y/n）
→ 中文名字（2-5 个汉字，直接输入完整姓名）→ 确认名字（y/n，也可
留空让系统随机产生）→ 密码（至少 6 位，必须同时包含大写字母、小写
字母和数字）→ 确认密码 → 天赋数值（输入 0 交由系统随机产生，随后
需再输入 y 确认这组数值）→ 电子邮件地址 → 性别（m/f）→ 进入游戏
世界。

注意：本站有一个真实的反滥用限制——同一 IP 60 秒内只能注册一次新
角色，这是有意的游戏设计，不是 bug。

## 本次修复的关键 bug

以下前三项 bug 和 [hy2000](../hy2000/) 完全相同（同一代码血统），
本次直接照搬已知修法后再逐一用真实连线验证：

- `include/globals.h` 的 `MASTER_OB`/`SIMUL_EFUN_OB` 宏指向了
  `/adm/single/` 下的死代码副本，而不是 `config.fluffos` 实际加载
  的 `/adm/obj/master`、`/adm/obj/simul_efun`（AGENTS.md §7.56）。
- `adm/daemons/logind.lpc` 的 `howmany_visitor()`/`howmany_card()`
  以及 `cmds/usr/uptime.lpc` 的"上次当机原因"显示：经典的
  `sscanf`/`write(read_file(缺失文件), ...)` 在全新档案下崩溃
  （AGENTS.md §7.54）。
- `adm/daemons/logind.lpc` 的 `check_legal_name()`：经典的 GBK 字
  节区间长度假设 bug（AGENTS.md §8.1）——长度界限按字节数写成
  `strlen(name)<4||>10`（应为按字符数 `<2||>5`）、`i%2==0` 的双字
  节对齐门槛、以及 `name[i..<0]` 尾部切片判断全部失效。

本次新发现的 bug：

- `adm/daemons/network/dns_master.lpc`：纯 socket 功能的互连（跨服
  intermud）守护进程在 WASM 下无法编译，按"禁用整个文件的入口点"方
  式清空为 no-op（AGENTS.md §7.52）：`startup_udp()`/`send_udp()`
  以及 `send_shutdown()` 里的 `socket_close()` 那一行。**这个 bug
  的影响特别隐蔽**：`adm/daemons/logind.lpc` 的 `gb_big5()`（选择
  编码之后的下一步）中途调用了
  `DNS_MASTER->query_muds()`/`query_svc()`，一旦这个守护进程无法编
  译，`gb_big5()` 剩下的代码（包括最后显示英文名字提示、调用
  `input_to("get_id",...)` 的那几行）全部不会执行——**玩家会永远
  卡在选择编码之后，连英文名字的提示都看不到，而且没有任何可见的
  报错信息**，是本次最难定位的一个 bug。

## 管理员账号 / Admin account

这份档案的管理员认证机制和 [hy2000](../hy2000/) 类似（`securd.lpc`
的 `restore_list()` 硬编码了一个后门 id），但硬编码的 id 是
`hxsd`——而这个 id **已经是档案里一个真实存在的旧玩家账号**（密码
未知，无法通过正常注册流程认领）。因此在 `hxsd` 那一行旁边追加了
一行 `set("wiz_status/fluffos","(admin)")`，让标准的 `fluffos` 账
号也能获得管理员权限（新增 AGENTS.md §1.5 bug 类型，因为这和
hy2000 的 `wuyou`——那个 id 是真正未被占用的——情况不同）。

- **id**: `fluffos`
- **密码 / password**: `Mud@2026Pass1`
- **权限 / level**: `(admin)`

管理员账号通过正常注册流程创建，已在游戏内确认 "目前权限：(admin)"
显示正确。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/hy2002
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40116**。
