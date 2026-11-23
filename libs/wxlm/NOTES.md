# 武侠黎明 (wxlm) — 移植笔记

- 来源：`https://github.com/lude2001/wxlm`（Issue `#31`），炎黄 / 地狱（指文游之终极地狱）系武侠 MUD。
- 编号：**199**，端口：**40404**，托管方式：`vendored`。

## 1. 源码清理与编码转换

- 运行 `convert_lib.sh` 将全部源码由 GB18030/UTF-8 统一转换为 UTF-8 并将 `.c` 规范为 `.lpc`，清理上游携带的 `.duchang.c.swp`、`.gitattributes`、`familyd.c.bak` 及扫描产物 `trace_lpcc.json`。
- `convert_lib.sh` 全局替换 `static->nosave` 误伤了部分非修饰符文本，已逐一还原：
  - `include/globals.h` 第 18–24 行 `#ifndef __SENSIBLE_MODIFIERS__` 块（被改写为 `#define static nosave`）；
  - `system/baoshi_huishou.lpc`、`clone/vip/wusheng_book.lpc`、`clone/vip/equipment_opener.lpc`、`clone/baoshi/equipment_opener.lpc` 中路径字符串字面量 `"nosave/"` 还原为 `"static/"`；
  - `include/net/ftpdsupp.h` 中的 `dot_match` 原型改用 `protected int`。
- 使用 FluffOS 驱动自带 `src/include/runtime_config.h` 替换陈旧的 `include/runtime_config.h`。
- 经 `scripts/check_ntfs_paths.py -v libs/wxlm` 验证：`non_utf8=0`、`illegal=0`、`case_file_dups=0`、`case_dir_dups=0`、`file_vs_dir=0`。

## 2. 编译警告清理与驱动 / WASM 兼容

- **JSON 仿真函数与 HTTP 包守卫**：从 `libs/fy2005` 引入 `adm/simul_efun/json.lpc` 并补充 `json_format(string str)`，在 `adm/single/simul_efun.lpc` 中启用 `#include "/adm/simul_efun/json.lpc"`；对 `external_system_package/http/controller/{httpd,http_send}.lpc` 及 `adm/single/simul_efun.lpc` 中的 HTTP 入口加上 `#ifdef __PACKAGE_HTTP__`。
- **`.c` → `.lpc` 后缀长度切片修复**：将 `adm/daemons/eventd.lpc`、`adm/daemons/storyd.lpc`、`adm/daemons/bossd.lpc`、`adm/daemons/autonpc.lpc`、`adm/npc/luban.lpc`（第 1521、2752 行）、`adm/special_ob/tianfu/obj/ganwu_tu.h`（第 40 行）、`cmds/adm/wizgo.lpc`（第 36–37 行）、`adm/single/importer.lpc`（第 555–556 行）与 `cmds/adm/to_man_json.lpc`（第 124 行）的 `[0..<3]` / 后缀剥离修正为 `[0..<5]` 或 `replace_string()`。
- **浮点 / 整型与格式串告警**：使用 `to_int()` 修正 `adm/simul_efun/atoi.lpc:30`、`adm/simul_efun/nt.lpc:900`、`d/bangpai/farm/farm.lpc:70`、`d/bangpai/plant/plant.lpc:39`、`inherit/condition/poison.lpc:369`、`kungfu/skill/gandanqinxin.lpc:157,169`、`kungfu/skill/liuyang-zhang/hui.lpc:118`、`kungfu/skill/weizhuang_guidao/guiying_shan.lpc:49`；`cmds/arch/config.lpc:102` 改用 `__MUD_IP__`；`adm/daemons/network/dns_master.lpc:237` 将 `||PORT:%s||` 改为 `||PORT:%d||`；移除 `cmds/skill/citiao_rf.lpc:165` 与 `cmds/wiz/more.lpc:19-20` 的未使用局部变量；`system/wusheng/zhenyi/test_baodi.lpc` 引入 `zhenyi_config.h` 并补充 `query_zhenyi_level`/`add_zhenyi_to_bag` 委派封装。
- **外部服务与 WASM 兼容**：
  - `adm/daemons/dbd.lpc` 加入 `#ifdef __PACKAGE_DB__` 并在 `db_host == "xxxxxxxx密码示例"` 时跳过 `connect()` 与心跳轮询；
  - `adm/special_ob/qq_msg/server.lpc` 将 `create()` 中的 `int ret;` 移入 `#else` 分支（`#ifndef __PACKAGE_SOCKETS__` 提前返回），消除 WASM 预加载时的未使用变量警告；
  - 对 31+ 个新增/修改 `.lpc` 文件以 `format-corpus.mjs --check` 验证零格式化报错（未改动的原始文件保留原有排版风格）。

