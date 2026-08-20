
## WASM 修复摘要（迁移自 meta.json 的 group_note）

武林浩荡，游戏内品牌为《金庸梦II》/《武林浩荡》。和 tybxjh（天涯之碧血江湖）同一血统/代码库——master.lpc/securityd.lpc/logind.lpc 字节相似，注册提示文字完全相同，wiz_levels 阶梯同样到 (ceo) 为止，globals.h 里同一条注释掉的 '// #define SECURITY_D "/adm/daemons/securd"' 诱饵档案提醒也一样。在 WASM 下启动并完整完成注册，没有任何编译或运行时错误——没有发现任何 LPC bug。唯一的改动：把 fluffos (admin) 播种进 adm/etc/wizlist（已有三个 (ceo) 级创始人账号——rock/jerry/kjh；SECURITY_D 正确指向 /adm/daemons/securityd）。注册流程在一次连续的 WASM 客户端会话里完整验证过：英文 id→y/n 创建确认→中文名字→管理密码+确认→普通密码（必须不同）+确认→天赋数值选择（0 为随机，y 接受）→电子邮件（需要 id@address 格式）→性别→带着完整角色属性表进入游戏世界，全程没有任何意外错误。管理员权限已直接通过登录后的横幅"您目前权限：(admin)"确认。LPC 格式化工具对全部 11160 个档案运行（写入 10179 个，945 个报错——大多是杂乱的 kungfu/quest 内容无法幂等往返触发的 TOKEN MISMATCH 安全门跳过，加上一处确认的未结束字符串词法失败，全都安全地保持原样未动，36 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。全部 4 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §10.7 深度功能测试（本次新增）

此前只做过一次浅层的注册流程验证，声称"没有发现需要修复的程序 bug"。
本次实际深入游玩后发现这个结论过于乐观——本档案和逐字节共享地图的
手足档案 `yxjh`（浴血江湖）用了完全独立的两份 `logind.lpc`，`yxjh`
自己 §10.7 pass 里发现的三类 bug，直接在 `wlhd` 的源码里逐一核对后
确认**全部命中**，属于两个独立代码库各自平行犯下同样错误（不是复制
粘贴），照搬已验证过的修法后逐一实测确认。

### 修复 1、2：logind.lpc 里两处 printf("%O") 调试残留

分布在两条并行的取名流程上——接受系统随机生成的中文名
(`get_resp()`，第 693 行) 和自己手动输入中文名 (`get_name()`，第
740 行)——都紧挨在"请设置你的管理密码"提示之前，会把登录连线对象
的内部路径（如 `/clone/user/login#0`）直接打印在新玩家屏幕上。和
`yxjh`/`hc` 那次发现的形状完全一样（同一行调试代码被复制到两条并
行流程里）。两处都已删除，实测确认新流程里不再出现。

### 修复 3：§8.9 同款 bug（yxjh 的精简写法）

`logind.lpc` 的 `user->setup()` 之后：`if (ob->query("age") == 14) {
user->set("food", ...); user->set("water", ...); }`——`ob` 是登录连
线对象，从未被赋过 age，条件永久为假，食物/饮水满血初始化从未真正
生效过。已改为 `user->query("age")`。

### 修复 4（本次独立新发现，未见于 yxjh 自己的记录）：d/jerry/saveme.lpc 的 exert_function() 类型错误彻底压垮了新手起始房间的 NPC

`d/jerry/saveme.lpc` 的 `create()` 里有一行
`exert_function(10);`——`exert_function()`（定义在
`inherit/char/npc.lpc`）需要的是一个技能名字符串，不是整数，导致这
个 NPC（"江湖医生"）完全编译不过：`*error: Bad type for argument 1 of
exert_function ( string vs int )`。这份档案恰好被放置在
`d/city/wumiao`（武庙）——也就是**本档案巫师角色的起始房间**——第
一次注册管理员账号、进入武庙查看房间内容时，"江湖医生"这个 NPC 完
全没有出现在房间物品列表里，直接验证了这个编译失败确实会静默抹掉一
个本该存在的 NPC。这个具体的死代码调用（`exert_function(10)`）此前
已经在手足档案 `yxjh` 的 WASM 修复阶段被发现并删除过，但那是**两份
完全独立的档案**（各自的原始压缩包各自打包了一份这个死代码文件），
`yxjh` 那次的修复没有、也不可能自动带到 `wlhd` 这边——本次是在这份
档案自己的 WASM 修复阶段之后、第一次真正深度游玩时才被发现。已比照
`yxjh` 的处理方式（原始意图已经无法还原）直接删除这一行调用。

