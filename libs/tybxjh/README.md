# 天涯之碧血江湖 (tybxjh)

天涯泥潭（Tianya MUD Wizard Group）的"碧血江湖"档案，自 2002 年建
站运行至今的老牌武侠 MUD。这份档案在 WASM 下**编译/登录流程本身无
需修复**——没有编译错误，没有执行时段错误，整个登录/注册流程一次
跑通；但深度功能测试（§10.7）发现了好几个真实存在的程序 bug，包括
一个从建站至今就存在的严重安全问题，详见下方"深度功能测试"一节。同一
个"天涯"代码家族还有 `wlhd`（武林浩荡/金庸梦II，`master.lpc`/
`securityd.lpc`/`logind.lpc` 核心系统档案结构几乎一致，但地图内容
各自独立修改过）、`xhcii`（笑红尘Ⅱ）、`zxty`（再现天涯）、
`ffxymud`（非凡夕阳MUD/时空游侠录）、`jhfy2`（江湖风云2）、
`xysylmhb`（夕阳三-炎龙美化版）、`xyzxiiylzymh`（夕阳再现II-炎龙
专用美化客户端）和 `yzxiiizylfy`（夕阳再现III之炎龙封印）——后三
者标题都带"夕阳再现"但地图其实是这个家族（真正的"夕阳再现"血统是
`xyzx`/`jhfy3`/`xajh4gkb`/`xyzxyl201412` 那一支完全不同的代码）。
除 `wlhd`/`yxjh` 外，这七者的 `d/city/sj.lpc`（"世界之巅"跳崖场
景）逐字节完全相同；`wlhd`/`yxjh` 用的是 `wlhd` 独立改写过的
"jump"版本，`ffxymud`/`xysylmhb`/`xyzxiiylzymh`/`yzxiiizylfy` 连登
入横幅/标题都完全不像同一批档案，如果不比对源码很难发现它们同源。

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

WASM 修复阶段没有发现需要修复的程序 bug。唯一做的事情是在
`/adm/etc/wizlist` 里加入管理员账号（`SECURITY_D` 正确指向
`/adm/daemons/securityd`，`u/zjb/securityd.lpc` 是没有被实际引用的
分身档案）。

顺带一提，`securityd.lpc` 的 `get_status()` 对四个特定账号
（`daniel`/`zjb`/`kjh`/`jiji`）写死返回最高的 `(boss)` 权限，不受
wizlist 内容影响——这是站方创始人账号的既有设计，不是 bug，也不
影响 `fluffos` 账号的权限。

深度功能测试（§10.7）发现这个"无需修复"的结论过于乐观——这份档案是
`wlhd`（武林浩荡）等一批同源档案的原始代码库，`wlhd` 自己已经确认
的 2 处 printf 调试残留、§8.9 食物/饮水年龄检查错对象、
`exert_function()` 类型错误在这里全部命中（后者甚至有 4 处，比
`wlhd` 的 1 处更多，分别废掉了升级师/两份医疗 NPC/转世僧人）；另外
发现一个从未被记录过的**严重安全问题**：注册时设置的管理密码和普通
密码明文被 `logind.lpc` 额外写进 `/doc/help/neima2`/`neima3`——而
`/doc/help/` 正是标准 `help` 指令对任何玩家开放搜索的路径，任何人
打 `help neima2` 就能看到建站以来每个账号的明文密码（已写入
AGENTS.md §7.84）；还有一个进度条渲染 bug，几乎让 `score` 指令的食
物/饮水/气血条无论真实数值都显示"满格"，掩盖了 §8.9 的真实影响（新
增 AGENTS.md §7.85）。详见 NOTES.md。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **管理密码 / Admin password**: `AdminPass123`
- **普通密码 / Regular password**: `LoginPass456`
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  横幅直接显示"您目前权限：(admin)"确认生效。

修正（round-two 深度测试发现）：`feature/dbase.lpc` 的 `set()` 有
一条防劫持保护，会把"这个 id 已经在 wizlist 里登记为 (admin)"错误
地当成"已有一个受保护的旧密码"，导致 `fluffos` 这类"提前播种
wizlist、再走正常注册"的账号在**第一次设置密码时**就被自己的保护
机制拦截，密码从未真正写入存档——修复前虽然注册流程能顺利走完、
`(admin)` 权限显示正常，但用刚设置的密码重新连线会被三次拒绝踢下
线。已修复该逻辑缺陷（只在密码已存在时才触发保护），并用真实的
"设置密码→重新连线"往返验证过。详见 NOTES.md。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

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
