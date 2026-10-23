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

## 深度功能测试（round two, AGENTS.md §10.7）— 2026-08-27

First live *playthrough* pass (prior session only verified registration
+ `look`/`score`/`quit`/admin-install, per the sections above). Read
`doc/help/newbie` and `doc/help/yxt_newbie` first — the intended path is
register → walk to one of 4 personality NPCs off 世外桃源 (東/西/南/北)
→ `out` to commit → 阎罗殿 → `wash` (reroll stats) → `born <中文地名>`
→ real starting room; `fight` is the built-in safe-sparring command
("点到为止，因此只会消耗体力，不会真的受伤"); teacher/sect join is
`bai <NPC>`, gated on the NPC's own willingness ("很多师父不轻意收徒");
new-player stat gift is `ask zhyx_boss about 天赋` + `add <stat>`.
Played a continuous session as two fresh characters (`qintestb`,
female, kept as the representative test character; `qintesta`, used to
find/verify the bugs below, then deleted) on the native driver
(`build-debug`), plus targeted admin-`eval` probes for the death/PvP
path that a level-1, mostly-miss-everything character can't reliably
reach live in reasonable real time. Booted/rebooted the driver 6 times
across this pass (`log/error_handler`/`log/log_error` are append-only
across restarts, not truncated — a `wc -l` diff plus checking a
process's own start time via `stat`/`ps` was needed more than once to
tell a genuinely-new crash from a stale leftover entry near the tail).

### Bug 1 (new class, AGENTS.md §7.125): the email-registration gate is permanently dead from the very first character ever created

`adm/daemons/logind.lpc`'s `enter_world()` — which runs on EVERY login,
not just character creation — does an unconditional
`user->set("registered", 1); //user->set("born",1);` a few lines before
its OWN later `if (!user->query("registered")) ...` checks, right after
the unrelated starting-clothing block. This permanently defeats:
`d/register/entry.lpc`'s `valid_leave()` ("you must `register <email>`
before leaving 世外桃源") and `adm/daemons/channeld.lpc`'s "you must
register before using channels" gate. Reproduced live: a brand-new
`qintesta` walked `east` out of the starting room with zero email ever
registered — no rejection, no crash, just silent success. Root-caused
by temporarily deleting the statement and confirming a fresh character
was then correctly blocked ("你还不快注册？") until `register <email>`
+ `decide` were actually run against 水笙, then correctly let through
afterward. **Fix**: deleted the premature `user->set("registered", 1);`
from `enter_world()` (`adm/daemons/logind.lpc:959`) — the real, correct
place this flag gets set, `d/register/npc/shuisheng.lpc`'s
`do_decide()`, was already there and always correct, just permanently
short-circuited. Verified with a second full fresh registration
(`qintestb`) post-fix: blocked from leaving pre-registration, walks
free immediately after `register`+`decide`. See AGENTS.md §7.125 for
the generalized writeup and the sibling libs worth checking
(`yanhuangwuhun`/`yhwhckdm`/`yhyxs`/`yhwhpublicfi`, same lineage,
likely same `enter_world()` shape).

### Bug 2 (extends AGENTS.md §7.12): the onboarding-time message()/tell_room() fix was silently dead code for the wrapper's own internal callers

The onboarding session already added the standard `if (exclude)
efun::message(...) else efun::message(...)` guard inside
`adm/simul_efun/message.lpc`'s local `message()` override, and it was
verified working for its own original repro (`CHANNEL_D->do_channel()`
at boot). This pass hit the *exact same* `*Bad argument 4 to EFUN
message() Expected: object, array, Got: int(0)` crash again, live,
reproducibly, from plain ambient gameplay (`clone/misc/corpse.lpc`'s
`decay()` calling a bare 2-arg `tell_room(env, msg)` on its own 60s/30s
`call_out` timer — no player action needed at all). Root cause,
isolated via three direct `eval` tests: on this driver, an unqualified
call to an identifier that is ALSO a genuine hard efun (`message` is a
real FluffOS efun) resolves to the hard efun, not to a same-named local
function, **specifically when the call is made from within the very
file/object that defines that local function** — `tell_room()` lives in
the SAME FILE as the guarded `message()`, so its own internal
`message("tell_room", str, ob, exclude)` statement was binding straight
to the hard efun the whole time, completely bypassing the "already
fixed" guard sitting a few dozen lines below it. Every EXTERNAL caller
of `message(...)`/`tell_room(...)` elsewhere in the mudlib was and is
correctly routed through the guard (confirmed: an identical bare call
from a plain `eval`, i.e. a different object, worked fine) — this trap
is narrowly about the wrapper file's own internal self-calls.
`message_system()` and `shout()` in the same file had the identical
bare-self-call shape with their own literal/falsy 4th argument
(`all_interactive(), 0` and `this_player()` respectively, the latter
frequently 0 in the NPC-death-event contexts several NPCs actually call
`shout()` from) and got the same fix pre-emptively, even though only
`tell_room()`'s instance was live-reproduced. **Fix**: qualified all
three internal self-calls with `efun::` explicitly (verified this
correctly bypasses the same-object shadowing, alongside a call_other
`find_object(SIMUL_EFUN)->message(...)` which also worked), keeping the
exact same exclude-guard logic:
```lpc
varargs void tell_room(mixed ob, string str, object *exclude)
{
    if (! ob) return;
    if (exclude)
        efun::message("tell_room", str, ob, exclude);
    else
        efun::message("tell_room", str, ob);
}
```
Verified live post-fix on a completely fresh driver boot (to rule out
stale-log false positives from a still-shutting-down prior driver
process, which briefly looked like the fix had failed before the
timing was untangled): `tell_room()`, `message_system()`, and `shout()`
all now execute cleanly via direct `eval`, and zero new
`log/error_handler` entries for this signature appeared across a full
fresh boot + registration + combat + shop + gift session afterward.
See AGENTS.md §7.12's new addendum for the general lesson (verify a
`message()`/`tell_room()` fix by testing the shared wrapper's OWN
internal helpers directly, not just the originally-reported repro path)
— worth a quick `eval tell_room(some_room, "test\n")` sanity check on
any other lib that received this project's standard §7.12 fix.

