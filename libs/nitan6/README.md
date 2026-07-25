# 笑傲江湖 (nitan6)

底层标注"NT.XAJH Library 5.1g" / "NTOS V2.4"，属于本项目中体量最大的
两个"泥潭/nitan/Lonely"系列引擎库之一（与 nitan170911 同源，后者需要
外部 MySQL 支持，本库不需要）。取材于金庸同名武侠小说的江湖世界。

## 内容亮点

- 标准的金庸风格武侠泥巴：日月神教、华山、少林、丐帮等门派体系，
  从"生命之谷"投胎入世后，靠内功、轻功、拳脚、兵器四大类修为闯荡
  江湖。
- 内容非常庞大（超过 2.3 万个文件），帮派威望、军功、结婚生子、坐骑
  等系统一应俱全。
- 丐帮拜师采用树洞机制——`bai` 拜入丐帮后可进入树洞内部继续历练。
- 天赋分配采用"洗点"设计：`washto` 指令一次性重新分配四项天赋数值。

## 在线试玩

https://mudlibs.fluffos.info/nitan6/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **普通密码 / Password**: `Mud@2026`（平时登录用这个）
- **管理密码 / Admin(recovery) password**: `Mud@2026admin`
- **中文名 / Display name**: 浮浮（姓"浮"名"浮"）
- **权限 / Level**: `(boss)`（本库的最高级别，高于 `(admin)`），通过
  `/adm/etc/wizlist` 授予。
- **注意**：本库中新账号 30 分钟内用 `quit` + `y` 退出会**自删账号**，
  且删除巫师账号时 securityd 会同步把该账号从 wizlist 中移除——不要
  用这种方式退出 `fluffos`。

> 警告：对外公开架设前请务必修改这两个密码。

## 本地运行

```
cd libs/nitan6
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40019**。作为超大型库，驱动预加载可能需要一点时间。
