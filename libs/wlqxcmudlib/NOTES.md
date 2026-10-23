# wlqxcmudlib（武林群侠传 MUDLIB）-- porting notes

Archive `武林群侠传MUDLIB.7z`（编号 931）7z 头加密，档尾有一段明文 GBK：

```
MUD
游戏QQ群：9783836
解压密码： mud.ren
```

`7z t -p'mud.ren'` Everything is Ok。`Lib/` 是完整的炎黄/武林群侠传引擎（`adm/single/master.c`，与 `yanhuangwuhun` 同一 yh 2003 头）。

`convert_lib.sh … GB18030`：already_utf8=476 converted=10572 lossy=8 skipped_binary=15；10265 个 `.lpc`。端口 **40268**。

运行时补了 yh 血统两处（与 `yanhuangwuhun`/`zhyx` 相同）：

1. `adm/daemons/versiond.lpc`：`get_config(__MUD_PORT__)` 在这个驱动上是字符串，`socket_bind()` 要 int，加 `to_int()`。
2. `adm/simul_efun/message.lpc`：第四参 `exclude==0` 不能直接丢给 efun（§15s），按有无 exclude 分两路。

注册路径还要 §15h 的 UTF-8 姓名检查：`adm/simul_efun/chinese.lpc` 的
`is_chinese()`、`logind.lpc` 的 `check_legal_name`/组合长度、
`named.lpc` 的 `PATH()` 与滑动窗口，都从「GBK 字节」改成「汉字字符」。
管理员 `fluffos` 已写入 `adm/etc/wizlist`。

`clone/user/user.lpc` 的 `accept_kill()` 把 object 传给
`is_killing(string)`，本树的 `feature/attack.lpc` 没有 yanhuang 那份
`mixed` 签名，user 物件编不过，新号 `make_body` 失败、指令全是「什么？」。
改成 `is_killing(ob->query("id"))` 后，`qinfeng`/秦风 走完整注册进
世外桃源（水笙、狄云在场）。`logind.lpc` 的 `MESSAGE_D->find_chatter`
也加了 `find_object` 保护。

## 商店付费购买（2026-09-04 librarian shop slice）

手足 `yanhuangwuhun` 2026-09-03 的路径可套：醉仙楼买烤鸡腿、丐帮黎生拜师。
本轮注册了真正的 admin `fluffos`/`Mud@2026`（登录密码 `Play2026x`，中文名
云游）。第一行就是英文 id，没有 GB/Big5 选择。落地世外桃源
`/d/register/entry`，`register test@example.com` + `decide` + `west`
花铁干（阴险奸诈）+ `out` 阎罗殿，`washto 20 20 20 20`，`born 扬州人氏`
进扬州客店 `/d/city/kedian`。提示是每秒时钟（`env/prompt` = time），
`mudclient.py` 用 `--idle 0.4`–`0.6`。`help/rules` 仍是生 GB18030，分页
打断第一次 look，是 yh 血统已知内容缺口，不是本轮新 bug。

### 修了两处真编程 bug

1. **`goto` 第一次触发 `MESSAGE_D` 崩溃**（AGENTS.md §7.89 形状）：
   `/adm/daemons/network/messaged.lpc` 的 `create()` 写
   `my_port = LOCAL_PORT() + MESSAGE_PORT`，`LOCAL_PORT()` 是
   `(int) get_config(__MUD_PORT__)`，这个驱动上 `get_config` 回字符串，
   `(int)` 不强制转换，`"" + 10` 变成字符串 `"10"`，`socket_bind()` 报
   `Expected: int Got: "10"`，整条 `goto` 中止。本树 `versiond.lpc`
   进口时已经用 `to_int(get_config(__MUD_PORT__))` 修过，`messaged`
   漏了。已改成同样的 `to_int`，`socket_bind` 两处也包 `to_int(my_port)`，
   `send_udp()` 加了 `!socket_id` 守卫。修复后 `goto /d/city/zuixianlou`
   干净落到醉仙楼。

2. **`clone` 因 `/log/nosave/` 不存在崩溃**（§7.11）：
   `adm/simul_efun/file.lpc` 的 `log_file()` 直接 `write_file(LOG_DIR +
   file)`，没有 `assure_file()`。巫师 `clone /clone/money/gold` 写
   `/log/nosave/clone` 时报 `Wrong permissions ... No such file or
   directory`，物件没变出来。已加 `assure_file` 前向声明并在写入前建
   目录。修复后 `clone` 回「黄金复制成功」，`i` 见到一两黄金。

本机 `debug.log` 这轮没打开（`log directory : /log` 是绝对路径，驱动
cwd 进 work 之后没有对应 fd）。运行时错误当时打在玩家屏幕上。

