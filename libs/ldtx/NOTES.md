# 鹿鼎天下.rar → `ludingtianxia`

- Archive: `鹿鼎天下.rar` (from the 2026-07-29 bulk `mudlib.rar` drop).
  "Century / adm-single" family lineage (custom `securityd.lpc` ACLs,
  master at `/adm/single/master` — same shape as `shiji` (021),
  `shujian2008` (024), `xjcq2000` (027), `xkxz2` (028),
  `xiakexing100` (030)). ES II heritage (`master.c` header: "for ES II
  mudlib... rewritten by Annihilator", further "modified by Xiang for
  XKX").
- **Naming quirk** (AGENTS.md §5.1's "don't trust the name field," a new
  instance of it): the archive is named 鹿鼎天下, but the login banner
  brands the game **雄霸天下『西安站』** ("Xi'an station"), while the
  `quit` message still says "离开了鹿鼎天下" — two different in-game
  names coexist in the shipped source, evidence of a rebrand that wasn't
  applied everywhere. Went with 鹿鼎天下 for the slug (matches the
  archive/what the user is most likely to look for) but documented both
  names in the README.
- Mudlib root in archive: `ldtx/ldj/` (two levels down).
- No shipped config file; reconstructed using `shiji`'s config.fluffos
  (same lineage/master path) as the template.
- Port: **40105**.

## Status: DONE — boots clean, full registration with a real Chinese name verified, playable

## What was fixed

1. **Systemic encoding artifact, not caught by `convert_lib.sh`'s normal
   GB18030→UTF-8 pass**: nearly the entire tree (3903 of ~5960 `.lpc`/`.h`
   files) shipped with doubled `\r\r\n` line endings (CRCRLF, doubled —
   worse than the single-CRCRLF quirk `convert_lib.sh`'s own comments
   already document). This silently broke every subsequent string-literal
   edit (exact-match tooling can't find `\r`-embedded lines). Fixed with a
   blanket `sed -i 's/\r//g'` across every `.lpc`/`.h` file before doing
   any further hand-edits.
2. **§7.1 class, simpler variant**: `adm/single/master.lpc`'s
   `valid_read`/`valid_write` did `if (ob = find_object(SECURITY_D)) ...
   return 0;` — no lazy `load_object()` attempt at all, just permanent
   deny until securityd happens to already be loaded. Real driver boot
   preloads securityd first so this never bit in practice, but it made
   `lpcc_check.sh`'s single-VM compile sweep (which doesn't preload)
   deny-everything (2/5960 pass). Added the standard re-entrancy-guarded
   `load_object(SECURITY_D)` fallback from AGENTS.md §7.1 to both
   functions — jumped to 5793/5960 passing.
3. **§8.1 class**: `adm/simul_efun/chinese.lpc`'s `is_chinese()` (GBK
   byte-range test) and `adm/daemons/logind.lpc`'s `check_legal_name()`
   (byte-oriented length bound 2-10 + `i%2==0` sliding window) — same
   fix pattern as every other lib in this catalog entry. Verified: real
   Chinese name 秦风六 registers correctly end-to-end.
4. `/adm/daemons/network/dns_master` and `/adm/daemons/ftpd` were
   actively preloaded (not already commented out, unlike most other
   libs in this collection) — commented out per the standing no-sockets-
   package policy (§1.3c). Confirmed harmless at runtime: login flow
   prints "网路精灵并没有被载入" (network daemon not loaded) and
   continues normally.
5. Admin seeding (§1.5): registered `fluffos` through the normal flow,
   appended `fluffos (admin)` to `adm/etc/wizlist` (same mechanism as
   the Century family generally — `/` is in `securityd.lpc`'s
   `trusted_write` for `(admin)`). Verified: recompiling `/adm/single/
   master` via `update` succeeds as `fluffos` (shows the driver's
   variable-clear side effect, no ACL denial).

## Known issues, NOT fixed (logged, matching the "content bugs" bar)

167 of 5960 files fail `lpcc_check.sh`'s compile sweep, none of them
core-system files (master/simul_efun/logind/securityd/chinesed all
compile and run correctly). Three observed failure shapes, all isolated
to individual content files:
- A handful of `kungfu/skill/*.lpc` files have a genuinely unterminated
  string literal in the original source (e.g. `qingyi-jian.lpc:11`:
  `"skill_name" : "大侠式,` — missing closing quote before the line
  ends), which then swallows the next line and surfaces as a garbled
  "Illegal character" error further down. Pre-existing author typo, not
  a conversion artifact (confirmed the file decodes as valid UTF-8
  throughout).
- A handful of `clone/misc/*_cloth.lpc` (clothing item) files reference
  the `YEL`/`NOR` ANSI color macros without the header that defines them
  being reachable from that specific file — compile error, item is
  simply unusable in-game.
- A couple of room/NPC files (e.g. `/d/city2/tian_anm`) throw a runtime
  "Bad argument 1 to call_other()" (got int 0) — a null-object reference
  in that room's own logic, likely a stale/removed NPC or item reference
  from the original game's development.

