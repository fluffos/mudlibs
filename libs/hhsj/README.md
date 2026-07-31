# 洪荒世界

源自 2026-07-29 批量归档 `mudlib.rar` 中的 `洪荒世界(自连数据库)`。与
`nitan170911`（仙剑奇侠传）、`nitan6`（笑傲江湖）同源的 NT/nitan/Lonely
引擎家族成员，这次以《封神演义》/盘古开天为背景重新设计。

## 内容亮点

- 开局即是盘古开天地的创世场景，需要在"生命之谷"面见盘古，选择角色
  性格与种族，再经由阎罗殿"投胎"完成真正的降生仪式——比这批归档
  里大多数泥潭更有仪式感的新手引导。
- 采用自带客户端协议（"自连数据库"即"自行连接数据库"之意），登录
  握手会显示版本校验信息；用普通 telnet 客户端也能玩，只是账号注册
  需要单行输入"账号,密码,密文,email"格式。

## 在线试玩

https://mudlibs.fluffos.info/honghuangshijie/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予。
- 注：巫师指令（如 `update`）的具体验证尚未完成（见 NOTES.md），
  wizlist 数据本身已按同引擎家族的标准方式正确写入。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/hhsj
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40106**。
