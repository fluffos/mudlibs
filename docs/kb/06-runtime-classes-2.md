# KB 06 — Boot-time and runtime crash classes, part 2 (§7.61–§7.202)

### 7.61 The §7.12 bug inside `message()` itself
3-arg calls from `channeld` and `questd` leave `exclude` as int 0. Fix
the root wrapper with `exclude || ({})`.

### 7.62 `check_legal_id`'s `while (i--)` accepts `""`
The empty id later crashes `sprintf("%c", id[0])`. Reject `!strlen(id)`
explicitly.

### 7.63 One `new(X)` call site lacks the guard every sibling call site has
That asymmetry is the diagnosis. Copy the siblings' guard; don't chase
driver internals.
- `jinyongwenzi`: a missing `/quest/weiguo/` tree plus unguarded `new()`
  in `natured` killed the day/night heartbeat.
- `hy5`: `room2->query("short")` after `load_object` →
  `local = objectp(room2) ? room2->query("short") : 0;` (54 sites).

### 7.64 Stray `;` after `if (...)`
It makes an unconditional call to a dev daemon that was never shipped.
Remove the dead call. Grep `if\s*\([^)]*\)\s*;`.

### 7.65 Uncaught `create()` error leaves a daemon non-resident
A later implicit `X->foo()` silently no-ops, which can wedge
character creation (`hhsj`'s `named`).
- Fix: `catch()` the `restore()`.
- Bisect with `write()`, not `log_file()`.

### 7.66 Archive ships only part of `/d/obj/`
Referenced items are either relocated or genuinely gone. Relocations
seen: `d/city/obj/` and top-level `/obj/...` (strip the `/d`). Verify
each candidate by matching `set_name()`, then repath. Leave truly
missing items alone (`xiyouji2003`).

### 7.67 Menu label disagrees with the value actually assigned
Grep where the value is consumed downstream; that tells you which side
is wrong. On `sanjieshenhua`, the label was wrong.

### 7.68 RETRACTED except `bmxkx2001`: `present(ob)` abandon in death `call_out` chains
Abandoning when absent is often intended (ghosts wander). Only retry if
you confirm LIVE that ghosts can't move on their own AND something else
forcibly moves them. Reverted in 28 libs. See §7.112 for the real
re-entrancy bug in the same files.

### 7.69 The real auto-included header lacks a macro an unused duplicate header has
Confirm which header `global include file` actually loads, then add only
the missing macro (`bmxkx2001`'s `EDITOR_D`).

### 7.70 `query(prop, ob)` used as if it meant `ob->query(prop)`
This codebase's `query(prop, raw)` takes an int. The fix is
`X->query("prop")`. Swept on `wxddym` (130 files / 471 sites) via
`lpcc --batch` before/after diffs. `query_temp` with the same shape was
left alone.

### 7.71 `call_out` to a function whose body is commented out
Silent no-op forever. Restore the already-written body (`syxjl`'s
`bgargoyle`).

### 7.72 Flood-kick `command("quit")` without `return`
The next line touches the destructed object. Add `return`.

### 7.73 `carry_object(missing)->wear()` in `create()`
Store the result and guard it:
```lpc
object c; c = carry_object(p); if (c) c->wear();
```
- **Blast radius:** inside a room's NPC population, the throw truncates
  the rest of the room's `create()` (on `ldtx` the board never
  appeared).
- The `if (object x = ...)` declaration form passes the formatter but
  NOT the driver; declare first.
- **Mini-archive variant (`xo`):** the target was relocated locally;
  repath and keep the guard. Check `vendor_goods` paths too.
- **Corpus sweep (2026-10-15):** `scripts/lpc_guard_carry_object.py SLUG... --apply` rewrote every
  full statement `carry_object("<missing literal path>")->wear()/wield()/set_amount(...)` as
  `{ object carried_ob = carry_object("..."); if (carried_ob) carried_ob->wear(); }` (no
  function-level declaration needed; sibling blocks may reuse the name, a nested block may not:
  `Illegal to redeclare local name`). 5,367 sites in 3,931 files, 164 libs: transplanted NPCs
  carrying another lineage's paths (shenmo 679, hy 284, zzfy 240 ...) and wizard items
  (`/u/wind/gun` in the xkx 李凌). The NPC now loads without the item; a virtual or restored path
  is carried as before. NPCs that still fail usually `set_skill()` a skill the lib lacks.
- **The base's own `carry_object()` can be the thrower (2026-10-15, `--base`).** The xyj / sjsh / mhxy lineage's `std/char/npc.lpc`
  starts `carry_object(string file)` with `if (file->query_unique())`: a call_other on the path string, which on this driver
  RAISES `call_other() couldn't find object` for a missing file before `new()` can return 0, so the call-site guard above
  does nothing there. 449 of shenmo's NPCs -- every sect master in `kungfu/class/` and `daemon/class/` -- failed to load, in
  the tree too. `if (!objectp(load_object(file))) return 0;` before that statement (36 files, 32 libs; `--base`) revived them;
  sjshwzb and sjshwzjqb already had the `file_size()` form of the same guard (section 7.99). Test a sample NPC after either
  fix: at HEAD the load error names the missing item, in a fixed tree it loads.
- **Third thrower: the simul_efun `unew()` (`--unew`).** The xkx lineage's `carry_object()` calls `unew(file)` (new, but honour
  `unique`), whose first lines are `object ob = new(str); int i = ob->query("unique"), ...`: `new()` of a missing file returns 0
  and the query on it raises `Bad argument 1 to EFUN call_other()` inside `unew` (jh2006: 124 NPCs in 13 libs, all the
  Miaojiang masters among them). `if (!ob) return ob;` before the first query, as fyzfqyy's copy already had (15 libs; the
  declaration `int i = ob->query("unique"), j, k;` is split so the guard can precede the assignment).
  **Detection order for a sample NPC that will not load:** read the first error line -- `call_other() couldn't find object
  '<item>'` is `file->query_unique()` in the base's `carry_object()`; `Bad argument 1 to EFUN call_other()` with
  `unew()` in the trace is this one; `Bad argument 1` at the NPC's own `->wear()` line is the call-site shape.

### 7.74 UNRESOLVED: `ob->move(REVIVE_ROOM)` never returns inside a `call_out` after `reincarnate()` (`wmkj`)
Suspect `notify_fail` in `move()`'s equip guard. Instrument inside
`move()` before changing anything.

### 7.75 A room macro used as a call target points at the wrong file after a split
`DEATHROOM->end_death()` silently no-ops. The real function lives in a
file whose header comment names the old path. Call the file that
actually defines it (`kxkj1`).

### 7.76 `REVIVE_ROOM` points at a renamed-away file
Even an undisturbed death strands the player. Use paired same-content
files to find the new name (`fys`: `yangzhou/temple` →
`damingshi`). Always run a full undisturbed death cycle to the end.

### 7.77 Food/water capacity computed from `query_weight()` before the clothes are given
New characters start at 0 food and water. Move the init after
equipping, guarded with `!query("food")` (`njhhdxdes2hx`).

### 7.78 Bare `set`/`query` inside F_* mixins that don't inherit F_DBASE
LPC binds a bare call at the DEFINING file's compile time. Fixes:
- Route mixin self-calls through
  `this_object()->query(...)`/`set(...)`.
- Do NOT add `inherit F_DBASE` to the mixin. The duplicate `nomask`
  inherit is fatal.

Present in every NT/nitan/Lonely lib (13 mixins). Companion:
`message()` non-varargs, fixed with `if (!exclude) exclude = ({});`.

### 7.79 `addn()` / `addn_temp()` 2-arg self calls (done)
The simul_efun-only shim's `this_object()` is the simul_efun object, so
the write is lost.
- Rewrite `addn(A,B)` → `this_object()->add(A,B)`.
- Exclude files with a LOCAL `addn` (`baby.lpc`, `user.lpc`) and never
  rewrite definitions.
- Libs fixed: `xfbhh`, `hhsj`, `nitan170911`, `nitan6`, `nt6`,
  `nt6nitan6win` (4,424 sites).
- `wxddym` and `shenmo` had NO shim at all (compile-fatal): add the shim,
  and convert `ob->addn` to `add`.

### 7.80 Suffix-strip slice off by one
`str[0..<n]` keeps `len-n+1` characters, so `.lpc` needs `[0..<5]`.
- `eventd.lpc`'s event list was silently empty on 15 libs (swept).
- `nt7`: `explode(__FILE__,"/")[<1][0..<3]` at 29 skill sites corrupted
  skill ids.

### 7.81 Wrapper parameter narrower than the daemon it forwards to
`set_information(string key, string info)` while callers pass closures.
Widen it to `mixed`, in both `inherit/misc/quest.lpc` and
`include/quest.h`. Swept on 16 libs. General form: §7.127.

### 7.82 Login object's own `nomask set()` guard blocks a legitimate root-less writer
Registration "succeeds" but the mailed password never applies. Route the
write through a root daemon helper that checks `base_name(linkob)`. Grep
transcripts for `set is error`.

