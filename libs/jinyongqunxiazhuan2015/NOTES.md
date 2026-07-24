# jinyongqunxiazhuan2015 — 金庸群侠传 (Jin Yong Heroes Gathering, 2015 edition)

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
(`jinyongqunxiazhuan2008`). Same `jy/` top-level directory name, same
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
  **directly confirmed live** during both registration tests: the
  `/clone/board/kedian_b` board at the starting room restores fine
  (not one of the 11 corrupted ones) and displays correctly under
  `look`; a SECOND corrupted-restore hit (`/clone/board/kedian_b`... no,
  see below) also fires harmlessly during `enter_world()` without
  blocking login.
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
  `cd`'d into `libs/jinyongqunxiazhuan2015/` first so `log/debug.log`
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
