
## WASM 修复摘要（迁移自 meta.json 的 group_note）

金庸题材 mudlib，jhfy2 的手足/后继档案（按路径和 jhfy2 重合 7977/9332 个档案，jhfy3 是一个更大的扩充超集），游戏内标题为"夕阳再现 之「风云再起Ⅱ」"。只有一个 bug：adm/daemons/logind.lpc 的 logon() 里 §1.3e 的 uptime()<30 开机保护闸门，在每一次 WASM 连线时都必然触发（测试环境开机后立刻连线，而且不管等多久现实时间都没用，因为 WASM 的事件后端是由宿主逐笔驱动而非真实系统时钟驱动）——已按 AGENTS.md §1.3e 既定方针对本地回环放行（query_ip_number(ob) != "127.0.0.1" && uptime() < 30）。没有发现中文名字/宏定义/指令表相关的 bug。管理员账号（fluffos，双密码机制）通过真实注册流程 + adm/etc/wizlist（CRLF 格式，和档案里既有条目一致）播种，游戏内"★ 您目前权限：(admin)"显示确认生效。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字——注意这份档案是双密码流程（先设管理密码再设登录密码），和 jhfy2 的单一密码不同。格式化工具发现 5 个真正损坏的档案（d/huashan/map.lpc 和它在 u/fyue/ 下的副本——都是 ASCII 地图，和手足档案里同样的分词器混淆模式；d/player/fyue_room.lpc；d/quanzhen_old/hudi5.lpc，一份和 ffxymud/jhfy2 的 d/city/sj.lpc 类似的、转档之前就存在的缺引号档案；kungfu/skill/jinshe-jian/kuangwu.lpc，一段两行的档头注释被合并、插入了空格）——全部用 git checkout 还原。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 100 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

对照手足档案 `jhfy`（本项目已完成 §10.7 深度测试，参见 `libs/jhfy/NOTES.md`）和 `jhfy2`（其 §8.9/§7.68/§7.34 发现已被 `jhfy` 交叉核对过）逐项复核，并独立验证 `jhfy3` 自己的实际代码（README 已明确指出 `jhfy3` 是在 `jhfy2` 地图基础上换用"夕阳再现"核心系统的扩充超集，不能假设两者代码完全一致）。原生驱动（`~/src/fluffos/build-debug/src/driver`），端口 40143。

### 1. 管理员账号：文档记录与实际存档不符（发现并修复）

`README.md` 此前记录 `fluffos`/`Mud2026Adm`/`Mud2026Log` 账号"已在游戏内确认"，但实际检查 `work/data/{login,user}/f/` 只有 `.donotdelete` 标记文件，**没有 fluffos 的存档**。推断：早前那次播种是在 WASM 阶段的 MEMFS 沙箱里完成的（`wasm_client.js` 的内存文件系统从不写回真实的 `work/data/`），所以 README 记录的"验证"从未落到这份档案的原生存档树上。已通过原生驱动的正常注册流程重新播种（id `fluffos`、中文名"浮浮"、管理密码/登录密码均为文档记录的默认值），`adm/etc/wizlist` 里原本就有 `fluffos (admin)` 一行（早前那次播种时写入的，本身没丢），所以新注册的角色一登入就正确显示"★ 您目前权限：(admin)"；额外用 `update /adm/daemons/logind`（对应本次改动的档案）验证了写入 ACL，回应"重新编译 /adm/daemons/logind.lpc：成功！"，确认管理权限真实可用而不只是等级显示正确。存档：`work/data/login/f/fluffos.o`、`work/data/user/f/fluffos.o`（已提交）。

### 2. §8.9 食物/饮水年龄检查错对象（命中，已修复）

`adm/daemons/logind.lpc` 的 `enter_world()`：
```lpc
user->setup();
if (ob->query("age") == 14) {          // 应为 user->query("age")
  user->set("food", user->max_food_capacity());
  user->set("water", user->max_water_capacity());
}
```
和 `jhfy`/`jhfy2` 的"简版"形状完全一致（没有 `!user->query("food")` 的额外守卫）——`ob` 是登录用的临时对象，`age` 属性从未在它身上被设置过，恒为驱动默认值 `0`，所以这个食物/饮水初始化闸门永远不会触发。和 `jhfy2` 的情况类似：**实测发现这个 bug 目前是"哑的"**——`feature/damage.lpc` 的 `heal_up()` 里有一段独立的兜底逻辑，`age<18`（新角色固定 14 岁）或巫师，食物/饮水任一耗尽时会自动填满到满值并提示"一道金光过后，你又变得神采奕奕！"，所以两次实测注册（沈风策、程延河）`score` 都显示食物/饮水两条满格，从未观察到"你饿得直冒金星"。按 AGENTS.md §8.9 记录的既定原则（"一个条件目前被别的默认值掩盖了，不代表这个错读对象的写法本身是对的"）依然修正为 `user->query("age")`，防止未来这条兜底逻辑被改动后此 bug 突然变得可见。修复后重新注册验证：闸门读取对象已改对，行为不变（因为兜底逻辑仍在），`update /adm/daemons/logind` 编译成功。

