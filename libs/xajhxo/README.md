# 笑傲江湖 XO

游戏取材自金庸小说《笑傲江湖》，"XO"是这个版本自己的代号（登录横幅上写着"THE SMILING PROUD WANDERER"），源自 TMI-2/ES2 引擎、由"Falcon"改写，本项目还收录了同一血脉的另外两个快照 `xo`（笑傲江湖迷你版）与 `xo_final`（XO最终版1.2），以及共享同一套"XO mudlib"世界模板的第四位近亲 `xajh2`——不过逐文件比对发现两者在共有路径中只有18%的字节完全相同，说明各自都是独立重写而非直接复制。门派体系是共享模板的一个精简子集：少林、崆峒、昆仑、青城、无量剑派、《天龙八部》里的大理段氏皇宫，以及丐帮麾下的"一品堂"，此外还有专属于本档案的南阳地区及一处山寨匪窝。新角色会被随机分配到几个不同的起始场景之一（比如"龙门客栈"），剑术、刀法、拳脚、轻功、短兵刃、鞭法、长兵刃等各类武学修为各自独立养成。新创建的人物如果在上线30分钟内就 `quit`，存档会被作废——这是游戏本身的防灌水设计，不是缺陷。

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
