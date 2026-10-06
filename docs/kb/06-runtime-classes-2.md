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
  `replace_program(<macro>);`. Hand-fix the irregular shapes:
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
   targets' base class.

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


