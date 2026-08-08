# 三界神话完整加强版「泉州师院」(sjshwzjqb)

"三界神话"系列第五个、也是最后一个档案（另见 099 `sjsh`/宝鸡站、
100 `sjshv150`/紫藤分站、101 `sjshv2578bb`/测试二区、102 `sjshwzb`
/泉州师院完整版），和 102 `sjshwzb` 同源，核心文件（`master.lpc`/
`securityd.lpc`/`logind.lpc`）与已知 bug 集合完全一致：
`master.lpc` 的 `log_error()`/`standard_trace()` 没有呼叫
`CHANNEL_D`（§7.60 不适用），`securityd.lpc` 的 `valid_read()` 不
会覆盖 `user` 参数，也没有 `sited.lpc`（不存在本地回环限制）。

## 内容亮点

- 是 `sjshwzb`（泉州师院完整版）的"加强版"，地图内容几乎完全一致
  （阿修罗、魔界、天空界等场景都在），核心系统档案与已知 bug 集合
  也逐一对应相同。
- 和 `sjshwzb` 的主要区别在于运维细节：这份档案的 `wizlist` 原本
  是空文件（`sjshwzb` 已经有两个既有巫师），管理员账号是完全从零
  写入的。
- 出生地〖南城客栈〗人物齐全：留言板、送礼物的☆小宁宁☆、店小二，
  以及暗示存在邮件系统的邮差"千里眼"（`d/ourhome/npc/bigeye.lpc`）。
  经 §10.7 深度功能测试确认死亡→复活循环完整可玩：真实战斗击杀
  朱雀大街的疥顶小僧后，送入〖阴阳界〗由判官崔珏走完生死簿对话，
  复活落地荒郊小店；峨嵋〖华严顶〗（`d/emei/`）也已修复至可正常
  进入，详见下方「本次修复的关键 bug」。

## 本次修复的关键 bug

1. **损坏的 `convertd.lpc` 字节**：和 `sjsh`/`sjshv150`/`sjshwzb`
   完全相同的损坏模式，同样的非 UTF8 杂散字节紧贴闭合引号（"Illegal
   character 0xce/0xb2/0xee/0x96/0xa3"，第 258 行附近）。用同样的
   字节级 Python 脚本修复了 45 处。
2. **经典 §8.1 `check_legal_name()` 的 `i%2` 奇偶假设**：和
   `sjshwzb` 完全相同的 bug 和修法——`adm/daemons/logind.lpc` 改成
   逐字符检查（`is_chinese(name[i..i])`，去掉奇偶门槛），长度限制
   从字节数 2-12 改成字符数 1-6。`adm/simul_efun/chinese.lpc` 的
   `is_chinese()` 本身已经正确，不用改。
   `emoted.lpc`/`message.lpc`/`channeld.lpc` 逐一检查过，均不存在
   已知 bug。
3. **§10.7 深度功能测试（2026-08-08）新发现并修复的 bug**，详见
   `NOTES.md` 的完整记录：`logind.lpc` 遗留调试 `printf`（§7.34）、
   `file.lpc` 的 `log_file()` 缺 `assure_file()` 防护（§7.11）、
   峨嵋〖华严顶〗房间引用大写 `.C` 文件在运行时 case-mismatch 崩溃
   （§8.15，`EMEI_B.C`/`YINGKE.C` 已重命名为小写）、以及移植 §8.15
   修复时新发现的 `carry_object()` 存在性检查对无扩展名路径假阴性
   （新增 AGENTS.md **§7.99**）——起始房间南城客栈的邮差"千里眼"
   NPC 原本会因为这个假阴性在每一次新角色注册时 100% 崩溃，已连带
   修复并回填到 `sjshwzb`。§7.97（LISTNODES 死亡死循环）、§8.13
   （WIZ 密码二次登录死锁）等其余家族已知 bug 类别均已逐条核实，
   本档案不适用。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **管理密码 / Admin password**: `Mud@2026`
- **普通密码 / Regular password**: `Mud@2027`（双密码机制，规则要求
  两个密码不能相同）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（这份
  档案的 wizlist 原本是空文件，本次重新写入），登录横幅直接显示
  "您的系统权限目前是：(admin)"确认生效，`update` 指令验证写权限
  正常。经 §10.7 深度测试确认可正常二次重连（本档案无 §8.13 类的
  WIZ 密码登录死锁）。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示

和 `sjshwzb` 完全相同：选择内码（GB/BIG5）→ 是否中小学生（回答
no）→ 输入 `new` → 英文 ID → 中文名字 → 管理密码 + 确认 → 普通密码
（必须与管理密码不同）+ 确认 → email（需要 `xxx@xxx.xxx` 格式）→
个人主页/ICQ（可留空）→ 性别 → 是否接受赠礼 → 天赋点分配。

## 本地运行

```
cd libs/sjshwzjqb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40173**。
