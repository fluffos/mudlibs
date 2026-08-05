# zjdyzj — 地狱无门 ("No Escape From Hell") — archive #80

Archive: `终极地狱-指间mud版服务端.rar` ("Ultimate Hell — 'Fingertip MUD'
edition server"). Port: **40074**. Status: **done** — boots clean, full
registration with a real Chinese name works end-to-end in one continuous
`mudclient`-style session, reaches the game world, and two post-login
commands (`look`, `score`) both produce real, correct output.

**Real in-game name** (per `config.hell`'s `name` directive, decoded):
**地狱无门** ("No Escape From Hell" / lit. "Hell Has No Gate"). The mudlib
root inside the archive is `hell/`. Lineage: **ES II** (per `master.lpc`'s
own header comment: *"for ES II mudlib, original from Lil, rewritten by
Annihilator (11/07/94), modified by Xiang for XKX (12/15/95), updated by
Doing Lu for hell (2K)"*) — same broad family as `kxkj`,
`kxkj1`, `yxcs`, `wuhanzhan`, `huoying`, `shenzhou`,
etc., but this specific `hell`/`XKX` branch is architecturally sound (real
per-object `F_DBASE` set/query/delete via `feature/dbase.lpc`, **not** the
nitan-family bare-simul_efun-dbase bug from AGENTS.md §15).

**CROSS-CHECK FLAG for the main session**: two other archives in this
batch also carry the "终极地狱" name and were being processed by sibling
agents concurrently with this one — archive #78 (`终极地狱.rar` →
`libs/zhongjidiyu`) and archive #79
(`终极地狱之爱若幽兰1.166正式版.rar` → `libs/zjdyaryl`).
I could not cross-check against them (concurrent extraction). **Please
diff/compare all three once all three are done** — same game at different
snapshots, unrelated forks sharing a name, or genuine duplicates. This one
(`zjdyzj`) is confirmed ES II/XKX lineage (`master.lpc`
header comment, `secure`-free `adm/single/`+`adm/simul_efun/` layout,
`F_DBASE` architecture) — cheap first thing to check against the other two
once their own NOTES.md exist.

## What makes the "指间mud版" ("Fingertip MUD edition") build distinctive

This is the answer to "investigate what makes this build distinctive" —
and it turned out to be **the single most impactful finding in this pass**
(see the crypt() section below), not just a cosmetic branding difference.

1. **Two mostly-dead client-protocol headers** are `#include`d from
   `globals.h` (so present in every object): `include/zjmud.h` ("指间MUD
   转义协议" / "Fingertip MUD escape protocol" — structured message-type
   tag macros like `ZJTITLE`/`ZJEXIT`/`ZJPOPMENU`/`ZJCHANNEL` meant for a
   rich mobile/web client to parse and render specially) and
   `include/tomud.h` (an older Tomud-client escape-sequence macro set,
   `TMI`/`ALERT`/`PTEXT`/`L_ICON` etc). **Confirmed by grep that neither
   header's actual protocol macros are ever called anywhere in the lib**
   (`grep -rn "ZJTITLE\|ZJEXIT\|ZJOBIN\|TMI(\|ALERT("` → zero hits outside
   the headers themselves) — these are vestigial/unwired, presumably
   copied in from a sibling build that did use them, or prepared for a
   client integration that was never finished.
2. **What IS actively wired in**: `zjmud.h`'s `ZJKEY` constant and two
   simple numeric tag macros (`SYSY = "000"`, `ZJTMPSAY = "000" + "015"`
   equivalent via `ESA=""` prefix) are used throughout `logind.lpc` — a
   plain telnet client just sees literal digit sequences (`0008`, `015`)
   glued to the front of certain system/registration messages (visible in
   the transcript below, e.g. `0000008`/`0000007`) — cosmetically odd over
   plain telnet but not a functional blocker.
3. **The real distinctive feature, and a genuine driver-compat bug**:
   `logind.lpc`'s login flow requires a **crypt()-based client-version
   handshake** before any account/character data is even accepted —
   `logon()` sends `"ver1.0," + crypt(ZJKEY, 0)`, then `jiance()` expects
   the client to echo back `crypt(ZJKEY, <received-string>[2..3])`. On the
   ORIGINAL driver this targeted, `crypt(key, 0)` produced a deterministic
   13-char old-style DES-crypt string (2-char salt + 11-char hash), so a
   real client could compute the matching response. **On this FluffOS
   build, passing an `int` (not a string) as crypt()'s salt argument falls
   through to a completely different code path that generates a FRESH
   RANDOM SHA-512 (`$6$...`) salt every single call** (confirmed by
   reading `src/packages/core/efuns_main.cc`'s `f_crypt()`), and the
   2-character slice `str[2..3]` the mudlib then uses as a "salt" for the
   verification call doesn't parse as any recognized modern salt prefix
   either (also random). **Empirically verified this makes the handshake
   mathematically unpassable by ANY client** — two consecutive
   `crypt(ZJKEY, str[2..3])` calls given the identical `str` never produced
   the same output. This silently blocked **100% of connections** at the
   very first prompt, with zero compile error and zero `debug.log` entry —
   it just looks like "wrong client version" to anyone testing it.
   **Fix**: changed `crypt(ZJKEY, 0)` → `crypt(ZJKEY, "zj")` (an explicit
   old-style 2-char alphanumeric salt, not starting with `$`) in
   `adm/daemons/logind.lpc`'s `logon()` — this driver's `crypt()` still
   honors that as the classic deterministic DES-crypt path, restoring the
   original request/response design so a real client (or our own test
   client, using Python's `crypt` module) can compute the correct reply.
   **This is a new pattern, not previously in AGENTS.md's catalog** —
   worth promoting to a `§15ai`-shaped entry: *"crypt(key, 0)/crypt(key,
   int) salt semantics changed on this driver — always generates a random
   modern hash instead of a deterministic old-style one; any lib doing a
   client-side challenge/response based on slicing a `crypt(..., 0)`
   result needs an explicit short (non-`$`-prefixed) string salt instead."*

## Fixes applied (with why)

Pre-boot proactive checks (per the task's required list) and what was
found:

1. **§15h (`is_chinese`/`named.lpc` GBK byte-range bug) — YES, present,
   fixed.**
   - `adm/simul_efun/chinese.lpc`'s `is_chinese(str)`: GBK lead/trail-byte
     range check (`str[i]<176||str[i]>=248` etc, stepping by 2, requiring
     even byte-length) → rewritten as a straight CJK Unicode codepoint
     range check (`str[i] >= 0x4e00 && str[i] <= 0x9fff`), one character
     per index, `strlen(str) < 1` minimum instead of `< 2`.
   - `adm/daemons/named.lpc` (the "similar name" / name-collision guard
     used during registration) had the full documented shape: `#define
     PATH(name) (name[0..1] + "/" + name)` (sharding key = "first GBK
     character", now taking 2 real characters) → `name[0..0]`; every
     `strlen(name) < 2` guard (meant as "at least 1 character") →
     `strlen(name) < 1`; the sliding-window near-miss check's byte-widths
     4/6 (2/3 GBK characters) → character-widths 2/3 (`name[i..i+1]` /
     `name[i..i+2]`, loop bounds `l-2`/`i+3<=l`).
   - Verified end-to-end: sent real Chinese names **秦风** and **夏流**
     through registration in two separate full sessions and both were
     accepted straight through to character creation and into the game
     world.

2. **§15ae (private add_action hook) — YES, present in TWO places, both
   fixed.**
   - `feature/command.lpc`'s `command_hook(string arg)` — the central
     `add_action`-registered command dispatcher, inherited into the player
     body class — was declared `private nomask`. Dropped `private`,
     kept `nomask`. Without this fix every single typed command (`look`,
     `score`, everything) would have silently done nothing after a
     successful login, with zero error anywhere — exactly the failure
     mode this policy exists to catch.
   - **New instance found by grepping every `add_action()` target lib-wide
     for a `private` declaration in the same file** (not just the obvious
     central dispatcher): `adm/npc/luban.lpc` (a crafting/house-building
     NPC, "鲁班" — the legendary Chinese master carpenter) registers 18
     of its own commands (`do_answer`, `do_stop`, `do_desc`, `do_show`,
     `do_changename`, `do_changeid`, `do_changetype`, `do_changedesc`,
     `do_finish`, `do_withdraw`, `decide_withdraw`, `do_demolish`,
     `do_help`, `do_list`, `do_type`, `do_agree`, `do_reject`,
     `do_delete`) via `add_action`, ALL declared `private` (consistent
     with the rest of that file's style, which declares essentially every
     helper function `private`). Removed `private` from just those 18
     forward-declarations + definitions (left every other, non-add_action
     `private` helper in the file untouched). Without this, talking to
     鲁班 and typing any of his commands would silently do nothing.

3. **New crypt()-semantics bug (see distinctive-build section above)**:
   `adm/daemons/logind.lpc`'s `logon()`/`jiance()` client-version
   handshake — fixed by using an explicit 2-char salt instead of `0`.
   **The single highest-impact fix in this pass** — nothing past the
   very first prompt was reachable before this.

4. **§15s (message() 4th-arg type bug) — YES, present, fixed, found live
   during boot testing.** `adm/simul_efun/message.lpc`'s `message()`
   wrapper forwarded its `exclude` parameter straight to `efun::message()`
   with no guard; the extremely common 2-arg `tell_room(str, target)` /
   bare `shout()`/`say()` call shapes leave `exclude` as a raw unset `int
   0`, which this driver's runtime efun-argument type checker rejects
   (`void|object|object*` expected, got `int`). **Confirmed live**: this
   crashed `questd.lpc`'s `collect_all_quest_information()` → 
   `channeld.lpc`'s `do_channel()` broadcast and `cpud.lpc`'s `create()`
   during ordinary preload, before any player ever connected. Fixed once
   at the shared root: `efun::message(arg, message, target, (objectp
   (exclude) || pointerp(exclude)) ? exclude : ({}))`.

5. **§2 second variant (fixed-width extension-strip slice, `.c`→`.lpc`
   rename fallout) — YES, present in 5 call sites across 3 files, all
   fixed.** `[0..<3]` (correct for stripping a 2-char `.c` extension) was
   never widened for the 4-char `.lpc` extension after the rename; widened
   to `[0..<5]` in:
   - `adm/daemons/eventd.lpc:23` (`event_name = map_array(event_name, (:
     $1[0..<3] :))` after `get_dir(EVENT_DIR + "*.lpc")`) — this one was
     caught live in the very first boot attempt (`call_other() couldn't
     find object '/adm/daemons/event/emei.l'`, the truncated filename
     visible directly in the error).
   - `adm/daemons/storyd.lpc:57` (identical shape, `story_name`).
   - `adm/single/importer.lpc:563` (`item_name[0..<3]`, comment on the
     line literally already says *"要去掉后面的 .c 字样"* — "need to strip
     the trailing `.c`").
   - `adm/npc/luban.lpc:1522` and `:2753` (`DBASE_D->clear_object(...)`
     dbase-key derivation from a `.lpc` filename, both same fixed-width
     slice bug).
   - **Confirmed NOT the same bug** for every other `[0..<2]` occurrence
     found lib-wide (11 hits: `configd.lpc`, `ftpd.lpc`×2, `versiond.lpc`
     ×2, `channeld.lpc`, `npcd.lpc`, `scheme.lpc`×2, `call.lpc`,
     `config.lpc`×3, `combine.lpc`) — spot-checked each; these strip a
     trailing single character (CR/space/last array element) or the
     2-char `.o` save-extension (`__SAVE_EXTENSION__`, unaffected by the
     rename), unrelated to `.lpc`. Also confirmed `importer.lpc:191`'s
     `[0..<3]` is a THIRD, unrelated, correct use (stripping `.o` from a
     player-save directory listing under `login/`, not a `.lpc` listing).

6. **New finding (not previously cataloged): a `get_config()` numeric-index
   mismatch between this mudlib's own `include/runtime_config.h` and this
   driver's real config-slot numbering.** The mudlib's copy defines
   `__MUD_PORT__` as `CFG_INT(0)` with `BASE_CONFIG_INT = 14` (→ absolute
   slot 14), matching some older/different FluffOS build's layout. This
   driver's actual `src/include/runtime_config.h` uses `BASE_CONFIG_INT =
   256` (after `RC_LAST_CONFIG_STR = CFG_STR(255)`), so `__MUD_PORT__` is
   really absolute slot 256 — meaning every `get_config(__MUD_PORT__)` /
   `LOCAL_PORT()` call in this mudlib silently reads the WRONG config
   slot (whatever driver-internal value actually lives at slot 14, a
   `CFG_STR` slot here, not a `CFG_INT` one). **Confirmed the concrete
   symptom**: `adm/daemons/network/messaged.lpc`'s `startup_udp()` calls
   `socket_bind(socket_id, my_port)` where `my_port = LOCAL_PORT() +
   MESSAGE_PORT` ends up evaluating to the STRING `"10"` instead of an
   int port number, throwing `Bad argument 2 to socket_bind() Expected:
   int Got: "10"` and failing the whole object's `create()` (surfaced via
   the `lpcc_check.sh` sweep, not the real boot, since — separately —
   `messaged` was never actually reachable in real play anyway, see next
   item). **Not fixed** (out of scope/low practical impact — see below);
   flagging as a new AGENTS.md-catalog-worthy pattern (`§15aj`-shaped:
   *"a mudlib's own `runtime_config.h` copy can have stale `get_config()`
   slot numbers from a different historical driver build; only trust the
   numbers if a value spot-check via a real interactive test confirms
   they line up, don't assume matching macro NAMES means matching
   NUMBERS across driver versions"*).
   - **Practical impact assessed as low, so not fixed**: the only two
     consumers found (`versiond.lpc`'s inter-station-sync port and
     `messaged.lpc`'s UDP messaging port) are both peripheral,
     non-preloaded, optional network features — neither blocks
     registration or ordinary solo gameplay, and both already fail
     gracefully in their own way (`versiond.lpc` sets its readiness flag
     *before* the broken call per §15ad below; `messaged.lpc` is simply
     never preloaded at all — see next item). Fixing the mudlib's whole
     `runtime_config.h` copy to match this driver's real numbering would
     be the "correct" fix but is broader than this pass's scope; noted
     here for whoever picks up cross-lib `get_config()` audits next.

7. **Separately found (also not fixed, same conclusion): `adm/etc/preload`
   lists `/adm/daemons/messaged` but the real file is
   `/adm/daemons/network/messaged.lpc`** — a path typo/drift, so this
   daemon has never actually been preloaded in this archive at all
   (`master.lpc`'s `preload()` silently no-ops on a `file_size(...) == -1`
   miss). Left as-is deliberately: fixing the path would newly expose the
   `get_config()` bug above (item 6) at every boot, trading one dormant
   bug for a newly-active one, for a peripheral inter-mud-messaging
   feature that isn't part of registration or basic play. Documented here
   rather than silently "fixed" in a way that would make things worse.

8. **New bug (not previously cataloged), found live in `clone/user/user.lpc`
   — the exact `is_killing` shape from AGENTS.md §15b's `nitan_ceshi`
   precedent, independently recurring in this unrelated lib**:
   `accept_kill(object ob) { if (is_killing(ob)) ... }` — `is_killing`
   is declared `varargs int is_killing(string id)` in `feature/attack.lpc`
   and every one of its other ~25 call sites correctly passes
   `ob->query("id")`; this one direct (non-`->`) call passed the object
   itself, a static type mismatch this driver's compiler rejects outright.
   Since `user.lpc` **is the player body class**, this took `make_body()`
   down with it — the account+id got accepted, but character creation
   (`get_char`) then silently failed to ever produce a working player
   body (confirmed: this was the actual blocker once the crypt-handshake
   fix let a real session reach this far). Fixed: `is_killing(ob->query
   ("id"))`. **A second, independent instance of the identical shape**
   found via the `lpcc_check.sh` sweep in `d/city/npc/guidao.lpc`
   (an NPC, "鬼刀王五") — same fix applied.

9. **New bug (not previously cataloged), found via the `lpcc_check.sh`
   sweep, one shared root cause per §8g**: `inherit/misc/quest.lpc`'s
   `set_information(string key, string info)` wrapper (and the matching
   forward declaration in `include/quest.h`) declared its second parameter
   as a bare `string`, but the real underlying implementation it forwards
   to (`questd.lpc`'s `set_information(object, string, mixed info)`) — and
   every one of 7 `clone/quest/*.lpc` call sites (`supply`, `explore`,
   `shen`, `search`, `capture`, `deliver`, `judge`) — actually pass a
   **function closure** (`(: ask_npc :)`, an F_DBASE-style deferred
   evaluated info display), not a string. Widened both the wrapper and
   the header declaration to `mixed info`, resolving all 7 sweep failures
   in one edit.

10. **Three more one-off pre-existing typos found via the sweep** (not
    encoding-conversion fallout, confirmed genuine authoring mistakes):
    - `inherit/condition/damo.lpc`'s `die_reason()`: missing closing quote
      + missing `+` before a trailing string literal (`return name + HIM
      "发作身亡了;` → `return name + HIM + "发作身亡了";`) — the classic
      §10-shaped "swallowed the rest of the file into one malformed
      string" bug, surfacing as a syntax error many lines later. This one
      shared header is `inherit`ed by 3 more files (`damo_luanqi`,
      `damo_shangshen`, `damo_zheyuan`), all fixed by the single edit.
    - `d/village/npc/obj/shoes.lpc`: a `set("icon", "05047");` statement
      was spliced into the middle of an unrelated `set("long", ...)`
      call's argument list, breaking it into a syntax error. Restored as
      two separate statements in the evident original order.
    - `d/baituo/obj/bowl.lpc` (and its exact duplicate,
      `d/baituo/npc/obj/bowl.lpc`): `set_name("海口大碗", "bowl")` passed
      a bare string where `set_name(string name, string *id)` requires an
      *array* of id strings (confirmed: 2850/2852 other `set_name()` call
      sites in the whole lib use the array form correctly) — fixed to
      `set_name("海口大碗", ({ "bowl" }))`.
    - `feature/attribute.lpc`'s `query_per(string arg)`: required a
      `string arg` that is **never read inside the function body at all**,
      and all 6 call sites lib-wide omit it — 5 via `->` (call_other,
      which tolerates the arity mismatch) and one direct call in
      `kungfu/class/generate/girl.lpc` (`per = query_per();`), which hit
      this driver's strict same-object argument-count check and failed to
      compile. Added `varargs` to match the calling convention actually
      used everywhere (same "direct call enforces the signature strictly"
      shape as §15b, just missing-arg instead of wrong-type).

11. **§15e/§13 (unguarded factory-call chain onto possibly-missing
    content) — found and fixed, broadly protective.**
    `inherit/room/room.lpc`'s `make_inventory(string file)` did
    `ob = new(file); ob->set(...)` with no check that `new()` actually
    returned an object; `new()` legitimately returns 0 when `file` points
    at content genuinely absent from this archive (§13: real archive gap,
    not something to fabricate). Root-caused via `d/beijing/gaosheng.lpc`
    referencing `d/beijing/npc/chaboshi.lpc`, which does not exist
    anywhere in the archive (confirmed: 3 of its 4 listed NPCs do exist,
    one doesn't — a genuine partial-content gap, not a systemic one).
    Added an `objectp(ob)` guard inside `make_inventory()` itself, AND
    (this part matters) at its one call site in `reset()`'s `case 1:`
    single-object branch, which called straight into `->is_character()`
    on the (possibly-0) result with no guard at all — the sibling
    `default:` (multi-object) branch already had this guard via
    `objectp()`, so this brings the single-object path up to the same
    standard rather than introducing a new pattern. This is a general
    robustness fix (protects any OTHER room in the lib with a similar
    missing-NPC gap), not just for `gaosheng`.

## Config file notes

- `mudlib directory`/`binary directory`: absolute paths to
  `libs/zjdyzj/work` (both, matching the archive's original
  `d:\hell` pointing the same directory at both roles).
- `port number`: **40074** (per TODO.md's port ledger — 40071-40073
  reserved for archives #77-79's concurrent agents).
- `maximum evaluation cost`: raised from the archive's original `2000000`
  to `5000000000`, matching the convention already used on sibling
  ES-II-lineage libs in this project (the stock value is uncomfortably
  low for this driver's real eval-cost accounting).
- `log directory : /log` resolves relative to the driver's own launch
  CWD (§6), NOT a mudlib-virtual path — created `libs/zjdyzj/
  log/` (sibling of `config.fluffos`) for this. **Separately**, the
  mudlib's OWN in-game `LOG_DIR = "/log/"` constant (used by `log_file()`/
  `write_file()` calls in LPC code) IS a mudlib-virtual path, resolving
  under `mudlib directory` (i.e. `work/log/`) — these are two genuinely
  different directories that happen to share a name; both needed
  creating. Also created `work/log/nosave/` (§15ah pattern — dozens of
  `log_file("nosave/...", ...)` call sites, including
  `nosave/register`/`nosave/security`/`nosave/logon`, none of which had a
  destination directory in the raw archive), `work/binaries/` (the
  configured `save binaries directory`), and `work/adm/tmp/` (the
  configured `swap file`'s parent directory).
- A duplicate, stale `global include file : <global.h>` directive
  (missing the `s` — no such file exists, only `globals.h`) appears later
  in the same config file, inside the "not currently implemented" section.
  **Confirmed harmless and left as-is**: `read_config()`'s
  `scan_config_line()` takes the FIRST matching line for any directive
  and never re-reads it (verified in `~/src/fluffos/src/base/internal/
  rc.cc`), so the correct earlier `<globals.h>` directive always wins;
  this stale second line is permanently dead, not a real risk.

## Checked, confirmed NOT applicable (per the task's proactive checklist)

- **§4** (master.lpc lazy security-daemon `load_object`-during-compile
  recursion): `master.lpc`'s `valid_read`/`valid_write` only ever do
  `find_object(SECURITY_D)` (never a lazy `load_object()`), degrading to
  a safe default (deny-write / allow-read) if not found. No recursion
  risk, no fix needed.
- **§7** (missing `get_root_uid()`/`get_bb_uid()`): both present in
  `master.lpc` already.
- **§14** (`valid_override` 2-arg vs 3-arg): `master.lpc`'s
  `valid_override(file, name)` already has an explicit special-case for
  `name == "destruct"` allowing any file under `/adm/simul_efun/` (exactly
  covering the `object.lpc`-fragment-inside-`simul_efun.lpc` case §14
  warns about) — this master is more mature than most in this project's
  catalog on this specific point; no fix needed.
- **§8d/§15o** (`get_include_path()` missing): `master.lpc` has no
  `get_include_path()` apply at all, but `convert_lib.sh`'s automated pass
  already converted every genuinely-local `<x.h>` angle-bracket include
  (14 of them) to quoted `"x.h"` form, which resolves against the
  including file's own directory unconditionally (no VM-context/master-
  apply dependency at all, unlike the angle-bracket path). Since the
  global `<globals.h>` (and everything else reached only via the
  driver's normal `include directories : /include` config default)
  doesn't need a local-directory lookup, `init_include_path()`'s fallback
  to the config's own `inc_list` when `get_include_path()` isn't defined
  is sufficient here. Confirmed via a clean boot + full interactive test
  with zero `Cannot #include` errors anywhere.
- **§15l** (master.lpc `create()` destructing `SIMUL_EFUN_OB`):
  `create()` is a bare one-liner (`write("master: loaded
  successfully.\n");`), no destruct/reload dance at all.
- **§15n** (custom securityd `valid_read` ACL blocking driver's own
  compile-time `load_object`/`include`): `securityd.lpc`'s real
  `default_exclude_read`/`default_exclude_write` tables never list
  `"(player)"` status in ANY entry (only `(wizard)`/`(arch)`/`(admin)`
  are ever excluded from anything) — an unauthenticated connection's
  default `(player)` status is never denied by this table at all, so the
  §15n failure mode (ordinary player status blocked from `/adm`/`/cmds`
  mid-connection) cannot occur here regardless of `func` value. Confirmed
  by reading the actual ACL data, not inferred.
- **§8e** (`tail()` non-efun): zero occurrences anywhere in the lib.
- **§8f** (`TYPE * a, b;` forgotten-star): the pattern (`object *obs, me;`
  etc, 46 hits) recurs throughout, but spot-checked several — in every
  case the un-starred trailing name really is later used as a genuine
  scalar (`me = this_player();` etc.), not assigned an array anywhere.
  This is intentional style (declare related vars together), not the
  Dead Souls "author actually wanted both as arrays" bug. No fix needed.
- **§15p** (DNS/intermud daemon in preload): `adm/etc/preload` DOES list
  `/adm/daemons/network/dns_master` — **removed** proactively per
  standing policy, before the first boot attempt.
- **§15ab-2** (DNS/intermud calls inlined outside preload even when
  excluded from it): grepped for direct `DNS_MASTER`/`dns_master` callers
  beyond preload — found only in `cmds/usr/who.lpc`, `cmds/usr/
  mudlist.lpc`, `cmds/adm/shutdown.lpc`, `cmds/adm/telnet.lpc`,
  `cmds/arch/reboot.lpc` — all interactive admin/utility commands never
  exercised by registration or the `look`/`score` test, not `logind.lpc`
  itself. Not fixed (out of scope, never reached by the required test).
- **§15v** (`LONELY_IMPROVED`/`DOING_IMPROVED`-gated dead efun calls):
  `DOING_IMPROVED` is referenced in `#ifdef DOING_IMPROVED`/`#else` guards
  in `sort_string`/`sort_msg`/`file_lines`/`binary_valid`, but is **never
  `#define`d anywhere** in this archive — confirmed every one of these
  compiles its pure-LPC `#else` fallback, already correct and tested by
  the original author. No missing-efun gap at all.
- **§15z** (`#define nosave static` shim colliding with the `static`→
  `nosave` blanket sed): no such compatibility shim found anywhere.
- **§15u** (dormant destructive "phone-home" anti-piracy function):
  grepped `securityd.lpc`/`master.lpc` for suspicious mass-delete/
  shutdown-gated functions; none found.
- **§15r** (`check_config.lpc`-style fatal driver-assumption self-check
  inherited into master/simul_efun): no such file exists in this archive.
- **§15x** (hardcoded `MUD_PORT` mismatch): `include/getconfig.h`'s
  `LOCAL_PORT()` dynamically queries `get_config(__MUD_PORT__)` rather
  than a baked-in literal — architecturally correct (this is, ironically,
  exactly the mechanism that turned out to be broken for an unrelated
  reason, see finding #6 above — a numbering mismatch, not a hardcoded
  value).
- **§8g** (N-identical-sweep-failures → one shared root cause): applied
  as methodology throughout the sweep triage above (the `damo.lpc` syntax
  error and the `quest.lpc` `set_information` type both resolved 4 and 7
  failures respectively via one shared-file edit each, not per-file
  patches).
- **§15ag** (`ed_start`/`ed_cmd`/`query_ed_mode`, this driver has
  `__OLD_ED__`): zero occurrences anywhere in the lib (`grep -r
  "ed_start\|ed_cmd\|query_ed_mode"` empty). `feature/edit.lpc` exists but
  uses the real `ed()` efun directly already.
- **§15ah** (missing save-data directory silently aborting a multi-step
  flow): checked every `log_file()`/`write_file()` target directory
  lib-wide against what actually exists on disk — only `/log/nosave/` was
  missing (created, see config notes above); every other target (`/data`,
  `/dump`, `/binaries`, `/log/user/...`) either already existed in the raw
  archive or is created dynamically by `feature/save.lpc`'s
  `assure_file()` call before every `save_object()`.

## Registration-flow test (CRITICAL instruction) — full transcript summary

Ran two complete, independent, single-continuous-connection sessions via
a custom scripted client (`mudclient.py`'s static `--send` list can't
handle this lib's dynamic crypt-challenge — wrote a small one-off Python
client that computes the correct `crypt()` response from the server's own
banner using the standard-library `crypt` module, which matches this
driver's classic-DES-crypt path for a non-`$`-prefixed 2-char salt):

1. Connect → receive `ver1.0,<random-$6$-hash>` → compute and send
   `crypt(ZJKEY, str[2..3])` → **"版本验证成功" (version verified)**.
2. Send `id║password║crypt(ZJKEY,id)+crypt(ZJKEY,password)║email`
   (new account, e.g. `xialiu99║test12345║...║test@example.com`) →
   accepted, advances to character creation (`0008` code).
3. Send `gender║avatar-id║name` with a **real Chinese name**
   (`男性║1║夏流`, then separately `男性║1║秦风` on the first run) →
   accepted, `make_body()` succeeds, **"你连线进入了地狱无门"** ("you have
   connected into 地狱无门") — confirmed landed in the actual game world
   (starting room "世外桃源"/Peach Blossom Spring, full room description,
   exit list, two NPCs present, all rendered correctly in UTF-8).
4. Sent `look` → full real room re-render (description, exits with
   flavor text, NPC/object list) — **confirmed working**.
5. Sent `score` → `"还没有出生呐，察看什么？"` ("You haven't even been born
   yet, what are you looking at?") — **this is correct, in-character
   behavior, not an error**: the welcome banner explicitly tells new
   players they must first walk through the cardinal-direction "投胎"
   (reincarnation) minigame at the starting room before their character
   is fully "born" with real stats; `score` correctly refuses until that
   completes. Confirmed intentional by reading the actual welcome text
   and room exits (`west:阴险奸诈` / `east:光明磊落` / `north:心狠手辣` /
   `south:狡黠多变` — four different "innate quality" paths).
6. Sent `quit` → clean disconnect, `"欢迎下次再来！"` ("welcome back next
   time").
7. Confirmed via `data/login/x/xialiu99.o` and `data/user/x/xialiu99.o`
   (and the `q/qinfeng1.o` pair from the first run) that real save files
   were written to the correctly-sharded directories.
8. `debug.log` across both full sessions shows **zero** new runtime
   errors beyond the two already-understood, already-cataloged benign
   `Bad argument 2 to socket_bind()` lines from `versiond.lpc` (§15ad
   pattern — `version_ok` is already set synchronously before the failing
   async socket call, confirmed by reading the code, not just observing
   the harmless symptom).

This satisfies the standing policy (§15ae) of testing at least one real
post-login command after registration — done with two (`look`, `score`),
both producing correct, real, in-character output.

## `lpcc_check.sh` sweep results

7302 files total. **7289 PASS, 13 FAIL** (all 13 triaged and confirmed
non-bugs, not fixed — see `lpcc_fail.log` for full detail):

- **11 files under `adm/daemons/story/*.lpc`** (`anthem`, `bizhen`,
  `jiuyang`, `sanfenjian`, `shenzhao`, `master`, `pangtong`, `baguadao`,
  `huanyin`, `jiuzhuan`, `mengzi`) — each is a one-shot "legendary NPC
  story" scenario whose `create()` calls `select_character()`, which
  filters `all_interactive()` for an eligible live player and
  **deliberately self-destructs** (`destruct(this_object())`) if none is
  found — completely expected in a bare `lpcc` compile-check context (no
  players ever connected), confirmed by reading the code (§6b category:
  "fails only because of missing real-world context, not a real bug").
- **`adm/single/importer.lpc`** — same shape: `create()` explicitly
  requires `this_player(1)` (a privileged/wizard-driven interactive
  invocation) and self-destructs otherwise. Confirmed by reading the code.
- **`adm/daemons/network/messaged.lpc`** — the `get_config()`
  index-mismatch bug (finding #6 above); genuinely fails to load when
  directly compiled+created, but never reached in real play anyway (wrong
  preload path, finding #7). Deliberately left unfixed, documented above.

All other 7289 files compile clean.

## Summary of what was confirmed working vs. left as known issues

**Working, verified**: encoding (zero stragglers after the standard
conversion + straggler re-scan), `.c`→`.lpc` rename + all `".c"` reference
fixes (zero uppercase `.C` files either), boot (zero fatal errors),
Chinese-name registration end-to-end, character creation, entering the
game world, `look`, `score`, `quit`, save-file persistence, the
`command_hook`/`add_action` dispatch chain for ordinary play.

**Known, documented, deliberately not fixed** (peripheral, non-blocking):
the `get_config()` runtime-config-index mismatch (affects only
`versiond`'s inter-station-sync port and `messaged`'s UDP port, both
optional network features); `messaged`'s wrong preload path (leaving it
undiscovered is currently the safer state given the above); the two
unwired "指间MUD"/Tomud client-protocol headers (harmless dead code,
documented for context); DNS/intermud calls reachable only from
`who`/`mudlist`/`shutdown`/`telnet`/`reboot` admin commands (never
exercised by the required test, not touched).

## Re-verification pass: driver rebuild + formatter + WASM (2026-07)

- **LPC formatter** applied to all `.lpc` under `work/` (7,302 total,
  7,272 written, 25 unchanged, 5 self-checked errors left untouched).
  Spot-checked `adm/daemons/logind.lpc`'s `crypt(ZJKEY, "zj")` fix
  post-format — intact, unchanged in substance.
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`): clean boot, only the
  pre-existing benign `versiond.lpc`/`socket_bind()` line in
  `debug.log`. Since `mudclient.py`'s static `--send` queue can't
  compute the dynamic crypt-challenge response, wrote a small one-off
  Python client (`crypt` stdlib module) that: connects, parses
  `ver1.0,<challenge>` from the banner, computes `crypt(ZJKEY,
  challenge[2:4])` and sends it back, then sends the `id║password║
  crypt(ZJKEY,id)+crypt(ZJKEY,password)║email` account line and a
  `gender║avatar║name` character-creation line. Verified end-to-end with
  a fresh id/real Chinese name (`zjretest`/秦岭): "版本验证成功" (version
  verified) → account accepted → character created → landed in 世外桃源
  (地狱无门), `look`/`score` (correct pre-投胎 message)/`quit` all
  produced correct output. **Confirmed the `crypt(ZJKEY, "zj")` fix is
  fully deterministic run-to-run** (the challenge string and its
  `[2:4]` salt slice were byte-identical across every connection tested
  in this pass, as expected now that the explicit 2-char salt replaced
  the old `crypt(key, 0)` call) — this determinism is what makes a
  scripted test client (or a real client that recomputes the response
  once) viable at all.
- **WASM test**: attempted via `scripts/wasm_client.js` with the
  crypt-response precomputed as a literal `--send` line (viable exactly
  *because* the challenge is now deterministic — no need for a reactive
  client). **Never reached the crypt banner at all** — root cause is the
  SAME test-harness gap identified on `zjdyaryl` in this
  same batch, an independent occurrence: `clone/user/login.lpc`'s
  `logon()` unconditionally calls `log_file("nosave/logon", ...)`
  (`log/nosave/` — note this is this lib's post-`static`→`nosave`-sed
  directory name, a REAL directory shipped in `work/log/nosave/` on
  disk, confirmed) as its very first statement, no `catch()`.
  `scripts/wasm_client.js`'s `copyDir()` only recreates the bare `log/`
  directory itself in the in-memory FS, not real subdirectories like
  `log/nosave/`/`log/static/`/`log/user/` — so this throws `Wrong
  permissions for opening file /log/nosave/logon for append. "No such
  file or directory"` uncaught, and `new_conn_handler()` disconnects the
  connection before `logon()` ever writes the `ver1.0,...` challenge.
  Already flagged in `zjdyaryl`'s NOTES.md for the
  orchestrating session to fix in the shared harness (not done here
  myself, since it's a script other agents' concurrent sessions use).
  Separately: this lib's `logon()` also has an unguarded
  `VERSION_D->is_version_ok()` call later in the function (same shape as
  `zhonghua2`/`zhongjidiyu` in this batch), which — given this lib's
  `versiond.lpc` also uses raw `socket_*()` calls unavailable under WASM
  — would likely block login a SECOND time even after a harness fix for
  the `log/nosave/` gap. Both are WASM-sandbox/harness artifacts, not
  mudlib bugs (native completes the full crypt-handshake + registration
  + gameplay flow cleanly, verified above) — not patched, per the
  standing instruction for WASM-mode limitations.
  (The VERSION_D gate is now patched — see the 2026-07 pass below.)

## WASM-enablement pass (2026-07): loopback gates + admin seeding

Standard pass per AGENTS.md §1.3b/§1.3c/§1.3e/§1.5:

- `adm/daemons/band.lpc`: new `is_local_site(site)` helper; `is_banned()`
  returns 0 for loopback/empty/malformed input. (Note: `logon()` passes
  `query_ip_name()`, not the number — a resolved hostname also passes
  the local check; acceptable for the WASM-first use case.)
- `adm/daemons/logind.lpc`:
  - `get_id()` (~line 262): `VERSION_D->is_version_ok()` gate guarded
    with `find_object(VERSION_D)` (absent ⇒ version ok — the WASM
    sockets-less case). Note this legacy `get_id` path isn't part of the
    zjmud `get_user` flow, but the guard is kept for completeness.
  - `check_ok()` (~line 414): `MESSAGE_D->find_chatter()` wrapped in
    `catch()` — same first-login-killer shape as the sibling hell libs
    (messaged's `create()` can throw; under WASM it fails to compile
    entirely and the call itself throws).
- `adm/daemons/network/messaged.lpc` `create()`: `catch(startup_udp())`
  — the §15aj get_config port bug makes `socket_bind()` throw a string-
  type error if this daemon is ever loaded (it IS lazily loaded by
  `check_ok()` despite the broken preload path); now degrades
  gracefully instead of aborting the login that triggered the load.
- `adm/daemons/closed.lpc` `heart_beat()` / `adm/daemons/questd.lpc`
  `start_all_quest()`: `find_object(VERSION_D)` guards (both preloaded).
- No uptime()/anti-flood/per-IP gates exist in this lib's zjmud login
  flow — nothing else to bypass. The crypt version-handshake itself is
  already deterministic since the earlier `crypt(ZJKEY, "zj")` fix and
  is left in place (it is the edition's defining feature; scripted
  clients can compute the reply — see `/tmp`-style client recipe in the
  transcript sections above, ZJKEY `123456789abcd`, reply
  `crypt(ZJKEY, challenge[2..3])`).
- Admin seeded: `fluffos` / `Mud@2026` / 浮云, rank `(admin)` via
  `adm/etc/wizlist`. Registered via the REAL zjmud flow (handshake →
  `fluffos║Mud@2026║crypt(ZJKEY,"fluffos")+crypt(ZJKEY,"Mud@2026")║
  fluffos@test.com` → `男性║1║浮云`). Verified after wizlist+restart:
  first login shows 目前权限：(admin) and
  `update /d/register/entry.lpc` → 成功.
- **Security note (pre-existing design, documented not changed)**: this
  edition performs NO server-side password verification on existing
  accounts — `get_user()` restores the login save and then OVERWRITES
  the stored password with whatever the client sent (verified
  empirically: a wrong-password login attempt succeeds). Account
  authentication was evidently delegated to the 指间MUD platform
  upstream. Anyone who can speak the ZJKEY handshake can log into any
  account, including `fluffos` — flagged in the README's hosting
  warning.
- Retest: fresh registration (`regtest`/秦风) end-to-end into 世外桃源,
  look/score(pre-投胎 message)/quit correct; test saves removed. Final
  debug.log: only the two known socket_bind lines (versiond uncaught ×1,
  messaged now-caught ×1).

## WASM long-sit boot-watch pass (2026-07)

200s `scripts/wasm_boot_watch.sh` sit surfaced one genuinely new,
previously-undocumented finding beyond the already-known
`ftpd.lpc`/`dns_master.lpc`/`versiond.lpc` sockets-absent preload class
(§1.3c, caught/cosmetic): `inherit/item/combined.lpc`'s `private void
destruct_me()`, self-invoked via `call_out("destruct_me", 0)` when a
money stack's `amount` hits 0 — denied with "apply() with insufficient
permission ... function: destruct_me, origin: internal, needs: private,
has: hidden" on `clone/money/silver#581`. Same root cause as this lib's
own already-fixed `command_hook` class (AGENTS.md §8.3a: `private`
demotes to DECL_HIDDEN once inherited; a self-invocation via
`call_out`/`command()` needs DECL_PRIVATE and gets silently denied) —
spent-down money stacks were never actually self-destructing (harmless
but permanent per-object leak). Fixed: dropped `private`, kept the
function otherwise unchanged. Same fix ported to siblings `zhonghua2`
(where the identical bug also fired live), `zhongjidiyu`,
`zjdyaryl` (latent there, didn't fire in their sits).
Retest via a small one-off Python client (`crypt`-module challenge/
response, same shape as the original verification pass) confirmed
registration → look → score → quit still clean; a fresh 200s WASM
re-sit confirmed the "insufficient permission" line no longer appears.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一核心加上指间mud手机协议。这是这个家族里唯一一个反映真实、仍然生效的注意事项而不是过时状态的 'limited'（和已经在本轮修正为 playable 的手足档案 zhongjidiyu（052）/zjdyaryl（053）不同）：这个移植版本的 logind.lpc 把每一个连线都挡在一个为'指间'（手机）客户端设计的自定义基于 crypt 的客户端版本握手之后，而不是普通的 telnet/网页终端会话。服务器发送 'ver1.0,<crypt(ZJKEY,"zj")>'，期待客户端回复 crypt(ZJKEY, <那段字符串>[2..3])——本轮已确认这个握手过程确实是完全确定性的、可以通过的（这个驱动的 crypt() 和标准 libc 的 DES-crypt 完全一致，已用 Python 的 crypt 模块重现服务器自己的挑战值并计算出一个服务器能接受的回复，'版本验证成功'来验证），之后还有第二个自定义协议步骤：一整行输入，组合了 id║密码║crypt(ZJKEY,id)+crypt(ZJKEY,密码)║电子邮件（║ 是 U+2551）。手动完成这两个步骤能干净地到达完整游戏流程（管理员登录已确认，'目前权限：(admin)'，quit 正常）——但这个项目提供的通用 WASM 网页终端（一个普通的类 telnet 界面）无法自动计算出这些值，所以普通访客点进这份档案的页面，没有外部工具是过不了第一个提示的。另外还修复了和手足档案相同的一个真实 bug：clone/user/login.lpc 的 query_save_file() 空字符串保护（既检查 id == ""，也检查 !stringp(id)），阻止第一次连线时的 %c/sprintf 崩溃。

## 深度功能测试（§10.7，2026-08-04）

此前的会话只做到"注册流程"（look/score 两条真实指令），本轮在此基础上
真正走完了完整流程：创角后的"投胎"仪式、地图移动、商店、战斗、死亡、
以及无人打扰的完整复活序列。原生 driver（端口 40074）。

**测试工具**：由于这份档案自创的手机客户端协议（见上一节），
`mudclient.py` 无法直接用，本轮写了一个一次性 Python 客户端（用标准库
`crypt` 模块复现驱动自己的 `crypt(ZJKEY, salt)` DES-crypt 挑战/应答），
能完整驱动"版本验证→账号注册/登录→创角→游戏内指令"的连续会话；后续
针对死亡复活的等待验证则单开一个只做登录、然后静默等待的连接，避免任
何指令打断 `call_out` 链。

**主动检查（对照 AGENTS.md 已归档的 bug 类）**：
- `adm/daemons/logind.lpc:872` 的 `user->query("age") == 14` 判断
  ——**确认不是 §8.9 的错误对象变体**：查询对象是 `user`（角色的持久
  存档对象），且紧跟在 `user->setup();` 之后，和已归档的正确写法完全
  一致，不是判断连线对象 `ob`。食物/饮水会在这一刻正确初始化。
- 全文搜索 `printf(` ——`logind.lpc` 及 `d/register/` 全部注册/创角
  文件均无遗留调试输出，没有 §7.34 的实例。
- `feature/command.lpc:40` 的 `command_hook` 已经是
  `nomask int command_hook(...)`（代码里的注释显示这是此前某一轮已经
  修复过的），本轮确认依然干净。
- `adm/daemons/logind.lpc:418` 的 `MESSAGE_D->find_chatter(...)` 调用
  已经包在 `catch()` 里，不是未加防护的裸调用。

**新发现并修复：第 11 例 §7.68 复活软锁死**（`d/death/npc/
{wgargoyle,bgargoyle}.lpc`，白无常/黑无常）——`DEATH_ROOM`
（`/d/death/gate`）摆着 wgargoyle，其 `north` 出口 `/d/death/gateway`
摆着 bgargoyle，两者都可达。两个文件的 `death_stage()` 都是
`if (!ob || !present(ob)) return;`——玩家在复活序列进行中如果暂时不在
场（例如短暂 net-dead），会被永久放弃，鬼魂永远卡在鬼门关。已按标准
修法拆分为"彻底缺失（!ob）→放弃"与"暂时不在场（!present）→ 5 秒后重
试"两种情况，两个文件都改了。

**完整游玩记录**：
1. 用真实中文名"沈牧"（id `shenmu`）完成账号注册（含邮箱）和创角
   （男性/沈牧），落地"世外桃源"，此时 `score` 正确提示"还没有出生
   呐"（游戏内合理行为，不是 bug——档案还没走完投胎仪式）。
2. 探索四个方向房间确认"阴险奸诈/光明磊落/心狠手辣/狡黠多变"四种天性
   任你选（这是这份档案自己设计的性格/命运系统，`d/register/
   yanluodian.lpc` 里"偏属→洗点→转生"的三步流程），进入"阴险狡诈"房
   间后 `out` 到"阎罗殿"，依次 `pianshu msx`（选择猛士型）、`wash`
   （在忘忧池随机洗出四项天赋：膂力24/悟性17/根骨19/身法20）、
   `born 中原人氏`，成功"投胎"落地"悦来客栈"，获得布衣/牛皮靴，
   `score` 此时正确显示完整数值面板。
3. 移动测试：悦来客栈→南阳城→迎宾楼（`list` 正确显示三样商品和价
   格）→尝试 `buy baozi from xiao er`，因为没有铜钱被店小二正确拒绝
   （"穷光蛋，一边呆着去！"——内容行为，不是 bug）→大驿道→汝州城，
   沿途场景描述、出口列表、NPC 列表均正常渲染。
4. 战斗测试：`wimpy 0` 后 `kill xiao fan`（南阳城的小贩），完整回合制
   拳脚对轰后成功将其打死，期间技能"基本拳脚/基本招架/基本轻功"多次
   熟练度提升提示正常触发；随后在汝州城 `kill wu jiang`（武将，带钢
   剑），两回合内被连续刺伤/砍伤直接打死（`wimpy 0` 生效，没有自动
   逃跑），角色武力值太低是内容/数值现象，不是 bug。
5. 死亡→复活：死亡后正确落地"鬼门关"（`DEATH_ROOM`），白无常在场。
   **在完全不打断的情况下**（关闭连线后等待、再用另一条静默连接确认
   最终状态）验证：`death_stage()` 五段对话全部走完，`reincarnate()`
   成功，角色最终落地 `/d/city/guangchang`（"泥潭广场"），`score`
   显示"你总共到黑白无常那里串门一次"，`quit` 正常退出。**这正是修复
   后应有的行为**——如果没有这次的拆分修复，任何一次连线中断都会让角
   色永久卡在鬼门关。
6. `mail` 指令确认"此服务已经暂停"——功能性下线，属内容/运营决定，不
   是 bug；未发现玩家可用的公共留言板入口（`cmds/arch/board.lpc` 是巫
   师级指令，`inherit/misc/bboard` 没有被任何 `d/` 房间挂载），本轮未
   深入排查这是设计如此还是遗漏，留作后续观察，不视为确认的 bug。

**结果**：整个测试会话（含两次死亡复活循环）`debug.log` 全程为空，没
有任何 `error:`/`Bad argument`/`No program`/`Too deep recursion` 记
录。测试角色存档（`data/{login,user}/s/shenmu.o`）保持未跟踪；两个死
亡 NPC 文件的改动已用 formatter 校验（`{"errors":0}`）。


## 更正（2026-08-05）：§7.68 复活软锁"修复"已撤销

上面提到的"鬼魂离开/不在场时被永久放弃复活流程"曾被当作 AGENTS.md
§7.68 记录的一类 bug 修复（把单次判定改成每 5 秒重试）。经用户指出并
重新审视：这更可能是**有意的游戏设计**，不是 bug——大多数这类档案里
鬼魂根本无法自行移动，所以"不在场"要么从未真正发生，要么是"离开去
在阴间游荡，想回来时再走回这个房间、流程会通过 init() 重新从头开始"
这种有意为之的宽松机制，而不是需要强制追上玩家的错误。强行重试还可能
引入新问题：如果鬼魂之后又走回这个房间，旧的重试和 init() 重新触发的
新一轮流程可能同时运行，导致对话重叠错乱。已把这处改动撤销，恢复成
原始的 `if (!ob || !present(ob)) return;` 单次判定写法（`bmxkx2001`
除外——那份档案里这确实是一个真实存在、经过实际复现验证的 bug：鬼魂
本身完全无法移动，是另一个不相关的 NPC 强行把鬼魂拖走导致的）。详见
AGENTS.md §7.68 顶部的撤销说明。
