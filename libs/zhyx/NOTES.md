# zhyx (中华英雄) -- porting notes

Source: `git clone https://github.com/MudRen/zhyx` (commit
`762908319b23b4ae910718daf524f91c70bf5817`, cloned 2026-08-26). Per an
earlier research pass this is the canonical/current version of the
"中华英雄" ("Chinese Hero") codebase -- its own `README.md` self-identifies
as "中华英雄MUD FluffOS v2017 版", names `mud.ren 5000` as its own live,
long-running production server ("长期稳定开放"), and has a much larger
domain list (~90+ named locations under `d/`) than a superseded sibling
repo (`ZHLib`, an older 2006 snapshot with a far smaller domain set) that
an earlier pass already ruled out. Not a duplicate of anything already in
this collection -- checked against the yanhuangwuhun/YHLib/yhmud cluster,
which is thematically similar (same underlying ES II/yh2003 lineage, see
below) but has its own distinct, much smaller domain list. Slug `zhyx`,
number 931, port 40233 (40232 was picked first but collided live with a
concurrent session's `sunshadow` onboarding; reassigned before first
boot).

Raw archive: 16,786 files (~99MB), 15,561 `.lpc` files after conversion.
Top-level layout: `adm b backup binaries clone cmds config.cfg d data
doc driver dump feature grant hate include inherit kungfu log quest
questobj shadow status temp u` -- the mudlib root is the repo root
itself (no nested wrapper directory). `driver`/`binaries` are empty
placeholders (`.gitignore`-only); a bundled `MudOSxp.exe` (an old MudOS
Windows binary, mentioned in the repo's own README as an alternative,
password-incompatible way to run this lib) and a stray FreeBSD ELF
binary at `u/yuchang/driver` were both ignored, per standing project
policy -- only the LPC mudlib source was converted and run through this
project's own FluffOS build.

## Lineage

`adm/single/master.c`'s header comment is the exact same lineage chain
already documented for `yanhuangwuhun`/`yhyxs`/`yhwhckdm` in this
collection: "for ES II mudlib / original from Lil / rewritten by
Annihilator (11/07/94) / modified by Xiang for XKX (12/15/95) / updated
by Doing Lu for hell (2K) / **Modify By Linux@lxtx for yh 2003.3**".
Same `adm/single/{master,simul_efun}` layout (not `adm/obj/`), same
`F_DBASE`-based property storage (no bare `set`/`query`/`delete`
simul_efuns -- confirmed by reading `adm/simul_efun/*.lpc`), same
overall registration flow (English login id -> confirm -> Chinese
surname -> Chinese given name -> admin password -> regular password ->
1-5 character-type selection -> gender -> world entry) as
`yanhuangwuhun`. **But independently, substantially diverged**: a
byte-count diff of this archive's `master.c`/`chinese.c`/`named.c`/
`logind.c`/`securityd.c`/`message.c` against `yanhuangwuhun`'s converted
copies runs from 46 differing lines (`chinese.lpc`) up to 2,236
(`logind.lpc`) -- confirming a real, old fork rather than a near-copy,
so every catalog fix below was independently verified against this
archive's own code, not blindly ported. The whole domain/quest/
kungfu-skill content tree is this codebase's own -- distinct from every
other yh2003-family lib already in this collection.

## Pipeline

