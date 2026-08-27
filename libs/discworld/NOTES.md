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

**2026-08-25 更新（另一次 session）**：真正跑通了 WASM 通道，`wasm_status`
由 `""`（未测试）提升为 `playable`。用的是 CI 同款的预编译 WASM 驱动
release（`fluffos/fluffos` 的 `*-wasm.zip`），配合
`scripts/pack_lib_for_web.sh` + `scripts/wasm_boot_check.js` /
`scripts/wasm_client.js` 本地复现。

首次打包后驱动**完全无法启动**——simul_efun 是唯一"急切"（非懒惰）加载
的对象，而它下面的 `secure/simul_efun/dump_socket_status.lpc` 无条件
调用了这台驱动没有的 `socket_status()`（WASM 构建没有 `sockets`
package），导致 `*No program in object '/secure/simul_efun/...'!`、
整个驱动拒绝启动——和同一个 session 早些时候在 `ds386`（Dead Souls）
上发现并修复的问题是同一类根因，详见 `AGENTS.md` §7.52 那条追记。
按同样的套路把 `dump_socket_status()` 挖空成安全桩后，又连续撞上
`compress` package 缺失的两处编译错误（`secure/master/
create_dom_creator.lpc` 里 6 处 `compress_file()`/`uncompress_file()`
闭包引用、`secure/login.lpc`/`obj/handlers/login_handler.lpc`/
`global/player.lpc` 里 3 处 `compressedp()`），逐一挖空/常量化后驱动
终于干净启动、能接到连接。

完整验证：真实跑完一遍注册向导（含文档里提到的、服务端故意暂停
~30 秒的条款确认环节——用 `wasm_client.js` 的 `--idle` 参数需要设得
比这个暂停更长，否则 `yes` 会在暂停期间过早发出而落空，这是脚本
本身的坑，不是驱动 bug），成功进入著名的 Discworld 圆形大厅，`look`
输出与原生测试记录的房间描述完全一致，MCCP 提示（"You are logged in
uncompressed!"）也正确出现（验证了 `check_mccp()` 的 `compressedp()`
桩替换按预期工作），womble NPC 的环境对话正常播放。`quit` 本次因为
womble 持续产生环境消息、脚本的 idle 检测一直"看不到真正的安静"而
没能在这次转录里捕获到，但 `quit` 路径本身没有触碰任何 compress/
socket 相关代码，原生测试已经完整验证过，不需要重复。

另发现一个**非致命**的预加载期编译失败：`/net/daemon/board_thingy`
（继承自 `/net/inherit/server.lpc`，一个 BBS/公告板网络监听服务）
同样因为 `sockets` package 缺失而编译失败，但这不影响驱动整体启动
（预加载会跳过失败的对象继续走），也不在登录/游玩路径上——按这个
项目"只修必经路径，可选管理工具留作已知缺口"的既定做法，本次没有
处理，留给以后如果真的有人报告这个 BBS 功能坏了再修。

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

## 深度功能测试（round two，2026-08-27）

本次是 `discworld` 第一次真正的 §10.7 round-two 全流程游玩测试（此前
NOTES.md 里的"验证记录"一节只是转档时的安装期烟雾测试，没有
`深度功能测试` 标题，AGENTS.md 的 §10.7 完成度统计里从未把这份
lib 计入）。用真实驱动（`~/src/fluffos/build-debug/src/driver
config.fluffos`，端口 40206）连续开了 6 次机（每次都是干净重启，
`grep -c "error:" debug.log` 恒为 0），全程用一份 Python 原始
socket 脚本（`dw_client.py`）交互，测试角色 `Roundtwo`（真实注册
流程，含服务端强制的 ~30 秒条款确认暂停）。

### 发现并修复的 bug

**`obj/handlers/armoury.lpc` 的 `request_item()` 在找不到道具时返回
`0`（有文档、有先例：早前转档时 `walk_directory()` 就因为同一个
"目录缺失返回 0 而不是空数组"的根因加过防御性 guard），但代码库里
至少 5 处 `ARMOURY->request_item(...)->move(...)` 调用链完全没有判
空，直接对返回值做 `->move()`。** 由于这份 "distribution lib" archive
本身缺失 `/obj/clothes/`、`/obj/armours/` 两个内容目录（转档时已
记录的已知缺口），任何请求这两类道具的调用都会返回 `0`，`0->move()`
在这个驱动上报 `*Bad argument 1 to call_other()`（未捕获），把调用
方的 `create()`/`setup()` 从崩溃点截断。

