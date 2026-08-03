# 笑傲江湖 XO

游戏取材自金庸小说《笑傲江湖》，"XO"是这个版本自己的代号（登录横幅上
写着"THE SMILING PROUD WANDERER"）。它源自"TMI-2/ES2"引擎，由"Falcon"
改写，本项目里另外两个库 `xo`（笑傲江湖迷你版）和 `xo_final`（XO 最终版
1.2）都是同一血脉的不同快照，这一份是三者中独立演化出来的第三个版本。

## 内容亮点

- 完整还原了《笑傲江湖》里的江湖门派、武功体系，新人物会被随机分配到
  几个不同的起始场景（比如"龙门客栈"）之一。
- 剑术、刀法、拳脚、轻功、短兵刃、鞭法、长兵刃等各类武学修为都有独立
  的养成线，是比较正统的金庸题材文字 Mud。
- 新创建的人物如果在上线 30 分钟内就 `quit`，系统会弹出"必须玩够 30 分
  才可以保存数据"的确认提示——这是游戏本身的防灌水设计。

## 在线试玩

https://mudlibs.fluffos.info/xajhxo/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **显示名 / display name**: 浮浮（Fluffos）
- **权限 / level**: `(admin)` —— 本 lib `securityd.lpc` 权限表的最高一级，
  通过 `/secure/etc/wizlist` 名单授予（`fluffos (admin)`）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此默认密码。

## 本地运行

```
cd libs/xajhxo
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40069**。
