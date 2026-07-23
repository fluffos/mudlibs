# jinyongqunxiazhuan2008 — 金庸群侠传 (Jin Yong Heroes Gathering)

Archive: `archives/金庸群侠传2008加强版.rar` ("Jin Yong Heroes Gathering 2008,
enhanced edition"). Extracted mudlib root: `raw/jy/` (a single top-level
`jy/` directory inside the archive). Port: **40082**. Status: **done**
(boots clean, full registration flow verified with a real Chinese name,
post-login `look`/`score` verified working).

## What this is / lineage

`config.cfg`'s `name` field (GBK-decoded) is literally `金庸群侠传`,
matching the archive title exactly — this is NOT a mislabeled archive.
`adm/obj/{master,simul_efun}` layout, "ES II" lineage (its own
`Readme.txt` says "ES2 lib (Tian Cao Di Guo) Version... Wrote By
Phoebus.suny 1998").

**Confirmed near-identical sibling of `xiakexing3` (archive #44,
`libs/xiakexing3/`)**: `md5sum` diff shows `adm/obj/master.c`,
`adm/daemons/logind.c`, `adm/daemons/chinesed.c`, `adm/obj/simul_efun.c`,
`adm/simul_efun/chinese.c`, `include/globals.h`, and
`adm/simul_efun/message.c`/`feature/message.c` are all **byte-identical**
between the two archives. Only `adm/daemons/securityd.c` and
`config.cfg` differ. This fully explains xiakexing3's own NOTES.md
oddity ("config `MUD_NAME` is 侠客行三 but the live banner reads 金庸群侠传")
— xiakexing3 is a rebranded fork/snapshot of (or a common ancestor with)
this exact "金庸群侠传" codebase; whoever forked it changed the config's
`name`/`MUD_NAME` field but never touched the deeper, shared engine
files, so the in-game banner text baked into those shared files still
says "金庸群侠传". **Cross-check note for later archives**: per the task
brief, archives #92 (`金庸群侠传2008版.rar`), #93
(`金庸群侠传2008超豪华版.rar`), and #94 (`金庸群侠传2015版.rar`) are
still queued and share this title family — worth an `md5sum`
cross-check against this lib's core files (`adm/obj/master.lpc`,
`adm/daemons/logind.lpc`, `adm/daemons/chinesed.lpc`,
`adm/simul_efun/chinese.lpc`) once processed, the same way this pass
cross-checked against xiakexing3(#44). Given xiakexing3, #92, #93, #94
all share "金庸群侠传"/"侠客行" branding, there is a real chance several
of them turn out to be near-identical snapshots of the same underlying
engine with only site branding + a handful of content files differing
(same pattern as the `shujian2008`/`shujiantianxia` and
`zhongjidiyu`-family precedents already in AGENTS.md) — check this
lib's fixes (§15h chinese.lpc shape, §15ae command.lpc shape, combatd.lpc's
`quest.h` include, the "tang"-family `new`-as-variable-name typo, etc.)
against them directly before re-diagnosing from scratch.

Small-to-medium lib: 3,773 raw files, 3,135 `.lpc`/`.c` files sweepable
by `lpcc_check.sh`.

## Fixes applied (with why)

