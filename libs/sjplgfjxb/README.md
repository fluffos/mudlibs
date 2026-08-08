# 书剑飘零官方教学版 (sjplgfjxb)

ES II 引擎家族（`adm/obj/master.lpc`，"original from Lil, rewritten by
Annihilator"），飞白工作室出品的《书剑飘零》官方教学版，与同门
`sjplii`（书剑飘零II）同源；虽然名字里也带"书剑"，但和 Century/
adm-single 家族的 `sjecl`/`sje` 属于完全不同的引擎谱系，纯属巧合。

## 内容亮点

- 新角色的出生地由角色创建时选择的"出生状况"（书香门第/商贾之家/
  贫寒农家/武力世家）决定，分别落在山东泰安或福州的一户普通民居
  （`adm/daemons/logind.lpc` 的 `start_loc` 数组），并非长安城；
  长安城的"大慈恩寺"（`d/city/ciensi`）只在角色已保存的
  `startroom` 失效时才作为兜底出生点使用。长安城本身仍以唐代真实
  地标为骨架展开（`d/city/` 下的城门都用真实地名，如 `kaiyuan-men`
  开远门、`zhuque-men` 朱雀门、`qixia-men`/`yanping-men`/
  `tonghua-men`/`yanxing-men`；`ciensi` 大慈恩寺、`baodian` 保定殿
  等也是真实地标），是游戏地图的另一大区域，值得探索。
- 除了常见的拜师门派体系，还提供一条独立的"镖师"生涯：加入"红旗
  镖局"（`d/city/biaoju/`，含帐房、佛堂、武器库等一整套镖局建筑）
  只需 `shenqing` 申请即可上任，不必事先拜师，`tuichu` 可随时退出。
- 武学招式多为原创命名（如"醉棍""风刃""无尘步"等），不是直接照搬
  金庸小说里的招式名称，自成一套武侠世界观。
- 巫师账号有一处刻意保留的"吵闹"设计：`master.lpc` 的
  `log_error()` 会把每一次编译警告实时转发给当时在线的玩家，新角色
  第一次创建时因为多个 feature 档案首次编译，会看到一串"你发现事情
  不大对了，但是又说不上来"提示——这些都只是无害的"Unused local
  variable"编译警告，不影响游戏本身。

## 本次修复的关键 bug

1. **`master.lpc` 的 `report_error()` 在 `CHANNEL_D` 尚未加载时呼叫
   它**（§7.60 类的第三个变体——这份档案里 `log_error()`/
   `standard_trace()`/`report_error()` 是三个各自独立的函数，只有
   `report_error()` 缺了保护）：补上 `find_object(CHANNEL_D)` 判断。
2. **`adm/daemons/whod.lpc` 用了未定义的 `REMOTE_DIR` 常量**，而这
   个精灵在 preload 列表里，直接导致它编译失败。硬盘上没有对应的目
   录可以推断原意，但 `get_dir()` 对不存在的目录只会返回空数组，所
   以在 `globals.h` 里补上 `#define REMOTE_DIR "/data/remote/"` 是
   安全的（哪怕这个目录本身从未真正被创建）。
3. **§7.41 类损坏的存档数据**：`adm/daemons/emoted.lpc` 的
   `create()` 对自己损坏的 `emoted.o` 存档做了未加保护的
   `restore()`，preload 时未捕获抛出——已包一层 `catch()`，并显式补
   上 `emote=([])` 兜底。
4. **§7.34 类调试遗留**：`adm/daemons/logind.lpc` 的 `get_resp()`/
   `get_name()`（角色创建流程中确认中文名字的两条并行路径）各留了
   一行 `printf("%O\n", ob)`，会在设定密码提示前把登录物件的内部路
   径（`/obj/login#N`）原样打印给玩家看——已删除两行。
5. **一处编译期 ERROR**：`d/fuzhou/npc/chess_player.lpc`（棋摊老板
   韦守儒）的 `play_chess()` 把继承自 `feature/name.lpc` 的本地方法
   `name(int raw)` 当成"取得对方名字"的自由函数误用为
   `name(this_player())`——传对象给一个只接受 int 的参数，编译直接
   报错，导致这个 NPC 全程无法编译，福州"茶馆"（`d/fuzhou/
   tearoom2`）填充该 NPC 时级联出 `*No program in object` 崩溃並反
   复刷屏。已改为 `this_player()->name()`，顺带删掉同一行紧挨着的一
   处无意义 `printf` 调试输出（§7.34 类）。
6. **§7.86 类第三个变体**：`obj/board/wizard_j.lpc`（巫师工作进度报
   告板）`inherit "/std/jboard"` 之后又多余 `replace_program(
   "/std/jboard")`，与已修复的 31 处 `BULLETIN_BOARD`/`inherit`
   实例是同一 bug 形状，只是换了一个板类基类名字；`/std/jboard.lpc`
   自己的 `do_report()`/`do_describe_project()` 也用
   `this_player()->edit((: lfun, ... :))` 建闭包，一样会崩。已删除
   多余的 `replace_program()` 调用。

## 排查过程中确认"不是 bug"的现象

注册过程中反复出现"你发现事情不大对了，但是又说不上来。"——这是这
份档案自己（有点吵闹但故意如此）的设计：`master.lpc` 的
`log_error()` 会把**每一次编译警告**都告诉当时正好连线中的玩家，而
新角色第一次创建时，其继承的各个 feature 档案（alias/damage/more/
move/skill/troop）恰好都是第一次编译。临时让 `error_handler` 无条
件显示完整细节后确认：每一条都只是无害的"Unused local variable"警
告。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`（标准注册流程完成，`update` 指令验
  证过读写权限正常）
- **权限 / Level**: `(admin)`，`/adm/etc/wizlist` 里早已有
  `fluffos (admin)` 一行，注册该 id 后自动获得。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/sjplgfjxb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40134**。
