## 概述

`discworld`（901）是官方 Discworld MUD 的 mudlib，本次转换自
`archives/901-2_dw_fluffos_v3_dw_fluffos_v3.zip`（Cratylus 打包的
"Discworld Bundle" 第三版，随附一份匹配的 FluffOS 驱动源码——按
AGENTS.md §2 惯例忽略捆绑驱动，只用本项目自己的驱动）。这是本项目
第一个真正意义上的纯英文 mudlib（此前"deprioritize English libs"
的旧策略已被项目负责人撤销）。`archives/` 里同时还有 v1
(`901_dw_fluffos_v1_dw_fluffos_v1.tar.gz`) 和 v2
(`901-1_dw_fluffos_v2_dw_fluffos_v2.zip`) 两份更早的快照，未发现
v3 有 v1/v2 没有的结构性问题，因此直接采用 v3 作为正式转换对象；
v1/v2 保留为未转换的 `scripts/non_mudlib_meta/dw_fluffos_v{1,2}.json`
条目（编号改为 901-1/901-2，把主编号 901 让给这份真正转换的
`libs/discworld/`，并删除了原来占位用的 `dw_fluffos_v3.json`）。

## 编码

英文 mudlib，GB18030→UTF-8 转档步骤基本不适用（`convert_lib.sh` 的
"already_utf8" 分支覆盖了绝大多数文件）。但发现并修复了三个真正的
编码坑，跟 AGENTS.md §4.1 描述的"GB18030 静默误转"是同一类问题，
只是编码对不是 GBK/BIG5，而是 **Mac Roman**（老 Mac 文字编辑器留下
的遗产，符合这份档案 1990 年代初 Discworld 开发史的年代背景）：
`doc/lpc/intermediate/chapter1`、`doc/concepts/conversions`
（两份游戏内 LPC 教程文本）、`www/external/java/telnet/README`
（bundle 自带的 Java telnet 小程序说明，非 mudlib 运行时内容）。
`convert_lib.sh` 默认的 GB18030 转码对这三个文件要么产出明显乱码
（`conversions` 被标记为 lossy），要么"成功"但内容变成 garbled 的
合法 UTF-8（`chapter1` 静默出现 `mud's` → `mud誷`；这正是 §4.1
警告过的、GB18030 广义超集特性带来的静默误转类别，只是这次的源编
码是 Mac Roman 而不是 BIG5）。用 Python 对整个 `work/` 树做了一次
全量 UTF-8 可解码性扫描，逐一用 `mac_roman`/`cp1252`/`latin-1` 试
解码确认后，从 `raw/` 原始字节用 `mac_roman` 重新解码替换修复。

## `.c` → `.lpc` 重命名的连锁反应（AGENTS.md §4.2 类，本 lib 最集中
的 bug 来源）

- **`global/virtual/virtual.h` 自包含**：原文件是
  `#include <virtual.h>`（尖括号，通过 include 路径解析到
  `/include/virtual.h`，一份内容完全不同、真正定义
  `VIRTUAL_NAME_PROP` 等宏的文件）。`convert_lib.sh` 的"本地尖括号
  转双引号"启发式误判：因为同一目录下恰好也有一个同名文件
  `global/virtual/virtual.h`（也就是它自己！），把它错误地改写成
  `#include "virtual.h"`——变成字面意义上的自我包含，导致
  `#include nested too deeply`。已改回尖括号形式，并确认全库范围内
  这是唯一一处真正的自包含碰撞（写了个脚本核对每个本地
  `#include "X"` 的解析目标是否等于包含它自身的文件，只有这一处命
  中）。
- **虚拟对象编译器的后缀分发表**（`global/virtual/server.lpc` 的
  `create_virtual_object()`）：按文件名最后一段（`explode(name,".")`
  取最后一个元素）查表决定用哪个编译方法，原来只注册了 `"c"`/`"C"`
  两个后缀作为"普通 LPC 主文件"的兜底编译器。重命名后这类引用变成
  `.lpc` 后缀，查表落空，报
  `create_virtual_object() : unknown suffix to /obj/vessel.lpc`。已
  在 `server.lpc` 的 `create()` 里补上 `add_method("lpc", ...)` 作为
  `"c"`/`"C"` 的别名。
