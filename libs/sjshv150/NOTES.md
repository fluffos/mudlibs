
## WASM 修复摘要（迁移自 meta.json 的 group_note）

三界神话「紫藤分站」，5 档案 sjsh 家族集群的第二个；和 sjsh（宝鸡站）子分支内容不同（紫藤 vs 宝鸡）但共享同一套核心代码库。WASM 修复：（1）§7.60 master.lpc log_error()/standard_trace()→CHANNEL_D 编译期崩溃，两处都用 find_object(CHANNEL_D) 守卫——这里有这个 bug，不像 sjsh 那份具体变体没有。（2）和 sjsh 一样的 45 行损坏字节 convertd.lpc 表，用完全相同的字节级脚本修复。（3）§7.61 message() simul_efun 包装函式缺少 exclude||({}) 守卫——channeld.lpc 的 do_channel()（以及其它 3 参数呼叫 message() 的地方）在修好（1）之后、CHANNEL_D 真的成功加载时崩溃报"Bad argument 4 to EFUN message()"；这正是 AGENTS.md §7.61 已经记载的那个 channeld.lpc 呼叫点。（4）§7.41 类损坏的 emoted.o，和 sjsh 相同的 catch(restore()) 修法。（5）§8.1 类的 is_chinese() 字节区间 bug，加上一种没减半长度界限类的不寻常表现：check_legal_name() 用 i%2 作为奇偶门槛，假设每个中文字占 2 字节 GBK，而这个驱动下 UTF8 码点索引的字符串里每个中文字占 3 字节，导致字数为奇数的 CJK 名字永远被拒绝（i%2 恒真），偶数字数则碰巧能通过——已修好 is_chinese()（码点区间检查）和 check_legal_name() 的界限（1-6 字符，匹配提示文字，去掉 i%2 门槛）。（6）一个仅限巫师的本地回环注册闸门（adm/daemons/sited.lpc 的 is_valid()，和 sje 的形状相同）连字面的"new"注册关键字都会挡在 127.0.0.1 之外，因为 wiz_level('new') 永远不为真——已专门为"new"加了例外（和这份档案自己既有的"allenc"引导例外并列），符合既定的 §1.3e 本地测试摩擦豁免类；真正全新的（未在 wizlist 里的）玩家 id 仍然无法从 WASM/本地环境注册，这是一个真实但范围很窄的测试限制，没有进一步处理，因为真实的远程部署不受影响（非本地 IP 永远不会走到这个回环分支）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist——这个账号同时绕过了回环 id 闸门（已经是巫师）和双密码（管理+普通）注册流程里的第二次 is_valid() 复查。已验证：完整注册（new→id→名字→管理密码→确认→普通密码→确认→电子邮件→性别→赠礼）→进入游戏世界，权限正确显示 (admin)；default_trusted_write/default_exclude_write ACL 表也已直接核对源码确认授予 (admin) 不受限的"/"写入权限。LPC 格式化工具对全部 10310 个档案运行；还原了 2 个通过"去空格后比对旧档案"扫描（覆盖 113 个格式化工具触碰过的档案）确认有 CJK 重新加空格损坏的档案（和 sjsh 相同的 2 个档案，共享内容）；另外直接比对了唯一一个 map.lpc 档案——干净，只是排版调整。格式化后重新验证过，干净。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 45 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

用原生驱动（`build-debug/src/driver`，端口 40171）通过 `scripts/tmux_mud.sh` 和 `scripts/mudclient.py` 走完整轮，对照同家族已深挖的 `sjsh`（宝鸡站）NOTES.md 逐条核对。

