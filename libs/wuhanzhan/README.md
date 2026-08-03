# 大话西游 (A Chinese Odyssey)

原始压缩包名为"武汉站"，但这只是收藏者标注的站点标签——游戏自身的
config 与登录横幅都写明真正的名字是**"大话西游"**，由湖北楚天热线
旗下的襄樊分站运营。属于 ES II（Eastern Stories II）引擎系列，与本
项目中的 wmkj、tiexuejianghu 等同宗但各自独立开发。

## 内容亮点

- 取材自周星驰同名电影，以搞笑轻松的西游/江湖世界观为底色，融合门派、
  武功、装备养成等传统 MUD 玩法。
- 新人物从"南城客栈"起步，可以找店小二、邮差等 NPC 互动，逐步在江湖
  中闯出名堂。
- 注册要设置一个独立的"身份识别码"（找回密码用），与日常登陆密码
  分开。

## 在线试玩

https://mudlibs.fluffos.info/wuhanzhan/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **登陆密码 / Password**: `Mud@2026`
- **身份识别码 / Recovery PIN (super password)**: `Pin@2026a`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)` —— 本 lib 的最高等级，通过
  `adm/etc/wizlist` 授予。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改两个密码。

## 本地运行

```
cd libs/wuhanzhan
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40052**。
