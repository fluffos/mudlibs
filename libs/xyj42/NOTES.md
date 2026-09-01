
## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一批里的西游记4.2.rar 是这份档案单纯换行符不同的重复版本（文件树完全一样，每个档案的差异只是 CRLF 对 LF）——只处理了一次，这个 .rar 算作重复，不算独立条目。没有和任何既有档案匹配上 master 哈希。启动干净，不需要任何修复。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc 的 make_body() 里因为多余 seteuid(getuid()) 而把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限；给 securityd.lpc 的 get_status() 加上了防御性保护。另外还发现并修复了 adm/daemons/combatd.lpc 里一个真正的编译阻断问题：一个 switch(random(4)) 代码块里真正的 case 标签全被注释掉了，只剩下一个裸的 default:——这在这个驱动下是非法的（switch 至少要有一个真正的 case，不能只有 default），导致整个档案编译失败，破坏了每一条和战斗相关的代码路径（而且是静默失败，因为错误只在真正有东西调用 combatd 时才会第一次显现）。已把这个 switch 换成一个普通代码块，因为那些被注释掉的 case 本来就从未真正分支过。注册到进入游戏世界、look/score、以及 quit 都已干净验证，没有残留的时序抖动；注意这个血统是先问电子邮件再问性别，和某些手足血统的顺序相反——要读真实的 input_to() 呼叫链，不要假设顺序能照抄。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 24 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 239 live occurrences deleted: 238 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant). 2 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, port 40203 listening, zero new "cannot replace"/"cannot bind" debug.log lines.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（§10.7 round two，2026-08-27）

用 `build-debug` 驱动完整跑了一次连续的 §10.7 深度游玩测试（单次会话，
Python 原始 socket 脚本），管理员账号种子为 `fluffos` / `Mud@2026`
（`adm/etc/wizlist` 里原本就列着 `fluffos (admin)`，但此前从未真正注册过，
`data/login/f/`、`data/user/f/` 都是空的）——用标准密码注册后确认
`(admin)` 权限即时生效（`目前权限：(admin)`，score 显示【巫师】标记），
密码策略（最短 5 字元）接受这组密码。测试角色：中文名"悟空侠"，男性，
登入 id `fluffos`。

覆盖流程：注册 → look/score/i/hp → 用 `call` 指令临时提高
`combat_exp` 后向灵台方寸山（`d/lingtai/`）二代首徒广筠子拜师成功
（`bai guang`，头衔即时变为"方寸山三星洞第三代弟子"）→ `learn ... from
... with ...`（潜能耗尽时正确报"太累了"并如实扣光剩余精神，
未耗尽时正确 `improve_skill`）→ 用 `clone`+`call set_amount()`
换取货币后在南城客栈跟店小二 `buy`/`eat`/`drink`，金额、负重、
食物/饮水数值均正确更新 → 在留言板 `post`/`read`/`discard`（用内建
的 `.` 结束输入）全部正常，无崩溃 → 与"扫地小童"战斗，命中/闪避/
伤害叙述、`wimpy` 自动脱离战斗都正确触发（脱离触发原因是我自己测试
学艺把"神"值耗到 wimpy 阈值以下，不是 bug，是设计好的双阈值——气或神
低于 wimpy 百分比都会 flee）→ `quit`（`debug.log` 未见任何非 warning
的报错）→ 两次真实等待间隔后重新连线两次，角色状态（头衔、门派、
金钱、道具、attribute）都完整保留，且用第二个临时测试角色验证跨连线
`tell` 双向都能送达对方（本项因两个角色 `mud_age` 都 < 20000 秒被
`block_tell.h` 的新手反滥用机制拦下——核对原始档案字节确认这条
"注册未满约 5.5 小时禁用 tell/say/whisper/reply/emote" 的限制是
1998 年原作者写死在 `cmds/std/block_tell.h` 里的，连巫师也不例外，
不是 WASM 转换或本次测试引入的 bug，是原始设计）。

**标准跨库 bug 形状全数系统性核对（§4.3/§4.4/§7.11/§7.30/§7.80/
§7.86/§7.100/§7.103/§7.112/§7.118/§7.121~§7.153）：均未在本档案命中
新实例。** `securityd.lpc`/`combatd.lpc` 的既有修复（见上面几节）未
回归；`log_file()` 的写入目标目录（`ALLCONT`/`USAGE`/`FILES`）此前
就已存在，未见 §7.11 形状；`set_living_name()` 只在 `enable_player()`
里调用一次（`std/char.lpc::setup()`），reconnect 复用同一个从未
destruct 的活体对象（`obj/user.lpc::reconnect()` 只是重挂
`enable_commands()`），不是"克隆新对象"模式，没有 §7.150/§7.152 的
适用空间；`std/room/hockshop.lpc`/`d/city/sm-room.lpc` 的 `do_list()`
用 `goods[name[i]]` 正确按元素索引，没有 §7.151 的整个 key 数组当索引
用的写法。

