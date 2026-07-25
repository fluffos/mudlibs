# 世纪

自称 **世纪（CENTURY）**，登录 banner 的版权信息写着"星战英雄之乱世
风沙"，采用 `adm/single/{master,simul_efun}` 布局，与本项目中若干
"世纪家族"（Century）系列的姊妹站点同宗同源。

## 内容亮点

- 传统中文武侠 MUD，玩家创建角色后从"天狼中心"这样的城镇场景起步，
  体验属性成长、江湖闯荡、门派与战斗系统。
- 整体风格朴素直接，是一个体量不大、结构清晰的早期 MudOS 时代武侠
  站点，没有特别复杂或花哨的额外机制。
- 巫师账号的权限体系颇具特色："宇宙特警"（`zhuguan`）是最高等级，
  可使用 `/cmds/zhu`/`/cmds/adm`/`/cmds/arch`/`/cmds/wiz`/`/cmds/imm`
  等全部巫师命令目录。

## 在线试玩

https://mudlibs.fluffos.info/shiji/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码**: `Mud@2026`
- **中文名**: 浮浮
- **权限**: `(zhuguan)`（宇宙特警，本 mudlib 的最高权限级别）
- 权限授予方式：`/adm/daemons/securd.o` 存档中 `wiz_status` 映射内
  加入 `"fluffos":"(zhuguan)"`（该 mudlib 的巫师表存于安全精灵的
  存档文件，不使用 `/adm/etc/wizlist`）。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/shiji
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40026**。
