# KB 07 — Login and registration flow bugs (§8)

Registration exercises the connection object, the ACL, lazy compiles,
Chinese-name detection, and the player-body class in a single chain.

**Finding them (2026-10-20):** a login that dies on a fresh tree is what the login survey walks (`scripts/play_survey.py`, KB 08 10.16: a robot registers a character in a booted pristine tree, reads the console, checks that the character was saved and, with `--relogin`, loads again). Its cases are in KB 06: a runtime counter file read unguarded (7.298, 7.301), `crypt()` over 255 bytes (7.294), the sefun's euid and `valid_read()` (7.295, 7.304), `valid_write()` and the `.o` of a save (7.309), the pager and a missing banner (7.297, 7.300), `get_config(__MUD_PORT__)` (7.302).

### 8.1 GBK byte-range Chinese detection (the most impactful bug in the project)
On this driver, `str[i]` is a Unicode codepoint and `strlen()` counts
characters. Every check written against GBK bytes silently misbehaves.
- `str[i] > 160 && str[i] < 255` → `str[i] >= 0x4e00 && str[i] <= 0x9fff`.
- Length gates calibrated in bytes (`strlen(name) < 4` meaning 2 hanzi):
  halve them, and match whatever the error message states. An
  `is_chinese()` that requires `strlen >= 2` rejects 1-character tail
  slices, so names of some lengths are accepted and others rejected.
  Check only the first codepoint (`dfgsiiv13b`).
- Drop `i % 2` gates. Change `name[i..i+3]` to `name[i..i+1]`. Change
  `PATH(name)` sharding from `name[0..1]` to `name[0..0]`. Byte-shift
  hacks are meaningless.
- Fix `chinese.lpc`/`chinesed.lpc`/`named.lpc`. Leave ASCII
  `is_english` checks alone.
- **HZK bitmap-font renderers** look up glyph offsets from bytes. They
  can't work without a Unicode→GBK table, so return plain text instead
  of a "BUG" string (`sanguozhi`, `sgzmudsgz` quiz).
- **Word-wrap `sort_string()`** with an extra `i++` inside its
  `> 160` branch drops every other Chinese character from all output.
  Remove the `i++` and keep `len += 2` (`xyxyutf8`).
- **`unit + short` keys cut with `[2..]`.** `inventory`, the brief-mode
  item list of `feature/move` and some `look` copies count items in a
  mapping keyed by `query("unit") + short()` and print `key[2..]` for a
  single item, to drop a one-hanzi unit. Here that also eats the first
  character of the name (「包子」 → 「子」) or the ESC of a coloured one. Use `[1..]`.
  Detection: `grep -rE '== *1 *\? *\w+\[\w+\]\[2\.\.\] *:'`; live in 45
  libs on 2026-10-18 (90 files: `feature/move`, `cmds/*/inventory`, `look`), swept with
  `scripts/lpc_fix_unit_cut.py SLUG... --apply` (code only: copies inside an unclosed `/*`
  block are skipped; `longyunmeng_binary` carries it in its patch). Proof at HEAD: the
  `inventory` of an NPC holding one 长剑 listed `剑(Sword)`.
  Same family: `feature/item_make`'s `get_item_id()` splits names into
  two-hanzi words with `[0..3]` / `len > 4` (4 libs).
