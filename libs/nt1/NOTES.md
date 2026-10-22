
## WASM 修复摘要（迁移自 meta.json 的 group_note）

NT/nitan 血统，和 nitan170911/nitan6/hhsj 没有精确的 master 哈希匹配；修复了一个真实存在的内容 bug（clone/user/user.lpc 的 accept_kill() 呼叫 is_killing(ob) 而不是 is_killing(ob->query("id"))——这份代码库里其它所有地方 is_killing() 都是接受字符串 id 的）；修复了 efun::message() 对 exc_target=0 的拒绝；启动干净。完整 WASM 修复：给 band.lpc 的 is_banned() 加了本地回环放行（这条血统会禁掉任何不符合严格四段式点分格式的地址，否则连 ::1/非点分地址也会被误禁）；修复了 is_chinese() 过时的 GBK 字节区间判断；修复了 check_legal_name() 过时的字节长度下限，以及 named.lpc 的 invalid_new_name() 里一个独立的、假设"4 字节=2 字符"的 bug（会把任何单字给名当成"空名字"拒绝，滑窗查重逻辑也是按原始字节偏移而不是字符步进）；logind.lpc（create()/make_body()）里同样的 seteuid(getuid()) 把 euid 重置掉的 bug。最大的一个：adm/daemons/versiond.lpc（约 2300 行，一个绑了 TCP 服务端/客户端的版本同步/校验和精灵）在 13 个各自独立的函式里无条件呼叫 socket_create/socket_bind/socket_listen/socket_accept/socket_address/socket_write/socket_close，导致整个档案编译失败——而 logind.lpc 的 logon() 会在每一次连线时无条件呼叫 VERSION_D->is_version_ok()，所以这个编译失败会静默破坏每一个玩家（不只是巫师）的登录。按 AGENTS.md §7.52 更新后的方针，只把涉及 socket 的函式掏空成 no-op（不是整个档案，因为 is_release_server()/append_sn()/query() 等函式被这份 mudlib 里其它几十个无关的 NPC 和指令呼叫）——这就是连线在开机横幅之后永久静默挂起、没有提示也没有错误堆栈的根本原因。另外发现并修复了从原始压缩包继承下来的、真正损坏的非 UTF8 目录/文件名（d/heimuya、d/jingzhou、d/tulong、d/beijing/map 下共 20 个条目，外加一份多余的 work/version/ 备份副本里的重复条目），这些名字会让基于 Node 的 WASM 测试工具目录扫描直接崩溃（scandir 报 ENOENT）——已改名为安全的 ASCII 文件名，内容不变。管理员账号通过 securityd.lpc 的 create() 里代码层面的默认值播种（这里的 wiz_status 声明为 nosave——从不持久化到存档档案，所以没有数据档案可编辑，播种只能写在代码里）——另外还得 mkdir -p 一个缺失的 log/nosave/ 目录，它会在播种那行代码执行之前就让 create() 静默中止（restore() 自己的 log_file() 呼叫抛出未捕获的异常，只被 master.lpc 最外层的 preload() catch() 接住）。新角色会落在 /d/register/regroom.lpc，需要用游戏内的 register <email> 房间动作才能继续进入真正的游戏世界——这个加上每秒一次的心跳驱动时钟重绘提示，让脚本化的注册后指令验证在 WASM 测试工具里不太可靠（和 nt6/nt6nitan6win 已记录过的同一类无害计时 artifact）；核心的注册+进入游戏世界+管理员权限识别路径已经过扎实验证，不受影响。

## 深度功能测试（§10.7，本轮）

之前几轮只做到 WASM 修复+注册流程验证这一层。这次用真实驱动起服，用 `scripts/mudclient.py`（单一连续 session）完整走了两次注册流程（不同中文名字），全程检查 `debug.log`。

### 发现并修复的 bug

**1. 与 xfbhh/hhsj 同宗的 §7.78，但这是一条独立血统（和它们没有精确 master 哈希匹配）——证明这不是同一份代码复制出来的巧合，而是同一个上游 NT/nitan 架构本身的通病。** `inherit/char/char.lpc` 组合出 CHARACTER 用的 mixin 文件（`alias`/`apprentice`/`attack`/`attribute`/`command`/`damage`/`message`/`more`/`name`，这份代码库用 `F_SHELL` 替换了 xfbhh/hhsj 的 `F_EQUIP_LIV`，同样是独立分支的证据）里有裸 `set()`/`query()`/`query_temp()`/`delete()` 调用，这些文件自己都没有 `inherit F_DBASE`。数量比 xfbhh/hhsj 少很多（这份代码大部分地方已经在用 `ob->set()/query()` 这种正确的写法），但 `command.lpc` 的 `enable_player()` 依然是同款 `set_living_name(query("id"))` 崩溃写法——每个新角色登录都会触发。修法一致：改成 `this_object()->set(...)`/`this_object()->query(...)`。

