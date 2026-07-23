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
own convention — cosmetic, harmless) plus one pre-existing, non-fatal,
caught runtime error during preload:
`/adm/daemons/questd.lpc` `read_table()` calls `explode()` on a `0`
(likely expects a MySQL-backed table this sandboxed environment doesn't
have — `__USE_MYSQL__` is predefined but there's no real MySQL server;
questd's own `create()` already wraps its `read_table()` call in a
`catch()`, so this is a pre-existing content/environment gap, not a
driver-compat bug, and doesn't block anything else). Not fixed, logged
as a known issue (quest-tracking daemon likely non-functional without a
real MySQL backend).

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

## How to run

```
cd libs/jinyongwenzi
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40083 --timeout 30 --idle 0.5 \
  --send "someid" --send "y" --send "真实中文名" --send "" --send "y" --send "1" \
  --send "look" --send "score" --send "quit"
```
