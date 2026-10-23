
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

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- `message_combatd(msg, me, you)` is called by 3 file(s) (the perform files) and defined nowhere in this archive (a simul_efun of the original server): 1 of them did not compile (`Undefined function message_combatd`). `adm/simul_efun/message.lpc` now has `varargs void message_combatd(string msg, object me, object you, mixed extra)` calling `message_vision()`, placed after `message_vision`'s definition (KB 04 §6.2). All callers compile.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 5 here-document block(s) repaired (5 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/heimuya/shenggu.lpc`, `d/heimuya/tang.lpc`, `d/heimuya/npc/tang.lpc`, `d/quanzhen_old/manglin1.lpc`, `d/quanzhen_old/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply jhfy3`: 1 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 2 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 0 PASS -> 2 PASS, 0 that loaded before fail now, 2 more load.

1 files moved (1 `.C`); mostly under `d/city/npc` (1). A rescan with `scripts/lpc_warnings.py jhfy3` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/app/tail.lpc`, `cmds/wiz/tail.lpc` call `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 2 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 86 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`u/fyue/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 1 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成；`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：`adm/daemons/questd.lpc`、`u/fyue/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 3 个），无回退；`u/fyue/questd.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。
验证：改动过的 `adm/daemons/questd.lpc`、`cmds/std/look.lpc`、`u/fyue/questd.lpc` 在新进程里加载，HEAD 通过 2 个、工作树通过 2 个（共 3 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py jhfy3 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 531 个 `.lpc` 和 4 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：475 -> 475 通过，无回退；改过的头文件的 39 个包含者 39 -> 39 通过。启动时警告 8 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 4 处比较、1 处去后缀（如 `cmds/imm/ls.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：`/u/snow/wudujiao/mishi.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 29 处，返回类型/原型 36 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 2 个文件；改动 63 个文件，HEAD 与工作树各载入一次无回退（63 objects; HEAD PASS 53, tree PASS 53; regress 0; newly loading 0），这些文件的警告 67 -> 0。

## 编译警告收尾（2026-10-12）

孪生库 bixiecanyang 同日的整理（7c2dd97d9a6：冗余继承 8 处，`u/isle/ToMud/tomud.h` 沙盒副本的 `TMI`/`TMA`/`TMB` 前 `#undef`，`kungfu/skill/huashan-jian.lpc` 多余的 `;`）用 `scripts/lpc_twin_port.py adopt bixiecanyang jhfy3 --pre 7c2dd97d9a6~1` 搬来，10 个文件与 bixiecanyang 修前逐 token 相同，清单里的警告全部落在这些文件里。HEAD 与工作树各载入一次：10 个对象，HEAD PASS 7，tree PASS 7，regress 0。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。13 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。9 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 8 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 6 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，1 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。


## `message_vision(msg, environment(me), me)`（2026-10-15，KB 06 §7.242）

把房间当成了动作者：`message_vision()` 取房间的 `name()` 得 0，`replace_string(msg, "$N", 0)` 报错。在状态（中毒）里，这个错误发生在 `apply_condition(name, duration - 1)` 之前，状态永不结束，心跳里后面的恢复也每次被跳过。改为 `message_vision(msg, me)`：`/kungfu/condition/sanpoison`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。4 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## iceforce「chillgaze」从未编译通过（2026-10-15）

`iceforce/chillgaze` 原档在第一个 `return notify_fail(...)` 后多了一个 `}`，`exert()` 就此结束，后面的语句全落在函数外，`skill`、`damage` 也没有声明，文件编译失败，这个 exert 从来用不了。照 bixiecanyang、hc、xyzx3 已修好的版本删去多余的 `}`、补上 `int skill, damage;`，其余字句不变，只是缩进进函数体。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`beimin-shengong`→`beiming-shengong`（`/d/quanzhen_old/kungfu/skill/xiantian-qigong`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 文件首行注释少了一个斜杠（2026-10-15）

首行的说明注释只剩一个 `/`（如 `/kuangwu.c金蛇狂舞`、`/ cloth.txt  //`），文件第一行就语法错误、编译失败：金蛇剑的绝招「金蛇狂舞」`/kungfu/skill/jinshe-jian/kuangwu`因此从来用不了；全真教的布衣 `/d/quanzhen_old/obj/cloth` 因此从来载入不了。补回斜杠成为 `//` 注释，现在都能载入。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）；`xuantie-jiafa`→`xuantie-jianfa`（`xuantie-jianfa`）；`xuanxie-jianfa`→`xuantie-jianfa`（`xuantie-jianfa`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。8 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunv-jian/suxin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`clone/gift/npc/bingqipu.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

5 个文件、10 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/obj/cloth/cloth`、`/obj/weapon/blade`、`/d/gumu/obj/fuchen`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 4 个（4 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory2.lpc`、`feature/move.lpc`、`feature/move2.lpc`、`feature/复件 move.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：2 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 全真心法 `valid_learn()` 里没声明的 `lvl`（2026-10-18）

