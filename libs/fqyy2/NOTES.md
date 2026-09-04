
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
