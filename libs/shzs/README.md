# 山海战神

不要被"山海战神"这个名字骗了——这并不是传统武侠/仙侠泥巴，而是史巴克（Spock）开发的英文科幻引擎"Final Frontier v0.6e"（`simple`/ES II 引擎系列）二次改造而成的中文版硬科幻"战斗模拟"游戏：人物属性叫力量/敏捷/智力/注意/体质/技术，护甲分传统、动能、光学、粒子、爆破五种类型，攻击方式带着浓厚的机甲/激光对抗色彩，是这批归档里题材最"硬科幻"的一个。整体规模不大，更像是一个演示引擎战斗系统的小型试验场，而非内容丰富的大型世界。

## 在线试玩

https://mudlibs.fluffos.info/shzs/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)`（最高级别），通过 `/adm/etc/wizlist` 授予。
- 本库没有基于连线地址的封禁/限流机制，WASM 化改造中仅需管理员账号
  播种即可。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/shzs
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40001**。
