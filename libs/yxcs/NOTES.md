# yxcs — 浴血重生 (archive #62)

Archive: `archives/浴血重生MUD.rar`. Port: **40056**. Status: **done**
(boots clean, full registration flow verified end-to-end with real Chinese
names, reaching an actual game room; lpcc sweep at ~98%+ pass).

## What this is

The mudlib's own `config.cfg` self-identifies `name : 1.YXCS` — "YXCS" is
the pinyin initialism of **浴血重生** ("Bathed in Blood, Reborn"), matching
the archive's own title exactly. The live in-game banner also prints
"浴血重生(2.YXCS)". No slug discrepancy worth noting.

Archive layout: the actual mudlib root is nested one level down at
`raw/socket/yxcs/` — `raw/socket/` also bundles several unrelated Windows
binaries alongside it (`MudOS.exe`, `serv-u/` — a cracked FTP server
installer + keygen, `superscan/` — a 2000s-era network port scanner). These
are contemporary "toolbox" bundling from whoever originally distributed
this archive, not part of the mudlib at all — ignored entirely, only
`raw/socket/yxcs/` was copied into `work/`.

13,452 raw files / 11,995 `.lpc` after conversion — a normal-to-large-sized
lib, well below the "mega-lib" bracket (AGENTS.md §6b) that would call for
skipping the full lpcc sweep.

## Lineage

A genuine **hybrid** of two lineages already seen elsewhere in this
project, not a clean match to either:

- `adm/simul_efun/chinesed.c`-equivalent (`adm/daemons/chinesed.lpc`)
  credits **"by Annihilator@ES ... modified by Xiang@XKX ... modified by
  Securityd"** — the ES/XKX ("ES II") lineage credit chain shared with
  `es1_win`/`esI`/`xkx2001`/`rzrmud`/`xo`/`bmxkx2001`/
  `kxkj`/`yueyingqiyuan`/`wuhanzhan`.
- `feature/dbase.lpc`, `adm/daemons/named.lpc`, and `include/globals.h`
  (`// for 1.YXCS mudlib, by lonely`) all credit **"Lonely"** — the same
  author as the "NT/nitan/Lonely" lineage (`nitan170911`/`nitan6`/
  `nitan_ceshi`/`nitan_san`). Confirms via authorship comments what the
  layout (`adm/obj/{master,simul_efun}`, `adm/daemons/`, `adm/simul_efun/`)
  already suggested: this looks like an ES-derived base that "Lonely" (the
  nitan-family author) built this specific game on top of, independently
  of the later nitan/kernel-layout snapshots.
- **Confirmed the core §15 dbase architecture bug does NOT apply here**:
  `feature/dbase.lpc` already has real, local `set`/`query`/`delete`/`add`/
  `_temp` variants (not bare simul_efun calls) — this predates or never
  needed that bug, same conclusion as `nitan_ceshi`/`nitan_san` (both
  earlier/distinct snapshots). No MySQL backend requirement either.

## Fixes applied, and why

### 1. NEW bug class: `#define nosave static` / `#define protected static`
   guarded by an LPC macro this driver never predefines — silently
   converts nearly every `nosave function` in the lib into `static
   function` (a hard parse error, AGENTS.md §3)

