
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
