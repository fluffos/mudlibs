
## WASM 修复摘要（迁移自 meta.json 的 group_note）

从一个"rar 套 rar"的嵌套压缩包中提取（外层压缩包里有一个"风起云涌.rar"，里面才是真正的 mudlib 根目录，文件夹名叫 xkx2）；和本项目里任何其它档案都没有 master-hash 匹配；启动干净，零修复。完整 WASM 修复：和"海洋/hy"血统同一套 bug 组合（这份档案的 SECURITY_D 也指向 adm/daemons/securd.lpc）——给 band.lpc 加了本地回环放行；修复了 logind.lpc（create()/make_body()/howmany_user()）里 seteuid(getuid()) 把 euid 重置掉的 bug；给 howmany_visitor()/howmany_card() 加上了缺失计数档案的防御；修复了 check_legal_name() 过时的 GBK 字节长度界限，去掉了 i%2==0 门槛；给 securd.lpc 的 get_status() 加上了防重入编译崩溃的保护。新发现的 bug（和 hy5 同一类）：adm/daemons/network/dns_master.lpc 在 3 个函式里无条件呼叫 socket_create/socket_bind/socket_close/socket_write，导致整个档案编译失败——而由于等同于 gb_big5() 的开机流程会间接碰到这个精灵，编译失败会静默破坏每一次连线的 input_to(get_id) 注册流程。已按 AGENTS.md §7.52 把涉及 socket 的函式体掏空成 no-op。管理员账号播种进了 adm/daemons/securd.o 存档文件自身的 wiz_status 属性（逐键用 CR 编码，需二进制模式读写）。注册流程到进入游戏世界、管理员权限识别都已验证。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 94 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-12，round two，本档案第一次真正的 §10.7 深度测试）

此前只做过 WASM 修复摘要 + §7.86 扫描修复，从未跑过真正的注册/游玩
全流程。这是第一次。Re-tested against the freshly-rebuilt
`build-debug/src/driver`（post 全库 `quest_times`/`win_times`
`%`-operator 修复 + Warning/warning 驱动文本回退）。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）对非巫师玩家没有严重度检查
   （AGENTS.md §7.34-class，与本轮 `wdxtym`/`ffxymud` 同一形状）**：
   `if (wizardp(...)) 显示原始诊断; else efun::write("什么?");`——
   巫师之外的每一位玩家，遇到任何编译诊断（哪怕只是最普通的警告）都
   会看到一句没头没脑的"什么?"。真实复现：一次全新驱动进程下的全新
   注册，冷编译级联触发的纯警告，让新角色进游戏前连续看到五次
   "什么?什么?什么?什么?什么?"刷屏。修复：加上
   `strsrch(message, "arning:") == -1` 判断，只有真正的错误才对非巫师
   显示这句提示，警告保持沉默。已用同一新驱动进程下的第二次全新注册
   复测：零次"什么?"。
2. **`new_password()`（`adm/daemons/logind.lpc`）密码校验失败后缺少
   `return`**：`check_legal_password()` 返回 0（密码太短/缺大写/缺
   小写/全字母没有数字或标点/和英文 id 太像）时已经自己 `write()` 了
   拒绝理由，但函数没有 `return`，直接继续往下走——如果密码长度恰好
   ≥5（跳过后面那道独立的 `strlen(pass) < 5` 兜底检查），就会在玩家
   刚被告知"密码不合格"之后，原样把这个不合格密码 `set()` 保存下去。
   静态审查直接确认这条代码路径存在（`abcdefgh` 这类纯字母无数字密
   码就会触发）；修复后用真实注册复现：同一个纯字母密码被正确地重新
   要求输入，直到给出一个真正合格的密码才继续到确认密码步骤。修复：
   补上 `input_to("new_password", 1, ob); return;`。
3. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例）**：`LOG_DIR` 下的
   `nosave/` 子目录在全新检出里不存在，`suicide`/崩溃日志/`purge`/
   巫师晋升等一批只在管理指令路径才会触发的 `log_file("nosave/...",
   ...)` 调用会在首次使用时未捕获抛出。注册/登录本身只写
   `log_file("USAGE", ...)`（无子目录，本来就存在），不受影响，但这
   是一个明确存在、迟早会炸的 bug，按标准模式补上
   `assure_file(LOG_DIR + file);`（含前向声明）。
4. **管理员账号播种从未真正生效（AGENTS.md §1.5 的两种已知 bug 形状
   同时命中）**：`adm/daemons/securd.lpc` 的 `wiz_status` 声明为
   `nosave mapping`——永远不会被存档持久化，每次开机都被
   `restore_list()` 里的硬编码赋值重置成只有一个 `titny`。而 `titny`
   本身已经是原始存档里一个真实玩家（`data/user/t/titny.o`，密码未
   知），`fluffos` 无法冒领这个 id。这意味着此前 WASM 修复摘要里"管
   理员账号播种进了 securd.o 的 wiz_status 属性"这句记录本身就是错
   的——`wiz_status` 从来就没有、也不可能被真正持久化进 securd.o；
   仓库里此前也确实从未提交过 `fluffos` 的存档文件。修复：在 `titny`
   那行旁边并列加一行 `set("wiz_status/fluffos", "(admin)");`。已用
   真实流程验证：注册 `fluffos`/`Mud@2026` 成功（称号显示"天帝"），
   `update /adm/daemons/securd` 成功重新编译，确认写权限真正生效
   （不只是"看起来是 admin"）。README 已同步更正这段此前错误的机制
   描述。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:177`
  `(string)(to_int(query("win_times")) % 5)`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。

### 实测过程

新号走完整注册流程（GB/Big5 选择 → 英文 id → 确认建立 → 中文名，直
接设定不需要二次确认 → 密码 → 确认密码 → 天赋 0 随机 → 接受 → 邮箱
→ 性别），完整进入"混沌之初"起始区域。中途一度怀疑存档没有真正写
入（用同一个 id 在同一驱动进程下二次连线时被当成全新账号处理），但
换一个全新 id 复测后确认注册→存盘→重新登录→存档正确恢复全部正常，
判定是一次性偶发状况（可能是紧接着上一次尝试触发的临时状态），非可
复现 bug——记录下这次排查过程本身，供未来遇到类似"看起来存档失败"
的现象时先排除偶发因素再下结论。`log/debug.log` 全程时间戳未变化，
确认无新增未捕获运行期错误。驱动最终按精确 PID kill，`ps -p` 确认已
退出。

### 已清理

- 测试用一次性小号存档已删除，未提交。
- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos.o`）。

## AGENTS.md §7.100 修复（2026-08-19，批次三）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：3257 处命中。自带建房工具 `clone/misc/roommaker.lpc` 的
字符串拼接模板同样修复。修复过程中因本地一次 `git stash` 误操作，
`d/gumu/tree.lpc` 一度残留了字面 `<<<<<<<`/`=======`/`>>>>>>>` 冲
突标记——提交前被 `git diff` 检查发现，改用从原始 `HEAD` blob 重新
按脚本逻辑派生该文件（二进制安全，保留原始 CRLF/尾随空格）修复，
未手动编辑穿过冲突。

`git diff --stat`：3256 files changed, 1 insertion(+), 3257 deletions(-)，
与预期精确吻合。

验证：`build-debug` 驱动真实冷启动（既有的"Too deep recursion"启动
期警告在改动前的原始代码上同样存在，与本次修复无关），端口 40197
正常监听。既有管理员账号 `fluffos`/`Mud@2026`（GB/Big5 编码选择
后）登录，头衔【天帝】，经 `oldplayer` 路径走访至〖圣殿〗，`quit`
自动存档、干净退出，全程无新增 "cannot replace"/"cannot bind" 日志
行。

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

## 深度功能测试第三轮 / §10.7 round three (2026-09-03)

