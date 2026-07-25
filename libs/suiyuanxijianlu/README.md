# 随缘洗剑录

自称 **【随缘洗剑录】**，是"ES II"引擎家族的一员（与本项目中的神州、
火影、武汉站等同宗），由 Annihilator 等人在原始 ES II 基础上多次改写
而成，是一款有较长运营历史的老牌武侠 MUD。

## 内容亮点

- 玩家从"随缘客栈"（扬州城内）起步，NPC"浪子"李寻欢会在开场热情地
  引导新手熟悉 look/get/i/hp 等基本指令。
- 游戏整体延续经典武侠养成路线：属性天赋抽取、门派拜师、武功修炼、
  江湖闯荡，风格朴实，没有花哨的额外系统。

## 在线试玩

https://mudlibs.fluffos.info/suiyuanxijianlu/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码**: `Mud@2026`
- **中文名**: 浮浮
- **权限**: `(admin)`（本 mudlib 巫师等级表的最高级别，上线时以【巫师】
  头衔公告）
- 权限授予方式：`/adm/etc/wizlist` 数据文件追加 `fluffos (admin)`。
- 登录小提示：连接后先回答 GB/BIG5 编码选择（输入 `gb`），然后有一个
  容易被淹没在站点列表里的 "Press Enter to Continue..." 提示，需要多
  敲一次回车才会出现英文名字提示。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/suiyuanxijianlu
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40088**。
