# 书剑3

从一个嵌套压缩包中提取（外层压缩包同时打包了一个 Android 客户端 apk
和这份 `shujian3.zip` 源码）；和 bxsj/bxsj1 及其他任何一个已有 lib 都
没有 master-hash 匹配。原生启动干净，零修复，但 WASM 下的完整注册→
游戏→退出流程需要下面这些真正的修复。

## 内容亮点

- 名字带"书剑"，但和 `bxsj`/`bxsj1` 及本项目里任何其它档案都没有
  master-hash 匹配，是完全独立的一份代码库——原始压缩包甚至和一个
  Android 客户端 apk 打包在一起，配合下面的自定义手机协议使用。
- `d/fuben/` 提供实例化副本内容，`d/music`/`d/group` 分别是音乐/
  帮会相关场景，比单纯的门派+地图结构更丰富。
- 本次修复中发现两个此前完全没有暴露过的严重 bug：`securityd.lpc`
  的 `valid_read()` 会在任何真实玩家连线时无条件拒绝所有代码编译，
  导致新账号无法注册——这是原始归档里真实存在的缺陷，只是恰好被
  这次 WASM 排查过程揪出来；`commandd.lpc` 的指令表重建逻辑因为
  匹配的是转换前的 `.c` 后缀，导致包括 `look`/`score`/`quit` 在内
  的**所有玩家指令**都失效，游戏事实上完全无法操作（详见下方 bug
  修复说明）。

## 注册流程（手机 App 协议）

这是一个自定义的手机客户端协议，不是标准的一问一答式注册：

1. 连线后驱动立刻无条件打印一次 `ver1.0,<key>` + `版本验证成功` 的握
   手横幅（不需要任何输入触发）。
2. 一次性发送 `账号,密码,密文,email`（英文逗号会被自动替换成 U+2551
   `║`）——账号/密码/邮箱一起提交，密文字段目前未做真正校验。
3. 如果是新账号，紧接着发送 `性别║图片║中文昵称`（这一步**只**用字面
   `║` 分隔，不会做逗号替换），例如 `m║img1║秦风`。

## 本次修复的关键 bug

- `adm/daemons/logind.lpc`：`create()`/`make_body()` 里的
  `seteuid(getuid())` 会把刚设置好的 euid 重置掉，已改为显式
  `seteuid(ROOT_UID)`。
- `check_legal_name()`：沿用旧版 GBK 字节长度界（`< 4 || > 8`、按
  2 字节跳步判断），已改为按字符数（2-4）+ 逐字符 `is_chinese()`
  判断；`adm/simul_efun/chinese.lpc` 的 `is_chinese()` 本身也从旧版
  GBK 字节区间判断（`str[0]>=176/161...`）改为 Unicode 码点判断
  （`0x4e00`-`0x9fff`）。
- `adm/daemons/named.lpc`：`valid_name()` 里逐 2 字节跳步、截取
  4/6 字节子串的近似重名检测循环，已改为逐字符跳步、截取真实字符子
  串。
- `adm/daemons/band.lpc`：`is_banned()` 补上本地/WASM 回环地址放行判
  断（放在严格的四段式解析之前，避免 `::1` 被误判为非法格式而拒绝）。
- `adm/daemons/payd.lpc`（HTTP 充值回调服务器，纯 socket 功能）：
  `setup()`/`store_client_info()`/`listen_callback()`/
  `close_connection()` 四个函数都直接调用 `socket_*`，WASM 下无法编
  译；按"整个文件的入口点直接禁用"的方式把这四个函数体清空为
  no-op（而不是逐个删除 `socket_*` 调用点），其余业务逻辑
  （`do_get()` 的充值处理）保持不变。
- **两个此前未被记录过的、真正会挡住每一个新玩家注册的 bug**：
  1. `adm/daemons/securityd.lpc` 的 `valid_read()` 会无条件地用
     `this_player()` 覆盖驱动传入的 `user` 参数。但驱动对
     `"load_object"`/`"include"`（编译代码、处理 `#include`）这两种
     调用传入的 `user` 本来就是 `master_ob`（root 权限）——被替换成当
     前连线的低权限玩家对象后，只要有人连着线，**任何代码编译**（包
     括编译 `USER_OB` 本身、以及它引用的每一个 `#include`）都会被拒
     绝，直接导致新账号无法完成注册（`*Read access denied.`，报错发
     生在 `logind.lpc` 的 `make_body()` 里 `new(USER_OB)` 这一行）。
     已修复为：仅当 `func` 不是 `"load_object"`/`"include"` 时才用
     `this_player()` 覆盖。这是一个真实存在于原始归档里的 bug（只要
     有真实玩家连线就会触发，和 WASM 沙箱本身无关），只是恰好被这次
     WASM 排查过程发现。
  2. `adm/daemons/commandd.lpc` 的 `rehash()` 用
     `sscanf(cmds[i]+"$", "%s.c$", cmds[i])` 从 `get_dir()` 的结果里
     筛出以 `.c` 结尾的命令文件——这是转换前 MudOS 的旧扩展名。本项目
     的 `convert_lib.sh` 把所有源文件批量改名成 `.lpc`，但它的正则修
     复只处理形如 `"foo.c"`（引号收尾）或 `#include <foo.c>` 这两种
     写法，管不到嵌在 `sscanf` 格式串里的 `"%s.c$"`（美元号收尾，不
     是引号）。结果是 `rehash()` 每次都把 `cmds` 目录下的全部条目过
     滤成空，`search[dir]`/`user_cmds[dir]` 永远建立不起来，
     `find_command()` 对任何动词都返回 0——**每一条玩家指令（look /
     score / quit / 任意指令）都会落到驱动默认的"什么？"提示**，游戏
     实际上完全无法操作。已改为 `"%s.lpc$"`。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里（标准 XKX/ES2 系
`securityd.lpc` 机制）；账号本身通过正常注册流程创建。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/shujian3
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40200**。
