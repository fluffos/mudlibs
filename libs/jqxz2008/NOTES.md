# jqxz2008 — 金庸群侠传 (Jin Yong Heroes Gathering)

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
(same pattern as the `shujian2008`/`sjtx2` and
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
  the live `look` test at `kedian_b`. **Correction (2026-07-24 WASM
  long-sit boot-watch)**: `kedian_b.o` IS actually one of the 11
  corrupted files (`data/board/kedian_b.o` is the same class of raw
  binary garbage, confirmed via `xxd`) — the registration flow's own
  `enter_world()` → `kedian.lpc create()` → `kedian_b.lpc create()` →
  `bboard.lpc setup()` → `restore()` chain throws the same "Illegal
  file format" error every time a fresh character registers there,
  caught by `logind.lpc`'s own `CATCH()` around `enter_world()`. Still
  fully non-fatal (board ends up empty, exactly as documented above)
  — the earlier claim that `kedian_b` restores cleanly was simply
  wrong (probably from a test transcript that only showed player-facing
  `write()` output, not the console-only intercepted-error banner).
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
  `libs/jqxz2008/` (required for `log/debug.log` to
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

## WASM-enablement pass (2026-07: loopback-allow + admin seeding)

Standard pass per AGENTS.md §1.3b/e + §1.5 (applied identically across
the three jqxz2008 builds — engine files are byte-identical
in this group):

- `adm/daemons/band.lpc:39` `is_banned()`: short-circuit `return 0` for
  loopback (`127.0.0.1`/`127.*`), empty, or non-string site values
  before the regexp ban-list scan. `logind.lpc:67`'s
  `BAN_D->is_banned(query_ip_name(ob))` gate in `logon()` is thereby
  loopback-proof (and robust against the WASM `query_ip_number()`/
  `query_ip_name()` garbage-return bug).
- No `uptime()` startup-grace gate and no per-IP anti-flood/registration
  throttle exist in this lineage (checked `logind.lpc`'s full input_to
  chain; the only other connection gate is the in-memory `mad_lock`
  admin lockdown flag, default off — left alone).

Admin account: `fluffos` / `Mud@2026` / 浮浮, registered through the
real native flow (id → y → Chinese name → password ×2 → gift y → email
→ gender m). Granted `(admin)` via `adm/etc/wizlist` (file was shipped
empty; now contains `fluffos (admin)`), which `securityd.lpc` reads at
create(). Verified after restart: login shows `目前权限：(admin)`,
`update /cmds/usr/score` prints 重新编译成功. Save files (must be
committed): `work/data/user/f/fluffos.o`, `work/data/login/f/fluffos.o`.

Retest: fresh registration (秦风/ceshizhe) end-to-end + look/score/quit
clean; fluffos login + wizard update clean; debug.log shows only the
known pre-existing corrupted-save restore errors (chinesed e2c dict /
kedian board) documented above — zero new errors; test character saves
removed.

## Dual-mode verification pass (2026-07-24)

- **Native** (port 40082): fresh registration `ceshier`/秦风 end-to-end
  into 客店; re-login (restore path) + look/score/quit all correct;
  `fluffos`/`Mud@2026` login shows `(admin)` and `update
  /cmds/usr/score` prints 成功. debug.log: only the two documented
  pre-existing corrupted-save restore errors (chinesed e2c dict +
  kedian board), both caught by the lib's own handler — zero new
  errors. (One mid-test driver death was an external SIGTERM — the
  §10.5 stray-kill hazard, not a lib fault; restarted and completed
  cleanly.) Driver killed by exact PID.
- **WASM** (build-wasm with query_ip_number/resolve fixes): fresh
  registration `wasmceshi`/秦风 end-to-end + look/score/quit all
  correct; second invocation: `fluffos` admin login `(admin)` +
  `update` 成功 — admin flow now verified under WASM too. **Verdict:
  native OK + wasm OK.** No fixes needed this pass. Test character
  saves removed; fluffos.o timestamp churn reverted.

## 2026-07-24 深度功能测试 / Deep functional test (AGENTS.md §10.7)

One continuous native `mudclient.py` session (plus a second `fluffos`
admin session used specifically to reach death/combat, since the main
character never accumulated the money or combat skill to risk real
`kill` safely in the time budget). §8.3a's `private nomask
command_hook` fix was **already applied** in this lib (`feature/
command.lpc:29` reads `nomask int command_hook(string arg)`, no
`private` — confirmed by direct read before touching anything else) —
not re-diagnosed.

**Test character**: id `shenshaofeng`, password `xia2026wu`, Chinese
name 沈少峰 (male). Left in a clean, alive, fully-saved state at
`/d/city/zuixianlou` (醉仙楼), title 叫化子/丐帮第二十代弟子 (member of
the Beggars' Sect, 20th generation, master 左全/Zuo Quan), `begging`
skill improved once via the organic teacher path, 潜能 98/99. Save
files left in place per the task instructions (`work/data/user/s/
shenshaofeng.o`, `work/data/login/s/shenshaofeng.o`) as evidence.
Admin account `fluffos`/`Mud@2026` (pre-existing, from the WASM-
enablement pass) reused for the death/reincarnation leg; left alive,
saved, at `/d/city/wumiao` (its own now-legitimate chosen home, set via
an explicit `quit` there — see bug #2 below for why that's legitimate
and the room's own automatic version isn't).

### What was verified working, live

- Full registration wizard with a real Chinese name (沈少峰), landing
  in the actual starting room (客店, the tea house) — `look`/`score`/`i`
  all correct at every step.
- Starting-zone navigation read from room source
  (`d/city/{kedian,beidajie1,guangchang}.lpc`) rather than guessed.
- Safe sparring: `help newbie`/`help intro` (`work/doc/help/{newbie,
  intro}`) both explicitly document `fight` (较量/切磋) as the
  non-lethal form (stops automatically at ~50% health, message: "这场
  比试算我输了，下回看我怎么收拾你！") vs `kill` (real, lethal). Used
  `fight` against 流氓头 (Liumang tou) at 中央广场 — auto-stopped
  correctly, zero real damage risk, exactly as documented.
- Sect join via the organic path: entered the 丐帮 (Beggars' Sect)
  hideout via the tree-hole passphrase at 中央广场
  (`d/city/guangchang.lpc`'s `shudong` → `d/gaibang/inhole.lpc`'s
  passphrase gate → `down` → 左全/Zuo Quan), then `bai zuo` — worked
  first try, correct flavor text, `score` afterward shows the new
  title/master.
  Also traced (not exercised, to keep the character safe/simple) the
  White Camel Mount (白驼山) sect's alternate teacher-recruit gate at
  `kungfu/class/btshan/ouyangke.lpc`'s `attempt_apprentice()` —
  correctly gates on `combat_exp` and confirms a second, independent
  join mechanism exists.
- Organic skill learning from a teacher NPC: `xue zuo begging` after
  `bai`-ing him — consumed 精 and 潜能 correctly, printed the expected
  "你的「begging」进步了！" message, confirmed via `score`.
- `cha zuo` (查功夫 — list a teacher's skills), once the crash below
  was fixed: full skill list rendered correctly.
- Clean `quit` (multiple times) followed immediately by a `debug.log`
  line-count check each time — **zero new `error:`/fatal lines** any
  time (confirmed at 349 lines before and after every quit across the
  whole session, on the FIXED driver).
- State persistence across a real driver restart + fresh restore-login
  (not just an in-memory reconnect): location, sect membership, master,
  skill level, 潜能 spend, and inventory (mailbox + a fresh cloth —
  clothes are deliberately non-`autoload` and get re-issued by
  `enter_world()` every login, see "confirmed not a bug" below) all
  came back correctly.
- Unclean (net-dead, not `quit`) disconnect + reconnect: exercised
  repeatedly (every `mudclient.py` invocation that didn't end in
  `quit` closes the socket without running the `quit` command, which
  `clone/user/user.lpc`'s `net_dead()` handles by stopping the
  heartbeat, clearing enemies, and scheduling `user_dump` after
  `NET_DEAD_TIMEOUT` — 600s/10min, `include/user.h:10` — the player
  object is never moved or void-parked, matching AGENTS.md §7.20's
  "good" shape, not its bug shape). Reconnecting always showed "重新连
  线完毕" and landed exactly where the character had been standing.
  Also did one deliberate net-dead disconnect followed by a real
  **~150-second wall-clock wait** (backgrounded `sleep`, polled, not a
  short synthetic gap) before reconnecting — same clean result. **Did
  NOT attempt the full 600s `NET_DEAD_TIMEOUT` wait** — explicitly
  skipped for time budget, not silently. Read `user_dump()`
  (`clone/user/user.lpc:66`) instead: on timeout it just runs
  `command("quit")`, i.e. the same already-verified-clean quit path,
  so the full-duration wait is very unlikely to surface anything the
  shorter wait + code read didn't already cover — lower priority here
  than actually chasing the two live crashes below.
- Real combat + death + corpse + ghost + reincarnation, end to end,
  live (not code-reviewed): the `fluffos` admin character fought a
  黑无常 (Black gargoyle) NPC at `/d/death/gateway` (reached via `goto`)
  and **actually died** for real. Confirmed the full chain once the
  crash below was fixed: `你死了` → ghost title (【鬼魂】) → corpse
  object left in the room → `score` shows reduced stats/0 jing-qi → the
  documented "ask yourself about 回家" ritual at `/d/death/inn1.lpc`
  (`d/death/gate` → `gateway` → `road1` → `inn1`, `ask fluffos about
  回家`) → `reincarnate()` fires and moves the (now living again)
  character to `/d/city/wumiao`. This is a genuinely deep, non-trivial
  path (matches checklist item 10's "get as far as reasonably possible
  toward combat/death") and it now works cleanly end-to-end.
- Shop (`buy`/`list`, F_DEALER pattern, `feature/dealer.lpc`): `list`
  at 醉仙楼 (a food stall, reached by mistake while navigating — turned
  out to be a useful second F_DEALER instance to check) rendered
  correctly with no crash. `buy` was exercised twice and both times
  produced the CORRECT rejection message with no crash: once as a
  丐帮 member ("你是个穷叫化，买什麽东西！" — beggars are deliberately
  forbidden from buying, `feature/dealer.lpc:116-117`, a real,
  internally-consistent design choice, not a bug) and once for
  insufficient funds.

### Not verified live (honest gaps)

- **A completed, successful purchase.** New characters start with
  zero money (`init_new_player()` in `logind.lpc` has the starting-
  balance line explicitly commented out) and the test character then
  joined 丐帮, which the shop code deliberately forbids from buying at
  all — reaching a real purchase would need either a different
  (non-beggar) character built from scratch or a source of starting
  gold, beyond this pass's time budget. `buy`'s code path (money
  check, `move()`, `call_out("enough_rest", 1)`) was read and looks
  sound, but that's a code-review conclusion, not a live one.
- **The full 600-second `NET_DEAD_TIMEOUT` wait.** See above — done a
  ~150s real wait instead, plus a source read of the timeout handler,
  and prioritized chasing the two live crashes found instead.

### Bugs found and fixed

**1. `adm/daemons/chinesed.lpc` — corrupted save data leaves a global
`mapping` as raw `0`, crashing the FIRST real use of `cha`/`chinese()`
(AGENTS.md §7.7, third bullet: "`restore_object()` ... ZEROES ... a
crash surfaces far away")**

This lib's own NOTES.md already documented `chinesed`'s
`data/e2c_dict.o` as pre-existing corrupted seed data whose `restore()`
fails at boot, and called it "fully non-fatal" because the failure is
caught by `master.lpc`'s `preload()` wrapper. That part is true for
*boot* — but nothing downstream was actually safe: `create()` was
```lpc
void create() {
  seteuid(getuid());
  restore();
}
```
`restore()` → `restore_object()` throws a real runtime error on the
malformed file; since that error is never caught INSIDE `chinesed.lpc`
itself, it aborts `create()` immediately at the `restore()` line — the
global `mapping dict = ([]);` initializer had already run at object
creation, but `restore_object()`'s failure zeroes it back out per
§7.7's exact mechanism, and because `create()` never reaches any
statement after the throwing call, no local recovery code could run
either. The very first real player use of any command that calls
`chinese()` (confirmed live via `cha zuo`, but `to_chinese()` used
throughout combat/skill messages could hit the same path) crashed with
`*Value being indexed is zero.` at `chinesed.lpc:94`.

Fix — wrap the throwing call in `catch()` (so `create()` can actually
continue past it) AND add the standard §7.7 post-restore guard:
```lpc
// BEFORE:
void create() {
  seteuid(getuid());
  restore();
}
// AFTER:
void create() {
  seteuid(getuid());
  catch(restore());
  if (!mapp(dict)) dict = ([]);
}
```
A `mapp()` guard alone (tried first) was NOT sufficient — confirmed
live that it still crashed identically, because the guard line is
never reached without the `catch()` (the runtime error unwinds straight
past it to the nearest existing catch, in `master.lpc`'s `preload()`).
**Verified**: rebooted, repeated the exact `bai zuo` → `cha zuo`
sequence — full skill list printed, zero runtime error, zero new
`debug.log` lines.

**2. (RETRACTED — content/design judgment call, not a programming bug;
reverted on user review) `d/death/gate.lpc` and `d/city/wumiao.lpc`'s
`init()` unconditionally wrote the player's permanent `startroom` on
mere room entry.** Originally flagged as an AGENTS.md §7.24 match and
fixed by deleting both `init()` bodies — since reverted. The key fact
that distinguishes this from the earlier `zzfy` §7.24 case: **both
rooms already flag themselves `valid_startroom` via their own
`create()`** — unlike `zzfy`'s revive-limbo rooms, which did NOT carry
that flag and so directly contradicted the lib's own gating convention.
Here, writing `startroom` on entry doesn't violate this lib's own
architecture at all; it's plausibly a deliberate "these are checkpoint
locations, entering one silently updates your home" design (the death
gate and a city temple both read as thematically plausible checkpoint
spots), even though it bypasses the normal player-initiated
`save`/`quit`-while-standing-here convention and gives no on-screen
confirmation. That's surprising UX, not a proven programming defect.
Left as originally shipped (both `init()`s restored), documented here
rather than silently re-fixed. `d/city/cangku.lpc`/`d/shaolin/cangku.lpc`
and the `d/shaolin/` jail-cluster rooms (also touch `startroom` on
capture/release) were separately confirmed to have genuine, matched
restore paths and were correctly never touched.

**3. Missing `/log/nosave/` runtime directory crashes `combatd.lpc`'s
`killer_reward()` on EVERY death, `kill.lpc`'s PK-attempt logger on
every player-vs-player `kill`, and `bai.lpc`/`apprentice.lpc`'s
Feng-Qingyang student counter (AGENTS.md §7.11, exact match — same
example directory the catalog entry already names)**

`work/log/nosave/` does not exist in this archive. Four call sites
write into it with a bare `write_file()`/no `assure_file()`/no
`catch()`:
- `adm/daemons/combatd.lpc:721` (`killer_reward()`, `KILLRECORD` —
  runs on literally every death, any killer/victim)
- `cmds/std/kill.lpc:37` (`ATTEMP_KILL` — runs on every `kill` where
  the target is a player)
- `cmds/skill/bai.lpc:57/65` and the identical duplicate
  `cmds/skill/apprentice.lpc:57/65` (`FENG` — a rarely-reached special-
  case counter, gated behind a separate bug, see #4)

**This is not a one-time cosmetic error — it's a live, reproduced,
severe softlock.** Confirmed by actually killing the `fluffos` admin
character in real combat (a 黑无常 NPC): `killer_reward()`'s
`write_file()` threw `*Wrong permissions for opening file
/log/nosave/KILLRECORD for append. "No such file or directory"`,
UNCAUGHT, which aborts `die()` at exactly that call — every statement
AFTER it (corpse creation, `remove_all_killer()`, moving the player to
`DEATH_ROOM`, setting the ghost flag) never ran. The character was
left standing in the combat room with 0 qi/jing, still "alive" by the
engine's bookkeeping, and the SAME crash then re-fired on every single
subsequent `heart_beat()` tick — an infinite crash loop, confirmed live
by watching it repeat identically 3+ times across one `score` check
before the fix.

Fix — the mudlib already has its own idiom for exactly this
(`assure_file()`, `adm/simul_efun/file.lpc:11`, already used by
`feature/save.lpc`) — used it at all four write sites instead of
introducing an out-of-band `mkdir`:
```lpc
// combatd.lpc, kill.lpc, bai.lpc, apprentice.lpc — pattern applied at
// each write_file("/log/nosave/...", ...) call:
assure_file("/log/nosave/KILLRECORD");   // (or ATTEMP_KILL / FENG)
write_file("/log/nosave/KILLRECORD", ...);
```
Also added a `stringp()` guard on the `FENG` counter's `read_file()`
result in both `bai.lpc`/`apprentice.lpc` (same file, same class of
risk as AGENTS.md §7.9 — `read_file()` on a not-yet-created file
returns `0`, which would otherwise flow into `atoi(0)`).
**Verified live**: rebooted, repeated the exact same admin-vs-gargoyle
fight to death — this time `die()` ran to completion cleanly (single
`你死了`, ghost title, corpse present, no repeated crash spam), and
`work/log/debug.log` stayed at its pre-fight line count throughout.

**4. `cmds/skill/bai.lpc` / `cmds/skill/apprentice.lpc` (identical
duplicate files) — misplaced parenthesis passes the WRONG ARGUMENT
TYPE to `query()`, so the Feng-Qingyang defection-counter check never
actually ran**

```lpc
// BEFORE (both files, same line):
if (((string)me->query("family/master_id" == "feng qingyang")) || ((string)me->query("family/master_name" == "风清扬"))) {
```
The `==` comparison is INSIDE the `query(...)` call's argument list,
so `query()` is actually invoked with a boolean/int (`0`, always false
for any real property name) instead of the intended string key —
`query("family/master_id" == "feng qingyang")` evaluates the
comparison first and passes its result, not the string, meaning the
branch could never fire regardless of the player's actual master.
Fixed to compare the RETURN VALUE of `query()` against the string, as
every other call site in the file already does correctly:
```lpc
// AFTER:
if (((string)me->query("family/master_id") == "feng qingyang") || ((string)me->query("family/master_name") == "风清扬")) {
```
Low real-world impact (only reachable for a player defecting FROM the
specific named master 风清扬/Feng Qingyang, a rare special case) but a
genuine, unambiguous programming bug — not a design question — since
the code's own structure makes its intent (compare a queried value to
a literal) unambiguous. Not separately live-exercised (would need a
character to actually be Feng Qingyang's disciple first, out of scope
for this pass) but confirmed by direct read that it now matches every
other correctly-written call site in the same file.

### Bug-class mapping (all four matched EXISTING AGENTS.md entries — no new class)

- Bug 1 → **§7.7** ("Unguarded `restore()` / corrupted save data",
  specifically its `restore_object()` zeroes-globals-on-failure
  bullet).
- Bugs 2 → **§7.24** ("Death/reincarnation code silently overwrites the
  permanent login-location field") — this pass found a SECOND, more
  severely-reachable instance of the exact same pattern in the same
  lib (an ordinary city room, not just the death limbo itself), and
  did the extra due diligence of checking every OTHER `startroom`
  write site in the lib against the same detection heuristic before
  concluding which were real bugs vs. legitimate matched capture/
  release mechanics (§7.24's own suggested check).
- Bug 3 → **§7.11** ("Missing runtime directories and the silent
  `write_file` abort") — this pass adds a concrete, live-reproduced,
  data point for the catalog's own example directory (`/log/nosave/`)
  and demonstrates the worst-case severity class explicitly: an
  UNCAUGHT crash mid-way through a multi-step cleanup function
  (`die()`) doesn't just fail once, it can leave the object in a
  broken state that re-triggers the same crash every `heart_beat()`
  forever.
- Bug 4: a plain misplaced-parenthesis wrong-argument bug, the same
  general shape as several "obviously-wrong call-site" fixes already
  cataloged elsewhere in this lib's own NOTES.md (§10.7 checklist item
  7's "obviously-wrong variable references" bucket) — not a numbered
  AGENTS.md class of its own.

### Process notes

Driver run from `libs/jqxz2008/` via `nohup ... &
disown`, restarted 4 times across the fix-iteration cycle (chinesed
fix alone → +bai.lpc paren fix → +gate.lpc/wumiao.lpc/§7.11 fixes →
final confirmation), each old PID killed only after confirming
`readlink -f /proc/<pid>/cwd` matched this lib's `work/` directory
(other agents' driver processes for `xiakexing2017`, `xlqy_new2007`,
`xo`, `shujian2008`, `xkxz2`, `zhonghua2` were running
concurrently throughout and were never touched). RSS stayed at
30-44MB across the whole ~10-minute final session, no unbounded growth
(§10.8 checked, nothing concerning). Final driver (PID 1718534) killed
by exact PID after all testing completed, confirmed via `ps`/`ss` no
longer showing port 40082.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

金庸群侠传引擎基础版（2008 加强版）。
