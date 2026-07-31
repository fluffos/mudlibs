# 指尖MUD

从一个嵌套压缩包中提取（`zjmud.7z` 内的 `指间mud服务器+手机版客户端.zip`，
内部文件夹名为 `hell`）——和已有的 hell/zjdywzb（Century 系）无关，
master-hash 不同。和 [shujian3](../shujian3/) 是同一个手机 App 协议、
同一套自定义 `logind.lpc` 血统，但注册流程的严格程度不同（见下）。

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
  AGENTS.md §7.14，`zhongjidiyu_zhijian` 的同类问题）。已改为显式的
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
