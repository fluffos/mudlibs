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

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复三处问题：

1. **`cmds/appr/update.lpc`（AGENTS.md §7.106）**：缺少
   `environment(me) &&` 前置防护，补上（`cmds/wiz/update.lpc` 已是正
   确写法）。
2. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护，补上调用及前向声明；`cat()` 补上
   `read_file() || ""` 空值防护。
3. **`obj/user.lpc::reconnect()`（AGENTS.md §7.108，第七条独立确认
   的血统）**：`adm/daemons/logind.lpc` 有同款 `exec(old_link,
   user);` 踢掉重复登录写法，`reconnect()` 缺少
   `enable_commands()`。按 §7.108 记录的写法预防性修复，现场用两个
   真实连线复现"保持第一个连线不断开→第二个连线登录→答 y 踢掉旧连
   线"验证：`score` 修复后立即正常显示完整角色档案。

`master.lpc::log_error()` 已经是正确的 `"arning:"` 大小写无关写法，
`maximum evaluation cost` 已经是 `5000000`，均无需改动；本档案无
`adm/daemons/closed.lpc`，不受 §7.107 影响。

### 现场验证摘要

驱动干净启动，管理员 `fluffos`/`Mud@2026` 登录确认
`目前权限：(admin)`（登录横幅带一处"按回车继续"分页符，第一次
`update` 指令被当作翻页 Enter 吃掉，重发一次即成功验证真实写入权
限）。踢掉重复登录重连路径现场验证通过（见上）。`debug.log` 全程
干净（338 行，无真实错误）。

### 本轮修改的文件

- `work/adm/simul_efun/file.lpc`
- `work/cmds/appr/update.lpc`
- `work/obj/user.lpc`

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/std/room`，见 `include/globals.h`）在本档案 2,290 处
房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个休眠 bug（多
余调用给对象打上永久"pending replace"标记，对象一旦绑定任何闭包就
会崩溃）。用 `fix_710_room.py`（二进制模式，只删除内容严格等于
`replace_program(ROOM);` 的独立行）扫过 `work/`，删除 2,280 处标准
形状；另有几处不规则形状手工修复：
- `obj/roommaker.lpc` 一处字符串拼接变体
  `str += "...replace_program(ROOM);..."`；
- `u/losey/roommaker.lpc`、`u/set/obj/roommaker.lpc`、
  `u/gdjk/roomm.lpc`、`u/gdjk/hongnong/maker.lpc`（4 份房间生成工
  具副本）以及两份内嵌了同一份工具代码的 NPC 档案
  `u/lark/xiaoyao/npc/{rich,tumu}.lpc`、`u/jakey/npc/rich.lpc` 共
  7 处一种新变体：`if (!mapp(env->query("item_desc"))) str +=
  "\treplace_program(ROOM);";`（只在房间没有 `item_desc`——即没有
  门——时才拼接这一行，本质上是原作者已经注意到"有门的房间会拒绝
  replace"这个驱动行为、但反而把 bug 精确地保留在了"没有门"的多数
  房间上）——整行删除；
- `u/lark/yangmingzhai/ss.lpc` 一处真实房间文件，`replace_program`
  紧跟在一段已被注释掉的 `/* setup() */` 后面同一行，手工删除。

`u/lark/luoyang/dongmen.lpc` 里剩下 1 处**转档之前就已经损坏、留
着未修**：整个文件从 `inherit ROOM`（无分号）开始就缺失几乎所有语
句分号，`git show HEAD` 确认这个损坏在本次改动之前就存在，和这次
的 sweep 无关，保持原样。实测走读时另外撞见两个类似的、转档之前
就存在、和本次改动无关的编译错误（`y/city/zhuque-n4.lpc` 的
`NPC_DIR "people/army"` 宏拼接语法错误、`u/lark/yangmingzhai/ss.lpc`
文件开头一个原始 ANSI 转义字节残留导致的语法错误）——两份档案的
`git diff` 都确认本次改动只碰了 `replace_program` 那一行，编译错
误是转档遗留问题，不在本次修复范围内。`work/data/` 下没有真实
`.lpc` 源码命中。`git diff --stat` 显示 2284 个文件净删 2289 行
（脚本 2280 + 手工 9 处），与预期的"2290 处存活 - 1 处保留不修"吻
合；另有 150 处转档之前已注释掉的 `//` 行原样保留。

