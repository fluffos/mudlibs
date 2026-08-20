
## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记2000（Journey to the West 2000），一个以西游记为题材的经典 MudOS 时代 mudlib，注册流程里带有一个"是不是在校学生"的年龄门槛问题，这是原始设计，不是 bug。WASM 修复了 3 个连环 bug：（1）adm/daemons/convertd.lpc 的 GB/BIG5 转换表（inittable）带有和 sjsh 系档案上同样的字节级损坏模式（多个符号挤在一起，而不是每个数组元素一个）——用标准的逐码点重新拆分脚本修复（影响约 45 行）。（2）adm/daemons/network/dns_master.lpc，一个真正的多用途 intermud 精灵（query_mud_name()/muds 映射被约 28 个其它服务档案呼叫：mudlist_a/mudlist_q/gtell/gchannel/rwho 等）——按照 AGENTS.md §7.52 对多用途精灵的例外处理，没有整个档案掏空，只掏空了两个碰 socket 的入口点（startup_udp() 现在回传 0，符合它自己既有的失败回传惯例，让 create() 里的 'if (startup_udp()) init_database();' 自然跳过依赖 socket 的初始化；send_udp() 变成 no-op），另外删掉了 send_shutdown() 里遗留的一处 socket_close()。（3）由此暴露出的一个连锁 bug：adm/etc/preload 里 dns_master 那一行被注释掉了（原始压缩包里是启用的；很可能是有人在 socket 兼容修复出现之前，为了让 mudlib 至少能启动而做的临时变通），导致 DNS_MASTER 从未被预加载。adm/daemons/logind.lpc 的 encoding() 在选完编码后紧接着检查 'if(!find_object(DNS_MASTER) || ...) shutdown(1);'——find_object() 只对已经加载的物件回传真，精灵既然从未被预加载，这个检查就永远为真，导致每一次连线在 GB/BIG5 选择完之后立刻触发 shutdown(1)，之后再也没有注册 input_to()（后续所有输入都显示为无法识别的指令）。已通过读 logind.lpc 的 encoding() 并确认预加载那一行被禁用（而原始压缩包里是启用的）根源定位；修复方式是重新启用那一行预加载，因为 dns_master.lpc 现在已经能在 WASM 下干净编译运行——logind.lpc 自己的检查逻辑不需要改动。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（securityd.lpc 真的会在开机时读取 WIZLIST）。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB/BIG5 选择→否（年龄门槛）→new→英文 id→中文名字→密码+确认→电子邮件→性别（m/f）→属性分配菜单（9 接受默认值，y 确认）→带着完整角色属性表进入游戏世界；look/score/quit 都正常。管理员权限已直接通过登录时的"目前权限：(admin)"确认。LPC 格式化工具对全部 5637 个档案运行（写入 5542 个，4 个因为转档之前就存在的未结束字符串/文本块内容 bug 被拒绝格式化，和格式化工具本身无关，91 个未改动）。改动档案格式化前的原始内容里没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。追加修复：scripts/scan_known_bugs.py（本次会话新写的静态扫描工具）事后标记出 5 个懒加载/潜伏的 bug，是原本只测注册流程的冒烟测试从未触发过的：d/obj/books-nonskill/book-qujing.lpc 的绝对路径写法 #include </d/qujing/obstacle.h>（永远解析不了，已改成引号写法）；logind.lpc 的 check_legal_name() 带有标准 §8.1 的 i%2 奇偶门槛加 [i..<0] 后缀切片写法（这里之所以无害，只是因为这份档案的 is_chinese() 恰好只检查 str[0]，但为了统一/稳健起见还是改成了标准的逐码点写法）；master.lpc 的 valid_read()/valid_write() 直接转发给 SECURITY_D，没有 'user == this_object()' 保护（和手足档案 xyj20032 上曾经静默弄坏每一次新角色物件编译的那个潜伏风险一模一样——这里没有观察到实际触发，属于主动预防性修复）；3 个档案用物件呼叫了 is_killing(me)，而 feature/attack.lpc 声明的是 is_killing(string id)（§7.50，daemon/class/dragon/dragonforce/roar.lpc、daemon/class/yaomo/kusong/huomo/fire.lpc、cmds/std/surrender.lpc）；d/sky/npc/zz-tianwang.lpc 还残留有原始 GBK 字节，是原来批量 GBK→UTF8 转换那一遍漏掉的（已用 iconv 转换）。另外还发现并修复了 adm/simul_efun/message.lpc 的 tell_room() 把一个未设置的 exclude 直接转发进 message() 第 4 个参数的问题（§7.12，改成 exclude || ({})）。修复后重新验证干净。

