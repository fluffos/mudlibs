# mudlibs — 200 restored classic Chinese LPC mudlibs (158 unique games), runnable natively and most in the browser

**▶ Play now, no install: https://mudlibs.fluffos.info/**

![Screenshot of the mudlibs.fluffos.info game gallery](docs/site-preview.png)

This repository preserves and restores the golden age of the Chinese MUD
scene (mid-1990s to ~2015): **200 restored LPC mudlibs across 158 unique
game codebases** (79 fully verified playable in the browser, 117 more
native-boot verified with the WASM packaging pass still pending, 1
native-only by policy, 4 confirmed non-bootable — see below) — 侠客行, 笑傲江湖,
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

**https://mudlibs.fluffos.info/** — the GitHub Pages site (built by
`.github/workflows/pages.yml`) hosts every converted lib as a click-to-play
page: it packs each `libs/<slug>/` tree into an in-memory filesystem image,
pairs it with the prebuilt WASM FluffOS driver from the latest fluffos
release, and generates an index page from the per-lib READMEs
(`scripts/gen_site_index.py`, `scripts/wasm_status.json`).

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
first** — it is a published default, deliberately identical across all
libs for local convenience, and grants full in-game wizard/admin power
(including file read/write inside the mudlib).

## The collection — numbering, lineage, and status

Each **unique game/codebase** has a sequential number (`001`–`158`, still
growing as new archives get dropped in). Confirmed derivatives — later
snapshots, rebrands, site builds, and close forks of the *same* codebase —
share the base number with a `-1`/`-2`/`-3` suffix (e.g. `031`
金庸群侠传2008加强版, `031-4` its 侠客行三 rebrand). Lineage was established
by actually diffing core files (`master.c`, `chinese.c`, `logind.c`) across
archives — similar Chinese titles alone turned out to be a *very*
unreliable signal, in both directions. Numbers `9xx` are archives that
turned out not to be LPC mudlibs at all (DikuMUD/Merc C servers, a Windows
mud client, compiled-binary-only releases) or deliberately-deprioritized
English libs; one entry (`033-3`, a binary-only release with no source)
is cataloged for provenance but was never convertible and has no `libs/`
directory.

The same mapping is machine-readable in `lib_numbering.json`, and the raw
files under `archives/` are named `NNN[-M]_<slug>_<original-name>.<ext>` —
the original archive filename is preserved verbatim inside the new name so
the provenance reference stays intact.

