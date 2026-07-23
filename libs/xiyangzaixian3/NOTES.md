# xiyangzaixian3 — 夕阳再现III之炎龙封印

Archive: `夕阳再线III之炎龙封印.rar`. Port: 40042. Status: **done** (boots
clean, full registration flow verified end-to-end including a real
Chinese name, character entered the actual game world).

## What this is

"夕阳再现III" ("Sunset Reappears III: Seal of the Flame Dragon"), by
AKAI Studio (阿凯工作室, http://akai.isme.net/), copyright 2006. `adm/obj/`
layout (`master file : /adm/obj/master`, `simulated efun file :
/adm/obj/simul_efun`), MudOS 0.9.20-era config. The mudlib root was
nested two directories deep plus a `world/` subdirectory inside the
archive (`raw/夕阳再现III/夕阳再现III/world/`) — confirmed via
`config.xyzx`'s own `mudlib directory : ./world` setting, relative to
the config file one level up. ~9,360 raw files, 8,302 after the
`.c`→`.lpc` rename.

`chinese.c`'s `is_chinese` was byte-identical to `tianxiawuxue`
(archive #51, processed in parallel by a sibling agent this same
session) — same standard single-first-character GBK-byte-range shape,
suggesting shared lineage or a common code pool, though this wasn't
otherwise investigated deeper (not depended on).

## Fixes applied

1. **AGENTS.md §15h**, standard shape, applied proactively per the
   assignment brief:
   - `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte check
     (`str[0] > 160 && str[0] < 255`, `strlen>=2`) → CJK codepoint check
     (`str[0] >= 0x4e00 && str[0] <= 0x9fff`, `strlen>=1`).
   - `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count bound
     `< 2 || > 10` → character-count bound `< 1 || > 5`; removed the
     `i%2==0 &&` even-byte-offset gate so every character position is
     checked.
2. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. No other preloaded daemon does synchronous socket setup
   (checked every preload entry for `socket_create`/`socket_bind`/
   `resolve()`; only files under `adm/daemons/network/` — none of which
   besides `dns_master` are preloaded — reference sockets at all).
3. **Confirmed NOT needed, via source reading**: `master.lpc`'s
   `valid_write`/`valid_read` only `find_object(SECURITY_D)` (no lazy
   `load_object`, so no §4 recursion risk); no `destruct()` on
   `SIMUL_EFUN_OB`/`MASTER_OB` in `create()` (no §15l crash risk);
   `get_root_uid()`/`get_bb_uid()` both present (no §7 gap); no
   `named.c` daemon exists in this lib at all; `securityd.c`'s
   `valid_read` is a bare `return 1;` (no §15n custom-ACL gap, no §8c
   `this_player()`-override footgun).
4. **NEW finding — missing `WQA_ROOM` macro, 81-file cascade**:
   `include/globals.h` never defined `WQA_ROOM`, despite 81 files across
   `quest/game/` doing `inherit WQA_ROOM;` — confirmed genuinely absent
   in the raw archive too (not a conversion artifact). The intended
   target, `/quest/game/wqa_room.c` (a lottery/"官运亨通" quest-room base
   class), does exist on disk, just never had its macro defined anywhere.
   Fix: added `#define WQA_ROOM "/quest/game/wqa_room"` to `globals.h`
   next to the other `ROOM`-family macros. This single-line fix resolved
   81 of the lpcc sweep's original 230 failures in one shot (matches
   AGENTS.md §8g's "one shared dependency, not N independent bugs"
   pattern, just via a missing `#define` rather than a broken shared
   file).