## 深度功能测试（§10.7，2026-08-05）

- **printf 调试残留**：`adm/daemons/logind.lpc` 的 `get_name()` 里有
  一处活跃的 `printf("%O\n", ob)`（和"天涯"/"hy"两个家族里已经修过
  的同款泄漏一样），每次注册都会把整个玩家对象的原始引用打印到连
  线画面上。已删除。
- **§8.9 不适用**：`enter_world()` 的 `user->set("food",
  user->max_food_capacity())` 等语句是无条件执行的，本来就没有用
  `ob`（登录对象）做任何年龄判断包装，所以不存在错对象年龄检查的
  问题——这份代码库的写法本身就是对的。
- **留言板 `post` 崩溃 bug（AGENTS.md §7.86，第三个不相关家族确
  认，且发现了一个新变体）**：这个 bug 之前在"天涯"（`tybxjh`/
  `xhcii`/`zxty`）和"hy/海洋"（`hy2000`/`hy2002`）两个互不相关的家
  族里都见过，这次在完全独立的西游记代码库里又发现了——而且这次除
  了常见的 `inherit BULLETIN_BOARD` + 多余 `replace_program
  (BULLETIN_BOARD)`（25 处）之外，还发现了一个新变体：3 份档案
  （`xyj_b.lpc`、`menpai_bbs.lpc`、`query_bbs.lpc`）用的是另一个同
  样有问题的留言板基类 `BBS_BOARD`（`/std/bbsboard.lpc`），同样的
  `inherit` + 多余 `replace_program` 写法，同样的
  `ob->edit((: done_postnews, ... :))` 闭包创建崩溃机制——已确认
  `bbsboard.lpc` 自己的 `do_postnews()` 和 `bboard.lpc` 的
  `do_post()` 是同一个致命形状。共删除 28 处多余的 `replace_program`
  调用（25 处 `BULLETIN_BOARD` + 3 处 `BBS_BOARD`）。live 验证过两
  块不同的留言板（南城客栈留言板、生死之间留言板）`post` 都能正常
  打开编辑器并保存成功。这已经是 §7.86 第三次在互不相关的代码库家
  族里被独立确认，基本可以认定是这一代 ES2 衍生代码库的通用陷阱，
  已更新 AGENTS.md §7.86 记录这个跨家族确认和新的 `BBS_BOARD` 变体。
- **战斗/死亡/复活测试**：在朱雀大街和"疥顶小僧"（一个使用"重重叠
  叠"分身幻术的强力和尚 NPC）打了一场，很快落败身亡，落到"阴阳
  界"，"朱笔判官 崔珏"在场（这份档案自己对§7.68 死亡守卫 NPC 的称
  呼和造型，判定守卫写法和"天涯"/"hy"家族的"白无常"完全一样：
  `if (!ob || !present(ob)) return;`，位于 `d/death/npc/pang.lpc`）。
  **先检查了 `pang.lpc` 的 `init()` 有没有 hy2000 那次发现的
  `wizardp()` 排除判断——确认没有**，管理员测试账号不会被排除在自
  动复活流程之外，于是直接原地等待，没有对判定守卫做任何改动（按
  AGENTS.md §7.68 现在收窄后的纪律）。复活流程完整播放了全部五个阶
  段对话，`reincarnate()` 正确执行，最终送到"荒郊小店"，角色状态
  （气血/精神部分恢复、食物/饮水满格）符合预期——复活系统本身完全
  正常，不需要任何修复。
- **本次没有测试**：拜师/门派、商店（时间主要花在追查/验证留言板
  bug 的完整范围上，留给后续深挖）。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 142 live occurrences deleted: 141 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant). 1 already-commented-out instance left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40155.