新角度：2026-08-12 那一轮只覆盖了注册 + 落在「混沌之初」。本轮走
移动、平安城当铺/武馆、扬州实战、白驼山拜师传送、quit 后重连。管
理员仍是播种账号 `fluffos` / `Mud@2026`（中文名阿福，称号天帝，年
龄 14）。登录第一提示是 GB/Big5，先回 `g`。

### 实测过程（无崩溃）

- 有机路径：`newbie` → `east` → `east` → `down` 进入
  `/d/pingan/pingankezhan`。年龄 ≥20 进不了平安城；本号 14 岁所以
  这条路通。kezhan `east` → nan1 `north` → 广场 `east` → dong1
  `south` = 当铺；dong1 `east` → dong2 `north` = 武馆。巫师
  `goto /d/pingan/dangpu` 也能到（驱动会补 `.lpc` 再 `move()`）。
- 当铺唐二：`list` 要分类（`armor|book|misc|weapon`）。空武器列表
  回「目前没有可以卖的武器。」，不是崩溃。`value changjian` = 7 银
  50 文；`sell` 成交，`trade` 升到 1。
- 武馆陈小德（`chen xiaode` / `chen`）：`give gold to chen`（学费
  ≥500 文）后 `xue chen dodge 1`，基本轻功到 1。
- 扬州 `/d/city/guangchang` 有流氓 / 流氓头。`kill liu` 打中流氓头，
  双方互出拳，角色打到「已经陷入半昏迷状态」。之后一次登录因残留
  战斗状态直接眼前一黑。巫师 `full` 回满 HP。`cmds/arch/recover.lpc`
  坏了（`#include obj.h.es2`），不要用；`full` 不调用 `revive()`，
  若仍 `!living()` 要等 `feature/damage.lpc` 的 revive `call_out`
  （约 30–111 秒）。
- 拜师：欧阳克（`/kungfu/class/btshan/ouyangke`）会 `random_move`，
  未加载时 `goto ouyang` 失败。`clone` 后再 `bai ke`：角色内拒绝 +
  传送到 `/d/baituo/liangong`，李教头劝拜他。无崩溃。
- quit 后重连：`trade` + `dodge` 都还在。

### 发现并修复的 PROGRAMMING bug

**`log_file()` ↔ `SECURITY_D` 重入「Too deep recursion」**
（AGENTS.md §7.11 的后续形状，不是缺目录本身）。2026-08-12 在
`adm/simul_efun/file.lpc` 给 `log_file()` 加了
`assure_file(LOG_DIR + file)`。`assure_file()` 里的 `file_size()` /
`mkdir()` 走 `SECURITY_D->valid_read` / `valid_write`。拒绝路径会
再调 `log_file("read_fail.log")` / `log_file("write_fail.log")`，
于是又进 `assure_file()`，直到：

```
Too deep recursion.
program: /adm/obj/simul_efun.lpc, ... file: /adm/simul_efun/file.lpc:25
Too deep recursion.
program: /adm/obj/master.lpc, ... file: /adm/obj/master.lpc:315
```

触发点是开机 `backupd` `create()` → `log_file("backup")`。驱动仍
会听到 40197，但这是真编程 bug，不是无害警告。

修复：`nosave int in_log_file;`。嵌套的 `log_file()` 跳过
`assure_file()`，直接 `write_file()`（`valid_write` 本来就放行
`LOG_DIR` 下的 `write_file`，循环出在 `file_size`/`mkdir`，不是
写文件）。CRLF 按二进制保留。复测冷启动（`/tmp/fqyy2-boot2.out`）
零条 “Too deep recursion”，登录 / skills / quit 仍正常。

兄弟档：同一套 Ocean/hy `securd.lpc` 拒绝日志 + §7.11
`assure_file`-in-`log_file` 至少在 `hy2000` 上也在。本轮不扫全库。

### 本轮未现场走完

