# 逸俠之世界 (yxzsj)

《逸俠之世界》（Daniel's World），ES II 引擎家族，台湾出品，和这批档案里的 `yxsj` 是同一份代码库在不同时间点的两个版本：同样的现代校园开局地图（`d/school/`，教室、中庭花园、实验大楼、厨房、脚踏车停放处）、同样收录台湾"霹雳布袋戏"元素的 `d/Pili/` 场景、同样的联络信箱与档案结构，但内容并非完全一致（例如 `adm/daemons/combatd.lpc` 相差约 80 行），是同一代码库不同时间点留下的独立快照，值得两份都保留而不是去重。

## 内容亮点

- 和 `yxsj` 是同一份代码库在不同时间点的两个版本：同样的校园开局
  地图（`d/school/`）、同样收录台湾"霹雳布袋戏"元素的 `d/Pili/`
  场景。两者内容并非完全一致（比如 `combatd.lpc` 相差约 80 行），
  值得都保留而不是去重。

## 重大编码问题（和 yxsj 一样，先修好才能继续）

这份档案也是 **BIG5** 编码，但最初的转换用了整个语料库默认的
GB18030，产生了看起来正常、实际语意不通的乱码（合法 UTF-8，但每
一句话都是错的汉字），而不是转码报错。用处理 `yxsj` 时扩充过的
`scripts/convert_lib.sh`（支持第三个"来源编码"参数）重新用 BIG5
转换了一遍，之前套用在乱码版本上的修复全部在新转出来的树上重做了
一遍。

## 本次修复的关键 bug

（和 `yxsj` 完全相同的模式）

1. 经典 §8.1 GBK 字节区间 `is_chinese()`/`check_legal_name()`
   ——改成逐码点的 `0x4e00`-`0x9fff` 判断，上下限从 2/12 减半成
   1/6。
2. §7.12 `tell_room()` 裸露 `exclude` 参数——补上
   `exclude || ({})`。
3. `master.lpc` 的 `valid_write()` 补上标准的
   `user == this_object()` 短路判断（`valid_read()` 本来就无条件
   回传 1；这份档案的 `securityd.lpc` 存档权限检查本来就是对的，
   不用改）。
4. §7.50 `is_killing(object)` 与 `is_killing(string id)` 类型不
   匹配，修好了和 `yxsj` 一样的 9 处呼叫点。
5. `data/` 目录下 45 个存档档案是 CRLF 换行，统一转成了 LF。

`adm/daemons/ftpd.lpc`、`adm/daemons/network/dns_master.lpc` 都已
经在 `adm/etc/preload` 里被注释掉，仅有的呼叫者也都是巫师专用指
令，属于完全休眠，本次没有改动。

## 已知但未修复的问题

和 `yxsj` 一样：`adm/daemons/chinesed.lpc`、`adm/daemons/emoted.lpc`
开机时都会报一次被拦截、非致命的"Illegal mapping format while
restoring dict/emote"；登陆过程会出现一次"apply() with
insufficient permission"，但都不影响任何游戏功能。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  后自动显示"目前權限﹕(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/yxzsj
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40170**。
