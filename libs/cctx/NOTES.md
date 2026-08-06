
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2/XKX 血统代码库（襄阳关/嘉峪关场景内容）。完整 WASM 修复：（1）过时的 SIMUL_EFUN_OB 和 MASTER_OB 宏都指向了未被使用的 /adm/single/{master,simul_efun}.lpc 死代码副本，而 config.fluffos 实际使用的 master/simul_efun 文件是 /adm/obj/{master,simul_efun}.lpc（真正的 simul_efun.lpc 带有旧版本缺少的 destruct()/remove() 覆写，和 §7.58 类的 bug 是同一类，在它搞坏 quit 之前就被排查出来了）；（2）adm/daemons/httpd.lpc（纯 HTTP 服务器，无条件调用 socket_*）按 §7.52 的整文件入口点掏空模式处理掉了。排版格式化工具的第三类盲点检查（CJK 重新加空格）在约 40 个"误报"（原文本来就有的装饰性房间名/诗词间距）里抓到了一处真正的损坏：d/huashan/map.lpc（一张密集的 ASCII 地图）——已直接还原，没有手工修补。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。

## 深度功能测试（第二轮，2026-08-03）

此前的验证只做到浅层冒烟测试。本轮启动前先主动检查了本次会话已经
反复确认过的 `private command_hook` 模式，提前修复了一处；随后完整
走通了注册流程，过程中又发现并修复了两个真实 bug：一处是本会话已
经在别的档案上见过的经典"调试信息泄漏"，另一处是全新发现、已经写
进 AGENTS.md §8.9 的一类新 bug——多物件函式里读错了物件。

### 主动排查发现并修复：`feature/command.lpc` 的 `private command_hook`

和本次会话在 `hell`/`jym` 上已经修过的同一个 AGENTS.md §8.3a 模式：
`inherit/char/char.lpc` 通过 `F_COMMAND` 继承的 `feature/command.lpc`
把 `command_hook` 声明成 `private nomask`，在这个驱动上继承后会降
级为 `DECL_HIDDEN`，导致对 `ORIGIN_EFUN`（NPC 自己用 `command()`
efun 说话）的分发静默失效。启动前 grep 直接命中，已去掉 `private`，
保留 `nomask`。

### 注册流程中发现并修复：`get_name()` 里一行调试用的 `printf("%O", ob)`

`adm/daemons/logind.lpc` 的 `get_name()` 在校验完中文名字之后有一行
`printf("%O\n", ob);`——这是 AGENTS.md §7.34 已经收录的经典模式（
`esI`/`xianlvqiyuan` 都出现过同一类问题）：原作者调试用的物件路径
打印，从未清理就随档案一起流通了出去。实测复现：注册时"您的中文名
字："提示之后，紧接着会看到一行 `/clone/user/login#1`（登录物件自
己的内部路径），然后才是"请设定您的密码："提示——每一个新玩家注册
时都会看到这行内部实现细节。已直接删除这一行，属于 AGENTS.md §7.34
明确记载的"删掉即可，从不服务于任何玩家可见目的"的一类修复，已列入
该条目"确认实例"名单。

### 注册流程中发现并修复：食物/饮水初始化门槛读错了物件（新增 AGENTS.md §8.9）

`adm/daemons/logind.lpc` 的 `enter_world()`（`exec(user, ob)` 之后
的角色进世界流程）里，食物/饮水一次性初始化的判断条件是
`!user->query("food") && !user->query("water") && ob->query("age")
== 14`——链条里前两个条件读的都是 `user`（刚创建的玩家身体物件），
唯独最后一个读的是 `ob`（临时的登录连线物件）。`clone/user/user.lpc`
的 `update_age()`（由 `setup()` 调用，在这个判断之前就已经执行过）
确实会把 `user` 自己的 age 设成 14，但**整个代码库里没有任何地方给
`ob` 这个物件设置过 age**（已通过对全代码库 `set("age"` 逐一核对确
认——所有命中都落在 `user`/NPC 类别上，登录物件类完全没有）。
`ob->query("age")` 因此永远回传驱动默认值 0，判断条件永远为假，
`max_food_capacity()`/`max_water_capacity()` 从未真正套用到任何一
个新角色身上——**每一个全新玩家一进游戏世界食物和饮水槽都是空的**，
第一次 `look`/`score` 就会触发"你饿得直冒金星，实在是顶不住了"的
挨饿提示。已把 `ob->query("age")` 改成 `user->query("age")`，和判断
链条里其它条件保持对象一致。修复前后各注册一个全新角色对照验证：
修复前 `score` 的食物/饮水槽全空，伴随挨饿提示；修复后两条槽全满，
没有挨饿提示。

### 完整验证：从注册到探索

用全新账号在原生驱动上完整走通：英文 id（3-12 个英文字母）→ y 确认
→ 中文名字（无泄漏问题）→ 密码 + 确认 → 天赋确认（y/n）→ 电子邮件
→ 性别 → 进入"欢迎光临驰骋天下"的欢迎室，食物/饮水槽全满（如上）。
`e` 移动到下一个房间，"接客童子"NPC 主动搭话，介绍 eat/drink/get/
buy/sell/sleep 等基本生存指令，并主动提示"如果你没有盘缠的话，可以
问我要"——是一整条 `command()`-efun 驱动的 NPC 对话链路，间接印证
了 `command_hook` 修复的必要性。断线后用同一账号重新登录，"重新连
线完毕"，直接回到游戏内状态，移动/NPC 对话依然正常。`quit` 干净退
出（丢下一件不值钱的布衣，"欢迎下次再来！"）。debug.log 只有驱动启
动期的诊断噪音（找不到旧版二进制路径、反向地址解析被拒绝），没有
来自本次实际游玩会话的运行时错误。

### 未覆盖范围（诚实说明）

预算集中在验证三处修复和基础移动/NPC 对话链路，没有走到：门派拜师、
战斗系统、经济系统（buy/sell/盘缠）。这些留给下一轮，目前的验证边
界如上所述。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`W_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 33 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
