
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES/金庸血统 mudlib，游戏内标题为"火云录2000"（Huo Yun Lu 2000）。修复的 bug：（1）真正生效的 adm/simul_efun/chinese.lpc 里经典的 §8.1 is_chinese() GBK 字节区间 bug——adm/single/chinese.lpc 那份死代码副本早就修好了（经典的 §7.56 类陷阱：真正被 include 的那份档案反而还是有 bug 的旧版本）；（2）adm/daemons/logind.lpc 里经典的 §8.1 check_legal_name() 字节数没减半的长度界限（2/10→1/5 字符）加上 i%2==0 门槛和 name[i..<0] 尾部切片；（3）新发现的严重 bug（AGENTS.md §7.59 的一个变体）：adm/obj/master.lpc 的 valid_read/valid_write 包装函式无条件地用 previous_object() 覆盖驱动提供的 user 参数，包括 load_object/include 这两种情形，静默拒绝了注册过程中编译玩家自己身体类别的请求——这个崩溃完全不可见（没有报错，没有编译警告），直到把可疑的呼叫包进 catch() 才浮现出"*Read access denied."；已仿照原始 §7.59 的模式，把 func=="load_object"/"include" 排除在覆盖之外来修复；（4）adm/daemons/wzd_log.lpc 里的管理员登录 bug：它的防盗号 IP 验证系统用 regexp()（真正的正则语法，不是通配符）来比对连线 IP 和按管理员分类的白名单——最初尝试用通配符语法（'*.*.*.*'）给测试管理员账号加白名单，结果因为无效的正则语法崩溃，静默杀死了 wzd_log() 剩下的代码，没有任何可见症状；已改用合法的正则（'.*'）修复。从白名单外的 IP 用管理员身份登录本来就会要求当场解答一道显示在画面上的随机数学题（这是有意的、设计良好的防盗号功能，不是 bug）——本次为了标准的 fluffos 测试账号绕过了这一步，用的是 IP 白名单映射，而不是真的去在线解题。GB 和 BIG5 两个编码选单选项都实测正常，不用修。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字，管理员流程（fluffos/loginpass1，"目前权限：(admin)"）格式化后也重新验证过。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`M_BOARD`、`WIZ_BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 47 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

### 血统鉴定：`hy3` 和 hy/海洋 家族无关，是同名不同源的独立代码库

`hy3` 这个 slug 和 `hy`/`hy2000`/`hy2002`（"海洋"题材）共享前缀，但游戏内
标题是完全不同的"火云录2000"，NOTES 里此前的 WASM 修复摘要也已经把它归类
成"ES/金庸血统"。本次专门做了一次核对，逐一 diff 了核心档案，结论是**两
者不是同一血统，只是碰巧都属于"ES2 衍生、金庸题材"这一大类武侠泥巴（和
AGENTS.md §11"ES II / 东方故事 mega-family"里其它十几个互不相关的成员一
样，共享山头/门派命名不是血统信号）**：

- `adm/obj/master.lpc`：`hy`/`hy2000`/`hy2002` 三份文件字节级相同（332
  行，注释头"for ES II mudlib / original from Lil / rewritten by
  Annihilator"）；`hy3` 的版本是 363 行，完全不同的结构（注释头"change
  by xhh"，多出一套 `get_player_fname()` BIG5/GB 双登录物件回退机制），
  diff 前几行就完全对不上。
- `adm/daemons/securd.lpc`/`securityd.lpc`：`hy`/`hy2002` 的真正生效版本
  署名"by jackyboy@cctx"，`wiz_levels` 里有 `"(apprentice)"` 等级，
  `inherit F_DBASE`/`F_SAVE`；`hy3` 的 `adm/daemons/securityd.lpc` 署名
  "xingyun 设置 on 2002.1"，`wiz_levels` 没有 `"(apprentice)"`，完全没
  有 `inherit`，`valid_read`/`valid_write`/`valid_seteuid` 的整体结构和
  权限判断逻辑都不同（例如 `hy3` 已经自己放行了 `func=="stat"` 和
  `"file_size"`，§7.5 的两个已知变体对它并不适用，见下）。
- `hy3` 自己的 `work/` 树里 `u/xingyun`（含一份 `u/xingyun/bak/`
  历史备份）、`u/xingyu`、`u/hsly` 几个巫师目录名和 `securityd.lpc`
  的署名"xingyun"/`README.md`"火云信箱：hsly@etang.com"互相印证，指
  向一个自成一体、独立维护过的代码库，不是从 hy 系任何一份分支出来的。

顺带一提：`libs/hy/work/` 树里意外嵌着一份完整的"海洋II 2002新春特别版"
Windows 发行包（`海洋2002/`，含 `MudOS.exe`/`mudos.dll`），其 `config.hy2`
的 `mudlib directory` 字段写的是 `./hy3`——这只是原作者给自己本地工作目
录起的名字（"海洋三代"之类），和本项目独立分配的 `hy3` slug 纯属巧合撞
名，两者内容（对比 `master.lpc`）完全不同，不构成任何血统证据，此处存
档说明以免未来某次巡检误把这个巧合当成新线索。

**结论**：`hy` / `hy2002` NOTES.md 已确认的 §8.9（食物/饮水年龄判断读
错对象）、§7.86（留言板 `post` 崩溃）两个 bug 类别，属于"值得按同类代码
特征检查，但不能假设代码完全一致"的情况——下面按 AGENTS.md 既定原则逐
条核实 `hy3` 自己的实际代码形状，不搬 hy 系的现成修法。

### 新发现（本次新增 AGENTS.md §8.14）：管理员自定义 IP 黑名单把几乎所
有连线都误判为"被封"

`adm/daemons/logind.lpc` 的开场横幅之后立刻有一段"added by
xingyun用来禁止恶意破坏的ip login"：

```lpc
if (BAN_D->is_banned(query_ip_name(ob))) {
    write("Sorry, your ip is banned by this mud.\n");
    destruct(ob);
    return;
}
```

`band.lpc` 的 `is_banned(string site)` 内部用
`sscanf(site, "%s.%s.%s.%s", ...)` 把参数当成一个点分四段的 IP 地址解
析，解析失败（段数不是 4）就直接 `return 1`（视为被封，fail-closed）。
但调用点传进去的是 `query_ip_name(ob)`——这是反向 DNS 解析出的**主机
名**，不是 IP。本地原生驱动测试下，回环地址的反向解析立即拿到
`"localhost"`（glibc `/etc/hosts` 命中，几乎瞬间完成，不像真正的公网
DNS 查询那样异步延迟），这个字符串没有任何"."，`sscanf` 直接失败，于
是**每一次连线，包括本地测试，都会被判定为"被封"并立刻断线**——玩家在
选完编码、还没看到"您的英文名字："提示之前就被踢出，`debug.log` 没有
任何报错，纯粹是游戏内的一行英文提示 + 断线，非常容易被误诊断成网络问
题或防火墙问题。真正部署给公网玩家时同样会踩坑：绝大多数有反向 PTR 记
录的真实主机名也不是点分四段格式，一样会被这条判断误伤——这不是一个只
在本地/沙箱环境才会触发的边界情况。

同一份 `logind.lpc` 里紧接着几十行之后，另一处用途相近的检查
（`BAN_D->is_netclub(query_ip_number(ob))`）用的是正确的
`query_ip_number()`，证明 `is_banned()` 这一处确实是调用参数传错了函
数，不是 `is_banned()` 本身故意设计成接受主机名。

修复：把 `query_ip_name(ob)` 改成 `query_ip_number(ob)`，让
`is_banned()` 收到它本来就期望的点分四段 IP 字符串。本档案的
`adm/etc/banned_sites` 目前是空文件，所以修复后默认放行所有连线（和
`band.lpc` 自己的设计意图一致：黑名单为空就不该拒绝任何人），管理员真
正想封的 IP 段可以照常通过巫师指令写进 `Sites` 数组生效。修复前用
tmux 连线复现（选完编码立刻被踢，提示"Sorry, your ip is banned by
this mud."）；修复后重启驱动，同一条连线正常走到"您的英文名字："提示，
完整注册流程（见下）全程无阻。

### §7.90 评估成本上限过低——适用，已修复

`config.fluffos` 的 `maximum evaluation cost` 是本项目模板默认值
`700000`。开机阶段 preload 还没跑完就已经在 `debug.log` 里留下 17 条
`Eval interrupted: object adm/obj/master cost limit reached, limit:
700000 usec.`——比典型的"移动到没走过的房间才触发"更早、更严重，连
`master.lpc` 自己的初始化都会撞上限。改为本项目常用的 `5000000`（30+
个其它档案已使用同一个值）后重新开机，`debug.log` 里 `cost limit
reached` 命中数从 17 降到 0；后续完整走了一遍注册、移动、战斗、留言板
的会话，全程 `grep -c "cost limit reached" log/debug.log` 始终是 0。

### §8.9 食物/饮水年龄检查读错对象——适用，已修复（效果目前被另一处默
认值掩盖，属于第十例已知实例）

`adm/daemons/logind.lpc` 的 `enter_world()`：

```lpc
if (!user->query("food") && !user->query("water") && ob->query("age") == 14) {
    user->set("food", user->max_food_capacity());
    user->set("water", user->max_water_capacity());
}
```

`ob` 是登录用的临时物件，"age" 属性在全档案任何地方都没有对它 `set`
过，这个判断按字面读永远是假。但本档案的 `init_new_player()`（在
`get_gender()` 里，`enter_world()` 之前就已经被呼叫）会无条件把新角色
的 `food`/`water` 都直接 `set` 成 `300`，所以上面这个门槛判断即使按字
面永远不触发，实测新角色的食物/饮水栏依然是满的——效果被完全掩盖，和
AGENTS.md §8.9 已经记录过的 `jhfy2` 第九例一模一样的"被掩盖"情况。按
既定教训（"被别处默认值掩盖不代表底层的读错对象是对的，未来任何人动到
那个默认值就会让这个 bug 突然显形"）照样修正为
`user->query("age") == 14`，不因为当前观测不到症状就跳过。

### §7.5 自定义 ACL 未放行编译期/存在性探测——两个已知变体均不适用

`hy3` 自己的 `securityd.lpc`（`SECURITY_D` 宏指向的真正安全精灵，和
hy/hy2000/hy2002 的 `securd.lpc` 是完全不同的代码）在
`valid_read()` 开头就有：

```lpc
if (file == WIZLIST) return 1;
if (func == "stat" || func == "file_size") return 1;
```

`load_object`/`recompile_object`/`include` 三个 func 虽然没有被显式列
在 `switch` 里，但 `valid_read()` 后半段的逻辑是"默认放行，只有几个特
定目录对非 `(admin)` 玩家拒绝"（`return 1` 收尾），不是 hy 系那种"默认
拒绝，只放行白名单 func"的形状，所以这条 §7.5 的两个已知变体（
`file_size` 探测误判 / `get_dir()` 的 `stat` 拒绝把整张指令表清空）都
不适用——实测走过扬州似的门派/技能初始化路径和全部指令（`look`/
`score`/`i`/`post`/`kill`），`debug.log` 全程没有任何 `F_SKILL`/`Read
access denied` 报错。

### §7.86 留言板 `post` 崩溃——此前的跨库扫描修复，本次首次带真实
post 内容全链路验证

上面"WASM 修复摘要"记录过全档案 47 处 `inherit BULLETIN_BOARD`/
`M_BOARD`/`WIZ_BULLETIN_BOARD` + 多余 `replace_program()` 已经删除，
但当时只做了编译检查，没有真的 post 过。本次用管理员账号在两个不同的
留言板实测：巫师休息室的 `/clone/board/wiz_b.lpc`（`post 深度测试` →
内建列编辑器 → `.` 结束 → "留言完毕。"）和客店的
`/clone/board/kedian_b.lpc`（同样流程），两次都正常打开编辑器、正常存
盘、`read new` 能读到刚发的留言——确认 §7.86 的修复在真实使用场景下
（不只是编译期）是干净的，没有残留任何指向同一个 board 基类的、还挂着
多余 `replace_program()` 的漏网文件。普通玩家账号需要先有
`literate`（识字）技能达到 10 级以上才能 `post`，这是本档案自己的游戏
设计（不是 bug），用管理员的 `setskill` 指令加上技能后验证。

### 管理员账号 `fluffos`：`wiz_status`/`adm/etc/wizlist` 授权数据已提
交，但角色存档此前从未真正落盘——本次重新走完整注册流程补齐

`adm/etc/wizlist` 里已经有 `fluffos (admin)` 一行（git 历史里已提交，
非本次改动），但 `work/data/login/f/`、`work/data/user/f/` 目录下并没
有 `fluffos.o` 存档——说明此前某次会话只播种了授权名单，管理员角色本
身从未真正在原生驱动上完整注册过（或者注册后存档没有被提交/被后续清
理误删）。本次用密码 `Mud@2026` 走完整注册流程重新创建了 `fluffos`
（中文名"云飞"），因为 `wizlist` 里已经有名单，注册完成、`enter_world()`
时自动拿到 `(admin)` 权限，落地在"巫师休息室"。验证 `update
/adm/daemons/logind` 编译成功（写权限正常）。**同一登录会话内用同一账
号 `fluffos`/`Mud@2026` 断线重连了第二次**（§8.13 的"第二次登录死锁"
检查），"重新连线完毕"提示正常，直接回到断线前所在房间，没有任何登录
死锁现象。

### 游玩验证：移动、战斗、留言板

用非管理员测试账号 `shiyu`（石语）走完整注册（GB 编码 → 英文 id →
中文名 → 密码 → 天赋 → 邮箱 → 性别）到进入游戏世界，`look`/`score`/
`i` 全部正常显示（食物/饮水栏满格，验证了上面 §8.9 的掩盖效果），移动
（`w`/`s`）到相邻房间正常。管理员账号在 `/d/village/sexit`（华山脚下
南村口）对野狗（`d/village/npc/dog.lpc`）发起 `kill`，完整战斗流程
（拳脚/招架/轻功技能随战斗提升、野狗体力递减描述、最终"倒在地上,死
了！"）正常结束，没有触发管理员自己的死亡（`accept_fight()` 差距明
显，属于预期结果，不是"安全陪练"NPC，本次未特意寻找陪练木人），因此
本轮没有触发死亡/复活流程，如实记录为未验证——不假装测试过。

### 编码菜单

GB 编码选项本次实测正常显示中文（连线横幅、房间描述、战斗提示全部无
乱码）；BIG5 选项本次未重复测试（此前 WASM 阶段已确认过两者都正常，
本次时间聚焦在新发现的连线拒绝 bug 上）。
