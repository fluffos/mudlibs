
## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记题材的 ES 血统 mudlib（MudOS v22pre11 MudLib Build 3310），游戏内标题为"西行战记"，连线时有一个实时的 GB/BIG5 双编码选单。修复的 bug：（1）经典的 §6.6 convertd.lpc 希腊字母表漏斜杠错字，45 处，导致每次连线的横幅 cat() 都会崩溃；（2）logind.lpc 里经典的 §8.1 check_legal_name() 字节数没减半的长度界限+i%2==0 门槛+尾部切片 bug（is_chinese() 本身已经是正确的码点判断）；（3）实时存在的 GB/BIG5 编码选单 bug（§8.7）——选 BIG5 会在之后每一行都刷出"Invalid GB code"，已把两个选单选项都对应到 GB 直通编码修复。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种，游戏内"目前权限：(admin)"显示确认生效。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字（秦风）。格式化工具发现 2 个档案（d/moon/obj/poem.lpc、u/bmw/task/taskd.lpc）带有转档之前就存在的损坏字符串字面量（一段没有结束的诗词字符串，和一段写死在源码里的分页器输出痕迹）——已还原格式化工具对这两处的重新加空格处理，而不是在已有损坏之上继续叠加，其余问题按 WASM 验证范围之外处理，未修。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 32 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
