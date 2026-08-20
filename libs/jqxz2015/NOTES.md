# jqxz2015 — 金庸群侠传 (Jin Yong Heroes Gathering, 2015 edition)

Archive: `archives/金庸群侠传2015版.rar` ("Jin Yong Heroes Gathering, 2015
edition"). Extracted mudlib root: `raw/jy/` (a single top-level `jy/`
directory inside the archive, identical layout convention to archive #91).
Port: **40086**. Status: **done** (boots clean, full registration flow
verified twice with real Chinese names, post-login `look`/`score`/`quit`
verified working both times).

## Lineage confirmation (evidence, not assumption)

`config.cfg`'s `name` field (GBK-decoded) is literally `金庸群侠传`, and
`Readme.txt` carries the same "ES2 lib (Tian Cao Di Guo)... Wrote By
Phoebus.suny 1998" credit already seen on archive #91
(`jqxz2008`). Same `jy/` top-level directory name, same
`adm/obj/`+`adm/single/` dual master-file layout.

**Confirmed via `md5sum`, not assumed, against #91's raw archive** — this
is an even closer match than #91 vs xiakexing3(#44) was:

| file | match vs #91 raw |
|---|---|
| `adm/obj/master.c` | byte-identical |
| `adm/single/master.c` | byte-identical |
| `adm/daemons/securityd.c` | byte-identical |
| `adm/daemons/chinesed.c` | byte-identical |
| `adm/obj/simul_efun.c` | byte-identical |
| `adm/simul_efun/chinese.c` | byte-identical |
| `include/globals.h` | byte-identical |
| `feature/command.c` | byte-identical (incl. the `private` bug) |
| `home/command.c` | byte-identical |
| `feature/name.c` | byte-identical (incl. capitalize()-on-0 bug) |
| `adm/daemons/commandd.c` | byte-identical |
| `d/city/npc/guidao.c` | byte-identical (incl. is_killing() typo) |
| `d/baituo/ouyangfeng.c` | byte-identical (incl. both typos) |
| `d/shaolin/obj/shuitan.c` | byte-identical (incl. ging_cost typo) |
| `adm/daemons/logind.c` | differs by **exactly one blank line** (whitespace only, confirmed via diff of decoded content) |

So this 2015 release is the SAME underlying "ES II / 金庸群侠传" engine
core as #91's 2008 "加强版" (enhanced edition), 7 years later, with the
engine/daemon layer essentially frozen and only game **content** evolved:
3,893 raw files here vs 3,773 in #91 (net +187 new / -67 removed, mostly
new zones — `city2`, `honghua`, `huanggon`, `gaibang` obj expansions,
etc. — plus some cleanup of old scratch/orphan files). A few individual
content files (mostly under `d/mingjiao/`) were independently edited
between the two releases (see below) — direction is NOT "2015 always
newer/better", it's a genuine content fork with drift in both directions
(e.g. `d/mingjiao/jmqshenmu.c`, truncated in #91, is COMPLETE here; but
`d/city2/npc/zhengmen.c` is genuinely truncated here, matching, in shape,
#91's `jmqshenmu.c` finding).

**Cross-check note for #92/#93 (concurrent, not yet landed)**: per the
task brief these could not be diffed against since they were being
processed concurrently in sibling sessions — a later pass should
`md5sum`-cross-check this lib's core files against whatever #92
(`金庸群侠传2008版.rar`) and #93 (`金庸群侠传2008超豪华版.rar`) turn out
to be, the same way this pass cross-checked against #91.

## Fixes applied (ported directly from #91 where the source was
byte-identical; confirmed present via direct read before applying, not
assumed)

1. **AGENTS.md §15h** (`is_chinese`/`check_legal_name` GBK byte-range
   checks): `adm/simul_efun/chinese.lpc`'s `is_chinese()` — GBK lead-byte
   range (`str[0] > 160 && str[0] < 255`, `strlen>=2`) → CJK codepoint
   range (`str[0] >= 0x4e00 && str[0] <= 0x9fff`, `strlen>=1`).
   `adm/daemons/logind.lpc`'s `check_legal_name()` — byte bound `<2||>12`
   → character bound `<1||>6` (message already promised "1 到 6 个中文
   字"); dropped the `i%2==0` even-byte-offset gate. Byte-identical
   source to #91's pre-fix files, so the fix is verbatim.
2. **AGENTS.md §15ae** (`private nomask` command-hook breaks every
   post-login command): `feature/command.lpc`'s `command_hook(string
   arg)` was `private nomask`; `home/command.lpc`'s copy was already
   correct (no `private`) — exact same split as #91. Dropped `private`.
   **Verified working** (see registration transcripts below — `look`/
   `score` both function correctly post-login in both test runs).
3. **AGENTS.md §15ar — checked, confirmed NOT independently needed**:
   `adm/daemons/commandd.lpc`'s `rehash()` uses `sscanf(cmds[i], "%s.c",
   cmds[i])` (no `$` anchor) to strip the `.c` extension. Because this is
   a *plain quoted* `"%s.c"` literal (not the concatenated `cmds[i]+"$"`,
   `"%s.c$"` shape from the archives where §15ar was first cataloged),
   `convert_lib.sh`'s standard `\.c"`-reference fixer (§2) already caught
   and rewrote it to `"%s.lpc"` automatically during the mechanical
   conversion pass — confirmed by grepping the post-`convert_lib.sh`
   `work/` copy before making any manual edit. **This clarifies why #91's
   own NOTES.md never called out a separate §15ar fix**: same shape, same
   automatic resolution, on the identical source file.
4. **`feature/name.lpc`'s `capitalize()`-on-`0` robustness bug** (same
   as #91 finding #5): `short(int raw)`'s fallback assumed `query("id")`
   is always a string; guarded with `stringp(id)` so non-character items
   (bulletin boards) don't crash `look` in their room. Byte-identical
   source to #91.
