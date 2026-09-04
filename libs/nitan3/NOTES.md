# nitan3 — 泥潭三 (git-hosted duplicate of `nitan_san`)

Source: `git clone https://github.com/mudchina/nitan3` (commit `6f6d92f`,
cloned 2026-08-25). Port: **40217**. Number: **169**. Status: **done,
confirmed duplicate** (boots clean, full registration flow verified
end-to-end with real Chinese names, reaching an actual game room).

## Duplicate check (done BEFORE the fix pipeline, per task instructions)

This lib is a **byte-identical duplicate of `nitan_san`'s raw archive**
(`archives/泥潭三.rar`, archive #61, port 40055) — confirmed, not
merely suspected, via direct comparison before investing in the full
conversion pipeline:

- File-list diff (`find | sort`, excluding `.git`): nitan3's raw clone
  has 15,237 files, `nitan_san`'s raw archive extract (`raw/nitaniii/`)
  has 15,252 — the only differences are one `.gitignore` (an artifact of
  this being a git repo, not present in a `.rar`) and 16 empty/log
  placeholder files under `nitan_san`'s own `log/` tree accumulated
  during ITS testing history (never part of the original archive).
- **Full-content md5sum comparison of all 15,236 shared files: 15,235
  are byte-identical.** The lone exception is `config.cfg`, which
  differs by exactly one cosmetic string — `mudlib directory : e:/nitan3`
  vs `e:/nitaniii` (and the matching `binary directory` line) — a
  leftover Windows folder-name artifact from whoever originally
  packaged each copy, not a code or content difference.
- `adm/single/master.c` (this lineage's actual master file, not the
  decoy `feature/master.c`/`adm/daemons/story/master.c` copies) is
  byte-identical (md5 `28de08a80a8c764528b1b935c05fdbf8`) between this
  clone and `nitan_san`'s raw archive.
- `nitan_san`'s own NOTES.md already documents that its snapshot
  self-identifies internally as `nitan.3`/"泥潭三"/"Nitan III" — i.e.
  `nitan_san` **is** "Nitan 3" under this project's own prior
  terminology; this GitHub repo (named literally `nitan3` by the
  `mudchina` org) is not a coincidentally-similar sibling, it is the
  same snapshot, git-hosted instead of `.rar`-packaged.

**Conclusion: genuine duplicate, not a distinct game.** Per this
project's standing convention (AGENTS.md's `duplicate_of` field), this
is still fully recorded — own slug/number/port, own `work/` tree,
`meta.json` with `"duplicate_of": "nitan_san"` — rather than silently
skipped, and the full onboarding pipeline (steps 3-13) was run to
completion below.

## Conversion

`scripts/convert_lib.sh libs/nitan3/raw libs/nitan3/work` (GB18030 default):
13,557 files converted 0-error (496 already UTF-8, 14,713 converted, 27
lossy — same three `help/` files flagged lossy as any GBK archive this
size typically has, cosmetic doc text, not code), 13,557 `.c`→`.lpc`
renames, 6,891 literal `.c"` reference fixups, 17 `#include <...c>`
fixups, 33 local angle-bracket→quote include conversions, 104
`static`→`nosave` fixups.

## Fixes: ported wholesale from `nitan_san`, not re-discovered

Since the raw content is confirmed byte-identical, rather than
re-running `nitan_san`'s entire multi-session bug-discovery process from
scratch, its **already-fixed, already-reformatted, already boot-tested**
`work/` tree was synced directly onto this fresh conversion:

```
rsync -a --delete \
  --exclude=/.git --exclude=/.gitignore \
  --exclude=/data/login --exclude=/data/user \
  --exclude=/log --exclude=/dump --exclude=/doc/dump \
  --exclude=/trace_lpcc.json \
  libs/nitan_san/work/ libs/nitan3/work/
```