### 商店

`goto /d/city/zuixianlou`，店小二 `list` 给出牛皮水袋/干粮/包子/烤鸡腿
（八十文铜板）/烤鸭/牛皮酒袋。`clone /clone/money/gold` 后 `buy jitui`
live 回「你从店小二那里买下了一根烤鸡腿」。`i` 为九十九两白银 +
二十文铜钱 + 烤鸡腿 + 零两黄金。扬州客店的 `list` 会先打到北丑（只卖
消息），要用醉仙楼的店小二。

### 拜师（2026-09-04 续：`command_hook` §8.3a）

同一次 wakeup 里先确认不是 `living()` 缺口：`call li->query_commands()`
已经登记了 `command_hook`（`""`, flag 1）和 path `{/cmds/std/, /cmds/skill/}`，
`bai li` 也确实进到了 `attempt_apprentice`。`f li to say` 却回「黎生无法执行你的命令」。
手足 `yanhuangwuhun` 已经是 `nomask int command_hook`（没有 `private`）。

根因是 AGENTS.md §8.3a：`feature/command.lpc` 的
`private nomask int command_hook` 被 inherit 后降成 `DECL_HIDDEN`。玩家手打
动词走 `ORIGIN_DRIVER`，NPC `command()` efun 走 `ORIGIN_EFUN`，apply 静默回 0。
本树是 2026-09-04 进口的，corpus sweep 之后才进来，所以还带着 `private`。

已改成 `nomask int command_hook`（只去掉 `private`）。重启后：

- `f li to say 测试说话` → `黎生说道：测试说话`
- `bai li` → nod + `我便收你为徒…` + `决定收你为弟子` + 磕头 +
  `恭喜您成为丐帮的第二十代弟子`
- `score` → `【 小叫花 】丐帮第二十代传人` / `师父是黎生`

商店切片上一轮已经付费买过醉仙楼烤鸡腿，本轮没有重做。

## WASM (2026-09-11 leftover 653)

`versiond.lpc` 直接调用 `socket_create`/`socket_bind`/`socket_listen`，
WASM 没有 sockets 包，daemon 编成 `*No program`。`logind.lpc` 两处
`VERSION_D->is_version_ok()` 和 `closed.lpc` 的 `heart_beat` 没
`find_object` 守卫，登录在 id 提示前就断、心跳反复重编。已按
`yhwhckdm` 同形加上守卫（`punishd`/`storyd` 的同步闸也加了）。
`ftpd`/`dns_master` 同样编不过，preload `catch` 掉，不挡登录。

提交了管理员 `fluffos` 存档（登录 `Play2026x`，管理 `Mud@2026`，
中文名云游）。`wasm_client.js`：`fluffos` / `Play2026x` → 扬州客店
`/d/city/kedian`（北丑、店小二），`look` 同文，`score`「普通百姓
云游」，`quit`「欢迎下次再来」。`wasm_status` 改为 `playable`。
提示仍是每秒时钟，`--idle 0.5`。

## 深度功能测试（§10.7，2026-09-13）

原生 driver 端口 40268，`fluffos` / `Play2026x`。stdout →
`/tmp/wlqxc-driver.out`。slug `libs/wlqxcmudlib/log/debug.log`（§10.9）
与 mudlib `work/log/log`（`master->log_error()`）都查了。

### 发现并修复

1. **`LOCAL_PORT()` 仍用 `(int) get_config(__MUD_PORT__)`，FluffOS 上
   不强制转换。** `dns_master` 的 `my_port = SRVC_PORT_UDP(mud_port())`
   变成字符串 `"4"`，preload 时 `socket_bind` 报
   `Expected: int Got: "4"`。商店切片已修过 `messaged`/`versiond` 的
   `to_int`，宏本身漏了。已改
   `include/getconfig.h`：`LOCAL_PORT()` → `to_int(get_config(...))`。

2. **`inherit/misc/quest.lpc` 的 `set_information(string key, string
   info)` 过窄（AGENTS.md 已归档形状）。** ambient quest daemon 冷编
   `clone/quest/{deliver,judge,…}` 时 `Bad type for argument 2
   (string vs function)`，物件 `*No program`，`heart_beat` 反复刷错。
   已改成 `mixed info`。手足 `yanhuangwuhun` 同修。

3. **§4.1 扩展名缺失的 GBK 文本：** `help/rules`、
   `clone/game/{8,21}_hlp` 仍是生 GB18030（NOTES 商店切片已点名
   `help/rules`）。`iconv -f GB18030 -t UTF-8` 转完；`help rules` 现场
   可读「【游戏规则】」。全树 UTF-8 扫描剩余命中只有字体二进制
   （`adm/etc/font/*`、`kungfu/skill/huashan-quan/MFM1992`），不是文本。