**2. 新发现：`adm/daemons/eventd.lpc` 的文件名截断算术错误，让每一个区域事件永久失效。** `event_name = map_array(event_name, (: $1[0..<3] :));` 想要去掉 `.lpc` 后缀（4 个字符），但这个驱动的 `str[0..<n]` 语义是"保留 len-n+1 个字符"，`[0..<3]` 实际只去掉了 3 个字符，留下一个尾随的 `.` 加上后缀的第一个字母——`"emei.lpc"` 变成了 `"emei.l"` 而不是 `"emei"`。`collect_all_event()` 于是对着一个根本不存在的路径（`/adm/daemons/event/emei.l`）做 `call_other`，5 个事件档案（`emei`/`huanggs`/`qiantang`/`tianchi`/`wuliang`）全部中招，每次开机都会静默报错、区域事件系统形同虚设。改成 `[0..<5]`（保留 8-5+1=4 个字符，正好去掉 `.lpc`）。

**3. 新发现：`inherit/misc/quest.lpc` 的 `set_information()` 参数类型收窄，导致 9 个任务档案全部编译失败。** `void set_information(string key, string info)` 把 `info` 声明成 `string`，但它转发给的 `adm/daemons/questd.lpc` 自己的 `set_information(object qob, string key, mixed info)` 早就正确地用 `mixed`。`clone/quest/{capture,shen,supply,trace,search,explore,deliver,judge}.lpc`（以及一份 `defend.bak`，未编译，不算在内）全都传一个函式指标 `(: ask_npcN :)` 作为 `info`，被这个过窄的中间层签名挡下来，变成 "Bad type for argument 2... string vs function" 编译错误——9 种任务类型全部因为一个共同祖先档案里的一行代码而完全无法使用。改成 `mixed info` 后一次性修好全部 9 个档案，不需要动任何一个任务内容档案本身。这也是 AGENTS.md 里提到过的教训的又一个实例：一个编译错误在一堆看起来无关的档案上以相同形式反复出现时，先查它们是不是共享同一个继承祖先。

### 未继续测试的部分

时间关系，两次测试都验证到"完整注册+进入注册房间+`debug.log` 干净"为止，没有走到 `register <email>` 之后的先天属性分配（南贤处 `ask nan about gift`）、移动、战斗、任务实际触发等更深的内容——不过第 3 点的编译错误修复本身已经确认了 9 个任务档案现在至少能正常编译加载，比修复前的"完全无法使用"是质的提升。下一轮如果继续深挖这个 lib，建议从 `ask nan about gift` 开始，走完先天属性分配，再实际触发一个任务验证 `set_information()` 修复后的运行时行为。

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级（引入 PR #1343/#1344）后的重测。复核第一轮结论
均仍成立（§7.78 mixin 修法、`eventd.lpc` 的 `[0..<5]` 修法、
`quest.lpc` 的 `mixed info` 修法逐一 grep 确认仍在）。标准检查清单发
现并修复三处问题，其中一处是本项目迄今在这条 NT/nitan 血统上找到的
**最严重的一类 bug**：一个会让驱动长时间（观察到持续 11 小时以上）
几乎满载单核 CPU、并不断悄悄重写数百个真实玩家存档的未捕获异常。

### 标准检查清单发现的修复

1. **`config.fluffos`**：`maximum evaluation cost` 从 `700000`（已知
   风险区间）提升到 `5000000`（本项目标准安全值）。
2. **`adm/simul_efun/file.lpc`**：`log_file()` 原本直接
   `write_file(LOG_DIR + file, text)`，没有 `assure_file()` 目录预建
   保护；补上调用，并加了前向声明（`log_file()` 在文本位置上先于
   `assure_file()` 自身定义——本驱动不容忍未声明的前向调用，否则整
   个开机会崩，参照本 session 在 `dtsl`/`mhxy` 上的发现）。