- **§7.97（sjsh 上发现的 LISTNODES 死亡死循环 bug）——不适用，已核实排除**：`work/include/net/config.h` 第 19 行 `#define LISTNODES ([ \` 本身就带着正确的续行反斜杠（`cat -A` 确认行尾是 `\$`，不是裸 `$`），跟 sjsh 那份缺失反斜杠的版本形状不同——这两份档案虽然共享核心代码库，但这个头文件的具体内容不是逐字节同源（`diff` 两份 `config.h` 显示是完全不同的文件版本：sjshv150 是"神话世界·西游记·版本４．５０"版本头，LISTNODES 表项也不同：`SJSH-DBSZ`/`SJSH_SK`/`SJSH_JYG`/`SJSH_SD`，而 sjsh 是 `SK`/`BJ`/`SD`）。为求实证而非只信静态分析，仍然用管理员测试角色在朱雀大街对 `疥顶小僧`（`d/city/npc/jieding.lpc`）打 `kill` 到真实死亡：屏幕只打印一次"你死了"，系统频道正常广播"〖谣言传说〗某人：测试道人在长安城被疥顶小僧杀死了。"，角色被送进〖阴阳界〗（`/d/death/gate`），判官崔珏（`朱笔判官 崔珏`）自动完整走完"莫乱跑→生死有命→翻生死簿→命不该死送还阳"对话，角色活着落地复活室〖荒郊小店〗（`/d/ourhome/kedian`，`气血：重伤`，被杀害次数正确记为 1），全程 `debug.log` 干净无 `dns_master`/`gchannel` 崩溃痕迹。确认本档案没有这个 bug。

- **（新增 AGENTS.md §8.13）`adm/daemons/logind.lpc` 的 WIZ 密码二次登录闸门在从未设置过 WIZ 密码时没有成功路径，导致 wizlist 内任何账号第二次登录起永久卡死**：这是本次深挖发现的、比 §7.97 更容易被忽视的新 bug——它只在**重新登录**（restore 路径）时才会触发，注册后紧接着的第一段会话完全不会经过这段代码，而 AGENTS.md §10.1/§10.7 恰恰要求重新登录也要至少验证一次，正是靠着这条规则才抓到。`get_passwd()` 里，只要账号 id 在 `SECURITY_D->get_wizlist()` 里（不限于 admin，apprentice/wizard/arch 全部一样），就会额外要求输入"WIZ密码"（`input_to("get_wizpwd", 1, ob)`），但 `get_wizpwd()` 本身：
  ```lpc
  if (!user->query("wiz_password")) {
      write(HIW "你没有设定WIZ密码，请用WIZPWD来设定！\n" NOR);
  }
  if (user->query("wiz_password")) { ... }
  ```
  在从未设置过 `wiz_password`（注册流程完全不会设置它，只能靠登入后用游戏内 `WIZPWD` 指令手动设——这就是先有鸡还是先有蛋的死结）的情况下，第一个 `if` 打印提醒后**直接落空**——既不调用 `check_ok()` 进入游戏，也不重新 `input_to()`，函数就这样返回。玩家紧接着输入的任何东西（`look`）都落进了裸连接对象自己的通用失败回复，永远只会收到"什么？"，且 `debug.log` 完全没有任何记录（不是崩溃，是静默卡死）。用刚播种好的管理员测试账号 `fluffos` 实测复现：第一次注册会话一切正常（这条闸门根本没被走到）；`quit` 后用 `scripts/mudclient.py` 重新连线、走完 id+密码流程，看到"你没有设定WIZ密码，请用WIZPWD来设定！"提示后，`look`/`score` 全部只回"什么？"，永远进不了游戏世界。修复：把提醒分支改成非阻断——补上 `check_ok(user); return;`，和这份档案自己在**首次**登录成功后（`enter_world` 之后同样打印这条提醒但完全不阻断）的既有行为保持一致。重启驱动后重测：同样的重连流程打印相同提醒，随即正常进入游戏（落地〖巫师会议厅〗，因为 fluffos 已是巫师），`look`/`score`/`quit` 全部正常，此前死亡记录（被杀害 1 次、气血重伤）也正确保留，证明存档读取完全没问题，唯一坏掉的只是这道 WIZ 密码闸门本身。已更新 AGENTS.md，新增 §8.13。

- **§7.34（logind.lpc 遗留 debug printf）适用，已修**：`get_name()` 在 `ob->set("name", arg)` 之前有一行裸 `printf("%O\n", ob);`，会把登录对象内部路径（`/obj/user/login#0 ("0(fluffos)")`）原样打印在中文名字确认和密码提示之间——用 `fluffos` 账号首次注册时现场复现确认（修复前的截图证据）。已删除该行；修复后重启驱动，用 `sited.lpc` 里既有的 `allenc` 本地测试豁免账号重新走一遍完整注册流程（`new`→`allenc`→中文名字→两套密码→邮箱→性别→天赋→落地），全程 grep 确认没有任何 `login#`/`obj/user` 字样泄漏；测试用的 `allenc` 存档已在提交前删除（`data/login/a/allenc.o`、`data/user/a/allenc.o`，未纳入 git，直接 `rm`，不影响任何其它账号）。

- **§7.11（log_file 缺 assure_file 防护）适用，已修**：`adm/simul_efun/file.lpc` 的 `log_file()` 是裸 `seteuid(ROOT_UID); write_file(LOG_DIR + file, text);`，同一份档案里的 `assure_file()` 辅助函数从未被调用；`ls work/log/` 确认 `nosave/` 目录本档案确实没有随仓库分发（会被 `securityd.lpc::set_status()` 的 `log_file("nosave/promotion", ...)`、崩溃处理器的 `log_file("nosave/CRASHES", ...)` 等路径触发写入失败），和 sjsh 已记载的形状完全一致。修复：补一行前向声明 `void assure_file(string file);`（`log_file()` 在文本顺序上定义在 `assure_file()` 之前），并在 `write_file()` 前调用 `assure_file(LOG_DIR + file)`。防御性修复，本轮实际游玩没有直接触发这几条日志路径，但按既定套路"看到就修"。

- **§8.9（食物/饮水初始化）不适用**：`confirm_gift()` 直接 `user->set("food", user->max_food_capacity())`/`user->set("water", user->max_water_capacity())`，没有对象混用、没有年龄闸门。三个测试角色（`fluffos`/`allenc`）`score` 食物/饮水都是满格「正常」。

- **§7.88/§7.12（message() varargs 缺陷）不适用，此前一轮已修好**：`adm/simul_efun/message.lpc` 的 `message()` 已经是 `efun::message(arg, message, target, exclude || ({}))`（对应 group_note 里记载的 §7.61 修复），`tell_room()` 同样有 `exclude || ({})` 兜底；本轮死亡广播、频道消息等大量触发 `message()` 的路径全程零崩溃，确认修复依然有效。

- **§8.3a（`private nomask command_hook`）不适用**：`feature/command.lpc` 的 `command_hook()` 声明就是 `nomask int command_hook(string arg)`，没有 `private`。

- **§8.3b（`commandd.lpc` 的 `.c` 后缀 sscanf）不适用**：整个档案没有 `commandd.lpc` 这个文件，指令分派走 `feature/command.lpc` 的 `add_action` 机制。

- **§7.90（eval cost 上限）本次未观察到问题，`config.fluffos` 保持默认 `700000` 未改动**：跨越注册、天赋分配、多次移动到未编译过的房间、两轮真实战斗到死、两次完整复活流程、`post`/`read`/`update` 等操作，`work/log/debug.log` grep `cost limit reached`/`Too long evaluation` 均为 0。

- **§7.5（securd/securityd 自定义 ACL 拒绝编译期访问，含 file_size 和 get_dir 两个变体）不适用**：`adm/daemons/securityd.lpc` 的 `valid_read()` 已经显式 `if (func == "file_size") return 1;`；本轮完整跑过注册、战斗、死亡、复活、`post`、`update`（recompile）等触发大量首次编译/首次读取的路径，`work/log/debug.log`、`work/log/nosave/FILES`（未生成，说明零次 ACL 拒绝）均无任何 "access denied"/"read attempt...failed" 记录。`get_dir()` 用到的 `"stat"` func 也未见任何异常（指令表本身工作正常，`kill`/`look`/`post`/`update` 全部能正确分派）。