### 游玩证据

- 登录落地扬州客店 `/d/city/kedian`；`help newbie` 桃源/方向说明可读。
- 商店：`goto /d/city/zuixianlou`，`list` 烤鸡腿八十文；
  `clone /clone/money/gold` 后有机 `buy jitui` →
  「你从店小二那里买下了一根烤鸡腿。」找零成 1 金 + 98 银 + 40 铜 +
  烤鸡腿。
- 拜师：`goto /d/gaibang/inhole`，`bai li`（黎生）→ 点头 /「我便收你
  为徒」/「恭喜您成为丐帮的第二十代弟子」；`score`
  「【 小叫花 】丐帮第二十代传人 / 师父是黎生」。
- 战斗：新手 `fight mu ren` 被拒「这点身手还不足以和木人练功」
  （木人门槛，设计如此）。巫师 `call` 把 unarmed/dodge/parry 提到 50、
  `combat_exp` 5 万后，`clone /clone/npc/mu-ren` + `fight mu ren` 互出
  拳脚，`surrender` 干净。
- `quit`「欢迎下次再来」；重连后门派/师父/银钱仍在。烤鸡腿未随档
  （食物常见 `no_save`，与手足 `yanhuangwuhun` 相同，不当 bug）。

### 日志

修完重启后：boot + 约半分钟 ambient quest 心跳，slug `debug.log` /
stdout **无** `socket_bind` Bad argument、**无** quest `Bad type` /
`*No program`。`work/log/log` 本轮尾部无同类命中。

### 未改

管理员运行时存档未提交。木人对新手的经验门槛未动（设计）。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。
- `cmds/std/swear.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt nitan_ceshi wlqxcmudlib` 把 nitan_ceshi 警告整理提交（ae7fbb619a5）里的改动搬到修改前与它一致的文件（逐文件核对非 ASCII 文字：除 nitan_ceshi 自己删掉的以外没有丢失或改动），再用 `scripts/lpc_nitan_family_fixes.py wlqxcmudlib`（`adm/daemons/combatd.lpc` 删去空语句 `your_temp["guarding"];` 等）。剩下的再跑 `scripts/lpc_warnings.py wlqxcmudlib --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`d/tiezhang`、`d/wudu` 几个房间删去 `return` 后面永远执行不到的 `"\n";`），共改动 748 个 `.lpc` 和若干 `.h`。以上都不改变行为。
HEAD 与工作树分别加载（新进程）：746 -> 746 通过，无回退。

启动时警告 93 -> 0；新进程登录正常。

- 2026-10-12：`clone/misc/swmuding.lpc`（神木王鼎）自己声明了一张 `mapping insects` 虫表，与继承的 `clone/misc/muding.lpc` 的 `insects` 同名；读表的是木鼎的代码，读到的是木鼎自己的表，神木王鼎的虫表从来没用上（`Redeclaration of global variable 'insects'`）。改名 `sw_insects`，`create()` 里 `insects = sw_insects;` 交给木鼎（nitan170911、wxddym、zjdy 系同修）。HEAD 与工作树各载入一次，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：`feature/food.lpc`、`feature/liquid.lpc` 的 `do_effect()` 由 `void` 改为 `int`，末尾 `return 1`。`drink`/`eat` 命令对 `only_do_effect` 的物品直接返回 `ob->do_effect(me)` 作命令结果，玉蜂蜜（`d/gumu/obj/fengmi.lpc`）、侠客岛猪肉（`pigpart.h`）这些子类本来就返回 int，基类是 void 才对不上。`d/beijing/npc/qianzhenglun.lpc` 的 `mapping count` 与继承来的同名变量冲突，改名 `ask_count`（只在本文件用）。改动的对象和 `pigpart.h` 的 3 个包含者载入无回退。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/duanyun-fu`、`/kungfu/skill/feifeng-whip`、`/kungfu/skill/pangen-cuojiefu`。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/nuoyi`）；`taiji-shengon`→`taiji-shengong`（`taiji-shengong`）；`xuxiang-zhi`→`wuxiang-zhi`（`wuxiang-zhi/wuse`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`jiujin-shengong`→`jiuyin-shengong`（`jiuyin-shengong/perform/zhang`）；`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库目前没有对象设了缺失的武功；三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 16 处、10 个文件：`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`changquana`→`changquan`（4 处）、`tiaji-jian`→`taiji-jian`（2 处）、`shenhuo-shengong`→`shenghuo-shengong`（2 处）、`taiji-shenfong`→`taiji-shengong`（1 处）、`yan-fly`→`yanfly`（1 处）、`zhoangnan-zhi`→`zhongnan-zhi`（1 处）、`jinwu-goufan`→`jinwu-goufa`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## guidao 的 is_killing 参数类型（2026-10-19，KB 06 §7.266）

`d/city/npc/guidao.lpc`（鬼刀王五）的 `ask_me()` 里调用 `is_killing(who)`，而本库 `feature/attack.lpc` 的 `is_killing(string id)` 要的是 id 字符串，驱动报 `Bad type for argument 1 of is_killing ( string vs object )`，整个 NPC 载入不了。改成 `is_killing(who->query("id"))`，与本库别处的调用一致。

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/kungfu/condition/damo_luanqi.lpc`、`/kungfu/condition/damo_shangshen.lpc`、`/kungfu/condition/damo_zheyuan.lpc`共 3 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：3 个函数补上 varargs（调用处少传参数）。修后与 HEAD 逐个物件对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`cross pubu`（穿瀑布）永远回答“你要往哪儿穿？”，瀑布后面的密室进不去。改动：`/d/mingjiao/shanmen.lpc`（1 处）、`/d/tiezhang/hhyuan-3.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/cmds/arch/sameip.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 1 处）。改动：`/cmds/std/watch.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/eventd.lpc`（1 处）、`/adm/daemons/storyd.lpc`（1 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/adm/daemons/network/messaged.lpc`（1 处）、`/adm/daemons/versiond.lpc`（1 处）、`/include/getconfig.h`（1 处）。