### 3. §7.34 printf 调试残留（命中 2 处，已修复）

同一个 `adm/daemons/logind.lpc` 里，中文取名流程的两条分支各有一处裸 `printf("%O\n", ob)`：
- `get_resp()`（玩家对系统随机产生的名字回答"满意"时）第 461 行；
- `get_name()`（玩家直接输入中文名字、通过 `check_legal_name()` 校验后）第 494 行。

两处都会把登录对象的原始物件引用（形如 `/clone/user/login#1`）直接打印给正在注册的玩家看——实测复现：用真实中文名字"沈风策"注册，取名后紧接着就在管理密码提示前多出一行 `/clone/user/login#1`。修复前后各做过一次完整注册验证：修复前这行残留原样出现在协议流里；删除两处 `printf` 调用并重启驱动后，再次完整注册（id `chengyanhe`，中文名"程延河"）确认取名提示和密码提示之间不再插入任何物件引用，`update /adm/daemons/logind` 编译成功。

### 4. §7.68 死亡软锁形状：观察到但未重新应用（遵循撤销指引）

`d/death/npc/{wgargoyle,bgargoyle}.lpc`（白无常/黑无常）的 `death_stage()` 都有
`if (!ob || !present(ob)) return;` 这个把"角色永久离开"和"暂时不在场"混在一起的经典 §7.68 形状——和 `jhfy`/`jhfy2` 一模一样（这三份档案共享同一套死亡系统代码）。按任务交代和 AGENTS.md §7.68 顶部的撤销说明，**没有重新应用"5 秒后重试"的修复**，只做现场观察：实测一次完整、无干扰的死亡→复活循环（详见下方"死亡/复活"一节），全程没有任何外部系统强行移动过处于鬼魂状态的角色，`present(ob)` 判定从未因为"暂时不在场"而被触发，五阶段对白顺利走完，`ob->reincarnate()` 正常调用，正确落地 `REVIVE_ROOM`（"武庙"，和 `include/login.h` 的宏定义一致）。没有发现任何强制移动鬼魂的第二套系统（比如 `jyqxc`/`syxjl` 里那种巡场 NPC），所以本次会话里**两个必要前提都没有被验证为真实存在**——按撤销说明的原则，维持原始的单次判定写法不变，仅记录观察结果。

### 5. §7.86 留言板修复：确认仍然有效（回归测试通过）

早前一轮 WASM 阶段的跨库扫描已经删除了全档案约 100 处多余的 `replace_program(BULLETIN_BOARD)`（3 处已注释掉的实例原样保留，无害）。本次在"武庙"复活房间实测 `post test2`：正常打开内建行编辑器，`.` 结束后提示"留言完毕"，`look board` 显示新留言正确出现在列表第 10 条（用户 `shenfengce`，标题 `test2`）。确认修复在真实游玩场景下持续有效。

### 6. 新发现：`replace_program()` 同一致命形状普遍存在于 `ROOM` 基类，不只是留言板（AGENTS.md 新增 §7.100，仅部分修复）