None of these affect the core registration/look/score/quit loop verified
above; logging here rather than auditing all 167 individually.

## Not yet done (out of scope for this pass)

WASM export / GitHub Pages packaging — deferred to a later batch pass.

## 移植修复（2026-08-03，来自姊妹档案 ldtxii 的深度测试）

`ldtxii` 深度功能测试（§10.7）在其 `logind.lpc` 里发现两个 bug，
逐行核对后确认 `ldtx` 这份档案在完全相同的行号上有一字不差的同一
段代码——是共享血统里从未修过的祖传问题，不是 `ldtxii` 自己引入
的。按 AGENTS.md §2.1 的"跨手足档案移植已验证修复"惯例，直接把两
个修复移植了过来：

1. `get_name()` 里紧跟在中文名字设定之前的调试残留
   `printf("%O\n", ob)`（AGENTS.md §7.34）——删除。
2. 食物/饮水满值初始化误读 `ob->query("age")` 而不是
   `user->query("age")`（AGENTS.md §8.9）——已改正。

用一个全新角色（`ldtxdive`）验证：注册流程无调试残留输出，
`score`显示食物/饮水槽创建时即为满值（16/16格），`look`/`score`/
`quit`均正常。重启后 debug.log 里出现的两条报错都是本档案早就记录
过的既有内容缺口（`xiaobao.lpc` 引用不存在的 `/u/rhxlwd/cloth.lpc`
的老问题，以及和 `ldtxii`一样的 `chatroom.lpc`/`/u/mouse/` 缺口），
不是这次改动引入的新问题。未做完整的第二轮深度功能测试（本次是移
植已验证的修复，不是从头深挖这个档案）。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

Century/adm-single 家族（shiji/shujian2008/xjcq2000/xkxz2/xiakexing100），游戏内标题为"雄霸天下『西安站』"。WASM 修复：把 adm/daemons/network/dns_master.lpc 的 startup_udp()/send_udp()/send_shutdown() 里那行 socket_close() 掏空（§7.52 socket 精灵掏空）——这个 WASM 构建下 socket_create()/socket_bind() 是未定义的 efun，导致编译失败，进而破坏了每一个中途呼叫进这个档案的 call_other()，包括每次连线在英文名字提示之前就会跑的 encoding_to_mudlist() 步骤。没有中文名字/宏定义/指令表相关的 bug（is_chinese() 本来就是正确的码点判断）。管理员账号"fluffos"/"Mud@2026"其实早在这份档案更早、WASM 之前的一轮里就已经播种进 adm/etc/wizlist 了（这份档案的 README 里已经提到过一个真实上线过的部署）——已验证既有凭据依然能登录并正确显示 (admin)，不需要新账号（一开始误以为这是 §1.5 那种引导 id 冲突的模式，多加了一个多余的并行账号"fladmin"，后来发现这份档案自己既有的 README 早就记录过可用的 fluffos 凭据，已撤销这个多余的添加）。留下一处真实存在、不阻断的内容缺口未修：d/city/npc/xiaobao.lpc 的 create() 引用了一个不存在的 /u/rhxlwd/cloth.lpc（这个巫师目录在整个档案里根本不存在）——对结果为 0 的物件做 call_other() 会抛出"Bad argument 1 to EFUN call_other()"，但被房间自己的 setup()/reset() 包装函式捕获了，从未传到玩家那里；按"不凭空捏造内容"的先例保持原样（和 ffxymud/jhfy2/jhfy3 的 d/city/sj.lpc 是同一类情况）。完整的注册（选 gb 编码→id→确认→中文名字→密码→确认→天赋选'0'→接受'y'→电子邮件→性别）和 look→score→quit 流程在排版格式化前后都验证过；格式化工具没有引入任何损坏（三类盲点检查都干净）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`WIZ_BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 34 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

之前的 WASM 阶段和 §7.86 扫描都只做过编译检查/浅层注册测试，没有真正玩过。这次用原生驱动（`build-debug/src/driver`）通过 `scripts/tmux_mud.sh` 完整走了一遍。

### 与 `xbtxiii` 的血统关系：确认为"同源但非同支"，不是同一份代码

本次深挖前先核对了 `xbtxiii`（雄霸天下III）——两者游戏内品牌都叫"雄霸天下"，但直接比对 `master.lpc`/`securityd.lpc`/`config.fluffos` 的结构后确认**不是同一份代码**：

- `ldtx` 的 `master file` 配置指向 `/adm/single/master`，档头明确写着"for ES II mudlib... rewritten by Annihilator... modified by Xiang for XKX"；`securd.lpc`（397 行）+ `securityd.lpc`（299 行）两个文件分工。
- `xbtxiii` 的 `master file` 配置指向 `/adm/obj/master`，档头只有一句 `#pragma save_binary`，没有那段 ES II/XKX 血统注释；`securityd.lpc` 是单一 286 行文件，没有配对的 `securd.lpc`。
- 两者的 `connect()` 函式体（包括那句一字不差的中文错误提示"现在有人正在修改使用者连线部份的程式，请待会再来。"）确实相同，说明两者都是更早期"东方故事 ES II"共同祖先的后代（AGENTS.md §11 的 ES II 大家族），但 `xbtxiii` 自己的 NOTES.md 早已记录"README 自称风云衍生分支，但没有发现和 风云3/风云Ⅳ/风云再起Ⅱ/夕阳再现 任何一支共享 master.lpc/securityd.lpc/logind.lpc 结构证据"——`xbtxiii` 走的是完全独立的一支演化路径，`master file` 路径、securityd 拆分方式都不同。