5. **NEW finding — `iconv -c`'s lossy-byte-drop can eat an adjacent
   legitimate newline, not just the genuinely invalid byte(s)**: three
   files (`d/heimuya/tang.c`, `d/heimuya/shenggu.c`, `d/heimuya/npc/tang.c`)
   were flagged by `convert_lib.sh` as "LOSSY conversion (invalid bytes
   dropped)". Root-caused via raw hex inspection: each file has a
   genuinely corrupt GBK byte sequence in the ORIGINAL archive right at
   the boundary between the room's `@LONG ... LONG` heredoc body and its
   closing `LONG` tag — two consecutive illegal GBK lead-byte fragments,
   the second of which unluckily consumes the very newline that
   separated the Chinese description text from the closing tag. With
   `iconv -c`, both illegal pairs get silently dropped, merging what were
   two lines into one (`...奕奕.LONG );` instead of `...奕奕.\nLONG );`),
   which breaks the heredoc parser (`error: End of file in text block`)
   since FluffOS requires the closing identifier alone on its own line.
   Two more files (`d/quanzhen/manglin1.c`, `manglin2.c`) had the exact
   same "closing tag glued onto the last text line" shape but WITHOUT
   any accompanying lossy-byte-drop warning — i.e. this exact authoring
   mistake (or one indistinguishable from it) also occurs as a genuine
   pre-existing typo, independent of the lossy-conversion mechanism.
   **Fix, all 5 files**: inserted the missing newline before the closing
   `LONG` tag. **Worth adding to AGENTS.md's encoding section**: any file
   flagged lossy AND using a `@TEXT...TEXT`-style heredoc is worth a
   quick manual check that the closing tag is still on its own line —
   the `-c` fallback's byte-drop isn't guaranteed to be "just" the
   invalid byte(s), it can eat a legitimate adjacent byte (here, a `\n`)
   too when two illegal sequences abut a real character.
6. **Pre-existing typos, unrelated to conversion** (confirmed present in
   the raw archive by direct byte inspection before fixing):
   - `kungfu/skill/hanbing-mianzhang2.lpc`: a stray backtick before
     `random(...)` inside `apply_condition(...)` turned the rest of the
     file into an unterminated "template literal" (`error: End of file
     in template literal`). Removed the backtick.
   - `kungfu/skill/iceforce/chillgaze.lpc`: an `if(...)  return
     notify_fail(...);` single-statement guard was immediately followed
     by a stray extra `}`, silently closing the function early and
     leaving the rest of the body as invalid top-level statements
     (`skill`/`damage` used without declaration, `->` arrow at file
     scope). Fix: removed the stray `}` and added the missing `int
     skill, damage;` declaration (the file already had an unused,
     seemingly-leftover `object *ob;` declaration hinting the original
     declaration line had been damaged/replaced at some point).
   - `d/city2/npc/zhengmen.lpc`: `valid_leave()` was missing its final
     two closing braces (confirmed via brace-depth counting — file ends
     at depth 2, needs to return to 0). Added the two missing `}`.
   - `kungfu/skill/guxing-sword.lpc` and `quest/baituo/qlist3.lpc`
     (twice): classic §10 missing-closing-quote-before-concatenation /
     missing-comma-in-array-literal typos. Fixed each.