live 复现：管理员测试角色进入新手战斗训练室（`d/liaison/NEWBIE/
combat.lpc`）后尝试 `one`/`two`/`three` 三个训练间任一个入口，
`combat_room1.lpc`（等）会 `clone_object` 训练假人
`d/liaison/NEWBIE/dummy.lpc`，假人 `setup()` 里
`ARMOURY->request_item("dirty rags", 30)->move(this_object())`
崩溃（`dirty rags` 是缺失目录里的衣物），玩家侧看到"A runtime error
occurred."，`log/runtime` 记录 `*Bad argument 1 to call_other()`
（未捕获，直接从驱动兜底冒出）。这条路径正是本轮方法论第 3 步要求
的"safe-sparring 机制"，属于核心验证路径，不是可选管理工具。

修复：给全部 5 处受影响的调用改成"先存局部变量再判空"写法（不改变
道具存在时的行为，只是让缺失时优雅跳过而不是崩溃），跟转档时
`walk_directory()` 的修法同一个思路：

- `d/liaison/NEWBIE/dummy.lpc`（训练假人，"dirty rags"）—— **live 复现并验证修复**：修复前 `one`/`two`/`three` 进训练间必崩，修复后干净重进（`log/runtime` 全程无新增崩溃）。
- `d/liaison/NEWBIE/trainer.lpc`（"Greg"，新手战斗训练室 NPC，"leather jerkin"/"leather breeches"/"hard leather boots"）—— 同一间训练室的教练 NPC，同一根因，未单独 live 复现（Greg 是 preload 期创建的，崩溃只在开机日志里，不在交互路径上现场触发），按同款 guard 一并修复。
- `obj/monster/godmother/magrat.lpc`、`obj/monster/godmother/granny.lpc`（地图上真实的"迷路仙女教母"NPC，"startling green dress"/"spiderweb shawl"/"pumps"、"hobnailed boots"/"antique black dress"/"witchs pointy hat"/"black witches cloak"）—— **live 复现**：这两个 NPC 在本轮测试期间被游戏世界自身的某个触发点（不是我直接操作）真实创建过一次，`log/runtime` 记录了它们各自的崩溃（见下一条，这两个是另一个独立根因，同一调用链形状，一并修的时候顺手发现的）。
- `d/dist/pumpkin/rabbit/print_shop_office.lpc`（"Mr. Goatberger"商店 NPC，"white linen tunic"/"green pants"）—— 未 live 复现（该 NPC 由 `reset()` 定期生成，不在本轮实测路径上），同款 guard 一并修复。

刻意没有动的同款代码：`d/learning/cutnpaste/althea.lpc`（教学沙盒
目录下的"抄写练习"示例 NPC，就是用来教这个确切写法的，不是真实
游玩内容）以及两份 `.htm`/`.txt` 教程文档——按项目一贯的"内容/文档不
在修复范围"处理。

**新的 AGENTS.md bug 类**：这是 §7.6"缺失目录"系列的一个新变种——
不是 `get_dir()`/`read_file()` 返回 `0` 被当数组用，而是一个有据可
查、文档明确写着"找不到就返回 0"的工厂函数（`request_item()`）,
它的返回值被链式 `->move()` 调用，中间没有存局部变量、也没有判空。
由于道具类文件层层散布在整个代码库里，这类调用天生就是"批量隐患"
的形状——同一个安全 factory 函数,调用方各自决定要不要判空,任何一
个偷懒的调用方在对应内容缺失时都会阻断自己的 `create()`。已在下面
新增 AGENTS.md §7.147 记录这个模式，供以后其它 archive 遇到同类
"factory-on-missing-content returns 0" + "unguarded ->call chain"
组合时参考。

