# 梦幻西游（青岛站）

2002 年版本，"青岛站"分线。与本项目中的 "mhxy" 是同一套 2002 年代码库
（仅站点名称品牌不同），属于西游记题材、ES II 引擎家族的一支（与
fluffos_xiyou2000 等同宗）。

## 内容亮点

- 取材自《西游记》的神话/仙侠题材 MUD：新手从"南城客栈"起步，途中会
  遇到黄飞鸿、孙悟空等耳熟能详的角色。
- 游戏内的成就体系紧扣原著——"西天取经""大闹天宫"等都是角色档案里
  会记录的经历。
- 新闻公告、门派、帮会系统一应俱全，整体偏休闲。
- 巫师账号每次登录都会重新进入天赋分配室（`/d/wiz/init`）——这是本库
  自己的既有设计，非巫师账号只在首次注册时经过这里。

## 在线试玩

https://mudlibs.fluffos.info/menghuanxiyou2002/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` — 本 lineage 最高权限（游戏内头衔显示为
  【天神】）。
- 授权方式：`work/adm/etc/wizlist` 加入 `fluffos (admin)`。

> 警告：正式对外开放前请务必修改此密码。

## 本地运行

```
cd libs/menghuanxiyou2002
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40050**。世界数据量较大，启动后大约还需要 1-2 分钟在后台
继续加载全图 NPC/场景，但这期间已经可以连线注册、游玩。
