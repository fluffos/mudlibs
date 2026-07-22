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
several libs at once never collides. **Next free port: 40003.**

## Progress summary (updated as libs are finished)

- **Done: 2 / 100** (shanhaizhanshen, xingzhanyingxiong)
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
- Fix catalog in `AGENTS.md` is up to §14 — read it before starting a new
  lib, most of what's there will recur.

| # | Archive | Slug | Port | Status | Notes |
|---|---|---|---|---|---|
| 1 | 山海战神.rar | shanhaizhanshen | 40001 | done | pilot lib; see libs/shanhaizhanshen/NOTES.md |
| 2 | 星战英雄.rar | xingzhanyingxiong | 40002 | done | 2nd pilot; found driver bug (AGENTS.md §8) + message_combatd mudlib bug; see libs/xingzhanyingxiong/NOTES.md |
| 3 | 20150716未知lib.zip | | | not started | |
| 4 | bxsj.rar | | | not started | |
| 5 | bxsj1.rar | | | not started | |
| 6 | chidi.rar | | | not started | |
| 7 | ds3.8.6.zip | | | not started | |
| 8 | dtsl.rar | | | not started | |
| 9 | dw_fluffos_v1.tar.gz | | | not started | likely a driver bundle, not a mudlib -- triage first |
| 10 | dw_fluffos_v2.zip | | | not started | likely a driver bundle, not a mudlib -- triage first |
| 11 | dw_fluffos_v3.zip | | | not started | likely a driver bundle, not a mudlib -- triage first |
| 12 | es1_win.rar | | | not started | |
| 13 | esI.rar | | | not started | |
| 14 | fengyun4-3-4.rar | | | not started | |
| 15 | fluffos(西游记2000).tar.gz | | | not started | likely a driver bundle, not a mudlib -- triage first |
| 16 | fy2005.rar | | | not started | |
| 17 | fy2.rar | | | not started | |
| 18 | LLMUD(大唐双龙)v_0.11版.rar | | | not started | |
| 19 | mhxy.rar | | | not started | |
| 20 | MUD侠客行2017完整版.zip | | | not started | |
| 21 | nitan170911.7z | | | not started | |
| 22 | nitan6.zip | | | not started | |
| 23 | rzrmud.20130220.tar.gz | | | not started | |
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