结论：**"雄霸天下"是被至少两个互不相关的具体分支各自沿用的品牌名，不是同一血统的确凿证据**——与本项目反复验证过的"共享品牌名≠共享血统"规律（AGENTS.md §5.1）再添一例。`ldtx` 真正的血统伙伴是 README/NOTES.md 已经记录的 Century/adm-single 家族（`shiji`/`shujian2008`/`xjcq2000`/`xkxz2`/`xiakexing100`）。

### `xbtxiii` 姊妹发现逐项核对（均不适用——不同代码库）

- **§8.12（大写字母属性类别选择菜单，提示大写实际只认小写）**：不适用。`ldtx` 的 `adm/daemons/logind.lpc` 里根本没有 `get_kind()` 这一步——注册流程里没有"12 种类型 A-L"的属性类别选择环节（这份档案的天赋分配是"输入 0-4"数字选择，见 README 已记录的流程），二者的角色创建设计完全不同。
- **§7.95（`fight` 婉拒切磋时 `notify_fail()` 后错误 `return 1`）**：不适用。`cmds/std/fight.lpc` 第 49-50 行本身就是 `notify_fail(...); if (!userp(obj) && !obj->accept_fight(me)) return 0;`——已经是正确的 `return 0`，不是 `xbtxiii` 那种写反的 `return 1`。两份 `fight.lpc` 是独立撰写的不同实现，只是恰好都用同一套 `notify_fail()` 惯例。
- **§7.90（`maximum evaluation cost` 太低，第三种触发形态）**：本档案 `config.fluffos` 已经是 `700000`（本项目常见默认值），但整轮注册→移动→战斗→死亡复活→重连的完整会话里 `debug.log` 全程没有出现任何 `cost limit reached`，说明这份档案自己的内容开销没有撞到这个默认上限，不需要调高。

### 本次新发现并已修复的 bug

- **AGENTS.md §7.11 新增实例（第五+例，第三个互不相关血统）：`adm/simul_efun/file.lpc` 的 `log_file()` 没有调用同文件里现成的 `assure_file()`，导致每次 `update` 指令后都抛出可见的执行时段错误**：`cmds/app/update.lpc` 重新编译任意档案成功后会呼叫 `log_file("nosave/update", ...)` 记录审计日志，而 `log/nosave/` 这个子目录在整份档案里从未存在（`work/log/` 下只有 `buglog`/`backup`/`static` 三个目录）。`log_file()` 本身只是裸 `write_file(LOG_DIR + file, text)`，同一个档案里紧接着定义的 `assure_file()`（会用 `mkdir` 逐级建立缺失目录）从未被呼叫过。全档案共 17 处 `log_file("nosave/...", ...)` 调用命中同一个缺口，包括 `adm/single/master.lpc`/`adm/obj/master.lpc` 的当机记录、`securd.lpc`/`securityd.lpc` 的晋升记录、`adm/daemons/autosaved.lpc` 的自动备份记录，以及几乎所有 `cmds/{app,arch,wiz,std}/*.lpc`（`update`、`rm`、`edit`、`clone`、`cp`、`give`、`drop`、`suicide`、`reboot`、`purge`、`chgkf`、`call`）的操作审计。实测：`update /inherit/room/room` 重新编译**成功**，但紧接着抛出 `*Wrong permissions for opening file /log/nosave/update for append. "No such file or directory"`，玩家/巫师端看不到本该出现的"成功！"确认字样。修复：在 `log_file()` 开头加一行 `assure_file(LOG_DIR + file);`（因为 `assure_file()` 在同一档案里定义在 `log_file()` 之后，还需要一行前向声明 `void assure_file(string file);`，否则整个 `simul_efun`/`master` 编译失败——AGENTS.md §7.11 已有的 `zjmudhell` 实例记录过同样的坑）。重启驱动后重测：`update` 干净显示"成功！"，无任何报错。已追加为 AGENTS.md §7.11 的新确认实例（第三个互不相关的具体血统，同一份 `adm/simul_efun/file.lpc` 工具文件在完全不同代码库里独立复制出现）。
- **AGENTS.md §7.73 新增实例，并发现该 bug 类别一个此前未记录的更严重后果——同一 `create()` 里"后面"的无关语句会被静默跳过**：`d/city/npc/xiaobao.lpc`（韦小宝，这份档案实际的开局房间"客店"里的固定 NPC）的 `create()` 末尾有 `carry_object("/u/rhxlwd/cloth")->wear();`，`/u/rhxlwd/` 这个巫师目录在整份档案里根本不存在。这个缺口此前（WASM 阶段）就已记录，但被误判为"无害，被房间自己的 catch() 接住"——实际追查发现**并没有任何 catch() 接住它**：`d/city/kedian.lpc`（开局客店房间）的 `create()` 用 `setup();` 触发 NPC populate（内部递归调用 `xiaobao.lpc` 的 `create()`），紧接着下一行是 `"/clone/board/kd_b"->foo();`（强制加载本房间的留言板）。因为 `xiaobao` 的 `carry_object(...)->wear()` 抛出未捕获例外，整条调用链一路往外传，`kedian.lpc` 自己的 `create()` 被中途打断，**留言板加载这一行永远不会执行**。实测确认：全新驱动首次开机、第一个连线进入客店的玩家，房间物品列表里完全没有"客店留言板"，`look kdboard`/`post kdboard` 都得到"你要看什么？"；用管理员手动 `update /clone/board/kd_b` 能临时补救（但只对当次开机有效，下次重启又会消失）。修复用标准 §7.73 写法（`object cloth; cloth = carry_object(...); if (cloth) cloth->wear();`）。重启驱动后用全新角色验证：第一次进入客店，房间描述里正确显示"客店留言板(Kdboard) [ 没有任何留言 ]"和"韦小宝"，`post`/`look kdboard` 均正常。顺手对全档案做了一次同类模式的静态扫描（`carry_object("<字面路径>")-><br>方法()`，排除已注释掉的行），另外命中 25 处、15 个档案、引用 8 个不同的缺失路径（其中 11 处指向同一个整体缺失的巫师目录 `/u/csy/kunlun/obj/`），逐一用同样的防御性写法修复，均为机械式、低风险改动。已追加为 AGENTS.md §7.73 的新确认实例。
- **§7.86 复查**：全档案 `inherit BULLETIN_BOARD`/`BBS_BOARD` + 冗余 `replace_program()` 的检测干净（此前已修复的 34 处均已生效，`post` 命令实测正常，无新命中）。

