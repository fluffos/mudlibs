
## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记2006（AKAI Studio 出品的、西游记/ES II 家族的 Tomud 品牌分支）。需要在正常的 id/密码流程之前先完成一次自定义的客户端版本握手：服务器在横幅之后发送的第一行是裸的 'version ' 提示，期待字面回传 '2060'（Tomud/笑傲江湖客户端的自动应答）；任何其它第一行回复都会得到"your client isn't Tomud..."并立刻断线——这不是 bug，任何测试客户端只需要把 '2060' 当作第一行发送即可。WASM 修复了 5 个 bug：（1）四处绝对路径尖括号 #include 在这个驱动的 include 目录规则下永远解析不了，尽管目标档案确实存在（d/obj/misc/jitan.h 的 </d/city/misc/banned.h>，d/obj/books-nonskill/book-qujing.lpc 的 </d/qujing/obstacle.h>，加上 d/qujing/wudidong/monk1.lpc 和 u/vikee/dntg10/sky/tongmingdian.lpc）——已改成引号写法。（2）标准的 §6.6 convertd.lpc 希腊字母/符号表反斜杠错字（'a\",' 应为 'a",'），共 45 处，在真正生效的 adm/daemons/convertd.lpc 和一份未被引用的死代码副本 daemons/convertd.lpc 里都有（两份都做了修复，保持树内一致）。（3）adm/simul_efun/message.lpc 的 tell_room() 把一个未设置的裸 varargs 参数 'exclude' 直接转发进 message() 第 4 个参数（§7.12），导致第一次只带 2 个参数呼叫 tell_room()（某个预加载房间自己的心跳/sounding()）就报"Bad argument 4 to EFUN message()"崩溃——已用 'exclude || ({})' 修复。（4）两个原始批量 GBK→UTF8 转换那一遍漏掉的残留原始 GBK 字节内容档案（d/sea/npc/beast1.lpc、d/obj/quest/shuijingqiu.lpc）——已用 iconv -c -f GB18030 -t UTF-8 重新转换（用 -c 丢弃了少量真正损坏的尾部字节，只是外观内容的轻微损失）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（securityd.lpc 真的会在开机时读取 WIZLIST）。注册流程在一次连续的 WASM 客户端会话里完整验证过：版本握手（2060）→new→英文 id→中文名字→管理员密码+确认→登录密码+确认→电子邮件→性别（m/f）→属性分配菜单（9 接受默认值，y 确认）→在南城客栈进入游戏世界，带完整房间描述，look/score 都干净，quit 被游戏自身"新账号首次存档前需游玩满 1 小时"的规则正确拦下（不是 bug）。管理员权限已直接通过登录时"目前权限：(admin)"确认。LPC 格式化工具对全部 9264 多个档案运行（写入 9118 个，9 个转档之前就存在的未结束字符串/文本块内容错误未做格式化，137 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中；case 标签带尾随注释的盲点找到了几处命中（combatd.lpc 3 份副本、ftpd.lpc 3 份副本），但逐一 diff 复核确认格式化工具正确保留了后面的每一条语句。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。追加修复：scripts/scan_known_bugs.py（新写的静态扫描工具）标记出真正生效的 adm/daemons/logind.lpc 的 check_legal_name() 仍带有标准 §8.1 的 i%2 奇偶门槛加 [i..<0] 后缀切片写法（这里之所以无害，只是因为这个家族的 is_chinese() 只检查第一个字符，但还是改成了标准的逐码点写法）以及 6 处 is_killing(me) 呼叫点（§7.50），分布在 daemon/class/*.lpc 的 kungfu 技能档案和 lestat/old/roar.lpc 里——已改成 is_killing(me->query("id"))。logind.lpc 有 5 份死代码副本（www/relative/、u/canoe/、u/canoe/program/、u/vikee/、daemons/）依然显示奇偶门槛模式，但从未被 LOGIN_D 加载，保持原样。httpd.lpc/ftpd.lpc/dns_master.lpc 不在真正生效的预加载列表里（休眠状态，只能通过巫师手动加载触达）——没有掏空，标记为已知的潜伏风险。修复后重新验证干净。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 36 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 235 live occurrences deleted: 234 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant, same shape as near-identical sibling `xyj2006zzzhx`). 6 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect showing the real login banner on port 40157.

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