- **§7.98（daemon `create()` 缺 `seteuid()` 导致自身配置读取被拒）不适用**：全程 `debug.log` 没有出现任何 `explode()`/`sscanf()` 相关的 preload 期崩溃（sjshv150 启动日志本身也完全干净，无编译错误无运行时错误）。

- **管理员写权限已现场验证**：用 `fluffos` 账号执行 `update /d/city/kezhan`，输出"重新编译 /d/city/kezhan.lpc ...成功！"，确认 `securityd.lpc` 的 `default_trusted_write["/"] = (admin)` 确实生效。

- **留言板 `post`/`read` 验证通过，§7.86 修复线上确认有效**：在〖荒郊小店〗对"生死之间留言板"（`common_a.o`）成功 `post` 一条标题「深度测试」的留言并 `read 1` 读出，无崩溃；同一条内容还自动镜像进了〖巫师会议厅〗的留言板总汇（`post_b.o`，`board_id: "post_b"`，`std/misc/bboard.lpc` 的转发机制）。这两份留言板数据此前完全未随仓库分发（`git ls-files` 确认 `data/board/` 目录此前不存在于版本控制里，说明该档案在本次深挖之前从未真正 `post` 过），本次测试留言在提交前已直接 `rm` 两个测试产生的 `.o` 文件（不是清空历史内容——本档案确实没有 sjsh 那样的历史留言）。

- **未覆盖**：`buy`/商店购买流程本轮时间有限未测（`list` 指令本身也没顾上，架空于巫师会议厅的账号需要先走到普通城镇商店）；帮派/门派拜师流程未触及；`WIZPWD` 指令本身（用于设置本次发现要求非阻断的那个 WIZ 密码）未实测，只验证了"未设置时不再卡死"这一失败模式的修复，没有验证"设置后校验成功/失败"两条分支——这两条分支代码本身逻辑清晰（`crypt()` 比对），风险较低，留待下次深挖时一并验证。

管理员账号（`fluffos`/`Mud@2027`，管理密码 `Mud@2026`）本次通过正常注册流程首次真正落地——此前 `adm/etc/wizlist` 已有 `fluffos (admin)` 一行（更早阶段播种），但 `data/login/f/fluffos.o`、`data/user/f/fluffos.o` 此前并不存在，说明账号只播种了权限数据、从未真正注册过。本次完整走完双密码注册流程后立即显示"系统权限目前是：(admin)"；已更新 README 的"管理员账号"一节，把密码从"注册时自设"改为具体的 `Mud@2026`/`Mud@2027`（管理密码/普通密码不能相同，是这份档案自己的规则）。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/std/room/room"`（嵌套路径，不要与其它以 `/std/room`
为宏值的手足档案混淆）：删除 515 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），509 处脚本自动
删除；另有 6 处手动修正——`obj/roommaker.lpc`（1 处，标准"两套模
板"简单变体，字符串拼接模板第 139 行）；此外，脚本的 `data/` 目录
排除逻辑（用于保护玩家存档）意外漏掉了本库真实存放在
`work/data/group/obj/` 下的两份帮派管理命令源码——`ling-pai.lpc`（2
处，`do_saveroom()` 分支）、`ling.lpc`（3 处，`do_mkroom()` 一处 +
`do_saveroom()` 两处），均确认是货真价实的 `.lpc` 源代码（帮派令牌
/令旗相关物品对象，内嵌造殿堂房间的命令），已逐一手动删除。修复后
全库仅剩 13 处历史遗留的 `//`-注释掉实例，均确认无害、未改动。已
用 `build-debug` 驱动干净启动验证（0 个新增编译错误，端口 40171
正常监听，`debug.log` 无新增 "cannot replace"/"cannot bind" 行）；
未做完整 §10.7 深度游玩测试。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试 round-four 补测（2026-08-24）——补齐先前"未覆盖"清单

复用同家族已知的两个 bug 检查、以及先前 §10.7 记录里明确留下的三项
"未覆盖"（`buy`/拜师/`WIZPWD` 两条校验分支），用 `build-debug/src/driver`
（端口 40171）+ `scripts/tmux_mud.sh` 走了一轮针对性验证。

- **已知 sibling bug #1（`combatd.lpc` `killer_reward()` 缺
  `killer->add("PKD",1)`/`victim->add("DIE",1)`）——不适用**：
  `work/adm/daemons/combatd.lpc` 第 866-868 行三行齐全，本档案没有这个
  缺陷（可能这份档案的 combatd.lpc 版本比 sjshwzb/sjshwzjqb 那份新，或
  从未被那次局部删除影响到）。

- **已知 sibling bug #2（`d/lingtai/obj/shengmao.lpc` `set_name()`
  未闭合字符串）——不适用**：本档案确实有这份档案（`work/d/lingtai/obj/
  shengmao.lpc`），但第 7 行 `set_name(HIC "三界神帽" NOR, ({...}));`
  字符串引号完整闭合，不是 sjshwzb/sjshwzjqb 那个坏版本。

- **`buy`/商店购买流程——已测试，正常**：用 `clone` 给管理员测试角色
  `fluffos` 变出 `/obj/money/silver`（一两银）后在〖三联书局〗
  （`/d/city/bookstore`，老板孔方兄 `d/city/npc/bookseller.lpc`）
  `buy xyjbook from kongfang`（单价一两银子，精确找零为零），成功买到
  《西游记》，银子被正确扣光。再 `clone /obj/money/gold`（一两金=
  10000 值）购买十两银子（1000 值）的〖刀法入门〗，找零验证：
  10000-1000=9000 值 → 应得九十两银（90×100=9000），实测背包正确出现
  「九十两银子」——找零换算完全正确。`list` 指令价目表显示也正常。
  测试道具已在提交前用 `drop` 丢弃（房间有自动清除的绿色小精灵拾走，
  不会残留在版本控制内）。