- **道具数据文件里硬编码的 `.c` 基类引用**（78 个 `.ob` 文件）：这
  类"prop 文件"不是 `.lpc`/`.h`，`convert_lib.sh` 的引用修复只扫描
  这两种扩展名，所以类似 `obj/misc/buckets/bucket_small.ob` 里的
  `::#Class:: "/obj/vessel.c"` 完全没被碰到。虚拟对象编译器
  (`global/virtual/compiler.lpc` 的 `prop_to_fun()`) 会把这个
  `#Class` 值原样拼进生成的临时源文件里当 `create_virtual_object()`
  的参数，指向一个磁盘上已经不存在的 `.c` 路径，报
  `*Bad argument 1 to EFUN call_other() ... Got: int(0)`（新角色出
  生装备里的水桶就是这么崩的）。写了个脚本扫描全部 `.ob` 文件里的
  `::#Class::`/`::#class::` 行，把其中的 `"X.c"` 批量改成
  `"X.lpc"`，78 个文件全部命中修复（`grep -c` 复查后 0 剩余）。
- **`secure/command.lpc` 的定长切片**（本 lib 最严重的一个 bug，
  见下面单独一节）。
- **虚拟基类的 `__FILE__` 定长切片**：`obj/armour.lpc`、
  `obj/clothing.lpc`、`obj/shield.lpc`、`obj/clothing_transport.lpc`
  的 `query_static_auto_load()` 都有
  `if (base_name(this_object()) != __FILE__[0..<3])`，用来判断"我是
  不是这个基类本身而不是子类/克隆体"。`__FILE__` 原本是 `.c` 后缀
  （2 字符），`[0..<3]` 精确去掉 2 个字符；重命名后 `__FILE__` 变成
  `.lpc`（4 字符），仍然只去掉 2 个字符，导致比较永远不相等，
  `query_static_auto_load()` 对这四个基类永远返回空 mapping 而不是
  真实的静态装载数据。已改成 `[0..<5]`（去掉 4 个字符）。同一 codebase
  里还有几处类似切片（`secure/bulk_delete.lpc`、
  `cmds/creator/hous_ing.lpc`、`obj/handlers/autodoc/*.lpc`、
  `global/cloner.lpc` 的 `add_mapping()`）没有确认是否受影响——都是
  巫师/管理工具，不在本轮 look/score/quit 核心验证路径上，留给以后
  的 pass。

## `secure/command.lpc`：同一个定长切片 bug，但后果是"每一条指令都
失效"

这是本次修复里影响面最大的一个：`eventRehash()`/
`eventGuildRaceRehash()` 扫描 `cmds/{living,player,creator,...}/`
目录下的 `*.lpc` 文件建立指令名索引，原文件对每个文件名做
`file[0..<3]` 去掉 `.c` 后缀（比如 `l_ook.c` → `l_ook`，下划线是
Discworld 自己的"最短缩写标记"约定）。`convert_lib.sh` 已经把
`get_dir(...)` 的通配符从 `"/*.c"` 改成了 `"/*.lpc"`（这是被
ref-fixup 扫描到的引号字符串，能自动修），但紧接着的 `[0..<3]`
是纯算术定长切片，扫描不到。结果是索引表里存的键从
`"l_ook"` 变成了带着半截扩展名尾巴的 `"l_ook.l"`，任何真实指令名
都查不中——`look`/`get`/`drop` 等等全部指令，不管是自动触发的还是
玩家手打的，全部落到驱动的默认 fail message `"What?"`。改成
`[0..<5]`（去掉 4 字符的 `.lpc`）后修复，同时把两处几乎一致的
调用点都改了并加了详细注释解释切片算术。

## `add_action` 的 `"*"` 万能动词约定，在这个驱动上根本不存在
（AGENTS.md §6.2 类，本次深挖最有价值的发现）