### 完整游玩验证（一次连续会话，原生驱动）

用全新角色 `ldtxqa`（中文名"云飞扬"）走完整套注册流程：`gb` 编码 → 英文 id → 确认 y → 中文名字（无 §7.34 调试残留输出）→ 密码 → 确认密码 → 天赋 0（系统随机）→ 接受 y → 电子邮件 → 性别 m → 进入游戏世界（客店），过程干净无报错。

- **移动**：`kedian`（客店，`no_fight` 生效，`fight`/`kill` 均被正确拒绝）→ `west` 到"北大街" → `south` 到"中央广场"，房间描述、出口、NPC 列表均正常。
- **留言板**：`post kdboard` 打开内建行编辑器，留言成功（"留言完毕。"），`look kdboard` 正确显示"[ 1] kdboard ... 云飞扬(ldtxqa)"，未读数统计准确。
- **战斗与死亡/恢复**：对"中央广场"的"流氓头"（`Liumang tou`）打 `kill`，多回合真实攻防判定正常（命中部位、伤害描述、体力状态提示逐条推进），角色被打倒后出现"你的眼前一黑，接著什么也不知道了...."——此时 `look`/`score` 均返回"什麽？"（指令被封锁），几秒后自动"慢慢地你终于又有了知觉...."恢复行动，`score` 显示"你共死亡：1 次"、"最后一次死于：[流氓头] 之手"，精/气条从满格降到 2/16（惩罚性削减），食物/饮水条未受影响，人物位置未变。这份档案的死亡机制是"原地昏迷→自动苏醒+属性惩罚"，不是分阶段鬼魂/冥界流程，全程一次顺畅完成，不属于 AGENTS.md §7.68 的"present() 守卫吞掉重试"情形（本档案压根没有那种多阶段 `call_out` 鬼魂守卫）。
- **`quit`/重连**：`quit` 显示"欢迎下次再来！"正常退出（因为最后所在的"中央广场"没有设置 `valid_startroom`，`quit.lpc` 正确地没有更新存档点——这是既有代码的正确设计，不是 bug）；重新用同一账号密码登录，正确恢复到之前保存的起始点（HP/食物/饮水延续为退出前的数值），未触发 §8.13 类的巫师二次登录死锁（本账号是普通玩家，未测试；管理员 `fluffos` 账号已在下面单独验证）。
- **管理员权限**：用既有 `fluffos`/`Mud@2026` 账号登录（`adm/etc/wizlist` 里已有的记录，非本次新增），立即显示"目前权限：(admin)"；`update /adm/simul_efun/file` 成功验证 §7.11 修复生效（"重新编译 ... 成功！"，无报错）；`look` 到客店房间物品栏正确显示留言板"[ 1 张留言，1 张未读]"，确认之前玩家角色的留言持久化正常。

全程 `debug.log` 无任何异常记录（唯一出现过的执行时段错误就是本次修复的 §7.11 `nosave` 问题本身，修复前后各测了一遍）。

### 未覆盖

商店/购买、正式门派拜师、邮件系统本轮时间有限未继续深挖；本档案的开局区域是围绕客店/北大街/中央广场展开的城市地图，未继续往更远的地图区域探索。

