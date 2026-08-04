
## 深度功能测试（第二轮，2026-08-03）

之前的会话只测过注册流程，本轮做了完整的 §10.7 深度功能测试。
proactive 检查 AGENTS.md 已归档的四类常见坏味道：`feature/
command.lpc`（以及一份 `edit/` 目录下的镜像副本，核实不是生效路
径）里的"private nomask command_hook"只是历史注释保留的旧代码痕
迹（`// private nomask int command_hook(...)`），真正生效的声明
早已是干净的 `nomask int command_hook(...)`；命中了一处 `adm/
daemons/logind.lpc` 里的 printf("%O") 调试残留（新增 `yszz` 到
AGENTS.md §7.34 确认实例列表）；未命中 unguarded MESSAGE_D->、
stat/water 键名、§8.9 坏 age 判断。

**完整流程验证**：注册全新角色（沐妖神/id `yszzdive`），从"南城
客栈"起步，`hp` 确认食物/饮水/气血/精神槽均满值；向"疥顶小僧"
（这批西游记题材姊妹档案里反复出现的同一个高战力 NPC，
combat_exp 50000）发起战斗——完整交手数回合后被击昏迷致死（"你
死了"），送往"阴阳界"由"朱笔判官 崔珏"接引，明确提示"你莫乱跑，
画了生死簿，我好送你还阳"（和 `bmxkx2001` 那次发现的"鬼魂在复活
过程中被强制移动会永久卡死"是同一类设计警示，但本次静候没有被
任何其它系统打断，正常复活成功，`score` 数据完整）；`quit` 干净
退出。全程 debug.log 零报错。

**未覆盖范围**：拜师（五庄观/月宫/龙宫/普陀/方寸山/无底洞/轩辕古
墓/水帘洞/大雪山/地府共十个门派可选）、西行取经任务线、留言板因
时间原因未实测。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

WASM 修复：修好了 §8.1 GBK 字节区间 is_chinese()/check_legal_name() bug（这个驱动下 str[i] 是一个码点，不是一个 GBK 字节——真实的中文名字会被静默拒绝）；给 band.lpc 的 is_banned()/create_char_banned() 打上了本地回环放行补丁；通过 adm/etc/wizlist 把 fluffos/Mud@2026 播种为 (admin)。在 WASM 下用一个真实的中文名字（秦风）完整验证了注册+look/score/quit，管理员账号的 update 指令也验证可用。