驱动干净启动（零新增编译错误、端口正常监听、`debug.log` 无任何
"cannot replace"/"cannot bind"行），巫师账号 `fluffos`/`Mud@2026`
`look`/`goto` 走读了 3 个曾经命中过这个 bug 的房间
（`y/city/baihu-n1.lpc`、`y/city/baozipu.lpc`、`y/city/bingqipu.lpc`）
均正常，`quit` 干净退出，登录存档的 `last_on` 时间戳增量已用
`git checkout HEAD --` 撤销，未落入提交。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## Round-four deep functional test (2026-08-20) — closed the two NOTES-flagged
## travel-distance gaps, found and fixed a real combat-engine crash

Picked up the two items the original 深度功能测试 pass explicitly disclosed
as "read/designed correct but never live-reached due to travel distance
on a fresh character" (safe-sparring against the real training dummy,
and a real sect-join). Used admin `goto`/`call obj->move(path)` to
close the distance rather than re-deriving anything already covered.

**Item 1 — real safe-sparring against the actual training dummy: REACHED
LIVE, found and fixed a genuine `combatd.lpc` crash.** Registered a
fresh throwaway character (`sjpljy`/真实中文名「秦风演武」, birth family
0), then admin `call sjpljy->move("/u/tian/shaolin/liangong1")`
teleported it straight into the Shaolin 练功房 (the room `liangong1.lpc`
that stocks 2 live clones of `u/tian/shaolin/npc/muren1.lpc`, the actual
in-room dummy — `muren.lpc` itself, referenced in the original pass, is
a same-shape but currently-unloaded sibling file; `muren1` is the one
genuinely reachable and reset into this room). `kill muren` started a
real fight. **This immediately (first exchange) tripped a genuine
runtime crash, repeated 14 times across the fight** —
`执行时段错误：*Division by zero` at `adm/daemons/combatd.lpc:628`, in
`do_attack()`'s combat_exp "bounce" damage-reduction loop, called from
the dummy's own `heart_beat()` → `feature/attack.lpc:attack()` →
`combatd.lpc:fight()`. Root cause: `bounce` starts at
`your["combat_exp"] + 1` and is halved (`bounce /= 2`, integer
division) each loop iteration; once `bounce` reaches `1`, one more
halving drives it to `0`, and the *next* loop-condition evaluation
(`absorb_vic / bounce`) divides by that zero. This reliably fires
whenever the attacker's own `combat_exp` is near its 0 default relative
to the victim's `combat_exp` — exactly the shape of the SECOND dummy
clone in the room (only the one actually targeted by `kill` gets its
`combat_exp` mirrored via `accept_fight()`; the other clone's `heart_beat`
still joins the fight and calls `do_attack()` with its own un-mirrored,
near-zero `combat_exp`) — i.e. a fresh newbie sparring session, the
exact scenario this test was verifying, crashes essentially every time
in the untouched code. This is a real, crash-with-error-signature
programming bug (an integer-division edge case), not content/balance —
fixed by short-circuiting the loop once `bounce` is exhausted:
`while (bounce > 0 && random(100) > absorb_vic / bounce)`. Verified: `update
/adm/daemons/combatd.lpc` recompiled clean (`重新编译...：成功！`), then
continued the SAME live fight (reconnected the test character, `kill
muren` again) for many more rounds including the wimpy auto-flee
trigger firing safely (`看来该找机会逃跑了...` → fled to `庭院`, 气血
stayed 250/250 the whole time) — zero further `Division by zero` (or
any other) errors in `debug.log` after the fix, versus 14 occurrences
before it. **Files modified**: `adm/daemons/combatd.lpc` (1 line changed
+ comment).

