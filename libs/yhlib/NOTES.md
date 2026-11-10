# 炎黄2003 (yhlib) — 恢复笔记

## 来源

- `https://github.com/MudRen/YHLib`（炎黄2003 基线）
- Issue：GitHub `#19`
- 与 `yhyxs`（炎黄英雄史）同 70 个 `d/` 域，但 adm 源码哈希不同；作为标注的 2003 基库单独入馆

## Bring-up（2026-11-10）

1. `convert_lib.sh` GB18030→UTF-8、`.c`→`.lpc`
2. `config.fluffos`：port `40393`，mudlib → `work/`，global include 同手足 `yhyxs`
3. §8.1 / §15h：`adm/simul_efun/chinese.lpc` 的 `is_chinese` 改为 CJK 码点；`logind.lpc` 姓名长度/`maxlen/2`；组合名 `strlen(fname)<2`；`named.lpc` `invalid_new_name` 空名门槛与滑动窗口改为字符宽
4. `logind.lpc` `check_ok`：`find_object(MESSAGE_D)` 保护 `find_chatter`（手足同病：MESSAGE_D 未编译时时中断进世界，命令全「什么？」）
5. `clone/user/user.lpc`：`is_killing(ob)` → `is_killing(ob->query("id"))`（§15b 类型）

## 验证

- Boot：`Accepting telnet` on `40393`
- 注册 `yhlibbot` / 张三 → 世外桃源（水笙、狄云）；`look`；`quit`「欢迎下次再来」
- 重登普通密码成功

## 深度功能测试

（见下方 2026-11-10 重测。）

## §6.10 未知 `#pragma save_binary`（2026-11-10）

- Boot 普查：94 条 `Unknown #pragma, ignored`（`globals.h` 与各 daemon/feature 顶行）。
- 删除 60 个文件中的活动 `#pragma save_binary`（FluffOS 忽略该 MudOS 语用，无行为变化）。
- 证明：工作树 `lpcc --batch` 启动后 0 条 Unknown #pragma；仍有 nosave 函数 / 未用局部等其它类，另轮处理。

## §6.10 机械警告清理（2026-11-10）

- `lpc_warnings.py yhlib --fix`：1530 → 78 诊断（10941 可编 / 60 仍失败）。
- 本轮：`nosave` 函数 32→`protected`；未用局部 1369；`varargs` 补 50；裸 `return` 1。
- 启动证明：`lpcc --batch` 仅剩 1 条「Expression has no side effects」（dns_master），无 Unused local / nosave / Unknown pragma。
- 残留（另轮）：`set_information` 参数类型、questd11/util/damo 语法、`is_killing` 类型、无副作用表达式、全局重声明等。

## §6.10 `util.lpc` 缺 `<ansi.h>`（2026-11-10）

- `process_bar` 写 `"…" NOR` / `HIY` / `BBLU`，文件未 include `ansi.h`，且 `globals.h` 也不拉它 → `unexpected L_IDENTIFIER`。
- 补 `#include <ansi.h>`。同形语料扫：44 个 `*/simul_efun/util.lpc`（含 `adm/kernel/`）。
- 证明：本库 util 错误消失；手足 `yhyxs` 诊断 3→0。

## §6.10 `set_information` 第二参 `string`→`mixed`（2026-11-10）

- `inherit/misc/quest.lpc` / `include/quest.h` 把包装收窄为 `string`，任务文件传 `(: ask_npc :)` 时报 Bad type for argument 2；`QUEST_D` 本体已是 `mixed`。
- 改为 `mixed`；语料同形 39 处（quest.h / quest.lpc 包装）。手足 `yhyxs` 的 `.lpc` 早已改过，本轮补其 `.h`。
- 证明：yhlib `set_information` 诊断 36→0；可编 10942→10950。

## §6.10 `do_effect` 签名 `void`→`varargs int`（2026-11-10）