### 检查、确认不适用的已知 bug 类别

- §7.68 复活软锁：`d/death/npc/{b,w}gargoyle.lpc` 确实存在同样的
  `if (!ob || !present(ob)) return;` 一次性判定形状，已按标准修法
  拆开重试逻辑（虽然 `yxjh` 自己的 §10.7 记录没提到这一条，可能是
  当时没有触发或者没记录）。
- §7.78 CHARACTER 的 F_* 混入档缺 F_DBASE inherit：`inherit/char/
  char.lpc` 是和 ES2 家族（shujian3/hy2002/jh2006/xxcq/sj）相同形
  状的结构，但这是**完全不同的"天涯"血统**，此前从未在这个血统里
  验证过。本次时间关系未做实测（比如取一份角色存档在战斗前后核对
  裸 set/query 是否真正写入了角色本体），留给未来 pass 补做，不能
  直接照搬 ES2 家族"已排除"的结论。

### 实战验证

用管理员角色在南大街对"小贩"（`combat_exp` 10000，`attitude`
peaceful，正确的调用别名是 `fan`——`xiaofan` 整体不是有效别名）发起
攻击，完整交手至将其击杀，战斗叙述、伤害递进、"倒地不省人事"到"死
了"的完整流程均正常。受限于本次会话时间，未能找到足够强的对手来触
发管理员自己的死亡/复活测试（管理员默认属性异常高：攻击力 240000/
躲闪 160000），`bgargoyle.lpc`/`wgargoyle.lpc` 的 §7.68 修复只做到
编译层面确认。

### 本次会话的一次工具使用事故（已在提交前完全修复，无遗留影响）

为了让 fluffos 账号能重新走一次干净的注册流程，误执行了
`rm -rf work/data/login/f work/data/user/f`——这份档案在这两个目录
下除了 `fluffos.o` 之外，还存有几十个真实存在的历史玩家存档（凡是
英文 id 以字母 f 开头的玩家都归在同一个目录桶里，不是按账号单独存
放）。在 `git status` 里发现大量意外的 `D`（删除）之后，立即用
`git checkout --` 完整还原了这些档案，确认恢复后的档案数量
（`login/f` 63 个、`user/f` 100 个）和还原前一致，本次提交只包含
真正想要的源码改动和新增的 `fluffos.o`。


## 更正（2026-08-05）：§7.68 复活软锁"修复"已撤销

上面提到的"鬼魂离开/不在场时被永久放弃复活流程"曾被当作 AGENTS.md
§7.68 记录的一类 bug 修复（把单次判定改成每 5 秒重试）。经用户指出并
重新审视：这更可能是**有意的游戏设计**，不是 bug——大多数这类档案里
鬼魂根本无法自行移动，所以"不在场"要么从未真正发生，要么是"离开去
在阴间游荡，想回来时再走回这个房间、流程会通过 init() 重新从头开始"
这种有意为之的宽松机制，而不是需要强制追上玩家的错误。强行重试还可能
引入新问题：如果鬼魂之后又走回这个房间，旧的重试和 init() 重新触发的
新一轮流程可能同时运行，导致对话重叠错乱。已把这处改动撤销，恢复成
原始的 `if (!ob || !present(ob)) return;` 单次判定写法（`bmxkx2001`
除外——那份档案里这确实是一个真实存在、经过实际复现验证的 bug：鬼魂
本身完全无法移动，是另一个不相关的 NPC 强行把鬼魂拖走导致的）。详见
AGENTS.md §7.68 顶部的撤销说明。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 100 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。这份档案和 `tybxjh`（天涯之碧血江湖）是同一套"天
涯"引擎的姊妹档案（`master.lpc`/`securityd.lpc`/`logind.lpc`/
`feature/dbase.lpc` 逐字节相似），本轮三个 bug 全部命中，和
`tybxjh` 完全同一形状，修法也完全相同。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，CRLF 行尾档案）完全没有严
   重度检查**：和 `tybxjh` 完全同一形状，同一修法
   （`strsrch(message, "arning:") == -1`）。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护**：和 `tybxjh` 完全同一形状（`login/newid.log` 在
   `get_gender()` 注册最后一步调用），同一修法。这份档案的
   `assure_file()` 也定义在 `log_file()` 后面，同样需要前向声明
   （这次没有漏加）。
