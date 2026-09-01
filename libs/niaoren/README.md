# 鳥人世界 (The Bird-Man World)

以金庸武侠小说为背景设定的繁体中文 MUD（作者原话："这里的故事和情
节，谜语的基本依据是金庸的十五本小说"），登录横幅标注底层为
`MudOS v22c2` / `MudOs V22pre11`，界面带有彩色 ASCII 艺术标题。玩
家从"龙门客栈"起步，在各大门派、城市间闯荡江湖，修习内功、外功与
各类技能，是传统武侠 MUD 的属性、门派、师徒、帮派、排行框架；深度
功能测试还确认了它的血统——和 `cctx`（驰骋天下）是同一套源码的独
立分支（注册流程的天赋选择提示文字逐字相同，`adm/daemons/
logind.lpc` 里至今还留着一行读取 `/adm/etc/cctxinfo` 的残留代码，
"cctxinfo" 这个档案名正是 `cctx` 的痕迹，并非 `xkx2001`/
`xuanjianlu` 所属的 XKX 家族）。客店留言板上还完整保留着真实的历
史玩家留言——bug 报告、任务修复公告、平衡性调整通知、门派讨论——是
这批档案里少见的、原始玩家社群历史被完整保存下来的例子。

## 深度功能测试新发现的 bug（详见 NOTES.md）

`adm/daemons/logind.lpc` 的食物/饮水初始化判断条件混用了两个不同的
物件——`!user->query("food") && !user->query("water") &&
ob->query("age") == 14`——前两个读 `user`（玩家身体），最后一个却
读 `ob`（登录连线物件，全代码库没有任何地方给它设过 age）。这个条
件因此永远为假，**每一个全新玩家食物/饮水槽永远是空的**，一进游戏
就会看到"你餓得直冒金星"的挨饿提示。是和 `cctx` 完全相同的坏代码
（AGENTS.md §8.9），因为确认了血统关系才主动去检查、也确实在这里
找到了同一个 bug。已同样改成 `user->query("age")`。修复前后各注册
一个全新角色对照验证：修复前食物/饮水槽全空，修复后全满。

## 在线试玩

https://mudlibs.fluffos.info/niaoren/

## 管理员账号 / Admin account

- 账号 id：`fluffos`　密码：`Mud@2026`　中文名：无敌铁鸟
- 权限：`(admin)`（本 mudlib 的最高巫师等级），通过 `adm/etc/wizlist`
  数据文件授予。

> 警告：这是为本地/浏览器单机游玩预置的公开默认密码，如要对外公网
> 开服，请务必先修改此账号密码（或从 wizlist 中删除该账号）。

## 本地运行

```
cd libs/niaoren
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40100**。
