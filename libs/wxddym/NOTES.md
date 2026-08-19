
## 深度功能测试（第二轮，2026-08-03）

之前的会话只验证到"能登录、score 卡在'还没有出生'"这一步，把
"还没有出生"判断为既定的创世任务设计后就没有再往下走。本轮实际把
这整个"投胎"创世任务链走通了——`hhsj`（同宗，"洪荒世界"）那轮会
话明确说"完成整条链条超出首次上线验收的范围，没有走完"，本轮是这
个项目第一次真正把这一整套流程走到底。

proactive 检查 AGENTS.md 已归档的四类常见坏味道：`private nomask
command_hook` 命中的 `feature/command喵.lpc` 核实是死档案（真正生
效的是 `feature/command.lpc`，已经是干净的 `nomask`，通过
`F_COMMAND` 宏定义确认）；§8.9 的 age 判断本来就正确读的是
`user`；printf 调试残留、stat/water 键名均未命中。

**投胎流程实测**（通过自定义手机 App 协议，登录行格式
`id║密码║密文║邮箱`，命令走普通 telnet 一样的动词）：进入"世外桃
源"→（原本设计中提到的"四个方向选择品质"实际已被注释掉，只剩
south 一个有效出口，走 south）→"阎罗殿"→ 先 `washto 20 20 20 20`
（在忘忧池洗四项属性点，四个数之和须为80）→ `pianshu msx`（刷新天
赋）→ `knock 5`（选"光明磊落"性格）→ `born 扬州人氏`（选择投胎籍
贯，选项还有段氏皇族/唐门世家/中原苗家/关外胡家/慕容世家/欧阳世家
共七个）。

**发现并修复的一个真实 bug（新增 AGENTS.md §7.70）**：`born` 执行
到一半时，试图把角色移动进新手村"世界之树"广场，负责在这个场景生
成的 NPC `d/newbie/npc/laocunzhang.lpc`（老村长）编译失败：
`query("id", me)` ——这份代码库里 `query()` 的真正签名统一是
`query(string prop, int raw)`（`raw` 是"是否返回未格式化原始值"
的开关，不是目标物件！在 `feature/dbase.lpc`/`inherit/room/
room.lpc`/`adm/daemons/examined.lpc`/`u/rock/dbase.lpc` 四处定义
里核实过，签名完全一致）——把一个物件 `me` 传给期待 `int` 的第二
参数，是静态类型检查能直接抓到的错误。这行代码显然是想写"查询
`me` 自己的 id"，正确写法应该是 `me->query("id")`。已修复；用同一
个存档的 fluffos 账号在修复前后各走一次完整投胎流程对照验证：修复
前 `born` 卡死在这个编译错误上，`score` 一直显示"还没有出生呐"；
修复后完整走通，最终 `score` 正确显示【天界总管】称号、性格【光明
磊落】、天赋【如鬼似魅】【越空提升】、四项属性 20/20/20/20，食物/
饮水槽满，新手村场景和老村长 NPC 的问候语都正常渲染，没有再触发任
何报错。

**范围备注（这次没有一并修完，留给以后专门排查）**：用
`grep -rlP 'query\("[a-zA-Z_/]+",\s*(me|ob|user|this_player\(\)|
this_object\(\))\)'` 在这份档案全库扫了一遍，命中 **162 个档案**
——说明这不是孤立的一次打字失误，而是贯穿这份代码库很大一部分的
系统性习惯性写法（`feature/apprentice.lpc`、`kungfu/class/`下大
量武学招式档案等）。每一处具体会不会真的编译失败，取决于该调用点
`me`/`ob` 这类变量在当时的声明类型是不是能被驱动的静态类型检查器
看穿（比如声明成 `mixed` 就可能绕过编译期检查，只在运行时才出问
题，甚至完全不报错静默出错）——这次没有逐一验证，只修了实测过程
中真正拦路的这一处。162 个档案的规模明显超出单个 lib 深挖会话的合
理范围，已记录进 AGENTS.md §7.70，留给未来一次专门的系统性排查
（参照 §8.3a `command_hook` 那次批量排查的做法：先分类，每一处都
要过一遍真实开机验证再动手，不要盲目全局替换）。

