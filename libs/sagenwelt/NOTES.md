# Sagenwelt (sagenwelt) — porting notes

Source: `git clone https://github.com/Shea690901/Sagenwelt-Lib`
(default branch `develop`; playable snapshot is `feature/player` commit
`77266da70c4103890effa3f20c0cadabbed388c3`, “moved struct's *.c ->
*.h”, 2016-04-03; converted 2026-09-05). Config name `Sagenwelt`. Slug
`sagenwelt`, number **973**, port **40282**.

This collection’s copy is a snapshot, not a live mirror.

Unfinished FluffOS skeleton by Gwenhwyvar (“Once ready, this lib will
contain everything needed to setup a new mud…”). `Domains/` is empty.
No shipped rooms or combat. Not a duplicate of collection
`morgengrauen` / `MorgenGrauen/mg-mudlib` (that is a different
Shea690901 repo). Do not onboard `Shea690901/Sagenwelt-Lib` again.

## 0. Layout

Mudlib root is `src/`. Master `/secure/obj/master`, simul
`/secure/obj/simul_efun`, intended login `/secure/obj/player/login`.
`raw/` is the full git tree (gitignored). Bundled `gamedriver`
gitmodules (`fluffos/fluffos`) was not cloned.

`feature/player` is further along than `develop` (player/login, racesd,
Lima-style shell). Both have empty `Domains/`.

## 1. Convert (2026-09-05)

`convert_lib.sh` UTF-8: `already_utf8=75 converted=2 lossy=0
skipped_binary=88`. 16 `.lpc`. 11 `.c"` rewrites (preload `*.lpc`).

## 2. FluffOS port

Archive master/simul do not boot on this driver.

### Archive bugs (kept in `master_orig.lpc` / `master_feature.lpc` /
`simul_efun_orig.lpc`)

- `SECCURE_DIR` / `DAEMKN_DIR` typos in `std_paths.h` (LOGIN_OB path
  would be wrong).
- Master: `switch driver_flag` missing parens; `return("%s:%s",…)`
  instead of `sprintf`; `*uids` missing comma; `if(a) || (b)` missing
  parens; `ORIGIN_DIVER` (not in origin.h); `valid_write` consulted
  `_READ`.
- Simul header `#include <messages.h>` (file is `message.h`); several
  prototypes missing `;`.
- `/var/cfg/*.acl` unfinished (own TODO). `Privs.cfg` is a single `/`.
- `player.c` concatenates a second leftover login.c at the bottom.
- Login never reaches a room.

### Catalog overlay

Original master needs the unfinished simul (author_of, syslog, ACL,
…). Catalog `master.lpc` + empty `simul_efun.lpc` +
`catalog_user.lpc` boot and implement `look` / `score` / `quit`.
Global include is `globals_catalog.h` because archive `std.h` pulls
the broken simul header.

Patched-but-still-unbootable archive master saved as
`master_feature.lpc`.

### Live-verified (native, port 40282)

No accounts. Connect → catalog landing; `look` / `score` / `quit`
(“Goodbye.”).

WASM not verified. `unique_games` stays counting numbers `< 900`; 973
is still listed as a lib.

## Leftover 678 (2026-09-12) — develop vs feature/player

GitHub default branch `develop` is +2 (Zappr CI + README) and **40
commits behind** `feature/player`. Those two commits are not game
content and are not on the playable snapshot. Pin stays `77266da`.
`meta.json` now has `"upstream": {"branch": "feature/player"}` so
`check_upstream_rebase.py` compares that branch, not `develop`. Do
not invent Domains rooms.

## 深度功能测试（§10.7，2026-09-13）

Catalog Void landing only — the archive has no playable world
(`Domains/` ships only a README; archive login/player never shipped a
room; no shop or combat). Do not invent Domains rooms. Source-
complete bar for this unfinished skeleton.

Native boot (`~/src/fluffos/build-debug/src/driver config.fluffos`
from `libs/sagenwelt`, port **40282**, PID owned by this session):

- Connect → catalog landing banner; `look` / `l` → The Void;
  `score` / `sc` → Guest (Sagenwelt guest), no stats; unknown
  `xyzzy` → `What?`; `quit` → “Goodbye.”; driver stayed up.