- **门派拜师（apprentice/bai）——测出并修复了一个真实 bug（AGENTS.md
  §7.117 同款）**：`cmds/std/apprentice.lpc` 第 62 行原本是
  `if ((string)me->query("family/family_name") != (string)ob->query("family/family_name")) {`
  ——这正是 AGENTS.md §7.117 记载的、跨 74+ 库确认过的"拜师确认分支缺
  首次拜师existence guard"的标准坏形状：当一个从未入过任何门派的新手
  角色被师父 `recruit` 后再用 `apprentice` 确认拜师时，`me->query
  ("family/family_name")` 是空值，天然就"不等于"师父的门派名，导致代码
  误判为"背叛旧门派转投他派"，本应是`else`分支的"正常拜师"礼却走进了
  "背叛"分支（会清零 score、打上 betrayer 标记）。同一对指令的另一半
  `cmds/std/recruit.lpc` 第 63 行早就有正确的 `(ob->query("family")) &&`
  存在性守卫（还带注释"follow modified by elon 09-10-95 to fix a bug in
  1st time recruit"）——证明这个修复曾经打在配对文件的一半上，另一半
  （`apprentice.lpc`）漏掉了，和 AGENTS.md §7.117 描述的典型情形分毫不
  差。修复：按 §7.117 既定写法加上同款守卫——
  `if ((me->query("family")) && ((string)me->query("family/family_name") != (string)ob->query("family/family_name"))) {`。
  **现场复现+验证**：clone 一个 `/d/city/npc/shubao`（秦琼，`将军府`
  二代弟子，`attempt_apprentice()` 无条件接受）放在管理员测试角色
  `fluffos` 所在房间，用 `call shubao->command("recruit fluffos")`
  让秦琼先对我发起收徒（设置秦琼自己的 `pending/recruit`），这样后续
  `apprentice shubao` 才会真正走到本档案原本有 bug 的那条"确认拜师"分
  支（而不是走 `recruit.lpc` 那条本来就守卫正确的路径）。`update
  /cmds/std/apprentice` 重编译成功后执行 `apprentice shubao`，输出
  "你决定拜秦琼为师...恭喜您成为将军府的第三代弟子。"（正常拜师文案，
  不是"决定投入...门下"的背叛文案），`score` 确认师承显示"将军府秦琼"、
  `family` dbase 字段里没有出现 `betrayer` 标记、`combat_exp`/`score`
  等属性也未被清零——修复确认生效。

- **`WIZPWD` 校验成功/失败两条分支——已测试，均正常**（此前一轮只验证
  过"未设置时不再卡死"这一条修复，这两条从未测过）：用
  `fluffos`/`Mud@2027` 重新登录，先用 `wizpwd` 指令（提示文字用大写
  `WIZPWD` 但实际指令是小写 `wizpwd`，纯粹是大小写不敏感，不是 bug）
  首次设定 WIZ 密码为 `TestWiz123`；`quit` 后重新连线，`get_wizpwd()`
  验证分支：（1）故意输入错误密码 `WrongPass`——正确显示"密码错误！
  请重新输入你的ID和密码！"并要求重新走 id+密码流程（未直接进入游戏）；
  （2）随后用正确的 `TestWiz123`——正确显示"密码正确！"并正常进入游戏
  世界。两条分支的 `crypt()` 比对逻辑均按预期工作，没有发现新 bug。

驱动全程 `debug.log`（`work/log/debug.log`）未生成任何内容（说明零次
运行时错误/崩溃），`work/log/err.log` 只有既有的"Unused local
variable"编译期警告，无新增编译错误。测试产生的一次性登录日志
（`u/koker/files/EEDIT` 新增两行"fluffos(admin) sets/updates"审计记录）
按既定套路保留，不算需要清理的临时产物。已停止 tmux 会话与本地
`build-debug` 驱动进程。

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()` (or `reset_me()`
calling `setup()`) chain -- confirmed live via a static scan of every
`init()` body in this lib: 45 NPC/item files call `setup()` directly
or via `reset_me()` from `init()`, after `create()` already called
`setup()` once (which already made the object `living()`). Calling
`enable_commands()` a second time on an already-`living()` object makes
the driver re-invoke that object's own `init()` as a side effect, which
re-enters this same chain while the original call is still on the
stack -- genuine reentrancy, crashing with "Too deep recursion" (most
likely to surface on an NPC's first-ever preload/compile).

`feature/damage.lpc`'s `revive()` and `cmds/std/sleep.lpc`'s `wakeup1()`/`wakeup2()` call `enable_player()` again while the object is still `living()`. This confirms a bare `if (living(this_object())) return;`
guard would be the WRONG fix (it would silently break that legitimate
re-enable) -- used the same true reentrancy-flag fix as `mhxy` instead:
a `nosave private int in_enable_player_now;` set for the duration of the
wrapper's body, guarding only genuine same-call-stack reentrancy while
leaving every legitimate re-enable (revive/wakeup/disguise) unaffected.
`feature/command.lpc`'s `enable_player()` had a single fall-through exit
(no early `return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 6 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators (opener line, case)

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 more block(s) repaired: 1 with the terminator spelled in another case than the opener (`@MING_PART ... MING_part`: the lexer compares case-sensitively, so the block never ended): `d/obj/club/bihai_mark.lpc`.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply sjshv150`: 1 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 4 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 3 PASS -> 4 PASS, 0 that loaded before fail now, 1 more load.

1 files moved (1 `.lpc`); mostly under `d/club/saiya` (1). A rescan with `scripts/lpc_warnings.py sjshv150` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 306 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 3 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt sjsh sjshv150` 把 sjsh 警告整理提交里的改动搬到 489 个修改前与它一致的文件（159 个按块拼接；逐文件核对非 ASCII 文字：除 sjsh 自己删掉的以外没有丢失或改动）。剩下的再跑 `scripts/lpc_warnings.py sjshv150 --fix`：无用局部变量 1481 个、`varargs` 47 处、转义 23 处、`nosave` 函数 14 个改 `protected`；`scripts/lpc_fix_no_effect.py --apply`：两份 `xuanyuan-archery.lpc` 删去 `(: throw_weapon :);`，`dns_master.lpc` 把 `#if PREF_* & SVC_TCP` 移到 `if` 外面。共改动 1142 个 `.lpc` 和若干 `.h`。
手工：`adm/daemons/natured.lpc` 删去空语句 `lt[LT_MON];`；`adm/daemons/securityd.lpc` 的 `valid_write()`、`valid_grant()` 删去没用到的 `string ip = query_ip_number(...)`（`valid_write()` 的 `user` 也可能是字符串，那时这句本身就会出错）；`adm/daemons/logind.lpc` `get_id()` 删去没用到的 `*usr = children(USER_OB)`。
HEAD 与工作树分别加载（新进程）：1103 -> 1103 通过，无回退；改过的头文件的 348 个包含者 336 -> 336 通过。`d/gumu/npc/zhangmen.lpc` 是编译不过、没人引用的旧稿，未动。

