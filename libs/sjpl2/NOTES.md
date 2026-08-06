# sjpl2 — 「书剑飘零」Ⅱ ("Stray Book & Sword" II)

Archive: `书剑飘零II .zip`. Port: 40031. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese
name).

## What this is

"【书剑飘零Ⅱ】", English tagline "Stray Book & Sword", credited to
"飞白工作室" (Feibai Studio), http://sjpl.sq.sh.cn. Mudlib root at the
archive top level (`config.wd` at the root, not nested in a subfolder).
Uses `adm/obj/{master,simul_efun}` — despite the similarly-named "书剑"
title, this is a genuinely **different, unrelated codebase** from
`shujian2008`/`sjtx2` (archives #35/#36, `adm/single/` layout):
different directory convention, no `named.c` daemon, and a `securityd.c`
with different internal logic. Don't assume shared lineage from a
similar Chinese title alone — always verify via layout/file diff.
~13,022 raw files, 12,349 after `.c`→`.lpc` rename.

## Fixes applied

1. **AGENTS.md §15h (GBK byte-range Chinese detection)**, standard
   shape: `adm/simul_efun/chinese.lpc`'s `is_chinese()` (GBK lead-byte
   range → CJK codepoint range) and `adm/daemons/logind.lpc`'s
   `check_legal_name()` (byte-count bound `< 2 || > 12` → character-count
   bound `< 1 || > 6`, removed the `i%2==0` even-byte-offset gate). The
   `name[i..<0]` slice syntax was already a clean single-character-to-end
   slice — no change needed there, unlike some other libs that used a
   multi-byte suffix relying on `is_chinese` reading only the first 2
   bytes.
2. **Proactively added `get_include_path()` to `master.lpc`** (the
   standard §15o/§8d shape) as cheap insurance, even though this specific
   symptom was never actually observed — the lib booted clean and the
   full registration flow worked without it being strictly proven
   necessary. Left in as prophylactic protection for any future
   mid-connection lazy compile.
