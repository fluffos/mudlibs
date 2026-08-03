# 重生的世界 (Revival World)

RWlib v1.0.1，台湾团队开发的生活模拟/城市经营类 MUD，与本项目其他武侠
类 mudlib 完全不属于同一谱系，是一套独立自制的引擎。

## 内容亮点

- 不是打怪升级的武侠 MUD，而是一款以经营、生活为核心的模拟游戏：种田、
  钓鱼、养殖、开工厂、买卖房地产、炒股、打麻将、抽奖样样俱全。
- 配有完整的城市市长、税收、企业系统——新角色可以选择加入某个城市定居，
  体验经营与养成的乐趣，风格更接近生活模拟游戏而非传统砍杀 MUD。
- 每次连线都会展示一段完整的模块加载动画，是这款游戏自己的特色开场。
- 巫师账号从 loopback（本机）连线时会被自动导向巫师登录流程，需要把
  英文 ID 重新输入一次（第一次输入用来触发跳转，第二次才是巫师登录
  流程自己的 ID 提示），然后才是密码。

## WASM 状态说明

早前的验证曾把这份档案标为 `noboot`：`system/kernel/simul_efun/ansi.lpc`
的 ANSI 颜色处理直接呼叫 `pcre_replace_callback()`/`pcre_replace()`/
`pcre_match_all()`，而这几个函数所在的 `simul_efun` 档案是开机时的必要
档案，当时的 WASM 版驱动完全没有打包 `pcre` package，导致
`fluffos_boot()` 直接失败、连测试用的连线记录都产生不了——这不是这份
mudlib 自己的 bug，纯粹是当时 WASM 驱动的能力缺口。本次重新测试时确认
`fluffos` 上游的 `docs/build-wasm.md` 已经记录 WASM 驱动现在打包了
`pcre`，用现在的驱动重新开机、完整走完注册流程、以及巫师账号登录，三
者都顺利通过，档案本身没有再改动任何代码。

## 在线试玩

https://mudlibs.fluffos.info/chongshengdeshijie/

## 管理员账号 / Admin account

- **ID**：`fluffos`
- **密码 / Password**：`Mud@2026`
- **中文名 / Display name**：浮浮
- **权限 / Level**：`(admin)`（`SECURE_D` 的最高等级）
- 授权方式：`system/kernel/data/secure.o`（SECURE_D 的存档）`wizards`
  映射中加入 `"fluffos":"admin"`。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，
> 请先修改此密码。

## 本地运行

```
cd libs/chongshengdeshijie
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40081**。
