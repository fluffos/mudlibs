# KB 09 — Lineage map and driver reference (§11–§12)

## 11. Lineage map: who shares code with whom

Porting a proven fix to a sibling is the biggest time-saver (§2.1).
Families below were established by real core-file diffs, never by
titles. When you fix one member, check the rest.

- **ES II / 东方故事 mega-family.** Expect §6.1, §8.1, §7.12, and §4.3.
  - `es1`/`es1_win`/`esI` (008).
  - Distinct ES II-derived games: `xkx2001`/`bmxkx2001` (017),
    `xuanjianlu` (046), `rzrmud` (016), `wuhanzhan` (040),
    `haiyang2`/`hymud` (043), `huoying` (044, Neolith), `shenzhou`
    (048), `shenmo` (049, Neolith), `zitengzhan` (051), `zhongjidiyu`
    (052), `xixingzhanji` (054), `tiexuejianghu` (056), `syxjl` (057),
    `mohuanshiji` (058), `yueyingqiyuan` (037), `yxcs` (042, hybrid),
    `xkxz2` (028), `dfgs2` (022), `zzhj` (061, by "Spock").
  - `kxkj`/`kxkj1`/`kxkjii2` (036): ES II/Annihilator. Has the §7.101
    bug, still unfixed on `kxkj`. `xajdxyj` (107) is a distant sibling.
  - The ES2 "Annihilator" AREA engine: `naruto`, `huoying`, `zhyx`,
    `demonangel`, `es2`.
- **西游记 / xiyouji.org branch.** Has the §6.6 convertd table and §7.6
  gates.
  - `xiyouji` (010), plus `xyj2000f`, `xiyouji2003`, `xiyouji450`,
    `xiyouji2006`; `mhxy`/`mhxyqd` (012).
  - Far forks: `shenmo`, `wuhanzhan`, `aoxiangtianji` (063).
  - The `xyj4.5` siblings: `xyj2006n`, `xyj451`, `xyj2006zzzhx`.
  - The 小雨西游 trio: `xyxyutf8`, `xiaoyuxiyou`, `xyxy2`.
- **yh2003:** `yanhuangwuhun`/`yhyxs` (045), with `yhwhpublicfi` as an
  independent fork.
- **金庸群侠传 engine:** `jqxz2008`/`_std`/`_dlx`/`2015`/`xiakexing3`
  (031). The engine was frozen across 7 years, so fixes port 1:1.
  - `jyqxc`/`jyqxc2` are effectively the same codebase (a missed "(1)"
    duplicate). Port every fix to both.
  - `jyqxc2013fwq` is a sibling.
- **书剑:** `bxsj`/`bxsj1`/`jinyongwenzi` (004). Unrelated to
  `shujian2008`/`sjtx2`/`sjecl` (Century) and `sjpl2`.
- **Century / adm-single.** Custom ACLs; §7.5 applies.
  - Members: `shiji` (021), `shujian2008` (024), `xjcq2000` (027),
    `xkxz2`, `xiakexing100` (030), `zhonghua2` (023), `ldtx`/`ldtxii`,
    `sje`.
  - The bulk-convert subset (§7.42): `zjdywzb`, `zjdy2008wzb`, `hell`,
    `xkxc98sj`, `ntii`, `nte`.
- **风云 family.**
  - 风云3: `zzfy`/`zzfy3` (near-duplicate operator copies; check both
    directions when fixing), `fy3xd`/`fy3dz` (020).
  - 风云Ⅳ: `fengyun434`/`fy2005` (009).
  - 风云再起Ⅱ: `fy2`/`fy2qh`/`fy2mg`.
  - Also `fy330`, `xsfyssjb`/`fysjmb`/`wqfy`, `sjpl*` (§7.199 money).
  - `moniHuafu` (039) is its own game.
- **夕阳再现:** `xyzxfk`/`_fengyun2`/`jhfy` (032); derived games `wmkj`
  (038), `bixiecanyang` (047), `xajhzcjh` (050). XYZX/炎龙封印:
  `xyzx3`/`ylfyxa3`/`longyunmeng` (033) and the
  `yzxiiizylfy`/`xyzxiiylzymh`/`xysylmhb`/`jhfy2` siblings.
- **XO / TMI-2 / Falcon:** `xo`/`xo_final`/`xajh2`/`xajhxo` (019). NOT
  nitan. `qhxajh` belongs to the same engine family.
- **NT / nitan / Lonely:** `nitan170911` (014), `nitan6` (015), `nt6`,
  `nt6nitan6win`, `hhsj`, `xfbhh`, `nt1`, `wdxtym`. §7.15, §7.78, and
  §7.79 apply. `nitan_ceshi`/`nitan_san` (041) predate §7.15.
