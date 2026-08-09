
## WASM 修复摘要（迁移自 meta.json 的 group_note）

神话世界·西游记 4.50 版，游戏内品牌《欢乐园》("A Journey to the West")，西安交大 BBS 附属 MUD。WASM 修复：（1）熟悉的 convertd.lpc 字节级损坏（45 行，和 sjsh 家族里见过的相同 0xce/0xb2/0xee/0x96/0xa3 非法字符签名，第 250 行附近）——用标准的字节级 Python 脚本修复。（2）adm/daemons/logind.lpc 的 banned_name 数组字面量里一个真正的语法错误：一行开头多了一个逗号（',"欢乐园",...'紧跟在上一行结尾的逗号后面），产生了一个不合法的空数组元素，连锁引发文件后面 5 个额外的解析错误（包括后面的"Undefined variable mud_list"，因为解析器再也没能恢复正常）——已去掉这个多余的逗号。（3）adm/simul_efun/chinese.lpc 和 adm/daemons/logind.lpc 里 §8.1 类的 is_chinese()/check_legal_name() GBK 字节配对 bug：两处都假设每个中文字占 2 字节 GBK 编码（strlen%2 奇偶门槛，对照一个魔术参考字符串做原始字节区间检查），在这个驱动按码点索引的情况下会拒绝合法的奇数字数 UTF8 中文名字——已把两处都改成逐码点的 0x4e00-0x9fff 区间检查，并把 check_legal_name 的长度界限从字节数（2-12）改成字符数（1-6）。另外记录（不是 bug）：logind.lpc 的 encoding() 里有一个开机后 180 秒的连线闸门——CONTROL_CENTER->query('MUD_SRART_TIME')（原文如此，原始源码里的拼写错误）会在驱动启动后的 3 分钟内拒绝所有登录，除非发送的第一行是字面的绕过短语'let me join ok'；这是有意的防灌水/开机稳定设计，不是缺陷。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（原档案完全是空的；wiz_levels 顶层是 (admin)，SECURITY_D 正确指向 /adm/daemons/securityd，没有诱饵副本）。注册流程在一次连续的 WASM 客户端会话里完整验证过：'let me join ok' 绕过→英文 id→y/n 创建确认→中文名字→单一密码+确认（不是双密码机制）→性别→电子邮件（可选，留空也行）→天赋重掷循环（y 接受）→带着完整角色属性表进入游戏世界，全程没有任何意外错误。管理员权限已直接通过 wizlist 指令输出"目前权限：(admin)"确认。LPC 格式化工具对全部 7338 个档案运行（写入 7272 个，3 个报错，63 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。两个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程（包括'let me join ok'绕过）重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 44 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-09）

**血统确认**：`adm/obj/master.lpc` 的档头注释（"for ES II mudlib / original
from Lil / rewritten by Annihilator (11/07/94)"）与 AGENTS.md §11 的
ES II / 东方故事巨型家族（尤其是 `kxkj`/`kxkj1`/`kxkjii2` 一支）完全一致，
`cmds/std/go.lpc` 的移动派发逻辑也是同一形状（先查房间自己的
`exits` 映射键是否存在，存在才会调用 `valid_leave()`）——因此在深挖前
先按 §7.101（`kxkjii2` 发现的死亡出口 bug）和 §7.12（该家族常见的
`message()` 参数 bug）专门核对过这两类，见下文。此前的 WASM 阶段已经
按 §8.1 修复过 `is_chinese()`/`check_legal_name()` 的 GBK 字节配对问题、
按 §7.86 修复过全部 44 处留言板 `replace_program()` 崩溃——本轮复测两者
均确认线上正常，未回归。

**本轮修复的 bug**：

