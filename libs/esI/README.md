# 东方故事 — esI（"屠龙之战"）

## 游戏名称

**东方故事**，站内活动主题为"屠龙之战"（Dragon Slaying War）。与本批次
的 `es1_win`（东方故事·蓝天版）同属 **ES / TMI 引擎家族**，两者核心代码
几乎一致，仅站点内容与分支细节不同。虽然中文名字带"故事"二字容易让人
联想到武侠，但实际是西式奇幻/DND 风格的世界观。

## 简介

游戏世界与 `es1_win` 相同：多种族（人类、精灵、矮人、半兽人、地精等）、
多职业公会（骑士、法师、牧师、武僧、学者、盗贼）的西式奇幻冒险 MUD。
本档案额外开启了"新角色自动获得巫师（管理员）身份"的测试期配置，
说明这个快照原本是用于内部测试/性能压测的版本。

## 如何运行

```
cd libs/esI
~/src/fluffos/build-debug/src/driver config.fluffos
```

服务器监听端口：**40010**。

## 如何连接游玩

```
python3 scripts/mudclient.py 127.0.0.1 40010 --timeout 25 --idle 0.5 \
  --send "" --send "英文名字(纯小写字母)" --send "y" \
  --send "你的中文名字" --send "密码" --send "确认密码" \
  --send "m" --send "职业种族(如human)" --send "\$" --send "真实姓名(可留空)" \
  --send "look" --send "score"
```

注册流程与 `es1_win` 完全一致：英文登录名 → 确认新建角色(y/n) → 中文
名字 → 密码 → 确认密码 → 性别(m/f/n) → 种族(英文单词，如 `human`) →
邮箱(无则填 `$`) → 真实姓名(可留空) → 正式进入游戏。

也可使用普通 telnet：`telnet 127.0.0.1 40010`。

## 已知问题

- 这份快照默认开启了"新角色自动获得巫师权限"的选项（原始测试用配置），
  实际游玩时每个新建角色都会带有管理员权限，如果只是想体验普通玩家
  视角，可自行忽略这项特权或不使用管理命令。
- （已修复）此前和 `es1_win` 一样，登录时会打印一行历史遗留的调试
  信息（"aadsaaaaaaaaaaaaaaaaaaaa"），本轮已删除；同时修复了退出
  （`quit`）指令偶发的运行时报错（`get_include_path`/`ROOM` 路径相关，
  详见 NOTES.md）。
- 部分年代久远的模板区域内容不完整，但不影响主线的种族/职业/公会玩法。
- **WASM 兼容性**：已在新的 WASM 构建下测试，注册、`look`、`quit`
  均可正常完成（本版本 IP 检查不阻挡登录，未受已知的
  `query_ip_number()` WASM 限制影响）。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: 完整管理员（FULL ADMIN）。`/adm/etc/groups` 将
  `fluffos` 加入 `(root)` 与 `(admin)` 组，连线档
  `data/std/connection/f/fluffos.o` 设置 `wizard 1` 与 `domains`
  (primary=wiz, level=archwizard)。已验证 `update /adm/daemons/statsd`
  更新并重载成功。
- ⚠️ **公开架站前请务必修改此默认密码。** Change this published default
  password before hosting publicly.
