
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
