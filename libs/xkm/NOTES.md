
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和金庸梦（jym，147）同一血统/同一套 simul_efun 组成——用同样的方式重新实现了 efun::tail()（§6.2）；启动干净。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc（create()/make_body()）里同样的 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限（去掉了遗留的 +=128 字节变异，把 is_chinese() 校验改成逐字符）；给 securityd.lpc 的 get_status() 加上了防重入编译崩溃保护；修复了 quit.lpc 未加保护的 environment(me) 崩溃；修复了 message.lpc 的 tell_room() exc_target=0 崩溃（AGENTS.md §7.12）。jym 里没有的新 bug：get_id() 会无条件为任何 wiz_level>0 的 id 注册 input_to("get_passwdd",...)——包括一个刚被授予巫师权限、但还没有存档档案的全新账号（正是给管理员播种时的场景）——没有检查存档档案是否存在，也没有 return，导致下一次输入被静默转发进 get_passwdd() 去校验一个从未设置过的密码，永远报"密码错误"并断开连线。已修复为在 file_size(存档文件)>=0 时才注册这个早期呼叫（匹配同一函式后面已有的正确检查），并补上缺失的 return。这是原始存档里真实存在的 bug，不是本次管理员播种过程引入的——任何给一个尚未注册的 id 授予巫师权限的真实部署都会碰到。另外发现注册流程比 jym 手足档案多了一个 QQ 号码提示和一道"玩家守则"y/n 确认步骤——已按 AGENTS.md §8.2 直接读取真实的 input_to() 调用链，而不是假设 jym 的确切发送顺序可以照搬。

## 深度功能测试（§10.7，2026-08-05）

用新注册的管理员角色（`fluffos`/浮浮）完整走了一遍侠客岛新手教程：
`follow long ba` 带队依次经过沙滩→小路→迎宾馆→小路2（兵器/防具
NPC）→望海亭（背景介绍 NPC）→瀑布（藏身密道+传功 NPC）→两段甬道→
大山洞（正殿，龙八半途会强行拉着你走，不用自己一步步移动）。全程无
崩溃，食物/饮水条满格（§8.9 不适用）。

**兄弟档案排查**：先看了同源档案 `jym`（147，同一套 simul_efun/adm/
obj 血统）已完成的 §10.7 记录，逐项在 xkm 自己的源码里核实、而不是直
接假设结论可以照搬：
- §8.3a `private nomask command_hook`：xkm 的 `feature/command.lpc`
  本来就是 `nomask int command_hook`，没有 `private`——不适用。
- §8.9 食物/饮水年龄检查错对象：`adm/daemons/logind.lpc` 核实过，
  不适用。
- §7.78 mixin 文件未继承 F_DBASE 就裸调用 set()/query()：
  `inherit/char/char.lpc` 是直接 `inherit F_DBASE`，不是通过某个未继
  承它的 mixin 间接调用——不适用。

**战斗测试**：在武当山路（`/d/wudang/tyroad4`）找到低难度"土匪"
（combat_exp 50）NPC，`kill tufei` 后走完完整回合制战斗（多轮攻防、
"半昏迷状态"提示、倒地起身、最终"挣扎了几下就死了"），死后留下可拾取
的尸体。`score` 确认经验/阅历/属性正常增长，无异常。战斗过程中一次
`kill` 指令触发了 `/cmds/std/kill.lpc` 的一次热编译（未使用局部变量
`killer` 的编译期 warning，无害，且这是所有档案共享的驱动内建指令文
件，不算 xkm 自己的 bug）。

**发现并修复一个此前从未被记录过的新 bug（已写入 AGENTS.md §7.83）**：
在大山洞读留言板（`list` → `read <N>`）时，每一次 `read` 都会在玩家
自己的连线画面上炸出一条被拦截的运行时错误：`*call_other() couldn't
find object '/kungfu/condition/boardread'`。追查后发现
`inherit/misc/bboard.lpc` 的 `do_read()` 本意是"每次读留言给 3 点
chatpts（聊天/灌水积分），但用一个叫 `boardread` 的 10 拍冷却条件把
连续刷分限制住"，可整个 `kungfu/condition/` 目录里唯独没有
`boardread.lpc` 这个条件精灵文件（旁边大约 50 个同类条件精灵，比如
`drunk.lpc`/`sleep.lpc`/`poisoned.lpc`，一个不少，就是漏了这个）。
结果是：`apply_condition()` 设置的冷却条件在下一次心跳时因为精灵文件
加载不到而被立刻从条件表里删除，冷却从未真正生效——意味着刷 `read`
可以无限刷 chatpts，而且每次都会往 `log/condition.err` 里写一条报
错。查看 `work/log/condition.err.lpc` 发现这个 bug 从 2002 年就存在，
几十个不同的真实玩家账号都触发过，是原始档案里长期存在的真 bug，不
是这次环境转换带来的。已仿照最简单的同类条件精灵 `sleep.lpc` 的写法
补上 `kungfu/condition/boardread.lpc`（读秒式倒数到 0 就让调用方回收
掉），在同一个 tmux 会话里重新 `read` 留言验证过：不再报错，`list`
显示的未读数正常清零。