`kungfu/skill/quanzhen-xinfa.lpc` 的 `valid_learn()` 判断 `me->query("gender") == "无性" && lvl > 49`，可是函数里只有 `nk`、`nf`、`nh`、`ns` 四个变量，没有 `lvl`：`Undefined variable 'lvl'`，这门心法的文件载入不了，学它、用它都失败。`nh` 正是全真心法的等级（`nh = query_skill("quanzhen-xinfa", 1)`），改成 `nh > 49`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/meng-zhu.lpc`、`clone/npc/shang-shan.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang2.lpc`、`d/taishan/tang3.lpc`、`d/taishan/xingtang.lpc`。改后用 `lpcc` 逐个载入这些对象：7 个通过。

## `kungfu/skill/qingyi-jian` 第一式的 `skill_name` 丢了收尾引号（2026-10-18，KB 03 §4.6）

`"skill_name" : "大悲式,` 的收尾引号没了（转码时跟半个汉字一起丢了），字符串连到下一行，`damage_type` 成了代码：`Illegal character 0xe5`，整个武功载入不了。补回 `",`（同系的 bixiecanyang、syxjl 等库里有完好的同名文件）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 6 个对象设了本库没有文件的武功（9 个名字，最多的是 `hunyuan-force`、`ruyi-blade`、`taxue-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：6 个里 6 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 27 处、25 个文件：`kunlun-shnfa`→`kunlun-shenfa`（4 处）、`yan-fly`→`yanfly`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`shaolin-shnfa`→`shaolin-shenfa`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）等共 16 个名字。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 2 处、1 个文件：`::init()`（1 处）、`::do_eat()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 同一个函数原样贴了两遍（2026-10-19，KB 06 §7.264）

同一个文件里同一个函数被原样贴了两遍（除空白外逐字相同），驱动报 `Redeclaration of function`，整个物件载入不了。删掉第二份及以后的副本，共 2 处：`/clone/book/lbook5.lpc` 的 `query_autoload()`、`/clone/book/pixie_book.lpc` 的 `query_autoload()`。（`scripts/lpc_fix_dup_functions.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 删掉 exert_function(整数)（2026-10-19，KB 06 §7.266）

`/d/player/ltsh/npc/saveme.lpc` `create()` 里的 `exert_function(10);` 把整数传给了要字符串的直接调用（让 NPC 闲聊时自己运功），驱动报 `Bad type for argument 1 of exert_function ( string vs int )`，整个 NPC 载入不了。这是存档里的笔误，不知道作者想传哪个字符串，删掉这一句（只影响闲聊时的运功表现）。chidi 的同一个 NPC 早先就是这样处理的。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/board/mingjiao_b.lpc` 的 `location` 从不存在的 `/d/mj/guangming-ding` 改成 `/d/mingjiao/guangming-ding`（载入明教留言板失败会让光明顶房间载入不了）
- 5 个 NPC 文件、5 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 5 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/quanzhen_old/obj/allow-letter.lpc`、`/d/quanzhen_old/obj/greenrobe.lpc`、`/d/quanzhen_old/obj/greyrobe.lpc`、`/d/quanzhen_old/obj/hanzhu.lpc`、`/d/quanzhen_old/obj/shenmu.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`（共 2 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：2 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_bian.lpc`、`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`、`/d/quanzhen_old/npc/obj/m_sword.lpc`（共 6 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 3 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/kungfu/skill/huang.lpc`（bixiecanyang）、`/quest/murong/qlist3.lpc`（bixiecanyang）。一行文字在逗号前丢了结尾的引号（下一行是同一个表的下一项），补上：`/kungfu/skill/kunlun-zhang.lpc`。修后与 HEAD 逐个对比载入：这 3 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 玩家买店用的 `feature/vendor_sale.lpc` 补回（2026-10-19，KB 03 §4.6 第四轮）

