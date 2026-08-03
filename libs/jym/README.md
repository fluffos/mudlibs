# 金庸梦

以金庸小说世界观为背景的武侠 MUD。地图目录结构和 111
`xkx2000zxb`（侠客行2000最新版，MudOS v22b25 世系）高度重合——
`d/taihu/gumu/houtang.lpc` 等场景内容相同，只是文件头的"破解"署名
不同（`xkx2000zxb` 是"Cracked by Kafei"，这份档案是"Cracked by
Roath"），应是同一款"侠客行I"底层代码库的不同流通版本，此前两份
档案都没有互相记录这层关系。`xkm`（侠客梦）也是同一批"Cracked by
Roath"流通版本的手足档案。

## 内容亮点

- 和 `xkx2000zxb` 共享同一套地图骨架（太湖古墓、苗疆、昆仑、少林、
  武当等），但作为不同流通版本各自独立修改过部分场景与外围系统。
- 注册流程有"使用密码"和"保密密码"（≥10 位，专门用于找回密码）两
  套独立密码，比大多数档案的单一密码更谨慎。
- 管理员权限存储在 `securityd.lpc` 自己的存档文件里（`data/
  securityd.o` 的 `wiz_status` 属性，CRLF 编码），不是常见的
  `wizlist` 文本文件。

## 注册流程

`new` 触发注册 → 英文 id（3-8 个英文字母）→ 确认创建（y/n）→ 中文名字
（1-4 个中文字）→ 使用密码 → 确认使用密码 → **保密密码**（至少 10 个
字元，用于密码找回，与"使用密码"是两个独立的字段）→ 确认保密密码 →
天赋数值选择（0-4，0 为随机）→ 天赋数值确认（y/n）→ 电子邮件地址 →
性别（m/f）。

## 本次修复的关键 bug

- `adm/daemons/logind.lpc`：与海洋系列同款的 euid 被中途重置的 bug——
  `make_body()`/`howmany_user()` 里的 `seteuid(getuid())` 会把
  `create()` 刚设置好的 euid 重置为空字符串。已将三处（含 `create()`
  自身）全部改为显式 `seteuid(ROOT_UID)`。
- `check_legal_name()`：沿用旧版 GBK 双字节假设的长度界，且在校验失败
  分支里还有一行 `name[j]+=128; name[j+1]+=128;`——对 Unicode 码点做
  "加 128" 已经没有意义（这是过去 GBK 高位字节判断的遗留代码），已删除
  并改为按字符数（1-4）+ 逐字符 `is_chinese()` 判断。
- `adm/daemons/securityd.lpc`：`get_status()` 对尚未完成初始化的
  `wiz_status`/`wiz_levels` 重入调用会崩溃，已加 `mapp()`/`arrayp()`
  防御（与海洋系列相同的重入编译崩溃模式）。
- `cmds/usr/quit.lpc`：`environment(me)->query(...)` 在玩家环境为 0
  时崩溃（`*Bad argument 1 to call_other()`），已在三处调用前加
  `environment(me) &&` 防御。
- `adm/simul_efun/message.lpc`：`tell_room(ob,str,exclude)` 把省略的
  `exclude` 参数（默认值裸 int 0）直接传给 `message()` 的第 4 个参数，
  导致游戏里第一次 `tell_room()` 调用（欢迎室自己的 `create()`）就崩溃。
  这是 AGENTS.md §7.12 已归档的共享 wrapper bug，按文档修复为
  `exclude || ({})`。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在 `adm/daemons/securityd.lpc` 自身的存档文件
`data/securityd.o` 的 `wiz_status` 属性里（该文件用 CRLF 而非海洋系列
的纯 CR 编码，但依然用二进制模式编辑以防万一）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/jym/

## 本地运行

```
cd libs/jym
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40184**。