## 房间文件结尾的 `replace_program(ROOM);`（2026-10-20，KB 06 §7.100）

3,467 个房间在 `create()` 末尾 `replace_program(ROOM);`：房间一旦在这之前建了闭包（`(: ... :)`）就是 `cannot replace a program with function references, ignored`（扫描里 `d/lingxiao/sroad6.lpc`），没建的则留下一个以后绑闭包就崩的地雷（KB 06 §7.86/§7.100）。本库在 191 库的清扫之后才入库，`scripts/lpc_drop_replace_program.py --apply wlqxcmudlib` 删掉这些整行（只删整行，3,467 行）；继承 `BUILD_ROOM` 却 `replace_program(ROOM)` 的 5 个 `d/hangzhou/shanlu*` 保留（它们加载正常）。抽样 300 个房间 HEAD 与 tree 都通过，回归 0；实测从起点走了几个房间，控制台没有错误。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/arch/blockade.lpc`、`/cmds/arch/recovermud.lpc`。

## `dual` 不带参数：`evaluate_shell()` 对 0 取下标（2026-10-21，KB 06 §7.336）

`dual`（`cmds/arch/dual.lpc`）把参数原样交给 `me->evaluate_shell(arg, flag)`，那里第一件事是 `arg[<1] == ';'`，参数为 0 时报 `Value being indexed is zero.`（`feature/shell.lpc`）；静态扫描只认直接传给 efun 的参数，看不见这种经过 `call_other` 的。命令开头加 `if (!arg) return notify_fail("指令格式 : dual [detail]\n");`（同系 16 个 `dual` 里另外 7 个本来就有这个检查）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 5 条注册（4 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/npc/referee.lpc`（`do_halt`）、`/d/tianlongsi/munitang.lpc`（`do_exit`）、`/d/wudu/huxue2.lpc`（`do_train`）、`/inherit/misc/fboard.lpc`（`do_list`）。最多的函数名：`do_halt` 2 处、`do_exit` 1 处、`do_train` 1 处、`do_list` 1 处。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 17 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；NPC 的称呼和提示里取到两个字而不是一个字。

本库 17 处（12 个文件）：拼名字的赋值 10 处、与汉字常量比较 6 处、`to_chinese()[..]` 1 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/fengling.lpc:134`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/emei/tobebonze.h:40`）；`chk[0..1] == "你"` → `chk[0..0] == "你"`（`/adm/npc/ganjiang.lpc:592`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：2 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 2 处（1 个文件）：`if ((strlen(name) < 4) || (strlen(name) > 12 )) {`（`/adm/npc/luban.lpc:1927`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 1 个文件；`channeld` 同盟 / 门派标题 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 中文名 / 验证码仍按 GBK 取「两字节一字」（2026-10-23，KB 06 §7.373）

`pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1]; pname = pname[0..1];` 在按字符计下标时会取出两个汉字。`scripts/lpc_fix_pname_slice.py` 去掉掩码并把收尾改成 `[0..0]`（`pname`/`pname2`/`sec_name`/`str`/`str1`）。本库 4 处。证明：nt1 生成名长度 2–4；HEAD 常见 3–5。

