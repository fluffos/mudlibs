# 火云 (hy3)

游戏内标题为"火云录2000"（Huo Yun Lu 2000），ES/金庸题材血统的
mudlib。

**血统说明**：`hy3` 这个 slug 和 `hy`/`hy2000`/`hy2002`（"海洋"题材）
共享前缀，但经逐一 diff `master.lpc`/`securd.lpc`/`securityd.lpc` 核
心档案确认，两者**不是同一血统**——只是碰巧同属"ES2 衍生、金庸题材"
这一大类武侠泥巴（和 AGENTS.md §11 里其它十几个共享山头/门派命名但
互不相关的成员一样）。`hy3` 的 `master.lpc` 是完全不同的结构（署名
"change by xhh"，363 行 vs. hy 系三份字节级相同的 332 行"for ES II
mudlib"版本），`securityd.lpc` 署名"xingyun 设置 on 2002.1"，`u/`
下的巫师目录（`xingyun`/`xingyu`/`hsly`）自成一体，指向一个独立维护
的代码库。详见 `NOTES.md` §10.7 深度功能测试记录的完整比对过程。

## 内容亮点

- 门派地图之外，还有独立的"杀手楼"（`d/shashou/`）势力和 `d/marry/`
  结婚玩法，和本轮见过的其它几份武侠泥潭是同一类社交/黑道路线扩展。
- 自带一套真实设计合理的防盗号机制：管理员从白名单外的 IP 登录会
  被要求当场算一道随机数学题才能通过（不是 bug，是这份档案自己的
  安全设计）。
- 本次修复中最难定位的一个 bug 出在 `master.lpc` 的
  `valid_read()`/`valid_write()`：它无条件用 `previous_object()`
  覆盖驱动传入的 `user` 参数，导致玩家自己的人物身体类在注册流程中
  编译时被误判为低权限用户而拒绝读取——整个注册流程会在设定完性别
  后悄无声息地卡死，没有任何可见报错，只有用 `catch()` 包住可疑调
  用才能看到真正的错误信息。
- 深度功能测试（§10.7）中发现并修复了一个更严重的连线拒绝 bug：
  管理员自定义的 IP 黑名单检查把反向 DNS 主机名（而不是 IP 地址）
  传给了一个只认点分四段 IP 格式的判断函数，导致几乎每一次连线（包
  括本地测试）都会被误判为"被封"而立即断线，选完编码、连英文 id
  提示都看不到——详见 AGENTS.md §8.14。

## 注册流程

连线后选择编码 GB/BIG5（本次验证两种选项都能正常显示中文，未发现
编码问题）→ 英文 id（3-7 个小写英文字母）→ 确认建立新角色（y/n）
→ 中文名字（1-5 个汉字，直接输入完整姓名）→ 密码 → 确认密码 →
天赋数值（随机产生，需再输入 y 接受这组数值）→ 电子邮件地址 →
性别（m/f）→ 进入游戏世界。

## 本次修复的关键 bug

- `adm/simul_efun/chinese.lpc` 的 `is_chinese()`：经典的 GBK 字节
  区间判断 bug（AGENTS.md §8.1）。这个档案有一个死代码副本
  `adm/single/chinese.lpc` 早就已经改成正确的码点判断（属于
  AGENTS.md §7.56 的"两个文件都像是对的那一个"陷阱），但真正被
  `adm/obj/simul_efun.lpc` 引入编译的那份 `adm/simul_efun/` 版本仍
  然是旧的错误逻辑，已经修正。
- `adm/daemons/logind.lpc` 的 `check_legal_name()`：同样经典的
  GBK 字节区间长度假设 bug——长度界限按字节数写成
  `strlen(name)<2||>10`（应为按字符数 `<1||>5`）、`i%2==0` 的双
  字节对齐门槛、以及 `name[i..<0]` 尾部切片判断全部失效。
- `adm/obj/master.lpc` 的 `valid_read`/`valid_write`：这是本次修
  复中最难定位的 bug（新增 AGENTS.md §7.59 变体）。这两个函数不
  分青红皂白地把驱动传入的 `user` 参数替换成
  `previous_object()`，包括 `func=="load_object"`/`"include"` 这
  两种驱动本应传入 root 身份（`master_ob`）的编译场景。结果是：
  玩家自己的人物身体类（`clone/user/user`）在注册流程中编译时，
  安全daemon 收到的 `user` 变成了玩家自己而不是 root，被当作低权
  限用户拒绝读取 `/adm/daemons/` 下的文件——整个注册流程在设定完
  性别后就悄无声息地卡死，没有任何可见的报错信息（只有用
  `catch()` 包住可疑调用才能看到 `*Read access denied.`）。修法
  和原本的 §7.59 一致：只对 `load_object`/`include` 这两个 func
  跳过 `user` 的替换。
- `adm/daemons/wzd_log.lpc` 的管理员异地登录验证：这个档案对连线
  IP 用 `regexp()`（真正的正则表达式，不是通配符）做白名单比对。
  最初尝试用通配符语法 `"*.*.*.*"` 把测试管理员账号加入白名单，
  结果因为无效的正则语法而崩溃，同样没有任何可见错误，静默地终
  止了 `wzd_log()` 剩下的代码。已改用合法正则 `".*"`。**注意**：
  从白名单以外的 IP 用管理员身份登录，本来就会要求当场计算一道
  随机数学题（这是真实存在、设计合理的防盗号功能，不是 bug），
  本次为了本地测试方便，直接把标准测试管理员账号加入白名单绕过
  了这道题，而不是尝试在线求解。
- `adm/daemons/logind.lpc` 的连线 IP 黑名单检查（AGENTS.md §8.14，
  §10.7 深度功能测试新发现）：`BAN_D->is_banned(query_ip_name(ob))`
  传的是反向 DNS 主机名，但 `is_banned()` 内部用
  `sscanf(site, "%s.%s.%s.%s", ...)` 只认点分四段 IP，解析失败就
  `fail-closed` 判定为"被封"——本地回环地址反向解析成
  `"localhost"`（没有"."），导致几乎每次连线（包括本地测试）都被
  立即断线，选完编码提示都看不到，`debug.log` 无任何报错信号。已
  改为 `query_ip_number(ob)`，让函数收到它本来就期望的 IP 字符串。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里（已包含
`fluffos (admin)` 一行）；账号本身通过正常注册流程创建。**注意**：
2026-08-08 的 §10.7 深度功能测试发现此前 `wizlist` 授权虽已提交，但
`fluffos` 角色存档（`data/{login,user}/f/fluffos.o`）此前从未真正落
盘（可能是早前只在 WASM 内存沙箱里测试过、从未在原生驱动上真正注册
并提交），本次已用标准密码 `Mud@2026` 重新走完整注册流程创建并提交
存档，`update` 指令验证写权限正常，同一账号断线重连第二次（AGENTS.md
§8.13 检查）也确认无死锁。已在游戏内确认 "目前权限：(admin)" 显示
正确（会自动带到"巫师休息室"）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/hy3
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40162**。
