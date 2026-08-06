# 金庸文字版.exe → `jinyongwenzi` (TRIAGE ONLY — not converted)

- Archive: `archives/金庸文字版.exe` (5,310,958 bytes — archive #90 in TODO.md,
  flagged "may not be an LPC mudlib at all — triage first" since it's a
  Windows self-extracting exe, not a normal archive container).
- Duplicate: `archives/金庸文字版 (1).exe` is a **byte-identical** duplicate
  (`md5sum` `6054d74e855aa660559ee1efc5065287` for both, same size) — only
  the primary was processed, matching the existing "Duplicate archives" table
  in AGENTS.md which already lists this pair.
- `file`: `PE32 executable (GUI) Intel 80386, for MS Windows, UPX compressed,
  RAR self-extracting archive` — confirms AGENTS.md's existing note.

## Extraction — two attempts, one silently-broken

1. **`7z x` "succeeded" but is a trap**: it printed `ERROR: Unsupported
   Method` for 6,409 individual members (exactly the total file count) and
   `Sub items Errors: 6409`, yet exited having created every single file
   anyway — all 6,409 files landed on disk at **0 bytes**, correct names/
   timestamps, zero content. If you don't check file sizes after a 7z
   extraction of this SFX, you'd wrongly conclude the archive is full of
   empty stub files (or, worse, a fake/empty installer).
2. **`unrar x` extracts it correctly** — reports `All OK`, and 6,392 of the
   6,409 files came out non-empty (17 zero-byte files appear to be genuinely
   empty in the source, e.g. some `feature/*.c` stubs — not an extraction
   artifact, sizes match plausible real content elsewhere). **Lesson for
   future self-extracting .exe archives in this project: verify with `find
   <dest> -type f -size +0c | wc -l` vs total file count after EITHER tool,
   don't trust a clean exit code alone** — 7z's "Unsupported Method" here is
   a real, silent-failure-mode method 7z's implementation of whatever RAR
   compression variant this SFX uses doesn't support, but it still writes
   placeholder files and doesn't propagate a nonzero process exit in a way
   that's obviously fatal.

Extracted to `libs/jinyongwenzi/raw/` (via `unrar x`).

## What's actually inside — THREE bundled things, not one

```
金庸文字版/
├── shujian/              <- genuine LPC MudOS mudlib (35MB, ~4,915 .c + 130 .h)
├── PZmud462/              <- bundled "PZMUD" (zmud-like) Windows telnet client (4.0MB)
├── hy/                    <- client-side menu/trigger text files for that client (60K)
├── MudOS.exe, mudos.dll   <- prebuilt Windows MudOS 0.9.20 driver binary
├── cmud.exe               <- a second bundled telnet client
├── 金庸文字版(zmud).bat   <- launcher: `start mudos.exe config.sj` + `start PZmud462\zmud.exe`
├── 金庸文字版(cmud).bat   <- launcher: `start mudos.exe config.sj` + `start cmud.exe`
├── config.sj, mudos.ini   <- driver config (config.sj is a genuine MudOS 0.9.20 runtime config)
├── *.mid, MudRoom.INI, MUDCHAR.DAT, ...  <- client-side sound/UI assets for the bundled clients
└── color.c                <- loose file at top level, unrelated to shujian/ (not investigated further)
```

This is the "bundles multiple things (client + server)" pattern AGENTS.md's
pipeline step 2 already warns about, taken to its fullest extent seen so far
in this project: a complete turnkey Windows package — driver binary + mudlib
source + TWO alternative bundled telnet clients + auto-launch `.bat`
scripts — clearly meant to be double-clicked and immediately play as a
"local" experience, which is almost certainly why AGENTS.md's original
triage note speculated it might be "a standalone single-player text game,
not an LPC/FluffOS mudlib at all." **That speculation is not correct** — see
below.

## Determination: **GENUINE LPC MUDLIB** (do not convert without a dedicated pass — reporting only, per task instructions)

The `shujian/` subtree is unambiguously a real, playable-over-the-network
MudOS/LPC mudlib, not a single-player game:

- `shujian/config.sj` is a standard MudOS 0.9.20 runtime config (identical
  directive set/format to every other lib in this project — `mudlib
  directory : ./shujian`, `master file : /adm/single/master`, `simulated
  efun file : /adm/single/simul_efun`, etc.), decodes cleanly as GBK
  (`name : 书剑2002` — "Book and Sword 2002"; `书剑` = 《书剑恩仇录》, one of
  Jin Yong's novels, consistent with the archive's "金庸" (Jin Yong) framing).
- It declares **real network listener ports**: `port number : 5555` plus
  `external_port_1..5 : telnet 5555/2000/2002/2003/2004` — a networked
  multi-user telnet server, the opposite of a single-player game.
- `MudOS.exe`/`mudos.dll` is a prebuilt **Windows MudOS driver binary**
  (`mudos.ini` → `config=config.sj`), and both `.bat` launchers start
  `mudos.exe config.sj` FIRST, then separately launch a bundled telnet
  client (`PZmud462\zmud.exe` or `cmud.exe`) to connect to it as a second
  step — i.e. the "single-player feel" is just a convenience wrapper
  auto-launching a real client against a real locally-hosted server, not
  evidence the game itself is single-player.
- `shujian/adm/single/master.c` is a genuine MudOS master object: real
  applies (`connect()`, `compile_object()`, `crash()`, catch/log_file/
  write_file usage) matching every other lib's master file in this project.