**门派系统**：迎宾馆没有门派接引 NPC，甬道 `/d/xiakedao/yongdao3` 有
"雪山第十三代弟子 大人物"，`ask lama about 雪山` 能问出完整的雪山派
背景介绍，并提示"想来我们雪山吗？先去大轮寺当喇嘛吧"——真正的拜师流
程在大轮寺（另一张地图），这次深挖没有跨图去把整个拜师流程走完，留
作后续深挖的候选项。

**死亡/复活**：按 AGENTS.md §7.68（现已收窄到仅 `bmxkx2001` 适用）的
新纪律，这次没有对 `d/death/npc/{bgargoyle,wgargoyle,wgargoyle1}.lpc`
里的 `if (!ob || !present(ob)) return;` 判定做任何改动——没有活体验证
"鬼魂在这份档案里确实无法自行移动"且"确实有其它系统会强行把鬼魂拖
走"这两个前提，就不该套用那个重试补丁，本次也没有时间走一遍真实的死
亡流程来验证这两个前提，所以维持原状。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 64 处命中，其中含 1 处运行时代码生成模板（write_file() 动态生成新留言板源码的字符串模板里嵌了同样的致命形状，已同步从模板字符串中删除，否则玩家用该功能新建的留言板也会一出生就带病），已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.112 跨库扫描修复（无常 NPC 重连触发重复轮回链）

- **`d/death/npc/{wgargoyle,wgargoyle1,bgargoyle}.lpc` 的 `init()` 无条件调度 `death_stage` call_out 链（AGENTS.md §7.112）**：这三个文件原本都没有任何去重判定——`enable_commands()` 会在同房间内向所有对象重播 `init()`，玩家哪怕只是断线重连一次，也会在原有的 `death_stage`/最终判官对话链之上再叠一条新链，导致重复的判官对白、重复扣血/转生等竞态错误。已仿照同族已修复库（`dtsl`/`dtsl2`/`dtslmud`/`jym`/`xuanjianlu`）的做法，给每个 `init()` 加上按受害者存的 `set_temp("death_stage_active", 1)`/`query_temp(...)` 门槛判定，并在 `death_stage()` 的每一个退出点（角色离场、黑无常"阳人退回"分支、链条走完转生）里 `delete_temp(...)` 清除标记。三个文件形状与 `jym` 版本几乎一致（均无 `final_death_stage` 分支），已用独立驱动干净编译+启动验证，未发现残留 save 数据变化。

## AGENTS.md §7.100 修复（2026-08-19，批次五）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：3176 个房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后
都有这一行多余调用，永久设下"待替换"标记，第一次对该房间对象绑
定闭包就会崩溃。这份档案有两处代码生成模板烤了同一个地雷：自带建
房工具 `clone/misc/roommaker.lpc`，以及帮派堂口建造精灵
`adm/daemons/groupd.lpc`（各自独立的字符串拼接模板）。另外发现 31
个帮派堂口房间源码文件放在 `work/data/group/` 下（真正的 .lpc 源码，
不是存档），扫描脚本默认排除 `data/` 目录（为了保护玩家 .o 存档）
误伤了这批文件——针对这个子目录单独关闭排除，手动补上。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`，
加上两处模板手动摘除字符串拼接片段。`git diff --stat`：3176 files
changed，与预期精确吻合（0 处遗留匹配，全部干净）。

验证：`build-debug` 驱动真实冷启动，端口 40191 正常监听，
`debug.log` 全程干净。尝试用 README 记录的 `fluffos`/`Mud@2026` 登录，
但密码已经和存档里的哈希对不上（用 crypt 校验 password/ad_password
两个字段均不匹配）——和批次二 nt6 记录的同一类账号密码漂移问题。
未触碰玩家存档，也未继续深挖新密码，改为依赖干净冷启动（含失败登
录尝试全程 debug.log 零新增行）作为本次纯机械修复的充分验证证据。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## §7.19 enable_player() reentrancy fix (2026-09-01)

Corpus-wide mechanical fix (AGENTS.md §7.19, Batch F of 6). `feature/command.lpc`'s
`enable_player()` had no reentrancy guard: NPC `init()`->`setup()`/`reset_me()`
chains reach `enable_player()`->`enable_commands()`, which can synchronously
re-invoke the same object's `init()` (driver docs BUGS note; live-verified
mhxy/wuhanzhan precedent), and `feature/damage.lpc`'s `revive()` /
`cmds/std/sleep.lpc`'s `wakeup()` re-invoke `enable_player()` while already
`living()`, ruling out a bare `living()` guard. Fixed with the standard
`in_enable_player_now` true reentrancy flag (mhxy's reference fix). Verified
via single-file `lpcc --batch` PASS.