This one operation reproduced every one of `nitan_san`'s NOTES.md fix
items automatically (verified via a post-sync `diff -rq`, which came back
clean except for the intentionally-excluded runtime/save directories):
the CJK-codepoint `is_chinese()`/`check_legal_name()`/`named.lpc` rewrite,
`securityd.lpc`'s `load_object`/`recompile_object`/`include` early-allow,
`master.lpc`'s `get_include_path()`, the `LONELY_IMPROVED` dead-efun
guards including the from-scratch `adm/simul_efun/bignum.lpc` arbitrary-
precision arithmetic library (a hard `simul_efun.lpc` compile-blocker
without it), `inherit/misc/quest.lpc`'s `set_information` signature
widening, `timed.lpc`/`ntefun.lpc`'s bare-`array` declarations,
`message.lpc`'s `exclude || ({})` guard, `clone/user/user.lpc`'s
`is_killing` type-fix, `eventd.lpc`/`storyd.lpc`'s `.lpc`-rename-width
fix, `d/city/npc/paimaishi.cc`→`.lpc` rename, the `assure_file()`
missing-directory fixes (`toptend.lpc`, `file.lpc::log_file()`,
`master.lpc::log_error()`), the §7.100 `ROOM` redundant
`replace_program()` sweep (3,252 files), the §7.112 `death_stage`
reentrancy guard, the §7.30 uninitialized-mapping accessor sweep, the
WASM-era loopback-allow / `uptime()`-grace-bypass / fail-closed
`band.lpc` retrofit, and the full `format-corpus.mjs` reformat pass —
all inherited in one step. See `libs/nitan_san/NOTES.md` for the
original per-item rationale; not re-derived here.

**Confirmed NOT ported and not needed**: `nitan_san`'s own accumulated
test/admin player-save data (`data/login/`, `data/user/`) and logs —
explicitly excluded from the sync so this lib gets its own fresh
registration/admin-seeding pass (below), not a copy of `nitan_san`'s
account state.

## New fix found on THIS lib (not present in `nitan_san`'s history)

**`adm/single/master.lpc`'s `log_error()` — missing `seteuid(ROOT_UID)`
re-elevation after `assure_file()`, same privilege-ordering bug already
fixed in `adm/simul_efun/file.lpc`'s `log_file()`.** `assure_file()`
resets the caller's euid back to `getuid()` as its own cleanup step; any
caller that needs to write immediately afterward must re-elevate.
`file.lpc::log_file()` already had this fix (ported in via the rsync
above, with an explanatory comment already documenting the bug class).
`master.lpc::log_error()` had the `assure_file(home + "log")` call (also
ported in — this is `nitan_san`'s own item covering the third
`assure_file`-needing call site) but was NEVER given the matching
re-elevation, because **`nitan_san`'s own `work/log/log` file already
existed from its multi-session testing history**, so `assure_file()`'s
`file_size(file) != -1` short-circuit always skipped the vulnerable path
there — this bug was latent and unreachable on `nitan_san`, but
immediately live on a genuinely fresh `work/log/` directory (this lib's
own, since `log/` was deliberately excluded from the sync). Symptom:
every single compiler warning during preload (this driver routes
warnings through `log_error()`, not just real errors — the game's own
`/log/log` warning-log file) failed `*Wrong permissions for opening file
/log/log for append`, looping indefinitely since the target file could
never actually get created. Fixed identically to `log_file()`: added
`seteuid(ROOT_UID);` immediately after `assure_file(home + "log");`,
before the `write_file()` call. Verified fixed: `/log/log` now exists
and accumulates warning text correctly across a full preload + test
session.

**Residual, not chased further**: 7 of the many `log_error()` calls
during a from-scratch preload still hit `Wrong permissions for opening
file /log/log for append` even after the fix (down from an unbounded
retry storm to a fixed, small, non-blocking count) — cause not fully
isolated (didn't reproduce with more diagnostic instrumentation within
this pass's time budget; possibly a narrow reentrancy window during the
very first few file compiles before `SIMUL_EFUN_OB` is resident). Does
not block boot, does not recur during actual gameplay (post-preload),
and `/log/log` itself ends up populated correctly regardless. Flagged
here for whoever next touches this file.

## Compile-sweep: skipped, matching `nitan_san`'s own precedent

