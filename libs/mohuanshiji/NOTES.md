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
