# 海洋（基础版）

以"金庸小说背景"为世界观的武侠 MUD（请勿使用小说中人名），社区名"情义盟"。

## 内容亮点

- 注册流程：`new` 触发注册 → BIG5 字体确认（y/n，非空即可）→ 英文 id →
  确认创建（y/n）→ 中文名字（可留空由系统随机取名）→ 密码 → 确认密码 →
  天赋数值选择（0-4，0 为随机）→ 天赋数值确认（y/n）→ 电子邮件地址
  （需含 `@`）→ 性别（m/f）。
- 天赋系统：膂力、悟性、根骨、身法，可指定其一或全部随机。
- 深度功能测试（§10.7）完整走通了注册→新手引导（客店→西大街→扬州
  武馆）→中央广场战斗→死亡→鬼门关（白无常五段对话）→复活送回武庙
  的全流程；另用留言板验证了 `look board`/`post` 全链路正常。地图上
  的昼夜可见度是有意设计——夜晚裸方向词（`north` 等）会失效、提示
  "天色太黑了"，须改用 `go <方向>`，不是 bug。虽然和 `hy2000`/
  `hy2002` 同属"海洋"命名，但 master 哈希和已知档案都不匹配，没有确
  认的血统关系（详见 NOTES.md），这次深度测试也确认它并不与两者共享
  同一份 `securd.lpc`/`feature/skill.lpc`，是独立验证出同一类 bug。

## 本次修复的关键 bug

- `adm/daemons/logind.lpc`：`create()` 里设置的 `seteuid(ROOT_UID)` 会被
  后续 `howmany_user()`/`make_body()` 里遗留的 `seteuid(getuid())` 重置为
  空字符串（该 daemon 的真实 uid 从未被正确解析），导致注册流程中途所有
  `read_file`/`log_file` 权限判定失败。已将这两处改为显式
  `seteuid(ROOT_UID)`。
- `howmany_visitor()`/`howmany_card()`：当 `/log/mud/MUDVISITOR`、
  `GIFTCARD` 计数文件不存在时，`read_file()` 返回 `0`，`sscanf(0, ...)`
  直接崩溃中断整个注册流程。由于 `libs/*/work/**/log` 已被 `.gitignore`
  排除，这在全新 clone 的仓库上是真实会复现的首次启动 bug，不只是 WASM
  沙箱的测试假象。已加 `if (!content) return 0;` 防御。
- `adm/daemons/securd.lpc`（真正生效的安全 daemon —— `SECURITY_D` 宏指向
  `securd.lpc`，同目录下的 `securityd.lpc` 是未被引用的遗留重复文件）：
  `get_status()` 里 `member_array(euid, wiz_levels)` 会在该对象自身尚未
  完成变量初始化时被重入调用（`wiz_levels` 声明在 `wiz_status` 之后，
  `create()` 内 `restore()` 触发的 `valid_read()` 链会在此刻重入本对象），
  此时 `wiz_levels` 还是默认值 `0`，导致崩溃。已加 `arrayp(wiz_levels)`
  防御。
- `adm/daemons/band.lpc`：`is_banned()` 加入 loopback 放行判断。
- `is_chinese()`：改为按 Unicode 码点判断（`0x4e00`-`0x9fff`），修正旧版
  按 GBK 双字节假设的判断逻辑。

## 深度功能测试（§10.7）新修复的关键 bug

- **`adm/daemons/securd.lpc` 的 `valid_read()` 没有放行编译期/存在性
  探测操作（AGENTS.md §7.5，两个变体）**：一是经典的 `file_size`（技
  能档案首次被引用时误判"不存在"，中断 NPC `create()`）；二是本次新
  发现、影响面大得多的变体——`get_dir()` 效率函式底层走的是
  `func=="stat"`，没放行导致 `adm/daemons/commandd.lpc`（自己
  `create()` 里从未 `seteuid()` 过）的 `rehash()` 每次 `get_dir()`
  都被拒绝、指令表永远建不起来，**表现为每个玩家的每一条指令（包括
  `look`）都回应驱动器的通用失败讯息"什麼？"**，且没有任何 debug.log
  报错信号。已把 `load_object`/`recompile_object`/`include`/
  `file_size`/`stat` 一起加入放行名单。
- **`adm/daemons/{natured,questd}.lpc` 的 `create()` 从未
  `seteuid()`，导致读取自己的配置表被同一个自定义 ACL 拒绝
  （AGENTS.md 新增 §7.98）**：`read_file()` 被拒绝后返回 `0`，
  `explode(0, "\n")`/`read_table()` 崩溃，报错形状和"档案缺失"类崩
  溃（§7.9/§7.54）一模一样，但两份档案（`/quest/dynamic_quest`、
  `/adm/etc/nature/day_phase`）其实都存在于硬盘上——真正原因是权限
  被拒绝而非档案缺失。已仿照本档案 `logind.lpc` 已有的写法，在两处
  `create()` 开头加 `seteuid(ROOT_UID);`。
- **§8.9 食物/饮水年龄检查错对象**：`logind.lpc` 的 `enter_world()`
  里 `ob->query("age") == 14` 应为 `user->query("age") == 14`（`ob`
  是登录对象，从未被设置过 `age`）。本档案的 `init_new_player()` 会
  在注册最后一步预先把食物/饮水设成非零值，所以这个 bug 之前不会在
  `score` 上表现出来，但仍按标准修法修正，避免未来重构掉那个默认值
  时静默复发。
- **`cmds/usr/uptime.lpc` 的"上次当机原因"显示崩溃**：`main(int i)`
  被以 `int` 参数直接呼叫时（例如巫师用 `call` 指令），
  `write(read_file("/log/nosave/LASTCRASH"))` 在该档案不存在的全新
  安装上会崩溃（`*Bad argument 1 to receive()`）。玩家正常输入
  `uptime`（不带参数）不会触发，但已按 §7.9 惯例加 `stringp()` 防
  御，避免巫师直接呼叫时崩溃。
- **AGENTS.md §7.86（留言板 `post` 崩溃）确认已在更早的一次跨库扫描
  中修复干净**：全档案唯一命中"`inherit BULLETIN_BOARD` 又多余
  `replace_program()`"这个形状的文件是 `clone/board/huashan_b.old`
  ——一份 `.old` 后缀的历史备份，不是驱动器会加载的 `.lpc` 源码，本
  次确认无需改动。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

此代码线的权限系统**不通过** `/adm/etc/wizlist`（该文件从未被
`securd.lpc` 读取，是遗留自旧版本的死代码路径）。管理员名单实际存储在
`adm/daemons/securd.o` 存档文件自身的 `wiz_status` 属性里。授予方式是
直接编辑该存档文件的 `wiz_status` 映射，追加 `"fluffos":"(admin)"`。

> 注意：`securd.o` 用真实的回车符（CR, `\r`）而非换行符对映射键里的
> `/` 做编码，编辑此文件务必使用二进制模式读写，文本模式的换行符转换
> 会静默把 `\r` 转成 `\n`，破坏存档格式（`restore_object(): Illegal
> mapping format`）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/hy/

## 本地运行

```
cd libs/hy
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40182**。
