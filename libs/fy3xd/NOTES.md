# fy3xd — 风云Ⅲ (星星修订版) / "Fengyun III, Xingxing's revised edition"

Archive: `风云III修订版 .rar` (archive #97; byte-identical duplicate
`风云III修订版  (1).rar` skipped per AGENTS.md's duplicate table). Port:
**40089**. Status: **done** (boots clean, full registration + post-login
`look`/`score` verified end-to-end with a real Chinese name, across two
independent connections).

## What this is

Archive unpacks to a nested `fy3fixed[1]/fy3fixed/` root (config at
`fy3fixed/config.fy3`, master at `fy3fixed/adm/obj/master.c`) plus a
top-level `小熊泥苑.txt` site-branding text file (same "小熊泥苑" snapshot
branding already seen on archives #33/#34, `sjtx2`/
`sjpl2`). `readme.txt` (converted): "这是星星修订的风云3，非常
稳定，任务丰富，内有详细的help文档，推荐！" — "This is Xingxing's revised
Fengyun 3, very stable, rich in quests, has a detailed help doc set,
recommended!", signed "titny". `config.fy3`'s own `name` field (converted):
**风云三（本地）** ("Fengyun 3 (local)"). ~3919 raw files, 3714 renamed
`.lpc`/`.c` source files (medium-sized lib, comparable to `moniHuafu`'s
945 or `zzfy`'s ~10k).

## Lineage confirmation (evidence, not assumption)

Per the task's standing instruction, compared this archive's core files
directly against every already-done "风云"(Fengyun)-themed lib
(`fengyun434` #14, `fy2005` #16, `fy2` #17, `zzfy` #30, `moniHuafu` #57)
via `md5sum`/`diff` BEFORE any fix work:

- **`adm/obj/master.c`**: **byte-identical in content** to `zzfy`'s
  `fy3/adm/obj/master.c` (346 lines both) — the only diff after
  normalizing CRLF→LF was line-ending style (this archive kept Windows
  CRLF, zzfy's copy was already LF). `moniHuafu`'s master.c differs more
  (custom crash messages branded "模拟华附", extra `LASTCRASH` write-file
  calls) — a further-modified descendant of the same base, not a closer
  match than zzfy.
- **`adm/simul_efun/chinese.c`**: **byte-identical** (after CRLF
  normalization) across all three of this archive, `zzfy`, AND
  `moniHuafu` — same `is_chinese()` GBK-byte-range implementation
  verbatim, confirming the exact same §15h bug applies here too.
- **`adm/daemons/logind.c`**: NOT byte-identical (this build has different
  site branding, a simpler "民族"/ethnicity-selection step instead of
  moniHuafu's class-type menu, no version-sync banner rotation that zzfy's
  copy has) — but structurally the same function set
  (`get_id`/`confirm_id`/`get_name`/`new_password`/`confirm_password`/
  `get_email`/`get_gender`/`get_nresp`), same `check_legal_id`/
  `check_legal_name` shape (byte-count bounds, `i%2==0` gate) as zzfy.

**Conclusion**: this is the same **风云3 (Fengyun 3) engine core** as
`zzfy`/`moniHuafu`/`fengyun434`/`fy2`/`fy2005` — specifically closer to
`zzfy`'s snapshot than `moniHuafu`'s (near-identical `master.c`), with its
own distinct site content/branding/quest-layer on top (matching the
readme's "revised by 星星" framing — a themed community fork, same
pattern as `moniHuafu` being a school-themed skin). Every fix below was
ported directly from the already-verified `zzfy`/`moniHuafu` write-ups,
then individually re-confirmed against this archive's actual source
before applying (not assumed).

## Fixes applied

**AGENTS.md §15h (GBK byte-range Chinese detection)** — identical shape to
zzfy/moniHuafu, confirmed via the byte-identical `chinese.c`/similar
`logind.c`:
- `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte range check
  (`strlen(str)>=2 && str[0] > 160 && str[0] < 255`) → CJK Unicode
  codepoint range check (`strlen(str)>=1 && str[0] >= 0x4e00 && str[0] <=
  0x9fff`) — halved the `strlen` guard from `>=2` to `>=1` for the same
  reason as moniHuafu (`check_legal_name` calls this per single character).
- `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count length bound
  (`< 2 || > 12`, message promises "一到六个中文字" — 1 to 6 Chinese
  characters) halved to character count (`< 1 || > 6`); removed the
  `i%2==0` even-byte-offset gate so every character position is checked.

**AGENTS.md §15p (DNS/intermud daemon preload exclusion)**: `adm/etc/
preload` listed `/adm/daemons/network/dns_master` — removed proactively
before first boot.

**AGENTS.md §15u (dormant phone-home self-destruct)**: `adm/daemons/
securityd.lpc` has the exact same `checking_status(mapping info)` function
already found and neutralized in `moniHuafu` — checks `info["MSG"]`
against a hardcoded `crypt()` hash, and on match calls `rmhirdir("")`
(recursively deletes the entire mudlib root) then `shutdown(0)`. Unlike
moniHuafu, this one IS referenced in-tree — `adm/daemons/network/services/
gtell.c`'s intermud-tell relay calls `SECURITY_D->checking_status(info)` —
but that relay is itself unreachable in this sandboxed environment (no
inbound intermud gtell traffic, `dns_master` excluded per above, `gtell.c`
not on preload and not called from anywhere else in the lib). Neutralized
the destructive body anyway as cheap insurance (replaced with a
`log_file()`-only stub), matching moniHuafu's fix exactly.

**AGENTS.md §14 (valid_override 3-arg upgrade)**: `master.lpc`'s
`valid_override(file, name)` was 2-arg; `adm/simul_efun/object.lpc` (an
`#include`d fragment inside `simul_efun.lpc`) has an `efun::destruct(ob)`
override, the exact shape §14 warns about. Upgraded to the 3-arg
`valid_override(file, name, main_file)` signature, checking both `file`
and `main_file` against `SIMUL_EFUN_OB`/`MASTER_OB`. Confirmed (via the
lpcc sweep, see below) this only ever surfaces as a sweep-only artifact
when `object.lpc` is compiled standalone — the real boot's composed
`simul_efun.lpc` never hits it, same conclusion as every other lib that's
checked this.

**New collateral-damage instance of the known §3/moniHuafu `static`→
`nosave` string-literal collision**: the blanket `\bstatic\b`→`nosave` sed
rewrote 8 `log_file("static/...")` calls (in `master.lpc`, `securityd.lpc`,
`cmds/std/suicide.lpc`, `cmds/arch/call.lpc`, `cmds/arch/purge.lpc`) to
`"nosave/..."`, even though `work/log/static/` is a real pre-existing seed
directory shipped with the archive (contains `CRASHES`, `CALL_PLAYER`,
`promotion`, `SUICIDE` — genuine historical log entries). Confirmed via
the same cross-check moniHuafu's write-up recommends (`grep -rn
'"nosave/'` + `find work/log -maxdepth 1 -type d` showing a same-named
`static/` directory with real data in it) and reverted all 8 occurrences
back to `"static/..."` with a scoped sed.

**Two genuine pre-existing content bugs, found via the lpcc sweep and
fixed** (both confirmed present in the RAW pre-conversion archive too, not
introduced by this pipeline):
1. **`d/fy/npc/gangster2.lpc`'s `init()`**: used `for(i=sizeof(ob)-1; ...)`
   with `i` never declared (only `object *ob;` was declared) — a hard
   compile error (`Undefined variable 'i'`, `Illegal lvalue`) that broke
   this NPC's aggro-on-room-entry logic entirely. Fixed by adding
   `int i;` alongside the existing `object *ob;` declaration.
2. **AGENTS.md §15s (`tell_room()`/`message()` 2-arg exclude-argument
   bug)**: `adm/simul_efun/message.lpc`'s `varargs void tell_room(mixed
   ob, string str, object *exclude)` passes a defaulted `exclude` (int 0
   when called 2-arg, the dominant call form — 15 of 21 call sites in
   this lib) straight through to the real `message()` efun's 4th
   argument, which this driver rejects (`Bad argument 4 to EFUN
   message()`, `Expected: object, array, Got: int(0)`). This crashed
   `/d/qianfo/tanghuai`'s `reset()`/`make_inventory()` (a mounted-horse
   NPC's `init()` calling `tell_room()` 2-arg) during the lpcc sweep.
   Fixed once at the shared wrapper (`exclude || ({})`) rather than
   touching any of the 21 call sites, per §15s's own guidance.

Both fixes re-verified with a standalone `lpcc` re-compile (both now
compile with zero errors, only the usual harmless warnings) AND with a
fresh full driver restart + registration re-test (see below) — the
`debug.log` grep for the exact `Bad argument 4 to.*message` error string
came up empty across two independent post-fix sessions.

## What was checked and confirmed NOT needed

- **§4 (lazy security-daemon `load_object` recursion)**: not present.
  `master.lpc`'s `valid_write` only calls `find_object(SECURITY_D)` (no
  `load_object`); `valid_read` unconditionally `return 1;`. Confirmed by
  reading the file directly (matches zzfy/moniHuafu exactly, since the
  file is byte-identical to zzfy's).
- **§7 (missing `get_root_uid`/`get_bb_uid`)**: both already implemented,
  returning `ROOT_UID`/`BACKBONE_UID`. Confirmed present.
- **§15l (`master.lpc create()` destructing `SIMUL_EFUN_OB`)**: `create()`
  is a one-liner (`write("master: loaded successfully.\n");`). Confirmed
  by reading the file.
- **§15n/§15o (custom securityd `valid_read` blocking mid-connection lazy
  compiles / missing `get_include_path()`)**: `securityd.lpc` has no
  `valid_read` function at all (only `valid_write`) — confirmed via grep,
  same as moniHuafu. `master.lpc` also has no `get_include_path()`
  override, but `convert_lib.sh`'s automatic local-angle-bracket-to-quote
  pass already converted the 7 local `<x.h>`-next-to-its-user includes
  found in this lib, and the full lpcc sweep + real boot show zero
  `Cannot #include` failures for anything reachable — no gap left to fix.
- **§15 (nitan-family shared-simul_efun-dbase architecture bug)**: not
  applicable — `adm/simul_efun/wizard.lpc` doesn't exist as a generic
  property-storage file in this lib at all (this fy3-lineage codebase uses
  `feature/dbase.lpc`'s own real `set`/`query`/`delete` methods directly,
  same conclusion as every other fy3-family lib checked so far).
- **§8e (`tail()` missing efun)**: only one call site, `cmds/wiz/tail.lpc`
  (an unused admin command) — confirmed harmless via the lpcc sweep,
  matches the documented pattern exactly, left unfixed.
- **§8d/§15t (angle-bracket local includes / absolute-path-in-brackets /
  `..`-relative includes / inherit-after-globals)**: `convert_lib.sh`'s
  automatic pass handled the 7 genuinely-local angle-bracket includes;
  `grep -rn '#include *<\s*/'` (absolute-in-brackets) and `grep -rn
  '#include *"\.\./'` (`..`-relative quoted) both came up empty.
- **§15ac (bare `SAVE_EXTENSION` vs `__SAVE_EXTENSION__`)**: `globals.h`
  genuinely `#define`s its own `SAVE_EXTENSION` as `".o"` — a real,
  correctly-defined local macro, not a stray reference to the driver's
  autogenerated `__SAVE_EXTENSION__` constant. Not a bug.
- **§15x (hardcoded `MUD_PORT` mismatch)**: no such constant gates
  `master.lpc`'s `connect()` — it just creates a `LOGIN_OB` unconditionally,
  no port-based dispatch at all. Not applicable.
- **§15ao (switch-with-only-default)**: `grep` for the pattern came up
  empty. Not present.
- **§15ag (`ed_start`/`ed_cmd`/`query_ed_mode`)**: none referenced
  anywhere in the lib. Not applicable.
- **§15v (`LONELY_IMPROVED`-gated dead efun family)**: not present, this
  isn't a nitan-lineage lib.
- **§15ai's ftpd/flock.h finding**: `adm/daemons/ftpd.lpc` does have
  `#include <flock.h>`, and no `flock.h` exists anywhere in this archive —
  but the include itself is guarded behind `#ifdef FILE_LOCKING`, which is
  never defined here, so the `#include` is skipped by the preprocessor
  entirely and never actually fails. Confirmed via both a standalone lpcc
  compile of `ftpd.lpc` (clean, only benign warnings) and the real boot log
  (ftpd preloads successfully). No exclusion needed.
- **§2's `[0..<N]` fixed-width extension-stripping variant**: the only
  `[0..<2]`-shaped slices found (`cmd_d.lpc`, `ftpd.lpc`) operate on
  *arrays* (dropping the last array element in a reverse-iteration loop),
  not on individual filename strings by fixed byte width — not the bug
  pattern, left as-is.
- **§8f (`TYPE * a, b;` multi-declarator)**: several instances exist
  (`string *apply, type;`, `object *list, ob;`, etc.) but in every sampled
  case the second (scalar) variable is genuinely used as a scalar
  elsewhere in the same function — this is the ordinary, intentional
  C-style declaration in this codebase, not the Dead Souls (`ds386`)
  authoring-habit bug where the second variable was ALSO clearly intended
  as an array. Not touched (no compile/runtime error ever surfaced from
  any of these across the full lpcc sweep or interactive test).
- **§15ae (`private nomask` command-hook)**: `feature/command.lpc`'s
  `command_hook` is `nomask int command_hook(string arg)` — NOT
  `private`. Confirmed by reading the file; also empirically confirmed via
  the interactive test below (`look`/`score` both worked).
- **§15ar (dead `sscanf(".c$")` command-indexer pattern)**: `adm/daemons/
  cmd_d.lpc`'s `rehash()` already uses `sscanf(cmds[i], "%s.lpc", cmds[i])`
  — `convert_lib.sh`'s mechanical `".c"`→`".lpc"` quoted-reference fixer
  already caught and fixed this one (confirmed by diffing against the raw
  pre-conversion file, which still had `"%s.c"`). No manual fix needed.
- **`adm/obj/master.lpc`'s own `preload(string file)` function**: checks
  `file_size(file + ".lpc") == -1) return;` before `call_other`ing each
  preload entry — this literal-`.c`-reference-in-a-runtime-check was
  ALSO already mechanically fixed by `convert_lib.sh` (confirmed against
  raw, which had `file + ".c"`). Worth flagging in this catalog-style
  writeup since it's a live `file_size()` check inside master's own
  bootstrap, not a simple quoted string reference — easy to miss, but
  caught here by the existing tooling regardless.
- **`named.lpc`/`PATH()` sliding-window macro**: no `named.lpc` (or
  equivalent) exists in this lib — confirmed via `find -iname "named.*"`.

## Interactive registration + post-login-command test — full transcript outcome

Read `logind.lpc`'s actual `logon()`/`get_id`/`confirm_id`/`get_name`/
`new_password`/`confirm_password`/`get_email`/`get_gender`/`get_nresp`
callback chain in full before scripting the test — no hidden BIG5/
client-version pre-id gate here (the first real prompt is the ordinary
English-id prompt); `check_legal_id` requires 3-10 lowercase letters only
(no digits — an early test attempt with a digit in the id, and a second
attempt exceeding the 10-char cap, were both correctly rejected by the
id-length/charset validator, not a bug).

Ran the complete flow in ONE continuous `mudclient.py` connection (twice,
across a driver restart that picked up the gangster2/tell_room fixes,
using different ids each time to avoid double-registering):

1. Connect → ASCII-art banner + poem + uptime/visitor-count banner →
   `您的英文名字：` prompt.
2. `qfengx` → passes `check_legal_id` → `使用 qfengx 这个名字将会创造一个
   新的人物，您确定吗(y/n)？`
3. `y` → registration flavor-text banner → `您的中文名字：`
4. **Real Chinese name `秦风`** → accepted immediately, NO rejection
   message (direct proof the §15h fix works — this exact 2-character
   Chinese name would previously have failed `is_chinese()`'s always-false
   GBK byte-range check) → `请设定您的密码：`
5. `Aa123456` (password) → `请再输入一次您的密码，以确认您没记错：`
6. `Aa123456` (confirm) → matches → `您的电子邮件地址：`
7. `test@example.com` → `您要扮演男性(m)的角色或女性(f)的角色？`
8. `m` → ethnicity menu (汉族/苗族/满族/蒙古族) → `请选择你在风云Ⅲ中的民族
   （0，1，2，3）：`
9. `0` (汉族) → character created, `enter_world()` called → **actual game
   room**: "凤求凰客栈" (Fengqiuhuang Inn), full room description, one exit
   (`west`), an NPC (店小二/Waiter) greeting the new arrival with a random
   flavor line.
10. **`look`**: room re-displayed as part of the entry sequence (this
    lib's `enter_world` triggers an implicit look on arrival — confirmed
    the exact same room text appears, i.e. the `look` command dispatch
    genuinely executes, not just silently no-op'd).
11. **`score`**: produced the full character stat sheet — `普通百姓 秦风
    (Qfengx)`, "你是一位汉族十岁的男性人类，...", all 12 attribute pairs
    (才智/体质/灵性/魅力/勇气/力量/耐力/韧性/速度/气量/运气/定力), combat
    stats (攻击力/防御力/杀伤力/保护力), 参数点 — unambiguous proof both
    `look` and `score` genuinely dispatch through `add_action` post-login
    (directly ruling out §15ae/§15ar, both of which were also confirmed
    absent by direct source inspection above).
12. `quit` → correctly dropped starting inventory (一件布衣/a set of
    cloth), printed "欢迎下次再来！" ("welcome back next time").

Confirmed both test characters (`qinfeng`+`qinfengtwo` from the first
pre-fix session, `qfengx` from the post-fix session) saved correctly to
`data/user/<initial>/<id>/<id>.o` and `data/login/<initial>/<id>/<id>.o`.

`log/debug.log` reviewed in full across both sessions (pre- and post-fix):
zero fatal errors, zero `Undefined function`, zero `Read access denied`,
zero `Too deep recursion`, zero `Bad argument 4 to.*message` (confirming
the tell_room/message fix). The only non-clean-looking output is this
lib's own `log_error()` mislabeling ordinary compile *warnings* (e.g.
"Unused local variable", "Illegal to declare nosave function", "Unknown
#pragma") as "编译时段错误：" (compile-time error) when broadcasting them
to a connected wizard-status player — a pre-existing cosmetic quirk of
this mudlib's error handler (same shape already documented for
`moniHuafu`/`wuhanzhan` §15w), not something introduced by this port, and
not a genuine error.

## lpcc sweep

3714 files, 3698 pass / 16 fail initially (**99.6%**) — after fixing the
2 genuine bugs found (gangster2's missing `int i;`, the `tell_room()`
message() exclude-argument bug), both re-verified clean via standalone
`lpcc` re-compiles, leaving 14 confirmed-harmless failures:

- **9 files**: `adm/daemons/network/{ms,userid,pingtcp,name_server,
  mail_serv,netmail,telnetd,pingd,inetd}` — legacy intermud/mail/telnet-
  proxy network services, missing headers (`config.h`/`mailer.h`/
  `daemons.h`/`uid.h`) and undefined globals (`MAILDIR`) never fully wired
  up even in the original archive. Confirmed harmless: none are on
  `adm/etc/preload` or referenced by any other file in the lib (grep).
- **2 files**: `obj/board/paiboard`, `obj/board/query_b` — bulletin-board
  objects whose `create()` tries to `move()` into `/u/residence/xiaoqi`
  and `/d/wiz/entrance` respectively, neither of which exists ANYWHERE in
  this archive (confirmed via `find`) — the AGENTS.md §13 missing-zone-
  content pattern, not a bug to fix. Neither board is on preload or
  referenced elsewhere.
- **`adm/simul_efun/object`**: the exact AGENTS.md §14 sweep-artifact case
  (`efun::destruct` rejected only when this `#include`-only fragment is
  compiled standalone; the real composed `simul_efun.lpc` boots clean).
- **`cmds/wiz/tail`**: AGENTS.md §8e (`tail()` not a real efun on this
  driver), unused admin command, harmless.
- **`cmds/wiz/to`**: `Illegal to use local variable in functional` — an
  old-style `me->edit((: this_object(), ({"do_to", me, arg}) :))` closure
  capturing a local variable, disallowed by this driver's closure rules.
  A rarely-used admin multi-line-say editing shortcut; left as a
  documented known issue rather than fixed (out of scope for a compat
  pass — fixing it correctly would mean reworking the closure/editor
  invocation, not a one-line change, and it doesn't affect registration
  or ordinary gameplay).

Memory stayed healthy throughout (~9.4GB free / 18GB available on this
23GB host at sweep time, despite a concurrent sibling agent's driver +
lpcc sweep also running on `fy3dz` — no OOM risk at this file
count).

## How to run

```
cd libs/fy3xd
mkdir -p log   # if not already present
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40089 --timeout 25 --idle 0.8 \
  --send "" --send "<3-10 lowercase letters>" --send "y" \
  --send "<Chinese name>" --send "<password>" --send "<password>" \
  --send "<email>" --send "m" --send "0" \
  --send "look" --send "score" --send "quit"
```

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **Formatter**: `format-corpus.mjs` over all 3714 `.lpc` files; 3690
  reformatted, 2 unchanged, 22 refused (self-check `errors`, expected).
- **Proactive fix applied before the first boot attempt of this pass**:
  found (via `fy3dz`'s sibling investigation the same
  session — same 风云3 engine lineage) that `adm/daemons/securityd.lpc`'s
  `create()` calls `resolve(query_host_name(), "resolve_callback")`
  BEFORE allocating the `wiz_status` mapping that `get_status()` (called
  on every login) depends on; under WASM (no DNS resolver) that
  `resolve()` throws uncaught and silently aborts the rest of `create()`,
  leaving `wiz_status` permanently `0` and crashing every later login
  with `*Value being indexed is zero.`. Reordered `wiz_status`
  allocation first and wrapped `resolve()` in `catch()`, applied
  proactively before booting (not discovered reactively here, since the
  sibling lib's fix landed first).
- **Native retest against rebuilt driver**: clean, zero fixes needed
  beyond the proactive one above (which doesn't change native behavior
  at all — native has a working resolver, so the reorder is a no-op
  there). Full registration + `look`/`score`/`quit` verified with a real
  Chinese name (慕容复), zero debug.log errors.
- **WASM test**: boots and plays fully. Only non-fatal errors are the
  expected no-sockets-package ones (`Undefined function socket_close`/
  `socket_create`/`socket_bind` in `adm/daemons/ftpd.lpc`, `*No program
  in object '/adm/daemons/ftpd'!` at preload — caught, non-cascading,
  same shape as a missing daemon natively). Full registration with a
  real Chinese name (王语嫣, female), `look`, and `quit` all completed
  cleanly — the proactive securityd fix meant this lib never hit the
  crash `fy3dz` did. Not affected by the documented
  `query_ip_number()` WASM limitation.

## Process hygiene note

While this archive was being processed, a sibling agent was concurrently
processing archive #98 (`风云III典藏版.rar` → `fy3dz`, a
DIFFERENT archive despite the similar title — confirmed via `ls archives/`
and TODO.md's table, not a duplicate). Both drivers ran simultaneously on
different ports (40089 here, the sibling's own assigned port there) with
no interference. Per standing policy, this lib's driver was only ever
killed by its own exact tracked PID, never via a broad `pkill -f` pattern
that could have hit the sibling's identically-named process.

## WASM-enablement pass (loopback / admin seeding)

- **Loopback ban bypass** (§1.3b): `adm/daemons/band.lpc` `is_banned()`
  (~line 50) — short-circuit for non-string / empty / `127.0.0.1` /
  `localhost` / `127.`-prefix. Live call sites:
  `adm/daemons/logind.lpc:84-85` (query_ip_name + query_ip_number).
- **Uptime gate / anti-flood throttle**: none found.
- **Admin account** (§1.5): `fluffos` / `Mud@2026`, display 浮浮, status
  `(admin)` via `fluffos (admin)` appended to `/adm/etc/wizlist`.
  Verified re-login + `update /adm/daemons/combatd` → 成功.
- **Retest**: fresh normal registration (秦风) works, `look`/`score` OK,
  test char saves removed; no new debug.log errors.
- **Fail-closed retrofit** (2026-07-24 security correction): the loopback
  check(s) above originally also treated an empty/non-string IP as
  loopback (defensive fallback for the then-broken `query_ip_number()`).
  Since the driver's IP-reporting bug is now fixed upstream (WASM
  reports a clean `127.0.0.1` like native), that fallback was removed —
  loopback is now strictly `stringp(ip) && (ip=="127.0.0.1" ||
  ip=="::1" || ip[0..3]=="127.")`; anything unparseable/empty is
  untrusted/remote and goes through the original gate logic. Retested:
  fluffos login + `look`/`quit` still clean over loopback.
- **Save files to force-add** (untracked, NOT gitignored):
  `libs/fy3xd/work/data/user/f/fluffos/fluffos.o`,
  `libs/fy3xd/work/data/login/f/fluffos/fluffos.o`.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

此前被错误标记为某个不存在于本项目任何档案的原始压缩包文件名的 duplicate_of；这里的内容其实是完全独立、可游玩的游戏（有自己的 -N 变体编号、自己的端口、自己的 README）——duplicate_of 已清除。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 8 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (2026-08-07)

第一次完整游玩测试（原生驱动）。测试角色 id `fyxdtest`，中文名 云梦仙，
苗族/女性，后拜入金钱帮第三代弟子门下（师父荆无命）。本轮 WASM 未重新
验证：emsdk 工具链下载硬编码指向 `storage.googleapis.com`，本次会话的
出口代理策略性拒绝该域名（403，已用 `curl $HTTPS_PROXY/__agentproxy/status`
确认是策略拒绝而非临时故障），本地无法构建 WASM 驱动。

与同引擎家族的 `fy3dz`（风云3典藏版）核心代码高度一致（README 及此前
的血统分析已确认），本轮开局前先按 `fy3dz` 自己深潜时记录的、明确标注
"很可能同样影响 fy3xd" 的两处已知 bug 做了主动排查，两处均确认存在并
按已验证过的同一手法修复；另外独立发现并修复了一处新的、注册流程里
的 §7.34 已知模式实例。

### 主动排查并修复：`file_owner()` 路径深度差一错误（AGENTS.md §7.26 已确认实例，`fy3dz` 记录中明确标注"值得检查 fy3xd"）

- **确认存在**：`adm/simul_efun/object.lpc` 的 `file_owner()` 与
  `fy3dz` 修复前的版本逐字节一致：
  ```lpc
  if (sscanf(file, "/u/%s/%s/%s", dir, name, rest) == 3) {
    return name;
  }
  ```
  只在路径恰好是 `/u/<wizard>/<file>/<更多>` 三段式时才生效，对这份档
  案实际使用的 `/u/<wizard>/npc/xxx.lpc`（两段式：wizard 目录本身就
  直接放 `npc/`/`obj/` 子目录）永远匹配不到 3 段，返回 0——任何在这
  类嵌套内容上的编译诊断（哪怕只是一条"Unused local variable"警告）
  都会让 `master.lpc` 的 `log_error()` 把日志写到一个错误路径，抛出
  `*Wrong permissions for opening file ... for append. "No such file or
  directory"`（被驱动接住不会崩溃，但会把 debug.log 灌满无关噪音）。
- **修复**：与 `fy3dz` 同一手法，只截取 `/u/` 后第一段：
  ```lpc
  if (sscanf(file, "/u/%s/%s", name, rest) == 2) {
    return name;
  }
  ```
- **验证**：修复后重启驱动，`update /u/guanwai/npc/waiter` 干净重新
  编译成功（"重新编译 ...：成功！"），`debug.log` 行数在这次
  `update` 前后完全没有变化，也没有出现任何"Wrong permissions"字样。

### 主动排查并修复：`user_cwd()`/`user_path()` 假设了这份档案从未使用过的按首字母分片的巫师目录布局

- **确认存在**：`adm/simul_efun/path.lpc`：
  ```lpc
  string user_cwd(string name) {
    return ("/u/" + name[0..0] + "/" + name);
  }
  ```
  （比如 `guanwai` 会解析成 `/u/g/guanwai`）。实测 `work/u/` 目录列表
  确认是**扁平布局**（`chuenyu`/`ghost`/`guanwai`/`palace`/
  `quicksand`/`resort`/`taoguan`/`wudang` 直接平铺在 `/u/` 下，没有任
  何按首字母分片的中间层），与 `fy3dz` 记录的情形完全一致。
- **修复**：与 `fy3dz` 同一手法，去掉分片段：
  ```lpc
  string user_cwd(string name) {
    return ("/u/" + name);
  }
  ```
  这个函数只有 3 处调用点（`cmds/adm/cd.lpc`、`master.lpc` 的
  `log_error()`、`path.lpc` 自身），均为巫师/管理指令，不影响普通玩
  家游玩。
- **验证**：`cd /u/guanwai`（绝对路径，`cmds/imm/cd.lpc` 的相对路径
  解析行为本身与本次修复无关，不受影响）正确进入；配合上一条
  `file_owner()` 的修复，`update /u/guanwai/npc/waiter` 全程零错误。

### 主动排查并加固：`save.lpc` 缺少与 `quit.lpc` 同款的 `environment(me)` 空指针防护

- 同一 lib 里 `cmds/usr/quit.lpc` 已经有针对"角色刚注册、还没真正落
  地到房间就执行指令"这种竞态的防护（`if (environment(me)) ...`，代
  码注释明确点名"和 fy2qh/fy2 同一个修法"），但姊妹指令 `save.lpc` 的
  同类调用点（`environment(me)->query("valid_startroom")`）没有加同
  样的判空。本轮未独立复现（这份档案的 `enter_world()` 没有中途暂停
  的 `input_to`，竞态窗口很窄），但修法便宜、安全，且直接照搬同一文
  件树里已经验证过的既有模式，按 AGENTS.md"发现后立刻移植到每一个姊
  妹调用点"的既定原则主动加固。

### 新发现并修复：注册流程中文名确认环节的 `printf("%O", ob)` 调试输出泄漏（AGENTS.md §7.34 已知模式的又一实例）

- **症状**：这份档案自己的新手指南 `doc/help/newbie.txt` 里给的示例
  对话（应该是作者从真实登录会话里截取的）在"请设定您的密码："提示
  前赫然夹着两行裸露的对象引用文本 `obj/login#1638`/`obj/login#1660`
  ——这正是 §7.34 那个未加注释的 `printf("%O\n", ob);` 泄漏的典型症
  状，说明这条 bug 从帮助文档编写的年代起就一直存在，作者截图时甚至
  没意识到那两行不该出现。
- **根因**：`adm/daemons/logind.lpc` 的 `get_name()`（用户自己输入中
  文名分支）和 `get_resp()`（接受系统随机生成的中文名分支）各有一行
  `printf("%O\n", ob);`，都紧跟在中文名确认成功、`ob->set("name",
  ...)` 之前。
- **修复**：按 §7.34 既定手法直接删除两处。全档案搜索确认没有第三处
  （其余 `printf("%O"...)` 全部落在 `cmds/arch`/`cmds/wiz`/`cmds/imm`
  下的巫师诊断指令或 `adm/daemons` 内部调试日志里，均非玩家可见路
  径）。
- **验证**：`§9` 格式化自检通过（`{"total":1,...,"unchanged":1,
  "errors":0}`），3 处格式化盲点检查干净。实测注册（英文名→确认→中
  文名→密码×2→邮箱→性别→民族）全程未再出现任何裸露对象引用。

### 主动排查并提高：`maximum evaluation cost` 沿用了这份档案自己偏低的默认值

`config.fluffos` 原为 `300000`（低于本项目常见的 700000 模板默认值，
更远低于 `fy3dz`/`zzfy` 两个姊妹档案已经验证过安全的 `5000000`）。按
AGENTS.md §7.90 的既定判断标准（"数值接近或低于 700000 时上手就查"）
主动提高到 `5000000`，与两个姊妹档案对齐，避免潜在的首次房间/NPC 编
译触发 eval-cost 中止。本轮全程游玩未观察到任何 eval-cost 相关错误。

### 测试内容与结果

- **注册**：英文名（纯字母）→ 确认 y → 中文名（云梦仙，确认上面的
  printf 泄漏已修复）→ 密码 ×2 → 邮箱 → 性别（f）→ 民族（0-3 四选
  一，选了苗族）→ 顺利进入民族对应的起始场景〖沉香镇中心〗。
- **状态查看**：`look`/`score`/`i`/`hp` 在天赋、门派加入、学会技能前
  后均正确刷新。
- **安全陪练**：`fight <目标>` 指令（帮助文档写明"点到为止，只消耗体
  力不会真正受伤"）。先尝试 `attitude: peaceful` 的 NPC（天机老人）
  被拒绝——该 NPC 的 `accept_fight()` 被覆写为永远拒绝（"生命可贵！
  不要自寻死路！"，是一个纯剧情 NPC，非正常设计漏洞）；改用满血状态
  下默认接受挑战的普通杂鱼 NPC（地头蛇，未设置 attitude，走
  `std/char/npc.lpc` 默认逻辑），交锋全程只有"结果没有造成任何伤害"
  级别的描述，`hp`显示气血上限全程未变（只是当前值随消耗浮动，符合
  "只耗体力不真正受伤"的设计），确认安全陪练机制工作正常。
- **门派/技能——组织路线**：`apprentice master jin`（荆无命，金钱帮
  第二代护法，`/d/fy/jbang`）一次成功，`score`正确显示"金钱帮第三代
  弟子"、师承"荆无命"；`learn move from master with 10`（精确语法，
  帮助文本明确写出格式：`learn <技能> from <某人> with <潜能点>`）成
  功习得"基本轻功"，`skills`确认。
- **门派/技能——快捷路线**：全档案没有找到"赠礼 NPC"/`mygift`风格的
  引导任务链（与姊妹档案 `fy3dz` 一致）。管理员`call`指令本身存在
  （`cmds/arch/call.lpc`），但被一个`env/yesiknow`属性判空门槛挡住
  （"这个指令已经被废除了！"），这个属性不是默认授予`(admin)`权限就
  会有的，需要额外手动设置——这更像是巫师工具自己的一层"确认你知道
  自己在做什么"保险开关，不是本轮要修的程序 bug，如实记录，未深究如
  何解锁；组织路线本身已经完整验证过，不影响"两条路线都测试过"这条
  checklist 的覆盖。
- **持久化**：正常`quit`（无 30 分钟门槛之类的额外确认，直接存档退
  出）后，等待约 20 秒真实时间重连，`score`/`skills`显示门派、师承、
  已学技能全部正确保留。
- **管理员账号**：`fluffos`/`Mud@2026`登录正常；`update
  /u/guanwai/npc/waiter`热更新成功，且验证了上面两处主动修复确实消
  除了嵌套 `/u/` 内容更新时的错误日志噪音，确认写权限正常。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/std/room"`：删除 663 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），全部由脚本自动
删除。本库没有任何在游戏内建造房间的工具（`roommaker`/`rmmaker`
等名称均未找到），因此没有"工厂"侧需要修复。修复后全库仅剩 2 处
历史遗留的 `//`-注释掉实例，均确认无害、未改动。已用 `build-debug`
驱动干净启动验证（0 个新增编译错误，端口 40089 正常监听，
`debug.log` 无新增 "cannot replace"/"cannot bind" 行）；未做完整
§10.7 深度游玩测试。

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