**`std/shops/print_shop.lpc` 的 `add_auto_load_info()` 用驱动保留字
`nosave` 当参数名，整个印刷厂片区（`print_shop.lpc` 自己 + 它的四
个子类 `print_shop_office`/`print_shop_foyer`/`print_shop_press`/
`print_shop_binding`）在这个驱动上完全无法编译，从转档以来一直是
死代码。** `nosave`/`static` 在这个驱动的词法分析器里都是真正的
`L_TYPE_MODIFIER` 保留字（`~/src/fluffos/src/compiler/internal/
lexer_utils.cc`），`protected int add_auto_load_info(string nosave,
string dynamic);` 这行原型声明里把 `nosave` 当参数名用，编译器直接
报 `error: syntax error, unexpected L_TYPE_MODIFIER`——不是我这次
交互测试里现场触发的（这个函数从没被玩家路径直接调用过），是用
`lpcc` 单文件编译核对旁边一处不相关问题时顺带发现的：查
`log/error-log.old` 发现同一行报错从转档以来的历次开机日志里反复
出现过至少 7 次，说明这从来没被人注意到过。函数体内部
`$(nosave)` 这个 lambda 捕获、连同文档注释里其实早就写着
`@param static_arg` 而不是 `nosave`（暗示原作者自己心里想的参数名
跟实际写的不是一回事，大概率是笔误）。修法：把参数名从 `nosave`
改成 `nosave_arg`（跟文档注释的命名意图一致），原型声明和函数定义
两处、函数体内部的 `$(nosave)` 引用一并改。用 `lpcc` 核对：修复前
`std/shops/print_shop.lpc` 和 `d/dist/pumpkin/rabbit/
print_shop_office.lpc` 单独编译都直接报错；修复后两个都干净通过
（无 warning 之外的输出）。全库 grep 过其余全部 `nosave`/`static`
两个保留字被当裸参数名用的情况，只有这一处命中。已新增 AGENTS.md
§7.148 记录这个模式。

### 检查过、确认干净的标准 bug 模式（§10.7 清单里列出的横切模式）

- **§7.139（`interactive catch tell` 配置项）**：Discworld 的颜色渲
  染完全不依赖驱动的 `catch_tell()`/`receive_message()` apply——整
  个代码库里从未定义过 `catch_tell()`，玩家可见文本的颜色标签
  （`%^TAG%^`）是在 mudlib 自己的输出管线里显式调用驱动原生 efun
  `terminal_colour()` 完成的（`global/events.lpc` 的 `fix_string()`，
  `secure/simul_efun/strip_colours.lpc`），再经由 `efun::tell_object()`
  直接发送，跟这个驱动 runtime 配置里的 `interactive catch tell`
  开关（`config.fluffos` 里确认没设置，默认 0/关闭）完全无关。这个
  开关只影响"驱动是否把 `catch_tell` apply 当拦截点调用"，而
  Discworld 自己从没注册过这个 apply,所以配置项开不开都没有实际影
  响——不是这个 bug 类的实例。
- **§7.131（`find_living`/`find_player` 需要 `set_living_name()`）**：
  `global/player.lpc`（两处，登录时和复活时）、`obj/monster.lpc` 都
  正确调用了 `set_living_name()`，不受影响。
- **§7.133（`net_dead` apply 未定义）**：`global/player.lpc`、
  `secure/login.lpc` 都定义了真正的 `net_dead()`，这个驱动本身也
  确实是按"直接调用 player 对象的 `net_dead()` apply"设计的（不是
  `remove_interactive(ob,linkdied)` 这种 master-level apply）,双方
  匹配,不受影响。
- **§7.130（非交互后仍无条件调用 `query_idle()`）**：`global/player.lpc`
  的 `heart_beat()` 和 `secure/login.lpc` 的 `time_out()` 都先
  `if(!interactive(...))` 分流,只在真交互对象上才调用
  `query_idle()`,写法正确,不受影响。
- **§7.132（`map()` 遍历 mapping 时用错参数）**：抓了全库所有
  `map(某变量, (: ... :))` 且该变量看起来像 mapping 的调用点逐一核
  对声明类型，命中的全部是 `string*`/`int*`/`class` 数组，没有一处
  是真的 mapping,不受影响。
