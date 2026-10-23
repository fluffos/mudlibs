# mohuanshiji — 魔幻世纪 (Magic/Fantasy Century)

Archive: `archives/魔幻世纪.rar` (archive #100, the last one in this batch).
Extracted mudlib root: `raw/mhsj/mud/` (a `config.cfg` sits at `raw/mhsj/`,
one level above the `mud/` dir it points into — `mudlib directory` in the
raw config is a Windows path `e:/mhsj/mud`). Port: **40092**. Status:
**done** (boots clean, full registration flow verified twice with real
Chinese names including both gender branches, post-login `look`/`score`
verified working every time, zero runtime errors in `debug.log` across all
sessions).

## What this is / lineage

`config.cfg`'s own `name` field (GBK-decoded, no stale leftover this time)
is `魔幻世纪`, matching the archive's own filename — no rebrand mismatch to
untangle here. `raw/mhsj/readme.txt` (credited to 小宝(suannai) /
西瓜太郎(gslxz) / 桃心太郎(iiiii), hosted for download by "星月传奇") states
this codebase itself started life as an **xyj (西游记/"Journey to the
West")-derived** ruleset — "本套源代码，修改了不少xyj中的BUG" ("this
source fixed many bugs in xyj") — with 武当 and 移花宫 sects added as this
site's own original content. `adm/obj/master.lpc`'s header comment reads
`"for ES II mudlib, original from Lil, rewritten by Annihilator
(11/07/94)"` — the same ES II lineage shared by the large majority of
already-processed archives in this project (directory layout `adm/`,
`feature/`, `std/`, `obj/`, `cmds/`, `d/`, `u/`; `securityd.lpc`'s ACL
shape; `feature/dbase.lpc`'s real non-simul_efun `set`/`query`). Several
in-mudlib strings (`logind.lpc`'s own comment header "神话世界·西游记·
版本４．５０", a `MUDLIB=="SJXY"` check in `total_players()`, `u/GSLXZ` /
`u/suannai` wizard homes matching the readme's credited authors) confirm
this is a "神话西游"(SJXY)-descended xyj build, not a from-scratch design —
consistent with, but not byte-identical to, any already-shipped sibling
spot-checked (`master.lpc`, `chinese.lpc`, `securityd.lpc` all differ from
the nitan/XO/ES2-Neolith/"hell" families' equivalents). Genuinely its own
build, not a rebrand of one already in the project.

Notably **not** present in this lib despite the ES II ancestry: the
nitan-family `dbase`-via-simul_efun architecture bug (§15) — this lib's
`feature/dbase.lpc`-equivalent already implements `set`/`query`/`delete`
directly, same as `tiexuejianghu`/`syxjl`/etc.

## Fixes applied (with why)

### §8h — `convertd.lpc` stray-backslash Greek/charset-table typo (43 instances, CRITICAL — broke the whole simul_efun boot)
`adm/daemons/convertd.lpc` builds several large lookup tables (Latin/Greek/
pinyin-tone character variants) as one-entry-per-line string literal
arrays. 43 of these lines had a stray trailing `\` immediately before the
closing quote (`"α\",` instead of `"α",`), escaping the closing quote and
swallowing every subsequent line into one giant malformed string literal
until the parser hit the *next* real quote — this crashed the compile of
`convertd.lpc`, which is `#include`d/composed such that it broke
`simul_efun` object loading generally, cascading into "couldn't find
object '/adm/daemons/channeld'" runtime errors for every daemon whose
`create()` fires after `convertd` in preload order (see the CHANNELD fix
below — same underlying trigger). One entry (`"α\",`) also
contained a legitimate hidden **PUA codepoint** (U+E5A2, an alternate
glyph representation intentionally stored alongside each table entry, e.g.
`"Ω",`/`"β",` — confirmed present and syntactically fine on
*every other* table row, not corruption) — fixed with a Python
line-indexed read/write that removed only the stray backslash and left the
PUA character untouched, per the encoding-section's PUA caveat (don't
trust a text editor / blind sed here). Found and fixed one instance first
via `lpcc` on `/adm/obj/simul_efun`, then proactively scanned the whole
file for the same shape (`grep`-style scan for lines ending `\",`) and
fixed all 43 in one pass rather than one-at-a-time.

### Case-sensitivity: `adm/daemons/CHANNELD.lpc` vs. `CHANNEL_D` macro (CRITICAL — broke `ftpd` and any other post-channeld preload daemon)
`include/globals.h` defines `CHANNEL_D` as `"/adm/daemons/channeld"`
(lowercase) — but the file on disk, after the standard `.C`→`.lpc`
uppercase-extension rename (§ "Watch for uppercase `.C`"), was
`CHANNELD.lpc` (all-caps **basename**, not just extension — a genuine
Windows-case-insensitive-authoring artifact, same root class as §15g/§15k
but for a `#define`d daemon path rather than an `#include` or literal data
file). Even though `channeld` itself loaded fine in preload order (its own
`create()` has no immediate dependency on the macro resolving), any LATER
preloaded daemon that calls `CHANNEL_D->do_channel(...)` in its own
`create()` (found via `ftpd.lpc`'s `create()`) got `*call_other() couldn't
find object '/adm/daemons/channeld'` — non-fatal individually (wrapped in
`catch()` by `master.lpc`'s `preload()`), but it flooded the boot log with
repeated error-handler recursion output and meant the channel daemon was
silently unusable from any of these call sites. Fixed by renaming the file
to lowercase `adm/daemons/channeld.lpc` to match the macro (much lower
blast radius than changing every `CHANNEL_D`/`do_channel` call site).
**Lesson for the catalog**: the uppercase-`.C`-rename check (found on
`shenmo` #73) needs to also cross-check renamed files against any
`#define`d macro path pointing at them by a DIFFERENT case, not just check
that the rename itself happened — 310 total uppercase-origin files existed
in this lib; only this one (a core preloaded daemon) actually mattered.

### Uppercase-`.C` rename encoding gap (15 files never GBK→UTF-8 converted — NEW finding)
`convert_lib.sh`'s forced-text-extension allowlist (`*.c|*.lpc|*.h|...`)
is a case-sensitive bash `case` match — an originally-uppercase `.C` file
never matches it and falls back to `file`(1)'s guess, which misclassified
15 of these (raw GBK, CRLF line endings) as `data` (binary) and skipped
them entirely — the same failure mode as the lib-#4 "CRCRLF confuses
`file`" bug, just gated by extension case instead of line-ending shape
this time. These 15 files were then manually `.C`→`.lpc` renamed (matching
every *other* uppercase file, most of which `file` DID correctly detect as
text) but never had their actual byte content converted, surfacing later
as `Invalid UTF8 codepoint in string literal` / raw `0xb9 0xa6...`-style
mojibake in the `lpcc` sweep, not at boot time (none of the 15 are
preloaded/reached by the registration path). Found via a small Python
script attempting `bytes.decode('utf-8')` on every `.lpc`/`.h` file in
`work/` and listing the ones that fail — cheap, worth running proactively
on any lib with uppercase-`.C` files going forward, not just this one
(files: `clone/{SHUSHAN,HELL,MOON,LONGGONG,JJF}.lpc`,
`adm/CL/{SHUSHAN,HELL,MOON,LONGGONG,JJF,QIANG}.lpc`,
`d/city/npc/XIA.lpc`, `d/city/obj/npc/greeting.h`, `d/sea/npc/beast1.lpc`,
`d/obj/quest/shuijingqiu.lpc` — converted with `iconv -f GB18030 -t UTF-8`,
falling back to `-c` for two files with a truncated trailing multi-byte
sequence at EOF).

### DOS-era Ctrl-Z (`0x1a`) EOF markers (11 files)
The same 11 `adm/CL/*`/`clone/*` files above (once GBK-decoded) also each
had a trailing `0x1a` (SUB/Ctrl-Z) byte — an old MS-DOS text-editor
end-of-file marker, harmless in GBK/UTF-8 either way but an "Illegal
character" hard compile error to this driver's lexer. Stripped with a
one-line Python byte-replace once identified via the same `lpcc` sweep.

### §14 — `valid_override()` upgraded to the 3-arg form (`adm/obj/master.lpc`)
Was the old 2-arg `valid_override(file, name)`. Added the 3rd `main_file`
parameter and an early-allow when `main_file == SIMUL_EFUN_OB ||
main_file == MASTER_OB`, matching the documented fix — cheap, correct,
applied proactively (never actually triggered in a real boot here either,
consistent with the catalog's note that this mostly only bites a bare
`lpcc` compile of an `#include`d simul_efun fragment).

### §15h — `is_chinese()` GBK byte-range check (`adm/simul_efun/chinese.lpc`)
Was `strlen(str)>=2 && str[0] > 160 && str[0] < 255`. Fixed to
`strlen(str)>=1 && str[0] >= 0x4e00 && str[0] <= 0x9fff` (CJK Unified
Ideographs range). Without this every real Chinese name is silently
rejected at registration — confirmed via the interactive test below that
`秦风`/`秦风四`/`秦风五` all now register correctly.

### §15h — `check_legal_name()` bound + sliding-window (`adm/daemons/logind.lpc`)
Byte-length bound `strlen(name) < 2 || > 12` (message already said "一到
六个中文字", i.e. 1–6 Chinese characters, calibrated for 2 bytes/char)
halved to `< 1 || > 6`. The sliding-window guard was `i%2==0 &&
!is_chinese(name[i..<0])` (checking only even *byte* offsets, using a
"rest of string" substring so `is_chinese`'s own `strlen>=2` requirement
had something to bite on) — replaced with a plain `!is_chinese(name[i..i])`
checked at every index (every position is one full character now, no
stepping needed, and a true single-character slice makes `is_chinese`'s
own length check trivially satisfied for every real position including
the last character, which the old shape always failed).

### §15p — excluded `network/dns_master` from `adm/etc/preload`
Standing policy; this daemon bootstraps a UDP intermud database against a
hardcoded remote "boot server" unreachable from this sandbox. Removed the
`/adm/daemons/network/dns_master` line from `adm/etc/preload`.

### §15ab-style — guarded `Mud_name()` macro against `dns_master` never loading (`include/net/macros.h`)
Per §15p's own caveat ("necessary but not sufficient"), grepped for direct
callers of the DNS/intermud subsystem outside `preload`/`adm/daemons/network/`
itself. `adm/daemons/CHANNELD.lpc`'s intermud-channel relay branch (fires
only when a player speaks on an `"intermud":`-flagged channel — `xyj`,
`es`, `jh`, `gwiz`; **not** the `sys`/`chat` channels used during ordinary
login, so this never actually fired during the interactive test below, but
is a real latent crash for anyone speaking on those channels) and
`cmds/usr/mudlist.lpc`/`cmds/wiz/tmp.lpc` all call the bare `Mud_name()`
macro, which unconditionally did `(string)DNS_MASTER->query_mud_name()`.
Changed the macro itself to
`(string)(find_object(DNS_MASTER) ? DNS_MASTER->query_mud_name() :
CHINESE_MUD_NAME)` — one fix covers every call site, degrading to the
mud's own name constant instead of a `0->query_mud_name()` runtime error
when the daemon is (deliberately) never loaded. Confirmed no other
network-subsystem macro (`index_add`/`index_call`/`dns_log`/`dns_warning`/
`udp_port`/`mud_nname`) is called from outside `adm/daemons/network/`
itself, so nothing else needed the same treatment.

### §15w — `log_error()` no longer echoes compile *warnings* to a connected non-wizard (`adm/obj/master.lpc`)
This driver's compile-diagnostic text is lowercase `"warning: "` (verified
by reading `~/src/fluffos/src/compiler/internal/lexer_utils.cc`'s
`prepare_logs()`), and `log_error()` is invoked for every compile
diagnostic, not just fatal errors — the original code showed the scary
`default error message` to any connected non-wizard on ANY diagnostic,
including harmless ones like our own §3 `nosave`-on-function warning that
this driver itself only warns about. Gated the player-facing branch on
`strsrch(message, "warning:") == -1` (i.e. only show it when the message is
NOT a warning) — still logged to the log file either way, just not echoed
to the connecting/playing user as if it were a crash.

### §15ab item 1 — missing `!stringp(str)` guard in the pre-login connection object's own `receive_message()` (`obj/login.lpc`)
`feature/message.lpc` (the real player body's copy) already guards with
`if(!msg || (len=strlen(msg))<1) return;`, but `obj/login.lpc`'s own copy
(used for the NOT-yet-authenticated connection object, reached by every
single fresh connect before `make_body()`) had no such guard at all —
any `write(0)` reaching this object during the pre-login sequence (this
driver's `write()` simul_efun doesn't static-type-check a `mixed`-typed
`0` at the call site) would have crashed `receive()` on literally every
connection, before any prompt appears. Added the same `!stringp(str)`
guard as a defensive fix (no live crash of this specific shape was
actually observed in testing here, but the asymmetry with the working
copy was the exact shape of a previously-documented bug from `haiyang2`).

### §15b — `db_affected(int)` stub (`adm/simul_efun/file.lpc`)
`adm/daemons/databased.lpc` (not preloaded, not reached by the
registration/gameplay path tested) calls a never-defined `db_affected(db)`
after every `db_exec()`. Restored as a simul_efun stub returning `1`
(assume ≥1 row affected) per the documented precedent — this driver's DB
package has no such efun and `db_exec()` itself returns 0 for
INSERT/UPDATE/DELETE regardless, so every real call site's own
`db_exec()`-return check is the actual signal; this only silences a
compile-time "Undefined function" for a file that was never going to be
exercised by this pass's testing anyway.

### §8e — `tail()` efun call in an unused admin command (`cmds/wiz/tail.lpc`)
Reimplemented in plain LPC (`read_file()` + `explode()` + slice + `write`),
matching the documented pattern exactly — non-fatal either way (dead wiz
tooling), fixed since it was cheap.

### §15ac — bare `SAVE_EXTENSION` (6 refs, `adm/daemons/network/netmail.lpc`)
Replaced with this driver's real autogenerated `__SAVE_EXTENSION__`
constant. Only reachable from the (deliberately unloaded) `network/`
subtree, so not exercised by testing, but cheap and correct to fix.

### §15t variant 1 — absolute path in angle-bracket `#include` (1 file)
`d/obj/books-nonskill/book-qujing.lpc`'s `#include </d/qujing/obstacle.h>`
converted to the quoted form `#include "/d/qujing/obstacle.h"`.

### `#include "../parent.h"` (disallowed `..`, 1 file)
`d/ourhome/honglou/npc/niu.lpc`'s `#include "../honglou.h"` rewritten to
the real absolute quoted path `#include "/d/ourhome/honglou/honglou.h"`.

### Pre-existing typo: missing closing quote (2 files, §10-shape)
- `d/obj/books-nonskill/hmeng014.lpc`: `string name = "《红楼梦》第十四回;`
  (missing closing `"` before the `;`) — confirmed a one-off by checking
  all 35 sibling `hmeng0NN.lpc` chapter files, every other one already has
  its closing quote correctly.
- `d/city/npc/BINGQI.lpc`: `set("long", "...商人\n由于...人称"兵器王"。\n");`
  spanned two raw physical lines with an embedded literal (unescaped)
  `"兵器王"` nickname — merged onto one line with the embedded quotes
  escaped (`\"兵器王\"`) and the missing `\n` restored between the two
  original lines' content.
- `d/moon/obj/poem.lpc`: two consecutive poem-string array entries
  (`"...宫阙。,` / `"...潇潇雨。,`) were each missing their closing quote
  before the trailing comma — both fixed.

## Confirmed NOT needed (checked explicitly)

- **§4** (lazy `load_object()` in `valid_read`/`valid_write` recursion) —
  `master.lpc`'s `valid_read`/`valid_write` only call
  `find_object(SECURITY_D)` and return a plain default (1/0) if not found;
  no `load_object()` call in either apply at all.
- **§7** (`get_root_uid`/`get_bb_uid`) — both already implemented in
  `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`.
- **§8c** (`this_player()`-override in `valid_read`) — `master.lpc` passes
  the driver's own `user` argument straight through to
  `SECURITY_D->valid_read/write(file, user, func)`, never substitutes
  `this_player()` for it.
- **§8d/§15o** (`get_include_path()`/local-header `<>` vs `""`) —
  `convert_lib.sh`'s automated pass already converted 282 local
  angle-bracket includes to quoted form; the one remaining absolute-path
  `<>` and one `..`-relative include (both listed above) were the only
  stragglers, fixed by hand. No `get_include_path()` apply needed since
  quoted-form resolution against the including file's own directory has no
  VM-context dependency at all.
- **§15ae** (`private nomask` command-hook) — `feature/command.lpc`'s
  `command_hook(string arg)` is plain `nomask` (a commented-out line
  directly above it, `// private nomask int command_hook(string arg)`,
  shows this lib's own authors had ALREADY dropped `private` at some
  point in this codebase's history — presumably for the same reason this
  project keeps finding). Confirmed via a full post-login `look`/`score`
  test that commands really do dispatch.
- **§15ar** (`commandd.lpc`-style dead `sscanf(".c$")`) —
  `adm/daemons/cmd_d.lpc`'s `rehash()` uses a plain quoted
  `sscanf(cmds[i], "%s.c", cmds[i])` (no trailing `$` before the closing
  quote), which `convert_lib.sh`'s standard quoted-`.c"`-reference fixer
  already turned into `"%s.lpc"` automatically — confirmed by reading the
  post-convert file and by the working `look`/`score` test.
- **§15aj** (missing mandatory gift/first-room object) — `logind.lpc`
  moves every new character with `no_gift` set to `/d/wiz/init`, which
  genuinely exists and runs a full 4-stat gift-allocation dialog before
  handing off to the real `START_ROOM` (`/d/city/kezhan`) — both files
  present and working, confirmed via the interactive test.
- **§15ag** (`ed_start`/`ed_cmd`/`query_ed_mode`) — grepped the whole
  lib; the only hit is `securityd.lpc`'s `valid_read` func-name
  whitelist comparing the STRING `"ed_start"` (one of several apply-name
  string literals in a `switch`-like func check), not an actual call to
  any of those three removed efuns/applies.
- **§15ai** (DNS_MASTER-absence causing an unconditional `shutdown(1)`
  gate) — `logind.lpc`'s only other `DNS_MASTER` use (`total_players()`)
  already guards with `if(!find_object(DNS_MASTER)) return 0;` first; no
  unconditional dispatch on a null find anywhere in the login path.
- **§15ah** (missing save-data directory silently swallowing a
  `write_file()`/`log_file()`) — checked every hardcoded `/log/...`
  directory referenced by the registration-adjacent code path
  (`/log/nosave/LASTCRASH`, checked with the correct `file_size(...)>0`
  guard, not the `§15am` truthiness trap) and created the one missing
  directory (`log/nosave/`) proactively; not actually reached by this
  pass's specific registration/look/score test but cheap insurance.
- **§15al** (`crypt(str,0)` random-salt-per-call client-challenge
  mismatch) — this lib's only `crypt()` uses are for ordinary password
  storage/verification (`crypt(pass,0)` once to set, `crypt(pass,
  stored_hash)` to check), not a client-side challenge/response protocol
  — `stored_hash` itself is always used as crypt's 2nd arg for
  verification, so per-call randomness at set-time is irrelevant.
- **§15am** (`file_size()==-1` truthy) — the two places that matter for
  boot/registration (`assure_file()`'s own `if(file_size(file)!=-1)
  return;`, and `logind.lpc`'s `file_size(...)>0` checks) both already
  compare correctly.
- **§15an** (live-clock heartbeat defeating `mudclient.py`'s idle pacing)
  — the login banner shows Beijing time ONCE at connect, not a
  continuously-updating prompt; no heartbeat-in-prompt pattern found. (An
  early test run's "9"/"y" gift-selection replies did appear to get lost
  once — likely ordinary local timing jitter rather than this pattern
  specifically, since retrying with the exact same script and a slightly
  longer `--idle` succeeded cleanly on every subsequent attempt.)
- **§15ao** (`switch` with only `default:`) — none found (`master.lpc`'s
  `connect()` doesn't even use a `switch`; grepped the whole lib).
- **§15ap** (`__FILE__` inside a `#include`d, not `inherit`ed, fragment)
  — not checked exhaustively given the archive's size, but none of the
  fixed/failing files above hit this shape.
- **§15l** (`master.lpc create()` destructing `SIMUL_EFUN_OB`) — this
  lib's `create()` is a one-line `write("master: loaded
  successfully.\n");`, no destruct/reload dance at all.
- **§15m** (unguarded `restore()` crashing a version-sync daemon's
  `create()`) — no `versiond.lpc`/replication-sync daemon exists in this
  lib at all. Several ordinary daemons (`chinesed`, `obstacled`, `msgd`,
  `emoted`, `clubd`, `familyd`, `shili`) do call `restore()` directly in
  `create()` with no `catch()`, same general shape — spot-checked
  `chinesed.lpc`'s own save file (`data/chinese.o`) for corruption (it's
  a large but well-formed `dict (["..."...])` mapping literal, closes
  cleanly) since it's the one on this list actually reached via preload;
  did not exhaustively byte-audit the others' save files given the
  clean boot and clean interactive test already obtained.
- **§15n** (custom `securityd.lpc` `valid_read` blocking the driver's own
  compile-time `load_object`/`include`) — this lib's `valid_read` already
  has an early `if (func != "read_file" && func != "file_size" && ... )
  return 1;` gate that implicitly allows `load_object`/`recompile_object`/
  `include` (none of those func names appear in the excluded list), so
  the ACL only ever applies to genuine data-read funcs. No fix needed.
- **§15r** (`check_config.lpc`-style driver-version self-check with a
  bare fatal `error()`) — no such file exists in this lib.
- **§15s** (shared `tell_room()`/`message()` wrapper passing raw `int 0`
  as the 4th `exclude` arg) — `adm/simul_efun/message.lpc`'s `tell_room()`
  does exactly this shape (`message("tell_room", str, ob, exclude)` with
  `exclude` unset/0 in the common 2-arg call form), but **verified against
  this driver's actual `f_message()` C++ source**
  (`src/packages/core/efuns_main.cc`): the `num_arg==4` branch's `switch`
  on the 4th arg's type has a `default:` case that sets `avoid =
  &the_null_array` for ANY non-object/non-array 4th arg, including a bare
  `int 0` — no `bad_argument()` is ever raised for this case on this
  driver build. Confirmed harmless by reading the driver source directly
  rather than assuming the catalog entry auto-applies; the real
  `yueyingqiyuan` bug this pattern was named after must have hit a
  different argument position or driver revision.
- **§15u** (dormant phone-home/license-check destructive function) —
  grepped `securityd.lpc`/`master.lpc` and the whole lib for
  `版权`/`盗版`/`正版`/`license`/suspicious `rm`+`shutdown` combinations;
  nothing found beyond an unrelated `cmds/std/curse.lpc` comment
  containing the substring "licensed_to_kill".
- **§15v** (`LONELY_IMPROVED`-gated dead `efun::X()` calls,
  `count_add`/etc bignum efuns) — not a nitan-lineage lib; grepped for
  `LONELY_IMPROVED` and `count_add\|count_mul` — zero hits, confirming
  this ES II-derived build never carried that fork's bignum/efun-gating
  convention at all.
- **§15z** (`static`→`nosave` blanket-sed colliding with a
  `#define nosave static` compatibility shim or a `"static/...\"`
  string-literal path) — grepped for both shapes after the sed ran; zero
  hits either way.
- **§8f** (`TYPE * a, b;` losing the array modifier on subsequent
  declarators) — found ~109 occurrences of the general shape
  `TYPE *name1, name2;`, but spot-checking a broad sample showed every one
  is an intentional single-scalar second declarator (an error/counter/
  string variable genuinely meant to be non-array, e.g. `mixed *cnd, err;`
  where `err` holds a `catch()` result) — not the Dead-Souls-style bug
  where the SECOND name was also later assigned an array value. Did not
  bulk-fix; no evidence this lib's authors ever wrote the buggy shape.
- A separate finding, confirmed **harmless, not fixed**: `adm/simul_efun/
  wizard.lpc`'s `wizhood()` has `if( objectp(ob) ) { if( ob=="suannai" )
  return "(admin)"; }` — comparing an OBJECT to a STRING literal, which is
  never true, so this hardcoded admin-shortcut never actually fires (an
  unused, differently-named sibling file, `adm/simul_efun/wiz.lpc`, has
  the corrected `getuid(ob)=="suannai"` version, but isn't `#include`d
  into `simul_efun.lpc` at all — a dead leftover, not the live copy).
  Harmless because the function always falls through to the real
  `SECURITY_D->get_status(ob)` check, and `adm/etc/wizlist` already lists
  `suannai (admin)` directly, so admin status resolves correctly anyway.
- A duplicate NPC file with a mojibake filename (GBK bytes `\xb8\xb4\xbc\xfe`
  = "复件" i.e. "Copy of", from `d/city/npc/`) — content differs from the
  real `xiaowang.lpc` it's named after, not referenced anywhere by any
  possible in-game path (nothing could type its raw byte sequence in an
  `inherit`/`load_object` call), left as-is; a permanent (harmless)
  `lpcc`-sweep failure, not fixed.

## Known content gaps (not fixed — genuine archive gaps, §13-style)

- **`d/hen/` zone (38 files)**: every file under this directory
  `#include <hen.h>`, and `hen.h` genuinely does not exist anywhere in
  the raw archive either (confirmed against `raw/`, not something our
  pipeline dropped). This is presumably a "恨"(hate/regret)-themed side
  zone whose shared header (macros for room-category constants judging by
  the `Undefined variable 'DEATH'/'TOUR'/'STUDY'/'SPORT'/'REST'/'MAGIC'`
  errors these files also throw) was simply never included in this
  release. None of these files are `#include`d/inherited from anywhere
  reachable via preload or the tested start zone.
- **`d/wuguan/{npc/jiading,npc/jiading1,qianyuan}.lpc` (3 files)**: call
  `CLOTH_OB("cloth")`/`WEAPON_OB("changjian")` as path-building macros
  that are never `#define`d anywhere in the archive (confirmed via
  whole-tree grep). A genuine, small, pre-existing content gap — not
  fabricated.
- **`d/wiz/angell/hp.lpc`**: a wizard-only diagnostic/"status card"
  command whose body is genuinely garbled mid-file (a `printf(...,)`
  with a dangling trailing comma and no closing arg, immediately followed
  by what looks like two merged/truncated lines — `ame(),ob->query
  ("genderprintf(...`). Almost certainly pre-existing corruption from the
  original archive (not a rename/encoding artifact — the surrounding
  ANSI-art `printf` calls are otherwise intact), and it's wizard-only
  tooling with no bearing on registration/ordinary play. Left unfixed
  rather than guess at reconstructing the intended two statements.

## Registration-flow AND post-login-command test (verified twice, both genders)

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/mohuanshiji/` (port 40092), then in ONE continuous
`scripts/mudclient.py` connection each time:

Run 1 (male): `""` → `gb` → `no` → `qinfengd` → `y` (confirm new char) →
`秦风四` (Chinese name) → `test12345` (password) → `test12345` (confirm) →
`qinfeng4@example.com` (email) → `m` (gender) → `9` (accept default gift
allocation) → `y` (confirm) → `look` → `score` → `quit`.

Run 2 (female): same shape with id `qinfenge`, name `秦风五`, gender `f`.

Both runs: encoding/age-gate prompts answered, English id accepted,
**Chinese name accepted on the first try** (validating the §15h fix),
password set/confirmed, email accepted, gender accepted with the
correctly gendered join broadcast (male: "…的小兄弟来到《魔幻世纪》求取真经" /
female: "…的小姑娘来到《魔幻世纪》求取真经"), landed in `/d/wiz/init`'s
gift-allocation dialog, accepted the default allocation, and the game
printed "好！祝你西天取经早成正果！" and moved the new character to the
real start room **南城客栈** (`/d/city/kezhan`) with a full room
description, exits, board, and NPCs (唐僧/店小二/千里眼) — `店小二`'s ambient
greeting even correctly used the gendered term ("这位小姑娘" for the female
run). `score` printed a complete, correctly-gendered character sheet
(仙衔/职称/attributes/etc). `quit` produced a clean "欢迎下次再来！" goodbye
with no hang. `log/debug.log` was **completely clean** (zero error/
undefined/recursion lines) across both full sessions, boot-to-quit.

## lpcc sweep results

`scripts/lpcc_check.sh` (fresh run after all fixes above): **8316/8535
pass (97.4%)**. Remaining 219 failures triaged by category:
- ~38 in `d/hen/` (missing `hen.h`, §13-style content gap, see above).
- A large fraction (~60+) of the rest are `#include`-only fragment files
  (`d/kaifeng/npc/quest*.lpc`'s shared `quest.lpc`/`reporting.lpc`
  fragments, and dozens of `daemon/class/*/*.lpc` skill-action files
  under the class/skill tree) failing standalone with `Undefined function
  query`/`setup`/`offensive_target`/`query_skill_prepare`/`prepare_skill`
  — all confirmed §6b sweep artifacts: the referenced functions are real,
  defined in `std/`-tree base classes (`std/sserver.lpc` defines
  `offensive_target`, `feature/dbase.lpc`-equivalent provides `query`)
  that these fragments only ever expect to inherit indirectly once
  composed into a real NPC/character object via `#include`, never when
  compiled as a bare top-level object by `lpcc`. Cross-checked against the
  fully clean `debug.log` from both real interactive sessions above.
- 3 in `d/wuguan/` (missing `CLOTH_OB`/`WEAPON_OB` macros, content gap,
  see above).
- A handful of genuine one-off pre-existing typos already fixed above
  (`hmeng014.lpc`, `BINGQI.lpc`, `poem.lpc`).
- 1 permanently-harmless mojibake-filename duplicate (see above).
- 1 genuinely-corrupted wizard command (`d/wiz/angell/hp.lpc`, see above).
- A small number of `Cannot #include uid.h`/`config.h`/`reporting.h` and
  assorted `syntax error`/`Undefined variable 'X'` failures not
  individually root-caused given time constraints on this, the last
  archive of the batch — none are reachable from the preload list or the
  tested registration/`look`/`score` path, consistent with the project's
  stated "breadth over exhaustive depth" priority.

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter**: ran `format-corpus.mjs` across all 8535 `.lpc` files
  under `work/` — 8383 reformatted, 133 unchanged, 19 refused
  (token-mismatch safety gate, expected/fine, not investigated further).
- **Native retest against the freshly-rebuilt driver**: booted clean
  (`Initializations complete.`, zero fatal errors). Repeated the full
  registration flow from this file's own "Registration-flow" section
  above with a fresh real Chinese name (`秦风六` / id `qflibsj`),
  reached 南城客栈, and confirmed `score` renders correctly and `quit`
  exits cleanly ("欢迎下次再来！"). No regression from the reformat or
  driver rebuild — behavior identical to the original conversion pass.
- **WASM build test** (`scripts/wasm_client.js`): **fully playable**,
  including a full real-name registration (`秦风七` / id `qflibwsj`)
  reaching 南城客栈 with correct room/NPC text and a clean `quit`. One
  thing worth flagging for the record: `debug.log` shows a single
  non-fatal `*Array index out of bounds` trace from `adm/daemons/
  ipd.lpc`'s `seek_ip_address()` during `enter_world()` — the exact same
  root cause as the documented `query_ip_number()`-under-WASM limitation
  (an empty/malformed IP string breaks `ipd.lpc`'s `explode(ip,
  ".")[1]` indexing), but here it fires from `enter_world()`'s tail-end
  "welcome, you're connecting from…" text lookup, which runs *after* the
  character is already created and moved into the world — so the
  uncaught error just skips that one cosmetic message instead of
  breaking the `input_to()` callback chain the way it does for `mhxy`
  (same bug, same lineage's `ipd.lpc`, different call site — this one
  isn't gating anything). Confirmed no functional impact: registration
  completed, room description/NPCs/exits all rendered normally, and
  `quit` worked. Status: **fully playable under WASM** (with one
  cosmetic, non-blocking IP-lookup error logged, same driver-level root
  cause as `mhxy`'s WASM limitation but not blocking here).

## WASM-enablement pass (2026-07-23): loopback-allow + admin seeding

Gates patched (loopback = `127.0.0.1`, any `127.*`, or an empty/malformed
non-dotted-quad string, which is what current WASM builds return):

- `adm/daemons/band.lpc` — `is_banned()` (~line 149),
  `create_char_banned()` (~168), `is_strict_banned()` (~187)
  short-circuit return 0 for loopback; `allow_multi_login()` (~242)
  returns 1000 for loopback.
- `adm/daemons/logind.lpc` `encoding()` — new `local_conn` flag; the
  `!ip_name` destruct and the "Non_number" character-scan destruct
  (~lines 158-175) are skipped for loopback/malformed IPs.
- `adm/daemons/ipd.lpc` `seek_ip_address()` — returns "本地连接" for
  loopback/short IPs instead of the (previously cosmetic-only under WASM)
  `explode(ip,".")[1]` out-of-bounds throw.
- `adm/daemons/securityd.lpc` `match_wiz_site()` (~line 97) — loopback
  always passes wizard site restriction.
- No `uptime()` startup gate, no multi-login cap use, and no reconnect
  throttle exist in this lib's logind (checked).

Admin account: `fluffos` / `Mud@2026`, Chinese name 浮浮, granted
`(admin)` via `/adm/etc/wizlist` (file normalized CRLF→LF). Verified:
registration via the real flow (login banner even shows 目前权限：(admin)),
re-login, `update /d/city/kezhan.lpc` succeeds. Saves at
`data/login/f/fluffos.o` + `data/user/f/fluffos.o` (not gitignored).
Fresh normal registration (秦风/testqa, female branch) re-verified
end-to-end and the test char removed; debug.log clean.

### Fail-closed retrofit (2026-07-24)

The loopback carve-out above originally ALSO treated any empty/
non-string/unparseable IP as trusted-local (fail-open, defensive against
an older WASM `query_ip_number()` bug now fixed upstream). Tightened to
strict loopback only (`"127.0.0.1"`, `"::1"`, `"127."` prefix) across
`band.lpc` (×4), `securityd.lpc`'s `match_wiz_site`, `ipd.lpc` (falls back
to "未知地区" for unparseable input instead of "本地连接"), and
`logind.lpc`'s `local_conn` flag. Re-verified loopback login/look/`update`/
quit all still work after tightening.

## 深度功能测试（第二轮，2026-08-03）

之前的会话只测过注册流程，本轮做了完整的 §10.7 深度功能测试。
proactive 检查 AGENTS.md 已归档的四类常见坏味道：`feature/
command.lpc` 里的"private nomask command_hook"只是一行历史注释
（`// private nomask int command_hook(...)`），真正生效的声明早已
是干净的 `nomask int command_hook(...)`；命中了一处 `adm/daemons/
logind.lpc` 里的 printf("%O") 调试残留（新增 `mohuanshiji` 到
AGENTS.md §7.34 确认实例列表）；未命中 unguarded MESSAGE_D->、
stat/water 键名、§8.9 坏 age 判断。

**完整流程验证**：注册全新角色（沐魔幻/id `mhsjqin`，途中还发现
了一步之前没记录过的"您是否是中小学学生或年龄更小？(yes/no)"年
龄自述关卡——答 yes 或不理会直接被系统劝退，答 no 才能继续注册，
纯属游戏自带的内容提示，不是 bug），从"南城客栈"（同一个西游记
ES2 大家族的经典布景，唐僧、店小二、千里眼 NPC 驻场）出发，向
"朱雀大街"的"疥顶小僧"（这批西游记题材姊妹档案里反复出现的同一个
高战力 NPC，combat_exp 50000）发起战斗——完整交手数回合后被击昏
迷致死，送往"阴阳界"由"朱笔判官 崔珏"接引（和 `yszz`/`bmxkx2001`
是同一套死亡/复活设计），静候片刻后自动复活还阳，`score` 数据完
整（气血显示"重伤"正在恢复中，其余状态正常）；`quit` 干净退出。
全程 debug.log 零报错。

**顺带核实一处文档与实际行为不一致，判断为陈旧帮助文档而非 bug，
未做代码改动**：`doc/help/newbie` 第二条明确写着"刚进入时，你的
食物和饮水都是空的"，但实测新角色食物/饮水槽创建时就是满的
（"正常"状态）。查了 `logind.lpc` 里的赋值语句——
`user->set("food", user->max_food_capacity())`
/`user->set("water", user->max_water_capacity())`——这是一行无条
件执行、没有任何坏掉的前置判断的正常代码，明确就是设计成"创建时
直接给满"，不是 §8.9 那种"卡在错误物件的判断条件"式 bug。判断为
帮助文档没有跟上后来的某次平衡性调整，按项目惯例不去改动这行明
确、正常工作的代码去迁就一份过时文档。

**未覆盖范围**：拜师、留言板、当铺/兵器铺购物因时间原因未实测。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 35 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 274 live occurrences deleted: 269 via scripted sweep (`fix_710_room.py`), plus 5 hand-fixed roommaker-tool occurrences across 3 tool copies (`clone/misc/roommaker.lpc`, `obj/roommaker.lpc` — simple variant; `cmds/wiz/roommaker.lpc` — "room_code"/`str` 3-occurrence variant). 7 already-commented-out instances left untouched. One occurrence NOT fixed: `d/city/center2.lpc` is already syntactically broken independent of this bug (unquoted strings like `set(short, 十字街头)`, stray `??` token, no semicolons at all in `create()`) — never compiles regardless, out of scope. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, port 40092 listening, zero new "cannot replace"/"cannot bind" debug.log lines. Pre-existing untracked test-account debris (`data/{login,user}/m/mhsj{dive,qin}.o`) confirmed left untouched.

## Round-four re-test (2026-08-20): 拜师/留言板/当铺·兵器铺 + standing-checklist sanity pass

Covered exactly the three areas round-two/round-three had explicitly left
untested for time, plus a sanity re-check of the standing bug catalog
items called out for this pass.

**Checklist sanity pass** (all confirmed already correct/intact, no
regressions, nothing new needed):
- **§7.90** (eval-cost) — `config.fluffos` still has `maximum evaluation
  cost : 5000000`, intact.
- **§7.100** — re-confirmed intact (see sweep entry directly above).
- **§7.111** (`standard_trace()`/`report_error()` unguarded
  `file_name(error["object"])`) — both call sites in
  `adm/obj/master.lpc` already have the `(undefinedp(error["object"]) ||
  !error["object"]) ? "(none)" : file_name(error["object"])` guard from
  the corpus sweep.
- **§7.112** (`init()` `call_out` reconnect-duplication) — all 4
  `d/death/npc/{wgargoyle,bgargoyle,pang,b}.lpc` death-desk NPCs already
  guard with the `death_stage_active` temp flag.
- **§7.113** (netdead reconnect losing `heart_beat`) — `obj/user.lpc`'s
  `reconnect()` unconditionally does `set_heart_beat(1)`, and
  `adm/daemons/logind.lpc`'s driver-invoked `reconnect()` calls
  `user->reconnect()` unconditionally; correct lineage, no bug.
- **§7.114** (`private` `input_to()` mixin callback) — `feature/edit.lpc`'s
  `input_line()` is plain (not `private`); live-verified below with a
  real multi-line board post.
- **§7.115** (missing `QUEST` macro target) — `include/globals.h`'s
  `QUEST` points at `/std/quest`, and `std/quest.lpc` genuinely exists in
  this archive. Not applicable.
- **§7.79** (bare 2-arg `addn`/`addn_temp`) — this lib has **zero**
  `addn(`/`addn_temp(` call sites anywhere in the whole tree (grepped),
  and no local `addn` definition either. Not applicable — this lib was
  never in the affected lineage.

**1. 拜师 (sect apprenticeship) — mechanism confirmed working (clean
rejection).** Located the command (`cmds/std/apprentice.lpc`) and a
reachable, no-existing-family-required sect master, 秦琼 (`d/jjf/npc/
qinqiong.lpc`, in `d/jjf/keting`正厅). `apprentice qin` (id `qin`, not
`qinqiong` — the alias list is `qin qiong`/`qin`/`shubao`/etc., space-
separated multi-word ids only) correctly resolved the target and
triggered `attempt_apprentice()`, which rejected on the admin test
character's insufficient `combat_exp` (< 100000) with an in-character
reason ("这位小兄弟还是先去跟本府家将打打基础吧！") — exactly the
"reject with a sensible reason" clean-pass shape. Re-verified identical
on a completely fresh driver boot. No crash, no `debug.log`/boot-log
error either time.

**2. 留言板 (board posting) — confirmed fully working.** `post board` at
`南城客栈留言板` (`/obj/board/nancheng_b.lpc`, `inherit BULLETIN_BOARD`
with no stray `replace_program()` — matches the already-applied §7.86/
§7.100 fixes) entered the line-editor cleanly; two content lines plus a
title line were all accepted (no "什么？" misroute on any line, ruling
out the §7.114 shape), `.` ended the post with "留言完毕。", and `read 1
board` immediately after showed the full multi-line content correctly
saved with the right author/timestamp. Persisted correctly across a full
driver restart. Test post removed afterward via the in-game `discard 1
board` command (admin-authored, cleanly deletable) to leave the board
back in its pre-test empty state — `data/board/` directory removed
after, no residue.

**3. 当铺 (pawnshop) / 兵器铺 (weapon shop) — REAL BUG FOUND AND FIXED.**

`当铺` (`/d/city/dangpu.lpc`, `inherit HOCKSHOP`) worked cleanly:
`value`/`pawn`/`sell`/`retrieve <stamp>` all round-tripped correctly on
a cloned test weapon (典当 480 银, 卖断 640 银, 赎回 560 银 — sane,
consistent conversion math each time). `list` correctly reported "当铺
目前没有任何货物可卖" since this pawnshop has no `vendor_goods` of its
own (by design — it only deals in player-pawned items, not a curated
sale list).

`兵器铺` (`/d/city/bingqipu.lpc`) crashed hard: `list` (i.e. simply
browsing the shop's stock, the very first thing any player does before
buying) threw an uncaught driver-level error on every single call:
```
执行时段错误：*call_other() couldn't find object '/clone/armor/whip'.
程序：/feature/vendor.lpc 第 48 行
```
Root cause: `feature/vendor.lpc`'s `do_vendor_list()` does
`goods[name[i]]->query("name")` on each `vendor_goods` string value
directly (an implicit lazy-compile `call_other`), with no existence
guard — and **every one of the vendor 萧萧's (`d/city/npc/xiaoxiao.lpc`)
10 `vendor_goods` entries** pointed at `/clone/armor/<item>`, none of
which resolved, because the whole directory on disk was
`clone/ARMOR/` (uppercase) with 14 of its 21 item files ALSO carrying an
uppercase basename (`WHIP.lpc`, `SWORD.lpc`, `MACE.lpc`, etc.) — the
exact same "Windows-authored uppercase directory/filename vs. a
lowercase path baked into the referencing code" shape this lib's own
`adm/daemons/CHANNELD.lpc`-vs-`CHANNEL_D` bug already documented above,
just one level up (a whole directory, not one file) and hitting a much
more central, always-reachable code path (`list` in ANY shop using this
NPC's item catalog) instead of a rarely-exercised daemon call site. This
made the entire 兵器铺 permanently unusable for every player — `list`
never worked, and `buy`/`value` on any of its 10 items would have hit
the identical unguarded `->` call in `buy_object()`/`complete_trade()`
the moment anyone tried.

**Fix**: renamed `clone/ARMOR/` → `clone/armor/` and the 14
uppercase-basename files inside it to lowercase (`bang.lpc`,
`blade.lpc`, `dun.lpc`, `fork.lpc`, `jinjia.lpc`, `kui.lpc`, `mace.lpc`,
`pao.lpc`, `pifeng.lpc`, `shoes.lpc`, `spear.lpc`, `staff.lpc`,
`sword.lpc`, `whip.lpc`, `zhi.lpc`) — all via `git mv`, content
untouched, matching every `/clone/armor/<lowercase-id>` reference
already in the code (corpus-wide grep confirmed exact 1:1 coverage, no
orphaned or newly-broken references either direction).

**Extended sweep of the same bug class, whole `clone/` tree.** Given
this was a real, live-reachable crash and the fix pattern is mechanical
and low-risk, ran the same "uppercase-basename file/dir vs. a lowercase
reference elsewhere in the corpus" check across all of `clone/` (not
just `armor/`), cross-referencing every `/clone/...` string literal in
every `.lpc`/`.h` file corpus-wide against the actual on-disk filenames.
Found **31 more** genuinely-broken (referenced-but-case-mismatched)
files, all suffering the identical fate — silent, unconditional
`->query()`/`new()` crashes the moment anything actually touched them
(NPC weapon-equip calls, gift-item grants, event/魔幻-item spawns):
`clone/{dan,qinghong,jiasha,tiekui,yinjia,bi,dun}.lpc` (top-level),
`clone/gift/{lingzhi,bingtang,xisuidan,xiandan}.lpc`,
`clone/bq/bang.lpc`, and 18 files under `clone/mohuan/`
(`{spear,qin,fork,armor,jindao,pifeng,staff,whip,cloth,shoes,shendan,
sq,qingting,dun,mobang,axe,kui,sengxie,xiandan}.lpc`). All renamed the
same way (`git mv`, content untouched). Re-ran the full corpus-wide
scan afterward: **zero remaining case-mismatched `/clone/...`
references** anywhere in the lib. (A separate, larger set of `/clone/...`
references — `d/hen/`-adjacent weapon items, `d/wuguan/`'s
`CLOTH_OB`/`WEAPON_OB` macro targets, a handful of `/clone/gift/` and
`/clone/book/` paths — genuinely have no on-disk file under ANY case
variant; left alone as pre-existing content gaps, not this bug.)

**Verification**: live-tested end-to-end on a freshly rebooted driver
(new PID, full recompile) — 兵器铺's `list` now shows all 10 weapons
with correct prices, `buy mace from xiao` completed a real gold-for-item
transaction (deducted the listed price, item appeared in inventory), and
the full 当铺 `value`/`pawn`/`sell`/`retrieve` cycle was re-run
end-to-end on the purchased item with correct currency math throughout.
Zero errors in the boot log across both driver runs (pre-fix crash was
player-visible in-session; post-fix, `list`/`buy` on this and every
other renamed item path produced no error at all). Driver killed by
exact PID (`kill -TERM`, not `pkill`) after testing. Admin account
(`fluffos`) inventory/gold left in its post-test state (matches this
lib's established convention of leaving the working admin seed account
as a normal, actively-used account); the synthetic board test post and
its resulting `data/board/` save file were both removed, and the only
remaining untracked debris is the pre-existing `mhsj{dive,qin}` test
account pair already documented above (left untouched).

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

## Round-four re-verify (2026-08-24): re-ran 拜师/留言板/兵器铺, found and fixed a real §7.117 instance

The task brief for this pass named the same three areas as the
2026-08-20 entry above (拜师/留言板/当铺·兵器铺) — that entry already
covers them and fixes the 兵器铺 case-mismatch crash. Re-verified all
three live on a fresh driver boot before doing any new work, since the
brief also asked to specifically check for AGENTS.md §7.117 (the
`apprentice`/`bai`/`recruit` first-time-applicant guard gap, documented
after the 08-20 pass) — which the 08-20 entry did not check for.

**Re-confirmed clean, no regressions**: NPC-rejection path
(`apprentice qin` at low `combat_exp`, exact same 秦琼/`d/jjf/keting`
setup as before) still gives the same clean in-character rejection;
board `post`/`read`/`discard` round-trip at 南城客栈留言板 still works
end-to-end; 兵器铺's `list`/`buy` still work (`clone/armor/` stays
lowercase, no case-mismatch regressions found anywhere under `clone/`).

**Found and fixed a real §7.117 instance.** `cmds/std/apprentice.lpc`'s
"the target already offered to recruit me, I'm confirming" branch (the
`ob->query_temp("pending/recruit") == me` branch, entered when a player
runs `apprentice <master>` a second time after the master's
`attempt_apprentice()`/`recruit` accepted them) compared
`me->query("family/family_name") != ob->query("family/family_name")`
with **no guard for `me` having no family yet** — exactly the pattern
in AGENTS.md §7.117. For any legitimate first-time apprentice (the
overwhelmingly common case — everyone's first sect join goes through
this exact code path), `me->query("family/family_name")` returns `0`
(no family set), `(string)0` casts to `"0"`, which is never equal to
the master's real family name, so the check always misfires into the
"betray your old sect" branch: wrong flavor text (`$N决定投入$n门下`
instead of the correct `$N决定拜$n为师`), plus `me->set("score", 0)`
and `me->add("betrayer", 1)` incorrectly applied to a brand-new
apprentice who never had a prior sect to betray.

The sibling file `cmds/std/recruit.lpc` (the master's side of the same
recruit/confirm transaction) already has the correct guard at its
analogous check (line 63: `if ((ob->query("family")) && (...))`), with
an explicit comment `// follow modified by elon 09-10-95 to fix a bug
in 1st time recruit` acknowledging this exact bug class — the fix was
applied once to `recruit.lpc` decades ago and never ported to its twin,
`apprentice.lpc`. Matches the general §7.117 write-up's own observation
about this exact half-fixed-pair shape.

**Fix** (`cmds/std/apprentice.lpc`, in the recruit-confirm branch):
```lpc
// before:
if ((string)me->query("family/family_name") != (string)ob->query("family/family_name")) {
// after:
if ((me->query("family")) && ((string)me->query("family/family_name") != (string)ob->query("family/family_name"))) {
```

**Live-verified end-to-end** on a fresh driver boot: bumped a
family-less admin test character's `combat_exp` to 200000 (temporarily,
via a throwaway wizard command created and removed within this
session — not left behind), went to 秦琼 at `d/jjf/keting`, ran
`apprentice qin` twice (first call triggers `attempt_apprentice()` ->
NPC `recruit`s the player; second call is the player's confirm). Before
the fix this would have shown the wrong "決定投入...門下" betrayal
message and zeroed `score`; after the fix it correctly shows "秦琼决定
收你为弟子。...恭喜您成为将军府的第三代弟子。", and `score` correctly
shows `师承：将军府秦琼` / `将军府第三代弟子`. Reverted the test
character's `family`/`title`/`betrayer`/`combat_exp`/`class` fields
back to pristine afterward (also bought+destroyed one 兵器铺 item along
the way while re-verifying the shop — correct gold deduction, 19→11
两黄金 for an 8-两黄金 item — left the resulting gold balance as the
account's normal post-test state, matching this lib's existing
admin-account convention). `lpcc --batch` and a full driver reboot both
clean after the fix, zero new debug.log errors. No corpus-wide sweep
of this exact shape was attempted here (each instance needs hand
verification per the general §7.117 write-up); left for a future
dedicated sweep as already flagged there.

## AGENTS.md §7.19: enable_player() reentrancy guard (2026-09-01)

Same corpus-wide bug class as `mhxy`/`wuhanzhan`: `feature/command.lpc`'s
`enable_player()` wraps `enable_commands()` and is unconditionally
reachable from an NPC's `init()` via `setup()`/`reset_me()` (confirmed
on this lib's own `d/*/npc/zhangmen*.lpc`-family NPCs, matching
`mhxy`'s originally-documented `d/xueshan/npc/zhangmen.lpc` pattern).
Calling `enable_commands()` on an object that's already `living()`
makes the driver re-invoke that object's `init()` as a side effect;
since `init()` calls back into `enable_player()`, that is genuine
same-call-stack reentrancy that repeats until "Too deep recursion"
aborts a room's first-ever visit.

Fixed with a true reentrancy flag (`nosave private int
in_enable_player_now;`), NOT a bare `if (living(this_object()))
return;` guard — this lib's `feature/damage.lpc` `revive()` and
`cmds/std/sleep.lpc` `wakeup()`/`wakeup2()` all legitimately
re-invoke `enable_player()` while the object is still `living()`
(that's how a fainted/asleep character gets commands back), so a
living()-gated guard would silently break every one of those real
re-enables. `enable_player()`'s single body has no early `return`
statements, so the flag is set at entry and cleared once, before the
function's fall-through end. Verified with a single-file `lpcc`
compile check (exit 0, no errors) against `feature/command.lpc`.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 2 file(s) `inherit F_SSERVER;` and no header defines it (1 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 257 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 3 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py mohuanshiji --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（三份 `xuanyuan-archery`/`xuanyuan-arrow` 删去什么也不做的 `(: throw_weapon :);`）：共改动 696 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：674 -> 674 通过，无回退；改过的头文件的 324 个包含者 314 -> 314 通过。
手工：`adm/daemons/fingerd.lpc` 把 `string *exclude` 声明了两次（先 `({})`，再 `({ "gslxz", "suannai" })`），删去前一个，值不变；`adm/daemons/logind.lpc` `get_id()` 删去没用到的 `*usr = children(USER_OB)`。

启动时警告 91 -> 0；新进程登录（编码选择、新人物提问）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 17 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 10 个，只在 #if 分支用的声明移进分支 0 个文件；改动 25 个文件，HEAD 与工作树各载入一次无回退（25 objects; HEAD PASS 19, tree PASS 19; regress 0; newly loading 0），这些文件的警告 50 -> 20。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 11 处多余继承；搬来 xianlvqiyuan（8c3c85ca28e）的 19 个文件，与本库逐 token 相同（袈裟 `tear`、`d/kaifeng/ground.h` 表格守卫、`yaoguai_type`、李靖与玉兔改 `void`、`alias.lpc` 的 `last_cmd_time`、`colors.h` 防重等）；手工：`d/wusheng/npc/jinren.lpc` 的 `kill_ob()` 改 `void`，`cmds/wiz/roommaker.lpc` 两份 `special_props` 删去前一份（代码用后一份）。能编译的文件警告清零；改动的 25 个对象在 HEAD 与工作树各载入一次：HEAD PASS 22，tree PASS 22，regress 0。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。5 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

5 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。4 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/wusheng/shijie5`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`yueya-chan/feicha`。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

36 个文件、41 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/liwu/obj/jiericloth`、`/d/city/npc/obj/choupao`、`/clone/weapon/needle1`）。本库 NPC 基类 `std/char/npc.lpc`、`std/char/npcs.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 2 个，改后 34 个（32 个原来载入不了），没有退步；其余 4 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`HALBERD` → `/std/weapon/halberd`（6 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：6 个里 6 个通过。


## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 9 个对象设了本库没有文件的武功（11 个名字，最多的是 `qin`、`strike`、`cuff`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：9 个里 6 个通过，其余 3 个停在别的错误上（`d/PANSI/NPC/ZIXIA`：*Bad argument 1 to EFUN call_other()；`d/city/obj/npc/zhong`：*No program in object '/d/city/obj/npc/zhong'!……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/PANSI/fangjian1` 的 `south`：`shiji1` → `SHIJI1`；`/d/PANSI/fangjian2` 的 `south`：`shiji2` → `SHIJI2`；`/d/PANSI/fangjian3` 的 `east`：`tongmen` → `TONGMEN`；`/d/changan/fendui` 的 `down`：`fen` → `FEN`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/unarmed`（宏 `UNARMED`）←sjsh，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 12 处、12 个文件：`dagonforce`→`dragonforce`（4 处）、`hellfire_whip`→`hellfire-whip`（2 处）、`yange_blade`→`yange-blade`（2 处）、`dragon-step`→`dragonstep`（2 处）、`changqaun`→`changquan`（1 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::buy_object()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 2 个：`d/city/obj/npc/zhong`、`d/wuguan/npc/master`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 54 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `SPORT`、`WEAPON_OB`、`MATRON`、`BATHE`、`INN`、`HAWKER`、`LOGER`、`EAT` 等共 54 个，用到它们的物件（名单里 35 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 同一个 init() 写了两遍、内容不同（2026-10-19，KB 06 §7.265）

`d/xuyi/npc/maihuanu1` 里 `init()` 定义了两次（一个加 `buy`/`work` 之类的指令，另一个再加 `list`/`block_cmd`），驱动报 `Redeclaration of function 'init'`，整个物件载入不了。两处作者本来都要：把第二个 `init()` 里的 `add_action(...)` 并到第一个 `init()` 末尾，删掉第二个。（`scripts/lpc_merge_dup_init.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/city/kezhan.lpc` 的 `down` 出口：`/d/city/daoju` → `/d/city/DAOJU`
- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/city/obj/npc/daiyu.lpc` 的 `#include "/u/fly/npc/npc.h"` 改成 `/d/city/obj/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/jz/npc/jiang.lpc`（dtxyzjb）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/cmds/imm/cast2.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 8 处）。改动：`/clone/medicine/liushen.lpc`（1 处）、`/cmds/wiz/dns.lpc`（1 处）、`/d/city/mjlady3.lpc`（3 处）、`/d/city/npc/MJ.lpc`（3 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`、`/std/char/npcs.lpc`（共 2 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dumpprog.lpc`（`new`）。加载检查 HEAD 与工作树对照，没有退步。

## `cron.lpc`：`emery()` 用循环外的下标，第一次越界就让 cron 停摆（2026-10-21，KB 06 §7.345）

怪兽入侵事件 `emery()`（`/adm/daemons/cron.lpc`）末尾 `for (m = 0; m < sizeof(user); m++) user[i]->set("kill_guaishou", 1);`：`i` 是前面随机选的地区下标，循环变量 `m` 没用上，同一个玩家被标记 `sizeof(user)` 次，在线人数不到 `i + 1` 时下标越界（`Array index out of bounds`，yueyingqiyuan 管理员扫描里的控制台行；`call /adm/daemons/cron->emery()` 一个人在线时四次里三次抛错）。`init_cron()` 在 15 分钟的整点调用 `emery()`，之后才 `call_out("init_cron", 60)` 重新排自己：抛错之后重排没有执行，玩家自动存盘（`autosave()`）、动态任务刷新（`TASK_D->init_dynamic_quest()`）和后面所有事件在这次启动里都停了。改成 `user[m]`（yueyingqiyuan 上实测：连续六次 `emery()` 都正常返回）。这个标记档案里没有任何地方读它（`go.lpc` 里的用法是注释掉的）。

## `cast1`：宏 `SYNTAX` 带着分号（2026-10-21，KB 04 §6.28）

`#define SYNTAX "指令格式：cast <法术> [<参数>| on <目标>]\n";` 的 `;` 属于宏展开，`notify_fail(SYNTAX);` 变成 `notify_fail("..." ;);`，整个指令编译不了（`unexpected ';'`）。去掉宏里的分号，并删掉没用到的局部变量 `dest`（编译警告）。本库的 `valid_kill(killer, victim, no_list)` 要三个参数，调用只给两个，补了 `, 0`（和同库 `ccast.lpc` 一样，KB 04 §6.19）。

## `tail`：`do_tail_lpc()` 定义在 `main()` 之后，没有原型（2026-10-21，KB 04 §6.28）

没有 `tail()` efun 之后用 LPC 重写的版本把辅助函数放在 `main()` 下面，编译报 `Undefined function do_tail_lpc`。在 `main()` 前加原型 `int do_tail_lpc(string file, int n);`。

## `ccast`、`ssteal`、`jji`、`pperform`：新手保护检查贴在目标赋值之前（2026-10-21，KB 06 §7.346）

`/cmds/std/ccast.lpc`、`/cmds/std/ssteal.lpc`：vikee 加的“本站暂时保护新手”检查 `if (userp(target) && target->query("age") < 16)`（以及后面两句 `... && userp(target)`）贴在 `target = present(...)` 之前。老驱动里 `userp(0)` 是 0，这几句从来不会触发；这里 `userp(0)` 抛错，指令一用就死。保持原来的（不触发）效果：赋值之前的 `userp(target)` 改成 `objectp(target) && userp(target)`。`pperform` 的检查还写着没声明的 `obj->query("target")`（整条指令编译不了），改成 `target->query("age")`，和其他几条一致。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 21 条注册（12 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/CL/YI.lpc`（`hun`）、`/d/PANSI/NPC/QINGXIA.lpc`（`do_yes`）、`/d/changan/FEN.lpc`（`do_chop`）、`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/WORK.lpc`（`do_buy`、`do_list`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/city/obj/npc/baochai.lpc`（`do_mo`）、`/d/eastway/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/eastway/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/obj/book/yishu.lpc`（`do_eat`） 等共 12 个文件。最多的函数名：`do_list` 3 处、`do_mo` 2 处、`do_cost` 2 处、`do_upgrade` 2 处、`do_push` 2 处。没有动（读过）：`/obj/prize/xueshan.lpc` 的 `do_chi`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 3 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 代码里写死 `.c` 后缀的路径（2026-10-22，KB 06 §7.356）

`carry_object("/x/y.c")->wield()`、`new("/x/y.c")`、`inherit "/x/y.c"`、出口 `"down" : "/x/y.c"`、商店货单 `"/x/y.c" : 10` 这类字符串，压缩包里的文件早已改名成 `y.lpc`；明确写出的后缀按原样查找（KB 03 §4.2），找不到文件，`new()` 返回 0，`0->wield()` 报 `Bad argument 1 to EFUN call_other() Got int(0)`，NPC 的 `create()` 中途退出、整个对象加载不了。`scripts/lpc_fix_dotc_path.py` 把 9 个文件里的 27 处 `.c` 改成 `.lpc`（只改文件存在于 `.lpc`、不存在于 `.c` 的代码字符串；注释、巫师目录、两种写法都不存在的路径不动）：`/d/wiz/no_get.c`、`/d/obj/cloth/tianyi.c`、`/d/obj/weapon/dagger/dagger.c`、`/d/obj/weapon/axe/tiefu.c`、`/clone/mohuan/armor.c` 等。 加载检查（HEAD 与工作区对比，改动的 9 个文件）：HEAD 能加载 4 个，现在 9 个（新增可加载 5 个，回归 0 个）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 3 个函数没有补（inquiry 2, chat_msg_combat 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/city/obj/npc/baochai.lpc`:`ask_tea`、`/d/death/npc/yanluowang.lpc`:`ask_cancel`、`/d/xueshan/obj/hufabird.lpc`:`saysth`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 3 个文件里 4 行只含这个指针的行（`"茶": (: ask_tea :),` `"tea": (: ask_tea :),` `"cancel": (: ask_cancel :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 写死的 `"/路径"->函数()` 指向库里没有的文件：改成现存的同名文件（2026-10-22，KB 06 §7.359）

1 处语句级的 `call_other` 字面量路径，库里没有这个文件（区域改了名 / 大小写不对 / 差一个字母 / 文件挪了地方）：`"/daemon/class/yaomo/wudidong/qixiu-jian/zxzx"->zxzx_effect()`（`/adm/daemons/combatd.lpc`）→ `"/daemon/class/yaomo/wudidong/qixiu-jian/ZXZX"`。`call_other()` 对不存在的对象抛 `couldn't find object`，所在函数当场中断。改成库里现存、并且定义了被调用函数的文件（`scripts/lpc_fix_call_path.py`；巫师目录、备份目录、名字不同的兄弟文件都不算候选）。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 3 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 3 处（2 个文件）：拼名字的赋值 3 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/master.lpc:104`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：6 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 6 处（3 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/d/city/npc/zhangsunwuji.lpc:163`）；`if ((strlen(arg) < 2) || (strlen(arg) > 12)) {`（`/d/city/obj/npc/zhifu.lpc:106`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 12 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。
