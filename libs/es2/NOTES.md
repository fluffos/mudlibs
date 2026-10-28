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

## WASM status update (2026-08-25, another session)

Promoted `wasm_status` from `""` to `playable` — booted clean on the
first try, zero fixes needed (unlike several sibling libs onboarded
the same day, e.g. `ds386`/`discworld`/`deadsouls_fluffos`, which all
hit an eager-simul_efun `socket_status()` compile failure specific to
the WASM build's missing `sockets` package). Verified with a real
scripted WASM session: login as `fluffos`/`Mud@2026`, arrival at the
documented 饮风客栈 with the 孙悟空 crossover NPC present and active,
and `score` producing the full character sheet (stats, 精/气/神 bars,
combat ratings) matching the native-tested output exactly. `quit`
wasn't distinctly captured in this transcript (孙悟空's own ambient
action lines kept the client's idle-detector from settling, the same
issue seen testing `discworld`'s womble NPC) but is already verified
clean under native testing above and untouched by anything WASM-specific.

## Deep functional test (round two, AGENTS.md §10.7, 2026-08-27)

Prior work on this lib had only ever run a basic boot/registration smoke
test (see "Interactive test result" above) plus the narrow §7.129
sibling-sweep fix (item 8 in "Config / driver-compat fixes"). This pass
is the first FULL §10.7 playthrough: registration → look/score/i at
every state change → movement → sect join (`apprentice`) → skill
learning (`learn`) → safe combat (`fight`) → a full death/revival cycle
→ `quit` + `debug.log` check → reconnect after a real wall-clock gap,
plus an explicit systematic grep for all thirteen standing cross-cutting
bug patterns (§7.121/§8.3a/§7.122/§7.123/§7.124/§7.126/§7.129/§7.130/
§7.131/§7.132/§7.133/§7.134/§7.135). Test character: `qinfeng`/秦风二
(`Test@2026`), joined 封山剑派 (Fengshan sword sect) under 柳淳风,
learned `sword` to skill level 2-3, went through a full `smash`-induced
death → 白无常 ghost dialogue → reincarnation → revive-room cycle, then
quit cleanly — save files removed post-test, only the seeded
`fluffos`/秦风 admin account remains. Four bugs found and fixed:

1. **§8.3a, `feature/command.lpc`'s `command_hook`** — declared
   `private nomask int command_hook(string arg)`, registered via
   `add_action("command_hook", "", 1)` in the same file's
   `enable_player()`, but `feature/command.lpc` is `inherit`ed into
   `std/char.lpc` (the base of `obj/user.lpc` AND every NPC) — the
   textbook §8.3a shape, already confirmed broken the same way on 4
   sibling ES2-lineage libs (`demonangel`, `xuanjianlu`, etc.) but never
   checked on `es2` itself. Fixed: dropped `private`, kept `nomask`.
2. **§8.3a variant, `std/item/combined.lpc`'s `destruct_me`** — also
   declared `private`, and inherited by `std/money.lpc` (every coin in
   the game), `std/medicine/{pill,powder}.lpc`, `std/weapon/throwing.lpc`,
   and several `obj/`/`d/` content items. Unlike the sibling `demonangel`
   instance of this exact file (where the `call_out("destruct_me", ...)`
   call site was dead/commented-out), **here it is live**:
   `set_amount()` does `if( v==0 ) call_out("destruct_me", 1);` — reached
   whenever a stacked item (most commonly money) is reduced to zero
   (spending your last coin, dropping/combining stacks down to 0).
   Fixed identically: dropped `private`, kept `nomask`.
3. **New bug, not a prior AGENTS.md class — dbase key mismatch silently
   disables the `wimpy` auto-flee safety net for every player, forever**:
   `cmds/usr/wimpy.lpc` (the player-facing `wimpy [<percentage>]`
   command) reads and writes the dbase key `"wimpy"` — but the ONLY
   consumer of the auto-flee threshold, `std/char.lpc`'s `heart_beat()`
   (`wimpy_ratio = (int)query("env/wimpy")`), and every NPC's own
   `create()` (`set("env/wimpy", N)`, ~30 files), all use the key
   `"env/wimpy"` instead. These are two entirely separate dbase entries
   on this driver's `feature/dbase.lpc`/treemap — running `wimpy 30` as
   a player set `"wimpy"=30`, which nothing ever reads, while
   `"env/wimpy"` stayed permanently unset (`0`) for every player
   character ever created, so `heart_beat()`'s
   `intp(wimpy_ratio = query("env/wimpy")) && wimpy_ratio > 0` guard was
   always false and the auto-flee branch never ran — the player-facing
   command was a complete, silent no-op from the very first player who
   ever typed it. Fixed by changing both the read and write in
   `wimpy.lpc` to use `"env/wimpy"`, matching every other consumer.
   Live-verified: after `wimpy 30`, a `fight` against a training-hall
   NPC (武馆弟子) correctly triggered an auto-flee/retreat line
   ("你向後一纵，躬身做揖说道...") once damage pushed a stat below the
   30% threshold — this did NOT happen pre-fix in code inspection terms
   (the key was never read) — and the save file correctly persisted
   `"env":(["wimpy":30,])`. **Flagged for a sibling sweep**: since this
   is the ES2 codebase's own `feature/dbase.lpc`/`env/` naming
   convention (not something `es1` shares — `es1` uses a different stat
   system entirely), check `haiyang2`/`demonangel`/`xkx2001`/`rzrmud`/
   `xo`/`zhyx`/`naruto` (the later ES2-derived family) for the same
   `cmds/usr/wimpy.lpc` vs. `env/wimpy` key mismatch — grep each for
   `query("wimpy")`/`set("wimpy"` (no `env/` prefix) outside of
   `std/char.lpc`'s own correctly-prefixed reads.
4. **AGENTS.md §7.112 class, `d/death/npc/{wgargoyle,bgargoyle}.lpc`** —
   both NPCs' `init()` unconditionally schedules a 5-stage
   `call_out("death_stage", ...)` narrative chain (ghost dialogue →
   `reincarnate()` → move to `REVIVE_ROOM`) with no re-entry guard. This
   is the exact, previously corpus-swept (150+ libs) §7.112 pattern
   under its most common filenames, but `es2` was never part of either
   sweep wave. Fixed with the same `death_stage_active` `set_temp()`/
   `delete_temp()` guard already applied to sibling `haiyang2`'s copy of
   this same file (see AGENTS.md §7.112's reference implementation),
   adapted to each file's own exit points (`bgargoyle.lpc` has an extra
   "not actually a ghost yet, attack them" branch that also needed the
   flag cleared). Live-verified via a full `smash`→ghost→`白无常`
   dialogue→`reincarnate()`→`REVIVE_ROOM`(城隍庙) cycle with zero
   `debug.log`/driver-log errors throughout.

**Confirmed clean (checked, no fix needed)**:
- §7.121/§7.124 (float-in-int / fraction-vs-percentage): no `int`-typed
  economy/threshold function found doing unconverted float arithmetic;
  the two `float count`/`count_total` locals in `feature/attack.lpc`'s
  `biwu_ob()` and `cmds/std/biwu.lpc`'s `start_biwu()` are a deliberate
  fractional extra-turn accumulator inside a `void` function, not a
  narrow-return-type bug.
- §7.122 (autoload duplication): `es2` has its own from-scratch
  `feature/autoload.lpc` (`save_autoload()`/`restore_autoload()`,
  NOT the TMI-2 `compute_autoload_array()`/`destroy_autoload_obj()`/
  `load_autoload_obj()` lineage `es1` shares with TMI-2-descended libs)
  — this driver's plain `save_object()` never serializes physical
  inventory contents at all, so there is no "captured twice" pathway:
  the autoload list is the ONLY mechanism that ever recreates a marked
  item, called exactly once per `setup()`, and ordinary reconnect
  (`obj/user.lpc`'s `reconnect()`, `adm/daemons/logind.lpc`'s
  `reconnect()`) never calls `setup()`/`enable_commands()` again — traced
  the full login/reconnect code path to confirm no double-`restore_autoload()`
  call site exists.
- §7.123 (bare file-scope `IDENT = (...)`): none found via manual
  inspection of every `nosave TYPE ident;`-then-bare-assignment
  candidate.
- §7.126 (stale `.c` extension in `.o` save data): `es2` has no
  AREA/coordinate-grid engine and only 3 `.o` files total outside
  player saves (no corpus of exit-storing dbase files to be affected).
- §7.130 (unconditional `query_idle()` after non-interactive branch):
  `std/char.lpc`'s `heart_beat()` correctly guards its `query_idle()`
  call with `if( !interactive(this_object()) ) return;` one line
  earlier — no unconditional post-branch call found.
- §7.131 (`find_living`/`find_player` without `set_living_name()`):
  `feature/command.lpc`'s `enable_player()` calls `set_living_name()`
  on every login, and `adm/daemons/logind.lpc`'s `find_body()` uses
  `find_player()` with a `children(USER_OB)`/`getuid()` fallback — a
  modern master-object-era design, not the classic per-call-scan
  archetype this bug class targets.
- §7.132 (`map()`-over-mapping wrong-arg binding): no `map()` call over
  a mapping with a single-parameter callback found in the tree.
- §7.133 (`net_dead()` never defined): both `obj/login.lpc` and
  `obj/user.lpc` define `net_dead()` (the latter `private`, but
  `obj/user.lpc` is a leaf nothing else `inherit`s, so the §8.3a
  demotion doesn't apply — confirmed via a live abrupt-disconnect
  reconnect test, "重新连线完毕" printed correctly every time).
- §7.134/§7.135 (uninitialized-default accumulator/accessor): no new
  instances found beyond the `std/room.lpc` `make_inventory()` guard
  already fixed at onboarding time (item 6 in "Config / driver-compat
  fixes" above).

Verified via `scripts/lpcc_check.sh` (same 21 pre-existing FAILs as
before this pass — all previously-documented dead/gapped content, zero
new regressions) and a full native driver boot + the playthrough above,
with zero `debug.log`/driver-stdout errors across the whole session.

## 深度功能测试（2026-09-04，round three，paid shop）

新角度：补上 2026-08-27 round two 没做过的真实购买。那次已经
`apprentice` 封山剑派柳淳风，本轮不再拜师。

### 修复的 programming bug

1. **`log_error()` 把编译警告当「编译时段错误」广播给玩家（§15w）**：
   `adm/obj/master.lpc` 的 `log_error()` 对 `this_player(1)` 无条件
   `write("编译时段错误：" + message)`。本驱动把 `warning: Unused
   local variable` / `Unknown #pragma` 也送进 `log_error()`，第一次
   登录刷了 34 条「编译时段错误」。闸门改成
   `this_player(1) && strsrch(message, "arning:") == -1`，警告仍写入
   `work/log/log`。修复后同路径 0 条玩家可见「编译时段错误」。
2. **`can_afford()` 在没有白银时把任何非整两黄金的价格都判成「零钱」**：
   `feature/finance.lpc` 的 1996-10-14 改写在 `silver` 缺失时直接
   `else if (amount%10000) return 2`。身上已有足够铜钱支付 15 文包子
   （一百文钱 + 一两黄金）仍报「你没有足够的零钱，而对方也找不开」。
   补上「无银、有铜、铜钱覆盖 `amount%10000`」分支。修复后
   `buy 包子 from waiter` 成功，找零 100−15=85 文。

黄金不能拆成铜钱仍是设计（纯黄金买 15 文会走同一句零钱提示）；
`vendor_goods` 的键是中文「包子」不是 `dumpling`，`buy dumpling from
waiter` 会「对方好像不愿意跟你交易」——list 列出的就是中文键，不是
bug。

### 实测过程

管理员 `fluffos` / `Mud@2026`。第一输入是「您的英文名字」，没有内码
菜单。端口 40214。落地饮风客栈 `/d/snow/inn`，店小二 id `waiter`。
孙悟空在场，ambient 不算 live clock，idle 0.45 够用。`clone
/obj/money/coin` + `call coin->set_amount(100)`，`list` 包子十五文 /
鸡腿三十文 / 酒二十文 / 匕首五十文。修复后 `buy 包子 from waiter`：
「你向店小二买下一个包子。」`i` 包子 + 一两黄金 + 八十五文钱。

live `debug.log` 是 `libs/es2/log/debug.log`（Boot Time Fri Sep 4
03:48:47 2026），无 `error:` / `Too deep recursion` / `F_FINANCE`。
管理员存档未提交。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-07）— 兵器的 `actions` 函数指针

`set("actions", (: WEAPON_D, "query_action" :));`：旧 MudOS 把 `(: 字符串, "函数" :)` 当作 call_other 函数指针，本驱动把它当作表达式函数指针，求值只得到字符串 `"query_action"`。没有对应兵器技能时 `feature/attack.lpc` 直接用兵器的 `actions`，`COMBAT_D` 拿到的不是 mapping，`reset_action()` 后仍不是，记一条 bad action 就不出招——拿着这些兵器打不出攻击。改成别的兵器早已用的 `(: call_other, WEAPON_D, "query_action" :)`（KB 04 §6.10）：`std/weapon/throwing.lpc`、`std/weapon/fork.lpc`、`std/weapon/whip.lpc`、`std/weapon/sword.lpc`、`std/weapon/axe.lpc`、`std/weapon/blade.lpc`、等共 8 个。改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py es2 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 180 个 `.lpc` 和 1 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：175 -> 175 通过，无回退；改过的头文件的 1 个包含者 1 -> 1 通过。启动时警告 21 -> 0；新进程登录（输入名字）正常。
手改 `include/net/ftpdsupp.h`：`check_access()` 的局部 `file` 只在 `#ifdef GUEST_WIZARD_FTP` 分支里用到，声明挪进同一个 `#ifdef`。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 1 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 1 个文件，HEAD 与工作树各载入一次无回退（1 objects; HEAD PASS 1, tree PASS 1; regress 0; newly loading 0），这些文件的警告 1 -> 0。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

能编译的文件里的警告 4 -> 0（`toolkit_fix.sh es2` 重扫：1841 个文件可编译，剩下的诊断都在本来就编译不过的文件里）。四条都是 `Function pointer returning string constant is NOT a function call`：`d/city/npc/walker.lpc` 的 inquiry「买官」、`d/city/shangshu/kefang.lpc`、`d/city/street3.lpc`、`daemon/class/scholar/taolin.lpc` 的 item_desc 写成 `(: "一段文字" :)`。这不是函数名而是要显示的文字：`feature/dbase.lpc` 的 `query()` 会 `evaluate()` 函数指针、`cmds/std/look.lpc` 对函数型 item_desc 也是求值后 `write()`，结果都等于那段文字，所以直接写成字符串，行为不变。

另外 `adm/daemons/network/mail_serv.lpc` 的 `tmp[i] == EOT+".";`（上一行是 `=`，TMI-2 原有的笔误，语料里已普遍修过）改为赋值；该文件缺 `daemons.h`/`uid.h`/`post.h`，本来就编译不过，只是顺手改掉。

验证：5 个改动对象 HEAD 与工作树各用新进程载入：4 -> 4 通过（mail_serv 两边都载不进），regress 0；删除声明审计 0 项待看。5 个对象载入无回退。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`include/net/ftpdsupp.h`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库目前没有对象设了缺失的武功；三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 1 处、1 个文件：`chaos-steos`→`chaos-steps`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/latemoon/in_room/flower1.lpc` 的 `north` 出口：`corridor7` → `backroom`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 1 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/daemon/class/ronin/master.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 1 条注册（1 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/village/lordhouse3.lpc`（`do_push`）。最多的函数名：`do_push` 1 处。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（chat_msg 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/green.n/npc/oldman2.lpc`:`do_sigh`。 另有 2 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 3 个文件里 4 行只含这个指针的行（`(: do_sigh :),` `(: follow_player :),` `"剃度" : (: ask_for_join :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 1 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 1 处（1 个文件）：拼名字的赋值 1 处。例：`name[0..1]` → `name[0..0]`（`/daemon/class/bonze/master.lpc:104`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 2 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。

## example/book 注释折行无法加载（2026-10-27，KB 04 §6.25 Also）

`obj/example/book.lpc` 的 `// name of the skill` 等注释被折行，下一行 `the skill` 成了裸标识符，驱动报 `unexpected L_IDENTIFIER`。用手足 sjsh 完好副本覆盖。证明：HEAD 加载失败；改后加载成功。

## 深度功能测试（2026-10-27，§6.25 one-arg message_vision）

`message_vision("…")` 补第二参（`me` / `TP` / `this_player()`）。