## 3. 登录流程、UTF-8 姓氏检验与品牌标记

- `adm/etc/welcome` 添加 `═══ FluffOS Mudlibs 典藏 · https://mudlibs.fluffos.info ═══`。
- `adm/daemons/named.lpc`：针对 UTF-8 汉字将 `NAME_HEAD` 改为 `strlen(name) >= 3 ? name[0..2] : name[0..0]`，避免 1 字节截断破坏中文姓氏，并在 `invalid_new_name()` 中使用 `pcre_match(name, "^\\p{Han}{1,4}$")` 验证纯汉字长度。
- `adm/daemons/logind.lpc`：将 `check_legal_name()` 改为 `pcre_match(name, "^\\p{Han}{2,4}$")`；在保留原 `║` 分隔协议及 `ldx123`/`zds123`/`demo7788` 分流逻辑的同时，为标准 telnet 与浏览器网页端新增交互式登录与创角流程（`interactive_id`、`interactive_get_passwd`、`interactive_new_passwd`、`interactive_confirm_passwd`、`interactive_reg_gender`、`interactive_reg_name`、`interactive_reg_born`），使网页端与普通客户端均能完成注册、选出生地并入世。
- `scripts/write_play_page.sh`：将 `ZJ_PROTOCOL` 判定收紧为同时检测 `zjmud.h` 与 `logind.lpc` 中的 `ver1.0` 握手标志（真 ZJ 库 `dtxyzjb`、`hhsj`、`shujian3`、`wdxtym`、`wxddym`、`xfbhh`、`zjdyzj`、`zjmudhell` 保持 `true`，`wxlm` 为 `false`）。
- 预建管理员账号 `fluffos` / `Mud@2026`（柳随风，扬州出生地，并在 `adm/etc/wizlist` 写入 `fluffos (admin)`）。

## 深度功能测试（§10.7，2026-11-14）

- **全量编译扫描**：使用 `build-debug/src/lpcc --batch libs/wxlm/config.fluffos` 扫描全部 `8,940` 个 `.lpc` 文件，0 编译错误、0 编译警告（零 `#pragma no_warnings`）。
- **原生端验证**：`fluffos`（`Mud@2026`）在扬州醉仙客栈登录、冷重连、`look`、`score`、`update /d/city/kedian` 与 `quit` 全程无报错；另以女性临时角色（楚轻霜，关外客栈）验证注册、`look`、`hp`、`i`、`skills`、`help` 与 `quit` 正常（测试后已清理临时存档）。
- **WASM 端验证**：通过 `scripts/wasm_client.js` 加载 `build-wasm/src` 与 `libs/wxlm` 完整启动全部预加载守护进程，使用 `fluffos` / `Mud@2026` 登录并执行 `look`、`score`、`quit`（`exit 0`，无报错），并同步生成 `scripts/wasm_keep_dirs.txt` 空目录清单。

## `sefun::cat()` 缺文件与目录保护修复（2026-11-15，KB 06 §7.388）

- `adm/simul_efun/file.lpc` 中的 `cat()` 未对其 `read_file()` 返回值判空（存在前置 `seteuid()`、`file_size()` 上限、`SECURITY_D->valid_read()` 或局部变量赋值，因而绕过了早期的裸体正则），缺失文件、目录或不可读时返回 `0` 并送入 `write()` / `receive()`；已通过 `scripts/lpc_fix_cat_unchecked.py --apply` 补全 `|| ""` 保护。
- 验证：`lpcc_eval.py` 缺失文件/目录 `cat()` 探针加载通过（`ZZT e1=0 e2=0`，无非字符串送入 `receive_message()`），`scripts/lpc_fix_cat_unchecked.py` 幂等复扫剩余 0。

