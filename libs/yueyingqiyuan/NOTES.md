# yueyingqiyuan — 月影奇缘 (Moon Shadow Wondrous Fate)

Archive: `月影奇缘.rar` (#54). Port: 40048. Status: **done** (boots clean,
full registration flow verified end-to-end into the actual game world).

## What this is

Config's own `name :` field confirms the self-identified title: `★月影奇缘★`
("Moon Shadow Wondrous Fate" / "Moon Love Story", per the lib's own English
banner text). Raw archive root is nested at `raw/yy/yueying/` (the top-level
`yy/` wraps the real mudlib dir `yueying/`); `config.cfg`'s comment says
`# name of this mud xyj 2000` and the live banner shows `世纪西游 之 月影奇缘`
/ `A Journey to the West` / `Moon Love Story` — a 西游记 (Journey to the
West)-themed reskin, credited "XYJ 2000, Copyright 2000-2001 by Moon lOVE
Story", with wizard names 巫师协会 crediting "stone"/"fix". The raw archive
also ships a generic `小熊泥苑.txt` readme (the same "小熊泥苑" hosting-site
readme text seen bundled with `shujiantianxia`, archive #36) — same
distribution site, unrelated codebase, not a lineage signal by itself
(consistent with the project's repeated "similar branding ≠ shared lineage"
finding).

**Lineage**: `adm/obj/master.c`'s own header comment says `// for ES II
mudlib` / `// original from Lil` / `// rewritten by Annihilator` — the same
"ES II" family already seen in `es1_win`/`esI`/`xkx2001`/`rzrmud`/`xo`/
`xo_final`/`beimeixiakexing2001`. Layout is `adm/obj/{master,simul_efun}`
(not `adm/single/` like the Century family, not `adm/obj` overlapping with
custom-ACL `securityd.lpc` like `shujian2008`). `feature/dbase.lpc` (the
`F_DBASE`-equivalent) implements real local `set`/`query`/`delete`/`add`
functions (inherited by `std/char.lpc` etc.) — the architecturally-correct
pattern, confirmed NOT the nitan-family bare-simul_efun dbase bug (§15).
~11,612 raw files, 9,498 renamed to `.lpc`.

## Fixes applied

1. **AGENTS.md §15h (is_chinese / check_legal_name GBK byte-range bug)** —
   confirmed present, fixed both sites:
   - `adm/simul_efun/chinese.lpc`'s `is_chinese(str)`: was
     `str[i] < 161 || str[i] == 255` plus an `i%2==0`-gated secondary GBK
     lead-byte range check, and `strlen(str) < 2` as the minimum-length
     gate. Replaced with a single CJK Unified Ideographs codepoint range
     check per character (`str[i] < 0x4e00 || str[i] > 0x9fff`) and
     `strlen(str) < 1` (character-count equivalent of "at least 1 full
     GBK char").
   - `adm/daemons/logind.lpc`'s `check_legal_name(name)`: bound
     `strlen(name) < 2 || strlen(name) > 12` (byte counts, message says
     "一到六个中文字" = 1-6 Chinese characters) halved to `< 1 || > 6`;
     the sliding-window loop's `i%2==0 && !is_chinese(name[i..<0])` gate
     had the `i%2==0 &&` dropped (every index is already one character
     under UTF-8 — harmless redundancy with the fixed `is_chinese()`, not
     a behavior change, per the catalog's documented pattern).
2. **AGENTS.md §15p (proactive DNS/intermud daemon preload exclusion)** —
   `/adm/daemons/network/dns_master` was present in `adm/etc/preload`;
   removed it before the first boot attempt. Confirmed via source read
   that nothing else in the registration path references it. Driver
   booted in well under 20 seconds with no hang.
3. **New: `message.lpc`'s `tell_room()` passes a raw `int 0` to
   `message()`'s 4th (`exclude`) argument when called with only 2 args**
   (the overwhelmingly common call shape — ~578 call sites in this lib use
   the 2-arg form). This driver's `message()` efun 4th arg is typed
   `void | object | object *` (see `src/packages/core/core.spec`) and
   rejects a plain `int 0` at runtime: `Bad argument 4 to EFUN message()
   Expected: object, array, Got: int(0)`. Found live on first boot — a
   preloaded room (`/d/wusheng/room1.lpc`)'s ambient `sounding()` heartbeat
   called `tell_room(where, msg)` (2-arg) every ~10s and errored every
   time. Fixed at the single shared root cause (`adm/simul_efun/
   message.lpc`'s `tell_room`), not per call-site: `exclude || ({})`.
   This is a genuinely new bug class for the catalog — the "ES II"
   lineage's own `message.lpc` implementation, not previously exercised by
   a boot that had a preloaded ambient-sound room reaching this exact
   code path this early.
4. **AGENTS.md §14 (valid_override 2-arg → 3-arg)** — `master.lpc`'s
   `valid_override(file, name)` only checked `file == SIMUL_EFUN_OB`, but
   `adm/simul_efun/object.lpc` (one of several fragments `#include`d into
   `adm/obj/simul_efun.lpc`) does `efun::destruct(ob)` — for a fragment,
   `file` is the physical file, never equal to `SIMUL_EFUN_OB` itself.
   Upgraded to the 3-arg signature and also check `main_file ==
   SIMUL_EFUN_OB || main_file == MASTER_OB`. Per the catalog's own caveat,
   this may never actually surface on a real boot (nothing in debug.log
   suggests it did here either) — applied proactively since it's free and
   correct, matching the documented pattern exactly.

## Confirmed NOT needed (checked by reading the actual source, not assumed)

- **§4 (master.lpc lazy `load_object(SECURITY_D)` inside `valid_read`/
  `valid_write` recursion)**: `master.lpc`'s `valid_write`/`valid_read`
  just do `if (ob = find_object(SECURITY_D)) return ...; return 0/1;` —
  no lazy `load_object()` call at all, so no recursion-on-failed-load
  possible. Not needed.
- **§7 (missing `get_root_uid`/`get_bb_uid`)**: both already implemented
  in `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`. Not needed.
- **§8c (`this_player()`-override footgun in `valid_read`/`valid_write`)**:
  `securityd.lpc` (the real ACL here, `adm/daemons/securityd.lpc`) never
  does `if (this_player()) user = this_player();` — it takes `user` as
  given throughout. Not needed.
- **§8d (`<local.h>` next to its own file, needs `get_include_path()`)**:
  every `#include <x.h>` in this lib resolves to a file that actually
  lives in the global `include/` directory (`weapon.h`, `armor.h`,
  `name.h`, etc. all confirmed present under `include/`), not a
  same-directory "flavor" header. `convert_lib.sh`'s automated
  local-angle-bracket-to-quotes pass also converted 308 genuinely-local
  `#include <x.lpc>`-style references to quotes as a safety net. Not
  needed as a `master.lpc` fix.
- **§15n/§15o (custom securityd ACL blocking driver's own compile-time
  reads / missing get_include_path for mid-connection compiles)**: read
  `securityd.lpc`'s `valid_read` in full — its very first check is
  `if (func != "read_file" && func != "file_size" && func != "stat" &&
  func != "read_bytes" && func != "tail" && func != "ed_start") return 1;`
  — i.e. `load_object`/`recompile_object`/`include` (and everything else)
  are auto-allowed BEFORE the ACL tables are even consulted. This
  architecture is already immune to the §15n class of bug. Not needed.
- **§15l (master.lpc `create()` destructing `SIMUL_EFUN_OB`)**:
  `master.lpc create()` is just `write("master: loaded successfully.\n");`
  — no destruct/reload trick. Not needed.
- **§8e (`tail()` missing efun)**: only one call site,
  `cmds/wiz/tail.lpc` (an unused admin command, not on any preload/login
  path) — left as-is per the catalog's own precedent (dead code, not
  worth reimplementing).
- **§3 (`static` on functions)**: only 3 genuine function-level
  occurrences in the whole lib (`master.lpc`'s `crash()`, `cmds/wiz/
  data.lpc`'s `sort_keys()`/`filter_props()`) — all mechanically fixed by
  `convert_lib.sh`'s blanket `\bstatic\b`→`nosave` pass (82 total
  replacements counting variable-level `static` too). Verified no leftover
  function-level `static` remains.
- **§8f (`TYPE * a, b;` array-modifier-doesn't-propagate)**: zero matches
  for the pattern — this is a Dead-Souls/English-lineage-specific habit,
  not present here. Not needed.
- **§15f (bare `array` type declaration)**: zero matches. Not needed.
- **§15r (check_config.lpc driver-version self-check)**: no
  `check_config`/`checkconfig`/`verify_driver`-shaped file anywhere in the
  archive. Not needed.

## Known, non-blocking issues (not fixed — documented per AGENTS.md §12/§13/§15m precedent)

- **Corrupted pre-existing save data**: `data/emoted.o` (the emote-phrase
  daemon's save file) throws `restore_object(): Illegal mapping format
  while restoring emote.` on every boot. Confirmed NOT an artifact of our
  UTF-8 conversion (the file was not flagged "LOSSY" by `convert_lib.sh`,
  and a raw-byte scan shows a genuine unbalanced-parenthesis-shaped
  truncation deep in the mapping literal, in the original archive). This
  is the exact same `emoted.o` corruption pattern AGENTS.md's §1 already
  documents as a known example from the pilot lib. `master.lpc`'s
  `preload()` wraps every preload target in `catch()`, so this is fully
  non-fatal — the error prints once at boot and the emote daemon simply
  starts with an empty phrase table. `emoted` is not referenced anywhere
  in the login/registration path, so it has zero effect on character
  creation.
- **One corrupted room-NPC content file**: `d/qujing/start/24/12.lpc`
  (raw `12.c`) ends mid-statement in raw binary garbage in the ORIGINAL
  archive (confirmed via `xxd` on the pre-conversion file — the last
  ~15 bytes are non-text binary, truncating a `carry_object(...)` call
  with no closing paren/semicolon/brace). Not `#include`d, inherited, or
  preloaded — a real, pre-existing one-off content gap (§12-style), not
  something to fabricate a fix for.
- **Intermittent driver crash observed twice during interactive testing,
  not reliably reproduced**: during the first ~10 minutes of manual
  `mudclient.py` testing, the driver process died twice with **zero**
  trace anywhere (no `Segmentation fault`/`Fatal` line in `debug.log`, no
  entry in `dmesg`/`journalctl -k`, master.lpc's own `crash()` apply never
  fired — no `log/static(nosave)/CRASHES` file was ever created). Both
  times followed a connection that answered the post-registration
  "talent/attribute" mini-game (`/d/wiz/init`-driven) with an unusual
  input pattern (repeatedly resending invalid answers to its `[0-3]/[9]`
  menu, or disconnecting right after sending `9` without following up
  with the `y/n` confirmation it then asks for). After enabling
  `ulimit -c unlimited` and restarting, **8+ subsequent full registration
  attempts — including 3 complete, clean runs all the way from `gb`
  through `y`/`look` into an actual game room — never reproduced it
  again**, and no core file was ever produced (the 2 crashes both
  predated the `ulimit` change). Root cause **not confirmed** — flagged
  here as a known, apparently-rare/non-deterministic issue for whoever
  next touches this lib, rather than something fixed. It did not block
  reaching "done" criteria since the flow completes correctly and
  repeatably in the large majority of attempts.
- **Cosmetic side-effect of the blanket `static`→`nosave` conversion**:
  this lib's original code uses a bare English word `static` as a **log
  subdirectory name convention** in dozens of `log_file("static/X", ...)`
  calls (`static/CRASHES`, `static/using`, `static/promotion`, `static/
  give`, `static/SUICIDE`, etc. — completely unrelated to the LPC `static`
  keyword). `convert_lib.sh`'s `\bstatic\b`→`nosave` regex has a word
  boundary on both sides of the string content too (bounded by `/` and
  `"`), so it renamed all of these path strings to `nosave/X` as a side
  effect. This is harmless in practice (`log_file()` just writes wherever
  it's told, self-consistently, across every call site) but worth noting
  for the shared script/catalog: **the `static`→`nosave` fix, as currently
  implemented, is not scoped to code context and will also silently
  rewrite string literals that happen to contain the bare word
  `static`** (not just this lib's `log_file("static/...")` convention —
  any lib that uses "static" as an in-string token is at risk of the same
  cosmetic corruption). Confirmed self-consistent here (no broken
  references), so left as-is.

## Interactive test result — full registration flow

Read `adm/daemons/logind.lpc`'s full `logon()→encoding()→if_young()→
get_id()→get_new_id()→confirm_id()→get_name()→new_password()→
confirm_password()→get_email()→get_gender()→confirm_gift()→enter_world()`
callback chain before scripting the test (per the task's explicit
instruction) — confirmed the shape: a GB/BIG5 encoding prompt (`GB_AND_BIG5`
is `#define`d in `include/mudlib.h`, so this prompt is live, not
compiled-out), then a "still have unfinished work? (yes/no)" age/distraction
gate (any non-`n` answer ends the session), then an English id prompt where
literally typing `new` branches into new-account registration (a
already-used/banned id just re-prompts, no separate "new" confirmation
step), then a fresh English id (3-8 lowercase letters, checked against
`banned_id`), then — **with no y/n confirmation in between** — straight to
the Chinese-name prompt, then password (twice), then email (custom
`???@ccb`-substring requirement), then gender (m/f), then automatic
`confirm_gift("n", ...)` → `enter_world()`, which moves a fresh
`no_gift`-flagged character straight to `/d/wiz/init` (a talent-point
allocation mini-game: reroll one of 4 stats via `[0-3]`, or `[9]` to accept
— `9` itself asks a **second** `y/n` confirmation before actually
finishing).

Full clean transcript, one continuous connection, id `zhongfen` /
**real Chinese name `秦风终`**:

```
gb                        -> GB encoding selected
no                        -> not a distracted worker
new                       -> new-player registration
zhongfen                  -> English id accepted
秦风终                     -> Chinese name accepted (no rejection message)
test12345                 -> password
test12345                 -> password confirmed
zhongfen@ccb.com           -> email accepted
m                          -> gender: male
9                          -> accept default talent allocation
y                          -> confirm talent allocation
  好！祝你西天取经早成正果！
  只见眼前霞光一闪，你已经来到了一个陌生的世界（ｌｏｏｋ）．．．
  【月影奇缘】: 听说来了一位叫做秦风终的少年英雄。
look
quit
```

Player landed in the actual game world (server-wide announcement
"听说来了一位叫做秦风终的少年英雄" — "heard a young hero named Qinfeng-Zhong
has arrived" — confirms `enter_world()`/`confirm_gift()` completed and the
character object is live). A second full run (`qfsan`/`秦风三`,
`qinfeng`/`秦风六`) reached the actual starting room (南城客栈 / South-City
Inn) with visible exits, a bulletin board, and 3 NPCs (店小二, 邮差
千里眼, 唐僧), including an NPC greeting message — confirming the room
itself, not just the character-creation flag, is fully live. Driver
process remained alive and responsive after every one of these tests.

## lpcc sweep

9,498 files, 9,220 pass / 278 fail (**97.06%**). Failure categories
triaged (not fixed individually, per AGENTS.md §6b — breadth over
exhaustive depth):
- **84 "Undefined variable"** — dominated by `std/skill_model_*.lpc`
  (`SKILL_CH_NAME`/`SKILL_EN_NAME`): these are **templates**, not real LPC
  objects — `cmds/std/meskills.lpc`/`editskill.lpc` read them as raw text
  and `replace_string()` the placeholder tokens to generate real per-skill
  files. Compiling the template standalone is expected to fail; this is
  not a bug (§6b's "`#include`-only fragment" pattern's cousin — a
  text-template pattern instead).
- **~40 "Illegal character 0xNN"** plus assorted syntax errors — spans
  several unrelated content files; spot-checked a few and found ordinary
  pre-existing typos (missing closing quotes, fullwidth punctuation in
  code position) of the same shape already catalogued in §9/§10 — not a
  systemic issue, just the normal long tail of pre-existing authoring
  bugs in a large, old, hand-edited content tree.
  - **12 "Invalid UTF8 codepoint in string literal"**: worth a note for
    whoever revisits — these are real conversion casualties that slipped
    past `convert_lib.sh`'s heuristics on this particular archive; not
    chased further given the sweep's job here is signal, not an
    exhaustive per-file fix pass, and none of the affected files are on
    the boot/login path (confirmed: the whole registration+game-entry
    flow booted and ran with zero such errors in `debug.log`).
- **5 "Cannot #include uid.h"** (`mail_serv.lpc`/`ms.lpc`/`pingtcp.lpc`/
  `telnetd.lpc`, all under `adm/daemons/network/`): a genuine missing-
  header content gap in the intermud/network subsystem (confirmed
  `uid.h`/`config.h`/`daemons.h`/`mailer.h` don't exist anywhere in this
  archive) — none of these files are in `preload` or reachable from
  registration; a real archive gap (§13), not fabricated.
- **Remaining categories** (`call_other`-target-not-found clusters,
  "Unable to find the inherited function" on a handful of files, etc.)
  match the standard "isolated single-file compile lacks the real room/
  preload graph" noise already documented in §6b — spot-checked a sample,
  none appear in the real boot's `debug.log`.

Memory stayed healthy throughout (~19GB available at completion, peaked
around 2.5GB RSS on the `lpcc` process mid-sweep — small relative to the
~9,500-file count, no pressure requiring an early kill despite 2-3 other
agents' concurrent sweeps running on the same host at the time).

## Housekeeping

Driver was killed after testing; verified no `driver config.fluffos`
process remains with cwd under `libs/yueyingqiyuan/` before finishing.

## Re-verification pass: driver rebuild + formatter + WASM (2026-07)

- **LPC formatter** applied to all `.lpc` under `work/` via
  `tools/lpc-syntax/bin/format-corpus.mjs` (9,498 total, 9,361 written,
  115 unchanged, 22 self-checked errors left untouched — expected on
  legacy code, not chased).
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `debug.log` (only the
  pre-existing benign `emoted.o` restore warning and ordinary compile
  warnings). Full registration flow re-verified end-to-end with a fresh
  real Chinese name (`秦风试`/`Zfretwo`) through `look`/`score`/`quit`,
  all correct.
- **NEW bug found during this pass (pre-existing, not caused by the
  reformat or driver rebuild)**: `adm/etc/banned_name` — the static,
  read-only Chinese name-blocklist file `check_legal_name()` in
  `adm/daemons/logind.lpc` reads via `explode(read_file(BANNED_NAME),
  "\n")` — was **entirely missing from `work/`**, present in `raw/`
  (500 GBK-encoded lines) and confirmed **never written to anywhere in
  the codebase** (grep for `BANNED_NAME` — only the one `read_file()`
  call site). `read_file()` on a missing path returns `0`, and
  `explode(0, "\n")` throws `Bad argument 1 to explode()`, uncaught,
  aborting **every** Chinese-name submission during registration —
  this silently blocked all new-character creation. Root cause traced:
  the repo-wide QA sweep commit that added
  `libs/*/work/adm/etc/banned_name` to `.gitignore` (intending to stop
  tracking *runtime-churn* ban-lists that some OTHER libs' code
  generates/appends to at runtime) also **deleted this lib's
  already-committed copy** — but here the file is genuine static
  shipped content (an authored blocklist), never runtime-written, so
  the blanket path-based `.gitignore` rule doesn't distinguish the two
  cases and this lib got its real content silently deleted. Fixed by
  regenerating it from `raw/yy/yueying/adm/etc/banned_name` via
  `iconv -f GBK -t UTF-8` (matches the same encoding-conversion the
  rest of the archive underwent). **Flagged for the orchestrating
  session**: the shared `.gitignore` rule
  `libs/*/work/adm/etc/banned_name` is unsafe as a blanket pattern and
  should be re-scoped or the other 90 libs re-checked for the same
  false-positive wipe (checked the other 7 libs in this batch —
  `yuxuechongsheng` uses a differently-named `BANNED_NAMES` file that
  IS genuinely runtime-managed via `write_file()` in `band.lpc`, so
  that one gitignore hit is correct; the remaining 5 libs in this batch
  have no `BANNED_NAME`-shaped gate at all).
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`):
  boots cleanly (only the expected non-fatal "sockets package not
  available"-class preload messages). Full registration flow completed
  end-to-end under WASM too — real Chinese name `秦风瓦`/`Zfrewasm`
  reached the actual starting room (南城客栈), `look`/`score`/`quit`
  all produced correct output. This lib's registration path does not
  gate on `query_ip_number()`'s format — the only WASM-side artifact
  observed was **cosmetic**: the "你现在从 ... 连线进入" banner line
  prints an empty IP substring (known WASM-mode `query_ip_number()`
  limitation, driver-side, not a mudlib bug) instead of `127.0.0.1`.
  Does not affect login/registration/gameplay in this lib.

## WASM-enablement pass (2026-07): loopback gates + admin seeding

Standard four-change pass per AGENTS.md §1.3b/§1.3e/§1.5:

- `adm/daemons/band.lpc`: new `is_local_site(site)` helper (loopback /
  empty / malformed-IP ⇒ local) short-circuits `is_banned()`,
  `create_char_banned()`, `is_strict_banned()` — all return 0 for local.
- `adm/daemons/logind.lpc`:
  - `logon()` (~line 100): per-IP concurrent-login-attempt cap
    (`login_cnt > 3` destruct) now skipped for loopback.
  - `encoding()` (~line 185): the no-`query_ip_name` destruct and the
    IP-must-be-numeric character-scan destruct are skipped for
    loopback/malformed IPs (the WASM garbage-IP case).
  - `get_id()`'s `MAX_LOGIN` per-IP multi-login cap (~line 375):
    loopback exempt.
  - `get_passwd()`'s 20-second relogin load throttle (~line 585):
    loopback exempt (kept for remote connections).
- `adm/daemons/securityd.lpc` `match_wiz_site()`: loopback/malformed IP
  always matches (wizard site locks can't block local logins).
- No `uptime()` startup-grace gate exists in this lineage's login path
  (only cosmetic uptime uses in cmwhod/httpd) — nothing to bypass.
- Admin seeded per §1.5: `fluffos` / `Mud@2026` / 浮浮, registered via the
  real flow (gb → no → new → id → 中文名 → 密码×2 → email 必含 "ccb"
  (`fluffos@ccb.com`) → gender m → talent 9 → y), then `fluffos (admin)`
  appended to `adm/etc/wizlist`. Verified on re-login: banner shows
  目前权限：(admin), lands in /d/wiz/wizroom, and
  `update /d/city/kezhan.lpc` recompiles successfully.
- Retest: fresh normal registration (`wasmtest`/秦风测) end-to-end into
  南城客栈 with `look`/`score`/`quit` correct; debug.log clean (warnings
  only). Test char saves removed; note the lib runtime-appends every new
  player name to `adm/etc/banned_name` (name-reservation) — test-churn
  lines were reverted, the single 浮浮 line is kept intentionally.