13,557 `.lpc` files — the same mega-lib bracket `nitan_san` (13,559
files) and `nitan_ceshi` (13,497 files) already established as risky for
a full `lpcc --batch` sweep (AGENTS.md §10.4: "a mega-lib sweep can eat
all host RAM... on mega-libs the boot + interactive test is the
sufficient verification gate; the sweep is nice-to-have"). Host memory
during this pass ranged from 21Gi down to ~2.7Gi available while the
driver + test client were live — not worth risking a full batch compile
of the same size class that has already twice been documented eating a
23GB host down to sub-1GB free. Skipped per the same policy `nitan_san`
used; the boot + full registration/quit/reconnect/admin-`update` test
below is what actually found and fixed the one real bug in this pass
(the `log_error()` euid issue, itself a `simul_efun`/`master`-adjacent
class of bug a sweep wouldn't have caught any faster than the boot did).

## Boot + interactive test

`~/src/fluffos/build-debug/src/driver config.fluffos` (cd'd into
`libs/nitan3` first). Preload completed and port 40217 listened cleanly
on the very first boot after the `log_error()` fix (a first attempt
before that fix also fully preloaded and listened — the euid bug is
non-fatal, just noisy). `log/debug.log`: zero real compile
errors/undefined-functions/bad-arguments/illegal-operations/syntax
errors across ~4,700 lines generated over the whole test session — only
the universal harmless `Unknown #pragma, ignored.` warning (every file
in this lineage emits it once) and the residual `Wrong permissions`
noise documented above.

Full registration flow (`scripts/mudclient.py`), matching `nitan_san`'s
own documented transcript almost line-for-line (same banner: 《終極魔界》
"Ultimate Demon Realm" skin over the "泥潭"/nitan engine, same
"泥潭三已经执行了..." uptime line, same GB/BIG5 pre-id prompt):

- **Admin registration** — id `fluffos`, surname/given-name 浮/浮
  (confirmed via the "姓名相同" full-name-confirmation prompt, same as
  documented for `nitan_san`), admin password `Mud@2026admin`, normal
  password `Mud@2026`, gender `m`. Landed immediately at **`(admin)`**
  status (`目前权限：(admin)`) in 巫师休息室 (wizard lounge) — the
  `adm/etc/wizlist` entry granting `fluffos` admin was already present,
  carried over automatically by the `nitan_san`-sourced sync (this is a
  config/data file under `work/`, legitimately part of the ported source
  tree, not player save state).
- **Normal player registration** — id `qinfengiii`, surname/given-name
  秦/风 (a real two-character Chinese name), gender `m`: reaches
  **注册房间** (registration room) with correct 十大富翁/十大高手
  rankings display, `look` correctly re-displays the room. Reconnect
  (restore) path verified: disconnecting and reconnecting with the same
  id/password produces `这个角色已经存在，请输入该角色的密码` →
  `重新连线完毕` and returns to the same room state.
- **`quit` gate, both branches**, verified on this same account: `n`
  correctly cancels (`您选择了放弃退出(quit)，继续游戏。`); a second
  `quit` → `y` correctly deletes the still-new account
  (`您选择了放弃该帐号退出泥潭，档案被删除`) — the standard
  anti-throwaway-account retention gate this whole lineage shares
  (intentional game design, not a bug — matches `nitan_san`'s own
  documented behavior).
- **Full birth continuation** — a second player, id `qinfengsan`,
  surname/given-name 秦/岭, gender `f`: `register test15@qq.com` from
  注册房间 correctly advances into **生命之谷** (Valley of Life), with
  盘古 (Pangu) greeting the player BY THEIR REAL REGISTERED NAME
  (`盘古说道：秦岭，你快快选择(choose)好角色性格，然后投胎去吧！`) —
  an exact match to `nitan_san`'s own documented transcript for the
  identical continuation step. `score` before this point (in 注册房间
  or 生命之谷, prior to actually completing the `choose`+投胎 birth
  ritual) correctly replies `还没有出生呐，察看什么？` ("not born yet,
  what are you looking at?") — confirmed as this lineage's intentional
  design gate (same as `nitan_san`'s own scope, which also stopped
  short of a full birth+score for its player-flow test), not a bug; this
  test account's `.o` save files were removed before commit (see below).
- **Admin write-access verification** (§1.5 standard check): logged in
  as `fluffos`, ran `update /adm/daemons/band.lpc` → `重新编译
  /adm/daemons/band.lpc：成功！` (success). Reconnecting afterward
  returns cleanly to 巫师休息室 with no quit-confirmation issue.

**Not tested this pass** (same "long tail, record don't chase"
convention as `nitan_san`'s own NOTES.md): combat, sect/门派 systems,
门派任务, the random-delivery-quest subsystem's known-but-unfixed `/
inherit/item/combined` "No program" background-daemon error (inherited
from `nitan_san`'s own documented finding, not re-verified here since
it's off the tested path and non-blocking).

## Save data committed

Only the seeded `fluffos` admin account (`data/login/f/fluffos.o`,
`data/user/f/fluffos.o`) is committed, matching `nitan_san`'s own
convention exactly — every other a-z login/user bucket directory is
preserved via an empty `.donotdelete` placeholder (git doesn't track
empty directories) rather than committing throwaway test-account saves.
The `qinfengiii` test account self-deleted via the `quit`/`y` flow
above; the `qinfengsan` test account's `.o` saves were manually removed
before staging.

## Admin account / 管理员账号

- **id**: `fluffos`
- **普通密码 / password**: `Mud@2026`
- **管理密码 / admin(recovery) password**: `Mud@2026admin`
- **中文名 / display name**: 浮浮 (姓浮名浮)
- **权限 / level**: `(admin)`, via `adm/etc/wizlist` (already present,
  carried over from `nitan_san`'s own seeding).

> 警告：对外公开架设前请务必修改这两个密码。

## WASM status update (2026-08-25, another session)

Promoted `wasm_status` from `""` to `playable`. Hit a real, non-trivial
bug the earlier prediction above didn't anticipate: `adm/daemons/
versiond.lpc`'s `in_server()` (called from `create()`) unconditionally
calls `socket_create()`/`socket_bind()`/`socket_listen()`, undefined on
this driver build (no `sockets` package). Regular player logins never
touch this file, but admin-rank login does (`logind.lpc`'s
`catch(enter_world(ob, user))` around entry ends up loading it), and
since the whole file fails to compile, the `catch()` fires and shows
"你无法进入这个世界，可能你的档案出了一些问题" -- non-fatal (the
player recovers into the normal room right after) but a real, visible
defect on every admin login.

Fixed per this project's established "sockets package absent" pattern
for a large multi-purpose daemon (33 other files call into this one
for non-socket functionality, so the whole file stays loadable — only
the 11 functions actually touching a real `socket_*`/`socket_address()`
call were gutted to no-ops/always-fail). Verified with a full scripted
WASM session: login as `fluffos`/`Mud@2026`, no more crash/error,
`look` reaching 巫师休息室 cleanly. `score`/`quit` weren't recaptured
distinctly in this transcript but both are already thoroughly verified
under native testing above (including both `quit` confirmation
branches) and untouched by this fix.

**This exact same bug was independently confirmed still present in
`nitan_san`** (the sibling this lib is a confirmed duplicate of,
byte-identical `versiond.lpc`) despite its `wasm_status` already being
`playable` from an earlier pass — that pass never exercised an
admin-rank login, so the crash went undetected. Patched `nitan_san`'s
copy identically as part of this same pass; see its own NOTES.md.

## 深度功能测试（§10.7）

No independent playthrough under this slug. This tree is a confirmed
byte-identical duplicate of `nitan_san` (15,235/15,236 files; the only
diff is a cosmetic Windows folder name in `config.cfg`). `nitan_san`'s
2026-08-12 round-two §10.7 pass (`libs/nitan_san/NOTES.md`) is the
functional-test record for this codebase. The `work/` sync above already
carries every fix from that pass.
