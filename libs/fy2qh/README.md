# 风云再起Ⅱ（清华仿写版）— fy2qh

经逐文件核实，本档案与本批次的 `fy2` **实际上是同一份源码的另一个流传
副本**（只是打包驱动、玩家存档快照不同），"清华仿写版"更像是当年某个
下载站/镜像站给这份拷贝起的名字，而非独立重写的版本。内容与 `fy2`
完全一致（详见该库介绍）：以古龙武侠为背景，"金钱帮"新手门派、风云
广场留言版与探花诗台、完整表情系统等均可体验。

## 在线试玩

https://mudlibs.fluffos.info/fy2qh/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 最高级别。通过 `/adm/etc/wizlist` 中的
  `fluffos (admin)` 行授权（securityd 启动时读取）。

> 警告：公开架站前请务必修改此默认密码。

## 本地运行

```
cd libs/fy2qh
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40091**。