## Deep functional test (round two, 2026-08-27)

First full §10.7 round-two live playthrough of this lib (previous work
on it was WASM-onboarding + mechanical corpus sweeps only, never a
continuous played session). Booted `~/src/fluffos/build-debug/src/driver
config.fluffos` natively on port 40157 and drove it with raw Python
socket scripts (client sends the literal `2060` version-handshake line
first, per this lib's own Tomud-client-detection gate — confirmed not a
bug, see the WASM summary above).

**Admin account had to be re-seeded live.** `adm/etc/wizlist` already
listed `fluffos (admin)`, but no corresponding save file
(`data/{login,user}/f/fluffos.o`) existed on disk — the account was
never actually registered through the login flow, only added to the
wizlist text file, so a login attempt as `fluffos` got "没有这个玩家"
(no such player). Registered it live: English id `fluffos`, Chinese
name `管理员`, admin/management password `Mud@2026` (the project's
standard password IS accepted for this field), login password
`Play2026x` (the login password is REQUIRED to differ from the admin
password — the registration flow rejects a login password equal to the
admin password with "您的登陆密码不能和管理密码一样"). Confirmed
`(admin)` privilege via the login banner. This is now a real, working
seeded admin account (previously only a wizlist-only phantom entry).

**Bugs found and fixed (2, both genuine programming bugs — missing
guards causing real crashes, not content/design):**