3. **AGENTS.md §7.10（`log_error()` 警告泄漏）——一次自我纠正的案
   例**：`adm/single/master.lpc` 的 `log_error()` 原本对
   `this_player(1)`/`this_player()` 无条件广播所有编译诊断消息，包括
   纯警告。第一次尝试用 `strsrch(message, "warning:")` 修复（小写），
   现场登录测试时立刻发现漏了——本驱动实际吐出的是**大写** `Warning:
   Unknown #pragma, ignored.`，逐字符不匹配。查阅 AGENTS.md §7.10 才
   发现这正是文档里明确记录过的坑："警告"大小写在这个驱动的历史上
   反复横跳过，正确写法是匹配不带开头 w/W 的子串 `"arning:"`（在
   `"warning:"`/`"Warning:"` 两种大小写下都能命中）。改用这个写法后
   重新开机验证，`update`/`look` 等操作不再往玩家屏幕泄漏警告文本。

### 严重 bug：`adm/daemons/closed.lpc` 的 `load_all_users()` 未捕获
`restore()` 异常，导致数小时级 CPU 满载和真实存档的静默重复重写

**现场发现过程**：第二次开机（已应用上面三处修复）后尝试登录，密码
验证卡住数秒才有响应；`ps` 显示驱动进程持续 80%+ CPU。经过一次长达
数小时的环境挂起（sandboxed 环境两次工具调用之间被暂停了相当长时
间——这不是我主动等待造成的，但恰好让 bug 有足够时间充分暴露）后
再检查，驱动进程本身已经消失（非我手动 kill），`log/`（准确说是驱
动 stdout 重定向文件）里有超过 20000 行输出，其中 127 处
`Eval interrupted...cost limit reached, limit: 5000000 usec` 错误，
横跨 `clone/user/user#707` 到 `#5085` 共数千个不同的对象编号；`git
status` 显示 `data/user/*/*.o` 和 `data/login/*/*.o` 下约 200 个真实
玩家存档全部被标记为已修改。

**根因**：`adm/daemons/closed.lpc` 是"闭关修炼"（离线自动修行）子系
统的心跳精灵，`heart_beat()` 每 10-19 秒调用一次 `load_all_users()`，
对 `closed_users` 映射里记录的每一个"正在闭关"的账号 id，尝试
`new(LOGIN_OB)` → `login_ob->restore()` → `LOGIN_D->make_body()` →
`user_ob->restore()` → `LOGIN_D->enter_world()` 完整走一遍真实登录
流程，把该玩家临时加载为一个真正的、活的 `clone/user/user` 对象。
本档案原始归档自带的 `data/closed.o` 快照里 `closed_users` 记录了
**约 150 个账号**正处于闭关状态——这是原始存档内容本身的特征（真
实玩家在归档快照那一刻确实处于这个游戏状态），不是转档或本轮测试
引入的问题。

问题出在 `feature/save.lpc:18` 的 `restore()`：
```lpc
int restore() {
  string file;
  if (stringp(file = this_object()->query_save_file()))
    return restore_object(file);
  return 0;
}
```
这里直接调用 `restore_object(file)`，没有 `catch()` 包裹。当
`closed_users` 里某个账号的存档本身有真实数据损坏时（现场复现：
`clone/user/user#707`/`#716`报 `*restore_object(): Illegal mapping
format while restoring alias.`——`alias` 这个属性的映射格式损坏，
且这是原始归档数据本身的损坏，与本轮任何修改无关），`restore_object()`
抛出的运行时错误会一路未捕获地穿透 `clone/user/user.lpc::restore()`
→ `closed.lpc::load_all_users()` → `closed.lpc::heart_beat()`，导致：
1. 当次 `heart_beat()` tick 提前中止，`closed_users` 里排在这个损坏
   账号之后的其余条目该 tick 完全没被处理到；
2. 更严重的是，`load_all_users()` 里原本设计好的清理逻辑
   （`destruct(login_ob)` + `map_delete(closed_users, u)`）因为异常
   直接跳过了函式剩余部分，永远执行不到——这个损坏账号既没有被真正
   清理掉，也没有从 `closed_users` 里移除，于是**下一次** heart_beat
   tick 会用一个全新的对象编号重新尝试加载同一个账号，重复触发同一
   个异常，如此往复，永不收敛。