`/feature/vendor_sale.lpc`（`/kungfu/class/npc/xiaoer.lpc` 继承它）从 `pay_back` 起约 160 行的行尾丢了最后一个字符（`;` `)` `{` `}`，`else {` 只剩 `els`，`msg` 只剩 `ms`），另有一行 `if(wizardp(who) || getuid(who)==owner_id)` 被拼进了前面的 `log_file(` 调用里。文件载入失败，继承它的物件也跟着失败。别的库（ldtx、ldtxii、xhcii、syxjl、hy3）里有这个文件的完好副本，但那是另一个版本：没有作者后来加的投标公告（`string mesg;` 和 `message("channel:chat", ...)`）。所以按完好副本补回丢失的字符（`scripts/lpc_restore_from_twin.py --diff --extra`），公告两段原样保留；被拼到别处的 `if(...)` 放回完好副本里它所在的 `write("\n盈利` 之前；`message_vision("channel:chat", ...)` 多出来的第一个参数删掉（`message_vision` 的签名是 `(string, object, object)`，每次 `bid` 在扣完款之后都会报错）。补完后文件和继承它的物件都能载入，没有警告，也没有退步（HEAD 上两个都载入失败）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/d/changan/ca2.lpc`（1 处）。

## 行编辑器指令编译失败：`(: this_object(), ({ "do_to", me, arg }) :)`（2026-10-20，KB 06 §7.284）

`Illegal to use local variable in functional.`：call_other 形式的函数指针 `(: ob, ({ "函数", 参数 }) :)` 的数组里只能是常量，写了局部变量 `me` / `arg` 整个指令就编译不过，`to` 这类先开编辑器、再回调自己的指令因此从未能用。改成 `(: call_other, this_object(), "do_to", me, arg :)`（参数在建立指针时绑定，编辑器再把输入的文字接在最后，`do_to(me, arg, text)` 收到全文；`scripts/lpc_fix_functional_locals.py`）。改动：`/cmds/wiz/to.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/migong/obj/npc1.lpc`、`/inherit/char/npc.lpc`（共 2 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（3 个文件）：`/cmds/adm/recover1.lpc`、`/cmds/arch/blockade.lpc`、`/cmds/arch/recover1.lpc`。

## `obj.h.es2`：`blockade` / `recover` 包含的头文件档案里没有（2026-10-21，KB 04 §6.23）

`blockade.lpc`、`recover*.lpc` `#include <obj.h.es2>`（`OBJ_*`、`NPC_*` 路径的 ES2 头文件，hy5、xkx100 等 33 个库带着），本库的 include 目录没有它，这些指令从来编译不了（`Cannot #include obj.h.es2`），`data/keep` 的修补也无从生效。指令本身不用里面的宏；从同系的 xkx100 复制一份头文件，加载检查 HEAD 与工作树对照：3 个对象原来加载失败，现在通过，没有退步。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/actionavailable.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## `socket`：`dump_socket_status()` 在本库没有（2026-10-21，KB 06 §7.291）

管理员扫描里 `socket` 指令（`/cmds/bos/socket.lpc`）编译不了：`write(dump_socket_status());` 用的是 MudOS 有、本驱动没有的 efun。2026-10-20 的补丁只按名字找了巫师目录里的同名指令，这一条在 `cmds/bos`、`cmds/hufa`、`cmds/island`、`cmds/ser` 这类目录里；用 `scripts/lpc_add_sefun.py dump_socket_status` 在 `/adm/obj/simul_efun.lpc` 末尾补了一个由 `socket_status()` 构造表格的 simul_efun（没有 sockets 包的构建，比如 WASM，只打印表头）。指令 HEAD 编译失败，现在通过。

## 睡袋：`/cmds/adm/bag` 本库没有，使用者被留在聋哑状态（2026-10-21，KB 06 §7.344）

`clone/misc/sleepbag.lpc`、`sleepbag2.lpc` 的 `do_sleep()` 在设好 `block_msg/all`、`no_get` 和房间的 `sleeping_person` 之后调用 `"/cmds/adm/bag"->main(me, "<休息中>")`。这条巫师指令只有 hc、tianxiawuxue 带着，本库没有：`call_other() couldn't find object '/cmds/adm/bag'`，玩家之后什么消息也收不到（`look` 一片空白），十秒后的 `wakeup` call_out 没有排上，房间一直 `no_fight`。城里的小贩 `xiaofan` 卖这个睡袋，没有人在扫描里买过它。`bag` 的全部内容就是 `me->disable_player(msg)`（`feature/command.lpc` 里的 `nomask void disable_player(string type)`，没有权限检查），两个文件都改成直接 `me->disable_player("<休息中>");`。chidi 上实测：`sleep` 之后十秒 "你一觉醒来，只觉精力充沛"，`look` 正常（HEAD 上玩家被留在空白屏里，`log/debug.log` 有 trace）。改动：`/clone/misc/sleepbag.lpc`、`/clone/misc/sleepbag2.lpc`。

## 香烟 `smoke.lpc`：`do_smoking()` 读没赋值的 `me`（2026-10-21，KB 06 §7.348）

