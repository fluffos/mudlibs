# 西游记450

这是一份专门用于建立"镜像站"的发行包，内附教学说明，供其他站长在其基础
上另开一个分身站点。与本项目中的 `fluffos_xiyou2000`、`mhxy`、
`menghuanxiyou2002` 同属一支血缘极近的"西游记/xiyouji.org"引擎家族——
核心引擎文件（`master.c`、`chinese.c` 等）与 `mhxy` 几乎逐字一致，只有
站点自定义的登录/安全层与世界内容各自不同。

## 内容亮点

- 以《西游记》世界观为背景的武侠/神话文字 MUD：玩家从长安城的南城
  客栈出发，探索天地三界，习练武功、结交门派。
- 作为一份"镜像站"发行包，世界内容与 `fluffos_xiyou2000`/`mhxy` 系高度
  相似，但拥有自己独立的注册与安全体系。
- 与姊妹版 `xiyouji` 不同，本版注册流程没有性别/天赋选择环节，更简洁。

## 在线试玩

https://mudlibs.fluffos.info/xiyouji450/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 本 lib 最高权限（通过 `adm/etc/wizlist`
  授予），可使用 `update`、`goto` 等全部巫师指令。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xiyouji450
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40078**。