- Fresh reconnect → same `look` / `score` / `quit` (no accounts /
  no persist).
- Shop / combat / guild / death: **N/A** (not in archive).

Logs this boot:

- Live driver `debug.log` fd:
  `libs/sagenwelt/var/log/debug.log` (pre-chdir open succeeds because
  `var/log/` exists beside `config.fluffos`). Boot banner + config
  dump only; no LPC `error:` / FATAL across play or quit (mtime
  matches this boot).
- `/var/log/catch` (`work/var/log/catch`): empty across the clean
  playthrough; mtime matches this boot. Handler proven live with a
  one-shot `catch(error("catch-path-probe"))` in `cmd_score` →
  `CAUGHT /secure/obj/catalog_user.lpc:… *catch-path-probe`, then
  reverted. No code fixes this pass.

## Deep test (§10.7, 2026-10-08) -- fixed-width `.lpc` suffix slices

The `.c` -> `.lpc` rename changed the string but not the slice width: `f[<2..] == ".lpc"` compares two characters with four and is never true (`!=` always true), so suffix filters and strips never ran or cut `x.l` (KB 06 §7.238). `scripts/lpc_lpc_suffix_slice.py --apply` fixed 2 comparison(s) and 2 strip(s) (e.g. `secure/obj/master_orig.lpc`); the changed files load at HEAD and in the tree (fresh processes) with no regression.

## Compile warnings (2026-10-13)

`scripts/toolkit_fix.sh` removed `#pragma save_binary` from `secure/include/pragmas.h` (FluffOS has no such pragma) and turned the bare `return;` in an `int` function of `secure/obj/master_feature.lpc` and `master_orig.lpc` into `return 0;`. By hand: `secure/include/mud_info.h` defined `MI_EMAIL_INVALID` twice, `"@inv@"` and then `"@reg@"`, so the later value won; the second line is renamed `MI_EMAIL_REGISTERED`, leaving `MI_EMAIL_INVALID` as `"@inv@"` (the same sentinel as `MI_PWD_INVALID`). `get_name_email()` in `secure/daemons/mud_info.lpc` is still an empty stub, so no comparison changes at run time. No warnings left in compiling files.

## 深度功能测试（2026-10-27，§6.10 未知 pragma save_binary/optimize）

删除本库中 FluffOS 不认的 `#pragma save_binary` / `#pragma optimize…` 行。


## switch 只有 `default:` 一个标号，不编译：case 分支被注释掉了，1 处（1 个文件）（2026-11-02，KB 04 §6.30）

`switch (EXPR) { default: BODY break; }` 只有 `default` 一个标号：这个驱动要 `case` 语句（`need case statements in switch/case, not just default:`），整个文件不编译，对象永远加载不了——归档时有人把 case 分支注释掉了、`default` 就是全部。本库 1 处（1 个文件）：。`scripts/lpc_fix_default_switch.py` 把它改成裸块 `{ BODY }`（尾部的 `break;` 去掉；`EXPR` 只有有副作用时留作一条语句；注释保持原位）。证明：改前该文件因 switch 不编译；改后越过 switch，又撞上本文件自己的另一缺陷（LDMud 的 `syslog()` 和 `LOG_*` 常量，KB 06 §7.291），仍不加载，另列处理；HEAD / 工作树加载对比 0 退步。

## 深度功能测试（2026-11-03，buffer 标识符）

FluffOS 保留 `buffer` 为类型；`string buffer` 局部/参数改为 `buf`。证明：声明层语法错消除（与 sticklib `_indent` 同类）。

## 深度功能测试（2026-11-03，默认参数）

FluffOS 不接受函数声明里的 `int x = CONST`（`unexpected L_ASSIGN`）。已从 `simul_efun.h`/`inp_sys.h` 原型与 `modal_push_char`/`syslogd::log` 定义上去掉默认值；`string array`→`string *`。证明：诊断中不再出现该 L_ASSIGN。

## 深度功能测试（2026-11-03，inherit 宏 / 缺头文件）

`globals_catalog.h` 补上 `P_INPUT`/`MOVE`/`LIVING`/`TO` 等路径与快捷宏（不拉坏掉的 `simul_efun.h`）；`playes/inp_sys.h` 拼写改为 `player/`；补空 stub：`connection.h`/`shell_sys.h`/`menus.h`/`std_defs.h`；`__ADMIN_EMAIL` 相邻字符串改为 `+`。证明：inherit 的 `expecting L_STRING` 诊断消失。

