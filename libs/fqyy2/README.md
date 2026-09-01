# 风起云涌2

风起云涌2 地图规模较大，除了华山、武当、少林、丐帮、峨嵋、明教等常见门派场景，还有独立的"杀手楼"势力和结婚玩法，社交与黑道路线并存。属于"海洋/hy"代码线家族（`SECURITY_D` 同样指向 `adm/daemons/securd.lpc`），与 `hy2000`/`hy2002`/`hy3`/`hy5` 等档案共享这套硬编码后门管理员机制，且管理员名单不存在常见的 `wizlist` 文本文件里，而是记录在安全 daemon 自身的存档数据中。

## 内容亮点

- "杀手楼"势力位于 `d/shashou/`，结婚玩法位于 `d/marry/`。
- 管理员名单记录在 `securd.o` 存档文件自身的 `wiz_status` 属性里，
  键名里的 `/` 用真实回车符（CR）编码，编辑时必须用二进制模式读写。

## 注册流程

`new` 触发注册 → 字符集选择（`gb`/`g` 或 `big5`/`b`）→ 英文 id → 确认
创建（y/n）→ 中文名字（1-5 个中文字）→ 密码 → 确认密码 → 天赋数值选
择（0-4，0 为随机）→ 天赋确认（y/n）→ 电子邮件地址 → 性别（m/f）。

## 本次修复的关键 bug

- `adm/daemons/network/dns_master.lpc`：`startup_udp()`/`send_udp()`/
  `send_shutdown()` 无条件调用 `socket_create`/`socket_bind`/
  `socket_close`/`socket_write`，WASM 驱动没有 sockets package，导致
  整个文件编译失败。由于启动流程会间接触碰这个 daemon，编译失败会让
  `input_to("get_id", ob)` 从未被注册，后续所有输入都会被当成游戏内
  指令处理。已将 socket 相关函数体清空为 no-op（同 hy5 的修复模式）。
- `adm/daemons/logind.lpc`：与海洋系列同款的 euid 被中途重置的
  bug——`howmany_user()`/`make_body()` 里的 `seteuid(getuid())` 会把
  `create()` 刚设置好的 euid 重置为空字符串。已将三处全部改为显式
  `seteuid(ROOT_UID)`。
- `howmany_visitor()`/`howmany_card()`：计数文件不存在时崩溃，已加
  `if (!content) return 0;` 防御。
- `check_legal_name()`：沿用旧版 GBK 字节长度界和隔位判断，已改为按
  字符数（1-5）+ 逐字符 `is_chinese()`。
- `adm/daemons/securd.lpc`：`get_status()` 对尚未完成初始化的
  `wiz_status`/`wiz_levels` 重入调用会崩溃，已加防御。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

修正（round-two 深度测试发现旧记录有误）：`wiz_status` 实际声明为
`nosave mapping`（`adm/daemons/securd.lpc` 第 6 行），永远不会被存档
持久化——每次开机都会被 `restore_list()` 里的硬编码赋值重置。原来这
一行只授权了 `titny` 这个 id，而 `titny` 已经是原始存档里一个真实的
玩家（`data/user/t/titny.o`，密码未知，`fluffos` 无法冒领），所以此
前任何"写进 securd.o"的播种尝试实际上从未生效（此仓库里从未真正提
交过 `fluffos` 的存档，直到这次修复）。已在 `titny` 那行旁边并列加
了一行 `set("wiz_status/fluffos", "(admin)");`，`fluffos` 走正常注册
流程创建，`update` 指令验证可正常编译，管理权限真正生效。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/fqyy2/

## 本地运行

```
cd libs/fqyy2
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40197**。