- **Sect code (2026-10-22, KB 06 7.360).** The masters' `attempt_apprentice()` renamed a disciple
  `"澄" + name[2..3]` (the second character of the old name) and tested the generation with
  `name[0..1] == "澄"`; the rename registrar `zhuce` (`change_name.h` / `zhao.lpc`) gated on
  `strlen(arg) != 4` and `i < 4 || i > 8 || i%2`. All of it counted bytes: 4,416 edits in 189 libs
  (`scripts/lpc_fix_gbk_slice.py`, not idempotent, ledger `scripts/gbk_slice_converted.txt`; the
  oracle is `xkx100utf8`, the community's UTF-8 port). A Chinese literal compared with a slice twice
  its length can never match: `rg '\[ *0 *\.\. *1 *\] *(==|!=) *"[^\x00-\x7f]'`.
- **Every other name gate (2026-10-22, KB 06 7.362).** House (`luban`), gang (`nicai`), group, IRC,
  title and board-title gates (`strlen(name) < 4 || strlen(name) > 12`, `i < 4 || i > 24 || i % 2`)
  beside a message that says `2 到 6 个中文字`: the message is the oracle, `scripts/lpc_fix_strlen_gate.py`
  halves the gates that are exactly twice what it states (1,813 edits in 173 libs).

**Standing rule:** registration isn't verified until a REAL Chinese name
(e.g. 秦风) has been accepted into the next stage.

### 8.2 Flow shapes vary; read the `input_to` chain
Flows include GB/BIG5 questions, age gates, `new` vs any id, and
split surname/given-name prompts. Prompt text can lie: `xyzx3`'s "英文名字"
prompt is actually a client-version gate expecting `2060`. Read the
callbacks in `logind.lpc` before scripting. Send one line at a time
when a flow is confusing.

### 8.3 "Every post-login command silently does nothing"
Check these in order:
1. A live-clock prompt never goes idle (lower `--idle`; §10.2).
2. `private command_hook` (8.3a).
3. A dead command-table `sscanf` (8.3b). It can coexist with (2).
4. The player has no environment (§7.14).
5. An ACL `"stat"` denial of `get_dir` (§7.5).
6. Missing re-enable after a kick-reconnect (§7.108).

#### 8.3a `private nomask command_hook`
Once inherited, `private` is demoted to DECL_HIDDEN, and
`add_action`/`command()` can't call it. Drop `private` and keep
`nomask`. Ordinary typed commands sometimes still work, because
ORIGIN_DRIVER bypasses the check. NPC `command()` self-calls
(movement auto-look, recruit, registration NPC dialogue) still fail, so
test at least one NPC `command()`.
- **Where the driver checks (read in `packages/core/add_action.cc` and `vm/internal/apply.cc`, FluffOS 923cdbc0; measured with `lpcc_eval.py`, 2026-10-22).**
  A command typed at the prompt has no `current_object`: `where = ORIGIN_DRIVER`, the access it needs is `DECL_HIDDEN`, the lowest, so every handler runs,
  `protected`, `private` and the hidden `private` of an ancestor included. `command()` called from LPC is `ORIGIN_EFUN`: a handler of ANOTHER object has to be
  public (`protected` / `private` answer 0 and the log says `apply() with insufficient permission`), a handler of the caller itself needs `private` or above
  (a hidden ancestor `private` fails). `call_out` / `input_to` need `private` too, which is why the hidden ancestors below fail. So a `private` / `protected`
  `add_action` target is not a dead handler for a player (measured through `command()` in a test object it looks like one: do not sweep it); it is dead for an NPC
  and for anything that goes through `command()`. A function that does not exist at all (KB 06 7.349) fails from every origin.
- Grep (uncommented declarations only):
  ```
  rg -n --glob '*.lpc' '^[ \t]*(nomask[ \t]+)?(private|static)[ \t]+(nomask[ \t]+)?int[ \t]+(command_hook|cmd_hook)\s*\('
  ```
  Ignore dead variant files (`command2`, `commandhell`, `u/<wiz>/`).
  Libs inherit via the `F_COMMAND` macro, so a literal-path inherit grep
  proves nothing.
- The same demotion breaks **`call_out`/`input_to` targets** in
  inherited files:
  - `feature/action.lpc::eval_function` (behind `start_call_out`, so all
    buffs and DoTs).
  - `inherit/item/combined.lpc::destruct_me` (money spent to 0 never
    destructs). The ES/xyj copies at `std/item/combined.lpc` were already
    `private` in the MudOS original (MudOS let a call_out reach it);
    swept 2026-10-06 to `protected` in 77 libs after a live hxxtjqb boot
    logged `apply() with insufficient permission ... destruct_me ...
    needs: private, has: hidden` for every coin pile.
  - Corpus sweep 2026-10-06 (87 files, 64 libs): every *inherited* file
    (its path resolved from the lib's `inherit` lines and header macros)
    that `call_out`/`input_to`/`get_char`s one of its own private
    functions -- `feature/action::eval_function` (37 libs),
    `feature/team::follow_path`, `d/xueshan/inherit/liquid_content::
    destruct_me`, `std/index::sort_manual_dirs` (finalrealms `man`,
    ninetears), wqa rooms, furnace rooms. `protected` is virtual, so a
    function was changed only when no inheritor of that file defines the
    same name (none did). A leaf object's call_out to its own private
    function works and was left alone.
  - Libs: Doing-Lu "hell" lineage, `xkx2001`, `ninetears`'s `refresh2`.
    In `ninetears` the boundary was an `#include`d `.lpc` file, then
    inherited.
  - Grep `private NAME` plus `call_out("NAME"`/`input_to("NAME"` in the
    same inherited file.
- Use binary-mode edits (17 CRLF files got normalized once).
- `protected` is a different visibility. Don't expand to it without a
  live failure.

#### 8.3b Dead command indexer
`sscanf(f+"$","%s.c$",f)` in `commandd` makes the command table empty.
Change it to `%s.lpc$`. Test a third command besides `look`/`quit`.

### 8.4 Test `score`, not just `look`
`score` proves the body class compiled. If registration stalls before
entering the world, grep for the body-class compile error (§6.2 missing
simul_efuns, §8.5).

### 8.5 Player-body compile blockers
A direct-call argument type mismatch is fatal: `is_killing(ob)` →
`is_killing(ob->query("id"))`. Grep `is_killing(`.

### 8.6 Anti-flood throttles
Bypassed per §1.3e. The rejection is often a silent disconnect.
Restarting the driver clears in-memory throttles. Register in one
continuous session.

### 8.7 GBK/BIG5 encoding-choice menus
- **Shape 1:** `set_encoding("gbk")` transcodes UTF-8 internals into GBK
  bytes, so the client sees mojibake. Map every choice to `"utf-8"`
  (`aoxiangtianji`).
- **Shape 2:** a local int-flag `set_encoding` override plus a
  `convertd` GB↔BIG5 table. Map every choice to the converter's no-op
  value (`encode=0`).
  - An UNBOUNDED byte test (`c >= 0xA1`) is a live bug.
  - A bounded one (`0xA1–0xFE`) never matches UTF-8 CJK, so it's not a
    bug. Verify live.
- **Shape 3:** WASM ICU lacks GBK, so a `set_encoding("gbk")` while the
  menu is being drawn disconnects the user. Use `catch(...)` and stay on
  utf-8 (`fy2005`). Corpus sweep done (2026-09-15): `fy2005`,
  `xyxyutf8`, `immaster`, `nt7`.

### 8.8 Wizard-id branch in `get_id()` with no save-existence check and no `return`
A freshly seeded admin id gets "密码错误". Add `file_size(save) >= 0`
plus `return` (`xkm`).

### 8.9 Food/water first-login gate reads `ob->query("age")` (the login stub)
Always false, so every new character starts starving. Use
`user->query("age")`. Swept across 21 libs. Score/display uses of
`ob->query("age")` elsewhere are a different meaning; leave them.

### 8.10 Retry re-prompt resumes `get_id` (the version gate) instead of `get_id1`
A mistyped id gets "unsupported client" and a kick (`xiyouji2006`).
Only applies when a distinct `get_id1()` exists. `mhxy`/`mhxyqd`/
`shenmo` have no `get_id1` and must not be "fixed".

### 8.11 Macro written inside a `@TEXT` block
`GAME_NAME` is never expanded. Use string concatenation
(`xlqy_early`).

### 8.12 Prompt says uppercase, check is lowercase
Apply `lower_case()` before the range check (`xbtxiii`).

### 8.13 WIZ-password gate has no path for "not set yet"
Every wizlist id deadlocks on its second login. After the nag, call
`check_ok(user); return;` (`sjshv150` only; corpus survey clean).

### 8.14 `BAN_D->is_banned(query_ip_name(ob))`
The hostname fails the dotted-quad parse. Fail-closed bans everyone;
fail-open never bans. Use `query_ip_number`. Swept across 67 libs.

### 8.15 Runtime wrong-case `new()`/`->`/`vendor_goods` paths
These compile clean and crash on first use. A directory's case can be
wrong too (`clone/ARMOR`).
- Force a caught first compile with `update <room>`.
- Cross-check every path literal against the on-disk case.
- Seen on: `sjshwzb` (resolved), `hy5`'s `Whammer`, `mohuanshiji`
  (32 renames).

### 8.16 Kick-reconnect re-arms `input_to("get_id", ob, user)` with a wrong type and no prompt
The next command is treated as a new id. Add the prompt and pass `0`
(`yxjh`).

### 8.17 Id-existence check is disk-only
A new account whose first save was delayed is told it never registered.
Guard the newbie move so the save happens; also try `find_body()`
(`xajh2`).

### 8.18 Socket read callback logs a non-array signal and doesn't `return`
Indexing 0 errors on every connection, visible only in the lib's own
catch log (`imud`).

### 8.19 Password reject branches fall through to "Password set!"
Add `return` to both (`rifts2`).

### 8.20 Character-generator room's only exit command (`ready`) commented out
Every new character is stuck forever. Re-enable it (`rifts2`).

### 8.21 Redundant second `restore_body()` after `BODY_D` setup
It reverts role-based command paths, so admin commands disappear on the
next login. Delete it (`oxidus`).

### 8.22 `export_uid()` sets only the uid, and only when the target's euid is unset
Every existing account sees "What?" after relogin (`pd`). Fix:
`ob->clear_euid()` before `export_uid`, and `seteuid(UID_ROOT)` before
`restore_object`. Test register → quit → reconnect in one sitting.

### 8.23 `(: "funcname" :)` returns the string; it doesn't call `funcname`
`edit`/`more` completion callbacks never fire: mail is silently lost
and pages drop to the prompt. Use `(: funcname :)` and make sure a
prototype is visible (`foundation1`; `nightmare3` has the same lines).
Grep `'(: *"[a-zA-Z_]*" *:)'`.

### 8.24 `access.db` grants a group whose `groups.db` line lacks the daemon uid
Add `Mudlibrary` (or that lib's daemon uid) to the group (`rifts2`).
Verify with `geteuid(find_object(...))`.

### 8.25 `find_player() || load_player()` fallback followed by an unconditional `userp()` check
The offline branch is always rejected. Gate the check on which branch
produced the object (`gjzddmudda`'s `fire`).

### 8.26 Abandoned registrations leave bodies that make `find_player()` raise
**Symptom:** an id that registered after an aborted attempt logs in to a
dead session: every command answers `什么？`; the console shows
`The player(<id>) has existed in the world.` from the simul_efun's
`find_player()`, called by `logind`'s `find_body()` in `get_passwd()`.
**Cause:** `logind` makes the body before registration ends (wllz3: at
the e-mail step), and a client that drops later leaves it in no room.
When the player is offline, `find_player()` falls back to
`filter(children(USER_OB), filter_player)` and raises on 2+ matches.
**Fix:** `filter_player()` also requires `environment(ob)` (an orphan is
then found and destructed by `find_body()`'s own loop).
**Detection:** `grep -l "has existed in the world" libs/*/work/adm/simul_efun/user.lpc`
(38 libs share the code); a lib is affected only if its `logind` calls
`make_body()` before the last prompt. Repro: abort registration twice
after that prompt, register fully, `quit`, log in again.
**Swept 2026-10-15:** the `environment(ob)` test is in all 42 vendored libs
that carry this `find_player()` (36 `adm/simul_efun/user.lpc`, 6 nitan-family
`adm/kernel/simul_efun/user.lpc`); nt7 upstream. It is a no-op where the bug
cannot happen: in bixiecanyang (body made at the e-mail step) two abandoned
registrations then a full one and a relogin worked with and without it, its
abandoned bodies never get the player's uid, so `filter_player()` skipped
them anyway.
