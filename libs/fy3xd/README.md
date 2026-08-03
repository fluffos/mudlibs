# 风云三（星星修订版）— fy3xd

压缩包内附带的说明文档称之为"星星修订的风云3"（社区爱好者"星星"整理
修订的一个内容较丰富的版本）。属于本批次的**"风云3"（Fengyun III）
引擎分支**，与 `fy3dz`（风云典藏版）核心代码高度一致，属于
同一引擎的不同内容打包。

## 内容亮点

- 以古龙武侠为背景的江湖世界，新角色从凤求凰客栈起步，选择民族（汉族
  /苗族/满族/蒙古族）与性别后即可闯荡江湖。
- 这个"修订版"任务内容比同引擎的早期版本更加丰富，并附带较详细的
  游戏内帮助文档，适合刚接触这套引擎的新玩家。

## 在线试玩

https://mudlibs.fluffos.info/fy3xd/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 最高级别，通过 `/adm/etc/wizlist` 中的
  `fluffos (admin)` 行授权（securityd 启动时读取）。

> 警告：公开架站前请务必修改此默认密码。

## 本地运行

```
cd libs/fy3xd
mkdir -p log   # 如尚未创建
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40089**。
