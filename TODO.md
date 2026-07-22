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

Port assignments: sequential from 40001, recorded here so re-running
several libs at once never collides. **Next free port: 40021** (40001-40020
assigned; 40007 is ds386, deprioritized/partial). On mega-libs (tens of
thousands of files, the "nitan" family), skip the full `lpcc_check.sh`
sweep — it can OOM the host before finishing (see AGENTS.md §6b) — and
rely on the boot + interactive-connect test as the verification gate.

## Progress summary (updated as libs are finished)

- **POLICY (per user direction): deprioritize non-Chinese/English-language
  archives.** Focus on the Chinese wuxia/xianxia libs, which is the vast
  majority of this collection. If an archive turns out to be English
  (like ds386/Dead Souls), do the minimum to note what it is, don't sink
  deep debugging time into it -- move on to the next Chinese one.
- **Done: 19 / 100** (shanhaizhanshen, xingzhanyingxiong, unknownlib20150716
  [小雨西游II], bxsj [书剑天下], bxsj1 [书剑·经典], chidi [江湖I], ...,
  nitan170911 [仙剑奇侠传], nitan6 [笑傲江湖], rzrmud [大唐西游])
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
| 24 | TOMud_VC源代码.rar | | | not started | name suggests VC/Windows source, triage |
| 25 | xkx2001测试用老lib.zip | | | not started | |
| 26 | xlqy_new2007.rar | | | not started | |
| 27 | xlqy-解压看readme.rar | | | not started | |
| 28 | xo.zip | | | not started | |
| 29 | xo最终版1.2.rar | | | not started | |
| 30 | zzfy (full).rar | | | not started | |
| 31 | 三国歪传.rar | | | not started | |
| 32 | 世纪.zip | | | not started | |
| 33 | 东方故事二.rar | | | not started | dup: 东方故事二 (1).rar |
| 34 | 中华2.rar | | | not started | |
| 35 | 书剑2008.rar | | | not started | |
| 36 | 书剑天下.rar | | | not started | |
| 37 | 书剑飘零II .zip | | | not started | |
| 38 | 仙侣奇缘新版.rar | | | not started | |
| 39 | 仙侣情缘浙大版.rar | | | not started | |
| 40 | 仙剑传奇.rar | | | not started | |
| 41 | 侠客新传(2).rar | | | not started | |
| 42 | 侠客英雄传III 可用.zip | | | not started | |
| 43 | 侠客行100.rar | | | not started | |
| 44 | 侠客行III .rar | | | not started | |
| 45 | 北美侠客行2001.rar | | | not started | |
| 46 | 夕阳再现-疯狂江湖.rar | | | not started | dup: 夕阳再现-疯狂江湖(1).rar |
| 47 | 夕阳再现-风云再起2.rar | | | not started | |
| 48 | 夕阳再线III之炎龙封印.rar | | | not started | |
| 49 | 大唐双龙.rar | | | not started | |
| 50 | 天下.tar.gz | | | not started | |
| 51 | 天下无雪.rar | | | not started | |
| 52 | 小雨西游.zip | | | not started | |
| 53 | 新狂想空间II.rar | | | not started | |
| 54 | 月影奇缘.rar | | | not started | |
| 55 | 未明空间.rar | | | not started | |
| 56 | 梦幻西游2002版.rar | | | not started | |
| 57 | 模拟华附.zip | | | not started | |
| 58 | 武汉站.rar | | | not started | |
| 59 | 江湖风云.rar | | | not started | dup: 江湖风云 (1).rar |
| 60 | 泥潭III测试版.rar | | | not started | |
| 61 | 泥潭三.rar | | | not started | |
| 62 | 浴血重生MUD.rar | | | not started | |
| 63 | 海洋II 2010 正式无错完整版下载.rar | | | not started | dup: "...(1).rar" |
| 64 | 消失的亞特蘭提斯MUD破解版.zip | | | not started | Traditional Chinese -- try BIG5 if GB18030 conversion is lossy |
| 65 | 火影.rar | | | not started | dup: 火影 (1).rar |
| 66 | 炎黄武魂_64bit.rar | | | not started | |
| 67 | 炎黄英雄史.rar | | | not started | |
| 68 | 炎龙封印-笑傲江湖3阿飞站.rar | | | not started | |
| 69 | 狂想空间.rar | | | not started | dup: 狂想空间 (1).rar |
| 70 | 玄剑录.rar | | | not started | |
| 71 | 碧血残阳之豪侠晚歌.rar | | | not started | |
| 72 | 神州.rar | | | not started | |
| 73 | 神魔20190924版本.rar | | | not started | large (98MB) |
| 74 | 笑傲江湖II.rar | | | not started | |
| 75 | 笑傲江湖XO .rar | | | not started | |
| 76 | 笑傲江湖服务端+客户端.rar | | | not started | client+server bundle, triage |
| 77 | 紫藤站.rar | | | not started | large (40MB) |
| 78 | 终极地狱.rar | | | not started | |
| 79 | 终极地狱之爱若幽兰1.166正式版.rar | | | not started | |
| 80 | 终极地狱-指间mud版服务端.rar | | | not started | |
| 81 | 西游记2003.rar | | | not started | |
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
