# 最终幻境 (The Final Frontier)

## 简介

「最终幻境」（The Final Frontier，简称 FF）是一个改写自「东方故事II」
(ES2) 函数库的太空科幻题材 MUD，由 Spock 创立。新角色从「新手學院大廳」
起步，创角时需要自行分配六项人物属性（力量/敏捷/智力/注意/體質/技術）
点数，总和须为 60。存档原为繁体中文（BIG5）内容，已转换为 UTF-8。

## 如何运行

```
cd libs/zuizhonghuanjing
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40099**。

## 如何连接游玩

```
python3 scripts/mudclient.py 127.0.0.1 40099 --idle 1.0
```

注册流程（无内码选择步骤，直接从英文名提示开始）：
1. 英文名字（3-20 位纯英文字母）——注意，本游戏**没有**特殊的 `new`
   关键字，任何未注册过的英文名字都会直接进入「创建新角色」确认
2. 确认创建新角色（y/n）
3. 中文名字（1-10 个中文字）
4. 密码（≥5 字元）→ 确认密码
5. 电子邮件地址
6. 分配六项人物属性点数（格式如 `10 10 10 10 10 10`，总和须为 60，
   各项有各自的上下限，输入 `?` 或 `h` 可查看说明）
7. 性别（m/f）

完成后进入「FF 新手學院大廳」，`look`/`score`/`quit` 等指令均正常。

本游戏已确认可在 WASM/浏览器模式下完整游玩（注册、登陆、`look`/
`score`/`quit` 均正常）。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 通过 `/adm/etc/wizlist` 中的
  `fluffos (admin)` 行授权。已验证 `update /adm/obj/master.lpc`
  重新编译成功（原生与 WASM 两种模式下均已验证）。

## 已知问题

- 存档自带的游戏公告声明作者已停止后续开发，属于历史存档内容，不影响
  实际游玩。