### 7.83 `apply_condition("x")` with no `/kungfu/condition/x.lpc` daemon
The condition is removed every tick, so the cooldown never engages
(unlimited farming) and errors spam. Write the minimal decrement daemon
(`xkm`'s `boardread`).

### 7.84 SEVERE: plaintext passwords appended to a `/doc/help/` file
Any player can read them via `help`. Delete the `write_file`. Keep the
historical entries, but revert any your test added (`tybxjh`'s
`neima2`/`neima3`). Diff `doc/` after registration tests.

### 7.85 Bar renderer keeps the GBK `*2` width math
`bar[0..-1]` returns the full bar for 0, and anything above 50% clamps
to full. Rework the bar as 1 glyph = 1 char. A full-looking bar hides
§8.9-class zeroes (`tybxjh`'s `score`).

### 7.86 `inherit X;` + redundant `replace_program(X)`
Any later closure bound to that object fails: `cannot bind an lfun fp
to an object with a pending replace_program()`. The usual victim is
board `post`.
- Delete the `replace_program`; keep the `inherit`.
- Check every class that creates `(: lfun ... :)` closures, plus
  generator templates (`cmds/king/set_board.lpc`, `build.lpc`).
- Grep bare `replace_program(` and compare its argument against the
  file's `inherit`, whether a macro or a literal path.
- Corpus-wide for rooms: §7.100.

### 7.87 `if (!restore() && !mapp(X)) X = ...` is unsafe
`restore()` THROWS when:
- the file exceeds `maximum read file size`,
- the mapping is corrupt, or
- the file is unconverted GBK.

`X` then stays 0 and emotes break game-wide, invisible to logs. Fix
with `catch(restore()); if (!mapp(X)) X = ([]);`, and raise
`maximum read file size` above the `.o` file's size (400000 is common).
`emoted.lpc` swept on 165 libs; the size check was not swept.

### 7.88 Non-varargs 4-param `message()` wrapper called with 3 args
On `zjdywzb` and `yhwhpublicfi`, this soft-locked character creation
(an NPC `command("chat")` mid-`valid_leave`). Fix:
`varargs`, plus `exclude || ({})`. On the current driver,
`f_message` ignores a non-object arg 4, so verify live before claiming
a repro.

### 7.89 Bundled `runtime_config.h` index numbering mismatches the driver
`get_config()` reads the wrong slot.
- Typical symptom: a string port, so `socket_bind("10")` crashes the
  wizard login.
- Fix: replace the header with the driver's canonical copy. Alias
  dropped symbols (`__SAVE_BINARIES_DIR__` → `__MUD_LIB_DIR__`) and
  remove `__ADDR_SERVER_IP__` uses.
- `__PORT__` is compiler-predefined; don't redefine it.
- `__BIN_DIR__` throws; `catch` it.
- Grep every `get_config(` call site.
- Survey 2026-10-04 (`scripts/runtime_config_survey.py`): 205 of the 216 libs that ship a `runtime_config.h` still have the
  MudOS-era numbering (integer settings from 15, this driver from 256; strings 1 and 6 are obsolete and answer `Bad
  argument to get_config()`). The driver's copy is in `skylib`, `openlib`, `nt7`, `xkx100utf8`, `aoxiangtianji`,
  `yhwhpublicfi`, `zjdy2008wzb`, `zjdywzb` and, since today, the Discworld family (where `/net/daemon/http`'s `create()`
  died on `Trying to put string in int` every time). The call sites in the rest: the shared xkx `config` admin command
  (`__ADDR_SERVER_IP__` raises), `LOCAL_PORT()` (`((int) get_config(__MUD_PORT__))`: the cast does not convert; 55 sites
  in 51 libs), and `versiond.lpc`/`cruised.lpc` (`bin_path = get_config(__SAVE_BINARIES_DIR__)` raises in `create()`, so the
  daemon never loads, which the `find_object(VERSION_D) &&` login guard of §1.3(c) papers over). Replacing the header
  changes which of those work, so a sweep is per class, not a blanket copy: a version daemon that starts to load can
  start to gate logins.

### 7.90 `maximum evaluation cost` too low (700000 template, sometimes 400000)
Cold compiles and NPC setup trip `cost limit reached`. Shapes seen:
- non-wizards see a generic "臭虫" message on room entry,
- `make_body()` aborts registration silently,
- background daemon heartbeats.

Fix: raise it to `5000000`. Proactively bumped on 74 libs. A retry that
succeeds in the same process is NOT proof it's fine; the compile is
cached. Test with a fresh driver.

### 7.91 One-character skill typo in a sect master's `create()`
`set_wugong("shalin-xinfa")` throws before `create_family()`, which
kills the whole sect's join path. Grep `No such skill` after visiting
each master's room (`xajhxo`).

### 7.92 `user_cwd()` assumes letter-sharded `/u/` while the tree is flat
Return `"/u/" + name` (the 风云3 family; done).

### 7.93 Admin set-command writes `me` where it means `ob`
One late line in `setparty` mutated the admin, not the target. Grep
`cmds/{wiz,arch,adm}/set*.lpc`.

### 7.94 Live command lost its plain `.lpc` filename
Only `.C`/`.bak`/`复件` drafts remain, so the verb is "什么？". Restore
it only when an independent matching copy proves which version is real
(`xyzxfk`'s `inventory`, `xyzx3`'s `setskill`).

### 7.95 `notify_fail(...)` followed by `return 1`
The message is discarded. Return 0, i.e. `return notify_fail(...)`
(`xbtxiii`'s `fight`).

### 7.96 `catch(load_object(path))` isn't an existence test
`load_object` of a missing path returns 0 without throwing. Use
`file_size(path + ".lpc") >= 0`, with chained fallbacks.
A shared `move()` that does `err = catch(dest = load_object(dest)); if (err) error(...)` and then `dest->receive_object()` is the same mistake (2026-10-18): `move("/open/x/room")` to a room the archive lacks raised `Bad argument 1 to EFUN call_other()` (every bulletin board whose `location` is a wizard's room: `std/bboard.lpc setup()`; dfgs2, dfgsiiv13b, huoying, naruto, kxkj, kxkjii2 -> kxkj 31 of 31 sampled objects failed, 15 load now). `if (!objectp(dest)) return 0;` after the catch.

### 7.97 Multi-line `#define` with no `\` on the FIRST line
The rest leaks as top-level statements, so `dns_master` fails to
compile. Every death then crashes in `gchannel`, and `die()` loops
forever (`sjsh`'s `include/net/config.h`).

### 7.98 Daemon reads its own config in `create()` without `seteuid()`
The custom ACL denies the read, `read_file` returns 0, and an
`explode()` crash during preload looks like a missing file.
- Fix: `seteuid(ROOT_UID)` first.
- Also check functions reached only by player actions (`hy5`'s
  `bgift`).

### 7.99 `file_size(file) < 0` guard ahead of `new()` breaks extensionless paths
`file_size` is a literal `stat` with no `.lpc` resolution. Check
`file`, `file + ".lpc"`, and `file + ".c"` (`sjshwzjqb`).

### 7.100 `inherit ROOM; ... replace_program(ROOM);` on the room base class (corpus sweep COMPLETE)
Same mechanism as §7.86. Nearly every room is a dormant closure
landmine; rooms that create a closure first get "cannot replace a
program… ignored".
- **Method:** a binary-mode script deletes lines that are exactly
  `replace_program(<macro>);` (for a new lib:
  `scripts/lpc_drop_replace_program.py [--apply] SLUG`, which also checks
  that the argument is the file's own `inherit`). Hand-fix the irregular shapes:
  - space before `;`,
  - shared line with `setup();`,
  - trailing comment,
  - `\r\r\n` endings,
  - `.lpc` source living under `work/data/` or a dir literally named
    `binaries/`.
- Also fix room-generator templates: `roommaker`, `rmaker`, `wall.lpc`,
  `flatroom`, guild-hall commands, and `item_desc`-conditional variants.
- Verify each lib: diff-stat count equals the script count, `build-debug`
  boot is clean, and an admin room walk works.
- **Result:** 191 libs, about 349.7k occurrences, all swept. Leave
  already-commented lines and files that are syntactically broken
  anyway.
- **Never `git stash` mid-sweep** (§10.5). Use `git add -u` plus
  explicit `NOTES.md` paths.

### 7.101 `valid_leave()` handles directions that `exits` omits
`go` rejects anything not in `exits` before `valid_leave` runs, so the
death-recovery `south`/`up` were dead and every death was permanent.
Restore the commented-out exits (`kxkjii2`; `kxkj` is identical). Type
every recovery command during a death test.

### 7.102 `go.lpc` force-loads the exit destination unguarded
A stale exit dumps a raw traceback. Fix:
`if (catch(call_other(dest,"???"))) return notify_fail("无法移动。\n");`
(`zzfy3`, `zzfy`).

### 7.103 `log_error` writes compile warnings to `this_player(1)` (every player)
Gate the write with `strsrch(message,"warning:")==-1`. Better: use
`"arning:"` (§7.10). Some libs gate behind `wizardp` already, so only
wizards see it.

### 7.104 Netdead auto-cleanup deletes young accounts without the quit path's y/n
`force_quit()` calls `remove_user()` when `mud_age < 1800` (or a
`birthday` variant). Delete that branch so it always saves. Done on 10
libs, verified via grep that the `remove_user` inside `force_quit` is
gone.

### 7.105 Training dummy lacks the flag `fight` checks
`fight` only calls `accept_fight()` when `can_speak` is set, so spars
were lethal. Fix by `set("can_speak",1)` on the dummies
(`tianxiawuxue`).

### 7.106 `update.lpc`: `present(file, environment(me))` with no environment
Guard with `environment(me) &&`. Swept across `cmds/{wiz,adm,imm,apr}/`.

### 7.107 `closed.lpc` mass-restores closed accounts each heartbeat; `restore()` uncaught
One corrupt save leaks a zombie object every tick, burns CPU for hours,
and churns hundreds of saves. Fix:
`err = catch(ok = ob->restore()); if (err || !ok) {cleanup; continue;}`.
Swept on 36 libs. Revert the save churn before committing.

### 7.108 Kick-duplicate-login reconnect loses command dispatch
Every command answers "什么？". Fix: `enable_commands()` at the top of
the body's `reconnect()`. 162 libs, plus `qhxajh`, which the sweep
missed. Test by logging in twice and answering `y`. "Stalled boot"
outliers were all false positives; verify with `nc`.

### 7.109 Uncaught `init_new_player(user)` before world entry
A throw strands the character forever with no save. Fix:
`catch(init_new_player(user));` (113 libs). An independent §7.90 cold
compile can cause the identical symptom; test with a fresh driver.

### 7.110 DANGER: `closed.lpc` `load_all_users()` mass `enter_world()` at t≈3s
Compiling dozens of zones at once fragments the allocator. RSS
balloons; `nt1` hit 10GB and OOMed the host. Before booting a lib with a
big `data/closed.o`, run `wc -c` on it and boot under a cap:
`(ulimit -v 6291456; exec ./driver config.fluffos)`. Signature: LPC
"accounted" memory is small while RSS is huge (`mud_status(1)`). No fix
implemented yet (it would need batching).

### 7.111 `standard_trace()` calls `file_name(error["object"])` when the object is 0
The handler crashes and eats the real trace. Fix:
`objectp(o) ? file_name(o) : "(driver)"` (67 libs).

### 7.112 `init()` unconditionally schedules a `call_out` chain
`enable_commands()` on reconnect re-broadcasts `init()`, so chains
duplicate and race (wrong revive room, double penalties).
- Fix: a per-victim `set_temp`/`delete_temp` guard, cleared at every
  exit of the chain.
- Hides under many filenames: `wgargoyle`/`bgargoyle`/`pang`/`b`/
  `yu-zu2`/`panguan`/`mengpo`/`yanluo`, arena rooms, `kfroom_*`. Grep
  `call_out("death_stage"` (and any `call_out` inside `init()`) and
  read the control flow. `remove_call_out` self-guards and differently
  named flags are already safe.
- Swept on about 300 libs. If it keeps recurring, move the fix into a
  shared base.

### 7.113 Netdead reconnect never restores `heart_beat`
Healing freezes and the revive gate never opens. The real reconnect
path must call a body-side `resume_heart_beat()`, since
`set_heart_beat` only affects `this_object()`. Only `shzs` had it; 61
other libs verified clean. Don't trust `call ob->query_heart_beat()`;
an undefined function returns 0.

### 7.114 `private` `input_to()` string callback reached via an inherited mixin
The re-arm silently fails, so the multi-line editor (post, mail, chfn)
swallows every line after the first. Drop `private` (5 libs). Same
family as §8.3a.

### 7.115 `QUEST` macro points at a missing file
Only `aoxiangtianji` had live callers. Guard with
`file_size(QUEST+".lpc") > 0 &&`. Survey of 80 libs is closed.

### 7.116 `userp()` is sticky ("ever interactive")
A natured cleanup `move()`d destructed zombies forever. Use
`interactive()` (`bmxkx2001` plus 6 siblings).

### 7.117 Apprentice "betrayed old sect" check without a family-exists guard
First-time joins get rejected. Fix:
`me->query("family") && ...`. `sj` also had
`query("family/master_id" == ...)`. 121 files swept; `sjshv150` was
missed. Check both halves of the `recruit`/`apprentice` pair.

### 7.118 Hardcoded `.c`-length slice math in dispatch tables and header generators
Command keys come out as `look.l`, so everything is "What?"; or
generated headers are empty, cascading hundreds of failures.
- Libs seen: `sunshadow`, `nightmare4`, `residuum`, `revivalworld`,
  `dsI`, `rifts2`, `pd`, `sanguozhi`'s `dir`/`doc_d`.
- A `continue`-skip variant (`sunshadow`'s `feat_d`) hid a whole layer
  of feat files.
- Also grep `+".c"`/`file_size(x+".c")` existence gates
  (`dreamofseven`). Make slices extension-agnostic.

### 7.119 Warning filter checks `"Warning"` while the driver emits `"warning:"`
Use `"arning:"` (`zhyx`, `naruto`).

### 7.120 Save-integrity helper is a no-op stub
Every player is locked out after the first driver restart. Restore it
from a sibling (`revive` ← `hell`). Always test stop → restart →
reconnect.

### 7.121 Declared-`int` economy/XP math returns floats
`(int)` is a no-op at runtime; use `to_int()`.
- Floats corrupt saved money, crash array indexing, or garble
  `random()`.
- Also applies to call arguments passed to `int` parameters
  (`AddHealthPoints(float)` in Dead Souls `eventRevive`).
- Seen in: Dead Souls `economy.lpc` (`dsIII`), `ninetears`,
  `sanguozhi`'s `jimou`, and `ds386`/`dshakkard`/`deadsouls_fluffos`'s
  `eventRevive`.
- Check every caller.

### 7.122 Autoload reload clones markers already present
Saves embed the item, then `load_autoload_obj()` clones again, so items
duplicate on each reconnect cycle. Make the reload idempotent: skip any
`base_name` already in the inventory.
- TMI-2 lineage: `mortremains`, `tmi2`, `es1`, `es1_win`.
- Nightmare: `nightmare3`'s `__AutoLoad`/`setup()`.

### 7.123 Bare top-level `ident = (...);` at file scope
Parsed as a redeclaration; the file never compiles. Merge it into the
declaration or move it into `create()` (`sunshadow`'s `astronomy_d`
blanked every outdoor `look`).

### 7.124 Percent threshold initialized with a fraction (`Wimpy = 0.20`)
The flee check is dead and float returns corrupt the display. Fix
`Wimpy = 20` and use `int` setters and getters. Seen in
`nightmare4`, `dsI`, `dsII`, `ds386`, `dsIII`, `dshakkard`,
`deadsouls_fluffos`.

### 7.125 `enter_world()` sets `registered=1` unconditionally
The email-register gate never works. Delete it; the NPC's `do_decide`
sets it. Seen in `zhyx`, `yanhuangwuhun`, `yhyxs`, `yhwhpublicfi`.

### 7.126 Stale `.c` inside `.o` save data used by `load_object`
Seen as AREA door macros (`naruto`, `huoying`), bank `location`
(`dreamofseven`), and player `guild_ob` (`ninetears`). Fix: strip a
trailing `.c` at the resolve choke point; don't edit the saves.

### 7.127 Wrapper parameter type narrower than every real caller
Generalizes §7.81. Examples: `revive`'s `set_information`; `pd`'s
`set_id`/`set_long`/etc. declared `string` while callers pass arrays or
closures. Widen to `mixed` and normalize where needed. That fixed 88%
of `pd`'s failures.

### 7.128 Custom dispatch's `process_input()` returns the input string
The driver re-parses it against an empty `add_action` table and appends
"什么？" after every command. Return `1`; `0` still falls through
(`revivalworld`).

### 7.129 `tell_room` forwards an omitted `exclude` as int 0
`create_ghost`'s 2-arg call broke `es1`'s whole death cycle (`die()`
looped). Fix with an `if (exclude)` branch. In the ES2 family,
`demonangel` and `naruto` were also unfixed. Trace with
`debug_message()`; `log_file` silently no-ops without euid.

### 7.130 `query_idle()` after a non-interactive branch in `heart_beat()`
Crashes every tick and leaks a body. Guard with
`if (objectp(this_object()) && interactive(this_object()))`; a
synchronous `quit()` can destruct mid-tick (`ninetears`,
`finalrealms`).

### 7.131 Pre-master-object archives never call `set_living_name()`
`find_player`/`find_living` always return 0. Register at login and in
monster `set_name()`.
- The duplicate-login self-exclusion trick breaks: register only after
  the dup check.
- `try_throw_out`'s `restore_object` wipes object globals: re-set
  `myself`/`soul`.
- Seen in `lpmud141`.

### 7.132 `map()` over a mapping calls `(key, value)` here
Single-parameter callbacks get the KEY. Add the key parameter
(`arkadia`/`genesis`'s `do_decay`).

### 7.133 Master `remove_interactive()` is never called; the driver calls `net_dead()` on the player
Add `nomask void net_dead(){ SECURITY->remove_interactive(this_object(),1); }`
on the player class. That exposed a statue `revive()` string→object
bug (`arkadia`, `genesis`).

### 7.134 Room `room_descs` declared without an initializer
`member_array(0, room_descs)` crashes every `look`. Fix:
`= ({})`. Sibling shape: an unconditional `return align_array[0]` on a
possibly-empty array (`finalrealms`).

### 7.135 One accessor in a family lacks the lazy-default guard its siblings have
`query_list_temp_start()` returned 0, so `quit` crashed before saving.
Add the guard (`arkadia`). On `genesis`, `quit` called missing
functions; switched to the `VALID_*_START_LOCATION` macros.

### 7.136 Mortal `cmdsoul_list` stripped, relying on missing race content
Players get only the NPC soul set, so `look` is "What?". Reseed from
the archive's own `proto_char.o` list, guarded by
`member_array("/cmd/live/things",...) < 0` (`genesis`).

### 7.137 `command("$verb")` alias-bypass prefix is unsupported
The literal `$look` fails. Strip the `$`; the quicktyper's
`modify_command` is dead here anyway (`genesis`, 13 sites).

### 7.138 `notify_fail` wrapper keys on `efun_defined()` (build flavor) instead of runtime state
Custom messages vanish into "What?". Branch on
`efun::query_verb()`, and hoist the `_notify_fail` prototype out of its
`#if`. Native `query_verb()` returns int 0 when there is no verb, not
`""` (`skylib`).

### 7.139 Colour translation lives in `catch_tell`; config lacks `interactive catch tell : 1`
Literal `%^TAG%^` appears everywhere. Add the config key. Check the
archive's `local_options` for `INTERACTIVE_CATCH_TELL` (`lpuni`).

### 7.140 `valid_read` uses `this_interactive()`'s privileges for `func=="include"`
The first non-admin to trigger a lazy compile permanently breaks that
file.
- Fix: `if (func=="include") return 1;`.
- Also: home dirs were created only for the first registrant. Hoist the
  mkdir, and guard `log_error`'s write with `directory_exists`
  (`lpuni`). Always test with a fresh non-admin account.

### 7.141 `replace_program()` fold in room `create()`
This driver defers the replace for about 5 minutes. Closures (in `say`)
fail with "pending replace_program" during that window. Remove the
fold. Seen in `dsI`, `ds386`, `dsII`, `dsIII`, `dshakkard`,
`deadsouls_fluffos`.

### 7.142 Virtual-grid exit typo
`compile_object` manufactures an orphan duplicate room instead of
failing, so `file_exists` checks give false negatives. Compare against
the namespace convention (`tmi2`: `/d/grid/9,14` vs
`/d/grid/rooms/9,14`).

### 7.143 Self-registered `add_action("cmd_hook","",1)` never attaches for reset-spawned NPCs
There's no `command_giver` at registration, so NPC `force_me()`
silently fails.
- Fix: route vendor speech via a `tell_room` helper rather than editing
  the core `cmd_hook` (`nightmare3`).
- Unverified siblings: monster spellcasting, `realtor`.

### 7.144 Generic NPC base self-names in `setup()`
`set_name` is one-shot, so later per-instance renames silently fail and
lookups break (`finalrealms`'s healer). Don't name the shared base;
callers name it.

### 7.145 Subclass `add_action` on a verb the base shop already handles
It shadows the real buy/sell (silent no-op). Use the base's
`set_open_condition()` hook instead. Check NPC `id()` case (`finalrealms`).

### 7.146 `/ text */` (missing `*`)
Compile error at some sites; silently compiled garbage at others. Grep
`'); / [a-z]'` (`finalrealms`).

### 7.147 Unguarded `FACTORY->request(...)->move()` when the factory documents a possible 0 return
Store the result and guard it (`discworld`).
- More severe when reached from a bootstrap or crontab loop: one miss
  silently truncates every later entry (`nt7`'s `equipmentd`/`timed`).
- Grep `find_object(X) || load_object(X)` loops too.

### 7.148 Parameter named `nosave`/`static`
These are `L_TYPE_MODIFIER` tokens here, so the file fails to parse
with "unexpected L_TYPE_MODIFIER". Rename (`discworld`'s print shop).

### 7.149 First-admin bootstrap checks membership in a domain that is never created
The bootstrap re-fires for every registrant and nobody actually becomes
admin. Also, case normalization differs between create and check.
- Fix: create the domain first and use one consistent case
  (`sanguozhi`).
- Verify by exercising a privileged action, not by trusting the
  message.

### 7.150 Throwaway password-check clone of a `LIVING` class is never destructed
Its heartbeat autosaves a stale snapshot over the real save, reverting
progress silently. Destruct it before reassigning, and in
`net_dead` (`merentha`).

### 7.151 `tmp[goods]` (array as mapping key) where `tmp[goods[i]]` was meant
Shop stock always shows 0 (`xxcqii`, `xxcqii2`).

### 7.152 `reconnect()` omits `set_living_name()`
After any dropped connection, `tell`/`call` can't find the player. Mirror
`enable_player()` (`xxcqii`, `xxcqii2`). Don't confuse this with the
lib's 10-second relogin cooldown.

### 7.153 `read new` branch falls into an unconditional `if (!sscanf(arg,"%d",num))`
Fix with `else if` (`yxsj`, `yxzsj`'s `jboard`).

### 7.154 `present("fire", this_player())` in `look_room()` reached from `call_out`s
`this_player()` is 0 there, so corpse decay and dawn crash at night.
Guard with `objectp(this_player())` (`xyj2006zzzhx`, `xyj2006n`).

### 7.155 Netdead `reconnect()` overwrites `link_ob` without destructing the stale one
One object leaks per reconnect. Mirror `confirm_relogin`'s destruct
(`xsfyssjb`).

### 7.156 Regression risk from the §7.30 fix
A caller that relied on a falsy `query_skills()` to call `set_skill()`
now mutates a disconnected copy, so the first learned skill is lost.
Call `set_skill()` unconditionally. Only the `xyxyutf8` lineage was
affected (3 libs); survey closed.

### 7.157 Diamond inheritance duplicates instance variables per path
Fixing the `nomask` errors makes functions resolve; variables still
duplicate, with only a "Redeclaration of global variable" warning. Two
functions can then touch different copies (`realms`'s region `grid`).
- Minimal fix: override the writer in the reader's file.
- Real fix: a singleton object instead of a shared inherit.

### 7.158 LDMud lineage (`questmud`): architecture gaps
1. `valid_read` needs `load_object`/`recompile_object`/`include` cases.
2. `creator_file()` must return a string. Exempt the backbone uid in any
   `creator()`-based guard.
3. `efun::` overrides outside simul_efun need a permissive
   `valid_override()`.
4. `reset()` is lazy here; see §7.192.
5. **`A->move_object(B)` silently no-ops** when `A` lacks an LPC
   `move_object`: `call_other` never falls back to the efun. Add
   `move_object(dest){ return efun::move_object(dest); }` to the
   global include, not one base class: boards, plaques and loot
   that inherit nothing stayed put (questmud's hall boards,
   2026-10-06).

Guide: `docs/ldmud-to-fluffos.md`.

### 7.159 Wizard-home paths in shipped content (`majik3`)
- If the real file exists elsewhere, repath it (sed
  `/home/madrid/agriculture/` → `/world/agriculture/`, 47 files).
- If it was never archived, leave it.
- A bare "Fail to load object" with no error text usually means a call
  to an undefined function (a runtime error the batch swallows). Read
  `log/runtime`.
- `say()` passed the raw `ob` instead of the built `ob2` to the first
  `message()`, so every `quit` errored.

### 7.160 Missing native driver-package efun (`majik4`'s `generate_map`)
Add a minimal labeled stub so the game is enterable; that's not a real
port. Also needed: master uid applies, missing `log/`/`binaries/`, and
typo fixes. Commands queue one per 2+ heartbeats, so wait longer
between sends.

### 7.161 Modern lib uses non-`OLD_ED` editor efuns (`oxidus`)
That breaks the whole body chain. Revert to the classic `ed()`. Never
flip `OLD_ED` corpus-wide.

### 7.162 Dynamic callback-name targets must not be `private`
`ed()` write/exit callbacks, `call_out`s, and socket callbacks resolve
by name like outside callers, so a private target silently fails. Make
them public. Fixed-name driver applies may stay private.

### 7.163 `class X array NAME`
Rewrite to `class X *NAME`. Grep `class \w+ array` (`riftsds`).

### 7.164 Flagship content depends on a base framework the author never committed
`riftsds`'s omega/common/std domains: 496 failures from one root cause.
Document it; don't author the framework. Don't advertise that content.

### 7.165 `message()` compat shim always forwards `exclude`
Branch on whether `exclude` was given. On `darkelib` that took
failures from 1363 to 493.

### 7.166 Daemon `create()` calls its own `check_privilege()`-gated mutator
There's no `this_user()` at boot, so it fails silently under
`preload`'s `catch`. Wrap with `unguarded(1, (: fn, args :))`
(`spacemud`'s `method_d`/`space_d`).

### 7.167 Collection-emptiness traps
- `mapping == ([])` compares references and is always 0. Use
  `!sizeof(m)`.
- `explode("", sep)` returns `({})`. Guard with `sizeof` before `[0]`
  (`spacemud`'s `crafting_d`, `m_frame`).

### 7.168 `(: head, "method" :)` is a call_other pointer only when `head` is a bare compile-time NAME
A string constant or a function call silently becomes a
comma-expression (returns `"method"`). Use
`(: call_other, target, "method" :)` (`basis`).

### 7.169 Vestigial `private inherit` of an already-public base
It creates an ambiguous second, uninitialized copy. Delete it; changing
it to `protected` hides the bug silently (`basis`).

### 7.170 `file_name()` has a leading `/`
`== "room/room"` is always false, and the self-delegation recurses
infinitely (`lpmud245`).

### 7.171 Non-wizards see only `default error message`
`debug.log` still has the full trace. Read it before concluding "no
bug".

### 7.172 `command(str, ob)` doesn't exist
`command()` runs as `current_object`. Add `do_command(str){return
command(str);}` and call `target->do_command(str)`.

### 7.173 `transfer(a, b)` doesn't exist
Use `a->move_object(b)` via the §7.158 shim. Return values are no
longer meaningful.

### 7.174 `add_action("f"); add_verb("v");`
Merge into `add_action("f","v")` (`lpmud245`: 366 sites).

### 7.175 `PACKAGE_UIDS` needs `creator_file()` for every load
Stub it alongside `get_root_uid`/`get_bb_uid`.

### 7.176 `valid_read`/`valid_write` get the calling OBJECT, not a euid string
`string eff_user` comparisons are always false, so every save is
denied. Fix:
`if (objectp(eff_user)) eff_user = geteuid(eff_user) || getuid(eff_user);`
(`lplib8`).

### 7.177 A direct `reset(0)` call can silently no-op
Move the logic into `do_reset()` and call that from `create()`, or use
`call_other(this_object(),"reset",0)` (`holymission`; `lpmud141` used
the latter).

### 7.178 Master apply never called by this driver (`inaugurate_master`)
Seed data in `create()` instead. Grep the driver source for any
hook-sounding name.

### 7.179 `mkdir()` doesn't create parents
Create the letter-bucket dir first (`dock9`; `lpuni` is latent).

### 7.180 Monster `heart_beat` chat/emote/wander blocks lack `ENV(THOB)` guards
Pre-cloned, undispatched guard pools crash every tick. Guard every
block, and check `ENV(guard)` after `move` (`majik3`).

### 7.181 Unchecked `sscanf` leaves outputs at 0, which then go into `present()`
Check the match count and `stringp` (`basis`'s `look`, `ready`).

### 7.182 `create()` override omits `::create()`
Base `seteuid`/`set_permission` never runs, so commands fail permission
checks as if gated (`basis`: 13 commands).

### 7.183 Command entry point not named `do_command`
`cmd_<verb>` leftovers produce silent dead commands (`basis`: 20
files).

### 7.184 Simul_efun replacing a "trusted" efun must `seteuid(ROOT_UID)` itself
`valid_write` sees the simul_efun object, so `log_file` silently fails
(`basis`).

### 7.185 Shared room macros (`ONE_EXIT` etc.) also need `create(){reset(0);}`
Fixing only hand-written files leaves most of the map dark
(`lpmud245`).

### 7.186 `this_player()` is invalid in heartbeat-queued `force_us()` commands
Use `previous_object()` like the majority convention (`majik4`'s `warp`,
`vlook`, `who`).

### 7.187 Dispatcher keeps using `THOB` after the command destructed it
Guard with `if (!THOB) return ret;` after dispatch. `quit` →
`offline` replacement crashed every quit (`majik4`).

### 7.188 `move_object(string)` resolves only with `find_object`, never auto-loading
An `update` that only destructs breaks every later move to that room
(login stuck). Reload after destruct (`amylaarmini`).

### 7.189 Hazard-room `object_arrived` destructs small arrivals without an `is_living()` check
It destroys the player's body. Add the guard (`wilderness`'s
`Outside_Cave`).

### 7.190 Per-daemon ACL trust exemptions added piecemeal
`mail_d` lacked read trust, and `valid_write` had no daemon mechanism at
all. Add both (`dock9`; `lpuni` latent).

### 7.191 Sequential `get_dir()+get_dir()` with a missing dir
`array + int` aborts index loading midway. Wrap each call in an
`arrayp`-guarded helper (`havenmud`'s `help`).

### 7.192 The lazy-`reset()` gap hits base classes too
Rooms and monsters with no `create()` stay exit-less until the first
reset, an hour later. Add
`create(){ call_other(this_object(),"reset",0); }` to the base classes;
that exposes many latent bugs in `reset()`. Walk the world to verify
(`questmud`).

### 7.193 Diku port put the room-listing sentence in `SetShort()`
"…is here. is standing here." Strip it to a noun phrase for livings
only (`brassring`).

### 7.194 Reconstructed `#define Str (query_str())` used inside `query_str()` itself
Infinite recursion. Make accessors read storage directly
(`holymission`).

### 7.195 Dead Souls Praxis `*_join.lpc` use `SetClass()` where `ChangeClass()` is needed
The class silently never applies. Seen in `riftsds`, `ds386`, `dsIII`,
`dshakkard`, `deadsouls_fluffos`. monk/kataan/rogue have no class data
(content gap).

### 7.196 `compat.h` shim incomplete
Add `query_name`/`query_cap_name`/`query_gender` (same 5 libs).

### 7.197 Utility mixin's vestigial `id()` shadows the player's real `id()`
`present()` can't find players. Remove it. Read "inherited from both…"
warnings carefully (`lplib8`).

### 7.198 No `valid_shadow()` apply means all `shadow()` calls are denied
Ghosts fail and `die()` loops. Add `int valid_shadow(object ob){return 1;}`
(`lplib8`). An LDMud-era master may carry the old name `query_allow_shadow()`
(holymission): have `valid_shadow()` return it. Shadows that start working can
expose code that moves a shadowed object (§7.231).

### 7.199 `std/money.lpc`'s `query_autoload()` commented out
Every `quit` drops the player's money on the floor. Uncomment it
(风云 lineage, 16 libs).

### 7.200 `set_in_room_desc()` evaluates its closure at set time
Dynamic descriptions freeze. Store the raw argument; the getter already
evaluates (`sanguozhi`).

### 7.201 `give` money destructs it instead of moving it
Move it to the recipient. Keep the `receive_money` opt-in hook
(`sanguozhi`).

### 7.202 Player input concatenated into a `sprintf` format string
A `%` in the input crashes it. Pass the input as an argument
(`huoying`, `naruto` meeting rooms).

### 7.203 Directories the code writes into but never creates are missing from the tree
Mail, board `post`, the line editor and `eval` die with `*Wrong permissions
for opening file /tmp/<name>-N.m ... "No such file or directory"` or
`*Could not open /room/post_dir/<name>.o.tmp for a save`. The archive's
empty dir was dropped (git tracks no empty dirs) or never shipped. The first
error aborts the caller before it resets its lock (`lpmud141` post office:
"You have to wait for <sender>" for everyone). Fix: tracked `.gitkeep`.
**Detection:** boot a pristine `git archive HEAD libs/<slug>/work` copy
(the working tree keeps the dirs earlier boots made) and run mail, board
post, `ed`, `eval` and every saving command (`scripts/pristine_tree.sh`);
static hint: `scripts/missing_write_dirs.py <slug>` lists literal and
`#define`d write targets whose directory is absent from `work/` (noisy:
confirm by running the command).
Seen: `tmi2` (`tmp`, `open`), `mortremains` (`open`), `lpmud141`
(`room/post_dir`, `banish`). Dirs the code makes itself (`mkdirs()`,
`assure_user_save_dir()`) need nothing.

### 7.204 Death empties the purse into the corpse but never saves
If the ghost is turned back into a body by restoring the save file, the
revived player gets the purse of the last save while the corpse holds the
coins too. **Detection:** set wealth W, save, die, revive: expect an empty
purse and W in the corpse. Fix: save right after emptying (`tmi2`
`std/user.lpc die()`). `lpmud141` saves after `transfer_all_to`; the ES1
libs back the user up at revive.

### 7.205 `remove()` run from `call_out` has no `previous_object()`
`seteuid(euid)` with an unset `euid` clears the euid, so the next
call-by-path (`FLOCK_D->...`) cannot load the daemon (`Can't load objects
when no effective user`), `remove()` aborts and the dead body stays in
the room. Only the first removal after boot fails (any earlier `quit`
loaded the daemon). Fix: default `euid` to `geteuid(this_object())`
(`tmi2`).

### 7.206 `net_dead()` assumes the body is already in a room
A connection dropped at the post-login "Press ENTER to continue" prompt
has no environment: `message(..., environment(), ...)` raises `Bad
argument 3 to EFUN message()` and the rest of `net_dead()` is skipped.
Guard with `if (environment())` (`tmi2`, `mortremains`).

### 7.207 Global dialog lock never released on abort or disconnect
A daemon flag set on entry (`suicide`'s `busy`) was reset only on the
success path (`busy = 1` typo on abort), so one `n` or one dropped
connection disabled the command for everyone. Keep the owner object and
ignore a holder that is no longer interactive (`tmi2`, `mortremains`).

### 7.208 `die()` dereferences a null `killer`
`killer = query("last_attacker")` falls back to `previous_object()`, which
is 0 when `die()` runs from the body's own `heart_beat()` (poison, trap,
admin `receive_damage()`); `killer->query("npc")` raises, and
`continue_attack()` re-enters `die()` every tick, so the death never
finishes. Guard with `killer &&`. A fix ported to one sibling must be swept
to all: `esI` -> `es1_win` -> `es1` (the last one missed).

### 7.209 `[0..-2]` / `[-2..]`: negative range ends do not count from the end
**Symptom:** an empty string or array, or the whole value, where "all but the
last" or "the last two" was meant. Foundation I `uptime` printed a lone `.`,
and `cd ~` went to `/` because `absolute_path()` built `user_path(...)[0..-2]`.
**Cause:** the MudOS/LDMud idiom. Here a negative end gives `""` / `({ })`
(`"abcd"[0..-1]` too), a negative start clamps to 0 (`"abcd"[-2..]` is the
whole string). `old range behavior : 1` is not the fix: it handles strings and
buffers only, not arrays (docs/lpc/types/substructures), and the docs advise
against it.
**Fix:** count from the end with `<`: `[a..-N]` → `[a..<N]`, `[-N..]` →
`[<N..]`, `[-N..-M]` → `[<N..<M]`; "to the end" is `[x..]`. Leave range
*lvalues* alone: `str[0..-1] = foo` is the documented prepend.
`scripts/lpc_fix_negative_ranges.py SLUG [--apply]` does all three in code only (comments, strings, here-documents blanked),
skips range lvalues and lists the bounds that are negative *expressions* (`msgs[-max+1..-1]`) for a hand edit; it refuses
submodule-hosted libs (patch or PR). Run 2026-10-04 over every lib whose `work/` is plain tracked files: 1550 bounds in about 545 files of 212 libs (1170 of the
sites were `..-1]`; `nirvlp312` 154, `holymission` 109, `genesis` 69, `arkadia` 41), each lib's changed files compiled at HEAD
and in the working tree with no new error. Four range lvalues in `nirvlp312` stay. The ten libs whose `work/` is a gitlink
(`fy2005`, `imud`, `lima`, `nightmare3`, `nt7`, `oxidus`, `residuum`, `sanguozhi`, `xkx100utf8`, `deadsouls_fluffos`) need the
same change as a catalog patch or a PR. `-name`, `-(expr)` and `-f(args)` bounds become `<name`, `<(expr)`, `<f(args)`
(a variable that is 0 at run time reads as `<0`, not `-0`).
**Detection:** the compiler warns `A negative constant as the second element
of arr[x..y] no longer means indexing from the end` (rvalue end indexes only),
so `scripts/lpc_warnings.py` sees those; negative *start* indexes need a grep
(`\[\s*-\d+\s*\.\.`). A corpus grep for a negative constant end ≤ -2 found
247 sites in 149 libs (2026-10-03; `genesis` 39, `arkadia` 22, `nirvlp312` 9,
`es1` 6, `sticklib` 5, ...): a sweep is queued, history libs first.

### 7.210 `lib.h` redefines a `LIB_*` macro to a path that does not exist
**Symptom:** `warning: Macro 'LIB_LIMB' redefined`; in `dsI` severing a limb prints
"X's fourth hand is severed!" and then dies at `new(LIB_LIMB)` (`Bad argument 1 to
EFUN call_other ... Got int(0)`), so the limb never appears and its worn items stay
on the body. **Cause:** `lib.h` includes `std.h` (`LIB_LIMB DIR_STD "/limb"`, the real
`/lib/std/limb`) and then redefines it as `DIR_LIB "/limb"`, a stale line pointing at
a file that is not there; every object that includes `<lib.h>` gets the wrong path and
`new()` returns 0. **Fix:** delete the stale line (the later Dead Souls releases did).
**Detection:** a `Macro redefined` warning on a `LIB_*`/`DIR_*` name is not cosmetic
until both expansions have been checked with `ls`; in a pristine boot run
`eval return new(LIB_X)`.

### 7.211 A function renamed in one file, its `call_other` callers in other files not
**Symptom:** the elevator's call buttons stopped closing the door: `car->SetDoor(1)`
now answers "Door not found." and nothing errors. **Cause:** upstream renamed the
elevator's own `SetDoor(int)` to `SetDoorClosed(int)` (it shadowed `LIB_EXITS::SetDoor(dir,
file)`), fixed the calls inside `elevator.lpc`, and left `car->SetDoor(1)` in
`obj/ebutton1.lpc`/`ebutton2.lpc`. The old name still resolves to the *inherited*
function, so the stale call "works". Present in `ds386`, `dsIII`, `brassring`,
`dshakkard`, `riftsds`; `dsII` still had the pre-rename `SetDoor(int)` (consistent, but it
clashed with `LIB_EXITS::SetDoor`, an arg-count warning) and was renamed in step with
dsIII. **Fix:** point the callers at the new name (`ds386`, `dsII`, `dsIII` done; the three
submodule-patch libs need a patch or upstream PR). **Detection:** after any rename, grep
the whole tree for `->oldname(`: the compiler cannot warn about `call_other`, and an
inherited function of the same name turns the mistake into a silent no-op.

### 7.212 Directories the archive ships empty, listed with `get_dir`, missing on a clone and on the site
**Symptom:** `help` answers `*Bad type argument to +.  Had array and int.  Object: /daemon/help
at line 58 ... 'LoadIndices' ... 'create'` and every later `help` fails too (`dsI`, `dsII`:
on the site and in any fresh clone; fine on the machine that did the port, where the
directories exist). **Cause:** the help daemon builds its index with `get_dir(DIR_X "/*.lpc") +
get_dir(...)`; `get_dir` of a directory that does not exist returns 0, and `array + 0`
aborts `create()`. The archive ships `secure/cmds/common`, `verbs/spells`, `verbs/undead` as
empty directories; git drops empty directories, and `scripts/gen_keep_dirs.py` only records
directories that exist in the LOCAL `work/` tree, which these never did. **Fix:**
`python3 scripts/raw_only_dirs.py [--apply] SLUG...` compares the pristine `raw/` extraction
with git plus `wasm_keep_dirs.txt` and lists the directories the lib's own code names (a
`#define` or literal that expands to exactly that directory); `--apply` appends them to
`wasm_keep_dirs.txt` (2026-10-03: 186 lines for 19 libs, among them `dsI`, `dsII`, `dsIII`,
`dshakkard`, `brassring`, `skylib`, `tmi2`, `discworld`, `foundation1/2`). The report reads a
submodule's own index, but its raw-root guess can be wrong (`deadsouls_fluffos` guesses
`secure`; skipped): read the printed root before `--apply`. A plain `git clone` still lacks
the empty directories, only the site recreates them from the list. **Detection:** a pristine
boot (`scripts/pristine_tree.sh` recreates the list) and `help`; `grep -c 'Bad type argument
to +' console` after the first creator login. Companion of §7.203 (write paths).

### 7.213 One file reached through two inherit paths
**Symptom:** hundreds of `Redeclaration of global variable 'RadiantLight'`/`'Smell'` and
`GetSmell() inherited from both /lib/events/smell.lpc and /lib/events/smell.lpc (via ...)`
whenever a class (and every descendant: 485 files in `dsII`, 929 in `dsIII`, 1020 in `ds386`) is compiled.
**Cause:** FluffOS has no virtual inherit: each inherit path carries its own copy of the
variables. `define_variable()` warns when a name is already known and forces the *later*
copy `nosave`; `overload_function()` lets the *later* inherit win every function (order:
first inherit < ... < last inherit < the current program) and warns only for functions
the current program does not define. So a leaf that inherits `LIB_ITEM` and then
`LIB_READ` again is served by the second copy and its variables are never saved, and an
extra `inherit "/lib/props/ambiance"` after `LIB_ROOM` replaces `room.lpc`'s
`GetAmbientLight()` (day/night light, the lit lamps in the room) with the plain getter.
Descendants repeat every warning, so the *source* files are few (`dsI` 9, `dsII` 66, `dsIII`
46, `ds386` 50, `deadsouls_fluffos` 50): `scripts/lpc_diamonds.py SLUG` lists files whose direct inherits overlap, and a
warning anchored on a declaration or `inherit` line that no parent already warns about
marks a source. **Fix, by kind:** (1) a redundant leaf inherit (everything it brings is
already in another inherit's closure): delete the line, unless the file calls `b::fn()`
through that scope name (only direct inherits are searched) or uses an unqualified
`::fn()` and the redundant inherit comes first (`::fn()` takes the first inherit that has
it); `lpc_diamonds.py --fix-redundant --apply` does the safe ones. (2) A mixin pulled in by
two parents of which one does not need it: `LIB_CONTAINER` and `LIB_OBJECT` both inherited
`LIB_RADIANCE`, `LIB_LIVING` and `LIB_OBJECT` both `LIB_SMELL`. Drop it from the parent
whose own use is nil (container: its function returns the contents' light, the classes
that are both object and container already add `object::GetRadiantLight()`; living is
never used without an object) and the pass-through that used the scope name. When some
classes do read the container's copy (havenmud: a room's own `SetRadiantLight()`, worn
storage that glows), give the container a `protected int GetContainerLight() { return 0; }`
hook in place of the inherit, and let those classes return their own `LIB_RADIANCE`'s
value from it (and pick the container's total with a `GetRadiantLight()` that calls
`container::`/`holder::`). Probe `SetRadiantLight(n)` on a room, a worn container and an npc
before and after. (3) The same
function in two unrelated mixins (`CanSell` in value and sell, `GetSave` in lock, close,
bait): delete the duplicate if the bodies are identical, otherwise define the function
in the class that inherits both and call the intended parent by scope; that is also what
silences the overlap for sibling parser applies (`direct_look_obj`, `inventory_visible`),
and the choice to spell out is whatever the inherit order already picked. (4) A private
variable with the same name in an ancestor and a descendant (`Level`, `Obvious`,
`CommandFail`, `mustcarry` in the copy-pasted `LIB_AIM` and `LIB_SHOOT`): rename the `nosave`/private one (no save-file impact), never the saved
one. (5) A leaf that inherits two *complete* classes (`LIB_BASE_DUMMY` next to
`LIB_STORAGE`/`LIB_FLASK`: dsIII's and ds386's scenery containers and water sources) has no
redundant line to delete: take what the first one adds (`isDummy()` and `SetInvis(1)`),
define it in the leaf, drop the inherit, and make every `inherits(LIB_BASE_DUMMY, ob)` test
ask `ob->isDummy()`. `LIB_BASE_DUMMY` also brings `LIB_ENTER`, `LIB_KNOCK` and `LIB_SCRATCH`
(the oracle lists 30 to 44 `direct_*`/`event*`/`Set*` rows per object as removed); nothing in the lib
uses them on these fixtures and `knock`/`enter`/`open` on them answer the parser's own
"You can't ..." either way (live-checked, `dsIII/NOTES.md`, `ds386/NOTES.md`). Where a leaf
inherits one of those for its own use (ds386's `seawater`: `LIB_EXITS` + `LIB_ENTER`), keep
that inherit and name the winner of the door calls the two share (`GetDoor`, `SetDoor`,
`ResolveObjectName`) with `enter::`. Read the dropped class's `create()` for every call it makes, not
only its inherit list: ds386's `base_dummy::create()` also calls `SetNoSink(1)` (dsIII's does not), which the
hybrids must make themselves; the oracle's getter list has no row for it, so check `GetNoSink()` live. (6) A dual-role class over two sibling classes that share a base
(`LIB_OOB` = `LIB_SOCKET` + `LIB_CLIENT`, both daemons): inherit the heavier one and carry
the few members of the other (a `Descriptor`, an `Owner`, three small functions).
**Detection:** `scripts/ds_oracle.py` before and after (KB 08 §10.12): function
definers change only where resolution was made explicit, `GetSaveString()` stays equal.

### 7.214 A hook both parents define: the later inherit's silently displaces the other
**Symptom:** `init() inherited from both /lib/npc.lpc (via /lib/sentient.lpc) and
/lib/base_trainer.lpc; using the definition in /lib/sentient.lpc`, and a feature that never
happens: in dsIII Radagast says "I am already training you!" for good once a pupil leaves in
the middle of a lesson. **Cause:** `overload_function()` keeps the later inherit's
`init()`/`create()`/`heart_beat()`; the earlier one (here the code that forgets a student who
walked away) is dead. **Fix:** define the hook in the class that inherits both and call both,
`sentient::init(); base_trainer::init();`. **Detection:** the warning, for `init`, `create`,
`heart_beat`, `reset`, `clean_up`, `eventDestruct`: read both bodies before choosing, and
check live that the displaced body's effect now happens (`dsIII/NOTES.md` structural pass).

### 7.215 `GetRadiantLight()` counts an object's own glow twice (dsIII)
**Symptom:** `SetRadiantLight(7)` then `GetRadiantLight(0)` is 14 for an NPC, a chest, a bed, a
chair, a corpse and 7 for an item or a player. **Cause:** dsIII's
`container::GetRadiantLight()` adds `GetBaseRadiance()` (the object's own glow) itself, while
`npc.lpc` and `storage.lpc` still add `object::`/`item::GetRadiantLight()`, which was right for
the dsI/dsII container (§7.213 kind 2). `worn_storage.lpc` goes the other way: armor's getter
wins and what the pack carries is not counted. **Fix:** all three return
`container::`/`base_storage::GetRadiantLight(ambient)` alone, as `interactive.lpc` does.
**Detection:** the `SetRadiantLight(7)` rows of `scripts/ds_oracle.lpc` across the lib.

### 7.216 A source file the driver only compiles at runtime is invisible to the scan (ds386)
**Symptom:** the lib scans clean, then the first-boot admin wizard (`cp("/secure/lib/connect.real",
LIB_CONNECT ".lpc")`) or the live-upgrade tool (`update.patch`, `update.blank`) copies a
non-`.lpc` file over a live program and 38 `nosave` function warnings, an unknown escape and two
unused locals are back on the first player's screen. **Cause:** `scripts/lpc_warnings.py`
compiles `.lpc` files only; `.real`, `.patch`, `.blank` are source in disguise. **Fix:** run the
fixer's routines (`fix_nosave_functions`, `fix_escapes`, `fix_unused_locals`) over temporary
`.lpc` copies in a scratch tree, with the diagnostics from a one-file `lpcc --batch` run, and copy
the result back; once the wizard has run, `diff connect.real connect.lpc` is empty.
**Detection:** `grep -rn 'cp(\|rename(' work | grep -v '\.lpc'` for source copied at runtime, and
a boot that completes the wizard, then a second login with the console watched.
`deadsouls_fluffos` (2026-10-04): `update.patch` and `update.blank` said `static void create()`, which this
driver does not read as a modifier at all (`syntax error, unexpected L_BASIC_TYPE`), so the first live upgrade
would have installed an update daemon that does not compile; `connect.real` had an unknown escape and
a `type.h`/`compat.h` `OBJECT` redefinition that only shows when a copy includes both. `static` -> `protected`.

### 7.217 Two uncaught errors in a row leave a Lima-family session mute (`HAS_PROCESS_INPUT` is dropped)
**Symptom:** a wizard's `clone` of a broken object fails twice (or a player repeats a command that raises), and from
then on every line gets only the driver's `> ` (swmud, wilderness) or `What?` (sgzmudsgz): `look`, `i`, `!look`,
`quit` all answer nothing until the player reconnects. **Cause:** Lima's `inputsys` registers
`input_to((: dispatch_modal_input :))` and re-arms it with `modal_recapture()` after the handler returns, so an
uncaught error in a handler unwinds past it and the next line reaches the user object's `process_input()` fallback
(the comment above it says so). `dispatch_modal_input` runs again there, and if that raises too the driver
(`comm.cc` `process_input`: `if (!ret) ip->iflags &= ~HAS_PROCESS_INPUT`) never calls `process_input()` for the
connection again; Lima has no `add_action` commands, so every line falls to `safe_parse_command` and is dropped.
**Fix:** what upstream Lima and spacemud already do: `catch()` around `evaluate(info->input_func, str)` and the `!`
escape's `dispatch_to_bottom()`, then `modal_recapture()` as before (swmud, wilderness, sgzmudsgz). The mudlib's
`error_handler()` prints for caught errors too (it checks `caught` only to pick `/log/catch`), so the player still sees
`*message` and `Trace written to`. Where it does not (`config.fluffos` has no `mudlib error handler`: sanguozhi; a
handler that logs a caught error and tells nobody: sagenwelt), print the caught string with `write()` the way the
driver's default does (wizards the error, players the `default error message`). **Detection:** boot, log in as a
wizard, `clone` a file whose `create()` is `int *a; a[0] = 1;` three times, then `look`; or
`grep -l 'modal_recapture' libs/*/work/secure/user/inputsys.*` and read `dispatch_modal_input`. Libs: lima and
spacemud had it fixed upstream; swmud, wilderness, sgzmudsgz fixed here; sanguozhi (submodule) goes upstream as a
PR; sagenwelt's `inp_sys.lpc` has the same shape but its header uses default arguments, so the player layer never
compiles and nothing runs it.

### 7.218 `get_dir(path) == -2` as a directory test (ES / TMI lineage)

**Symptom:** `bug`, `typo`, `praise` and `idea` answer `Thanks for the report` and never write the report to the domain's
`reports` file. **Cause:** the MudOS/LPmud `get_dir("/d/x")` of a directory answered `-2`; this driver answers an array, so
`(int)get_dir(d) == -2` (the cast is compile-time only) and `-2 == get_dir(d)` are always false (the driver says so:
`== always false because of incompatible types ( int vs mixed * )`, once the file compiles). **Fix:** `file_size(d) == -2`.
**Detection:** `grep -rnE 'get_dir[^;]*[=!]=[ ]*-2|-2 *== *get_dir' libs/*/work`; only `cmds/std/_bug.lpc` and `praise.lpc` of
`es1_win`, `esI` and `es1` had it (fixed 2026-10-04). Related: §7.191, §7.212.

### 7.219 A prototype says `varargs`, the definition does not

**Symptom:** `Wrong number of arguments to 'set_name', expected: 2, minimum: 2, got: 1` in five objects of `es1_win`/`esI`
(`silver_card`, `tavern_key`, `crimson_scepter`, `pig`, `wanderthief`), which therefore never loaded. **Cause:** `std/object/
ob_logic.lpc` prototypes `varargs void set_name(string str, string c_str);` and defines `void set_name(string str, string
c_str) {`; the definition's flags win, so a one-argument call is an error although the body already handles `c_str == 0`.
**Fix:** `varargs` on the definition. **Detection:** the scan's top error kind for the calling files, then compare the
prototype and the definition; MudOS passed the missing argument as 0, so any lib of that age can have call sites that
pass fewer arguments than the definition takes.

### 7.220 Plain-text path tables written with `.c` (`dynamic_location`, `dynamic_quest`), and what fixing them runs for the first time

**Symptom:** `adm/daemons/questd.lpc` never loads: `Bad argument 1 to EFUN call_other()` at `tar->set("value", 0)` in `spread_quest()`, out of
`create()` -> `init_dynamic_quest(1)`; the cron daemon that loads it fails with it, and `give` (which loads questd lazily for its quest hook) raised
(xyj2006n, the Journey-to-the-West family; xysylmhb found it first, August). The xkx / Fengyun / Haiyang daemons test the result: the random room
jobs and quest items silently never spawn, and hy5 `natured.lpc` raises on `base_name(room2)` of 0. **Cause:** the tables list `/d/x/y.c`; the
extraction renamed the files to `.lpc` and an explicit extension is resolved exactly (KB 03 §4.2), so `load_object("/d/x/y.c")` and
`new("/d/obj/quest/x.c")` are 0 without an error, while `children()`, `find_object()` and `base_name()` ignore the extension. **Fix:** the rows,
`X.c` -> `X.lpc` where `X.c` is not there and `X.lpc` is (`scripts/lpc_dynamic_rows.py`: 83,854 rows in 147 tables of 77 libs, only tables the
lib's code reads; no consumer mentions `.c` in code, checked over 152 files; rows naming a file in neither spelling are content gaps and stay:
fyzfqyy 2,268, jqxz2008 6,666). **Running it exposes what never ran:** `scripts/lpc_dynamic_quest_guard.py` wraps the `spread_quest()` call of
the `init_dynamic_quest()` loop in `catch()` (153 sites, 90 libs; `new()` of an item the archive never shipped is 0, a room may not compile:
xjcq2000 has none of its 42 `/quest/shenshu/bookN`, and its questd failed to load once the rooms resolved) and puts `objectp(this_player()) &&`
in front of `look_room()`'s `!present("fire", this_player())` (30 sites, 22 libs: `/feature/move.lpc remove()` calls `look_room()` for every
item a room's reset() destructs, with no this_player(), so `Bad argument 2 to present()` failed questd's create() on a random room pick in
xiyouji2006; xyj2006n carried that guard). **Detection:** `read_file("...dynamic_...")` in a daemon, then the tool's dead-row list; load the
daemon three times in fresh processes (the room picks are random: one pass proves nothing); never trust a HEAD PASS of a daemon that
tests `new()` for 0, it only means the code did not run.

### 7.221 A simul_efun override does not cover the files inherited into the simul_efun object

**Symptom:** residuum on the shared driver: every combat hit, miss, block and heal message is missing (only the `hp:` prompt moves while a
fight runs), while every other message arrives; its own `test all` fails `ability.test` (`'action'` where `'ability hit'` is expected).
**Cause:** catalog patch 0003 replaces `message()` in `secure/sefun/override.c` with an LPC version, because on a driver built without
`NO_ADD_ACTION` the efun never reaches a non-interactive character (no `O_LISTENER`). `sefun.c` inherits `combat.c` beside `override.c`, and
inside the simul_efun object a call that its own program does not define binds to the **efun**: `lpcc` on `sefun.c` shows `EFUN: message`
in `combat_hit_message`. Objects outside it get the override. **Fix:** `SEFUN->message(` at the 25 call sites in `combat.c`. A
`varargs void message(...);` prototype also rebinds the calls, but `combat.test` loads `combat.c` on its own, where the prototype has no body
(`Undefined function called: message`). **Detection:** for each name the lib's simul_efun overrides, grep the other files of the simul_efun
directory for bare calls, and confirm with the disassembly (`F_CALL_FUNCTION_BY_ADDRESS` vs `EFUN:`).

### 7.222 `author_file() in the master file does not work` at every boot (mudlib_stats probes)

**Symptom:** two lines right after the master loads, on every boot and so in every site visitor's terminal: `author_file() in the
master file does not work, using root_uid as fallback (see author_file.4)` and `domain_file() in the master file does not work, using
bb_ui as fallback (see domain_file.4)d` (43 libs on 2026-10-05). **Cause:** with `PACKAGE_MUDLIB_STATS` (on in the native and WASM
builds) `set_master()` calls `author_file(<master file>)` and `domain_file("/")` once and wants strings. A missing apply, an empty body,
a forward into a simul_efun that does not define it, or the TMI-2 / Nightmare / Dead Souls shape that credits only realm and domain
directories and falls through to `return 0;` all fail the probe. Old MudOS never asked: it used the root and backbone uids, which is
what the fallback does. The author probe's path is `"/"` + the configured master file, so `master file : /adm/obj/master` passes
`//adm/obj/master`, and sane `explode()` keeps one leading `""` for it: a TMI / Eastern Story `author_file()` testing `path[0]` never
sees `adm`. **Fix:** answer the probes with those values. A missing apply becomes `return get_root_uid();` / `return get_bb_uid();`;
an existing one that falls through to `return 0;` returns `"NONAME"` / `"BACKBONE"` there (the fluffos-org `deadsouls_fluffos`
upstream shape). Where the lib's own code calls `master()->author_file()` / `domain_file()` and reads 0 as "none" (Discworld `ls` and
ftpd print `Root`; ES / TMI `praise` and `find -author`), keep the 0 and answer only the probe: `"/"` gets the backbone uid, `/adm`
gets `ROOT_UID` (`explode(f, "/") - ({ "" })`). Objects keep their domains: a domain equal to the backbone domain, like a 0, makes the
driver give the object its creator's domain. Authors become visible only through `author_stats()`. Do not mark the new applies
`nosave` (the driver warns `Illegal to declare nosave function`). A helper the applies call that is defined later than an included
file needs a prototype there (revivalworld, zsdsj). Lima-family masters take LIMA's own pair (limalib/lima `f85dba3a`: `/domains/<name>/`
and `/wiz/<name>/`, else `"std"` / `"mudlib"`); their drivers lack `PACKAGE_UIDS`, so the lines read `using 'BACKBONE'` / `'NONAME' as
fallback`. **Detection:** `lpcc config.fluffos /nonexistent.lpc` runs the master load; grep the lines between `Loading master file` and
`Loading preload files` for `does not work`. A submodule lib needs a site-like tree (pin + catalog patches + overlay), and a custom-driver
lib its own `lpcc`; the bare submodule fails earlier (oxidus: `No function get_root_uid()`).

### 7.223 CD-driver ports: `map()` / `filter()` over a mapping hand the function the key

**Symptom:** genesis / arkadia: anything read through `lib/cache.lpc` comes back with every value replaced by its key (`"sel" : "sel"`),
so arkadia's `mbs` died with `Trying to put string in int` in `restore_mbs()`; any CD-era `filter(BbpMap, ...)` tests the wrong thing.
**Cause:** the CD driver calls the function of `map()`/`filter()` over a mapping with the value only; FluffOS calls it with `(key, value)`
(checked live: `map(([ "k":"v" ]), (: one :))` gives `([ "k":"k" ])`). `secure_var()` (`map(var, secure_var)`) therefore turned each
mapping into key:key, and `read_cache()` returns `secure_var(data)`. **Fix:** CD-semantics `map`/`filter` simul_efun overrides for
mappings (arrays and strings go to `efun::`), plus `(: secure_var($2) :)` inside the simul_efun object itself, where calls bind to the
efun (§7.221). Neither lib had FluffOS-style `$2` code to break. **Detection:** `grep -n "map(var, secure_var)"`; a CD port with
`m_indexes()`. Companion trap: CD partial application (`&operator(==)(x) @ &operator([])(, F)`, `&f(, a)`, a bare `@` that
the lexer reads as a here-document start: `End of file in text block`) is rewritten by `scripts/lpc_cd_closures.py`, capturing
lowercase locals with `$(...)`; a `(: f :) @ (: g :)` composition needs a hand rewrite.

### 7.224 CD-driver ports: a `set_alarm()` shim must keep alarms per object

**Symptom:** genesis / arkadia: rooms stop resetting (NPCs and items never come back); every new arkadia character logs `Owner
(/d/Standard/login/ghost_player#N) of function pointer is destructed`; in genesis `get_alarm(id)[2]` (torch, corpse, resistance) and
the reset scan fail on a non-array. **Cause:** the shim kept one global id table in the simul_efun object. `get_all_alarms()` listed every
object's alarms, so `std/object.lpc`'s `reset()`/`enable_reset()` ("remove every alarm named reset, then schedule mine") cancelled
every other object's reset (an lpcc probe: two rooms each saw the same 5 alarms and only one `reset`), and alarms of destructed objects
still fired. **Fix:** record `previous_object()` as the owner; `get_all_alarms()`/`get_alarm()`/`remove_alarm()` act on the caller's
own alarms and return the CD shape `({ id, name, time_left, repeat, args })`; a firing alarm whose owner is gone is dropped.
The CD signature is `set_alarm(float, float, function|string, args...)`: a string names a function of the caller, and the
extra arguments go to it (arkadia: 20 call sites; genesis's `std/callout.lpc` `call_out()` passes one). **Detection:** `grep -n "get_all_alarms" secure/simul_efun*`, then `query_alarms()` on two freshly loaded rooms.

### 7.225 CD-driver ports: `random(range, seed)` is deterministic

**Symptom:** genesis `cmd/live/state.lpc`: five `Unused local variable 'seed'` warnings; `compare`/appraisal answers change on every
try, so repeating the command averages a skill-limited estimate into the true value. **Cause:** on the CD driver the same seed always
gives the same number, and the appraisal code seeds with both objects' numbers on purpose. The onboarding dropped the seeds (45 calls in
5 files: state, shop, heap, area_handler, gog_accounts), and arkadia's `random()` simul_efun accepted the seed and ignored it.
**Fix:** a `random(int range, mixed *seed...)` simul_efun that hashes the seed (`efun::random()` when there is none), and the seeds put
back from the pristine `raw/` sources. **Detection:** `grep -rn "random([^()]*,[^()]*)" raw/` against the work tree.

### 7.226 A master whose `log_error()` changes its euid: clearing warnings breaks `#include`

**Symptom:** after a warnings pass (arkadia, 2026-10-05) `/std/room`, `/cmd/live/state` and `/cmd/wiz/apprentice` fail to load with
`Cannot #include /d/Standard/login/login.h`. The file exists and nothing on the include path changed. **Cause:** the driver checks
each `#include` with `valid_read(file, master, "include")`, so the answer depends on the master's euid at that moment.
`preload_boot()` sets that euid to the preloaded file's creator ("backbone" for `/cmd` and `/std`), and backbone may not read
`/d/Standard` (not a registered domain). It used to work only because every compile warning called the master's `log_error()`,
which runs `set_auth(this_object(), "root:root")`. **Fix:** in `valid_read`, return 1 for `func == "include"` once the closed
directories (`players`, `binaries`, `data`) are refused; the CD driver does not check includes. **Detection:** boot before and after a
warnings pass and diff the error lines, not only the warning count. A new `Cannot #include` of an existing file means `valid_read`.

### 7.227 Nightmare-family master: `else if` creates the players dir but not the letter bucket

**Symptom:** the first character registered on a fresh tree fails its first save: `Could not open /secure/save/players/z/zephyrq.o.tmp
for a save` (`ConfirmPassword` → `SetPassword` → `save_player`). The password is never written, and a second try works. On the site
this hits every visitor, because git tracks nothing under `secure/save/players/`. **Cause:** `compile_object()` in
`secure/daemon/master` runs `else if (file_size(DIR_PLAYERS) != -2) mkdir(DIR_PLAYERS); else if (<letter dir missing>) mkdir(<letter>);`.
When the parent is missing it makes the parent and skips the letter. **Fix:** make the letter check a plain `if` (dsI already did).
**Detection:** `grep -rn "else if(file_size(DIR_PLAYERS) != -2)" libs/*/work`. Fixed in nightmare4, dsII, foundation2, havenmud
(2026-10-05). To reproduce, use a tree of tracked files only (git archive), not the local tree, which already has the dirs.

### 7.228 LDMud libs: `reset(0)` never runs at load, and `lazy resets` does not change that

**Symptom (questmud, 2026-10-05):** every fresh weapon errors in `short()` (its `start()` never ran); the chat-channel daemon has no
channels; new characters skip the gender question and start in no channel. **Cause:** LDMud calls `reset(0)` when an object loads;
FluffOS calls only `create()`. Rooms and monsters worked because their bases had `create() { call_other(this_object(), "reset", 0); }`
(§7.177), but standalone objects (no `inherit`) and the `obj/weapon`/`obj/armour`/`obj/player` bases did not. `lazy resets : 1`
does not help: `try_reset()` fires only once `next_reset` has passed (`simulate.cc`), never at load. The periodic reset passes no
argument, so `if (arg) return;` code re-runs its setup each cycle (harmless where it is guarded, as `obj/player` is).
**Fix:** that same bridge `create()` in every core standalone file defining `reset()` and no `create()` (113 in questmud, generated
list; leave out wizard dirs, backups, and anything whose reset needs a player). **Detection:** clone a weapon/item and call `short()`
in an lpcc probe; a daemon's `reset()`-initialized array reads 0.
A root base that defines no `reset()` of its own (holymission `obj/treasure`: every subclass sets itself up in `reset(arg)`)
needs the bridge too; a scan for "defines reset, lacks create" misses it. Resolve per base: walk each file's inherit chain and
flag the root that has no `create()` calling `reset`.

### 7.229 LDMud compatibility sefuns with the wrong signature (holymission, 2026-10-06)

**Symptom:** every `member()` call errors (`Bad argument 1/2 to member_array()`): banks, pubs, signposts, doors, the mage soul's
command hook (`member(verb, '.') != -1` on every command). `extract(name, 0, 0)` returns the whole name instead of its initial.
**Cause:** the onboarding wrote the sefuns from memory: `member(item, container)` (LDMud is `member(container, item)`, returning
0/1 for a mapping and the index or -1 for an array or string), and `extract()` treated an explicit end of 0 as "to the end".
**Fix:** match the original efun (`undefinedp(end)` tells an omitted argument from 0). **Detection:** an lpcc probe calling each
compat sefun with the original's documented cases; tally the call sites' argument shapes (`grep -rhoP "member\s*\([^,]{1,40},"`).

### 7.230 LDMud `set_modify_command()` → FluffOS `process_input()` (holymission, 2026-10-06)

**Symptom:** `n`/`s`/`e` say "What?" while `north` works; aliases and `!` history do nothing. **Cause:** the player's
`modify_command()` (expander: aliases, history, the master's `modify_command_global` direction table) was registered with
`set_modify_command()`, stubbed as a no-op on the claim that FluffOS has no such hook. FluffOS calls `process_input(string)` on
the interactive object and uses a returned string in place of the typed line. **Fix:**
`string process_input(string str) { return modify_command(str); }` beside `modify_command()`. **Detection:** a no-op
`set_modify_command` sefun; a master table mapping `"n": "north"`.

### 7.231 LDMud two-argument `move_object(item, dest)` behind a one-argument shim (holymission, 2026-10-06)

**Symptom:** `Can't move object inside itself` (a castle moving to the quest room), later `Can't move an object that is
shadowing`. **Cause:** a global-include `mixed move_object(mixed dest)` lfun stood in for the 1400 rewritten call sites, but
~100 calls and the `#define MOVE move_object` / `MO` macros still pass `(item, dest)`; untyped callers compile, the extra
argument is dropped and the caller moves itself. Forwarding `item->move_object(dest)` then hits the item's shadow, which
receives every `call_other` to the object it shadows. **Fix:** `varargs mixed move_object(mixed item, mixed dest)`: one
argument moves this object; two forward to the item; inside a shadow (`query_shadowing(this_object())`) forward to the
shadowed object (a call from its own shadow reaches it). **Detection:** count calls with a top-level comma plus the
`#define \w+ move_object` aliases.
The same onboarding rewrote `move_object(m = clone_object(f), dest)` as `m = clone_object(f)->move_object(dest)` (241 calls,
most NPC spawners): `m` got the efun's 0 and the next `m->set_name()` failed. The shim returns the moved object; check the
rewrite against raw (`grep -rn '= *clone_object([^;]*)->move_object('`).

### 7.232 A fragment rebuilt as a standalone class (holymission player, 2026-10-06)

**Symptom:** the player has no `attack()`/`run_away()`/`query_level()`; `this_object()->attack()` in its heart_beat returns 0,
death never ends a fight, `look` shows no room contents, others see `0 arrives.`. **Cause:** the archive's `player.c` used
`living`'s variables without declaring them and called `::reset(arg)` with no parent; the onboarding read that as "undeclared"
and "orphaned" and re-created the variables and ~56 simplified `living` functions inside the player. **Fix:** restore the
inherit; delete the copies (the driver's `Redeclaration of global variable` warnings give each position; take `living`'s
`nosave` where they differ); keep the leaf's own overrides; call the parent's `reset` once (FluffOS's periodic reset passes
no argument). **Detection:** a class whose original source uses globals it never declares, or calls `::fn()` with no parent
defining `fn`; list `this_object()->X()` names the class does not define (`function_exists` probe).

### 7.233 Two saved variables with one name: restore fills the first and clears the second (finalrealms, 2026-10-06)

**Symptom:** a player's skill levels are 0 after every login although the save file holds them (`skills` appears twice in the
`.o`). **Cause:** `save_object()` writes every saved variable, so a name declared in two inherited programs (`std/skills.lpc`'s
skill tree, `std/living/skills.lpc`'s levels) is written twice; `restore_object()` looks each line up with
`find_global_variable()`, which returns the first match depth-first (the earliest, deepest inherit), so both lines land in that
variable and the other is left cleared. The compiler only says `Redeclaration of global variable`. **Fix:** make the copy that
needs no persistence `nosave` (state rebuilt in `create()`), or rename one; old saves then restore into the right variable.
**Detection:** a save file with the same variable name on two lines (`awk '{print $1}' file.o | sort | uniq -d`); filter out
`.o` files that are not saves, then check the save's class still declares the name twice. Corpus sweep 2026-10-06: only
finalrealms was live; havenmud `isRiding` comes from the `move.lpc` diamond (riding state, minor); nirvlp312 `dead`
(`banish/` copies), ninetears `creator` (`w/oldcreators`), pkuxkx `cond_def` (now `nosave`), sanguozhi/sgzmudsgz `name`,
swmud `follow_search` and wilderness `dmg` were saves written by older code.

### 7.234 Converting LDMud closures and wide mappings: `#'>` sorts ascending, a missing key reads 0 (questmud, 2026-10-06)
**Symptom:** after a port, the emote list prints Z to A; a board's `list` errors `Value being indexed is zero` once a thread
has been removed. **Cause:** LDMud's `sort_array(a, #'>)` swaps when the closure is true, so it sorts ascending, not
descending (`({4,5,2,6})` -> `({2,4,5,6})`). LDMud's `m[k, N]` returns 0 for a missing key `k`; the converted `m[k][N]`
indexes 0. **Fix:** `#'>` -> `sort_array(a, 1)`, `#'<` -> `-1`. Guard converted reads that probe keys which may be gone
(`if (!m[n] || !m[n][0])`), typically loops over `0..sizeof()` of a mapping with deleted keys. **Detection:**
`grep -rn "sort_array([^;]*-1).*#'>"` (a comment left by the port); for wide mappings, read every `m[i][N]` whose `i` comes
from a counter rather than `keys()`. Reads the port missed still say `m[k, N]`: in FluffOS that is a comma expression (`m[N]`) and reads the wrong key without
an error; the driver flags each one as `Expression has no side effects`, so read every such warning on an indexed mapping (questmud
2026-10-11: 116, among them `lite` colours and the multiguild starter guilds). A width-1 LDMud mapping read as `m[k, 0]` becomes `m[k]`.


### 7.235 A master guard on `SIMUL_EFUN_OB` gives every object uid `""` when the config loads another simul_efun file (hy, hy5, 2026-10-06)
**Symptom:** a link-dead player is never removed: `quit` after a disconnect errors `你()不能摧毁其他的使用者` from `feature/move.lpc`
`remove()` and prints the leave message twice; `getuid()`/`geteuid()` of every object, `/cmds` included, is `""`. **Cause:** the
master's `creator_file()` forwards to the simul_efun with a boot guard `if (!find_object(SIMUL_EFUN_OB)) return "";`, but the
onboarding config named `/adm/obj/simul_efun` while `globals.h` (and the archive's own `config.cfg`) use `/adm/single/simul_efun`; the
guarded object is never loaded, so every file gets `""`, which fails the `ROOT_UID` checks and most `valid_write` trust tables. A master
without the guard just loads the second copy and still answers correctly (17 other xkx/jqxz/sj/ldtx libs have the same path mismatch
and resolve `Root`). **Fix:** point `simulated efun file` at the path the lib's own macro and original config use. **Detection:** a
probe that prints `getuid(load_object("/cmds/..."))`; compare `config.fluffos`'s simul_efun path with `#define SIMUL_EFUN_OB`.


### 7.236 The master reports errors to a channel as `this_object()` but has no `channel_id` (sjpl2, sjplii, sjplgfjxb, 2026-10-07)
**Symptom:** every error with no player behind it (load, call_out, heart_beat) logs `Error in mudlib error handler: *Bad argument
1 to capitalize()` from `report_error()`, and the error never reaches the wizard channel. **Cause:** `CHANNEL_D->do_channel(this_object(),
"sys", ...)` in the master; `channeld` names a non-user speaker by `me->query("channel_id")` and falls back to
`capitalize(me->query("id"))`, and the master has no `query()`, so `capitalize(0)`. **Fix:** give the master `mixed query(string arg)
{ if (arg == "channel_id") return "系统核心"; return 0; }` (what `sj`'s master has). Channel daemons that guard `if (me->query("id"))`
or fall back to `"未知"` (dtsl2, dtxywzxzb, xyj2006*) are safe. **Detection:** a master that calls `do_channel(this_object()` with no
`channel_id` in it; load a failing object with `lpcc --batch` and look for `Error in mudlib error handler`.


### 7.237 A file copied from another lineage calls that lineage's daemon API (nitan family task2 killer, 2026-10-08)
**Symptom:** an NPC fails to load one time in three, with no compile error (`Fail to load object`); the quest that `new()`s
it errors mid-command. **Cause:** nitan's `d/city/task2/shashou.lpc` came from xkx100's task2: `switch (random(3))` calls
`NAMES_D->jap_name()`, which only xkx100's name daemon has (a `call_other` to a missing function returns 0, so
`name["name"]` errors), and wraps the id as `({ name["id"] })`, xkx100's string-id convention, while nitan's daemon already
returns an id array (the NPC's `"id"` becomes an array). **Fix:** port the missing function to the daemon in the target's own
return shape and pass the id through (`scripts/lpc_nitan_jap_name.py`). **Detection:** a file that flips PASS/FAIL between
fresh loads (random branch); grep the `DAEMON->fn()` it calls against the daemon's definitions.


### 7.238 `f[<2..] == ".lpc"`: the rename changed the suffix, not the slice width (102 libs, 2026-10-08)
**Symptom:** a directory filter keeps nothing or everything, a suffix strip never runs (or leaves `x.l`), a daemon that
walks rooms by file name never accepts one. nitan's `taskd` rejected every room in `alloc_task()` and, because
`rooms -= ({ room })` removed `zone + name` from a list of bare names, drew forever: `taskd` never loaded, so the player
commands `task` and `locate` printed the generic "这里发现了臭虫" bug message in the whole nitan family. **Cause:** the
`.c` -> `.lpc` rename (KB 03 section 4.2 item 4) turned `f[<2..] == ".c"` into `f[<2..] == ".lpc"`, two characters
against four; the strip after it, `f = f[0..<3]`, stayed two characters too. **Fix:** `scripts/lpc_lpc_suffix_slice.py
--apply` sets the slice to `[<4..]`/`[<4..<1]` and widens the strip of the same name within two lines to `[0..<5]`
(also `[..<3]` and a strip after an already-correct test); read its READ lines by hand (skylib's cloner stripped with
`f[<2..]`). 425 comparisons + 96 strips in 363 files. nitan `taskd` also needed the list fix and, once it really walks
the rooms, more than a 2-5 s `maximum evaluation cost` for its cold first load (10000000). **Detection:**
`grep -rnE '\[<[0-35-9]\.\.(<1)?\] *[!=]= *"\.lpc"'`; a daemon whose load runs the VM out of memory or eval time.

### 7.239 An empty stub kept "so the file compiles alone" wins over the real function (havenmud corpse, 2026-10-10)
**Symptom:** `AddSave() inherited from both /lib/common/persist.lpc ... and /lib/items/light.lpc; using the definition in light.lpc`, and the object silently saves nothing.
**Cause:** a mix-in defines a do-nothing body (`void AddSave(mixed n) {};`) instead of a prototype, so it compiles standalone; when it is the *later* inherit (corpse: storage, cook, light) the driver picks it for every unqualified call, including the parents' own `AddSave(({...}))` in their `create()`.
**Fix:** make it a prototype with the real signature (`mixed *AddSave(mixed *vars);`) or call `this_object()->AddSave(...)` as ds386 does; never "name the winner" for these rows without reading both definitions (`lpc_name_winner.py` would freeze the stub in place).
**Detection:** in every `inherited from both` row, open W's definition; a `{}` or `{ return 0; }` body for a getter/setter that the other side implements is this bug. havenmud's `combat/magic.lpc` carried the same stub, harmless only because `physical`'s real one is inherited later.
**Variant, a whole base under a mixin (finalrealms cave rats, 2026-10-11):** `/std/actions.lpc`, a set of NPC callbacks, did `inherit "/std/room"`; NPCs doing `inherit "/obj/monster"; inherit "/std/actions";` got the room's `create`/`init`/`id`/`short`/`add_alias` (a 2-arg exit alias, so `add_alias("rat")` stopped compiling). The tell is one row per shared base function, all naming the mixin as winner. Fix: drop the base from the mixin when it calls nothing of it.
**Variant, a mixin's one-liner over F_MOVE's `remove()` (nitan_ceshi/nitan3/nitan_san `feature/unique.lpc`, 2026-10-12):** `int remove() { save(); }` in F_UNIQUE, inherited after NPC/weapon, replaces the destruct hook that unequips, takes the weight off the carrier and (for `is_ob_saved()` objects) already calls `save()`; every destructed unique item left its weight on the holder (probe: 10000 -> 25000 -> still 25000). Delete the mixin's copy when the base's covers it; a leaf that must save first does `save(); ::remove(euid);`. Detection: `remove() inherited from both ... using the definition in <mixin>`. The same one-liner sits in the storage boxes of the nitan/xkx family (`adm/npc/obj/xiang.lpc`, `jubaoxiang`, lockers): 2026-10-12 sweep fixed 30 files in 14 libs plus tianxiawuxue (`233a95604a4`, `3b32800e67a`), where it shows only as `Function remove ... does not match ... return type ( void vs int )`; grep `int\s+remove\s*\(\s*\)\s*\{\s*save\s*\(\s*\)\s*;\s*\}` (`grep -Pz`). nt7 (fluffos-upstream submodule) still has it in `adm/npc/obj/xiang.lpc`: upstream PR.
**Recurrences (havenmud, 2026-10-12):** `weapon.lpc`'s `mixed GetPreventDrop() { return 0; }` sat in an "abstract methods" block and won on every item (scrap, resize and disarm ignored `SetPreventDrop`), and an earlier warning pass had already frozen it with a named winner; `help.lpc`'s `void create() {}` over `daemon.lpc`'s; `messages.lpc`'s `string GetName() { return 0; }`. Grep each mixin's "abstract methods" block for bodies, and re-read names a winner tool wrote.

### 7.240 A redundant base listed before the class that extends it: `::create()` runs only the base (havenmud, 2026-10-12)
**Symptom:** `F() inherited from both /lib/rooms/room.lpc and /lib/rooms/room.lpc (via /lib/rooms/fishing.lpc)` plus every room variable redeclared, in a leaf `inherit LIB_ROOM; inherit LIB_FISHING;` whose `create()` calls `::create()` or `room::create()`; the fishing state (`Fishing = ([])`) is never set up and the first `cast` indexes 0. Same with `inherit LIB_ITEM; inherit LIB_POLE;` + `item::create()` (pole strength never set or saved), `LIB_ITEM` before `LIB_ARMOUR` (the saved `Mass`/`Value` are the first, dead copy's: 0).
**Cause:** an unqualified `::f()` takes the *first* inherit that has `f`, so the base's `create()` runs and the subclass's never does; and the first copy's variables are the ones `fetch_variable()`/`save_object()` see, while the later class's functions write the second copy. `lpc_diamonds.py --fix-redundant` skips exactly these files ("B before A with an unqualified `::fn()`") because removing B changes the call: here that change is the fix.
**Fix:** drop the redundant base and rename `base::` calls to the subclass scope (`fishing::create()` reaches room's through it). Where the base came in through a *mixin* that inherits a whole class (`craftable.lpc` doing `inherit LIB_ITEM`, used beside `LIB_ARMOUR`), make the mixin abstract: prototypes, and its leaves inherit the class. Keep calls made from the mixin's own `create()` as `this_object()->F()`: the driver loads every inherited file as an object, a `create()` that calls an undefined prototype errors there, and the first clone of a leaf after boot fails to load (a fresh `lpcc --batch` that loads the leaf first shows it; a second load passes).
**Detection:** the `lpc_diamonds.py SLUG` rows it lists but does not fix; for each, read which `create()` the leaf actually reaches, and compare `GetSaveString()` HEAD vs tree on a clone. When both bases come from the same NPC root the object does not even compile (`Redeclaration of global variable 'busy'`, `Illegal to redefine 'nomask' function 'command_hook'`): wxddym's eight `d/maze/boss/npc/*` (`inherit NPC; inherit BOSS;`) and xxcqii's `wenliangyu` (`inherit NPC; inherit F_DEALER;`) never loaded. Load each MANUAL row at HEAD (`lpc_listcheck.sh`) before touching it: of the 183 rows outside the sjpl/pasted-together files (2026-10-18) only those nine failed in live directories; the rest, the bmxkx2001 `F_CLEAN_UP` rooms among them, load and stay as they are.

### 7.241 A cost written as negative damage: `receive_damage("neili", -52)`, `receive_damage("qi", -12)` (nitan/zjdy/xkx/shujian/xyj families, 2026-10-15)
**Symptom:** `F_DAMAGE: 伤害值为负值。` every time a skill is practised (`duanyun-fu`, `pangen-cuojiefu`, `feifeng-whip`, `yiwei-dujiang`, `shaolin-tantui`, `hujia-daofa`), on `exert powerup`/`huntian`, in a trap, an NPC's revenge, a miscarriage condition; in libs whose `damage.lpc` does `if (damage < 0) damage = 0;` (shujian/bxsj family) there is no error, the cost just vanishes.
**Cause:** the author wrote the `add()` amount (`-52`) into `receive_damage()`, which takes a positive amount. A second, unrelated mismatch is the damage *type*: xkx `jing/qi/neili/jingli` content inside an ES/xyj `gin/kee/sen` lib, or the reverse (`伤害种类错误`); that one needs per-lib reading.
**Fix:** `scripts/lpc_fix_damage_calls.py SLUG... --apply`: negative literal, `-N ± X`, `-(...)` or a negated skill level becomes a positive amount; a resource pool (`neili`, `jingli`, `force`, `mana`) becomes `add(type, -N)`. A variable such as `-damage` is left alone (the counter-attack branches negate a value that is already below zero). 141 calls in 49 libs + nt7.
**Detection:** the fixer's plan; `scripts/lpc_damage_types.py` lists the type mismatches against each lib's own `damage.lpc`.
**Second class, a resource pool as damage type:** `me->receive_damage("jingli", 30)` / `("neili", 10)` / `("force", 50)` where the lib's `receive_damage()` accepts only `jing`/`qi` (nitan, nt6/nt7, hy, chidi, yxcs, xyzx, shenmo...): `F_DAMAGE: 伤害种类错误( 只能是 jing, qi 其中之一 )` on every practice of dozens of movement and weapon skills, on perform costs and drains. The same script's second pass rewrites the statement to `add(type, -amount)` (the third, killer argument dropped), only where the type is missing from that lib's `type != "..."` list and the call is a statement of its own. Each function's own list is read (xjcq2000's `receive_damage()` takes `jingli`, its `receive_wound()` does not: `receive_wound("jingli", 10)` in its poisons errored before the countdown). It also covers `receive_wound()` on a pool (a weapon's `victim->receive_wound("force", n, me)` drain) and the `max_` pools (`receive_damage("max_qi", random(100))`, a 走火入魔 penalty). 1031 calls in 93 libs (2026-10-15). The `gin/kee/sen` vs `jing/qi` lineage mismatches the report also lists need a per-file read (the file usually reads `query("kee")` too).
**Third class, an ES/xyj skill file inside an xkx lib:** `practice_skill()` does `me->receive_damage("kee", 30); me->add("force", -3);` after testing `query("kee")`/`query("force")`/`query("max_force")`, in a lib whose characters carry `qi`/`jing`/`neili`: the damage call errors and the tests read 0, so the skill can neither be learned nor practised. `scripts/lpc_port_es_props.py SLUG... --apply` renames the first string argument of the dbase and damage calls in those files only (`kee`->`qi`, `gin`/`sen`->`jing`, `force`->`neili`, `max_force`->`max_neili`, `force_factor`->`jiali`, `max_`/`eff_` forms), and only where `receive_damage()` errors on an unknown type and accepts `qi` and `jing`. 514 files in 67 libs (xjcq2000 204, hy3 60). Libs whose `receive_damage()` returns 0 for an unknown type (shenmo) are silent no-ops and are left. `--any-file` widens it to every file that passes a foreign type (performs, conditions, weapons' `hit_ob`, NPC specials, books), skipping a two-level directory no other file names (xbtxiii's unwired `daemon/gongfu`, nested archive copies); 1063 more files. It also runs the **reverse direction**, xkx content in an ES/xyj lib (`qi`->`kee`, `neili`->`force`, `jiali`->`force_factor`, and `jing`-> whichever of `gin`/`sen` the lib's own study/learn commands charge: `sen` in the xyj and 风云 families, `gin` in dtsl), and the **xxcq direction** (that family renamed xkx `jing` to `jingli`; its own `cmds/skill/learn.lpc` charged a teaching player `receive_damage("jing")` and read `query("jing")`, always 0). A ported `query("qi") * 100 / query("max_qi")` in an ES lib was a division by zero before. The xyj libs whose pools are only `kee`/`sen` (the 三界神话 family) dropped `gin` too: a pill's `receive_heal("gin", 60)` or an NPC's `receive_curing("gin", 1000)` errored, so `gin`->`sen` there; files are chosen by `receive_heal()`/`receive_curing()` as well (their `type != ...` lists error the same way). 282 more files. Not handled: libs with a model of their own (dreamofseven's `ap/hp/mp` with limbs, zzhj's `spi/mov`).
**Fourth class, a formula that goes negative:** xue-dao `shendao` (祭血神刀, 10 libs of the sj/xbt/ldtx families) deals `random(shen / -1000) + shen / -3000`, rewarding a negative shen; a performer whose shen is positive gets negative damage and `F_DAMAGE: 伤害值为负值`. `if (damage < 0) damage = 0;` keeps the design (no damage for the righteous) without the error.

### 7.242 `message_vision(msg, environment(me), me)`: the room as the actor (poison conditions, 2026-10-15)
**Symptom:** `Bad argument 3 to EFUN replace_string() Expected: string, Got: int(0)` from `sanpoison`, `emerald_poison`, `xianglu-du`, `laugh` and a few NPCs, on every heart beat while the condition lasts.
**Cause:** the argument order of `message("vision", msg, environment(me), me)` carried over to `message_vision()`, whose first object is the actor: it calls the room's `name()`, gets 0, and `replace_string(msg, "$N", 0)` errors. In a condition the error comes before `apply_condition(name, duration - 1)`, so the condition never runs out, and the rest of the heart beat (healing) is skipped every tick; conditions are saved, so it survives a relogin.
**Fix:** `scripts/lpc_fix_vision_env.py SLUG... --apply` rewrites it to `message_vision(msg, me)` (`$N` is the player). 54 calls in 28 libs.
**Detection:** the condition probe (`update_condition(me, 5)` on every condition file with a cloned NPC); grep `message_vision(.*environment(\(\w+\)), \1)`.

### 7.243 query_action() indexing past the move table (2026-10-15)
**Symptom:** `Array index out of bounds` or `Value being indexed is zero` from a skill's `query_action()` on some or most attacks; the skill probe shows it nondeterministically (the index is random).
**Cause:** the table and the index disagree. kxkj/kxkjii2 `lonely-sword` picks `action[random(9) + 6]` and similar from a table of 8 moves (160 of 200 attacks errored at level 100 with the quest flag, 99 without); xlqy's `iori-sword` does `action[random(7)]` with 4 (its own commented-out line reads `random(sizeof(action))`); `guangming-blade` read the level of the skill it was copied from, and `liu-unarmed` had its level loop commented out (the earlier fixes, 5d9eea02680 and 7887baefbe0).
**Fix:** clamp to the table (`pick_action(i)` returning the last move for a larger index) or restore the intended `random(sizeof(action))`.
**Detection:** `scripts/lpc_action_index.py`; most other hits are xyj's `else return action[5];` under a perform's temp flag that nothing sets (dead).
**Variant, the level of the skill it was copied from:** `level = me->query_skill("tiesha-shenzhang", 1)` in `tiezhang-zhangfa.lpc`, `quanzhen-jianfa` in `quanzhen-jian.lpc`, `sougu` in `sougu-yingzhua.lpc`: a player with only this skill walks the table at level 0, no move matches, and `a_action["dodge"]` indexes 0 on every attack. `scripts/lpc_fix_action_level.py SLUG... --apply` points that assignment at the file's own name when it drives the table, in skills the lib uses (124 assignments, 51 libs, 2026-10-15; hc tiezhang-zhangfa at level 150: 100 of 100 attacks errored, now 0).
**Variant, a table that starts above the player's level:** every `"lvl"` of hc's tiesha/tiezhang tables is 100 (xiongba-tianxia 250, zuixin-sword 350), so below that the walk assigns nothing and every attack errors until the skill passes it. `lpc_fix_action_level.py --fallback --apply` adds `if (!a_action) a_action = action[0];` after the loop (22 files, 11 libs).
**Comments hide both variants from a plain regex:** chidi's `kuangfeng-jian` and tianxiawuxue's `dugu-jiujian` keep an older `query_action()` commented out above the real one, and dugu-jiujian's first 15 moves (lvl 0–98) sit inside `/* */`, so its live table starts at 105 and every attack below that errored. The fixer reads only the definition and the `"lvl"` keys that are code (2 more files, 2026-10-15).

### 7.244 `CONDITION_D(x)` defined as one daemon: every condition runs the autosave (sj, shiji, 2026-10-15)
**Symptom:** poisons, jails, `killer` and the like do nothing (the condition is gone after one tick), and each applied condition posts `Auto_save has been started for N minutes` on the `sys` channel and, a few ticks later, saves every user.
**Cause:** the 世纪 archive's `include/globals.h` has `#define CONDITION_D(x) ("/adm/daemons/autosaved")`: F_CONDITION resolves every condition name to the autosave daemon, whose `update_condition()` re-applies an `auto_save` condition and returns 0, so the real one is deleted. The 46 files in `kungfu/condition` were never reached (a `CONDITION_D(x)` with no `x` in it is the tell).
**Fix:** `("/kungfu/condition/" + x)`, as in 120 other libs; the periodic save lives in `natured.lpc`'s `auto_save` call_out and does not depend on it. The now-live conditions then need the pool port (`lpc_port_es_props.py --any-file`: their poisons were ES `kee`/`sen`). Live check: a `rose_poison` tick now takes 10 qi and 20 eff_jing.
**Detection:** `grep -rE '#define\s+CONDITION_D\(x\)' libs/*/work/include` and read any definition that does not use `x`; the condition probe on a lib whose conditions all "work" without ever damaging.

### 7.245 `->query_("x")`: a typo that call_other answers with 0 (2026-10-15)
**Symptom:** none at run time: `ob->query_("combat_exp")` calls a function nobody defines, and call_other returns 0 without an error. yxcs `tiandao-blade`'s alignment test `if (me->query_("shen") > -100000)` therefore always passed, so every attack added a `betrayer` point and took 1000 neili even from the evil wielders it was meant to spare; wuyue-spear `buhui` scaled by a target exp of 0; sje's 金蛇秘笈 `query_("str", 1) > 20` never passed.
**Fix:** `->query(`; 41 calls in 37 files, 29 libs (code only). Nothing in the corpus defines `query_`.
**Detection:** `grep -rn -- '->query_(' libs/*/work`; more generally an `->` call to a name no inherited file defines (the compiler cannot see it).
**Variant, `->querry(`:** linji-zhuang `youming` (幽冥桩, 20 libs of the shenzhou/nitan lineage) reads the attacker's and the exerter's death counts with `killer->querry("combat/dietimes")`: always 0, so the bad-guy ratio used PKS alone. `->query(`; it changes play only where the key is recorded (the nitan family; shenzhou-lineage libs keep `death_count`).
**More `->querry(` (2026-10-15):** yunu-jianfa `hebi` tests `me->query("marry/id") == target->querry("id")`, which is `0 == 0` for every unmarried pair, so the married bonus (skill and exp times yunu-xinjing/80) went to everyone and was never undone (section 7.253); Eastern Story I's `std/room/std_storage` meant to keep players and clean NPCs. None left in live code.

### 7.246 A weapon perform used bare-handed: `weapon->name()` on 0 (2026-10-15)
**Symptom:** `perform stick.ban` (or any move named explicitly) with nothing wielded stops with `Bad argument 1 to EFUN call_other() ... Got: int(0)`, often after the move already took its neili (murong-jianfa `kuangjian` deducts 150 first).
**Cause:** the perform command resolves `martial.move` without checking that a weapon of that kind is in hand, and many performs read `weapon = me->query_temp("weapon");` and use it straight away (dagou-bang `ban` even declares it `string weapon`).
**Fix:** `scripts/lpc_fix_perform_weapon.py SLUG... --apply` adds `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");` after the assignment when nothing tested the weapon before its first `weapon->` (449 performs, 79 libs). Moves that test it themselves, or use it conditionally (`weapon ? ... : ...`), are left. The guard sits after the assignment, not at the top: a move that charges neili before reading the weapon (`kuangjian`) still charges it, but a top-of-function guard would also block early paths that return without a weapon (stance toggles).
**Detection:** the perform probe (`pfm_probe.py`, a prepared NPC fighting a dummy) run with and without a weapon; the fixer's plan.
**Variant, a weapon test that is itself the crash:** iceforce's `roar` (碧海生潮曲, 24 libs) reads `ob = me->query_temp("weapon")` and then tests `base_name(ob) != "/d/taohua/obj/yuxiao"` to refuse anything but the 玉箫: bare-handed, `base_name(0)` errors before the refusal can print. `!objectp(ob) ||` goes inside that condition (2026-10-15).
**Variant, a bare-hand perform that reads a weapon it never set:** qinlong-shou `qin` (擒龙打, 7 libs) refuses to run with a weapon, then does `wn = weapon->name();` on a local nobody assigned (and never reads `wn`): every use errors. The line goes, with its two locals.
**Variant, the target's weapon in a message:** yinsuo-jinling `dian` (银索金铃点穴, 20 libs) prints `"真气贯注" + ob->query("name")` for the target's weapon in one of three miss texts, so one miss in three against a bare-handed target errors. `(objectp(ob) ? ob->query("name") : "全身")`, the nitan lineage's own wording for that line.
**Inline shape, the weapon never stored (2026-10-15):** `(me->query_temp("weapon"))->query("name")` in the message (yunv-jian `suxin`, liangyi-sword `yin`, suiyuan-sword `yiqiesuiyuan`, whose else branch had already raised `apply/attack` and `apply/damage` when it errored, so a bare-handed use kept the bonus), or the refusal test itself, `if ((weapon = me->query_temp("weapon"))->query("skill_type") != "whip")` (feiyu-bian `chanrao`). `lpc_fix_perform_weapon.py` now also puts the refusal before the function-level statement that holds the first such use when nothing tested the weapon earlier (75 performs, 52 libs); never between an `if` block and its `else`. Left: mhxy's `dianxue` family, where an included `type()` turns no weapon into `"unarmed"` (dif 110) and every weapon read sits under `if (dif != 110)`.
**Related, a local that is never assigned:** damo-jian `sanjue` and fanliangyi-dao `sanshen` (xkx100, xiakexing100) declare `object weapon, ob;` and end with `if (!ob->is_fighting(me))`, and `sanshen` even attacks `ob` three times: every use errors after the neili is spent; `target`. songfeng-jian `chan` (wxddym) tested `weapon->query_temp("noliving")` before assigning `weapon` (meant `target`). daojian-guizhen `xue` (wdxtym, wxddym) read the second weapon's `skill_type` with no second weapon in hand; its siblings `ben`/`jiu`/`tian` refuse first.
More of the same (2026-10-15): a `check_fight()` that declares `object weapon;` and tests `|| !weapon ||` -- always true, so the buff ends at the first check one second in (ranmu-daofa `fentian` 13 libs, xuanxu-daofa `luanhuanjue`): `!objectp(weapon = me->query_temp("weapon"))` in the same place; mantian-huayu `huayu` (5) counting `weapon->query_amount()` with nothing fetched; blade-of-death `suo` (4) knocking away an opponent's `weapon2` it never read; sad-strike `tuo` (nt1, wdxtym) and ssj `fw` (sje), where the line that set the variable was commented out and its later use stayed; huilong-zhang `baiwei` (4) with `!objectp(me->query_temp("weapon") || weapon->...)`, the parenthesis around the whole `||`, so the move refused everyone holding a weapon. **Detection:** `scripts/lpc_unassigned_locals.py SLUG...` (an `object` local a function dereferences and never assigns; read each hit: a use behind a guard that is never true is listed too).

### 7.247 A pool, attribute or experience read through `query_skill()` (2026-10-15)
**Symptom:** a gate that never opens (niaoren's dragon-whip `query_skill("max_neili") < 500`, ylfyxa3's 慕容博/慕容复 apprenticeship `query_skill("int", 1) < 30`, syxjl's 武穆遗书 `query_skill("shen", 1) < 20000`), a move that never lands (liancheng-jian `ci`/`erguang`/`li1`/`li2`, wxddym's shigu-bifa `dian`: `random(me->query_skill("combat_exp")) > target->query_skill("combat_exp")` is `0 > 0`, since FluffOS `random(0)` returns 0), or `call_other() couldn't find object '/daemon/skill/combat_exp'` (Fengyun's `dual-attack` valid_learn).
**Cause:** the name is not a skill. The xkx/ES F_SKILL returns `apply/NAME` plus nothing, so the call is 0; the Fengyun F_SKILL loads `SKILL_D(name)` for a non-raw query. Formulas lose the term silently: `guaiob->set("kar", who->query_skill("kar"))` in the 金庸/武当 quest monsters, the other side of `query("max_neili", me)` in nitan's tanzhi-shentong `dian`, the `neili`/`neili2` comparison of sj's lengquan-shengong/longxiang-boruo `ob_hit()` (always 0 against 0, so always the middle branch).
**Fix:** `scripts/lpc_fix_pool_as_skill.py SLUG... --apply` rewrites the names with one reading (combat_exp, shen, score, potential, age, the attributes, the max_ pools) to `query("NAME")` (88 calls, 2026-10-15). Current pools are listed for a reading by hand, because `query_skill("neili")` often stands for the internal-power *skill*: chidi/yxcs/yxjh's `gouyee`/`yuxuan-guizhen` heal reads `query_skill("neili") / 5` where the lib's 17 other heal exerts read `query_skill("force") / 5` (fixed to force; the pool would heal ten times as much). Fixed by hand to the pool: luoying-shenjian `lybf` (27 libs; its own comment says success depends on 精神), the `ob_hit()` pair (14 libs). Left: yuxiao-jianfa `bihai` (`dp = target->query_skill("jing") / 2` clamps to 1; the miss text says the target resists with 内功, so force is as likely as jing), huntian-qigong `shexin` (its failure loop would call `tell_object(me, command("laugh"))`, an int), jiali assignments in xyj-style NPCs (no neili there), wdxtym's `topten` (sums `query_skill("weiwang")`, `query_skill("gain/armor")` ...), gouyee `concentrate` (one copy, no sibling to read the intent from).
**Detection:** the fixer's plan (HAND lines for the rest); the skill probe's `/daemon/skill/<pool>` errors (Fengyun). The rest is silent: no probe sees a gate that never opens.

### 7.248 `get_dir()` is checked as `valid_read(path, ob, "stat")` (2026-10-15)
**Symptom:** `get_dir()` returns 0 for an ordinary object while the same path lists fine for a daemon: xkxz2/xkxc98sj's `lonely-sword` does `filter_array(get_dir("/kungfu/skill/*.lpc"), ...)` in `query_action()` and errors on every attack.
**Cause:** the driver's `get_dir()` calls `check_valid_path(path, current_object, "stat", 0)` (src/packages/core/file.cc), so the master's `valid_read` sees func `"stat"`, not `"get_dir"`. A security daemon that exempts `"stat"` (jh2006: `case "file_size": case "stat": return 1;`) lets every object list directories; one that exempts only `"file_size"` (the xkx securityd: `if (func == "file_size") return 1;`) runs `"stat"` through its read rules, and `/kungfu` objects (euid `Domain`) are allowed nothing under `/`.
**Fix:** at the caller, not in the security policy: list without `get_dir()` (lonely-sword now borrows moves from the attacker's own sword skills, then the weapon's moves) or test a directory with `file_size(dir) == -2` (`"file_size"` is exempt in both shapes).
**Detection:** a skill/room/NPC calling `get_dir()`, in a lib whose securityd lacks `"stat"`; test with `master()->valid_read(path, ob, "stat")` from lpcc, not with `"get_dir"` (asking with the wrong func name gave a false "refused" for jh2006).

### 7.249 A misspelled skill name in `query_skill()` (2026-10-15)
**Symptom:** a skill or move nobody can learn or use, silently: xkx2001's 天山六阳掌 `liuyang-zhang` accepts any of three 逍遥派 forces at 50 but spells one `xiaowu-xiang` (the skill is `xiaowuxiang`), so a 小无相功 student is refused (`valid_learn` 0 at HEAD, 1 now); the zhongnan `chunyang-quan` gate reads `xiatian-gong`; 无相指 `wuse` reads `xuxiang-zhi`. Or a force-mixing exclusion that never fires (`beimin-shengong` in the exclusion lists of 48 libs' forces), or a formula term that is always 0.
**Cause:** typos (`beimin`, `douzhuan-xignyi`, `taiji-shengon`, `matrial-cognize`), `_`/`-` drift (`yinyun_ziqi`, `five_poison`), a dropped hyphen (`mizongxinfa`), or the name a skill had before the lib renamed its file (`jinwu-dao` for jinwu-daofa, `hengshan-jianfa` for hengshan-jian, `xixing-dafa` where the lib's file is `xixin-dafa`, `palm-sword` where it is `plam-sword`). `query_skill()` of an unknown name is 0 with no error.
**Fix:** `scripts/lpc_fix_skill_typo.py SLUG... --dict-libs SLUG... --apply` (1155 calls, 975 files, 147 libs). A name is fixed only when it is typo-shaped against exactly one skill of the lib, nothing gives it out (set_skill/map_skill: a missing skill is a content gap), and something confirms it: the site's own message names that skill in Chinese, a dictionary (`data/e2c_dict.o`, `data/chinese.o`) gives the misspelled id the same Chinese name, or the difference is one no pinyin word comes from (`_`/`-`, a hyphen, two adjacent letters swapped) and the id is no skill file of any lib. A fourth route, added after the first pass: the site sits in that skill's own file or perform dir and the names are one letter apart (`hujian-daofa` in hujia-daofa.lpc, `xiyu-tiezhang` driving xiyu-tiezheng's own move table, `jinggang-quan`, `xuanyuan-arror`); 298 more calls in 223 files, 90 libs). Rejected as a different skill (OTHER lines, 164): a site that names the id's own Chinese name (syxjl shenghuo-lingfa: "你对圣火心法的领悟不够，无法学圣火令法" gates on 圣火心法, not on itself), the lib's own dictionary or three dictionaries naming it differently (tonsillitis 反五行摄气诀 vs tonsillit 摄气诀; jiuyang-force 九阳真气 vs jiuyangforce 九阳神功; xiantian-qigong vs xiantian-gong). Skipped: domain skill dirs' own names (d/kunlun/mjskill/qiankun-nuoyi), backup dirs and copies (`skill-bak/`, `x - 副本.lpc`), untracked trees.
**Detection:** the fixer's plan; its 576 SKIP lines are typo-shaped but unconfirmed (single-letter edits often make another pinyin word: jiuyin/jiuyang, youshe/youshen, daya/damo) and need a reader.

### 7.250 mapdb's `map.o` saved before any map existed: every lookup indexes 0 (2026-10-15)
**Symptom:** 幽冥桩 (`linji-zhuang/youming`) errors with `Value being indexed is zero` (nitan170911), the sj job system's `get_arearoom()` errors at `keys(room)`, the 福威镖局 escort (`ftb_zhu`), jinhe and jiumozhi stop at `keys()` or `strsrch(0, ...)`. A 23-byte `data/npc/map.o` that holds only `#/clone/obj/genmap.c` ships in 10 libs (bxsj, bxsj1, chidi, nitan170911, shenzhou, shujian2008, sjtx2, wxddym, yxcs, zhyx).
**Cause:** genmap's `create()` is `if (!restore()) save();`: its first load writes `map.o` before any map is built, and a variable that is 0 is not saved. mapdb's `restore()` then succeeds from that file and leaves `map` 0 (restore_object zeroes what the file does not name), and `query_room_info()`/`query_room_exits()`/`query_map()` hand out 0 or index it. Without any `map.o`, `map` is `([])` and `query_random_room_path()` indexes `keys(map)[random(0)]`, also an error.
**Fix:** mapdb gets `int restore() { int ret = ::restore(); if (!mapp(map)) { map_ready = 0; map = ([]); } return ret; }` (create() and the traverser's `mapdb->restore()` both go through it), `query_random_room_path()` returns 0 on an empty map, and its callers test `!stringp(room_path) ||` before their `strsrch()` chain, so the 100-try loop ends with its own "cannot find target room" (32 mapdb copies, 20 callers). No map is invented: an admin still has to run genmap.
**Detection:** `ls -l libs/*/work/data/npc/map.o` (a header-only file is ~23 bytes); `restore()` in a daemon whose state is one mapping.
**Variants in the traverser users:** youming's `visit_room()` compared `dist` with `range` before reading `range` from its data (0), so the effect never spread through an unloaded room; nitan3/nitan_san's `clone/obj/traverser.lpc` declared `noasve int traverse_done;` and never compiled.

### 7.251 A wizard's test room as a destination in live code (2026-10-15)
**Symptom:** 柔云纵 (`rouyun-steps/zong`, 30 libs) takes the jingli, prints "乘云而去了", and in one use out of three errors with `call_other() couldn't find object '/u/deaner/test1'`; the fighter stays in the fight.
**Cause:** the escape picks one of three rooms and the third is a wizard's test room that no archive ships (or `/u/vin/workroom`, zhyx). In shiji/sj/xzyx and xbtxiii the two city rooms are missing too, so every use failed.
**Fix:** the corpus's own third room, `/d/city/guangchang` (hy, jym, shenmo, xjcq2000, yxxcii already had it); where the lib lays its city out differently, its own square, inn and temple (sj family: guangchang/jiudian; xbtxiii: `/d/yangzhou/`; shenmo: center/kezhan/chenghuang). Every destination checked to exist.
**Detection:** `grep -rn 'move("/u/' libs/*/work/{kungfu,d,clone,cmds}` and test each path: 878 sites pointed at a missing `/u/` room (2026-10-15), mostly room exits, jails, quest rooms and wizard tools; read each.
**Parking moves** (an item used up, an NPC that "leaves", a thrown weapon held in the air): a missing `/u/aln|llm|wind|ryu|wsky|lonely|smallfish|baiwt/...` room became the lib's own `VOID_OB` (319 sites, 66 libs, 2026-10-15; haiyang2's maintainers had used a holding room the same way). What the bad move did depends on F_MOVE: `call_other(dest, "???")` raises (38 libs: the rest of the function never runs -- a drug never used up, the wedding stopping before the couple are sent to the banquet, fengmo-zhang's `fengmo` flag never cleared), `load_object(dest)` + `notify_fail` returns 0 (28 libs: the NPC stays put, one more 月老 in the hall per wedding). Check the lib has the room: xfbhh's `VOID_OB` (`/clone/misc/void`) was missing and 26 callers (`fubend`, `vrm_server` ...) failed with it. A move into a room that does exist (`/u/lonely/workroom` in the nitan family) was left alone.

### 7.252 Room exits indexed as an array (2026-10-15)
**Symptom:** 随风而舞 (`qiulin-shiye/wu`, 14 libs) errors whenever it succeeds: `me->move(0)`, or `Value being indexed is zero` in a room without exits.
**Cause:** `mapping *obb = query("exits", env);` then `me->move(obb[0])`: exits are a mapping (direction to path), so `obb[0]` looks up key 0, which no exit has. The `if (sizeof(obb) > 0)` guard most copies carry does not help.
**Fix:** the sibling lineage's own code (yanhuangwuhun family): `mapping exits`, `string *obb`, and `if (sizeof(exits) > 0) { obb = values(exits); me->move(obb[random(sizeof(obb))]); }`.
**Detection:** `grep -rn 'mapping \*[a-z_]* = .*"exits"'`; an exits mapping indexed with an integer.

### 7.253 A call_out target declared without the parameters the call_out passes (2026-10-15)
**Symptom:** yunu-jianfa `hebi` (合壁, 35 files): the joint attack's bonus never wears off and the `hebi` flag stays until the next login; with section 7.245's `querry` the user's `yunu-jianfa` and `combat_exp` were multiplied (floats from then on, doubled at yunu-xinjing 160) and `set_skill("combat_exp")` on the partner raised `No such skill`, so nothing was ever restored.
**Cause:** `call_out("hebi", 1, me, target, env, i, j, o, p, count)` into `void hebi() { object me, target, env; int i, j, o, p, count; ...`: the arguments are dropped and the locals of the same names are 0, so `if (!me && !target) return;` returns every time. The perform's own call_out also passed `h, k` that the re-scheduling call inside `hebi()` does not.
**Fix:** declare the parameters the re-scheduling call passes and drop the locals; make the first call_out pass the same list. xbtxiii's ultimate area has the same shape in `yangguo`/`xiaolongnv` `come_shuitan` but its chain also needs a 小龙女 NPC the archive never had, so it was left.
**Detection:** compare each `call_out("f", delay, args...)` with `f`'s parameters in the same file and keep the targets that read a local they never assign (3,892 call_outs pass extra arguments, almost all harmlessly; 38 matched this, 2026-10-15); `lpc_unassigned_locals.py` lists the object-typed ones.

### 7.254 A saved NPC whose `weapon`/`armor` is a mapping (2026-10-18)
**Symptom:** the 武林盟主 NPCs (`clone/npc/meng-zhu`, `fa-e`, `shang-shan`, `d/quanzhou/npc/tang3`, `d/taishan/tang2`/`tang3`/`xingtang`: 89 files in 15 libs) die in `create()` with `Bad argument 1 to EFUN new()` once their saved data is restored.
**Cause:** `do_recopy()` copies the crowned player's whole dbase into the NPC, including a crafted weapon stored as a mapping under `weapon`; the next `create()` runs `if (query("weapon")) carry_object(query("weapon"))->wield();` and `carry_object()` wants a path. Fifteen libs' `data/npc/*.o` really carry the mapping (jhfy3's holds `"weapon":(["id":"my sword", "make":1, ...])`).
**Fix:** `if (stringp(this_object()->query("weapon"))) ...` (and `armor`); the champion comes up bare-handed.
**Detection:** `git grep -F '"weapon":([' -- 'libs/*/work/data/npc/*.o'`, then the libs whose code reads the property as a path.

### 7.255 A corrupt board save kills the room that creates it (2026-10-18)
**Symptom:** `restore_object(): Illegal file format - 1 (?inh...` while a room such as `d/city/kedian` loads (the jqxz2008 family, jyqxc, xiakexing2017: 50 board saves under `data/board/` start with `?inh` and binary noise, foreign data that no driver reads).
**Cause:** `inherit/misc/bboard.lpc setup()` calls `restore()` bare, and `restore_object()` raises on a file that is not a text save (a missing file returns 0). The board's `create()` aborts, and with it the room that clones the board.
**Fix:** `catch(restore());`, the board starts empty (xkx2017's copy already read so).
**Detection:** scan the first four bytes of every tracked `.o` for `?inh`; the census row `Illegal file format`.

### 7.256 `set_skill()` of a skill the lib has no file for aborts the NPC's `create()` (2026-10-18)
**Symptom:** an NPC, maze boss or sect master never loads and the room that spawns it is one short: `*F_SKILL: No such skill (magic-sword)`. 3,736 objects in 169 libs call `set_skill()` with a name no skill file of their lib carries (wxddym's 404 and zxty's 205 maze bosses: `magic-sword`, `magic-fire` ...; chidi's `dragon`; the Shaolin monks' `yijin-jing`); `map_skill("leg", ...)` raises the same when the lib has no `leg` (bixiecanyang) or `spells` (nitan6).
**Cause:** the shared `feature/skill.lpc` `error()`s in `set_skill()`, `map_skill()` and `prepare_skill()` when `SKILL_D(skill)` is no file. The skill is content the archive never shipped (or a name the lib spells another way, see 7.249 for query sites); the NPC itself is intact. chidi and fyzfqyy already skipped the skill instead.
**Fix:** `scripts/lpc_guard_set_skill.py --apply`: the three `error("F_SKILL ...")` become `return` (187 libs; sanjieshenhua, sjshv2578bb, xyj20032 by hand around their `check_skill()`; shzs and zzhj already `return notify_fail()`). The NPC loads without that skill; the missing skill stays a content gap. The xajh/xo family (xajh2, xo, xo_final, xajhxo: `system/feature/[char/]skill.lpc`) reaches it through `set_wugong()` -> `set_jibie()` -> `check_skill()`: `set_wugong()` returns 0 for a name `valid_skill()` rejects (the lib's own idiom in `set_xiuwei()`), 20 objects load that never did (39 grant a skill with no file; the commonest is `parry`, which xajh2, xo and xajhxo never shipped). Restoring the skill itself needs a donor lib whose skill files are mostly byte-identical to this lib's (`lpc_scan_missing_skills.py --donors`): only 341 of the 3,749 (lib, skill) pairs have one, the rest are other versions of the game.
**Detection:** `scripts/lpc_scan_missing_skills.py [--summary] [--files DIR]`; the census row `F_SKILL: No such skill`.

### 7.257 A room exit that names a file the lib does not have (2026-10-18)
**Symptom:** the player types `west` and goes nowhere: `"west": __DIR__"desert4"` with no `desert4.lpc`, and the map behind that exit is out of reach. 17,000 such exits corpus-wide (`lpc_scan_dangling.py`), most pointing at rooms the archive never shipped; 138 sit in rooms a visitor can reach from the start room (`lpc_reach_census.py --dead`).
**Cause:** a typo (`birdge`, `huazangzn`, `jiudaoguai4`), a renamed room or area directory (`/d/dali` -> `/d/dali1`, `sanshengtang` -> `shanshengtang`), numbered rooms that were never shipped (`jitan1` where each qujing area has one `jitan`), case (`happyjie` for `HAPPYJIE`, 7.238-style).
**Fix:** `scripts/lpc_fix_dead_exits.py --apply`: the room at the other end exists and its opposite exit points back here, so that is where the exit was meant to go. One candidate only, in the room's own game area or the target's; never a /clone or /obj file; no two dead exits repaired into each other. 181 exits in 63 libs. Not in a lib whose virtual server makes rooms from names with no file: the first run also "repaired" 140 files of es1, es1_win, esI (`_westgate`, `8,5.east`) and pd (`22,30,0`), every old target loaded fine in a fresh tree, all reverted and the libs listed in the tool's VIRTUAL set. Test the old targets with `load_object` before believing a plan.
**Detection:** the tool's plan, `lpc_scan_dangling.py [--summary] [--kinds EXIT]`, `lpc_reach_census.py --dead`.
**Parser trap (2026-10-19):** `parse_exits` judged a pair that starts at its opening quote by the character before it, and that character is the closing `/` of `/* sizeof() == 4 */` in `set("exits", ([ /* sizeof() == 4 */` (the comment is masked like a string), so the first exit of every room written that way, in the fy, xyj and ES lineages, was invisible: the reach census saw 2 rooms of zzfy's 9,000 and the dead-exit repair never looked at those exits. `in_code` now asks whether that quote opens a string literal of the code (`string_starts`).

### 7.258 A skill granted under a misspelled name: the NPC loads without the skill (2026-10-19)
**Symptom:** the Shaolin guards dodge with the plain `dodge`, the Kunlun disciples have no `shenfa`, the monk who should teach the Yi Jin Jing teaches nothing: `set_skill("shaolin-shnfa", 100)` and `map_skill("dodge", "kunlun-shnfa")` name a skill the lib has no file for. Before the 7.256 guard `create()` died on the spot; now the object loads and the skill is silently absent. 4,281 names in 3,233 files of 166 libs (`shaolin-shnfa` 451, `kunlun-shnfa` 414, `yijin-jing` for `yijinjing` 187, `tiaji-jian` 182, `dagonforce` 144, `bixie-sword` for `pixie-sword` 134, `yan-fly` 133, `lahua-shou` 132 ...).
**Cause:** one NPC template typed the name wrong and every copy kept it: a letter dropped, doubled or swapped, a hyphen added or lost, `_` for `-`, a second transliteration of the same skill. 7.249 is the same slip on the reading side (`query_skill`).
**Fix:** `scripts/lpc_fix_skill_names.py --apply`: a table of 150 spellings, each read by a person, replaced in the string arguments of `set_skill`, `set_wugong`, `map_skill`, `prepare_skill`, `query_skill*`, `improve_skill`, `add_skill`, `delete_skill` and `SKILL_D()`, in a lib that has no skill file of the wrong name and one of the right name. Neighbours that are a different skill (`taiji`/`taiyi`, `bihai-jianfa`/`bihai-bianfa`) stay out of the table. A sample of the edited objects of every lib loads as before.
**Detection:** `scripts/lpc_scan_missing_skills.py [--summary]` lists the skill names a lib's objects grant that no skill file carries; a name one edit from an existing skill is a candidate for the table.

### 7.259 A call to an inherited function no parent has (2026-10-19)
**Symptom:** `Unable to find the inherited function 'create'.` and the object never compiles: 63 unique weapons and armors ending `create()` with `::create();` (`clone/unique/fumo-dao` and its 62 copies), books and talismans with `::init();`, NPCs with `::setup();`, xlqyzdb's shopkeepers with `return ::buy_object(who, item);` (18), `::do_discard(arg)` on the notice boards. 133 files in 47 libs; another 180 files also carry it, next to an error of their own.
**Cause:** the line was written for a base that has the function. The archive's base (`F_UNIQUE`, `BOOK`, the NPC class) does not, and the old driver took a call with nothing behind it for a no-op that returns 0; FluffOS reports it at compile time. The same message after `inherit INLAID;` (a macro nobody defines) is the missing parent speaking, not a dead line.
**Fix:** `scripts/lpc_fix_dangling_super.py --diag DIR --apply`: a call written as a statement is deleted (the line, when nothing else is on it); `return ::f(...);` becomes `return 0;` (`return;` in a void function), as the old driver evaluated it. Only files whose every error is such a call are edited, because with an unresolved `inherit` the call is the only trace of the function the restored parent will have; a call inside an expression (`if (::do_advance(str))`), under an `if` without braces, an efun (`::add_action()` in pkuxkx's simul_efun is `efun::add_action()`) and `::init_hammer(155)` in a sword (fengyun434's `left_sword`, the copy-paste of a hammer; siblings call `::init_sword`) are listed and left.
**Detection:** the compile scan (`scripts/lpc_warnings.py`, census class `Unable to find the inherited function`), the tool's plan.

### 7.260 `set_name(name, "id")`: the ids passed as a string where the lib wants an array (2026-10-19)
**Symptom:** `Bad type for argument 2 of set_name ( string * vs string )` and the object never compiles: the Baituo bowl `d/baituo/npc/obj/bowl` (`set_name("海口大碗", "bowl");`) in 46 libs of the Eastern Story family, pkuxkx's gem blades and swords (`set_name(blade_name[type - 1], blade_id[type - 1])`).
**Cause:** the old driver checked no argument types, and `member_array("bowl", "bowl")` still finds the word in a string, so the item answered to its id; the lib's `set_name(string name, string *id)` declares the array.
**Fix:** `scripts/lpc_fix_set_name_id.py --diag DIR --apply`: the second argument becomes `({ "bowl" })` when it is a plain id literal or an indexed name (86 calls in 46 libs). Left: `d/linghai/footprint` of xyj20032 and sjshv2578bb, whose author wrote `set_name("short", "...")` and `set_name("long", @LONG ... LONG)` for `set()`; the item has no name to give.
**Detection:** the compile scan; the tool's plan.

### 7.261 `NewRandom()` missing from the lib's skill base (2026-10-19)
**Symptom:** `Undefined function NewRandom` and the basic martial arts never compile: `daemon/skill/boxing`, `houquan`, `westsword`, `taiji-quan`, `jueqingbian` ... 154 skill files in 28 libs (the Journey-to-the-West family xyj/sjsh/xiyouji, dtxy, fy2mg 52, zzfy, wqfy ...). The characters that have the skill fall back to bare hands.
**Cause:** the moves are picked with `action[NewRandom(i, 20, level/5)]`; `NewRandom()` and the `sum()` under it live in the skill base of the 115 libs where those skills were written (`inherit/skill/skill.lpc`), and these libs' `/std/skill.lpc` is the lighter ES base without them.
**Fix:** `scripts/lpc_restore_skill_helpers.py --apply`: the helper pair (the text 115 libs share) is appended to the `SKILL` base of each lib that lacks it while a live skill file calls it; a base that defines `sum` already is left (HELPERS table for more). 152 of the 154 load; the other two are 7.263.
**Detection:** `Undefined function NewRandom`; the tool's plan.

### 7.262 A function the lib's copy of a base file lost (2026-10-19)
**Symptom:** `Undefined function set_ghost` (the wooden-man NPCs `d/shaolin/npc/muren_fighter*`: 16 libs, 53 objects) and `Undefined function prepare_skill` (the sect NPCs of zzfy/zzfy3 27 files each, wqfy 24, sjpl2/sjplii 12, fy2mg 10 ... 23 libs, 138 files); the object never compiles.
**Cause:** the lib's copy of a base file is an older or trimmed one: `feature/damage.lpc` has `int ghost` and `is_ghost()` but not `set_ghost()`; `feature/skill.lpc` has `skill_map` and `map_skill()` but not the prepared-skill block (`skill_prepare`, `prepare_skill`, `query_skill_prepared`, `query_skill_prepare`); the NPC files of the xkx lineage call them.
**Fix:** `scripts/lpc_transplant_function.py --lib L --from xkx100 --path /feature/skill.lpc --name prepare_skill --name query_skill_prepared --name query_skill_prepare --var 'mapping skill_prepare;' --after 'mapping skill_map;' --apply`: copies the functions (and the comment lines above them) from the sibling's copy of the same file to the end of the lib's file, in its line ending, adds the global after the named line, and lists the identifiers the target file never mentions (UNRESOLVED). 53/53 `set_ghost` callers and 124/138 `prepare_skill` callers load; the rest fail on macros the lib lacks (`BINGQI_D`, `CITY_OB`, `F_NOCLONE`, `TYPE_WRISTS`: the undefined-macro class).
**Detection:** `scripts/lpc_scan_missing_funcs.py --diag DIR`: one NEED line per (lib, function, base file) that sibling libs define at the very path the failing lib also has. Not transplanted: ninetears' guild functions (`set_main_skill`, `set_teaching_person`: the Nightmare guild base differs deeply), mortremains' `set_type`/`set_ac`. A stub the sibling documents is as good as the function (chidi's `add_light(room, level) {}` in `adm/simul_efun/object.lpc`, from yxcs: the temple rooms call a lighting effect nobody ever implemented). The sefun `unew(file)` of the xkx lineage (a `new()` that honours the object's `unique` limit) is the same kind: dtsl, dtsl2, dtslmud, pkuxkx, sjpl2, sjplii call it from their sect NPCs and weapons without ever shipping it in `adm/simul_efun/object.lpc`; `--from xkxz2 --name unew` adds it (12 dtsl-family objects load; pkuxkx's `laozu2` and sjpl2/sjplii's `limochou` then wait for `BINGQI_D`). The nitan6 family's `quest11/jinshe`... packs call it too, but those files also need `BINGQI_D`/`ARMOR_D` and carry no live exit, so they are left. `write_file2(file, str, flag)`, the fengyun lineage's `efun::write_file` wrapper (fy3dz, fy3xd carry it), is the same kind: the `brd` board daemon of zzfy and zzfy3 and the `smith`, `makeupseller`, `caifeng` NPCs of fy330 call it and their `adm/simul_efun/file.lpc` never had it (added to fy330, zzfy, zzfy3, fyzfqyy; the brd daemons and the NPCs load). Nine more libs call it without having it (nitan170911, hhsj, nitan6, nt6, nt6nitan6win, xfbhh in `adm/kernel/simul_efun/object.lpc`; shenmo, wdxtym, xuanjianlu in their single simul_efun file): `scripts/lpc_add_unew.py SLUG... --apply` appends the same text. `space(n)` (with `itoa(n)`) is the same kind: the cover-drawing book base `/std/item/book` of the xkyx family writes `space(4)` and the fy-family libs wqfy, zzfy and zzfy3, whose 40 skill books are byte for byte the xkyx ones, had `atoi()` in their `adm/simul_efun/atoi.lpc` and nothing else; `scripts/lpc_add_sefun.py space SLUG... --apply` appends the xkyx `string.lpc` text to the file that holds `atoi()` (the book base then loads, see KB 04 section 6.15).

### 7.263 Pager text pasted into a source file (2026-10-19)
**Symptom:** `syntax error, unexpected L_ORDER` at line 1 of `boxing.lpc` (`> more boxing.c  // houquan.c 猴拳`) and `Illegal character 0xe5` in `westsword.lpc` (a line `已 经 显 示 26 % (ENTER 继 续 下 一 页 ， q 离 开 ， b 前 一 页)` between two array elements) in xajdxyj, xianlvqiyuan and xjcq2000.
**Cause:** the files were copied out of a `more` session; the command line and the pager's status line stayed in the text. The code around them is intact (the token stream equals chidi's and yxjh's copy except for the tuned numbers).
**Fix:** the line deleted (6 files). Left alone: five shadowgate `d/player_houses/alzar/*` files that end in `--More-- (93%)` (the capture stopped there, the file is cut).
**Detection:** `git grep -n -E '^\s*(已 ?经 ?显 ?示|>+ ?more |--More--)' -- '*.lpc' '*.h'`.

### 7.264 A function pasted twice, word for word (2026-10-19)
**Symptom:** `Redeclaration of function 'query_autoload'.` and the object never compiles: the xyzx family's books `clone/book/lbook5` and `pixie_book` (`int query_autoload() { return 1; }` twice), the Journey-to-the-West `d/pkdao/room1` (`greeting()` twice, 6 libs), `d/moon/npc/xiwangmu` (`ask_pantao()`), yhwhpublicfi's `danB_6`, yueyingqiyuan's `huitian-shenjue` (`exert_function_file()`).
**Cause:** an editor paste; the two copies are equal apart from white space. 200 other `Redeclaration` errors have one definition in the file and the second in an `#include`d header (decide per file); 29 have two different bodies (a stray half of another version: read before cutting).
**Fix:** `scripts/lpc_fix_dup_functions.py --diag DIR --apply` deletes every copy after the first when all are equal; different bodies and include-caused ones are listed and left. The ES virtual-room templates (`_bed2.lpc`, three whole copies of the Roommaker output) are not touched: the virtual server loads them as they are. 26 copies in 19 files.
**Detection:** the compile scan's `Redeclaration of function`; the tool's plan.
Two more shapes, read by hand: hell's `clone/misc/bandage`, `clone/special/jindouyun`, `shunfenger` have the real `string query_autoload()` (the bandage's name or the amount, restored by `autoload(string arg)`) and, appended to the end of the file, `int query_autoload() { return 1; }`: the stub is deleted (the old driver let the later definition win, which made the object reload with the argument `1`). shujian2008/sjtx2/sjecl `d/city/npc/wushi` pastes the `nick_first`/`nick_second`/`create_nick()` of its own header `skills_pfm.h` and includes `r_name.h` a second time (the header already includes it): the copies are deleted.

### 7.265 `init()` defined twice with different bodies (2026-10-19)
**Symptom:** `Redeclaration of function 'init'.`: the wandering vendor `maihuanu1.lpc` of the Journey-to-the-West family (14 files in 8 libs: a first `init()` greets and adds `buy`, a second one further down is `::init(); add_action("do_vendor_list", "list");`), `shzs` `d/zuichen/huli`, `wuhanzhan` `d/city/liangdian2` (`work` and a `block_cmd` catch-all).
**Cause:** two authors, two pastes; each wanted both sets of commands.
**Fix:** `scripts/lpc_merge_dup_init.py --diag DIR --apply`: when the file holds exactly two `init()` and the second is nothing but `::init();` and `add_action(...)` statements, those `add_action` calls move to the end of the first and the second definition is deleted (15 files). Any other body (logic, three definitions, a definition that comes from an include: `d/gumu/tiao.h`, `smdian`) is listed and left.
**Detection:** `Redeclaration of function 'init'` in the compile scan; the plan.

### 7.266 Typos that keep a reachable NPC or room from loading (2026-10-19)
Found by taking the objects a visitor meets (`scripts/lpc_reach_census.py` lists of the start-room walk), intersecting them with the compile failures and loading each again; each is a one-line archive typo, fixed in every lib that carries it:
- `command("give yancao to", me);` (`d/heimuya/npc/laozhe`, the old man of the Black Wood Cliff; `Too many arguments to 'command'`) in xkx100, xkxlb, xiakexing3, xkxc98sj, xkxz2, xkxyb, niaoren, yxxcii: cctx and fys had already corrected it to `command("give yancao to " + ob->query("id"));`.
- `query(environment(this_object()))->query("discussion_shen")` (`d/biancheng/npc/sanniang`): an extra `query(` around the environment; fengyun434, fysjmb, hy5, hymud, xsfyssjb.
- `mapping ob;` for the loop variable that is then passed as an object to `query("online_time", ob)` (`d/city/kedian4`, hhsj, nitan170911, xfbhh); `is_killing(who)` where the lib's `is_killing(string id)` wants the id (wlqxcmudlib `guidao`); `return 1;` at the end of a `void` function (yhyxcs `engineer`); a closing quote eaten by the byte after `丐帮` (sje `guo`, `Illegal character 0xe6`).
- `exert_function(10);` (an integer where the direct call wants a string; 30 files in 21 libs: `saveme.lpc`, `shengji.lpc`, `wizer.lpc`): deleted, as chidi did.
- Truncated sources: `d/liangong/npc/muren.lpc`, `muren2.lpc` of ffxymud end inside `create()` (100 practice dummies per room; closed with `setup(); }`, no sibling has the file), hy and hyiishzdscbb `d/city/bite.lpc` (a sibling has the whole file).
- BIG5 `功\"HIR"`: the extended `scripts/lpc_fix_big5_quote_backslash.py` also accepts a colour macro glued to the next string after the quote (44 sites in kxkj, kxkjii2, yxsj, yxzsj).
**Detection:** the reach census (`FAIL slug depth path error` with `--load`), then the first error of each file.

### 7.267 An NPC whose name and stats live only in a save file the archive did not ship (2026-10-19)
**Symptom:** `Bad argument 1 to set_living_name()  Expected: string Got: 0` from `enable_player()` <- `setup()` <- the NPC's `create()`: 94 of the 99 `kzznpc` NPCs of tiexuejianghu (the inn keepers, smiths, tailors and guards of every town) never loaded; the room's `make_inventory` swallows the failure, so the shops stand empty.
**Cause:** `include/kzznpc.h` does `restore();` and then `set_name(query("name"), ({query("id")}))`; name, id, skills and stats are in `/data/npc/<name>.o`, and the archive's `data/npc/` was an empty directory. The sibling fys (the same game, the same author's `txjh/export/mudlib` tree, 5,767 of 5,832 shared `d/*.lpc` byte for byte) shipped all 109 saves.
**Fix:** copy the sibling's saves for the names the NPC files point to (`query_save_file()` -> 96 of 98 names), and give `kzznpc.h` a fallback for an NPC with no save at all (name from the save file's name, id from the object's file name): `xiaohuoji` of both libs. 99 of 99 load (5 before).
**Detection:** the reach census `FAIL ... Bad argument 1 to set_living_name()`; `ls libs/*/work/data/npc | wc -l` against the files that define `query_save_file()`.

### 7.268 `this_player()->carry_object(...)` inside an NPC's `create()` (2026-10-19)
**Symptom:** `Bad argument 1 to EFUN call_other()  Expected: object, string, array,  Got: int(0)` from `create()`: the NPC (ldtxii `d/city/npc/wei`, haiyang2 `d/feihu/npc/me`, tianxiawuxue `d/city/npc/hhm`) never loads when the clone is made with nobody acting (a room's reset from the driver, a preload, a loader); when a visitor's walk into the room makes the clone, the visitor is `this_player()` and gets the NPC's cloth and sword while the NPC stands naked.
**Cause:** an author's habit in a few families (syxjl 33 files, ldtx 27, ldtxii 27, hy3 20, the honghua and mr cloth NPCs of 10 xkx libs ...): `this_player()->carry_object("/d/city/obj/cloth")->wear();` where `carry_object(...)` was meant.
**Fix:** `scripts/lpc_fix_tp_carry.py --apply` rewrites it inside functions named `create` only (a `do_combine()` that gives the player an item is a different thing: 105 sites left): 227 sites in 178 files of 30 libs.
**Detection:** the reach census `FAIL ... Bad argument 1 to EFUN call_other()`; `git grep -F 'this_player()->carry_object('`.

### 7.269 Area objects that name a wizard directory the archive does not ship (2026-10-19)
**Symptom:** `Cannot #include /u/swordman/newbie/npc/sujia.h` (hc: the 34 `jobsys/gfjob` NPCs include `/u/poi/job/npc/npc.h`), `call_other() couldn't find object '/u/lzd/biwu_b'` (a board loaded by `"/u/lzd/biwu_b"->foo();` in a room's `create()`), `wield_weapon("/u/s/smore/weapon/whip1.lpc")` in an NPC: the room or NPC never loads.
**Cause:** the author built the object in his wizard directory and moved it into the area without moving what it names; the archive has no `/u/<wizard>/` (or not that file).
**Fix:** when the area carries the file itself, point at it: `scripts/lpc_fix_wizard_include.py --diag DIR --apply` rewrites a `/u/...` include to the one copy (all copies byte-equal) the lib has outside the wizard directories (54 includes in 16 libs: hc 34, sjcs 4, es1_win 3, bxsj, bxsj1, mhxy, mhxyqd, mohuanshiji, ...; 52 of 54 objects load); fys and tiexuejianghu `d/thd/hall.lpc` named `/u/aug/thd/thd_b`, the board is `d/thd/thd_b.lpc` (its `location` too). A call into a wizard's board that is nowhere is deleted (ldtx, ldtxii, syxjl `d/biwu/wudao4`, ldtx and ldtxii `d/wizard/arch_room`). The ES npc base guards `new()` of a missing file (`if (weapon) weapon->move(this_object());`, `std/npc.lpc` of es1, es1_win, esI). Not touched: es1's CWA club (the whole wizard project names `/u/s/supertramp/`), holymission's sheriff office, names with several differing copies (finalrealms `unarmed_combat.h`, es1 `echobomber.h`), nirvlp312's `/players/`.
**Detection:** `Cannot #include /u/...` rows outside the wizard directories in the compile scan; `git grep -E '"/(u|w|players)/[^"]*"->'` over `d/`, `clone/`, `obj/`, `room/`.

### 7.270 A shared daemon the lineage's `dealer.lpc` calls and the lib never shipped (2026-10-19)
**Symptom:** `Undefined variable 'MONEY_D'` in `feature/dealer.lpc` (sjpl2, sjplgfjxb, sjplii): every shopkeeper that inherits `F_DEALER` fails to compile; the `xiansheng` tutors and the `yzyunhe`/`szyunhe` ferries too.
**Cause:** the archive carries the xkx lineage's `dealer.lpc` (byte-equal to jqxz2008's) but neither `adm/daemons/moneyd.lpc` nor the `MONEY_D` line of `globals.h`.
**Fix:** `adm/daemons/moneyd.lpc` copied from the sibling that shares the dealer (jqxz2008, 2,778 bytes; its `COIN_OB`/`SILVER_OB`/`GOLD_OB` are in the lib's header) and `#define MONEY_D "/adm/daemons/moneyd"` after the last `#define` of `include/globals.h` (`scripts/lpc_restore_defines.py` refuses it until the file is in the git index).
**Detection:** the compile scan's `Undefined variable 'MONEY_D'`; the restore tool's `SKIP ... is not in the lib`.

### 7.271 A saved exit with an explicit `.c` and a destination that is gone (2026-10-19)
**Symptom:** the player-house entrance rooms of wxddym (`d/city/jiaowai7`, `d/huanghe/caodi1`, 4 more) die in `setup()` with `call_other() couldn't find object '/data/room/qazzaq/dayuan.c'`.
**Cause:** `data/dbased.o` keeps the entrance's exits as written by the running game (`"sah":"/data/room/qazzaq/dayuan.c"`); the rename left `dayuan.lpc`, and an explicit extension is resolved exactly (KB 03 4.2). `feature/dbase.lpc`'s ZJ hook (`set("exits/x", path)` asks the destination for its short with `data->query("short")`) then loads a room that does not exist, and the `set()` aborts the restore. Four of the 21 saved houses have no room file at all.
**Fix:** `.c` dropped from the 17 saved refs whose `.lpc` exists; the lookup is guarded in `feature/dbase.lpc` of wxddym, wdxtym and zjmudhell (`if (!catch(name = data->query("short")) && stringp(name))`), so a gone destination only skips the client message. 6/6 entrance rooms load.
**Detection:** reach census `FAIL ... couldn't find object '/data/room/...'`; `grep -o '"/data/[^"]*\.c"' libs/*/work/data/*.o`.

### 7.272 A source whose line breaks were lost: the whole object sits in its leading `//` comment (2026-10-19)
**Symptom:** none. The file compiles to an empty program, so nothing in the compile scan or the load census sees it: the Quanzhen-old robes and the letter (`d/quanzhen_old/obj/*`, 8 libs), the tea-house child `d/taoyuan/npc/kid` (5 libs), the `idiot` condition (3 libs), hc's `zhenyuan-force` skill, the shaolin kitchen and weapon items of wuhanzhan (13 files), `junfu` (sj, shiji, xzyx) ... have no name, no id, nothing to wield.
**Cause:** the archive's editor kept the indentation and lost the line breaks: line 1 is `// idiot.c  白痴inherit __DIR__"generic_condition";#include <ansi.h>#include <condition.h>int update_condition(object me, int duration){  int i;          i = ...` (the raw `.c` is the same single line: the object was dead in the original game too).
**Fix:** `scripts/lpc_uncollapse.py [--list FILE] --apply`: cuts the comment head at the first `#include` / `inherit` / function header (every `//` of the head is a line of its own), walks the code with strings, `({ })` / `([ ])` literals and `@TEXT` heredocs kept whole, breaks after `;` outside parentheses, after block braces and after `#include <...>`, ends an inner `//` comment at the indentation run that follows it; then `format-corpus.mjs` over the result (KB 08 section 9). 69 files in 19 libs; all load, `new()` of a restored item answers its name. Left: mohuanshiji `clone/gift/GONGGAO.lpc` (truncated in the archive).
**Detection:** `git grep -c -a -P '^\s*//[^\n]{60,}\{[^\n]*;[^\n]*\}' -- 'libs/*/work/*.lpc'` and a file with at most three line breaks.

### 7.273 `RANK_D->query_respect(this_player())` while an NPC is created with nobody acting (2026-10-19)
**Symptom:** `Bad argument 1 to EFUN call_other()  Expected: object, string, array,  Got: int(0)` from `rankd.lpc` `query_respect()` called by the NPC's `create()` (`"…不知这位" + RANK_D->query_respect(this_player()) + "有何见教？"` in an `inquiry` mapping or a `chat_msg` array: the wudang disciples, yideng, the bianliang scholars, the feihu `me` ... 1,819 files in 60+ libs). The room's `make_inventory()` catches it, so the room loads and the NPC is missing. The driver's own `reset()` runs with no command giver (`reset_object()` saves and clears it), so an NPC that was killed never comes back after a timed reset.
**Cause:** the old driver answered `0->query("age")` with 0, so `query_respect(0)` fell through to its default branch ("小兄弟"); this driver raises. Only the creation under a player's command (a walk into the room) worked.
**Fix:** in the daemon, not in 1,800 files: `scripts/lpc_fix_rank_null.py --apply` puts `if (!objectp(ob)) ob = this_object();` at the top of `query_respect`, `query_rude`, `query_self`, `query_self_rude` (`query_close` / `query_self_close` already test `objectp`) in `adm/daemons/rankd.lpc` (794 functions, 193 libs), after the leading local declarations; every `ob->query(...)` answers 0 again.
**Detection:** the reach census with `--walk` (rooms are loaded by a script with no command giver); `git grep -P '"\s*\+\s*RANK_D->query_\w+\(\s*this_player\(\)\s*\)'`. Other eager uses of `this_player()` in `create()` (summoned beasts, forged weapons) are by design: they are made under a command.

### 7.274 A directive glued to the end of a `//` comment line: the `inherit` / `#include` is part of the comment (2026-10-19)
**Symptom:** `Undefined function offensive_target` for `daemon/class/moon/moonshentong/shiyue.lpc` (22 files in 20 libs: the skill has no `SSERVER` parent), `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('` on line 2 of xkx100's `d/shaolin/obj/heisuo.lpc` (`WHIP` is unknown: `#include <weapon.h>` is the end of the comment on line 1), `syntax error, unexpected L_STRING` in `renshen-guo.lpc` (xajh2, xo, xo_final), the cloth `red_cloth.lpc` of xajh4gkb. A file that compiles without the lost include (securd.lpc of the xxcq family loses `<login.h>`, gift.lpc, rm.lpc, a skill without its `inherit FORCE;`) shows nothing at all.
**Cause:** the line break after a comment was lost in the archive or the conversion (a lone GBK lead byte before the newline eats it, KB 03 section 4.6): `// 蚀月咒inherit SSERVER;`, `// heisuo.c  黑索#include <weapon.h>`, `//sadboy is 2001.4.5inherit FORCE;`.
**Fix:** `scripts/lpc_fix_swallowed_directive.py [--apply]` puts the break before the directive when it stands in the first 12 lines of a file and the same directive is not on a line of its own elsewhere in the file. Left alone on purpose: `//**inherit PRIVATE_ROOM;` (the luban template marker of the xxcq family), `// (by rong)inherit F_DEALER;` (a commented-out parent), `// by yahoo 18:35 99-3-22#include <weapon.h>` above the real include. 42 files in 35 libs; 30 of them were compile errors at HEAD.
**Detection:** the scan's errors for a file whose line 1 is a comment; `git grep -n -a -P '^\s*//[^\n]*[^\s/*#()\x27"`](#\s*include\s*[<"]|inherit\s+[A-Z_]+\s*;)\s*$'`, then drop the hits whose directive is also on a line of its own.
**The statement-level twin:** the swallowed text is a statement, not a directive: `set("xyzx_sys/level", jibie);  //2016.5.22阿飞调整NPC属性    set_name("小沙弥", ...);` (the comment's last half character ate the line break and the next line's indentation survives as a run of blanks). The NPC loads without a name and dies in `setup()` with `Bad argument 1 to set_living_name()` (xajh4gkb: 4 NPCs); `set_weight(4000);  //***** ADDED BY SCATTER *****      set("wposition", ...)` in 20 libs; the auction room's `pay_back(...);  //归还前一个竞买者的钱      add("pnum",1);` never counted a bid (tybxjh, wlhd, yxjh, zxty, zxty08nxgbb); xyzxfk's `learn` / `xue` lost a message. `scripts/lpc_fix_swallowed_statement.py --apply` splits the line at the blank run when the code before the comment ends in `;{})` and the swallowed part has balanced quotes (dreamofseven's `add_force.lpc` swallowed a half-quoted message and stays). 27 lines in 27 files. Detection: a `//` comment followed by 3 or more blanks and a statement that ends the line, with real code before the comment (commented-out code and prose with aligned examples are the false positives: mortremains' `// You would do that like this       set_bonus(0,1,1);`).

### 7.275 A player-forged weapon template created with nobody (or an NPC) as the forger (2026-10-19)
**Symptom:** `Bad argument 1 to switch  Expected: int  Got: "/d/npc/m_weapon/weapon/m_sword"` from `inherit/weapon/weapon.lpc` `set_desc()`, or `Bad argument 1 to EFUN call_other()` from the template's own `create()`, while a room loads or a visitor enters one (hy, hyiishzdscbb: `d/hangzhou/road19` and a dozen rooms of the `--walk` census, among them the start room; the chain is an NPC's `init()` that loads `d/taishan/fengchan`, whose guard creates the alliance leader `clone/npc/meng-zhu`, which `carry_object()`s the template); the NPC and every room on that chain fail.
**Cause:** the forge templates (`d/npc/m_weapon/weapon/m_sword.lpc`, `m_club`, `m_blade` ..., `d/quanzhen*/obj/m_sword.lpc`) read the forge data of `this_player()` in `create()`: `me = this_player(); //读入数据 w_lv = me->query("weapon/lv"); ... set_desc(w_lv, w_or, w_name);`. With nobody acting `me` is 0; under an NPC the dbase answers the NPC's own `weapon` property, which is the *file name string*, so `switch (w_lv)` (int cases) raises. The old driver let `0->query()` answer 0 and the switch fall through.
**Fix:** `scripts/lpc_fix_forge_template.py --apply`. 77 files in 28 libs had `if (me) {`: it is `if (me && mapp(me->query("weapon"))) {` now. 293 files in 60 libs had no test at all (`w_name = me->query("weapon/name");` straight after the comment; every one ends with `setup();`): after the `//读入数据` line `if (!me || !mapp(me->query("weapon"))) { setup(); return; }` leaves an unnamed empty template. A lib without the `M_WEAPON` base (wuhanzhan) is left: its templates never compiled.
**Detection:** the reach census `--walk` (the chain needs a living as the command giver); `git grep -n -a -A1 '读入数据' -- 'libs/*/work/*.lpc'`. The fixer skips a lib that does not `#define M_WEAPON`; fy2mg, sje, sjpl2, sjplii, sjplgfjxb, xyj451 and wuhanzhan got the macro and the base file later (KB 04 section 6.18), and the fixer was run on them again (37 more templates; with the base in place fy2mg 6/6, sjpl2 and sjplii 22/22, sjplgfjxb 8/8, xyj451 5/6, wuhanzhan 5/6 of the listed objects load).

### 7.276 An object path with two leading slashes: `Read access denied.` (2026-10-19)
**Symptom:** `Read access denied.` from `inherit/char/npc.lpc` `carry_object()` while an NPC is created: `carry_object("//clone/cloth/hic_cloth")->wear();` (xajh4gkb: 32 files, the sect disciples, the Gaibang elders, the Dali ruffians ...), `carry_object("//d/gaoli/obj/armor")` (dtsl, dtsl2), `new("//obj/weapon/sword")`, `inherit "//d/azha/town/market1"`, `move("//d/nopk/standard/void.lpc")`. The NPC never loads and the room that holds it loses it (or fails, if its `make_inventory()` is not guarded).
**Cause:** the games ran on a driver that did not object (it evidently normalised the path before asking the master). This one passes the string as written to `valid_read()`, and securityd explodes it into the directory chain `//clone`, `//clone/cloth` ... which has no entry in `trusted_read` for an NPC's euid; an object with the root euid passes (a test object with euid `Mudlib` did not show it, a real NPC does).
**Fix:** `scripts/lpc_fix_double_slash.py --apply`: the one-slash path, for string literals that look like a path (`"//` + a first segment without a dot + a further `/`). The block-comment markers of an editor (`"//EXIT"`, `"//OVER"`, `"//extras"`, hundreds of them in the corpus) stay. 100 sites in 35 libs (xajh4gkb's 32 first, by hand).
**Detection:** census failures `Read access denied.`; `git grep -n -a -P '"//[A-Za-z_][A-Za-z0-9_-]*/' -- 'libs/*/work/*.lpc'`. Prove it with the NPC loaded at HEAD and in the tree, not with a probe object (the probe's euid is the root's).

### 7.277 `userp(0)`: an efun that wants an object, called while nobody is acting (2026-10-19)
**Symptom:** `Bad argument 1 to userp()  Expected: object  Got: 0.` while an NPC is created by a room reset: `ji.lpc` (xajh4gkb) `carry_object("/clone/cloth/huiyuan")->wear()`, and the cloth's `wear()` starts with `if (!userp(this_player())) return ::wear();`; `d/new/lgting` and the NPC never load. The old driver answered `userp(0)` with 0; this one raises, for the efun and for any sefun that forwards its argument (`int userp(object ob) { if (efun::userp(ob)) ...` in the xyzx family's `adm/simul_efun/player.lpc`).
**Fix:** in the sefun, `if (!objectp(ob)) return 0;` first (xajh4gkb, longyunmeng, xyzxyl201412, ylfyxa3). Where the plain efun is called with `this_player()` the call site is the only place: not swept (`living()`, `interactive()`, `wizardp()` behave the same; the census names the ones a visitor reaches).
**Detection:** the reach census FAIL lines `Bad argument 1 to userp()`; a trace with the cloth's `wear()` under an NPC's `create()`.

### 7.278 A header that is a list of `inherit`s, `#include`d by an object that also inherits the base: a whole-class diamond and a half-dead object (shadowgate, sunshadow `d/magic/obj/rebirther.lpc`, 2026-10-19)
**Symptom:** 100+ warnings from the one `inherit OBJECT;` line (`Redeclaration of global variable` for every variable of `/std/Object`, then `inherited from both ... using the definition in ...` for hundreds of functions, the compiler's cap of 100 hides the rest), and at run time `Value being indexed is zero` from `/std/Object.lpc`'s `id()` when `present()` asks the object while an avatar is `this_player()`.
**Cause:** `<user.h>` in this lib is the player's inherit list (`inherit "/std/weaponless_users"; ...`), pasted with the other includes of `user.c` into an item. The object got two copies of `/std/Object`: `set_name()` / `set_id()` bound to the later one, `::id()` to the earlier one that `create()` never set up. The death and rebirth code, copied from `user.c`, called `save_player()`, `query_money()`, `add_money()`, `query_currencies()` on *itself* (the living chain supplied them), so the dying player's money and save were never touched (`save_player(name)` returns when `name` is not its own).
**Fix:** drop the `#include <user.h>` and keep `inherit OBJECT;`; give the calls their receiver (`reborn->save_player(...)`, `reborn->query_money(...)`); write `set_invis()`, the one living function the object used, as the toggle it ran (`set_hidden` / `set_magic_hidden`). Prove it with the function table, not with a load: `functions(ob, 0)` + `function_exists()` at HEAD and in the tree, and a fake player that logs the calls the object makes on it (`rtvoid/rt.sh`; the probe object goes beside the code under test, this master refuses `/zz_rt`). Dropping the redundant `inherit OBJECT;` instead changes the winner of 17 functions (`move`, `remove`, ...) and is not neutral.
**Detection:** `Redeclaration of global variable` rows at an `inherit` line whose earlier text `#include`s a header (`grep -l '^inherit' include/*.h`); a file at the 100-warning cap in the scan.

### 7.279 An object that inherits two complete classes on purpose: the diamond is a split brain, and dropping one chain breaks it (shadowgate, sunshadow `d/laerad/dojo/obj/shield.lpc`, `d/mine2/rooms/mine22.lpc`, shadowgate `d/atoyatl/tecqumin/obj/table.lpc`, 2026-10-19)
**Symptom:** the compiler's 100-warning cap in a file that compiles (`Redeclaration of global variable` for every variable of `/std/Object`, then `inherited from both ... using the definition in ...`): a shield that is `sheath_inherit` (`/std/pocketarmour`, a copy of the armour class on `/std/bag`) and `mshield` (the real `/std/armour`), a mine shaft that is `mine.lpc` and `/std/pier.lpc`, a walking table that is `MONSTER` and `/std/bag_logic`.
**Cause:** each class brings its own copy of `/std/Object`; every function binds to one chain and works on that copy, so state set through one is invisible to the other. At HEAD the shield's `query_ac()` and `query_block_chance()` return 0 after `set_ac(1)` / `set_block_chance(25)`, and `query_item_bonuses()` is empty.
**Fix:** none that is mechanical. Dropping `inherit mshield` and keeping its `create()` additions makes `set_armor_prof()` undefined (the bag-armour chain has no such setter): the object stops loading cleanly. Which class wins, and which of its setters the other needs, is the author's design decision; the three files stay and are listed in both libs' NOTES. Prove any change with the function table and the getters (`rtvoid/rt.sh`), not with a load. 7.278 is the one case with a mechanical fix (a header that pastes an inherit list).
**Detection:** a compiled file at the 100-warning cap in the scan (`Redeclaration of global variable` rows at an `inherit` line): three in shadowgate, the first two in sunshadow.

### 7.280 `x == !"literal"`: the stray `!` turns the test into "x is 0" (xkx lineage, 236 sites in 43 libs, 2026-10-19)
**Symptom:** a branch the author wrote for everyone else never runs, with no error and no warning: `kungfu/class/gumu/long.lpc` (Long Nü's hint about the secret door, 5 tests in 27 libs), `sunpopo.lpc` and `d/gumu/*` (the gatekeepers send every disciple away), `kungfu/skill/yunu-xinfa.lpc` (men learn a skill whose refusal text says "you are not a woman", 34 libs), `d/lingtai/npc/puti.lpc` ("get out, you are not of my cave" fires only for someone with no family at all, so the other sects walk in).
**Cause:** `me->query("class") == !"taoist"` is `query(...) == 0`: `!"taoist"` is the integer 0. The author meant `!= "taoist"`; the line was copied with its files into every lib of the lineage (23 distinct lines, one file per lib). It compiles in every driver.
**Fix:** `scripts/lpc_fix_not_literal_cmp.py --apply`: `== !"x"` (any spacing) becomes `!= "x"`, in code only; `== !func()` and every other shape stay. 236 comparisons in 110 files; a probe of `yunu-xinfa`'s `valid_learn()` with a fake player answers male 1 / female 1 / neuter 1 at HEAD and male 0 / female 1 / neuter 0 after the fix (`rtvoid/rt.sh xyzx`).
**Detection:** `grep -rnE '==\s*!\s*"'` (the tool's plan lists them); an NPC dialogue branch no player can reach.

### 7.281 `x == "a" || "b"`: the bare literal is always true (every lineage, 209 sites in 58 libs, 2026-10-19)
**Symptom:** a test that is true whatever the variable is: `eat anything` eats the `zicao` / `yuyou` (`arg == "zi cao" || "zicao"`, 13 libs), `valid_enable()` / `valid_combo()` of a skill answers yes to every usage (`tianyu-bufa`, `talk`, `meinv-quan`), the combat daemon prints its hunt message for every kill type (`type == "hatred" || "vendetta"`), `unequip` treats every item as a bracer, a post-house takes any word for a city name, every race is an elf in the Darkwood centaurs, `look drawer` finds the notch in any room that has the line.
**Cause:** `||` binds weaker than `==`, and a non-empty string is true: `arg == "a" || "b"` is `(arg == "a") || 1`. What was meant is `arg == "a" || arg == "b"`; the same slip with `&&` over `!=` (`str != "a" && "b"`) reduces the chain to its first test. No driver warns about it.
**Fix:** `scripts/lpc_fix_literal_or.py --apply`: the left side (a name, an index or a `->query("x")` chain) is written in front of every bare literal that ends its operand; comments, strings and `x == "a" || "b" == y` stay; a chain with the wrong conjunction (`dir == "north" && "south" && me->query(...)`: `forrest2.lpc` in six libs, which needs the parentheses) is listed and was done by hand as `(dir == "north" || dir == "south") && ...`. 209 literals in 124 files + 6 by hand.
**Detection:** `grep -rnE '==\s*"[^"]*"\s*\|\|\s*"'`; the tool's plan.

### 7.282 `x != "a" || x != "b"` and `x == "a" && x == "b"`: a chain of comparisons of one value that can never differ (every lineage, 343 connectives in 277 files of 154 libs by tool and about 20 files by hand, 2026-10-20)
**Symptom:** a guard that never opens or never closes, with no warning anywhere. The `cross pubu` of the Tiezhang waterfall always answers "你要往哪儿穿？" (`arg != "瀑布" || arg != "pubu"`: the secret room behind it is unreachable), the 百日十龙丸 can never be eaten (`arg != "丸" || arg != "wan"`), `qiankundanuoyi.valid_learn()` refuses every character type, the Ming Cult / Wudang mountain gates shut for everyone (`family != "明教" || family != "武当派"`, the `shanmen.lpc` family), the Chang'an inn never stops a guest who paid and walks out (`dir == "south" && dir == "north"`, `ca2.lpc`), a league can be named after a family (`leagued.lpc`: `fname == "大雪山" && fname == "方寸山三星洞" && ...`), Dead Souls' interface never marks `prompt` / `editor` messages `MSG_NOWRAP` (`msg_class == "prompt" && msg_class == "editor"`, 6 libs), `push lever` in Discworld's weather rooms always answers "You must push an existing lever." (`str == "levers" && str == "lever"`), nirvlp312's `players/tar_castles`, `inactive_saved` and `pre_reno` were never reserved for ELDER and above (`who != "tar_castles" || who != "inactive_saved" || ... || level >= ELDER`), and the clause of `xpasswd` that protects the boss accounts (`id == "zjb" && id == "daniel"`) never applied. The inverted reading exists too: `if (arg != "泥" || arg != "mud") { dig the mud; return 1; }` (Hangzhou lake, 7 libs) digs mud for any word and `climb yanshi` (Ming Cult island, 3 libs) climbs for any word, because the body runs when the argument is the *accepted* one: `==` and `||` were meant.
**Cause:** an author who wanted "neither of these" wrote `!= a || != b` (the negation of `== a || == b`, De Morgan slipped); one who wanted "either of these" wrote `== a && == b`. Both compile in every driver and nothing warns. The first is true for every value, the second false for every value, so the branch under it is dead or unconditional.
**Fix:** `scripts/lpc_fix_cmp_chain.py --apply`. `!=` chains joined by `||` become `&&` only where the statement the condition guards is a refusal or a guard clause (it starts with `return`, or is a block that starts with one, holds a `return notify_fail(` or ends in `return 0;` / `return;`): "neither of these" is then what the text under the test says. `==` chains joined by `&&` become `||` whatever the body: a value cannot equal two literals at once. The chain is parenthesized unless it already is a whole group (`(a != x && a != y) || level >= ELDER`), so the operators around it keep their grouping; comments, strings, negated groups and wizard / backup / test directories stay. By hand where the text says which was meant: the blademan `mkblade.lpc` (the comment says the two blades cannot be destroyed by this attack: `material != "blacksteel" && ... != "crimsonsteel"`, kxkj, kxkjii2), the `huagang1.lpc` / `xbkai.lpc` copies (`==` and `||`), shadowgate's Aunuit gates (`(race != "drow" && race != "elf") || enemy`), the majik3 bridge climbs, shenmo's `juanlian.lpc` (a stray fifth `|| id != "nver hong"` after the four fragments: the NPC refused everything, so the quest could not be finished). About 120 sites are listed and left: the body *does* something (`if (str != "curtains" || str != "curtain") tell_room(...);` with the `pull` that follows running for any word: the author forgot braces, not the operator; mahjong `Hu_type` scoring in 56 of them), so `==` and `||` could as well have been meant. HEAD-vs-tree load check of one object per distinct content (73 libs, regress 0); runtime probes: `leagued.valid_new_league("盘丝洞")` answers 0 at HEAD and a refusal now, `qiankundanuoyi.valid_learn()` answers 0 at HEAD and 1 for a 光明磊落 character now.
**Detection:** `grep -rnE '([A-Za-z_][A-Za-z_0-9>\[\]"()-]*)\s*!=\s*"[^"]*"\s*\|\|\s*\1\s*!=\s*"'` and the `==` / `&&` twin; the tool's plan.

### 7.283 `member_array('/', str)`: a byte search whose offset is a byte offset (every lineage, 226 calls in 88 libs, FluffOS 923cdbc0 warns, 2026-10-20)
**Symptom:** `/std/json.lpc:566: Warning: member_array(int, string) searches BYTES ...` on the console, once per call site, the first time the string holds non-ASCII text before the match (pkuxkx / formosasaga / shadowgate / sunshadow JSON encoders test every Chinese string they encode for `"`, `\\`, `\b`, `\f`, `\n`, `\r`, `\t`, `\x1b`). Before the warning the answer was silently wrong for such a string.
**Cause:** a character literal is an int, so `member_array('/', str)` is the byte search (strchr) of the UTF-8 string: its result and a third-argument start offset are byte offsets, while `str[0..idx-1]` / `str[idx+1..]` count characters. The ASCII path strings of `vrm_server.lpc` / `mazemap.lpc` / `mine_field.lpc` (`idx = member_array('/', str)`, about 40 libs) never differ: only the warning. A name, a title or a mail line in Chinese is cut in the wrong place.
**Fix:** `strsrch(str, "c")` is the same search by character (-1 when absent, the character index otherwise). `scripts/lpc_fix_member_array_char.py --apply` rewrites `member_array('c', STR)` when STR is certainly a string (a literal, a name declared plain `string` in scope, a call of `lower_case` / `read_file` / `sprintf` ...): 188 calls in 172 files of 87 libs; by hand the four JSON encoders (31 calls, they test a `mixed` inside `stringp()`, and `0x0c` / `0x1b` hex literals), the holymission masters' `valid_write` (3) and sgzmudsgz (4). LDMud libs are skipped (their `member_array` is another efun). Left as written: the calls with a start offset (strsrch() has none: `i = strsrch(str[from..], "c"); if (i != -1) i += from;`), i.e. the `tail()` sefuns of discworld / dw_fluffos_v1 / v2 / pkuxkx (inside `#ifdef COMPAT_TAIL`, which the lib defines: dead code) and sgzmudsgz `m_file` / `m_set`.
**Detection:** `grep -rnE "member_array\(\s*('[^']+'|0x[0-9a-fA-F]{2})\s*,"`; the census keeps the run-time warnings (`scripts/lpc_load_census.py --report`).

### 7.284 `(: this_object(), ({ "do_to", me, arg }) :)`: a local variable in the call_other function pointer, the line-editor commands do not compile (xkx lineage, 42 files in 26 libs, 2026-10-20)
**Symptom:** `/cmds/usr/to.lpc:19:54: error: Illegal to use local variable in functional.` and a stack trace for `to say ...` (a many-line `say` / `tell` / `chat`), `describe`, `plan`, `sig`, `song`: the command object never loads. The first `to` line of a play sweep found it.
**Cause:** the call_other pointer `(: ob, ({ "fn", args }) :)` takes constants only; a local inside the array makes the compiler read the whole pointer as an expression functional, where locals are illegal. The old driver let the form through. The libs that kept `to` working wrote `(: call_other, this_object(), "do_to", me, arg :)`.
**Fix:** that efun-pointer form: the arguments are bound when the pointer is made, and what the caller passes (the editor's `(* callback)(text)`) is appended, so `do_to(me, arg, text)` gets the text. `scripts/lpc_fix_functional_locals.py --apply` (42 sites; every callback's parameter count is bound arguments + 1). Live in xkx100: `to say 第一行` / `这是第二行` / `.` answers `你说道：第一行 这是第二行`. Wizard directories, `last_modify/` copies and the commented-out lines stay.
**Detection:** `grep -rnE "\(:\s*this_object\(\)\s*,\s*\(\{\s*\"\w+\"\s*,\s*[A-Za-z_]"`; census text `Illegal to use local variable in functional`.

### 7.285 A command writes the result of `read_file()` of a file the archive does not ship (`boss`, 9 xkx libs, 2026-10-20)
**Symptom:** `Bad argument 1 to receive()  Expected: string or buffer Got: 0.` from `write(msg)` in `cmds/usr/boss.lpc` (`boss 1` shows a fake document, `msg = read_file("/open/shit.txt")`). The screen had been cleared and `block_msg/all` set first, so the session is left muted until `bossgone`.
**Cause:** `read_file()` of a missing file answers 0 and `write(0)` is a bad argument in this driver; `/open/` is a wizard-owned directory the archive does not carry.
**Fix:** `if (stringp(msg)) write(msg);` (xkx100, xkx100utf8, xiakexing100, xxcq, xxcqii, xxcqii2, yxxcii, sj, shiji). The same session found the sibling slip `news`: it loads the update board's room `/u/qingyun/workroom` (and `bboard.setup()` moves the board there), a file the three xkx libs lack: `file_size(LOC + ".lpc") > 0 &&` before both (see 7.269).
**Detection:** a play sweep of `cmds/usr` (KB 08 10.16) with the argument shapes `1` and `me`; statically `read_file("literal")` whose literal is not under `work/` and whose result is written unchecked.

### 7.286 `save_object()` answers the number of bytes it wrote: a test `== 1` never passes (xkx lineage `exit.lpc`: xiakexing100 fixed 2026-07, xkx100utf8, xkx100 2026-10-20)
**Symptom:** `quit` prints the goodbye text, then `警告：档案保存失败，无法退出游戏，请马上联系巫师解决。` and the player is never disconnected; every player, every login (the `link_ob` branch runs on every login).
**Cause:** `save_object(file)` returns the size of the text it wrote (`save_object_recurse()` accumulates `textsize`), not the 1 of the MudOS convention; `a = link_ob->save(); ... if (a == 1 && me->save())` held only for a one-byte save. The fix made in xiakexing100 in July was not carried to the family member that has the same line.
**Fix:** test truthiness: `if (a && me->save())`. Found by running `quit` in a live session.
**Detection:** `grep -rnE "save(_object)?\([^()]*\)\s*(==|!=)\s*1\b"` (no other direct comparison in the corpus); a play test that ends with `quit` and checks the connection closed.

### 7.287 `call_out_info()` entries have three elements: the `callouts` command and every reader of `info[i][3]` fail (every lineage, 121 files in 97 libs, 2026-10-20)
**Symptom:** the wizard command `callouts` answers `Array index out of bounds` (`/cmds/wiz/callouts.lpc` line 18) on its first line and lists nothing; the same for `calloutd`, the `cod` tool and the alarm clock's `query_long()` when an alarm is pending.
**Cause:** this driver's `call_out_info()` returns `({ object, function, delay })` (`src/packages/core/call_out.cc` `get_all_call_outs`: `allocate_empty_array(3)`); `docs/efun/system/call_out_info.md` still promises a fourth element, the call_out's argument. MudOS-era code prints or compares `info[i][3]`.
**Fix:** `(sizeof(info[i]) > 3 ? info[i][3] : 0)` (`scripts/lpc_fix_callout_info.py`: the name must be assigned from `call_out_info()` in the same file, or be the variable of a `foreach` over it); the alarm clock shows `"..."` for the message. Left: the intermud `pingd.lpc` / `pingtcp.lpc` (the same access inside `for (loop = 0; loop < sizeof(loop); loop++)`, a loop that never runs) and the Praxis `sage_room.lpc` (it re-schedules the call_outs whose argument is not `ob`: without the argument nothing can be kept). The missing argument element is a driver gap, not a lib bug.
**Detection:** `grep -rn "call_out_info" ... | grep "\[3\]"`; a wizard sweep (KB 08 10.16) of `callouts`.

### 7.288 `find_object(dest)->query("no_fight")` in a random walk: the destination is not loaded yet (xkx lineage quest NPCs, 15 files in 6 libs, 2026-10-20)
**Symptom:** `Bad argument 1 to EFUN call_other()  Expected: object, string, array  Got: int(0)` from `random_move()` of every quest / haojie NPC (`clone/quest/questyinshi`, `questman`, `questjianxi`, `questxuncheng`, `bwdhnpc`, `clone/haojie/shashou`), once per heart beat, and the NPC never leaves its first room.
**Cause:** the NPC asks the destination room whether it is `no_fight` before it walks; `find_object(dest)` is 0 until somebody has loaded that room. The `npcd` daemon's own `random_move()` loads it first (`if (!find_object(dest)) load_object(dest);`).
**Fix:** `(find_object(dest) || load_object(dest))->query("no_fight")`. Found by the live sweep: a `clone /clone/quest/questyinshi` in the room and the console.
**Detection:** `git grep -nE 'find_object\(dest\)->'`; the shape `find_object(x)->f()` with a computed `x` is the general class.

### 7.289 The catastrophe system's verdict names a leader who may have left: `lead->name()` raises, the lock-down is never lifted (xkx lineage `disaster.lpc`, 25 libs, 2026-10-20)
**Symptom:** thirty minutes after a 浩劫 / 天地劫 starts, `verdict_time()` dies in the `message()` that announces the result (`lead` is 0), `LOGIN_D->set_madlock(0)` is never reached and `cmds/usr/exit.lpc` refuses `quit` for everybody from then on (`if (LOGIN_D->get_madlock())`).
**Cause:** `lead` is the player who received the challenge (a global set in `copy_npc()`); a player who logged out meanwhile is a destructed object, a global that holds one reads as 0.
**Fix:** `(lead ? lead->name() : "各派豪杰")` in the two verdict messages (xkx100, xiakexing100 `adm/daemons/disaster.lpc`; `feature/disaster.lpc` in 22 more libs, 48 sites).
**Detection:** `git grep -nE '(弟子在|联盟，在)" *\+ *lead->name'`.

### 7.290 `if (x = CONST)`: an assignment of a constant used as a condition (every lineage, 1,908 terms in 375 paths of 190 libs, 2026-10-20)
**Symptom:** a test that is always true or always false, with no warning of any kind: `if (arg = "button" || arg = "按钮")` (njhhdxdes2hx `d/taohua/andao.lpc`: `push` anything opens the cave, the Qimen skill gate is the only check), `if (!arg || arg = "") return 0;` (bmxkx2001 `no_pk_room.lpc`: the command answers 0 for every argument), `else if (check = 0 && tempB != "")` (the mahjong scorer of 40+ libs never awards 混老头 / 清老头), `if (m=0) {p=new(..)} if (m=1) {p=new(..)} ... if (m=9)` (pkuxkx `clone/gift/liwu.lpc`: the gift box always gives the last item), `if (skill = 80 && ...)` (every `qiankun-danuoyi` copy), `if (type = "boots") return 10; else if (type = "waist") return 5;` (dtsl `duanzao.lpc`), `if (daming_positions="") get_daming_positions();` (pkuxkx: refreshed on every call), `if (j = 1) { map_skill("force", ...) }` (pkuxkx `feature/skill.lpc`).
**Cause:** `=` typed for `==`. The value of the assignment is the constant, so the branch is taken for every non-zero number and every string (even ""), never for 0, and the variable is overwritten either way. The driver diagnoses neither (`lpcc`: `if (x = 1)`, `if (s = "a")`, `while (x = 0)` compile clean; only the type-incompatible `==` forms are errors, `== always false because of incompatible types`). The shapes copy with the files: 375 distinct paths for 1,908 terms.
**Fix:** `scripts/lpc_scan_cond_assign.py` lists the terms (a condition's `&&` / `||` operands of the shape `name = "string"` or `name = number`; a call, a name or an expression on the right is the ordinary `if (ob = find_object(x))` idiom and is not listed); `scripts/lpc_fix_cond_assign.py --apply` turns the `=` into `==` (code only, wizard homes and backups skipped, `JOBS=6`). What the `==` exposes is then fixed by the earlier tools: `lpc_fix_literal_or.py` (`str == "shield"||"astral shield"||...` is `x == "a" || "b"`, 7.281) and `lpc_fix_cmp_chain.py` (`arg == "仙鹤" && arg == "xian he"` can never be true, 7.282). About 50 hits (random samples across the libs, then the pkuxkx and xkx100 ones) were read in context: every one was the typo.
**Detection:** `grep -nE '(if|while) *\( *[A-Za-z_][A-Za-z_0-9]* *= *("[^"]*"|-?[0-9]+) *\)'` finds the single-term form; the scanner finds the chains. Dormant branches become live: boot a few of the touched libs and read the console.
