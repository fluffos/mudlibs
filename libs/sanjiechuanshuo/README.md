# 三界传说 (San Jie Chuan Shuo)

## 简介

以中国古典神话「三界」（天界/人间/地府）为背景的江湖世界。新角色从
「南城客栈」（长安城）起步，注册时可自由决定体格/根骨/悟性/灵性四项
天赋点数的分配（默认平均分配，也可自行调整后确认）。

## 如何运行

```
cd libs/sanjiechuanshuo
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40097**。

## 如何连接游玩

```
python3 scripts/mudclient.py 127.0.0.1 40097
```

注册流程：
1. 内码选择（`gb`）
2. 「是否为中小学生」问题 → 回答 `no`（回答 yes 会被断线，这是原始
   游戏内容，非托管保护，已保留）
3. 英文 ID：键入 `new` 触发注册
4. 新英文 ID（3-8 位纯英文字母）
5. 中文名字（往后不能更改）
6. 密码 → 确认密码
7. 电子邮件地址
8. 选择性别（m/f）
9. 天赋点数分配菜单 → 输入 `9` 接受默认分配 → 输入 `y` 确认

完成后进入「南城客栈」，`look`/`score`/`quit` 等指令均正常。

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

- lpcc 批量编译扫描中有若干失败项（多为原始存档缺失的周边功能，例如
  `CLUB_D`/`F_DISASTER` 等未随附的守护进程，或个别管理员调试指令），
  均不在正常登录/游玩路径上，详见 `NOTES.md`。
- 一位巫师（`feizei`）的个人日志子目录在存档中缺失，首次编译时会打印
  一条无害的权限警告，不影响游玩。