## §7.100 sweep (2026-08-19): redundant `replace_program(ROOM);` landmine

Same corpus-wide bug as documented at AGENTS.md §7.100: rooms
inheriting `ROOM` (`/inherit/room/room`) had a redundant, harmful
`replace_program(ROOM);` call right after `inherit ROOM;` in `create()`,
setting a permanent "pending replace" flag that crashes the object the
first time anything binds a closure to it. This lib had **1,516 live
occurrences** (survey-ranked #87 of 166 candidates >=100, tied with and
sharing a lineage with `ldtxii`). Fixed with the sweep's binary-mode
script (`fix_710_room.py`); `git diff --numstat` totals (0 insertions,
1516 deletions) match the survey's live-occurrence count exactly. This
lib's `clone/misc/roommaker.lpc` room-building tool never had the
factory-bug variant at all — its generated-room code templates (both
the `mkroom`-style heredoc and the `str +=` string-builder path) never
included a `replace_program(ROOM)` call to begin with. No `work/data/`
room-source false-negative found. Verified via a clean `build-debug`
boot (zero "cannot replace"/"cannot bind" `debug.log` lines, port
40105 listening) plus a live admin login (`fluffos`/`Mud@2026`, GB
encoding selection, `Press Enter to Continue` banner) — entered the
game world normally, `look`/`quit` both worked, `debug.log` stayed
clean throughout. Incidental admin save-timestamp drift from the
spot-check reverted before committing (pre-existing untracked
`ldtxdive.o`/`ldtxqa.o`/`data/board/` save files left untouched, not
part of this change).

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/wgargoyle.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

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

## 深度功能测试（§10.7，2026-08-21）：商店购买 + 门派拜师首次实测

之前几轮测试（§7.86 扫描、2026-08-08 那轮深度测试、§7.100/§7.112/§7.30
扫描）都验证过注册/移动/留言板/战斗死亡复活/`quit`重连，但商店购买和
正式拜师流程一直没有真正跑过（2026-08-08 那轮 NOTES 里"未覆盖"一节明
确记录了这一点）。这次原生驱动（`build-debug/src/driver`）+ 两个并行
telnet 会话（一个测试角色、既有 `fluffos`(admin) 账号）补上这两项，并
用真实 `kill` 指令对"中央广场"的"流氓头"重新走了一遍战斗/死亡/复活流
程（与 2026-08-08 那轮结果一致，无回归）。

### 1. 战斗与死亡复活：复测无回归

新角色 `ldtxwyf`（中文名"石中玉"）对"流氓头"使用真实 `kill` 指令（非
切磋指令），多回合真实攻防判定后被打倒昏迷，`look`/`score` 短暂返回
"什麽？"（指令封锁），随后自动苏醒，`score` 显示"你共死亡：1 次"、
"最后一次死于：[流氓头] 之手"，精/气从满格降到 2/16。全程 `debug.log`
无异常。

### 2. 商店购买：首次实测，通过

用 `admin clone /clone/money/gold` + `give gold to <角色>` 的标准套路
给测试角色注资（一两黄金＝10000 铜板），在开局房间"客店"内向既有的
`d/city/npc/xiaoer.lpc`（店小二，`inherit F_VENDOR`＝`/feature/dealer.lpc`）
执行 `buy huo`，成功买下"火把"（五两白银＝500），扣款后找零"九十五两
白银"（10000-500=9500，换算白银单位正确），物品正确出现在角色物品栏。
`debug.log` 全程无异常。

### 3. 门派拜师：首次实测，发现并修复一个真实的执行时段崩溃（新增 6 个文件）

用 `admin goto`+`summon` 把测试角色传送到少林寺广场（`d/shaolin/guangchang1w`），
对"清为比丘"（`kungfu/class/shaolin/qing-wei.lpc`）执行 `bai qingwei`，
`debug.log` 立即记录一条真实的执行时段崩溃：

```
执行时段错误：*Value being indexed is zero.
程式：/kungfu/class/shaolin/qing-wei.lpc 第 74 行
呼叫来自：/cmds/skill/bai.lpc 的 main() 第 106 行
呼叫来自：/kungfu/class/shaolin/qing-wei.lpc 的 attempt_apprentice() 第 74 行
```

**根因**：`attempt_apprentice(object ob)` 里 `mapping ob_fam = ob->query("family");`
对一个从未拜过师的新角色而言，`query("family")` 返回的是裸 `int 0`
（不是 `mapp()` 检查过的空 `([])`），随后 `if (ob_fam["family_name"] == "少
林派" && ...)` 不经任何 `mapp()` 守卫直接对这个 `int 0` 做下标索引，
触发驱动级"Value being indexed is zero"。这意味着**任何全新角色第一次
在这个 NPC 面前 `bai`，一定崩溃**——门派拜师这个核心玩法在这份档案里
从代码提交以来大概率从未在这个 NPC 身上真正跑通过。