1. **AGENTS.md §15h** (is_chinese / check_legal_name — GBK byte-range
   checks silently wrong under UTF-8 strings):
   - `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte range
     check (`str[0] > 160 && str[0] < 255`, `strlen>=2`) → CJK Unified
     Ideographs codepoint range check (`str[0] >= 0x4e00 && str[0] <=
     0x9fff`, `strlen>=1`).
   - `adm/daemons/logind.lpc`'s `check_legal_name()` (inline in
     logind.lpc — this lib has no separate `named.lpc`): byte-count
     bound `strlen(name) < 2 || > 12` → character-count bound `< 1 ||
     > 6` (halved, matching what the user-facing message already
     promises: "1 到 6 个中文字"); dropped the `i%2==0 &&` even-byte-offset
     gate in the per-character `is_chinese(name[i..<0])` sliding-window
     loop (every index is already one full character now).
   - **Verified working**: real Chinese name "秦风" now passes on the
     first attempt (confirmed via the registration transcript — see
     below); before this fix every valid Chinese name would have been
     silently rejected.

2. **AGENTS.md §15ae** (`private nomask` command-hook breaks every
   post-login command silently): `feature/command.lpc`'s
   `command_hook(string arg)` was declared `private nomask` and is
   dispatched via `add_action("command_hook", "", 1)` from
   `F_COMMAND`, inherited transitively into the player body
   (`clone/user/user.lpc` → `inherit/char/char.lpc` → `inherit
   F_COMMAND`). Dropped `private` (kept `nomask`). **Verified**: `look`
   and `score` both work correctly post-login (see transcript below) —
   without this fix every typed command, including `look`, would
   silently do nothing.

3. **AGENTS.md §15t (variant 1)**: `adm/daemons/combatd.lpc` had
   `#include </quest/quest.h>` — an ABSOLUTE path inside angle
   brackets, which this driver's `inc_open()` never resolves (angle
   brackets only search the configured include path, never an
   already-absolute name). `/quest/quest.h` genuinely exists on disk.
   Fixed to `#include "/quest/quest.h"` (quoted absolute form, which
   this driver's resolver does handle). Without this, `combatd.lpc`
   (needed by the `score` command and all combat) never compiled at
   all — confirmed via a live `score` attempt throwing `*No program in
   object '/adm/daemons/combatd'!` before the fix.

4. **AGENTS.md §15t (variant 3, NEW manifestation)**: fixing #3 above
   then surfaced a SECOND bug in the same file: once `/quest/quest.h`
   actually got included, its file-scope global
   `mapping quest_name = ([...]);` landed textually BEFORE
   `combatd.lpc`'s own `inherit F_DBASE;` line (the `#include` was
   listed after some other `#include`s but before the `inherit`),
   which is a fatal "Illegal to inherit after defining global
   variables" on this driver. Fixed by moving `inherit F_DBASE;` above
   ALL of `combatd.lpc`'s `#include` lines. `quest.h`'s own
   `quest_finished()`/`quest_failed()`/`lock_quest()`/`islocked()`
   function bodies are real (not just prototypes) — the earlier
   "Undefined function quest_finished" sweep error was purely a
   downstream symptom of the broken `#include`, not a missing
   function; it resolved automatically once the include worked.