启动时警告 105 -> 0；新进程登录（编码选择、新人物提问）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 30 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 8 个，只在 #if 分支用的声明移进分支 0 个文件；改动 36 个文件，HEAD 与工作树各载入一次无回退（36 objects; HEAD PASS 35, tree PASS 35; regress 0; newly loading 0），这些文件的警告 58 -> 20。
- 2026-10-14：`data/emoted.o`（表情守护进程的存档）整个还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string while restoring emote`，表情守护进程启动时一个表情都没有。现按 GB18030 转码，丢掉原文件里几个被截断的半个字符。转码后 `adm/daemons/emoted` 载入不再报错（HEAD 上报错）。

- 2026-10-14：2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：2 个对象，新增载入 2，回退 0。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。4 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

1 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。本库人物只有 kee/sen（连 gin 也没有）：药物的 `receive_heal("gin", 60)`、NPC 的 `receive_curing("gin", ...)` 和来自侠客行体系的 qi/jing 调用都报 `伤害种类错误`。6 个文件按 gin→sen、qi→kee、jing→sen、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/luanjian`、`yueya-chan/feicha`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`qiusheng-blade`→`qiushen-blade`（`/daemon/class/youning/siqi-sword/siqi`）。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`d/moon/emoted.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

9 个文件、11 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/obj/armor/密林青衣`、`/d/obj/weapon/staff/tc_staff`、`/u/calvin/armor/jinlingpao`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 10 个（9 个原来载入不了），没有退步。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 3 个，改后 12 个，没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`adm/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，2 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h；`adm/network/netmail`：/adm/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 6 个对象设了本库没有文件的武功（11 个名字，最多的是 `fumobashi`、`mizongbu`、`strike`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：6 个里 5 个通过，其余 1 个停在别的错误上（`d/wuguan/npc/master`：*No program in object '/d/wuguan/npc/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 19 处、19 个文件：`dagonforce`→`dragonforce`（4 处）、`lahua-shou`→`lanhua-shou`（3 处）、`yange_blade`→`yange-blade`（2 处）、`dragon-step`→`dragonstep`（2 处）、`hellfire_whip`→`hellfire-whip`（1 处）、`kongming--steps`→`kongming-steps`（1 处）、`changqaun`→`changquan`（1 处）、`lingyi-sword`→`liangyi-sword`（1 处）等共 12 个名字。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 3 个：`/daemon/skill/boxing.lpc`、`/daemon/skill/westsword.lpc`、`/daemon/skill_wiz/whip/jueqingbian.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 1 个：`d/wuguan/npc/master`。（`scripts/lpc_transplant_function.py`）

## 同一个函数原样贴了两遍（2026-10-19，KB 06 §7.264）

同一个文件里同一个函数被原样贴了两遍（除空白外逐字相同），驱动报 `Redeclaration of function`，整个物件载入不了。删掉第二份及以后的副本，共 1 处：`/d/pkdao/room1.lpc` 的 `greeting()`。（`scripts/lpc_fix_dup_functions.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `WEAPON_OB`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：3 处浮点数赋给 int 的地方改成 to_int()，4 处重复的 inherit。修后与 HEAD 逐个物件对比载入，没有退步。

## 开封擂台头文件的重复全局变量（2026-10-19，KB 04 §6.10）

`d/kaifeng/ground.h` 里的 `modes`、`mode_hints`、`families` 三张表被 `ground0.lpc` 和继承它的 `ground1/2/3.lpc`、`ground.lpc` 各包含一次，每次 `inherit` 都报 `Redeclaration of global variable`。表只放在 `ground0.lpc` 里：头文件用 `#ifndef GROUND_TABLES_INHERITED` 包住表，继承的几个程序在 `#include "ground.h"` 前 `#define GROUND_TABLES_INHERITED`（与 xiyouji 系其余库同一改法）。`d/kaifeng/npc/colors.h` 也加了防重复包含。改后警告消失，与 HEAD 逐个对比载入，没有退步。

## 全局变量重复声明（2026-10-19，KB 04 §6.10）