**同一份坏代码的姊妹实例**：全档案 `grep`所有 `attempt_apprentice()`
里出现 `ob_fam[` 下标的 24 个文件，绝大多数（少林/明教/峨嵋各支）已经
用 `if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "...")`
这种"赋值同时判空、`||`短路"的写法正确守卫；但另外 6 个文件是同一处
逻辑的裸下标变体，同样会在全新角色面前崩溃：

- `kungfu/class/shaolin/qing-wei.lpc`（现场实测崩溃确认）
- `kungfu/class/shaolin/qing-wu.lpc`（同一段代码逐字重复）
- `d/quanzhen/npc/qiuchuji.lpc`（丘处机，全真教；`ob_fam["generation"]`
  连 `family_name` 判断都没有，是这 6 个里最先执行到的一行，实测复现）
- `d/quanzhen/npc/mayu.lpc`、`d/quanzhen/obj/mayu.lpc`（马钰，两份重复文件）
- `d/quanzhen/npc/wangchuyi.lpc`（王处一）

修复：统一在下标之前补一个 `mapp(ob_fam) &&` 短路守卫，与本档案其余
安全写法保持同一防御性风格，不改变原有的"同门派、辈分不够"拒绝逻辑。
现场重新用另一个全新角色（`xiaolong`/"小龙女"）对丘处机执行 `bai qiu`
验证：不再崩溃，正确走到下一条资质检查（"六根清静...资质似乎不适合
当道士"，因为膂力/根骨未达 30 的门槛，这是既有的、正常的游戏内拒绝
逻辑，不是 bug）。用 `ldtxwyf` 对清为比丘重新 `bai qingwei` 验证：正
常完成拜师，`score`/`goto` 均显示"少林派第四十一代弟子"称谓，无崩溃。