3. 与此同时，`closed_users` 里其余 ~150 个**没有数据损坏**的账号，
   每个完整登录流程本身也相当昂贵（`make_body()`/`enter_world()`
   涉及大量装备/技能物件的首次编译），部分账号单独就能吃满
   `maximum evaluation cost`（哪怕已经提到 5000000usec=5 秒）——这
   是本次观察到的另一层性能问题，`load_all_users()` 每个心跳周期都
   要完整重新走一遍所有 ~150 个账号的登录流程，而不是加载一次后长
   期复用，导致驱动实质上要持续模拟 150 个"幽灵在线玩家"的完整心跳
   负载，这个规模在这台测试硬件上足以让单线程驱动长期维持 80-95%
   CPU 占用。这一部分是"设计上开销很大但架构本身工作正常"（原始
   `enter_world()` 失败路径本身已经有 `catch()` + 清理逻辑，第
   153-158 行），不是本节要修的未捕获异常类别，留作已知的高开销特征
   记录，不在本轮改动范围内（不是程序性 bug，属于"离线闭关模拟"这
   个游戏机制在真实存档规模下的正常固有成本，触碰这部分需要重新设
   计整个心跳节流策略，超出本轮"修复真正的程序 bug"范畴）。

**修复**：只处理未捕获异常这一层（真正的程序 bug），给
`load_all_users()` 里两处 `restore()` 调用分别包一层 `catch()`：
```lpc
// 修复前
if (!login_ob->restore()) { ... }
// 修复后
err = catch(ok = login_ob->restore());
if (err || !ok) { ... }
```
（`user_ob->restore()` 同样处理。）修复后重新开机验证：同一个损坏账
号（`clone/user/user#716`）现在被正确捕获并记录为"错误讯息被拦截"，
而不是让整个 tick 崩溃；观察 150 秒的开机+运行窗口，`Eval
interrupted` 错误数保持为 0（此前第一次开机在类似时间窗口内已经出
现超过百次）。

### 现场登录验证的局限性说明（方法论坑，非程序 bug）

尝试验证真实管理员写入权限时遇到一个和账号持久化相关的方法论陷阱，
记录下来供以后同宗测试参考：本档案 `cmds/usr/quit.lpc` 对
`mud_age < 1800`（账号创建不满 30 分钟）的新账号，`quit` 指令不会走
正常的 `me->save()` 路径，而是弹出"退出该游戏将删除你的账号，你确
定要放弃该帐号而退出吗？(y/n)"的确认——本轮第一次测试会话里，注册
完 `fluffos` 管理员账号后立即发送了 `quit`（账号显然远不满 30 分钟
新），随后为了应用 `master.lpc` 的修复而直接 kill 了驱动进程，没有
等待/回答这个确认提示，导致该次会话从未真正走到任何 `save()` 调用。
重启驱动后用同一账号 id 重连，密码验证失败（`密码错误！`）——这不
是密码持久化的程序 bug，而是这条 NT 血统里已经在 `kxkj`（ES II 血
统，见其 NOTES.md）独立记录过的同类设计：**注册期间设置的密码只存
在内存里，真正落盘要么要等到 `mud_age>=1800` 后的正常 `quit`，要么
需要一次干净的 net-dead 断线**，强行 kill 驱动会跳过这两条路径。本
轮改为依赖第一次会话内（未重启、账号仍在内存中）已经成功验证过的
`update /adm/daemons/logind.lpc` → "重新编译...成功！"作为管理员写
入权限的有效证据，未重新走一遍跨重启的账号验证。**给未来同类测试的
提醒**：测试新注册账号的跨重启持久化时，务必等待 `mud_age>=1800`
真实经过 30 分钟后再 `quit`，或者用断线（net-dead）方式结束会话，
不要在账号很新的时候强行终止驱动进程。

### 现场验证摘要

- 第三次（修复后）开机：干净，0 处 `Fail to load`/`Undefined
  function`；150 秒观察窗口内 `Eval interrupted` 计数保持 0（对照
  第一次开机同等时间窗口内已出现百次以上）。
- 管理员写入权限：`fluffos` 账号（`securityd.lpc::create()` 代码层
  硬编码播种为 `(admin)`）在同一次未重启会话内 `update
  /adm/daemons/logind.lpc` 成功，确认 `file.lpc`/`master.lpc` 两处
  修复编译干净、不影响正常巫师指令。
