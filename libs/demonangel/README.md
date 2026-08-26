# 恶魔天使 — Demon Angel (DA)

一个由 es2 1.1e mudlib 改造而来的中文武侠/仙侠 MUD——项目自己的 README
明确写着"本 DA mudlib ... 由 es2 1.1e mudlib 修改而成"，`README.ES2`
（es2 原作者 Annihilator 的原版说明文件）也原样保留在存档中。与本项目
已收录的 `es2`、`haiyang2`、`xkx2001` 等"ES II 引擎家族"一样，共享同
一套 `adm/`、`feature/` 底层框架，但游戏世界完全不同：城市/地图以
gourd（葫芦城，新手出生点）、grid、pet、ship、special、wiz 等 domain
构成，和 es2 的 canyon/choyin/city/temple/village 等世界完全独立，并
非重复收录。

原始存档：`git clone https://github.com/MudRen/DemonAngel`（commit
`9487693`）。仓库本身是纯 GBK 编码的原始快照，本次上线按本项目一贯
的方式完成了 GBK→UTF-8 全量转码与驱动兼容性修复（详见 `NOTES.md`）。

## 内容亮点

- 注册需要取一个真正的中文名字（如"秦风"），新人物会降生在葫芦城的
  "中央广场"——四方通往东西南北四座城门，还有留言板与 NPC"小美女"。
  `score` 展现完整的力量/智慧/敏捷/毅力/体质/运气六维属性与体力/法
  力条。
- `feature/irc.lpc` 提供组队/战斗小队系统（命名沿用早期 mudlib 里常
  见的"irc team"说法，并非真正连到 IRC），另有一整套（默认关闭、不
  会产生任何对外连线的）Intermud 风格网络守护进程留在
  `adm/daemons/network/` 下，作为历史遗留代码保留但从未加入
  `adm/etc/preload`。
- 保留了大量 ES II 家族典型的历史设计：门派/技能练功系统、
  `feature/dbase.lpc`+`feature/treemap.lpc` 的嵌套属性存储、双轨
  `feature/damage.lpc`/`feature/attribute.lpc` 状态模型等。

## 在线试玩

https://mudlibs.fluffos.info/demonangel/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 秦风
- **权限 / level**: 通过编辑 `adm/etc/wizlist`（`securityd.lpc` 在
  `create()` 时读入此文件填充 `wiz_status`）加入 `fluffos (admin)`
  一行，再以正常注册流程创建该账号。已用 `update /adm/obj/master`
  验证成功（读取+编译 ACL 均通过）。

> 警告：公开架站前请务必修改此默认密码。

## 本地运行

```
cd libs/demonangel
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40218**。