- **"hell" / Doing Lu:** `hell`, `zjmudhell`, `zjdyaryl`/`zjdyzj`
  (053), `xkxc98sj`, `revive`, `xuanjianlu`-adjacent idioms. `zhongjidiyu`
  is unrelated despite the same title. `xkxc98sj` is NOT `xkx100`/
  `xkx2017`.
- **XLQY 仙侣情缘:** `xlqy_new2007`/`xlqy_early`/`xlqyzdb` (018).
  `xianlvqiyuan` (026) is a different codebase.
- **大唐双龙:** `dtsl`/`dtslmud`/`dtsl2` (007).
- **小雪初晴:** `xxcq`/`xxcqii`/`xxcqii2`. `xxcqii2` is NOT
  byte-identical to `xxcqii`, despite old notes saying so.
- **天涯 map family:** `tybxjh`/`xhcii`/`zxty`/`zxty08nxgbb`/`ffxymud`/
  `jhfy2`/`wlhd`/`yxjh`.
- **驰骋天下:** `cctx` (066) and `niaoren` (062), which are the same
  codebase (`niaoren` still reads `/adm/etc/cctxinfo`).
- **English stacks:**
  - Dead Souls 3.x: `ds386`, `dsIII`, `dshakkard`, `deadsouls_fluffos`,
    `riftsds`.
  - Nightmare-IV: `dsI`, `dsII`, `nightmare4`.
  - `nightmare3`/`residuum`/`foundation1`/`foundation2`.
  - Genesis/CD: `genesis`, `arkadia`.
  - LPUniversity: `lpuni`, `dock9`.
  - DarkeLIB: `darkelib`, `rifts2`.
  - TMI-2: `tmi2`, `mortremains`.
  - Lima: `lima`, `swmud`, `spacemud`, `wilderness`, `sgzmudsgz`
    (145, not `sanguozhi` 162).
- **Standalone:** `shzs` (001), `xzyx`/`shiji` (same game), `chidi`
  (005), `xiakexing2017` (013), `tianxia` (034, which is also
  `MudRen/txmud`; don't onboard that twice), `tianxiawuxue` (035),
  `xkyx3b` (029), `zsdsj` (055), `sjcs` (059) and `sanjieshenhua`
  (060), which are not a pair.
- **Duplicates:** byte-identical archives share a number via
  `duplicate_of`. A dedup by container bytes misses re-packed duplicates,
  so diff the extracted trees.

---

## 12. Driver reference: local patches and builds

There are three builds from `~/src/fluffos`. To rebuild after
`git pull`:
```
cd ~/src/fluffos/build-debug && cmake --build . --target driver lpcc -- -j8
```
Boot one known-good lib before trusting a rebuilt binary.

Driver patches this project depends on (all merged upstream). Verify
them with `git log`:
1. A null `backbone_domain` guard in `mudlib_stats.cc` (boot segfault
   in `init_domain_for_ob`).
2. `MAX_EXPANSION_NESTING`/`kMaxExpandStringDepth` raised to 1024.
3. `lpcc --batch` with a per-file `set_eval()` re-arm.
4. WASM `query_ip_number`/`resolve` fixes (§1.3a).
5. The `lpc-syntax` formatter and its three fixes (§9).

**`MARCH_NATIVE` defaults to ON in `build-debug`.** On older host
hardware the binary dies with SIGILL: exit 132, no output at all,
identical for every lib. Rebuild with:
```
cmake -S ~/src/fluffos -B ~/src/fluffos/build-debug -DMARCH_NATIVE=OFF && cmake --build ~/src/fluffos/build-debug -- -j8
```

Custom per-lib drivers (Lima flags): see §7.46.

### 12.1 The WASM web terminal
`src/www/wasm/index.html` in the fluffos repo is mirrored byte-for-byte
at `scripts/web_shell_override/index.html`, which `write_play_page.sh`
prefers. **Keep the two identical.** Re-diff them right before
committing.

Features:
- multi-connection Game tabs and a Logs tab;
- a `visualViewport`-synced keyboard-safe input bar;
- a boot progress bar driven by `Module.setStatus`'s download string;
- compact chrome below 620px of visible height;
- a feature-detected fullscreen toggle driven by `fullscreenchange`.

Verify visually with Playwright and Chromium
(`pip install --user playwright && python3 -m playwright install chromium`).
Emulate real touch (`pointer: coarse`); static CSS review has missed
real bugs.