**顺手修复同一个 `bai.lpc` 里紧邻的另一处已确认会崩溃的括号写反 bug**：
`bai.lpc` 第 56 行原文 `me->query("family/master_id" == "feng qingyang")`
——括号位置写反，实际变成对 `query()` 传入一个恒为 0 的布尔比较结果
（`me->query(0)`），而不是比较查询结果字符串。这条分支只有当"师父一
方先用 `recruit` 指令主动收徒、徒弟后用 `bai` 补礼"这个顺序（而不是
本档案 203 处 `attempt_apprentice()` 里全部采用的"徒弟先 `bai`，NPC
自动 `attempt_apprentice→recruit`"顺序）时才会走到；用 `qiangpo <师
父NPC> to recruit <全新角色>` 强制模拟这个顺序，配合静态追踪
`/feature/dbase.lpc` 的 `query(string prop, int raw)` 实现（`prop`
为 `int 0` 时 `strsrch(prop, '/')` 必然抛"Bad argument 1"）确认这条
分支一旦触发必定崩溃，但由于该分支要求一个真人巫师/门派掌门角色主
动使用 `recruit` 指令，两次现场复现都因为测试脚本自身的时序问题
（角色状态残留、新角色未过 15 分钟存档保护期）没能触发到这一具体路
径本身。鉴于这是与已确认崩溃同一函数、同一提交范围内、语义上明显写
反的逻辑错误（不是内容缺失），且修复风险极低，一并改成
`ob->query("id") == "feng qingyang" || ob->query("name") == "风清扬"`
（`ob` 才是即将成为新师父的一方，语义上也更正确）。这份档案里没有任
何 NPC 叫"风清扬"/"feng qingyang"，所以这条分支本身的实际效果依旧是
空操作，此次修复只消除潜在崩溃，不改变游戏内容。

### 4. 顺手发现并修复的第三个真实崩溃：`d/city/npc/dog.lpc`（小白狗）问候函式参数不匹配

在多次测试过程中 `debug.log` 反复出现：

```
执行时段错误：*Bad argument 1 to EFUN call_other()
Expected: object, string, array,  Got: int(0).
程式：/d/city/npc/dog.lpc 第 58 行
呼叫来自：/d/city/npc/dog.lpc 的 greeting() 第 58 行
```

`init()` 用 `call_out("greeting", 1, ob)` 只传了一个参数（进入客店的
玩家），但 `greeting(object who, object ob)` 的函式签名要两个参数，
第二个 `ob` 因此永远是没绑定的 `int 0`。当 `who->query("gender") ==
"女性"`（即女性角色进客店）时，紧接着 `if (ob->query("per") > 25)`
对这个 `int 0` 做 `call_other()`，必然崩溃——**任何女性角色第一次进
入开局房间"客店"，小白狗的问候 `call_out` 都会崩溃**。用女性角色
`gongsun`（"公孙绿萼"）现场复现确认。修复：补 `objectp(ob) &&` 守卫。
因为 `call_out` 本身的参数缺口没有配套的"礼物物件"创建逻辑（很可能
是原作者裁剪掉的半成品功能，不是这次改动引入的），修复后女性角色进
客店时这条"亲热"分支会被安全跳过而不是崩溃，符合"不凭空捏造缺失内
容，只消除崩溃"的既定尺度；用另一个女性角色重新验证：干净无报错。

### 标准巡检结果

- §7.90（eval-cost）：`config.fluffos` 现为 5000000，全程无
  `cost limit reached`。
- §7.100（`replace_program(ROOM)`）：已在 2026-08-19 扫描修复，本轮
  未见新增实例。
- §7.111（`standard_trace()` 对 `error["object"]==0` 无守护调用
  `file_name()`）：**本轮新发现，`adm/single/master.lpc` 第 197 行
  是未修复的裸调用形态**，已修复为
  `objectp(error["object"]) ? file_name(error["object"]) : "(driver)"`。
- §7.112（`death_stage()` 重入守卫）：`d/death/npc/bgargoyle.lpc`、
  `d/death/wgargoyle.lpc`、`d/death/npc/wgargoyle.lpc`、
  `d/shaolin/npc/yu-zu2.lpc` 四个含 `death_stage` call_out 链的文件逐
  一核对，所有出口分支均正确清理 `death_stage_active` 标记，干净。
- §7.79（`addn()` 两参数变体）：全档案无 `addn()` 调用，不适用。
- §7.108（重新连线指令封锁）：`clone/user/user.lpc` 的 `reconnect()`
  已含 `enable_commands()`，早前已修复，本轮多次强制断线重连复测均正常。
- §7.30（`feature/skill.lpc` 未初始化 mapping 存取器）：已在 2026-08-20
  扫描修复，4 处存取器均已带 `mapp(x) ? x : ([])` 守卫，符合要求。
- 4 个"本轮测试后期全库复查"具体形态（`combatd.lpc` 的 `bounce` 除零、
  `chacha.lpc` 死亡重入泄漏、`natured.lpc` 的僵尸物件误判、`go.lpc` 的
  `exit[arg]` 越界腐化）：均不适用——`combatd.lpc` 无 `bounce`、全档
  案无 `chacha.lpc`、`natured.lpc` 无对应的 `destruct(ob[i])` 写法、
  `go.lpc` 无 `sizeof(exit[arg]) - 2` 写法。

### 未覆盖

邮件系统、其余城市外的更远地图区域（大理/雪山/明教/桃花岛等支线内容）
本轮仍未深入探索；商店/拜师验证仅覆盖各一个代表性 NPC（店小二、清为
比丘/丘处机），未逐一走遍全档案数十个门派/商人 NPC。

## 深度功能测试（§10.7，2026-08-24）：邮件系统 + 大理/雪山/明教/桃花岛地图补测

这次补上上一轮明确标记的两项未覆盖内容：玩家间邮件系统、开局城市以外
的四个支线地图区域。原生驱动（`build-debug/src/driver`）+ 全新 Python
socket 脚本（`scripts/mudclient.py`，规避 tmux 多字节传输失真的已知
误报模式）实测。

### 1. `cmds/skill/apprentice.lpc` 的 §7.117 姊妹文件缺口（真实崩溃，已修复）

先按任务清单顺手复查 `bai`/`apprentice` 拜师指令族：`cmds/skill/
bai.lpc` 的 §7.117 类"背叛师门"判断已在 2026-08-21 那轮修好（`ob->
query("family")` 前有 `mapp()` 守卫），`cmds/skill/apprentice.lpc`
是同目录下几乎逐字重复的姊妹文件（同一段 `main()`），但第 56 行仍是
未修的原始写法：

```
if (((string)me->query("family/master_id" == "feng qingyang")) || ((string)me->query("family/master_name" == "风清扬"))) {
```

括号写反（`me->query("family/master_id" == ...)`，实际是对 `query()`
传入一个恒为 0/1 的布尔比较结果），与 2026-08-21 那轮在 `bai.lpc` 里
发现并修复的同一个 bug 一字不差，只是那一轮的修复没有同步应用到这个
姊妹文件——与 AGENTS.md §7.117 记录的 `sjshv150` "姊妹文件漏改"缺口是
同一类问题。按同样写法修复：

```
if (((string)ob->query("id") == "feng qingyang") || ((string)ob->query("name") == "风清扬")) {
```

`lpcc_check.sh` 编译确认 `/cmds/skill/apprentice` 通过（本档案 5960
个文件里既有的 148 个失败与本次改动无关，改动前后失败总数不变）。

### 2. 邮件系统：首次实测，功能完整，未发现 bug

`clone/misc/mailbox.lpc`（信箱道具，`mail`/`forward`/`from`/
`readmail`/`discard` 五个指令）在 `adm/daemons/logind.lpc` 第 731-732
行每次登入都会自动 `new()` 一份塞进玩家物品栏（含离线玩家的"有你的
信哟"到站提醒、`new_mail` 标记），是真实可达的核心功能，不是需要 NPC
额外授予的隐藏内容。

用两个全新角色实测端到端流程：`ldtxmt`（田伯光，在线）对离线的
`ldtxml`（岳灵珊）执行 `mail ldtxml`，标题"问候一下"，正文通过内建
行编辑器（`~q`/`.`/`~e` 语义与留言板编辑器一致）输入后选择不留副本，
返回"Ok."确认发送成功（`send_mail()` 内部用 `FINGER_D->
acquire_login_ob()` 找到收件人的登入档，因为对方离线所以走 `new
(MAILBOX_OB)` 建立信箱、写信、`destruct()` 释放这条路径）。之后用
`ldtxml` 重新登入，`from` 正确显示 1 封未读信件（寄信人"田伯光
(ldtxmt)"），`readmail 1` 正确显示标题、寄信人、正文全文，编码无损、
无乱码（用裸 socket 脚本交叉验证过，排除 tmux 多字节传输失真的已知
误报模式）。全程 `debug.log` 无任何异常。未逐一测试 `forward`/
`discard`，但 `receive_mail()`/`send_mail()`/`do_read()` 这条端到端
主路径干净可用，判定为功能完整、无需修复的既有内容。

### 3. 远地图区域：大理/雪山/明教/桃花岛，发现并修复一个真实的、几乎
必现的执行时段崩溃

用既有 `fluffos`(admin) 账号 `goto` 四个区域各自的入口房间（`/d/dali/
yamen`衙门、`/d/xueshan/shanmen`雪山寺山门、`/d/mingjiao/shanmen`明
教山门、`/d/taohua/damen`桃花山庄正门），逐一 `look` 并各走一两步验
证出口，四个区域均正常加载、出口指向正确、无断链。

但在明教山门 `east` 走进下一个房间时，`debug.log` 立即记录两条真实
崩溃：

```
执行时段错误：*Value being indexed is zero.
程式：/kungfu/class/mingjiao/weiyixiao.lpc 第 6 行
呼叫来自：/kungfu/class/mingjiao/weiyixiao.lpc 的 greeting() 第 6 行

执行时段错误：*Value being indexed is zero.
程式：/d/mingjiao/npc/chengchaofeng.lpc 第 6 行
呼叫来自：/d/mingjiao/npc/chengchaofeng.lpc 的 greeting() 第 6 行
```

**根因**：明教各级 NPC（法王级用 `fawang.h`，坛主/香主级用 `tanzhu.h`
/`tangzhu.h`/`zhangqishi.h`/`menzhu.h` 等）都在文件末尾 `#include
"mingjiao.h"`，这个共享头文件定义的 `greeting(object me, object ob)`
在玩家走近时由 `call_out` 触发，里面直接对 `ob->query("party")` 的返
回值做下标：

```
if ( ob->query("party")["party_name"] == HIG "明教" NOR )
```

任何从未加入过帮会/门派"party"的角色，`query("party")` 返回裸 `int
0`（不是空 `([])`），对 `int 0` 做 `["party_name"]` 下标必然触发驱动
级"Value being indexed is zero"——这意味着**任何普通新角色第一次走
近任意一个明教 NPC 都会触发这个崩溃**（本档案的门派"party"系统与
"family"拜师是两套独立的属性，绝大多数角色终身都不会有 `party`）。
这个头文件在整份档案里有两份byte-identical 拷贝
（`kungfu/class/mingjiao/mingjiao.h` 与 `d/mingjiao/npc/mingjiao.h`），
通过 `fawang.h`/`shizhe.h`/`menzhu.h`/`zhangqishi.h`/`tanzhu.h`/
`tangzhu.h` 六个中间头文件被 15+ 个明教 NPC 文件间接引入（青翼蝠王韦
一笑、青龙坛主程嘲风等），覆盖面很广。

修复：在下标前补 `mapp()` 守卫（两份拷贝同步修复）：

```
mapping party;
if ( environment(ob) != environment(me) ) return;
if ( !mapp(party = ob->query("party")) ) return;
if ( party["party_name"] == HIG "明教" NOR ) {
  if ( party["level"] < me->query("level"))
    message_vision(..., me, ob );
}
```

现场用一个刚注册、从未加入任何门派的角色重新走进明教山门并 `east`
穿过程嘲风所在的房间验证：不再崩溃，`debug.log` 全程干净（只有既有
的、与本次改动无关的启动期 `nosave` 声明警告）。

顺带发现 `zhangqishi.h`/`tangzhu.h`（间接经由 `mingjiao.h`）里已经
存在一个**编译期**失败（`HIG "明教" NOR` 这种宏与中文字符串字面量相
邻拼接触发 `unexpected L_STRING` 语法错误），在本次改动前后都存在、
不受影响——用 `git stash` 交叉核实过修复前该错误就已独立出现在
`zhangqishi.h`（`yanyuan.lpc`/`tangyang.lpc`/`wensong.lpc` 等）里，
是与本次运行时崩溃无关的既有内容缺口（148 个既有编译失败之一），未
处理。

### 标准巡检

- `lpcc_check.sh` 全库编译：`total=5960 pass=5812 fail=148`，与本档
  案既有基线完全一致，本次两处改动未引入新的编译失败、也未修掉任何
  既有失败（`apprentice.lpc`/`mingjiao.h` 之前就在能编译的那 5812 个
  里）。
- 四个区域走查全程 `debug.log` 除上述明教崩溃外无其它异常；测试用角
  色存档（`ldtxml`/`ldtxmt`/`ldtxgn`/`ldtxvf`）及产生的 `data/mail/`
  目录已清理，`fluffos.o` 的巡检时间戳漂移已还原。
