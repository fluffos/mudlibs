# 鳥人世界 (The Bird-Man World)

登录横幅标注底层为 `MudOS v22c2` / `MudOs V22pre11`，是一个 ES-family/
xkx 风格的代码库，但尚未通过逐文件比对确认与本项目其他 XKX/ES2 家族
成员共享同一血脉。

## 内容亮点

- 以金庸武侠小说为背景设定的繁体中文 MUD（作者原话："这里的故事和
  情节，谜语的基本依据是金庸的十五本小说"）。
- 玩家从"龙门客栈"起步，在各大门派、城市间闯荡江湖，修习内功、外功
  与各类技能——传统的武侠 MUD 框架（属性、门派、师徒、帮派、排行）。
- 登录时带有彩色 ASCII 艺术标题，繁体中文界面。

## 在线试玩

https://mudlibs.fluffos.info/niaoren/

## 管理员账号 / Admin account

- 账号 id：`fluffos`　密码：`Mud@2026`　中文名：无敌铁鸟
- 权限：`(admin)`（本 mudlib 的最高巫师等级），通过 `adm/etc/wizlist`
  数据文件授予。

> 警告：这是为本地/浏览器单机游玩预置的公开默认密码，如要对外公网
> 开服，请务必先修改此账号密码（或从 wizlist 中删除该账号）。

## 本地运行

```
cd libs/niaoren
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40100**。
