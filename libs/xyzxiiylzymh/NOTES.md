
## WASM 修复摘要（迁移自 meta.json 的 group_note）

夕阳再现II-炎龙专用美化客户端——xysylmhb 家族的又一个夕阳再现III/炎龙封印构建版本，同样有 AKAI Studio 的 Tomud '2060' 客户端握手闸门。WASM 修复靠 scripts/lib_bulk_fix.py + scripts/scan_known_bugs.py 在第一次启动测试之前就主动抓出来：标准的 §8.1 check_legal_name() i%2 奇偶门槛/[i..<0] 后缀切片（is_chinese() 本身已经正确）改成了逐码点的 name[i..i]；master.lpc 的 valid_read()/valid_write() 缺少 'user == this_object()' 短路判断（这份档案和它的手足档案一样，已经有一段基于 previous_object() 的局部保护——额外补上了标准保护）。dns_master.lpc 本来就已经在 preload 里被注释掉（原来就是这样，休眠状态）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（SECURITY_D 正确指向 securityd.lpc）。注册流程在一次连续的 WASM 客户端会话里完整验证过：版本握手（2060）→英文 id→y（确认新角色）→中文名字→管理员密码+确认→登录密码+确认→天赋菜单（0 随机，y 接受）→电子邮件→性别（m/f）→在北疆小镇进入游戏世界（和手足档案 xysylmhb 的南城客栈不同的起始房间——这个构建版本在 4 个 start_room 条目里随机选择），look/score 都干净。管理员权限已通过"★ 您目前权限：(admin)"确认。LPC 格式化工具对全部 8302 个档案运行（写入 8205 个，64 个转档之前就存在的未结束字符串/文本块内容错误未做格式化，33 个未改动）。没有 :: 父类呼叫拆分命中；一处 CJK 重新加空格命中（d/city/sj.lpc）确认是和 xysylmhb 那份完全相同的手足档案上见过的同一处转档之前就存在的缺失引号损坏，已还原；和 xysylmhb/xyzx 一样的 2 处 case 标签带尾随注释的命中（cmds/bakcmds/csc.lpc、cmds/bakcmds/meskills.lpc，都是死代码备用指令副本）经 diff 复核干净。格式化后重新验证干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 93 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试（此前只做过 WASM 阶段的注册流程验证）。**更正**：
group_note 里描述的"管理员密码+确认→登录密码+确认"双密码流程和这
份档案实际代码不符——`adm/daemons/logind.lpc` 读代码确认只有一组
密码（`new_password`/`confirm_password`），没有独立的"管理密码"
（`wizpwd`）步骤，和手足档案 `xysylmhb`/`xyzx` 的双密码机制不同，
这是同一血统下的一个更简化的构建变体。连线握手（"2060"）沿用同一
家族的机制。

### 发现并修复的 PROGRAMMING bug

1. **`get_resp()`/`get_name()`（`adm/daemons/logind.lpc`）各有一处
   调试残留 `printf("%O\n", ob)`（AGENTS.md §7.34-class）**：紧跟
   在中文名字确认之后，把连线桩物件的原始引用直接回显给正在注册
   的新玩家。已删除两处。
2. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master
   file）完全没有严重度检查（AGENTS.md §7.34-class）**：已加上
   `strsrch(message, "arning:") == -1` 判断。
3. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
4. **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/
   logind.lpc` 的 `enter_world()` 里 `ob->query("age") == 14`（应为
   `user`）。已改成 `user->query("age") == 14`。

### Proactive checks（无需改动）

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:146` 已用 `to_int(query("win_times")) %
  5`；`d/huashan/npc/refereew.lpc`/`referee.lpc` 未用到 `%`，不适
  用。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。

### 实测过程

管理员 `fluffos`/`Mud@2026`（`adm/etc/wizlist` 早已播种，但从未真
正注册过）用完整注册流程（含"2060"握手）创建，落地"客店"，`score`
显示"【天界总管】"头衔，食物/饮水满格。随后**单独一步**做了真实断
线重连+密码验证（同样先发"2060"握手）：用刚设的密码重新连线成功
登录，存档数据一致。全程 `debug.log` 无运行时错误（连线过程中出现
的 `bnway`/`lbadd0`/`lbclear0`/`ptext` 之类原始字符串是 Tomud 客户
端专用带外控制标记，正常客户端会解析成小地图/状态栏 UI，不是
bug）。驱动按精确 PID 结束；管理员存档已提交。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`）在本档案 2,070 处房间文件的
`create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个休眠 bug，
和手足档案 `yzxiiizylfy` 完全同源。用 `fix_710_room.py` 扫过
`work/`，删除 2,068 处标准形状；两份房间建造工具（`clone/misc/
roommaker.lpc`、`d/huanggon/obj/roommaker.lpc`）各剩 1 处字符串拼
接变体，手工改成 `str += "\n\tsetup();\n}\n";`。修复后 `work/` 下
0 处存活残留，`work/data/` 下没有真实 `.lpc` 源码命中。`git diff
--stat` 显示 2068 个文件净删 2070 行、增 2 行，与脚本自报数字 + 2
处手工编辑吻合。

驱动干净启动（零新增编译错误、端口 40130 正常监听、`debug.log`
无任何"cannot replace"/"cannot bind"行）。管理员 `fluffos`/
`Mud@2026`（'2060' Tomud 客户端握手）实机登录成功，`look`/
`score`/`quit` 均正常，全程 `debug.log` 保持干净。管理员存档的时
间戳漂移已用 `git checkout HEAD --` 还原，未提交。驱动按精确 PID
结束。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（2026-09-03，第三轮）

新角度：2026-08-13 第二轮只做了注册 + `2060` 握手重连，没测商店和
拜师。本轮用既有 `fluffos`/`Mud@2026`（中文名「浮浮」，男性）。
第一行仍发 `2060`（Tomud 握手）；单密码，无巫师效验码。

- **登录**：落地 `/d/xingxiu/beijiang` 北疆小镇（四个候选出生点
  之一）。`quit_time` 冷却 50 秒（不是手足 `xyzx` 的 120 秒
  `last_on`）。
- **商店**：先买后拜（`feature/dealer.lpc` 对丐帮一律「穷叫化」）。
  `goto /d/city/zuixianlou`，`list` 列出烤鸡腿 80 文 / 牛皮酒袋一
  两白银 / 包子 50 文。无现金时 `buy jitui` 正确拒绝。`clone
  /clone/money/gold` 后再买成功（烤鸡腿 + 找零 99 两白银 + 20 个
  铜板）。
- **拜师**：`goto /d/gaibang/inhole`，`apprentice zuo`（左全）一次
  完成 →「恭喜您成为丐帮的第二十代弟子」。`score` 称谓「丐帮第二
  十代弟子」、师傅「左全」。
- **持久化**：`save` + 50 秒后重连，落地铁枪庙，称谓/师傅/银钱均
  在；烤鸡腿未随存档回来。
- **日志**：live `debug.log` 是 `libs/xyzxiiylzymh/log/debug.log`
  （Boot Time Thu Sep 3 22:16:22 2026）。无 `error:`。mudlib
  `work/log/debug.log` mtime 仍是 2026-08-13。
- **结论**：商店 / 有机拜师 / 重连均通过，本轮无新编程 bug 可修。