### Bug 3 (extends AGENTS.md §7.11): live PvP kills silently corrupt killer/victim combat-tracking state forever

`adm/daemons/combatd.lpc::killer_reward()`'s player-vs-player branch
calls `log_file("nosave/killrecord", ...)` — a directory (`/log/nosave/`)
this archive's shipped `work/` tree never contains — immediately BEFORE
`killer->remove_killer(victim);` in the same `if` block. Confirmed via a
controlled admin-triggered kill (`eval` calling `ob->die(ob)` against
the test character, since no level-1-reachable live opponent could
realistically kill a fresh character in test-session time) that this
throws uncaught (`*Wrong permissions for opening file
/log/nosave/killrecord for append. "No such file or directory"`),
aborting the rest of the block — `remove_killer()` never runs, so every
real PvP kill leaves the killer's `killer`/`want_kills` tracking on the
victim and the victim in the killer's `enemy` list forever. This is the
same `log_file()`/`assure_file()` gap already cataloged extensively in
AGENTS.md §7.11 (`adm/simul_efun/file.lpc`'s `log_file()` was a bare
`write_file(LOG_DIR + file, text)` with its own correct, already-defined
`assure_file()` helper sitting unused two functions below it) — same
family of `combatd.lpc::killer_reward()` instance already documented for
`jyqxc2013fwq` (that one broke the death/resurrection transition itself,
worse blast radius; this one corrupts combat state instead, since this
lib's own death-room move happens earlier in `die()`, unaffected).
**Fixed at the shared wrapper** rather than only the one call site:
added `assure_file(LOG_DIR + file);` inside `log_file()` itself (plus
the one-line forward declaration this driver needs since `assure_file()`
is defined textually after `log_file()`), closing the identical latent
gap for every other `log_file()` call into a never-shipped subdirectory
project-wide in one fix — grepping `log_file("<dir>/...` call sites
against `find work/log -type d` turned up at least `job/` (雪山 burning
quest logging), `test/` (神龙教 PK/force-join records), and `voting/`
(`polld.lpc`) as other genuinely-referenced-but-never-shipped
subdirectories that this same fix now protects, not just `nosave/`.
Verified live on a completely fresh boot with NONE of these directories
pre-existing on disk: `log_file("nosave/killrecord", ...)` and
`log_file("job/xueshan", ...)` both auto-created their target
directories on first use and succeeded with zero error. (Note: `log/`
is entirely gitignored project-wide as driver-recreated runtime state —
`libs/*/work/log/` in the top-level `.gitignore` — so this fix
deliberately lives in code, not as a committed placeholder directory;
a bare `mkdir` workaround tried earlier in this session would not have
survived a fresh checkout.)

### Confirmed clean (checked, cross-cutting bug classes from other libs' deep-test passes)

- **§7.121-style currency float corruption**: not applicable. This
  lib's economy (`feature/banker.lpc`'s `do_check`/`do_convert`/
  `do_deposit`/`do_withdraw`, `clone/money/*.lpc`'s `base_value`) is
  pure integer denomination math (`base_value` values are plain
  literals like `1`/`100`/`10000`) — no exchange-rate float anywhere in
  the currency path.
- **§8.3a `private command_hook`**: `feature/command.lpc` (the one
  actually inherited into the player body via the `COMMAND` macro)
  correctly declares `protected nomask int command_hook(string arg)`.
  A second, unrelated `feature/command1.lpc` DOES have the exact buggy
  `private nomask int command_hook(...)` shape, but it's dead code —
  zero files inherit it anywhere in the tree (grepped for
  `COMMAND1`/`command1"` and found nothing) — left alone as an inert
  archive artifact, not a live bug.
- **§7.122-style class-item duplication on reconnect**: no
  `auto_load`/`compute_autoload_array`/TMI-2-style mechanism exists in
  this codebase at all (grepped, zero hits) — not applicable in the
  general sense. Did specifically check the one candidate that looked
  suspicious on paper: `enter_world()` unconditionally clones and
  `move()`s a `/clone/misc/fly` "新手飞行包" into inventory every login
  while `age < 16` (no `present()` guard visible in the source). Tested
  live across a real quit + reconnect cycle expecting to find
  duplicates — found exactly ONE copy both times, no accumulation. Did
  not fully root-cause why (a `no_drop`/`no_get`/`no_put` item like this
  may not round-trip through ordinary `save_object()`/`restore_object()`
  the way ordinary inventory does, so each login's fresh clone may be
  the only copy that ever really persists), but the live test is
  unambiguous: this is NOT a reproducible duplication bug on this lib,
  despite superficially matching the §7.122 shape. Documented here so a
  future pass doesn't waste time re-suspecting it without re-testing.

### What else was tested and confirmed working

- **Registration → personality → born**, twice, full flow, both genders
  (`qintesta` male "光明磊落", `qintestb` female): id/surname/given-name
  → 2 passwords → role-type → gender → 世外桃源 → `register`+`decide`
  → walk to a personality NPC (陆天抒, east) → `out` → 阎罗殿 → `wash`
  → `born 扬州人氏` → landed in 武庙 with starting cloth/shoes/fly bag,
  `look`/`score`/`i` all correct at every step.
- **Combat (safe-sparring)**: `fight <NPC>` against 流氓头 (a weak
  street NPC near 中央广场) ran several dozen non-lethal exchanges,
  correctly self-terminated once 气/精 dropped low (no `halt` needed),
  awarded 潜能 without ever risking real death — matches the newbie
  doc's own description of `fight` exactly.
- **Skill/sect acquisition**: organic route tested via `bai <丐帮一袋
  弟子>` (found via 中央广场's `enter dong` → 树洞内部, matching the
  newbie doc's "丐帮在扬州城里，易于寻找" note) — correctly returned a
  pending "对方还没有答应" state rather than an immediate accept/crash,
  consistent with the doc's own "很多师父不轻意收徒" description; did
  not force acceptance (would require deciding game-balance timing, out
  of scope). New-player gift route: `ask zhyx_boss about 天赋` →
  `add str` correctly granted and applied one of the 6 free stat
  points, `score` reflected it immediately.
- **Shop/economy**: `list`/`buy jitui` at 醉仙楼 correctly rejected an
  impoverished character ("店小二冷笑道：穷光蛋，一边呆着去！") rather
  than crashing or silently succeeding — matches `score`'s own "你目前
  没有存款" for a level-1 character with no money yet; a real successful
  purchase was not reached live (would need actual gold, out of budget
  for this pass) but the rejection path itself is now confirmed clean
  post-Bug-3-fix (the same `log_file()` gap could plausibly have hit a
  shop/economy log path too, though none was actually reached live).
- **Death/respawn**: reached via a controlled admin `eval` (`ob->die(ob)`
  against the non-admin `qintestb`/`qintesta` test characters, never the
  admin's own body) rather than a live kill, since no level-1-reachable
  opponent could realistically kill a fresh character within this
  session's time budget — this is the path that surfaced Bug 3 above.
  Did not additionally verify the full reincarnate/revive-room cycle
  live (out of budget after the Bug 3 investigation); worth a follow-up
  pass with a genuinely lethal opponent or a longer session.
- **`quit` → `log/error_handler`/`log/log_error` grep → reconnect after
  a real ~65s wall-clock gap**: done twice (once pre-fix on `qintesta`,
  once post-all-fixes on `qintestb`). Both times: clean "这样东西不能
  随意丢弃"(fly bag, expected — `no_drop`, harmless) + "欢迎下次再来！"
  on quit, zero new fatal signatures in either log immediately after,
  and a genuine reconnect after the wait landed back with correct
  persisted state (`score`/`i` matching pre-quit exactly).
- **Outbound network / long-sit caveat**: not re-tested this pass
  (out of scope for a §10.7 playthrough) — the onboarding session's
  `dns_master.lpc` UDP finding stands; this lib should still not be
  swept into high-frequency automated reboot loops.

### Minor observation, not fixed (deployment/logging quirk, not a clear LPC bug)

`adm/daemons/cleard.lpc`'s `auto_clear()` (a 30-minute recurring
`call_out`) does `cp("/log/debug.log", "/driver/system.log")`
unconditionally, and `log/debug.log` does not exist in this project's
own way of running the driver (this project redirects the driver's
stdout to an external file via its own `nohup .../driver config.fluffos
> some.log` convention, rather than relying on the mudlib's internal
`debug log file` config value ever actually being written to inside
the mudlib tree) — so this `cp()` throws "lstat failed" every 30
minutes, harmlessly (nothing else in `auto_clear()` depends on its
result). Left as-is: fixing it would mean guessing whether this
project's own driver-invocation convention should change, or whether
the mudlib should stop assuming a `log/debug.log` inside its own tree,
either of which is a judgment call beyond "make the code's own already-
intended logic work," not a clear-cut programming bug.

### Test character / evidence

`qintestb` (female, 光明磊落, 扬州人氏) kept as the representative
playthrough character — registered, born, has the new-player gift's
6 free stat points applied (`add str` used), visited 醉仙楼, survived
a real quit+reconnect cycle. Save files: `work/data/user/q/qintestb.o`,
`work/data/login/q/qintestb.o`. `qintesta` (used to find/verify Bugs
1-3) deleted after use, per convention. Admin account (`fluffos`/
`Mud@2026`) untouched, still seeded from the onboarding session.

### Not run this session (round two)

- **LPC formatter (§9)**: `node` still not available in this
  environment (`command not found: node`). All edits this round
  (`adm/daemons/logind.lpc`, `adm/simul_efun/message.lpc`,
  `adm/simul_efun/file.lpc`) were small, manually reviewed against
  surrounding style. Worth a formatter pass in a future session with
  `node` available.
- **A live (non-admin-triggered) death/reincarnate/revive cycle** and
  **a real gold-funded shop purchase**: both would need either a much
  longer session or a deliberately-outmatched fight; documented above
  as unverified-live rather than silently presented as tested.

## wasm_status 审计（2026-09-01）：内容本身干净，closed.lpc 一处 VERSION_D 守卫补齐，验证为 playable

`meta.json` 的 `wasm_status` 此前一直留空（此前只做过原生驱动验证）。
本次批量审计（见 [[project_wasm_status_audit]]）补上这一步。

好消息：当前生效的 `adm/daemons/logind.lpc` 里对
`VERSION_D->is_version_ok()` 的调用早就被注释掉了（同目录下还留着
一份没有接入配置的 `zhyx_logind.lpc`，那份还是活的调用，但不是
`LOGIN_D` 宏指向的文件，不影响实际登入），`questd.lpc` 里的同类调用
也已经注释——说明这个登入路径本身在 WASM 下不会被同宗
`revive`/`zhonghua2` 家族那个"VERSION_D 编译失败→登入被拒"的闸门
卡住。只有 `adm/daemons/closed.lpc` 的 `heart_beat()`（开机常驻）
还留着一处未加保护的 `VERSION_D->is_version_ok()` 调用，同 AGENTS.md
§1.3(c) 目录里的既有模式，补上 `find_object(VERSION_D) &&` 前缀，
消除每次心跳都要重新编译一遍失败的 `versiond.lpc` 的额外开销。

`system/kernel` 之类没有独立 simul_efun 级 socket 依赖，`dns_master.
lpc`/`ftpd.lpc`/`versiond.lpc`/`messaged.lpc` 等网络精灵编译失败
只是预载列表里的正常"外围精灵跳过"，不影响真实登入。

完整会话验证：英文 ID（3-10 个英文字母）→ 中文姓氏（留空）→ 中文
名字 → 双重密码 → 角色资质(3) → 性别(m) → 落地"世外桃源"，水笙/
狄云在场，水笙主动提示注册邮箱 → `look` 正常重复显示房间描述 →
`score` 得到"还没有出生呐，察看什么？"（与 NOTES.md 此前记载的
"score 显示未出生是正常游戏设计"一致，不是 bug）→ `quit` 干净退出
（"欢迎下次再来！"），全程无未捕获错误。`wasm_status` 设为
`playable`。

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：2026-08-27 那一轮醉仙楼 `buy jitui` 只走到「穷光蛋」拒绝
路径，丐帮一袋弟子 `bai` 也只挂起「对方还没有答应」。本轮补成
功购买 + 真正收徒。

### 实测过程

管理员 `fluffos` / `Mud@2026`（管理密码 `Admin2026`，本轮用普通
密码进）。账号还没 `born`，落地世外桃源，`score` 仍是「还没有出
生呐」——内容规则。巫师 `goto` 不受影响。

`cmds/wiz/clone.lpc` 额外要求 `me->is_admin()`，而
`clone/user/user.lpc` 的 `is_admin()` 只认 uid `mudren`（线上站
点锁，passwd 设 admin_flag 的路径已注释掉）。`clone
/clone/money/gold` 因此回「你没有使用该命令的权限。」未改——这
不是崩溃，是这份档案自己的管理权限模型。改用 `eval
new("/clone/money/gold")->move(me)`（`cmds/adm/eval.lpc` 只查
`wizardp()`）把金锭放进物品栏。

`goto /d/city/zuixianlou`，`list` 烤鸡腿八十文铜板。`buy jitui`
成功（「你从店小二那里买下了一根烤鸡腿」），找零九十九两白银 +
二十文铜钱（10000−80=9920）。本档案 `F_DEALER` 没有 XKX 那种丐
帮穷叫化拒绝，已拜师也能买。

`goto /d/gaibang/inhole`。左全的源码在
`kungfu/class/gaibang/zuo-qu.lpc`，但这份地图没把他放进房间（树
洞放的是黎生 + 随机一袋/二袋弟子）。一袋弟子不 inherit
`F_MASTER`，所以 08-27 那次 `bai` 只会挂起。`apprentice li` 拜黎
生一次成功：`permit_recruit()` 允许无门派，`score` 虽然被未出生
挡住，但收徒文案是「恭喜您成为丐帮的第二十代弟子」，`user.o` 里
`family_name":"丐帮"` / `master_name":"黎生"` / 头衔「丐帮第二十
代传人」。`save` 有 30 秒节流，等过后再存成功。巫师不受 60 秒
`last_on` 重连冷却限制。

本轮没有新的 programming bug。`cleard.lpc` 每 30 分钟
`cp("/log/debug.log")` 仍会在 `log/error_handler` 留下 `lstat
failed`（08-27 已记录，未改）。驱动 `debug.log` 本轮没落到
`libs/zhyx/log/` 也没落到 `work/log/`，运行期错误看
`work/log/error_handler`（本轮游玩期间行数未增加）。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply zhyx`: 5 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 6 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 1 PASS -> 2 PASS, 0 that loaded before fail now, 1 more load.

5 files moved (4 `.C`, 1 `.lpc`); mostly under `d/zhuanshi/china-aojue` (5). A rescan with `scripts/lpc_warnings.py zhyx` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 395 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/tasknpcd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 5 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/tasknpcd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 3 个），无回退；`adm/daemons/tasknpcd.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。
- `cmds/std/swear.lpc`、`cmds/std/team/bunch.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py zhyx --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`d/tiezhang`、`d/wudu` 几个房间删去 `return` 后面的 `"\n";` 等），再用 `scripts/lpc_nitan_family_fixes.py zhyx`（`combatd.lpc` 的空语句 `your_temp["guarding"];`，`genmap`/`traverser` 的空 `DEBUG` 宏），共改动 1634 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：1594 -> 1594 通过，无回退；改过的头文件的 213 个包含者 207 -> 207 通过。
手工：
- `clone/drug/fengdong.lpc`：`if (... < 10000) max1/2;`（没空格，前次全库清扫没认出来）改成 `max1 /= 2;`——经验不足一万的对手，分身技能减半（pkuxkx 同改）。
- `kungfu/skill/sixiang-shengong/perform/jing.lpc`（四象神功「精」）：命中描述 `msg += HIW + "…" HIW + "…被最后一发打了个正中。" NOR;` 后面一行"惨叫一声，血流如注。"被多余的 `;` 截成单独的语句；接回去。
- `adm/daemons/combatd1.lpc` 副本里同样的空语句 `your_temp["guarding"];` 删去。

启动时警告 34 -> 0；新进程登录正常（回应较慢）。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 5 处比较、0 处去后缀（如 `u/dgdg/giftd.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 1 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 1 个文件，HEAD 与工作树各载入一次无回退（1 objects; HEAD PASS 1, tree PASS 1; regress 0; newly loading 0），这些文件的警告 1 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 6）

- 补齐前几批漏掉的同码副本：`your_temp["guarding"];` 补 `= 0`（反击后清除防守姿态，含 `u/` 下的 combatd 拷贝）；`(: WEAPON_D, "query_action" :)` 改为 `(: call_other, WEAPON_D, "query_action" :)`（KB 04）；`mysql_d.lpc` 的空 `MSG` 宏改成空函数；`gigicook.lpc` 的 `arg == menu_list[0]` 改为 `=`。
- 改动文件：u/kasumi/combatd.lpc u/npc/combatd.lpc u/yuchang/combatd.lpc u/yuchang/combatd1.lpc 
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（同码收尾）

- 改动文件：u/mudren/linji-zhuang/youming.lpc u/xiner/skills/sixiang-shengong/perform/jing.lpc 
- 与前几批同型：`youming.lpc` 空 `DEBUG` 宏改空函数；`who1.lpc` 孤立的分隔线字符串删去；`jing.lpc` 被分号截断的“惨叫一声，血流如注。”接回上一句；`_dashi.lpc` 三行只造不调的 `(: call_other, __FILE__, "…_name_skill", who :);` 改成注释（行为不变）。
- 载入无回退。

- 2026-10-12：`adm/npc/obj/jubaoxiang.lpc`、`adm/npc/obj/xiang.lpc`、`adm/npc/obj/xiang1.lpc`、`adm/obj/locker.lpc`、`u/npc/storage.lpc`、`u/sanben/obj/deposit.lpc`、`u/sanben/obj/locker.lpc`、`u/sanben/obj/locker2.lpc` 写着 `int remove() { save(); }`，盖掉了 `feature/move.lpc` 的 `remove(string euid)`——这些存盘箱子/柜子被销毁时不从携带者身上减负重、不清 handing（KB 06 §7.239 变体，nitan_ceshi/tianxiawuxue 同类）。改成 `varargs void remove(string euid) { save(); ::remove(euid); }`。HEAD 与工作树各载入一次，regress 0（载不进的文件在 HEAD 就载不进）。

- 2026-10-12：`clone/misc/swmuding.lpc`（神木王鼎）自己声明了一张 `mapping insects` 虫表，与继承的 `clone/misc/muding.lpc` 的 `insects` 同名；读表的是木鼎的代码，读到的是木鼎自己的表，神木王鼎的虫表从来没用上（`Redeclaration of global variable 'insects'`）。改名 `sw_insects`，`create()` 里 `insects = sw_insects;` 交给木鼎（nitan170911、wxddym、zjdy 系同修）。HEAD 与工作树各载入一次，regress 0。

## 编译警告收尾（2026-10-13）

搬来同族已整理的改法（`scripts/lpc_twin_port.py adopt`：yanhuangwuhun 89552da089f、zhonghua2 7d27a20c08d、yhwhpublicfi 2ac7a6f02ed），`scripts/toolkit_fix.sh` 去掉 3 处多余继承，其余手工，能编译的文件警告清零。改动的 21 个对象在 HEAD 与工作树各载入一次：HEAD PASS 21，tree PASS 21，regress 0。

- `adm/daemons/huanjing2003/` 四国 NPC/宝物与 `room_readygo_hj.lpc`：同一条声明里先裸声明再带初值声明的变量去掉裸的那份（`scripts/lpc_fix_double_decl.py`）。
- `feature/food.lpc`、`feature/liquid.lpc` 的 `do_effect()` 改 `varargs int`，与重载它、被 `eat`/`drink` 用返回值的物品同型；`cmwhod` 的 `nosave` 函数改 `protected`。
- `clone/megazine/obj/duka_3b.lpc` 赔率变量声明两次，删去不用的前一行（赔率不变）；`d/beijing/npc/qianzhenglun.lpc`、`u/mudren/mj.lpc` 自己的 `count` 遮住基类同名变量，改名；`clone/obj/genmap.lpc` 函数里没用的 `#include "harbor.h"` 删去；`clone/book/yjj_book2.lpc` 写明用 `skill::clean_up()`。
- 天书任务 `quest/shenshu/npc/man.lpc`、`testman.lpc` 的 `kill_ob()` 改 `void`（同 wxddym），末尾 `return 1;` 改 `return;`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。13 个文件 29 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件里多行写的 `int hard_point() { return 2.5; }` 之类浮点经 int 返回被截断；本库没有调用者，改成 `float`，保留原数值。

- 2026-10-14：1 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：1 个对象，新增载入 1，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/duanyun-fu`、`/kungfu/skill/feifeng-whip`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。17 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 2 个文件。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`dacidabei-shou`。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`huashan-sword/feilong`、`xue-dao/xuemo`、`yunu-sword/yijian`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`xiawuxiang`→`xiaowuxiang`（`jidao-shaqi`、`jingshen-jue`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`feilong--cuff`→`feilong-cuff`（`feilong-cuff/dan`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/nuoyi`）；`xuxiang-zhi`→`wuxiang-zhi`（`wuxiang-zhi/wuse`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`jiujin-shengong`→`jiuyin-shengong`（`jiuyin-shengong/perform/zhang`）；`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 擒龙手「擒龙打」每次都报错（2026-10-15，KB 06 §7.246）

`qinlong-shou/qin` 要求空手施展，却在出招前执行 `wn = weapon->name();`：局部变量 `weapon` 从没赋值，`wn` 也没人用，每次使用都报 `Bad argument 1 to EFUN call_other()`。删去这一行和两个没用的局部变量。


## 地图数据库 mapdb 读到只有文件头的 map.o（2026-10-15，KB 06 §7.250）

本库的 `data/npc/map.o` 只有一行文件头：genmap 第一次载入时 `if (!restore()) save();`，地图还没建就存了档，值为 0 的变量不写进去。mapdb 的 `restore()` 读它成功，`map` 却成了 0，`query_room_info()`、`query_room_exits()`、`query_map()` 都对 0 取下标或把 0 交出去：遍历器 traverser 的用户都会报错。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。地图本身仍需巫师用 genmap 生成。


## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的工作间 `/u/vin/workroom`，库里没有；改为 `/d/city/guangchang`。


## 秋林拾叶「随风而舞」成功时报错（2026-10-15，KB 06 §7.252）

`qiulin-shiye/wu` 把房间的出口映射当数组：`mapping *obb = query("exits", env)`，成功时 `me->move(obb[0])`，映射里没有键 0，移动到 0 报错（没有出口的房间则是对 0 取下标）。改为 yanhuangwuhun 一系的写法：从 `values(exits)` 里随机选一个出口。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`shenlong-jian/anxi`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`d/biwu/npc/gongping.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参，`clone/drug/cb_renshen`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃。1 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同。

## 火焰刀「修罗降世」每次报错（2026-10-15，KB 06 §7.246）

本库的 `huoyan-dao/xiuluo` 被换成了取经棍法「震雷乾坤」的文字（同系其他库是真正的火焰刀绝招）：先拒绝持兵器，却用从未赋值的 `weapon->name()` 拼招式，三段伤害又按 `WEAPON_ATTACK` 交给 combatd，每次使用都报错。文字里的兵器名改为“火焰刀”，伤害类型改为 `UNARMED_ATTACK`（火焰刀是掌法），其余原样。


## 回龙杖「神龙摆尾」从来用不出（2026-10-15，KB 06 §7.246）

`if (!objectp(me->query_temp("weapon") || weapon->query("skill_type") != "staff"))`：括号放错，`objectp()` 包住了整个 `||`，拿着兵器时 `objectp(1)` 为假，永远“双手应该持杖”；空手时又去读从未赋值的 `weapon`，报错。改为先存兵器再判断。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

8 个文件、34 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/tangmen/obj/qinglianzi`、`/d/tangmen/obj/feidao`、`/d/tangmen/obj/fhshi`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 5 个（5 个原来载入不了），没有退步；其余 3 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`quest/quest_jun/look.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`NPC_TRAINEE` → `/inherit/char/trainee`（1 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：1 个里 1 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 4 个对象设了本库没有文件的武功（3 个名字，最多的是 `longxiang-banruo`、`kick`、`move`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：4 个里 4 个通过。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/death/qiao2` 的 `north`：`hell1` → `youmingjie`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件：`/d/xueshan/inherit/liquid_container`←nitan_ceshi，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 23 处、14 个文件：`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`tiaji-jian`→`taiji-jian`（4 处）、`changquana`→`changquan`（4 处）、`shenzhao-jing`→`shenzhaojing`（3 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`shenhuo-shengong`→`shenghuo-shengong`（2 处）、`yan-fly`→`yanfly`（1 处）、`zhoangnan-zhi`→`zhongnan-zhi`（1 处）等共 10 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 1 个文件：`/d/baituo/npc/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/baituo/obj/lingshezhang.lpc`：`set("wposition", "/d/baituo/obj/lingshezhang.lpc")` 被 `//***** ADDED BY SCATTER *****` 注释吞掉

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：1 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回丢失的基类宏（2026-10-19，KB 04 §6.13、§6.16）

`include/globals.h` 补回 `STICK`、`SPEAR`、`MACE` 指向 `/inherit/weapon/` 下同名文件：`clone/newitem/newweapon/` 或 `d/city/obj/` 里 `inherit` 这些宏的物件找不到宏，载入失败（一个只在巫师目录的头文件里定义的宏，对正式文件不算已定义，`scripts/lpc_restore_macros.py` 以前把它当成了已定义）。补完后这些物件载入，没有警告。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西（`eat` 后面不管写什么）都会吃掉紫草。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/adm/daemons/gift/danshen.lpc`（1 处）、`/adm/daemons/gift/huangqi.lpc`（1 处）、`/adm/daemons/gift/pantao-gao.lpc`（1 处）、`/adm/daemons/gift/pantao.lpc`（1 处）、`/adm/daemons/gift/zicao.lpc`（1 处）、`/clone/medicine/zicao.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`cross pubu`（穿瀑布）永远回答“你要往哪儿穿？”，瀑布后面的密室进不去；`valid_learn()` 对任何性格都拒绝。改动：`/d/tiezhang/hhyuan-3.lpc`（1 处）、`/kungfu/skill/qiankundanuoyi.lpc`（1 处）。

## `string` 变量里存的是数字（2026-10-20，KB 04 §6.22）

`kungfu/skill/fengshen-tui1.lpc` 的 `sk1`（`ob->query_skill("paiyun-zhang", 1)` 的结果）声明成 `string`，`sk1 > 100` 过不了编译，改成 `mixed`（`scripts/lpc_fix_cast_cmp.py`）。这个文件本身仍然不能加载：`hit_ob()` 的 `return` 后面多出一个孤立的 `{`，括号对不上，是源文件损坏，不是机械可修的类别。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/arch/sameip.lpc`（1 处）、`/d/zhuanshi/ajszhuang/vrm_server.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 2 处）。改动：`/adm/daemons/competed.lpc`（1 处）、`/cmds/adm/watch.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/adm/daemons/versiond.lpc`（1 处）、`/include/getconfig.h`（1 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/adm/daemons/npc.lpc`、`/inherit/char/npc.lpc`、`/inherit/char/npc1.lpc`、`/inherit/char/npc2.lpc`（共 4 个文件）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/arch/blockade.lpc`、`/cmds/arch/recovermud.lpc`。

## 任务守护进程的 `clear_room()` 加载档案里没有的房间（2026-10-21，KB 06 §7.299）

管理员扫描里 `task1`（玩家指令；同系的库里还有别的入口）在 `/adm/daemons/taskd.lpc` 的 `clear_room()` 里报 `Bad argument 1 to EFUN call_other() Got: int(0)`：守护进程写死的 19 个房间里有 19 个本库没有，`room = load_object(localroom);` 答 0，下一句 `room->reset();` 就是对 0 的调用。`load_object()` 之后加 `if (!room) continue;`，有的房间照常重置。

## `board` 把 `/clone/board/` 里的数据文件当成留言板（2026-10-21，KB 06 §7.299）

管理员扫描里 `board`（`cmds/arch/board.lpc`）报 `call_other() couldn't find object '/clone/board/Answer.txt'`：指令把 `get_dir("/clone/board/")` 的每个名字都当成留言板对象去 `->short()`，目录里有一个 `Answer.txt`，不是对象。改成 `get_dir("/clone/board/*.lpc")`。

## `dual` 不带参数：`evaluate_shell()` 对 0 取下标（2026-10-21，KB 06 §7.336）

`dual`（`cmds/arch/dual.lpc`）把参数原样交给 `me->evaluate_shell(arg, flag)`，那里第一件事是 `arg[<1] == ';'`，参数为 0 时报 `Value being indexed is zero.`（`feature/shell.lpc`）；静态扫描只认直接传给 efun 的参数，看不见这种经过 `call_other` 的。命令开头加 `if (!arg) return notify_fail("指令格式 : dual [detail]\n");`（同系 16 个 `dual` 里另外 7 个本来就有这个检查）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 39 条注册（25 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/npc/referee.lpc`（`do_halt`）、`/clone/drug/guiyuan.lpc`（`do_pour`）、`/clone/drug/huiyang-san.lpc`（`do_pour`）、`/clone/drug/shedan.lpc`（`do_pour`）、`/clone/drug/yangxin.lpc`（`do_pour`）、`/clone/drug/yulu-wan.lpc`（`do_pour`）、`/clone/heidian/beijing_huoji.lpc`（`do_value`）、`/clone/heidian/chengdu_huoji.lpc`（`do_value`）、`/clone/heidian/dali_huoji.lpc`（`do_value`）、`/clone/heidian/foshan_huoji.lpc`（`do_value`） 等共 25 个文件。最多的函数名：`do_pour` 6 处、`do_value` 5 处、`do_halt` 2 处、`do_skills` 2 处、`do_drop` 1 处。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`outdoor_room_event()`（7 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 2 个函数没有补（item_desc 1, inquiry 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/city/shan.lpc`:`look_duilian`、`/d/city2/npc/zhuangyu.lpc`:`ask_weiwang`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 123 个文件里有 224 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/tianzi`、`nosave/using`、`nosave/killrecord` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 1 个子目录写日志：`log/money`（`d/suzhou/npc/meipo.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/money` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"lian" : (: look_duilian :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 19 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；NPC 的称呼和提示里取到两个字而不是一个字。

本库 19 处（14 个文件）：拼名字的赋值 10 处、与汉字常量比较 6 处、`to_chinese()[..]` 3 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/fengling.lpc:134`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/emei/tobebonze.h:40`）；`chk[0..1] == "你"` → `chk[0..0] == "你"`（`/adm/npc/ganjiang.lpc:593`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：12 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 12 处（6 个文件）：`if ((strlen(name) < 4) || (strlen(name) > 12 )) {`（`/adm/npc/luban.lpc:1691`）；`if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {`（`/clone/pet/petowner.lpc:161`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 8 个文件；`channeld` 同盟 / 门派标题 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 7 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 中文名 / 验证码仍按 GBK 取「两字节一字」（2026-10-23，KB 06 §7.373）

`pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1]; pname = pname[0..1];` 在按字符计下标时会取出两个汉字。`scripts/lpc_fix_pname_slice.py` 去掉掩码并把收尾改成 `[0..0]`（`pname`/`pname2`/`sec_name`/`str`/`str1`）。本库 6 处。证明：nt1 生成名长度 2–4；HEAD 常见 3–5。

