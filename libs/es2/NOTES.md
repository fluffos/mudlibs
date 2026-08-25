# es2 — 东方故事Ⅱ (git clone from mudchina/es2)

Source: `git clone https://github.com/mudchina/es2` (commit `ae8adf6`,
cloned 2026-08-25). Port: 40214. Status: **done** (boots clean, full
registration verified end-to-end with a real Chinese name, `look`/
`score`/`quit`/`whoami`/`update` all confirmed working post-login).

Note: the sibling repo `mudchina/es2-utf8` (pre-converted) was
deliberately NOT used — per this project's established methodology
(AGENTS.md §4), doing the GBK→UTF-8 restoration itself, on the original
GBK snapshot, is the point.

## What this is

A first-generation, from-scratch Chinese LPC mudlib, not a reskin of an
existing English codebase. `bin/es2.info` names it `MUDNAME=ES2`;
`adm/obj/master.lpc`'s header credits "Annihilator@Eastern.Stories"
(1994-11-07) with `feature/treemap.lpc` crediting "Buddha@TMI" and
noting it is "part of the TMI mudlib distribution" — i.e. this archive
genuinely is (part of) the historical root of the "ES2/TMI-2" lineage
name this project's AGENTS.md catalog uses for dozens of unrelated
LATER Chinese mudlibs. `mudlib directory` is the repo root itself (no
nested subdirectory); `master file : /adm/obj/master`, `simulated efun
file : /adm/obj/simul_efun`.

Layout: `adm/` (master/simul_efun/daemons), `cmds/` (wiz/arch/imm/usr/
std command dirs, Lima-esque `ADM_PATH`/`WIZ_PATH`/... dispatch by
`wizhood()`), `feature/` (mixin classes inherited into `std/char.lpc`:
action, attack, command, dbase/treemap, equip, food, message, move,
name, save, skill, team, vendor, ...), `d/` (game-world domains: city
gates/streets, a snow-mountain sect, a temple, a bamboo canyon, a green
forest estate, a graveyard/death area, a moon-pavilion zone, ...), `u/`
(individual wizard-workspace directories, e.g. `u/cloud/`), `quest/`
(experience-tier quest-list tables), `daemon/class/*` (character-class
skill masters). Start room `/d/snow/inn` (饮风客栈), death room
`/d/death/gate`.

## Conversion (GBK→UTF-8)

`scripts/convert_lib.sh libs/es2/raw libs/es2/work` (default GB18030
encoding — confirmed correct via `name : 东方故事Ⅱ` decoding cleanly
from the raw `config.ES2`'s mojibake bytes). Results: 1933 files
converted, 616 already UTF-8, 8 lossy (invalid-byte-dropped) files, 77
binaries skipped. Also stripped `raw/`'s `.git/` from `work/` (not part
of the mudlib) and removed the prebuilt `bin/driver`/`bin/addr_server`
binaries' influence (this project uses its own driver; left the files
in place since nothing references them).

- **8 lossy-conversion files individually audited** per AGENTS.md
  §4.1's warning that a dropped byte can silently corrupt adjacent
  syntax: `d/choyin/npc/yamen_po.c`, `d/latemoon/upstar/upcenter.c` (a
  `@LONG`/`LONG` heredoc room description — closing tag intact, one
  content character dropped), `d/temple/{obj,npc/obj}/{spells_book,
  magic_book}.c` (all 4: inside a `//` comment, harmless),
  `u/cloud/obj/npc/flower_girl/guihua.c` (see "Not fixed" below —
  independently corrupted, not a lossy-conversion artifact),
  `cmds/std/exercise.c`. All but `guihua.c` compile fine; the dropped
  bytes in `yamen_po.c`/`upcenter.c`/`exercise.c` land inside string
  literals or comments and only cost a character or two of decades-old,
  already-garbled NPC dialogue/room text (pre-existing raw-byte
  corruption confirmed present in `raw/`, not introduced by this
  conversion pass) — left as-is per AGENTS.md's "don't fabricate
  content" rule.