顺带核对了 `d/register/entry.lpc`（"世外桃源"起始房间）`item_desc`
里注释掉的一段说明文字提到"四个不同方向的出口代表不同的角色发展方
向"，但对应的 east/south(原)/west 三个出口在代码里确实被注释掉
了——查证后发现这不是当前生效流程的缺陷：真正的选择"品质"/性格/
天赋机制早已迁移到阎罗殿的 `born`/`knock`/`pianshu` 这一套菜单命
令上，跑得完全正常，这三个方向出口和对应的 `roome.lpc`/`rooms.lpc`
/`roomw.lpc` 档案是被更新设计取代后留下的死代码，不是当前流程的必
经步骤，未做改动。

管理员账号 fluffos 因为本轮实际走完了投胎流程，存档
（`data/user/f/fluffos.o`、`data/login/f/fluffos.o`）里记录了真实
的天赋/性格/属性状态，已随本次改动一并提交（这是既有约定要持续维
护的演示管理员账号，不是随手创建的测试角色）。

**未覆盖范围**：门派拜师、真正的中原地图探索、战斗系统因时间原因
未实测（"投胎"完成后已可以正常使用 `score`，具备继续测试战斗的前
提条件，留给后续会话）。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

自定义手机 App 协议（不是原始 telnet）：登录发送"id║password║ciphertext║email"（║ = U+2551），新角色创建发送"gender║img║nickname"（通过直接阅读 logind.lpc 的 jiance()/get_user()/get_char() 调用链逆向工程得出）。WASM 修复：修好了 GBK 每字 2 字节的 is_chinese() 检查（现在是码点判断），给 band.lpc 的 is_banned() 打了本地回环放行补丁，修复了 clone/user/user.lpc 的 accept_kill() 里 §7.50 的 is_killing(ob) 对 is_killing(ob->query("id")) 不匹配。score 卡在和 hhsj 相同的 nitan 血统"已出生"dbase 属性上（不是 bug，是有意的创世任务设计）。通过 adm/etc/wizlist 把 fluffos/Mud@2026 播种为 (admin)。完整的注册+look/score/quit+管理员 update 已在 WASM/原生下全程验证。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`DATABASE_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 5 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 跨库扫描修复（ROOM 冗余 replace_program() 关闭包炸弹，2026-08-19）

同一形状覆盖到几乎所有房间基类（机制详见 AGENTS.md §7.100）。本库属
于该扫描已知最大规模的 10 个库之一。二进制模式脚本机械删除了 5921
处独立、未注释的 replace_program(ROOM); 整行。另外手工清理了造房工
具代码生成模板里内嵌的同一形状，共发现三份独立的造房工具
（`clone/misc/roommaker.lpc` 1 处、`u/lonely/obj/roommaker.lpc` 3
处、`u/lonely/obj/roommk.lpc` 3 处，后两份是巫师个人目录下的完整独
立拷贝，同样内嵌了这个模板 bug，一并清理）。删除总计 5928 行，与本
次扫描 FINDINGS.md 记录的 wxddym 存活命中数完全一致。

验证：干净启动一次真实调试驱动，端口 40189 正常监听，
work/log/debug.log 全程无新增内容。本库登录用自定义"指尖客户端" App
协议而非普通 telnet 文本菜单（详见上方"迁移自 meta.json"记录），且
第一行任意内容都会被 jiance() 无条件放行，真正的登录行要在第二行发
送 UTF-8 编码的 `id║密码║密文║email` 格式（GBK 编码会导致分隔符字
节不匹配、explode() 拆不出 4 段而报"未知错误"——排查耗时最长的一步）；
登录成功后世界会持续推送任务精灵后台广播消息，属正常游戏内容非卡
死。用已播种的 `fluffos`/`Mud@2026` 管理员账号连线成功（"目前权
限：(admin)"），在世界之树/村间小路之间往返移动，`look`/`score`
均正常，未见任何 "cannot replace"/"cannot bind" 或崩溃迹象（唯一
噪音是 `cmds/std/go.lpc` 首次惰性编译时打印的几个无害 Unused local
variable 警告，与本次修复无关）。测试产生的
`data/{login,user}/f/fluffos.o` 存档时间戳 diff 已 `git checkout`
撤销，不提交。驱动按精确 PID kill。
