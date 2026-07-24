# mudlibs — 91 restored classic Chinese LPC mudlibs, runnable natively and in the browser

This repository preserves and restores the golden age of the Chinese MUD
scene (mid-1990s to ~2015): **91 complete LPC mudlibs** — 侠客行, 笑傲江湖,
金庸群侠传, 西游记, 风云, 大唐双龙, 书剑天下, 东方故事, and dozens of
derivatives and forks — recovered from community archive dumps, transcoded
to UTF-8, and fixed to boot and play on the modern
[FluffOS](https://github.com/fluffos/fluffos) driver.

Every restored lib runs two ways:

- **Natively**: the real FluffOS driver, a real telnet port, exactly like
  hosting the game in 2002 — except on a 2020s driver with UTF-8 strings.
- **In the browser (the primary distribution channel)**: a WebAssembly
  build of FluffOS boots the whole game — driver, mudlib, virtual
  filesystem — inside a browser tab, no server needed. A GitHub Pages site
  built from this repo lets anyone click a game and start playing.

These are wuxia (武侠) and xianxia (仙侠) worlds: martial-arts sects,
Jin Yong novel characters, cultivation, reincarnation — plus a few
outliers (a GPLv2 Taiwanese life-simulation MUD, a Naruto-themed lib, a
high-school simulator). Nearly all gameplay text is Simplified Chinese;
one archive is BIG5 Traditional Chinese.

## Quick start — play in the browser

The GitHub Pages site (built by `.github/workflows/pages.yml`) hosts every
converted lib as a click-to-play page: it packs each `libs/<slug>/` tree
into an in-memory filesystem image, pairs it with the prebuilt WASM
FluffOS driver from the latest fluffos release, and generates an index
page from the per-lib READMEs (`scripts/gen_site_index.py`,
`scripts/wasm_status.json`).

To smoke-test a lib under WASM locally without a browser:

```
node scripts/wasm_client.js ~/src/fluffos/build-wasm/src libs/<slug> \
    --timeout 20 --idle 1.0 --send "" --send "look" --send "quit"
```

To verify a packed site bundle boots: `node scripts/wasm_boot_check.js
<site/slug> <site/_driver>`.

## Quick start — run natively

Requirements: a FluffOS driver built from current master (the WASM and
native builds come from the same source; see `AGENTS.md` for build notes).

```
cd libs/<slug>
~/src/fluffos/build-debug/src/driver config.fluffos
```

Each lib has its own port (see the table below, and the lib's
`config.fluffos`), so several can run at once. Connect with any
UTF-8-capable telnet client, or the bundled test client:

```
python3 scripts/mudclient.py 127.0.0.1 <port>
```

Then register a character — these games generally ask for an English login
id, then a real Chinese name (e.g. 秦风), then a password. Each lib's own
`README.md` documents its specific login flow quirks (hidden BIG5 prompts,
client-version gates, startup grace periods).

## Admin account (管理员账号)

Every lib is being seeded with a **standard local admin account** so you
can immediately use wizard commands (`update`, `goto`, `call`, etc.)
without archaeology into each lineage's wizard-registration mechanism:

- **Login id: `fluffos`  Password: `Mud@2026`**
- A small per-lib patch also **allows connections from `127.0.0.1`
  unconditionally** (short-circuiting IP ban lists, site-restriction
  daemons, and registration throttles), so local and WASM play is never
  blocked by circa-2000 site-gating aimed at other people's networks.
- Legacy **connection-time gates are bypassed** the same way: startup
  grace periods ("server still starting, come back in 30 seconds/5
  minutes") and per-IP anti-flood throttles no longer apply to loopback
  connections. In-game content timers (quit-retention windows, save
  gates) are untouched — those are game design, not hosting protection.
- If a lib's own id/name rules force a different admin id or name, the
  exception is documented in that lib's `README.md` under
  「管理员账号 / Admin account」.

**If you host any of these games on a real network, change this password
first** — it is a published default, deliberately identical across all 91
libs for local convenience, and grants full in-game wizard/admin power
(including file read/write inside the mudlib).

## The collection — numbering, lineage, and status

Each **unique game/codebase** has a sequential number (`001`–`058`).
Confirmed derivatives — later snapshots, rebrands, site builds, and close
forks of the *same* codebase — share the base number with a `-1`/`-2`/`-3`
suffix (e.g. `031` 金庸群侠传2008加强版, `031-4` its 侠客行三 rebrand).
Lineage was established by actually diffing core files (`master.c`,
`chinese.c`, `logind.c`) across archives — similar Chinese titles alone
turned out to be a *very* unreliable signal, in both directions. Numbers
`9xx` are archives that turned out not to be LPC mudlibs at all (DikuMUD/
Merc C servers, a Windows mud client, compiled-binary-only releases) or
deliberately-deprioritized English libs.

The same mapping is machine-readable in `lib_numbering.json`, and the raw
files under `archives/` are named `NNN[-M]_<slug>_<original-name>.<ext>` —
the original archive filename is preserved verbatim inside the new name so
the provenance reference stays intact.

WASM status values: **playable** = full registration + gameplay verified
in the WASM harness; **limited** = boots under WASM but login is blocked
by a known driver-side gap (usually the `query_ip_number()` bug — see
`AGENTS.md`; most of these are expected to clear once the in-progress
driver fix lands and the loopback-allow patches roll out); **no-boot** =
does not boot under WASM yet.

<!-- BEGIN NUMBERING TABLE (generated from lib_numbering.json) -->
| # | Slug | Game | Original archive | Port | WASM |
|---|---|---|---|---|---|
| 001 | `shanhaizhanshen` | 山海战神 | `山海战神.rar` | 40001 | WASM playable |
| 002 | `xingzhanyingxiong` | 星战英雄 | `星战英雄.rar` | 40002 | WASM playable |
| 003 | `unknownlib20150716` | 小雨西游Ⅱ (Xiaoyu Xiyou II) | `20150716未知lib.zip` | 40003 | WASM limited |
| 003-1 | `xiaoyuxiyou` | 小雨西游 | `小雨西游.zip` | 40046 | WASM limited |
| 004 | `bxsj` | 书剑天下 (ShuJian MUD) | `bxsj.rar` | 40004 | WASM limited |
| 004-1 | `bxsj1` | 书剑·经典 (ShuJian Classic) | `bxsj1.rar` | 40005 | WASM limited |
| 004-2 | `jinyongwenzi` | 书剑2002 | `金庸文字版.exe` | 40083 | WASM playable |
| 005 | `chidi` | 江湖 I (Jianghu I) | `chidi.rar` | 40006 | WASM limited |
| 006 | `ds386` | Dead Souls 3.8.6 | `ds3.8.6.zip` | 40007 | partial (native only) |
| 007 | `dtsl` | 大唐双龙传 (Twin Dragons of the Tang Dynasty) | `dtsl.rar` | 40008 | WASM playable |
| 007-1 | `llmud_datangshuanglong` | 大唐双龙传（LLMUD） | `LLMUD(大唐双龙)v_0.11版.rar` | 40015 | WASM playable |
| 007-2 | `datangshuanglong` | 大唐双龙 (DaTangShuangLong) | `大唐双龙.rar` | 40043 | WASM playable |
| 008 | `es1_win` | 东方故事（蓝天） — es1_win | `es1_win.rar` | 40009 | WASM playable |
| 008-1 | `esI` | 东方故事 — esI（"屠龙之战"） | `esI.rar` | 40010 | WASM playable |
| 009 | `fengyun434` | 风云Ⅳ — fengyun434 | `fengyun4-3-4.rar` | 40011 | WASM playable |
| 009-1 | `fy2005` | 风云Ⅳ（2005 国内经典版）— fy2005 | `fy2005.rar` | 40013 | WASM playable |
| 010 | `xiyouji` | 西游记 (A Journey to the West) | `西游记.rar` | 40079 | WASM playable |
| 010-1 | `fluffos_xiyou2000` | 西游记 2000 — fluffos_xiyou2000 | `fluffos(西游记2000).tar.gz` | 40012 | WASM playable |
| 010-2 | `xiyouji2003` | 西游记[光辉岁月] | `西游记2003.rar` | 40075 | WASM playable |
| 010-3 | `xiyouji450` | 西游记450 | `西游记450.rar` | 40078 | WASM playable |
| 010-4 | `xiyouji2006` | 西游记2006·大唐西游 | `西游记2006之 最终幻想.rar` | 40077 | WASM playable |
| 011 | `fy2` | 风云再起Ⅱ — fy2 | `fy2.rar` | 40014 | WASM playable |
| 011-1 | `fengyun2qinghua` | 风云再起Ⅱ（清华仿写版）— fengyun2qinghua | `风云II (清华仿写版）.ZIP` | 40091 | WASM playable |
| 012 | `mhxy` | 梦幻西游 (mhxy) | `mhxy.rar` | 40016 | WASM limited |
| 012-1 | `menghuanxiyou2002` | 梦幻西游（青岛站） | `梦幻西游2002版.rar` | 40050 | WASM limited |
| 013 | `xiakexing2017` | 侠客行 (MUD侠客行2017完整版) | `MUD侠客行2017完整版.zip` | 40017 | WASM playable |
| 014 | `nitan170911` | 仙剑奇侠传 (nitan170911) | `nitan170911.7z` | 40018 | WASM limited |
| 015 | `nitan6` | 笑傲江湖 (nitan6) | `nitan6.zip` | 40019 | WASM limited |
| 016 | `rzrmud` | 大唐西游 YWX人造人 (rzrmud) | `rzrmud.20130220.tar.gz` | 40020 | WASM playable |
| 017 | `xkx2001` | 侠客行 Ⅰ (The Quest of Oriental Chivalry) | `xkx2001测试用老lib.zip` | 40021 | WASM playable |
| 017-1 | `beimeixiakexing2001` | 侠客行 (The Quest of Oriental Chivalry) — 北美 2001 版 | `北美侠客行2001.rar` | 40039 | WASM playable |
| 018 | `xlqy_new2007` | 新仙侣情缘之飘渺纪元 | `xlqy_new2007.rar` | 40022 | WASM playable |
| 018-1 | `xlqy_early` | 仙侣情缘（早期测试版） | `xlqy-解压看readme.rar` | 40076 | WASM playable |
| 018-2 | `xianlvqingyuanzheda` | 仙侣情缘·浙大版 | `仙侣情缘浙大版.rar` | 40033 | WASM limited |
| 019 | `xo` | 笑傲江湖（迷你版） | `xo.zip` | 40023 | WASM limited |
| 019-1 | `xo_final` | 笑傲江湖（最终版） | `xo最终版1.2.rar` | 40024 | WASM playable |
| 019-2 | `xiaoaojianghu2` | 笑傲江湖 II | `笑傲江湖II.rar` | 40068 | WASM playable |
| 019-3 | `xiaoaojianghu_xo` | 笑傲江湖 XO | `笑傲江湖XO .rar` | 40069 | WASM limited |
| 020 | `zzfy` | 郑州风云3 | `zzfy (full).rar` | 40025 | WASM playable |
| 020-1 | `fengyun3xiuding` | 风云三（星星修订版）— fengyun3xiuding | `风云III修订版 .rar` | 40089 | WASM playable |
| 020-2 | `fengyun3dianzang` | 风云典藏版 — fengyun3dianzang | `风云III典藏版.rar` | 40090 | WASM playable |
| 021 | `shiji` | 世纪 | `世纪.zip` | 40026 | WASM limited |
| 022 | `dongfanggushi2` | 东方故事Ⅱ之天朝帝国 (Eastern Story II: The Celestial Empire) | `东方故事二.rar` | 40027 | WASM playable |
| 023 | `zhonghua2` | 中华英雄苏州站 | `中华2.rar` | 40028 | WASM limited |
| 024 | `shujian2008` | 书剑天下 2008 | `书剑2008.rar` | 40029 | WASM limited |
| 024-1 | `shujiantianxia` | 书剑天下（小熊泥苑分站） | `书剑天下.rar` | 40030 | WASM limited |
| 025 | `shujianpiaoling2` | 书剑飘零Ⅱ | `书剑飘零II .zip` | 40031 | WASM playable |
| 026 | `xianlvqiyuan` | 仙侣情缘（知秋站 2001版） | `仙侣奇缘新版.rar` | 40032 | WASM limited |
| 027 | `xianjianchuanqi` | 仙剑狂侠2000（仙剑传奇） | `仙剑传奇.rar` | 40034 | WASM limited |
| 028 | `xiakexinzhuan2` | 侠客新传 (New Legend of the Wandering Swordsman) | `侠客新传(2).rar` | 40035 | WASM playable |
| 029 | `xiakeyingxiong3` | 侠客英雄传 III | `侠客英雄传III 可用.zip` | 40036 | WASM limited |
| 030 | `xiakexing100` | 侠客行一百 (Xia Ke Xing - Yi Bai) | `侠客行100.rar` | 40037 | WASM playable |
| 031 | `jinyongqunxiazhuan2008` | 金庸群侠传（2008 加强版） | `金庸群侠传2008加强版.rar` | 40082 | WASM playable |
| 031-1 | `jinyongqunxiazhuan2008_std` | 金庸群侠传（2008 标准版） | `金庸群侠传2008版.rar` | 40084 | WASM playable |
| 031-2 | `jinyongqunxiazhuan2008_deluxe` | 金庸群侠传（2008 超豪华版） | `金庸群侠传2008超豪华版.rar` | 40085 | WASM playable |
| 031-3 | `jinyongqunxiazhuan2015` | 金庸群侠传（2015版） | `金庸群侠传2015版.rar` | 40086 | WASM playable |
| 031-4 | `xiakexing3` | 金庸群侠传 (原名"侠客行三") | `侠客行III .rar` | 40038 | WASM playable |
| 032 | `xiyangzaixian_fengkuang` | 夕阳再现·疯狂江湖 | `夕阳再现-疯狂江湖.rar` | 40040 | WASM limited |
| 032-1 | `xiyangzaixian_fengyun2` | 夕阳再现·风云再起Ⅱ | `夕阳再现-风云再起2.rar` | 40041 | WASM limited |
| 032-2 | `jianghufengyun` | 江湖风云 | `江湖风云.rar` | 40053 | WASM limited |
| 033 | `xiyangzaixian3` | 夕阳再现III之炎龙封印 | `夕阳再线III之炎龙封印.rar` | 40042 | WASM limited |
| 033-1 | `yanlongfengyin_xiaoao3` | 炎龙封印（笑傲江湖·阿飞站） | `炎龙封印-笑傲江湖3阿飞站.rar` | 40062 | WASM limited |
| 033-2 | `longyunmeng` | 龙云梦·炎龙封印（源码版） | `龙云梦-炎龙封印源码版.rar` | 40094 | WASM limited |
| 033-3 | `longyunmeng_binary` | 龙云梦·炎龙封印（二进制版） | `龙云梦-炎龙封印-二进制版.rar` | — | not convertible |
| 034 | `tianxia` | 天下 Beta | `天下.tar.gz` | 40044 | WASM limited |
| 035 | `tianxiawuxue` | 天下无雪 | `天下无雪.rar` | 40045 | WASM limited |
| 036 | `xinkuangxiangkongjian2` | 狂想空间 | `新狂想空间II.rar` | 40047 | WASM playable |
| 036-1 | `kuangxiangkongjian` | 狂想空间 | `狂想空间.rar` | 40063 | WASM playable |
| 037 | `yueyingqiyuan` | 月影奇缘 | `月影奇缘.rar` | 40048 | WASM playable |
| 038 | `weimingkongjian` | 未明空间 (Weiming Kongjian / "wmkj") | `未明空间.rar` | 40049 | WASM limited |
| 039 | `moniHuafu` | 模拟华附 (moniHuafu) | `模拟华附.zip` | 40051 | WASM limited |
| 040 | `wuhanzhan` | 大话西游 (A Chinese Odyssey) | `武汉站.rar` | 40052 | WASM playable |
| 041 | `nitan_ceshi` | 泥潭III测试版 / 《終極魔界》 (nitan_ceshi) | `泥潭III测试版.rar` | 40054 | WASM limited |
| 041-1 | `nitan_san` | 泥潭三 / 《終極魔界》 (nitan_san) | `泥潭三.rar` | 40055 | WASM limited |
| 042 | `yuxuechongsheng` | 浴血重生 | `浴血重生MUD.rar` | 40056 | WASM limited |
| 043 | `haiyang2` | 海洋II | `海洋II 2010 正式无错完整版下载.rar` | 40057 | WASM limited |
| 044 | `huoying` | 火影 | `火影.rar` | 40059 | WASM limited |
| 045 | `yanhuangwuhun` | 「武林群侠传」之炎黄武魂Ⅱ | `炎黄武魂_64bit.rar` | 40060 | WASM limited |
| 045-1 | `yanhuangyingxiongshi` | 炎黄英雄史（游戏内也称"皇朝再现"） | `炎黄英雄史.rar` | 40061 | WASM limited |
| 046 | `xuanjianlu` | 玄剑录 | `玄剑录.rar` | 40064 | WASM playable |
| 047 | `bixiecanyang` | 碧血残阳 之「豪侠晚歌」 | `碧血残阳之豪侠晚歌.rar` | 40065 | WASM limited |
| 048 | `shenzhou` | 神州 | `神州.rar` | 40066 | WASM playable |
| 049 | `shenmo` | 神魔（西游记之神魔传说） | `神魔20190924版本.rar` | 40067 | WASM playable |
| 050 | `xiaoaojianghu_client` | 笑傲江湖之重出江湖 | `笑傲江湖服务端+客户端.rar` | 40070 | WASM limited |
| 051 | `zitengzhan` | 紫藤站 | `紫藤站.rar` | 40071 | WASM limited |
| 052 | `zhongjidiyu` | 终极地狱之轩辕传说 | `终极地狱.rar` | 40072 | WASM limited |
| 053 | `zhongjidiyu_airuoyoulan` | 终极地狱之爱若幽兰 | `终极地狱之爱若幽兰1.166正式版.rar` | 40073 | WASM limited |
| 053-1 | `zhongjidiyu_zhijian` | 终极地狱-指间MUD版 | `终极地狱-指间mud版服务端.rar` | 40074 | WASM limited |
| 054 | `xixingzhanji` | 西行战记 | `西行战记.gz` | 40080 | WASM playable |
| 055 | `chongshengdeshijie` | 重生的世界 (Revival World) | `重生的世界v1.0.1.rar` | 40081 | WASM no-boot |
| 056 | `tiexuejianghu` | 铁血江湖 (Tie Xue Jiang Hu) | `铁血江湖.rar` | 40087 | WASM playable |
| 057 | `suiyuanxijianlu` | 随缘洗剑录 | `随缘洗剑录.rar` | 40088 | WASM limited |
| 058 | `mohuanshiji` | 魔幻世纪 (mohuanshiji) | `魔幻世纪.rar` | 40092 | WASM playable |
| 901 | `dw_fluffos_v1` | Discworld MUD lib (v1) | `dw_fluffos_v1.tar.gz` | — | deprioritized |
| 901-1 | `dw_fluffos_v2` | Discworld MUD lib (v2) | `dw_fluffos_v2.zip` | — | deprioritized |
| 901-2 | `dw_fluffos_v3` | Discworld MUD lib (v3) | `dw_fluffos_v3.zip` | — | deprioritized |
| 902 | `tomud_vc` | TOMud VC++ 客户端源码 | `TOMud_VC源代码.rar` | — | not a mudlib |
| 903 | `sanguowaizhuan` | 三国歪传 (Diku/Merc) | `三国歪传.rar` | — | not a mudlib |
| 904 | `atlantis` | 消失的亞特蘭提斯 (EnvyMud) | `消失的亞特蘭提斯MUD破解版.zip` | — | not a mudlib |
| 905 | `chongchujianghu` | 重出江湖 (C++ engine) | `重出江湖.rar` | — | not a mudlib |
| 905-1 | `chongchujianghu_win` | 重出江湖 WIN完全版 | `重出江湖WIN完全版.rar` | — | not a mudlib |
| 905-2 | `chongchujianghu_linux_src` | 重出江湖 Linux 源码 v2.71 | `重出江湖完整源码linunx_2.71原版.rar` | — | not a mudlib |
| 906 | `mofaleidemuba` | 魔法类的泥巴 (EmberMUD) | `魔法类的泥巴.rar` | — | not a mudlib |
<!-- END NUMBERING TABLE -->

## Repository layout

```
archives/                 original archive files, renamed NNN[-M]_<slug>_<original-name>
libs/<slug>/raw/          pristine extraction, original encoding/extensions (gitignored,
                          regenerable via scripts/extract.sh)
libs/<slug>/work/         the playable mudlib: UTF-8, .lpc extensions, fixes applied
libs/<slug>/config.fluffos  FluffOS runtime config (port, paths) for this lib
libs/<slug>/README.md     player-facing intro: what the game is, how to log in, quirks
libs/<slug>/NOTES.md      restoration record: layout, every fix applied, known issues
scripts/                  extraction/conversion/test/site tooling:
  extract.sh              archive -> raw/ (zip/rar/7z/tar, SFX exes, odd tars)
  convert_lib.sh          GB18030->UTF-8 + .c->.lpc rename + reference fixups
  lpcc_check.sh           batch-compile every file in a lib against the real master
  mudclient.py            scriptable telnet smoke-test client
  wasm_client.js          same interface, drives an in-process WASM driver
  wasm_boot_check.js      boot-check a packed site bundle under node
  pack_lib_for_web.sh / build_site.sh / gen_site_index.py   GitHub Pages build
lib_numbering.json        number <-> slug <-> original archive mapping (machine-readable)
AGENTS.md                 the contributor/agent handbook: pipeline, fix catalog, WASM triage
```

## Provenance and licensing

These are **historical community archives**, collected from Chinese MUD
enthusiast sites and forum dumps circulated over roughly two decades. Most
carry no formal license; they were written by volunteer wizard teams
(often building on the ES2/东方故事 or TMI-2 base mudlibs) and shared
informally in that community's tradition. One lib
(`055`/`chongshengdeshijie`, 重生的世界) is explicitly GPLv2. This repo
preserves them as cultural artifacts and makes them runnable again; it
does not claim ownership. Original author credits inside the files are
retained untouched. If you are an original author and want a lib
attributed differently or removed, please open an issue.

What this project changed in each lib is intentionally minimal and fully
documented per-lib in `NOTES.md`: encoding conversion, driver-API
compatibility fixes, repairs of pre-existing corruption, and the
local-play conveniences described above. Game content was never invented
— genuinely missing zones/files are documented as gaps, not fabricated.

## Contributing / continuing the restoration

Read **`AGENTS.md`** first. It is the accumulated handbook of this
project: the per-lib conversion pipeline, a ~60-entry catalog of
driver-compatibility bug classes (with symptoms, root causes, and code
fixes), the WASM triage playbook, and the testing methodology (including
the hard-won rule: a lib is not "working" until a real Chinese name has
registered *and* a post-login `look` has produced output). The current
mission is getting every lib **fully playable under WASM**, which is the
main distribution channel.
