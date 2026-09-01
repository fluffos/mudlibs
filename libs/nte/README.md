# 泥潭二 (nte)

ES2/Annihilator 系架构衍生的武侠 mudlib，"泥潭"系列的一支，共 13000+ 个 `.lpc` 文件，属性存储代码为独立编写、并非与 nt6/nt1 分支同源。同样设有"出生仪式"关卡（`d/register/` 区域，`regroom.lpc` 等文件名甚至和 nt6/nt6nitan6win 完全相同），但具体文案与实现各自独立——直接比对内容可确认不是同一份代码，而是"泥潭"系里多个团队各自独立开发出的相近设计范式，地图规模也和 nt6 系相近。

## 本次修复的关键 bug

1. **经典 §8.1 GBK 字节区间 `is_chinese()` 判断错误**，而且是**独
   立复现**的（不是 nt6 那种同源共享代码，是不同代码库各自写出了
   同一类问题）：
   - `adm/simul_efun/chinese.lpc` 的 `is_chinese()` 用字节区间判
     断（`str[i] < 161`、`str[0] < 176` 之类），已改成正确的码点
     区间检查。
   - `logind.lpc` 的 `get_surname()`/`get_name()` 用
     `check_legal_name(arg, 4)`，但提示语写的是"不要超过两个汉
     字"——`4` 是没有减半的旧字节数上限，改成 `2`；姓名组合起来的
     检查 `strlen(fname) < 4` 同理改成 `< 2`。
   - `named.lpc` 的 `invalid_new_name()` 用 `strlen(name) < 2` 判
     断"是否为空名字"，会把任何单字给名（比如"风"）都当空名字拒
     绝，改成 `< 1`。
2. **§1.3e `uptime() < 30` 启动宽限期检查**：`logind.lpc` 的
   `logon()` 一开始就会挡掉这个检查，而 WASM 沙箱每次连线都紧接
   在驱动启动之后，必然触发。已对 `127.0.0.1`（本地/WASM 测试连
   线）放行。
3. **§7.52 socket 精灵编译失败**，这份档案里有两个：
   - `adm/daemons/network/dns_master.lpc`：小型专用 daemon，直接
     整个清空 socket 相关函数。
   - `adm/daemons/versiond.lpc`：大型多功能"版本同步发布"精
     灵，有 32 处其他档案调用它的非 socket 功能（`is_version_ok()`/
     `query()` 等），不能整个禁用；只清空了里面含
     `socket_create`/`socket_bind`/`socket_accept`/`socket_write`/
     `socket_close` 等呼叫的 13 个函数/回调，其余公开接口原样保留。
4. **§7.50 `accept_kill()` 的 `is_killing()` 参数类型错误**：
   `user.lpc` 的 `accept_kill(object ob)` 直接把物件传给
   `is_killing()`，但这个函数要的是字符串 id——和这个档案里其他呼
   叫点用的 `ob->query("id")` 不一致，导致整个 `clone/user/user`
   编译失败（角色创建的 `make_body()` 依赖这个档案）。这是本项目
   里已经在 nt1/wxddym/zjmudhell/hell 独立复现过四次的同一类
   copy-paste bug，改成 `is_killing(ob->query("id"))` 即可。

## 内容亮点

内容与出生仪式详见上方简介；`is_killing()` 参数类型不匹配这一类
bug 在本项目里已经独立出现过五次（`nt1`/`wxddym`/`zjmudhell`/
`hell`，加上这份档案），是同一种复制粘贴笔误在完全不同代码库间反
复出现的典型案例。

## 注册流程

选择编码 GB 或 BIG5 → 英文名字（3-10 个英文字母）→ 确认建立新角
色（y/n）→ 中文姓氏（1-2 个汉字，可留空）→ 中文名字（1-2 个汉
字，姓名合计至少 2 个汉字）→ 管理密码（至少 5 位）→ 确认管理密码
→ 普通密码（至少 3 位，不能和管理密码相同）→ 确认普通密码 → 性别
（m/f）→ 进入游戏世界。

真正的"score"要求角色先完成一段在 `/d/register/` 区域和创世神话
NPC 对话的"出生仪式"才会被标记为"已出生"，和 nt6/nt6nitan6win 是
同一类设计，不是 bug，本次验证范围内没有走完整这段剧情。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `AdminPass1`（管理密码）/ `loginpw1`（普通
  密码，双密码机制）
- **权限 / level**: `(admin)`

管理员身份通过正常注册流程创建，注册完成后已确认自动落在巫师专属
的"巫师休息室"，验证了权限判定正确生效。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/nte
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40115**。