1. **`adm/simul_efun/file.lpc`'s `log_file()` writes into
   `/log/nosave/`, a directory this archive never shipped, with no
   `assure_file()` guard — crashing every wizard `call`/`clone`/`purge`/
   `purgehouse`/`xpass`/`superpass` command AND the player-facing
   `suicide -f` account-deletion command the welcome banner itself
   advertises** (AGENTS.md §7.11, same shape as the `xajhxo`/
   `nitan_ceshi` instances). Reproduced live: admin `call
   ceshiwyz->add("money",1000)` (a normal wizard debug command) threw an
   uncaught `执行时段错误：*Wrong permissions for opening file
   /log/nosave/CALL_PLAYER for append. "No such file or directory"`
   straight to the admin's screen, aborting the whole `call` before the
   requested side effect ran. Since `cmds/usr/suicide.lpc`'s real
   account-deletion path (`slow_suicide()`) calls the identical
   `log_file("nosave/SUICIDE", ...)` line BEFORE any of the actual
   deletion logic, every real `suicide -f` on this lib would have hit
   the same uncaught error and aborted before deleting anything —
   despite the rules banner telling players to use exactly this command
   to clean up unused accounts. This file already carries its own
   `assure_file(string file)` helper (mkdir-p's every path component),
   just never wired into `log_file()`, and defined textually AFTER
   `log_file()` in the same file (needs a forward declaration on this
   compiler). **Fix**:
   ```lpc
   void assure_file(string file);          // added forward decl

   void log_file(string file, string text) {
     assure_file(LOG_DIR + file);          // added guard
     write_file(LOG_DIR + file, text);
   }
   ```
   Verified live post-fix: the identical `call` command now completes
   cleanly (`/obj/user#206 ("云游生")->add("money", 1000) = 1000`, no
   error), and `/log/nosave/CALL_PLAYER` now exists with the expected
   audit-log line. This is the project-wide simul_efun `log_file()`, so
   the fix transparently covers every one of the ~20 call sites across
   `cmds/wiz/call.lpc`, `cmds/wiz/clone.lpc`, `cmds/arch/purge.lpc`,
   `cmds/arch/purgehouse.lpc`, `cmds/adm/xpass.lpc`,
   `cmds/adm/superpass.lpc`, `cmds/usr/suicide.lpc`, and others that
   write into `nosave/...` or other never-shipped log subdirectories.

2. **`adm/obj/master.lpc`'s `log_error()` broadcasts every plain compile
   WARNING (not just genuine errors) straight to any connected player's
   screen** (AGENTS.md §7.103, exact same shape/fix as `zzfy3`'s own
   instance — this lib's own `master.lpc` still had the unguarded
   original). Reproduced live: registering a fresh character and typing
   ordinary early commands (`look`/`score`/`i`) each triggered several
   `编译时段错误：...warning: Unused local variable 'x'`-style dumps as
   the corresponding command file (`cmds/std/look.lpc`,
   `cmds/std/score.lpc`, `cmds/usr/inventory.lpc`) got lazily compiled
   for the first time that boot. **Fix**: `if (this_player(1)) ...` →
   `if (this_player(1) && strsrch(message, "warning:") == -1) ...`,
   identical to the established corpus fix. Verified live: post-fix, the
   same register→look→score→i sequence produced zero warning dumps.

**Cross-cutting pattern sweep** (all the standing AGENTS.md patterns
listed in the round-two task brief, checked via targeted grep against
`work/`, excluding the already-documented dead-code trees `daemons/`,
`www/relative/`, `u/canoe/`, `u/vikee/`): §4.3 (no `log_file()` call
site has "static" in its literal path argument), §4.4 (no remaining
non-UTF-8 byte sequences in any `.lpc` file — the two known post-WASM
GBK stragglers were already reconverted per the summary above), §7.86/
§7.100 (already swept corpus-wide, re-confirmed no live residual
`replace_program()`-on-top-of-`inherit` hits), §7.121 (no `int`-typed
field/parameter assigned a bare `0.xx` float literal), §7.123 (no
column-zero bare `IDENT = (\[|\{` file-scope statement outside a
function), §7.126 (no `load_object()`/`new()` call fed a string pulled
from a `dbase` mapping — this lib's saved data uses literal, already-
`.lpc`-safe paths, not a macro-placeholder area engine), §7.129
(already fixed at WASM-onboarding time — `exclude || ({})` guard
confirmed still present in the live `adm/simul_efun/message.lpc`),
§7.131/§7.152 (`find_living`/`find_player` work correctly — this lib
DOES call `set_living_name()`, confirmed live via a cross-connection
`tell` reaching the test character both before and after a reconnect),
§7.133 (`net_dead()` is defined and reachable — `obj/user.lpc`/
`obj/user1.lpc`/`obj/login.lpc` all define it directly, not a classic-
driver `remove_interactive()`-on-master shape), §7.148 (no parameter
named a reserved keyword like `nosave`), §7.153 (`feature/more.lpc`'s
pagination `switch` correctly covers `"b"`/`"q"`/default with no
missing `else`; confirmed live via a real multi-page `help menpai` — `q`
correctly aborted mid-page). No new instances found for any of these.

**Live playthrough** (real Chinese-named test character `云游生`
/`Ceshiwyz`, deleted before commit — only the seeded admin account
remains): version handshake → `new` → English id (letters only, 3-8
chars, no digits — confirmed by trial) → Chinese name (2-6 Chinese
characters) → admin password → confirm → login password (must differ
from admin password) → confirm → email → gender → stat-allocation menu
(`9`/`y` for defaults) → arrived at 南城客栈 with a full room
description; `look`/`score`/`i` all clean. Skill acquisition: the
starting-room NPC 阿凯哥哥 (Akaigege) grants one full free skill set via
`ask akaigege about <menpai-keyword>` (e.g. `fangcun`), gated by a
`yudian/skills == "got"` flag that correctly blocks a second grant
("你不是已经要过功夫了吗？") — `skills` correctly showed all 13 granted
skills afterward, `score` showed the resulting attribute increases.
Safe-sparring mechanism: `fight <npc>` (documented in `help fight` as
"点到为止，不会真的受伤") — used against 疥顶小僧 in 朱雀大街, fought to
a clean loss (`这场比试算我输了，佩服，佩服！`), left "受伤" (wounded, a
recoverable condition) but alive and not ejected from the room. Shop:
`list`/`buy` at 南城客栈 dispatch correctly — `list` shows the real
priced inventory, `buy huasheng from xiao er` on a broke fresh character
correctly returns "你的钱不够" rather than silently no-op'ing or
crashing (no §7.143/§7.151 shape found); currency here is physical
money-objects (`gold_money`/`silver_money`/`coin_money` carried in
inventory, not a simple int stat), so a full paid purchase wasn't
exercised live. Board: `read board` on the (empty) 南城客栈留言板
correctly reports no messages, no crash.

**Quit/reconnect**: the "new account must be connected 1+ hour before
it can be saved" gate (`cmds/usr/quit.lpc`, `time() -
birthday < 3600`) is confirmed intentional design (also documented at
WASM-onboarding time) — bypassed for testing purposes only by editing
the test character's own `birthday` field backward in its `.o` save
file while the driver was stopped (never done to the real admin
account). With that bypassed, did TWO full quit→reconnect cycles:
`quit` produced a clean "欢迎下次再来！" both times with zero new
`log/log` error lines either time; a second connection (the seeded
admin) could `tell ceshiwyz ...` and have it delivered correctly both
before and after each reconnect (confirms `find_player()` +
§7.152-style post-reconnect `set_living_name()` re-registration both
work), and the room listing never showed more than one copy of either
character at a time (no §7.150-style leaked duplicate). Non-`autoload`-
flagged carried items (the starting 粗布衣 clothing) are dropped/
destroyed on every `quit` and freshly reissued by `restore_autoload()`
at next login — traced this to `feature/autoload.lpc`'s intentional
"only autoload-flagged items persist across a session, everything else
is graceful-dropped rather than silently vanishing on `destruct()`"
design (the same TMI-2-lineage `save_autoload()`/`restore_autoload()`
idiom documented corpus-wide in AGENTS.md §7.122's family) — NOT a bug,
left untouched.

**Not reached this session** (budget, not correctness concerns): a full
paid shop purchase (no free starting currency reachable without a
wizard-granted `add()`, and the currency is object-based rather than a
simple stat), sect/menpai formal `apprentice`/`bai` enrollment beyond
the one-shot NPC skill grant, real PK/death-and-respawn (would require
finding a genuinely lethal opponent and burning significant real time),
and the bang/economy-heavy `bank`/pawnshop flows. None of these showed
any red flag during code reading; flagging honestly as unexercised
rather than guessing them clean.

Verified `grep -h '"port"' libs/*/meta.json | grep -oE '[0-9]{5}' | sort
-n | uniq -c | awk '$1>1'` prints nothing before committing. Driver
killed by exact PID after testing; test character's save files deleted,
only the seeded `fluffos` admin account save files remain under
`work/data/{login,user}/f/`.

**Targeted follow-up (AGENTS.md §7.154 sibling check)**: `xyj2006zzzhx`'s
NOTES.md (round-two deep test) had explicitly flagged `xyj2006n`'s
`cmds/std/look.lpc:410` as byte-for-byte the same unfixed
`present("fire", this_player())`-with-no-null-check line documented in
AGENTS.md §7.154. Confirmed identical here: `feature/move.lpc::remove()`
(called on every `destruct()`) calls `LOOK_CMD->look_room(me, ob,
query("env/brief"))` whenever an object leaves a non-living, non-
character environment (line 283), and `look_room()`'s outdoor exit-
listing block unconditionally evaluated `present("fire",
this_player())` before checking whether `this_player()` was even an
object. Reproduced live on a fresh boot two independent ways: (1) the
real production path — waited for `adm/daemons/natured.lpc`'s
boot-persistent `update_day_phase()` call_out chain to reach its
`event_dawn()` phase, which `destruct()`s the outdoor 钟馗(Zhong kui)/
青霞仙子(Qingxia xianzi) NPCs spawned at midnight; `debug.log` recorded
`*Bad argument 2 to present() Expected: object Got: 0` at
`cmds/std/look.lpc:410` via
`natured.lpc:event_dawn()`→`destruct()`→`move.lpc:remove()`→
`look_room()`, exactly matching the zzzhx trace shape (and a bonus
third instance via `/std/room.lpc::reset()` destructing a decayed
corpse the same way); (2) a synthetic `set_heart_beat(1)` harness
object (heart_beat calls are a reliable way to get `this_player()==0`
outside a live command, confirmed via `log_file()`) that cloned a
corpse into an outdoor room and called `decay(3)` from `heart_beat()`
— crashed identically. Applied the identical fix from `xyj2006zzzhx`:
added an `objectp(this_player())` short-circuit guard before the
`present()`/`wizardp()` calls. Rebooted fresh and reran the same
`set_heart_beat()` harness (confirmed `this_player()==0` at the
`decay(3)` call site via the same `log_file()` check) — zero
`present()` crashes in `debug.log` afterward; the torch/wizard check is
now cleanly skipped instead of throwing when there's no player in
context. Test harness file and its log were removed before commit;
only `cmds/std/look.lpc` changed.


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

## 商店付费购买 + 将军府拜师（2026-09-04 librarian shop slice）

2026-08-27 深度测试只验证了穷号 `buy huasheng from xiao er` 回「你的钱不够」，
正式 `bai` 未走到。本轮补完付费购买和将军府拜师，并确认 quit→重连后师承仍在。

第一行必须发字面 `2060`（Tomud 握手，`get_id` 拒其它）。登录密码
`Play2026x`，管理密码 `Mud@2026`。`if_young("no")` 自动走，没有 Y/N 提示。
落地南城客栈 `/d/city/kezhan`，`list` 显示花生豆 二十文钱。

Admin `fluffos`：`clone /obj/money/gold` 得到一两黄金，然后
`buy huasheng from xiao er` live 回「你向店小二买下一碟花生豆」。
`i` 为九十九两银子 + 八十文钱 + 花生豆。没有崩溃，没有「钱不够」误报。

新手拜师：`goto /d/jjf/jjf_bingqi`，`bai qin ping`（秦平，管家，无经验门槛）
→ 将军府第四代弟子，师承秦平。秦琼要求 `combat_exp >= 100000`：
`call me->set("combat_exp", 100000)`（本库 `eval` 只 `force_me` 一条命令，
不是 LPC；用 `call`），`goto /d/jjf/keting`，`bai qin qiong` →
将军府第三代弟子，师承秦琼。`quit` 后重连，`score` 仍是师承秦琼 / 第三代弟子。

本机临时建了空 `/u/f/fluffos/`（不入库）。驱动 PID 已杀，端口 40157 已空。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 6 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 编译警告与加载失败整理

与 `xiyouji2006` 同日同批修复（本库与它的 `d/`、`adm/`、`std/` 是同一份代码：改动的 1036 个文件中 984 个与 `xiyouji2006` 工作树逐字节相同，其余 52 个含本库自有代码，由同一套工具处理）：`scripts/lpc_warnings.py xyj2006n --fix` 与 KB 08 §10.13 的结构化工具，855 行增、1967 行删。逐条记录见 `libs/xiyouji2006/NOTES.md` 同日一节（`d/kaifeng/ground.h`、`quest.lpc`、`yaoguai.lpc`、`mojie.lpc` 等手工修复，`for (n == 0; ...)`、邮件守护进程 `tmp[i] == EOT + "."`、`int ref ()`（`ref` 是保留字，改 `do_refresh`，连同 `call_out("ref", 20)`）、`cmds/wiz/tail.lpc` 用的 `tail()` 在 `adm/simul_efun/file.lpc`）。

验证：全部 `.lpc`（9264 个对象，每次 VM 启动 700 个，HEAD 对工作树）9020 PASS -> 9036 PASS，由通变不通 0 个，新增可加载 16 个（8 个来自上述修复，8 个来自房间基类：`std/room.lpc` 的 `make_inventory()` 加了 `catch(ob = new(file)) || !objectp(ob)`，`scripts/lpc_resilient_room.py`，KB 05 §7.25）。`scripts/lpc_audit_removed_locals.py HEAD`：19 条候选全是误报（声明被重建，仍在用的名字仍在；这些文件无诊断）。`scripts/lpc_warnings.py xyj2006n` 剩 292 条诊断：87 个文件 287 条错误、5 条警告，都在本来就不能编译的文件里。

**剩余（不虚构内容）**：TMI-2 网络守护进程（`adm/daemons/network`、`daemons/network`：`uid.h`、`config.h`、`mailer.h` 档案里没有）；`d/kaifeng` 的 `old/quest_*` 片段；巫师目录（`u/yesi`、`u/vikee`）；损坏内容：`d/qujing/start/24/12.lpc` 在路径中间截断，`d/xueshan/obj/hufabird.lpc` 的函数写在 `create()` 里，`d/shendian/obj/niepan.lpc`、`d/moon/obj/poem.lpc`、`d/obj/quest/shuijingqiu.lpc` 有乱码字节（`Illegal character`），`d/dntg/sky/npc/yuhuang1.lpc` 丢了引号和分号。警告 5 条：`adm/simul_efun/oo.lpc`（`object.lpc` 里 `destruct()` 的无引用副本，simul_efun 之外被 `valid_override()` 拒绝）、`vikee.canoe.lpc`（`case` 写成 `cast`）、`d/penglai/_._/10.10/score.lpc` 与 `u/vikee/10.10/score.lpc`（缺分号）。

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 263 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 4 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 4、4、4 个（共 4 个），无回退；`adm/daemons/questd.lpc`、`daemons/cron.lpc` 原先加载失败，现在加载成功。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK；全库 9264 个对象 HEAD 对工作树的加载检查：9038 -> 9088，新增 50 个可加载，无回退。

- 2026-10-10：`/obj/roommaker.lpc` 生成新文件用的 here-document 模板（`@ROOM_CODE`/`@OBJ_CODE`）里的 `inherit` 行，被 94b87c18461 的重复继承清理当成代码删掉了（`lpc_diamonds.py` 当时不识别 here-document），用它生成的房间/物品会因缺少继承而无法编译。已恢复该行；工具已修正。

## 深度功能测试（§10.7，2026-10-12）：vikee.canoe.lpc

- `d/city/npc/vikee.canoe.lpc`（及 `npc/npc/` 副本）：`cast "mace" :` 是 `case` 的笔误，整份文件从不编译；改正后可载入（这是 `vikee.lpc` 的旧副本，无人引用）。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 3 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`yueya-chan/feicha`。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

19 个文件、22 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/npc/obj/choupao`、`/d/city/npc/obj/changqiang`、`/d/obj/cloth/cloth`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 19 个（18 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，2 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h；`daemons/network/netmail`：/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 3 个对象设了本库没有文件的武功（5 个名字，最多的是 `chanting`、`essencemagic`、`qitian-gun`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：3 个里 3 个通过。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/unarmed`（宏 `UNARMED`）←sjsh，2 个对象继承它，抽样 2/2 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 15 处、15 个文件：`dagonforce`→`dragonforce`（4 处）、`hellfire_whip`→`hellfire-whip`（3 处）、`lahua-shou`→`lanhua-shou`（3 处）、`dragon-step`→`dragonstep`（2 处）、`yange_blade`→`yange-blade`（1 处）、`changqaun`→`changquan`（1 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 2 处、2 个文件：`::buy_object()`（2 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 6 个：`/daemon/skill/boxing.lpc`、`/daemon/skill/houquan.lpc`、`/daemon/skill/taiji-quan.lpc`、`/daemon/skill/westsword.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 全局头文件丢了 2 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `NPC_D`、`LOCATION_D`，用到它们的物件（名单里 2 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/daemon/class/fuqiperform/perform.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/liandan/baihuagu.h`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 5 处）。改动：`/cmds/wiz/dns.lpc`（1 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 登录计数文件 `UserNumber` 缺失（2026-10-20，KB 06 §7.298）

`logind.lpc` 的 `do_counter()` 读 `/adm/daemons/UserNumber`（访客计数，运行中的 mud 才会写）；`.gitignore` 把它排除在仓库之外，所以新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。登录时的 `logon()` 调用了它，每个连接都以 `Bad argument 1 to sscanf` 被断开，没有人登录得进来。加了 `if (stringp(file))` 的守卫（与 dtxywzxzb、rzrmud、xiyouji2006、zitengzhan 早先的做法相同）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## 访客计数 `howmany_visitor()` 读文件不检查（2026-10-20，KB 06 §7.301）

`howmany_visitor()` 读访客计数文件（`VISITORS` / `COUNTER` / `BBSVISITOR`，只有运行中的 mud 才会写；`.gitignore` 把它排除在仓库之外），新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不一定走到它，但调用时同样会出错。在读文件之后加了 `if (!stringp(content)) return 0;`（xkx100、xiakexing100、zzfy 早先的写法，`scripts/lpc_fix_visitor_count.py`）。改动：`/www/relative/logind.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 2 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（4 个文件，括号里是接住 0 的 efun）：`/cmds/adm/admove.lpc`（`present`）、`/cmds/adm/baiban.lpc`（`sscanf`）、`/cmds/adm/dumpprog.lpc`（`new`）、`/cmds/wiz/call.lpc`（`replace_string`）。加载检查 HEAD 与工作树对照，没有退步。