`include/globals.h` (and identical copies in `adm/obj/master.lpc`,
`adm/obj/simul_efun.lpc`, and 4 files under a `u/lonely/` backup tree) had:
```c
#ifndef __SENSIBLE_MODIFIERS__
#define nosave static
#define protected static
#endif
```
`__SENSIBLE_MODIFIERS__` (double-underscore, LPC-visible) is **never**
predefined by this driver to LPC code (confirmed: only mentioned in
`~/src/fluffos/src/local_options.README` as a suggestion, never actually
`#define`'d anywhere reachable from LPC) — so this `#ifndef` branch always
fires. Since this driver DOES support `nosave` as a real (soft-warning-only)
function modifier and rejects `static` on functions with a hard parse error
(empirically verified: `static int foo(){}` → hard error, `nosave void
foo(){}` → soft "Illegal to declare nosave function" warning only), this
macro would have converted the vast majority of this lib's own `nosave`
function declarations into an immediate, near-universal boot-blocking
parse error.

**Caught by luck, then fixed properly**: `convert_lib.sh`'s blanket
`\bstatic\b` → `nosave` sed (§3's standard fix) also fired on the word
"static" *inside this macro's own replacement text*, turning `#define
nosave static` into `#define nosave nosave` — a self-referential macro
that the C preprocessor's "blue paint" rule resolves as a no-op (leaves
`nosave` as itself), which accidentally neutralized exactly half the
problem. But it also turned `#define protected static` into `#define
protected nosave`, silently changing `protected`'s semantics
(`DECL_PROTECTED` → `DECL_NOSAVE`) instead of leaving it alone. Verified
`protected` is a fully legal, real modifier on this driver on its own
(`protected int foo(){}` compiles clean, no warning) — so the correct fix
is to let BOTH pass through completely unchanged, not alias one to the
other. Rewrote all 7 files' macro block to:
```c
#define nosave nosave
#define protected protected
```
Spot-checked afterward: `grep -rn '\bstatic\b'` across the whole `work/`
tree now only matches my own new comments, confirming no other lingering
`static`-as-function-modifier collateral.

### 2. §15h (is_chinese / check_legal_name GBK byte-range bugs)

- `adm/simul_efun/chinese.lpc`'s `is_chinese()`: `strlen(str)>=2 &&
  str[0]>160 && str[0]<255` → `strlen(str)>=1 && str[0]>=0x4e00 &&
  str[0]<=0x9fff` (CJK codepoint range, matches every other lib in this
  project).
- `adm/daemons/logind.lpc`'s `check_legal_name()`: bounds `strlen(name) <
  2 || > 10` (byte-count, matching the message's real intent "1 到 5 个
  中文字") halved to `< 1 || > 5` (character-count); dropped the `i%2==0
  &&` guard on the per-character `is_chinese(name[i..<0])` loop (was
  landing on alternating GBK lead-byte offsets, now every index is
  already one full character).
- `adm/daemons/named.lpc` (the classic nitan-family `named.lpc` shape,
  present here despite the different dbase architecture — genuinely
  **dead code**, see below): `PATH(name)` macro's `name[0..1]` ("first GBK
  char") → `name[0..0]`; `strlen(name) < 2` → `< 1` (×3 call sites);
  `strlen(name) < 4` → `< 2`; sliding-window `name[i..i+3]`/`name[i..i+5]`
  (4-byte/6-byte = 2-char/3-char windows) → `name[i..i+1]`/`name[i..i+2]`;
  loop bounds `i <= l - 4` → `i <= l - 2`, `i + 6 <= l` → `i + 3 <= l`.
  **Confirmed dead**: `NAME_D` macro is defined in `globals.h` but grepping
  the entire `work/` tree finds zero call sites anywhere (`NAME_D->...`) —
  fixed anyway as cheap insurance per standing policy, consistent with the
  identical finding on `wmkj` (#55).

### 3. §14 (`valid_override` needs the 3-arg signature)

`adm/obj/master.lpc`'s `valid_override(file, name)` upgraded to
`valid_override(file, name, main_file)`, checking both `file` and
`main_file` against `SIMUL_EFUN_OB`/`MASTER_OB`.

### 4. §15w (`log_error()` conflates warnings with real errors)

`adm/obj/master.lpc`'s `log_error()` unconditionally showed the scary
"编译时段错误：..." message to whatever player happened to be connected
for EVERY compile diagnostic reaching the apply, including harmless soft
warnings (e.g. this driver's own `nosave`-function warning, `#pragma`
warnings, unused-variable warnings — all very common in this lib). Gated
the player-facing write on `strsrch(message, "warning:") == -1`, matching
the `wuhanzhan` (#58) precedent. Everything still logged to the log file
regardless.

**Confirmed NOT needed**: `error_handler()` already unconditionally does
`efun::write_file(LOG_DIR + "debug.log", standard_trace(...))` at the end
of its own body (no "falls through automatically" assumption relying on a
non-existent return-value path) — the §15w "add a permanent
RUNTIME_ERRORS insurance write" follow-up wasn't needed here.

### 5. NEW: `#8e` (`tail`) — fatal here since it's inside the composed
   simul_efun compilation unit

`adm/simul_efun/file.lpc`'s `tail(string file)` called `efun::tail(file)`
— never a real FluffOS efun. Reimplemented in plain LPC (read_file +
explode on `\n` + slice last 20 lines + write), same pattern as every
other lib. Also fixed an identical copy in `u/lonely/sec/file.lpc` (an
unused wizard-homedir backup copy, not on the live compile path, fixed for
consistency). Confirmed dead/rarely-used admin tooling — no live callers
found anywhere in the tree.

### 6. §15s (`tell_room()`'s bare `message()` 4th-arg bug)

`adm/simul_efun/message.lpc`'s `varargs void tell_room(mixed ob, string
str, object *exclude) { if(ob) message("tell_room", str, ob, exclude); }`
— when called in the common 2-arg form, `exclude` defaults to bare `int
0`, which this driver's `message()` (4th arg typed `void | object |
object *`) can reject. Fixed to `exclude || ({})`.

### 7. §11-style copy-paste bug: `clone/weapon/panguanbi.lpc`

`inherit PEN;` / `init_pen(25)` — `PEN` was never a defined macro anywhere
(`PIN` exists, a *different* weapon type meaning "针"/needle) and
`init_pen()` was never a real function. The item's own content (id
`"panguanbi"`, long description "这是一柄普通的精钢剑" — "an ordinary fine
steel **sword**") plus a working sibling copy at
`/d/obj/weapon/sword/panguanbi.lpc` (correctly `inherit SWORD;
init_sword(20);`) confirm this was a copy-paste-and-half-rename artifact.
Fixed to `inherit SWORD; ... init_sword(25);` (kept the original numeric
argument).

### 8. §8g-style missing `#define`s: `SSERVER`, `F_NOCLONE`

Two bare macros used by `inherit SSERVER;` (5 skill files) and `inherit
F_NOCLONE;` (4 boss-NPC files under `kungfu/class/ultra/` — 南海神尼/黄裳/
独孤/葵花太监, all major named Jin Yong characters) were never `#define`'d
anywhere, a hard parse error (`inherit <undefined identifier>` parses as
"expecting L_STRING", not silently OK). Both had an obvious, already-
existing target to alias to rather than fabricate:
- `SSERVER` → `F_SSERVER` (`/feature/sserver.lpc`), which already exists
  and has the exact same `offensive_target()` helper as the un-prefixed-
  macro's actual target file `/inherit/sserver.lpc`.
- `F_NOCLONE` → `F_UNIQUE` (`/feature/unique.lpc`) — confirmed via other
  sibling boss NPCs in the same lib (`kungfu/class/mingjiao/yintianzheng
  .lpc`, `fanyao.lpc`) using the IDENTICAL shape (`inherit NPC; inherit
  F_MASTER; inherit F_UNIQUE;`) for exactly the same "only one instance of
  this boss may exist" purpose that "NOCLONE" implies. No `noclone.lpc`
  file exists anywhere in the archive to restore faithfully — aliasing to
  the already-proven-working sibling mechanism was the correct call per
  AGENTS.md §11's own guidance ("don't try to implement the missing base
  class from scratch").

Follow-on: the 4 `F_NOCLONE` boss files each call a bare `check_clone()`
explicitly from their OWN `create()` (which fully overrides
`feature/unique.lpc`'s own automatic-on-create uniqueness check without
ever calling `::create()`), so the automatic check never actually ran for
them. Added `check_clone()` to `feature/unique.lpc` itself (same body as
its own `create()`), which — since it's inherited via the new
`F_NOCLONE`→`F_UNIQUE` alias — became available to all 4 files at once.

### 9. §15b (never-defined-but-called globals): `add_light`, `keep_heart_beat`

