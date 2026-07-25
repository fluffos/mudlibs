# 终极地狱之爱若幽兰

游戏登录后自报家门为"地狱泥潭---爱若幽兰"（压缩包标题为"终极地狱之爱若
幽兰"）。属于 ES II → XKX → "地狱"（hell）分支引擎家族，与
`zhongjidiyu_zhijian`（指间MUD版）是同一套"地狱"引擎核心的姊妹版本
（两者 master 文件内容完全一致），与另一个同样带"终极地狱"字样、但内容
完全不同的 `zhongjidiyu` 压缩包不是同一款游戏，只是名字碰巧相似。

## 内容亮点

- 同样是"地狱"世界观下的武侠向 MUD，主题偏"爱若幽兰"这一支线剧情，整体
  系统架构和 `zhongjidiyu_zhijian` 基本一致（角色创建、门派、装备系统
  等），但没有那个版本专属的手机客户端协议层，可以直接用普通 telnet
  客户端游玩。
- 修复了一个原始存档就有的老 Bug：每次重启后的第一次登录所有命令都
  无效（连 quit 都提示"什么？"，第二次登录才正常），现已修复。

## 在线试玩

https://mudlibs.fluffos.info/zhongjidiyu_airuoyoulan/

## 管理员账号 / Admin account

- **ID**: `fluffos`　**中文名**: 浮云
- **普通密码（日常登录用）**: `Mud@2026`
- **管理密码（找回/改密用）**: `Admin@2026`（本 lib 强制两个密码不能相同，
  因此管理密码与标准约定不同，特此说明）
- **权限**: `(admin)`（最高级；通过 `adm/etc/wizlist` 授予）。
- 该账号尚未做游戏内"注册邮箱 + 投胎"流程，`score` 会显示"还没有出生呐"，
  属正常现象。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改这两个密码。

## 本地运行

```
cd libs/zhongjidiyu_airuoyoulan
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40073**。