这份 mudlib 出身的原始驱动把 `add_action(fn, "*", priority)` 当成
"匹配任意指令"的万能动词写法，并且把第三个参数当优先级数字用（从
`-10000` 到 `10000` 都有）。整份代码库有 5 处这样的注册：
`std/living/living.lpc` 的 `exit_command`（出口/移动检测）、
`global/psoul.lpc` 的 `lower_check`/`drunk_check`（eval-cost 节流
和指令排队）、`global/new_parse.lpc` 的 `new_parser`、
`global/command.lpc` 的 `cmdAll`（真正的目录式指令分发器，见上一
节）。

但本项目这份 FluffOS 驱动（`packages/core/add_action.cc`）里
`add_action` 的动词匹配是精确字符串比较（或前缀匹配，取决于标
志位），源码里明确写着"if was `add_action(blah, "")` then accept
it"——**万能动词约定用的是空字符串 `""`，不是 `"*"`**（驱动自带的
`testsuite/clone/user.lpc` 也是这么用的）。字面上的 `"*"` 不会被
特殊处理，就是个永远不会等于任何真实指令的普通字符串。后果：这 5
个处理函数在这个驱动上**一次都不会被调用**——不是报错，是彻底静默
失效。用 `efun::write()`（§10.3 建议的、能绕过 write_file() 潜在 ACL
拒绝的调试手段）在 `command_commands()`/`cmdAll()` 里加临时探针才
现场坐实：`command_commands()` 确实执行了、`add_action` 也确实调用
了、`commands()` 里也确实能看到 5 条以 `"*"` 为动词的记录——但玩家
打 `look` 时 `cmdAll` 的探针从未触发过，`"What?"` 直接从驱动兜底逻
辑冒出来。全部 5 处 `add_action(fn, "*", N)` 改成
`add_action(fn, "", N)`（连同两份未被实际 inherit 的历史备份文件
`std/living/living.eff_shad.lpc`/`living.no_eff_shad.lpc` 里的同款
调用，为了一致性也顺手改了，虽然它们目前不在真正的继承链上）。

**同一个坑的第二层，不改完全部指令依然会崩**：这个驱动上
`add_action` 的第三个参数根本不是优先级，而是一个 2-bit 标志位
（`flag & 3`；`V_SHORT=1`、`V_NOSPACE=2`，见
`vm/internal/simulate.h`），决定驱动传给处理函数的参数是"整行原
文"还是"undefined"。原代码库那些看似"优先级"的数字被这个驱动重新
解释成了几乎随机的标志组合：`cmdAll` 恰好拿到 `-1&3=3`（含
`V_NOSPACE`，侥幸拿到整行文本）、`new_parser` 拿到 `-2&3=2`（同样
侥幸），但 `exit_command`（`1&3=1`，只有 `V_SHORT`）、
`lower_check`/`drunk_check`（`±10000&3=0`，两个标志都没有）在这个
驱动上对不带空格的单字指令（比如 `look`）拿到的参数是 **undefined**
而不是字符串 `"look"`。现场验证：只改动词字符串后重新开机，`look`
不再是 `"What?"`，但会在 `exit_command()` 内部因为
`explode(word," ")` 对 `word==0` 报 `*Bad argument 1 to explode()`
崩溃（这是这些处理函数第一次真正被这个驱动调用，之前从未被真实执
行过，所以这个参数类型 bug 此前完全没有暴露的机会）。把全部 5 处
的第三个参数统一显式改成 `2`（`V_NOSPACE`），确保驱动总是把整行原
文传给这些处理函数——这才是它们的代码本身一直假设的行为。两处改动
（动词字符串 + 标志位）叠加后，`look`/`score`/`quit` 等全部指令才
真正跑通。

## `secure/simul_efun.lpc`：`query_multiple_short` 的先有鸡先有蛋