**Item 2 — real sect-join: REACHED LIVE, clean, no bug found.** Admin
`call sjpljy->move("/d/wuhan/dragon_hall")` teleported the same test
character to 海鲸帮总舵 (`d/wuhan/dragon_hall.lpc`, which loads
`npc/master.lpc` — 余志枭/Yu Zhixiao). `apprentice master` → confirmed
with `master` a second time (the standard `input_to` two-step
`cmds/std/apprentice.lpc` flow) → completed for real: 余志枭 accepted
unconditionally (not a `betrayer`), `recruit_apprentice()` fired,
character's title changed to `海鲸帮记名弟子`, `score` now shows `你的师
父是余志枭` and "第二代弟子", and the first quest (`将长剑找来给我`) was
assigned exactly as `master.lpc`'s `recruit_apprentice()` codes it.
`debug.log` stayed completely clean through this whole sequence — the
`apprentice`/`recruit` mechanism itself has no bug, matching the
original pass's by-inspection conclusion. No files modified for this
item.

**Item 3 — skill-teacher tuition follow-through: COMPLETED.** With
budget remaining, closed out the previously-disclosed-incomplete 魏柄林
tuition gate. Admin `call sjpljy->move("/d/shandong/ta/ta-shuju")` +
`goto sjpljy` to join the character at 魏家书局, `clone /obj/money/silver`
+ `call silver->set_amount(3)` (value 300, above the `do_learnbook()`
`ob->value() >= 200` gate), then — since `give` requires the recipient
to be `interactive()` or accept via `accept_object()`, and a net-dead
character satisfies neither — reconnected the test character first,
THEN `give silver to sjpljy` from the admin side while it was live.
Player-side `give silver to wei` triggered `wei.lpc`'s `accept_object()`
(`"很好，你自己找位子坐下，准备上课"`), then `ask wei about study` ran
the real `do_learnbook()` lesson end to end: `improve_skill("literate",
...)`, `add("potential", 1)` (confirmed in `score`: 当前潜能 99 → 100),
`delete_temp("can_learn")`. No errors, no crash — the gate and the
lesson both work exactly as designed once genuinely reachable.

**Standard checklist pass** (all previously-fixed items reconfirmed,
none needed re-fixing): §7.90 `config.fluffos` eval-cost already
`5000000`; §7.100 live `replace_program(ROOM);` grep → 0 hits; §7.111
`standard_trace()` already has the `objectp(error["object"]) ?
file_name(...) : "(driver)"` guard; §7.112 — read every exit branch of
`death_stage()` in all 4 files touched by the earlier §7.24 fix
(`wgargoyle.lpc`, `bgargoyle.lpc` have the guard/full reentrancy
pattern; `inn1.lpc`/`yabian.lpc` never implemented `death_stage()` at
all, so the guard doesn't apply to them) — every present/absent/final
branch in both gargoyle files correctly clears
`delete_temp("death_stage_active")` before returning or before the
final revival `move()`, no gap; §7.79 `addn()` — 0 hits in this lib,
not applicable; §7.108 `reconnect()` already calls `enable_commands()`
(fixed in the 2026-08-15 round-two pass); §7.30 `feature/skill.lpc`
accessors already carry the `mapp(x) ? x : ([])` guard (fixed in the
sweep immediately above this section).

Test character `sjpljy`/秦风演武 deleted from `work/data/{login,user}/s/`
after testing, per convention. Driver killed by exact PID after
confirming `cwd` matched this lib's `work/` directory. Admin `fluffos`
save data shows only expected churn (silver clone/give, room location)
from this pass.

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()` (or `reset_me()`
calling `setup()`) chain -- confirmed live via a static scan of every
`init()` body in this lib: 45 NPC/item files call `setup()` directly
or via `reset_me()` from `init()`, after `create()` already called
`setup()` once (which already made the object `living()`). Calling
`enable_commands()` a second time on an already-`living()` object makes
the driver re-invoke that object's own `init()` as a side effect, which
re-enters this same chain while the original call is still on the
stack -- genuine reentrancy, crashing with "Too deep recursion" (most
likely to surface on an NPC's first-ever preload/compile).

`feature/damage.lpc`'s `revive()` calls `this_object()->enable_player()` while the object is still `living()` (kept alive across the disabled interval by `disable_player()`'s own internal re-`enable_commands()`). This confirms a bare `if (living(this_object())) return;`
guard would be the WRONG fix (it would silently break that legitimate
re-enable) -- used the same true reentrancy-flag fix as `mhxy` instead:
a `nosave private int in_enable_player_now;` set for the duration of the
wrapper's body, guarding only genuine same-call-stack reentrancy while
leaving every legitimate re-enable (revive/wakeup/disguise) unaffected.
`feature/command.lpc`'s `enable_player()` had a single fall-through exit
(no early `return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 10 line(s) in 4 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 4 file(s) `inherit F_SSERVER;` and no header defines it (2 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER "/feature/sserver.lpc"` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (1 with the terminator glued to the last text line, 1 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/wuhan/wroad2.lpc`, `u/lark/yangmingzhai/ss.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/arch/tail.lpc`, `cmds/wiz/tail.lpc` call `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 2 of the 2 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 错误处理器自身出错

主控对象 `adm/obj/master.lpc` 的 `report_error()` 用 `CHANNEL_D->do_channel(this_object(), ...)` 把运行错误报到频道，但主控对象没有 `query()`，`channeld` 拿不到 `channel_id`，就去取 `capitalize(me->query("id"))`，即 `capitalize(0)` 出错——没有玩家触发的错误（call_out、heart_beat、加载时）都让错误处理器自己再出错（`Error in mudlib error handler: *Bad argument 1 to capitalize()`），频道上收不到错误报告。照 `sj` 的主控对象补上 `query("channel_id")` 返回 "系统核心"。验证：加载一个出错的 NPC，修改前出现 `Error in mudlib error handler`，修改后错误处理器正常跑完。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py sjpl2 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 1221 个 `.lpc` 和 4 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：1167 -> 1167 通过，无回退；改过的头文件的 148 个包含者 145 -> 145 通过。启动时警告 20 -> 0；新进程登录（新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 4 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 4 个文件，HEAD 与工作树各载入一次无回退（4 objects; HEAD PASS 4, tree PASS 4; regress 0; newly loading 0），这些文件的警告 4 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `u/kyd/npc/luqingdu.lpc`：已给过任务物品时的回话少了 `return`，玩家得不到任何答复；补上。`u/gdjk/hongnong/npc/chigu.lpc` 末尾空的 `else if (exp <= 102000) { }`、`u/xiyu/shanjiao.lpc` 空的 `if (current_water == 0) {}` 删去（行为不变）。
- 改动的对象载入无回退。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮去掉 53 处多余继承（`d/chengdu/npc/cheng.lpc` 在 `NPC` 之外又继承 `F_SKILL` 并重声明它的三张表，muren/jiguan 等多余的 `F_CLEAN_UP`），`scripts/lpc_fix_return_types.py` 改了两把剑的 `query_autoload`；手工两处，能编译的文件警告清零。改动的 13 个对象在 HEAD 与工作树各载入一次：HEAD PASS 7，tree PASS 9，regress 0。

- `d/yangzhou/npc/mouse.lpc` 的闲逛 `(: "random_move" :)` 只是返回字符串，老鼠从不走动；改成真指针 `(: random_move :)`。
- `u/losey/gogoha.lpc`（巫师 losey 的居所）把 `no_steal` 和出口表注释掉，可内层自动注释 `/* sizeof() == 2 */` 的 `*/` 提前结束了外层注释，结尾又写成 `* /`，整个房间编译失败、从没载入过。内层改 `//`、结尾改 `*/`，按作者标出的范围注释，房间载入（只能从 `u/losey/huayuan.lpc` 进来）。
- 不是警告、未改：`d/wuhan/npc/npc.lpc` 是四十来个 NPC 文件首尾相接贴成的一个文件（每段都另有单独文件），`cmds/adm/locate.lpc` 后面贴了一份旧 `globals.h` 和 `score.c`；两者都 `Redeclaration of function` 编译失败，扫描报的其余警告是这个错误的连带。没人引用 `npc.lpc`；`locate` 命令本身因此从来不能用。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。4 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

4 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。6 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。1 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 暗器功夫身上没有对应暗器（2026-10-15）

`bolt-throw`（玉石棋子）和 `fozhu-throw`（玄木佛珠） 的 `query_action()` 先 `present("yushi qizi", me)` 取暗器，再直接调用 `qizi->query_amount()`：throwing 映射到这门功夫、手里拿的却是别的暗器（身上没有这种棋子/佛珠）时，每次出招都报 `Bad argument 1 to call_other()`。数量改为 `objectp(qizi) ? (int)qizi->query_amount() : 0`，兵器判断前补 `!objectp(weapon) ||`，没有对应暗器时退回普通招式。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`iceclaw`→`ice_claw`（`ice_claw`）；`leaf_strike`→`leaf-strike`（`leaf-strike`）；`mizongquan`→`mizong-quan`（`mizong-quan`）；`senluo_force`→`senluo-force`（`fanliangyi-dao`）；`zongzi-force`→`tongzi-force`（`weituo_chu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`wave_step`→`wave_steps`（`bagua-steps`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

95 个文件、122 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/misc/cloth`、`/d/city2/obj/jinduan`、`/obj/armor/tiejia`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 58 个（58 个原来载入不了），没有退步；其余 37 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`F_DEALER` → `/feature/dealer`（28 个文件）、`F_UNIQUE` → `/feature/unique`（19 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：47 个里 10 个通过，其余 37 个还有别的错误（`d/chengdu/boss.lpc`：Undefined variable 'MONEY_D'；`d/chengdu/cdjiulou2.lpc`：Undefined variable 'MONEY_D'；`d/chengdu/jiulou2.lpc`：Undefined variable 'MONEY_D'……）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 36 个对象设了本库没有文件的武功（44 个名字，最多的是 `cuff`、`wenjia-quan`、`shaolin-shenfa`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 20 个通过，其余 10 个停在别的错误上（`d/npc/killer-n`：*No program in object '/d/npc/killer-n'!；`d/wuhan/npc/npc`：*No program in object '/d/wuhan/npc/npc'!……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/chengdu/dao` 的 `south`：`dadao1` → `dadao2`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/mace`（宏 `MACE`）←dtsl2，21 个对象继承它，抽样 8/8 载入；`/std/weapon/rake`（宏 `RAKE`）←dtsl2，5 个对象继承它，抽样 5/5 载入；`/std/weapon/archery`（宏 `ARCHERY`）←dtsl2，2 个对象继承它，抽样 2/2 载入；`/inherit/weapon/bow`（宏 `BOW`）←tiexuejianghu，2 个对象继承它，抽样 2/2 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 14 处、7 个文件：`iceforce`→`ice_force`（14 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 3 处、3 个文件：`::init()`（3 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 2 个：`/d/chengdu/skill/jinshe-jianfa.lpc`、`/daemon/skill/hou_ken.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 12 个：`d/jiaxing/npc/limochou`、`d/npc/killer-n`、`d/xiangyang/npc/dingpopo`、`d/xiangyang/npc/pingpopo`。（`scripts/lpc_transplant_function.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 1 个：`d/xiangyang/npc/muren`。（`scripts/lpc_transplant_function.py`）

## simul_efun 丢了 unew()（2026-10-19，KB 06 §7.262）

`adm/simul_efun/object.lpc` 没有 `unew()`（带“独一无二”次数限制的 `new()`），`d/jiaxing/npc/limochou` 按 xkx 一系的写法调用它，`Undefined function unew`。从同系的 xkxz2 把这个函数原样补回 `object.lpc` 末尾（`scripts/lpc_transplant_function.py`）。这个物件还差宏 `BINGQI_D`（本库的头文件没有定义），所以仍载入不了，属于未定义宏一类，另案处理。

## 全局头文件丢了 3 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `RICH_B`、`PKER_B`、`EXP_B`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/latemoon/in_room/flower1.lpc` 的 `north` 出口：`corridor7` → `backroom`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- 补上 `adm/daemons/moneyd.lpc`（取自带同一份 `feature/dealer.lpc` 的 jqxz2008）和 `include/globals.h` 的 `MONEY_D`：`feature/dealer.lpc` 之前编不过，所有继承 `F_DEALER` 的店主都载入不了

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 钱庄老板和客店留言板（2026-10-19，KB 06 §7.262）

`d/hangzhou/npc/qzlaoban`、`d/suzhou/npc/laoban2`（钱庄老板）`inherit F_BANKER`（`/feature/banker`），档案里没有这个文件，NPC 载入不了；取 xkx100 的 `feature/banker.lpc`（`MONEY_D` 已在上一批补上）。`d/hangzhou/tianxianglou` 和 `d/suzhou/kedian` 开头的 `"/clone/board/kedian_b"->foo();` 指向一块档案里没有的留言板（整个 `clone/board/` 都不在），房间载入不了；这两行删掉（`u/kunlun` 下巫师目录里的留言板调用不动）。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/std/char/kzznpc`（宏 `KZZNPC`）←tiexuejianghu：15/15 个继承它的对象载入，同时带来头文件 `/include/kzznpc.h`、`/include/die.h`
- `/inherit/weapon/weapon`（宏 `M_WEAPON`）←xjcq2000：5/5 个继承它的对象载入
- 玩家打造兵器的模板（7 个文件）这回有了基类，照 KB 06 §7.275 加上没有打造者时的保护（`scripts/lpc_fix_forge_template.py`）。

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 2 个文件，修前 HEAD 载入失败。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/kyd/npc/obj/caidao.lpc`、`/u/kyd/obj/caidao.lpc`。修后与 HEAD 逐个对比载入：这 2 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/u/jakey/obj/origin.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 2 处）。改动：`/d/fuzhou/npc/mei_po.lpc`（1 处）、`/d/wuhan/npc/obj/letter.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/cmds/std/char/npc.lpc`、`/feature/newvendor.lpc`、`/std/char/new_npc.lpc`、`/std/char/newvendor.lpc`、`/std/char/npc.lpc`、`/std/char/vendor.lpc`（等共 7 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（2 个文件，括号里是接住 0 的 efun）：`/cmds/adm/cmaterial.lpc`（`sscanf`）、`/cmds/adm/cpall.lpc`（`read_file`）。加载检查 HEAD 与工作树对照，没有退步。

## 帮会税 `/cmds/adm/ctom.lpc`：档案里没有帮会地盘模块（2026-10-21，KB 06 §7.344）

`/d/chengdu/npc/qiuwa.lpc`、`/d/chengdu/npc/wenlaoban.lpc` 在收钱的 `accept_object()` / 兑换函数里调用 `"/cmds/adm/ctom.lpc"->save_money(..)`（把一半钱记给占着地盘的帮会）。本库没有 `ctom`，也没有 `/clone/misc/area`、`lingpai` 这套帮会地盘模块，玩家付住店钱或兑换时在 `return 1` 之前抛错（客栈老板那一支连 `rent_paid` 都有时来不及设）。调用前加 `file_size("/cmds/adm/ctom.lpc") > 0` 的判断（KB 06 §7.308 的写法），模块以后补上就自然生效。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/daemon/class/taoist/scratmancy/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 24 条注册（11 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/famous.lpc`（`do_bian`、`do_upadm`、`do_upboot`、`do_uplock`）、`/d/city/piggy.lpc`（`do_bian`）、`/d/city/qiyuan.lpc`（`do_pass`、`do_resign`）、`/d/suzhou/liang3.lpc`（`do_jump`、`lingwu`）、`/d/village/npc/seller.lpc`（`do_buy`）、`/d/wuhan/hankou/npc/xiaoboss.lpc`（`do_buy`）、`/std/qitem.lpc`（`do_sing`）、`/std/qitem1.lpc`（`do_cures`、`do_defend`、`do_lookfor`、`do_sing`等）、`/y/city/famous.lpc`（`do_bian`、`do_upadm`、`do_upboot`、`do_uplock`）、`/y/city/piggy.lpc`（`do_bian`） 等共 11 个文件。最多的函数名：`do_bian` 4 处、`do_upadm` 2 处、`do_upboot` 2 处、`do_uplock` 2 处、`do_pass` 2 处。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← fengyun434：`check_control()`（1 处调用）、`check_length()`（5 处调用）、`check_return()`（1 处调用）、`check_space()`（1 处调用）、`check_chinese()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 3 个函数没有补（inquiry 3）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/yangzhou/npc/woman1.lpc`:`about_he`、`/y/city/npc/heyunfeng.lpc`:`about_he`、`/y/city/npc/heyunfeng.lpc`:`about_yang`。 另有 1 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。