WASM status values: **playable** = full registration + gameplay verified
end-to-end in the WASM harness (registration, look/score/quit, and the
seeded admin account's login + a wizard command all confirmed); **limited**
= boots and plays under WASM with a known caveat documented in that lib's
own README; **partial (native only)** = `ds386` (Dead Souls), an
English-language lib deliberately deprioritized per project policy (see
`AGENTS.md` §10.6) and not pushed through the WASM pass; **native-boot
verified, WASM pending** = boots and plays cleanly on the native FluffOS
driver but hasn't been through the WASM packaging pass yet — this covers
a large batch of archives added in the most recent bulk-conversion pass
and is next in line for that pass; **noboot** = a genuine LPC mudlib
that fails to boot for a structural reason unrelated to this project's
own conversion (a missing master object in the archive itself, a
different mudlib codebase family the driver isn't built for) — not a
pending-work item, filed for provenance. Every lib that has been through the
WASM pass also gets a periodic long-sit WASM boot-log sweep — not just a
quick login check — watching the driver's own output for several minutes
to catch lazily-triggered daemon/heartbeat failures that a fast smoke
test would miss; see `AGENTS.md` §10.0 for the tool and §7/§8 for the bug
classes it's found.

<!-- BEGIN NUMBERING TABLE (generated from lib_numbering.json) -->
| # | Slug | Game | Original archive | Port | WASM |
|---|---|---|---|---|---|
| 001 | `shanhaizhanshen` | 山海战神 | `山海战神.rar` | 40001 | WASM playable |
| 002 | `xingzhanyingxiong` | 星战英雄 | `星战英雄.rar` | 40002 | WASM playable |
| 003 | `unknownlib20150716` | 小雨西游Ⅱ (Xiaoyu Xiyou II) | `20150716未知lib.zip` | 40003 | WASM playable |
| 003-1 | `xiaoyuxiyou` | 小雨西游 | `小雨西游.zip` | 40046 | WASM playable |
| 004 | `bxsj` | 书剑天下 (ShuJian MUD) | `bxsj.rar` | 40004 | WASM limited |
| 004-1 | `bxsj1` | 书剑·经典 (ShuJian Classic) | `bxsj1.rar` | 40005 | WASM limited |
| 004-2 | `jinyongwenzi` | 金庸文字版 | `金庸文字版 (1).exe` | — | pending |
| 005 | `chidi` | 江湖 I (Jianghu I) | `chidi.rar` | 40006 | WASM limited |
| 006 | `ds386` | Dead Souls 3.8.6 | `ds3.8.6.zip` | 40007 | WASM partial |
| 007 | `dtsl` | DTSL | `DTSL.7z` | — | pending |
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
| 011-1 | `fengyun2qinghua` | 风云II | `风云II (清华仿写版） (1).ZIP` | — | pending |
| 012 | `mhxy` | 梦幻西游 (mhxy) | `mhxy.rar` | 40016 | WASM limited |
| 012-1 | `menghuanxiyou2002` | 梦幻西游（青岛站） | `梦幻西游2002版.rar` | 40050 | WASM limited |
| 013 | `xiakexing2017` | 侠客行 (MUD侠客行2017完整版) | `MUD侠客行2017完整版.zip` | 40017 | WASM playable |
| 014 | `nitan170911` | 仙剑奇侠传 (nitan170911) | `nitan170911.7z` | 40018 | WASM limited |
| 014-1 | `hhsj` | 洪荒世界 | `洪荒世界.rar` | 40106 | WASM playable |
| 014-2 | `xfbhh` | 洪荒世界（修复版） | `修复版洪荒.rar` | 40190 | WASM playable |
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
| 019-4 | `qhxajh` | 清华笑傲江湖 | `清华笑傲江湖）.tgz` | 40195 | WASM playable |
| 020 | `zzfy` | 郑州风云3 | `zzfy (full).rar` | 40025 | WASM playable |
| 020-1 | `fengyun3xiuding` | 风云III修订版 | `风云III修订版  (1).rar` | — | pending |
| 020-2 | `fengyun3dianzang` | 风云III典藏版 | `风云III典藏版 (1).rar` | — | pending |
| 021 | `shiji` | 世纪 | `世纪.zip` | 40026 | WASM limited |
| 022 | `dongfanggushi2` | 东方故事二 | `东方故事二 (1).rar` | — | pending |
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
| 032 | `xiyangzaixian_fengkuang` | 夕阳再现-疯狂江湖 | `夕阳再现-疯狂江湖(1).rar` | — | pending |
| 032-1 | `xiyangzaixian_fengyun2` | 夕阳再现·风云再起Ⅱ | `夕阳再现-风云再起2.rar` | 40041 | WASM limited |
| 032-2 | `jianghufengyun` | 江湖风云 | `江湖风云 (1).rar` | — | pending |
| 033 | `xiyangzaixian3` | 夕阳再现III之炎龙封印 | `夕阳再线III之炎龙封印.rar` | 40042 | WASM limited |
| 033-1 | `yanlongfengyin_xiaoao3` | 炎龙封印（笑傲江湖·阿飞站） | `炎龙封印-笑傲江湖3阿飞站.rar` | 40062 | WASM limited |
| 033-2 | `longyunmeng` | 龙云梦·炎龙封印（源码版） | `龙云梦-炎龙封印源码版.rar` | 40094 | WASM limited |
| 033-3 | `longyunmeng_binary` | 龙云梦·炎龙封印（二进制版） | `龙云梦-炎龙封印-二进制版.rar` | — | not-convertible |
| 033-4 | `xyzxiiidup` | 夕阳再现III (dup) | `夕阳再现III.rar` | — | not-mudlib |
| 034 | `tianxia` | 天下 Beta | `天下.tar.gz` | 40044 | WASM limited |
| 035 | `tianxiawuxue` | 天下无雪 | `天下无雪.rar` | 40045 | WASM limited |
| 036 | `xinkuangxiangkongjian2` | 狂想空间 | `新狂想空间II.rar` | 40047 | WASM playable |
| 036-1 | `kuangxiangkongjian` | 狂想空间 | `狂想空间 (1).rar` | — | pending |
| 037 | `yueyingqiyuan` | 月影奇缘 | `月影奇缘.rar` | 40048 | WASM playable |
| 038 | `weimingkongjian` | 未明空间 (Weiming Kongjian / "wmkj") | `未明空间.rar` | 40049 | WASM limited |
| 039 | `moniHuafu` | mnhf | `mnhf.zip` | — | pending |
| 040 | `wuhanzhan` | 大话西游 (A Chinese Odyssey) | `武汉站.rar` | 40052 | WASM playable |
| 041 | `nitan_ceshi` | 泥潭III测试版 / 《終極魔界》 (nitan_ceshi) | `泥潭III测试版.rar` | 40054 | WASM limited |
| 041-1 | `nitan_san` | 泥潭三 / 《終極魔界》 (nitan_san) | `泥潭三.rar` | 40055 | WASM limited |
| 042 | `yuxuechongsheng` | 浴血重生 | `浴血重生MUD.rar` | 40056 | WASM limited |
| 043 | `haiyang2` | 海洋II 2010 正式无错完整版下载 | `海洋II 2010 正式无错完整版下载 (1).rar` | — | pending |
| 043-1 | `hymud` | 海洋V·星月传奇 | `hymud-main.zip` | 40103 | WASM playable |
| 044 | `huoying` | Naruto | `Naruto.rar` | — | pending |
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
| 055 | `chongshengdeshijie` | 重生的世界 (Revival World) | `重生的世界v1.0.1.rar` | 40081 | noboot |
| 056 | `tiexuejianghu` | 铁血江湖 (Tie Xue Jiang Hu) | `铁血江湖.rar` | 40087 | WASM playable |
| 057 | `suiyuanxijianlu` | 随缘洗剑录 | `随缘洗剑录.rar` | 40088 | WASM limited |
| 058 | `mohuanshiji` | 魔幻世纪 (mohuanshiji) | `魔幻世纪.rar` | 40092 | WASM playable |
| 059 | `sanjiechuanshuo` | 三界传说 | `三界传说.rar` | 40097 | native-boot verified, WASM pending |
| 060 | `sanjieshenhua` | 三界神话「嘉峪关」 | `三界神话-春节.rar` | 40098 | native-boot verified, WASM pending |
| 061 | `zuizhonghuanjing` | 最终幻境 | `最终幻境.zip` | 40099 | native-boot verified, WASM pending |
| 062 | `niaoren` | 最新鳥人世界 | `最新鳥人世界.zip` | 40100 | native-boot verified, WASM pending |
| 063 | `aoxiangtianji` | 翱翔天际 | `翱翔天际utf8.7z` | 40101 | native-boot verified, WASM pending |
| 064 | `yhyxcs` | 银河英雄传说 | `银河英雄传说.zip` | 40104 | WASM playable |
| 065 | `ldtx` | 鹿鼎天下 (in-game: 雄霸天下『西安站』) | `鹿鼎天下.rar` | 40105 | native-boot verified, WASM pending |
| 066 | `hc` | 红尘 (in-game: 红尘录) | `红尘.rar` | 40107 | WASM playable |
| 067 | `cctx` | 驰骋天下 | `驰骋天下.rar` | 40161 | native-boot verified, WASM pending |
| 068 | `dfgsiiv13b` | 东方故事IIv1.3b | `东方故事IIv1.3b.tar.gz` | 40144 | native-boot verified, WASM pending |
| 069 | `dfgsitlzjwin` | 东方故事I屠龙战记WIN98版 | `东方故事I屠龙战记WIN98版.rar` | 40111 | native-boot verified, WASM pending |
| 070 | `dtxywzxzb` | 大唐西游完整修正版 | `大唐西游完整修正版.rar` | 40150 | native-boot verified, WASM pending |
| 071 | `ffxymud` | 非凡夕阳MUD | `非凡夕阳MUD.rar` | 40142 | native-boot verified, WASM pending |
| 072 | `fys` | 风云三 | `风云三.rar` | 40164 | native-boot verified, WASM pending |
| 073 | `fysjmb` | 风云四解密版 | `风云四解密版.rar` | 40165 | native-boot verified, WASM pending |
| 074 | `fyzfqyy` | 风云之风起云涌 | `风云之风起云涌.rar` | 40133 | native-boot verified, WASM pending |
| 075 | `gjzddmudda` | 国家制度的MUD DA | `国家制度的MUD DA.rar` | 40122 | native-boot verified, WASM pending |
| 076 | `hell` | hell | `hell.7z` | 40114 | native-boot verified, WASM pending |
| 077 | `hxxtjqb` | 幻想西天加强版 | `幻想西天加强版.rar` | 40177 | native-boot verified, WASM pending |
| 078 | `hy2` | 火影 | `火影 (2).rar` | 40123 | native-boot verified, WASM pending |
| 079 | `hy2000` | 海洋2000 | `海洋2000.rar` | 40174 | native-boot verified, WASM pending |
| 080 | `hy2002` | 海洋2002 | `海洋2002.rar` | 40116 | native-boot verified, WASM pending |
| 081 | `hy3` | 火云 | `火云.rar` | 40162 | native-boot verified, WASM pending |
| 082 | `hyiishzdscbb` | 海洋II上海站第三次版本 | `海洋II上海站第三次版本.rar` | 40147 | native-boot verified, WASM pending |
| 083 | `jh2006` | 江湖2006 | `江湖2006.rar` | 40128 | native-boot verified, WASM pending |
| 084 | `jhfy2` | 江湖风云2 | `江湖风云2.rar` | 40137 | native-boot verified, WASM pending |
| 085 | `jhfy3` | 江湖风云3 | `江湖风云3.rar` | 40143 | native-boot verified, WASM pending |
| 086 | `jyqxc` | 金庸群侠传 | `金庸群侠传 (1).rar` | 40129 | native-boot verified, WASM pending |
| 087 | `jyqxc2` | 金庸群侠传 | `金庸群侠传.rar` | 40172 | native-boot verified, WASM pending |
| 088 | `jyqxc2013fwq` | 金庸群侠传2013_服务器版 | `金庸群侠传2013_服务器版.rar` | 40108 | native-boot verified, WASM pending |
| 089 | `kxkjii2` | 狂想空间II | `狂想空间II.rar` | 40160 | native-boot verified, WASM pending |
| 090 | `ldtxii` | 鹿鼎天下II | `鹿鼎天下II.rar` | 40176 | native-boot verified, WASM pending |
| 091 | `mnhf` | 模拟华附 | `模拟华附.rar` | 40156 | native-boot verified, WASM pending |
| 092 | `nte` | 泥潭二 | `泥潭二.rar` | 40115 | native-boot verified, WASM pending |
| 093 | `ntii` | 泥潭II | `泥潭II.rar` | 40151 | native-boot verified, WASM pending |
| 094 | `sj` | 世纪 | `世纪.rar` | 40127 | WASM playable |
| 095 | `sje` | 书剑贰 | `书剑贰.rar` | 40146 | WASM playable |
| 096 | `sjecl` | 书剑恩仇录 | `书剑恩仇录.rar` | 40139 | WASM playable |
| 097 | `sjplgfjxb` | 书剑飘零官方教学版 | `书剑飘零官方教学版 .rar` | 40134 | WASM playable |
| 098 | `sjplii` | 书剑飘零II | `书剑飘零II.rar` | 40153 | WASM playable |
| 099 | `sjsh` | 三界神话 | `三界神话（宝鸡站的版本）.rar` | 40141 | WASM playable |
| 100 | `sjshv150` | 三界神话V1.50 | `三界神话V1.50.rar` | 40171 | WASM playable |
| 101 | `sjshv2578bb` | 三界神话v2.578b版 | `三界神话v2.578b版.rar` | 40125 | WASM playable |
| 102 | `sjshwzb` | 三界神话完整版 | `三界神话完整版.rar` | 40113 | WASM playable |
| 103 | `sjshwzjqb` | 三界神话完整加强版 | `三界神话完整加强版.rar` | 40173 | WASM playable |
| 104 | `tybxjh` | 天涯&碧血江湖 | `天涯&碧血江湖.rar` | 40158 | WASM playable |
| 105 | `wlhd` | 武林浩荡 | `武林浩荡.rar` | 40121 | WASM playable |
| 106 | `wqfy` | 无情风云 | `无情风云.rar` | 40124 | WASM playable |
| 107 | `xajdxyj` | 西安交大西游记 | `西安交大西游记.rar` | 40179 | WASM playable |
| 108 | `xajh4gkb` | 笑傲江湖4公开版 | `笑傲江湖4公开版.rar` | 40154 | WASM playable |
| 109 | `xhcii` | 笑红尘Ⅱ | `笑红尘Ⅱ .rar` | 40163 | WASM playable |
| 110 | `xkx100` | 侠客行一百 | `侠客行一百.rar` | 40117 | WASM playable |
| 111 | `xkx2000zxb` | 侠客行2000最新版 | `侠客行2000最新版.rar` | 40140 | WASM playable |
| 112 | `xkx2017` | 侠客行2017 | `侠客行2017（MUD）.rar` | 40145 | WASM playable |
| 113 | `xkxc98sj` | 侠客新传98书剑 | `侠客新传98书剑.rar` | 40126 | WASM playable |
| 114 | `xkxyb` | 侠客行一百 | `侠客行一百 (1).rar` | 40152 | WASM playable |
| 115 | `xkyxciii` | 侠客英雄传III | `侠客英雄传III.rar` | 40118 | WASM playable |
| 116 | `xsfyssjb` | 心声风云四升级版 | `心声风云四升级版.rar` | 40149 | WASM playable |
| 117 | `xxcq` | 小雪初晴 | `小雪初晴.rar` | 40135 | WASM playable |
| 118 | `xxcqii` | 小雪初晴II | `小雪初晴II.rar` | 40131 | WASM playable |
| 119 | `xxcqii2` | 小雪初晴II | `小雪初晴II  .zip` | — | pending |
| 120 | `xyj2000` | 西游记2000 | `西游记2000.rar` | 40155 | WASM playable |
| 121 | `xyj20032` | 西游记2003-2 | `西游记2003-2.rar` | 40119 | WASM playable |
| 122 | `xyj2006n` | 西游记2006年 | `西游记2006年.rar` | 40157 | WASM playable |
| 123 | `xyj2006zzzhx` | 西游记2006之最终幻想 | `西游记2006之最终幻想.rar` | 40159 | WASM playable |
| 124 | `xyj451` | 西游记451 | `西游记451.rar` | 40112 | WASM playable |
| 125 | `xysylmhb` | 夕阳三-炎龙美化版 | `夕阳三-炎龙美化版.rar` | 40169 | WASM playable |
| 126 | `xyxyutf8` | 小雨西游utf8 | `小雨西游utf8.zip` | 40168 | WASM playable |
| 127 | `xyzx` | 夕阳再现 | `夕阳再现.rar` | 40180 | WASM playable |
| 128 | `xyzxiiylzymh` | 夕阳再现II-炎龙专用美化客户端 | `夕阳再现II-炎龙专用美化客户端.rar` | 40130 | WASM playable |
| 129 | `xyzxyl201412` | 夕阳再现-炎龙20141231 | `夕阳再现-炎龙20141231.rar` | 40175 | WASM playable |
| 130 | `yhwhpublicfi` | 炎黄武魂public-final-2016-12-08 | `炎黄武魂public-final-2016-12-08.rar` | 40132 | WASM playable |
| 131 | `yxjh` | 浴血江湖 | `浴血江湖.rar` | 40148 | native-boot verified, WASM pending |
| 132 | `yxsj` | 逸侠世界 | `逸侠世界.rar` | 40167 | native-boot verified, WASM pending |
| 133 | `yxxcii` | 游侠笑传II | `游侠笑传II.rar` | 40136 | native-boot verified, WASM pending |
| 134 | `yxzsj` | 逸  俠  之  世  界 | `逸  俠  之  世  界.rar` | 40170 | native-boot verified, WASM pending |
| 135 | `yzxiiizylfy` | 阳再线III之炎龙封印 | `阳再线III之炎龙封印.rar` | 40178 | native-boot verified, WASM pending |
| 136 | `zjdy2008wzb` | 终极地狱2008完整版 | `终极地狱2008完整版.rar` | 40110 | native-boot verified, WASM pending |
| 137 | `zjdywzb` | 终极地狱完整版 | `终极地狱完整版.rar` | 40109 | native-boot verified, WASM pending |
| 138 | `zxty` | 再现天涯 | `再现天涯.rar` | 40166 | native-boot verified, WASM pending |
| 138-1 | `zxty08nxgbb` | 再现天涯（08年修改版本） | `再现天涯08年修改版本.rar` | 40193 | native-boot verified, WASM pending |
| 139 | `zzfy3` | 郑州风云3 | `郑州风云3.rar` | 40120 | native-boot verified, WASM pending |
| 140 | `hellxg` | hell（修改版） | `hell - 修改.7z` | 40181 | noboot |
| 141 | `wxddym` | 武学大道 | `武学大道源码.7z` | 40189 | WASM playable |
| 142 | `nt6` | 泥潭6 | `泥潭6.zip` | 40186 | native-boot verified, WASM pending |
| 142-1 | `nt6nitan6win` | 泥潭6 (win_nodb版) | `泥潭6nitan6-win_nodb.rar` | 40187 | native-boot verified, WASM pending |
| 143 | `yszz` | 妖神之争 | `妖神之争.rar` | 40192 | WASM playable |
| 144 | `njhhdxdes2hx` | es2/侠客行（南京河海大学校内版1.01） | `南京河海大学的es2和xkx《校内_1.01版》.tar.gz` | 40194 | WASM playable |
| 145 | `sgzmudsgz` | 三国志MUD (sgz) | `三国志MUDsgz.tar.gz` | 40196 | noboot |
| 146 | `hy` | 海洋（基础版） | `海洋（由千堆雪上传）.rar` | 40182 | native-boot verified, WASM pending |
| 146-1 | `hy5` | 海洋5 | `海洋5.7z` | 40183 | native-boot verified, WASM pending |
| 147 | `jym` | 金庸梦 | `金庸梦.rar` | 40184 | native-boot verified, WASM pending |
| 148 | `nt1` | 泥潭1 | `泥潭1.gz` | 40185 | native-boot verified, WASM pending |
| 149 | `wdxtym` | 武动仙途 | `武动仙途源码.rar` | 40188 | WASM playable |
| 150 | `xkm` | 侠客梦 | `侠客梦.rar` | 40191 | native-boot verified, WASM pending |
| 151 | `fqyy2` | 风起云涌2 | `风起云涌2修正版.rar` | 40197 | native-boot verified, WASM pending |
| 152 | `fy2mg` | 风云II（美国版本） | `风云II(美国版本）.rar` | 40198 | native-boot verified, WASM pending |
| 153 | `fy330` | 风云III (3.0) | `风云III(3.0).rar` | 40199 | native-boot verified, WASM pending |
| 154 | `xbtxiii` | 雄霸天下III | `雄霸天下III.rar` | 40201 | native-boot verified, WASM pending |
| 155 | `xkxlb` | 侠客行（老版/金庸群侠传） | `侠客行老版(金庸群侠传）.rar` | 40202 | native-boot verified, WASM pending |
| 156 | `xyj42` | 西游记 4.2 | `西游记4.2.gz` | 40203 | native-boot verified, WASM pending |
| 156-1 | `xyj42dup` | 西游记4.2 (dup) | `西游记4.2.rar` | — | not-mudlib |
| 157 | `shujian3` | 书剑3 | `最新独立安卓客户端和书剑源码一键架站.zip` | 40200 | native-boot verified, WASM pending |
| 158 | `zjmudhell` | 指尖MUD | `指尖后端.7z` | 40204 | native-boot verified, WASM pending |
| 901 | `dw_fluffos_v1` | Discworld MUD lib (v1) | `dw_fluffos_v1.tar.gz` | — | deprioritized |
| 901-1 | `dw_fluffos_v2` | Discworld MUD lib (v2) | `dw_fluffos_v2.zip` | — | deprioritized |
| 901-2 | `dw_fluffos_v3` | Discworld MUD lib (v3) | `dw_fluffos_v3.zip` | — | deprioritized |
| 902 | `tomud_vc` | TOMud VC++ 客户端源码 | `TOMud_VC源代码.rar` | — | not-mudlib |
| 903 | `sanguowaizhuan` | 三国歪传 (Diku/Merc) | `三国歪传.rar` | — | not-mudlib |
| 903-1 | `sgwcxz` | 三国歪传 (下载版) | `三国歪传下载.rar` | — | not-mudlib |
| 904 | `atlantis` | 消失的亞特蘭提斯MUD破解版 | `消失的亞特蘭提斯MUD破解版 (2).zip` | — | pending |
| 905 | `chongchujianghu` | 重出江湖 (C++ engine) | `重出江湖.rar` | — | not-mudlib |
| 905-1 | `chongchujianghu_win` | 重出江湖 WIN完全版 | `重出江湖WIN完全版.rar` | — | not-mudlib |
| 905-2 | `chongchujianghu_linux_src` | 重出江湖 Linux 源码 v2.71 | `重出江湖完整源码linunx_2.71原版.rar` | — | not-mudlib |
| 905-3 | `zcjh` | 重出江湖 | `重出江湖.rar` | — | not-mudlib |
| 905-4 | `zcjh271yb` | 重出江湖 2.71原版 | `重出江湖_2.71原版.rar` | — | not-mudlib |
| 906 | `mofaleidemuba` | 魔法类的泥巴 (EmberMUD) | `魔法类的泥巴.rar` | — | not-mudlib |
| 907 | `tianlongbabu` | 天龙八部 (incomplete archive) | `天龙八部.tgz` | — | not-convertible |
| 908 | `xianwukungfu` | 仙武kungfu (content module, not a mudlib) | `仙武kungfu.rar` | — | not-mudlib |
| 909 | `fsxy13` | 浮世侠影1.3 | `浮世侠影1.3.rar` | — | not-mudlib |
| 910 | `glhj` | 攻略合集 | `攻略合集.rar` | — | not-mudlib |
| 911 | `jyqs` | 金庸全索 | `金庸全索.rar` | — | not-mudlib |
| 912 | `kxkjii` | 狂想空間II (WWW版, PHP) | `狂想空間Ⅱ(www版).tgz` | — | not-mudlib |
| 913 | `lordstar40` | LordStar 4.0 | `LordStar4.0.7z` | — | not-mudlib |
| 914 | `mhjh10203` | 梦回江湖 1.02.03 | `梦回江湖1.02.03.rar` | — | not-mudlib |
| 915 | `sgqycoljc` | 三国群英传OL私服架设教程 | `三国群英传OL教程.rar` | — | not-mudlib |
| 916 | `szkf` | 神州开发 | `神州开发.rar` | — | not-mudlib |
| 917 | `wintin` | WinTin++ | `WinTin++.7z` | — | not-mudlib |
| 918 | `wlfymudsqyx` | 网路风云MUD社区游戏 | `网路风云MUD社区游戏.rar` | — | not-mudlib |
| 919 | `xjmhmudyx` | 星际迷航MUD游戏 | `星际迷航MUD游戏.rar` | — | not-mudlib |
| 920 | `xky2` | 侠客游2 | `侠客游2.rar` | — | not-mudlib |
| 921 | `xyj` | 西游记(三国群英传2mod) | `西游记(三国群英传2mod).rar` | — | not-mudlib |
| 922 | `xyjjqzl` | 西游记机器资料 | `西游记机器资料.rar` | — | not-mudlib |
| 923 | `yhwhckdm` | 炎黄武魂参考代码 | `炎黄武魂参考代码（d,kungfu,clone）.rar` | — | not-convertible |
| 924 | `yy` | 异域 | `异域.rar` | — | not-mudlib |
| 925 | `zjhd` | 指尖后端 | `指尖后端.7z` | — | not-mudlib |
| 926 | `zjwygjb` | 指尖网页改进版 | `指尖网页改进版（需要v2019驱动）.rar` | — | not-mudlib |
| 927 | `zxmudkhd` | 最新mud客户端 | `最新mud客户端.rar` | — | not-mudlib |
| 928 | `duobao` | duobao | `duobao.7z` | — | password-protected |
| 929 | `nitanpw` | nitan (加密版) | `nitan.7z` | — | password-protected |
| 930 | `dtxyzjb` | 大唐西游指间版 | `大唐西游指间版.rar` | — | password-protected |
| 931 | `wlqxcmudlib` | 武林群侠传 MUDLIB | `武林群侠传MUDLIB.7z` | — | password-protected |
| 932 | `swzf` | 谁与争锋 | `谁与争锋.7z` | — | password-protected |
| 933 | `xyzxwww0707` | 夕阳再现 WWW安装客户端 (20100707) | `夕阳再现WWW安装客户端Setup20100707.rar` | — | not-mudlib |
| 934 | `xyzxwww0718` | 夕阳再现 WWW安装客户端 (20100718) | `夕阳再现WWW安装客户端Setup20100718.rar` | — | not-mudlib |
| 935 | `zjmudv13` | 指间MUD V1.3 | `指间MUDV1.3.rar` | — | not-mudlib |
| 936 | `ptjnbxq` | 普通技能编写器 | `普通技能编写器.rar` | — | not-mudlib |
| 937 | `xlwebmud` | 西陆WEBMUD 仗剑江湖 | `西陆WEBMUD仗剑江湖.rar` | — | not-mudlib |
| 938 | `njhhdxfhzxth` | es2/xkx（南京河海大学，含纵横天下） | `南京河海大学的es2和xkx《包含纵横天下》.gz` | — | not-convertible |
| 939 | `zjmudouter` | zjmud (outer container) | `zjmud.7z` | — | not-mudlib |
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