- 死亡 / 转生 / 阴曹地府：只打到昏迷 + 巫师 `full`，没有走完地府。

### 本轮修改的文件

- `work/adm/simul_efun/file.lpc`
- 管理员存档 `work/data/{login,user}/f/fluffos.o`（本轮后状态）

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (2 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest`、`quest/dynamic_location` 里 1261 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/newquestd.lpc`、`adm/daemons/questd.lpc`、`adm/daemons/questd2.lpc`、`cmds/std/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 517 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：4 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成；`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：`adm/daemons/newquestd.lpc`、`adm/daemons/questd.lpc`、`adm/daemons/questd2.lpc`、`cmds/std/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 5 个，工作树三次分别通过 5、5、5 个（共 5 个），无回退。
验证：改动过的 `adm/daemons/newquestd.lpc`、`adm/daemons/questd.lpc`、`adm/daemons/questd2.lpc`、`cmds/std/look.lpc`、`cmds/std/questd.lpc` 在新进程里加载，HEAD 通过 5 个、工作树通过 5 个（共 5 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py fqyy2 --fix`：无用局部变量 1922 个、转义 73 处、`nosave` 函数 37 个改 `protected`、`varargs` 19 处，共改动 922 个 `.lpc` 和若干 `.h`。`scripts/lpc_fix_no_effect.py --apply`：`d/tiezhang/pingtai.lpc`、`wmfeng.lpc`、`wztang.lpc` 删去 `return` 后面永远执行不到的 `"\n";`，`kungfu/skill/xuanyuan-arrow.lpc` 删去什么也不做的 `(: throw_weapon :);`，`dns_master.lpc` 把 `#if PREF_* & SVC_TCP` 移到 `if` 外面。
手工：`d/xingxiu/shanjiao.lpc`、`nanjiang2.lpc`、`nanjiang3.lpc` 删去空的 `if (current_water == 0) {}`；`kungfu/skill/liangyi-jian.bak.lpc` 删去空语句 `level;`。
HEAD 与工作树分别加载（新进程）：895 -> 895 通过，无回退；改过的头文件的 216 个包含者 216 -> 216 通过。`scripts/lpc_audit_removed_locals.py HEAD` 的 19 条候选都是声明被重建或同名 efun。

启动时警告 105 -> 0；新进程登录（编码选择、新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 10 处，返回类型/原型 29 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 34 个文件，HEAD 与工作树各载入一次无回退（34 objects; HEAD PASS 32, tree PASS 32; regress 0; newly loading 0），这些文件的警告 41 -> 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。9 个文件 12 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/zhenup.lpc`（`damage *=`）、`/u/xtuzi/taiji-quan/zhenup.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：同一次重扫的其余 16 条：8 个文件在基类已有的情况下又 `inherit F_CLEAN_UP`，删去；`fang`、`qiuhang1` 的 `unconcious()`（dangpu 与 damage 两份）和 `li.lpc` 的 `clean_up()` 写明胜出者（行为不变）；`STORY_DIR` 宏重定义前加 `#undef`；`huashan-jian.lpc` 多余的 `;`。改动的 22 个对象新进程各载入一次，无回退。
- 2026-10-14：`feature/alias.lpc` 的指令频率计时 `nosave int last_time` 与平安城神医 `shenyi.lpc` 自己存档的 `last_time` 同名（KB 04：存档的那份不能改名，否则旧 `.o` 里的键对不上），改名基类私有的那份为 `last_cmd_time`。

- 2026-10-14：79 个文件用了颜色宏（`HIW`、`NOR` 等）却没有 `#include <ansi.h>`（本 lib 的 `globals.h` 不带它），首个错误是 `syntax error, unexpected L_STRING`，整份不编译：成都 `d/city3` 的客房、菜谱、`clone/weapon/bb_zhen` 等。每个文件开头补上 `#include <ansi.h>`。新进程比对 HEAD 与工作树：80 个对象，新增载入 69，回退 0（其余缺 `/inherit/item/embed.h` 等内容）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。6 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 14 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 4 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，2 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。9 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`（`ob->query_temp("weapon")` 报错），还把兵器对象和字符串 "银针" 比较。改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`、`duanyun-fu/hongtianza`、`huanhua-jian/snow`、`murong-jianfa/kuangjian`、`tianyu-qijian/kuangwu`、`wuyue-blade/jiao`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`/quest/jinyongjob/jinyong` 生成的任务怪物照抄玩家福缘（`set("kar", who->query_skill("kar"))`，怪物福缘一直为 0）。

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`guiyuan-dafa`、`tiangang-zhengqi`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`yinyun_ziqi`→`yinyun-ziqi`（`yinyun-ziqi/cure`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`chanyun-tui`→`chuanyun-tui`（`chuanyun-tui/shuangjue`）。

## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。6 处（4 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunv-jian/suxin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`clone/gift/npc/bingqipu.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：婚礼最后一步（`d/nanyang/npc/meipo` 的 `last_marry`）先把月老送走，在这里报错：新人不会被送上花轿去迎宾楼，喜宴没有了；喜宴结束、礼金付出之后，喜来福（`d/nanyang/npc/xi-laifu`）退回内堂时报错，留在楼上。2 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

11 个文件、25 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/quest/blade`、`/quest/armor`、`/clone/misc/long_cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 9 个（8 个原来载入不了），没有退步；其余 2 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`BULLETIN_JBOARD` → `/inherit/misc/jboard`（1 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：1 个里 0 个通过，其余 1 个还有别的错误（`d/board/wizard_j.lpc`：Undefined variable 'HIY'）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 34 个对象设了本库没有文件的武功（31 个名字，最多的是 `luohua-jian`、`youlong-shenfa`、`bugui-bufa`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 25 个通过，其余 5 个停在别的错误上（`clone/npc/zhong-shentong`：*No program in object '/clone/npc/zhong-shentong'!；`d/honghua/guanjia`：*No program in object '/d/honghua/guanjia'!……）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/stick`（宏 `STICK`）←wmkj，2 个对象继承它，抽样 2/2 载入；`/inherit/weapon/weapon_combo`（宏 `WEAPON_COMBO`）←xjcq2000，2 个对象继承它，抽样 2/2 载入；`/feature/frozen`←bxsj，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 50 处、42 个文件：`kunlun-shnfa`→`kunlun-shenfa`（12 处）、`shaolin-shnfa`→`shaolin-shenfa`（11 处）、`yunu-shenfa`→`yunv-shenfa`（6 处）、`yunu-xinfa`→`yunv-xinfa`（5 处）、`yijin-jing`→`yijinjing`（3 处）、`lingbo-weibu`→`lingboweibu`（3 处）、`tiaji-jian`→`taiji-jian`（2 处）、`yan-fly`→`yanfly`（2 处）等共 14 个名字。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 3 处、3 个文件：`::do_discard()`（2 处）、`::do_eat()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 全局头文件丢了 3 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `ARMOR_D(x)`、`BINGQI_D(x)`、`LANGUAGE_D`，用到它们的物件（名单里 3 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 3 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- 5 个 NPC 文件、5 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）
- `d/honghua/npc/xutianhong.lpc` 第 63 行 `ob - query("family/master_id")` 改成 `ob->query(...)`（手误，物件编译不过）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：4 处重复的 inherit。修后与 HEAD 逐个物件对比载入，没有退步。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/hangzhou/npc/tangzi.lpc`：整个文件只是 UTF-16 的空格（`\x00 \x00 …`，作者把这个物件清空了），驱动报 `Illegal embedded NUL byte (0x00) in source`；旧驱动编出一个空程序。改成一个换行，行为和原来一样（空程序），不从 xkx100 抄回同名 NPC。

逐个载入与 HEAD 对比，没有退步。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc` 等（共 7 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `kungfu/skill/huashan-jian.lpc`：数组 `});` 后面单独一行的 `;` 删掉（`Extra ';'. Ignored.`）。

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/clone/npc/luohantang-shouzuo.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/d/changan/ca2.lpc`（1 处）、`/d/haojie/npc/tianshaxing.lpc`（1 处）、`/d/haojie/obj/tianshaxing.lpc`（1 处）、`/d/haojie/tianshaxing.lpc`（1 处）、`/d/mingjiao/shanmen.lpc`（1 处）。另有 `/d/city/new-mj.lpc`（2 处）、`/d/city/npc/new-mj.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 6 处）。改动：`/adm/daemons/combatd.lpc`（1 处）、`/d/city4/puke-room.lpc`（4 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 访客计数 `howmany_visitor()` 读文件不检查（2026-10-20，KB 06 §7.301）

`howmany_visitor()` 读访客计数文件（`VISITORS` / `COUNTER` / `BBSVISITOR`，只有运行中的 mud 才会写；`.gitignore` 把它排除在仓库之外），新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不一定走到它，但调用时同样会出错。在读文件之后加了 `if (!stringp(content)) return 0;`（xkx100、xiakexing100、zzfy 早先的写法，`scripts/lpc_fix_visitor_count.py`）。改动：`/adm/daemons/logind2.lpc`。

## 华山论剑排行榜：第一场比武就读不到 `/data/ladder.txt`（2026-10-20，KB 06 §7.326）

比武裁判在一场比武结束时先 `list = explode(read_file("/data/ladder.txt"), "\n")`，读完再 `rm` 并 `write_file` 写回；`/data/ladder.txt` 是比武本身写出来的，全新的树里没有，第一场比武结束就是 `Bad argument 1 to explode()`，排行榜永远建不起来。把写回之前的那一次读改成 `read_file(...) || ""`（空表走原来的 `lost == -1 && win == -1` 分支，把第一对名字写进去）；写回之后的第二次读文件已经存在，没有动。加载检查各 1/1。

## `wizwhatdo`、`setmission`：`explode(read_file("/adm/daemons/wizmission"))`（2026-10-21，KB 06 §7.326）

巫师名单命令 `wizwhatdo`（在 `cmds/std`，玩家能敲）和 `cmds/imm/setmission` 都先 `explode(read_file("/adm/daemons/wizmission"), "\n")`；这个文件由 `setmission` 写，归档里没有，`read_file()` 答 0，`explode(0)` 抛 `Bad argument 1 to explode()`：玩家敲 `wizwhatdo` 是运行时错误，巫师也没法用 `setmission` 建出这个文件（读在写之前）。读不到按空文本处理（`read_file(...) || ""`，`explode("", "\n")` 是空数组，名单里每个人显示 "(任务未定)"，`setmission` 走 `write_file()` 新建的分支）。hy 系的其余库（hy、hy2000、hy2002、hy5、hymud、haiyang2、hyiishzdscbb）带着这个文件，没有问题。实测：`wizwhatdo` 打出巫师名单。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/clone/guard/baoer.lpc`、`/clone/guard/long2.lpc`、`/inherit/char/npc.lpc`（共 3 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 29 个存档共 29 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/p/residence/dodo1012573917.o`（1 处）、`/p/residence/dodo1012574161.o`（1 处）、`/p/residence/jad998790693.o`（1 处）、`/p/residence/jad998790833.o`（1 处）（等共 29 个存档）。

## `home`：模板 `/clone/misc/wizroom.lpc` 档案里没有（2026-10-21，KB 06 §7.310）

管理员扫描里 `home` 报 `Bad argument 1 to EFUN replace_string() Got: int(0)`（`cmds/imm/home.lpc` 第 30 行）：巫师还没有工作室时，`home` 从 `/clone/misc/wizroom.lpc` 读模板，把 `NAME` 换成名字写进 `/u/<id>/workroom.lpc`；本库没有这个模板，`read_file()` 答 0，第一次敲 `home` 的巫师就是系统错误。`wizroom.lpc` 是这一系的公用文件（hy3、chidi、wmkj、yxcs 等 28 个库都带，内容相同，只差换行符：“没有建造工作室的巫师的临时住处”，出口 `north` 通 `/d/wizard/wizard_room`，本库有这个房间），从 hy3 原样复制过来，加载检查通过。

## `lsusers`：用档案里没有的 `/clone/misc/player`（2026-10-21，KB 06 §7.299）

管理员扫描里 `lsusers` 报 `Bad argument 1 to EFUN call_other() Got: int(0)`（`cmds/adm/lsusers.lpc`）：指令 `new("/clone/misc/player")` 一个对象，用它的 `new_object(name)` 逐个还原玩家存档；本库没有 `/clone/misc/player.lpc`（同系的 hy3、jhfy、xyzx 等 27 个库带着它，`new_object()` 只定义在那里），`new()` 答 0，后面就是对 0 的调用。`new()` 之后加 `if (!ob) return notify_fail(...)`，指令回一句话而不是系统错误；文件本身补不上，那个旧的玩家对象已经不是本库的用户对象了。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（4 个文件）：`/cmds/adm/blockade.lpc`、`/cmds/adm/recover.lpc`、`/cmds/arch/blockade.lpc`、`/cmds/arch/recover.lpc`。

## `bangnick`：对字符串参数调用 `->query()`（2026-10-21）

管理员扫描里 `bangnick`（玩家指令 `cmds/usr/bangnick.lpc`，wmkj、yxcs 同一份）报 `Bad argument 1 to EFUN call_other() Got: int(0)`：`main(me, arg)` 的头两行 `int bangzong = arg->query("bangzong"); int bangpai2 = arg->query("bangpai");` 对字符串参数调用函数，不带参数时是对 0，带参数时是 `call_other() couldn't find object '<参数>'`：这条指令对任何输入都不工作。作者要的大概是 `me` 的 `bangzong` 和目标的 `bangpai`（目标要等 `sscanf` 解析出 `dest` 才知道），但哪一边是谁只能猜，没有改。

## `obj.h.es2`：`blockade` / `recover` 包含的头文件档案里没有（2026-10-21，KB 04 §6.23）

`blockade.lpc`、`recover*.lpc` `#include <obj.h.es2>`（`OBJ_*`、`NPC_*` 路径的 ES2 头文件，hy5、xkx100 等 33 个库带着），本库的 include 目录没有它，这些指令从来编译不了（`Cannot #include obj.h.es2`），`data/keep` 的修补也无从生效。指令本身不用里面的宏；从同系的 hy5 复制一份头文件，加载检查 HEAD 与工作树对照：2 个对象原来加载失败，现在通过，没有退步。

## `selfthinking`、`qlian`：缺乏实战经验的提示读了不存在的老师（2026-10-21，KB 06 §7.348）

自创武功的自习指令在“技能等级³/10 大于实战经验”时打印 `printf("也许是缺乏实战经验，你对%s的回答总是无法领会。\n", ob->name())`。这一句是从 `learn` 抄来的，`ob` 是老师；自习没有老师，`object ob;` 从没赋值，`ob->name()` 抛 `call_other() ... Got: int(0)`。改成 `你对「%s」的疑问总是无法领会` 加 `to_chinese(skillname)`，去掉没用的 `object ob;`。改动：`/cmds/skill/selfthinking.lpc`。

## 瓦耳拉齐 `ask_back`：送回去的是没赋值的 `ob`（2026-10-21，KB 06 §7.348）

带着地图问“回去”时 `ob->move(__DIR__ "entrance")`：`ob` 没赋值，路径也错成了 `/d/gaochang/npc/entrance`。xkx100 的原文是 `me->move("/d/gaochang/entrance");`，照改，去掉 `object ob;`。改动：`/d/gaochang/npc/wuaer.lpc`。

## 妙手回春 `valid_learn()`：先读 `ob->query_temp("weapon")` 再给 `ob` 赋值（2026-10-21，KB 06 §7.348）

学这门暗器技能时 `valid_learn()` 第一个武器检查读的是没赋值的 `ob`，`xue` / `learn` 在这里抛错；后面 `ob = me->query_temp("weapon")` 的检查才是对的。有两种写法：`if (!ob->query_temp("weapon"))` 改成 `me->query_temp("weapon")`；`if ((string)ob->query_temp("weapon") != "银针")`（拿一个对象和字符串比较，永远不等，补上 `ob` 之后这门技能也学不成）改成后一种写法里的 `!objectp(ob = me->query_temp("weapon")) || !(ob->id("yin zhen") || ob->id("yinzhen"))`。改动：`/d/pingan/pingan/shenzhen/skills/miaoshouhuichun.lpc`、`/d/pingan/shenzhen/skills/miaoshouhuichun.lpc`。

## 守卫 `clone/guard/baoer.lpc`：`do_send()` 里丢了收尾引号，整个文件从来没编译过（2026-10-21，KB 03 §4.6 第五轮、KB 06 §7.349）

`new_id=ob->query("id")+"'s bao er;` 少了字符串结尾的引号：字符串一直读到下一行的引号，后面的汉字全成了 `Illegal character 0xe5`（几千行错误，批量验证器里的表现是“没有答案”）。补成 `"'s bao er";`。文件第一次能编译后带出 11 个 `Unused local variable` 警告（`host_id`、`i`、`obj`、`shape`、`emotes`、`inv`、`msg`、`same_place`、`couple_id`、`couple_name`、`couple`），按 KB 04 §6.10 删掉。文件里的 `do_heji` / `do_lian` / `do_order` / `do_title` / `do_ticks` / `do_sha` / `do_shape` / `do_hulian` / `do_quit` 等处理函数都有定义（静态扫描因为引号没闭合把它们当成字符串里的文字，补引号后运行时 `function_exists()` 全部证实存在），所以这个文件的 `add_action` 不属于死登记，没有动。改动：`/clone/guard/baoer.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 34 条注册（31 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/board/hy2news_b.lpc`（`do_discard`）、`/cmds/usr/news.lpc`（`do_discard`）、`/d/city/chatroom2.lpc`（`do_jump`）、`/d/city3/npc/sister.lpc`（`do_vendor_list`）、`/d/city4/qishi.lpc`（`do_pass`、`do_resign`）、`/d/mr/shuichi.lpc`（`do_strike`）、`/d/pingan/pingan/npc/sighmoon.lpc`（`do_vendor_list`）、`/d/quanzhen/npc/haodatong.lpc`（`do_decide`）、`/d/quanzhen/npc/mayu.lpc`（`do_decide`）、`/d/quanzhen/npc/qizhicheng.lpc`（`do_decide`） 等共 31 个文件。最多的函数名：`do_send` 15 处、`do_decide` 6 处、`do_discard` 2 处、`do_vendor_list` 2 处、`do_strike` 2 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 商人的 `list` 命令：登记的是另一个血统的函数名（2026-10-22，KB 06 §7.349）

第 42 批把 `add_action("do_vendor_list", "list");` 当成死登记删掉了（这些文件里没有 `do_vendor_list`，输入 `list` 只会得到 `*Function for verb 'list' not found.`），但它们的商人基类里同一个工作的函数叫 `do_list`，`list` 动词就此没了：`/d/city3/npc/sister.lpc`。按真正存在的函数名放回 `add_action("do_list", "list");`；用库的管理员账号克隆 NPC 再输入 `list` 实测（`/d/city3/npc/sister.lpc`：`您想看哪一种货物(armor, book, misc, weapon)？ ⊙`），每个文件都列出商品或问要看哪一类。同一批里放回去后仍答 `什麼？`、没有商品或者列表时报错（货品文件缺失）的商人没有动。
