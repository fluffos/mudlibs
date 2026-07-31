# 海洋5

"海洋"系列的另一支代码线（与 146/hy 同源但代码内容已大幅分叉，行数差异
很大，不能假设两者的具体修复位置/行号一致）。世界观为武侠向，社区自称
"海洋V"。

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

与 146/hy 相同，本代码线的权限系统也不通过 `/adm/etc/wizlist`，而是
存储在 `adm/daemons/securd.o` 存档文件自身的 `wiz_status` 属性里。编辑
该 `.o` 文件务必使用二进制模式读写（同 146/hy 的踩坑记录）。

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
