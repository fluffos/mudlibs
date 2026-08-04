
## 深度功能测试（第二轮，2026-08-03）

之前的会话只测过注册流程，本轮做了完整的 §10.7 深度功能测试。
proactive 检查 AGENTS.md 已归档的四类常见坏味道，命中了一类：
`adm/daemons/logind.lpc` 里两处 `printf("%O\n", ob)` 调试残留（`hc`/
`yxjh`/`xkyx3b` 那种"两条并行取名流程各自一份"的经典形状）。已删
除两处，新增 `mnhf` 到 AGENTS.md §7.34 确认实例列表。其余三类
（private command_hook、未防护 MESSAGE_D->、stat/water 键名、§8.9
坏 age 判断）均未命中。

**完整流程验证**：注册全新角色（沐华附/id `mnhdive`），走完游戏
自带的"军训"新手引导（教官依次介绍生存/经济系统、拜师/读书/任务
系统、最后在"欢迎光临模拟华附"的枢纽房间用数字菜单 1-6 选择去
处）；到"聚清园"向任务 NPC"夜刻名"用 `quest` 指令（不是
`ask...about quest`，指令直接注册在 `add_action("give_quest",
"quest")` 上）领到一个限时寻物任务（"给我八分五秒内找回我要的
『大青菜』"）；以管理员身份 `goto` 到广播里提到的新手练功用"草
坪"场景，对"小鸟"NPC 发起战斗，完整交手十余回合，攻防叙述、命
中/闪避/招架判定均正常；`quit` 干净退出。全程 debug.log 零报错。

顺带确认了这份档案的管理员账号 fluffos 之前只在 `adm/etc/
wizlist` 里列了名，实际存档从未真正创建过（本轮通过正常注册流程
用密码 `Test1234` 创建，符合这份档案自己"必须同时包含大小写字母
和数字"的密码规则），已随本次改动一并提交存档文件。

**未覆盖范围**：拜师、读书系统、工作赚钱（单车楼看车/麦当劳洗盘
子/钓鱼/扫楼梯等）、完整走完已领取的寻物任务，因时间原因未实
测。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

校园题材 mudlib（模拟华附，背景设在华南师范大学附属中学）。WASM 修复：修好了两个 bug。（1）cmds/usr/uptime.lpc 的 write(read_file("/log/nosave/LASTCRASH"))（§7.54 类）——全新安装下这个档案不存在，read_file() 回传 0，write(0) 会崩溃报"Bad argument 1 to receive()"；由于 UPTIME_CMD->main() 在每一次 logon() 里、英文名字提示之前都会执行，这会导致每一次连线尝试都崩溃断线。已用 stringp() 保护修复。（2）adm/daemons/httpd.lpc（§7.52）——socket_create()/socket_bind()/socket_accept()/socket_write()/socket_close() 在这个 WASM 构建下都是未定义的 efun；导致的编译失败（"No program in object"）发生在预载阶段，甚至在上面那个 uptime 崩溃有机会发作之前就先出现了。既然这个精灵存在的唯一目的就是通过 socket 提供 HTTP 服务，已按既定的"整个档案禁用"方针把 setup()/write_data_retry()/store_client_info()/listen_callback()/close_connection()/remove() 整批掏空，而不是逐个呼叫点修补。没有中文名字/宏定义/指令表相关的 bug（is_chinese() 本来就是正确的码点判断）。通过 adm/etc/wizlist 把 fluffos/Test1234 播种为 (admin)（这份档案的 check_legal_password 要求至少 6 位且同时包含大小写字母和数字，常用的 Mud2026Adm 式密码不满足小写字母要求——改用 Test1234 来匹配这份档案自己的规则）。完整的注册（id→确认→直接输入中文名字→密码→确认→电子邮件→性别→角色类型 0-3）和 look→score→quit 流程在排版格式化前后都验证过；格式化工具没有引入任何损坏（三类盲点检查都干净）。
