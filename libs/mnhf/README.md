# 模拟华附 (mnhf)

以广州市华南师范大学附属中学为背景设定的校园题材 mudlib。

## 内容亮点

- 和 `yxsj`/`yxzsj`（台湾"逸俠之世界"的校园+霹雳布袋戏设定）一样是
  校园题材，但这份档案是纯粹的大陆真实中学校园模拟——地图（`d/
  huafu/`）以"华附"教学楼、宿舍、电脑房、图书馆等真实校园场景为
  蓝本，没有任何武侠/奇幻元素。
- 角色创建有独立的"人物类型"选择（聪明好学型/活泼可爱型/冷静细心
  型/身高力壮型），呼应校园生活模拟的定位，而不是常见的门派/种族
  选择。
- 密码规则要求同时包含大小写字母和数字，本次测试账号密码也因此从
  项目惯用的 `Mud2026Adm` 改成了符合这份档案规则的 `Test1234`（详
  见下方管理员账号说明）。

## 注册流程

英文名字（3-10 个英文字母）→ 确认建立新角色（y/n）→ 中文名字（直
接输入真名，或直接按 Enter 交给系统随机产生）→ 密码（至少 6 位，
必须同时包含大写字母、小写字母、数字，且不能与英文名字过于相似）
→ 确认密码 → 电子邮件地址 → 性别（m/f）→ 人物类型（0 聪明好学
型、1 活泼可爱型、2 冷静细心型、3 身高力壮型）→ 进入游戏世界。

## 本次修复的关键 bug

- `cmds/usr/uptime.lpc`：`write(read_file("/log/nosave/LASTCRASH"))`
  （AGENTS.md §7.54 一类的 bug）——全新存档里这个档案根本不存在，
  `read_file()` 会返回 0，`write(0)` 就会崩溃报
  `Bad argument 1 to receive()`。因为 `UPTIME_CMD->main()` 是每次
  连线 `logon()` 里、显示英文名字提示之前就会执行的，所以这个 bug
  会让**每一次连线**都在还没看到提示前就直接崩溃断线。已加上
  `stringp()` 判断再决定是否 `write()`。
- `adm/daemons/httpd.lpc`（AGENTS.md §7.52）：`socket_create()`/
  `socket_bind()`/`socket_accept()`/`socket_write()`/`socket_close()`
  在这个 WASM 编译版本里都是未定义的 efun，导致整个档案编译失败
  （"No program in object"），而且是在开机预载阶段就会发生，比上面
  那个 uptime bug 还要早出现。因为这个 daemon 存在的唯一目的就是
  跑一个基于 socket 的 HTTP 网页服务器，按项目一贯做法直接把
  `setup()`/`write_data_retry()`/`store_client_info()`/
  `listen_callback()`/`close_connection()`/`remove()` 整批清空，而
  不是一个一个呼叫点去修补——网页服务器功能在 WASM 试玩范围内本
  来就用不到。

没有发现 Chinese 姓名判断、宏定义或指令表相关的 bug——
`is_chinese()` 本来就是正确的 Unicode 码点判断。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Test1234`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里；账号本身通过正常
注册流程创建，已在游戏内确认 "目前你的权限为：(admin)" 显示正确。
密码用 `Test1234` 而不是本项目惯用的 `Mud2026Adm`，是因为这份档案
自己的密码规则要求必须同时包含大写、小写字母和数字，`Mud2026Adm`
缺小写字母，通不过检查。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/mnhf
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40156**。
