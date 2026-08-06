
## WASM 修复摘要（迁移自 meta.json 的 group_note）

风云Ⅳ（Sumxin fengyun），一款以古龙小说为题材的 MUD（sumxin.com/bbs、fy.sumxin.com）。和 wqfy（本轮另一个风云系手足档案）血统/bug 模式相同，但是不同的代码库。WASM 修复了经典的 §8.1 GBK 字节区间 is_chinese() bug：adm/simul_efun/chinese.lpc 的 is_chinese() 要求偶数字节对长度，还检查 str[0] 的原始字节区间（161-254），会拒绝合法的奇数字符数 UTF8 中文名字；adm/daemons/logind.lpc 自己的 check_legal_name() 有对应的 i%2 奇偶门槛，以及按字节数算的长度界限（2-10，本意是按用户提示"一到五个中文字"应为 1-5 个字符）。已把 is_chinese() 改成逐码点 0x4e00-0x9fff 区间检查，check_legal_name() 改成逐字符检查，长度界限修正为 1-5。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（存在两个 securityd.lpc 候选档案——adm/securityd.lpc 和 adm/daemons/securityd.lpc——已通过 SECURITY_D 宏确认 /adm/daemons/securityd 才是真正生效的那份，符合 §7.56 记载的双档案歧义模式；WIZLIST 真的会在开机时被读取）。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB/BIG5 编码选择→英文 id→y/n 确认创建→中文名字→密码+确认→性别（m/f）→民族选择（0-3）→带着完整角色属性表和可用的 score/look 指令进入游戏世界，全程没有任何意外错误。测试笔记：性别/民族选择正好接在 std/char.lpc 首次编译的大量负荷之后，引发了和 xhcii/xkyxciii 上记载过的同一类测试工具时序竞争——用 --idle 4 补发额外的 'm'/'0' 能可靠绕过；这是客户端时序上的假象，不是 mudlib 本身的缺陷。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"，fluffos 出现在最高阶层里。LPC 格式化工具对全部 8238 个档案运行（写入 6459 个，1775 个报错——几乎全部是安全的 TOKEN MISMATCH 安全闸门跳过，针对无法幂等往返的杂乱历史代码，跳过比例明显偏高但无害，因为被跳过的档案完全没有被改动——4 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。唯一一个存在的 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 15 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
