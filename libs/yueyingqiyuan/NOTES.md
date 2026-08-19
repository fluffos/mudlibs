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
readme text seen bundled with `sjtx2`, archive #36) — same
distribution site, unrelated codebase, not a lineage signal by itself
(consistent with the project's repeated "similar branding ≠ shared lineage"
finding).

**Lineage**: `adm/obj/master.c`'s own header comment says `// for ES II
mudlib` / `// original from Lil` / `// rewritten by Annihilator` — the same
"ES II" family already seen in `es1_win`/`esI`/`xkx2001`/`rzrmud`/`xo`/
`xo_final`/`bmxkx2001`. Layout is `adm/obj/{master,simul_efun}`
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
  `yxcs` uses a differently-named `BANNED_NAMES` file that
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

## WASM long-sit boot-watch pass (2026-07)

200s `scripts/wasm_boot_watch.sh` sit: no new failures beyond the
already-documented `ftpd.lpc`/socket-efun sockets-absent preload error
(caught by `master.lpc`'s preload `catch()`, cosmetic — FTP feature
unavailable under WASM, not on any login/gameplay path) and the
already-documented `emoted.o` restore warning. Proactively fixed
`adm/simul_efun/object.lpc`'s `file_owner()` (`return name` → `return
dir` — misattributes 3-level-deep `/u/<wiz>/<subdir>/<file>` log_error
writes to a bogus path) as part of a repo-wide port of the fix found
live on sibling `zhonghua2`; did not fire in this lib's own sit, fixed
proactively since it's the identical shared file. Retest: fresh
registration (`yysanit`/秦风检) end-to-end through look/score/quit,
clean, no regressions.

## 深度功能测试 / Deep functional test (2026-07-24)

Round-two deep-playthrough pass (per `AGENTS.md` §10.7; see
`libs/bxsj/NOTES.md`'s and `libs/xiyouji/NOTES.md`'s "深度功能测试"
sections for the worked examples this pass follows). Read
`doc/help/newbie` in full first — it directly named the `fight`-vs-`kill`
safety distinction (`help combat` gives the full contract: `fight` stops
at unconsciousness/surrender/flight and doesn't carry a grudge; `kill`
fights to the death and ignores `quit`), the `apprentice`/`learn` syntax,
`wimpy`, and the general command set, exactly as the methodology predicts.
Played as an ordinary new player through registration, exploration, safe
combat, organic skill-learning and sect-joining, a real `quit`, a
real-wall-clock-gap reconnect, and a shop-purchase attempt, native driver
(`build-debug`).

**Test characters** (both kept, as representative playthrough evidence):
- id `qinzf`, Chinese name 秦振风, password `Test12345`, male — the main
  playthrough character. State: apprenticed to 秦富 (Qin Fu, 将军府/
  Grand-Marshal's-Mansion sect, 4th generation — `将军府第四代弟子`),
  learned `force` (内功心法) to level 1 via the organic teacher-NPC path,
  survived a `fight` against 疥顶小僧 (a wandering monk NPC, non-lethal,
  auto-surrendered at low HP), quit once (dropping its starting sect
  spear per this lineage's item-drop-on-quit design, see below), and was
  round-tripped through **both** persistence paths: a silent reconnect
  (disconnect without `quit`, then reconnect — resumed in place, no full
  login) and a real `quit` → 35-real-second wall-clock wait → full
  relogin (title/sect/skill all intact). Saves: `work/data/user/q/
  qinzf.o`, `work/data/login/q/qinzf.o`.
- id `shenqf`, Chinese name 沈青枫, password `Test12345`, male — a second
  character used specifically to walk `/d/jjf/gate` → `front_yard` →
  `front_yard2` (the exact crash site below) on a **freshly rebooted**
  driver, confirming clean room population and correct, uncorrupted NPC
  titles after the fix. Saves: `work/data/user/s/shenqf.o`, `work/data/
  login/s/shenqf.o`.
  (A third character, id `shenqing`/沈青, was used only to reproduce the
  crash pre-fix; its save files were removed after the fix was verified
  since its story is fully captured in this writeup and it added nothing
  `shenqf` doesn't already demonstrate more cleanly.)

### Bug found and fixed: this is AGENTS.md §7.17, not a new class — confirmed present via the shared "ES II" lineage, not independently discovered

`yueyingqiyuan` and `xiyouji` are documented siblings in the same "ES II /
西游记" mega-family (`AGENTS.md` §11; both this lib's own NOTES.md
lineage note and `xiyouji`'s independently confirm `adm/obj/master.c`'s
`// for ES II mudlib // original from Lil // rewritten by Annihilator`
header). Per §7.17's own instruction to "check documented siblings for
the same pattern before moving on," `std/room.lpc` was read first and
found structurally **identical** to `xiyouji`'s pre-fix copy — `setup()`
calls `this_object()->reset()` synchronously as the last line of every
room's `create()` (`std/room.lpc:211-213`), and `reset()` only marks a
room's NPC population done on its very last line (`set_temp("objects",
ob)`, `std/room.lpc:104` pre-fix) — and `d/jjf/npc/zhangmen.lpc`'s
`init()` calls a local `create_identity()` whose `where`-resolution does
the exact same forced `call_other(where, "???"); where_ob =
find_object(where);` idiom when `where` isn't already an object. This
whole shape — 16 structurally-identical copies of a "sect entrance"
NPC file (one per sect: `d/jjf`, `d/nanhai`, `d/wusheng`, `d/xueshan`,
`d/moon`, `d/sea`, `d/death`, `d/lingtai`, `d/fenghuang`, `d/pansi`,
`d/shushan`, `d/xuyi`, plus 4 under `d/qujing/{kusong,wudidong,wuzhuang,
xuanyuan}`) each calling `me->create_identity(<master path>, <own room
path>)` from `init()` — is the same copy-pasted pattern §7.17 documents
for `xiyouji`'s 9 sect-entrance NPCs, just with 16 sects instead of 9.

- **Live reproduction** (before applying the fix, fresh driver boot,
  `debug.log` cleared first): registered a fresh character and walked
  `南城客栈` → `朱雀大街` → `十字街头` → `青龙大街` ×2 → `answer 拜师` →
  `将军府`(gate) → `south` into `front_yard`(练武场, 秦富's courtyard) →
  `south` again into **`front_yard2`(练武场, the crash site — logs/pits/
  weapon rack, holding `npc/guard` and `npc/zhangmen`)**, its first-ever
  visit since the driver booted. Player-visible symptom: the second
  `south` command silently failed to move — the client displayed the
  **same** `front_yard` room a second time (identical description and
  NPC list, 秦富/小童×2) instead of `front_yard2`, with no error visible
  on screen. `log/debug.log` showed the real story: **7** "Too deep
  recursion." traces in a single connection — 6 blamed on
  `/adm/daemons/securityd.lpc:175` and the last one squarely on
  `program: /d/jjf/npc/zhangmen.lpc, object: /d/jjf/npc/zhangmen#217,
  file: /d/jjf/npc/zhangmen.lpc:38` (the `create_identity(...)` call
  inside `init()`) — the blamed file:line shifting between calls is
  exactly §7.17's documented signature of a genuine reentrant cycle
  rather than one bad line.
- **Root cause**: identical to §7.17's documented mechanism — `reset()`
  can fire twice on `front_yard2`'s first-ever compile (once
  synchronously from `setup()` at the end of `create()`, once more from
  the driver's own standard reset-pass triggered by the same player
  `move()`), a reentrant second call sees `query_temp("objects")` still
  empty and clones a second full set of `guard`/`zhangmen`, and cloning +
  moving the second `zhangmen` synchronously fires its `init()` →
  `create_identity()` → the forced `call_other("/d/jjf/front_yard2",
  "???")` self-locate, which can itself re-trigger the room's own
  compile — closing the cycle until "Too deep recursion." aborts it.
- **Fix** (ported directly from §7.17, applied lib-wide, not just to the
  one reproduced site):
  1. `std/room.lpc`: added `nosave int resetting_now;` (declared at
     top, `std/room.lpc:10`), checked/set at the top of `reset()`
     (`std/room.lpc:42-43`) and cleared on every return path (both the
     early `!mapp(ob_list)` return and the normal end of the function,
     `std/room.lpc:65` and `:105`). A reentrant call is now a safe
     no-op; the original (outer) call still runs to completion exactly
     once. Lib-wide — every room inherits `std/room.lpc` — but provably
     inert for the normal non-reentrant case (re-verified several
     already-known-good multi-NPC rooms, e.g. `d/city/kezhan` with its 3
     NPCs, after the fix and saw identical, correct population).
  2. All **16** `<sect>/npc/zhangmen.lpc` files: added a `nosave int
     in_init_now;` flag (declared just above `init()`) guarding the
     entire body of `init()` the same way (`if (in_init_now) return;
     in_init_now = 1;` at entry, `in_init_now = 0;` at every fall-through
     exit — none of these 16 `init()` bodies had an early `return`, so
     each needed exactly one flag-clear line before the closing brace).
     Applied identically to `d/death`, `d/fenghuang`, `d/jjf`,
     `d/lingtai`, `d/moon`, `d/nanhai`, `d/pansi`, `d/qujing/{kusong,
     wudidong,wuzhuang,xuanyuan}`, `d/sea`, `d/shushan`, `d/wusheng`,
     `d/xueshan`, `d/xuyi` — confirmed each file still diffs cleanly
     against its siblings aside from the expected per-sect content
     (master/room paths, `inquiry` text). `d/npc/zhangmen.lpc` (a
     generic, unplaced template — its own `init()` never calls
     `create_identity()` and it's not referenced live from any room's
     `"objects"` mapping; the one call site that looks like it,
     `d/nanhai/guangchang.lpc`, is fully commented out) was deliberately
     **not** touched — dead code, left alone per the catalog's own
     precedent.
  3. Belt-and-suspenders in all 16 files' `create_identity()`: since
     `where` is, at every real call site in this lineage, always the
     room the NPC was just cloned into, resolve it via
     `environment(this_object())` first (falling back to the original
     forced `call_other(where, "???"); find_object(where)` only if that
     doesn't already resolve to `where`).
- **Verified**: reproduced live pre-fix as above (fresh driver boot,
  `debug.log` cleared, 7 "Too deep recursion." traces from one
  connection). Post-fix: killed and rebooted the native driver fresh
  again, registered a **brand-new** character (`shenqf`/沈青枫) and
  walked the identical route through `front_yard2` on its first-ever
  visit — the second `south` now correctly rendered `front_yard2`'s own
  description (木桩/沙坑/兵器架, distinct from `front_yard`'s 沙袋) with
  its own NPCs (`大唐天下兵马大元帅 朝廷兵马大元帅(Zhang men)` and
  `校尉(Xiao wei)`) — no duplicate-room artifact, no corrupted `0`-prefixed
  title (`zhangmen`'s title/name come from its own `reset_me()`, which
  ran cleanly exactly once). `debug.log` showed **zero** "Too deep
  recursion.", `error:`, or `Fatal` lines for the entire post-fix
  session. Re-verified again with the main `qinzf` playthrough
  (different route, through `front_yard` only, apprenticing under 秦富)
  across multiple reconnects — clean throughout.
- **Scope note**: only `/d/jjf/front_yard2` was live-reproduced and
  live-verified fixed (both pre- and post-fix). The other 15 sects'
  entrance rooms were fixed proactively by the identical code-shape match
  (per `AGENTS.md`'s "port the sibling's proven fix" pattern, §2.1) —
  each of the 16 source files was read and confirmed to have the exact
  vulnerable shape before fixing, but a live walk-through of all 16
  sect-entrance rooms was not pursued given the time budget. **The
  `std/room.lpc`-level `resetting_now` guard is lib-wide and structural**
  — it independently closes the reentrancy cycle for every room in the
  game regardless of which NPC's `init()` would otherwise re-touch it, so
  the un-walked 15 sects are protected even without their own live
  verification. A future pass reaching any of the other 15 sects should
  spot-check its own `zhangmen.lpc`'s entrance room on first visit anyway.

### What was tested and confirmed working

- **Registration**: real Chinese name (秦振风), full flow (gb encoding →
  distracted-worker gate → `new` → English id → Chinese name → password
  ×2 → email → gender → talent roll/accept), landing directly in
  `南城客栈` (bypassing the `/d/welcome/welcome` routing lobby below —
  new-player registration routes through `/d/wiz/init`'s talent-roll
  minigame, which moves the character straight into the city on
  completion, independent of the `startroom`-based routing that ordinary
  relogins use).
- **Movement/exploration**: walked `南城客栈` → `朱雀大街` → `十字街头`
  → `青龙大街` ×2 → `answer 拜师` → `将军府`(gate) → `练武场`
  (front_yard, 秦富/小童×2) → `练武场`(front_yard2, the crash site,
  now fixed, via `shenqf`). Room descriptions, exits, and day/night
  flavor text all correct throughout; read the underlying `.lpc` room
  files to plan the route (§10.7's explicit instruction) rather than
  guessing — this is how the `/d/jjf/gate`'s `answer 拜师` gate (`d/jjf/
  npc/qinan.lpc`'s `do_answer()`) was found before blindly walking into a
  "你胡说什么呀？" rejection.
- **Character info**: `score` (仙衔/职位 title line, attributes, 气/神
  bars, kill/death counts) and `hp` (气/神/食物/饮水/内力/法力 bars) both
  correct at every stage (fresh, post-fight, post-apprentice,
  post-skill-learn). `i` correct throughout, including the `□`
  equipped-item marker convention (same ES2-family convention seen in
  sibling libs).
- **Combat**: `help combat` documents `fight` (not `kill`) as this
  lineage's own safe-sparring contract — battles stop at unconsciousness/
  surrender/flight and don't carry grudges, matching `xiyouji`'s finding
  for the same lineage. A genuine stat-mirroring training-dummy object
  (`muren.lpc`, `accept_fight()` copies the attacker's own
  skills/skill-map) **does exist** at `d/shushan/obj/muren.lpc` (placed,
  ×4, in `d/shushan/{w,e}-lianwu.lpc`) but is a real trek from the
  starting zone; a second, byte-similar copy at `d/city/obj/muren.lpc`
  is **orphaned** (confirmed via `grep -rn "city/obj/muren" work/d`:
  zero hits — not referenced by any room's `"objects"` mapping anywhere
  in the archive), the same "dead training-dummy content" pattern
  `xiyouji` documented for its own lineage. Used `fight xiaoseng` (阿疥顶
  小僧, a wandering peaceful monk NPC one step from the starting inn,
  `combat_exp` comparable to a starting character) instead — produced a
  normal turn-by-turn exchange with narration, correctly auto-surrendered
  at low HP ("你向後退了几步，说道：这场比试算我输了，佩服，佩服！"),
  no crash, `hp`/`score` both showed partial-but-recovering气血/精神
  afterward. **Note**: the NPC's set `id` is the full alias
  `"jieding xiaoseng"`/`"xiaoseng"`/`"seng"` (not `"jieding"`, which is
  only part of its display name) — `fight jieding` alone correctly fails
  with "你想攻击谁？", a correct target-not-found rejection, not a bug.
- **Skills**: the organic path is `learn <skill> from <teacher>`
  (`cmds/std/learn.lpc`), gated on family/apprentice status for most
  teachers but not this lib's low-tier stewards — used after
  apprenticing (below); `learn force from qin fu` succeeded ("你的「内功
  心法」进步了！"), `skills` correctly listed the new `内功心法 (force)`
  entry at `若有若无 1/0`. `skills <teacher>` (`skills qin fu`) correctly
  listed the teacher's full 9-skill roster with `★`-marked specials.
- **Menpai/sect**: the organic path is `apprentice <master>`
  (`cmds/std/apprentice.lpc`) → the NPC's own `attempt_apprentice()`/
  `recruit_apprentice()`. Two sect NPCs were checked in `将军府`:
  `d/jjf/npc/qinqiong.lpc` (秦琼, the sect's actual master, gates
  recruitment behind a `combat_exp` threshold like `bxsj`/`xiyouji`'s
  equivalent high-tier teachers — not visited live here since `qinfu`
  already demonstrates the mechanism, and `qinqiong`'s own save data was
  deliberately left untouched, see Housekeeping below) vs. `d/jjf/npc/
  qinfu.lpc` (秦富, the steward, no threshold), which accepted
  immediately: `apprentice qin fu` → `你想要拜秦富为师。秦富决定收你为
  弟子。` → `score`'s title updated to `将军府第四代弟子 秦振风`, 师承
  line correctly showed `将军府秦富`, and a `师门点钢枪` (sect spear) was
  auto-granted. **A direct/shortcut sect-join path was checked for and
  NOT found**: `d/city/npc/shizhe.lpc` (「不知情愁枉少年」月影使者,
  placed in the `/d/welcome/welcome` routing lobby every full login
  passes through) looks, by name and placement, exactly like `xiyouji`'s
  documented newbie-gift-envoy shortcut, but its only actual effect
  (`ask shizhe about 月影奇缘`) is a one-time food/water top-up
  ("小的已经对您施过法力了" on repeat) — **no sect grant, no stat boost**.
  This lib's only join mechanism is the organic `apprentice` path,
  matching `xiyouji`'s own conclusion for its sibling lineage (not every
  ES II derivative kept the shortcut).
- **Persistence**: confirmed at both layers this lineage has —
  (a) *silent reconnect* (disconnect without `quit`, reconnect with the
  same id/password — "重新连线完毕", resumed in the exact same room with
  full HP/inventory state, no fresh `look` printed automatically);
  (b) *full quit → 35-real-second wall-clock wait (backgrounded `sleep`,
  per the standing methodology note on not idling a live connection) →
  relogin*: title (`将军府第四代弟子`), 师承 (秦富), and the learned
  `force` skill (`若有若无 1/0`) all round-tripped correctly. **Location
  after a full relogin is `/d/welcome/welcome`(混沌之初), NOT wherever
  `quit` was called from or even the game's actual starting room** — this
  lineage's `START_ROOM` constant (`include/login.h`) is itself this
  routing lobby, which requires typing `oldplayer` (→ `/d/city/kezhan`)
  or `newbie` to proceed; a player's own `startroom` property is never
  set to anything else by ordinary play (only registration's separate
  `/d/wiz/init` flow bypasses this lobby entirely on the FIRST login).
  Confirmed `oldplayer` correctly lands back in `南城客栈` with the
  world otherwise unaffected. This is a real, deliberate, one-more-hop
  variant of the same "location resets on full relogin" design already
  documented for sibling libs — not a bug, just implemented as an extra
  routing room instead of a direct room jump.
  **Item-drop-on-quit, same class as `bxsj`/`xiyouji`'s documented
  behavior**: `cmds/usr/quit.lpc` drops every non-`query_autoload()` item
  on a real `quit` — confirmed live (the `师门点钢枪` sect spear, present
  in `i` right before `quit`, was gone after relogin; a fresh 皮靴/紫蟒袍
  outfit appeared instead, granted by the login flow's own `get_cloth()`-
  equivalent re-grant). Deliberate original-archive design, not a
  persistence defect.
- **Shops/economy**: `d/city/kezhan.lpc`'s 店小二 (`d/city/npc/
  xiaoer.lpc`, `F_VENDOR_SALE`) — `list` correctly showed the documented
  menu (炸鸡腿/水晶球/挑战金牌/红烧狗肉/花生豆/下棋指南/桂花酒袋).
  `buy jiudai from xiao er` was attempted live with a fresh character's
  starting money (0 — no starting-money grant found anywhere in the
  registration/talent-roll path) and correctly rejected with "你的钱不够"
  — a real, correct exercise of the economy gate, matching `help
  newbie`'s own text ("新手：没有钱怎么办？不要问巫师，向老玩家讨"). **No
  successful purchase was completed live** — flagged honestly as an
  incomplete verification (no in-game income source was pursued within
  the time budget), not silently skipped, matching the `xiyouji` pass's
  own precedent for the same gap.
- **Death/respawn**: **not live-tested.** `feature/damage.lpc:275`'s
  `die()` was read (environment `alternative_die` hook, wizard-immortal
  guard, `rulaitask` quest-death special-case, corpse/reward handling)
  and looks structurally sound — no obvious bug. `cmds/usr/suicide.lpc`
  was checked as a possible low-risk trigger: bare `suicide` (no arg)
  turned out to be flavor-text-only (prints a message, does not actually
  call `die()` or reincarnate); `suicide -f` is a genuine, real death
  trigger but **permanently deletes the character** (30-second countdown,
  password-gated) — deliberately not used since it would destroy the
  kept evidence character. No genuine `kill`-to-death fight was pursued
  either, given the time budget was prioritized toward chasing the
  confirmed, live, reproducible `front_yard2` recursion crash (above) to
  a verified fix. Concrete to-do for a future pass on this lib.

### Housekeeping

Driver killed by exact PID after testing (`kill 1385155`, confirmed via
`ps`/`ss -tlnp` that both the process and the port-40048 listener were
gone) — verified no `driver config.fluffos` process remains with cwd
under `libs/yueyingqiyuan/` before finishing. `work/data/zhangmen/
zhangmen_qin_qiong.o` (秦琼's own save file, touched by `restore()` calls
made from testing `create_identity()`/apprenticeship in the 将军府 zone)
was reverted to its committed content after confirming the diff was a
pure key-reordering + `.c`→`.lpc` header self-normalization from a
`restore()`+`save()` round-trip, not a real state change. `work/adm/etc/
banned_name` (this lib's runtime name-reservation append target, see the
"Re-verification pass" section above) picked up entries for the two kept
test characters (沈青枫, 秦振风) — kept, since they correspond to real
kept save files — and one entry for the discarded `shenqing`/沈青
character, which was removed along with that character's save files.
No other scratch/diagnostic files were created outside `/tmp` (removed).

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD`、`BULLE_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 39 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round 2 (2026-08-15, post driver-upgrade re-test)

Round-two re-verification against the current native `build-debug` driver
(post-upgrade — pulls in PRs #1343/#1344 and the corpus-wide `%`-operator
float-crash fix). Standard checklist + live playthrough-style verification.

Findings:

1. **AGENTS.md §7.108** (`obj/user.lpc`'s `reconnect()` missing
   `enable_commands()`): this lib has the kick-duplicate-login pattern
   (`adm/daemons/logind.lpc` calls `user->reconnect()` on the character
   body after `exec(old_link, user)`). Fixed by adding `enable_commands();`
   as the first statement. Live-verified with two concurrent telnet
   sessions: session 2 logged in as `fluffos`, confirmed the "赶出去，
   取而代之吗？(y/n)" prompt with `y`, and the resulting session correctly
   dispatched `look` (real room description) and `score` (real stat
   panel). (Other `exec(old_link`/`reconnect()` copies under `www/cgi-bin`,
   `www/relative`, and `u/yxm/obj/logind.lpc` are stray/dead per-user or
   web-tree copies, not the active `LOGIN_D` — confirmed via
   `include/globals.h`'s `LOGIN_D` define — left untouched.)
2. **`adm/simul_efun/file.lpc`**: `log_file()` never called `assure_file()`
   before `write_file()`; added the call (plus a forward declaration).
   `cat()`'s `write(read_file(file))` had no null-guard; changed to
   `write(read_file(file) || "")`.
3. **Already correct, no change needed**: `cmds/wiz/update.lpc` (only
   `update.lpc` in this lib) already guards with `environment(me) &&`.
   `adm/obj/master.lpc`'s `log_error()` already uses the case-agnostic
   `"arning:"` filter (AGENTS.md §7.10). No `adm/daemons/closed.lpc`
   exists, so AGENTS.md §7.107 does not apply. `maximum evaluation cost`
   was already `30000000`.

Live verification summary: booted the native driver on port 40048 (clean
boot aside from pre-existing unused-variable/unknown-pragma warnings, no
fatals; `Initializations complete` / `Accepting telnet connections` both
printed). Logged in as the seeded `fluffos` admin (`Mud@2026`, via the
`gb`-encoding prompt then the internal-network "还有好多工作没有做完？"
gate answered `no`), confirmed real write access via `update
/adm/simul_efun/file` (recompiled successfully). The lib's own boot-warning
notifier ("有新文件update错误，立即查看 /log/log") fired as expected —
checked `/log/log`, confirmed it's just the routine pre-existing compile
warnings, not a new error. Ran the two-session kick-duplicate-login
reconnect test described above and confirmed the §7.108 fix live. No
fatal errors in the driver's console output. Killed the driver by exact
PID when done.

本轮修改的文件 / Files modified this round:
- `libs/yueyingqiyuan/work/obj/user.lpc`
- `libs/yueyingqiyuan/work/adm/simul_efun/file.lpc`

## Round-three deep functional test (2026-08-18)

Standard §10.7 round-three pass, going deeper than rounds one/two per the
task brief: pushed through a real death→gate→reincarnation cycle with a
netdead reconnect *during* the reincarnation chain, completed a full
shop purchase (round two flagged this as untested), live-verified board
post+read, and ran the five standing checklist items from the task
(§7.111/§7.112/§7.113/§7.90/`logind.lpc enter_world() save`).

### Standing checklist results

1. **§7.111** (`master.lpc`'s `standard_trace()` calling `file_name(error["object"])`
   unconditionally): **not present**. Both call sites in `adm/obj/master.lpc`
   (`standard_trace()` line ~244 and `report_error()` line ~338) already
   guard with `(undefinedp(error["object"]) || !error["object"]) ? "(none)" :
   file_name(error["object"])`. No fix needed.
2. **§7.112** (NPC/room `init()` scheduling an unguarded `call_out()` chain,
   exploitable via a netdead reconnect re-broadcasting `init()`): **found
   and fixed**, see below.
3. **§7.113** (netdead reconnect not restoring `heart_beat`): **not
   present**. `obj/user.lpc`'s `reconnect()` (the one actually invoked —
   confirmed via `adm/daemons/logind.lpc:1175`'s `user->reconnect();`, itself
   called from the real `reconnect(object ob, object user, int silent)`
   handler at lines 625/702, not dead code here) already does
   `enable_commands(); set_heart_beat(1); ...` as its first two statements.
   This predates the round-two §7.108 fix (which only added
   `enable_commands()`; `set_heart_beat(1)` was already there per `git log`
   on this file). Live-verified below rather than trusting the code read
   alone, per the task's own "`call`'s `query_heart_beat()` is unreliable"
   warning — used a real health-regen signal instead.
4. **§7.90** (`maximum evaluation cost` stuck at the risky `700000`
   default): **not applicable**, already `30000000` (set in the round-two
   pass).
5. **`logind.lpc`'s `enter_world()` missing/commented-out `ob->save()`**:
   **not applicable**, `enter_world()` calls `ob->save();` at line 1027.

### Bug found and fixed: §7.112, this lib's own 4-file instance of the death/reincarnation `init()`-`call_out()` race

Grepped every `init()` body in the archive for an unguarded `call_out(`
(481 hits total, the overwhelming majority ordinary one-shot NPC chat/
greeting timers where a duplicate is harmless). Narrowed to the
death/reincarnation-themed directory the task flagged as the highest-risk
shape: `d/death/npc/{b,pang,bgargoyle,wgargoyle}.lpc` — all four are
`阴间判官`-style "psychopomp" NPCs placed in the death-zone rooms a
player's character is moved into on death (`feature/damage.lpc`'s
`die()` → `this_object()->move(DEATH_ROOM)`, `DEATH_ROOM` =
`/d/death/gate`, which places `npc/pang`; the other three sit in
`new-out*`-linked rooms further into the zone). All four have the
identical shape: `init()` unconditionally does
`call_out("death_stage", 5, previous_object(), 0);` with **no** guard
against being re-triggered, and `death_stage()`'s final stage calls
`ob->reincarnate()` and `ob->move(REVIVE_ROOM)` — i.e. exactly the
"duplicate reincarnation chain" hazard the task describes. Since a
netdead reconnect re-broadcasts `init()` to every object in the
reconnecting player's environment (the same mechanism the round-two
§7.108 fix depends on), reconnecting while standing in one of these
rooms mid-chain would schedule a **second**, independently-ticking
`death_stage` chain overlapping the first — duplicate/interleaved
psychopomp dialogue at minimum, and a real risk of a second
`ob->reincarnate()`/`ob->move(REVIVE_ROOM)` racing the first.

**Fix** (ported from the task's reference shape, `libs/sj/work/d/death/
npc/wgargoyle.lpc`, extended slightly — see below): added a per-target
`"death_stage_active"` `set_temp()`/`query_temp()`/`delete_temp()` guard.
`init()` now checks `if (previous_object()->query_temp
("death_stage_active")) return;` before setting the flag and scheduling
the first `call_out`. `death_stage()` clears the flag on **every** exit
path (not just the two the `sj` reference clears) — including the
"turned out not to be a ghost, attack/kick them instead" branches in
`b.lpc`/`bgargoyle.lpc`/`wgargoyle.lpc` and the `max_gin/kee/sen <= 0`
early-return in `bgargoyle.lpc`, which the `sj` reference's own fix
leaves un-cleared (a latent gap there — if that branch fires, the flag
would stay set forever for that player object, permanently blocking any
*future* legitimate death_stage chain for the same login session).
Applied identically across all four files; confirmed each diff is
minimal (`git diff --stat`, 9-17 lines changed per file, all plain-LF
files so no CRLF risk).

**Live reproduction and verification** (single script, deterministic
timing, native `build-debug` driver, fresh `debug.log`):
- Triggered a real death via `call qintan->die()` as the seeded admin
  (exercises the actual `die()` apply combat calls too — not a
  synthetic path) — confirmed `qintan` moved to `/d/death/gate`
  (阴阳界) with `npc/pang` (崔珏, 朱笔判官) present, matching
  `feature/damage.lpc`'s documented `DEATH_ROOM`/`start_death()` flow
  (`DEATH_ROOM->start_death(this_object())` is itself a pre-existing,
  harmless no-op — no `start_death()` function exists anywhere in the
  codebase, and LPC's `call_other()`-to-undefined-function silently
  returns 0 rather than erroring; not fixed, dead but non-fatal, noting
  for the record).
- Closed the `qintan` socket ~0.6s after the death-move (simulating a
  network drop) and reconnected ~1.5s later — the reconnect landed
  during the ~5-10s window (confirmed via wall-clock timestamps in the
  test script), i.e. **squarely between** `death_stage` stage 0
  (fired ~5s after entry, its message text arrived mid-login) and stage
  1 (due ~5s later). This is exactly the race window the fix closes.
  Watched the full remaining chain: stages 1, 2, and 3 (崔判官's four
  dialogue lines) each printed **exactly once**, at the correct ~5-second
  cadence, with no duplicate or interleaved text — confirming the guard
  blocked the second `init()` broadcast (triggered by the reconnect's
  `enable_commands()`) from scheduling a competing chain.
- `debug.log` (freshly cleared at boot) stayed **completely empty**
  through the whole death→reconnect→chain→revive sequence — no errors,
  no "Too deep recursion.", nothing.
- A follow-up connection confirmed the chain completed correctly exactly
  once: `qintan` ended up in the real revive room (荒郊小店, "Wilderness
  Small Shop") with its own corpse and board present, `score` showed
  被杀 incremented to 二 (2, correct — two real deaths this session), and
  `hp` showed 气血 56/200 recovering (not stuck at the post-death floor
  of 1) — direct live evidence `heart_beat` resumed correctly after the
  reconnect (confirms the §7.113 code-read finding above without relying
  on the unreliable `call`-based `query_heart_beat()` check the task
  warned about).

### Economy: completed a real purchase (round-two gap closed)

Round two flagged "no successful purchase completed live" as an honest
gap. This round closed it: discovered live that `score`'s "存款" (bank
deposit, the `"balance"` property) is **not** the currency `cmds/std/
buy.lpc`'s `can_afford()`/`pay_money()` check — those check for actual
money *objects* carried in inventory (`feature/finance.lpc`, presence-
checks `coin_money`/`silver_money`/`gold_money`/`gold-coin_money`/
`thousand-cash_money`), a deliberate two-tier economy (bank deposit vs.
cash-in-hand), not a bug. Used the seeded admin to `clone /obj/money/
silver`, `set_amount(50)`, and `give` it to `qintan`; `buy jiudai from
xiao er` then succeeded correctly (`你向店小二买下一个桂花酒袋。`,
inventory and remaining silver both updated correctly, 49 taels left).
Confirms the vendor/purchase code path is sound.

### Board post/read: live-verified end to end

`南城客栈留言板` (`obj/board/nancheng_b.lpc`, a `BULLETIN_BOARD` instance
— the same class the corpus-wide §7.86 sweep touched in this lib,
previously only compile-checked, never live-played) — `read new` and
`post <title>` (via the real `ed`-editor flow, `<body text>` then `.` to
end) both worked correctly as the seeded admin (posting requires either
wizard status or `literate` skill ≥ 10, a real, intentional gate — a
fresh player correctly gets "还是先去学点读书写字吧！" instead, not a
bug). Confirms the §7.86 fix (dropping the redundant
`replace_program()` call) did not break the underlying post/read
mechanism it was applied to. (Test churn: reverted the board's own save
file, `data/board/nancheng_b.o`, after confirming the post worked —
kept the fix, not the test data.)

### Other things tested, no issues found

- Registration (fresh char, `qintan`/秦探三): clean, same flow as prior
  rounds.
- `goto`, `call`, `clone`, `give` wizard commands: all work correctly for
  the seeded `fluffos` admin account.
- Reconnect while netdead (silent, no `quit`): resumes in place, per
  prior rounds' findings — reconfirmed here as a side effect of the
  death-chain test's own reconnect step.

### Housekeeping

Driver killed by exact PID (`kill 102769`; verified via `ps` and
`ss -tln` that both the process and port 40048's listener were gone)
after confirming `readlink /proc/102769/cwd` matched this lib's `work/`
directory. Reverted incidental save-file churn that wasn't real test
evidence: `data/board/nancheng_b.o` (the test board post) and the
seeded admin's `data/login/f/fluffos.o` / `data/user/f/fluffos.o` (pure
key-reordering + `last_on` timestamp bump from login activity, no real
state change). Kept `qintan`'s save files (`data/user/q/qintan.o`,
`data/login/q/qintan.o`) as playthrough evidence, consistent with prior
rounds' convention — it demonstrates a full death→reincarnation→revive
cycle survived two real deaths cleanly. `adm/etc/banned_name` picked up
`秦探三`'s name-reservation entries (kept, since the character save is
kept). No scratch files were left in the lib's own directory (test
scripts lived under the session scratchpad, not the repo).

本轮修改的文件 / Files modified this round:
- `libs/yueyingqiyuan/work/d/death/npc/b.lpc`
- `libs/yueyingqiyuan/work/d/death/npc/pang.lpc`
- `libs/yueyingqiyuan/work/d/death/npc/bgargoyle.lpc`
- `libs/yueyingqiyuan/work/d/death/npc/wgargoyle.lpc`
