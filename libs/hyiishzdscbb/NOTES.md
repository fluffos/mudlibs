
## WASM 修复摘要（迁移自 meta.json 的 group_note）

海洋II（Ocean II）血统，hy2000/hy2002 的手足档案（分别按路径和两者重合约 9600/10253 个档案）——上海站第三版快照。修复的 bug（全部是主动套用已知的 hy2000/hy2002 修法并确认这里同样存在）：（1）过时的 MASTER_OB/SIMUL_EFUN_OB 宏指向 /adm/single/ 死代码副本（§7.56 类）；（2）howmany_visitor()/howmany_card()/uptime.lpc 的 LASTCRASH 显示里 §7.54 类的 sscanf/write(read_file(缺失档案)) 崩溃；（3）adm/daemons/network/dns_master.lpc 的 startup_udp()/send_udp()/send_shutdown() 里 §7.52 类的 socket 掏空；（4）经典 §8.1 check_legal_name() 字节数没减半的长度界限 bug（2/10→1/5 字符）加上 i%2==0 门槛和 name[i..<0] 尾部切片（is_chinese() 本身已经是正确的）；（5）§7.63 quit.lpc 的 new('/clone/topten/magic-rice') 缺少防御性判断 if(ob=new(...))，和 hy2000 的模式完全一致。管理员引导偏离常规模式（和 hy2002 同一类 §1.5 bug）：securd.lpc 在 restore_list() 里硬编码了引导用管理员 id "titny"，但这个 id 已经是档案里一个真实存在的旧玩家账号——已在旁边追加一行 set("wiz_status/fluffos","(admin)")，用 fluffos/loginpass1 注册，游戏内"目前权限：(admin)"显示确认生效。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字；GB 和 BIG5 两种编码都实测正常（gb_b5d.lpc 的中文字转换表里有一处无害的编译警告，两种模式下文字都能正确显示）。格式化工具发现 1 个真正损坏的档案（cmds/usr/setbak.lpc，和 hy2000/hy2002 一样的 heredoc 帮助文字损坏）——已用 git checkout 还原。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 53 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，第一次真正的 §10.7 深度测试）

此前只做过 WASM 修复摘要 + §7.86 扫描修复，从未跑过真正的注册/游玩
全流程。这是第一次。Re-tested against the freshly-rebuilt
`build-debug/src/driver`（post 全库 `quest_times`/`win_times`
`%`-operator 修复 + Warning/warning 驱动文本回退）。这份档案和
`hy2000`/`hy2002` 是同一套"海洋II"血统的又一个快照（README 已记
录），管理员 `wiz_status/fluffos` 并列授权行已经从更早的一次会话
里正确修复过（`titny` 是已被占用的真实旧账号，和 `hy2002` 的
`hxsd` 同一形状），本轮只发现并修复了 log_error()/log_file() 两处。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fy2mg`/`fys`/`hc`/`hy`/
   `hy2000`/`hy2002`/`hy3`/`hy5` 同一原始形状）**：`if
   (this_player(1)) efun::write(...)`——不区分巫师/玩家，也不区分
   警告/错误。修复：加上 `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例）**：注册/登录本身只
   写 `log_file("USAGE", ...)`（无子目录，本来就存在），不受影响，
   但 `nosave/CRASHES`/`nosave/PURGE`/`nosave/tengaoshou`/
   `nosave/tenrich`/`nosave/addobj` 等管理指令路径会在首次使用时未
   捕获抛出。已补上 `assure_file(LOG_DIR + file);`（含前向声明）。

### 管理员账号：存档从未真正提交

README 记录"账号通过正常注册流程创建，已在游戏内确认'目前权限：
(admin)'显示正确"——`git log` 确认这个存档从未被提交过，本地
`work/` 目录里也不存在。已用真实注册流程（英文 id → 确认建立 →
中文名，直接设定不需要二次确认 → 密码 `loginpass1` → 确认密码 →
天赋 0 随机 → 接受 → 邮箱 → 性别）重新创建 `fluffos`/浮浮，`score`
确认"目前权限：(admin)"，`update /adm/simul_efun/file`（就是本轮改
过的文件）确认可正常重新编译，本次是真正的 live 验证。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:177`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。

### 实测过程

登录时有一个 GB/Big5 选码提示（选 `g`）。`adm/log/debug.log` 时间
戳全程未变化（`Jul 30`，早于本次会话），确认无新增未捕获运行期错
误。驱动最终按精确 PID kill，`ps -p` 确认已退出。

### 已清理

- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos.o`）。

## §7.100 修复（`ROOM` 基类的同一"多余 replace_program()"形状，全档案扫描第 6 批）

- 删除 2,623 处存活的 `replace_program(ROOM);` 相关行，与普查记录一致。
  除脚本批量删除的标准 standalone 行外，另手工修复三处不规则形状：
  `d/happy/workroom.lpc` 的行尾空注释变体（`replace_program(ROOM);
  //`）、`adm/roommaker.lpc`（本库第二套建房工具，独立于
  `clone/misc/roommaker.lpc`）里 `room_code`/`str` 两处字符串拼接
  模板变体。
- 验证：真实 `build-debug` 驱动干净开机、端口正常监听，`debug.log` 中
  零 "cannot replace"/"cannot bind" 行。

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