3. **Confirmed NOT needed, verified via source reading rather than by
   hitting and diagnosing a crash**:
   - **§4** (lazy security-daemon load): `master.lpc`'s
     `valid_write`/`valid_read` already gate via `find_object(SECURITY_D)`
     only (no unconditional `load_object`).
   - **§15n** (custom-securityd func-discrimination gap): this lib's
     `securityd.c`'s `valid_read` does NOT override the `user` parameter
     with `this_player()` (unlike `shujian2008`'s), so compile-time reads
     (which the driver attributes to `master_ob`, per
     `check_valid_path(..., master_ob, "load_object"/"include", ...)`)
     see `master_ob`'s own euid — presumably Root — and hit this
     `securityd`'s early `if (euid==ROOT_UID) return 1;` check before any
     directory-based ACL is even consulted. Confirmed by reading the
     source rather than needing to reproduce the crash first, per the
     lesson learned on `shujian2008`.

## Re-verification pass (2026-07-23) — found and fixed a §15w-class bug

The original pass above never tested a post-login command. Re-testing the
full flow through `look`/`score`/`quit` found `adm/obj/master.lpc`'s
`log_error()` unconditionally broadcasting every compile *warning* (not
just real errors) to the connected player — wizards saw `编译时段错误：...`,
and ordinary players saw an even vaguer but equally alarming
`你发现事情不大对了，但是又说不上来。`("something's wrong, but I can't
say what") on literally every lazily-compiled file's first warning,
which in practice fired repeatedly right after registration and on every
`look`/`score` in a fresh session (AGENTS.md §15w). Fixed by gating both
branches on the message not containing `"warning:"` (still always logged
to file). **Also checked, not a live bug**: `feature/command_new.lpc` has
the exact §15ae `private nomask int command_hook` shape, but it's dead
code — nothing in the whole lib references `command_new` by path; the
actually-inherited command feature (`F_COMMAND` = `feature/command.lpc`,
confirmed via `std/char.lpc`) already declares `command_hook` as plain
`nomask`, no `private`. Verified via 2 full registration sessions
(id `sjplhh`/`sjplii`, real Chinese names `秦风十四`/`秦风十五`) that
`look`/`score`/`quit` all produce correct real output with zero spurious
"something's wrong" messages after the fix. `debug.log` clean of
`denied`/`cannot`/`undefined function`/`error in error handler` in both
sessions.

## Interactive test result — full registration flow (original pass)

Verified the complete registration path in one continuous connection:

1. `sjplbtest` → passes `check_legal_id`, reaches the "确定吗(y/n)？"
   confirmation.
2. `y` → reaches the Chinese-name prompt.
3. **Real Chinese name `秦风`** → accepted (no rejection message),
   proceeds straight to "请设定您的密码：" — the actual proof the §15h
   fix works. No novel-character-name restriction found in this lib's
   `banned_name` list (unlike `shujian2008`) — just game-title words
   ("书剑", "书剑飘零", "飘零", "飞白") and pronouns.

## lpcc sweep

12,349 files, 11,772 pass / 577 fail (95.3%). Failure tail is the usual
shape (a large syntax-error cluster, missing `MONEY_D`/`prepare_skill`
globals, a handful of type-mismatch returns) — not triaged individually
per AGENTS.md §6b/§13, boot + full interactive registration test is the
verification gate. Memory stayed healthy throughout (~15GB free
consistently, no pressure).

## Rebuilt-driver / formatter / WASM re-verification pass (2026-07-23)

1. **LPC formatter** applied across all 12,349 `.lpc` files in `work/`:
   `{"total":12349,"written":12291,"wouldChange":0,"unchanged":4,
   "errors":54}`. Verified post-format that `feature/command.lpc`'s
   `command_hook` is still plain `nomask` and `master.lpc`'s §15w
   `strsrch(message, "warning:") == -1` guard is intact.
2. **Native re-test against the rebuilt `build-debug/src/driver`**:
   booted clean (zero fatal errors). Full registration verified
   end-to-end via `mudclient.py`: id `sjplfmtc` → confirm → real Chinese
   name **`秦风廿二`** → password ×2 → email `abc@abc.com` → gender `m`
   → birth-family choice `0` (书香门第) → entered the game world at
   民居, `look` displayed the room, `score` showed a correct character
   sheet (才智/体质/... matching a 书香门第 background), `quit` dropped
   items and printed "欢迎下次再来！". `debug.log`: zero `error in error
   handler`/`denied`/`undefined function`/`bad argument` lines. (Noted
   in passing, not a regression: `get_name()`/`get_resp()` in
   `logind.lpc` both contain a pre-existing `printf("%O\n", ob);`
   debug leftover from the original archive that echoes the login
   object's `/obj/login#N` identifier to the player right after a valid
   Chinese name is entered — harmless, doesn't block registration,
   present before this pass and left as-is per the project's "don't fix
   unrelated cosmetic content" convention.)
3. **WASM test**: boots cleanly (only the expected non-fatal preload
   noise — an `Invalid utf8 string while restoring emote` on
   `restore_object()`, same class of harmless save-data quirk as other
   libs, and the usual missing-sockets-package compile errors for any
   network daemons). **Full registration completed successfully under
   wasm**: id → confirm → Chinese name → password ×2 → email → gender →
   birth-family choice → entered 民居 → `look`/`quit` both produced
   correct real output, ending with the same "欢迎下次再来！" farewell as
   the native session. This lib has **no IP-format-dependent login gate**
   (no `sited`-style `query_ip_number()` check blocking new
   connections), so it is **fully playable under wasm**, unlike several
   sibling libs in this batch — the best-case wasm result observed this
   pass.

## WASM-enablement pass (2026-07-24)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback-allow**: `adm/daemons/logind.lpc` `logon()` (~line 74) —
   the `BAN_D->is_banned(query_ip_name/query_ip_number)` gate is skipped
   when `query_ip_number(ob)` is empty/non-string/`127.*`.
   `adm/daemons/band.lpc` `is_banned()` also short-circuits to 0 for
   loopback/localhost/malformed sites.
2. **Uptime gate / anti-flood throttle**: none present at connection
   time (the per-command flood counters in `feature/alias.lpc` are
   in-game robot protection, left alone per the KEEP-content-timers
   rule).
3. **Admin seeded**: `fluffos` / `Mud@2026` / 浮浮 → `(admin)` appended
   to `/adm/etc/wizlist`. Save files: `work/data/login/f/fluffos/fluffos.o`
   and `work/data/user/f/fluffos/fluffos.o` (per-id subdirectory layout;
   data/ not gitignored). Verified: login shows 目前权限：(admin);
   `update /cmds/usr/score.lpc` → 成功; `cd`/`whoami` work.
   Gotcha discovered while verifying: `update` on its OWN file
   (`/cmds/wiz/update.lpc`) silently no-ops — main() destructs the
   command object it is executing from before reaching the write();
   original behavior, not a bug introduced here.
4. Retest: fresh registration (sjplqf/秦风, deleted after test) into the
   start room with look/score/quit OK. debug.log: only pre-existing
   noise (`restore_object(): Invalid utf8 string ... emote` from
   emoted.o — known; `/cmds/wiz/tail` uses the never-existed `tail()`
   efun (§6.2 class) — pre-existing, hit only by my probe command).

### Retrofit: fail-closed loopback check (2026-07-24)

The loopback-allow gates above were originally written per the (now
superseded) defensive instruction to also treat an empty/non-string/
malformed `query_ip_number()` result as loopback, since older WASM
driver builds returned garbage. That driver bug is now fixed upstream
(`query_ip_number()`/`resolve()` return real values under WASM too), so
the "malformed IP = trust it" fallback was a fail-open bypass with no
remaining justification. Tightened every gate listed above to the
strict pattern: loopback is ONLY `ip == "127.0.0.1"`, `ip == "::1"`, or
a leading `"127."` prefix — a non-string/empty/malformed IP is now
treated as untrusted/remote and subject to the gate normally, not
silently allowed through. Retested: fluffos login (127.0.0.1, real
value under the current driver) still passes every gate; debug.log
stayed clean of `denied`/`undefined function`/`error in error handler`.

## 深度功能测试 / Deep functional test (2026-07-24, AGENTS.md §10.7)

One continuous native-driver session (port 40031), following the
distilled §10.7 checklist. Read `doc/help/newbie.txt` first (a detailed
guide — birth families, `ask <parent> about help`, `hp`/`score`/`i`,
`distribute`, the 5 家/宗门 orientation, `apprentice`, `fight`/`quest`
progression, money units, `alias`). Note: the guide's own text describes
an OLDER Chang'an-centric ("长安") map layout that no longer matches
this archive's actual live map (birth-family homes are in 泰安/山东 and
福州, not 长安, and the nearest reachable sect gate is a hostile
"三才剑阵" guard, not a walk-up master) — a content/documentation staleness
observation, not a programming bug, left as-is.

**Bugs found and fixed (2 classes, 4+21 files):**

1. **NEW instance of the §4.3 `"static/…"` → `"nosave/…"` string-literal
   collision, previously unnoticed on this lib.** The blanket
   `static`→`nosave` conversion pass also rewrote 24 STRING LITERALS
   across 21 files that happened to start with the word `static/` as a
   log-file path — `adm/obj/master.lpc`'s crash handler
   (`log_file("nosave/CRASHES", …)`), five copies of a promotion-log
   write (`adm/securityd.lpc`, `adm/daemons/securityd.lpc`/`securityd2`/
   `securityd_hb`/`securityd_new`/`security.lpc`/`bak/securityd.lpc`/
   `adm/tmp/securityd.lpc` — `log_file("nosave/promotion", …)`),
   `cmds/usr/suicide.lpc` (+2 `bak/` copies), `feature/vi.lpc`'s `LOGFILE`
   macro, and 8 copies of a `call`/`callme` audit-log write
   (`cmds/arch/call.lpc`, `cmds/adm/call2.lpc`, `cmds/wiz/callme.lpc`
   +`bak/`, `cmds/appr/callme.lpc` +`bak/`, `u/set/callme.lpc` +
   `Incomplete-callme.lpc`, `cmds/wiz/bak/call.lpc`). Confirmed by
   diffing against the raw GBK archive (`raw/adm/obj/master.c` etc. all
   say `"static/CRASHES"`/`"static/promotion"`/… — never `"nosave/"`,
   which appears NOWHERE in the raw archive) — this is purely a
   conversion-pipeline artifact, not original content. `work/log/static/`
   already exists on disk (empty) as the intended destination;
   `work/log/nosave/` never existed, so every one of these writes was
   silently failing (`log_file()` on a missing directory returns 0 / is a
   no-op, so this never crashed anything — it just silently discarded
   promotion logs, call-audit logs, the vi edit log, and (worse) the
   driver's own crash-dump log on every abnormal shutdown, defeating
   its one purpose). Fixed by reverting every `"nosave/…"` literal in
   these 21 files back to `"static/…"` (verified zero genuine `"nosave/…"`
   literal exists anywhere in the raw archive, so a blanket revert across
   all hits was safe). Detected via a stray boot-shutdown log line
   (`"Wrong permissions for opening file /log/nosave/CRASHES..."`) while
   first booting the driver for this pass — not by the standard
   `grep '"static` pre-boot checklist (§2.2), which only greps for the
   collision INSIDE source files, not for evidence of it having actually
   fired at runtime. Worth adding to the §2.2 on-sight checklist: also
   grep the target lib for any `"nosave/…"` string literal after the
   `static`→`nosave` pass and diff each hit against the raw archive.

2. **§7.24-class bug (new instances, not yet cataloged for this lib):
   death/reincarnation code unconditionally overwrites the permanent
   `"startroom"` login-location field**, live in **4 files**:
   `d/death/npc/wgargoyle.lpc`, `d/death/npc/bgargoyle.lpc`, and
   `d/death/inn1.lpc` (all three death-realm NPCs/rooms that move a
   dead/reincarnating player to a revival location — either
   `/d/city/chenghuang` or `/d/fuzhou/duchang`, chosen by `combat_exp`)
   did `ob->set("startroom", base_name(environment(ob)))` right after the
   `move()`, unconditionally, exactly the shape §7.24 (found on `zzfy`)
   describes. Confirmed neither `chenghuang.lpc` nor `duchang.lpc` sets
   `valid_startroom` — the legitimate mechanism the lib's own
   `cmds/usr/save.lpc` uses to gate the SAME field
   (`if (environment(me)->query("valid_startroom")) me->set("startroom", …)`)
   — so this death-path write was bypassing that gate entirely, silently
   and permanently relocating every future full login away from wherever
   the player actually lived (their family's 民居, or any inn/room they
   legitimately `save`d in) to a random revival slum, with zero
   player-facing indication anything about future logins changed. A
   FOURTH copy of the identical shape was found in an unrelated context —
   `u/mojiao/yabian.lpc`'s "jump off the cliff" shortcut mechanic (two of
   its three outcome branches set `startroom` to the cliff-base landing
   room `u/mojiao/yadi.lpc`, also not `valid_startroom`-flagged) — same
   root cause, different trigger, cataloged together since they're the
   same bug class.

   **Live-reproduced and confirmed fixed**, not just source-reviewed:
   using the seeded `fluffos` admin account's `call` command, force-moved
   the live `qinfengdt` test character (a real, non-wizard, in-session
   player object, at the time net-dead/disconnected but not destructed)
   into `/d/death/gate`. `wgargoyle`'s automatic `init()` → `death_stage()`
   chain fired for real (its `!wizardp()` skip only blocks wizards, and
   `qinfengdt` is not one), ran its full 5-message/~25s sequence
   unattended, and genuinely moved the character to `/d/fuzhou/duchang`
   (confirmed by an admin `look` at that room, seeing `秦风大同
   <断线中>` standing there). Checked `qinfengdt`'s `"startroom"` before
   and after: it stayed `/d/shandong/ta/minzhai1` (their real family
   home) the whole time — the fix holds under the actual automatic
   trigger path, not just a compile check. Then had `qinfengdt` `quit`
   from inside `duchang` and log back in fresh: landed correctly back at
   `民居`/`minzhai1`, not `duchang` — the concrete practical confirmation
   the bug class describes (before the fix, this exact sequence would
   have permanently rerouted every future login to the gambling den).
   All 4 files also reconfirmed to recompile cleanly via the running
   driver's own `update` command (`重新编译 …：成功！` for each).

**Registration / core loop, verified in one continuous session:**
registered `qinfengdt`/**真实中文名「秦风大同」**, birth family 0
(书香门第), landed in `民居` (`/d/shandong/ta/minzhai1`). `look`/`score`/
`i`/`hp` all correct at every state change (after register, after the
family-NPC gift interaction — `ask man about help` → 中年男士 hands over
`旧书`+`腰带` and silently grants `literate` skill 2 — after moving through
~9 first-visit rooms in the 泰安/Tai'an zone, after a real fight, after
`quit`). Explored `d/shandong/ta/*` (city streets, pharmacy, clothing
shop, grain-store search — none in this city, only in 福州/Fuzhou — 魏家
书局 literate-teacher shop) reading room `.lpc` source for navigation;
`debug.log` stayed clean of `Too deep recursion`/`eval cost`/
`couldn't find object` through every first-ever room compile this boot
(no §7.17/§7.19/§7.22/§7.25-shaped reentrancy hit).

**Safe-sparring mechanism**: found and read (not live-reached — see
below) `y/city/npc/peilian.lpc` and `u/tian/shaolin/npc/muren.lpc`
(木头人/training dummy), both genuine `accept_fight()` stat-mirrors of
the attacker (per §10.7's own detection pattern) — confirmed as designed,
gated at `combat_exp` ceilings (20000/15000) appropriate for a
mid-progression character, not a fresh newbie. Both sit 15-20+ rooms
from the actual starting zone (Shaolin/Huashan sect grounds, not
anywhere near 泰安/福州), too far to reach live within this session's
budget on a fresh, un-equipped character — **not verified live**,
disclosed explicitly rather than guessed. As the best available live
proxy, fought the newbie-doc-recommended `obj/npc/shangren.lpc`
(combat_exp 20, `env/wimpy` 60, self-surrenders) with `wimpy 30` set —
resolved safely (opponent surrendered, own hp/sen barely scratched,
247/250 气血), no errors in `debug.log`.

**Sect-join mechanism**: read `cmds/std/apprentice.lpc` (organic
`apprentice <name>` → `attempt_apprentice()` two-step flow) and 3 real
master NPCs' gates: `u/taishan/npc/master1.lpc` (rejects unless
`class == "taishan"` already — a genuine two-tier "join a junior
disciple first" design, not reachable directly; its zone entrance
guard `u/taishan/npc/dizi.lpc` is an ACTIVELY HOSTILE gate that attacks
any non-member on sight, matching the newbie doc's "有些门派…必须通过解
谜才能拜师" — correctly NOT walked into with a fresh, unarmed character),
`d/wuhan/npc/master.lpc` (海鲸帮/Whale Gang — unconditional accept
for any non-`betrayer`, genuinely "easy" as the newbie doc claims), and
the death-flow gargoyles (unrelated to sect-join, covered above). All
reachable sect entrances are 20+ rooms of travel from the starting
zone in THIS archive's actual live map (as opposed to the newbie
doc's stale Chang'an-centric description) — **not verified live**,
disclosed explicitly. The mechanism itself (`apprentice.lpc`'s
`input_to`-confirmed two-step flow, `recruit`/`attempt_apprentice`
pairing) reads as functionally sound; no bug found in it by inspection.

**Organic skill-teacher path**: reached 魏柄林 (`d/shandong/ta/npc/wei.lpc`)
at 魏家书局 live and exercised `ask wei about study` — correctly gated
("你需要先付学费。" / "you need to pay tuition first", matching
`do_learnbook()`'s `!me->query_temp("can_learn")` check) since the
fresh character had no coin (no `work`-verb location exists in this
character's home city — 泰安/山东 — only in 福州/Fuzhou and huashan/etc,
a content-scope observation not a bug). Did not complete an actual
successful lesson (would need real coin, not reachable within budget)
— disclosed explicitly, not presented as fully tested. The
gate/tuition logic itself triggered correctly with no error.

**Shop purchase**: reached `d/shandong/ta/ta-chengyidian.lpc`
(成衣店/clothing shop) live, `list` printed real prices (绸袍 6两银子
etc.), `buy choupao from guo` correctly rejected with "你的钱不够。"
(insufficient funds) — no crash on the failure path. Full successful
purchase not completed (same money constraint as above), disclosed
explicitly.

**Combat/death**: real (not staged) combat tested against `shangren`
(see above, safe-proxy fight). A full player-controlled death (not the
admin-forced repro used to verify the §7.24-class fix) was not
attempted live within this session's time budget — disclosed
explicitly; the death-flow FIX itself, however, WAS verified live via
the automatic NPC-driven trigger path as described above, which is the
same code path a real death takes.

**Reconnect / persistence testing (all in one continuous session,
`qinfengdt`):**
1. Prompt net-dead reconnect (socket closed without `quit`, mid-session
   at 魏家书局, reconnected within seconds): resumed cleanly in the same
   room, no errors.
2. Clean `quit` (from 魏家书局, a non-`valid_startroom` room) → real
   ~3-minute wall-clock wait → reconnect: correctly landed back at the
   real persistent home (`民居`/minzhai1, NOT 魏家书局 where the quit
   happened) — confirms `startroom`-based persistence works as designed
   and that `quit` doesn't wrongly persist the CURRENT room as home.
3. Net-dead disconnect (no `quit`, mid-session after moving south) →
   real ~2.5-minute wait → (superseded by the admin-driven death-flow
   test before a plain reconnect could be separately re-verified at this
   exact point — the prompt-reconnect case in (1) already demonstrates
   the mechanism works). This lib's `net_dead()` (`obj/user.lpc`) never
   moves the player to a "void" holding room while disconnected (unlike
   the §7.20 class) — the body simply stays in its current room with
   `heart_beat` off — so there is no void-parking stranding risk to
   verify separately; confirmed by reading the code.
4. The full `NET_DEAD_TIMEOUT` (900s / 15 min) `user_dump()` auto-quit
   boundary was **not** crossed live (would cost 15 real minutes of pure
   idle wait) — disclosed explicitly. Mitigated by source review: this
   lib's `obj/user.lpc` `user_dump()` DUMP_NET_DEAD case calls the
   lib's own `tell_room()` simul_efun wrapper
   (`adm/simul_efun/message.lpc`), which IS correctly `varargs`-safe
   (`varargs void tell_room(mixed ob, string str, object *exclude)`),
   unlike the broken 2-arg-into-a-non-varargs-wrapper shape that caused
   `dtsl`'s severity escalation of this same class (§7.12) — so the
   specific mechanism that made that bug dangerous (an aborted
   `user_dump()` silently skipping the `command("quit")` at the end,
   permanently orphaning net-dead sessions) does not appear to apply
   here. Confirmed live that ~561 ordinary `tell_room()` call sites
   fired without error throughout this session (combat messages, NPC
   greetings, room announcements), including from `call_out` contexts,
   reinforcing that this wrapper is safe in practice, not just by
   inspection.

**Driver-fatal crash — 6th independent occurrence of the AGENTS.md
§10.8 class, NEW fault signature.** During this same admin-driven
verification sequence (after confirming the death-flow fix worked and
with `debug.log` checked clean seconds earlier), the native driver
process (PID recorded, cwd-verified) **segfaulted and died outright**
— `Segmentation fault (Address not mapped to object [0x4a])` — while
running its own ordinary periodic object-reset sweep
(`look_for_objects_to_swap` → `reset_object` → some object's `reset()`
→ the `environment()` efun → `object_visible()` dereferencing a bad
`current_object` pointer). `debug.log` showed **zero** trace of this,
exactly matching §10.8's signature (only the driver's own captured
stdout, redirected to a file, revealed it — the same lesson §10.8 already
documents). This is a genuinely NEW fault shape for the class (a raw
SIGSEGV in `f_environment`/`object_visible()`, not a `debugmalloc`
consistency-check abort or a "ref count 0, but not destructed" fatal
like the five prior occurrences), but the same overall pattern: a
driver-internal memory-consistency violation, surfacing during ordinary
ambient driver activity (a ~5-minute periodic reset sweep, not any
single identifiable LPC statement), uncatchable and invisible to
mudlib-level logging. Full C++ backtrace captured to the driver's own
stdout log during the session (not committed as a file, per the
`dtsl`/`shenzhou` precedent of describing it in prose here instead) —
available on request by re-running the same sequence with stdout
captured. **Honest caveat on causation**: this occurred shortly after a
sequence of somewhat unusual admin-`call`-driven object manipulation
(moving a live, non-wizard, mid-net-dead player object across rooms
programmatically, several `call` invocations with malformed/unresolved
string arguments that were silently ignored by the target functions) —
unlike ordinary player action, but also not fundamentally different
from what any in-game `move()`/`command()` sequence does. Whether this
contributed to, was coincidental with, or is simply the same
low-reproducibility background corruption class documented in §10.8
(triggered eventually by ANY sufficiently long/active session,
regardless of what that session did) is **not established** — flagged
honestly per the §10.8 precedent's own standard, not attributed to a
specific LPC cause. Driver restarted cleanly afterward for final
verification (see below); no recurrence in the remainder of this pass.

**Final clean re-verification pass** (after all fixes, fresh driver
restart): registered a brand-new character (`sjplfinal`/真实中文名
「秦风终验」, birth family 0) through the FULL flow — id → confirm →
Chinese name → password ×2 → email → gender → birth choice → world entry
at 民居 → `look`/`score`/`i` all correct → `quit` (dropped the cloth,
"欢迎下次再来！"). `debug.log` fully clean of
`denied`/`undefined function`/`error in error handler`/`bad argument`/
`Too deep recursion`/`eval cost`/`couldn't find object`. Test character
save data (`qinfengdt`, `sjplfinal`, and the earlier pass's throwaway
ids) deleted from `work/data/{login,user}/` after testing, per this
project's established convention; the seeded `fluffos` admin account's
save data and `(admin)` wizlist entry were left intact and reconfirmed
working (`update <path>` → 成功) throughout.

**Files modified this pass**: 21 files reverting the `"nosave/"` →
`"static/"` string-literal collision (listed above, item 1); 4 files
removing the unconditional `startroom` overwrite in death/limbo code
(`d/death/npc/wgargoyle.lpc`, `d/death/npc/bgargoyle.lpc`,
`d/death/inn1.lpc`, `u/mojiao/yabian.lpc`, item 2). No other code
changes. `work/data/login/f/fluffos/`, `work/data/user/f/fluffos/`
show only normal save-churn (mapping key reordering from a routine
`save()`, no data loss — `startroom`/`combat_exp`/admin status all
unchanged) from logging in as admin repeatedly during this pass.

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 44 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