`std/object.lpc` 等大量文件把 `query_multiple_short()` 当 simul_efun
裸调用。原代码库自带一份可用的 polyfill
(`secure/simul_efun/multiple_short.lpc`)，但在 `secure/simul_efun.lpc`
里被注释掉了，附注"现在通过 parser 包提供"——说明原始目标驱动把它
实现成了真正的 C 层 efun。这个驱动没有这个 efun，取消注释后仍然编
译失败：`secure/simul_efun/modified_efuns.lpc`（在
`secure/simul_efun.lpc` 里比 `multiple_short` 更早被 inherit）内部
调用了 `query_multiple_short()`，但每个 `inherit` 目标文件是被当独
立编译单元处理的——simul_efun 对象自身还在"第一次构建中"，驱动尚未
把它注册为可解析的 simul_efun，所以裸调用在这个阶段无法按 simul_efun
兜底解析，报 `Undefined function query_multiple_short`。修法参考
同一个文件里已有的先例（`base_name` 就是用同样手法处理的）：让
`modified_efuns.lpc` 自己直接 `inherit "/secure/simul_efun/multiple_short"`，
这样它在调用点之前就作为真正的同编译单元继承函数存在，不再依赖
simul_efun 运行时解析。

## `global/psoul.lpc`：`process_input()` 里 `time_expression{}` 块
按分支不对称收尾

`process_input()` 用 `int t = time_expression{ ...; #if
efun_defined(add_action) return str; #else _process_input(str); #endif
};` 这种写法，但闭合花括号 `};` 只出现在 `#else` 分支内部，`#if`
分支（`return str;`）完全没有闭合。在原始目标驱动上 `add_action`
不是原生 efun，`#else` 分支恒定被选中，从未暴露过这个不对称。这个
驱动上 `add_action` 是原生的，`#if` 分支被选中，`time_expression{}`
块（以及整个 `process_input()` 函数）实际上从未正确闭合，把后面几
百行代码（`_process_input`/`command` 函数定义、`lower_check()` 等）
都错误地解析成了 `process_input()` 内部悬空语句，最终在文件末尾的
`int lower_check(...)` 处以 `unexpected L_BASIC_TYPE` 报错——报错位
置离真正的病灶（一次 `#if`/`#else` 分支闭合不对称）隔了 100 多行，
容易误判成 `lower_check()` 自己的语法问题。修法：把 `};` 挪到
`#endif` 之后，两个分支统一在同一处闭合；`#if` 分支的 `return str;`
依然会在闭合前提前退出函数，行为不变。

## `global/wiz_channels.lpc`：命名参数 lambda 里混用了 `$1`

`map_func = function (object ob) { ...; str = $1->query_cap_name();
... }` 用显式命名参数 `ob`，函数体里却写成匿名闭包才用的 `$1`——这
个驱动对这种混用直接报编译错误（`$var illegal inside anonymous
function pointer`），大概率是从紧邻的 `(: strcmp($1->query_name(),
$2->query_name()) :)` 匿名闭包写法复制粘贴时漏改的作者笔误。把三处
`$1` 全部改成 `ob`。

## `obj/handlers/armoury.lpc`：目录缺失时的空指防护

`walk_directory()` 对 `get_dir(dir,-1)` 的返回值不做非数组判断直接
`foreach`；这份第三方压缩包本身就缺 `/obj/armours/`、
`/obj/clothes/` 两个内容目录（见下面"已知内容缺口"），`get_dir()`
对不存在的目录返回 `0` 而不是空数组，每次 `rehash("armours"/"clothes")`
都会崩一次 `*Bad argument 2 to foreach`（被 preload 的 catch 兜住，
不影响开机，但会持续往 log 里写噪音）。加了
`foreach(file in (tmp || ({}))) {...}` 防护，属于通用防御性写法，
和目录缺失是否"该修"无关——不管以后是否补上这两个内容目录，这个
guard 都是对的。

## 预加载卫生（AGENTS.md §7.6 标准策略）

`secure/config/preload` 里的 `/net/intermud3/intermud`（真实的
Intermud-3 协议精灵，会试图连接外部 intermud 路由器）按标准策略提
前注释掉，避免在沙盒环境里挂起/拖慢开机。它的 `create()` 本身不会
立即联网（真正的 socket 连接是懒加载的），只有玩家主动执行
`mudlist` 才会隐式自动编译并触发；这不在核心验证路径上，未做进一
步处理。