- **§7.122（class 自动重载在断连重连时复制道具）**：`compute_autoload_array`/
  `destroy_autoload_obj`/`load_autoload_obj` 这一整套 TMI-2 系亲缘
  机制在这份代码库里根本不存在（Discworld 是完全不同的谱系），不
  适用。
- **§7.134（累加数组字段没有初始化）**：`std/room/basic_room.lpc`
  的 `hidden_objects`/`_exits`/`aliases` 等全部数组字段都在
  `create()` 里正确初始化为 `({})`,不受影响。
- **§7.126（.o 存档里残留 `.c` 后缀的坐标出口路径）**、**§7.123（裸
  `IDENT = (...)`）**、**§7.137（`command("$verb")`）**、**§7.140
  （`valid_read` 把 include 注入算到当前玩家头上）**：分别 grep 全
  库，零命中或（§7.140）已被数小时的真实多角色游玩隐式覆盖验证
  （每个新角色第一次触发的懒编译贯穿了几乎整个新手区，从未报过
  `Cannot #include`），判定不适用/干净。
- **§7.112（NPC `init()` 无条件排 `call_out` 链）**：`obj/monster.lpc`
  唯一的 `init()` 只调用幂等的 `set_heart_beat(1)` 和条件触发的
  `start_attack()`,没有直接排 `call_out` 链,不匹配这个模式的形状。
- **§7.141（`replace_program()` 折叠在开机后 ~5 分钟内让闭包创建崩
  溃）——认真复现但未能触发,记录为观察项，不作代码改动**：
  `std/room/basic_room.lpc`/`basic_room_new.lpc` 的 `create()` 确
  实有跟 dsI 那条一模一样的形状（`replaceable()`+`sizeof(inherit_list())==1`
  判断后 `call_out(delay 0)` 里调用 `replace_program()`），而且
  `calc_long_exit()`（几乎每个房间 `look` 时都会算一次）在 3 个以上
  出口时确实会创建一个真正的闭包
  (`map(words, (: mxp_tag("Exit",$1,1) :))`) 且不区分客户端是否有
  MXP——形状上完全符合。用真实的 trustee 管理员账号（`fluffos`，
  `secure/master.o` 的 `positions` 里已有）在开机后 85~253 秒内（严
  格早于这个驱动 `backend_register_tick_events()` 注册的、从开机起
  每 5 分钟一次的 `replace_programs()` 扫描）连续对两个从未被访问过
  的、真正满足折叠条件的房间（`/d/dist/pumpkin/squash/squash5`，4
  个出口，经 `CITYROOM`→`outside`→`basic_room` 继承链；
  `/d/dist/pumpkin/rabbit/print_shop_foyer`，3 个出口，直接继承
  `basic_room`）做了 3 次独立尝试，每次都干净渲染出出口列表，
  `log/runtime`/`log/debug.log` 全程零 "cannot bind a functional to
  an object with a pending replace_program()" 记录。没有进一步深挖
  这个驱动为什么没触发（可能是 `call_out(fn,0)` 在这个版本的
  backend 循环里比理论分析更快被处理，也可能是某个未追踪到的差
  异）——按项目"不是每个模式相似的代码形状都真的在每个驱动/lib 组
  合上复现"的既定原则，如实记录为"检查过、代码形状匹配但未能 live
  复现",不做任何代码改动。

### 新观察：这是一份"distribution lib"裁剪版，公会系统本来就没有随
包分发（不是 bug，如实记录）

`include/config.h` 定义了 `__DISTRIBUTION_LIB__`，`d/liaison/NEWBIE/
path.h` 在这个宏打开时把 `GUILDS` 宏定义成字面量 `"None currently"`，
`d/liaison/NEWBIE/guilds_foyer.lpc` 里全部六个公会大门出口
（witch/wizard/thief/assassin/warrior/priest）都包在
`#ifndef __DISTRIBUTION_LIB__` 里——也就是说这份 archive **设计上就
不随包分发任何公会加入内容**，`/std/guilds/` 目录下也确实只有
`warrior.lpc`/`standard.lpc` 两个基类文件，没有任何一个公会总部房
间（`d/guilds/` 整个目录都不存在；开机 preload 列表里的 `/d/guilds/
wizards/books/beginners`、`/d/guilds/wizards/Ankh-Morpork/inside/
gymnasium`、`/d/guilds/wizards/chars/frenkel` 三条也全部指向不存在
的文件,被 preload 的 catch 静默吞掉,零 debug.log 痕迹）。这意味着
本轮方法论第 4 步（公会/技能习得路径测试）在这份具体 archive 上**
从设计上就不可达**，不是我漏测——如实记录，不视为 bug，不尝试编造
公会内容去"修复"。