5. **A `capitalize()`-on-`0` robustness bug in `feature/name.lpc`**
   (same family as AGENTS.md §15e's "guard every unchecked chained
   call" principle, new concrete instance): `short(int raw)`'s
   fallback (`str = name(raw) + "(" + capitalize(query("id")) + ")"`,
   used whenever `query("short")` isn't set) assumes `this_object()`
   always has an `"id"` property — true for characters, but this same
   function is inherited by ALL items via `ITEM -> F_NAME` (`inherit/
   item/item.lpc`), including bulletin boards
   (`inherit/misc/bboard.lpc`). Any board/item without an explicit
   `"short"` property crashes every `look` in its room with `*Bad
   argument 1 to capitalize() Expected: string Got: 0`. Found via the
   very first `look` in the tea-house starting room
   (`/clone/board/kedian_b` has no `"short"` set). Fixed with a
   `stringp(id)` guard: only append the `"(id)"` suffix when there
   really is a string id; otherwise return the bare name. **Verified**:
   re-ran the full test after the fix — `look` in the same room no
   longer throws, board is now displayed cleanly as
   `/clone/board/kedian_b [ 没有任何留言 ]`.

6. **`d/city/npc/guidao.lpc`'s `is_killing(who)` direct-call type
   mismatch** (same shape as AGENTS.md §15b's `nitan_ceshi` finding):
   `is_killing(string id)` is declared in `feature/attack.lpc`
   (`inherit`ed transitively into every NPC/character); every other
   20+ call site in this lib correctly calls
   `is_killing(ob->query("id"))`, but `guidao.lpc`'s `ask_me(object
   who)` called `is_killing(who)` directly with the raw object. Since
   this is a same-object DIRECT call (not `->`), the static type
   checker enforced the declared `string` parameter strictly and
   refused to compile the whole file. Fixed to
   `is_killing(who->query("id"))`, matching every sibling call site.

7. **Duplicate `inherit F_UNIQUE;` (copy-paste typo, pre-existing, not
   a conversion artifact)**: `d/mingjiao/npc/{yinwushou,yinwulu,
   yinwufu}.lpc` each had `inherit F_UNIQUE;` listed TWICE. Harmless
   under whatever driver these were authored against, but this driver
   fatally rejects re-declaring the same `nomask` function
   (`violate_unique`) from a duplicate inherit ("Illegal to redefine
   'nomask' function"). Removed the duplicate line in all 3 files.

8. **The "tang"-family NPC template's `new` used as a bare variable
   name** (pre-existing authoring bug, not a conversion artifact): 7
   files — `d/quanzhou/npc/{tang,tang1,tang2,tang3}.lpc`,
   `d/taishan/{tang2,tang3,xingtang}.lpc` — all share one copy-pasted
   `do_clone()` function declaring `object *inv, new;` and later doing
   `new = new("/clone/npc/...")`. `new` is a reserved efun/keyword on
   this driver, so declaring/assigning a variable literally named
   `new` is a hard syntax error (`unexpected L_NEW`, `unexpected
   L_ASSIGN`, `Illegal LHS`) — the whole file failed to compile.
   Renamed the local variable to `newob` throughout (declaration +
   both usages) in all 7 files; the actual `new(...)` efun calls are
   untouched (they're function-call syntax, not the bare identifier).

9. **AGENTS.md §15ac (bare `SAVE_EXTENSION` instead of
   `__SAVE_EXTENSION__`)**: found in `include/net/ftpdsupp.h`,
   `adm/daemons/network/netmail.lpc`, `cmds/arch/purge.lpc`, and 2 of
   the "tang"-family files above (`d/quanzhou/npc/tang.lpc`,
   `d/quanzhou/npc/tang3.lpc`, `d/taishan/tang3.lpc` — 3 files
   actually). Replaced the bare `SAVE_EXTENSION` with
   `__SAVE_EXTENSION__` in all of them. **Left alone**:
   `clone/npc/meng-zhu.lpc` and `u/jackyboy/TOKEN.lpc`, which both
   `#define SAVE_EXTENSION ".o"` locally themselves — self-contained,
   not part of the bug.

10. **`kungfu/class/mingjiao/mingjiao.h`'s string-literal-adjacent-to-
    macro-expansion syntax error**: `ob->query("party")["party_name"]
    == HIG "明教" NOR` (a colored-string equality check) failed to
    parse (`unexpected L_STRING`) because after macro expansion
    (`HIG` → `ESC+"[1;32m"`, `NOR` → `ESC+"[2;37;0m"`) two string-
    literal tokens end up textually adjacent with no operator between
    them, which this driver's grammar doesn't auto-concatenate.
    Rewrote as `HIG + "明教" + NOR` with explicit `+`. Also added
    `#include <ansi.h>` to this same header, since two of its
    includers (`d/mingjiao/npc/{litianyuan,yinyewang}.lpc`, reached
    transitively via `tangzhu.h`) never include `<ansi.h>` themselves,
    so `HIG`/`NOR` were genuinely undefined identifiers in that
    compilation context once the syntax error above stopped masking it.

11. **`d/mingjiao/npc/changjinpeng.lpc`'s wrong absolute
    `#include` path**: `#include "/kungfu/class/mingjiao/tanzhu.h"` —
    that path doesn't exist (an early-draft location; the real
    `tanzhu.h` lives at `d/mingjiao/npc/tanzhu.h`, right next to this
    file, exactly where its sibling NPC files
    `chengchaofeng.lpc`/`gaoshanwang.lpc` correctly reference it via a
    bare `"tanzhu.h"`). Fixed to `#include "tanzhu.h"`.

12. **`d/mingjiao/npc/{fenggongying,baiguishou}.lpc`'s
    `#include __DIR__"tanzhu.h"` (no `+`, no quotes around the whole
    directive) failed with "Cannot read #include file"** (a different,
    more specific driver error than the "Cannot #include" bad-path
    case — the path resolves/opens but reading its content fails,
    consistent with `__DIR__`'s macro-expansion inside `#include`'s
    unquoted form doing something unexpected here). Rather than
    forensically chase the exact interaction (low value for 2 files),
    rewrote both to the already-proven-working plain quoted form
    `#include "tanzhu.h"`, matching every other sibling NPC file in
    the same directory that already resolves this exact same file
    successfully.

13. **`d/baituo/ouyangfeng.lpc`, two independent pre-existing typos**:
    (a) a missing semicolon after `write("...")` inside a `switch`
    `case 0:` block, causing the parser to read the next line's
    `break;` as part of an unterminated expression
    (`unexpected L_BREAK`); (b) `object me=this-player();` — `this-
    player()` (a subtraction of `this` and `player()`) instead of
    `this_player()` (missing underscore). Fixed both.

14. **`d/shaolin/obj/shuitan.lpc`: `ging_cost` typo for the declared
    variable `jing_cost`** (transposed letters) in
    `me->receive_damage("jing", ging_cost)`. Fixed to `jing_cost`.

15. **`d/mingjiao/jmqshenmu.lpc` was genuinely truncated in the raw
    archive itself** (confirmed by diffing against the pre-conversion
    `.c` — both are exactly 26 lines, ending mid-`void init() {` with
    no closing braces at all — not something our pipeline introduced).
    Closed the truncated function with an empty body (a single `}`)
    rather than fabricating any actual `init()` content, purely so the
    file is syntactically valid instead of a permanent parse-error
    landmine; the room's real, complete `create()` content is
    untouched.

## Confirmed NOT needed (checked by reading the actual source)

- **§4** (master's lazy security-daemon load recursing to a stack
  overflow): `master.lpc`'s `valid_write` only does
  `find_object(SECURITY_D)` (no `load_object()` at all — returns 0 if
  not found, no recursion risk); `valid_read` is a bare `return 1;`.
  Exactly the same shape already confirmed clean on `xiakexing3` (this
  file is byte-identical between the two archives).
- **§7** (missing `get_root_uid()`/`get_bb_uid()`): both already
  implemented in `master.lpc` (lines 177/182).
- **§8c** (`valid_read`/`valid_write` overriding caller with
  `this_player()`): `securityd.lpc` has no `valid_read` at all (only
  `valid_write`, which never touches `this_player()` to override
  `user`).
- **§15n/§15o** (custom securityd ACL blocking driver's own
  compile-time reads / missing `get_include_path()`): this lib's
  `securityd.lpc` implements `valid_write` only (no custom
  `valid_read` ACL), and `master.lpc`'s `valid_read` is an
  unconditional `return 1;` — the driver's own lazy compiles are never
  gated by anything custom. No `get_include_path()` needed either: no
  `<local.h>`-next-to-its-user `#include` collisions found anywhere in
  the tree (checked programmatically).
- **§15p** (DNS/intermud daemon in preload causing hangs):
  `adm/etc/preload` never listed `network/dns_master` in the first
  place (11-entry preload list, all registration-relevant daemons,
  confirmed by direct read before the first boot attempt) — nothing to
  exclude.
- **§15l** (master.lpc destructing `SIMUL_EFUN_OB` in `create()`):
  `master.lpc`'s `create()` is a single `write(...)` line, no
  `destruct()` call at all.
- **§15u** (dormant "phone home" destructive license check): grepped
  `master.lpc`/`securityd.lpc` for `shutdown`/`rm(`/`rmdir(`/
  `unlink(` — only one hit, a harmless comment.
- **§15r** (`check_config.lpc`-style driver-version self-check):
  no such file anywhere in this lib.
- **§15ag** (`ed_start`/`ed_cmd`/`query_ed_mode`): zero occurrences.
- **§15al** (`crypt(str, 0)` random-hash-every-call footgun):
  `logind.lpc`'s `new_password()` uses `crypt(pass, 0)` only to
  generate a NEW password hash at registration time (stored once);
  every subsequent login compares via `crypt(attempt, stored_hash)`
  (a real string salt, not `0`) — this is ordinary, correct password
  hashing, not the client-challenge-determinism footgun the catalog
  entry describes (which specifically involves BOTH sides needing to
  independently compute the same `crypt(KEY, 0)` value — no such
  challenge/response protocol exists in this lib).
- **§8e** (`tail()` not a real efun): 2 harmless hits, both in
  `cmds/wiz/tail.lpc` (an unused admin command, never reachable from
  registration/core gameplay) — left as documented pre-existing noise,
  matching the catalog's own precedent for this exact non-fatal case.
- **§15/§15b** (simul_efun-based generic `set`/`query`/`delete` dbase
  architecture bug, "NT/nitan/Lonely" lineage): `adm/obj/simul_efun.lpc`
  and its `#include`d fragments define no global `set`/`query`/
  `delete` at all — this lib uses the architecturally-correct
  per-object `inherit F_DBASE` pattern throughout (same as `rzrmud`/
  `xiakexing3`), confirmed by grep before assuming the fix was needed.
- **§15w/§15af** (`log_error()` spamming players with warnings /
  crashing on a lazy uid-check during compile-time warnings):
  `master.lpc`'s `log_error()`-equivalent apply wasn't found doing
  anything unusual; not investigated further since no symptom of this
  shape appeared in any boot or gameplay test.
- **§15x** (hardcoded `MUD_PORT` mismatch): `master.lpc` has no custom
  `connect(int port)` apply at all — nothing to mismatch.
- **§15ao** (`switch` with only `default:`): none found in
  `master.lpc`.
- **Uppercase `.C` files**: 4 found, all under `u/jackyboy/` (a
  wizard's personal item files — `TOKEN.C`, `WIZ_CLOA.C`, `CLOTH1.C`,
  `GLASS.C`), already UTF-8 (not GBK), simply renamed to `.lpc`
  (`convert_lib.sh`'s glob only matches lowercase `.c`).
- **`#define nosave static`/`#define protected static` compat shim
  (§15z)**: none found in any `.h` file.
- **Fixed-width `[0..<N]` slice bugs (§2's `<3`→`<5` widening
  variant)**: several `[0..<2]`/`[0..<3]` occurrences found via grep,
  but all inspected and confirmed to be either ARRAY-removal idioms
  (`cmds` array element deletion in `commandd.lpc`), or ordinary
  trailing-character trims (dropping a `*` wildcard suffix in
  `channeld.lpc`, dropping a trailing newline in `ftpd.lpc`) —
  unrelated to the `.c`→`.lpc` filename-extension-width bug. The one
  genuine filename-extension `[0..<3]` pattern found
  (`explode(__FILE__,"/")[<1][0..<3]` in 8 `kungfu/skill/*/*.lpc`
  files) computes a value (`pfname`) that is used ONLY inside
  commented-out permission-check blocks in every one of the 8 files —
  confirmed dead code, not fixed (no live effect either way).

## Interactive test result — full registration + post-login flow

Registration flow (all in one continuous `mudclient.py` session,
verified 3 times across the fix-iteration cycle, final clean run
shown): `英文名字(id)` → `y` (confirm new character) → **real Chinese
name "秦风"** (accepted on the first try, no rejection loop) →
password → confirm password → accept random gift stats (`y`) → email →
gender (`m`) → enters the game world at `客店` (the tea-house starting
room).

```
您的英文名字：使用 qinfengwu 这个名字将会创造一个新的人物，您确定吗(y/n)？
请输入您的高姓大名，...
您的中文名字：/clone/user/login#0        <- (author's own printf("%O\n",ob) debug leftover; harmless)
请设定您的密码：
请再输入一次您的密码，以确认您没记错：
...膂力[20]， 悟性[18]， 根骨[20]， 身法[22]
您接受这一组天赋吗？
您的电子邮件地址：
您要扮演男性(m)的角色或女性(f)的角色？

目前权限：(player)
...
[1;36m客店[2;37;0m -
    这是一家价钱低廉的客栈，生意非常兴隆。...
    这里明显的出口是 west 和 up。
  /clone/board/kedian_b [ 没有任何留言 ]
  店小二(Xiao er)
你上次连线是从0 on Wed Dec 31 16:00:00 1969
```

Post-login commands, in the SAME connection:
- `look`: works, re-renders the room + NPC + (now-fixed) board display
  cleanly, zero runtime errors.
- `score`: works, shows full real character sheet (title, age/gender/
  birthdate, 膂力/悟性/根骨/身法 stats, 精/气 bars, 食物/饮水 bars, kill
  count, 潜能/实战经验) — this is the fix from combatd.lpc's `quest.h`
  include bug; before that fix `score` crashed with `*No program in
  object '/adm/daemons/combatd'!`.
- `quit`: clean save + disconnect message.

Zero fatal/runtime errors anywhere in `log/debug.log` across this final
run (only expected compile *warnings* — "Unused local variable",
"Illegal to declare nosave function" — and the one known, non-fatal,
pre-existing corrupted-save-data error described below).

## Known non-fatal pre-existing issue (not fixed)

`adm/daemons/chinesed.lpc`'s `create()` calls `restore()`
unconditionally on its English→Chinese translation dictionary save file
(`data/e2c_dict.o`). That file's raw bytes (confirmed identical,
`md5sum`, between `raw/` and `work/` — genuinely never touched by our
encoding pass, since `file` classifies it as `data` and `.o` is
deliberately excluded from the forced-text extension list) do not
decode as a valid LPC mapping (`restore_object(): Illegal file format`)
— this looks like pre-existing corrupted seed data in the original
archive itself (same class of bug as `zhonghua2`'s stale `versiond.o`,
AGENTS.md §15m), NOT a driver-compat or encoding-conversion bug. It's
fully caught by `master.lpc`'s own `preload()` catch wrapper (visible
in `debug.log` as "错误讯息被拦截"/"error message intercepted"), entirely
non-fatal, and `chinesed.lpc`'s `dict` mapping simply stays at its
default empty value — English/Chinese name translation lookups just
return the input unchanged instead of a real translation. Does not
affect registration, `look`, or `score`.