## 管理员账号播种

`secure/master.lpc` 用一个硬编码的 `TRUSTEES` 宏（含 `Root` 和
`cratylus`）+ 一个真正可持久化的 `positions` mapping（存在
`secure/master.o` 里，通过 `add_trustee()`/`add_senior()` 等指令维
护）两层机制判断管理员身份。`positions` 在原始档案里是空 mapping，
且 `add_trustee()` 本身要求调用者已经是 trustee 才能提升别人（先有
鸡先有蛋，符合 §1.5 提到的典型引导场景）。直接编辑 `secure/master.o`
的存档数据，把 `positions (["fluffos":2,])` 写进去（`2` 是
`master.lpc` 里 `#define TRUSTEE 2` 的值）。验证：`fluffos` 正常走
完注册流程 → 密码验证成功注册 → 重新登录时能看到只有巫师才会看到
的"To all creators.../To all Domain Leaders..."提示横幅 → 执行
`compile /std/room`（本 lib 里 wizard 级别的重编译指令，等同其它
lib 常用的 `update`）成功走到实际尝试编译的阶段（报
`Undefined function generate_source`，而不是任何权限拒绝提示——说
明 ACL 授权本身是通的，卡在的是下面这条独立的、和管理员授权无关的
预置代码 bug）。

## 已知内容缺口（第三方重打包档案本身缺失，非本次转换造成，不予
"修复"）

- **`/std/outside.lpc` 完全不存在**（原始 `raw/` 里也没有）。多个
  教学/示例房间（`d/learning/...`）和至少一个真实房间
  (`room/air.lpc`) `inherit "/std/outside"`，这个基类缺失会让这些
  房间编译失败。`/std/outsides/`（复数）目录下有 `basic.lpc` 等一
  套不同的"地形贴图"体系，但它们各自 `inherit
  TERRAIN_MAP_OUTSIDE_BASE`，不是同一套东西，不能直接顶替。
- **`/obj/armours/`、`/obj/clothes/`（复数，内容目录）完全不存在**
  （原始 `raw/` 里也没有；`/obj/armour.c`/`/obj/clothing.c` 这两个
  基类文件本身是存在的）。`/obj/weapons/`、`/obj/scabbards/` 等姊
  妹目录反而都在，说明这份第三方重打包的内容裁剪并不均匀。
- **`/twiki/data/` 完全不存在**：创作者协作 wiki 子系统的数据目
  录，`obj/handlers/twiki.lpc` 的 `find_changed_pages()` 会在每次
  开机 `do_check_changes()` 时报一次 `*Bad argument 1 to explode()`
  （`read_file()` 读不存在的目录返回 0）。被 preload 的 catch 兜
  住，纯创作者向工具，不影响玩家侧。
- **`secure/cmds/creator/compile.lpc` 里 `generate_source()` 未定
  义**：这个文件自己的注释就写着"compile command, **trial out** by
  Turrican for a commands daemon"——看起来是原始档案里就没写完的实
  验性代码，两个分支（`__RUNTIME_LOADING__` 开/关）都调用同一个从
  未定义过的函数。已确认这不影响管理员 ACL 授权本身（详见上一节），
  未做修复（不清楚 `generate_source()` 原本该对接到哪个真实的动态
  编译机制，贸然补一个容易变成编造内容）。
- **MySQL 数据库不可用**：这份第三方 bundle 有几处功能依赖 MySQL
  （`obj/handlers/map.lpc` 的 NPC 走路寻路会调用
  `db_exec()`，`net/daemon/mysql.lpc`，`bin/mysql_handler` 等）。本
  环境没有装 MySQL/MariaDB，`db_exec()` 会抛
  `Can't connect to local MySQL server...`。这是本项目里已经反复出
  现过的已知环境限制（`nitan170911` 等 lib 的 NOTES.md 也记录过同
  款问题），不在本次转换范围内解决。实测这个错误只发生在 NPC 自主
  走路寻路时（被 catch 兜住，不影响任何一个真人玩家的核心指令），
  没有观察到它阻塞注册/`look`/`score`/`quit` 核心验证路径。
