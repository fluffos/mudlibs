# 江湖2006 (jh2006)

游戏内标题为"江湖2005"（Annihilator/书剑 ES2 血统，与本项目中的 `sjplgfjxb`/`sjplii` 同宗，但与 Century/adm-single 家族的 `sjecl`/`sje` 是完全不同的谱系），金庸题材武侠 mudlib。地图除华山、武当、少林、峨嵋、崑仑、丐帮等常见门派场景外，还有独立的"苗疆"（`d/miaojiang/`）区域和"星宿"（`d/xingxiu/`，取自《天龙八部》星宿派）门派场景；在华山"正气堂"可以完整拜岳不群为师、成为"第十四代弟子"。这份档案自己的命名习惯也颇具特色：查看人物状态用的是 `stscore` 而非常见的 `score`，移动指令则是"方向-地点全名"式的复合字符串（如"西-小石路"）而非单独的方向字。

## 内容亮点

- Annihilator 的 ES2/书剑 血统档案（和 ES II 家族的 `sjplgfjxb`/
  `sjplii` 同宗，但和 Century/adm-single 家族的 `sjecl`/`sje` 是完
  全不同的谱系），地图有"苗疆"（`d/miaojiang/`）等场景。
- 查看人物状态的指令不是常见的 `score`，而是 `stscore`，是这份档
  案自己的命名习惯。
- 踩中了经典的死指令表 bug（AGENTS.md §8.3b）：`commandd.lpc` 的
  `rehash()` 用 `sscanf` 匹配旧版 `.c` 文件后缀来重建指令表，转换
  成 `.lpc` 后缀后这个匹配永远落空，导致除了 `look`/`quit` 之外几
  乎所有指令（包括 `stscore`）都变成"什么？"。
- 移动指令用的是"方向-地点全名"这种复合字符串（如"西-小石路"），
  不是单独的"西"/"west"，是这份档案自己的地图命名习惯。
- 深度功能测试修复了 `d/death/gate.lpc` 的一处 §7.68 复活软锁（编
  译层面已验证；受限于测试时间未做端到端的活体死亡/复活验证，详见
  NOTES.md）。

- **更正（2026-08-05）**：上面提到的"7.68 复活软锁"修复已经撤销——经重新评估，鬼魂"不在场"时放弃复活流程更可能是有意的游戏设计（多数这类档案里鬼魂本身就无法自行移动，离开是一种游荡机制，回来时 init() 会重新触发流程），不是需要强制重试的 bug；详见 NOTES.md。

## 注册流程

连线后先回答 BIG5 字体问题（y/n，本次未发现编码问题）→ 英文 ID
（3-8 个小写英文字母）→ 确认建立新角色（y/N）→ 密码（至少 5 位，
须同时包含数字和大写英文字母）→ 确认密码 → 中文名字（2-4 个汉字）
→ 天赋数值（输入 0-4 选择自订某一项，或输入 0 由系统随机产生，随
后需再输入 y 同意这组数值）→ 性别（m/f）→ 进入游戏世界。

**注意**：这份档案查看人物状态的指令不是常见的 `score`，而是
`stscore`。

## 本次修复的关键 bug

- `adm/daemons/securityd.lpc` 的 `valid_read()`：经典的
  `this_player()` 顶替 root 身份的 bug（AGENTS.md §7.59）——驱动
  在编译 `func=="load_object"`/`"include"` 时本应传入 root 身份
  （`master_ob`），但这里无条件地被替换成当前连线玩家。结果是：
  游戏启动后第一个连线尝试，`logind.lpc` 的 `gb_big5()` 里第一次
  调用 `BAN_D->is_banned()` 触发的惰性编译就直接崩溃报
  `*Read access denied.`，连英文 ID 提示都出不来。已修正为只对
  `load_object`/`include` 跳过 `user` 的替换。
- `adm/simul_efun/chinese.lpc` 的 `is_chinese()` 以及
  `adm/daemons/logind.lpc` 的 `check_legal_name()`：经典的 GBK
  字节区间长度假设 bug（AGENTS.md §8.1）——长度界限按字节数写成
  `strlen(name)<4||>8`（应为按字符数 `<2||>4`）。
- `adm/daemons/commandd.lpc` 的 `rehash()`：经典的死指令表 bug
  （AGENTS.md §8.3b）——`sscanf(cmds[i]+"$", "%s.c$", cmds[i])`
  在文件都改名为 `.lpc` 后再也匹配不到任何东西，导致整个指令表是
  空的。`look`/`quit` 碰巧仍能用（可能是驱动内建或另外
  `add_action` 注册的），但包括查看人物状态的 `stscore` 在内的其
  它所有指令全部回退成"什么？"。已修正为 `"%s.lpc$"`。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud2026Pass`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里；账号本身通过正常
注册流程创建，已在游戏内确认 "您目前的权限是：(admin)" 显示正确
（会自动带到"巫师休息室"）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/jh2006
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40128**。