## Content gaps confirmed as real archive gaps, not bugs (AGENTS.md §13)

- `d/mingjiao/yuan/*` (9 named "yuan" NPCs, e.g. 郑七灭/郑十灭 family)
  reference two genuinely-missing kungfu skill files
  (`xuanyuan-arrow`, `liangyi-jian`) — not present anywhere under
  `kungfu/skill/`.
- `d/mingjiao/npc/monkey.lpc` references an undefined race (`走兽`,
  "beast") not present in the race table.
- `d/mingjiao/npc/{gaoshanwang,fenggongying,baiguishou,changjinpeng,
  chengchaofeng}.lpc` all also reference a whole missing zone
  (`/d/yanziwu/`, referenced via `carry_object()`/room exits from
  several 明教-zone NPCs) that doesn't exist anywhere in this archive.
- `d/wudang/taoyuan/{tyroad4,5,6,7}.lpc` are confirmed ORPHANED early
  drafts of the finished, fully-working `d/wudang/tyroad{4,5,6,7}.lpc`
  files one directory up (diffed byte-for-byte content — the top-level
  versions are the complete/correct ones, with proper NPC spawns and
  the correct `feng.h` include path; the `taoyuan/` copies are
  shorter, broken-include, no-NPC earlier drafts). Nothing in the
  entire lib references the `taoyuan/` directory at all (grepped) — a
  dead/unreachable duplicate, not fixed.