- 每次开机后都检查了 `git status`：确认 `data/user/*`、
  `data/login/*`、`data/room/*`、`data/closed.o` 的批量"修改"均为
  `closed.lpc` 心跳精灵扫描闭关账号产生的存盘时间戳噪声（推送前已用
  `git checkout --` 逐一还原），不是真实内容变化。
- 本轮注册的测试账号 `fluffos` 的存档文件（`data/{user,login}/f/
  fluffos.o`）因为上面记录的"密码从未真正落盘"问题不具备可用价值，
  本轮**未提交**这两个文件，留给未来一次严格遵循"等 30 分钟或用
  net-dead 断线"流程的会话去正确播种。

### 本轮修改的文件

- `config.fluffos`
- `work/adm/simul_efun/file.lpc`
- `work/adm/single/master.lpc`
- `work/adm/daemons/closed.lpc`

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 51 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 修复（`ROOM` 基类的同一形状 landmine，全档案扫描第 6 批）

- 同样的"多余 `replace_program()`"形状也出现在几乎每个房间都继承的
  `ROOM` 基类上（`/inherit/room/room`）：删除了 `work/` 下 2,748 处存活
  的 standalone `replace_program(ROOM);` 行，以及 `clone/misc/
  roommaker.lpc`（本库在线建房工具）代码生成模板里同形状的
  `str += "...replace_program(ROOM);..."` 变体。
- **⚠️ 本库有已记录的 §7.110 OOM 事故（一次实机开机曾占用 22GB+ 内存
  并压垮主机）——本次修复只用 `lpcc --batch` 静态编译全部 2,748 个改动
  文件验证，未开实机驱动。** 结果：2,746 PASS，2 个失败
  （`d/fuzhou/wuxiang.lpc`、`d/quanzhou/nanhu.lpc`，均为"End of file in
  text block"语法错误）——两个都用原始（修复前）文件单独复测确认是
  **预先存在**的问题，与本次改动无关。编译输出中零 "cannot replace"/
  "cannot bind" 警告。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/bai.lpc`, `d/death/npc/hei.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 5 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（2026-09-04，shop + 拜师）

Live `build-debug` driver on port **40185**. Prior rounds stopped at
the register room (`ask nan about gift` / 先天 / 移动 / 战斗 deferred)
or were static-only (§7.100 / §7.30). First send is **`gb`** (GB/BIG5
menu; `gb` is two letters so `check_legal_id` rejects it and re-prompts
for the English id). No `fluffos.o` existed; `securityd.lpc` `create()`
still seeds `wiz_status["fluffos"] = "(admin)"`. New-character path:
`gb` → `fluffos` → `y` → 秦 / 风 → admin password `Mud@2026x` →
ordinary `Mud@2026` → 性格 `1` → 类型 `5` → `m`. Lands in
`/d/wizard/wizard_room` (WIZARD_ROOM overrides REGISTER_ROOM for
non-players). Live clock prompt needs idle ≤0.45. `register
player@me.com` in `/d/register/regroom`, then `goto /d/register/entry`
→ `wash` → `born 扬州人氏` (客店; `help rules` more-pager — send `q`).
`clone` is `is_admin()` gated (`VERSION_D->is_release_server()` /
`admin_flag==21` / `getuid()=="lonely"`) — design, not removed.
`giveall /clone/money/gold` works via `valid_grant("(admin)")`.

**§7.110:** first boot this pass kept `data/closed.o` (138 闭关
accounts). Port came up, but `load_all_users()` still mass-`enter_world()`s
them; RSS climbed ~5.5GB in ~4 minutes and the 6GB `ulimit -v` process
died. `closed.lpc` `restore()` is already catch-wrapped (round two);
the remaining cost is the design of loading every closed account each
heartbeat, not an uncaught exception. Subsequent boots in this pass
moved `closed.o` aside for the shop/拜师 playthrough only (restored
afterward, not committed). **Never boot nt1 without a memory cap.**

