# Heaven7 v2.07 — 恢复笔记

## 来源

- MudBytes.net 历史归档快照 `10000/heaven7_2v07.tar.gz`（GitHub `#28`）
- 1994 年发布的 Amylaar 3.2 COMPAT / 2.4.5 派生 mudlib，含 Tempus 城、商业工匠（炼金术士/铁匠/护甲匠）、技能系统（战士/盗贼/法师/牧师）与完整示例物品区（`/doc/examples/`）。

## Bring-up 与 FluffOS 移植（2026-11-14）

1. 目录与配置：`convert_lib.sh` 规范化 `.lpc` 扩展名；分配编号 `192`，端口 `40397`；全局头文件 `<fluffos_global.h>`。
2. 兼容层（`include/fluffos_global.h` 与 `obj/sim_ef_1.lpc` / `obj/sim_ef_2.lpc`）：
   - 补齐 Amylaar/MudOS-DR 兼容函数与宏：`m_delete()`、`tail()`、`process_string()`、`move_object(item, dest)`、`force_me()`、`command(str, ob)`、`copy_mapping`、`m_indices`、`mappingp`、`query_imp_port()`、`CLOTHING`、`UDP_CMD_DIR`、`INETD`，以及适配 FluffOS `snoop()` 参数顺序。
3. 语法与严格类型修复：
   - 保留字变量改名（`class` -> `wand_class`/`pkt_class`，`in` -> `in_file`，`new` -> `new_val`/`new_ob`/`new_mail`/`new_note`，`move` -> `wiz_get`/`move_book`）、`static` 原型改为 `protected`、变量声明统一移到 `inherit` 之后、闭合未封闭字符串/注释及错误分号。
   - 补齐缺失 `return`（`objects/safe.lpc`）、前向声明及头文件 `.spc`/`.cfg` 与定义签名对齐（`player.spc`、`room.spc`、`wizard.spc`、`living.spc`、`party.cfg`、`secure/questdef.lpc`、`obj/weather.lpc`、`obj/money.lpc`）。
   - 修复 `living.lpc`、`player.lpc`、`wizard.lpc`、`master.lpc`、`mail_rdr.lpc` 中因宏开关未开启导致的未用局部变量、`questdef.lpc` `void long` 返回值错误、`tree4.lpc` 与 `room.spc` 冲突的 `search` 动作函数、以及 6 个铁匠/炼金师 NPC 与 `base_obj` 全局变量重名（统一为 `job_name`/`job_weight`/`job_value`）。
4. `create()` 与菱形继承修复：
   - 为 `inherit/` 下 `room2`、`contain`、`clothing`、`armour`、`weapon`、`treasure`、`drink`、`food`、`chair`、`sign`、`std_bank`、`std_pub`、`store`、`monster`、`undead` 添加 `void create()` 转调 `reset(0)`，修复原版仅在 `reset(0)` 初始化导致 FluffOS 下房间描述、出口、NPC 与门全空的问题；修复 `chair.lpc:44` `i == member_array(...)` 笔误。
   - 拆分 `inherit/wand_base.lpc`（供 `m_armour`、`m_weapon`、`objects/potion` 无重复 `BASE` 继承）及 `skills/obj/sp_weap_arm.lpc`（供 `bless`/`curse`/`prayer` 避免 `sp_weap`+`sp_arm` 菱形继承）。
   - 修复 `lpcc` 批量加载 `reset(0)` 暴露出的 4 个运行时错误：`doc/examples/weapons/t_sword.lpc` `set_class` -> `set_wc`、`room/city/clerk.lpc` 空 `this_player()` 判空、`room/city/monst/{elfguard,ltguard}.lpc` 武器/铠甲路径 `room/city/obj/{lsword,plate}`。
5. 登录横幅：在 `info/WELCOME` 与 `info/WELCOME2` 保留原 ASCII 艺术并标注 `Preserved at https://mudlibs.fluffos.info`。

## 深度功能测试与验证（2026-11-14）

- 编译与警告：`lpcc --batch` 与 `scripts/lpc_warnings.py` 全量扫描 `472/472` 个文件全部编译并成功执行 `reset(0)`，`0` errors、`0` warnings、`0` `#pragma no_warnings`；`check_ntfs_paths.py` 全部通过；新增文件 `inherit/wand_base.lpc`、`skills/obj/sp_weap_arm.lpc` 已按 formatter 规范化。
- 原生启动与实机测试：新建角色 `hero`（密码/邮箱/性别 `m`/种族 `human`）登录 Tempus 广场，移动穿过木桥至市政厅前（4 名守卫鞠躬）及南部花园门（石像鬼与守卫），核对 `score`（Level 1，2s 50c）、`save`、`quit` 后重连读档一致；`log/debug.log` 无错误。
- WASM 验证（`scripts/wasm_client.js`）：`build-wasm` 正常启动，登录界面完整显示 `mudlibs.fluffos.info`，完成新角色注册、移动浏览与保存退出。