1. **§7.90 变体：`maximum evaluation cost` 默认值 700000 在 PRELOAD 阶段
   就直接把驱动"防不住"（`*Can't catch eval cost too big error.`）**：
   `config.fluffos` 沿用了本项目最常见的 700000 默认值，但 `adm/obj/
   master.lpc` 的 `preload("/d/wiz/qiushi")`——囚室房间，`create()` 里
   通过 `setup()` 生成 NPC `d/wiz/npc/yuzu.lpc`——连续 3 次触发
   `Eval interrupted: ... cost limit reached, limit: 700000 usec.`
   重试后，第 4 次直接变成不可 `catch()` 的 `*Can't catch eval cost too
   big error.`，在**驱动刚启动、还没有任何玩家连线**的阶段就写入
   debug 日志。这是 NPC 首次冷编译（`/std/char` 及其整条 `inherit`
   链）的一次性开销撞上偏低上限，与 AGENTS.md §7.90 已归档的
   `xyj2000f`/`xiyouji450`/`xlqy_early` 等实例是同一形状。修复：
   `config.fluffos` 的 `maximum evaluation cost` 从 700000 提到
   5000000（本项目已有 30+ 个库使用的常规补救值）。现场验证：修复前
   每次重启驱动都在 preload 阶段稳定复现上述 3+1 次报错；修复后连续
   两次全新驱动重启，`d/wiz/qiushi` 的 preload 均无任何 eval-cost 报错，
   随后完整的注册、移动、战斗、死亡/复活全流程（见下文）也没有再触发
   过 `cost limit reached`。
2. **§7.12 变体：`adm/simul_efun/message.lpc` 的 `shout()` 把
   `this_player()` 直接当 `message()` 第 4 个排除参数，在非玩家上下文
   （游戏内报时的 `heart_beat`/`call_out`）调用时炸出
   `Bad argument 4 to EFUN message()`**：同文件里的 `tell_room()` 早就
   有 `exclude || ({})` 的防御写法，但 `shout()` 漏了同样的保护。
   `adm/daemons/timed.lpc::bj_hour_event()` 每到欢乐纪元的整点就调用
   `shout()` 广播"现在是北京时间...点整"，此时没有 `this_player()`
   （返回 `int(0)`），`message()` 的类型检查直接报错——**这个游戏内
   时钟推进远快于真实时间**（本轮会话不到 5 分钟真实时间，游戏内时辰
   就从丑时跳到卯时，跨过了至少一次整点广播），所以这不是要等很久才
   触发一次的边角情况，而是几乎每次整点都会命中的常规错误。现场验证：
   修复前的第一次驱动启动，日志里在 `Initializations complete.`
   之后几秒内就出现了这条 `Bad argument 4 to EFUN message()` 报错
   （伴随 `previous_object(1): /adm/daemons/timed`，确认是
   `bj_hour_event()` 触发）；修复（`this_player() || ({})`）后重启，
   同一会话跑满至少一次整点广播窗口（游戏内从丑时到卯时），
   `debug.log`/stdout 都没有再出现这条报错。修复方式与该文件里
   `tell_room()` 已有的写法完全对称。
3. **§7.34 debug 遗留输出**：`adm/daemons/logind.lpc::get_name()`，
   中文取名成功后、设定密码提示之前，有一行裸的 `printf("%O\n", ob)`，
   会把登录对象的内部路径（`/clone/user/login#N` 之类）直接打在取名
   和密码提示之间——已删除，属于本项目在多个血统里反复见过的原作者
   调试遗留输出，不影响任何逻辑，纯粹的信息泄露/观感问题。现场验证：
   修复前后各走了一遍完整注册流程，修复后取名成功到密码提示之间干净
   无多余输出。

**§7.68 / §7.101 是否适用于本库的死亡系统**：都不适用，理由分别记录：

- **§7.101（`exits` 缺键导致 `valid_leave()` 永远打不到）不适用**：本库
  死亡去处 `/d/death/gate.lpc`（阴阳界）的 `exits` 映射本身 4 个方向
  （south/north/west/east）都是真实、可用的键（虽然映射上方注释写着
  过时的 `/* sizeof() == 2 */`，纯粹是没跟着改的注释，不影响功能）；
  真正负责复活的不是玩家手动找出口，而是房间里的 NPC 判官
  `d/death/npc/pang.lpc`——它的 `init()` 在鬼魂进房时立刻排一个 5 个
  阶段、每阶段 5 秒的 `call_out("death_stage", ...)` 对话链，最后调用
  `ob->reincarnate(); ob->move(REVIVE_ROOM);` 把玩家送回
  `/d/ourhome/kedian`（荒郊小店）。整个复活机制完全不经过 `go`/
  `valid_leave()` 这条路径，`gate.lpc` 自己的 `valid_leave()` 其实是在
  鬼魂状态下**无条件拒绝所有方向**移动（"还是赶着去投胎吧！"），这与
  §7.101 描述的"该有的出口被注释掉"完全是两回事。
