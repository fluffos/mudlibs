# 鹿鼎天下II (ldtxii)

[ldtx](../ldtx/) 的姊妹版本（同一个 Century/adm-single 架构家族，
但绝大多数内容不同，不是文件级重复）。

## 内容亮点

- 以《鹿鼎记》为名的 Century/adm-single 家族档案，和 `ldtx` 是姊妹
  版本，架构相同但绝大多数具体内容独立开发。
- 地图里同样有"杀手楼"（`d/shashou/`）和结婚系统（`d/marry/`），
  是这批门派+社交/黑道路线扩展的又一个例子。
- 有一处真实存在、未修复的内容缺口：`d/city/chatroom.lpc` 引用了
  一个根本不存在的巫师目录 `/u/mouse/`，NPC 心跳偶尔走进这个房间
  会触发崩溃——和 `ldtx` 的 `xiaobao.lpc` 缺口是同一类"预先存在、
  不凭空补内容"的处理方式。

## 注册流程

选择编码 GB 或 BIG5（本地/浏览器测试用 `gb`）→ 按 Enter 跳过跨服
Mud 列表 → 英文名字（3-8 个小写英文字母）→ 确认建立新角色（y/n）
→ 中文名字 → 密码（至少 5 位）→ 确认密码 → 天赋分配（输入 0-4，0
代表全部交给系统随机产生）→ 是否接受这组天赋（y/n）→ 电子邮件地
址 → 性别（m/f）→ 进入游戏世界。

## 本次修复的关键 bug

- `adm/simul_efun/chinese.lpc` 的 `is_chinese()`：经典的 §8.1
  GBK 字节区间判断错误——`str[0] > 160 && str[0] < 255`，这是旧式
  GBK 编码「前导字节」的判断范围，但本驱动的字符串是 Unicode 码
  点，中文字的码点落在 0x4e00-0x9fff（19968-40959），远超过 255，
  所以这个判断式对任何真正的中文字都是 false——等于每一个中文名
  字都会被判定成「不是中文」而拒绝注册。改成正确的码点区间判断
  （`str[0] >= 0x4e00 && str[0] <= 0x9fff`）即可。
- `adm/daemons/network/dns_master.lpc`：和 [ldtx](../ldtx/) 完全
  相同的 bug——`socket_create()`/`socket_bind()` 在这个 WASM 编译
  版本里是未定义的 efun，档案编译失败会打断连线一开始
  `encoding_to_mudlist()` 里对 `DNS_MASTER->query_muds()` 的呼叫，
  导致每次连线都卡在编码选择之后。已用和 ldtx 相同的方式清空
  `startup_udp()`/`send_udp()`/`send_shutdown()` 里的
  `socket_close()`。

`check_legal_name()` 里同样有 ldtx 那个 `i%2==0` 隔字检查的历史写
法，但因为不影响真实中文名字通过验证，未做修改。

另外发现一个**不影响游戏进行、没有修复**的内容缺失：
`d/city/chatroom.lpc` 的物件列表里放了 `/u/mouse/topten`，但整个
存档里根本没有 `/u/mouse/` 这个巫师目录。当某个 NPC 的
`heart_beat` 随机走进这个房间触发 `reset()` 时，`make_inventory()`
对不存在的文件调用 `new()` 拿到 0，再对 0 调用 `->move()` 就会抛
出 `Bad argument 1 to EFUN call_other()`——和 ldtx 的
`xiaobao.lpc`、以及 `sj.lpc` 那一类预先存在、不补内容的缺失是同一
种情况，按项目一贯做法没有去凭空补一个档案。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud2026Adm`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里；和 ldtx 不同，这
份档案本身没有预先存在的管理员账号或 README，是本次全新注册的。
账号本身通过正常注册流程创建，已在游戏内确认 "目前权限：(admin)"
显示正确。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/ldtxii
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40176**。
