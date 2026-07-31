# 侠客行（老版/金庸群侠传）

从一个扩展名错误的 `.rar`（实际是带有 `../` 成员路径的 POSIX tar）
提取。归档里还带着一份未被使用的 `adm/obj/master.lpc`，恰好和
jyqxc/fy2mg/xkx2017 那套框架字节相同——但实际启动用的是
`/adm/single/master`，不是这份。

## 注册流程

`new` 触发注册 → 英文 id（3-12 个英文字母）→ 确认创建（y/n）→ 中文
名字（1-6 个中文字）→ 密码（≥5 字元）→ 确认密码 → 天赋确认（y/n）
→ 电子邮件地址 → 性别（m/f）。

## 本次修复的关键 bug

- **最重要的一个**：`include/globals.h` 里的 `SIMUL_EFUN_OB` 宏指向
  一个未被使用的死代码文件 `/adm/single/simul_efun.lpc`（早期重构留
  下的重复文件），而 `config.fluffos` 的 `simulated efun file` 实际
  指向 `/adm/obj/simul_efun.lpc`——两者路径不一致。这导致
  `feature/move.lpc` 里 `remove()` 的安全检查（校验
  `previous_object()` 是否等于 `SIMUL_EFUN_OB`）对每一次通过
  `destruct()` 触发的物件摧毁都会失败，具体表现为：**每一个新玩家
  退出游戏（quit）都会失败**——因为 `quit` 的自动丢弃背包逻辑会摧毁
  任何不值钱的物品，而新角色出生就带着一件不值钱的布衣。这个 bug 很
  隐蔽：连接看起来打印了一个被拦截的运行时错误然后就断开了，但实际
  上角色仍然停留在游戏世界里，连线从未真正关闭。已将宏指向真正被
  使用的文件（这和之前某个 lib 里 `securityd.lpc`/`securd.lpc` 两份
  文件的陷阱是同一种教训——即使宏名字看起来"显然正确"，也要用
  `config.fluffos` 或实际调用链去验证它到底指向哪个文件）。
- `adm/daemons/logind.lpc`：`make_body()` 里的 `seteuid(getuid())` 会
  把 `create()` 刚设置好的 euid 重置为空字符串，已改为显式
  `seteuid(ROOT_UID)`。
- `check_legal_name()`：沿用旧版 GBK 字节长度界，已改为按字符数
  （1-6）+ 逐字符判断。
- `adm/daemons/securityd.lpc`：`valid_write()` 的 `save_object` 分支
  比较 `file` 参数时忘记驱动会附加存档扩展名，已修复为
  `file == qsf || file == qsf + 扩展名`。
- 一处真正损坏的留言板存档（`data/board/kedian_b.o` 某条留言的作者
  字段里混入了原始的、非 UTF-8 的 GBK 字节），导致进入那个房间就必
  然崩溃 `look`。尝试过按 GBK 部分重新解码，但剩下的字节不足以安全
  完整地修复，最终选择直接删除这个损坏的存档文件，而不是冒险做局部
  字节级修补。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/xkxlb/

## 本地运行

```
cd libs/xkxlb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40202**。
