# 海洋（基础版）

以"金庸小说背景"为世界观的武侠 MUD（请勿使用小说中人名），社区名"情义盟"。

## 内容亮点

- 注册流程：`new` 触发注册 → BIG5 字体确认（y/n，非空即可）→ 英文 id →
  确认创建（y/n）→ 中文名字（可留空由系统随机取名）→ 密码 → 确认密码 →
  天赋数值选择（0-4，0 为随机）→ 天赋数值确认（y/n）→ 电子邮件地址
  （需含 `@`）→ 性别（m/f）。
- 天赋系统：膂力、悟性、根骨、身法，可指定其一或全部随机。

## 本次修复的关键 bug

- `adm/daemons/logind.lpc`：`create()` 里设置的 `seteuid(ROOT_UID)` 会被
  后续 `howmany_user()`/`make_body()` 里遗留的 `seteuid(getuid())` 重置为
  空字符串（该 daemon 的真实 uid 从未被正确解析），导致注册流程中途所有
  `read_file`/`log_file` 权限判定失败。已将这两处改为显式
  `seteuid(ROOT_UID)`。
- `howmany_visitor()`/`howmany_card()`：当 `/log/mud/MUDVISITOR`、
  `GIFTCARD` 计数文件不存在时，`read_file()` 返回 `0`，`sscanf(0, ...)`
  直接崩溃中断整个注册流程。由于 `libs/*/work/**/log` 已被 `.gitignore`
  排除，这在全新 clone 的仓库上是真实会复现的首次启动 bug，不只是 WASM
  沙箱的测试假象。已加 `if (!content) return 0;` 防御。
- `adm/daemons/securd.lpc`（真正生效的安全 daemon —— `SECURITY_D` 宏指向
  `securd.lpc`，同目录下的 `securityd.lpc` 是未被引用的遗留重复文件）：
  `get_status()` 里 `member_array(euid, wiz_levels)` 会在该对象自身尚未
  完成变量初始化时被重入调用（`wiz_levels` 声明在 `wiz_status` 之后，
  `create()` 内 `restore()` 触发的 `valid_read()` 链会在此刻重入本对象），
  此时 `wiz_levels` 还是默认值 `0`，导致崩溃。已加 `arrayp(wiz_levels)`
  防御。
- `adm/daemons/band.lpc`：`is_banned()` 加入 loopback 放行判断。
- `is_chinese()`：改为按 Unicode 码点判断（`0x4e00`-`0x9fff`），修正旧版
  按 GBK 双字节假设的判断逻辑。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

此代码线的权限系统**不通过** `/adm/etc/wizlist`（该文件从未被
`securd.lpc` 读取，是遗留自旧版本的死代码路径）。管理员名单实际存储在
`adm/daemons/securd.o` 存档文件自身的 `wiz_status` 属性里。授予方式是
直接编辑该存档文件的 `wiz_status` 映射，追加 `"fluffos":"(admin)"`。

> 注意：`securd.o` 用真实的回车符（CR, `\r`）而非换行符对映射键里的
> `/` 做编码，编辑此文件务必使用二进制模式读写，文本模式的换行符转换
> 会静默把 `\r` 转成 `\n`，破坏存档格式（`restore_object(): Illegal
> mapping format`）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/hy/

## 本地运行

```
cd libs/hy
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40182**。