在死亡/复活流程之后的日常游玩中，`debug.log` 出现一行此前从未见过的警告：
```
d/city/xxci1.lpc: cannot replace a program with function references, ignored.
```
读源码发现 `d/city/xxci1.lpc`（先贤祠－玩家部）和几乎全档案的房间文件一样：`inherit ROOM;` 之后，`create()` 的最后又调用了一次完全多余的 `replace_program(ROOM);`——和 §7.86 记录的留言板致命形状一模一样，只是这次的基类是 `ROOM`（`/inherit/room/room`）而不是 `BULLETIN_BOARD`。用 `grep -c "replace_program(ROOM)"` 扫了全档案：**5,717 处命中，其中 124 处已被注释掉，5,591 处是活跃的独立语句**——占这份约 9,300 个档案的档案库的六成左右。这个房间之所以只产生"ignored"警告而没有像留言板那样直接崩溃，是因为它的 `create()` 在调用 `replace_program(ROOM)` 之前先调用了 `create_door(...)`，而 `create_door()` 内部会 `set("item_desc/" + dir, (: look_door, dir :));`——先绑定了一个指向自身 lfun 的闭包，驱动侦测到"已经有闭包引用"就直接拒绝执行这次 replace，安全地放弃。**这只是侥幸**：绝大多数没有调用 `create_door()`（即没有门）的房间，`replace_program(ROOM)` 会静默执行成功，永久设下和留言板一样的"replace 挂起"标记，直到这个房间对象生命周期里任何一次绑定自身闭包的操作（比如在 `create()` 之外再 `set("item_desc/...", (: ... :))`、`edit()`、`call_out()` 绑定闭包参数等）才会触发和留言板一样的致命错误。

进一步发现：本档案自带的房间建造工具 `clone/misc/roommaker.lpc`（和它在 `u/fyue/misc/` 下的完全同副本）自己生成的房间源码模板里，**也**内建了这个 bug——"造一个空房间"用的 heredoc 模板、"复制当前房间"用的字符串拼接模板，两处都写死了 `replace_program(ROOM);`，意味着任何玩家或巫师用这个工具造出的新房间从出生起就带着这颗地雷。

**处理范围**：这个 bug 的修复本身极其简单（删掉多余的 `replace_program()` 调用即可，`inherit` 已经提供了全部功能），和 §7.86 已经在 6 个互不相关血统上验证过的修复完全同一形状。但对全部 5,591 处做一次性批量脚本改写，被本次会话自身的执行安全机制拦下（判定为"过于宽泛的自动化批量改写"，符合本项目一贯"不要从宽泛扫描结果直接派生批量操作"的原则，这次是同样原则用在批量*编辑*而不是批量*删除*上）。本次实际修复：1 个有现场实测证据的档案（`d/city/xxci1.lpc`）、造房工具的两份完全同副本（各自的两处生成模板都已修正，堵住"工厂"持续生产带 bug 新房间的源头）、外加 3 个抽样验证同一写法可正常修复的档案（`d/mingjiao/maowu.lpc`、`d/quanzhou/nanhu.lpc`、`d/xiangyang/qianzhuang.lpc`）——共 6 个档案，全部用 `update <path>` 验证重新编译成功；`xxci1.lpc` 的"ignored"警告在修复并重启驱动后确认消失。**剩余约 5,585 个房间档案仍未修复**，已在 AGENTS.md §7.100 记录为已识别但因规模过大本轮未能处理完的已知缺陷，留给未来专门一轮分批扫描（详见该条目）。

### 7. 移动/战斗/死亡/复活：完整实测

用真实中文名字"沈风策"（id `shenfengce`）注册，随机落地"北疆小镇"（xingxiu 分支之一）。`kill woman` 攻击当地维吾尔族妇女 NPC（非训练木人，普通友善 NPC，具备反击能力），战斗自动进行约 30 回合后角色不敌落败，正常触发"你扑在地上挣扎了几下……死了！"，全场公告死讯，自动传送至"鬼门关"，NPC"白无常"依次讲述五阶段对白（约 25 秒），无任何干扰，最终 `reincarnate()` 正常调用，正确落地 `REVIVE_ROOM`（"武庙"）。复活后 `score` 确认角色状态从【鬼魂】恢复为可行动状态（精/气各恢复到约 30%，符合"大难不死但元气未复"的正常复活语义），`debug.log` 全程干净。

### 8. 未测试部分

时间关系，没有测试拜师、购物、寄信（mail）系统。

### 9. 其它已排查、确认不适用的 bug 类别

