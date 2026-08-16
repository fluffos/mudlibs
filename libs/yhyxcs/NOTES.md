# 银河英雄传说.zip → `yinhexiongxiongchuanshuo`

- Archive: `银河英雄传说.zip` (from the 2026-07-29 bulk `mudlib.rar` drop,
  not the original numbered archive batch). ES-II-lineage MudOS lib
  (`master.c` header: "for ES II mudlib, original from Lil, rewritten by
  Annihilator (11/07/94)") reskinned as a sci-fi setting based on the
  novel/anime *Legend of the Galactic Heroes* (银河英雄传说) — 2001-era
  snapshot (file dates Aug 2001), ships a Windows `mudos.exe` binary
  (ignored; this repo always uses its own driver).
- Mudlib root in archive: `new/` (one level down from archive top).
- No shipped config file at all (unusual for this collection — most
  archives ship *some* `config.*`); `config.fluffos` reconstructed from
  scratch using another lib's config as a template + this lib's own
  `master file`/`simulated efun file` paths.
- Port: **40104**.

## Status: DONE — boots clean, full registration with a real Chinese name verified, playable

## What was fixed

1. Standard encoding (GB18030→UTF-8, 786 converted) + `.c`→`.lpc` rename
   (834 files) via `convert_lib.sh`; 134 literal `.c` refs fixed
   automatically.
2. **§7.3 class**: `master.lpc`'s `create()` had the old MudOS
   force-reload trick — `efun::destruct(find_object(SIMUL_EFUN_OB))`
   followed by `call_other(SIMUL_EFUN_OB, "???")` to force a recompile.
   Segfaults this driver instantly on boot (raw C++ stack dump, master_ob
   not yet set during its own `create()`). Deleted; serves no purpose here.
3. **§8.1 class**: `adm/simul_efun/chinese.lpc`'s `is_chinese()` used the
   GBK lead-byte range test (`str[0] > 160 && str[0] < 255`) — never true
   for a real Unicode codepoint. Fixed to `str[0] >= 0x4e00 && str[0] <=
   0x9fff`. `adm/daemons/logind.lpc`'s `check_legal_name()` had the
   matching byte-oriented bugs: a `strlen(name) < 2 || > 12` bound (should
   be 1-6, the error message already says "一到六个中文字") and an
   `i%2==0` sliding-window gate that only ever tested every OTHER
   codepoint (landing on what used to be GBK lead bytes) — dropped the
   `i%2==0` gate entirely and fixed the bound to 1/6. Verified: real
   Chinese name 秦风二 now registers correctly end-to-end into the game
   world (previously any Chinese name would have been rejected).
4. **Pre-existing archive typo**: the whole `/feature/` tree (skills,
   damage, movement, etc. — inherited by `std/char` and dozens of other
   files) was shipped on disk as `/teature/` (not `/feature/`) — a typo
   baked into the original archive's directory name, invisible on the
   original case-insensitive Windows filesystem, fatal here. Renamed the
   directory; fixed ~745 of 745 initial "Inherited file does not exist"
   compile failures in one move (745 fail → 24 fail).
5. `/obj/id_card.lpc` and `/obj/task/id_card.lpc` (identical duplicate
   content, different locations) both declare `void geton_taxi(...)` but
   `return 1;` from two early-exit branches inside it — hard compile
   error on this driver (old MudOS tolerated returning a value from a
   void function). Changed both to bare `return;`. This was also the root
   cause of a reproducible "Too deep recursion" in
   `securityd.lpc:143`/`valid_write()` on nearly every `quit` and
   registration — the never-successfully-compiled `/obj/id_card` object
   kept getting reloaded/retried inside a security check, tripping the
   recursion guard instead of a clean compile error. Fixing the compile
   error resolved the recursion on `quit` for a normal player id_card.
6. Admin seeding (AGENTS.md §1.5): registered `fluffos` through the
   normal flow, appended `fluffos (admin)` to `adm/etc/wizlist` (this
   lineage's `securityd.lpc` reads it directly, and `/` is already in
   `trusted_write` for `(admin)`/`(arch)`, so no separate ACL table
   needed). Verified: `update /obj/id_card` succeeds as `fluffos`.

## Known issue, NOT fixed (logged per §7.15's spirit, not blocking)

`feature/dbase.lpc`'s `query(prop)` falls through to
`default_ob->query(prop, 1)` when a property is undefined locally and
`default_ob` is set (a prototype/template-object pattern used broadly by
this lineage for NPC/item base classes). `/obj/login.lpc`'s
`query_save_file()` calls `query("id", 1)` and reproducibly hits "Too
deep recursion" in `securityd.lpc`'s `valid_write` on **every** login
object's save (both mid-registration and normal reconnect) — but it is
NOT fatal: the farewell message still prints and the save file is still
written correctly (confirmed: `data/login/q/qinfengtest.o` and
`data/user/q/qinfengtest.o` both exist and are loadable on relogin). Did
not chase down which specific object's `default_ob` chain is implicated
(this is a shared/global mechanism touching many files) — real fix would
need auditing every `set_default_object()` call site for a cycle or
self-reference; out of scope for a first bring-up pass. Cosmetic log
noise only; does not affect play.

## 深度功能测试 / Deep functional test (AGENTS.md §10.7)

Not a wuxia lib — sci-fi *Legend of the Galactic Heroes* (银河英雄传说)
theme, confirmed by reading source directly (no `doc/help/` tree shipped
at all in this archive — `HELP_DIR` topics file doesn't exist, so newbie
orientation came from `README.md`/`NOTES.md` plus tracing
`adm/daemons/logind.lpc::init_new_player()`/`enter_world()` and the
`d/phezzan/` room tree). One continuous session, real Chinese-named
account (`qintestcc` / 秦风测, password `TestPass123`), `look`/`score`/`i`
at every state change:

1. **Registration**: id → confirm → Chinese name (rejected an ASCII-only
   English id first, as expected) → password ×2 → email → gender → into
   `START_ROOM` (`/d/phezzan/starport`, 费沙中央宇宙港), matching
   README's stat set exactly (力量/胆识/才智/统率/沉着/魅力/体格/运气,
   实战/格斗经验 split). Same pre-existing, non-blocking
   `securityd.lpc`/`feature/dbase.lpc` "Too deep recursion" noise
   documented above reproduced twice on this pass too (still cosmetic,
   still doesn't block anything).

2. **§7.90 new instance, found live, not by static grep**: the test
   character's very first `look` command — which lazily compiled
   `/cmds/usr/look.lpc`, `/feature/s_attribute.lpc`, `/std/char/rank.lpc`
   and friends for the first time on this boot — hit `Eval interrupted:
   object d/phezzan/starport cost limit reached, limit: 700000 usec` /
   `执行时段错误: *Too long evaluation. Execution aborted.` at
   `/feature/dbase.lpc:266` (the same `default_ob` fallback chain as the
   documented recursion issue, but this time exhausting the full
   eval-cost budget before the recursion-depth guard could catch it —
   FluffOS charges first-time lazy-compilation cost against the calling
   context, and this lib's `700000` ceiling was too tight to absorb a
   cold-boot compile burst plus one `dbase.lpc` fallback in the same
   tick). The room description itself still rendered correctly to the
   player — silent/invisible exactly per §10.7's premise. **Fix**: raised
   `maximum evaluation cost` in `config.fluffos` from `700000` to
   `5000000` (matching this session's `zzhj`/`xixingzhanji`/`zjdyaryl`
   precedent, §7.90). Verified: killed the driver, rebooted, registered a
   second fresh character (`qintwob`/秦风乙) from a cold boot (so
   `look.lpc`/`std/room.lpc`/`id_card.lpc` etc. all lazily compiled again)
   — zero `Eval interrupted`/`Too long evaluation` lines in `debug.log`
   this time (`grep -c` = 0), only the pre-existing recursion noise.
   `maximum call depth : 30` (driver default 150) was left untouched —
   it's what makes the `default_ob` recursion resolve as a *fast*,
   harmless guard-catch rather than a slow burn, and the prior pass
   already made an explicit, reasoned decision not to chase the
   underlying `default_ob` cycle itself; not re-litigated here.

3. **§7.11, second instance this pass**: `adm/simul_efun/file.lpc`'s
   `log_file()` called `write_file(LOG_DIR + file, text)` directly with
   no `assure_file()` guard, even though this file defines its own
   `assure_file()` two functions down — same shape as `zzhj`/`xajhxo`
   etc. this session. `LOG_DIR` (`/log/`) doesn't exist in a fresh
   checkout (gitignored runtime dir). `logind.lpc::enter_world()` calls
   `log_file("USAGE", ...)` on **every** successful registration and
   login — did not reproduce as a hard crash on THIS lib specifically
   (this driver's mudlib error handler + `securityd.lpc`'s own already-
   fragile `valid_write` swallowed it into more of the same recursion
   noise rather than aborting registration outright), but it's the exact
   same latent bug class and was silently no-op'ing the USAGE log every
   time. **Fix**: `assure_file(LOG_DIR + file)` before the `write_file()`
   call, plus a one-line forward declaration (`assure_file()` is defined
   textually after `log_file()` in the same file). Verified:
   `work/log/USAGE` now gets created and correctly appended
   (`qintestcc was created from 127.0.0.1 (...)`, `fluffos loggined from
   127.0.0.1 (...)`) — did not exist as a possibility before the fix
   since the directory was never created.

4. **Safe-sparring mechanism**: read `cmds/std/fight.lpc`/`kill.lpc`
   before assuming anything — turns out this lineage uses the exact same
   `can_speak`/`accept_fight()`/`fight_ob()` vs `kill_ob()` convention as
   the wuxia-family ES2 siblings tested elsewhere this session (same
   engine, just reskinned) — `fight` is the non-lethal "点到为止" spar
   (stamina only, no real injury, per its own help text) and `kill` is
   real combat; both gated by `environment(me)->query("allow_fight")`.
   **Notable, NOT a bug**: only **one** room in the entire `d/` tree sets
   `allow_fight` (`d/phezzan/earth_antehall.lpc`), and its only NPC
   (`earth_monk`, a hostile "地球教徒" cultist) attacks on sight via
   `kill_ob()` in its own `init()` before a player ever gets a command
   prompt — confirmed by walking the admin character in there: it
   auto-fought back, took real damage, and died (`sethp hp==5000` fired
   too late). This reads as intentional "hostile cult guard" quest
   content (fits the Terra-cult antagonist lore), not a broken
   spar-room — but it does mean there's no NPC anywhere that offers a
   truly walk-up-and-`fight` safe spar out of the box. Verified the
   `fight_ob()` mechanic itself works correctly and safely by using the
   admin's `call <obj>-><func>(<args>)` wizard tool (this lib's only
   `cmds/wiz/` general-purpose object-mutator, effectively its "eval") to
   temporarily set `allow_fight` on `/d/phezzan/winter_library` (already
   the location of a friendly, `can_speak` NPC — see below), then had the
   test character `fight n.b` (博尔德克/Boltic): mutual `fight_ob()`
   exchange, ended cleanly with "今日点到为止，我们下次再比试！", no HP
   loss, only stamina — reverted `allow_fight` back to unset on both
   rooms touched afterward (runtime-only property, not persisted to
   disk, so this was a pure in-memory test scaffold, not a code or save
   change).

