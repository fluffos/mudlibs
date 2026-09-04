
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
