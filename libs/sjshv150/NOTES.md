
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