- **§7.68（`present(ob)` 缺失重试导致鬼魂卡死）也不适用，且未做任何
  改动**：`pang.lpc::death_stage()` 的守卫是同样的
  `if (!ob || !present(ob)) return;` 形状，但按 AGENTS.md 的撤回说明，
  这个"改成重试"的修复只有在**同时**满足 (1) 鬼魂在这个房间无法自主
  移动、且 (2) 确实存在某个外部系统会强制把鬼魂拖走 两个前提都现场
  验证过之后才该应用。本库满足条件 (1)（`gate.lpc::valid_leave()` 对
  `is_ghost()` 的角色无条件 `notify_fail`，鬼魂物理上走不出这个房间），
  但通读全库没有找到任何类似 `bmxkx2001` 里"剧情向导 NPC 会不分死活强
  行拖走任何被追踪玩家"的强制位移机制——条件 (2) 未成立，因此保持原样
  不改，符合"没有现场验证两个前提就不要套用"的既定原则。
- **现场验证的完整死亡/复活流程**：用种子出的 `fluffos` 管理员账号在
  长安城中心 `kill guolao`（张果老，NPC 战斗力明显超出新手角色），
  几回合后角色死亡，移动到 `/d/death/gate`（阴阳界），判官崔珏的
  `init()` 立刻触发（**没有** `wizardp()` 排除逻辑，管理员账号和普通
  玩家走的是同一条复活流程，这点和 `hy2000` 记录的"管理员被排除在
  鬼魂剧情外"不一样），5 段对话如期播放，最终"你的魂魄又回到了自己
  身上"+"reincarnate()"，落地在 `/d/ourhome/kedian`（荒郊小店）。
  `score` 确认死亡计数 +1、气/神条恢复到 `reincarnate()` 设定的初始值、
  食物/饮水条满格（§8.9 一类的食水初始化问题未复现）。

**其余检查过、确认没问题的项目**：§7.5/§7.98（`adm/daemons/
securityd.lpc` 是 `trusted_read`/`trusted_write` 目录前缀式 ACL，
`valid_read()` 对未设置 euid 的情况是放行而非拒绝，即使是这样也没有
在 `file_size`/`stat` 上出现过 §7.5 那种"目录 ACL 挡住编译期检查"的假
阴性）、§8.13（没有独立的"WIZ 密码"二次登录闸门）、§8.14（`is_banned()`
统一传入 `query_ip_number()`，没有 `query_ip_name`/`query_ip_number`
混用）。留言板 `post`/`look board` 现场复测正常（§7.86 修复未回归）。
二次登录（`quit` 后重连）确认存档正确保存并恢复：管理员权限、留言板
帖子均在重连后完整可见。

**已记录但保持不修的观察项（非 bug，符合 §1.3e 精神）**：
`adm/daemons/logind.lpc::encoding()` 里"限制多重登录"的节流逻辑用
`query_ip_name(usr[i]) == ip_number` 比较（一边是反向 DNS 主机名，一边
是点分十进制 IP），实际上永远不相等，导致这个节流从未真正生效——但
既然本项目对这类 circa-2000 的连线节流机制本来就是"直接绕过，不用
修对"的既定政策（§1.3e），这个 bug 的净效果恰好就是"节流形同虚设"，
不需要改成"修好之后又要专门加绕过"，故按现状记录、不改代码。

**环境说明**：本轮测试中途，运行环境所在的底层主机发生过一次更换
（CPU 型号变成不支持 AVX 的 Xeon L5520），导致 `build-debug/` 下用
`-march=native` 编译出的驱动二进制在新主机上无声崩溃
（`SIGILL`，退出码 132，stdout/debug.log 均无任何输出）——这不是这个
库本身的问题，其它任何库都会同样炸；已用 `-DMARCH_NATIVE=OFF`
重新配置并完整重建 `build-debug`（详见 AGENTS.md §12 新增第 5 条），
重建后本库和另一个对照库都能正常启动，本轮后续的全部现场测试都是在
重建后的驱动上完成的。

**运行环境限制**：本次会话的 sandbox 里没有 `node`（仅
`~/.vscode-server` 下捆绑的 v16.13.2 可临时借用，已用它跑过一次
`format-corpus.mjs`，两处改动均"unchanged"，说明本身格式已合规），
`scripts/wasm_client.js` 这条 WASM 备用路径本次未启用，全程用原生
驱动 + `scripts/tmux_mud.sh` 完成注册、移动、留言板、战斗和完整死亡/
复活流程的现场验证。