- **Straggler extensionless GBK text files** (`file`/extension-based
  sweep misses these): `doc/help/{weapon,quest,guild,history,theme,
  taoist,story,myth}` — converted with a direct `iconv -f GB18030 -t
  UTF-8` pass.
- **`static`→`nosave` string-literal collision** (AGENTS.md §4.3): the
  blanket `\bstatic\b`→`nosave` sed rewrote `log_file("static/...")`
  path literals in `adm/obj/master.lpc`, `adm/daemons/securityd.lpc`,
  `cmds/std/suicide.lpc`, `cmds/arch/purge.lpc`, `cmds/wiz/call.lpc` (8
  hits/5 files) — reverted `"nosave` back to `"static` in all of them.
  No `#define nosave static`/`#define protected static` compatibility
  shim found (the other known collision class).

## Config / driver-compat fixes

`libs/es2/config.fluffos` modeled on the raw `adm/etc/config.ES2`
(decoded name/messages), pointed at `libs/es2/work`, port 40214;
dropped 5 directives the driver flags obsolete (`address server ip/
port`, `reserved size`, `binary directory`, `swap file`).

1. **`adm/obj/master.lpc`'s `valid_override()` was 2-arg** (AGENTS.md
   §10.4) — `simul_efun.lpc` `#include`s 7 fragment files, needing the
   3-arg `(file, name, main_file)` signature for `efun::` calls inside
   them to resolve cleanly. Widened the signature and OR'd in
   `main_file == SIMUL_EFUN_OB`.