7. **Documented, not fixed — pre-existing severe corruption, out of
   scope for a quick fix**:
   - `feature/vendor_sale.lpc` (inherited by 21 shop-NPC files): from
     roughly the halfway point of the file onward, virtually every
     statement is missing its terminating `;` and/or closing `)`/`{`
     (confirmed byte-identical to the raw archive — not something our
     pipeline introduced). This is far beyond a single-token typo;
     reconstructing correct intent for ~180 lines of shop/deposit/
     price-setting logic was judged not worth the time for one feature
     file not on the boot/registration path. Never reached during the
     verified boot+registration+room-entry test.
   - `d/city/sj.lpc` (a "jump off the summit" easter-egg room): every
     string literal argument in `do_out()`/`look_out()` is missing its
     quotes entirely (`message_vision($N大喊...\n, me)` instead of
     `message_vision("$N大喊...\n", me)`, `me` is also never assigned
     `this_player()`), confirmed identical in the raw archive. Same
     "not worth reconstructing intent for a non-critical isolated room"
     call as `vendor_sale.lpc` above.
   - `quest/mmid/*` (9 `qlistNNNN.lpc` files): all `#include "query.h"`,
     but no `query.h` exists anywhere in that directory (confirmed
     genuinely absent from the raw archive; a sibling directory,
     `quest/upr/`, has its own copy defining a generic `query_quest()`
     helper). A real content gap (AGENTS.md §13), not fabricated.
   - `clone/weapon/panguanbi.lpc` inherits a `PEN` macro that's never
     defined anywhere and has no corresponding base-class file on disk
     at all (unlike `WQA_ROOM` above, there's nothing to point the
     macro at) — one missing weapon subtype, a genuine content gap.
   - `adm/daemons/network/*` (userid, telnetd, pingd, pingtcp, ms,
     netmail, mail_serv, inetd, ...): the whole intermud/DNS network
     daemon family has several missing headers (`uid.h`, `mailer.h`,
     `daemons.h`, `config.h`) and simul_efun-override errors. None of
     these are preloaded (only `dns_master` was, and that's now
     excluded per §15p) — pure dead/unreachable code in this
     environment, matching the standing policy of not chasing this
     daemon family.
   - `/adm/obj/simul_efun_bak.lpc` and `/adm/simul_efun/file.lpc`: the
     former is a stray `.bak` copy caught by the blanket rename (§12-
     style, never loaded); the latter is a `#include`-only fragment of
     `simul_efun.lpc` (confirmed via grep) that only fails standalone
     under `lpcc` because `efun::ed/cp/rm` overrides are file-identity-
     sensitive — the classic §6b/§14 false-positive shape. Real boot
     loaded `simul_efun.lpc` (which `#include`s this fragment) with zero
     errors.
   - `d/city2/npc/liling2.lpc` and `d/city2/npc/zhengmen.lpc` (post-
     brace-fix): both still report a bare `Fail to load object` from
     `lpcc` with **no accompanying error/warning text at all** even
     after removing the eval-cost-limit noise (see next item) — tried
     re-running standalone multiple times, checked brace/paren balance
     (both balanced), found no lead. Neither object is preloaded or
     touched by the verified boot+registration+room-entry test; treated
     as an unexplained `lpcc`-only artifact per §6b rather than chased
     further given the two rounds of investigation already spent.

## Config tuning

Bumped `maximum evaluation cost` from the raw config's `400000` to
`5000000`, matching what's now the de facto standard across this
project's recent libs (`xianlvqiyuan`, `xianlvqingyuanzheda`,
`xianjianchuanqi`, `xiakexinzhuan2`, `xiakexing100`, `shujian2008`,
`zhonghua2` all already use `5000000`). Confirmed this actually matters
here: `d/city2/npc/liling2.lpc` spuriously failed under the raw
`400000`-microsecond real-time budget (`Eval interrupted: ... cost
limit reached, limit: 400000 usec`) purely from compiling its own
(large, 1500+ line) inheritance chain, with zero relation to any real
bug — after bumping to `5000000` that specific "Eval interrupted"
message disappeared (the file still fails for the separate,
unexplained reason noted above, but the eval-cost false-positive itself
is gone). Worth flagging generally: **any lib whose original config
still has a low `maximum evaluation cost` should get this bump
proactively**, since this driver interprets the value as literal
real-time microseconds (`vm/internal/eval_limit.cc`), not an
instruction-count budget the way classic MudOS did — a value tuned for
the old semantics can be far too tight now.

## Interactive test result — full registration flow