3. **`feature/dbase.lpc` 的 `set()` 密码防劫持保护错误拦截了自己第
   一次的密码设置——这份档案不仅命中了和 `tybxjh` 完全相同的这个
   新发现 bug 类别，而且是**活生生的现场证据**：此前提交的
   `data/{login,user}/f/fluffos.o` 存档（"WASM 修复摘要"一节声称
   "登录横幅直接显示确认生效"）打开一看，`dbase` 映射里根本没有
   `"password"`/`"ad_password"` 这两个键——和 `tybxjh` 修复前的现
   场复现结果一模一样，证实这个旧存档从一开始就是坏的，账号从未真
   正能够登录。已应用和 `tybxjh` 完全相同的修法（只在
   `dbase[prop]` 已存在时才触发保护）。删除旧的坏存档，重新走完整
   注册流程，新存档的 `dbase` 映射正确包含两个密码哈希；用刚设置
   的普通密码断线重连，"重新连线完毕"确认真正登录成功。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:146`。
- 未发现 `message()` simul_efun 包装函数。

### 实测过程

登录流程和 `tybxjh` 完全一致（英文 id → y/n 确认 → 中文名字 → 管理
密码+确认 → 普通密码+确认 → 天赋 0 随机+接受 → 邮箱 → 性别）。
`log/debug.log` 里全是 `*Too long evaluation`/`*Can't catch eval
cost too big error`，追查后确认全部发生在全新驱动进程首次预载/注
册触发的冷编译级联期间（AGENTS.md §7.90/§10.8 已归档类别），断线
重连后未再出现，确认已自愈，非持久性 bug。驱动最终按精确 PID
kill，`ps -p` 确认已退出。

### 已清理

- 管理员 `fluffos` 的存档已更新提交（`data/{login,user}/f/
  fluffos.o`，密码：管理密码 `AdminPass123`，普通密码
  `LoginPass456`；旧的、从未真正可用的存档已删除重建）。
- `data/{login,user}/c/ccc.o` 是此前会话遗留的角色存档，本轮某个
  背景守护进程（`closed.lpc` 的 `heart_beat()`）的例行存盘产生了
  纯粹的时间戳类 diff，已用 `git checkout` 撤销，不提交。

## AGENTS.md §7.100 fix (2026-08-19): redundant replace_program(ROOM) landmine

Same corpus-wide bug as the batch-1-6 sweep (`ROOM` macro
`"/inherit/room/room"` from `include/globals.h`). Deleted 2,384 live
standalone `replace_program(ROOM);` lines under `work/` via
`fix_710_room.py`, plus hand-fixed both room-building tool copies'
string-builder template (`work/clone/misc/roommaker.lpc`,
`work/u/tyui/obj/roommaker.lpc`). Checked 98 real `.lpc` files under
`work/data/{area,room,proom,...}` for the known data/-exclusion
false-negative — none had the bug pattern. All remaining
`replace_program(ROOM)` matches after the fix are pre-existing
`//`-commented lines only.

Verified: clean `build-debug` boot (zero new compile errors, zero
"cannot replace"/"cannot bind" in `debug.log`), live admin login
(`fluffos`/`LoginPass456`) into the game world, `look`/`west`/`score`/
`quit` all worked cleanly.

**Extra caution note per this lib's standing player-save-damage
history**: the live login run left several incidental data/ diffs —
routine `heart_beat()` background saves on unrelated player accounts
(`ccc.o`, `cscb.o`, `seven.o`, `area/*.o`), the `fluffos` account
picking up starting equipment from normal gameplay, AND (more
notably) a **deletion** of `data/login/f/fluffos.o` (the credential/
password-hash file) observed after `quit`, even though that same file
was used successfully to log in during this very session. Root cause
not investigated (out of scope for this sweep — not related to the
replace_program fix), but ALL data/ drift including this deletion was
reverted via `git checkout HEAD -- work/data` before committing, so
the credential file and all other player saves are untouched in the
committed diff. Flagging for whoever next touches this lib's `fluffos`
account or investigates login/logout save behavior.

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
