# xo_final — 笑傲江湖最终版1.2 (The Smiling, Proud Wanderer — "Final" Edition)

Archive: `xo最终版1.2.rar`. Port: 40024. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese name).

## What this is

Same TMI-2/ES2 (Falcon) lineage as `xo` (#28), but the full, un-trimmed
"final" build — ~7,174 `.c` files vs `xo`'s 1395 "mini edition". Same
`secure/daemon/{master,sefun}` layout. A homebrew test-station banner
("自玩测试站... 本lib是在mini xo基础之上，全新设计开发而成") confirms this
is a fork built on top of the mini edition.

## Fixes applied

1. **AGENTS.md §4 (lazy security-daemon load)**: applied proactively to
   `secure/daemon/master.lpc`'s `valid_write`/`valid_read`, same shape as
   `xo`.
2. **AGENTS.md §15h (GBK byte-range Chinese detection)**: `secure/sefun/
   chinese.lpc`'s `is_chinese`, `system/daemon/band.lpc`'s `IsLegalName`,
   and `system/daemon/logind.lpc`'s length checks all fixed to the CJK
   codepoint range / halved character-count bounds, applied proactively
   from the catalog before first boot.
3. **New: "comment eats next line" typo**, found twice — a Chinese-text
   comment line with no leading whitespace runs `//` right into the start
   of the *next* physical line's code, silently deleting a function
   declaration and leaving a dangling `{`:
   - `system/skill/basic/kongshou.lpc`: `// ...int is_native_skill()\n{`
   - `d/menpai/shaolin/npc3/hui_quest.lpc`: `// ...if ( random(...) < 100 )`
   Both fixed by moving the comment to its own line above the code.
4. **Lossy GBK→UTF8 conversion corruption**: `convert_lib.sh`'s `iconv -c`
   pass silently drops genuinely-invalid byte sequences in some raw `.c`
   files, occasionally eating a string literal's closing quote (breaking
   syntax) and sometimes leaving behind invisible Unicode Private-Use-Area
   characters (``, ``) that defeat exact-string `Edit` calls.
   Surveyed the whole tree with `iconv -f GBK -t UTF-8` against the RAW
   pre-conversion files to find every instance (33 total flagged,
   most cosmetic/non-fatal); confirmed and fixed the ~8 in `system/skill`
   that actually broke compilation, reconstructing each closing quote
   from context (sibling "action"/"lian"/"zhaoshi" fields' patterns):
   `mohe-zhi.lpc`, `yuanyang-dao.lpc`, `taizu-quan.lpc` (two spots),
   `dagou-bangfa.lpc`, `dugu-jiujian.lpc`, `baye-zhui.lpc`. The two with
   hidden PUA characters needed Python line-index read/write instead of
   the `Edit` tool's exact-substring match.

## Interactive test result — full registration flow

Verified the complete registration path in one continuous connection
(critical per the user's explicit instruction not to stop at "reaches a
prompt"):

1. `new` → `欢迎光临笑傲江湖3` / English-name prompt.
2. English id (`myxoidfull`) → passes `IsLegalID`, reaches the
   "确定吗(y/n)？" confirmation.
3. `y` → reaches the Chinese-name prompt.
4. **Real Chinese name `赵云`** → accepted (no rejection message),
   proceeds straight to "请设定您的密码：" — this is the actual proof the
   §15h fix works, not just that the prompt renders.

Also confirmed (as expected, not a bug): empty input at the English-name
prompt triggers a polite disconnect; `BAN_D->IsTimeAllowed`'s anti-flood
throttle (3 real minutes between `new` registrations from the same IP,
enforced via an in-memory `NewIps` mapping in `band.lpc`, cleared by
restarting the driver) rejects a second `new` attempt from the same
source within the window with **no output at all** (`die()`'s error
message is commented out at `logind.lpc` — this is intentional silence,
not a swallowed error; don't mistake it for a bug when retesting).

## lpcc sweep

**Memory warning (new data point for AGENTS.md §6b)**: this ~7,174-file
lib drove the host to ~214MB free / 18.8GB RSS on the `lpcc` process
after ~12 minutes despite being far smaller than the previously-documented
"tens of thousands of files" nitan-family threshold — file count alone
does not predict memory blowup risk. Monitor `free -h`/process RSS on
*any* sweep, not just presumed-large ones, and kill proactively if
pressure gets severe. Reached a clean boot (zero compile errors in the
boot log) after the fixes above.

## 2026-07-23: driver rebuild retest + LPC formatter + WASM check

- **Formatter**: ran `tools/lpc-syntax`'s `format-corpus.mjs` over all
  7174 `.lpc` files in `work/`; 7154 written, 9 already-conformant, 11
  errors (files it refused to touch, expected/fine on legacy code).
  Confirmed the `__OLD_ED__`-compat rewrite in `system/feature/user/
  editor.lpc` and the (disabled) `private`/`nosave` compatibility shim
  in `include/globals.h` both survived the reformat unchanged in
  substance.
- **Native retest**: rebuilt `~/src/fluffos/build-debug/src/driver`
  booted clean (zero fatal `debug.log` errors). Ran a **full
  end-to-end registration + play session** in one continuous
  connection with a real Chinese name (赵云): English id `zhaoyun` →
  confirm → Chinese name → password → email → gender all completed,
  dropped into the newbie training area (新手培训站); `look` showed the
  correct room, `score` produced a correct full character sheet,
  `quit` correctly enforced the "10 real minutes before saving" gate.
  One operational note (not a bug): this lib's `BAN_D->IsTimeAllowed`
  anti-flood throttle (documented in the original pass) meant a second
  `new` attempt shortly after a first one from this same host got
  silently ignored — resolved by restarting the driver (clears the
  in-memory throttle map) rather than waiting out the real-time window.
- **WASM**: booted cleanly (only the expected non-fatal
  `socket_create`/`socket_bind`/`socket_connect` preload warnings from
  the missing `sockets` package). **Full registration + play flow
  completed successfully end-to-end under WASM** — real Chinese name
  赵云乙, English id/confirm/Chinese name/password/email/gender all
  completed, dropped into 新手培训站 exactly like the native run;
  `look` and `quit` both worked correctly (10-minute save gate
  correctly triggered its confirmation prompt). Notably, this lib's own
  `enter_world()`/registration chain — despite being near-identical in
  shape to its `xo` (#28) sibling's — does **not** exhibit the
  world-entry hang `xo` shows under the identical WASM harness (see
  `xo`'s own NOTES.md). **Verdict: fully playable under WASM**, no
  issues found.

## WASM-enablement pass (loopback-allow / gate bypass / admin seed)

Standard WASM-first pass per AGENTS.md §1.3b/e and §1.5. Gates patched
(all in `system/daemon/band.lpc`, the live BAN_D — `xoban.lpc` is
orphaned/unreferenced, left untouched):

- Added `IsLoopbackSite(string)` helper (loopback / empty / malformed-IP
  → local).
- `IsBannedSite()` (~line 126) — loopback short-circuit `return 0;`.
- `IsMultiLogin()` (~line 214) — loopback exempt (`return 0;` = allowed).
- `IsTimeAllowed()` (~line 244, the 3-minute per-IP new-registration
  throttle whose rejection used to look like a silent stall) — loopback
  exempt (`return 1;` = allowed). Verified: two back-to-back `new`
  registrations from 127.0.0.1 both succeeded.
- `logind.lpc`'s `LOGIN_DELAY` startup gate is compiled out (macro never
  defined) — noted, no change. `uptime() < 10` there is cosmetic banner
  text, kept. The 10-minute new-account quit-retention prompt is a
  content timer, kept per policy.

Admin account seeded: id `fluffos`, pw `Mud@2026`, name 浮浮, granted
`(admin)` via `fluffos (admin)` appended to `secure/etc/wizlist`.
Verified: real registration (new/fluffos/y/浮浮/pw×2/email/m → landed in
新手培训站, auto-save fired), relogin as fluffos →
`update /system/daemon/band` → 成功, `score` correct. Retest: two fresh
normal registrations (秦风 m, 秦岚 f) end-to-end; test char saves
removed; zero new debug.log errors. Note: this lib's email prompt
actually validates format — `a@b.c` is rejected, use a normal-looking
address. Save file: `work/data/user/f/fluffos.o` (NOT gitignored —
normal add, no force-add needed).


## Fail-closed retrofit for the loopback-allow gate (2026-07-24)

The loopback helper above was originally written matching the
project-wide convention at patch time (AGENTS.md §1.3b), which also
treated an empty/non-string/malformed `query_ip_number()` result as
loopback, defensively, because the WASM driver used to return garbage
there. That underlying driver bug is now fixed (fluffos commits
`e33bb5da` "fix: query_ip_number() returned uninitialized garbage under
WASM" and `007bb863` "feat: synthetic resolve() on WASM instead of
raising an LPC error", both 2026-07-23; the locally-built
`build-debug`/`build-wasm` binaries already postdate both commits), so
treating unparseable IPs as trusted is a fail-open gap with no remaining
justification. Retrofitted to fail-closed: loopback is now strictly
`ip == "127.0.0.1" || ip == "::1" || ip[0..3] == "127."` (with a
`stringp()` guard before the slice) — a malformed/empty IP now falls
through to the NORMAL gate instead of being treated as local. Retested
after tightening: fresh driver boot clean, `fluffos` loopback login and
its wizard `update` command both still work; zero new debug.log errors.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一血统，完整的'final'构建版本。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 13 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (2026-08-07)

第一次真正的完整游玩测试（此前几轮都只验证了注册/`look`/`score`/`quit`
和管理员登录，没有实战、门派、持久化）。测试角色 id `xofdeep`，中文名
云梦仙，拜入峨嵋派后法号"静仙"。本轮 WASM 未重新验证：emsdk 工具链下
载硬编码指向 `storage.googleapis.com`，本次会话的出口代理策略性拒绝该
域名（403，已用 `curl $HTTPS_PROXY/__agentproxy/status` 确认是策略拒
绝而非临时故障），本地无法构建 WASM 驱动。

本档案体量巨大（~7,174 个 `.lpc` 文件），原生 debug（ASAN/UBSAN）驱动
下几乎每条指令第一次触发某个尚未编译过的文件时都会有数秒到十几秒的
延迟（不是死锁，只是懒编译开销大），测试过程中多次原样等待而非误判
为卡死。

### 发现并修复：`toptend.lpc` 的排行榜数据文件缺失时，每一次玩家登录都会崩溃（AGENTS.md §7.54 已知模式的又一实例，触发原因是错误的 `file_size()` 判断值而非完全没有判断）

- **症状**：`debug.log`（首次触发时，修复前）记录了一条完整的登录期崩
  溃：
  ```
  *Bad argument 1 to explode()
  Expected: string Got: 0.
  函数调用堆栈：
  get_passwd()             /system/daemon/logind.lpc:235
  enter_world()            /system/daemon/logind.lpc:607
  topten_checkplayer()     /system/daemon/toptend.lpc:40
  topten_add()             /system/daemon/toptend.lpc:354
  ```
  `logind.lpc` 的 `enter_world()`——每一次玩家真正进入游戏世界都会调用
  ——无条件调用 `toptend_checkplayer()`，后者又为年龄/杀人数/内功/拳
  法/轻功/剑法/刀法/短兵刃/长兵刃/经验/钱财/总纲这 12 项排行榜各调用
  一次 `topten_add()`。
- **根因**：`topten_add()`（第 344 行）用
  ```lpc
  if (file_size(f_name) == 0) {
    ... // 写一份全新的排行榜文件
  }
  //主要程序！
  ...
  str = read_file(f_name);
  astr = explode(str, "\n");
  ```
  只处理了"文件存在但大小为 0"的情况，没有覆盖`file_size()`返回 `-1`
  （文件根本不存在）的情况——而 `libs/*/work/data/topten/` 这整个目
  录在项目的 `.gitignore` 里被标记为"可重新生成，不纳入版本控制"
  （`# Lib similarity/lineage analysis data -- regenerable via ...`
  一节）。也就是说这不是这份归档特有的缺陷，而是**任何一次真正的全
  新 `git clone` 都会必然触发**：`file_size()==-1`（不等于 0）→ 落
  入下面的"主要程序"分支 → `read_file()` 对不存在的文件返回整数
  `0`（不是空字符串）→ `explode(0, "\n")` 抛出上面的错误。同一文件
  里另外两处功能类似的读取（`topten_query()` 第 125 行、`topten_del()`
  第 243 行）都正确地写的是 `file_size(f_name) == -1`，证明这是那一
  处判断值写错了，不是设计上刻意如此。
- **修复**：把第 344 行的判断从 `== 0` 改为 `<= 0`，同时覆盖"文件不
  存在"（-1）和"文件存在但是空"（0）两种情况——两种情况原本要走的
  都是同一个"写一份全新排行榜"的回退分支，改动后不影响任何"文件已
  有正常数据"的路径。`§9` 格式化自检通过
  （`{"total":1,...,"unchanged":1,"errors":0}`），3 处格式化盲点检查
  干净。
- **验证**：修复前用刚重启的驱动新建/重连测试角色，`debug.log` 每次
  都稳定复现上面的崩溃（`enter_world()` 是任何一次真正登录都会走的
  路径，不需要特殊操作触发）。修复后重启驱动、清空的
  `debug.log` 里，无论是新注册还是重新登录已有角色，全程零次
  `Bad argument`/`explode` 相关错误。因为该驱动本身有"mudlib error
  handler"接管未捕获异常并继续执行的兜底机制，这个崩溃此前并不会中
  断登录流程本身（角色仍能正常进入游戏），但会在**每一次登录**都往
  `debug.log` 里写入一条完整的崩溃现场，而且意味着排行榜功能对一个
  全新归档来说从第一次运行起就是坏的。已加入 AGENTS.md §7.54 作为
  该模式的又一实例（同文件已有的姊妹判断用的是正确的 `== -1`，是很
  好的"检测正确写法就在同一个文件里"的例子）。

### 观察但未修改：库存列表中某个物品的 ANSI 颜色码首字节（ESC，0x1B）在发送给玩家的字节流里神秘缺失，怀疑是驱动层问题，未能定位根因

- **症状**：新角色起始物品"百宝箱(Box)"在 `i`（inventory）指令的输
  出里，颜色码 `HIG`（`ESC+"[1;32m"`）的 ESC 字节完全缺失，玩家实际
  看到的是裸露的字面文字 `[1;32m百宝箱`，而不是绿色高亮的"百宝箱"。
  用绕开 tmux/nc 终端渲染的原始 Python socket 抓包核实过：这不是终端
  渲染问题，服务器实际发送出去的字节流里确实少了那一个 ESC (0x1B)
  字节——`\r\n` 后紧跟的恰好是 `inventory.lpc` 自己硬编码的两个空格
  前缀，然后直接是 `[1;32m` 的文本字节，中间没有任何 ESC。同一条
  `i` 输出里，另一件装备物品的颜色码（`HIM`，`ESC+"[1;35m"`）完全正
  常，ESC 字节俱全；这件"百宝箱"自身的收尾重置码 `NOR`
  （`ESC+"[2;37;0m"`）的 ESC 字节也完整——只有这一处开头的 `HIG` 丢
  了 ESC。
- **已排除的可能原因**（逐层核实过源码/字节，均未发现问题）：
  1. `clone/misc/box.lpc` 源码本身（`set_name(HIG "百宝箱" NOR, ...)`）
     ——用 `od -c` 核实过字节完全正确，`HIG`/`ESC` 宏也是正常引用。
  2. `include/ansi.h` 里 `ESC`/`HIG` 宏定义——同样 `od -c` 核实过，
     `ESC` 内含真实的 `\033` 控制字节。
  3. `inventory.lpc` 的渲染逻辑（`"  " + $1->short()`）——纯字符串拼
     接，没有做任何可能吞字节的处理。
  4. `system/feature/base/name.lpc` 的 `short()`（`box.lpc`
     实际继承链上真正生效的那个）——只对 `id`（"box"→"Box"）调用了
     `capitalize()`，从不touch颜色化的 name 字符串本身。
  5. `logind.lpc:522-523` 把百宝箱发给玩家的方式是普通的
     `new("/clone/misc/box"); mb->move(user);`，不经过 `command()`/
     输入解析，不会碰到驱动里那个专门为"防止玩家在聊天里注入 ANSI
     转义码"设计的、默认开启的输入端 ESC 过滤逻辑（`comm.cc` 的
     `on_user_input()`，配置项 `no ansi`/`strip before process
     input`）——而且那个过滤逻辑是把 ESC 替换成一个空格字符，不是整
     字节消失；实测字节里 `\r\n` 后只有两个空格（正好等于
     `inventory.lpc` 自己那个硬编码前缀的长度），不是三个，从字节
     计数上也确认不是这条路径。
  6. 编译期的字符串常量折叠（`compiler/internal/
     grammar_rules_exprs.cc` 里 `"str1"+"str2"` 字面量在编译期合并
     那一段代码，`NODE_STRING` 分支）——追踪了 `ScratchString`/
     `store_prog_string()`/`findstring()`/`alloc_new_shared_string()`
     （`base/internal/stralloc.cc`）整条链路，这些都是基于
     `strlen()`/`strcmp()` 的传统"NUL 结尾共享字符串"实现；我们这段
     被拼接的字符串里没有任何嵌入的 NUL 字节，所以于理不应该被这条
     链路的任何一环误判/截断。
  同一条崩溃现场的调试信息（前一条 bug 修复前抓到的 `debug.log`
  crash trace，打印函数调用栈里各个参数对象的可读名字时）也显示了完
  全一样的缺陷（`/clone/misc/box#5 ("[1;32m百宝箱[2;37;0m")`），说明
  这不是"仅在 `i` 指令这一条输出路径上偶发"，而是这个对象的 `name`
  属性本身，无论从哪条打印路径读取，都已经缺了这个字节——更倾向于是
  运行时字符串存储层面的问题，而不是某一处具体的输出格式化代码的问
  题。
- **为什么没有继续深挖**：排查已经超出了这份 mudlib 归档本身能覆盖
  的范围——上面所有排除项都指向 fluffos 驱动（`~/src/fluffos`，本项
  目里近百份档案共用的同一份驱动代码）的 C++ 运行时内部，而不是这份
  归档自己的 `.lpc` 源码或配置。要继续定位真正的根因，需要给驱动加
  实际的运行时调试（断点/打印）并重新编译，这已经不是"读源码就能确
  认"的范畴，而且即便确认了，修复也应该落在 `~/src/fluffos` 里并对
  这个项目共用同一驱动的全部档案做回归验证，不是这一次单库深潜任务
  的范围。如实记录为一个已充分排查、但未能定位根因的观察，代码未作
  任何改动。

### 测试内容与结果

- **注册**：`new` → 英文名 `xofdeep` → 确认 `y` → 中文名（云梦仙）→
  密码 ×2 → 邮箱 → 性别（f）→ 顺利进入起始房间〖新手培训站〗，`help
  newbie`（真正的新手指南入口是 `help start`→`newbie`，`help new`只
  是更新日志）、`help menpai` 均正常显示门派列表。
- **门派/技能——组织路线（拜师）**：少林派（`d/menpai/shaolin`）的两
  个候选拜师对象（法堂执事慧觉、僧人虚音）都以"女施主不要跟贫僧开
  这种玩笑"拒绝了女性角色——这是少林（僧人门派）刻意设计的性别限
  制，不是 bug（少林派 NPC 的 `accept_teach`/对话逻辑本身可以正常
  compile 运行，只是业务逻辑拒绝）。改为峨嵋派（`d/menpai/emei`，历
  史原型即为女性门派）——`apprentice miejue shitai`（灭绝师太，峨嵋
  派第三代掌门人）一次成功，获得法号"静仙"、门派/师承/`generation`
  字段全部正确写入并在后续 `score`、真实驱动重启后都保持一致。
- **技能——请教（qingjiao）**：`qingjiao lao cunzhang jiben-quanfa`
  两词形式因为 NPC 别名"lao cunzhang"本身带空格、被
  `sscanf("%s %s", master, skill)` 贪婪匹配成 `master="lao"`（不存
  在的单词，present() 找不到）而失败——但 `qingjiao jiben-quanfa
  from lao cunzhang` 的 `from`语法（`sscanf("%s from %s", skill,
  master)`，`master` 部分是贪婪匹配到结尾）正常工作，是命令本身就
  提供的两种写法之一，帮助文档里也写了两种格式都存在，不是 bug。
- **安全陪练/对练（duilian）**：`duilian miejue shitai`——真实的、非
  致命的对练交锋，命中会有轻微划伤但不会真的重伤/死亡；持续对练一
  段时间后角色因为体能耗尽而"眼前一黑，接着什么也不知道了……"（昏迷）
  ，`hp`面板正确区分了"方格=消耗程度（体能条清空但很快恢复）"和"百
  分数=内伤外伤程度（这里仍是 100%，代表没有真正受伤）"——帮助文本
  （`help hp`）明确写了这个设计，不是 bug。`system/feature/char/
  damage.lpc`的`unconcious()`会正确排一个 30+秒的`call_out("revive",
  ...)`，实测约 1 分钟后角色自动苏醒、恢复行动能力，不是永久卡死。
- **持久化——异常驱动重启后重连**：会话过程中容器/驱动两次意外重启
  （与本次深潜无关的环境因素），其中一次重启发生在角色刚好处于"对
  练昏迷"状态时存档——`disable_type` 属性的 `"<昏迷不醒>"` 字符串确
  实原样保存进了存档文件，但重连登录时角色可以正常行动（`score`等
  指令立即可用），并没有卡死：`disable_type`只在`!living(who)`（当
  前真的还在昏迷状态）时才会被读取用于展示，登录流程本身走的是
  `enable_player()`重新挂载所有指令，跟这个残留属性值无关——是稳健
  的设计，不是 bug。门派/师承信息在两次异常重启后都完整保留。
- **持久化——正常 `quit` 后重连**：`quit` 正常触发存档提示（"保存玩
  家档案中…"），重连后 `score` 显示的门派、法号、天赋数值与 quit 前
  完全一致；固定回到起始房间〖新手培训站〗而不是 quit 时所在房间
  ——与本项目其它已测试档案的既定设计一致，不是位置持久化 bug。
- **管理员账号**：`fluffos`/`Mud@2026` 登录成功（Wiz motd 正确显
  示），`update /system/daemon/toptend`（本轮修复的文件）热更新成功
  （"重新编译 ... 成功！"），确认写 ACL 正常。
- **观察但未处理（超出"仅修程序 bug"范围）**：`mygiftd.lpc` 里定义
  的新手引导任务链（`mygift` 指令，"了解如何开始玩游戏"等共 90+ 项
  任务）依赖的"条件标识"（如 `newbie_mygift/help`、`newbie_mygift/
  map`……）在全档案里几乎从未被任何代码实际置位——仅有的两处相关引
  用（`maze/forest/out.lpc`、`system/daemon/zhoutiand.lpc`）都是被
  注释掉的 `MYGIFT_D->check_mygift(...)` 调用。也就是说这条任务链
  第一步之后大概率永远无法自然达成、拿不到后续奖励。这更像是一个未
  完工的内容功能（需要决定在哪些指令里补上 `check_mygift()` 调用，
  这是内容/设计判断，不是"明显写错的一行代码"），如实记录为观察，
  未作改动。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM STD_DIR "room/room"`（`STD_DIR` = `/system/std/`，宏
名本身仍是字面量 `ROOM`，源码里的调用不受拼接影响）：删除 615 处
多余的、独立成行的 `replace_program(ROOM);`（保留 `inherit
ROOM;`），全部由脚本自动删除。本库没有任何在游戏内建造房间的工具
（`roommaker`/`rmmaker` 等名称均未找到），因此没有"工厂"侧需要修
复。修复后全库仅剩 11 处历史遗留的 `//`-注释掉实例，均确认无害、
未改动。已用 `build-debug` 驱动干净启动验证（0 个新增编译错误，端
口 40024 正常监听，`debug.log` 无新增 "cannot replace"/"cannot
bind" 行）；未做完整 §10.7 深度游玩测试。