## `enable_player()` 重入守卫与 `RANK_D` 空对象守卫（2026-11-18，KB 05 §7.19 / KB 06 §7.273）

- `feature/command.lpc` 的 `enable_player()` 缺少 `in_enable_player_now` 重入标志，已通过 `scripts/lpc_fix_enable_player_guard.py --lib wxlm --apply` 补入 `nosave private int in_enable_player_now;` 守卫，防止 `init()` → `setup()` → `enable_commands()` 重入递归溢出。
- `adm/daemons/rankd.lpc` 的 `query_respect`、`query_rude`、`query_self`、`query_self_rude` 缺少 `!objectp(ob)` 守卫，在无 `this_player()` 上下文传入 `0` 时触发 `*Bad argument 1 to EFUN call_other()`；已通过 `scripts/lpc_fix_rank_null.py --lib wxlm --apply` 在 4 个函数头部补入 `if (!objectp(ob)) ob = this_object();`。
- 验证：`lpcc_eval.py`（`--head` `rankd->query_respect(0)` 报错 FAIL → 工作树 `new("/feature/command")`、`new("/inherit/char/npc")->enable_player()` 与 `rankd->query_{respect,rude,self,self_rude}(0)` 均正常返回、`PASS`），`play_boot.sh` + `play_stop.sh`（端口 `40404`）启动与停止正常，`scripts/lint.py` 零告警。

## `lint.py` 补全历史扫除遗留（2026-11-19，KB 06 §7.209/§7.246/§7.282/§7.283/§7.334/§7.351/§7.373/§7.391）

- 本库收录晚于多轮全语料扫描，`scripts/lint.py --all` 检出并按现有修复脚本统一清理以下 8 处源码缺陷（跳过经核实属有意设计的 `kungfu/skill/lonely-sword/xiao.lpc:139` `if (delta = 2)`）：
  - `inherit/char/npc.lpc`：`chat()` 空 `chat_msg` 骰子前补 `sizeof(msg) &&`（`--head` `*Array index out of bounds` 崩溃 → `chat_err=0`）。
  - `d/mingjiao/shanmen.lpc`：`valid_leave()` `family_name != "明教" || family_name != "武当派"` 恒真误拦本派弟子，改为 `&&`（`--head` `leave=0` → `leave=1`）。
  - `d/wudang/npc/xiaocui.lpc`：`new(__DIR__"../obj/nuerxiang")` 触发驱动拒绝 `..` 路径，改为 `"/d/wudang/obj/nuerxiang"`（`accept_object()` 返回 `1`）。
  - `cmds/arch/board.lpc`：`get_dir("/clone/board/")` 加 `|| ({})`（本库无 `/clone/board/` 目录）。
  - `cmds/arch/sameip.lpc`：`member_array('.', arg)` 改为 `strsrch(arg, ".")`。
  - `kungfu/class/lingjiu/zhuo.lpc`：`recognize_apprentice()` `ob->query("family")["master_name"]` 改为 `ob->query("family/master_name")`。
  - `include/npc/chinese.lpc`：`get_cn_name()` 删去 `& 0xFFFE` 对齐并改为 `[0..0]` 单汉字切片。
  - `include/net/ftpdsupp.h`：4 处负号区间结尾 `..-1` 补 `<` 为 `..<1`。
- 验证：`lpcc_eval.py` 前后对比均 `PASS`，`lpc_format_changed.py` `0` 重排，`play_boot.sh` + `play_stop.sh`（端口 `40404`）正常，`scripts/lint.py --changed HEAD` 零告警。

## `family` 映射未判空索引修复（2026-11-19，KB 05 §7.30）

