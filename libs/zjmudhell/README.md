# 指尖MUD

《指尖MUD》从嵌套压缩包中提取而来（`zjmud.7z` 内的 `指间mud服务器+手机版客户端.zip`，内部文件夹名为 `hell`），核心系统档案（`master.lpc`/`logind.lpc` 等）为配合自定义手机客户端协议被大幅重写、注册流程和 master 文件哈希都与其他版本不同，但地图内容仍属于本项目"地狱"/Doing 血统六件套家族（与 `hell`、`zjdy2008wzb`、`zjdyaryl`、`zjdywzb`、`zjdyzj` 同源）——逐字节比对显示与 `zjdyzj` 相似度高达 83%，与 `zjdyaryl` 约 79%，与 `zjdy2008wzb` 约 76%，与 `hell`、`zjdywzb` 则更疏远、约 67%，说明这是把同一套门派/城市江湖世界整体搬到一套完全独立开发的手机客户端引擎上，而不是简单的引擎内衍生版本；本作和 [shujian3](../shujian3/) 同属一个手机 App 协议、同一套自定义 `logind.lpc` 血统，但密码学挑战是真正校验的（真实的 `crypt(ZJKEY, ...)` 握手，没有任何万能旁路字符串），是这批档案里手机协议实现最严谨的一个；不过核心系统重写也带来代价——留言板发帖、玩家商店、邮件等旧系统专属功能在重写时没有被移植过来，深度测试确认这些功能在这套引擎里本来就不存在，并非隐藏的 bug。

## 内容亮点

- 地图和"地狱"/Doing 家族（`hell`/`zjdy2008wzb`/`zjdywzb`）逐字节
  相同，说明这份档案是把"地狱"的门派世界搬到了一套完全独立开发的
  手机客户端引擎上，而不是简单的引擎内衍生版本。
- 自定义手机 App 协议里的密码学挑战是真实校验的：客户端必须正确计
  算 `crypt(ZJKEY, str[2..3])` 才能通过握手，账号密码字段也要求真
  实的 `crypt()` 密文，和 `shujian3` 的"密文字段目前未做真正校验"
  形成对比——这是这批档案里安全性设计最认真的一个手机协议实现。
- 地图内容逐字节相同，但核心系统被完全重写这一事实也带来一个副作用：
  旧系统专属的功能（留言板 `post`、玩家可用的商店/买卖/邮件指令）在
  重写时没有被移植过来——不是这些子系统里藏着 bug，是它们在这份手机
  App 引擎里根本不存在，深度功能测试（§10.7，见 NOTES.md）确认过。

## 注册流程（手机 App 协议）

1. 连线后驱动打印一次 `ver1.0,<str>` 握手横幅，`input_to("jiance", ...)`
   等待客户端回应 `crypt(ZJKEY, str[2..3])`（`str` 本身是
   `crypt(ZJKEY, "zj")`，一个真实的、需要正确计算的密码学挑战——和
   shujian3 不同，这里没有任何万能旁路字符串）。
2. 一次性发送 `账号║密码║密文║email`——**只认字面 `║`
   分隔符，不会做逗号自动替换**；密文字段是真实校验的
   `crypt(ZJKEY,账号)+crypt(ZJKEY,密码)`，同样没有旁路。
3. 新账号则紧接着发送 `性别║图片║中文昵称`，例如 `m║img1║指剑`。

## 本次修复的关键 bug

- `adm/daemons/logind.lpc`：`crypt(ZJKEY, 0)` 在这个驱动上不是原版的
  确定性 DES-crypt，而是每次都生成一个全新的随机 `$6$` SHA-512
  盐值，导致这个客户端挑战/应答握手在数学上永远无法通过（参见
  AGENTS.md §7.14，`zjdyzj` 的同类问题）。已改为显式的
  旧式 2 字符盐值 `crypt(ZJKEY, "zj")`，恢复确定性。
- `adm/simul_efun/chinese.lpc` 的 `is_chinese()`：沿用旧版 GBK
  字节区间判断（`str[i]<176||str[i]>=248` 等），在这个驱动上
  `strlen()` 按字符计数、`str[i]` 是 Unicode 码点而非原始字节，导致
  真实的中文名字永远无法通过检测。已改为码点区间判断
  （`0x4e00`-`0x9fff`）。
- `clone/user/user.lpc` 的 `accept_kill()`：`is_killing(ob)`
  传入了一个物件而 `is_killing()` 期望的是字符串 id（AGENTS.md
  §7.50，这是第三个独立发现同一个 bug 的血统），导致整个玩家身体类
  无法编译，注册流程卡死。已改为 `is_killing(ob->query("id"))`。
- 三个纯 socket 功能的守护进程在 WASM 下无法编译，按"禁用整个文件
  的入口点"的方式清空为 no-op（§7.52）：
  - `adm/daemons/versiond.lpc`（~2200 行的版本同步守护进程）：
    `in_server()`/`connect_server()`/`send_command()`/
    `send_client_pending_msg()`/`syn_finish()`/`in_listen_callback()`/
    `in_write_callback()`/`in_close_callback()`/`cmd_close()`/
    `send_pending_msg()`/`send_result()`/`clear_syn_info()` 内的
    `socket_close()` 分支，共 12 处——这个文件不是"多功能大文件"的
    例外情况（`is_version_ok()`/`is_release_server()` 等非 socket
    函数被 `questd.lpc` 等广泛调用），但整个文件因为散落各处的
    `socket_*` 调用无法编译，实际上在运行时导致
    `collect_all_quest_information()` 崩溃——之前的记录把这个当作
    "非致命错误，保持原样"是不准确的。
  - `adm/daemons/payd.lpc`（HTTP 充值回调服务器）。
  - `adm/daemons/network/dns_master.lpc`（跨服 intermud UDP 层）。

## 深度功能测试补充修复（2026-08-08，§10.7）

- `adm/simul_efun/file.lpc` 的 `log_file()` 一直是裸的 `write_file()`，
  没有调用同一份文件里紧邻定义的 `assure_file()`（AGENTS.md §7.11）；
  每一条新连线最先执行的 `clone/user/login.lpc::logon()` 就会调用它
  写 `/log/nosave/logon`。此前的记录说"创建了缺失的 /log/nosave 目
  录"只是治标：那个目录从未被 git 追踪（`.gitignore` 把整个
  `libs/*/work/log/` 当运行时状态排除），只是恰好还没在某次 checkout
  中丢失过。已在 `log_file()` 里补上 `assure_file(LOG_DIR + file);`，
  并在文件顶部加一行 `assure_file()` 前向声明（否则整个
  `simul_efun`/`master` 编译失败）——live 验证：临时清空
  `work/log/nosave/` 后重启驱动，新连线不再卡死，目录被自动重建。
- `efun::message()` 的 0 值 `exclude` 参数问题：核实后确认
  `adm/simul_efun/message.lpc` 的 `message()` 函数体本身就有
  `if (!exclude) exclude = ({});` 防护，属于彻底根治，不是像
  `zjdywzb`/`yhwhpublicfi`（AGENTS.md §7.88）那样"包装函数漏标
  `varargs`、部分调用点参数不足"的破损形状——这份代码从一开始就没
  有这个漏洞，此前的 WASM 笔记"已修复"这个说法是准确的。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里；账号本身通过正常注
册流程创建。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/zjmudhell
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40204**。