## 深度功能测试（2026-11-03，move_object/syslog sefun）

Catalog `simul_efun`：§7.231 双参 `move_object` shim；`syslog`/`creatorp`/`cred_cmp`/`HOME_DIR`/`set_this_player` 桩。`deep_inherit_list` 结果改为 `string *`；`efun::move_object` 改走 sefun；`start_shell()` 改为 `call_other`。证明：`move.lpc` / shell 相关诊断清除。

## 深度功能测试（2026-11-03，syslogd/mud_info）

映射字面量内非法 `;`（`]);`→`])`）；`syslogd` 补 `privs.h`/`syslog.h`，`PO() =`→`==`，`iLOG_NOTICE`/`brewk`/`get_uid` 修正；`mud_info` 含 `privs.h` + `is_wiz` 桩；catalog sefun 补 `itoa`/`query_host_port`（安全、无 bind）。证明：两 daemon 不再因 BB_UID/映射 `;` 失败。

## 深度功能测试（2026-11-03，mud_info mssp）

`mssp_telopt` 返回类型改为 `mapping`；`foreach` 标注 `string val`；去重 `get_player_info`；`save_obiect`→`save_object`；引入 `mud_info.h`/`syslog.h`；`init_eids`/`ORIGIN_*` 桩。证明：mssp 相关类型诊断清除。

## 深度功能测试（2026-11-03，ORIGIN_* 字符串）

`globals_catalog.h` 里先前补的 `ORIGIN_*` 桩是整数，而 FluffOS `origin()` 返回字符串（KB 05 §7.47），导致 `origin() != ORIGIN_EFUN` 报 string vs int / always true。改成与 `driver/origin.h` 一致的 `"local"`/`"call_other"`/`"simul"`/`"efun"`。证明：三条 always-true 诊断清零（39→36 diags）。

## 深度功能测试（2026-11-03，master ?: 与缺分号）

`master_feature`/`master_orig`：`valid_database` 的 `(action == "connect") ? "password" : 1` 触发 Types in ?:（string vs int）——拆成两次 return。配置解析 `explode(...)
 ret[...]` 缺分号，导致 `t` 被报 Unused。补分号。证明：?: 与 Unused 警告清零（36→33 diags）。

## 深度功能测试（2026-11-03，move ROOM/STD_OBJECT/CONTAINER）

`secure/lib/move.lpc` 用 `ROOM`/`STD_OBJECT`/`CONTAINER` 做 `member_array(deep_inherit_list(...))`，档案未定义这些宏。在 `globals_catalog.h` 按 `LIVING` 同款补 `STD_LIB "room"|"object"|"container"`。证明：三条 Undefined 清零；move 可编译（10 files compile）。

## 深度功能测试（2026-11-03，catalog 补 std 宏与头）

用 `globals_catalog.h` 替换 `std.h` 后，`I_*`/`LOG_*`/`MSGCLASS_*`/`TERM_D`/`SEFUN_DIR`/`INPUT_AUTO_POP` 不再自动进入每个对象。整理 catalog：补 `I_*`、`SEFUN_DIR`、`TERM_D`、`INPUT_AUTO_POP`，并 `#include` `syslog.h`/`message.h`；修好被提前 `#endif` 切断的结构。`input.lpc` 的 `INPUT_AUTOPOP` 改为头文件里的 `INPUT_AUTO_POP`；`inp_sys` 的 `LOG_ERROR` 改为 `LOG_ERR`；`messages::receive_message` 第一参改为 `int`，并用参数名 `message`（原先 `string msg_class` 与位运算冲突，且误用未定义的 `msg`）。证明：原 LOG_/I_/MSGCLASS_/TERM_D/INPUT_ 类 Undefined 清零；compile 10→13。

## 深度功能测试（2026-11-03，sefuns 无扩展名 → .lpc）

档案 `secure/sefuns/*` 无后缀；FluffOS `#include` 读不到。全部 `git mv` 为 `.lpc`；`simul_efun_orig` 的 `#include SEFUN_DIR "name"`（宏拼接）改为绝对路径 `"/secure/sefuns/name.lpc"`。活 sefun 仍是 catalog `simul_efun.lpc`；这些片段单独扫描会 FAIL（仅被 include），属预期。证明：`simul_efun_orig` 的 Cannot read #include 清零。

