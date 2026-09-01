# 三界神话完整版「泉州师院」(sjshwzb)

"三界神话"系列第四个档案（另见 `sjsh` 宝鸡站原始版、`sjshv150` 紫藤分站、`sjshv2578bb` 测试二区），泉州师范专科学院站点的完整版内容，是家族里内容最扩充的一份：除共享的武当/古墓/蜀山/雪山门派场景和开封解谜任务区外，独有整套"阿修罗"（`d/axiuluo/`）、"魔界"（`d/Mojie/`）、"天空界"（`d/tiankongjie/`）等佛教/神话场景，以及少林、峨嵋、昆仑等前三份同系档案都没有的门派；其核心系统档案（`master.lpc`/`securityd.lpc`/`logind.lpc`）和前三份并非同源，是家族内部代码分叉较大的一支。注册流程也更完整，多了管理密码+普通密码的双密码机制、个人主页/ICQ 字段和天赋点分配画面。同一批档案里的 `sjshwzjqb`（增强版）与这份档案的地图、门派名单和核心系统档案几乎逐字节一致（99% 以上相同路径完全相同），是在此基础上小幅增强的姊妹版本。

## 本次修复的关键 bug

1. **损坏的 `convertd.lpc` 字节**：和 `sjsh`/`sjshv150` 完全相同
   的损坏模式——转换表里混入了非 UTF8 的杂散字节，紧贴在闭合引号
   前面，最后一个字节（`0x5C`）把引号转义掉，导致编译失败（"Illegal
   character 0xce/0xb2/0xee/0x96/0xa3"，出现在第 258 行附近）。用
   同样的字节级 Python 脚本修复了 45 处。
2. **经典 §8.1 `check_legal_name()` 的 `i%2` 奇偶假设**：
   `adm/daemons/logind.lpc` 的合法中文名字检查假设每个中文字占两
   个字节，用 `i%2==0` 隔一个字节检查一次；这个驱动是按 UTF8 码点
   索引字符串的，所以奇数字数的中文名字会被误判为不合法。已改成
   逐字符检查（`is_chinese(name[i..i])`，去掉奇偶门槛），并把长度
   限制从字节数 2-12 改成字符数 1-6（对应提示文字"一到六个中文
   字"）。`adm/simul_efun/chinese.lpc` 里的 `is_chinese()` 本身已
   经是正确的码点区间判断（0x4e00-0x9fff），不用改。
   这份档案没有 `emoted.lpc`/`message.lpc`/`channeld.lpc` 相关的
   已知 bug（都逐一检查过，均不存在或不需要修）。
3. **§10.7 深度测试新发现：`logind.lpc` 的 §7.34 debug printf 泄漏**
   （`get_name()` 里裸 `printf("%O\n", ob)`，把登录对象内部路径打
   印在中文名字确认和密码提示之间）、**`file.lpc` 的 §7.11 缺
   `assure_file()` 防护**（已补），以及**`obj/board/EMEI_B.C` 漏网
   的 §7.86 留言板崩溃**（跨库扫描按 `*.lpc` glob 找的，这份档案唯
   一一个全大写 `.C` 扩展名的留言板漏网了）——均已修。修 `EMEI_B.C`
   时进一步发现峨嵋"华严顶"房间还有两层更深的运行时崩溃：`set(
   "objects", ...)` 里引用的 NPC 文件 `d/emei/NPC/YINGKE.C`（目录
   和文件名都是大写）、以及该 NPC 自己 `carry_object()` 一件从未存
   在于 `work/` 里的 `/d/shaolin/obj/cloth.c`（整个 `d/SHAOLIN/`
   大写目录从未被转档流程处理过）。这三处只在真正**进入房间**（或
   `update` 强制重编译）时才炸，编译期检查和之前两轮 WASM 验证完全
   看不出来——详见 AGENTS.md 新增的 §8.15、`NOTES.md` 的深度测试记
   录。已修：两个大写文件改名成小写 `.lpc`（`git mv`）+ 更新引用，
   `std/char/npc.lpc` 的共享 `carry_object()` 加了 `file_size()` 前
   置检查防止不存在的路径把整条 NPC create() 链炸掉。`d/SHAOLIN/`
   目录本身（102 个档案）**未**全量转档，超出本轮范围。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **管理密码 / Admin password**: `AdminPass123`
- **普通密码 / Regular password**: `Mud@2026`
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  横幅直接显示"您的系统权限目前是：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示

注册顺序是：选择内码（GB/BIG5）→ 是否中小学生（回答 no）→ 输入
`new` → 英文 ID → 中文名字 → 管理密码 + 确认 → 普通密码（必须与
管理密码不同）+ 确认 → email（需要 `xxx@xxx.xxx` 格式）→ 个人主页
/ICQ（可留空）→ 性别 → 天赋点分配（`get_gender()` 里 `confirm_gift()`
是硬编码 `"n"` 自动呼叫的，不会真的弹出"是否接受赠礼"的互动提示，
§10.7 深度测试确认过）。

## 本地运行

```
cd libs/sjshwzb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40113**。
