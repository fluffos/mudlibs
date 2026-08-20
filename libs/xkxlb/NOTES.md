
## WASM 修复摘要（迁移自 meta.json 的 group_note）

从一个扩展名错误的 .rar（实际是带有 ../ 成员路径的 POSIX tar）提取；启动靠 /adm/single/master（树里还打包了一份未使用的 adm/obj/master.lpc，碰巧和 jyqxc/fy2mg/xkx2017 框架家族字节相同，但不是真正被加载的那份）；启动干净，零修复。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc 的 make_body() 里 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限；给 securityd.lpc 的 get_status() 加上了防御性保护；修复了 securityd.lpc 的 valid_write() 里经典的 §7.49 存档扩展名不匹配 bug。最大的发现：include/globals.h 里的 SIMUL_EFUN_OB 指向一份过时、未使用的 /adm/single/simul_efun.lpc（早期重构留下的死代码副本，虽然在树里但没有被 config.fluffos 的"simulated efun file"设定引用），而不是 config.fluffos 真正加载、定义了 destruct() 覆写的那份真正的 /adm/obj/simul_efun.lpc。这破坏了 feature/move.lpc 的 remove() 安全检查（它会核对 previous_object() 是否等于 SIMUL_EFUN_OB）——每一次经由那个覆写路由的物件销毁都会失败——具体表现为：每一个新玩家的 quit 都会失败，因为 quit 的自动丢弃背包逻辑会销毁任何不值钱的丢弃道具（每个新角色出生就带着一件）。这个 bug 很隐蔽：连线会打印一个被捕获的运行时错误、看起来像是断开了，但角色其实仍然在线，世界那一侧的连线从未真正关闭。已把宏指向真正的档案来修复（和之前某个 lib 里 securityd.lpc/securd.lpc 重复档案陷阱是同一种直觉——哪怕宏名字看起来"显然正确"，也要用 config.fluffos/真实调用链去验证它到底指向哪个文件）。另外修复了一份真正损坏的留言板存档（data/board/kedian_b.o 的某条留言作者字段里有原始的非 UTF-8 GBK 字节，导致每次在那个房间 look 都崩溃）——直接删除了这份损坏的存档档案，而不是冒险做局部字节级重新编码。管理员账号通过纯文本的 adm/etc/wizlist 档案播种。注册流程到进入游戏世界、look/score、以及一次正确完成的 quit 都已干净验证——建议在任何共享这种 SIMUL_EFUN_OB/重复 simul_efun 档案形态的档案上都专门重新测试一下 quit。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 18 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试（此前只做过 WASM 阶段的注册流程验证）。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/single/master.lpc`，实际生效的 master
   file）完全没有严重度检查（AGENTS.md §7.34-class）**：已加上
   `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
3. **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/
   logind.lpc` 的 `enter_world()` 里 `!user->query("food") &&
   !user->query("water") && ob->query("age") == 14` 判断的
   `ob->query("age")` 拿的是登录阶段用完即弃的连线桩物件，永远没有
   `age` 这个属性，条件恒为假，每个新角色食物/饮水永远初始化成
   0。改成 `user->query("age") == 14`。live 测试确认：修复前注册
   `score` 食物/饮水两栏全空（□□□），修复后重连（这个判断在
   `enter_world()` 里每次登录都会重新求值，只要 `food`/`water` 仍
   是 0 就会补发）同一账号立即变满格（■■■）。

### Proactive checks（无需改动）

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:176`、`u/wind/refereew.lpc:176`、
  `u/wind/refereew2.lpc:184` 均已用 `to_int(query("win_times")) %
  N`。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。
- **留言板存档括号计数怀疑（未采取行动）**：用简单的方括号/圆括号
  配对启发式扫描全部 `data/board/*.o`，`bonze_b`、`gaibang_b`、
  `gaibang_r`、`huashan_b`、`shaolin_b`、`taohua_b`、`towiz_b`、
  `wiz_b`、`wudang_b`、`xiaoy_b`、`xueshan_b` 共 11 份显示括号不配
  对（`kedian_b.o` 那份真正确认损坏的存档 WASM 阶段已经删除）。这
  个启发式本身不可靠（留言内容里出现的普通括号标点也会误报），本
  轮完整注册/look/score/重连流程没有触发任何一份的
  `restore_object()` 报错，`debug.log` 全程干净，没有实际证据证明
  这些是真损坏（不像 `xkx2017` 那批，有确认的存档头缺失+live 崩溃
  复现）。按"没有真实复现就不动"的纪律，本轮未删除任何一份，留给
  以后如果真的踩到崩溃再处理。

### 实测过程

管理员 `fluffos`/`Mud@2026`（`adm/etc/wizlist` 早已播种，但从未真
正注册过）用完整注册流程创建，落地"客店"，`score` 显示"【天神】"
头衔。随后**单独一步**做了真实断线重连+密码验证：用刚设的密码重
新连线成功登录（顺带验证了 #3 的食物/饮水修复对已存在账号的自愈效
果）。全程 `debug.log` 无运行时错误。驱动按精确 PID 结束；管理员
存档已提交。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/inherit/room/room"`：删除 791 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），与 `jqxz2008`/
`jyqxc`/`xiakexing3` 系列同一血统同一形状。`clone/misc/
roommaker.lpc` 同样有两套模板——"造一间空房间"的 heredoc 本来干
净，"克隆我所在的房间"命令的字符串拼接模板把同一枚多余的
`replace_program(ROOM);` 烤进了每一个新克隆的房间，已同步修正。已
用 `build-debug` 驱动干净启动验证（0 个新增编译错误，端口正常监
听）；未做完整 §10.7 深度游玩测试。
