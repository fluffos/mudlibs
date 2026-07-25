# 金庸群侠传 (原名"侠客行三")

压缩包与内部配置文件都叫"侠客行三"，但实际连接进游戏后，登录横幅显示
的名字是**"金庸群侠传"**——经比对，这份存档与本项目中的
jinyongqunxiazhuan2008 系列共享同一套 master 核心代码，是同一引擎不同
时期的换皮/内容版本。

## 内容亮点

- 以金庸小说人物与门派体系为背景的江湖题材 MUD，新人物从"客店"起步，
  可以习武、结交江湖人物、闯荡各大门派。
- 与 jinyongqunxiazhuan2008 系列共享引擎核心，但内容/换皮与那一系列
  各版本均不相同。

## 在线试玩

https://mudlibs.fluffos.info/xiakexing3/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: 天神 `(admin)` —— 本 lib 的最高等级，通过
  `adm/etc/wizlist` 授予。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xiakexing3
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40038**。