- **部分 `/save/` 子路径缺少专属 ACL 授权**：`secure/master.o` 的
  `permissions` mapping 对 `/save` 只有笼统的
  `(["Room":3,"all":8,])`（`8` = `LOCK_MASK`，对未被更具体规则覆盖
  的子路径相当于"默认拒绝"），`/save/handlers/error_handler.o`、
  `/save/inv_check.o` 这类路径没有更具体的授权规则，导致
  `error_handler.lpc`/`inv_check.lpc` 的 `restore_object()` 在
  `create()` 里报 `read permission denied`（被 `unguarded()`/
  `apply_unguarded()` 的 catch 兜住，只在 `log/catch`、`log/runtime`
  留痕，不影响任何一次实测的注册/登录/核心指令）。真实原因大概率
  是这份重打包档案的 `secure/master.o` 存档数据本身就不完整（对照
  下面 board 备份目录缺失的情况，怀疑是原站点部署时这些精细授权规
  则是在运行中动态积累的，而不是随源码一起分发的）。未做修复，因
  为这需要判断"这个具体路径本该授权给哪个 euid"，属于内容/部署配
  置层面的猜测，不属于驱动兼容性 bug。
- **`/save/board_backups/` 目录缺失**：`board_handler.lpc` 定期把
  `save/boards.o.gz` 备份到这个目录，目录不存在导致
  `Error copying file ... No such file or directory`，纯日志噪音，
  不影响留言板本身的读写。

## 验证记录

- `lpcc_check.sh` 未使用（主库规模大、含大量非 `.lpc` 数据/资源文
  件，参照 AGENTS.md §10.4"开机 + 交互测试就是充分验证门槛"的惯
  例，直接以真实驱动开机+多轮交互验证为准）。
- 真实驱动开机日志：0 条编译 `error:`，只有少量`Unused local
  variable`/`Number of arguments...disagrees`一类无害警告。
- 完整走过两次真实注册流程（`fluffos` 和 `wombletest`，含 30 秒服
  务端强制等待的条款确认环节），每次都在 `debug.log` 全程干净的前
  提下进入真实游戏世界（著名的 Discworld 圆形大厅），`look`（含由
  游戏自动触发的首次 `look`）、`score`、`quit` 均产出正确输出；用
  已有存档验证过一次重新登录（restore 路径），退出流程干净（"Do
  come again!" + 服务端主动断开）。
- 管理员账号 `fluffos` 已验证：注册成功、重新登录后可见巫师专属横
  幅、执行 wizard 级重编译指令 `compile` 时通过了 ACL 检查（卡在无
  关的 `generate_source()` 缺失上，见上文）。

## WASM

本 session 未做 WASM 通道测试——`~/src/fluffos/build-wasm/src/driver.js`
在本次工作期间尚未构建完成（另一个并发 session 正在构建这个共享产
物），且这个 native pass 本身已经是相当大的工作量。`meta.json` 的
`wasm_status` 标记为 `pending`，留给下一轮。

## 本 session 的一个失误（如实记录）

排查驱动进程时先后两次误用了匹配范围过宽的 kill：一次是用精确 PID
`kill` 时没有先核实该 PID 属于哪个工作目录，误杀了另一个并发 session
（`libs/ds386`）正在运行的驱动；另一次是用 `pkill -f "driver
config.fluffos"` 排查端口占用，这个文件名是全项目几乎所有 lib 共用
的约定命名，极可能同时误杀了当时并发运行的 `nightmare3`/`lima`
两个 lib 的驱动进程（进程列表在那次 kill 前后确认消失）。两次都不
是数据/文件层面的损坏，只是让对应 session 的驱动测试被迫中断重启；
已按项目惯例（“Kill drivers by exact PID / never pkill -f”）改回精
确 PID 方式，后续操作未再复发。