- `d/city/npc/yg/yaoguai.lpc` 的 `int yaoguai_type = 0;` 与基类 `/d/dntg/yunlou/npc/yaoguai.lpc` 重复（叶子文件里没有任何地方用它），删掉。
- `d/city/npc/sanhua-counter.lpc` 的 `int last_time` 与 `feature/alias.lpc` 里防刷命令用的 `nosave int last_time` 同名，但是两回事（这里是每天重置的时间戳）：改名 `last_reset_time`，存档 `data/npc/c/city_sanhua.o` 里的键同步改名。
改后警告消失，与 HEAD 逐个对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `d/longzhu/npc/long.lpc`：同 sjcs，删掉从未定义的 `int long();` 声明。
- `d/obj/cloth/jiasha.lpc`：同时继承 `CLOTH` 和 `F_UNIQUE`，两个都有 `init()`，驱动用了后继承的 F_UNIQUE 那个（检查所有者），布料的 `tear`（撕布条）命令从来加不上。写一个 `init()`，两个都调：`cloth::init(); unique::init();`。
- `d/kaifeng/npc/reporting.lpc`：`reporting()` 里 `str` 只在被注释掉的调试代码里用，声明改成注释。
- `d/dntg/lijing/lijing.lpc`、`d/moon/npc/yutu.lpc`：李靖的 `int die()`、`int unconcious()` 和玉兔的 `int kill_ob()` 盖掉基类的 `void` 函数（`does not match current function in return type ( void vs int )`）；全库没有任何地方读它们的返回值，改成 `void`，玉兔的 `return ::kill_ob(victim);` 改成语句。
- `data/group/obj/ling.lpc`、`data/group/obj/ling-pai.lpc`：`special_props` 声明了两遍，先 `({ "short", "long" })`，后面又 `({ "short", "long", "file_name" })`；同名的后一次声明盖掉前一次（`compiler.cc` `define_variable`），代码用的一直是后者，删掉前一个。
- 宏重复定义：`include/globals.h` 和 `d/quest/task/{cron,tu}.lpc` 的 `TASK_D`、`d/quest/task/questd.lpc` 的 `CRON_D`、`include/net/ftpdconf.h` 的 `VALID_READ`、`VALID_WRITE`，在后一个 `#define` 前加 `#undef`（`scripts/lpc_fix_macro_redef.py`）。

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/jz/npc/jiang.lpc`（dtxyzjb）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：离开时清除“砍柴”标记只在往北走时才生效，往南不清。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/d/wizz/stey/npc/robber.lpc`（1 处）、`/d/lingtai/forrest2.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：同盟可以取门派的名字（`fname == A && fname == B && ...`）。改动：`/adm/daemons/leagued.lpc`（13 处）、`/cmds/std/bian.lpc`（3 处）、`/d/calvin/lanling/yuhuayuan.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 10 处）。改动：`/d/city/mjlady3.lpc`（3 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）、`/daemon/class/tianpeng/fofa/only.lpc`（1 处）、`/daemon/class/tianpeng/fofa/onlyu.lpc`（1 处）、`/www/cgi-bin/board_h.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 访客计数 `howmany_visitor()` 读文件不检查（2026-10-20，KB 06 §7.301）

`howmany_visitor()` 读访客计数文件（`VISITORS` / `COUNTER` / `BBSVISITOR`，只有运行中的 mud 才会写；`.gitignore` 把它排除在仓库之外），新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不一定走到它，但调用时同样会出错。在读文件之后加了 `if (!stringp(content)) return 0;`（xkx100、xiakexing100、zzfy 早先的写法，`scripts/lpc_fix_visitor_count.py`）。改动：`/www/cgi-bin/logind.lpc`。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## 本机回环地址只放巫师：新玩家无法注册（2026-10-20，KB 01 §1.3b/e 的补充）

`adm/daemons/sited.lpc` 的 `is_valid(id, ip)` 对 127.0.0.1 只放行巫师、`allenc` 和字面的 `new`。`logind` 在新玩家输入英文名字之后（`get_new_id()`）和老玩家登录时（`get_id()`）还会以真实的 id 再调一次，所以只给 `new` 开例外不够：站点的访客永远是回环连线，除管理员 `fluffos` 外每个 id 都被 `Sorry,This id can not login from this address.` 拒绝，登录调查记作 `closed`。以前的说明里把这一点当成"范围很窄的测试限制、真实的远程部署不受影响"，这对博物馆站点不成立。现在回环地址一律放行（和同族的 sje、sjshv2578bb、sanjieshenhua 一样，KB 01 §1.3b）；别的地址的 `valid_login` 限制不变。实测：新角色从 `new` 一直走到进入世界，`look`、`score` 正常。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## `wheremoney`：没有 `/adm/daemons/money`（2026-10-21，KB 06 §7.308）

`cmds/std/wheremoney.lpc` 对 `"/adm/daemons/money"->show_msg()`；这个 daemon（寻宝发钱的事件）在 sjsh、sjshwzb、sjshwzjqb、shenmo、xlqy 系里有，v1.50 没有带：`call_other() couldn't find object '/adm/daemons/money'`（第二遍扫描的 `wheremoney` 一行）。命令先检查 `file_size("/adm/daemons/money.lpc") < 1`，走原来 “现在没有发放任何钱财。” 的那一支。没有搬 daemon（它连着挖宝的物品）。

## 观礼台 `d/city/under.lpc`：`wait_and_start()` 里的 `fan` 没赋值，比武开不了（2026-10-21，KB 06 §7.346）

接受挑战（`defend`）两秒后 `wait_and_start()` 调用 `fan->command("chat ...比武开始")`，`object fan;` 声明了却没有 `fan = load_object(__DIR__ "npc/fan");`（dtxywzxzb 的同一份文件有），抛错之后两条 `kill` 和 `call_out("finish_match", 300)` 都不执行，比赛不开始。补上这一句（`npc/fan.lpc`、`ground.lpc` 本库都有）。

## 七龙珠 `combine`：六次 `present()` 都存进了 `b`（2026-10-21，KB 06 §7.348）

