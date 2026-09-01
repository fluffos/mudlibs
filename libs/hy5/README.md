# 海洋5

"海洋"系列的另一支世界，社区自称"海洋V"，世界观为武侠向。经核心档
案比对确认，`hy5` 实际上与本项目里的 `haiyang2`（海洋II／星月传奇）
血缘更近：`adm/obj/master.lpc` 逐字节完全相同，抽样域文件也约有
90% 字节相同，本质上是同一个基础世界，而不只是"海洋"家族的又一条
独立分支。`hy5` 独立重写了安全精灵（`securd.lpc`），并在 `haiyang2`
约 141 个地图分区的基础上再扩展约 50 个新区域——安南（越南）、高丽
（朝鲜）、日本（神户/京都）、西藏、新疆、楼兰、台湾等，使总地图规
模成为本项目最大之一，这个扩展部分才是本档案真正独有的内容。

## 内容亮点

- 地图规模是本项目里数一数二的：除了长安、洛阳、大理、湘阳等中原
  城池，还延伸到安南（越南）、高丽（朝鲜）、日本（神户/京都）、
  西藏、新疆、西域、楼兰、流沙、台湾等几乎覆盖整个东亚/中亚的地
  理场景，比 `xkx100`/`hy3` 等档案的跨境地图还要更广。
- 和 `d/marry/` 结婚系统一起出现，说明这份"海洋V"社区版本也延续了
  同系"海洋"家族的社交玩法。
- 字符集选择提示看起来像是/否问句，实际上只接受 `gb`/`g` 或
  `big5`/`b`，回答 y/n 会被当成非法输入反复重问——这是这份档案自己
  的措辞问题，不能照搬其它"海洋"分支档案的提示语义假设。
- 死亡系统叠了异常多层的"新手不死"保护（战斗经验 <300万、平安城内
  未成年、擂台/比武区等安全区域、以及一层与经验值完全无关的"濒死自
  动满血复活一次"机制），普通新手角色几乎不可能触发真正的鬼门关流
  程——本项目 §10.7 深度测试用管理员权限临时提升测试角色的战斗经验
  才验证到完整的死亡/白无常对话/复活序列，详见 NOTES.md。

## 注册流程

`new` 触发注册 → 字符集选择（**注意**：本代码线的提示虽然长得像 y/n
问句，实际接受的是 `gb`/`g` 或 `big5`/`b`，回答 y/n 只会被当成非法输入
反复重问）→ 英文 id → 确认创建（y/n）→ 中文名字 → 密码 → 确认密码 →
天赋数值选择（0-4，0 为随机）→ 天赋数值确认（y/n）→ 电子邮件地址 →
性别（m/f）。

## 本次修复的关键 bug

- `adm/daemons/network/dns_master.lpc`：`startup_udp()`/`send_udp()`/
  `send_shutdown()` 无条件调用 `socket_create`/`socket_bind`/
  `socket_close`，WASM 驱动没有 sockets package，导致整个文件编译失败。
  由于注册流程里 `gb_big5()` 会间接触碰到这个 daemon，编译失败会让
  `input_to("get_id", ob)` 从未被注册，后续所有输入都会被当成游戏内指令
  处理（"什么？"）。已将 socket 相关函数体清空为 no-op（同
  `mudlistd.lpc` 的修复模式）。
- `adm/daemons/logind.lpc`：与 146/hy 同样的 euid 被中途重置的 bug——
  `howmany_user()`/`make_body()` 里的 `seteuid(getuid())` 会把 `create()`
  刚设置好的 `seteuid(ROOT_UID)` 重置为空字符串（该 daemon 的真实 uid
  从未被正确解析）。已将三处全部改为显式 `seteuid(ROOT_UID)`。
- `howmany_visitor()`/`howmany_card()`：计数文件不存在时崩溃，已加
  `if (!content) return 0;` 防御（同 146/hy）。
- `check_legal_name()`：沿用旧版 GBK 双字节假设的长度界（4-10 字节）和
  `i%2==0` 隔位检查，已改为按字符数（2-5）判断，并对每个字符调用
  `is_chinese()`。
- `adm/daemons/securd.lpc`：`get_status()` 里 `member_array(euid,
  wiz_levels)` 在该对象自身尚未完成变量初始化时被重入调用会崩溃，已加
  `arrayp(wiz_levels)` 防御（同 146/hy）。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

与 146/hy 相同，本代码线的权限系统也不通过 `/adm/etc/wizlist`。

修正（round-two 深度测试发现，上面这段此前的记录不完整）：
`wiz_status` 实际声明为 `nosave mapping`——永远不会被存档持久化，
"存储在 securd.o 里"这个说法本身是错的，每次开机都会被
`restore_list()` 里的硬编码赋值重置成只有一个 `hxsd`（"预先留个门"
的原始后门 id，已经是原始存档里一个真实玩家）。此前虽然已经有一个
`fluffos` 角色存档被提交过，但因为没有并列的 `wiz_status/fluffos`
授权行（不像姊妹档案 `hy2002` 的 README 明确记录了这一步），那个账
号登录后实际上从未真正拿到过 `(admin)` 权限。已在 `hxsd` 那行旁边
并列加一行 `set("wiz_status/fluffos", "(admin)");`（AGENTS.md §1.5
标准修法），用真实登录 + `update` 指令验证权限真正生效。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/hy5/

## 本地运行

```
cd libs/hy5
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40183**。
