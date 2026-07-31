# 风云III (3.0)

与 151/fy2mg 同为 `jinyongqunxiazhuan`/XKX 框架家族成员（登录流程、
`check_legal_name`、密码复杂度要求、民族选择等均字节级相同），但游戏
内容和标题不同，与本合集里其它"风云"系 lib（fy2/fys/fysjmb/jhfy2/
jhfy3/fyzfqyy/fengyun2qinghua/fengyun3dianzang/fengyun3xiuding/
jianghufengyun/zzfy/zzfy3/fengyun434/fy2005）也无 master-hash 匹配。

## 注册流程

`new` 触发注册 → 英文 id（3-10 个英文字母）→ 确认创建（y/n）→ 中文
名字（1-6 个中文字，留空则随机取名）→ 密码（需同时包含大写字母、
小写字母和特殊符号）→ 确认密码 → 电子邮件地址 → 性别（m/f）→ 民族
选择（0=汉族，1=苗族，2=满族，3=蒙古族）。

新手起始房间"凤求凰客栈"里有活跃的 NPC 心跳对话，如果用脚本化测试
（`--idle` 触发发送）在刚进入房间后立即测试 `quit`，NPC 对话可能会
不断刷新输出、延后满足静默阈值的时机——这不是 bug，多给几条中间指令
（例如先 `look`/`score`）就能正常触发。

## 本次修复的关键 bug

（与 151/fy2mg 完全相同）

- `adm/daemons/logind.lpc`：`make_body()` 里的 `seteuid(getuid())` 会
  把 `create()` 刚设置好的 euid 重置为空字符串，已改为显式
  `seteuid(ROOT_UID)`。
- `check_legal_name()`：沿用旧版 GBK 字节长度界，已改为按字符数
  （1-6）+ 逐字符 `is_chinese()` 判断。
- `adm/daemons/securityd.lpc`：`get_status()` 加了防御性
  `mapp()`/`arrayp()` 检查。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026x`（含大小写字母 + 特殊符号）
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/fy330/

## 本地运行

```
cd libs/fy330
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40199**。