每颗龙珠的 `do_combine()` 先检查身上有另外六颗：`if (!(b = present("liang longzhu", me))) ... if (!(b = present("fen longzhu", me))) ...`，六句都写成 `b =`，后面 `destruct(b); destruct(c); ... destruct(g)` 的 `c` 到 `g` 一直是 0。这几个库的 `destruct()` sefun 对 0 不抛错（原始 efun 也不抛），结果是合成神龙时只消耗了最后一颗和合成者自己，另外五颗还留在身上，可以反复合成。改成 `b, c, d, e, f, g`（shenmo 的 `/d/longzhu/obj/*` 是对的）。sjsh 上实测：HEAD 合成之后背包里还剩青、黄、蓝、粉、亮五颗，改后只剩神龙。改动：`/d/longzhu/obj/1.lpc`、`/d/longzhu/obj/2.lpc`、`/d/longzhu/obj/3.lpc`、`/d/longzhu/obj/4.lpc`、`/d/longzhu/obj/5.lpc`、`/d/longzhu/obj/6.lpc`、`/d/longzhu/obj/7.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 47 条注册（26 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/calvin/lanling/npc/guard1.lpc`（`do_bian`）、`/d/calvin/lanling/npc/gurad1.lpc`（`do_bian`）、`/d/calvin/lanling/x.lpc`（`do_swim`）、`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/eastway/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/eastway/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/gumu/huo.lpc`（`do_chop`）、`/d/gumu/jin.lpc`（`do_chop`）、`/d/gumu/mu.lpc`（`do_chop`）、`/d/gumu/shui.lpc`（`do_chop`） 等共 26 个文件。最多的函数名：`do_swim` 10 处、`do_chop` 9 处、`do_bian` 7 处、`do_no` 5 处、`do_cost` 2 处。没有动（读过）：`/d/gumu/npc/zhangmen.lpc` 的 `do_comfirm`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/wizz/stey/npc/rulai1.lpc` 的 `do_cancel`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/wizz/stey/npc/rulaim.lpc` 的 `do_cancel`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 1 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/calvin/npc/wu.lpc`（`do_bian`）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`query_current_day_phase()`（4 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 3 个函数没有补（inquiry 2, chat_msg_combat 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/9ct/npc/wuyazi.lpc`:`kick_back`、`/d/death/npc/yanluowang.lpc`:`ask_cancel`、`/d/xueshan/obj/hufabird.lpc`:`saysth`。 另有 11 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 不带前导斜杠的物品路径：缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`carry_object("d/city/obj/jiasha")->wear();` 这类路径不带前导斜杠的写法在这个驱动里按根目录解析（`new("d/city/obj/changjian")` 能加载 `/d/city/obj/changjian`），所以和带斜杠的一样：文件不在压缩包里时 `new()` 返回 0，`->wear()` 在 0 上报 `Bad argument 1 to EFUN call_other()`，整个 NPC 加载不了。此前的保护工具把这种写法当作「相对当前目录，没法判断」跳过了。2 个文件里 6 处（`d/wizz/junhyun/usr/obj/godarmor`、`d/wizz/junhyun/usr/obj/godshield`、`d/wizz/junhyun/usr/obj/sessword.lpc`等）改成带保护的块（`scripts/lpc_guard_carry_object.py`）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 0 个，现在 2 个（新增可加载 2 个，回归 0 个）。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 4 个文件里 14 行只含这个指针的行（`"回去": (: kick_back :),` `"cancel": (: ask_cancel :),` `"set": (: set_max :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 2 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 2 处（1 个文件）：拼名字的赋值 2 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/tidu.lpc:126`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：9 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 9 处（4 个文件）：`if (strlen(arg) > 20) return notify_fail(WHT "标题过长,请控制在10个中文字符以内！\n" NOR);`（`/cmds/usr/news.lpc:170`）；`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/d/city/npc/zhangsunwuji.lpc:177`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 10 个文件；茶馆猜诗 `mixup` 1 个文件；`channeld` 同盟 / 门派标题 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 从末尾按字节取汉字、书剑开帮长度（2026-10-23，KB 06 §7.364）

§7.360 只折了数字下标的 `[a..b]`，从末尾取的 `[<2..<1]`（GBK 下一个汉字）和 `[<4..<1]`（两个字）还留着：开帮 `gcreate` 的帮助写「二至六个汉字 / 3到8个英文字母」，检查却是 `(strlen%2)==1 || <4 || >12`，末字对 `({ "帮","会",… })` 用 `gname2[<2..<1]` 永远对不上；少林 / 峨嵋法名 `"明" + name[<2..<1]`、死讯 `killer[<2..<1] != "。"`、兵器改名的 `can_name` 同样坏掉。`scripts/lpc_fix_tail_slice.py` 只改汉字语境（对照非 ASCII 字面量、`can_name` / `valid_group_name`、拼名字），ASCII 补零 / ctime / 复数词尾 / `.lpc` 不动；`[<2..<1]`→`[<1..<1]`，`[<4..<1]`→`[<2..<1]`，开帮门槛按帮助改写。本库 从末尾切片 1 个文件。证明（`scripts/lpcc_eval.py` bxsj）：HEAD 上 `斧头帮[<2..<1]` 对不上「帮」；改后 `[<1..<1]` 对上；长度放行 `斧头帮`/`fut`；`"明"+"张三"[<1..<1]` 得「明三」。


## 家丁 CLOTH_OB()/WEAPON_OB() 调用式宏（2026-10-27，KB 04 §6.16 Also）

`d/wuguan/npc/jiading.lpc`（及 `jiading1`，xlqy 系在 `d/dntg/hgs/wuguan/npc/`）写 `carry_object(CLOTH_OB("cloth"))` / `WEAPON_OB("changjian")`：库中没有带参的 `CLOTH_OB`，`WEAPON_OB` 在 `globals.h` 只是裸路径 `"/d/obj/weapon/"`，展开成 `"/d/obj/weapon/"("changjian")` 语法错误，NPC 无程序。同目录其它 NPC 用 `__DIR__ "obj/cloth"`；剑在 `/d/obj/weapon/sword/changjian`。改成这两条（目标文件均在树内）。证明：HEAD `Undefined function CLOTH_OB`；改后 `new()` 成功且 inventory 为 2。