- Directory tree under `shujian/` is fully mudlib-shaped: `adm/{daemons,etc,
  simul_efun,single,tmp}`, `cmds/{adm,app,arch,ass,debug,imm,leitai,skill,
  std,usr,wiz}`, `d/` (23 zone/domain dirs: baituo, city, dali, emei,
  hengshan, hmy, huashan, kunlun, mingjiao, shaolin, songshan, taishan,
  wudang, xiangyang, xingxiu, xueshan, etc. — Jin-Yong-novel sect/location
  names), `data/{board,group,login,npc,sos,user,wenxuan}`, `doc/{applies,
  build,cefuns,efuns,help,html,LPC,skill,story,wizhelp}`, `feature/`,
  `help/`, `include/{net,race}`, `inherit/{armor,char,food,item,medicine,
  misc,room,skill,weapon}`, `kungfu/{class,condition,skill}`, `log/`.
- 123 files matched `grep '^inherit'` in a spot sample, and room files under
  `d/` use the standard `set("short", ...)` idiom — real LPC object
  definitions, not compiled/opaque data.
- `shujian/adm/daemons/` has the exact daemon roster seen across this whole
  project's lib family (`securityd.c`, `logind.c`, `chinesed.c`, `combatd.c`,
  `channeld.c`, `commandd.c`, `moneyd.c`, network daemons, etc.) — same
  MudOS-lineage architecture as every already-converted lib here.
- Coincidental naming note: `libs/bxsj` (archive #4, `archives/bxsj.rar`,
  already DONE) is a *different* codebase that also self-identifies as
  "书剑" (there: "书剑天下"/"ShuJian MUD", mudlib root also literally named
  `shujian/`). This archive's mud calls itself "书剑2002" — related lineage/
  naming convention (both wuxia MUDs riffing on the same Jin Yong novel
  title), almost certainly NOT the same underlying codebase snapshot
  (different config port, different top-level bundle shape/client tooling),
  but worth cross-referencing if this archive is converted later.

**The `PZmud462/`, `hy/`, `cmud.exe`, `MudOS.exe`/`mudos.dll`, `*.mid`,
`.bat`, `.INI`/`.DAT` client-and-driver-binary material is NOT mudlib source**
and should be excluded/ignored the same way this project already ignores
bundled prebuilt drivers/clients in other archives (per AGENTS.md pipeline
step 2) — only `shujian/` (and its `config.sj`) is relevant to any future
conversion pass.

## Per task instructions: STOPPING HERE

Per the triage task's explicit instruction, since `shujian/` is genuine LPC
mudlib source in a mudlib-shaped tree, **no conversion, `work/` copy,
`config.fluffos`, port assignment, or driver boot attempt was made** — this
NOTES.md is a triage report only. If the main session decides to proceed,
the next steps would follow the standard pipeline (AGENTS.md pipeline
steps 2-7): confirm `shujian/` as mudlib root (already done here), assign a
port, copy to `work/`, run the encoding/`.c`→`.lpc`/`static`→`nosave`
passes, then compile/boot per usual. Not attempted in this pass.

## Recommendation for TODO.md (left to the main session to apply, superseded below)

