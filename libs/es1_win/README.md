# 东方故事（蓝天） — es1_win

## 游戏名称

**东方故事（蓝天版）**（英文内部注释常写作 "Eastern Story"）。这是"东方故事"
（ES）系列 MUD 的一个早期基础版本，属于 **ES / TMI 引擎家族**——尽管名字
听起来像武侠题材，实际内容是一个西式奇幻/DND 风格的冒险世界（人类、精灵、
矮人、半兽人、地精等种族，骑士、法师、牧师、武僧、学者、盗贼等职业），
由英文经典 MUD 翻译改编为中文而来。同批次的 `esI`（屠龙之战）与本作同源，
共享同一套核心引擎代码。

## 简介

游戏以一个奇幻大陆为背景，玩家可以选择十余种种族（人类、精灵、矮人、
半兽人、地精、半身人、蜥蜴人、妖精、魔族、半人马、黑暗精灵、眼魔、
吸血鬼、鸟人、变形虫）扮演冒险者，通过加入不同的职业公会（骑士团、
法师塔、牧师团、武僧院、学者会、盗贼公会等）来学习技能、提升等级。
整体风格更接近传统欧美奇幻 MUD，而非江湖武侠——这是它与本批次其他
"风云"系列武侠 MUD 最大的不同之处。

## 如何运行

```
cd libs/es1_win
~/src/fluffos/build-debug/src/driver config.fluffos
```

服务器监听端口：**40009**。

## 如何连接游玩

```
python3 scripts/mudclient.py 127.0.0.1 40009 --timeout 25 --idle 0.5 \
  --send "" --send "英文名字(纯小写字母)" --send "y" \
  --send "你的中文名字" --send "密码" --send "确认密码" \
  --send "m" --send "职业种族(如human)" --send "\$" --send "真实姓名(可留空)" \
  --send "look" --send "score"
```

注册顺序说明（新角色）：
1. 先输入一个 **纯英文小写字母** 的角色 ID（不超过 12 个字母），这是
   你的登录名，之后确认"这个角色不存在，确定要用这个名字吗？(y/n)"。
2. 接着会让你输入 **中文名字**（直接回车则与英文名同名）。
3. 设置密码，并再输入一次确认。
4. 选择性别（male/female/neuter，也可只输入 m/f/n）。
5. 选择种族（英文单词，如 `human`）。
6. 输入邮箱（没有可以输入 `$`）与真实姓名（可随意/留空）。
完成后即进入游戏，可以正常使用 `look`、`score` 等指令。

也可以用普通 telnet 客户端连接：`telnet 127.0.0.1 40009`，按上面顺序
手动输入即可。

## 已知问题

- 部分很老的模板/示例区域（如 `noden`/`drow`/`hawk` 等目录下的房间）
  缺少必要的头文件引用，无法正常加载，但这些区域似乎并非正式游戏内容
  的一部分，不影响主线游玩。
- （已修复）此前登录时系统设置（`setup()`）阶段会打印一行调试遗留的
  乱码字符（"aadsaaaaaaaaaaaaaaaaaaaa"），本轮重新测试中已删除。
- **WASM 兼容性**：已在新的 WASM 构建下测试，可以正常启动、登录、
  `look` 等指令均正常（本版本的 IP 检查只是提示性警告，不会阻挡登录，
  未受已知的 `query_ip_number()` WASM 限制影响）。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: 完整管理员（FULL ADMIN）。通过 `/adm/etc/groups` 将
  `fluffos` 加入 `(root)` 与 `(admin)` 组（`/adm/etc/access` 授予 `(admin)`
  对 `/` 的全局读写），并在连线档 `data/std/connection/f/fluffos.o` 中设置
  `wizard 1` 与 `domains`（primary=wiz，level=archwizard），登录即拥有巫师
  身份与全局写权限。已验证 `update /adm/daemons/statsd`（更新并重载 /adm
  守护进程）成功。
- ⚠️ **公开架站前请务必修改此默认密码。** This is a published default
  password for local play — change it before hosting publicly.