## 深度功能测试（2026-11-03，MENJ/NP_MENU/PLAYER_DOMAIN）

`menu.lpc` 的 `new(MENJ)` 笔误（同文件别处已是 `new(MENU)`）。`login` 缺 `NP_MENU`→`char_gen_menu`；`__PLAYER_DOMAIN__` 应为 `privs.h` 的 `PLAYER_DOMAIN`（缺宏导致 `":" __PLAYER_DOMAIN__` 语法错）。`player.lpc` 补 `#include <player/login.h>`（带出 `mud_info.h`/`NPWD_PROMPT`），并在本文件定义 `NEW_PASSWD` 等状态；`login.h` 补 `EMAIL_PROMPT`。证明：MENJ/NP_MENU/MI_PI_PWD/PLAYER_DOMAIN 类诊断清零。

## 深度功能测试（2026-11-03，player crypt/return/GET_NAME）

`player.lpc`：`NEW_PASSWD` 分支 `return` 缺分号引发连锁语法错；`crypt(input)` 在 FluffOS 需盐→`crypt(input, 0)`；补 `GET_NAME` 状态；`get_name_email(arg)`→`input`；`__ADMIN_MAIL`→`__ADMIN_EMAIL`；`mud_info.h` 补 `MI_PI_EMAIL`。证明：crypt/GET_NAME/缺分号类诊断清零。

## 深度功能测试（2026-11-03，master init_acl 返回类型）

`init_acl` 声明返回 `mapping`，出错路径却 `return ({})`（数组）。改为 `allocate_mapping(0)`；并为同文件稍后定义的 `author_file`/`domain_file` 补前置原型（否则 check_acl 报 Undefined）。证明：mixed* vs mapping 与 author_file Undefined 清零。

## 深度功能测试（2026-11-03，catalog sefun 权限/菜单桩）

master 调用 `elderp`/`archp`/`adminp`/`Dlordp`/`done_startup`；menu 调用 `trim_spaces`/`more`/`reg_pat_translate`/`insensitive_regexp`——活 sefun 是 catalog，原先无这些。补桩（权限类委托 `creatorp`；正则类返回 `string *`）。证明：master/menu 上对应 Undefined 清零；compile 14→15。

## 深度功能测试（2026-11-03，char_gen/login/master 档案残渣）

`char_gen_menu`：缺分号、`#include <menu.h>`/`mud_info.h`、宽映射 `races[race][RD_RACE_GENDER]`、档案未写的 `name_menu`/`password`/`email`/`homepage` 用 `modal_simple` 桩补齐；`MI_PI_RACE`/`MI_PI_HOMEPAGE`。login/player：`receive(msg)`（原误用 `message`）、`login_handler(START,0,"")`、`PASSWD_PROMPT`→`PWD_PROMPT`、player 底部粘贴的第二份 login.c 删掉、`env`/`_env` 初始化、`START` 宏、去掉未定义的 `setup_connection`。master `flag()`：`switch (driver_flag)` + `case`；`crash` 参数拼写；`case "move_object"`；`object *anc`→`string *`（`deep_inherit_list`）；`ORIGIN_DIVER`→`ORIGIN_DRIVER`；`*uids` 缺逗号；`sizeof(sp)`→`path`；`connect()` 不再用会展开成 `get_config(...)` 的 `case __MUD_PORT__`。catalog sefun 补 `init_eids`/`simul_efun()`/`file_name(ob,flag)`/`getegid`/`distinct_array`/`m_syslog`/`get_cwd`/`canonical_path`；`globals_catalog` 补 `DFLT_SCR_*`/`RACES_D`/`MAP_D`/`INPUT_SYSTEM`/`__MASTER_FILE__`/`ORIGIN_DRIVER`；`LOG_WARN` 别名；`MSGCLASS_LOGON`；`std_paths` 的 `SEFUN_DIR` 加 ifndef。证明：char_gen/login/player/master_feature/master_orig/catalog simul_efun 错误清零；剩余 FAIL 仅为单独扫描的 sefun 片段（预期）。