Suggest updating archive #90's row from "not started / may not be an LPC
mudlib at all, triage first" to reflect the actual finding: it IS a genuine
LPC MudOS mudlib (`书剑2002`, root `shujian/`) bundled inside a self-
extracting exe alongside driver + 2 client binaries; ready for a normal
conversion pass whenever scheduled. `libs/jinyongwenzi/raw/` currently holds
the `unrar`-extracted tree (7z's extraction of this file is NOT usable —
see "Extraction" above, don't reuse a 7z-produced `raw/` for this archive).

---

# Conversion pass (this session) — Port **40083**. Status: DONE — boots clean, full registration + post-login commands confirmed working over telnet

## Lineage confirmation against `libs/bxsj` (archive #4) — SAME codebase, not just "related naming"

The triage pass above flagged this as "related lineage/naming convention,
almost certainly NOT the same underlying codebase snapshot" based only on
directory-shape/name similarity. A direct byte comparison proves that
call wrong — **this is the literal same codebase as `bxsj`** (`书剑天下`),
just saved with different line endings at some point in its history:

- `md5sum` on `adm/single/master.c`, `inherit/char/master.c`,
  `adm/daemons/securityd.c`, `adm/simul_efun/chinese.c`,
  `cmds/arch/chinese.c` differ raw (CRLF vs LF), but **`diff <(tr -d '\r'
  ...)` between bxsj's raw archive and this archive's raw `shujian/` is
  EMPTY (0 lines) for every one of those files** — 100% byte-identical
  content once line-ending noise is stripped out.
- Whole-tree comparison: 5,245 files exist at the same relative path in
  both raw trees; of those, 3,501 (66.7%) are byte-identical
  (CRLF-normalized) and 1,744 differ. bxsj also has 6,469 files this
  archive's `shujian/` doesn't have at all (bxsj is a larger, later-grown
  snapshot — same relationship bxsj1 already has to bxsj, just a
  different branch/point in time), and this archive has 1,071 files bxsj
  doesn't have.
- Conclusion: same lineage as the `bxsj`/`bxsj1` family (archives #4/#5),
  a genuinely different point-in-time snapshot/fork rather than a
  from-scratch "book and sword"-themed rewrite. Applied the exact 3 known
  `bxsj` fixes proactively per the playbook TODO.md already documents
  ("Once a lib's lineage is recognized ... apply known catalog fixes
  PROACTIVELY before the first boot attempt") — **and found this snapshot
  has TWO further bugs that bxsj/bxsj1 also have, unfixed and completely
  undetected there** (see "New findings" below — this is the important
  part of this pass for the rest of the project, not just this one lib).

## What was applied proactively, before ever booting (ported directly from bxsj/AGENTS.md, confirmed present via identical-file diff first)

1. **`adm/single/master.lpc` `log_error()`** (AGENTS.md §4 family): added
   the `logging_error` reentrancy guard + `catch()` around
   `CHANNEL_D->do_channel(...)`. Confirmed the identical unguarded call
   was present (byte-identical source to bxsj's pre-fix version).
2. **`adm/single/master.lpc` `valid_override()`** (AGENTS.md §14): added
   the 3rd `main_file` parameter, plus the
   `shout`/`write`/`tell_object`/`tell_room`/`say` allow-list, exactly as
   in bxsj.
3. **`adm/daemons/securityd.lpc` `valid_read()`** (AGENTS.md §8c): was
   `if (this_player()) user = this_player();` unconditionally — same
   bug/same file as bxsj, wrongly attributes a system-initiated
   `load_object()` (e.g. master lazily loading an unpreloaded daemon) to
   whatever player happens to be connected at the time, denying `/adm`
   reads a real root-euid caller was always allowed. Fixed to only
   fall back to `this_player()` when `user` has no resolvable euid/uid
   of its own.
4. **`adm/simul_efun/chinese.lpc` `is_chinese()`** (AGENTS.md §15h,
   applied here proactively for the first time instead of post-hoc):
   was checking GBK lead/trail-**byte** ranges (0xa1-0xfe etc), which
   silently never match now that `str[i]` returns a Unicode codepoint on
   this driver. Replaced with a CJK Unified Ideographs block check
   (`str[0] >= 0x4e00 && str[0] <= 0x9fff`). Note: this codebase's own
   `check_legal_name()` (which also has the GBK-byte-length-bound half of
   this bug, per bxsj's NOTES) turned out to have its ONE call site
   commented out in `logind.lpc` here — registration never actually
   invokes it in this snapshot, so that half of the fix was moot for
   registration specifically, but `is_chinese()` itself is still called
   live from several gameplay files (`artname.lpc`, `uweapon.lpc`,
   `bboard.lpc`, `ling.lpc`, `zhao.lpc`, `tiejiang.lpc`) so the fix was
   applied anyway.

## Routine per-lib mechanical steps (via `convert_lib.sh`)

- Encoding: 5,579 converted, 669 already UTF-8/ASCII, 34 skipped binary,
  33 lossy (spot-checked a sample of the lossy list — control-byte/name
  glitches in save-data `.o`/`.ppp`/`.w` files and a couple of NPC/map
  source files with stray invalid bytes; none were in the master/login/
  security compile path).
- `.c` → `.lpc`: 4,915 files. 0 uppercase `.C` stragglers (checked). 0
  un-converted GBK masquerading as `.lpc`/`.h` (checked with the
  `file -b` straggler sweep from AGENTS.md's Encoding section).
- 417 literal `.c"` refs auto-fixed, 0 left over.
- 6 local `#include <x.lpc>` angle-bracket includes converted to quoted
  form (AGENTS.md §8d), 0 absolute-path or `..`-relative angle includes
  found (checked, none present).
- `static` → `nosave`: 80 files.
- No extensionless-file/`.c`-backup pairs found (AGENTS.md §15ak checked
  explicitly across the whole raw tree — 0 hits, doesn't apply here).
- No `nosave`/`protected` compatibility-macro redefinition collision
  (§15z), no bare `array` declarations (§15f), no `LONELY_IMPROVED`-style
  flag (§15v), no phone-home license check (§15u), no `ed_start`/
  `ed_cmd`/`query_ed_mode` calls outside `doc/cefuns/` documentation
  stubs (§15ag) — all checked and confirmed absent/not applicable.

## §15c: `/adm/etc/preload` bare `.c` refs (found and fixed)

Two of the 14 preload entries were bare paths with a literal `.c` suffix
(`/adm/daemons/questd.c`, `/adm/daemons/cron.c`) — not caught by the
quote-anchored `.c"` auto-fixer since this is an unquoted plain-text data
file (exactly AGENTS.md §15c's documented shape). `master.lpc`'s
`preload()` does `file_size(file + ".lpc")` before loading, so
`"questd.c" + ".lpc"` = `questd.c.lpc`, which never exists — the daemon
would have silently never loaded, with zero error anywhere (preload()
just `return`s early). Fixed both entries to bare `questd`/`cron`
(matching every other entry in the file).

## §15p: excluded `network/dns_master` from preload

Removed proactively per standing policy, before the first boot attempt.

## §6: `log directory` — created `libs/jinyongwenzi/log/` (sibling of `config.fluffos`, not inside `work/`)

The shipped `config.sj` used `log directory : /adm/log`; simplified to
`/log` in `config.fluffos` (matching every other converted lib's
convention) and created `libs/jinyongwenzi/log/` at the driver's actual
launch CWD. Also proactively created a `log/nosave/` subdirectory
(missing from the raw archive, present in bxsj's copy — AGENTS.md §15ah:
`master.lpc`'s `crash()`/`log_error()` both write there) to avoid a
silent `write_file()`/`log_file()` failure if the driver ever crashes.

## New findings this pass — TWO bugs bxsj/bxsj1 ALSO have, unfixed and undetected there

Both were only caught because this pass followed §15ae's standing policy
literally (test a real post-login command, not just reaching the world) —
**bxsj's own NOTES.md explicitly stops at "reached ... the password
prompt", never tests a command after entering the game**, which is
exactly the blind spot §15ae warns about. Confirmed by direct file
comparison that bxsj's shipped `work/` has the *identical* unfixed source
for both of these:

1. **`feature/command.lpc`'s `command_hook()` was `private nomask`**
   (AGENTS.md §15ae, textbook case) — inherited into the player body via
   `F_COMMAND`, registered with `add_action("command_hook", "", 1)`, and
   on this driver a `private` function is unreachable by `add_action`'s
   external dispatch. Registration completed fine (driven by `input_to`,
   not `add_action`), the character reached the game world, and then
   **every single typed command — `look`, `score`, `quit`, everything —
   silently produced the default fail message** (`什么?`), with zero
   `debug.log` entry, indistinguishable from a hung connection. Fixed by
   dropping `private` (kept `nomask`). Also found and fixed the identical
   pattern in one NPC file, `d/city/npc/zhao.lpc`'s `change_name()`
   (registered via `add_action("change_name", "zhuce")`) — same fix.
   **Confirmed bxsj's `work/feature/command.lpc` still has this exact
   `private nomask` on `command_hook` today** — bxsj (and almost
   certainly bxsj1, same lineage) is very likely ALSO completely
   command-dead post-registration; flagging for the main session to
   decide whether to re-open those libs, out of scope for this task to
   fix directly.
2. **`adm/daemons/commandd.lpc`'s `rehash()` filters `get_dir()` output
   with `sscanf(cmds[i]+"$", "%s.c$", cmds[i])`** — a NEW bug pattern not
   yet in AGENTS.md's catalog, a variant of the classic `.c`→`.lpc`
   rename fallout but invisible to every existing detection method (it's
   not a quoted string literal `§2`'s auto-fixer or grep-for-`.c"` would
   catch, and it's not a bare-line data file `§15c`'s preload fix
   pattern covers either — it's a live `sscanf` format string that
   silently matches nothing once every command file is named `.lpc`
   instead of `.c`). Effect: `rehash()` filtered its OWN `get_dir()`
   listing down to zero files every time (nothing ends in literal
   `.c` anymore), so `search[dir]` was NEVER populated, and
   `find_command()` returned 0 for every verb, forever — which combined
   with bug #1 above to produce the exact same "every command does
   nothing" symptom via TWO independent, compounding root causes. Fixed
   by matching `"%s.lpc$"` instead. Grepped the whole tree for the same
   `sscanf(...,"%s.c$"/"%s.c",...)`-shaped pattern — only this one
   instance exists. **`bxsj`'s shipped `work/adm/daemons/commandd.lpc`
   has the byte-identical unfixed `"%s.c$"` pattern too** — same
   flagging-for-the-main-session note as bug #1; recommend adding this as
   a new AGENTS.md catalog entry (proposed §15ar) since it's a genuinely
   new class of `.c`→`.lpc` fallout distinct from §2/§15c, and checking
   every already-"done" lib in this lineage family for it.

Both of the above were root-caused by first restarting the driver after
the master/securityd fixes, completing a full interactive registration,
observing `look`/`score`/`quit` all silently returning `什么?`, then
reading `feature/command.lpc`'s dispatch chain end-to-end (find_command →
commandd.lpc → rehash) rather than assuming it was one bug — the two
compounded, and fixing only one of them (either one) would still have
left the lib completely uncommandable after registration.

## Cosmetic bug also fixed (not fatal, but noisy on every login/logout)

`adm/daemons/logind.lpc`'s `enter_world()` and `clone/user/user.lpc`'s
`net_dead()` both called `CHANNEL_D->do_channel()` passing a non-player
object as the "who" argument (`this_object()` = the logind daemon itself,
and `load_object(LOGIN_D)` respectively, instead of the real player) —
neither defines `query("channel_id")`, so `channeld.lpc`'s fallback path
(`me->query("name") + "(" + capitalize(me->query("id")) + ")"`) crashed
on `capitalize(0)` on literally every single login and every single
disconnect (caught by the driver's own error handler, non-fatal, but
spammed `debug.log` and the "err" channel on every connect/disconnect).
Fixed both call sites to pass the actual player object, matching every
other correctly-written `do_channel()` call site elsewhere in the same
tree.

## Confirmed NOT needed (checked, found absent/inapplicable)

- §15l (`SIMUL_EFUN_OB` destruct/reload bootstrap trick in master
  `create()`) — not present, `create()` is a one-line `write()`.
  §15o (`get_include_path()`) — missing from master, same as bxsj/bxsj1
  (neither needed it either); no `#include` failures observed in any
  mid-connection compile during testing, so not added speculatively.
- §15n (securityd `valid_read` blocking compile-time reads) — the ported
  §8c fix already handles the relevant shape; no compile-time read
  denials observed.
- §8e (`tail` efun) — `cmds/app/tail.lpc` defines its own `tail()`
  function, unrelated to the (nonexistent) efun of the same name.
- §7 (`get_root_uid()`/`get_bb_uid()`) — both already present and correct
  in `master.lpc`.
- §15ao (switch with only `default:`) — none found.
- §15t (`#include` absolute-path/`..`-relative/inherit-ordering
  failures) — none of the three shapes found.

## Boot result

Clean boot, zero fatal errors. `debug.log` shows only expected compile
*warnings* (unused locals, "Illegal to declare nosave function" on
functions that are legitimately `nosave`-annotated per this codebase's
own convention — cosmetic, harmless).

**Update (2026-07-24, WASM long-sit boot-watch, AGENTS.md §7.9 class,
FIXED)**: a previous pass of this note logged `questd.lpc`'s
`read_table()` `explode()`-on-`0` preload error as a MySQL-environment
gap and left it unfixed — that diagnosis was a guess, not verified
against the source (`questd.lpc` has no `MYSQL`/`__USE_MYSQL__`
reference anywhere, and its `create()` has no `catch()` of its own; the
error was only ever caught by `master.lpc`'s generic `preload()`
wrapper). The real root cause: `read_table("/quest/dynamic_quest")`
and a second unguarded call two lines later
(`roomlines = explode(read_file("/quest/dynamic_location"), "\n")`) both
feed `read_file()`'s result straight into `explode()` with no
`stringp()` guard — classic AGENTS.md §7.9 shape. `/quest/` doesn't
exist ANYWHERE in this archive (not a fresh-checkout gitignore gap,
a genuine missing directory), so both calls always error, on every
single boot, every time. Fixed both sites in
`adm/daemons/questd.lpc` (`read_table()`'s `line = ...` assignment and
`create()`'s `roomlines = ...` assignment) to guard with `stringp()`
and fall back to `({})` — matches `read_table()`'s own natural
"no data" return shape, and `init_dynamic_quest()`'s
`for (i = 0; i < sizeof(quests); i++)` loop already no-ops cleanly on
an empty `quests` array (never reaches the `roomlines[random(...)]`
indexing that would otherwise need `roomlines` to be non-empty).
**Verified**: fresh WASM long-sit boot-watch (200s) shows zero runtime
errors of any kind (previously the one caught questd hit); native
registration + `look` + `score` + `quit` (id `qinfengw`, Chinese name
秦风) still works end-to-end with no new regressions. Quest-spreading
itself (`spread_quest()`) simply never fires without the missing
`/quest/dynamic_quest` seed data — same as before, but now via a clean
early return instead of a caught runtime error on every boot.

## Full registration + post-login test transcript (ONE continuous connection)

```
cd libs/jinyongwenzi
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40083 --timeout 30 --idle 0.5 \
  --send "qinfengc" --send "y" --send "秦风" --send "" --send "y" --send "1" \
  --send "look" --send "score" --send "quit"
```

- ID prompt: `qinfengc` (a fresh, letters-only 3-8-char English ID; the
  lib requires this specifically — a numeral in the ID, e.g. `qinfeng2`,
  is correctly rejected: "对不起，您的英文名字只能用英文字母").
- `y` confirms creating a new character under that ID.
- Chinese name prompt (`您的中文名字：`) — sent the real Chinese name
  **秦风**, accepted with no rejection/mojibake.
- An empty `""` send is required next (this codebase's `select_gift()`
  ignores its own input and immediately shows the first random stat
  roll — a quirk of this snapshot's flow, not a bug).
- `y` accepts the offered stat roll (膂力/悟性/根骨/身法).
- `1` selects a starting skill ("一阳指" — One Finger Zen, an actual Jin
  Yong kung-fu technique, confirming the wuxia theming is intact).
- Character lands in the actual game world (`第一关` — "Level One", a
  real starting room with a full description, visible exits, and
  ambient items).
- `look` **correctly redisplayed the full room description** (matches
  the auto-shown description on room entry, confirming the command
  actually dispatched rather than coincidentally matching).
- `score` **correctly displayed the full character sheet**
  (`书剑个人资料卡`) with the real registered name `秦风(Qinfengc)`,
  stats (膂力/根骨/身法/悟性), age (十四岁), gender (男性), etc. —
  genuine dynamic output, not a static string.
- `quit` correctly began logout (`正在退出游戏……`).
- `debug.log` for this session shows zero new errors (only the
  pre-existing questd preload one, from before this connection even
  started).

## `lpcc_check.sh` sweep

`total=4915 pass=4866 fail=49` (99.0% pass). Failure categories, all
matching known pre-existing-content-gap shapes already seen across this
project (none in the master/login/security compile path, none newly
introduced by this pass's fixes):

- 9 optional network/intermud daemon files (`adm/daemons/network/*` —
  `ms`, `userid`, `pingtcp`, `name_server`, `mail_serv`, `netmail`,
  `telnetd`, `pingd`, `inetd`) — expected, these are exactly the family
  `dns_master` belongs to (AGENTS.md §15p), never preloaded, never
  reachable from the live game.
- 2 expected `#include`-fragment false positives (`adm/simul_efun/
  message`, `adm/simul_efun/object` — AGENTS.md §6b, meant to be
  `#include`d INTO `simul_efun.lpc`, not compiled standalone; harmless,
  confirmed by the clean real boot).
- 5× `Bad type for argument 1 of is_killing` (object vs string) — same
  shape as bxsj/bxsj1's identical un-triaged category.
- 12× `Undefined variable 'skill2'`, 4× `'look_feng'`, and similar —
  scattered kungfu-skill/NPC content-specific gaps (missing shared
  variable definitions in a handful of `kungfu/skill/*` and `d/*/npc/*`
  files), consistent with AGENTS.md §13 (missing zone/room content is a
  real archive gap, not a conversion bug).
- 7× `Undefined function set` / 5× `Undefined function query` — the
  known simul_efun-based generic property-storage architecture gap
  (AGENTS.md §15).
- 5× `Cannot #include uid.h`, 3× `config.h`, 2× `mailer.h`, 2×
  `daemons.h` — missing optional headers for features not wired up in
  this snapshot (mail/postal system: `member_group`, `data_netmail_file`,
  `POSTAL_D`, `MAILDIR`, `DIR_POSTAL` all undefined — same optional-mail-
  daemon-cluster gap already seen on other libs in this family).
- Remainder: isolated one-off content typos in individual NPC/room/skill
  files (`/feature/vi`, `/feature/sadjust2`, several `d/wudang/taoyuan/
  tyroad*`, `d/dali/job/*`, etc.) — not individually triaged, matching
  this project's stated breadth-over-depth policy for a ~100-archive
  batch job.

Full failure list: `libs/jinyongwenzi/lpcc_fail.log` (49 entries,
1317 lines with full compiler output).

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **LPC formatter**: ran `format-corpus.mjs` over all 4,915 `.lpc`
  files — 4,873 reformatted in place, 30 already-idempotent, 12 refused
  (nonzero `errors` expected/fine per the tool's own contract).
- **Native retest against rebuilt driver** (`~/src/fluffos/build-debug/
  src/driver`, freshly rebuilt from upstream master): booted clean,
  zero fatal errors (only the pre-existing, already-documented
  non-fatal `questd.lpc` `read_table()` `catch()` hit and routine
  compile warnings). Full registration re-verified with a fresh real
  name (秦风丁) via the documented flow (letters-only id → confirm →
  Chinese name → empty send → accept stats → pick skill → arrives in
  第一关); `look`/`score`/`quit` all produce correct dynamic output. No
  regressions from the rebuilt driver or the reformat pass; nothing to
  fix. (Also double-checked: `qinfengc2`-style numeral-containing ids
  still correctly get rejected and desync the scripted send sequence —
  same pre-existing id-validation behavior/test pitfall as before, not
  a regression.)
- **WASM build test** (`scripts/wasm_client.js` against
  `build-wasm/src`): boots cleanly in-process, only ordinary compile
  warnings. Full registration/login flow completed successfully under
  WASM too (fresh name 秦风戊, same flow as native), `look`/`quit` also
  correct — this lib has no IP/site-gating daemon on its login path,
  so it is **not** affected by the documented `query_ip_number()` WASM
  limitation and is fully playable under WASM.

## How to run

```
cd libs/jinyongwenzi
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40083 --timeout 30 --idle 0.5 \
  --send "someid" --send "y" --send "真实中文名" --send "" --send "y" --send "1" \
  --send "look" --send "score" --send "quit"
```

## WASM-enablement pass (loopback-allow / uptime / throttle / admin seed)

Standard pass per AGENTS.md §1.3(b)/(e), §1.5.

**Gates patched:**
- `adm/daemons/logind.lpc` `logon()` (~line 92): per-IP anti-flood cap
  (`login_cnt > 3` same-IP login objects → silent destruct) now skipped
  for strict loopback (`127.0.0.1`/`localhost`/`::1`/`127.*`) only.
- `adm/daemons/band.lpc` `is_banned()` (~line 39): strict-loopback
  short-circuit `return 0` (defensive; called on login path in sibling
  builds).
- `adm/daemons/sited.lpc` `is_valid()` (~line 126): strict-loopback
  short-circuit `return 1` (replaces the original commented-out loopback
  block which DENIED non-wiz loopback).
- **Fail-closed correction (retrofit):** all three gates above were
  initially written with a `!stringp(ip)`/`ip == ""` "treat malformed IP
  as loopback" fallback per the original (pre-driver-fix) instructions.
  Since `query_ip_number()`/`resolve()` are now fixed upstream and always
  return a clean `127.0.0.1` for loopback, that fallback was tightened to
  strict equality/prefix checks only — a malformed/non-string IP now
  falls through to the original gate logic (fail closed) instead of being
  waved through.
- Uptime startup gates: none in this lib (rankd uptime uses are content
  timers, kept).

**Cold-relogin fix (real pre-existing bug exposed while seeding admin):**
`adm/daemons/securityd.lpc` `valid_read()` — added an own-save-file
exception for `func == "restore_object"` mirroring `valid_write()`'s
`save_object` exception. Without it, the cold-relogin path
(`logind.lpc` get_passwd → make_body → `user->restore()`, body has uid
but no euid until `enter_world()`'s exec/setup) got
"restore_object: read permission denied: /data/user/...o", and the
returning player landed in a body whose command path was never set
(every command answered "什么?"). Hot/netdead reconnect was unaffected,
which is why earlier passes (which only tested reconnect) never saw it.

**Admin account:** id `fluffos`, pw `Mud@2026` (this snapshot does not
verify passwords on login — original upstream edit), name 浮浮, granted
`(admin)` via `adm/etc/wizlist` (rewrote file LF-only; the old CRLF
endings made every parsed level end in `\r` and match nothing).
Verified: relogin as fluffos, `update /adm/daemons/band` → 成功,
admin-channel tag 【仙人】 shown. Save files (untracked but NOT
gitignored — orchestrator must add): `work/data/user/f/fluffos.o`,
`work/data/login/f/fluffos.o`.

**Retest:** fresh registration (id ceshiyi, name 秦风壬) end-to-end OK —
look/score/quit all correct; test char saves removed afterwards. Only
pre-existing caught questd preload error in debug.log; no new errors.

## Proactive fix (2026-07-24): rank-decay loop crashed every `quit` (AGENTS.md §7.16/§10.7)

Found while pattern-matching a bug discovered on lineage sibling `bxsj`
during that lib's first deep functional playthrough (AGENTS.md §10.7
methodology), before ever booting this lib for the check.
`cmds/usr/top.lpc`'s `add_rank()` decays a stale rank entry's score via
`while (ranks[i]["time"] + 3600 < t) { ... }` with no iteration cap. The
shipped `work/log/rank.o` carries a real timestamp from 2007
(`"time":1181487290`), so any boot against today's wall clock runs the
loop ~170,000+ times and blows the eval-cost limit.
`cmds/usr/quit.lpc:139` calls `TOP_CMD->add_rank(me)` unconditionally on
every `quit` — so every `quit` was silently crashing (driver's error
handler swallows it; the player-visible "正在退出游戏……" message looks
normal). Fixed the same way as `bxsj`: cap the loop at 240 iterations
(~10 days of decay, enough to crush any stale score near zero) and
unconditionally advance the stored timestamp to `t` afterward regardless
of whether the cap was hit. Compile-checked clean via `lpcc --batch`; not
re-verified live in this lib specifically (verified live on `bxsj`, the
source of the pattern) — flagging per §10.7 point 6 rather than silently
claiming a live retest.

## 深度功能测试 / Deep functional test (2026-08-06)

第一次完整游玩测试（原生驱动 `build`，ASAN/UBSAN debug 构建）。测试角色
id `jyxtest`，中文名 云飞扬，起手绝学选择「太极拳」（选项 4）。本轮
WASM 未重新验证：emsdk 工具链下载硬编码指向 `storage.googleapis.com`，
本次会话的出口代理策略性拒绝该域名（403，已用 `curl
$HTTPS_PROXY/__agentproxy/status` 确认是策略拒绝而非临时故障），本地无
法构建 WASM 驱动。

### 发现并修复：`natured.lpc` 的 `event_morning()` 缺失 `objectp()` 守卫，导致日夜循环心跳永久停摆（新 AGENTS.md §7.63 追加实例）

- **症状**：真实游玩触发（连续通过「第一关」监狱越狱剧情的 3 场剧情战
  斗后），`debug.log` 出现 `*Bad argument 1 to EFUN call_other()
  Expected: object, string, array, Got: int(0)`，栈追踪指向
  `adm/daemons/natured.lpc` 第 386 行（`event_morning()`）由
  `update_day_phase()` 第 132 行通过 `call_other()` 触发。
- **根因**：`event_morning()` 的 15 个 `if (random(8) == N) { ... }`
  天气事件分支各自生成 2-8 个「外敌奸细」NPC（`badguy =
  new("/quest/weiguo/<国家>/<文件>N")`）。每个分支里第一个 `new()`
  （boss 变体）都正确用 `objectp(badguy = new(...)) &&
  badguy->move(room)` 守卫，但同一分支后续的 2-6 个小兵变体
  一律是裸 `badguy = new(X); badguy->move(room);`（全档案共 40 处）。
  `find work/quest/weiguo` 确认这整棵目录树在这份快照里根本不存在
  ——`new()` 必然返回 0，紧接着的 `->move()` 崩溃。因为这次
  `call_other()` 崩溃发生在没有 `catch()` 包裹的调用里，
  `update_day_phase()` 自己在崩溃点之后的收尾代码
  （`remove_call_out`/重新 `call_out("update_day_phase", ...)`）根本没
  机会执行——也就是说，只要 `event_morning` 某次 `random(8)` 抽中任何一
  个未存档的分支，整个驱动的日夜循环心跳就会永久停摆，不只是这一次生
  成失败。
- **修复**：机械化地把所有 40 处裸 `badguy = new(X); badguy->move(room);`
  改写为 `if (objectp(badguy = new(X))) badguy->move(room);`，与同一
  代码块里本来就有守卫的兄弟调用保持一致写法。修复后用
  `find ... -name '*.lpc' | node .../format-corpus.mjs` 跑过§9格式化
  自检（unchanged，无需改动），并逐行 grep 确认 `event_morning()` 范围
  内不再有任何裸 `badguy = new(...)` 紧跟 `badguy->move` 的组合。
  `event_afternoon()` 里对应的清场逻辑用的是 `children()`，本身对不存
  在的文件天然安全，未改动。
- **验证**：修复前先用真实游玩重现了一次崩溃（debug.log 有完整栈追
  踪）；修复后 `lpcc`/驱动重启编译干净（这份档案里 `natured` 常驻且总
  有未完成的 `call_out`，`update` 指令的向导会直接拒绝热更新常驻精
  灵——`cmds/imm/update.lpc:40-44` 检测到 pending call_out 就直接
  `return 1` 放弃编译——所以走的是完整重启驱动来加载新代码，而不是热
  update）。重启后确认无新增运行时错误；`event_morning()` 本身要等游
  戏内真实经过一次「早晨」阶段才会被再次调用（`day_phase` 配置的阶段
  长度以真实秒计，累计要等相当长时间），这次会话的时间预算内没有等到
  再次触发同一分支来现场复现"修复后不再崩溃"——但修复本身是严格机械
  化的、且与同一函数里另一处已经在正常工作的守卫写法完全一致，可信度
  高，如实记录未能重新触发验证这一点，而不是假装已验证。
- 已在 AGENTS.md §7.63（"one caller of new(X) missing the guard that
  every sibling call site already has"）追加了这个实例，因为它是同一
  个错误模式在更大规模下的例子（40 处而非 1 处），且根因（整棵内容目
  录缺失）比 §7.63 原案例（原因不明的 `new()` 失败）更容易在其它档案
  里复现和识别。

### 发现并修复：`回车一次即可进入`提示与实际代码行为矛盾——按提示操作反而进不去

- **症状**：已注册账号重新连线时，`adm/daemons/logind.lpc` 明确提示
  "回车一次即可进入"（本档案密码校验代码已被原作者删除，任意输入均
  可登录，这是保留的历史设计——见 README），但真的只按回车（空字符
  串）时，代码却把你送回"您的英文名字(ID)是："重新输入 ID，不会登录。
  用任意非空字符（哪怕一个字母）代替空回车则能正常登录——与 README
  文档的"任意输入均可登录"部分相符，只有"空输入"这一种情况被排除在
  外，而这恰好是提示语言唯一明确建议的操作。
- **根因**：`get_passwd(string pass, object ob)`（`logind.lpc:211`）开
  头有 `if (pass == "") { ob->delete("id"); write("您的英文名字(ID)
  是："); input_to((: get_id :), ob); return; }`——这段代码在整个文件
  里只有唯一一个调用方（`logind.lpc:183` 的
  `input_to("get_passwd", 1, ob)`，紧跟在打印"回车一次即可进入"之
  后），逻辑上明显是删除密码校验之前遗留下来的旧分支：那时这个函数大
  概率还承担"输入密码"职责，空输入自然应该打回重新输入。密码校验被
  整段删除、调用方文案也改成"按回车即可"之后，这个旧的空输入特判没
  有同步移除，从而和新提示的意图直接相反。`grep` 确认同目录下
  `logind2.lpc` 有完全相同的死代码副本，但全档案没有任何地方
  `inherit`/引用 `logind2.lpc`（真正生效的 `LOGIN_OB` 只解析到
  `logind.lpc`），故未改动这份从未被使用过的重复文件。
- **修复**：删除 `logind.lpc` 里这段孤立的 `if (pass == "") {...}`
  分支，让空输入和其它任意输入一样直接往下走正常的登录/重连流程。
- **验证**：用管理员账号 `fluffos` 现场复现了修复前的问题（按提示裸
  回车 → 弹回 ID 重新输入提示 → 超时踢出）；`update
  /adm/daemons/logind` 热更新编译成功后，用新连接重新尝试裸回车登
  录，正确进入"人物目前正在游戏当中，是否取代"确认流程（因为原会话
  仍连着），证明修复后空输入确实按提示所说的那样被当作"确认登录"处
  理，不再被踢回 ID 输入。

### 测试内容与结果

- **注册**：英文 ID（`jyxtest`）、密码不校验（原始设计，未改动）、中文
  名（云飞扬）、天赋随机摇点（回车确认）全程无错误，注册流程与
  `bxsj`/`bxsj1` 系同源但独立实现（没有 BIG5 编码选择提示）。
- **起手绝学**：新角色开局即可从"一阳指/九阳神功/易筋经/太极拳/白手起
  家"中任选其一（本轮选太极拳），立即获得对应的基础技能组
  （`cuff`/`dodge`/`force`/`parry` 四项基本技能 + `piaoyi-shenfa`/
  `taiji-quan`/`yinyun-ziqi` 三项特殊武功）——`skills` 命令确认发放正
  确，非 bug。
- **剧情战斗（"第一关"越狱情节）**：连续三场由房间/剧情驱动的强制战斗
  （分别对阵 1 名、3 名、2 名"监狱第六代狱卒"），全部靠角色自身技能
  （无需玩家手动 `fight`/`kill` 指令，走到房间即自动触发对战）胜利，
  过程中气血最低降到约 64%，未出现死亡风险；战斗系统本身（招式描述、
  闪避/格挡/命中判定、经验/潜能结算）全程无崩溃、无异常。
- **持久化**：完整 `quit`（在非战斗状态下，`is_fighting()` 守卫按预期
  正常放行）之后重新登录，正确恢复到退出时所在的房间（却日殿）——一开
  始怀疑这是"每次重连都被强制送回起点"的持久化 bug，追踪
  `enter_world()`/`quit.lpc` 的 `startroom` 读写逻辑并现场复现后确
  认：房间本身会在有角色进入时（含重连復位）重新生成守卫 NPC，与地点
  持久化无关，是设计内的"守卫巡逻/重生"机制，不是 bug。
- **管理员账号**：`fluffos`/密码任意非空字符串均可登录，显示"您目前的
  权限是：(admin)"（README 已注明本档案密码不校验）。
- **经济/商店、门派/师承、死亡/复活**：**未覆盖**——这份快照走的是剧
  情驱动的越狱关卡开局，而非 `bxsj` 系那种一开始就在武馆自由活动的沙
  盒式新手村，传统的 `bai`/`menpai` 拜师系统在测试范围内的场景没有出
  现（起手绝学替代了拜师流程，见上）；商店与死亡系统留给后续测试覆
  盖，如实标注为未覆盖而非默认判定为正常。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

此前被错误标记为某个不存在于本项目任何档案的原始压缩包文件名的 duplicate_of；这里的内容其实是完全独立、可游玩的游戏（有自己的 -N 变体编号、自己的端口、自己的 README）——duplicate_of 已清除。