**Bug 1 — `goto` aborted on `MESSAGE_D->find_user()`.**
`cmds/wiz/goto.lpc` always calls `MESSAGE_D->find_user(arg)` before
treating `arg` as a path, which `create()`s
`/adm/daemons/network/messaged.lpc`. `startup_udp()` →
`socket_bind(socket_id, my_port)` got string `"10"` (`Expected: int
Got: "10"`). Uncaught error aborted the first `goto` (wizard stayed in
巫师休息室; the wizard `register` command then fired instead of the
room action). Same shape as `wxddym`: `LOCAL_PORT()` is
`((int) get_config(__MUD_PORT__))` but the bare `(int)` cast is a
no-op on the string `get_config()` returns, and `MESSAGE_PORT` (10)
arrived as string `"10"` too. Fixed `create()` to
`my_port = to_int(LOCAL_PORT()) + to_int(MESSAGE_PORT);`. File is LF.
After reboot, `goto /d/register/regroom` reached 注册房间.

**Bug 2 — `(admin)` character creation dropped `password` /
`ad_password`.** `feature/dbase.lpc` `set()` refuses those keys when
`wizhood(id)=="(admin)"` unless `geteuid(this_player())==id`. During
`input_to` character creation `this_player()` is the login object,
whose euid is not yet the new id, so `ob->set("password", ...)` in
`logind.lpc` silently no-op'd. `login.o` saved without either secret;
reconnect was `密码错误！`. `nitan3` had already commented this guard
out; here it is kept but skipped when `this_player()==ob` (self during
creation) so a third party still cannot `set` an admin password. File
is LF. After the fix, `login.o` contains both hashes and relogin with
`Mud@2026` works.

**Shop:** `/d/city/zuixianlou` 店小二 (`d/city/npc/xiaoer2.lpc`).
`feature/dealer.lpc` already `#include <dbase.h>`, so bare
`query("vendor_goods")` resolves; `list` shows 烤鸡腿 80 文 without a
`this_object()` patch. `buy jitui` deducted one gold into 99 两白银 +
20 文铜钱 and delivered 烤鸡腿. No `F_DEALER` 丐帮 refuse on `do_buy`
(only `do_pawn`).

**拜师:** `goto /d/city/lichunyuan`, `bai kong` on 空空儿
(`kungfu/class/gaibang/kongkong.lpc`) — `permit_recruit()` only.
Accepted: “恭喜您成为丐帮的第二十代弟子.” `score` shows 【门派】丐帮
/ 【师承】空空儿. `save` (after the 30s `last_save` cooldown). After a
full driver kill + reboot, relogin still shows 丐帮 / 空空儿; the
silver/coin change persisted; 烤鸡腿 did not (food, not autoload —
expected). Do not `quit` a fresh character: `cmds/usr/quit.lpc` offers
to delete the account when `mud_age < 1800`.

**Also fixed (same Huashan recruit-limit typo as nitan3):**
`kungfu/class/huashan/{yue-buqun,yue-wife,feng-buping}.lpc`
`recruit_apprentice()` wrote `add("apprentice_availavble", -1)` (extra
“av”) while `attempt_apprentice()`/`reset()` use
`"apprentice_available"`. CRLF preserved. `qingcheng/yu.lpc` is not in
this tree.