- 通过 `scripts/lpc_fix_family_guard.py --apply` 为 `9` 个 `.h`（`/d/mingjiao/npc/menzhu.h`、`/d/mingjiao/npc/tangzhu.h`、`/d/mingjiao/npc/zhangqishi.h`、`/kungfu/class/mingjiao/fawang.h`、`/kungfu/class/mingjiao/shizhe.h`、`/kungfu/class/shaolin/cheng.h`、`/kungfu/class/shaolin/dao.h`、`/kungfu/class/shaolin/hui.h`、`/kungfu/class/shaolin/qing.h`） 中未判空直接索引 `["family_name"]`/`["generation"]` 的 `query("family")` 局部变量补充 `if (!mapp(...)) ... = ([ ]);` 防护，避免无门派玩家触发 `*Value being indexed is zero.`。
- 验证：全语料相关含头文件 `.lpc` 宿主与修改后 `.lpc` 共 `1,247` 目标经 `lpcc` 差分编译全部通过（`regressions=0`）；代表实测 `hy2002` `kunlun-zhang->valid_learn`、`bixiecanyang` `cheng.h`、`bxsj` `pfm_control.h` 均由 `--head` `*Value being indexed is zero.` 转为 `err=0`；`lpc_format_changed.py` 与 `scripts/lint.py --files` 零错误零告警。

## `add_action` 缺失回调清理（2026-11-19，KB 06 §7.349）

- 清理全库 `8` 个源码文件中指向不存在或被注释函数的 `10` 处无效 `add_action` 绑定（避免触发 `*Function for verb '...' not found.` 运行时报错）：
  - `adm/npc/referee.lpc`（第 43–44 行 `do_halt` -> `halt`/`h`）；
  - `clone/baoshi/color_baoshi.lpc`（第 34–38 行空 `init()`，不存在 `do_embed_gem`/`do_embed`，实际通过 `do_effect` 与 `cmds/std/embed_gem` 工作）；
  - `clone/vip/qiankun_lingbei.lpc`（第 12–15 行空 `init()`，不存在 `do_eat`，实际通过 `do_effect` 使用）；
  - `d/beijing/hg_w.lpc`（第 25–28 行空 `init()`，不存在 `do_body`）；
  - `d/fuben/kuihua/npc/kuihua_mozun.lpc`（第 79 行 `do_flatter`）；
  - `d/tulong/yitian/npc/obj/ling2.lpc`（第 7–10 行空 `init()`，不存在 `do_du` 且误遮蔽全局 `yandu`）；
  - `d/yihua/lianhuachi.lpc`（第 24 行 `do_CAI`，原函数已在第 33 行起注释）；
  - `inherit/char/smith.lpc`（第 9–12、20–23 行 `do_gu`/`do_stop`/`do_dapi`/`do_cuihuo` 前向声明与绑定，原 4 个实现已在第 58–229 行注释）。
- 验证：`8` 个文件全部通过 `lpcc` 编译与 `lpcc_eval.py` 载入检查，`lpc_scan_callout_targets.py --lib wxlm --kind add_action` 剩余 `0`，`lpc_format_changed.py` 零格式告警，`scripts/lint.py --files` 零告警，`play_boot.sh` + `play_stop.sh`（端口 `47393`）启动正常。
## `->query*()` 拼写错误修复（2026-11-19，KB 06 §7.397）

- 全语料排查无定义函数调用（`call_other` 静默返回 `0`），修正 `/d/emei/obj/tianxiang-gao.lpc`、`/adm/daemons/combat/combat_player_escape.h`（共 `2` 个文件） 中的 `->qurey`/`->qeury`/`->quert`/`->queyr`/`->quety_temp`/`->querk_skill`/`->quert_respect`/`->query_tmp`/`->quary`/`->queryr`/`->quer` 等拼写错误为标准方法名，消除功能失效或条件误放行问题（保留原文件行尾）。
- 验证：全批 `698` 文件（`691/698` 编译通过、`7` 处为既有历史问题、零新增退化）；`lpc_format_changed.py --apply` 零重排；`lpcc_eval.py` 代表对比验证通过（`dtxywzxzb` 非蜀山 `valid_learn` 由 `1` 转为 `0`，`fqyy2` `qurey=0 -> query=50`）；`scripts/lint.py`（新增 `query-method-typo`，共 `69` 条规则）全库与 `--fast` 零错误零告警；`10` 馆代表 `play_boot.sh`+`play_stop.sh` 正常且 `ZERO_DRIVERS`。
## `->receive_*`/`->set_temp`/`->delete_temp` 等调用拼写错误修复（2026-11-19，KB 06 §7.398）

