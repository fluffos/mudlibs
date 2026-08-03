# 侠客行2000最新版 (xkx2000zxb)

侠客行Ⅰ（"The Quest of Oriental Chivalry"），XiaKeXing Gaming
Group 1996-1999，MudOS v22b25 世系，由 sdong 移植。`jym`（金庸梦）
共享同一套地图骨架（`d/taihu/gumu/houtang.lpc` 等场景内容相同，
只是文件头"破解"署名不同：这份是"Cracked by Kafei"，`jym`/`xkm`
都是"Cracked by Roath"），应是同一款底层代码库的不同流通版本。

## 内容亮点

- 1996-1999 年 MudOS v22b25 世系的老牌"侠客行I"，地图涵盖华山、武
  当、少林、丐帮、峨嵋、慕容、终南等经典门派地标，以及洞庭湖、太
  湖、黄山、西夏等地理场景。
- 注册时需要先选择 GB/BIG5 编码，是这批老档案里典型的两岸三地共用
  设计。
- 管理员权限的存储方式很特别：既不是常见的 `wizlist` 文本文件，也
  不是 `securityd.lpc` 里的表格常量，而是一份纯文本 mapping 存档
  （`data/securityd.o`）——而且已有管理员账号被硬编码锁定在特定
  局域网 IP（`192.168.0.40`），换了地址登录会被直接拒绝（详见下方
  管理员账号说明）。

## 本次修复的关键 bug

1. **§7.52 从零手写的 HTTP 服务器**：`adm/daemons/network/http.lpc`
   （经典的 Truilkan/Jacques Interstice `httpd.c`，和 AGENTS.md 里
   `mnhf` 那份是同一血统）直接呼叫
   `socket_create()`/`socket_bind()`/`socket_close()`，没有任何存
   在性判断，导致整个档案在 WASM 下编译失败。搜过了整个代码库，没
   有任何其他文件呼叫这个精灵，所以按 §7.52 的默认做法，把每一个碰
   socket 的函式（`setup()`、`write_data_retry()`、
   `store_client_info()`、`listen_callback()`、
   `close_connection()` 里的 `socket_close`）都掏空成空函式，而不
   是一个一个补呼叫点。
2. **§8.1 `check_legal_name()` bug**：`adm/daemons/logind.lpc` 用字
   节数长度上限（2-8，原意是 1-4 个字）加上 `i%2` 奇偶门槛，还有一
   个**破坏性的"修正"骇客**——只要（已经被作者自己注释掉的）
   `is_chinese` 检查判定某个字符不是中文，就 `name[j]+=128`，在
   UTF8 码点索引下这会直接把合法名字的字符搞坏。已把长度上限改成
   字符数 1-4，并且彻底删掉这个 `+=128` 的破坏性副作用（原本的
   `is_chinese` 拒绝逻辑本来就是注释掉的，这里只是去掉遗留下来的
   破坏性动作，没有恢复任何主动校验）。`adm/simul_efun/
   chinese.lpc` 里真正的 `is_chinese()` 本身已经是正确的码点区间
   检查。

## 管理员账号 / Admin account

这份档案的管理员权限**不是**从 `adm/etc/wizlist`/`wizlist.h` 读取
的（这两个文本文件在实际代码里完全没被引用，纯属遗留）——真正的
数据来源是 `securityd.lpc` 自己的存档文件
`data/securityd.o`（一份纯文本的 mapping 存档格式）。已经直接编辑
这个存档，往 `wiz_status` 和 `wiz_sites` 里加入 `fluffos` 条目
（权限 `(admin)`，站点正则 `.*` 不限制来源地址——注意已有的
`waiwai`/`xgslxz` 管理员账号被锁定在 `192.168.0.40` 这一个特定地
址，`logind.lpc` 的 `get_id()` 会对任何有巫师等级但 `wiz_sites` 里
没有条目的账号一律拒绝登录，所以新增账号必须显式给一个站点正则）。

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，`wizlist` 命令确认显示"目前权限：
  (admin)"，且未被站点检查拒绝。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/xkx2000zxb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40140**。
