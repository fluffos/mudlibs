# 郑州风云3 (zzfy3)

《郑州风云3》（游戏内横幅：风云系列之天下无敌）。以古龙小说为背景的风云系列 MUD，由长孙无情（Xgchen）建立，和 `wqfy`（无情风云，同样打着"天下无敌"横幅）共享同一套"郑州风云"地图与结婚系统（`d/marry/hongniang-zhang.lpc` 说媒 NPC 逐字节相同），又和本项目另一份同样叫"郑州风云3"的档案 `zzfy` 近乎重复——两边工作目录各 10345 个档案，只有 183 个内容不同。注册时可选择民族（0-3），呼应古龙背景下的跨民族江湖设定；死后由鬼门关的判官 NPC（`d/death/npc/panguan.lpc`）推动一段五阶段对话进入轮回，鬼魂可以在阴间自由走动，不像部分兄弟档案会锁住鬼魂的移动。这份档案的权限系统比较特殊：管理员权限不经过 `adm/etc/wizlist`，而是硬编码授予原作者自己的巫师 ID `xgchen`。

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

## §10.7 深度游玩测试新增修复的 bug

移植自兄弟档案 `zzfy` 现场验证过的发现：死亡代码覆盖永久登入地点
（AGENTS.md §7.24）、房间填充助手 `new()`/`move()` 无防护（§7.25）、
商店坏路径 `/obj/example/wineskin`（13 处 NPC 档案）、`summon`
指令空指针判断顺序。本档案独有的新发现（已写入 AGENTS.md §7.102/
§7.103）：移动派发器 `cmds/std/go.lpc` 对失效出口的强制加载没有
`catch()` 保护（新手学堂入口 `/d/newbei/wel1` 整个不存在，撞上时
会把驱动报错堆栈甩给玩家）；`master.lpc` 的运行时报错处理器把纯
编译警告也原样刷给每一个普通玩家，不只是真正的错误。另外补齐了
标准的 §1.3b/§1.3e 本地连线节流豁免（`band.lpc` 新增
`is_local_site()`，多重登录上限和 20 秒重连节流对回环连线豁免）。
详见 `NOTES.md` 的完整现场验证记录。

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
