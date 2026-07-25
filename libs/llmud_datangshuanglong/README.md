# 大唐双龙传（LLMUD）

LLMUD v0.11 版，改编自黄易同名武侠小说《大唐双龙传》。与本项目中的
"dtsl"（大唐双龙传）为同一血脉的姊妹版本，共享同一套底层架构。

## 内容亮点

- 以隋末唐初为背景的武侠 MUD，玩家从"大唐学院"新手村起步，在乱世
  江湖中习武、闯荡、结交帮派，体验原著小说中群雄并起的历史武侠氛围。
- 角色成长围绕膂力、悟性、根骨、身法四项基础天赋展开，注册时一次性
  分配（总和须为 80，每项 10-30）。
- 巫师/管理员的游戏内头衔显示为"天帝"。

## 在线试玩

https://mudlibs.fluffos.info/llmud_datangshuanglong/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)`（游戏内头衔显示为【天帝】）— 最高权限。
- 授权方式：`work/adm/etc/wizlist` 加入 `fluffos (admin)`。

> 警告：正式对外开放前请务必修改此密码。

## 本地运行

```
cd libs/llmud_datangshuanglong
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40015**。
