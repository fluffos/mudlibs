# 泥潭1

NT/nitan（"泥潭"/Lonely）系代码线的独立分支，和 nitan170911/nitan6/ hhsj 都没有精确的 master-hash 匹配。新角色要先进入"注册房间"，用房间内置的 `register <email>` 指令完成邮箱登记才能正式进入游戏世界分配天赋属性——和"地狱"/Doing 家族的"投胎"机制类似，都比常见的 "选完性别直接进游戏"多一道关卡；角色创建除性别外，还要在独立的性格类型（1-4）和角色类型（1-5）之间各做一次选择。

## 内容亮点

- 原始压缩包里带有 20 个非法 UTF-8 编码的文件/目录名，会让基于
  Node.js 的目录扫描直接崩溃（`ENOENT`）——这是一个此前没在其它档
  案里见过的、和内容本身无关的转档层面问题，本次改名为安全的 ASCII
  文件名以修复。
- 深度测试修复了与 xfbhh/hhsj 同架构、但独立血统的 CHARACTER mixin
  裸 `set()`/`query()` 解析失败问题（AGENTS.md §7.78）；一个让全部
  5 个区域事件永久失效的文件名截断算术错误（`eventd.lpc`）；以及一
  个让全部 9 种任务类型编译失败的共同祖先文件类型收窄 bug
  （`inherit/misc/quest.lpc` 的 `set_information()`）。详见
  NOTES.md。

## 注册流程

`new` 触发注册 → 字符集选择（`gb`/`big5`，任何非 `big5` 的输入都会被
当作英文 id 直接尝试，所以 GB 用户可以直接跳过这一步输入 id）→ 英文
id（3-10 个英文字母）→ 确认创建（y/n）→ 中文姓氏（可留空，不超过两
汉字）→ 中文名字（不超过两汉字，姓名合计至少 2 个汉字）→ 管理密码
（至少 5 个字元，用于密码找回/巫师密码）→ 确认管理密码 → 普通密码
（至少 3 个字元，且不能与管理密码相同）→ 确认普通密码 → 性格类型
（1-4）→ 角色类型（1-5）→ 性别（m/f）。

新角色会先进入"注册房间"，需要用房间内置指令 `register <email>` 完
成邮箱注册后才能正式进入游戏世界分配天赋属性。

## 本次修复的关键 bug

- `adm/daemons/versiond.lpc`（约 2300 行的版本同步/校验和 daemon，内
  置了一套完整的 TCP 服务端/客户端）：13 个不同函数无条件调用
  `socket_create`/`socket_bind`/`socket_listen`/`socket_accept`/
  `socket_address`/`socket_write`/`socket_close`，导致整个文件编译失
  败。由于 `logind.lpc` 的 `logon()` 在**每一次连接**时都无条件调用
  `VERSION_D->is_version_ok()`，这个编译失败会让**所有玩家**（不仅仅
  是巫师）的登录静默卡死在欢迎画面之后，没有任何提示或报错。已仅将
  涉及 socket 的函数体清空为 no-op（而不是整个文件禁用，因为
  `is_release_server()`/`append_sn()`/`query()` 等函数被全库大量其它
  npc/指令调用）。
- `adm/daemons/logind.lpc`：与海洋系列同款的 euid 被中途重置的
  bug——`make_body()` 里的 `seteuid(getuid())` 会把 `create()` 刚设置
  好的 euid 重置为空字符串。已改为显式 `seteuid(ROOT_UID)`。
- `check_legal_name()`：沿用旧版 GBK 字节长度界。
- `adm/daemons/named.lpc`：`invalid_new_name()` 要求单独传入的名字部
  分至少 2 个字符（旧版 4 字节=2 字符假设），导致任何单字名字被拒绝
  为"空名字"；另有一个基于字节偏移步进的相似名字滑窗检测算法，也是
  同样的字节假设，已按字符数重写。
- 原始归档中带有 20 个非法 UTF-8 编码的文件/目录名（`d/heimuya`、
  `d/jingzhou`、`d/tulong`、`d/beijing/map` 及冗余的 `work/version/`
  备份副本下），Node 的目录扫描遇到会直接崩溃（`ENOENT`）。已改名为
  安全的 ASCII 文件名，内容不变。
- `adm/daemons/securityd.lpc`：`wiz_status` 声明为 `nosave`，从不落
  盘存档，因此管理员名单必须写在代码里而非编辑存档文件。同时
  `restore()` 会调用 `log_file("nosave/security", ...)`，如果
  `log/nosave/` 目录不存在会抛出未被本对象捕获的异常，导致
  `create()` 提前中断（只被 `master.lpc` 最外层的 `preload()` 
  `catch()` 兜底）——需要先 `mkdir -p log/nosave/`。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

由于 `wiz_status` 是 `nosave` 的，管理员是通过在
`adm/daemons/securityd.lpc` 的 `create()` 里硬编码
`wiz_status["fluffos"] = "(admin)";` 实现的，每次驱动重启都会重新生
效（无需编辑存档文件）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/nt1/

## 本地运行

```
cd libs/nt1
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40185**。
