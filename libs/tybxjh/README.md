# 天涯之碧血江湖 (tybxjh)

天涯泥潭（Tianya MUD Wizard Group）的"碧血江湖"档案，自 2002 年建
站运行至今的老牌武侠 MUD。这份档案在 WASM 下**完全无需修复**——
没有编译错误，没有执行时段错误，整个登录/注册流程一次跑通。同一
个"天涯"代码家族还有 `wlhd`（武林浩荡/金庸梦II，`master.lpc`/
`securityd.lpc`/`logind.lpc` 核心系统档案结构几乎一致，但地图内容
各自独立修改过）、`xhcii`（笑红尘Ⅱ）、`zxty`（再现天涯）和
`ffxymud`（非凡夕阳MUD/时空游侠录）——后三者的 `d/city/sj.lpc`
（"世界之巅"跳崖场景）逐字节完全相同，`ffxymud` 连登入横幅都完全
不像武侠泥潭，如果不比对源码很难发现它们同源；`wlhd` 这个房间的
具体写法已经被独立改写过（指令改成 `jump`，配上 `valid_leave()`），
但核心系统档案的同源关系不受影响。

## 内容亮点

- 地图几乎覆盖金庸小说的全部门派与地理版图：华山、武当、峨嵋、丐
  帮、明教、逍遥、星宿、天龙寺、少林、昆仑、桃花岛等门派场景一应
  俱全，城池跨越长安、荆州、襄阳、大理、西夏、泉州等地。
- `quest/japan/` 是一整条"抗日"主题任务线，NPC是入侵中国的"东洋
  鬼子"，明确把历史背景（日本侵华）编织进传统武侠世界观，这在同类
  泥潭里并不常见。
- `quest/guojob` 提供团队向的"国家任务"（`teamjob.lpc`、
  `mengbing.lpc`、`mijian.lpc` 等），配合按银两数量分级的悬赏榜
  （`quest/qlist*.lpc`，赏金从 3000 到 200 万不等），是比单人打怪更
  结构化的经济/协作玩法。
- 双密码注册机制（管理密码+普通密码需不同）配合真实存在的 150 秒
  注册超时，是这份档案自己独有的登录设计（详见下方"测试注意事项"）。

## 本次处理内容

没有发现需要修复的程序 bug。唯一做的事情是在 `/adm/etc/wizlist`
里加入管理员账号（`SECURITY_D` 正确指向 `/adm/daemons/securityd`，
`u/zjb/securityd.lpc` 是没有被实际引用的分身档案）。

顺带一提，`securityd.lpc` 的 `get_status()` 对四个特定账号
（`daniel`/`zjb`/`kjh`/`jiji`）写死返回最高的 `(boss)` 权限，不受
wizlist 内容影响——这是站方创始人账号的既有设计，不是 bug，也不
影响 `fluffos` 账号的权限。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **管理密码 / Admin password**: 注册时自设（至少 5 位，且不能与
  普通密码相同）
- **普通密码 / Regular password**: 注册时自设（双密码机制）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  横幅直接显示"您目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 测试注意事项

这份档案有一个真实存在、非测试artifact的 **150 秒注册超时**
（`clone/user/login.lpc` 的 `time_out()`，`LOGIN_TIMEOUT` 定义在
`include/login.h`，从连线那一刻就开始计时，不是每个提示符重置）。
`get_email()`/`get_gender()` 阶段会触发 `/inherit/char/char` 极其
庞大的一次性编译警告洪流，如果测试脚本用较长的 `--idle`（比如
6-15 秒）等待这些警告刷完，反而会撞上这个 150 秒的整体超时被系统
踢下线（显示"您花在连线进入手续的时间太久了"）。用较短的
`--idle 2` 反而能够顺利在超时窗口内完成整个注册流程。

## 本地运行

```
cd libs/tybxjh
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40158**。