`smoke` 指令的第一句是 `jing = me->query("jing")`，`me` 声明了没赋值，每次抽烟都抛 `Bad argument 1 to call_other()`。补 `me = this_player();`（后面的 `this_player()` 调用不变）。改动：`/d/emei/user-room/melodies/smoke.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 32 条注册（32 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/qinhuang/shidao5.lpc`（`do_train`）、`/d/city/chatroom2.lpc`（`do_jump`）、`/d/city/npc/wei.lpc`（`do_sell`）、`/d/city2/qishi.lpc`（`do_pass`）、`/d/city3/npc/sister.lpc`（`do_vendor_list`）、`/d/flypproom/npc/flypp.lpc`（`do_sell`）、`/d/npc/m_weapon/npc/jia.lpc`（`do_levelup`）、`/d/player/yysz/hupan.lpc`（`do_han`）、`/d/quanzhen/npc/haodatong.lpc`（`do_decide`）、`/d/quanzhen/npc/mayu.lpc`（`do_decide`） 等共 32 个文件。最多的函数名：`do_send` 15 处、`do_decide` 7 处、`do_train` 2 处、`do_sell` 2 处、`do_jump` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。2 个文件里 2 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（2 处调用）；`/adm/daemons/natured.lpc` ← aoxiangtianji：`room_event_fun()`（9 处调用）；`/adm/daemons/natured.lpc` ← chidi：`outdoor_room_outcolor()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/yihua/lianhuachi.lpc`:`look_CAI`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"CAI": (: look_CAI :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 写死的 `"/路径"->函数()` 指向库里没有的文件：改成现存的同名文件（2026-10-22，KB 06 §7.359）

1 处语句级的 `call_other` 字面量路径，库里没有这个文件（区域改了名 / 大小写不对 / 差一个字母 / 文件挪了地方）：`"/d/mj/obj/baihong-jian"->move()`（`/d/mingjiao/npc/yingwang.lpc`）→ `"/d/mingjiao/obj/baihong-jian"`。`call_other()` 对不存在的对象抛 `couldn't find object`，所在函数当场中断。改成库里现存、并且定义了被调用函数的文件（`scripts/lpc_fix_call_path.py`；巫师目录、备份目录、名字不同的兄弟文件都不算候选）。 其中殷天正（白眉鹰王）的 `do_answer()`：玩家念对暗语（`answer 怜我世人，忧患实多；保护教主，同抗外敌`）时把白虹剑 `move` 给玩家，区域目录改名 `mingjiao` 之后这个路径没跟着改，回答暗语只得到 `couldn't find object`，剑永远发不出来。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 19 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 19 处（14 个文件）：拼名字的赋值 11 处、与汉字常量比较 8 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/jingxin.lpc:101`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/qing-fa.lpc:100`）；`name[0..1] == "慧"` → `name[0..0] == "慧"`（`/kungfu/class/shaolin/cheng.h:108`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：12 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 12 处（6 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 10)) {`（`/adm/daemons/logind.lpc:896`）；`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/cmds/bakcmds/csc.lpc:611`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 5 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 6 处（3 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## Beyond 出口仍指向 /u/beyond（2026-10-23，KB 06 §7.368）

宁波 / 苏州 / 慕容等区域已进 `/d/ningbo`、`/d/suzhou`、`/d/mr`、`/d/hz`，出口与任务物路径仍写 `/u/beyond/…`。`scripts/lpc_fix_beyond_exits.py` 在目标 `.lpc` 存在时改写（`murong`→`mr`）。本库 1 处。证明：sjplii `xikou` HEAD 西向 `/u/beyond/ningbo/aywsi`，改后 `/d/ningbo/aywsi` 可加载；bxsj `hubian1` 三向均可加载。


## 死巫师出口 gold/dock、sunrise、mei（2026-10-23，KB 06 §7.370）

`/d/wanjiegu/road4` 东向 `/u/g/gold/dock`、峨眉寿星居南向 `/u/xinyue/sunrise_room`、玩家卧室通往 `/u/mei/…` 均无对应房间。`scripts/lpc_fix_drop_dead_u_exits.py` 删除这些出口行，并去掉同方向的 `create_door`（否则 `create_door` 无出口会炸）。本库 4 处。证明：zxty08nxgbb 的 road4 HEAD 有东向，改后没有；mei_room1 可加载。


## 巫师区出口 faceoff / rence / niulang / yihua（2026-10-23，KB 06 §7.372）

`/u/f/faceoff/`、`/u/r/rence/`、`/u/onskyer/niulang/`、`/u/skinys/yihua/` 对应区域已在 `/open/world1/faceoff/bird/`、`/open/prayer/`、`/d/niulang/`、`/d/yihua/`。`scripts/lpc_fix_wizard_area_exits.py` 在目标存在时改写，仍缺失的出口行删除。本库 1 处。证明：dreamofseven wood5 四向可加载；xlqy_new2007 天河东西向 niulang；kxkj kitchen7 → prayer。