Read `logind.lpc`'s actual `logon()`/`get_id`/`get_id1`/`confirm_id`/
`get_name` chain before testing (not assumed). **Hidden pre-id gate
found**: the very first prompt is captioned "请输入您的英文名字:" ("please
enter your English name") but the first `input_to` callback (`get_id`)
actually checks the literal string against a hardcoded client-protocol
version code, `"2060"` — rejecting anything else with "你的客户端非
Tomud或者非笑傲江湖WWW客户端" and disconnecting. Only after receiving
exactly `"2060"` does it advance to `get_id1`, which validates the real
English id (`check_legal_id`: lowercase letters only, length 3-14). A
failed `check_legal_id` loops back to `get_id` (i.e. the `"2060"` gate
must be re-satisfied on every retry, not just once) — a subtlety that
produced a confusing false rejection ("你的客户端非Tomud...") on a first
test attempt using an id containing a digit, until re-read carefully.

Verified the complete flow in one continuous connection:
`"2060"` → `qinfengwu` (English id) → confirm `y` → **real Chinese name
`秦风五`** (accepted — no rejection, no political/banned-name hit;
`banned_name` here includes politically-sensitive names like 毛泽东/
邓小平/江泽民 plus a few generic pronouns/profanity, not novel-character
names) → password `abc12345` (twice) → gift selection `0` (random) →
confirm `y` → email → gender `m` → **entered the actual game world**
(room "铁枪庙" near 嘉兴), `look` rendered a full room description with
NPCs, `quit` exited gracefully with "欢迎下次再来！". No crashes, no
mangled text, no unexpected disconnects anywhere in the chain.

## lpcc sweep

8,302 files, 8,161 pass / 141 fail (**98.3%**) after all fixes above.
Memory stayed healthy throughout every sweep run (multiple sibling
agents' lpcc sweeps were running concurrently on this host at various
points; free memory dipped to a low of ~16GB free out of 23GB total at
worst, never remotely close to the kill threshold).

Remaining failure categories (all triaged, none individually chased
further — see "Documented, not fixed" above for the ones with a clear
story): 9× "Cannot #include query.h" (quest/mmid content gap), 9×
"Invalid simulated efunction override" + assorted "Cannot #include
uid.h/mailer.h/daemons.h/config.h" (dead intermud network-daemon code,
unreachable), ~21 files cascading from `vendor_sale.lpc`'s pre-existing
corruption, plus a long tail of one-off "Undefined variable/function"
hits in individual quest/skill files not reached by the verified boot
path.

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter** applied to all `work/*.lpc` (8302 files): 8215
  reformatted, 33 already-clean/unchanged, 54 self-checked errors
  (skipped, expected on legacy code).
- **Native re-test against the rebuilt driver** (`~/src/fluffos/build-debug/src/driver`):
  booted clean (only pre-existing compile warnings, no fatals). Full
  registration flow re-verified end-to-end with a fresh real Chinese
  name ("秦风廿六") — remembered the `"2060"` client-version gate must
  be re-sent after *every* `get_id1` rejection, not just once (bit by
  this exact subtlety on a first retry using an id containing a digit,
  exactly as this file already warned) — `"2060"` → English id (pure
  letters) → confirm `y` → Chinese name → password ×2 → gift `0` →
  confirm `y` → email → gender → entered the real game world
  (`北疆小镇`); `look`/`score`/`quit` all produced correct Chinese
  output, `log/debug.log` clean of real errors. Reformat + new driver
  build introduced no regressions.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`): boots
  cleanly (no fatal preload errors; this lib's `dns_master` is already
  excluded from preload per an earlier fix, so no `socket_*`
  undefined-function noise either). Registration proceeds correctly
  through the `"2060"` gate and the English-name prompt, but is then
  **rejected by `BAN_D->is_banned(query_ip_number(ob))`** in
  `logind.lpc` ("你的地址在本 MUD 不受欢迎。") — this is the documented
  `query_ip_number()` WASM limitation exactly as described in
  AGENTS.md/`docs/build-wasm.md` (same shape as `bxsj`'s
  `adm/daemons/sited.lpc`): the welcome banner's own IP line already
  shows blank instead of `127.0.0.1` under this WASM build, and
  `BAN_D`'s ban-list lookup on that malformed value spuriously matches
  as banned. **Not a mudlib bug** — not patched, per this pass's
  instructions. Verdict: boots under WASM, registration reaches the
  English-name step, but login is gated by the known IP-format
  limitation before a Chinese name can even be entered.