- `u/liujun/quest/leftkiller.lpc` references a missing skill
  (`six-chaos-sword`); `u/editer/tie-luohan.lpc` is a broken/unfinished
  wizard scratch-directory draft (garbled variable names look like a
  botched find-replace, e.g. `skill_statussname`) — both under
  personal wizard directories, not core content, not fixed.
- `adm/daemons/network/*` (dns_master, mudlist_a, netmail, inetd,
  mail_serv, and friends): confirmed via grep that NOTHING outside
  this subdirectory references any of these files, and none are in
  `adm/etc/preload` — genuinely dead/inert intermud subsystem code,
  never compiled during a real boot or any registration/gameplay path.
- `home/simul_efun.lpc`: a stray backup/scratch copy of the real
  simul_efun sitting in a `/home` sandbox directory (not the configured
  `simulated efun file`, which is `/adm/obj/simul_efun`) — the lpcc
  sweep's "Invalid simulated efunction override" failure on it is a
  pure sweep artifact (AGENTS.md §6b: `main_file_name()` reports
  differently when this fragment is compiled standalone vs. as the
  real thing), never loaded as the actual simul_efun in real gameplay.
- `clone/board/*` corrupted save data (11 board `.o` files under
  `data/board/` fail `restore_object()` with either "Illegal file
  format" or "Invalid utf8 string while restoring dbase") — same class
  of pre-existing corrupted seed data as `chinesed`'s `e2c_dict.o`
  above; each board's `setup()` already wraps the failure gracefully
  (boards just start with no persisted notes), confirmed non-fatal via
  the live `look` test at `kedian_b` (which restores fine as an EMPTY
  board, not one of the 11 corrupted ones).
- `d/npc/m_weapon/weapon/{m_club,m_blade,m_whip,m_sword,m_staff}.lpc`:
  `create()` calls `this_player()` unconditionally — always null in an
  isolated `lpcc` compile (no player context), causing a
  `call_other()`-on-0 sweep failure. This is the standard AGENTS.md
  §6b "compiled divorced from runtime context" false positive — these
  files are only ever `new()`'d as a direct response to a real player
  action, where `this_player()` is always valid.

## lpcc sweep

Ran 3 times across the fix-iteration cycle (baseline → after the
combatd/command_hook/name.lpc/guidao/tang-family/mingjiao fixes → final
confirmation), each a fresh `lpcc --batch` sweep via
`scripts/lpcc_check.sh`:

- Baseline (before any post-boot fixes beyond §15h/§15ae): 3040/3135
  pass (96.97%).
- After combatd.lpc / tang-family `new` / SAVE_EXTENSION / mingjiao.h /
  yinwushou-family duplicate-inherit / guidao is_killing /
  ouyangfeng.lpc / shuitan.lpc fixes: 3054/3135 (97.4%).
- **Final** (after the mingjiao.h `ansi.h` include + tanzhu.h path
  fixes + jmqshenmu.lpc truncation guard): **3064/3135 pass (97.74%)**.

Remaining 71 failures were triaged by category (AGENTS.md §6b) and are
all one of: corrupted pre-existing save data (11, boards), genuinely
missing zone/skill/race content (§13, ~20 files across
`mingjiao/yuan`, `yanziwu`-zone NPCs, wizard scratch quests), the dead
DNS/intermud subsystem (~16, never preloaded/never referenced), a
handful of wizard personal-sandbox scratch files
(`u/liujun/`, `u/editer/`, `home/simul_efun.lpc`), 2 harmless
`tail()`-missing-efun hits in an unused admin command (§8e, matching
established precedent), and the `this_player()`-is-null-during-
isolated-compile sweep artifact on 5 weapon template files (§6b). None
of these affect registration, `look`, or `score` — all confirmed via
direct source reading, not guessed.

Memory stayed healthy throughout all 3 sweeps (well under 1 minute
each, `free -h` never dropped meaningfully — this is a small/medium lib,
nowhere near mega-lib territory).

## Process notes

- Driver launched via `nohup ... & disown` from within
  `libs/jinyongqunxiazhuan2008/` (required for `log/debug.log` to
  resolve correctly, per AGENTS.md §6). Rebooted 4 times total across
  the fix-iteration cycle; each old PID was killed by its own exact
  PID (never a broad `pkill` pattern) and verified gone via `ps`/`ss`
  before relaunching. Final driver process was killed (PID 632097)
  after all testing completed, confirmed via `ss -tlnp` no longer
  showing port 40082.
- Each successive registration test used a fresh English id
  (`qinfeng`, `qinfengtwo` → rejected, digit not allowed; `qinfengsan`,
  `qinfengsi`, `qinfengwu`) since a successfully-registered id's save
  file persists across driver restarts and re-prompts for a password
  instead of fresh registration — not a bug, just a test-script
  gotcha worth noting for whoever re-tests this lib later.

## 2026-07-23 re-verification pass (driver rebuild + formatter + WASM)

- **LPC reformat**: ran `format-corpus.mjs` over all of `work/` (3,135
  `.lpc` files) — 3,102 written, 13 already-idempotent, 20 refused
  (self-checked round-trip failures on messy legacy syntax, expected).
- **Native retest against the freshly-rebuilt driver**: booted clean on
  port 40082, zero fatal preload errors. Full registration flow with a
  fresh real Chinese name ("秦风六"/`qinfengliu`, distinct from all
  prior test ids on this lib) through the complete wizard (id → confirm
  → Chinese name → password → confirm → gift accept → email → gender)
  into the actual game world (客店); `look`, `score` (full character
  sheet, correct stats/HP/potential), and `quit` (correct item-drop
  flavor text + clean save) all verified with real output, zero runtime
  errors in the whole session. No regressions from the reformat or the
  new driver binary.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`):
  boots cleanly, same preload warnings as native. **Full registration +
  login + look + quit all work end-to-end under WASM** — this lib does
  not gate its login on `query_ip_number()`'s format, so the documented
  WASM IP-check limitation doesn't apply here. Only cosmetic artifact
  observed: the WASM session's synthetic clock reports "上次连线...Wed
  Dec 31 16:00:00 1969" (Unix-epoch-adjacent) for the last-login
  timestamp on a fresh registration — harmless, purely a WASM-clock
  display quirk, not a functional issue.
