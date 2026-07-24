# 风云Ⅳ — fengyun434

## 游戏名称

**风云四**（风云Ⅳ，Sumxin 风云工作室出品）。属于本批次的 **"风云"
（Fengyun）武侠引擎家族**，与 `fy2`、`fy2005`、`fengyun2qinghua`、
`fengyun3xiuding`、`fengyun3dianzang` 等同属一个核心引擎，各自是不同
站点/年代的内容分支。

## 简介

以古龙武侠小说为背景的江湖世界。玩家扮演一位刚踏入江湖的普通百姓，
选择民族（汉族/苗族/满族/蒙古族，不同民族对应不同的初始属性倾向和
出生地点），闯荡由古龙笔下人物、门派与恩怨编织的武侠天地。游戏强调
角色养成与门派归属，是典型的"风云"系武侠 MUD 玩法。

## 如何运行

```
cd libs/fengyun434
~/src/fluffos/build-debug/src/driver config.fluffos
```

服务器监听端口：**40011**。

## 如何连接游玩

```
python3 scripts/mudclient.py 127.0.0.1 40011 --timeout 25 --idle 0.5 \
  --send "0" --send "英文名字(3-8位纯小写字母)" --send "y" \
  --send "你的中文名字" --send "密码(需含大小写字母)" --send "确认密码" \
  --send "邮箱" --send "m" --send "0-3选择民族" \
  --send "look" --send "score"
```

连接后会先看到一个 **编码选择提示**（输入 `0` 表示国标码 GB，`1` 表示
大五码 BIG5）——这是这批老式 MUD 常见的历史遗留提示，**普通玩家直接
输入 `0` 即可**，不用理会。之后依次是：英文登录名（3-8 位纯小写字母）
→ 确认新建角色 (y/n) → 中文名字 → 设置密码（需同时包含大写、小写字母
及数字/符号，且不能与英文名太相似）→ 确认密码 → 邮箱 → 性别(m/f) →
民族选择（0=汉族/1=苗族/2=满族/3=蒙古族，决定出生地点）。完成后正式
进入游戏。

也可使用普通 telnet：`telnet 127.0.0.1 40011`。

## 已知问题

- 极少数装备类文件引用了未定义的常量，属于原始存档本身遗留的小缺口，
  不影响主线剧情与登录、创角、日常指令的使用。
- **WASM 兼容性**：已在新的 WASM 构建下完整测试，注册、`look`、`quit`
  均可正常完成（本轮已提前应用了同引擎家族的安全管理进程域名解析
  修复，未触发相应的登录报错）。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 最高级别，通过 `/adm/etc/wizlist` 中的
  `fluffos (admin)` 行授权。本版本还有一个巫师登录 IP 白名单机制
  （`/adm/etc/wizip/<id>`，无文件则不限制；本地/回环地址已一律放行）。
  已验证 `update /adm/daemons/combatd` 重新编译成功。
- ⚠️ **公开架站前请务必修改此默认密码。** Change this published default
  password before hosting publicly.