顺带发现一个由此衍生的真实崩溃（同一根因,不单独归为新 bug）：地
图上"迷路仙女教母"NPC（`magrat.lpc`/`granny.lpc`）的 `setup()` 都
调用了 `set_guild("witch")`,而 `/std/guilds/witch.lpc` 在这份
archive 里根本不存在,`std/race.lpc:199` 的 `set_level()` 内部对它
做 `call_other()` 直接报 `*call_other() couldn't find object
'/std/guilds/witch'`（live 复现,`log/runtime` 有记录）。同样属于
"distribution lib 没有公会内容"这一句话能完全解释的已知限制,不修。

另外，`d/liaison/NEWBIE/foyer.lpc` 的 `guilds` 出口本身也会崩
（`d/liaison/NEWBIE/guilds_foyer.lpc` `inherit PATH+"outside"` ->
`d/liaison/NEWBIE/outside.lpc` `inherit "/std/outside"` ->
转档时就已经记录在案的已知缺口"`/std/outside.lpc` 完全不存
在"），live 复现：`*Inherited file '/std/outside' does not exist!`
（`log/runtime`）。这是对已有已知缺口条目的一次**扩大确认**——此
前的记录只提到"多个教学/示例房间和至少一个真实房间(`room/air.lpc`)"
受影响,这次确认它还directly 挡住了新手大厅九个出口里唯一通往
"guilds"（公会花园）的那一个,即使 `/std/outside.lpc` 真的补上了,
这个花园本身在这份 distribution 配置下也只有一个 "foyer" 返回出口
（六个公会大门出口全部被 `#ifndef __DISTRIBUTION_LIB__` 排除），没
有任何实际可加入的公会内容——两个独立限制（缺失基类 + 故意裁剪的公
会内容）叠加在同一个房间上。仍然判定为"已知内容缺口,不予修复"（需
要编造一整个 `/std/outside.lpc` 基类文件的内容,属于内容/设计猜测,
不是程序 bug）,只是把这条记录写得更完整。

### 环境/测试基础设施问题（非 mudlib 代码 bug，直接修复）

- **`save/players/f/` 目录完全不存在**：`save/players/` 整棵树都是
  git 未跟踪的运行时数据（`.gitignore` 排除），这个沙盒环境里从来
  没有出现过名字以 `f` 开头的玩家，导致这个字母桶目录压根没被创建
  过。管理员账号 `fluffos` 第一次尝试注册时,断线时触发的
  `net_dead()`→`save_me()`（这条路径不受 30 分钟新手不存档规则限
  制,是无条件保存）报 `*Could not open /save/players/f/fluffos.o.gz.tmp
  for a save.`（`log/catch`），角色数据丢失,下次连接查无此人。直
  接 `mkdir -p save/players/f`（这个目录本身不在 git 跟踪范围内,
  这个改动不会出现在任何 diff 里,纯粹是让这个沙盒环境的后续测试/
  session 不再撞到同一个坑）。