2. **Missing runtime directories, §7.11**: `/log/` and `/data/` were
   never shipped (gitignored in the upstream repo) — `mkdir -p log
   data`. More importantly, the shared `log_file()` simul_efun
   (`adm/simul_efun/file.lpc`) had NO `assure_file()` guard at all
   (unlike `feature/save.lpc`'s `save()`, which already calls
   `assure_file()`) — added one, with a forward declaration (this
   driver doesn't resolve forward references within a file without
   one — hit "Undefined function assure_file" until added). Also
   guarded `master.lpc`'s own bypass call (`efun::write_file(home +
   "log", ...)` in `log_error()`) the same way. Without this, the
   FIRST diagnostic/crash log write of the whole boot threw before
   `Accepting telnet connections`.
3. **`feature/treemap.lpc`'s `_query`/`_delete`/`_set` were `private`**
   (AGENTS.md §7.48) — `feature/dbase.lpc` inherits `F_TREEMAP` and
   calls them directly, illegal on this driver (`private` is
   file-local only here, not "protected-like"). Changed to `protected`
   in `feature/treemap.lpc`. Same class found and fixed in
   `feature/action.lpc`'s `continue_action()`/`eval_function()` and
   `feature/attack.lpc`'s `attack()` — all three called cross-file
   from `std/char.lpc`, which inherits `F_ACTION`/`F_ATTACK`.
4. **`origin()` returns a string on this driver, not an int bitmask**
   (AGENTS.md §7.47) — `feature/team.lpc:20`'s
   `origin()==ORIGIN_LOCAL || origin()==ORIGIN_CALL_OUT` is `always
   false because of incompatible types`. This one line, inherited into
   every `std/char.lpc`-based object, was the single largest
   contributor to the initial compile-sweep failure count (1126 of
   1610 raw failure lines — every NPC/player-body compile unit hit it
   once). Fixed: `origin()=="local" || origin()=="internal"` (the
   §7.47 mapping table: `ORIGIN_CALL_OUT` (0x10) → `"internal"`).
5. **`adm/simul_efun/object.lpc` overrode `destruct()`** (AGENTS.md
   §7.38, "Invalid simulated efunction override" — this driver
   hard-rejects it). Deleted the wrapper (lost its `ob->remove(euid)`
   pre-cleanup step, same documented tradeoff as every other lib that
   hit this).
6. **`std/room.lpc`'s `make_inventory()` had no guard around
   `new()`/`move()`** (AGENTS.md §7.25, textbook match) — a room's
   `"objects"` mapping referencing a missing/broken content path
   crashed that room's first-ever population (`*Bad argument 1 to EFUN
   call_other() ... Got: int(0)`, `/std/room.lpc` in the trace). Wrapped
   `new()` in `catch()`, added `objectp()` checks at both call sites in
   `reset()`. Root-caused (not just guarded) 3 of the crashing rooms:
   `d/latemoon/{obj,npc/obj}/latebook.lpc`'s `"objects"` entry pointed
   at `__DIR__"npc/girl"`, but `girl.lpc` only exists under the sibling
   `d/latemoon/npc/` directory, not `d/latemoon/{obj,npc/obj}/npc/` —
   a pre-existing content-tree drift (multiple parallel copies of the
   same zone), not a conversion artifact.
7. **Same content-tree-drift class, but via `carry_object(...)->wear()/
   wield()` chained straight off a possibly-0 return** (no `std/room.lpc`
   helper involved, so #6's fix didn't cover these): `d/village/
   flowergirl.lpc` (`__DIR__"obj/flower"` missing, only exists at
   `/obj/flower.lpc` or under a sibling `npc/obj/`), `d/latemoon/room/
   npc/aaa.lpc` (`__DIR__"houndbane"`, only exists under an unrelated
   `d/class/fighter/`), `d/latemoon/room/npc/fong.lpc` and `.../jane.lpc`
   (`__DIR__"obj/{deer_boot,blue_dress,redbelt}"`, only exist under
   sibling `d/latemoon/{obj,npc/obj}/`). Guarded each call site
   (`object ob = carry_object(...); if (ob) ob->wear();`) rather than
   guessing which sibling copy was "the" intended path.
8. **`adm/simul_efun/message.lpc`'s `tell_room()` passed a defaulted
   int `0` as `message()`'s 4th (`exclude`) argument** when called with
   only 2 args (`tell_room(room, str)`, the overwhelmingly common
   call shape — 71 call sites across the tree) — this driver's
   `message()` requires that argument be `void | object | object *`,
   never a bare int, and throws `*Bad argument 4 to EFUN message()`.
   First surfaced via `d/choyin/stove.lpc`'s `create()` crashing, but
   this was a **shared root cause affecting essentially every
   `tell_room()` call in the game**, not a per-file bug. Fixed once in
   the simul_efun: omit the 4th argument to `message()` entirely when
   no exclude list was passed, instead of passing a defaulted 0.
9. **`cmds/std/to.lpc` used an old-MudOS call_other-shaped functional
   literal**: `(: this_object(), ({ "do_to", me, arg }) :)`, illegal on
   this driver ("Illegal to use local variable in functional"). Every
   sibling `->edit()` call site in this archive (`std/{bboard,jboard}
   .lpc`, `obj/mailbox.lpc`) already uses the modern `(: func,
   bound_args... :)` shape — rewrote to match: `(: do_to, me, arg :)`,
   plus a forward declaration for `do_to` (defined later in the same
   file; same forward-reference requirement as fix #2 above).
10. **`cmds/wiz/tail.lpc` called a bare `tail()` efun** that was never
    real on MudOS/FluffOS (not in this driver's `.spec` files at all).
    Reimplemented with `read_file()`+`explode()`+`implode()` (last ~15
    lines) since this driver's `read_file()` also has no
    "negative start = from end" mode.
11. **`d/city/{south,east1,east2,west1,west2}door.lpc` (all 5 city
    gates) call `create_door("out", ...)` unconditionally, but each
    one's own `"exits"` mapping has the `"out"` entry commented out**
    (its target "outskirts road" room was never shipped in this
    snapshot) — `create_door()` hard-`error()`s without a matching
    `exits[dir]` entry, crashing all 5 gate rooms' first load. Disabled
    the now-inconsistent `create_door()` call to match the already-
    disabled exit, rather than fabricating the missing target room.
12. **`adm/daemons/securityd.lpc`'s `valid_write()` save-file check
    forgot the driver appends the save extension** (AGENTS.md §7.49,
    textbook match) — compared the driver's `file` argument (full
    filename, `.o` included) against the bare `query_save_file()`
    return value, so it NEVER matched and every player save threw
    `*Denied write permission in save_object()`. This is the reason a
    freshly-registered character landed with "你的四周灰蒙蒙地一片，
    什麽也没有" (blank void) instead of the start room:
    `enter_world()`'s `user->save()` call errors out midway through the
    function, before the `user->move(startroom)` line ever runs — boots
    clean, registers clean, only breaks on the FIRST real save (exactly
    the "survives a smoke test, only shows up on the full flow"
    signature §7.49 warns about). Fixed: `file == qsf || file == qsf +
    __SAVE_EXTENSION__`. Re-verified with a full fresh registration
    after the fix: character correctly lands in 饮风客栈 (start room),
    `look`/`score`/`quit` all produce correct output, and the save
    files (`data/{login,user}/f/fluffos.o`) are written successfully.

## Author-typo fixes (pre-existing in `raw/`, AGENTS.md §6.6)

Confirmed against the raw GBK bytes for each before fixing (none are
conversion artifacts):

- `u/cloud/npc/goddd.lpc`: a `message_vision(...)` call missing its
  closing quote before string concatenation (`"...说:" 就凭你...`,
  the classic §6.6 shape) -- fixed. Separately, later in the same file,
  an unbalanced-paren typo (`num += ((...` opens one extra paren versus
  its parallel `else`-branch sibling 3 lines below, which has the
  correct single-paren shape) plus `sizeof(level)` (undeclared) where
  every other use in the function says `sizeof(levels)` -- both fixed
  to match the parallel/sibling code exactly, not guessed.
- `u/cloud/obj/sword_book.lpc`: `set("long",\net("long", ...)` — a
  stray duplicate `et(` fragment (apparent leftover from a botched
  `set("long",` paste) breaking the call in two. Removed the stray
  fragment.
- `u/cloud/npc/chess_player.lpc`: `name(this_player())` called `name()`
  as if it were a global "get an object's name" function; it's actually
  `feature/name.lpc`'s own per-instance `varargs string name(int raw)`
  method. Fixed to `this_player()->name()` (2 call sites, also affects
  `u/cloud/tearoom2.lpc` which inherits this NPC).
- `d/snow/npc/guard.lpc`: `is_killing(who)` passed an object where
  `feature/attack.lpc`'s `is_killing(string id)` expects the string id
  — every other call site in the tree correctly passes `->query("id")`.
  Fixed to match.
- `d/green/npc/master.lpc`: `map_skill("spells",magic-array)` — missing
  quotes around the `"magic-array"` skill-name string literal (parsed
  as subtracting two undefined variables `magic`/`array` instead).
  Fixed to `map_skill("spells","magic-array")`.
- `d/village/lordhouse3.lpc`: a commented-out `if(...){` block left its
  closing `}` NOT commented out, producing a dangling brace before
  `return 1;`. Commented out the stray `}` too.
- `u/cloud/duchang2.lpc`: `do_bet()`'s source is genuinely **truncated**
  mid-statement in the raw archive (`this_player->add("` with nothing
  after it, `wc -l` confirms the `.c` file itself ends there) — per
  AGENTS.md §6.6, closed the function body as a safe no-op
  (`notify_fail()`+`return`) rather than fabricating the missing
  gambling-payout logic. Also fixed the adjacent `return "没钱就别赌！"`
  from a bare string return inside an `int`-typed function to the
  `notify_fail()`+`return 0` idiom every other action-command handler
  in this archive uses.
- `d/npc/oldman.lpc`: `kill_ob()`'s `set("nickname", ...)` was
  immediately followed by a bare string literal with no enclosing
  function call — a `message("vision", ...)` header (confirmed via the
  identical 4-arg `message("vision", <text>, environment(),
  this_object())` shape used by 3 sibling files) had been dropped.
  Restored it. Separately in the same function, the parameter `object
  ob` (the target being killed) was reassigned to an ARRAY
  (`all_inventory(environment())`, a "reveal boss, aggro the whole
  room" trigger this override repurposes `kill_ob` for) and then
  indexed — a real type collision, not a missing-quote typo. Renamed
  the array-holding local to `obs` throughout rather than changing the
  parameter, preserving the original reveal-and-attack-all behavior
  exactly (this is a deliberate, if unusually-named, override — a
  sibling `d/green/npc/oldman.lpc` shows the "normal" `kill_ob`
  override shape, single-target delegation to `::kill_ob()`; this
  file's author chose different semantics for this NPC and that choice
  was left alone, only the compile-blocking type bug was fixed).

## `eat_func`/`eat_tonic` — dead-but-broken data, not fixed as content

`d/snow/{obj,npc/obj}/{agaric,ginseng,ice_lotus,ebony_lotus}.lpc` (all 4
tonic herbs, both `obj/`+`npc/obj/` copies) and `d/goathill/{obj,npc/obj}
/dead_leech.lpc` all `set("eat_func", (: eat_tonic :))` — `eat_tonic` is
referenced NOWHERE else in the archive (grepped the whole tree), a hard
compile error for an undefined function pointer. Even if it existed,
`feature/food.lpc` (the ONLY food class anything in this snapshot
actually inherits — `feature/food{old,bak}.lpc` are unused duplicates,
see "Not fixed" below) never reads `"eat_func"` at all (the one line
that would have — `//if (query("eat_func")) return 1;` — is itself
commented out). Dropped the dead `set()` call in all 10 files rather
than inventing tonic-healing logic to give `eat_tonic` a body.

## Not fixed (pre-existing content gaps / dead code, confirmed via `raw/`)

- **`adm/daemons/network/` (12 files: `ping_q`, `mudlist_a`, `ms`,
  `userid`, `pingtcp`, `name_server`, `mail_serv`, `netmail`, `telnetd`,
  `pingd`, `inetd`, plus `services/`)** — an incomplete/never-finished
  Intermud-mail-and-services subsystem. References headers that don't
  exist anywhere in this archive at any path (`uid.h`, `mailer.h`,
  `priv.h`, `post.h`; `config.h`/`daemons.h` exist only under
  `include/net/`, not the bare paths these files `#include`), macros
  never defined (`DAEMON`, `MAILDIR`, `POSTAL_D`, `THIS_MUD`), and one
  file (`mudlist_a.lpc`) uses `new`/`old` as variable names, both
  driver-reserved keywords now. All of it is reachable only via
  `dns_master.lpc`'s own `create()`, and `dns_master` is excluded from
  `adm/etc/preload` in the raw archive already (AGENTS.md §7.6's own
  standard exclusion) — confirmed genuinely dead, not a conversion
  regression.
- **`u/cloud/obj/npc/flower_girl/guihua.lpc`**: independently corrupted
  in the raw archive (confirmed via direct byte inspection of `raw/`,
  unrelated to this session's conversion pass) — the file's real `//
  guihua.c` source is preceded by ~128 bytes of binary junk, and later
  in the same file the content abruptly switches into what looks like a
  SECOND, different NPC's `set()` calls (a "杂货贩"/peddler) mid-
  statement, including embedded non-UTF8-representable binary bytes in
  a `set("gender", ...)` call. Not a simple dropped-character case —
  genuinely unrecoverable without fabricating content. `u/cloud/` (a
  builder's personal workspace, containing dozens of `.c.<unix-
  timestamp>` backup/auto-save artifacts alongside the live files, e.g.
  `d/snow/npc/rat.c.832813889`) already shows other signs of
  interrupted/abandoned editing sessions from the original archive.
- **`d/green.n/npc/womana.lpc`**: genuinely truncated at the START in
  the raw archive too (`wc -l` on `raw/`'s copy: 4 lines, opening with a
  bare `}) );` and no `inherit`/`create()` header at all). Not
  referenced by any other file in the tree (grepped) — dead/orphaned,
  left as-is per AGENTS.md §6.6 ("don't fabricate content").
- **`d/snow/test.lpc`**: literally plain English prose ("test again /
  just a test."), not LPC source at all — a builder's leftover scratch
  note, not referenced anywhere.
- **`F_UNIQUE` and `F_MERCENARY` feature macros are referenced but never
  defined** anywhere in `include/globals.h` (or any other header) —
  affects `d/snow/npc/obj/old_book.lpc`, `d/canyon/bamboo/obj/
  {parry_book,slipcase}.lpc`, `d/green/obj/jade.lpc` (`F_UNIQUE`) and
  `d/snow/npc/mercenary.lpc` (`F_MERCENARY`). A genuine archive content
  gap (these `inherit`s were presumably a shared feature-file that
  either predates this snapshot or was pulled from a different site
  branch) — not something to invent a base class for.
- **`feature/foodbak.lpc`, `obj/example/book.lpc`**: confirmed
  unreachable dead scaffolding. `F_FOOD` (the only macro anything
  `inherit`s) points at `feature/food.lpc`; `foodbak.lpc`/`foodold.lpc`
  are never `inherit`ed by anything and additionally contain their own
  independent typos (`foodbak.lpc`'s `If(` capitalization). `obj/
  example/` is explicitly example/documentation scaffolding (`// An
  example book`), and its one compile failure is an ancient 80-column
  hard-line-wrap landing mid-comment (`// name of \nthe skill`) —
  cosmetic, not live content.

## Interactive test result — full registration flow

Registration shape: English id (3-12 letters) → confirm new-character
(y/n) → real Chinese name (2-6 characters; `check_legal_name()`/
`is_chinese()` both needed the AGENTS.md §8.1 byte-range→codepoint-range
fix, see below) → password (≥5 chars, entered twice) → email (free
text) → gender (m/f) → lands in `/d/snow/inn` (饮风客栈). Verified live
with a real Chinese name (秦风): `look` showed the full room description,
exits, board, and NPCs (店小二/旅客×3/孙悟空); `score` showed a fully
populated character sheet (age/gender/ganzhi birthdate, 精/气/神 bars,
combat attack/defense, food/water, kill counts, potential %, overall
score); `quit` produced a clean "你丢下一件布衣。...欢迎下次再来！" and
correctly wrote both save files (`data/login/f/fluffos.o`, `data/user/
f/fluffos.o`) with zero runtime errors in `debug.log`.

### §8.1 GBK byte-range Chinese-detection fix

`adm/simul_efun/chinese.lpc`'s `is_chinese()` was the length-gate
variant (`strlen(str)>=2 && str[0] > 160 && str[0] < 255`) and `adm/
daemons/logind.lpc`'s `check_legal_name()` had the matching byte-
calibrated length bound (`strlen(name) < 2 || strlen(name) > 12` for a
message that says "1 到 6 个中文字") plus an `i%2==0` GBK-lead-byte loop
gate. Both fixed per the AGENTS.md §8.1 playbook: `is_chinese()` now
checks only the first character's CJK-Unified codepoint range (`str[0]
>= 0x4e00 && str[0] <= 0x9fff`, guarded against an empty string);
`check_legal_name()`'s bound is now the literal `1..6` characters the
message states, and the loop checks every character (no `%2` gate).
Live-verified: 秦风 (2 characters) registered cleanly on the first try.

## Admin account

`fluffos` / `Mud@2026`, Chinese display name 秦风. Granted via this
lineage's own mechanism: `adm/daemons/securityd.lpc`'s `create()` reads
`adm/etc/wizlist` (a plain `<euid> <status>` text file) into the
in-memory `wiz_status` mapping every boot — added a `fluffos (admin)`
line alongside the pre-existing `lin (admin)` entry, then registered
`fluffos` through the normal flow. `wizhood()`/`get_status()` both read
this mapping; `(admin)` status makes `feature/command.lpc`'s
`enable_player()` call `set_path(ADM_PATH)` + the real `enable_wizard()`
efun. Verified: login banner shows "目前权限：(admin)", `whoami` shows
`User ID = fluffos`, and `update /adm/obj/master` succeeds ("master:
loaded successfully. 重新编译 /adm/obj/master.lpc：成功！") — the
canonical read+compile ACL check per AGENTS.md §1.5.