5. **`d/city/npc/guidao.lpc`'s `is_killing(who)` direct-call type
   mismatch** (same as #91 finding #6): fixed to
   `is_killing(who->query("id"))`. Byte-identical source to #91.
6. **`d/baituo/ouyangfeng.lpc`, two typos** (same as #91 finding #13):
   missing semicolon after a `write(...)` in a `switch case 0:` block;
   `object me=this-player();` → `this_player()`. Byte-identical source
   to #91.
7. **`d/shaolin/obj/shuitan.lpc`: `ging_cost` typo for `jing_cost`**
   (same as #91 finding #14). Byte-identical source to #91.
8. **AGENTS.md §15ac (bare `SAVE_EXTENSION`)**: 6 files this pass —
   `include/net/ftpdsupp.h`, `d/quanzhou/npc/{tang,tang3}.lpc`,
   `d/taishan/tang3.lpc`, `cmds/arch/purge.lpc`,
   `adm/daemons/network/netmail.lpc` — replaced with
   `__SAVE_EXTENSION__`. **Left alone**: `clone/npc/meng-zhu.lpc` (`#define
   SAVE_EXTENSION ".o"` locally, self-contained — verified, same as #91).
9. **The "tang"-family `new`-as-bare-variable-name typo** (same 7 files
   as #91, same lines: `d/quanzhou/npc/{tang,tang1,tang2,tang3}.lpc`,
   `d/taishan/{tang2,tang3,xingtang}.lpc`): `object *inv, new;` +
   `new = new("/clone/npc/...")` + `new->move(...)`. Renamed the local
   variable to `newob` throughout (declaration + both usages) in all 7
   files; the `new(...)` efun calls themselves untouched.
10. **`kungfu/class/mingjiao/mingjiao.h`'s string-literal-adjacent-to-
    macro-expansion syntax error** (same shape as #91 finding #10, but
    the surrounding logic differs — this 2015 copy independently added an
    `else` branch with reversed rank-comparison logic and its own second,
    correctly-`+`-joined string, plus already carries `#include <ansi.h>`
    unlike #91's original): `ob->query("party")["party_name"] == HIG
    "明教" NOR` → `HIG + "明教" + NOR` (explicit `+`).
11. **`adm/daemons/combatd.lpc`'s `#include </quest/quest.h>`** —
    AGENTS.md §15t variant 1 (absolute path inside angle brackets, never
    resolved by this driver's `inc_open()`) — **this file's content
    diverges substantially from #91's** (2015's combatd.lpc has different
    damage-formula code entirely, but kept the same broken quest.h
    include and the same variant-3 ordering bug independently). Fixed to
    `#include "/quest/quest.h"` (quoted absolute form) AND moved
    `inherit F_DBASE;` above all `#include` lines (AGENTS.md §15t variant
    3 — quest.h's file-scope `mapping quest_name = ([...])` global would
    otherwise land textually before the inherit, a fatal "Illegal to
    inherit after defining global variables" here). Confirmed via a live
    `score` test that `score` now works correctly (this is the same code
    path #91 needed this exact pair of fixes for, but arrived at via a
    fresh discovery here since combatd.lpc's content differs — the
    `quest.h` include itself, previously assumed only relevant to #91,
    turned out to be genuinely present and broken here too).
12. **`quest/quest.h`'s own string-literal-adjacent-to-macro syntax
    errors** (NEW finding this pass, not present in #91's combatd.lpc
    since #91's copy never actually included `quest.h` at all — its
    version of combatd.lpc had no quest.h reference to trip over this):
    once fix #11 above made `quest.h` actually get included and parsed,
    two more of the exact same "adjacent string literal + macro, no `+`"
    bug (AGENTS.md §9/§10 family) surfaced inside it —
    `"你可以领取"HIG + values(quest_name)[i] + NOR"任务了！\n"NOR` and
    `"你得先完成"HIY + quest_name[lock_quest] + NOR"任务才能继续这个任务。\n"`
    — both rewritten with explicit `+` throughout. `quest.h` is only
    ever `#include`d by `combatd.lpc`, which already has `#include
    <ansi.h>` earlier in the same file, so `HIG`/`HIY`/`NOR` resolve
    fine once the syntax itself compiles.
13. **`d/baituo/{obj,npc/obj}/bowl.lpc`'s `set_name()` wrong argument
    type** (NEW finding, genuinely pre-existing, not present in #91 —
    #91's archive doesn't ship this file at all): `set_name("海口大碗",
    "bowl")` passed a bare string where `set_name(string name, string
    *id)` (per `feature/name.lpc`) requires an array — every other
    `set_name()` call site in the whole lib correctly uses `({ "id" })`.
    Fixed both copies (`d/baituo/obj/bowl.lpc` and
    `d/baituo/npc/obj/bowl.lpc`, identical content) to
    `set_name("海口大碗", ({ "bowl" }));`.
14. **`d/city2/npc/zhengmen.lpc` genuinely truncated in the raw archive
    itself** (NEW finding, same class as #91's `jmqshenmu.c` — confirmed
    by diffing `work/` against the pre-conversion raw `.c`, both exactly
    77 lines, ending mid-`valid_leave()` with 2 unclosed braces, not
    something our pipeline introduced): closed the truncated function
    with the 2 missing closing braces (no fabricated logic added), purely
    so the file is syntactically valid — the room's real, complete
    `create()`/`look_gaoshi()` content above is untouched.

## Confirmed NOT needed (checked by reading the actual source, not
assumed from #91's precedent alone — `master.lpc`/`securityd.lpc` are
byte-identical to #91's so these transfer directly, but each was
re-verified against this archive's actual `work/` content)

- **§4** (master's lazy security-daemon load recursing): `master.lpc`'s
  `connect()`/`compile_object()`/`log_error()` never do a lazy
  `load_object(SECURITY_D)` — confirmed by direct read of the whole file
  (byte-identical to #91, which already confirmed this clean).
- **§7** (`get_root_uid()`/`get_bb_uid()`): both present in `master.lpc`
  (lines 177/182, matching #91 exactly).
- **§8c** (`valid_read`/`valid_write` overriding with `this_player()`):
  `securityd.lpc` has only `valid_write`, no `valid_read` at all, no
  `this_player()` override logic — confirmed present (byte-identical to
  #91).
- **§15n/§15o** (custom securityd ACL blocking driver compiles / missing
  `get_include_path()`): `securityd.lpc` implements `valid_write` only;
  `master.lpc`'s file has no custom `valid_read` ACL to gate compiles.
- **§15p** (DNS/intermud daemon in preload): `adm/etc/preload` (11
  entries, read directly) never lists any network/dns daemon — nothing
  to exclude, same as #91.
- **§15l** (`master.lpc` destructing `SIMUL_EFUN_OB` in `create()`):
  `master.lpc`'s `create()` body (read directly) has no `destruct()`
  call at all.
- **§15ag** (`ed_start`/`ed_cmd`/`query_ed_mode`): zero occurrences
  anywhere in `work/` (grepped).
- **§15v** (`LONELY_IMPROVED`-style always-on efun-substitution flag):
  zero occurrences (grepped) — this is an ES II lineage lib, not the
  unrelated "nitan" lineage this pattern is specific to.
- **§8f** (bare `array` / `TYPE * a, b;` comma-list array-modifier bug):
  zero bare `array name;` declarations found (grepped); this is a
  Chinese ES II lineage lib, not the English Dead-Souls lineage this bug
  is specific to.
- **§15z** (`#define nosave static`/`#define protected static` shim):
  none found in any `.h` file (grepped).
- **Duplicate `inherit F_UNIQUE;`** (present in #91's
  `d/mingjiao/npc/{yinwushou,yinwulu,yinwufu}.lpc`): **already fixed in
  this 2015 archive independently** — confirmed via diff, only ONE
  `inherit F_UNIQUE;` line in each of the 3 files here (2008's had two).
  Not a bug here, no action needed.
- **`kungfu/class/mingjiao/tanzhu.h` wrong-path `#include`** (#91 finding
  #11/#12): zero references to `tanzhu.h` anywhere in this archive
  (grepped) — the NPC files that used it in #91
  (`fenggongying`/`baiguishou`/`changjinpeng`) were independently
  rewritten in this 2015 release to either use `mingjiao.h` instead
  (`changjinpeng.lpc`) or have their own inline `init()` with no header
  include at all (`fenggongying`/`baiguishou`) — confirmed via direct
  diff against #91.
- **Fixed-width `[0..<3]` filename-extension-width slice bug** (§2's
  variant): present (18 `kungfu/skill/*/*.lpc` files, same `pfname =
  explode(__FILE__,"/")[<1][0..<3]` pattern as #91) but confirmed dead
  code — `pfname` is assigned once and never read again anywhere in any
  of the 18 files (grepped each), same as #91's finding. Not fixed.
- **`d/huashan/map.lpc`** — a plain ASCII-art room-layout text file
  mistakenly caught by the blanket `.c`→`.lpc` rename (AGENTS.md §12),
  confirmed via `grep -rl` returning zero references anywhere else in
  the tree. Same precedent as #91/other libs' orphaned-map findings —
  left as a permanently-"failing" but harmless dead file, not renamed
  (matches established convention of not touching confirmed-dead
  content unless it actively breaks something live).
- **`doc/build/devil.lpc`** (missing semicolon after `inherit NPC`) and
  **`doc/efuns/shiwu.lpc`** (bare `do_close` identifier instead of a
  quoted string in `call_out`) — both are illustrative example/template
  files under the `doc/` documentation tree, confirmed unreferenced
  anywhere in the real object tree (grepped). Left as-is, same
  "documentation, not live code" category as other libs' `doc/`-tree
  lpcc-sweep noise.
- **`cmds/usr/to.lpc` / `cmds/wiz/to.lpc`** ("Illegal to use local
  variable in functional" — `me`/`arg` referenced inside an old-style
  `(: ... :)` functional closure): byte-identical to #91's copies, which
  hit the exact same failure and was **not** individually fixed there
  either (present in #91's own `lpcc_fail.log`, part of its
  undifferentiated remaining-failures tail) — left unfixed here too for
  consistency; a rarely-used admin multi-line-input utility, not on the
  registration/gameplay-critical path.

## Content gaps confirmed as real archive gaps, not bugs (AGENTS.md §13)
— same categories as #91, independently re-verified for this archive
(not assumed transferred)

- `d/mingjiao/yuan/*` (9 "yuan" NPCs, e.g. 郑七灭/郑十灭 family) reference
  two genuinely-missing kungfu skill files (`xuanyuan-arrow`,
  `liangyi-jian`) — confirmed absent anywhere under `kungfu/skill/`
  (same gap as #91).
- `d/wudang/taoyuan/{tyroad4,5,6,7}.lpc` are orphaned early drafts of
  the complete, working `d/wudang/tyroad{4,5,6,7}.lpc` files one
  directory up — confirmed nothing in the tree references the
  `taoyuan/` copies (grepped), same finding as #91.
- `d/npc/m_weapon/weapon/{m_club,m_blade,m_whip,m_sword,m_staff,
  m_cloth}.lpc`: `create()` calls `this_player()` unconditionally,
  always null in an isolated `lpcc` compile — the standard §6b
  "compiled divorced from runtime context" false positive, same shape
  as #91 (one extra file, `m_cloth`, vs #91's 5 — this 2015 release
  added a 6th weapon-template variant).
- `adm/daemons/network/*` (10 files: dns_master-family services,
  mudlist, mail_serv, netmail, telnetd, inetd, pingd, ...): confirmed
  not in `adm/etc/preload` and not referenced from outside this
  subdirectory (grepped) — dead/inert intermud subsystem, never
  compiled during a real boot or registration/gameplay path.
- `home/simul_efun.lpc`: a stray sandbox copy of the real simul_efun,
  same §6b `main_file_name()` sweep artifact as #91 — never loaded as
  the actual simul_efun (configured path is `/adm/obj/simul_efun`).
- `clone/board/*` corrupted save data (11 board `.o` files under
  `data/board/` fail `restore_object()` with "Illegal file format") —
  same pre-existing corrupted-seed-data class as #91's board/chinesed
  findings; each board's `setup()` wraps the failure in `catch()`
  (visible in `debug.log` as "错误讯息被拦截"), fully non-fatal —
  **directly confirmed live** during both registration tests AND a
  subsequent WASM long-sit boot-watch (2026-07-24): `/clone/board/
  kedian_b`, the starting-room board, IS one of the 11 corrupted
  files — its own `restore()` throws "Illegal file format" every time
  a fresh character's `enter_world()` creates it, caught harmlessly by
  `logind.lpc`'s `CATCH()`, and it then displays correctly under
  `look` as an empty board (no persisted notes). (An earlier pass of
  this note wrongly suggested `kedian_b` restores cleanly and a
  separate board was the one throwing — direct inspection of
  `data/board/kedian_b.o`'s raw bytes confirms it's random binary
  garbage like the other 10.)
- `adm/daemons/chinesed.lpc`'s `data/e2c_dict.o` (English→Chinese
  translation dictionary save file) fails to `restore()` — same
  pre-existing corrupted-seed-data issue as #91, caught by `master.lpc`'s
  `preload()` catch wrapper, fully non-fatal (translation lookups just
  return input unchanged).
- `u/liujun/quest/{leftkiller,rightkiller}.lpc` reference a missing
  skill (`six-chaos-sword`); `u/editer/tie-luohan.lpc` is a broken
  wizard scratch-directory draft with garbled variable names (e.g.
  `skill_statussname`, `snamei`) from a botched find-replace — both
  under personal wizard directories, not core content, same finding as
  #91 (identical filenames too).
- `d/taohua/taohua_b.lpc` (a bulletin board) references a room
  `/tmp/jungu/dating` that doesn't exist anywhere in this archive (only
  an unrelated NPC file `d/npc/jungu.lpc` exists, no `/tmp/jungu/` zone)
  — genuine content gap, board just never resolves its "home room",
  harmless since boards aren't preloaded.

## Interactive test result — full registration + post-login flow
(verified TWICE, across a driver restart, with the complete final fix
set applied both times)

**Run 1** (before the `bowl.lpc`/`zhengmen.lpc` fixes, driver PID
1099537): id `qinfengwu` → `y` (confirm new character) → real Chinese
name **秦风** (accepted first try) → password `test1234` (x2) → accept
gift stats (`y`) → email → gender `m` → enters `客店` (the tea-house
starting room). `look` re-renders the room correctly; `score` shows a
full real character sheet (title/age/gender/birthdate, 膂力/悟性/根骨/
身法 stats, 精/气 bars, 食物/饮水 bars, kill count, 潜能/实战经验) — this
is exactly the code path fix #11 (combatd.lpc's quest.h include) makes
work; `quit` saves and disconnects cleanly with the expected "你丢下一件
布衣" message.

**Run 2** (after ALL fixes above, fresh driver restart, PID 1133574): id
`qinfengliu` → `y` → real Chinese name **秦岭** → password `test5678`
(x2) → `y` → email → gender `f` → enters `客店`, with the correct
gender-specific NPC greeting ("这位小姑娘" instead of run 1's "这位小
兄弟"). `look`/`score`/`quit` all work identically to run 1, score
showing correct female-specific stat roll. Zero `error:` lines and zero
`Segmentation`/`fatal` lines in `debug.log` across the full run
(confirmed via `python3` substring count, not just `grep`, to sidestep
any shell/locale quoting issues with the Chinese search strings).

```
您的英文名字：使用 qinfengliu 这个名字将会创造一个新的人物，您确定吗(y/n)？
您的中文名字：
请设定您的密码：
请再输入一次您的密码，以确认您没记错：
膂力[ 19]  悟性[ 21]  根骨[ 17]  身法[ 23]
您接受这一组天赋吗？
您的电子邮件地址：
您要扮演男性(m)的角色或女性(f)的角色？

目前权限：(player)
...
客店 -
    这是一家价钱低廉的客栈，生意非常兴隆。...
  /clone/board/kedian_b [ 没有任何留言 ]
  店小二(Xiao er)
店小二笑咪咪地说道：这位小姑娘，进来喝杯茶，歇歇腿吧。
【 平  民 】普通百姓 秦岭(Qinfengliu)
 你是一位十四岁的女性人类，...
 膂力：[ 19]  悟性：[ 21]  根骨：[ 17]  身法：[ 23]
 ...
你丢下一件布衣。
当你下次连线进来时，会从这里开始。
欢迎下次再来！
```

**Testing-methodology note** (matches #91's own pitfall exactly): the
first two names attempted in initial ad-hoc testing (`qinfeng2015` —
contains digits) got rejected at the English-id prompt
("对不起，你的英文名字只能用英文字母"), which desynced the whole
scripted `--send` sequence (each subsequent line got consumed as a fresh
id-retry attempt instead of advancing through the intended flow) — not
a bug, just confirms the id-validation is working correctly (English
letters only) and a reminder to always use a letters-only id in
`mudclient.py` scripts for this lineage.

Both known non-fatal pre-existing corrupted-save-data hits (`chinesed`'s
`e2c_dict.o`, one board's `.o`) appeared during both runs exactly as
expected, both caught gracefully with zero effect on registration,
`look`, or `score`.

## lpcc sweep

Ran twice (before/after the `bowl.lpc`/`zhengmen.lpc` fixes found via the
first sweep's own output), each a fresh `lpcc --batch` sweep via
`scripts/lpcc_check.sh` against all 3,256 `.lpc` files:

- **Before**: 3194/3256 pass (98.09%).
- **After** (bowl.lpc x2 + zhengmen.lpc fixes): **3196/3256 pass
  (98.16%)**.

Remaining 60 failures triaged by category (AGENTS.md §6b), every single
one directly re-verified against this archive's own source (not assumed
from #91's precedent) — see "Confirmed NOT needed" and "Content gaps"
sections above for the full breakdown: 11 corrupted pre-existing board
save files, 2 chinesed/e2c-dict-adjacent restore failures, ~19 genuinely
missing zone/skill content (`mingjiao/yuan` x9, `wudang/taoyuan` x4,
`u/liujun`/`u/editer` wizard scratch x3, `taohua_b`'s missing room x1,
`m_weapon` x6 this_player()-null sweep artifacts), 10 dead
network/intermud daemon files, 1 `home/simul_efun.lpc` sweep artifact, 2
`doc/`-tree illustrative example files, 1 orphaned ASCII-art map file, 2
`cmds/{usr,wiz}/to.lpc` admin-utility functional-closure errors (present
and left unfixed in #91 too, for consistency). None of these affect
registration, `look`, or `score` — all confirmed via direct source
reading and, for the network/preload-related ones, direct grep of
`adm/etc/preload`, not guessed from precedent alone.

Memory stayed healthy throughout both sweeps (~35s wall-clock each,
`free -h` showed only ~4.1GB used / 11GB free at peak — a small/medium
lib, nowhere near mega-lib territory; no throttling needed despite
concurrent sibling agents potentially sweeping #92/#93 at the same
time).

## Process notes

- Driver launched via `setsid nohup ... & disown` (per AGENTS.md's
  documented workaround for the plain-`nohup`-dying-mid-session issue),
  `cd`'d into `libs/jqxz2015/` first so `log/debug.log`
  resolves correctly. Booted twice total (once before the
  `bowl.lpc`/`zhengmen.lpc` fixes to get an initial clean registration
  read, once after, to re-verify with the complete final fix set) — PID
  1099537 (first boot) was killed by its own exact PID before the
  second boot (PID 1133574), and PID 1133574 was killed by its own exact
  PID after all testing completed, each confirmed via `ss -tlnp` no
  longer showing port 40086. No broad `pkill -f` pattern used at any
  point (this session was warned about a prior incident where that
  killed sibling agents' concurrent driver processes on archives
  #92/#93 — avoided entirely here).
- `trace_lpcc.json` (auto-generated by the single-file `lpcc` sanity
  check before the first boot) and `lpcc_batch_raw.log` (the sweep
  script's intermediate raw output) were both removed from the lib's
  top-level directory after use; `lpcc_fail.log` was kept, matching
  every other already-shipped lib's convention (it's the sweep's
  designed, permanent-per-lib output artifact, not an ad hoc scratch
  file).

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **LPC formatter** (AGENTS.md "Post-conversion tooling"): ran
  `format-corpus.mjs` over all 3,256 `.lpc` files — 3,227 reformatted in
  place, 29 refused (nonzero `errors` is expected/fine on messy legacy
  code per the tool's own self-check contract, not chased down).
- **Native retest against rebuilt driver** (`~/src/fluffos/build-debug/
  src/driver`, rebuilt fresh from upstream master): booted clean, zero
  fatal errors in `debug.log` (only pre-existing non-fatal warnings and
  the already-documented `chinesed`/board corrupted-save-data
  `catch()` hits). Full registration verified with a fresh real name
  (秦风八) — English id → confirm → Chinese name → password ×2 → accept
  stats → email → gender m → arrives in 客店; `look`/`score`/`quit` all
  produce correct real output. No regressions from either the rebuilt
  driver or the reformat; no fixes needed this pass.
- **WASM build test** (`scripts/wasm_client.js` against
  `build-wasm/src`): boots cleanly in-process (only ordinary compile
  warnings, no fatal preload errors). Full registration/login flow
  completed successfully under WASM too (id → name 秦风瓦 → password →
  stats → email → gender → 客店 arrival), `look`/`quit` also correct —
  this lib has no IP/site-gating daemon on its login path, so it is
  **not** affected by the documented `query_ip_number()` WASM
  limitation and reaches a full playable state under WASM.

## WASM-enablement pass (loopback-allow / uptime / throttle / admin seed)

Standard WASM/local-play pass per AGENTS.md §1.3(b)/(e) and §1.5.

**Gates patched (loopback always allowed):**
- `adm/daemons/band.lpc` `is_banned()` (~line 39): short-circuit `return 0`
  for loopback / `localhost` / `127.*` (strict match on a well-formed
  string only — a malformed/non-string host is NOT treated as loopback,
  per the fail-closed correction: the driver-side `query_ip_number()`/
  `resolve()` bugs are now fixed upstream, so this fallback is no longer
  needed and would otherwise be a fail-open bypass). This is the
  only address gate on the login path — `logind.lpc` `logon()` calls
  `BAN_D->is_banned(query_ip_name(ob))`.

**Uptime startup gate:** none. No `uptime() < N` connection-rejection gate
exists (only cosmetic UPTIME_CMD display + in-game rumor/content timers).

**Anti-flood throttle:** none. `logind.lpc` has a reconnect/replace flow
(有人从别处…) which is normal game behavior, not a per-IP rate limit.

**Admin account:** id `fluffos`, pw `Mud@2026`, name 浮浮, granted `(admin)`
via `adm/etc/wizlist`. Registered through the real flow; login verified as
`目前权限：(admin)`, `update /adm/daemons/band` recompiled successfully.
Save files (must be committed — NOT gitignored, orchestrator: force-add if
git status hides them): `work/data/user/f/fluffos.o`,
`work/data/login/f/fluffos.o`.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一引擎核心，2015 年内容版本。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 19 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (2026-08-07)

按 AGENTS.md §10.7 流程做的第一轮真正意义上的深度游玩测试——此前几
轮都停留在注册/登录/编译层面。这份档案自己的 README 及既有 NOTES 已
确认它和"2008 加强版"（`jqxz2008`）、"2008 标准版"（`jqxz2008std`）、
"2008 豪华版"（`jqxz2008dlx`）、`xiakexing3` 共享同一套 ES II 引擎核
心，其中 `jqxz2008`/`jqxz2008dlx`/`jqxz2008std`/`xiakexing3` 都已经
各自做过一轮 §10.7 深挖并记录了具体 bug——开机前先把这几份记录读了
一遍当路线图，逐条对照本档案的实际源码，5 个全部确认存在（细节见下
"开机前主动移植"），比预期的还要更省事：不用重新从零排查，直接照着
清单核对再动手修。

WASM 本轮仍然跳过验证：emsdk 安装器把工具链下载硬编码到
`storage.googleapis.com`，本 session 的出站代理策略拒绝该域名
（`curl -sS $HTTPS_PROXY/__agentproxy/status` 确认为 403），未重试。
但这份档案自己 NOTES.md 里"WASM build test"一节记录过更早一轮会话
已经用 `scripts/wasm_client.js` 完整验证过注册/登录流程在 WASM 下能
跑通——本轮只是没有重新跑一遍确认这轮修的 bug 在 WASM 下同样生效，
不是"从未验证过"。

**开机前主动移植（对照 `jqxz2008` 系家族已确认修好的 bug）：**

1. **AGENTS.md §7.7（已确认第 N 例）**——`adm/daemons/chinesed.lpc`
   的 `create()` 原本是裸 `restore()`，本档案的 `data/e2c_dict.o` 是
   损坏的二进制垃圾（不是合法 mapping 字面量），`restore_object()`
   抛出的运行时错误没有被捕获，会让 `create()` 在那一行直接中止，
   全局 `mapping dict` 被清零——第一次真正用到 `chinese()`/
   `to_chinese()` 的地方（战斗/技能提示大量使用）就会崩溃。改成
   `catch(restore()); if (!mapp(dict)) dict = ([]);`，和 `jqxz2008`
   系已验证过的修复完全一致。开机日志里能直接看到这处 `catch()`
   正确拦下了损坏存档的运行时错误（而不是让 `create()` 中止），
   验证修复生效。
2. **AGENTS.md §7.11（已确认第 N 例，且是本档案里最严重的一处）**——
   `work/log/nosave/` 目录在这份 `work/` 树里从未被创建（gitignore
   忽略的运行期目录，与仓库无关），但至少 4 个 `write_file()`/
   `log_file()` 调用点无保护地往里面写：`adm/daemons/combatd.lpc`
   的 `killer_reward()`（**每一次玩家死亡**都会跑到，且这一处不像
   `kill.lpc` 那样有 `userp()` 判断限定 PK 场景，任何死亡都会触发）、
   `cmds/std/kill.lpc`（仅 `userp()` 场景）、`cmds/skill/{bai,
   apprentice}.lpc` 的风清扬弟子计数器。`killer_reward()` 这一处一旦
   目录缺失就会在 `die()` 中途未捕获地抛异常，让角色的死亡清理（尸
   体、鬼魂状态、移到死亡场景）全部不会执行，角色变成"活着但气血
   精气归零"的破损状态，而且会在之后**每一次 `heart_beat()`** 都
   重新触发——`jqxz2008`/`jqxz2008dlx` 都通过实际杀死角色确认过这
   个死循环崩溃。本轮用该家族已验证的 `assure_file()` 模式在 4 处
   `write_file()` 调用前各加一行 `assure_file(...)`（`combatd.lpc`/
   `kill.lpc`/`bai.lpc`/`apprentice.lpc`），并给 `bai.lpc`/
   `apprentice.lpc` 里 `read_file()` 的结果加了 `stringp()` 判断
   （避免 `atoi(0)`）。**本轮额外发现的第 6 个同类隐患**：这份档案
   自己的 `adm/simul_efun/file.lpc` 里 `log_file()`（全档案通用的日
   志辅助函数，被 `cmds/arch/call.lpc` 等至少 5 个不同的
   `nosave/*` 日志点调用）本身也只是裸 `write_file(LOG_DIR + file,
   text)`，没有调用同一个文件里现成的 `assure_file()` 辅助函数——
   直接在 `log_file()` 内部加一行 `assure_file(LOG_DIR + file)`，一
   次性覆盖它所有的调用点，比逐个日志点手工加保护更彻底（`assure_file`
   定义原本在 `log_file` 后面，这个驱动的编译器要求同文件内被调用
   的函数需要先声明/定义，所以顺手把两个函数的顺序对调了）。
3. **`cmds/skill/bai.lpc`/`cmds/skill/apprentice.lpc`（一处括号位置
   错误）**——`if (((string)me->query("family/master_id" ==
   "feng qingyang")) || ...)`，`==` 比较被夹在 `query(...)` 的参数
   括号内，传给 `query()` 的实际是恒为假的布尔值，不是想要的属性名
   字符串，导致"从风清扬门下叛出"检测分支永远不会触发。已改成先呼叫
   `query("family/master_id")` 拿返回值再比较，两个完全相同的文件都
   改了。
4. **AGENTS.md §8.9（已确认第 N 例）**——`adm/daemons/logind.lpc`
   `enter_world()` 里 `if (!user->query("food") && !user->query("water")
   && ob->query("age") == 14)`，`age` 取自登录阶段用完即弃的连线桩物
   件 `ob`，不是真正的角色本体 `user`——桩物件永远没有 `age` 属性，
   条件恒为假，导致每个新角色的食物/饮水从创建起就永远是空的。改成
   `user->query("age") == 14`。Live 验证：注册后 `score` 食物/饮水两
   栏均满格（■■■...），管理员账号 `fluffos` 重新登录后同样两栏被
   补上（此前从未有 food/water 字段，见下方存档 diff）。
5. **`get_name()` 遗留调试 `printf("%O\n", ob)`（新发现，`jqxz2008`
   系没有，`xiakexing3` 有）**——紧跟在玩家输入中文姓名之后，会把连
   线桩物件的原始引用（`/clone/user/login#0` 这类内部标识）直接回显
   给正在注册的新玩家，属于内部调试信息泄漏。已删除该行，Live 验证：
   注册流程中输入中文名字后直接进入密码设置提示，没有任何对象引用
   泄漏。

**测试路径**：读 `doc/help/newbie` 确认「较量」(fight) 是安全对练的
标准做法（气/精跌到 50% 或以下自动停止）后，在原生驱动下一次连续会
话里：注册（真实中文名 叶秋白，id `jqxzdeep`）→ 落地客店，`look`/
`score`/`i` 确认干净、食物/饮水满格（§8.9 修复验证）→ `west`→`south`
到中央广场，`fight liu mang` 对普通"流氓"安全对练，几回合后自动
"承让了"结束，`score` 确认气条降到约 50%、无死亡/无损失 → `enter
shudong` 进入丐帮地下通道，`bai zuo` 组织性拜入 `丐帮` 第二十代弟子
（师父左全），`xue zuo begging` 组织性学习技能，即时进步提示正常 →
另开管理员会话（`fluffos`/`Mud@2026`，账号已在 `adm/etc/wizlist` 中）
用 `call jqxzdeep->set_skill(sword,50)`（该引擎家族没有专门的
`setskill`/`setparty` 类快捷指令，`cmds/arch/call.lpc` 是通用的管理
员任意函数调用指令，充当本档案的技能赋予捷径路径）验证捷径路径——
`nosave/CALL_PLAYER` 操作日志正确写入（验证了上面第 2 点里 `log_file()`
的修复），角色 `skills` 指令确认组织性的 `begging` 与捷径赋予的
`sword` 同时存在 → `quit`（触发 `save()`）→ `debug.log` 全程检查
（`grep -v` 排除编译期 warning 后）零 `error:`/`crash`/`fatal` 行 →
真实间隔重新连线（`nc` 断开重连，非同一 TCP 会话），`score`/`skills`
确认门派归属、师父、组织性/捷径两条技能、已花费潜能全部正确持久化。

**一次会话内的持久化教训（记录，非 bug）**：本轮为了应用
`log_file()` 修复重启过一次驱动，但重启前忘了让测试角色先 `quit`
（只是杀掉了旧驱动进程）——重连后发现角色回到全新状态（无门派、无
技能、潜能满格），排查后确认这不是 mudlib 的持久化 bug：`cmds/usr/
quit.lpc` 的 `main()` 明确调用 `me->save()`，本档案没有自动周期性
存档，纯粹是测试流程上少做了一次 `quit` 才导致进度丢失。之后重新走
了一遍拜师/学艺流程并正确 `quit`，最终的持久化验证（见上）就完全
正常了。

**测试角色**：id `jqxzdeep`，中文名 叶秋白，密码 `Jqxz2026Test`，
丐帮第二十代弟子（师父左全），技能 begging（组织性）+ sword（捷径路
径，50 级），位于客店。存档：`work/data/{login,user}/j/jqxzdeep.o`。
管理员账号 `fluffos` 存档因本轮测试产生了正常的 food/water/mud_age
增量（§8.9 修复的直接体现，非损坏），按这份档案自己既有 NOTES 里
"必须提交，不受 gitignore"的约定一并提交。

**验证通过**：真实中文名注册；`look`/`score`/`i` 多次状态检查；食
物/饮水初始化（§8.9）；安全对练 `fight`（自动停止机制）；丐帮组织
性拜师+学艺；管理员捷径路径（`call`）技能赋予；`chinesed.lpc`
损坏存档的 `catch()` 防护；`log_file()`/`assure_file()` 缺失目录防
护（含新发现的 `log_file()` 自身漏洞）；`quit`（`save()`）后
debug.log 检查；真实断线重连后的完整状态持久化。

**明确未验证**（记录而非静默跳过）：完整战斗到死亡的循环（`fight`
安全对练已覆盖核心战斗机制，真正杀死角色需要更多时间预算构造合适
对手，本轮未做）；风清扬弟子叛出这个罕见分支（`bai.lpc`/
`apprentice.lpc` 的括号修复已通过代码比对验证，未构造这个特定场景
实机触发）；商店购买（起始区域客店本身没有商店，真实商业区未探索）；
WASM 下的重新验证（详见上方说明，proxy 阻断，且此前已有会话独立确
认过 WASM 可用）。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。本次复核确认这份档案已经是本轮 `jqxz2008` 家族里
最干净的一个：`log_error()`（已有 `#15w` 引用注释）、`log_file()`
（早前会话自己就发现并修复了同一个 `assure_file()` 缺失 bug，见
commit `4603617af84`）、管理员账号（`fluffos`/`Mud@2026`，
`wizlist` 已有授权且存档已提交）全部依然正确生效，本轮**没有发现
新 bug，未做任何改动**。

`win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:176`；
未发现 `message()` simul_efun 包装函数。用已提交的 `fluffos`/
`Mud@2026` 登录，`update /adm/simul_efun/file` 确认可正常重新编
译，零诊断刷屏（这次连线也没有再触发姊妹档案 `jqxz2008std` 那次遇
到的随机昏迷事件）。`log/debug.log` 时间戳全程未变化（`Jul 23`，
早于本次会话），确认无新增未捕获运行期错误。登录本身产生的存档时
间戳类微小 diff 已用 `git checkout` 撤销，不提交。驱动最终按精确
PID kill，`ps -p` 确认已退出。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/inherit/room/room"`：删除 818 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），与 `jqxz2008`
系列同一血统同一形状。`clone/misc/roommaker.lpc` 同样有两套模
板——"造一间空房间"的 heredoc 本来干净，"克隆我所在的房间"命令的
字符串拼接模板把同一枚多余的 `replace_program(ROOM);` 烤进了每一
个新克隆的房间，已同步修正。已用 `build-debug` 驱动干净启动验证
（0 个新增编译错误，端口正常监听）；未做完整 §10.7 深度游玩测
试。

## 深度功能测试（2026-08-20，round three，补齐三处"明确未验证"）

本轮专门针对上面 2026-08-07 记录的三处"明确未验证"项，预算充足，
逐一构造场景实机验证。开机前先做了一遍标准清单快速核对（全部确认
已经是干净状态，未发现新问题，细节见下）。

**标准清单核对**：§7.90（`config.fluffos` 第 40 行 `maximum
evaluation cost : 5000000`，确认——注意 `work/config.cfg` 里另有一份
`maximum evaluation cost : 300000`，但那不是驱动实际加载的配置文件，
`config.fluffos` 的 `master file`/`mudlib directory` 等字段才是真正
生效的一份，已核实）；§7.100（全档案 `replace_program(ROOM);` 42 处
命中全部是注释行，零处存活，确认已是上一轮修复后的干净状态）；
§7.111（`adm/obj/master.lpc`——`config.fluffos` 的 `master file`
字段指向的真正生效文件——第 200 行已经是
`objectp(error["object"]) ? file_name(error["object"]) : "(driver)"`
的空指针防护写法；`adm/single/master.lpc` 那份没有防护但从未被驱动
加载，非生效代码，确认无需处理）；§7.79（全档案零 `addn()`/
`addn_temp()` 2 参数裸调用，本档案这套血统本来就不含这个 bug 形
状，确认不适用）；§7.108（`clone/user/user.lpc` 第 110-116 行
`reconnect()` 明确调用了 `enable_commands()`，确认干净）；§7.112
（`death_stage()` 家族 4 个实例——`bgargoyle`/`wgargoyle`/
`newgargoyle`/`yu-zu2`——逐一检查每一个真正终止流程的 exit 分支，
全部正确清除了 `death_stage_active` 重入锁，确认无残缺分支）。

**1. 完整战斗到死亡的循环——已验证，真实死亡+复活全流程跑通**：
新建测试角色 `jqxzfour`（中文名 秦四，密码 `Jqxz2026Four`，男性），
读 `cmds/std/kill.lpc` 确认（与本 session 其它库的规律一致）`kill`
指令对 NPC 目标确实没有任何安全阀（`obj->kill_ob(me)` 对方直接反
击）。找到 `d/npc/xiaofeng.lpc`（萧峰，北大街）——`max_qi 4500`/
`max_jing 1500` 级别的高战力 NPC，远超新手角色——在原生驱动下对他
下 `kill xiao feng`：几回合后被"雷霆一击"重创，"眼前一黑"，真实死
亡（非 `fight` 安全对练）。死亡后走的是完全真实、未修改的代码路
径：`feature/damage.lpc` 的 `die()` → `CHAR_D->make_corpse()` 掉落
尸体 → 移动到 `DEATH_ROOM`（`/d/death/gate.lpc`，鬼门关）→ 房间内
`white gargoyle`（白无常）NPC 的 `death_stage()` 对话流程逐条播放
（"你叫什么名字？"→…→"阳寿未尽？"）→ 最终 `reincarnate()` 并移动到
复活点 `/d/city/wumiao`（武庙）。`score` 确认惩罚符合设计（潜能从
99 减半到 50，气/精降为约 75%，随心跳自然恢复中）、身上物品全部
随尸体掉落（`i` 显示"目前你身上没有任何东西"，与登录时"你丢下一件
布衣"的既有设计一致）。整段过程 `debug.log` 零 `error:`/`crash`/
`Segmentation`。断线重连验证状态正确持久化。（注：`feature/
damage.lpc` 里 `DEATH_ROOM->start_death(this_object())`
这一行调用的函数在全档案任何地方都未定义——`call_other` 到不存在
的函数在这个驱动下是静默返回 0，不是运行时错误，`debug.log` 全程
确认没有相关报错；真正的死亡流程是靠玩家被移动进鬼门关房间后，房
间里 `wgargoyle` 的 `init()` 自己探测 `previous_object()` 触发的，
不依赖这个从未实现的 `start_death()`，纯粹是历史遗留的死代码，不
是本轮范围内的 bug）。

**2. 风清扬弟子叛出——已验证，真实触发，且额外发现并修复一个真
实运行时崩溃 bug（详见下）**：读 `cmds/skill/apprentice.lpc`/
`kungfu/class/huashan/feng.lpc` 确认触发条件——先要成为风清扬的弟
子（`family/master_id == "feng qingyang"`），再拜一个不同门派的师
父，且对方已经对你 `pending/recruit`（即对方已经用 `recruit` 指
令点名收你为徒、只等你回拜）。`feng.lpc` 收徒门槛很高（剑法/紫霞
神功/身法/文学等技能全部 ≥130~160、`shen ≥ 100000`、`int ≥ 41`、
随机 `kar` 检定），管理员 `call` 赋予测试角色对应技能/属性后（符
合任务允许的"用管理员捷径进入场景，但让真正的触发指令走真实代码"
原则），先在 `/d/huashan/buwei2` 拜入门槛较低的入门弟子路线（岳不
群，仅需 `shen≥1000`+`query_int()≥25`），确认拿到 `family_name ==
"华山派"` 后，再到 `/d/huashan/houshan` 拜风清扬，成功——`family/
master_id` 确认变为 `"feng qingyang"`。随后用管理员 `possess`
指令附身到丐帮 `左全`（`/d/gaibang/inhole`）身上手动对 `jqxzfour`
下一次 `recruit` 指令（不经由 `attempt_apprentice()` 的自动即时收
徒分支，只是先挂起 `pending/recruit`），退出附身后，`jqxzfour` 玩
家自己下 `bai zuo`——这次真正命中 `apprentice.lpc`（原括号 bug
修复处）里 `ob->query_temp("pending/recruit")==me` 那个分支，输出
"你决定背叛师门，改投入左全门下！！"，`family_name` 变为"丐帮"，
`family/master_id` 变为左全，`score` 也确认师承信息正确更新；`/
kungfu/class/huashan/FENG` 计数文件从"0"变为"2"（两次拜风清扬产生
的正常计数递增，一次是最初的入门测试，一次是为复现这个分支而重
新拜的），确认原括号错误修复后这条分支的运行时行为完全符合预期。

（补充观察，非 bug，未修改）：`feng.lpc`/`kungfu/class/gaibang/
hong.lpc` 的 `attempt_apprentice()` 用
`(string)ob->query("family/family_name") != ""` 判断"对方是否已
经有师父"——对一个从未加入任何门派的全新角色，`query(...)` 返回
的是裸 `int 0`，`(string)0` 在这个驱动下转成字符串 `"0"` 而非空
字符串 `""`，导致该判断对"完全没有门派"和"已有其它门派"两种情况
一视同仁地拒绝，实机复现确认（`bai feng` 对一个从未拜过师的全新
角色会被拒绝，提示"既然已有名师指点，何必又来拜老朽呢"）。但这条
分支在正常玩法里几乎不可能被触发——华山派/丐帮的高阶传人一定是先
经过入门弟子（岳不群/宁中则/令狐冲，或丐帮的左全等）才可能有资格
再进阶拜访风清扬/洪七公，不会有全新角色跳过所有入门步骤直接来见
这两位——按本 session 的 scope 纪律（无编译错误/运行时崩溃/
debug.log 报错/驱动级拒绝，大概率是设计而非 bug）未作修改，只记
录在此供后续参考。

**3. 商店购买——已验证，价格扣除+实物到手全部正确**：`d/city/
zahuopu.lpc`（杂货铺，东大街南）用 `list`/`buy` 两个指令，NPC
`杨永福`（`d/city/npc/yang.lpc`）用 `F_DEALER` 混入。给测试角色
`jqxzfour` 用管理员 `clone /clone/money/coin` + `call
coin->set_amount(500)` + `give coin to jqxzfour`（任务允许的
"clone+give 该档案真实货币物件"标准手法，需要角色在线才能接收，
先重连再 give）；`list` 确认价目表，`buy budai`（麻布袋，标价一
两白银=100）购买成功，`i` 确认物品到手且找零正确（四两白银，
500-100=400=4两，数学验证一致）。有一处值得记录但非 bug 的现象：
`buy` 命令刚执行完的一瞬间，`i` 仍然显示"五百文铜板"（旧的、本该
被清空的硬币堆）——根源是 `inherit/item/combined.lpc` 的
`set_amount(0)` 并不会立即把 `amount` 归零，只是 `call_out
("destruct_me", 1)` 延迟 1 秒后再摧毁物件，这 1 秒窗口内
`query_amount()`/`short()` 显示的是即将消失前的旧值；2 秒后再查
`i`，旧硬币堆已经正确消失，只剩找零后的银两，最终状态完全正确。
无编译错误/运行时崩溃/debug.log 报错，纯粹是这个 ES2 引擎家族的
货币物件通用的、无害的、会自我纠正的显示延迟，不是本档案独有，
不作修改。

**新发现并修复的真实 bug（AGENTS.md §7.30 第二例）**：在"1.完整战
斗到死亡"测试过程中，`debug.log` 捕获到一条真实未拦截的运行时错
误——`执行时段错误：*Bad argument 1 to keys() Expected: mapping
Got: 0`，来自 `/d/npc/xiaofeng.lpc` 第 99 行 `check_skills()`。根
源：`feature/skill.lpc` 的 `mapping query_skills() { return
skills; }`，`skills` 这个成员变量对一个从未学过任何技能的全新角色
从来没有被赋值过，LPC 对未初始化 `mapping` 变量的默认值是裸
`int 0` 而非 `([])`，`xiaofeng.lpc` 的 `init()` 在任何玩家进入他
所在房间（北大街）2 秒后排程的 `check_skills()` 无防护地对这个
可能是 0 的返回值调用 `keys()`，直接崩溃——**任何全新、从未学过
任何技能的角色路过北大街都会触发**，属于高可及性的真实 bug，不是
本档案独有内容/平衡设计。全档案排查所有 `keys(...->query_skills
())`/`sizeof(...)` 调用点（多数早已用 `mapp()`/真值判断正确防
护），额外发现 4 处同款无防护实例并一并修复（均改为在调用 `keys()`
前加 `if (!mapp(skl)) return;` 或等价的提前返回防护）：
- `d/npc/xiaofeng.lpc`（萧峰，北大街，已确认可达且已实机复现崩溃
  与修复后不再崩溃）
- `d/npc/duanyanqing.lpc`（段延庆，西大街2，与萧峰同款
  `check_skills()` call_out 形状，确认已放置可达）
- `kungfu/class/mingjiao/yangxiao.lpc`（杨逍，明教铁焰令对话，需
  先加入明教才会走到这条分支，但明教新弟子零技能时仍会命中）
- `kungfu/class/shaolin/qing-le.lpc`（清乐，少林两处——藏经楼手谕
  +达摩令——同理需先加入少林）
- `d/city/npc/baibian.lpc`（城内"百变"，目前档案里未被任何房间引
  用，是死代码，但为与已有防护的姊妹文件
  `d/wudang/npc/baibian.lpc` 保持一致，顺手一并修复）

全部 5 处用 `update` 指令在活驱动上重新编译确认"成功"，并用一个全
新注册、`skills` 指令确认"你目前并没有学会任何技能"的角色（`秦五`
/`jqxztest`）真实走进萧峰房间验证不再崩溃、`debug.log` 全程零
`error:`。已提交。

**测试角色**：`jqxzfour`（秦四，`Jqxz2026Four`，男性，历经商店购
买→真实死亡复活→华山派→风清扬弟子→丐帮叛徒的完整测试链）、
`jqxztest`（秦五，`Jqxz2026Test5`，男性，仅用于验证 §7.30 fix，
零技能状态）。存档：`work/data/{login,user}/j/{jqxzfour,
jqxztest}.o`。管理员账号 `fluffos` 存档因本轮测试（`clone`/
`give`/`possess` 等操作）产生正常增量，按既有约定一并提交。

**测试过程中的插曲（记录，非 bug）**：`possess`（附身 NPC）后，
账号与"当前受控身体"的绑定关系（`find_body(id)`）会保持指向被
附身的 NPC，若不先用某种方式正确退出附身就断线，下次用密码重新
连线会走 `confirm_relogin` 的"是否踢掉旧连线"流程而不是直接
`reconnect`，且如果同一批命令里把 y/n 确认和后续指令一起发送，
非 y/n 的后续指令会被当成 y/n 回答误吃掉（`yn[0]!='y'` 直接判定
为"否"，`destruct(ob)` 断开这次新连线）——这不是 mudlib bug，是
测试脚本没有先手动处理这个确认提示；后续通过重启驱动清空所有连
线状态解决，之后的 `update` 验证等操作均在干净状态下完成。**验证通过**：真实商店购买（价格扣除+实物到手+找零正确）；真实
`kill`战斗死亡到复活的完整流程（掉落尸体/鬼门关对话/复活点正
确/惩罚符合设计/断线重连持久化正确）；风清扬弟子叛出的完整真实
触发（含用管理员 `possess` 精确构造出 `apprentice.lpc` 里那条此
前只做过代码比对、从未实机触发过的 `pending/recruit==me` 分支）；
新发现并修复一处 §7.30 家族真实运行时崩溃 bug（5 处实例）；标准
检查清单六项全部确认干净。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.
