# 魔幻世纪 (mohuanshiji)

青岛站，作者"小宝(suannai)/西瓜太郎(gslxz)/桃心太郎"，由"星月传奇"发布，属于"神话西游"(SJXY) 一脉，是 ES II 引擎下西游记（Journey to the West）神话世界观的一个独立改版分支——与本项目收录的 mhxy、rzrmud 同为这一神话西游世界观，但代码血统各自独立，并非彼此的换皮版本。新角色从"南城客栈"启程，唐僧、店小二、千里眼等经典角色以 NPC 身份驻场迎接新人，并在原有取经故事框架上加入了武当、移花宫等原创门派内容，是同类西游题材泥巴中内容比较丰富、系统比较完整的一支；注册流程里还有一步"您是否是中小学学生或年龄更小？"的自述式年龄提示，答 yes（或不理会）会被直接劝退，是这批档案里少见的、游戏本身自带的年龄门槛；死亡则有完整的阴曹地府体验——由"朱笔判官 崔珏"接引到"阴阳界"，静候片刻后自动复活还阳，和同一 ES2 大家族的 `yszz`/`bmxkx2001` 是同一套设计。

## 深度功能测试新发现的 bug（详见 NOTES.md）

`adm/daemons/logind.lpc` 里有一行调试用的 `printf("%O\n", ob)`，紧
挨在设定中文名字之前，每一个新玩家注册时都会看到（AGENTS.md
§7.34）。已删除。（另外核实了 `doc/help/newbie` 里"食物/饮水初
始为空"的说法和实际代码不符——`logind.lpc` 明确无条件把两者初始
化为满值，是文档陈旧而非程序 bug，未做代码改动。）

## 在线试玩

https://mudlibs.fluffos.info/mohuanshiji/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)`（最高级别），通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/mohuanshiji
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40092**。