5. **Faction/rank acquisition, organic path — fully verified,
   end-to-end**: `apprentice <npc>` at `/d/phezzan/npc/boltic.lpc`
   (尼古拉斯·博尔德克, 帝国驻在事务官, reachable from `START_ROOM` via
   `north×7, west×3, north, northup, east, north×2, east` through the
   费沙 winter palace — `boltic.attempt_apprentice()` directly issues
   `command("recruit " + id)` on itself, i.e. it always accepts).
   Result: `score` went from 【普通公民】to 【费沙武官】, "现任费沙自治领
   低级幕僚，官阶列兵"/"你的直属上司是尼古拉斯·博尔德克", a `uniform.lpc`
   (费沙军服) was written to `data/login/q/qintestcc/` and cloned into
   the player's inventory. Contrast: the higher-ranked `fuguan.lpc`/
   `blackfox.lpc` NPCs' `attempt_apprentice()` unconditionally refuse
   ("以你现在的实力恐怕还不足以成为我的手下") — that's a deliberate
   score/rank gate on the higher-tier recruiters, not a bug (only
   `boltic`, the lowest-generation recruiter, accepts newcomers
   unconditionally, which is exactly the newbie on-ramp you'd expect).

6. **Admin shortcut path — genuinely does not exist, checked
   honestly**: grepped `cmds/wiz/`, `cmds/adm/`, `cmds/arch/` for any
   rank/family/skill grant command — none. `cmds/adm/promote.lpc` only
   changes *wizard* status (`(player)`→`(admin)` etc.), not in-game
   faction/rank. `cmds/adm/sethp.lpc` (`sethp <prop>==<value>`, sets an
   arbitrary property on the admin's own body) and `cmds/wiz/call.lpc`
   (`call <obj>-><func>(<args>)`, arbitrary `call_other`) are the closest
   things to a generic admin toolkit and were used above for test
   scaffolding, but neither is a dedicated "grant faction/rank" shortcut
   — the organic `apprentice`/`recruit` path above is the only way any
   character (including staff) joins a 势力 in this lib.

7. **`quit` → `debug.log` → real reconnect → persistence confirmed**:
   no new-account-quit-deletes-account grace period found in
   `cmds/usr/quit.lpc` (plain save + destruct, no lockout timer), so a
   normal `quit` was used directly. `debug.log` after quit showed only
   the pre-existing recursion noise. Killed the driver
   (`config.fluffos` change requires a restart to take effect), rebooted,
   did the NOTES.md write-up in between for a real wall-clock gap, then
   reconnected as `qintestcc` with a fresh `nc` session after the reboot:
   password accepted, `score` on landing showed 【费沙武官】秦风测 with
   the family/rank/uniform state fully intact — confirms both the
   registration fix and the faction-join state survive a real disconnect
   + driver restart + reconnect cycle.

Cleanup: deleted the `qintestcc`/`qintwob` test-character save files
under `data/{login,user}/q/` before committing; reverted the admin
(`fluffos`) save-file drift caused by the `earth_antehall` death (HP/
stamina/score fields) back to its pre-test committed state via `git
checkout --` (no revision) since it's incidental test drift on a shared
account, not an intended change.

**WASM**: unverified under WASM this pass — `curl -sS
"$HTTPS_PROXY/__agentproxy/status"` confirms emsdk's
`storage.googleapis.com` dependency is still proxy-denied; not retried.
Both fixes above (§7.11, §7.90) are plain LPC/config changes with no
WASM-specific code path, so they're expected to carry over cleanly
whenever WASM verification becomes possible, consistent with this
archive's `wasm_status: playable` from the prior pass.

## Not yet done (out of scope for this pass)

WASM export / GitHub Pages packaging — deferred to a later batch pass
across all newly-added libs.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES II 血统，独立档案（来自 2026-07-29 批量上传的 mudlib.rar）；游戏内重新包装成了银河英雄传说题材。之前一次会话对原生驱动的适配过程（记载在这份档案自己的 NOTES.md 里）已经修好了 master.lpc 的 create() 里那个会段错误的强制重新加载技巧、标准的 §8.1 GBK 字节区间 is_chinese()/check_legal_name() bug、/teature/ → /feature/ 的目录名拼写错误，以及 id_card.lpc 里一处 void 函式却 return 了值的编译错误，还播种了 fluffos (admin) 的 wizlist 条目——这些都没有在本轮重做。这次 WASM 修复覆盖了剩余的 §7.x 类检查：（1）三个碰 socket 的精灵（adm/daemons/ftpd.lpc、adm/daemons/network/ftpd.lpc、adm/daemons/network/dns_master.lpc）都完全处于休眠状态——在 adm/etc/preload 里被注释掉，而 DNS_MASTER 仅有的两个呼叫者（cmds/adm/shutdown.lpc、cmds/wiz/mudlist.lpc）都是巫师指令，已经带有 find_object() 检查保护——保持原样，不需要掏空。（2）master.lpc 的 valid_read() 本来就无条件回传 1（完全没有转发给 SECURITY_D，所以那种 new() 注册卡死的 bug 模式在这里不适用）；还是在 valid_write() 上加了标准的 'user == this_object()' 短路判断，和本次会话其它档案保持一致。（3）§7.50 类的 is_killing(object) 对 is_killing(string id) 修复了 cmds/std/surrender.lpc 里唯一一处呼叫点。is_chinese()/check_legal_name() 本来就已经正确（在更早的原生启动那一轮修好了，本轮没有重新处理）。原生启动那一轮留下的唯一悬而未决问题——securityd.lpc 的 valid_write() 里一个不会阻断的'Too deep recursion'，在每一次登录物件存档时都会通过 feature/dbase.lpc 的 default_ob 兜底链复现——在 WASM 下再次复现（错误签名/行号完全一致），依然只是外观问题：注册、进入游戏世界、以及 quit 都能围绕它正常完成。注册流程在格式化前后都用一个真实的中文名字完整验证过（id→y 确认→中文名字→密码+确认→电子邮件→性别→进入费沙中央宇宙港）。管理员权限已通过既有的 fluffos/Mud@2026 凭据确认：'目前权限：(admin)'。LPC 格式化工具对全部 834 个档案运行（写入 821 个，2 个转档之前就存在的错误，11 个未改动）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选，没有 CJK 重新加空格/转义损坏命中。

## 深度功能测试第二轮 / Deep functional test round 2 (2026-08-15, post driver-upgrade re-test)

Round-two re-verification against the current native `build-debug` driver
(post-upgrade — pulls in PRs #1343/#1344 and the corpus-wide `%`-operator
float-crash fix). Standard checklist + live playthrough-style verification.

Findings:

1. **AGENTS.md §7.108** (`obj/user.lpc`'s `reconnect()` missing
   `enable_commands()`): this lib has the kick-duplicate-login pattern
   (`exec(old_link` in `adm/daemons/logind.lpc`, calling `user->reconnect()`
   on the character body). `reconnect()` lacked `enable_commands()` as its
   first statement, so confirming "y" to kick out an already-connected
   duplicate session would reconnect into a permanently non-interactive
   character. Fixed by adding `enable_commands();` as the first line.
   Live-verified with two concurrent telnet sessions: session 2 logged in
   as `fluffos`, confirmed the "赶出去，取而代之吗？(y/n)" prompt with `y`,
   and the resulting session correctly dispatched `look` (real room
   description) and `score` (real stat panel). Note: a separate, unrelated
   `obj/connection.lpc` also defines a `reconnect()` with the same missing
   shape, but it is dead code (not referenced anywhere else in the tree,
   not part of the `logind.lpc` call path) — left untouched.
2. **AGENTS.md §7.10** (`adm/obj/master.lpc`'s `log_error()`): had no
   compile-severity filter at all — every message, including routine
   compile warnings, was unconditionally written to the admin's screen via
   `efun::write()`. Added the standard `strsrch(message, "arning:") == -1`
   guard.
3. **`adm/simul_efun/file.lpc`**: `cat()`'s `write(read_file(file))` had no
   null-guard; changed to `write(read_file(file) || "")`. `log_file()`
   already correctly called `assure_file()` first — no change needed there.
4. **Already correct, no change needed**: `cmds/wiz/update.lpc` (only
   `update.lpc` in this lib) already has the `environment(me) &&` guard.
   No `adm/daemons/closed.lpc` exists in this lib's tree, so AGENTS.md
   §7.107 does not apply. `maximum evaluation cost` was already
   `5000000`.
5. **Recurrence of a previously-documented cosmetic issue** (see this
   NOTES.md's own WASM-pass section above): the non-blocking "Too deep
   recursion" during `securityd.lpc`'s `valid_write()` → `feature/dbase.lpc`
   `default_ob` fallback chain reproduced again on every login-object save
   during this round's admin login (`program: /obj/login.lpc, object:
   /obj/login#0, file: /obj/login.lpc:33`), exact same signature as
   before. Confirmed again to be purely cosmetic — login, `update`,
   the reconnect test, `look`, and `score` all completed normally around
   it. Not re-chased, per the prior pass's own conclusion.

Live verification summary: booted the native driver on port 40104 (clean
boot, only pre-existing unused-variable warnings, no fatals;
`Initializations complete` / `Accepting telnet connections` both printed).
Logged in as the seeded `fluffos` admin (`Mud@2026`), confirmed real write
access via `update /adm/simul_efun/file` (recompiled successfully). Ran
the two-session kick-duplicate-login reconnect test described above and
confirmed the §7.108 fix live. No new fatal errors in the driver's console
output (the pre-existing `debug.log` file itself is stale, dating to an
earlier pre-`.lpc`-conversion bring-up session — this boot's output was
captured separately and showed nothing beyond the known cosmetic
recursion note above). Killed the driver by exact PID when done.

本轮修改的文件 / Files modified this round:
- `libs/yhyxcs/work/obj/user.lpc`
- `libs/yhyxcs/work/adm/obj/master.lpc`
- `libs/yhyxcs/work/adm/simul_efun/file.lpc`