逐项核对 AGENTS.md 当前收录的其它高频 bug 类别，均未在 `jhfy3` 复现：
- **§7.5 / 自定义 securd.lpc valid_read() ACL**：`securityd.lpc` 是自定义 ACL（`trusted_read`/`exclude_read`/`trusted_write`/`exclude_write` 按目录+权限等级配置），但整个游玩会话（含 `update` 写入测试）`debug.log` 未出现任何 `Read/Write access denied`。
- **§7.90 eval-cost 过低**：`maximum evaluation cost : 700000`（和同属"夕阳再现"家族但需要调到 5000000 的 `xajh4gkb` 不同）——实测多次跨房间冷编译（含死亡→复活途中的鬼门关、武庙等新房间）均未触发"bug found, report it"通用报错，未发现需要调高的证据。
- **§7.98 daemon create() 缺 seteuid()**：`securityd.lpc` 的 `create()` 直接 `read_file(WIZLIST)` 且没有任何 `seteuid()` 调用，但整个会话（包括 fluffos 权限判定、`update` 写入）均正常工作，未观察到因权限问题导致的崩溃或错误——不适用此形状。
- **§8.13 wizlist 二次登录死锁**：`get_passwd()` 里有专门分支处理"未设定管理密码"的情况（`if (!ob->query("wizpwd")) { ...; input_to("reset_wizpwd", ...); }`），有明确的成功路径，不是死锁形状。
- **§8.14 IP 封禁误用逆向 DNS**：`query_ip_name()` 只在连线播报的装饰性文字里使用，封禁判定逻辑（`band.lpc`）用的始终是 `query_ip_number()`，不适用。
- **§8.15 大小写不匹配的档案名运行期崩溃**：留言板目录 `d/board/` 下抽查未发现大小写相关的运行期崩溃证据；本轮实测未触发。
- **§7.11 log_file()/write_file() 缺 assure_file()**：注册流程会写入 `log/login/newid.log`，该目录本身已存在于档案库中，注册测试全程未见任何写入失败。
- **§8.3 指令表 bug**：`kill`/`look`/`score`/`post`/`update`/`quit` 等核心指令全部实测正常，未见任何指令表相关异常。

## 第四轮补测（§10.7 round four，2026-08-19）：拜师、购物、寄信

补测第一轮明确留下未测的三个系统：拜师（sect/guild apprenticeship）、购物（shopping）、寄信（mail）。原生驱动，端口 40143，用真实注册账号 `shenqingyang`（中文名"沈清扬"，悟性 30）+ 已有管理员账号 `fluffos` 双连线（`goto`/`summon`/`clone`/`give`/`call` 配合）实测。**三个系统全部正常工作，没有发现任何真正的 bug**（无编译错误、无 debug.log 崩溃、无卡死状态）。

### 1. 拜师（`cmds/skill/apprentice.lpc` + `feature/apprentice.lpc`）：正常

用 `bai huchong`（华山派"大师兄"令狐冲，`/d/heimuya/npc/linghu.lpc`，被 `/d/huashan/sgyhole1.lpc` 引用克隆）实测：角色悟性 30 ≥ 门槛 25、负神 0 ≥ 门槛 0，`attempt_apprentice()` 一次通过，NPC 自动 `command("recruit ...")`，`score` 确认"华山派第十五代弟子"、"你的师父是令狐冲"。机制（`is_apprentice_of`/`recruit_apprentice`/`create_family`）运作正常，是一次干净的通过。（第一次尝试用了错误的 NPC id "linghu"——`set_name` 实际登记的 id 是 `({"ling huchong","ling","huchong"})`，没有"linghu"——属于测试方法问题，不是 mudlib bug。）

### 2. 购物（`feature/dealer.lpc` / `F_DEALER`）：正常

在 `/d/xiangyang/jiekou1`（大街口）的小贩 NPC 处，给角色银子后 `buy egg`（五香茶叶蛋）成功购得，`i` 确认物品与找零都正确到账。`list`/`buy` 命令、`can_afford`/`pay_money` 结算链路均正常。

（诊断过程中发现 `feature/finance.lpc` 的 `can_afford()`/`pay_money()` 使用 `this_player()` 而不是（注释所声称的）`this_object()`——用管理员的 `call` 指令跨物件直接调用 `pay_money()` 给测试角色打钱时，钱进了管理员自己的背包而不是目标角色的，因为 `this_player()` 此时是发指令的管理员。**这不是真实 bug**：正常游戏流程里 `do_buy()` 内部是 `dest = this_player()` 然后 `dest->can_afford(...)`，`this_player()` 全程就是发起 `buy` 指令的玩家自己，`call_other()` 不会改变 `this_player()`，链路是自洽的；只有像管理员 `call obj->pay_money()` 这种跳出正常指令上下文的诊断手段才会踩到这个上下文错位。已改用 `clone`+`give` 的正常游戏内流程绕过，不建议改动 `finance.lpc`。)

### 3. 当铺/收购（买卖提 `d/xingxiu/npc/maimaiti.lpc` 卖哈密瓜 → 波斯生意人 `d/gaochang/npc/dealer.lpc` 收购哈密瓜）：正常，round-trip 验证