- 续查全语料无定义 `call_other` 调用（静默返回 `0`），修正 `/kungfu/skill/lingshe-zhangfa.lpc`（共 `1` 个文件） 中的 `->recieve_damage`/`->recieve_wound`/`->recieve_curing`/`->delte_temp`/`->delet_temp`/`->settemp`/`->se_temp`/`->stat_busy`/`->query_skil`/`->quert_skill`/`->queyr_skill` 拼写错误为标准方法名（并顺手将 `lingshe-zhangfa.lpc` 中的 `"linshe-zhangfa"` 修正为 `"lingshe-zhangfa"`）（保留原文件行尾）。
- 验证：全批 `359` 文件中 `321` 个 `.lpc` 差分编译通过 `313/321`（`8` 处为既有历史问题、零新增退化）；`lpc_format_changed.py --apply` 零重排；`lpcc_eval.py` 代表实测通过（`bxsj` `recieve_damage=100 -> receive_damage=60`，`tybxjh` `delet_temp=1 -> delete_temp=0`）；`scripts/lint.py`（新增 `call-method-typo`，共 `70` 条规则）全库与 `--fast` 零错误零告警；`8` 馆代表 `play_boot.sh`+`play_stop.sh` 正常且 `ZERO_DRIVERS`。

## ES2 `F_DBASE` 单参 `set("`/`set_temp("` 与悬空逗号修复（2026-11-20，KB 06 §7.414）

- 修复 `/kungfu/condition/xixing-fanshi.lpc`、`/kungfu/condition/xuanming_poison.lpc` 中仅传单一属性名的 `set("k")`/`set_temp("k")`（ES2/Nitan7 `F_DBASE` 缺省第 2 参数为 `0` 致标记失效或写错键名）及 `set("k",)` 悬空逗号编译错误：按各自语义分别补 `", 1"` / `", 0"`、修正 `delete_temp("playing")`（`flute.h` `delete/playing` 笔误）、`delete_temp("apply/long")`（`silk3a.lpc`）、`set_temp("die_reason", ...)`（状态死亡原因）或还原被脚本倒置的双参 `set(prop, var)` / 拼写错误。
- 验证：全批 `1348` 文件 / `182` 馆完成，代表实测涵盖 `21` 馆差分 `lpcc --batch`（零新增编译退化）、`lpcc_eval.py` 前后对照（`fengyun434` / `dtxyzjb` / `bxsj silk3a` / `hell xixing-fanshi` / `jym lu` / `wdxtym dymo+baihu` / `xbtxiii damo` / `xkm tu` / `xajhxo cloth` / `esI copperman` / `xixingzhanji logind` 均通过）、`lpc_format_changed.py --apply` 零重排、`scripts/lint.py`（新增 `one-arg-set` 规则，共 `85` 条）全库 `--all` 与 `--fast` 零错误零告警，以及 `10` 馆代表实机 `play_boot.sh`+`play_stop.sh` 启动正常且 `ZERO_DRIVERS`。

## 2026-11-23 `qujing-gunfa.lpc` 空手解引用 `query_temp("weapon")->query("name")` 崩溃修复（KB 04 §6.56）

- 修复 `/kungfu/skill/qujing-gunfa.lpc:125,128` `query_action(object me, object weapon)` 中未判空直接内联解引用 `me->query_temp("weapon")->query("name")` 致空手触发 `*Bad argument 1 to EFUN call_other() Got: int(0)` 崩溃的缺陷：优先取形参 `weapon` 并补 `objectp()` 判空守卫（无兵器兜底 `"长棍"`，保留原 LF 行尾）。
- 验证：`lpc_format_changed.py` `0` 错误；`lpcc_eval.py`（`hell` 及 `6` 馆代表）`query_action(me, 0)` 返回有效招式映射 `PASS`；`scripts/lint.py`（规则 #117 `qujing-gunfa-weapon-name`，共 117 条）`--changed HEAD` 与 `--fast` 零错误零告警。
