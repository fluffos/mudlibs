# 金庸群侠传（2015版）

2015 年整理发布的版本，属于 ES II 引擎系列——与本项目中的"金庸群侠传
2008加强版"等同门作品共享同一套底层引擎/守护进程代码，七年间引擎本身
几乎没有变化，变化的主要是游戏内容，本版比 2008 版新增了不少区域和
剧情。

## 内容亮点

- 以金庸武侠世界观为背景：少林、武当、峨嵋、明教、丐帮等各大门派
  悉数登场，玩家从一间普通客栈起步，练武、闯荡江湖、体验金庸小说中
  的经典桥段。
- 相比 2008 版内容更丰富——新增区域和剧情，对练功、内功、装备均有
  细致的数值设计，江湖气息浓厚。

## 在线试玩

https://mudlibs.fluffos.info/jinyongqunxiazhuan2015/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` — 本 lineage 的最高权限等级，可使用全部
  巫师指令。
- 授权方式：在 `work/adm/etc/wizlist` 中加入 `fluffos (admin)` 一行。

> 警告：正式对外开放前请务必修改此密码（这是本地游玩用的公开默认
> 密码）。

## 本地运行

```
cd libs/jinyongqunxiazhuan2015
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40086**。