`buy hamigua`（跟买卖提买）→ `sell hamigua`（卖给波斯生意人"收购店"）全部成功，银两正确增减。这个项目一贯的"多数商人只卖不收，只有当铺/收购类 NPC 才收购"设计（已在 hell/niaoren/ylfyxa3/xyzx3 独立确认）在这里同样成立：`d/gaochang/npc/dealer.lpc`（波斯生意人）只注册了 `add_action("do_sell","sell")`，没有注册 `buy`/`list`——这是有意为之的"收购店"（sign 原文"专门收购当地物产"），不是缺陷；同理 `inherit/room/hockshop.lpc`（当票/pawn 房间 mixin）扫描全档案 0 处房间实际 `inherit` 它，看起来是未使用的死代码，但没有任何编译错误或运行期错误，判定为未完成/未接入的内容而非 bug，未做改动。

（诊断中还确认了这份档案里"NPC 后到达房间"不会自动给房间里已存在的玩家绑定该 NPC 的指令——`买卖提` 是在测试角色已经站在房间里之后才用 `clone` 补进去的，此时角色执行 `buy hamigua` 报"你想买什么？"，因为 `add_action` 只绑定给了触发 `clone` 动作的 `this_player()`（管理员），不是旁观的角色；让角色重新"进入"房间一次（再 `summon` 一次）后立刻可以正常 `buy`。这是标准 LPC driver 语义，不是本档案的 bug，纯粹是本轮测试方法上的一个坑，记录下来供未来测试参考。）

### 4. 寄信（`d/city/npc/post_officer.lpc` + `clone/misc/mailbox.lpc`）：正常

`ask officer about 寄信` 领取信箱 → `mail shenqingyang`（寄给自己）→ 标题/内容（内建行编辑器 `.` 结束）→ 备份询问 `n` → 系统提示"有您的信！"。`from` 正确列出信件，`read 1` 正确显示标题/寄信人/内容。整条链路（`post_officer.lpc` 的 `send_mail()`/`receive_mail()` 依赖的 `query("startroom")`，由 `inherit/room/room.lpc` 的 `setup()` 在克隆时自动写入）完整可用，不是 `zjdy2008wzb`/`zjdywzb`/`hell` 那种被禁用的 stub。

### 5. 标准积压清单快速核对（§7.90、§7.111、§7.112、§7.113、§7.114、§7.115）：均无异常

- **§7.90**（eval-cost 过低）：`config.fluffos` 已是 `maximum evaluation cost : 5000000`（上一轮记录还是 700000，现已被 §7.90 语料级扫描修复覆盖），本轮多次跨房间冷编译（含新克隆的 `maimaiti`）未见任何 eval-cost 报错。
- **§7.111**（`standard_trace()` 对 `error["object"]==0` 的 `file_name()` 崩溃）：`adm/obj/master.lpc` 第 206 行已是 `objectp(error["object"]) ? file_name(error["object"]) : "<none>"` 的守卫写法，修复已在。
- **§7.112**（NPC `init()` 无守卫重复挂 `call_out`）：抽查多个 `d/baituo/npc/*.lpc` 等文件的 `init()`，全部是 `remove_call_out(...)` 紧跟 `call_out(...)` 的守卫写法，修复已在。
- **§7.113**（netdead 重连不恢复 `heart_beat`）：`clone/user/user.lpc` 第 196 行 `reconnect()` 明确包含 `set_heart_beat(1)`，修复已在。
- **§7.114**（mixin 里的 `private input_to` 回调失效）：`feature/edit.lpc` 的 `edit()` 是 `public`（非 `private`），本轮寄信、上一轮留言板都验证过内建行编辑器（`.` 结束）正常工作，不适用。
- **§7.115**（`QUEST` 宏指向缺失文件）：`include/globals.h` 的 `#define QUEST "/inherit/quest"` 对应的 `inherit/quest.lpc` 确实存在且内容完整（`quest_give`/`quest_ask`/`quest_kill`），不适用（本档案不是 aoxiangtianji 那种孤立个案）。

**结论：本档案没有发现新 bug，第四轮补测的三个系统（拜师/购物/寄信）全部工作正常，标准积压清单六项复核全部通过。** 测试用账号 `shenqingyang` 的存档在测试结束后已删除，不留痕迹；`fluffos` 管理员账号的存档因正常使用（`last_on` 等字段）产生了预期内的小改动。
