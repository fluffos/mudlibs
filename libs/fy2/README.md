# 风云再起Ⅱ — fy2

## 游戏名称

**风云再起Ⅱ**（河海大学计算机及信息工程学院开发）。属于本批次的
**"风云"（Fengyun）武侠引擎家族**，与 `fy2005`、`fengyun434`、
`fengyun2qinghua`、`fengyun3xiuding`、`fengyun3dianzang` 同源——其中
`fengyun2qinghua`（"清华仿写版"）经核实其实就是本档案的另一个转发
副本，源码完全一致。

## 简介

以古龙武侠小说为背景的江湖世界，玩家在凤求凰客栈或沉香镇等地起步，
选择民族（汉族/苗族/满族/蒙古族）扮演一位初出茅庐的江湖新人，通过
江湖历练、拜师习武、行走门派逐步成长。是"风云"系武侠 MUD 早期、
较为经典的一个分支版本。

## 如何运行

```
cd libs/fy2
~/src/fluffos/build-debug/src/driver config.fluffos
```

服务器监听端口：**40014**。

## 如何连接游玩

```
python3 scripts/mudclient.py 127.0.0.1 40014 --timeout 25 --idle 0.5 \
  --send "英文名字(3-12位纯小写字母)" --send "y" \
  --send "你的中文名字(或直接回车要随机名字)" --send "y(确认满意这个名字)" \
  --send "密码(需含大小写字母)" --send "确认密码" --send "邮箱" \
  --send "m" --send "0-3选择民族" \
  --send "look" --send "score"
```

连接后直接会看到"您的英文名字："提示，无需其他隐藏前置关卡。依次
输入：英文登录名（3-12 位纯小写字母）→ 确认新建角色 (y/n) → 中文
名字（可以直接回车让系统随机取一个）→ 对该中文名满意与否 (y/n) →
设置密码（需同时含大写、小写字母及数字/符号）→ 确认密码 → 邮箱 →
性别(m/f) → 民族（0=汉族/1=苗族/2=满族/3=蒙古族，决定出生地点）。
完成后正式进入游戏，凤求凰客栈的店小二会热情招呼你。

也可使用普通 telnet：`telnet 127.0.0.1 40014`。

## 已知问题

- 少数盔甲类文件引用了未定义的常量，属原始存档遗留的小缺口，不影响
  正常游玩。
- 系统内部的"表情"守护进程有一份种子存档文件带有少量无法识别的字符，
  开服时会有一条无害的内部错误提示，不影响正式游戏功能。
- （已提前修复）与 `fengyun2qinghua` 相同分发版本共有的一处极端情况
  `quit` 报错问题，本轮已提前修复。
- **WASM 兼容性**：已在新的 WASM 构建下完整测试，注册、`look`、`quit`
  均可正常完成，无任何报错。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 最高级别。通过 `/adm/etc/wizlist` 中的
  `fluffos (admin)` 行授权（securityd 启动时读取该文件），登录时
  `feature/command.lpc` 依据 wizhood 自动 `enable_wizard()` 并设置
  ADM_PATH。已验证 `update /adm/daemons/combatd`（重新编译系统守护
  进程）成功。
- ⚠️ **公开架站前请务必修改此默认密码。** Change this published default
  password before hosting publicly.