`debug.log` for `cd libs/nt1 && driver` is `libs/nt1/log/debug.log`
(opened before chdir into `work/`). Mudlib `error_handler()` also
writes `work/log/debug.log`. Truncated both before the patched boot;
Boot Time Fri Sep 4 05:55:42 2026 matches. No `socket_bind` / `Error:`
lines on that boot. Demo `fluffos` save left uncommitted.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 8 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (2 with the terminator glued to the last text line, 1 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/quanzhou/nanhu.lpc`, `d/fuzhou/wuxiang.lpc`, `u/jinx/wiz.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。
- `cmds/std/team/bunch.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

4 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt nitan_ceshi nt1` 把 nitan_ceshi 警告整理提交（ae7fbb619a5）里的改动搬到 495 个修改前与它一致的文件（逐文件核对非 ASCII 文字：除 nitan_ceshi 自己删掉的以外没有丢失或改动），再用 `scripts/lpc_nitan_family_fixes.py nt1`（`adm/daemons/combatd.lpc` 删去空语句 `your_temp["guarding"];`）。剩下的再跑 `scripts/lpc_warnings.py nt1 --fix`：无用局部变量 1104 个、`varargs` 45 处、`nosave` 函数 27 个改 `protected`、转义 13 处，共改动 1099 个 `.lpc` 和若干 `.h`。
HEAD 与工作树分别加载（新进程）：1087 -> 1087 通过，无回退；改过的头文件的 225 个包含者 223 -> 223 通过。

启动时警告 94 -> 0。登录画面在启动后头几秒不回应输入——`adm/daemons/closed.lpc` 的 heart_beat 正在恢复闭关人物（KB 05 §7.110 的大 `closed.o`），HEAD 也一样，不是这次的改动。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 2 处比较、0 处去后缀（如 `cmds/wiz/lsss.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 3 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 3 个文件，HEAD 与工作树各载入一次无回退（3 objects; HEAD PASS 3, tree PASS 3; regress 0; newly loading 0），这些文件的警告 3 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 6）

- 补齐前几批漏掉的同码副本：`your_temp["guarding"];` 补 `= 0`（反击后清除防守姿态，含 `u/` 下的 combatd 拷贝）；`(: WEAPON_D, "query_action" :)` 改为 `(: call_other, WEAPON_D, "query_action" :)`（KB 04）；`mysql_d.lpc` 的空 `MSG` 宏改成空函数；`gigicook.lpc` 的 `arg == menu_list[0]` 改为 `=`。
- 改动文件：u/lonely/combatd.lpc 
- 改动的对象 HEAD 与工作区都能载入，无回退。

- 2026-10-12：`adm/npc/obj/xiang.lpc`、`adm/npc/obj/xiang1.lpc`、`u/lonely/obj/jubaoxiang.lpc` 写着 `int remove() { save(); }`，盖掉了 `feature/move.lpc` 的 `remove(string euid)`——这些存盘箱子/柜子被销毁时不从携带者身上减负重、不清 handing（KB 06 §7.239 变体，nitan_ceshi/tianxiawuxue 同类）。改成 `varargs void remove(string euid) { save(); ::remove(euid); }`。HEAD 与工作树各载入一次，regress 0（载不进的文件在 HEAD 就载不进）。

- 2026-10-12：`clone/misc/swmuding.lpc`（神木王鼎）自己声明了一张 `mapping insects` 虫表，与继承的 `clone/misc/muding.lpc` 的 `insects` 同名；读表的是木鼎的代码，读到的是木鼎自己的表，神木王鼎的虫表从来没用上（`Redeclaration of global variable 'insects'`）。改名 `sw_insects`，`create()` 里 `insects = sw_insects;` 交给木鼎（nitan170911、wxddym、zjdy 系同修）。HEAD 与工作树各载入一次，regress 0。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 `u/tsunade/godhand.lpc` 多余的 `F_CLEAN_UP`；两张麻将桌 `u/lonely/tools/mj.lpc`、`mjlady3.lpc` 自己的 `count` 与基类同名变量冲突，改名 `mj_count`（同 zhonghua2 的 `mj.lpc`）。能编译的文件警告清零；改动的 3 个对象在 HEAD 与工作树各载入一次，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。6 个文件 6 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/feifeng-whip`、`/kungfu/skill/pangen-cuojiefu`、`/kungfu/skill/yiwei-dujiang`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。15 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 2 个文件。

## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，2 处改为 `add(type, -N)`。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。2 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`sun-finger`。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`bingpo-blade/ningxie`、`duanyun-fu/hong`、`huashan-sword/long.bak`、`taiji-jian/tong`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/nuoyi`、`qiankun-danuoyi/yi`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`longxiang-boruo`→`longxiang-banruo`（`longxiang-banruo`）；`mantian-huayu`→`mantianhuayu`（`taxue-wuhen`）；`shenglong-xinfa`→`shenlong-xinfa`（`shenlong-xinfa`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 密宗猴拳「震」最重的一档报错（2026-10-15）

`/kungfu/skill/houquan/zhen`、`/kungfu/skill/mizong-houquan/zhen` 按伤害分档写描述：前几档都是 `pmsg = ...`，最后一档（伤害 ≥ 80，也就是最重的一击）却写成 `pmsg += ...`，而 `pmsg` 没有初值，本驱动里 `0 += 字符串` 直接报错，这一招打得最狠时反而中断。改为 `pmsg = ...`。

## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 秋林拾叶「随风而舞」成功时报错（2026-10-15，KB 06 §7.252）

`qiulin-shiye/wu` 把房间的出口映射当数组：`mapping *obb = query("exits", env)`，成功时 `me->move(obb[0])`，映射里没有键 0，移动到 0 报错（没有出口的房间则是对 0 取下标）。改为 yanhuangwuhun 一系的写法：从 `values(exits)` 里随机选一个出口。


## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。


## 存档读不出来：转码损坏（2026-10-15，KB 03 §4.4）

`/data/board/chatroom_coke.o`、`/data/board/chatroom_deyee.o`、`/data/user/r/redl.o` 在转码时坏了：原档里孤立的 GBK 前导字节被 `iconv -c` 连同后面的引号一起丢掉，`restore_object()` 报 `Illegal mapping format`，读档的对象（玩家、留言板、信件、表情）从空白开始。按 raw/ 原档重新解码（孤立字节丢掉、引号保留），驱动核对全部能读回（`scripts/lpc_save_encoding.py --from-raw`、`scripts/lpc_save_restore_check.py`）。

## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`help/newsd.o`、`version/help/newsd.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：婚礼最后一步（`d/ruzhou/npc/meipo` 的 `last_marry`）先把月老送走，在这里报错：新人不会被送上花轿去迎宾楼，喜宴没有了。1 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 黯然销魂掌「拖泥带水」气血不足时报错（2026-10-15，KB 06 §7.246）

设置 `cob = find_player(couple)` 的那几行被注释掉了（不再要求配偶在线），后面气血低于四分之一时的招式文字仍用 `cob->name(1)`：正是这一招最该出现的时候报错。改为读存档里配偶的名字 `couple/name`，没有就写“远方”。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

1 个文件、1 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/weapon/sword`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 1 个（0 个原来载入不了），没有退步。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`quest/quest_jun/look.lpc`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 3 个对象设了本库没有文件的武功（14 个名字，最多的是 `xinyuegong`、`taizuquan`、`liangyi-dao`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：3 个里 3 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 14 处、9 个文件：`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`tiaji-jian`→`taiji-jian`（2 处）、`shenkongxing`→`shenkong-xing`（2 处）、`shaolin-shnfa`→`shaolin-shenfa`（1 处）、`taiji-shenfong`→`taiji-shengong`（1 处）、`yan-fly`→`yanfly`（1 处）、`chanquan`→`changquan`（1 处）、`zhoangnan-zhi`→`zhongnan-zhi`（1 处）等共 9 个名字。（`scripts/lpc_fix_skill_names.py`）

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：3 个函数补上 varargs（调用处少传参数）。修后与 HEAD 逐个物件对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 2 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）、`/d/baituo/obj/bowl.lpc`（cctx）。修后与 HEAD 逐个对比载入：这 2 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/u/tsunade/staff1.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/arch/sameip.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 1 处）。改动：`/cmds/adm/roomlong1.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/storyd.lpc`（1 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）、`/version/include/getconfig.h`（1 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 1 个存档共 739 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。`data/dbased.o` 里 739 处是房间 dbase 里的文件名值（物件、出口），键本身没有 `.c`。改动：`/data/dbased.o`（739 处）（共 1 个存档）。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/actionavailable.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：张无忌：`destrory` → `destroy`。改动：`/kungfu/class/mingjiao/zhangwuji.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 7 条注册（6 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/npc/referee.lpc`（`do_halt`）、`/clone/ultra/gift.lpc`（`do_fenpei`）、`/d/changan/npc/wanxi.lpc`（`do_expiate`）、`/d/city/chatroom2.lpc`（`do_jump`）、`/d/tianlongsi/munitang.lpc`（`do_exit`）、`/inherit/misc/fboard.lpc`（`do_list`）。最多的函数名：`do_halt` 2 处、`do_fenpei` 1 处、`do_expiate` 1 处、`do_jump` 1 处、`do_exit` 1 处。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 2 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/jingzhou/npc/smith.lpc`（`do_buy`、`do_list`）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。7 个文件里 12 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 7 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 7 个，现在 7 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`outdoor_room_event()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（inquiry 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/meizhuang/npc/danqing-sheng.lpc`:`ask_me`。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 1 个子目录写日志：`log/money`（`d/ruzhou/npc/meipo.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/money` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"令牌": (: ask_me :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 30 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；NPC 的称呼和提示里取到两个字而不是一个字。

本库 30 处（20 个文件）：拼名字的赋值 16 处、与汉字常量比较 13 处、`to_chinese()[..]` 1 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/fengling.lpc:133`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/emei/tobebonze.h:41`）；`text[0..1] == "№"` → `text[0..0] == "№"`（`/adm/daemons/editord.lpc:83`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。