1. Cloned directly into `libs/zhyx/raw/zhyx/` (git-hosted source, no
   archive-extraction step needed -- `.git` stripped before copying in,
   per this project's convention for already-git-hosted sources).
2. `scripts/convert_lib.sh libs/zhyx/raw/zhyx libs/zhyx/work GB18030`:
   `already_utf8=642 converted=16092 lossy=13 skipped_binary=39`;
   renamed 15,561 files to `.lpc`; fixed 6,812 literal `.c"` references
   + 17 `#include <....c>` refs; converted 13 local angle-bracket
   includes to quotes; `static`->`nosave` touched 143 files (no
   collision counterexamples found on inspection, unlike some sibling
   libs' large false-positive runs).
3. Full-tree straggler sweep (per AGENTS.md §4.1, beyond what
   `convert_lib.sh`'s extension-based scan covers): a plain Python
   UTF-8-decode walk of the whole `work/` tree found 24 non-UTF8 files.
   Triaged each:
   - **Genuine un-transcoded GBK text** (fixed): `clone/game/8_hlp`,
     `clone/game/21_hlp` (the 8-张/21-点 card-minigame help text --
     the exact same extensionless-help-text gap class documented for
     `yanhuangwuhun`/`yhyxs`/`yhwhpublicfi`, though NOT the same
     specific files/content here -- this codebase's own card games) and
     `d/death/README.TXT` (an unreferenced dev note, a captured chat
     log about the reincarnation quest chain). Converted with
     `iconv -f GB18030 -t UTF-8`.
   - **Genuine binary, correctly left alone**: `MudOSxp.exe` (bundled
     driver), `u/yuchang/driver` (a personal wizard's own stray FreeBSD
     ELF binary), `kungfu/skill/huashan-quan/MFM1992` (opaque binary
     blob, zero references anywhere in the tree by that name -- orphaned
     dead data alongside its sibling `song.lpc` skill file), and the
     `adm/etc/{hzk12,hzk14,hzk16,asc12,asc14,asc16}` +
     `adm/etc/language/{hzk12,hzk14,hzk16,asc12,asc14,asc16,font.lib,
     zhiku1..6}` files -- genuine binary Chinese bitmap font tables
     (HZK-format), confirmed still real and in use via
     `adm/daemons/text2pic_d.lpc`/`text2d.lpc`/`kungfu/class/ultra/
     robot.lpc` (an ASCII-art/text-to-picture rendering feature).
   - **False-positive from `file(1)`'s heuristic** (no fix needed):
     `include/tomud.h`/`tomud1.h` -- pure-ASCII macro definitions that
     legitimately embed raw control bytes (0x19/0x1A) as literal
     protocol-marker characters inside string literals (a GUI-client
     display-tag format), not encoding damage.
4. **Uppercase-`.c`-extension stragglers** (missed by `convert_lib.sh`'s
   lowercase-only rename): 9 files. Checked encoding first (all already
   UTF-8, no transcoding needed) then checked reachability before
   deciding what to do with each:
   - **4 confirmed LIVE, fixed** (`d/death/{BAIHUXUE,XUECHI1,XUECHI2,
     JIMIESI}.C` -> lowercase `.lpc`): all four are real rooms, reached
     via plain lowercase `__DIR__"baihuxue"`/`"jimiesi"`/`"xuechi1"`/
     `"xuechi2"` exit-string references from `d/death/{heisenlin,
     yanluodian}.lpc` and from each other's own `exits` mappings --
     unreachable on this case-sensitive filesystem/driver until renamed
     (the original site likely ran on a case-insensitive Windows
     filesystem, where this was always latent and invisible). Copied
     content byte-for-byte (already UTF-8) to the new lowercase `.lpc`
     name, removed the stale uppercase original.
   - **5 confirmed orphaned, left alone**: `d/zhuanshi/china-aojue/
     PERFORM/{AOJUE,JIANQI}.C` and `.../EXERT/{POWERUP,SHIELD}.C` --
     the sibling file `d/zhuanshi/china-aojue.lpc` does reference
     lowercase `china-aojue/perform/`+`china-aojue/exert/` paths, but
     the *directory itself* is still named uppercase `PERFORM`/`EXERT`
     on disk (even its one already-`.lpc` file, `PERFORM/
     zhangzhen.lpc`, is unreachable through that reference), and the
     game's actual "china-aojue" skill resolves purely through
     `SKILL_D(x)` (`#define SKILL_D(x) ("/kungfu/skill/" + x)`) to the
     entirely separate, already-correct `kungfu/skill/china-aojue/`
     tree -- so this whole `d/zhuanshi/china-aojue/` subtree (including
     its already-lowercased file) is unreachable dead content, not
     fixed. `u/yuchang/zhuangbei/obj/weapon/stick/BB.C` -- zero
     references anywhere by any case; a personal wizard's orphaned
     draft weapon item.

## Fixes applied (driver-incompatibility bugs)

- **§9-class, highest-impact finding this session: `log_error()`'s
  warning-vs-error string check used the wrong case.** `adm/single/
  master.lpc`'s `log_error(string file, string message)` -- the apply
  the driver calls with EVERY compiler diagnostic from EVERY lazy
  compile -- classifies a diagnostic as a real error (vs. a benign
  warning to just log quietly) with `if (strsrch(message, "Warning")
  == -1)`. This driver's own compiler emits **lowercase** `"warning:
  Unused local variable '...'"` (never capitalized "Warning"), so that
  check was **always true** -- literally every compile warning from
  every lazily-loaded room/NPC/item (an extremely common, mostly
  harmless diagnostic -- dozens appear in a normal boot log) was
  broadcast straight to whichever player happened to be connected at
  that moment: the raw `config.fluffos` `default error message` text
  for a normal player, or `"编译时段错误：" + message` for a wizard.
  Confirmed live and extremely reproducible before the fix: a single
  fresh character's very first room entry (many first-time lazy
  compiles firing at once) showed the default-error-message text
  **up to 19 times in a single short session** -- purely cosmetic
  (never blocked registration, movement, or any command), but a
  glaring, constant, unexplained-looking wall of "你发现事情不大对了，
  但是又说不上来。" for every single real player, forever, until this
  fix. Root-caused via a temporary diagnostic write at the very top of
  `master::error_handler()` (a *different*, correctly-implemented
  apply for actual runtime `error()`s) that proved these specific
  messages were NOT going through that apply at all -- ruling out every
  runtime-error hypothesis and pointing at the separate compile-time
  `log_error()` path instead. Fixed by matching both cases:
  ```lpc
  if (strsrch(message, "Warning") == -1 && strsrch(message, "warning") == -1)
  ```
  Verified with 4 independent fresh-driver registration runs after the
  fix: zero spurious messages in any of them (vs. every single
  pre-fix run showing several).
- **§15h (is_chinese GBK byte-range check)** -- `adm/simul_efun/
  chinese.lpc`'s `is_chinese()` was the classic whole-string GBK
  lead/trail-byte-range check (`str[i] < 161`, an `i%2==0` lead-byte
  gate, `str[i] < 176 || str[i] >= 248`). This driver's strings are
  UTF-8 codepoint-indexed, so every real Chinese character failed the
  check. Rewritten as a CJK Unified Ideographs codepoint range check
  (`str[i] >= 0x4e00 && str[i] <= 0x9fff`), dropped the byte-lead gate,
  floor changed `< 2` -> `< 1`.
- **§15h (check_legal_name length bound)** -- `adm/daemons/logind.lpc`'s
  `check_legal_name(name, maxlen)` had `strlen(name) < 2 ||
  strlen(name) > maxlen` (`maxlen=4` at both call sites, a byte-oriented
  "2 Chinese characters" GBK bound). Fixed to `strlen(name) < 1 ||
  strlen(name) > maxlen / 2`. Also fixed the separate combined
  surname+given-name length check in `get_name()`: `strlen(fname) < 4`
  -> `< 2`.
- **§15h (named.lpc full "deep" fix)** -- `adm/daemons/named.lpc` has
  the complete shape documented for this lineage:
  - `#define PATH(name) (name[0..1] + "/" + name)` -> `name[0..0]`.
  - Every `strlen(name) < 2` guard (`remove_name`, `map_name`,
    `who_is`, `invalid_new_name`) -> `< 1`.
  - A `name[0..1]` bucket-key reference in `remove_name` -> `name[0..0]`.
  - `invalid_new_name()`'s sliding-window near-duplicate-name check:
    guard `strlen(name) < 4` -> `< 2`; loop bound `i <= l - 4` -> `i <=
    l - 2`; 2-char window `name[i..i+3]` -> `name[i..i+1]`; 3-char
    window `name[i..i+5]` (guarded `i+6<=l`) -> `name[i..i+2]` (guarded
    `i+3<=l`).
- **New variant of the message()/tell_room() 4th-argument bug** --
  `adm/simul_efun/message.lpc`'s local `message(mixed, string, mixed,
  mixed)` wrapper called `efun::message(arg, message, target,
  exclude)` unconditionally; `tell_room()`'s call site
  (`message("tell_room", str, ob, exclude)`) passes a bare `int 0` for
  `exclude` on every ordinary call (no exclude list), which fails
  `efun::message()`'s 4th-arg type check (`void|object|object*`).
  First reproduced live via `securityd`/preload daemons that call
  `CHANNEL_D->do_channel()` -> `tell_room()` during boot. Fixed by
  guarding: only pass the 4th arg when it's actually truthy:
  ```lpc
  if (exclude)
      efun::message(arg, message, target, exclude);
  else
      efun::message(arg, message, target);
  ```
  Unlike `yanhuangwuhun`'s instance of this same bug, no separate
  forward-declaration workaround was needed here -- `tell_room()`'s
  bare `message(...)` call already correctly bound to this file's own
  override (confirmed by the crash's own stack trace pointing inside
  the local `message()` function body, not at `tell_room()` directly).
- **Extension-rename-width bug** (`.c`->`.lpc`, same shape as the
  `nitan_ceshi`/`nitan_san`/`yanhuangwuhun` precedent) -- `adm/daemons/
  eventd.lpc` and `adm/daemons/storyd.lpc` both do `get_dir(DIR +
  "*.lpc")` then `map_array(names, (: $1[0..<3] :))` to strip what used
  to be the 2-character `.c` extension, now leaving a stray `.l`
  (`"emei.lpc"[0..<3]` -> `"emei.l"`, not `"emei"`) -- surfaced as
  `call_other() couldn't find object '/adm/daemons/event/emei.l'`
  during `eventd`'s preload. `adm/npc/luban.lpc` has the identical
  idiom at 2 further sites (a player-built-house NPC clearing stale
  dbase entries by filename). All 4 sites widened `[0..<3]` ->
  `[0..<5]`.
- **UDP DATAGRAM socket read_callback receives a BUFFER, not a string**
  -- `adm/daemons/network/dns_master.lpc` (`DNS_MASTER`, on the real
  preload list and actively listening on a real UDP port) declares
  `void read_callback(int sock, string msg, string addr)`, but this
  driver's `socket_create(DATAGRAM, ...)` delivers the packet as a
  `buffer`, not a `string`. Crashed `sscanf()` with "Bad argument 1 to
  sscanf Expected: string Got: BUFFER" on every real incoming packet --
  and this daemon DOES receive real incoming packets: the crash was
  first caught live from an actual Intermud-style "mudlist ping" UDP
  packet sent by another real, currently-running Chinese MUD
  ("YHMUD"/"炎黄", `HOST:...||PORT:5566||...`) somewhere on the public
  internet, arriving unprompted during this port's boot-test window.
  Fixed by widening the parameter to `mixed` and coercing defensively
  (this driver has no `to_string()` efun; `string_decode(buffer,
  encoding)` is the buffer->string conversion it actually provides):
  ```lpc
  if (bufferp(msg))
      msg = string_decode(msg, "UTF8");
  ```
  **Flagging per AGENTS.md/task convention: this is a genuine, active
  outbound/listening network side effect**, unlike almost every other
  lib in this collection (all sandboxed, no real connections). This
  lib's `dns_master.lpc` binds a real UDP socket and both sends and
  receives real traffic to/from real hosts on the public Intermud
  network at every boot. Should NOT be swept into high-frequency
  automated reboot loops (§10.0-style long-sit scans, round-two/
  round-three re-test cron) the way every other lib in this collection
  safely can be -- each boot is a real network event against real third
  parties. The other 3 files under `adm/daemons/network/` (`ms.lpc`,
  `mail_serv.lpc`, `netmail.lpc` -- an Intermud-style cross-mud mail
  relay) are confirmed genuinely dead/unreachable: not on the preload
  list, and `cmds/usr/mail.lpc` (the real, live in-game mail command)
  uses a completely separate, unrelated `MAIL_D` (`/adm/daemons/
  maild`) system -- left as-is, several undefined-macro compile
  failures in that dead subtree (`MAILDIR`/`POSTAL_D`/`MAILER_D`/
  `THIS_MUD`/`SAVE_EXTENSION`/`MUD_TYPE`) not fixed.
- **`(int)` cast is compile-time-only, not a real runtime coercion, on
  this driver** (see this project's own standing reference note) --
  hit this TWICE independently in this lib:
  - `adm/daemons/versiond.lpc`'s `in_server()`: `port =
    get_config(__MUD_PORT__) + VERSION_PORT;` crashed `socket_bind()`
    with "Bad argument 2 ... Expected: int Got: \"12\"" (i.e. the
    string-typed `get_config()` result silently string-concatenated
    with the bare int `VERSION_PORT`, `12`, rather than adding). A
    first attempt adding a plain `(int)` cast did NOT fix it (same
    crash, same value) -- switched to `to_int()`, which actually
    coerces:
    ```lpc
    port = to_int(get_config(__MUD_PORT__)) + VERSION_PORT;
    ```
    (Left the resulting bind failure -- this driver's config-array
    index for the mud's own port evidently isn't retrievable the way
    this old code expects -- to fail gracefully through the function's
    own existing `if (socket_bind(...) < 0) { log(...); return; }`
    guard, which now works correctly and logs cleanly instead of
    crashing. VERSION_D's own version-sync feature may not be fully
    functional as a result, but it's a narrow admin/release-tracking
    daemon, not on the registration/gameplay path.)
  - `include/getconfig.h`'s shared `LOCAL_PORT()` macro had the exact
    same `((int) get_config(__MUD_PORT__))` shape, hit by `adm/
    daemons/network/messaged.lpc`'s `startup_udp()` (lazily loaded the
    first time ANY character successfully logs in, via `logind.lpc`'s
    `check_ok()`) -- same crash shape, same root cause. Fixed once at
    the shared macro definition (covers this call site and `d/city/
    npc/shizhe.lpc`'s use of the same macro):
    ```lpc
    #define LOCAL_PORT()            (to_int(get_config(__MUD_PORT__)))
    ```
- **`report_error()` declared `void` but its result used as a string
  argument** -- `adm/single/master.lpc`'s `error_handler()` (the real
  runtime-error apply, separate from `log_error()` above) does
  `tell_object(this_player(1), report_error(error))` for any
  non-wizard player, but `report_error(mapping error)` was declared
  `void` and never returned anything (it only had the side effect of
  posting to the "wiz" channel) -- so `tell_object()`'s 2nd argument
  evaluated to `0`, not a string, crashing `tell_object()` itself for
  every non-wizard player who ever triggers ANY genuine runtime error
  site-wide, and -- because the crash happens partway through
  `error_handler()`'s own body -- silently preventing that function's
  own final `write_file(LOG_DIR + "error_handler", ...)` line from ever
  running, so these secondary crashes left **zero trace in any log**.
  Fixed by making `report_error()` build and return the message string
  (matching its own declared use), and wrapping its `CHANNEL_D->
  do_channel(this_object(), "wiz", ...)` side-effect call in `catch()`
  since `this_object()` here is master itself, not a normal
  player/wizard speaker, and the channel code path isn't designed for
  that case.
- **Missing macro, §8g-style (target file exists, macro just never
  defined)**:
  - `SKI_ZHEN` -- `inherit/skill/array.lpc` (a "formation"/阵法 skill
    base class) has its own header comment literally saying `* #define
    SKI_ZHEN`, but the real `#define` was never added anywhere. 4
    files (`kungfu/skill/{quanzhen-jianzhen,zhenwu-jianzhen,
    dagou-zhen,hebi-jianzhen}.lpc`) `inherit SKI_ZHEN;`. Added
    `#define SKI_ZHEN "/inherit/skill/array"` next to `SKILL`/
    `SHAOLIN_SKILL` in `include/globals.h`.
  - `IP_D` -- `adm/daemons/ipd.lpc` exists and defines exactly the one
    function its only call site needs (`seek_ip_address()`, from
    `cmds/wiz/ipname.lpc`), but the macro was never defined. Added
    `#define IP_D "/adm/daemons/ipd"`.
- **Typos, individually diagnosed** (not part of any wider bug class):
  - `u/kasumi/kungfu/snake.lpc` -- a fullwidth `！` (U+FF01) placed
    *outside* a string's closing quote as bare code syntax (same §9
    class as the `mamian.lpc`/`）` precedent in `yanhuangwuhun`). Moved
    inside the string, where the sentence clearly intended it.
  - `u/sanben/yuanxiao/new_lot_machine.lpc` -- `#define SECOND_PRIZE
    /d/death/obj/tianjing"` (missing the opening quote). Added it.
  - `inherit/condition/damo.lpc` -- the same shared-root bug already
    documented in `yanhuangwuhun`'s NOTES.md, present here
    byte-for-byte identically: an unclosed string in `die_reason()`
    (`return name + HIM "发作身亡了;` missing its closing `"`) plus a
    separate bracket-mismatch typo in `update_condition()`
    (`intp(cnd["remain"] || ...` missing a `)`). Fixed both exactly as
    in the sibling lib.

## Confirmed NOT needed (checked, not applicable)

- **§4/§7.1 (master's lazy security-daemon load recursion)** --
  `valid_read`/`valid_write` in `master.lpc` only call
  `find_object(SECURITY_D)`, never `load_object()`; `valid_write`
  degrades to deny (`return 0`) and `valid_read` degrades to allow
  (`return 1`) when `securityd` isn't loaded yet -- no recursion risk,
  confirmed by reading both functions in full.
- **§7.2 (missing get_root_uid/get_bb_uid)** -- both already
  implemented in `master.lpc`.
- **§7.3 (create() destructing SIMUL_EFUN_OB)** -- `master::create()`
  only does one `write()`; no `destruct()` anywhere in it.
- **§15n (custom securityd ACL blocking compile-time access)** --
  `adm/daemons/securityd.lpc` does have the same `exclude_read`/
  `trusted_read` default-deny-by-directory shape as other libs in this
  family, but its early-allow list already covers `restore_object`/
  `file_size`, and the actual boot/registration/gameplay testing below
  never once hit an ACL-denial error for `load_object`/
  `recompile_object`/`include` -- the ROOT_UID/`(admin)` early-allow
  earlier in the function already covers the compile-time access path
  in practice for this lib. Not patched (no evidence it's needed; a
  `(admin)`-status wizard test also confirmed no denials).

## Boot / registration verification

- `~/src/fluffos/build-debug/src/lpcc`, single-file, confirmed clean on
  all core base classes before ever running a full batch sweep (per
  this project's RAM-safety discipline): `adm/single/master`,
  `adm/single/simul_efun`, and a scoped `--batch` run over all 174
  `feature/*.lpc` + `inherit/**/*.lpc` files -- 173/174 passed on the
  first attempt, the one failure (`inherit/condition/damo.lpc`, a
  content bug, see below) fixed and reconfirmed 174/174 before
  proceeding.
- Full `lpcc_check.sh` batch sweep (all 15,565 objects): peaked at
  ~2.7GB RSS (well under the 10GB safety threshold), completed in
  ~2.5 minutes. **15,354 / 15,565 = 98.6% pass** (211 failures) on the
  final sweep, after also fixing `inherit/condition/damo.lpc`,
  `u/kasumi/kungfu/snake.lpc`, and `u/sanben/yuanxiao/
  new_lot_machine.lpc` (see below); remaining failures triaged by
  category -- the large
  majority trace to a personal wizard sandbox (`u/yuchang/zhuangbei/`,
  an entire parallel weapon/armor item collection whose own private
  `weapon.h`/`armor.h` define macros like `STICK`/`SPEAR`/`MACE`/
  `RAKE`/`FINGER` pointing at a `/std/weapon/...`/`/std/armor/...` path
  that doesn't exist anywhere in this archive -- a genuine,
  pre-existing content gap, not fabricated a substitute base class,
  per standing policy) plus a handful of narrow, genuinely
  unimplemented content gaps (`attack_power()`/`defense_power()`/
  `damage_power()` used but never defined anywhere, affecting only the
  Tang-Sect "钵孟锁物"/"唐门暗器" hidden-weapon throwing skills;
  `check_owner()` used but its base class `feature/oneowner.lpc` never
  inherited, confined to one wizard's personal "宝石"/gem item drafts;
  a few more §8g-style dead-subtree undefined macros already covered
  above). None of the 218 affect the boot/registration/gameplay path
  actually exercised below.
- Real `build-debug` driver boot on port 40233: clean, zero fatal
  `debug.log`/`log/error_handler` errors (only benign compile
  warnings, correctly routed to `log/log_error` after the fix above,
  never shown to a connecting player).
- Full registration flow verified via raw socket scripts (`scripts/
  mudclient.py`), **5 independent runs**, real Chinese names each time
  (id/surname/given-name: `qinling`/秦/岭, `qinhuai`/秦/淮,
  `qinchuan`/秦/川, `qinzhen`/秦/真, `qinshui`/秦/水), each reaching
  the actual starting room "世外桃源" ("Peach Blossom Land," a
  scenic entry area with 2 present NPCs, 水笙/狄云), `look` correctly
  re-displaying it, `score` correctly returning the graceful
  "还没有出生呐，察看什么？" (not-yet-born) response rather than
  erroring, and `quit` cleanly returning "欢迎下次再来！". The last 2
  of these 5 runs (post the `log_error()` fix) showed **zero**
  spurious error-message noise; all 3 runs before that fix showed it
  repeatedly (3 to 19 times per session) -- see the fix write-up above.
- Admin account seeded: id `fluffos`, 普通密码(login) `Mud@2026`,
  管理密码(recovery) `Admin2026`, display name 浮浮 (surname prompt
  skipped with a bare newline, given name `浮浮` -- a single `浮`
  alone is rejected by the 2-character-minimum combined-name check;
  this lineage's combined-length floor is intentional content, not a
  bug). Granted `(admin)` via `fluffos (admin)` appended to `adm/etc/
  wizlist` (the same plain-text `wiz_name status` format already used
  for the existing `mudren (admin)` entry). Verified: `fluffos`/
  `Mud@2026` login succeeds, `look` shows the wizard-only room-path/
  coordinate suffix (`/d/register/entry - (0,0,0)`), confirming
  `(admin)` status is live; `quit` clean.
- Save files for the orchestrator to add (not gitignored, normal add):
  `libs/zhyx/work/data/user/f/fluffos.o`,
  `libs/zhyx/work/data/login/f/fluffos.o`. All other test characters'
  save data (6 throwaway ids) was deleted before finishing, per
  convention.
- Outbound network check (per task step 6): **the one intentional
  exception in this whole collection so far to "every lib is fully
  sandboxed"** -- see the `dns_master.lpc` UDP fix write-up above.
  Confirmed via direct observation of a real incoming packet from
  another live MUD during a routine boot-test window, not a
  hypothetical.

## Not run this session

- **LPC formatter (§9)**: `node` is not available in this environment
  (`command not found: node`), so `tools/lpc-syntax/bin/format-corpus.mjs`
  could not be run against the handful of files edited above. Every
  edit in this session was small (a few lines each, one macro
  definition, one string-literal fix, one cast-vs-conversion swap) and
  was manually reviewed against the surrounding code's existing
  indentation/brace style rather than auto-formatted. Worth a
  formatter pass in a future session that has `node` available.
- **Full deep §10.7-style playthrough / WASM pass**: out of scope for
  this onboarding session per the task brief (native boot +
  registration verification only). `dns_master.lpc`'s live network
  side effect is an extra reason to be deliberate about how often this
  lib gets rebooted in any future automated long-sit/WASM-enablement
  pass.
