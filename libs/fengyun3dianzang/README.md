# 风云典藏版 — fengyun3dianzang

**风云 3.8.0**，"风云工作室"内部整理的一份"收藏版"合集，在"风云3.7.4"
基础上补充了此前未发布/散佚的原创内容。属于本批次的**"风云3"
（Fengyun III）引擎分支**，核心引擎代码与 `fengyun3xiuding`（星星
修订版）几乎完全一致，是这条分支里内容最完整的打包版本之一。

## 内容亮点

- 以古龙武侠为背景的江湖世界，新角色从凤求凰客栈起步，可自由选择任意
  喜欢的中文名字（本版本对中文名字没有额外限制），选好民族（汉族/苗族
  /满族/蒙古族）和性别即正式踏入江湖。
- 注册流程比同引擎其他版本更精简——**没有密码设置这一步**，选完中文
  名字直接跳到性别选择。
- 管理员账号同样**没有密码环节**，任何人对 `fluffos` 输入 y 确认即可
  登录（本版本的原始设计如此）。

## 在线试玩

https://mudlibs.fluffos.info/fengyun3dianzang/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: 无 —— 本版本注册/登录流程根本没有密码环节，
  重新登录只需对 `fluffos` 输入 y 确认。
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 最高级别，通过 `/adm/etc/wizlist` 中的
  `fluffos (admin)` 行授权。

> 警告：本版本无密码保护，任何人输入 id 即可登录任意账号（包括管理员）。
> 公开架站前必须先给登录流程加上密码验证。

## 本地运行

```
cd libs/fengyun3dianzang
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40090**。
