# 西行战记

游戏自称《西行战记》，配置文件里写着"总站"，但实际登录横幅打的是 "西行战记[宜昌站]"——这是同一套源码在不同地区搭建的分站，内容是一样的，只是站点名字没改而已。它属于 ES II（Eastern Stories II）架构的一个独立分支，和本项目里其他好几个西游/ES II 系 Mud 是远房同门。

## 内容亮点

- 以《西游记》故事为底色的江湖 Mud，新手会从长安城的"南城客栈"起步，
  围绕取经、降妖、门派历练展开。
- 系统保留了不少 ES II 家族典型的老派元素：留言板、天赋点数分配、
  体格/根骨/悟性/灵性四维属性等，适合喜欢慢节奏文字养成的玩家。

## 在线试玩

https://mudlibs.fluffos.info/xixingzhanji/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **显示名 / display name**: 浮浮（Fluffos）
- **权限 / level**: `(admin)` —— 本 lib `securityd.lpc` 权限表的最高一级，
  通过 `/adm/etc/wizlist` 名单授予（`fluffos (admin)`）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此默认密码。

## 本地运行

```
cd libs/xixingzhanji
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40080**。