- `feature/{food,liquid}.lpc`（及 `feature/feature/` 副本）基类是 `void do_effect()`，叶子如 `fengmi`/`pigpart` 重载为 `varargs int do_effect(object me)` → 返回类型不符警告。
- 与手足 `yhyxs` 对齐：改为 `varargs int do_effect(object me)` 并 `return 1`。语料同形 23 文件（另修 wllz3 前向声明）。
- 证明：yhlib do_effect 警告消失（诊断 39→37）。

## §6.10 换行切断标识符 / `is_killing`（2026-11-10）

- `questd11.lpc`：`message_vision(...太差\n，" ... me, w\nho)` 与 `ob->na\nme()` / `ob->name(\n)+` 换行切断；与 `zhonghua2` 同修。首段语法错误已消。
- 同文件后部仍有多处中文串被换行切断（约 896+），另轮处理；勿用“奇数引号就拼接下行”的盲修（会切断 UTF-8）。
- `d/city/npc/guidao.lpc`：`is_killing(who)` → `is_killing(who->query("id"))`（原型为 `string`）。
- 证明：guidao 类型错误消失；questd11 不再在 300 行一带报错；可编 10950→10952。

## §6.10 damo 括号/缺引号 + questd11 ASCII 换行切断（2026-11-10）

- `inherit/condition/damo.lpc`：`! intp(cnd["remain"] || ! stringp(...))` 缺 `)`（语料 23 库同修）；另本库 `die_reason` 缺收尾 `"`，词法失步后表现为 224/277 假错误。
- `questd11.lpc`：ASCII 标识切断 `db\nase`、`fami\nly_name`、`experien\nce`、`["i\nd"]` 等 9 处（`zhonghua2` 同步）。
- 证明：damo 错误清零；可编 10953→10957。新露 `die_reason` 参数个数警告（叶子与基类），另轮。

## §6.10 die_reason varargs + 无副作用 `"\n";`（2026-11-10）

- `kungfu/condition/damo_{luanqi,shangshen,zheyuan}.lpc`：`string die_reason()` → `varargs string die_reason()`（对齐基类 `die_reason(string)`，同手足 yhyxs）。
- 地图 look 函数里 `NOR` 后多余的 `"\n";`：若上一行已是 `NOR;` 则删；若是无分号的 `NOR` 则改为 `NOR;`（该 `"\n";` 其实是整句的终止分号）。语料同形清理。
- 另：`combatd` 无意义的 `your_temp["guarding"];`；`swear`/`team/swear` 中 `$N";` 误终止导致下一串字面量悬空。
- 证明：yhlib 诊断 18→8；无副作用类仅剩 dns_master 的 `return;`。

## §6.10 残留警告清扫（2026-11-10）

- `indian.lpc`：`ma_sname`/`ma_pname` → `in_sname`/`in_pname`（与 `masia.lpc` 同编时不撞名）。
- `duka_3b`（及 `duka_3a`）：删重复的 `int peis=3` 行，留 `peis=4`。
- `swmuding`：`insects` → `sw_insects`，`create()` 里 `insects = sw_insects`。
- `qianzhenglun`：`count` → `my_count`。
- `ultra_questd`：`lvl = to_int(pow(...)-50)`。
- `dns_master`：去掉 void 函数末尾多余 `return;`（仍余 1 条无副作用，疑预处理空语句，另查）。
- 证明：诊断 8→1。

## §6.10 dns_master PREF_TELL 空 if（2026-11-10）

- `query_services`：`PREF_TELL` 为 `SVC_UDP` 时 `#if PREF_TELL & SVC_TCP` 为假，留下空 `if (...) { }`，报无副作用。
- 与 `PREF_MAIL` 同形：把 `if` 放进 `#if TCP / #elif UDP`，UDP 分支发 `send_support_q(..., "tell")`。
- 证明：`lpc_boot_survey` yhlib warnings 1→0。

## 深度功能测试（§10.7，2026-11-10）— 重测 + §7.61

手启：`build-debug`；端口 40393。

