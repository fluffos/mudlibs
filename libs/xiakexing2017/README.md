# 侠客行 (MUD侠客行2017完整版)

取材自金庸小说《侠客行》，压缩包标注为"2017完整版"，与本项目中的
xiakexing100、xiakexing3 属于名字相近但代码库彼此独立的不同分支
（各自的核心引擎文件并不相同）。

## 内容亮点

- 以《侠客行》的江湖门派与武学体系为背景，新人物从"客店"起步，可以
  习武、结交江湖人物、加入各大门派。
- 游戏世界会同时显示"侠客行时间"、现实北京时间以及农历日期，带有
  一点"活历法"的氛围感。

## 在线试玩

https://mudlibs.fluffos.info/xiakexing2017/

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
cd libs/xiakexing2017
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40017**。
