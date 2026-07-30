# 鹿鼎天下（游戏内实际品牌：雄霸天下『西安站』）

源自 2026-07-29 批量归档 `mudlib.rar` 中的 `鹿鼎天下.rar`。"世纪
(Century) / adm-single" 引擎家族的一支（与 `shiji`、`shujian2008`、
`xianjianchuanqi`、`xiakexinzhuan2`、`xiakexing100` 同源），ES II 血统。

有趣的是，压缩包本身叫"鹿鼎天下"，但登入画面品牌其实是"雄霸天下
『西安站』"，而 `quit` 退出提示又写着"离开了鹿鼎天下"——两个名字
同时残留在代码里，看起来是曾经改过品牌但没有全部替换干净。

## 内容亮点

- 经典金庸武侠背景的门派/武功养成类泥巴：膂力、悟性、根骨、身法四维
  属性，另有隐藏的福缘、容貌影响解谜与拜师。
- 客栈开局，NPC 店小二和一只可爱的小白狗会互动欢迎新玩家。
- 明确提醒"请尽量不要选择金庸小说中已有人物姓名"，鼓励玩家自创
  角色名而非直接扮演原著人物。

## 在线试玩

https://mudlibs.fluffos.info/ludingtianxia/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)`（最高级别），通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/ludingtianxia
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40105**。