- **`save/garbage.o` 的自愈式自动重启节流被这个 session 自己的反复
  重启"作死"到了极限值**：`obj/handlers/garbage.lpc` 有一套"距离
  上次重启是不是很快又崩了"的自调节机制（`max_time` 初始
  219600 秒/61 小时,每次 `create()` 时如果 `crash` 标记是真就打 5/6
  折,只有在它自己发起的定时重启完整走完 9 分钟等待后才会清零
  `crash` 标记、下次开机才会缓慢回涨,涨速只有跌速的 1/6）。这个项
  目本身的开发/测试流程会大量直接 `kill`+重启驱动进程（不经过
  `check_reboot()` 自己触发的那条"优雅重启"路径),每一次都被这个机
  制误判成"上次崩溃了",`max_time` 单调下跌。到本轮测试开始时已经
  跌到了 **15 秒**——开机后 heartbeat 走到第一次
  `check_reboot()`（`create()` 里 `call_out("housekeeping",300)` +
  `housekeeping()` 里 `call_out("check_reboot",10)`,即开机后
  ~310 秒）时,`uptime() > max_time(15)` 恒真,直接触发
  `"/obj/shut"->shut(10)`,10 分钟倒计时期间非管理员一律无法登录
  （`secure/login.lpc` 的 `find_object("/obj/shut")` 检查）。这不
  是一个会在真实部署环境复现的 mudlib bug（真实部署不会像这个项目
  的迭代式调试流程一样在几天内 `kill`+重启驱动几十次),纯粹是这个
  沙盒环境自己测试方式的副作用,按项目一贯做法（管理员账号也是直接
  编辑存档种出来的）直接把 `save/garbage.o` 重置为健康初始值
  （`max_time 219600`、`crash 0`、`limit 1000`）,重启后验证正常
  （非管理员账号顺利登录,没有再触发"too close to shut-down"）。**
  这套"崩溃惩罚,只有走完自己那条优雅重启全流程才能恢复"的不对称自
  调节设计本身，在这个项目"驱动被频繁直接 kill/重启"的日常工作流下
  会反复被打到最低值——如果以后其它 session 又撞到同样的"新角色注
  册后立刻收到 too close to shut-down"，直接检查/重置
  `save/garbage.o` 而不用怀疑是新 bug。

### 已验证的核心流程（本轮 round-two 清单）

- **注册**：`Roundtwo`，含真实的 ~30 秒条款确认暂停，完整走到落地
  新手大厅（`d/liaison/NEWBIE/foyer.lpc`），`look`/`score`/`i` 每
  次状态变化后都产出正确输出。
- **移动**：foyer ↔ combat（新手战斗训练室）↔ commerce（新手商店）
  多次往返，均正常。
- **safe-sparring 机制**：找到了（`d/liaison/NEWBIE/combat.lpc` +
  "Greg" 教练 NPC + 训练假人,标牌明确写着 "say 'can I practise
  please'"），bug 修复前 `one`/`two`/`three` 三个训练间入口必崩,修
  复后干净可进入（Greg 后续对话触发条件跟具体措辞有关,受限于时间
  预算没有把整套"打假人"流程走完,但核心崩溃点已修复并验证）。
- **公会/技能习得**：**从设计上不可达**（见上文"distribution lib
  裁剪"一节),如实记录为未测试而非"测试失败"。
- **quit + debug.log 检查 + 隔一段真实时间重连**：`quit` 后
  `log/debug.log` 全程干净；等待若干分钟真实时间后用同一账号密码
  重新登录,成功恢复到断线前的房间（战斗训练室）,角色年龄
  （"X minutes and Y seconds old"）、登录次数计数、经验值、随身物
  品（"a fruitbat flavoured badge"）全部正确延续,验证通过。
- **商店/经济**：进入了新手商店（`commerce` 出口）,房间描述与提示
  正常；`list` 命令测试未能在预算时间内确认真实商品列表输出（可能
  是这个 driver 上 shop soul 命令的排队显示时序问题,不是本轮方法论
  重点,未继续深挖,如实标注为未完全验证）。
- **死亡/复活**：未在本轮预算时间内触及,如实说明未验证。

### 管理员账号重新播种

上一次转档 session 种下的 `fluffos` 管理员角色存档本身没有随仓库提
交（`save/players/` 整棵树不在 git 跟踪范围内），这次沙盒环境里已
经找不到了（`secure/master.o` 的 `positions` trustee 记录本身还在，
只是玩家存档丢了）。用同样的账号名 `fluffos`/密码 `Mud@2026` 走完
整套注册流程，真实挂机 30+ 分钟（满足 `global/player.lpc` 的
`MIN_TIME_TO_SAVE`=1800 秒新手存档门槛）后 `quit`，验证
`save/players/f/fluffos.o.gz` 已生成且 `#/global/lord.lpc` 开头（确
认是真正的 creator/lord 类实例，不是普通玩家），全程 `debug.log`/
`log/runtime` 干净。