## 黑风山 pusa1 用未声明的 ob 且函数外残留 call_out（2026-10-27，KB 06 §7.348 Also）

`d/qujing/heifeng/npc/pusa1.lpc` 的 `announce_success(object who)` 写成 `if (!ob->query("obstacle/hf"))`（`Undefined variable 'ob'`），同目录 `pusa.lpc` 是 `who->query("obstacle/hf") == "done"`；`who->save(); }` 之后还残留 `call_out("die"...); return; }`，落在函数外（`unexpected L_STRING`），对象无程序。改成与 `pusa` 相同的门，并删掉残留语句。证明：HEAD 加载失败；改后加载成功。


## 雪山 obj/hufabird set_level 缺 }（2026-10-27，KB 04 §6.28 Also）

`d/xueshan/obj/hufabird.lpc` 的 `set_level` 在 `setup();` 后少了一个 `}`，后面的 `int heal_up()` / `leave` / `invocation` / `die` 都嵌进了 `set_level`（`unexpected '('`），对象无程序；同目录 `npc/hufabird.lpc` 正常关闭。顺带：`messege_vision`→`message_vision`，`return : die()`→`return ::die()`，以及无 `saysth` 的 `(: saysth :)` 按 7.355 注释掉。证明：HEAD 加载失败；改后加载成功。


## 月宫 quest/road 模板缺 index（2026-10-27，KB 06 §7.348 Also）

`d/moon/quest/road.lpc`（及误放在 `npc/road.lpc` 的副本）出口写 `sprintf("%d", index ± 1)`，却没有像 `road1`…`road10` 那样声明 `int index = N;`（`Undefined variable 'index'`），对象无程序。补上 `int index = 5;`（中间段，东西出口都能落到已有房间）。证明：HEAD 加载失败；改后加载成功。


## 星君/罗汉模板缺 ID 宏（2026-10-27，KB 06 §7.348 Also）

`d/dntg/sky/stars/star.lpc` 与 `d/nanhai/luohan/npc/luohan.lpc` 用 `title[ID]` / `first_name[ID]`，真正带号的副本是 `#define ID N` 再 `#include` 本文件；单独编译模板时 `Undefined variable 'ID'`。加 `#ifndef ID` / `#define ID 0` / `#endif`，带号 include 仍用各自的 N。证明：HEAD 模板加载失败；改后模板与 `stars/5`、`luohan5` 均加载成功。


## 雷神 check 在 stop_fight 定义之前调用且 call_out 缺逗号（2026-10-27，KB 04 §6.28 Also）

`d/qujing/start/24/1.lpc` 的 `check()` 里调用 `stop_fight(who)`，函数却写在后面（`Undefined function stop_fight`）；`call_out("lost", 1 who)` 少了逗号（`unexpected L_DEFINED_NAME`）。把 `stop_fight` 挪到 `check` 之前，并改成 `call_out("lost", 1, who)`。证明：HEAD 加载失败；改后加载成功。


## toy 旁缺 message.h（2026-10-27，KB 04 §6.23 Also）

`obj/toy/*.lpc`（及少数 `obj/obj/toy`、嵌套副本）写 `#include "message.h"`，引号 include 只解析同目录；本 lib 的 `d/obj/misc/message.h` 有同内容副本，toy 目录没有。玩具对象无法编译（`Cannot #include message.h`）。从本 lib 的 `d/obj/misc/message.h` 复制到缺失的 toy 目录旁。证明：HEAD `buwawa` 加载失败；改后加载成功。

## 玉皇 yuhuang1 去引号无法加载（2026-10-27，KB 04 §6.25 Also）

`d/dntg/sky/npc/yuhuang1.lpc`：字符串与路径几乎全部丢掉引号（`set_name(玉皇大帝,…)`、`carry_object(/d/obj/cloth/mangpao)`、`setup()` 后无 `;`），下一句 `int promote_me()` 成语法错误。同目录手足 `yuhuang.lpc` 完好；用本库 `yuhuang` 字节覆盖 `yuhuang1`。证明：HEAD 加载失败；改后加载成功。

## 悬空 ::init / unique::init（2026-10-27，KB 06 §7.259 Also）

`kugu-1/2/3`、`kunxian-suo` 写 `::init();`，`tianyi` 写 `unique::init();`，而 `F_UNIQUE` / `ITEM` / `feature/unique` 没有 `init`；本驱动编译报 `Unable to find the inherited function 'init'`（tianyi 带 `in file 'unique'`），物件无法加载。老驱动把空父调用当返回 0。`lpc_fix_dangling_super.py` 删掉这些语句；`cloth::init()` 保留。证明：HEAD 加载失败；改后加载成功。

## dami 误调 init_unarmed（2026-10-27，KB 04 §6.25 Also）

`d/obj/food/dami.lpc` 继承 `ITEM`+`F_FOOD` 却调用 `init_unarmed(5)`（并 `#include <weapon.h>`），未继承空手兵器基类，驱动报 `Undefined function init_unarmed`。手足 hymud 已注释该行。删掉该调用与无用的 weapon 头。证明：HEAD 加载失败；改后加载成功。

## 深度功能测试（2026-10-27，§6.25 tell_object 参数顺序）

`tell_object("…", me/who)` 参数颠倒（消息当对象）；改为 `tell_object(me/who, "…")`（guest.lpc）。证明：残渣 0；抽样 guest/rukou/forest_c 加载。

## 深度功能测试（2026-10-27，§6.25 tell_object 缺 me（自动放弃/愿否））

一参 `tell_object("…")` 在已有 `me` 时改为 `tell_object(me, "…")`（city.lpc）。证明：抽样 city / xiaolongnv 加载。

## 深度功能测试（2026-10-27，§6.25 tell_object 路径当房间）

`tell_object("/…", …)` → `tell_room(load_object("/…"), …)`（去掉 `.lpc`）。

