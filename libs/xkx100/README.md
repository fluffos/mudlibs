# 侠客行一百 (xkx100)

Coollizard & xkx100，2003-2004，yoyo.xm.fj.cn/xkx100。这份档案与另
外单独完成的 GitHub `fluffos/xkx100` 仓库是完全不同的代码库，只是
恰好同名。

## 内容亮点

- 地图规模在同类档案里数一数二：从长安、洛阳、大理、湘阳等中原城
  池，一路延伸到漠北、哈萨克、台湾等边疆/海外场景，几乎覆盖整个古
  代中国地理版图。
- 角色创建带出生地（1-5 选一）、属性点自由分配（前三项手动输入，
  第四项自动补满）、性格特质菜单（可选 0 不设定）等多步定制，比常
  见的"选性别就完事"要精细得多。
- 一个真实存在、影响所有全新安装的 bug：`log/MUDVISITOR`
  访客计数档案在原始压缩包里根本不存在，第一次连线就会在看到 ASCII
  横幅后卡死、不出现任何提示（详见下方 bug 修复第 4 条）——这不是
  测试环境特有的问题，任何人重新架设这份档案都会撞上。
- 深度测试确认这份档案和"金庸群侠传"系列、`xkx2017` 共享同一个更上
  游的引擎血统：食物/饮水初始化检查错对象、`/log/nosave/` 缺失导致
  的死亡死循环风险，两处都命中并修复；同时也确认了另外两处已知 bug
  （损坏存档崩溃、拜师括号错误）在这里并不存在。另外修复了 4 处独
  立的死亡/复活软锁，实际打死过一次角色验证了完整流程，详见
  NOTES.md。

## 本次修复的关键 bug

1. **§7.48 `private` 函式被继承档案呼叫**：`feature/treemap.lpc`
   的 `_set()`/`_query()`/`_delete()` 声明成 `private`，但
   `feature/dbase.lpc`（`inherit F_TREEMAP`）直接呼叫它们——这个驱
   动对 `private` 的语义比老 MudOS 严格得多（只在声明的那个档案内
   可见，继承链也不例外）。已改成 `protected`。
2. **同样的 §7.48 模式**又独立出现在 `feature/action.lpc` 的
   `continue_action()` 和 `feature/attack.lpc` 的 `attack()`，都是
   被 `/inherit/char/char.lpc` 呼叫——也都改成 `protected`。
3. **§7.47 `origin()` 返回字符串不是整数位掩码**：
   `feature/team.lpc` 的 `follow_path()` 用
   `origin()==ORIGIN_LOCAL` 这种旧式整数比较，这个驱动的
   `origin()` 返回的是字符串——改成 `origin()=="local"` /
   `"internal"`。
4. **真正的健壮性 bug**：`adm/daemons/logind.lpc` 的
   `howmany_visitor()`/`howmany_card()` 直接对 `read_file()` 的结
   果做 `sscanf()`，没有先检查是不是字符串。`log/MUDVISITOR` 这份
   档案里**根本不存在**（连原始压缩包里都没有），所以一次真正的全
   新安装第一次连线就会撞上这个 bug——`sscanf(0, ...)` 的类型不匹
   配错误会在 `logon()` 执行过程中被静默吞掉，导致连线卡在 ASCII
   横幅之后，既不报错也不出现英文名字提示。已加上 `stringp()` 判
   断，文件不存在时直接返回 0（原本代码的其他地方本来就预期这个默
   认值，只是没有安全实现）。
5. **`#include` 路径错误**：`adm/daemons/combatd.lpc` 用
   `#include </quest/quest.h>`（绝对路径写法），但这个驱动的
   `<...>` 语法是照 `config.fluffos` 里 `include directories :
   /include` 解析的，不认得这种写法。其他所有需要
   `quest_finished()`/`quest_failed()`/`lock_quest()` 的档案都是用
   `#include <quest.h>`（对应到内容几乎一样、更新一点的
   `/include/quest.h`）——改成一致写法。
6. **连锁问题**：quest.h 里声明了一个全局 `quest_name` 映射，一旦
   上面那条 include 真的生效了，它就出现在 `combatd.lpc` 的
   `inherit F_DBASE;` 之前，触发"Illegal to inherit after defining
   global variables"。把 `#include <quest.h>` 挪到 `inherit` 语句
   之后即可。

顺带修了 `check_legal_name()` 自己的经典 §8.1 `i%2` 奇偶门槛和字
节数长度上限（4-10，原意是 2-5 个中文字），改成逐字符
`is_chinese()` 检查、长度上限改成字符数 2-5（`adm/simul_efun/
chinese.lpc` 里真正的 `is_chinese()` 本身已经是正确的码点区间检
查）。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（已有
  多个 `(admin)`/`(arch)`/`(wizard)` 账号），`wizlist` 命令确认显
  示"目前权限：(admin)"。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/xkx100
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40117**。