**发现并修复：6 个仍是原始 GBK 字节、从未转码的可达文本文件**（和
AGENTS.md §1 記載的 WASM 转码遗漏是同一类问题，只是这次是靠 §10.7 深
度游玩才碰到，不是靠整树 UTF-8 扫描的常规验收）：

- `doc/help/oldhelp/{weapon,guild,taoist}`——虽然没有被任何现存
  `doc/help/topics` 菜单链接到，但 `cmds/usr/help.lpc` 的话题查找是
  裸 `file_size(HELP_DIR + arg)`，只要玩家真的打 `help
  oldhelp/weapon` 这种路径就能读到，实测过（`help oldhelp/weapon`）
  之前会整页乱码。
- `d/ourhome/honglou/poem/{poem74,poem175,poem228}`——`d/ourhome/
  honglou/yard2.lpc` 的猜诗小游戏用 `random(POEMS)` 随机抽一首，这
  三首命中率不算低，玩家迟早会撞上乱码。

全部 6 个文件用 `iconv -f GB18030 -t UTF-8` 转码，转码前后逐字确认是
通顺的古文/说明文字（含裴迪《送崔九》、高适《燕歌行》《送李少府贬峡
中王少府贬长沙》三首唐诗）；文中出现的"□"字符是原文件本来就有的
（`raw/` 归档里字节一致），`yard2.lpc:217` 甚至专门用
`sscanf(poem[index], "%*s□")` 把"□"当成诗谜里特意留白的标记字符处理，
所以刻意保留，没有猜测性地替换成任何字。`doc/help.old/`
（`hints-freehero`、以及重复的 `oldhelp/{weapon,guild,taoist}`）
确认代码里完全没有引用（不是 `help_search_path`/`DEFAULT_SEARCH_PATHS`
的一部分），是打包进档案但从不会被读到的备份快照，本次不处理。
`d/obj/books-nonskill/ALL`、`d/temp/d_obj0610.tar`、`work/driver`、
`adm/tmp/swapfile.*`、`log/log`、`d/kaifeng/npc/bei.c.swp` 这些
UTF-8 解码失败的文件逐一确认是二进制/运行期产物（tar 包、vim 交换
文件、日志、driver 可执行文件残留），不是文本内容，不需要处理。

**观察但未动手改的可疑点**（不确定是不是 bug，留给以后判断）：
`feature/edit.lpc::input_line()` 提示"使用内建列编辑器用
'~e'"，但 `~e` 分支是空代码块 `{}`——不追加这一行到缓冲区，也不启动
任何编辑器，只是静默地继续等下一行输入，跟没打这个命令效果一样。
这是发留言、发信等所有走 `F_EDIT` 的地方共用的框架代码，如果这确实
是个从未补完的功能（而不是本来就该是空操作的占位符），值得以后专门
查一次；没有直接改，因为不确定"内建列编辑器"原本应该长什么样，属于
猜测性实现的范畴，超出本次程式 bug 修复的范围。

**留给未来检查同源库（xyj2006n/xyj2006zzzhx/xyj451/xyj/xyjjqzl）的
线索**：既然 `doc/help/oldhelp/` 这种"没被任何菜单链接、但 help
指令仍然裸路径可达"的残留旧帮助文件在本档案里就藏着 3 个未转码文件，
和"随机抽文本"式小游戏（诗词、灯谜等）用到的独立数据文件一样容易被
整树扫描漏掉（因为只有真正随机抽中或真的打对隐藏路径才会触发），这
两类目录建议在这几个手足库里也各自扫一遍。

清理：测试用的临时小号 `ceshiwo`（仅用于验证跨连线 `tell`）的存档
已在提交前删除；只保留种子管理员账号 `fluffos`（中文名"悟空侠"，
已加入灵台方寸山三星洞门下，测试用的技能/金钱/门派状态原样保留，
作为本次测试的存证）。


## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()` (via the
shared `std/char.lpc` `setup()` chain), and `enable_commands()` is only
safe to call from `create()` -- calling it again on an object already
`living()` makes the driver re-invoke that same object's `init()` as a
side effect, which recursed back into `enable_player()` on the same call
stack until "Too deep recursion" aborted the boot on a room's first-ever
visit. Fixed with a true reentrancy flag (`in_enable_player_now`, set at
entry, cleared before every return), NOT a `living()`-gated guard --
`disable_player()` in the same file legitimately re-calls
`enable_commands()` while already `living()` (sleep/wakeup via
`cmds/std/sleep.lpc`, revive via `feature/damage.lpc`), which a
`living()` guard would silently break. Verified via `lpcc --batch`
single-file compile check (PASS). Part of the corpus-wide §7.19 sweep
(Batch C).
