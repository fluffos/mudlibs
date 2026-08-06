
## WASM 修复摘要（迁移自 meta.json 的 group_note）

侠客行一百，厦门热线一百分支，MudOS V22pre11——和 110 号 xkx100 标题相同（都叫"侠客行一百"），但内容是真正不同的、更小的一份快照（6456 对 14255 个 .lpc 档案，目录结构也不一样，有 ftp/mudos.etc/www 这些 xkx100 没有的目录），尽管显示名字容易混淆，但不是重复压缩包，没有标记 duplicate_of。WASM 修复了和 xkx2000zxb/xkxyb 自己的表亲档案上已经见过的相同 §7.52 类从零手写 HTTP 服务器 bug：adm/daemons/httpd.lpc（经典的 Truilkan/Jacques Interstice httpd.c，这里的档头注释明确标注是由 xiaobao/ken@XAJH 移植到 XAJH mudlib 底座）直接呼叫 socket_create()/socket_bind()/socket_close()，没有任何存在性判断，导致整个档案在 WASM 下编译失败；已确认零外部呼叫者，按 §7.52 的默认做法，把每一个碰 socket 的函式（setup()、write_data_retry()、store_client_info()、listen_callback()、close_connection() 和 remove() 里的 socket_close 呼叫）都掏空。没有发现 is_chinese()/check_legal_name() bug——"小浮侠"（三个字）第一次尝试就通过了，不需要修，这和本轮好几份手足档案不同。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（已通过源码确认 SECURITY_D 真的会在开机时读取 WIZLIST；wiz_levels 顶层是 (admin)）。注册流程在一次连续的 WASM 客户端会话里完整验证过：按任意键横幅→英文 id→y/n 创建确认→中文名字→密码+确认→接受天赋赠礼（y）→电子邮件（id@address 格式）→性别→带着完整角色属性表和可用的 score/look 指令进入游戏世界，全程没有任何意外错误。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"，fluffos 出现在最高阶层里。LPC 格式化工具对全部 6456 个档案运行（写入 6420 个，19 个报错，17 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。全部 3 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`W_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 54 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
