# 郑州风云3 (zzfy3)

《郑州风云3》（游戏内横幅：风云系列之天下无敌）。以古龙小说为背
景的风云系列 MUD，由长孙无情（Xgchen）建立，和 `wqfy`（无情风
云，同样打着"天下无敌"横幅）是同一套"郑州风云"地图与代码库——
`d/marry/hongniang-zhang.lpc` 逐字节相同，此前两份档案都没有互相
记录这层关系。档案里有一个巫师个人目录 `u/wiz/u/xxy/`，里面是真正的游戏内容（武功/NPC 档案，不
是死代码备份），另外还有几份真正没用的 `logind.lpc` 备份放在
`d/wiz/xgchen/`、`u/wiz/u/china/`、`u/wiz/u/lxh/` 下——用
`include/globals.h` 里的 `LOGIN_D`=`/adm/daemons/logind` 和
`MASTER_OB`=`/adm/obj/master` 确认过只有
`adm/daemons/logind.lpc` 和 `adm/obj/master.lpc` 是真正生效的，
那几份 `logind.lpc` 备份没有动，但 `u/wiz/u/xxy/` 下的
`is_killing()` 呼叫点是真正会被玩家碰到的游戏内容，**修了**。

这份档案的权限系统比较特殊：`securityd.lpc` **不使用**
`adm/etc/wizlist`，而是在自己的 `restore_list()` 里每次开机都
硬编码执行 `set("wiz_status/xgchen","(admin)")`，所以第一次开机
唯一能拿到管理员权限的方法就是用原作者自己的巫师 ID `xgchen` 注
册（确认过 `xgchen` 不在 `logind.lpc` 的 `banned_id` 黑名单里）。

## 内容亮点

- 和 `wqfy` 共享同一套"郑州风云"地图与结婚系统（`d/marry/`，"红
  娘"NPC 说媒牵线），但管理员引导机制完全不同：这份档案的
  `securityd.lpc` 每次开机都硬编码授予固定 ID `xgchen` 管理员权
  限，完全不读取 `wizlist`（详见下方管理员账号说明）。
- 注册时要选择民族（0-3），呼应古龙背景下的跨民族江湖设定，和
  `wqfy` 一致。
- `daemon/class/` 和 `cmds/daemon/class/` 是两份内容完全相同的
  平行目录，无法判断哪个是死代码，本次两边的 `is_killing()` bug
  都做了修复（详见下方第 3 条）——这是本轮修复过的档案里
  `is_killing` 波及范围最大的一次（25 处，后来在 `yxxcii` 里还发现
  过波及 49 处的更大规模版本）。

## 本次修复的关键 bug

1. **`check_legal_name()` 的 §8.1 字节数没减半 + 奇偶判断
   bug**：长度上限没有减半（`<2||>12`，本意是"一到六个中文
   字"）——改成 `<1||>6`；还有一个 `i%2==0` 的奇偶门槛，配合只
   检查 `str[0]` 的单码点 `is_chinese()` 辅助函数
   （`name[i..<0]` 切片），实际上只验证了一半的字符——去掉了这
   个奇偶门槛。
2. **`master.lpc`（`adm/obj/master.lpc`）的 `valid_write()`
   缺少标准的 `user == this_object()` 短路判断**——补上了
   （`valid_read()` 这里本来就无条件 `return 1`，完全没有转给
   securityd，所以不需要补）。
3. **§7.50 `is_killing(object)` 与 `is_killing(string id)` 类型
   不匹配**，修好了 25 处呼叫点——涉及 `daemon/class/*`、
   `cmds/daemon/class/*`（这是 `daemon/` 的一份真正的平行重复
   目录，内容完全一样，两边都无法排除是死代码，所以两边都
   修了）、`cmds/std/{surrender,nuoyi,kill}.lpc`、
   `d/wiz/xgchen/touxiang.lpc`，以及 `u/wiz/u/xxy/` 下好几份武
   功/NPC 档案（`mei-po.lpc` 等）。

确认了本档案已经正确、不需要修的地方：`securityd.lpc` 的
`save_object` `valid_write()` 判断已经正确比较
`query_save_file()+__SAVE_EXTENSION__`。`httpd.lpc` 和
`dns_master.lpc`（`adm/daemons/` 下的正式版本以及
`u/wiz/u/china`、`u/wiz/u/lxh` 下的旧备份）都有真正没被掏空的裸
`socket_*()` 呼叫，但都已经在 `adm/etc/preload` 里被注释掉，也
没有其他可达的呼叫者——按本项目其他档案已经确认的先例保持休眠，
没有改动；本档案也没有 `versiond.lpc`。`log/nosave/` 目录本来缺
失——为保险起见建了这个目录（没有确认是致命 bug）。

## 管理员账号 / Admin account

- **ID**: `xgchen`（这份档案的权限系统硬编码只认这个 ID 作为初
  始管理员，不经过 `adm/etc/wizlist`）
- **密码 / Password**: `Mud@2026`
- **权限 / Level**: `(admin)`，`securityd.lpc` 每次开机都会自动
  赋予，登录后自动显示"目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码，并考虑是否要调整
> `securityd.lpc` 里硬编码的初始管理员 ID。

## 本地运行

```
cd libs/zzfy3
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40120**。
