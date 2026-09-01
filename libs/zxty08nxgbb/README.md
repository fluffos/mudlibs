# 再现天涯（08年修改版本）

与 `zxty` 同一款游戏（"再现天涯"，本项目"天涯"家族的一员，完整谱系见 `zxty` 词条）的 2008 年修改重发布版本，地图内容基本一致，master.lpc 有改写、无精确 hash 匹配。`quit` 指令带有真实的反滥用设计——登录不满 30 分钟的新账号退出时必须连按两次才会真正退出且不存档；注册室实现（`named.lpc`）经核实和本项目 NT/nitan 系家族（如 `nt1`）共享同一套设计，而不只是和 `zxty`/`jym` 同源，是"天涯"家族与 NT/nitan 系之间此前未被记录的一处基础设施交集。

## 注册流程

`new` 触发注册 → 英文 id（3-14 个英文字母）→ 确认创建（y/n）→ 中文
名字（1-5 个中文字，留空则随机取名）→ 管理密码（≥5 字元）→ 确认管理
密码 → 普通密码 → 确认密码 → 天赋数值选择（0-4，0 为随机）→ 天赋确认
（y/n）→ 电子邮件地址 → 性别（m/f）。

`quit` 有反滥用机制：登陆不满 30 分钟的新号退出时会提示"再按 2 次
Quit 才会真正退出且不存档"——这是设计如此，不是 bug。

## 本次修复的关键 bug

- `adm/daemons/logind.lpc`：与 nt1/hy 系同款的 euid 被中途重置的
  bug——`make_body()` 里的 `seteuid(getuid())` 会把 `create()` 刚设置
  好的 euid 重置为空字符串。已改为显式 `seteuid(ROOT_UID)`。
- `check_legal_name()`：沿用旧版 GBK 字节长度界及隔位 `is_chinese()`
  判断，已改为按字符数（1-5）+ 逐字符判断。
- `adm/daemons/named.lpc`：与 nt1 完全相同的两处 bug——
  `invalid_new_name()` 拒绝单字名字为"空名字"，以及基于字节偏移步进
  的相似名字滑窗检测算法。均已按字符数重写（这条代码线和 NT/nitan 系
  共享同一套 `named.lpc`/注册室设计，不只是与 jym 同源）。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里（`securityd.lpc` 每
次启动都会重新读取这个文件），格式为 `id (level)`，与本项目大多数
lib 的标准做法一致。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/zxty08nxgbb/

## 本地运行

```
cd libs/zxty08nxgbb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40193**。
