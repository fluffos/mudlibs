# TODO — master status table

Process: see `AGENTS.md` for the per-lib pipeline and the fix catalog. One
row per unique archive (10 exact-duplicate archives excluded — see
`AGENTS.md`'s "Duplicate archives" table). Update this table as each lib is
worked; keep status values consistent so the table stays greppable:

- `not started`
- `extracted`
- `converted` (encoding + rename + ref-fixes applied)
- `boots` (driver starts clean, no fatal errors)
- `playable` (connected with mudclient.py, login flow works, Chinese
  renders correctly)
- `done` (playable + NOTES.md written + committed)
- `blocked: <reason>` (needs a decision or hit something unresolved)
- `not mudlib` (confirmed not LPC mudlib content — client source, docs,
  etc.; see AGENTS.md's non-mudlib list — skipped, not converted)

Port assignments: sequential from 40001, recorded here so re-running
several libs at once never collides. **Next free port: 40076** (40001-40075
assigned/reserved -- 40071-40075 are reserved for archives #77-81, being
processed in parallel by background agents as of this update; 40007 is
ds386, deprioritized/partial). On mega-libs (tens of
thousands of files, the "nitan" family), skip the full `lpcc_check.sh`
sweep — it can OOM the host before finishing (see AGENTS.md §6b) — and
rely on the boot + interactive-connect test as the verification gate.

## Progress summary (updated as libs are finished)

- **POLICY (per user direction): deprioritize non-Chinese/English-language
  archives.** Focus on the Chinese wuxia/xianxia libs, which is the vast
  majority of this collection. If an archive turns out to be English
  (like ds386/Dead Souls), do the minimum to note what it is, don't sink
  deep debugging time into it -- move on to the next Chinese one.
- **Done: 71 / 100** (shanhaizhanshen, xingzhanyingxiong,
  unknownlib20150716 [小雨西游II], bxsj [书剑天下], bxsj1 [书剑·经典],
  chidi [江湖I], ..., nitan170911 [仙剑奇侠传], nitan6 [笑傲江湖], rzrmud
  [大唐西游], xo, xo_final, zzfy [郑州风云3], shiji [世纪],
  dongfanggushi2 [东方故事Ⅱ之天朝帝国], zhonghua2 [中华英雄苏州站],
  shujian2008 [书剑天下 2008], shujiantianxia [书剑天下, 小熊泥苑
  snapshot], shujianpiaoling2 [书剑飘零Ⅱ], xianlvqiyuan [仙侣情缘/XLQY,
  知秋站 2001 snapshot], xianlvqingyuanzheda [仙侣情缘浙大版],
  xianjianchuanqi [仙剑狂侠2000], xiakexinzhuan2 [侠客新传],
  xiakeyingxiong3 [侠客英雄传III], xiakexing100 [侠客行一百], xiakexing3
  [侠客行三/金庸群侠传], beimeixiakexing2001 [侠客行, North America 2001
  build], xiyangzaixian_fengkuang [夕阳再现], datangshuanglong
  [大唐双龙, config has a stale "碧血残阳之豪侠晚歌" name field --
  confirmed NOT a duplicate of archive #71, just a copy-paste leftover],
  tianxiawuxue [天下无雪], xiyangzaixian_fengyun2 [夕阳再现/风云再起2],
  xiyangzaixian3 [夕阳再现III之炎龙封印], tianxia [天下 Beta],
  menghuanxiyou2002 [梦幻西游2002版, same codebase as mhxy #19],
  xiaoyuxiyou [小雨西游/小雨西游Ⅱ, same lineage as unknownlib20150716 #3],
  yueyingqiyuan [月影奇缘, ES II lineage], weimingkongjian [未明空间/wmkj,
  fork of xiyangzaixian_fengkuang #46's 夕阳再现 lineage],
  xinkuangxiangkongjian2 [新狂想空间II, actually named 狂想空间, ES II
  lineage], moniHuafu [模拟华附, 风云3 engine lineage], jianghufengyun
  [江湖风云单机, 夕阳再现 lineage shared with #46/#55], nitan_ceshi
  [泥潭III测试版/《终极魔界》, NT/nitan/Lonely lineage predating the §15
  dbase bug], nitan_san [泥潭三, sibling of nitan_ceshi #60], wuhanzhan
  [武汉站/大话西游, ES II lineage], huoying [火影/Naruto, ES2 lineage],
  yuxuechongsheng [浴血重生, hybrid ES II/nitan lineage],
  yanhuangwuhun [「武林群侠传」之炎黄武魂Ⅱ, ES II lineage], haiyang2
  [海洋II/星月传奇, ES II lineage], kuangxiangkongjian [狂想空间, distinct
  earlier snapshot of xinkuangxiangkongjian2 #53's game],
  yanhuangyingxiongshi [炎黄英雄史/炎黄英雄传, sibling of yanhuangwuhun
  #66], xuanjianlu [玄剑录, ES II/XKX lineage shared with xkx2001
  #25/beimeixiakexing2001 #45], bixiecanyang [碧血残阳之豪侠晚歌,
  夕阳再现 lineage shared with #46/#47/#55/#59], yanlongfengyin_xiaoao3
  [炎龙封印-笑傲江湖3阿飞站, heavier fork of xiyangzaixian3 #48's XYZX
  lineage], shenmo [西游记之神魔传说, ES II/Neolith lineage mega-lib],
  shenzhou [神州, ES II lineage], xiaoaojianghu_client [笑傲江湖服务端+
  客户端, actually a genuine mudlib (not client-only), 夕阳再现 lineage],
  xiaoaojianghu_xo [笑傲江湖XO, third TMI-2/ES2/Falcon snapshot alongside
  xo #28/xo_final #29], xiaoaojianghu2 [笑傲江湖II, ALSO TMI-2/ES2/Falcon
  lineage not nitan-family, a fourth snapshot], xiyouji2003 [西游记2003/
  光辉岁月, ES II lineage close to fluffos_xiyou2000 #15],
  zhongjidiyu_airuoyoulan [终极地狱之爱若幽兰1.166, ES II/"hell" fork
  lineage, cross-check with #78/#80 pending], zitengzhan [紫藤站/大唐西游
  之紫藤站, ES II lineage])
- **New AGENTS.md §15q (hidden client-protocol-version gate)**: found on
  xiyangzaixian3 -- a pre-id prompt can check the input against a
  hardcoded literal (client version string), not just a BIG5/student
  question, and looks identical in prompt text to a normal id prompt.
  Always read the actual `input_to` callback chain, don't infer flow
  shape from prompt text alone.
- **Parallelizing more aggressively per user request**: archives #47-51
  (5 libs) were dispatched to concurrent background agents, each handed
  the full convert/fix/boot/test/lpcc pipeline for one archive
  independently; the main session verified each agent's key claims (fix
  present in the actual file, dns_master excluded, zero boot errors, no
  lingering driver process) before doing the TODO.md/AGENTS.md edits and
  git commit itself, to avoid concurrent-edit conflicts on shared files.
  All 5 are now done (datangshuanglong, tianxiawuxue,
  xiyangzaixian_fengyun2, xiyangzaixian3, tianxia). A second batch of 5
  (archives #52-56: xiaoyuxiyou, xinkuangxiangkongjian2, yueyingqiyuan,
  weimingkongjian, menghuanxiyou2002) followed the same pattern and is
  also now all done. A third batch of 5 (archives #57-61: moniHuafu,
  wuhanzhan, jianghufengyun, nitan_ceshi, nitan_san) followed the same
  pattern and is also now all done; #60/#61 (both "nitan"/泥潭 family)
  were flagged in advance as likely siblings of nitan170911/nitan6 and
  confirmed as a related-but-earlier snapshot that predates §15's core
  dbase bug. A fourth batch of 5 (archives #62-66: yuxuechongsheng,
  haiyang2, atlantis [confirmed not a mudlib], huoying, yanhuangwuhun)
  also followed the same pattern and is all done/triaged. A fifth batch
  of 5 (archives #67-71: yanhuangyingxiongshi, yanlongfengyin_xiaoao3,
  kuangxiangkongjian, xuanjianlu, bixiecanyang) also followed the same
  pattern and is all done; #69/#71 were flagged in advance for lineage
  cross-checks against #53/#49 respectively (both confirmed as related-
  but-distinct or unrelated, not hidden duplicates). Also: xuanjianlu's
  pass found a new bug class (§15ae, `private nomask` command-hook
  breaking every post-login command silently) that turned out to
  retroactively affect the already-shipped beimeixiakexing2001 (#45) too
  -- fixed and re-verified there as well. A sixth batch of 5 (archives
  #72-76: shenzhou, shenmo, xiaoaojianghu_xo, xiaoaojianghu2,
  xiaoaojianghu_client) also followed the same pattern and is all done;
  #74/#75/#76 were flagged in advance for lineage cross-checks against
  nitan6/xo/xo_final -- all confirmed as belonging to the TMI-2/ES2/
  Falcon "XO" lineage (a third and fourth snapshot) rather than
  nitan-family, despite sharing "笑傲江湖" in the title; #76 also turned
  out to be a genuine mudlib despite its "server+client" name (the
  "client" half is just a second wire protocol, no separate client
  program bundled). Every agent in this batch was instructed to test a
  post-login command per §15ae, and all confirmed clean. This mode
  continues for archive #77 onward.
- **New standing policy from §15ae**: never mark a lib "done" without
  testing at least one ordinary post-login command (e.g. `look`) after
  registration completes -- reaching the game world is not the same as
  being able to play in it, and the `private`-command-hook failure mode
  produces literally zero signal in any log.
- **Caution for future batches**: one agent in the #57-61 batch used a
  broad `pkill -f "build-debug/src/driver config.fluffos"` mid-session
  before switching to exact-PID kills -- since every lib's driver shares
  that identical command line, this can kill OTHER concurrently-running
  agents' driver processes too. Always kill by exact PID (`kill <pid>`
  from a recorded launch, not a pattern match) when multiple agents may
  have drivers running at once.
- **New AGENTS.md §15r (check_config.lpc driver-version self-check)**:
  found on tianxia -- a driver-version self-check file `inherit`ed
  straight into simul_efun.lpc/master.lpc can fatally `error()` on
  obsolete MudOS-era `#ifdef` assumptions (e.g. `__PRIVS__` vs
  `PACKAGE_UIDS` presumed mutually exclusive) that don't hold on this
  FluffOS build; disable just the specific failing checks, don't delete
  the whole file.
- **New Encoding gotcha**: `iconv -c`'s invalid-byte recovery can eat an
  adjacent REAL newline too (not just the bad byte), merging a heredoc's
  closing tag onto the preceding text line -- cross-reference against
  convert_lib.sh's LOSSY-conversion log when seeing "End of file in text
  block" errors. Found on tianxia (3 files).
- **New §15b additions**: clr_ansi, chinese_number, changed_match_path,
  query_bandwide, query_shadowed -- more "called everywhere, defined
  nowhere" simul_efuns, found on tianxia. query_shadowed() must restore
  as `shadow(previous_object(), 0)`, not `this_object()` (bare
  simul_efun-call footgun, §15).
- **New extraction edge case (AGENTS.md's Archive tooling section)**:
  a `.rar`-named archive can actually be a plain tar with relative
  `../...` member paths, which GNU `tar -xf` refuses outright even with
  `--transform`. Found on archive #44 (`侠客行III .rar`) -- worked
  around with Python's `tarfile` module, stripping the leading `../`
  from each member's name before extracting. Also: TODO.md's table had
  the wrong filename/extension for this archive (said `.zip`, actual
  file is `.rar` with a trailing space) -- always verify the exact
  filename via `ls archives/ | grep` before assuming the table entry is
  literal.
- **Watch for hidden pre-id prompts** (e.g. a "BIG5 font Y/N?" question
  that blends invisibly into the connection banner, found on
  xiakexinzhuan2): if a registration test produces confusing cascading
  rejections, re-verify with ONE `--send` at a time and read the FULL
  transcript before suspecting the fix logic is wrong.
- **§15p validated**: xianjianchuanqi applied the DNS-daemon-preload
  exclusion PROACTIVELY (before first boot, not reactively) and booted
  clean in under 20s -- confirms the new standing policy works as
  intended, worth doing on sight for every remaining lib.
- **New tooling edge case**: a raw archive can contain a DIRECTORY
  literally named `something.c` (not a file) -- confuses
  convert_lib.sh's blind `.c`->`.lpc` rename (renames the dir but not
  its children, throws harmless `mv: cannot stat` warnings). Found on
  xianjianchuanqi (`chuixue-jian.c/`, an orphaned duplicate-content
  folder) -- rename the resulting dir away from a `.lpc`-look-alike name
  (e.g. `foo.orphaned-dir`) so it's never mistaken for a compilable
  object.
- **NEW standing policy (AGENTS.md §15p, per explicit user direction):
  proactively exclude DNS/intermud/network daemons (e.g. `network/
  dns_master`) from `adm/etc/preload` on EVERY lib before the first boot
  attempt** -- don't wait to discover a hang. These try to bootstrap a
  cross-mud database against a hardcoded remote server unreachable in
  this environment, causing severe boot slowness/hangs (minutes of
  wall-clock with almost no CPU time -- heavily I/O-blocked). Found on
  xianlvqingyuanzheda after a long bisection investigation; per the
  user, this class of bug is NOT worth deep-diving each time -- just
  exclude proactively and, if still slow, trim preload to only the
  registration-essential entries and document what was excluded.
- **Registration flow SHAPE varies a lot between libs** -- confirmed
  again on xianlvqiyuan: GB/BIG5 prompt, then an "are you a student"
  age-gate (any non-"no" answer ends the session), then `new` must be
  typed literally (not any unused id), then English name, then Chinese
  name with NO y/n confirmation in between. Always read logind.lpc's
  actual get_id/confirm_id/get_name call chain before scripting a
  registration test -- don't assume the shape from a previous lib.
- **Similar Chinese titles are NOT a reliable lineage signal** (2nd
  confirmation, after shujianpiaoling2 vs shujian2008): xianlvqiyuan's
  "仙侣奇缘新版" turned out to be a different, older 2001 codebase
  snapshot than xlqy_new2007's "新仙侣情缘之飘渺纪元" (archive #26,
  2007-era) -- confirmed via md5sum diff on core files. Always verify
  via diff, never assume from title alone.
- **Reminder confirmed again on shujianpiaoling2**: a similar Chinese
  title ("书剑" in both this and shujian2008/shujiantianxia) does NOT
  imply shared lineage -- this one has a completely different adm/obj/
  layout, no named.c daemon, and a securityd.c with different internal
  logic (doesn't override `user` with `this_player()` in valid_read, so
  the §15n bug doesn't apply here -- confirmed by reading the source
  proactively rather than needing to hit the crash first).
- **Time-saver confirmed**: before doing full diagnostic work on a new
  archive, spot-check its core `.c` files (`chinese.c`, `logind.c`,
  `named.c`, `master.c`, `securityd.c`) against already-processed libs
  via `diff`/`md5sum` -- `shujiantianxia` (#36) turned out to be
  byte-identical source to `shujian2008` (#35, different site branding
  only), so its fixes were ported directly instead of rediscovered,
  booting clean on the first attempt.
- **Two major new bug classes (AGENTS.md §15n, §15o), found on
  shujian2008**: on any lib with a genuinely CUSTOM `securityd.lpc` ACL
  (not the simpler `find_object`-only master.lpc pattern), the driver's
  own compile-time source/`#include` loading goes through the SAME
  `valid_read` gate as real data reads, attributed to `this_player()` --
  a fresh pre-login connection defaults to `(player)` status, which most
  ACLs deny for `/adm`/`/cmds`, so the FIRST lazy compile of any
  never-preloaded object touched by the registration flow crashes
  ("Read access denied") one dependency at a time. Fix: allowlist
  `func=="load_object"/"recompile_object"/"include"` in the custom
  `valid_read`. Separately, a missing `master.lpc get_include_path()`
  breaks `#include`s specifically for compiles triggered mid-connection
  (works fine at preload/bare lpcc-check). **Check both proactively on
  any lib with a real custom security daemon** -- this was the most
  diagnostically expensive lib processed since the nitan-family §15
  discovery.
- **New bug class (AGENTS.md §15m), found on zhonghua2**: a daemon's
  unguarded `restore()` in `create()` can crash on stale/corrupted save
  data shipped in the archive itself (not a UTF8 issue), masquerading
  as an intentional maintenance/sync gate on every connection instead of
  looking like a crash. If a fresh boot's banner shows an unexplained
  "syncing"/"please wait" message, check debug.log for a
  `restore_object()`/"Illegal mapping format" error before assuming it's
  a real gate to wait out.
- **New crash bug class (AGENTS.md §15l), found on dongfanggushi2**:
  `master.lpc`'s `create()` destructing+reloading `SIMUL_EFUN_OB` (an
  old-MudOS trick) segfaults the WHOLE DRIVER PROCESS on this build if
  called during master's own bootstrap — not an LPC error, a raw
  process crash with no debug.log clue beyond a C++ stack dump. Check
  every new lib's master.lpc `create()` for a `destruct()` call
  targeting `SIMUL_EFUN_OB`/`MASTER_OB` proactively; it's invisible to a
  compile-only lpcc check and only surfaces as a hard crash on first
  real boot.
- **New bug class (AGENTS.md §15k), found on shiji**: case-sensitive
  filename mismatches from Windows-origin archives aren't limited to
  `#include`s (§15g) — a plain DATA file read via `read_file()` hits the
  same issue but fails at RUNTIME instead of compile time, and if it's on
  the connection-setup path (`logon()`) it kills every single new
  connection with zero prompt output, looking exactly like a dead
  server. Check for this first when a fresh boot produces truly nothing
  on the very first connection attempt.
- **CRITICAL, project-wide (AGENTS.md §15h)**: every `chinesed.lpc`-style
  GBK byte-range Chinese-character check is silently wrong under this
  driver's UTF-8 native strings — it doesn't error, it just always
  evaluates incorrectly, and this specifically breaks character
  registration (is_chinese/check_legal_name are used to validate a new
  player's name). Retroactively fixed across all 21 libs done before this
  was discovered, and now applied proactively to every new lib. **Never
  consider a registration flow "verified" just because it reaches a
  prompt — must actually send a real Chinese name through it and confirm
  it reaches the NEXT stage.** This is exactly how the bug went
  undetected across 21 libs for so long.
- **rzrmud confirms the nitan-family bug is lineage-specific, not
  universal**: this lib's simul_efun has no global set/query/delete at
  all, relying entirely on per-object `inherit NPC;`-style base classes
  instead (the architecturally correct pattern) -- booted with zero
  fixes needed. Don't assume every lib needs the §15 dbase fix; check
  whether `adm/obj/simul_efun.lpc` (or equivalent) actually defines
  those functions before assuming the bug applies.
- **Major finding on nitan170911** (AGENTS.md §15): the whole "NT/nitan/
  Lonely" mudlib lineage implements per-object property storage
  (`set`/`query`/`delete`) as bare simul_efun calls, relying on
  `this_object()` being the CALLER during a simul_efun call -- but on this
  driver `this_object()` is the SIMUL_EFUN OBJECT itself, so without a
  fix every object sharing no local override reads/writes ONE shared
  dbase. Fixed by giving `feature/dbase.lpc` real local set/query/delete
  (inherited by nearly everything).
- **Confirmed on nitan6**: applying every nitan170911 fix proactively
  before the first boot attempt worked -- booted clean on the first try.
  This is the playbook for any future same-lineage lib: recognize it, copy
  the byte-identical generic engine files straight over, manually re-apply
  the same transformation to files with real content differences, THEN
  boot.
- **Mega-lib note**: both nitan170911 (~54,600 files) and nitan6 (~23,100
  files) are far larger than every other lib processed so far. The full
  `lpcc_check.sh` sweep is impractical at this scale -- it drove this
  23GB host to ~370MB free with heavy swapping after 18 minutes on
  nitan170911, well before finishing, so it was killed rather than risk
  an OOM. Skipped entirely on nitan6. The boot + interactive-connect test
  found every real bug on both libs and is treated as sufficient
  verification for libs this size (AGENTS.md §6b).
- **Partial/deprioritized: ds386** ("Dead Souls", archive #7 — English,
  Nightmare-mudlib-lineage, not wuxia). Boots and the first-time admin
  setup wizard runs interactively; not polished further per the policy
  above. Still found reusable fixes along the way (§8f, §8g in AGENTS.md).
- Once a lib's lineage is recognized (shared master.lpc/securityd.lpc
  code shapes), apply known catalog fixes PROACTIVELY before the first
  boot attempt instead of rediscovering them -- worked cleanly for bxsj1
  (same lineage as bxsj): all 3 fixes applied up front, booted clean on
  the first try.
- **Lesson from ds386**: an automated multi-file fix for a systemic-
  looking pattern needs verification per-instance, not just on the 1-2
  samples that motivated it -- a regex-shaped bug class can still have
  genuinely-correct instances mixed in with broken ones. Also: when the
  SAME error string appears in dozens of files, check for one shared
  inherited dependency before assuming dozens of separate bugs (AGENTS.md
  §8g) -- much higher leverage.
- Tooling built along the way (now reusable for the rest): `extract.sh`,
  `convert_lib.sh` (encoding + rename + ref-fixes, automated), `lpcc_check.sh`
  (now batch-mode, ~15-70x faster — one VM boot compiles every file),
  `mudclient.py` (telnet smoke-test client).
- Driver patched twice (`~/src/fluffos`, both `build/` and `build-debug/`
  rebuilt each time — see AGENTS.md §8, §"lpcc --batch"):
  1. Null-pointer crash in `mudlib_stats.cc` (old-MudOS bootstrap ordering).
  2. `MAX_EXPANSION_NESTING`/`kMaxExpandStringDepth` raised (32→1024,
     64→1024 outside ASan builds) so long macro-heavy expressions compile;
     `lpcc` given a `--batch` mode for fast multi-file sweeps.
- Fix catalog in `AGENTS.md` is up to §15f (+ §8b-8h, §15b-15f sub-entries)
  — read it before starting a new lib, most of what's there will recur.

| # | Archive | Slug | Port | Status | Notes |
|---|---|---|---|---|---|
| 1 | 山海战神.rar | shanhaizhanshen | 40001 | done | pilot lib; see libs/shanhaizhanshen/NOTES.md |
| 2 | 星战英雄.rar | xingzhanyingxiong | 40002 | done | 2nd pilot; found driver bug (AGENTS.md §8) + message_combatd mudlib bug; see libs/xingzhanyingxiong/NOTES.md |
| 3 | 20150716未知lib.zip | unknownlib20150716 | 40003 | done | actually 小雨西游II; found get_include_path fix (§8d); see libs/unknownlib20150716/NOTES.md |
| 4 | bxsj.rar | bxsj | 40004 | done | 书剑天下; found 3 new bugs incl. the this_player()-override footgun (§8c); see libs/bxsj/NOTES.md |
| 5 | bxsj1.rar | bxsj1 | 40005 | done | 书剑·经典, same lineage as #4; 3 known fixes applied proactively; see libs/bxsj1/NOTES.md |
| 6 | chidi.rar | chidi | 40006 | done | 江湖I; found tail() missing-efun + include-angle-bracket bugs (§8e, convert_lib.sh fix); see libs/chidi/NOTES.md |
| 7 | ds3.8.6.zip | ds386 | 40007 | partial/deprioritized | Dead Souls, English-language -- user directed to deprioritize non-Chinese libs; boots + admin wizard runs but not polished; see libs/ds386/NOTES.md |
| 8 | dtsl.rar | dtsl | 40008 | done | 大唐双龙传, lib #1 lineage, booted with zero fixes; found F_UNIQUE macro gap + diamond-inherit issue; see libs/dtsl/NOTES.md |
| 9 | dw_fluffos_v1.tar.gz | | | deprioritized | confirmed Discworld mudlib (English) -- skipping per policy, revisit only if asked |
| 10 | dw_fluffos_v2.zip | | | deprioritized | same Discworld bundle, different version -- skipping per policy |
| 11 | dw_fluffos_v3.zip | | | deprioritized | same Discworld bundle, different version -- skipping per policy |
| 12 | es1_win.rar | es1_win | 40009 | done | 东方故事(蓝天), foundational wuxia base lib; found preload-time get_include_path timing gotcha (§8d); see libs/es1_win/NOTES.md |
| 13 | esI.rar | esI | 40010 | done | 东方故事/屠龙之战, same lineage as #12, both known fixes applied proactively; see libs/esI/NOTES.md |
| 14 | fengyun4-3-4.rar | fengyun434 | 40011 | done | 风云Ⅳ, booted with zero fixes, 99% lpcc pass rate; see libs/fengyun434/NOTES.md |
| 15 | fluffos(西游记2000).tar.gz | fluffos_xiyou2000 | 40012 | done | 西游记/xiyouji.org; bundled driver source ignored, mudlib nested in world.tar.gz inside; see libs/fluffos_xiyou2000/NOTES.md |
| 16 | fy2005.rar | fy2005 | 40013 | done | 风云Ⅳ (2005 build), boots clean; 5-min startup grace period before login works; see libs/fy2005/NOTES.md |
| 17 | fy2.rar | fy2 | 40014 | done | 风云再起Ⅱ, booted with zero fixes; see libs/fy2/NOTES.md |
| 18 | LLMUD(大唐双龙)v_0.11版.rar | llmud_datangshuanglong | 40015 | done | same lineage as dtsl(#8), zero boot fixes needed; see libs/llmud_datangshuanglong/NOTES.md |
| 19 | mhxy.rar | mhxy | 40016 | done | 梦幻西游 (Qingdao), 西游记 lineage; CRLF sed gotcha (§8h); see libs/mhxy/NOTES.md |
| 20 | MUD侠客行2017完整版.zip | xiakexing2017 | 40017 | done | 侠客行 2017, booted with zero fixes; see libs/xiakexing2017/NOTES.md |
| 21 | nitan170911.7z | nitan170911 | 40018 | done | 仙剑奇侠传 (NT/nitan/Lonely lineage); found the major simul_efun set/query/dbase architecture bug (AGENTS.md §15) + several never-defined-globals gaps (§15b) + preload data-file .c refs (§15c); new-player registration needs a real MySQL backend (out of scope, fails gracefully with a clear message); see libs/nitan170911/NOTES.md |
| 22 | nitan6.zip | nitan6 | 40019 | done | 笑傲江湖, same NT/nitan lineage as #21 -- proactively applied all §15/§15b/§15c fixes before first boot, booted clean on the first attempt; found a missing seteuid() + a heartbeat-interval efun gap + the "bare array" typo (§15f, new); plays through into full character creation with zero crashes; see libs/nitan6/NOTES.md |
| 23 | rzrmud.20130220.tar.gz | rzrmud | 40020 | done | 大唐西游/YWX人造人, different lineage from nitan family (no simul_efun-based dbase, correctly uses per-object inherit instead); booted with zero fixes, 97.5% lpcc pass; ~55-file missing-inherit content gap noted but not fixed; see libs/rzrmud/NOTES.md |
| 24 | TOMud_VC源代码.rar | | | not mudlib | confirmed: "MyMud", a Windows MFC/VC++ GUI mud CLIENT (MainFrm.cpp, DialogGame.cpp, MudSock.cpp, ...), not LPC source -- skipped, see AGENTS.md's non-mudlib list |
| 25 | xkx2001测试用老lib.zip | xkx2001 | 40021 | done | 侠客行Ⅰ, "ES II" lineage (shares master.c almost verbatim with rzrmud #23 despite adm/single/ layout resembling bxsj); booted with zero fixes, 84.7% lpcc pass; missing EDITOR_D daemon noted (bulletin-board feature gap, not fixed); see libs/xkx2001/NOTES.md |
| 26 | xlqy_new2007.rar | xlqy_new2007 | 40022 | done | 新仙侣情缘之飘渺纪元, ES II lineage; found + fixed an extract.sh bug (relative .rar paths silently failed) + the recurring convertd.lpc Greek-table backslash typo (§8h); 98.6% lpcc pass after fix; one non-fatal unexplained runtime error during login noted but not chased; see libs/xlqy_new2007/NOTES.md |
| 27 | xlqy-解压看readme.rar | | | not started | probed: extracts fine (no password/special step needed despite the name), root `xlqy/`, same "仙侣情缘" name/config as #26 (xlqy_new2007) but a different, EARLIER/incomplete snapshot -- its own readme.txt says (translated) "this lib is very incomplete, mainly used to test the driver ... many things are incompatible, no tech support provided". Not a byte-duplicate of #26 (9174 vs 9060 .c files). Lower priority given #26 already covers this game; process with standard pipeline when its turn comes, expect a rougher lpcc pass rate per the author's own disclaimer |
| 28 | xo.zip | xo | 40023 | done | 笑傲江湖迷你版, TMI-2/ES2 lineage (Falcon), secure/daemon/ layout; found a case-sensitivity #include bug (Action.h vs action.h, new §15g) that was causing 209/1395 lpcc failures, fixed to 72; applied §4's security-daemon reentrancy guard proactively; see libs/xo/NOTES.md |
| 29 | xo最终版1.2.rar | xo_final | 40024 | done | same TMI-2/ES2 lineage as xo(#28), full "final" build (~7,174 files vs xo's 1395); found the "comment eats next line" typo (2x) + ~8 lossy-conversion corrupted string literals; full registration flow verified incl. real Chinese name "赵云" reaching the password prompt; see libs/xo_final/NOTES.md |
| 30 | zzfy (full).rar | zzfy | 40025 | done | 郑州风云3, same 风云 lineage as fy2/fy2005/fengyun434; simpler registration architecture (no separate "new" keyword branch -- "new" is itself banned as an id, any unused id goes straight to character creation); §15h fix applied proactively; full registration flow verified incl. real Chinese name "萧峰" reaching the password prompt; 89.5% lpcc pass; see libs/zzfy/NOTES.md |
| 31 | 三国歪传.rar | | | not mudlib | confirmed: DikuMUD/Merc-lineage compiled C server ("三国歪传" by mrec, Taiwan) -- src/db.c,comm.c,fight.c,handler.c (Diku/Merc/ROM names), area/ .are-style world files, zero `inherit` statements anywhere -- fundamentally not LPC, skipped, see AGENTS.md's non-mudlib list |
| 32 | 世纪.zip | shiji | 40026 | done | 世纪(Century), adm/single/ layout; found §4 master.lpc fix + §15h chinese-detection fix + a NEW case-sensitive DATA file bug (mudvisitor vs MUDVISITOR, §15k) that silently crashed every connection attempt; full registration flow verified incl. real Chinese name "萧峰"; 93.6% lpcc pass; see libs/shiji/NOTES.md |
| 33 | 东方故事二.rar | dongfanggushi2 | 40027 | done | dup: 东方故事二 (1).rar; "东方故事Ⅱ之天朝帝国", ES II lineage but a distinct/smaller codebase than es1_win/esI despite same adm/obj/ layout; found a NEW driver-crash bug (master.lpc destructing SIMUL_EFUN_OB segfaults on boot, §15l) + §4 fix on both valid_write/valid_read + §15h fix incl. a new sliding-window sub-variant; unusually long registration chain (id→confirm→password→email→race→gender→Chinese name) verified end-to-end through a real Chinese name "萧峰" all the way into an actual game room; 85.9% lpcc pass; see libs/dongfanggushi2/NOTES.md |
| 34 | 中华2.rar | zhonghua2 | 40028 | done | 中华英雄苏州站, adm/single/ layout; found a stale corrupted versiond.o save file crashing a daemon's create() and masquerading as a maintenance gate (NEW, §15m) + §15h fix (unique whole-string is_chinese variant) + deep named.lpc fix (nitan-family shape) + combined surname/given-name length fix; full registration flow verified with real surname "萧" + given name "峰"; 97.3% lpcc pass; see libs/zhonghua2/NOTES.md |
| 35 | 书剑2008.rar | shujian2008 | 40029 | done | 「书剑天下」2008, Century-family adm/single/ layout with a genuinely custom securityd.lpc ACL; found TWO new major bug classes (§15n func-discrimination gap blocking mid-connection lazy compiles + §15o missing get_include_path) + standard §15h fixes; full registration flow verified incl. correct rejection of banned novel-name "萧峰" then acceptance of invented name "秦风"; 99.2% lpcc pass; see libs/shujian2008/NOTES.md |
| 36 | 书剑天下.rar | shujiantianxia | 40030 | done | code-identical to shujian2008(#35) -- confirmed via diff, only site branding ("小熊泥苑") + runtime state differ, NOT a byte-identical archive though (different md5sum, kept as its own entry); ported all 7 already-proven fixes directly, booted clean on first attempt; full registration flow verified with real name "秦风"; 99.2% lpcc pass (same as #35); see libs/shujiantianxia/NOTES.md |
| 37 | 书剑飘零II .zip | shujianpiaoling2 | 40031 | done | 「书剑飘零Ⅱ」"Stray Book & Sword" by 飞白工作室, adm/obj/ layout -- genuinely unrelated to shujian2008/shujiantianxia despite similar title; standard §15h fix + proactive get_include_path() insurance; confirmed §4/§15n not needed via source reading; full registration flow verified with real name "秦风"; 95.3% lpcc pass; see libs/shujianpiaoling2/NOTES.md |
| 38 | 仙侣奇缘新版.rar | xianlvqiyuan | 40032 | done | 仙侣情缘/XLQY, 知秋站 2001 snapshot, DIFFERENT older codebase than xlqy_new2007(#26) despite similar title (confirmed via md5sum diff); standard §15h fix + proactive get_include_path() + §8h convertd.lpc typo (45x) + NEW case-sensitivity bug (BANNER vs banner) that silently crashed every connection via unguarded cat()/write(0), fixed + hardened cat() itself; full registration flow verified (gb->no->new->English name->real Chinese name "秦风"); 98.5% lpcc pass; see libs/xianlvqiyuan/NOTES.md |
| 39 | 仙侣情缘浙大版.rar | xianlvqingyuanzheda | 40033 | done | "ZJU" fork of XLQY by bugbug/alading, adm/obj/ layout, chinese.c matches xlqy_new2007(#26) but other core files differ; standard §15h/§8h fixes + NEW standing policy (§15p): dns_master preload hang -> trimmed preload to registration-essential daemons only (documented exclusions in NOTES.md); full registration flow verified with real name "秦风"; 98.4% lpcc pass; see libs/xianlvqingyuanzheda/NOTES.md |
| 40 | 仙剑传奇.rar | xianjianchuanqi | 40034 | done | 仙剑狂侠2000, Century-family adm/single/ layout matching shujian2008's is_chinese/check_legal_name shape; proactively excluded dns_master from preload (§15p) before first boot -- booted clean in <20s; found+fixed a new unguarded write(read_file()) crash (uptime.lpc LASTCRASH path mismatch) + an orphaned directory-named-like-a-file conversion quirk; full registration flow verified with real name "秦风"; 95.5% lpcc pass; see libs/xianjianchuanqi/NOTES.md |
| 41 | 侠客新传(2).rar | xiakexinzhuan2 | 40035 | done | 侠客新传 v0.1b, Century-family adm/single/ layout (config.cfg has a leftover 海洋II MUD_NAME suggesting a forked base); standard §15h fix + deep named.lpc fix (nitan-family shape) + proactive dns_master preload exclusion (§15p); hidden BIG5-prompt testing gotcha documented; full registration flow verified with real name "秦风" (avoiding banned novel character "中神通"); 97.3% lpcc pass; see libs/xiakexinzhuan2/NOTES.md |
| 42 | 侠客英雄传III 可用.zip | xiakeyingxiong3 | 40036 | done | 侠客英雄传 (Jin Yong + European medieval + manga crossover setting), adm/obj/ layout; standard §15h fix (chinesed.c's is_chinese had a pre-existing str[0]-not-str[i] typo, harmless since always called per-character, fixed to standard shape) + proactive dns_master preload exclusion (§15p); full registration flow verified with real name "秦风" (avoiding banned "张三丰"); 98.0% lpcc pass; see libs/xiakeyingxiong3/NOTES.md |
| 43 | 侠客行100.rar | xiakexing100 | 40037 | done | 侠客行一百, Century-family adm/single/ layout, largest lib in this batch (~14,227 raw files); standard §15h fix + proactive dns_master preload exclusion (§15p); full registration flow verified with real name "秦风" (avoiding banned "韦小宝"); 99.3% lpcc pass, memory stayed healthy despite size; see libs/xiakexing100/NOTES.md |
| 44 | 侠客行III .rar | xiakexing3 | 40038 | done | actually a plain tar despite .rar extension (relative ../ paths, needed Python tarfile workaround, see AGENTS.md); config MUD_NAME "侠客行三" but live banner says "金庸群侠传"; adm/obj/ layout, unrelated to xiakexing100(#43) despite similar title; standard §15h fix + proactive dns_master preload exclusion (§15p); full registration flow verified with real name "秦风"; 96.8% lpcc pass; see libs/xiakexing3/NOTES.md |
| 45 | 北美侠客行2001.rar | beimeixiakexing2001 | 40039 | done | 侠客行/"The Quest of Oriental Chivalry", same codebase lineage as xkx2001(#25) confirmed via diff (chinese.c/master.c identical, logind.c differs by one comment); ported xkx2001's proven check_legal_name fix + standard is_chinese fix + NEW instance of §8e tail-efun bug (fatal here, took down the whole simul_efun compile) + proactive dns_master preload exclusion (§15p); hidden BIG5 prompt; full registration flow verified with real name "秦风" (avoiding banned "韦小宝"); 84.6% lpcc pass (same missing EDITOR_D pattern as xkx2001); RETROACTIVE FIX (2026-07-22, found via xuanjianlu #70 flagging the same bug): feature/command.lpc's `private nomask command_hook` silently broke EVERY post-login command with zero error (§15ae) -- dropped `private`, re-verified with a fresh registration + look/score both now working; see libs/beimeixiakexing2001/NOTES.md |
| 46 | 夕阳再现-疯狂江湖.rar | xiyangzaixian_fengkuang | 40040 | done | dup: 夕阳再现-疯狂江湖(1).rar; 夕阳再现, adm/obj/ layout, no dns_master in preload (nothing to exclude); standard §15h fix; full registration flow verified with real name "秦风"; 97.8% lpcc pass; see libs/xiyangzaixian_fengkuang/NOTES.md |
| 47 | 夕阳再现-风云再起2.rar | xiyangzaixian_fengyun2 | 40041 | done | adm/obj/ layout, chinese.c byte-identical to archive #46 but logind.c/master.c/securityd.c differ (similar titles/shared files ≠ shared lineage overall); standard §15h fix + proactive dns_master preload exclusion (§15p) + fixed a couple of pre-existing missing-quote typos; full registration flow verified end-to-end incl. real name "秦风" reaching the actual game world; 98.6% lpcc pass; see libs/xiyangzaixian_fengyun2/NOTES.md |
| 48 | 夕阳再线III之炎龙封印.rar | xiyangzaixian3 | 40042 | done | "夕阳再现III之炎龙封印" (AKAI Studio 2006), adm/obj/ layout nested at raw/夕阳再现III/夕阳再现III/world/; standard §15h fix + missing WQA_ROOM macro fix (81-file cascade, new §8g variant) + proactive dns_master preload exclusion (§15p) + NEW hidden client-version gate found (§15q, literal "2060" check) + several pre-existing typos fixed; full registration flow verified end-to-end incl. real name "秦风五" reaching the actual game world; 98.3% lpcc pass; see libs/xiyangzaixian3/NOTES.md |
| 49 | 大唐双龙.rar | datangshuanglong | 40043 | done | related-but-distinct fork of dtsl(#8)/llmud_datangshuanglong(#18) lineage (chinese.c identical, master.c differs, same diamond-inherit weapon bug recurs); config has a stale "碧血残阳之豪侠晚歌" name field (confirmed NOT #71 duplicate, just copy-paste leftover); standard §15h fix + F_UNIQUE/F_BACKUP macro gaps + diamond-inherit fix; full registration flow verified with real name "秦风" reaching the actual game world; 94.6% lpcc pass; see libs/datangshuanglong/NOTES.md |
| 50 | 天下.tar.gz | tianxia | 40044 | done | 《天下》Beta, adm/obj/ layout (nested at raw/mud/tx/, archive also bundles a full MudOS driver source tree at raw/mud/MudOS/ which was correctly ignored); standard §15h fix doubled (is_chinese + a separate valid_chinese() whole-string check) + logind.lpc check_legal_name() byte-width fixes + disabled 2 stale checks in a check_config.lpc driver-version self-check inherited into simul_efun.lpc (§15r, new) + restored 5 never-defined simul_efuns (clr_ansi, chinese_number, changed_match_path, db_affected, query_bandwide, query_shadowed -- §15b additions, new) + fixed a genuine query_shadowing() efun-arity bug in bleeding.lpc + fixed 3 files' lossy-iconv-merged text-block closing tags (new Encoding gotcha) + fixed a 45-occurrence §8h Greek-table typo + fixed a 12-file duplicate `inherit ROOM;` bug + proactive dns_master preload exclusion (§15p); query_shadowed() fix was the single most impactful -- was silently blocking the player body class from compiling, breaking character creation right after Chinese name/password were accepted; full registration flow verified end-to-end incl. real name "秦风" reaching the actual game world; 99.1% lpcc pass; see libs/tianxia/NOTES.md |
| 51 | 天下无雪.rar | tianxiawuxue | 40045 | done | adm/obj/ layout (nested at raw/mud/world/); standard §15h fix + upgraded valid_override to 3-arg (§14) + fixed a stray-brace typo cluster in d/kaifeng/ground0-3.lpc + proactive dns_master preload exclusion (§15p); full registration flow verified end-to-end incl. real name "秦风" reaching the actual game world; 97.6% lpcc pass; see libs/tianxiawuxue/NOTES.md |
| 52 | 小雨西游.zip | xiaoyuxiyou | 40046 | done | self-IDs as 小雨西游 but live banner says 小雨西游Ⅱ v3.0 (2013 snapshot); chinese.lpc byte-identical to unknownlib20150716(#3), same engine lineage different site snapshot; standard §15h fix + proactive get_include_path() insurance; no dns_master in preload (nothing to exclude); one corrupted quest file hung lpcc, renamed .corrupted-orig; full registration flow verified with 3 real Chinese names incl. one reaching an actual room + look/quit, dup-id rejection also confirmed working; 99.0% lpcc pass; see libs/xiaoyuxiyou/NOTES.md |
| 53 | 新狂想空间II.rar | xinkuangxiangkongjian2 | 40047 | done | actually named plain "狂想空间" (config/banner) -- "新"/"II" are collector-site additions, not the game's own name; Taiwan release by wizard wade (Oct 2002), genuine ES II lineage (same as es1_win/esI/xkx2001/rzrmud/beimeixiakexing2001); standard §15h fix + proactive dns_master preload exclusion (§15p) + NEW absolute-path angle-bracket #include bug (359 files, driver's resolver never handles absolute names in <>, was silently sending new characters into VOID_OB instead of the real start room -- highest-impact fix) + NEW "inherit after global vars" ordering bug (74 files) + NEW disallowed-`..`-relative-include bug (54 files, incl. reconstructing a small missing cold.h from sibling-zone style, not fabricated content); full registration flow verified twice independently with real Chinese names "秦风二"/"秦风三", both reaching the actual starting room, second run had zero debug.log output; 95.9% lpcc pass (up from 94.8% pre-sweep-fixes); see libs/xinkuangxiangkongjian2/NOTES.md |
| 54 | 月影奇缘.rar | yueyingqiyuan | 40048 | done | ★月影奇缘★, ES II lineage (adm/obj/{master,simul_efun} layout, master.c credits "Lil"/"Annihilator" like es1_win/esI/xkx2001/rzrmud/xo family); standard §15h fix + proactive dns_master preload exclusion (§15p) + upgraded valid_override to 3-arg (§14) + NEW message.lpc tell_room() bug (578 call sites passed raw int 0 as message()'s 4th arg, driver rejects it, fixed once at the shared root); an intermittent unreproduced crash seen twice early in testing (no trace anywhere, not reproduced across 8+ later clean runs) flagged for future investigation, not blocking; full registration flow verified end-to-end incl. real name "秦风终" reaching an actual starting room; 97.1% lpcc pass; see libs/yueyingqiyuan/NOTES.md |
| 55 | 未明空间.rar | weimingkongjian | 40049 | done | self-IDs as 未明空间/"wmkj" (README, author 龙宝宝/xiha, 2001) but live banner shows "江湖风云之夕阳再现" -- chinese.c byte-identical to xiyangzaixian_fengkuang(#46), master/logind/securityd differ, a related-but-distinct fork; standard §15h fix (chinese.lpc + logind.lpc + named.lpc, latter turned out dead code) + proactive dns_master preload exclusion (§15p, CONFIG_DIR=/adm/etc/ confirmed as the live path, a stray unused adm/etcc/preload copy left dns_master active but is never read) + new message_combatd gap (aliased to message_vision) + PEN->SWORD copy-paste inherit fix + several pre-existing typos incl. a large unquoted-string cluster in d/city/sj.lpc; full registration flow verified twice independently across two driver sessions with real Chinese names "秦风" and "林风", both reaching different actual start rooms; 95.4% lpcc pass; see libs/weimingkongjian/NOTES.md |
| 56 | 梦幻西游2002版.rar | menghuanxiyou2002 | 40050 | done | same 2002-era codebase as mhxy(#19) -- confirmed via diff (14561/14563 files identical incl. master.c/chinese.c byte-identical, only logind.c banner branding + wizlist state differ), all fixes ported directly rather than rediscovered; standard §15h fix + §8h convertd.lpc typo (45x) + missing /u/feizei/log file fix + proactive dns_master preload exclusion (§15p); full registration flow verified end-to-end incl. real name "秦风" reaching gift-allocation/game-world welcome, confirmed via saved data files too; 97.3% lpcc pass (matches #19); see libs/menghuanxiyou2002/NOTES.md |
| 57 | 模拟华附.zip | moniHuafu | 40051 | done | 模拟华附 (华南师大附中 high-school setting, author 阿飞/Jjgod, 2000), 风云3 engine lineage (same as zzfy/fy2/fy2005/fengyun434); standard §15h fix + proactive dns_master preload exclusion (§15p) + upgraded valid_override to 3-arg (§14) + new uptime.lpc unguarded write(read_file()) crash killing every connection (LASTCRASH path) + reverted a static/->nosave sed collateral hit on 10 files' "static/CRASHES"-style string literals (orphaned real seed data, restored) + neutralized a dormant "phone-home license check" self-destruct function in securityd.lpc (confirmed unreachable, disabled as insurance); full registration flow verified incl. real name "秦风" reaching an actual game room, re-login/restore also verified in a second session; 98.7% lpcc pass; see libs/moniHuafu/NOTES.md |
| 58 | 武汉站.rar | wuhanzhan | 40052 | done | self-IDs as 大话西游 (A Chinese Odyssey) -- "武汉站"/archive title is just the collector site's label ("楚天热线"/"湖北省襄樊大话西游站"); ES II lineage (same family as es1_win/esI/xkx2001/rzrmud/xo/beimeixiakexing2001/xinkuangxiangkongjian2/yueyingqiyuan), distinct codebase within it; standard §15h fix + proactive dns_master preload exclusion (§15p) + §14 valid_override 3-arg + §15s message()-wrapper fix + §8h convertd.lpc typo (45x, largest count seen) + NEW log_error() spam bug (driver funnels every compile WARNING through the same APPLY_LOG_ERROR path shown to every non-wizard player, not just real errors -- gated on absence of "warning:" in the message) + hardened error_handler() with a permanent /log/RUNTIME_ERRORS write since its old "falls through to debug.log" assumption doesn't hold on this driver + 19 files missing #include <ansi.h> while using HIW/NOR color macros; full registration flow verified twice in one continuous connection each with real names "秦风"/"秦风三"/"秦风五"/"秦风终" reaching the actual starting room, zero spam/errors on the final clean run; 96.3% lpcc pass (9528/9898); see libs/wuhanzhan/NOTES.md |
| 59 | 江湖风云.rar | jianghufengyun | 40053 | done | dup: 江湖风云 (1).rar; config self-names "江湖风云单机"; 夕阳再现 lineage confirmed via md5sum three-way against xiyangzaixian_fengkuang(#46)/weimingkongjian(#55) -- chinese.c identical across all 3, master.c matches #55, securityd.c matches #46, likely close to their common ancestor; ported #46/#55's proven §15h fix + proactive dns_master preload exclusion (§15p) directly; 18 pre-existing content bugs fixed via lpcc sweep (heredoc-merge typos, missing quotes, iconv-eaten-newline, PEN->SWORD copy-paste, etc, several literally the same files/bugs already seen in weimingkongjian, confirming shared world content); full registration flow verified 3 times with real Chinese names "秦风三"/"林风"/"秦风四", each reaching a different actual room; 98.6% lpcc pass; see libs/jianghufengyun/NOTES.md |
| 60 | 泥潭III测试版.rar | nitan_ceshi | 40054 | done | self-IDs as "nitan.3", live banner "《终极魔界》"; confirmed NT/nitan/Lonely engine family via diff against nitan170911(#21)/nitan6(#22) but an earlier snapshot (adm/single/ not adm/kernel/) that PREDATES the §15 dbase architecture bug entirely (feature/dbase.c already has real local set/query/delete, zero efun::set/query/delete call sites) -- no MySQL backend needed either, unlike nitan170911; standard §15h fix (chinese/logind/named) + §14/§15o/§15p + new LONELY_IMPROVED-gated efun:: family (6 sites flipped to existing fallback, 9 count_* bignum functions restored via atoi() not a bare (int) cast which doesn't parse strings) + disconnected rmtree.lpc wired in + §15s message() 4th-arg fix (was breaking the mudlib's own error handler) + is_killing(ob) vs is_killing(ob->query("id")) typo blocking the player body class from compiling (same shape as tianxia's query_shadowed finding) + new .c->.lpc rename-fallout variant (hardcoded [0..<3] extension-strip needing [0..<5] in eventd/storyd.lpc); full registration flow verified in 3 independent runs incl. real single-character surnames/names "秦风"/"林风" reaching the actual starting room, plus a returning-player admin-password-reset login path also confirmed; lpcc sweep skipped (13,497 files, risky size per §6b, relied on boot+3x interactive test instead); see libs/nitan_ceshi/NOTES.md |
| 61 | 泥潭三.rar | nitan_san | 40055 | done | sibling of nitan_ceshi(#60) -- same NT/nitan/Lonely adm/single/ layout branch, predates §15's dbase bug (feature/dbase.c has real local set/query/delete, zero efun::set/query/delete sites), no MySQL backend needed; independently found nearly the identical fix list as #60 (strong cross-confirmation): standard §15h fix + §15n/§15o/§15p + LONELY_IMPROVED efun:: fallback flips + wrote a from-scratch bignum.lpc replacing nonexistent efun::count() (~230 call sites) + §15f bare-array bug (incl. a new function-parameter variant in ntefun.lpc) + §15s message() fix + fixed inherit/misc/quest.lpc's set_information() signature at the shared root (resolved 9 quest-template failures at once, vs #60 which left it as documented noise) + is_killing() type typo blocking the player body class + eventd/storyd rename-width bug; full registration flow verified across multiple runs with real single-character Chinese names (秦风/秦岭/秦淮), each reaching an actual room, dup-name rejection and quit-abort also confirmed working; lpcc sweep skipped (13,559 files, mega-lib bracket + concurrent host memory pressure); see libs/nitan_san/NOTES.md |
| 62 | 浴血重生MUD.rar | yuxuechongsheng | 40056 | done | self-IDs as 1.YXCS/浴血重生; hybrid lineage (chinesed.lpc credits ES II family, feature/dbase.lpc/named.lpc credit "Lonely" of the nitan family) but confirmed §15 dbase bug does NOT apply (real local set/query/delete already present); NEW `#define nosave static`-guarded-by-undefined-macro bug (convert_lib.sh's blanket sed half-fixed it but broke `protected`'s semantics, rewrote both to pass through unchanged) + standard §15h/§14/§15w/§8e/§15s fixes + PEN->SWORD copy-paste inherit fix + missing SSERVER/F_NOCLONE macro aliases + restored add_light()/keep_heart_beat() stubs + biggest fix: an entire "international challenger" subsystem had been silently dropped from feature/attack.lpc but was still called by 9+ files, restored verbatim from feature/attack.bak; dns_master already commented out in raw archive; full registration flow verified 3 times incl. real names "秦风"/"林风" reaching an actual starting room ("世外桃源"), existing-user login + 3-wrong-password disconnect also confirmed; 98.0% lpcc pass; see libs/yuxuechongsheng/NOTES.md |
| 63 | 海洋II 2010 正式无错完整版下载.rar | haiyang2 | 40057 | done | dup: "...(1).rar"; self-IDs as 海洋II, live sub-brand "星月传奇", ES II lineage (same family as es1_win/esI/xkx2001/rzrmud/xo/beimeixiakexing2001/xinkuangxiangkongjian2/yueyingqiyuan/wuhanzhan/yanhuangwuhun); large lib (26,182 files) but full lpcc sweep completed fine with monitoring; standard §15h fix + §14 + §8d/§15o get_include_path + §15n securd.lpc ACL func-allowlist + preload securityd->securd typo fix (2 files) + new §15p manifestation (DNS_MASTER never in preload but called inline from gb_big5()'s intermud display + a Mud_name() macro, rewritten to avoid dns_master.lpc entirely) + securd.lpc get_status() crash on euid-less objects (every quest NPC clone at create() time) + missing !stringp(str) guard in clone/user/login.lpc's receive_message() killing every fresh connection at the very first banner (found via interactive testing) + §15s tell_room/shout fix + one corrupted securd.o save-data file (GBK run in channel_id, crashing restore() silently under catch()) fixed directly; full registration flow verified twice incl. real names "秦风"/"秦岭" reaching the actual game world, second run had zero bad-argument/denied/crash patterns in debug.log; 96.4% lpcc pass (25242/26183); see libs/haiyang2/NOTES.md |
| 64 | 消失的亞特蘭提斯MUD破解版.zip | atlantis | | not mudlib | confirmed: Merc 2.1/DikuMUD-derivative compiled C server ("EnvyMud" lineage per envyb.exe/play.bat scaffold) -- src/act_*.c/comm.c/db.c/fight.c/handler.c (canonical Merc names), area/*.are Diku world-data files, prebuilt merc.exe+cygwin1.dll, zero `inherit` statements anywhere -- same category as 三国歪传(#31), skipped, see AGENTS.md's non-mudlib list |
| 65 | 火影.rar | huoying | 40059 | done | dup: 火影 (1).rar; self-IDs as 火影 (Naruto-themed, "Neolith 0.0.2" engine by Annihilator 2000, ES2 lineage same family as wuhanzhan/xinkuangxiangkongjian2/yueyingqiyuan); §4 recursion-guard fix (existing catch() wasn't sufficient, recursion re-enters via a new outer call) + standard §15h fix incl. a fullwidth-space byte-vs-char equality variant + §15w log_error() warning-spam gate + NEW hardcoded MUD_PORT=8000 mismatch silently rejecting every connection at the TCP layer despite a clean boot log (fixed to 40059) + NEW mixed-GBK+BIG5 config.cfg (BIG5 bytes decode to valid-but-wrong mojibake under GB18030, undetectable by convert_lib.sh's lossy-conversion check, fixed 4 lines manually) + one pre-existing typo; full registration flow verified with real names "秦风"/"王小虎" both reaching an actual starting room ("巫师神殿"), reconnect/quit save-restore lifecycle also confirmed; 98.1% lpcc pass; dns_master already commented out in the raw archive itself, nothing to fix there; see libs/huoying/NOTES.md |
| 66 | 炎黄武魂_64bit.rar | yanhuangwuhun | 40060 | done | self-IDs as 「武林群侠传」之炎黄武魂Ⅱ; ES II lineage (same family as es1_win/esI/xkx2001/rzrmud/xo/beimeixiakexing2001/xinkuangxiangkongjian2/yueyingqiyuan/wuhanzhan), master.lpc header traces the full chain to "Linux@lxtx for yh 2003.3"; "64bit" in the name refers to a bundled prebuilt Cygwin driver, ignored; standard §15h fix (3 files) + §15n securityd allowlist + §14 valid_override + NEW §15s/§8b interaction (message.lpc's own tell_room/shout/say called bare `message()` before its own override was textually defined, compiler silently bound straight to the real efun bypassing the exclude-arg guard entirely -- fixed with a varargs forward declaration, crashed 9 preload daemons) + nitan-family [0..<3]->[0..<5] rename-width bug recurring in 3 files (not a nitan lineage lib, same bug independently) + §3 counterexample (105 static/nosave string-literal collisions across 60 files reverted) + several pre-existing content typos/missing macros; dns_master never in preload at all, nothing to exclude; full registration flow verified 3 times with real names 秦风/秦岭/秦淮, each reaching the actual starting room (世外桃源), final run had zero debug.log errors; 99.92% lpcc pass (10747/10756); see libs/yanhuangwuhun/NOTES.md |
| 67 | 炎黄英雄史.rar | yanhuangyingxiongshi | 40061 | done | config self-names 炎黄英雄传 but live banner says 炎黄英雄史 (matching archive title); confirmed genuine close-cousin sibling of yanhuangwuhun(#66)'s same "yh 2003" ES II-derivative codebase via diff (identical master.lpc author credit, byte-identical is_chinese/message.lpc bugs), independent gameplay content not a duplicate; ported #66's proven fixes directly (§15h/§14/§15n/§15aa/§15s/§15p/§15w) + §3 counterexample revert (104 occurrences/64 files) + NEW is_killing() type-mismatch recurrence blocking the player body class (2 files) + nitan-family [0..<3]->[0..<5] rename-width bug (not itself nitan lineage) + a new questd11.lpc split-identifier/string corruption pattern (9 sites, confirmed pre-existing) + quest set_information() signature fix (7 files at once); full registration flow verified 3 times incl. real names 秦岭/秦淮 plus a returning-user login, all reaching the actual starting room (世外桃源); 99.81% lpcc pass (10980/11001); one harmless versiond.lpc socket_bind() config-mismatch error noted (confirmed non-fatal, not yet catalogued in AGENTS.md); see libs/yanhuangyingxiongshi/NOTES.md |
| 68 | 炎龙封印-笑傲江湖3阿飞站.rar | yanlongfengyin_xiaoao3 | 40062 | done | self-IDs as 炎龙封印, live banner「夕阳再现」之「笑傲江湖」; genuine shared "XYZX"/夕阳再现 lineage with xiyangzaixian3(#48) via near-verbatim master.lpc matches, but a substantially heavier independent fork (1.5-2x larger, credited to "阿飞" further-modifying "碎梦"'s branch) -- only is_chinese ported directly, everything else freshly discovered; standard §15h fix + §14/§8d-§15o/§15n/§15w/§15s fixes + §3 counterexample revert (13 files) + neutralized a nosave/protected/private shim bug (would have wrongly aliased private->protected) + NEW 32-file double-leading-slash carry_object() typo (likely root cause of a pre-fix segfault a few minutes into first boot, correlated with the exact broken NPCs) + 4-file lossy-conversion-eaten-newline bug silently deleting NPC names (set_name() calls) + 3 heredoc-closing-tag newline drops + one call_out() unquoted-identifier typo; dns_master already commented out in raw archive; full registration flow verified twice (crash-free 6.5+ min post-fix) incl. real names 秦风(male, 悦来客栈)/秦岭(female, different room w/ correct gender-specific gift); 99.95% lpcc pass (16173/16181); see libs/yanlongfengyin_xiaoao3/NOTES.md |
| 69 | 狂想空间.rar | kuangxiangkongjian | 40063 | done | dup: 狂想空间 (1).rar; NOT a duplicate of xinkuangxiangkongjian2(#53) despite both self-identifying as "狂想空间" -- confirmed distinct via diff (different file counts/sizes/mtimes, #53's registration flow has an extra email step this one lacks), but same ES II lineage + same 小熊泥苑 distribution site, an independently-circulated earlier snapshot (own bugfix readme dated Dec 2002); ported #53's proven fixes directly: standard §15h fix + §15t all 3 sub-bugs (172 absolute-path angle-bracket includes, 94 disallowed ..-relative includes incl. reconstructing 2 genuinely-missing headers, 187-file inherit-after-globals cluster) + get_include_path + §3 counterexample revert (31 files) + §15b is_killing() typo (4-file cascade) + §15w log_error fix + NEW bare SAVE_EXTENSION vs real __SAVE_EXTENSION__ constant bug (11 files, worth cataloging); full registration flow verified twice with real names "秦风"/"秦风二" reaching an actual starting room, zero debug.log errors; 95.0% lpcc pass (6004/6323, up from 91.8%); see libs/kuangxiangkongjian/NOTES.md |
| 70 | 玄剑录.rar | xuanjianlu | 40064 | done | distributed via 小熊泥苑 (same site as #35/#36); chinese.c/master.c byte-identical to xkx2001(#25)/beimeixiakexing2001(#45), ES II/XKX engine family, distinct game-world content (明教/昆仑/侠客岛); standard §15h fix (incl. removing a corrupting name[j]+=128 "auto-correct" hack) + §15p/§14/§8d-§15o/§8e/§15c fixes + NEW `private nomask command_hook` bug (private gets demoted to DECL_HIDDEN once inherited, add_action silently refused to call it, breaking EVERY post-login command incl. `look` with zero visible error -- same bug present but never caught in beimeixiakexing2001 since testing there stopped at the password prompt; recommend new AGENTS.md catalog entry) + securityd.lpc ACL lazy-init fix (no seed save data shipped) + §3 counterexample (23 files, incl. rebuilding an accidentally-deleted work/log/ seed subtree) + several lpcc-sweep content fixes (misplaced shared header, missing HALBERD macro, iconv-eaten-newline merges); full registration+post-login-command flow verified 3 times with real names 秦岭/林风/秦风, incl. look/score/i/quit all working correctly; final run had zero debug.log errors; 96.6% lpcc pass (10244/10605); see libs/xuanjianlu/NOTES.md |
| 71 | 碧血残阳之豪侠晚歌.rar | bixiecanyang | 40065 | done | self-IDs exactly as archive title; own readme credits "夕阳再现-江湖风云2-风云再起" -- confirmed genuine member of the 夕阳再现 lineage (#46/#47/#55/#59), chinese.c byte-identical across all 5, securityd.c matches xiyangzaixian_fengyun2(#47) specifically as closest sibling; confirmed NOT related to datangshuanglong(#49) in either direction (differing chinese.c/master.c/logind.c) -- found a SECOND piece of evidence for #49's stale-copy-paste theory: its raw config file is literally named `config.bxcy`, the template extended to the filename itself; standard §15h fix + §15z protected-shim collision (5 files) + §3 counterexample revert (22 files) + §14/§15p/§15s fixes + new message_combatd() alias (§15aa-shaped ordering gotcha, first attempt broke the whole simul_efun compile until reordered after message_vision) + 19 individual pre-existing content typos fixed; confirmed NOT needed: §15x (hardcoded TOMUD_PORT=8888 only sets a cosmetic flag, never rejects connections) + a §15q-shaped client-version gate confirmed structurally unreachable on our assigned port; full registration flow verified twice incl. real names 秦风(male, 武庙 start room)/林风(female, 北疆小镇, correct female honorific), zero real debug.log errors either time; 98.6% lpcc pass (13374/13559, up from 98.5%); see libs/bixiecanyang/NOTES.md |
| 72 | 神州.rar | shenzhou | 40066 | done | self-IDs as 【神州】; ES II lineage (same family as es1_win/esI/xkx2001/rzrmud/xo/beimeixiakexing2001/xinkuangxiangkongjian2/yueyingqiyuan/wuhanzhan/haiyang2/yanhuangwuhun/yanhuangyingxiongshi/xuanjianlu) with a ShenZhou-specific layer; standard §15h/§14/§8d-§15o/§15ae/§8e/§15s/§15n fixes + NEW log_error() bug (unconditional wizardp(this_player(1)) lazily loaded securityd mid-compile, crashing every boot on the first preloaded daemon before securityd existed, + a "Warning:"/"warning:" case-sensitivity bug in the same function) + §3 counterexample revert (52 files) + is_killing() typo (5 files) + stale corrupted data/npc/map.o moved aside + pre-existing PUA-character/octal-escape corruption in several files reconstructed from an uncorrupted sibling copy + missing auto_perform.h shared header (7 files); full registration + post-login-command flow verified twice with real names 秦风(male)/林风(female), look/score/i/quit all working, zero debug.log errors either session -- confirms the command_hook fix (already correctly `nomask` without `private` here) genuinely works; 97.95% lpcc pass (12481/12742, up from 97.79%); see libs/shenzhou/NOTES.md |
| 73 | 神魔20190924版本.rar | shenmo | 40067 | done | self-IDs as 西游记之神魔传说 (root dir xyj/); ES II/Neolith 0.0.2 lineage, same large family as es1_win/esI/xkx2001/rzrmud/beimeixiakexing2001/xinkuangxiangkongjian2/yueyingqiyuan/wuhanzhan/yanhuangwuhun/haiyang2/kuangxiangkongjian/huoying; long-lived multi-author lib (1994-2013), mega-lib (33,199 .lpc files, 740MB); standard §15h fix (chinese/named/logind) + §8d/§15o get_include_path (1706 same-dir includes) + §3 counterexample revert (82 files) + §15w fix + NEW uppercase `.C` extension (363 files, convert_lib.sh's glob missed them, manually renamed -- worth adding to AGENTS.md); §15ae explicitly checked hardest per new policy -- already independently fixed in this lib's own source (`private` commented out); full registration + post-login-command flow verified twice with real name 秦风六, look/score/quit all working correctly reaching actual start room 南城客栈; full lpcc sweep skipped per §6b mega-lib policy, individual per-file lpcc checks on critical path files passed clean; see libs/shenmo/NOTES.md |
| 74 | 笑傲江湖II.rar | xiaoaojianghu2 | 40068 | done | NOT nitan-family despite sharing the "笑傲江湖" title with nitan6(#22) -- confirmed TMI-2/ES2/Falcon "XO mudlib" lineage instead, same family as xo(#28)/xo_final(#29) but a distinct non-duplicate 2003-dated snapshot; F_DBASE confirmed real per-object storage, §15 dbase bug definitively does not apply; standard §15h fix + §4 reentrancy guard (ported from xo) + NEW combatd.lpc all-cases-commented-out switch bug + NEW high-impact __OLD_ED__ driver-build gap (ed_start/ed_cmd/query_ed_mode don't exist, broke editor.lpc inherited into player-body class + message.lpc's write_prompt(), silently killing make_body() mid-registration with zero visible error -- rewrote to use the old ed() efun) + NEW hardest-to-diagnose bug: missing /log/nosave/ directory caused an uncaught write_file() error to silently abort the entire post-gender registration chain with zero visible error anywhere except the mudlib's own /log/runtime/secure (not debug.log) -- created the dir + wrapped log_file() in catch() + §15i-shaped comment-eats-if/else-chain bug (2 files) + a few pre-existing typos; §15ae confirmed clean both by code read and empirically (score works); full registration + post-login-command flow verified with real name 秦风, score produces full correct character sheet, look hits a genuine pre-existing missing-room content gap (documented not fixed), quit's 10-point save gate works correctly; 97.65% lpcc pass pre-final-fixes (4242/4344); 5 new bug classes flagged for AGENTS.md; see libs/xiaoaojianghu2/NOTES.md |
| 75 | 笑傲江湖XO .rar | xiaoaojianghu_xo | 40069 | done | same TMI-2/ES2/Falcon lineage as xo(#28)/xo_final(#29) confirmed via identical master.lpc header credit, but a third independently-evolved snapshot (4922 files, between xo's/xo_final's sizes, own hybrid secure/obj/ layout) -- core files closer to xo by diff-size but game/skill content closer to xo_final (several identical corrupted skill files + a hami.npc header reconstructed verbatim from xo_final's byte-identical hami.h); standard §4/§15h/§15g fixes (incl. a NEW finding: `class Action` never defined anywhere, ported from xo's include/action.h) + 3 new §8g-variant missing-macro cascades (GROUP_TASK 42 files, EXERT_DIR 6 files, ZUOJI 3 files) + a class task field-name mismatch (45-file cascade) + missing hami.npc + missing armor.h include + undefined LIB_ROOM base class + §3 counterexample (14 files) + §15w fix + ~12 individual pre-existing typos; full registration + post-login-command flow verified 3 times with real names 秦风/秦岭/秦风三 each reaching different randomly-selected start rooms, look/score/i all working per §15ae; 97.6% lpcc pass (4202/4304, up from 95.9%); see libs/xiaoaojianghu_xo/NOTES.md |
| 76 | 笑傲江湖服务端+客户端.rar | xiaoaojianghu_client | 40070 | done | despite the name, confirmed genuine mudlib not client+server bundle -- "server+client" refers to bundling 2 wire protocols (telnet/ZMUD + TOMUD menu-client handshake) on different ports, not a separate client program; NOT related to nitan6/xo/xo_final despite "笑傲江湖" title -- confirmed genuine independent fork of the 夕阳再现 lineage (#46/#47/#48/#55/#59/#68/#71) via readme credit + md5sum (chinesed.lpc matches 4 siblings, chinese.lpc matches bixiecanyang specifically); standard §15h fix + §15z (3 files) + §3 counterexample (7 files) + §14/§15s(+new shout() variant)/§15ac(3 files)/§15ab/§15w fixes + new message_combatd/message_sort aliases + highest-impact: missing shared d/city/obj/cloth.lpc (referenced by 47 NPC files across a dozen zones) restored verbatim from an identical sibling template + 5 iconv-eaten-newline fixes; §15q hidden client-version gate IS live here (get_version unconditional first callback, unlike bixiecanyang); full registration + post-login-command flow verified twice with real names 秦风(male,铁枪庙)/林风(female,武庙 w/ correct gender-specific flavor text), score also tested per §15ae, zero debug.log errors; 97.59% lpcc pass (11138/11413, up from 97.06%); see libs/xiaoaojianghu_client/NOTES.md |
| 77 | 紫藤站.rar | zitengzhan | 40071 | done | full name 大唐西游之紫藤站/【紫藤西游】; ES II lineage (same family as es1_win/xkx2001/rzrmud/beimeixiakexing2001/wuhanzhan/yanhuangwuhun/haiyang2/shenzhou/shenmo); NEW finding worth AGENTS.md: 35 extensionless-file/same-named-.c-backup pairs where the driver's extension-less path resolution (.lpc-then-.c, never literal zero-ext) silently makes the .c backup authoritative post-rename, not the file the author was actually editing -- direction inconsistent archive-wide, each pair had to be diffed individually, found 2 real bugs this way (dead-code stray return making log_error() a permanent no-op + an old force-load boot-spam trick) that were absent from the true master file; standard §15h fix (3 bound sites) + §15z shim neutralized + §3 counterexample (68 files) + §14/§8d-§15o/§15w/§8h(45x)/§15t/§15ac(2 files) fixes + uppercase .C rename (183 files) + a multi-char-literal '25'->'9' typo blocking the entire preload chain + 2 BIG5-encoded files fixed via iconv; full registration + post-login-command flow verified with real name 秦汉 reaching an actual starting room (南城客栈), score/quit both working, zero errors across 4 test connections; 96.63% lpcc pass (14150/14643); see libs/zitengzhan/NOTES.md |
| 78 | 终极地狱.rar | | | not started | |
| 79 | 终极地狱之爱若幽兰1.166正式版.rar | zhongjidiyu_airuoyoulan | 40073 | done | self-IDs as "地狱泥潭---爱若幽兰"; ES II -> XKX -> "hell" fork (author Doing Lu), same family as es1_win/esI/xkx2001/rzrmud/shenzhou/shenmo -- NOT nitan-lineage despite "泥潭" in the display name; bundled Windows GUI client + illustrative-example docs correctly ignored; standard §15h fix (deep named.lpc + logind.lpc) + §14/§8d-§15o/§15n/§15p/§15w fixes + §15ae command_hook `private` bug (critical, would have silently broken every post-login command) + §3 counterexample revert (51 files) + §2 rename-width bug (5 sites) + §15b is_killing() typos (2 sites, one in the player-body class) + new §8g-shaped quest.lpc set_information() shared-root fix (7 files at once) + 4 pre-existing content typos found via lpcc sweep; full registration + post-login-command flow verified twice with real names 秦风(male)/秦岭(female), both reaching 世外桃源 with correct gender-specific gear, look/score/i/quit all working, zero new debug.log errors; 99.81% lpcc pass (7289/7303, up from 7272/7303); flagged for cross-check against sibling #78/#80 once all three land; see libs/zhongjidiyu_airuoyoulan/NOTES.md |
| 80 | 终极地狱-指间mud版服务端.rar | | | not started | |
| 81 | 西游记2003.rar | xiyouji2003 | 40075 | done | self-IDs as 西游记[光辉岁月]; master.c 486/486 lines with only 3 trivial diffs against fluffos_xiyou2000(#15), same ES-II/"Lil"/"Annihilator" root with a later maintainer credit, NOT the mhxy/menghuanxiyou2002/shenmo branch despite shared ancient zone names indicating a much older common root; standard §15h fix (re-derived fresh, different implementation shape than any sibling) + §8h convertd Greek table (ported verbatim from mhxy/fluffos_xiyou2000) + §14/§8d-§15o/§15w/§15b/§15ac fixes + new §8g-variant missing CLUB/F_CLUB macros + §3 counterexample (17 files) + NEW dns-site-verification gate in logind.lpc calling shutdown(1) unconditionally once dns_master was excluded from preload (fixed to require find_object(DNS_MASTER) truthy first) + NEW missing /d/wiz/init gift room (mandatory post-registration move target, absent from archive, silently left new characters with no environment crashing every post-login command -- fixed with a load_object() guard falling back to START_ROOM); full registration + post-login-command flow verified across 3 runs (first exposed the /d/wiz/init bug via post-login failures, next two clean) incl. real names 秦岭(female)/林风(male), dup-name rejection also confirmed; 89.3% lpcc pass (2322/2599); see libs/xiyouji2003/NOTES.md |
| 82 | 西游记2006之 最终幻想.rar | | | not started | |
| 83 | 西游记450.rar | | | not started | |
| 84 | 西游记.rar | | | not started | |
| 85 | 西行战记.gz | | | not started | bare gzip of a tar, not .tar.gz named |
| 86 | 重出江湖.rar | | | not started | |
| 87 | 重出江湖WIN完全版.rar | | | not started | |
| 88 | 重出江湖完整源码linunx_2.71原版.rar | | | not started | |
| 89 | 重生的世界v1.0.1.rar | | | not started | |
| 90 | 金庸文字版.exe | | | not started | Windows self-extracting exe -- may not be an LPC mudlib at all, triage first |
| 91 | 金庸群侠传2008加强版.rar | | | not started | |
| 92 | 金庸群侠传2008版.rar | | | not started | |
| 93 | 金庸群侠传2008超豪华版.rar | | | not started | |
| 94 | 金庸群侠传2015版.rar | | | not started | |
| 95 | 铁血江湖.rar | | | not started | |
| 96 | 随缘洗剑录.rar | | | not started | |
| 97 | 风云III修订版 .rar | | | not started | dup: "...  (1).rar" |
| 98 | 风云III典藏版.rar | | | not started | dup: "...(1).rar" |
| 99 | 风云II (清华仿写版）.ZIP | | | not started | dup: "...(1).ZIP" |
| 100 | 魔幻世纪.rar | | | not started | |
| 101 | 魔法类的泥巴.rar | | | not started | |
| 102 | 龙云梦-炎龙封印-二进制版.rar | | | not started | "binary version" in name -- may not have source, triage |
| 103 | 龙云梦-炎龙封印源码版.rar | | | not started | "source version" in name -- prefer this over the binary one above |

## Non-mudlib triage items (see AGENTS.md)

- `eval.c` (stray file, not an archive)
- `金庸文字版.exe` / duplicate — confirm whether it's actually an LPC mudlib
  before spending conversion effort
- `西行战记.gz` — bare gzip, confirm contents
- `dw_fluffos_v1/v2/v3`, `fluffos(西游记2000).tar.gz` — names suggest these
  bundle a driver, not just a mudlib; check what's actually inside before
  assuming the standard pipeline applies