- `add_light(object, int)` — called from ~14 sites (mostly `d/temple/*`
  room `create()`s, plus one skill file) for a room/object lighting
  cosmetic effect that was never implemented anywhere in the archive (not
  even in a `.bak`). Restored as a no-op simul_efun stub (`adm/simul_efun/
  object.lpc`) — a documented, safe compromise (same spirit as the
  project's `db_affected()` precedent), since there's no reference
  implementation to restore faithfully and none of the affected rooms are
  on the registration/critical path.
- `keep_heart_beat()` (bare, no args) — called from 3 NPC generator files
  (`girl.lpc`/`killed.lpc`/`receiver.lpc`, ×2 each incl. `u/lonely/`
  backup copies). Clearly an alias for the real `set_heart_beat(1)` call
  used identically elsewhere in this same lib (`feature/attack.lpc`,
  `feature/damage.lpc`, `feature/action.lpc`). Restored as `void
  keep_heart_beat() { efun::set_heart_beat(1); }`.

### 10. NEW: whole "competitor" (international-challenger event) subsystem
    silently dropped from `feature/attack.lpc`

`feature/attack.lpc` had a `.bak` sibling (`feature/attack.bak`, 555 lines
vs the live file's 342) — diffing them showed the ENTIRE `competitor`
variable + `query_competitor()`/`set_competitor()`/`competition_with()`/
`win()`/`lost()` subsystem existed in the backup but had been completely
removed from the live file, while 9+ other files (`kungfu/class/generate/
challenger|indian|european|japanese|japanese1.lpc` + `u/lonely/` copies,
`adm/daemons/story/challenge.lpc`, `inherit/char/challenger.lpc`,
`u/lonely/obj/user/quit.lpc`) still call it — a real, wide-reaching
"only ever called, never defined" gap (§15b), not a typo. Restored
**verbatim** from `attack.bak` (not a guess) into `feature/attack.lpc`:
the `competitor` variable + `query_competitor()`/`set_competitor()` near
the top (no forward-call issue), and `competition_with()`/`win()`/`lost()`
moved to just AFTER `fight_ob()`'s own definition later in the file — per
§8b, these three call `fight_ob()`/`run_override()` and calling a
same-file function before its definition fails to resolve on this driver;
the backup's original ordering (which put all 5 functions in one place,
before `fight_ob()`) would have hit exactly that. This was the single
highest-impact fix in this pass by file count (resolved compile errors
across the whole challenger-NPC family in one shot).

Follow-on fix needed once `query_competitor` resolved: `inherit/char/
challenger.lpc`'s own `competition_with()` override had `killertemp=ob;`
with **no local declaration anywhere in the function** — a genuine
pre-existing typo (not something the restore introduced). Every sibling
file using the identical `killertemp=ob;` idiom elsewhere in this lib
(`japanese.lpc`, `questguai.lpc`, `chinese.lpc`) declares it as a plain
local `object`; matched here (`object killertemp;` added to the function).

### 11. Pre-existing content typos fixed via the lpcc sweep

- `kungfu/skill/guxing-sword.lpc` AND its duplicate `kungfu/skill/
  fengxiao-xinfa/guxing-sword.lpc`: `"...星光瞬闪+NOR+"」..."` — missing
  closing quote before string concatenation (§10's exact pattern),
  fixed to `"...星光瞬闪"+NOR+"」..."`.
- `d/shushan/zhenyaota/npc/yaoguai4.lpc`: a `tell_object()` call split
  across two lines with a stray leading `"` on the continuation line
  (`"点武学"+` then `"+chinese_number(...)` — extra quote), fixed by
  removing the stray quote.
- 3 orphaned non-LPC `.c`→`.lpc`-renamed files (§12's exact pattern):
  `u/ken/{11,bb1,test1}.lpc` were plain Chinese test/scratch NOTES ("大家
  好，这是一个测试" / "我用来测试乱码的" — "hello, this is a test" / "I use
  this to test garbled text"), not LPC code at all. Confirmed nothing
  references them; renamed to `.orphaned-text`.

## Confirmed NOT needed (and how confirmed)

- **§4** (master's lazy `load_object()`-during-compile recursion in
  `valid_read`/`valid_write`): read `adm/obj/master.lpc` — both applies
  only ever `find_object(SECURITY_D)`, never `load_object()`. Not present.
- **§7** (`get_root_uid`/`get_bb_uid`): both already implemented in
  `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`.
- **§8c/§15n** (`this_player()`-override footgun / custom securityd ACL
  blocking mid-connection lazy compiles): `securityd.lpc`'s `valid_write`
  correctly substitutes `previous_object()` (the real calling object), not
  `this_player()`, as the identity to check — read the whole file, no
  `this_player()`-clobbering pattern present. `valid_read` doesn't gate on
  connected-player status at all except for `securityd.lpc`/`security%`
  self-protection, so a fresh unauthenticated connection's lazy compiles
  are never denied. Confirmed empirically too: the live registration test
  exercised several never-preloaded lazy compiles (`feature/attack`,
  `feature/command`, `feature/damage`, `feature/message`, `feature/move`,
  `feature/name`, `feature/skill`, several `d/register/npc/*` files) with
  zero "Read access denied"/"access denied" anywhere in `debug.log`.
- **§15o** (missing `get_include_path()` breaking mid-connection
  `#include`s): all the angle-bracket local headers checked (`dbase.h`,
  `weapon.h`, `name.h`) genuinely live in `/include/` (the configured
  global include path), not next to their including file — no
  `get_include_path()` needed, and confirmed via the same live-registration
  test above (multiple lazily-compiled `feature/*` files, zero `#include`
  errors).
- **§15l** (`master.lpc create()` destructing `SIMUL_EFUN_OB`): read
  `create()` — just a `write()` line, no `destruct()` call anywhere.
- **§15p** (DNS/intermud daemon in preload): `adm/etc/preload` already had
  `#/adm/daemons/network/dns_master` commented out in the raw archive
  itself — nothing to exclude.
- **§15m** (unguarded `restore()` crashing a daemon's `create()`):
  `chinesed.lpc`/`emoted.lpc`/`adversed.lpc` all call bare `restore()`
  in `create()` with no `catch()`, but the actual boot produced zero
  `Illegal mapping format`/restore-related errors in `debug.log` — no
  stale/corrupted save data shipped for any of the 3.
- **§15u** (dormant phone-home/anti-piracy destructive function): grepped
  `adm/daemons/*.lpc` for `rm`/`shutdown`/mass-delete patterns gated on
  opaque checks — every hit (`profiled.lpc` resetting its own profile
  file, `versiond.lpc`'s legitimate periodic-reboot-on-sync-failure,
  `natured.lpc`'s guild-data cleanup) is ordinary admin/maintenance logic,
  nothing resembling a licensing gate.
- **is_killing() type-mismatch family** (the exact shape that broke the
  player-body class on `nitan_ceshi`): `feature/attack.lpc` declares
  `varargs int is_killing(object ob)` and IS called directly with a
  string arg (`is_killing(ob->query("id"))`) at 2 call sites in the same
  file — a real type mismatch on paper, but the live boot (`inherit/char/
  char.lpc` successfully compiling `feature/attack` with zero errors, and
  the registration test reaching the game world) confirms this driver
  does NOT enforce it as a hard error here (likely because the parameter
  is inside a `varargs` declaration) — not a live bug, left alone.
- **`.c`→`.lpc` rename-width bug** (nitan-family `[0..<3]` extension-strip
  variant): grepped for `\[0\.\.<3\]`/`\[0\.\.<4\]` near `.lpc`/`.c`
  filename contexts — zero hits; the handful of `[0..<2]` slices found
  elsewhere (`channeld.lpc`, `versiond.lpc`, `configd.lpc`,
  `commandd.lpc`) are unrelated string-trimming, not extension-stripping.
- **§8f** (`TYPE * name1, name2;` comma-list array-modifier bug): many
  candidate lines exist (`mixed *name,value;` etc.) but this is a
  speculative pattern only worth fixing when it actually produces a "Bad
  assignment (TYPE vs TYPE*)" compile error (per §15f's own "don't
  bulk-fix speculatively" guidance) — the boot and lpcc sweep produced
  zero such errors, so left untouched.
- **§15f** (bare `array` type declaration): zero occurrences found via
  grep.

## Known residual issues (documented, not fixed — non-critical content)

- **3 files with a silent, non-diagnostic "Fail to load object"** after
  the competitor-subsystem restore: `kungfu/class/generate/indian.lpc`,
  `european.lpc`, `japanese1.lpc` (all "international challenger" event
  NPCs). Their own compile produces zero error/warning text at all, yet
  `lpcc` still reports the load as failed. Ruled out: missing macros
  (none), missing content (all referenced items — `seng-cloth`, etc. —
  exist on disk), a shared inherited-file problem (a sibling file in the
  same directory, `chinese.lpc`, compiles clean). Given these are deep,
  never-preloaded quest-event NPCs with no bearing on registration/core
  gameplay, and per AGENTS.md §6b's own guidance that isolated single-file
  `lpcc` runs (no player, no room graph) are a recognized source of
  false-shaped failures, this was left as a documented gap rather than
  chased further.
- **`diary_write(ob, msg)`** — called from exactly one file
  (`d/taoyuan/npc/hongniang.lpc`, a wedding-officiant NPC) via `#include
  <diary_write.h>`, which doesn't exist anywhere in the archive. No
  reference implementation exists to restore faithfully (unlike
  `add_light`, this isn't obviously a no-op-safe cosmetic — it's a named
  "diary" feature with unknown intended behavior) — left as a documented
  content gap, single file, non-critical.
- **`temp/ken*`/`temp/lonely*` scratch files** (9 of 35 fail): these are
  ephemeral one-line `mixed temp(object ob){return me->query(...);}`-style
  snippets, artifacts of wizards using an in-game `eval`-style debug
  command that happened to get captured into the archive — not real
  content, expected noise.
- A handful of deep skill-file syntax errors (`kungfu/skill/wushuang-
  sword.lpc`, `club-sword.lpc`, `wulainizou-unarmed.lpc`, and similar)
  remain from genuinely malformed pre-existing code (mismatched
  parens/braces predating this conversion) — none reachable from
  registration; left as-is per the project's stated "breadth over depth"
  policy for the remaining long tail.

## Registration flow

Read `adm/daemons/logind.lpc`'s actual callback chain before testing (per
AGENTS.md's standing warning about hidden pre-id prompts): `logon()` prints
a "Select 国标码 GB or 繁体 BIG5 (gb/big5):" line, but this is a **soft**
prompt, not a gate — `input_to(get_id, ...)` fires next regardless, and
`get_id()` only special-cases the literal input `"big5"` (sets a flag and
re-shows the whole banner+prompt); ANY other input (including a normal
English id) falls straight through to the real id-validation logic. So the
very first `--send` can just be the real login id directly, no separate
blank/gb answer needed.

Full chain confirmed by reading the source: `get_id` → (existing user)
`get_passwd` **or** (new user) `confirm_id` (y/n) → `get_name` (Chinese
name, **no** separate y/n confirmation when a real name is typed — only
random-name generation goes through `get_resp`) → `new_password` →
`confirm_password` → gift-attribute selection (`select_gift`
0-4/`set_gift`/`get_gift` y/n) → `get_email` → `get_gender` (m/f) →
`make_body()`/`init_new_player()`/`enter_world()`.

**Verified twice, in two separate continuous `mudclient.py` sessions**
(before AND after restarting the driver to pick up the `feature/
attack.lpc` competitor-subsystem restore, to make sure that change didn't
regress the core player-body class every character depends on):

1. `qinfeng` → `y` → **秦风** → `test12345` → `test12345` → `0` → `y` →
   `qinfeng@test.com` → `m` → `look` → `quit`
2. `linfeng` → `y` → **林风** → `test12345` → `test12345` → `0` → `y` →
   `linfeng@test.com` → `f` → `look` → `quit`

Both runs: Chinese name accepted with no rejection, no separate
confirmation prompt (matches the source), gift/email/gender flow completed
normally, and the character landed in an actual room ("世外桃源" / Peach
Blossom Spring — the real starting room, not a void/error state), with a
correct room description, exits, NPCs (水笙/狄云) listed, and the news
system firing normally. A third quick test confirmed the *existing-user*
path (re-entering `linfeng`) correctly routes to a password prompt instead
of character creation, and 3 wrong-password attempts correctly disconnect
with the expected message. `debug.log` was clean of any
error/access-denied/crash lines across all three sessions (only the usual
first-boot `*Warning: unable to open stat file domain_stats/author_stats`
lines, and ordinary compile warnings — no `执行时段错误`, no
`Segmentation`, no `Fail to load`, no `access denied`).

## lpcc sweep

Ran twice (once before the deeper §15b/copy-paste-content fixes, once
after, to measure improvement): 11995 total files both times.
- 1st pass (after mechanical fixes + §15h/§14/§15w/§8e/§15s/panguanbi/
  SSERVER+F_NOCLONE fixes): 11737 pass / 258 fail (**97.8%**).
- 2nd pass (after restoring the whole `feature/attack.lpc` competitor
  subsystem + `add_light`/`keep_heart_beat` stubs): 11760 pass / 235 fail
  (**98.0%**).
- A few more fixes landed just after the 2nd sweep finished (2× `guxing-
  sword.lpc` missing-quote typo, `yaoguai4.lpc` stray-quote typo, 3
  orphaned scratch files renamed away from `.lpc`) — not re-swept a third
  time given diminishing returns, but each was individually re-verified
  clean via a direct single-file `lpcc` check. Effective current pass rate
  is slightly above 98.0%.

Memory stayed healthy throughout both sweeps on this 23GB host (never
dropped below ~16GB available, well clear of the OOM risk threshold in
AGENTS.md §6b) despite a concurrent agent running another lib's sweep at
the same time.

## Process notes

- Driver launched via `run_in_background: true` (Bash tool), never a bare
  `nohup ... &`. Killed by exact PID only (never a `pkill -f` pattern) —
  confirmed via `/proc/<pid>/cwd` before every kill, since another agent's
  driver process shares the identical `driver config.fluffos` command line
  and was running concurrently for most of this session (`libs/haiyang2`,
  later `libs/yanhuangwuhun`).
- Restarted the driver once mid-session (after the `feature/attack.lpc`
  competitor-subsystem restore) specifically to verify that change didn't
  regress the player body class, per the standing reminder that LPC
  objects don't recompile just because the source file changed on disk.

## Re-verification pass: driver rebuild + formatter + WASM (2026-07)

- **LPC formatter** applied to all `.lpc` under `work/` (11,992 total,
  11,796 written, 42 unchanged, 154 self-checked errors left untouched
  as expected on legacy code). Reformatted files include `data/area.lpc`
  (a data file authored as LPC array literal) — cosmetic only, verified
  no content change beyond whitespace.
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero real errors in `debug.log`. Full
  registration flow re-verified end-to-end with a fresh real Chinese
  name (`秦风测`/`qftest`) through the gift-attribute/email/gender flow,
  landing in 世外桃源, with `look`/`score`/`quit` all producing correct
  output — confirms all the prior fixes (the `#define nosave nosave`/
  `protected protected` macro rewrite, §15h, §14, §15w, §8e `tail()`,
  §15s, the restored `feature/attack.lpc` competitor subsystem, etc.)
  survived the reformat and the new driver build intact.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`):
  boots cleanly, zero fatal/undefined-function errors. Registration is
  **blocked under WASM** by the known `query_ip_number()` limitation:
  `adm/daemons/logind.lpc`'s `logon()` calls `BAN_D->is_banned(str)`
  where `str = query_ip_number(ob)`; `band.lpc`'s `is_banned()` does
  `if (!site) return 1;` then `if (sscanf(site, "%s.%s.%s.%s", ...) !=
  4) return 1;` — under WASM `query_ip_number()` doesn't return a real
  dotted-quad, so `is_banned()` returns 1 ("banned") and every
  connection is destructed at the very first `logon()` call with
  "本站正在进行内部调整..." before ever reaching the id/name prompt.
  Confirmed this is the documented driver-side WASM limitation (not a
  mudlib bug) — the exact same lib boots and completes full registration
  cleanly natively (see above). Not patched, per standing instruction.
  (Superseded by the 2026-07 WASM-enablement pass below — now patched.)

## WASM-enablement pass (2026-07): loopback gates + admin seeding

Standard pass per AGENTS.md §1.3b/§1.3e/§1.5:

- `adm/daemons/band.lpc`: new `is_local_site(site)` helper (loopback /
  empty / malformed IP ⇒ local). `is_banned()` short-circuits to 0 for
  local sites (this was THE WASM login blocker documented in the earlier
  re-verification pass: malformed WASM IP ⇒ "banned" ⇒ instant destruct).
  `vaild_allow_address()` (per-account allow-ip lock) returns 1 for
  loopback.
- `adm/daemons/logind.lpc`:
  - `logon()`: `ban_cnt > 12` per-IP pending-connection cap — loopback
    exempt.
  - `get_id()`: the netclub/public-ip per-IP multi-login caps
    (`ip_cnt > 12` / `> 4`) — loopback exempt.
  - `get_passwd()`: 30-second "你刚退出游戏" relogin load throttle —
    loopback exempt (the 600s kickout penalty is punishment/game design,
    kept). Also removed a leftover debug `printf("%O\n", ob)` in
    `get_name()` that printed `/clone/user/login#N` at every new player.
- No `uptime()` startup-grace gate exists in this lib (only cosmetic
  uptime uses in check_cpu/uptime display) — nothing to bypass.
- Admin seeded: `fluffos` / `Mud@2026` / 浮浮, rank `(boss)` via
  `adm/etc/wizlist`. **Lineage quirk discovered**: `feature/dbase.lpc`'s
  `set()` has an anti-steal-power gate ("Add by Lonely") that silently
  refuses `set("password", ...)` on any object whose id has `(boss)`
  wizhood unless this_player()'s euid IS that id — so registering an id
  that is ALREADY in the wizlist as (boss) dead-loops at the password
  step (confirm always mismatches against old=0). Correct order:
  register as a plain player first, then add `fluffos (boss)` to the
  wizlist and restart. Verified after restart: login banner shows
  权限〖巫师协会懂事〗(boss), `update /d/register/entry.lpc` succeeds.
- Retest: fresh normal registration (`regtest`/秦风测) end-to-end into
  世外桃源, look/score/quit fine; test saves removed. debug.log clean
  except one pre-existing content bug surfaced by updating
  /d/city/wumiao.lpc: `/d/city2/npc/wizer.lpc:22` calls
  `exert_function(10)` (string-typed param, hard compile error) — a
  genuine pre-existing content bug unrelated to this pass, room loads
  fine at boot (NPC clone fails only when wumiao is recompiled), left
  documented. Runtime churn (`u/lonely/log` compile-warning append)
  reverted via `git show HEAD:`.

## WASM long-sit boot-watch pass (2026-07)

200s `scripts/wasm_boot_watch.sh` sit: completely clean, zero grep hits
beyond the known-benign early `Unable to open log file:
"log/debug.log"` line — no new findings, no fix needed. (This lib's own
`adm/simul_efun/object.lpc` `file_owner()` uses a different, already-
correct 2-arg `sscanf(file, "/u/%s/%s", name, rest)` shape that doesn't
have the 3-arg misattribution bug found live on sibling `zhonghua2` and
ported to 7 other libs in this batch — checked and confirmed fine,
nothing to port here.)

## WASM 修复摘要（迁移自 meta.json 的 group_note）

状态已从过时的 limited 修正——这份档案自己的 README 和 group_note 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）干净正常，权限已通过这份档案自己的最高阶层字符串确认（'★ 您目前权限：〖 巫师协会懂事 〗(boss)'），quit 正常。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 115 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (AGENTS.md §10.7)

Read `doc/help/newbie` in full first (5-part in-game newbie guide, credited
"By 黑客(lonely)"): covers stat-roll ranges, personality/character choice
(光明磊落/狡黠多变/心狠手辣/阴险奸诈, each with a mechanical effect),
sect recommendations by weapon type, and a Q&A section explicitly naming
`gc e n` + `learn zhu literate` as the free literacy-training route (`gc`
= 扬州中央广场).

### NEW bug found and fixed: every single connection crashed inside `logon()`, before the id prompt, on a genuinely fresh checkout

First boot attempt (driver launched clean from `libs/yxcs`, port up in
~1s) produced, for every connection attempt: `new_conn_handler: logon()
on object clone/user/login#N has failed, the user is disconnected` in
the driver's own `debug.log` — a total, silent connection block with
zero player-visible banner text (matches the exact symptom class in
AGENTS.md §7.9/§7.11: the driver's own crash-summary line carries no
LPC stack trace).

Root cause, found via the **second**, LPC-level `debug.log`
(`work/log/debug.log`, written by `error_handler()`'s own
`write_file(LOG_DIR "debug.log", ...)` — see the `log_error()`
discussion above; check BOTH log locations per AGENTS.md's standing
instruction, this bug was invisible in the first one):

```
执行时段错误：*Wrong permissions for opening file /log/file/cat_file for append.
"No such file or directory"
呼叫来自：/clone/user/login.lpc 的 logon() 第 7 行
呼叫来自：/adm/daemons/logind.lpc 的 logon() 第 115 行
呼叫来自：/adm/obj/simul_efun.lpc 的 cat() 第 291 行
呼叫来自：/adm/obj/simul_efun.lpc 的 log_file() 第 11 行
```

`adm/daemons/logind.lpc`'s `logon()` — the very first thing every new
connection's `login.lpc` calls — does `cat(WELCOME)` to print the login
banner. `adm/simul_efun/file.lpc`'s `cat()` unconditionally calls
`log_file("file/cat_file", ...)` as its own audit-log side effect
*before* actually printing anything, and `log_file()` itself was a bare
`write_file(LOG_DIR + file, text)` with **no directory guard at all** —
a fresh checkout never ships `work/log/file/`, so the write throws, the
throw is never caught anywhere in the `logon()` call chain, and the
entire apply aborts before the banner (or the id prompt after it) ever
gets sent to the connecting socket. This is a new confirmed instance of
AGENTS.md §7.11 ("missing runtime directories and the silent
`write_file` abort") — same shape as the `xajhxo` precedent
(`log_login()` → uncaught `log_file()` write into a never-shipped
directory, killing registration one step earlier than the visible
symptom), except here it fires on **every** connection, not just at one
step of character creation, because `cat(WELCOME)` sits at the very top
of `logon()` itself.

**Fix**: patched `log_file()` itself (`adm/simul_efun/file.lpc`), not
just the one call site, since it's a shared simul_efun used by dozens of
call sites across the whole tree — added the missing `assure_file()`
guard (this file already has its own `assure_file()` helper, same
pattern as the `xajhxo` fix; needed a one-line forward declaration since
`assure_file()` is defined later in the same file and this compiler
doesn't resolve same-file forward references without one):

```c
void assure_file(string file);
void log_file(string file, string text) {
  assure_file(LOG_DIR + file);
  write_file(LOG_DIR + file, text);
}
```

Verified: killed the driver, restarted clean, reconnected —
`work/log/file/cat_file` now gets created on first write, banner prints,
id prompt reached, zero `logon() ... has failed` lines in either
`debug.log` for the rest of the session.

**Also required** (pure operational setup, not a code bug, but a
fresh-checkout prerequisite worth recording): the archive shipped with
neither `libs/yxcs/log/` (the driver's own real `debug.log`, §5.2 —
CWD-relative, not mudlib-relative) nor `work/log/` (the mudlib-virtual
`LOG_DIR` target used by the LPC code above) on disk at all. `mkdir -p
log work/log/nosave work/log/wiz` before boot; without it, `debug.log`
itself never gets written (silent, not even the crash-summary line makes
it to disk) and `log_error()`'s own write additionally throws during
preload compile-warning logging (self-healing since it's already inside
`preload()`'s outer `catch()`, but pollutes preload output).

**Defensive fix applied alongside** (not confirmed as a live crash this
pass, but matches the exact AGENTS.md §7.9 shape and the underlying data
files are explicitly gitignored — `libs/*/work/adm/daemons/iduser` /
`.../users`, per this project's own `.gitignore` comment "user-id
counters... not meaningful shipped content"): `logind.lpc`'s `logon()`
did `i_user = atoi(read_file(__DIR__"users", 1))` (and the same shape
for `iduser` and `maxonline`) with no `stringp()` guard — on a fresh
checkout where those counter files don't exist yet, `read_file()`
returns int `0`, and `atoi()` on a non-string argument is exactly the
`§7.9` "fresh-checkout crash bomb" pattern. Guarded all three with
`stringp(...) ? atoi(...) : 0`. (`maxonline` already existed on this
checkout so this one wasn't empirically confirmed as live here, but
`users`/`iduser` were both genuinely absent and this guard is cheap
insurance regardless of which exact site would have thrown first.)

### Registration — real Chinese name, full flow

Continuous session via a small custom Python telnet-IAC-stripping client
in tmux (this environment has no `telnet` or `nc`-with-negotiation
binary available, so `scripts/tmux_mud.sh` — which shells out to
`telnet` — doesn't work here; wrote a ~90-line drop-in replacement using
the same IAC-strip logic as `scripts/mudclient.py`, kept in the
scratchpad, not committed).

`qinfengb` (rejected once first as `qftest2` — digits not allowed, "你的
英文名字只能用英文字母") → `y` → **秦风波** (real Chinese name, accepted
immediately, no separate confirmation prompt — matches the `logind.lpc`
source read in the earlier pass) → `test12345` ×2 → gift-attribute `0`
(random) → `y` → `qinfengb@test.com` → `m` → landed in `世外桃源`
(`/d/register/entry`), correct room description, water笙/狄云 present,
news system fired. `look`/`score`/`i` all correct at this state.

Then the personality-choice sub-flow (not covered by the earlier
registration-only pass): `east` → 陆天抒 (光明磊落 branch) → `out` →
「阎罗殿」(reincarnation hall, 地藏王) → `born 扬州人氏` → landed in
`/d/city/kedian` ("有间客栈"). `score` afterward correctly shows
性格:光明磊落, correct stats, food/water bars full (§8.9 pattern:
confirmed NOT present here, bars start full).

### Combat — safe sparring via the training-dummy stat-mirror pattern

`cmds/std/fight.lpc`'s actual logic read first (per AGENTS.md's standing
warning against assuming a "safe" NPC without checking the real
`accept_fight` gate): a `can_speak`-having NPC's `accept_fight(me)` must
return 1 for `fight` to proceed. `d/shaolin/npc/mu-ren.lpc` (and an
apparently-orphaned identical copy at `d/city/npc/mu-ren.lpc` — see
"observations" below) matches the exact §10.7-documented dummy shape:
`set("no_die", 1)`, and `accept_fight()` deletes its own skills/stats
and copies the attacker's own skill map + str/int/con/dex/qi/jing/neili
onto itself before the fight starts (a genuine mirror match, not a
scripted-weak opponent). Admin-cloned one into the player's current room
(`clone /d/shaolin/npc/mu-ren`) since none of this lib's dummy instances
happen to be placed along the 世外桃源→扬州 walking path used above.
`fight mu ren` in a `no_fight`-clear outdoor room ran a full multi-round
exchange (both sides landing and missing hits, HP-state narration
escalating normally) and resolved with the player conceding
("这场比试算我输了，佩服，佩服！") — no crash, no stuck state,
`score`/`look` immediately afterward both correct.

### Skill acquisition — organic path AND admin shortcut, both verified

**Organic**: per the newbie doc's own "gc e n" hint and the `board`
item_desc text in `d/city/shuyuan.lpc` ("学文化的格式是 learn zhu
literate!"), gave money to 朱丹臣 (`d/city/npc/zhu.lpc`, aliased `zhu`)
via `give 10 silver to zhu` (money supplied by admin `clone
/clone/money/silver 20` + `give`, since a level-14 newbie starts with no
cash) → NPC's own `accept_object()` credited a `mark/朱` balance → `learn
zhu literate` → "你听了朱丹臣的指导，似乎有些心得。你的「读书写字」
进步了！" — real accept-logic path, no shortcut, works end to end.

**Admin shortcut**: `cmds/wiz/copyskill.lpc` (`copyskill <target>`) —
copies a target's entire skill map + skill_prepare + combat stats onto
the caller. Ran `copyskill qinfengb` from the admin account: "你口中念
念有词，只见一道红光笼罩了你和秦风波。" — no dedicated single-skill
grant command exists in `cmds/wiz/` (checked the whole directory; the
closest is this bulk stat/skill copy), documented honestly rather than
assumed.

### `quit`, debug.log, reconnect after a real gap

No new-account quit-deletes-account grace period found in this lineage
(unlike the nitan family): `logind.lpc`'s registration chain only calls
`ob->save()`/`user->save()` once, inside `enter_world()`, at the very
end of the full flow (after gender selection) — by the time a player can
even type `quit`, the account is already durably saved, so there is no
partial-registration window to worry about. `cmds/usr/quit.lpc` read in
full: no lockout for `wizardp()`, and for non-wizards a `pker_starttime`
window is punitive-PK-cooldown design, not a fresh-account grace period.

`quit` from 「东大街」 (outdoors, mid-conversation with 朱丹臣): dropped
one worthless `Cloth` item as expected content-consistency (§7-adjacent
but plainly intentional — "因为这样东西并不值钱，所以人们并不会注意到
它的存在" is a normal drop-message, not an error), printed "欢迎下次再
来！", connection closed cleanly. Both `debug.log` (driver-level) and
`work/log/debug.log` (LPC-level) checked immediately after — zero new
error/crash/access-denied lines beyond the already-documented,
pre-existing `d/city2/npc/wizer.lpc:22` `exert_function()` type-mismatch
content bug (unrelated to this session, confirmed via grep this bug's
own earlier pre-existing note in this same file).

Used the post-quit interval productively (reverted incidental resave
noise on `data/{login,user}/f/fluffos.o`, spot-checked earlier
prior-pass fixes — the `nosave nosave`/`protected protected` macro
rewrite, `F_NOCLONE`→`F_UNIQUE`, `SSERVER`→`F_SSERVER` — all still
intact, grepped 6 sibling same-lineage libs for the same
`log_file()`-missing-`assure_file()` shape found above (see "cross-lib
observation" below), and drafted this NOTES.md section) — then
registered a **second** throwaway character, `persisttest`/李持久
(female, so the §8.9-adjacent gender-conditional `init_new_player()`
money/combat_exp bonus path got exercised too), specifically to redo
the persistence check cleanly (the first attempt, on `qinfengb`, was
invalidated by deleting its own `.o` save files as part of the
resave-noise cleanup *before* actually reconnecting to confirm — logged
that mistake so a future pass doesn't repeat it: do the persistence
reconnect BEFORE any save-file cleanup, not after).

`persisttest` `quit`ed from 世外桃源, then reconnected after a genuine
~1-2 minute additional wall-clock gap (on top of the several minutes
already spent on the interval work above) via a **fresh telnet
session** (real disconnect+reconnect, not a resumed connection):
banner printed clean, `persisttest` + password → **recognized as an
existing account** (no "creates a new person" prompt this time,
confirming the id correctly round-tripped through save/reload) →
"☆ 您现在是第 二 次光临浴血重生" / "☆ 您上次连线的地址是 127.0.0.1" /
"☆ 您上次退出本游戏的时间是：［ 2026年8月7日21点36分 ］" (matches the
exact prior quit time) → `score` showed the exact same character:
中文姓名 李持久, 性别 女性, stats 膂力25/悟性22/根骨18/身法15 (the exact
roll accepted at registration), 钱庄存款 二十两白银 and 实战经验 50
(both from the female-branch `init_new_player()` bonus, confirming
`user->save()`/reload round-trips that data correctly too). Full state
persistence confirmed. `quit`ed again cleanly, `debug.log`/`work/log/
debug.log` both still clean (same pre-existing `wizer.lpc` content bug
only, no new errors).

### 发现但判定为既有设计、未改动的现象

- **`d/city/shuyuan.lpc`'s `valid_leave()` deliberately blocks
  non-wizard players from going `north` into `shuyuan2`** ("那是朱熹的
  私人寝室！！" — explicit `notify_fail`, not a broken/accidental gate).
  The room's own flavor `long` description ("那就是当今大儒朱先生了")
  and the newbie doc's "朱熹处给钱" phrasing both point at 朱熹
  (`zhuxi.lpc`, the NPC actually living in the blocked `shuyuan2`), but
  the REAL, reachable literacy teacher is 朱丹臣 (`zhu.lpc`, present in
  the accessible `shuyuan` room, and the room's own in-game `board` item
  spells out the correct `learn zhu literate` command). This is
  intentional content design (a padlocked "boss's private room" flavor
  choice) with slightly misleading flavor text/doc-vs-actual-NPC
  mismatch — a content/documentation nit, not a programming bug; left
  untouched.
- **`d/city/npc/mu-ren.lpc`** (a byte-for-byte near-duplicate of the
  live `d/shaolin/npc/mu-ren.lpc` training dummy, differing only in
  `no_get`/combat_exp increment) appears to be genuinely unreferenced —
  grepped the whole `work/` tree for both `city/npc/mu-ren` and a
  relative `__DIR__ "npc/mu-ren"` from any `d/city/*.lpc` room and found
  no call site. Orphaned dead content (a leftover duplicate from map
  development), not wired into any room's `objects` mapping; harmless,
  left as-is.

### Cross-lib observation (not fixed this pass — out of scope, `yxcs`-only pass)

The `log_file()`-missing-`assure_file()` shape fixed above in
`adm/simul_efun/file.lpc` is present, unfixed, in every other checked
sibling of this lib's ES/XKX lineage (§11): `xkx2001`, `rzrmud`,
`bmxkx2001`, `kxkj`, `yueyingqiyuan`, `wuhanzhan` all ship the identical
unguarded `void log_file(string file, string text) {
write_file(LOG_DIR + file, text); }`. Whether any of them actually hits
the crash live depends on whether their own `logon()`/registration chain
routes through an equivalent `cat()`-audit-log or other `log_file()`
call before the id prompt (not checked here — that's each lib's own
§10.7 pass to make). Flagging for whichever future dive picks one of
these up: check `work/log/debug.log` (not just the driver's own
`debug.log`) for a `Wrong permissions ... for append` trace through
`log_file()` before assuming registration is clean.

### §9 formatter

Ran `format-corpus.mjs` on both edited files (`adm/daemons/logind.lpc`,
`adm/simul_efun/file.lpc`) — both reformatted clean, 0 errors. Checked
all 3 documented blind spots: `grep -rnE ':\s:\s*[a-zA-Z_]+\('` — zero
hits in either file; no `case`-label lines touched by either diff (no
manual diff-review needed); `grep -rl '\\ n'` — zero hits in either
file. Re-booted and re-tested the full flow above against the
reformatted files (this NOTES entry's own registration/combat/skill/quit
walkthrough was run AFTER formatting, not before).

### WASM 未验证说明

Per this project's build state this pass: WASM build permanently
blocked (`emsdk` hardcodes `storage.googleapis.com`, denied by the
proxy — confirmed via `curl -sS $HTTPS_PROXY/__agentproxy/status`). The
fixes above (both the new `log_file()`/`assure_file()` fix and the
`logind.lpc` counter-file guard) are pure LPC-level runtime-error
guards with no WASM-specific code path — expected to apply identically
under WASM once a build becomes available, but genuinely unverified
under WASM this pass; the earlier WASM-enablement pass's own findings
(loopback ban-bypass, admin seeding) are untouched and still apply.
