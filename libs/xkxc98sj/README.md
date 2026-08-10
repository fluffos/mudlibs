# 侠客新传98书剑 (xkxc98sj)

「侠客新传」v0.1b，MudOS v22pre11，Xkxz MUD Wizard Group 2000-2001，
由 jjgod 维护。名字里带"书剑"二字，但和 `sjecl`/`sje`/`sjplgfjxb`/
`sjplii` 那批真正的"书剑"系列泥潭完全不同源，纯属命名巧合（"98书
剑"应该是站点当年的版本代号）。血统上也和同样带"XKX"/"侠客"字样的
`xkx100`/`xkx2017`（另一支"侠客行"泥潭）无关——`master.lpc` 逐字节
确认属于 AGENTS.md §11 的「"hell" / Doing Lu」支系（ES II → XKX →
hell），和 `zjdyaryl`/`zjdyzj`/`hell` 同源，详见 NOTES.md 的深度测
试记录。

## 内容亮点

- 地图里有"苗疆"（`d/miaojiang/`）场景，是这批档案里比较少见涉及
  苗疆蛊术文化背景的门派/地理设定。
- `is_killing()` 参数类型不匹配这一类 bug（详见下方第 3 条）波及
  18 个文件、遍布各门派武功技能与城市 NPC，比此前在 `sjecl`/`sje`
  只各自出现几个文件的规模大得多（后来在 `zzfy3` 里还发现过波及
  25 处的更大规模版本）。
- 游戏内事件系统曾因 `eventd.lpc` 的字符串切片 off-by-one 完全失
  效（和 `wdxtym` 的是同一个 bug），本次修复后应已恢复正常。
- 死亡/复活系统实际打死过角色（管理员+非管理员各一次）验证过完整
  无干扰循环，落地房间、属性、经验值都正确保留，没有类似同血统
  `kxkjii2` 那种死亡出口 bug（详见 NOTES.md §10.7）。
- 任务系统 7 个任务档案（`clone/quest/{search,shen,judge,supply,
  deliver,explore,defend}.lpc`）曾因共享的 `inherit/misc/quest.lpc`
  包装函数类型声明过窄而全部编译失败、静默退出随机任务生成轮换，
  本次一并修复（AGENTS.md §7.81 第四个确认实例）。

## 本次修复的关键 bug

1. **`eventd.lpc` 的经典 off-by-one**：和 `wdxtym` 修的是同一个
   bug——`$1[0..<3]` 想去掉 `.lpc` 后缀（4 个字符），却只去掉了 2
   个（`emei.lpc` 变成 `emei.l`），导致 `collect_all_event()` 呼叫
   每一个事件文件全部失败。改成 `[0..<5]`。
2. **§8.1 GBK 字节区间 bug**：`adm/simul_efun/chinese.lpc` 的
   `is_chinese()` 只检查前两个原始字节，在 UTF8 码点索引下永远失
   败；`adm/daemons/logind.lpc` 自己的长度上限也是字节数写法（最小
   2、最大用 8 呼叫，实际应该是最小 1、最大 4，对应注册提示文字
   "名字的长度不能大于四个汉字"）。已把 `is_chinese()` 改成逐码点
   检查，并把 `check_legal_name(arg, 8)` 的呼叫改成 4。
3. **`is_killing()` 参数类型不匹配，波及 18 个文件**：
   `feature/attack.lpc` 声明 `is_killing(string id)`，但代码库里到
   处（各种武功技能、城市 NPC）直接传对象——`is_killing(me)`、
   `is_killing(who)`、`is_killing(ob)`、`is_killing(ob[i])`。这和之
   前在 `sjecl`/`sje` 修的是同一类 bug，只是这份档案里波及范围大得
   多。已把所有活跃调用点都改成传 `->query("id")`（`haotian-
   zhang/ju.lpc` 和 `quanzhen-jianfa/ding.lpc` 里各有一处已经被作者
   自己注释掉的调用，属于死代码，未做改动）。
4. **两处 §7.41 存档损坏 bug**：`adm/daemons/emoted.lpc` 的
   `create()` 对 `restore()` 没有保护，`emote.o` 存档确实已经损坏
   （"Illegal mapping format"）；`adm/daemons/newsd.lpc` 的
   `create()` 也是一样的问题，`dbase` 存档同样损坏。两处都加上
   `catch()`——从驱动的错误堆栈可以确认，现在异常在精灵自己的
   `create()` 里就地被拦截了（堆栈里出现了精灵自己的
   `CATCH()`），不再往外传播，后续也没有观察到任何连锁错误。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（这份档
  案的 `securityd.lpc` 真的会在开机时读取 `WIZLIST`，`fluffos
  (admin)` 这一行早已存在，本轮认领了这个 id），登录后显示
  "您目前的权限是：(admin)"确认生效，并用 `update` 指令验证过实际
  写权限。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/xkxc98sj
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40126**。