覆盖：注册 `fluffos` → `y` → 姓「张」名「三」→ 管理 `Adm@2026`×2 → 普通 `Mud@2026`×2 →
类型 `5` → `m` → 世外桃源（水笙、狄云）`look`/`inventory`/`who` → `east` 桃源竹屋 /
`west` 回桃源 → `quit` → 重连/`look`/`quit`。

同轮修：`adm/simul_efun/message.lpc` §7.61（quit/channel 的 `Bad argument 4 to EFUN message()`）。
修复后 quit 干净。驱动仍有 NPC `command_hook` 的 apply 权限提示与 socket_bind（另轮）。
部署 tip：`2655786aeb0`（§7.61 sweep 本体；本 NOTES 触达 Pages `libs/**` 路径过滤）。

## `if (per = 30)` 相貌描述恒真（2026-11-10，KB 06 §7.290）

`cmds/adm/watch.lpc`（及已跟踪的 `admBAK` 副本）女性分支 `if (per = 30)` 把相貌改成 30 且恒进「倾国倾城」句。改为 `per == 30`。对象可载入。

## `wasm_keep_dirs` 里 915 条空目录拖垮 Pages 部署（2026-11-10，KB 06 §7.358）

`gen_keep_dirs` 把本库磁盘上大量无跟踪文件的空目录（`kungfu/skill/<名>`、`d/`、`clone/` 等）都记进了 keep 表，共 915 行；打进 WASM `keepDirs` 后 GitHub Pages 的 `deploy-pages` 在 `syncing_files` 超时。裁成仅 `log/*`、`data/*`、`adm/log`。

## §7.282 比较链恒真/恒假（2026-11-10）

`d/mingjiao/shanmen.lpc`：`family != "明教" || != "武当派"` 恒真，上山持械检查对所有人触发。`d/tiezhang/hhyuan-3.lpc`：`arg != "瀑布" || != "pubu"` 恒真，`cross` 穿瀑布永远被拒。`lpc_fix_cmp_chain.py` 改为 `&&`。对象可载入。

## §7.296 `get_dir("*.lpc")` 后仍按 `.c` 剥后缀（2026-11-10）

`adm/daemons/eventd.lpc` / `storyd.lpc`：`map_array(..., (: $1[0..<3] :))` 只剥 2 字符，事件/故事名留下 `.l`，后续 `EVENT_DIR + event` 载入失败。改为 `[0..<5]`。`lpcc_eval`：`query_all_event()` 得 `emei` 等干净名。

## §7.302 旧 `runtime_config.h` 下 `get_config(__MUD_PORT__)` 是字符串（2026-11-10）

本库 `include/runtime_config.h` 仍是 `BASE_CONFIG_INT` 旧编号。`include/getconfig.h` 的 `LOCAL_PORT()` 与 `adm/daemons/versiond.lpc` 的 `get_config(__MUD_PORT__) + VERSION_PORT` 会得到字符串，`socket_bind` 报 Bad argument 2。改为 `__PORT__`。`lpcc_eval`：`LOCAL_PORT()` 为 int 45993；`versiond` 可载入。

## §7.283 `member_array('.', arg)` 字节搜索（2026-11-10）

`cmds/arch/sameip.lpc`（及跟踪的 `archBAK` 副本）用 `member_array('.', arg)` 区分 IP 与名字；对含非 ASCII 的串会告警且偏移按字节。改为 `strsrch(arg, ".")`。对象可载入；点分 IP 得正下标、纯名字得 -1。

## §7.349 死 `add_action` 残留（2026-11-10）

`adm/npc/referee.lpc` 的 `do_halt`、`clone/megazine/obj/maikaren.lpc` 的 `do_drop`、`d/tianlongsi/munitang.lpc` 的 `do_exit`、`d/wudu/huxue2.lpc` 的 `do_train`、`inherit/misc/fboard.lpc` 的 `do_list`：注册的处理函数本对象与继承链均无定义。删除整行 `add_action`。
