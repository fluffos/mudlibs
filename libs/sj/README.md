# 世纪 (sj)

《世纪》科幻星际战争题材代码库，`adm/obj/master.lpc` 一支——虽然 slug 与 `sje`/`sjecl`（书剑系列）相似，但其实是完全不同的 Century/adm-single 家族，不要混淆；房间级别上它与本项目另一姊妹档案 `shiji`（同样自称"世纪"）几乎完全一致——天狼星区、四大阵营、太空港口等内容连文件都能对上，两者差异主要在安全精灵/master 对象的实现层面，属于同一款原作游戏的两次独立服务器部署，而非各自独立的作品。新角色从"天狼"星区的街道开局，"太空港口"（`d/taikong/`）可以花电子货币购买星际战舰，分别通往中心城的四大阵营——凤凰星、皇族、圣殿、特种部队（`budui`）；权限称号也走同一套科幻风格，管理员在游戏内显示为〖银河特警〗（Galaxy Special Police），传统 kungfu 目录结构（`kungfu/class`、`kungfu/skill`）被保留下来，配合"绝地""监狱""部队""神殿"等场景，呈现出科幻背景下的江湖势力划分。

## 内容亮点

- 管理员的启动授权走的是另一条隐藏路径：`securd.lpc` 自己的
  `restore_list()` 里硬编码了一个后门账号 `keyboy`（`(zhuguan)`），
  和标准的 `wizlist` 文本文件完全无关（详见下方"本次修复的关键
  bug"第 4 条）。
- 深度功能测试完整走通了注册→天狼星区探索→与 NPC 交谈→战斗→死亡
  →鬼门关复活的全流程（复活后送到"太空港口"，呼应科幻题材），修
  复了 §8.9 食物/饮水年龄检查错对象、两处 `d/death/npc/{b,w}
  gargoyle.lpc` 的 §7.68 复活软锁，详见 NOTES.md。

- **更正（2026-08-05）**：上面提到的"7.68 复活软锁"修复已经撤销——经重新评估，鬼魂"不在场"时放弃复活流程更可能是有意的游戏设计（多数这类档案里鬼魂本身就无法自行移动，离开是一种游荡机制，回来时 init() 会重新触发流程），不是需要强制重试的 bug；详见 NOTES.md。

## 本次修复的关键 bug

1. **`master.lpc` 的 `log_error()`/`standard_trace()` 在 `CHANNEL_D`
   尚未加载时呼叫它**（§7.60 类），触发编译期递归加载崩溃——两处都
   补上 `find_object(CHANNEL_D)` 判断。
2. **大小写不一致的计数器文件**：`logind.lpc` 的 `VISITORS`/
   `GIFTCARD` 宏指向 `/adm/single/MUDVISITOR`/`GIFTCARD`（大写），但
   硬盘上的实际文件是小写 `mudvisitor`/`giftcard`——导致每一次连线
   `sscanf()` 都会因为 `read_file()` 返回 0 而崩溃（"the user is
   disconnected"，看起来像服务器完全没反应）。已修正宏的大小写，并
   给两处 `sscanf()` 补上 `stringp()` 防护。
3. **`logon()` 里少了一个 `return`**：`!find_object(DNS_MASTER)`
   这个分支（在本项目"不启用 socket 包"的标准处理下，这个分支永远
   会被走到）已经显示了简化版欢迎屏并提示输入 ID，但少了 `return`，
   导致函数继续往下执行，无条件呼叫 `DNS_MASTER->query_muds()`，每
   次连线都触发一次"未定义 socket efun"的编译报错。
4. **两个"像是安全精灵"的档案**：`SECURITY_D` 宏实际指向
   `adm/daemons/securd.lpc`（一个存档式/dbase 精灵，硬编码了
   `keyboy` 作为 `(zhuguan)` 的启动后门），和长得很像但完全没被用
   到的 `adm/daemons/securityd.lpc` 是两个不同的档案（同类问题参见
   AGENTS.md §7.56）。一开始误把 `fluffos (admin)` 写进
   `/adm/etc/wizlist` 文本文件，完全没有效果，因为 `securd.lpc` 根本
   不读这个文件——后来改成在 `securd.lpc` 自己的
   `restore_list()` 里，紧挨着 `keyboy` 那行加一行
   `set("wiz_status/fluffos","(admin)")`，和它自己既有的启动后门用
   同一套写法。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设（至少 5 个字符）
- **权限 / Level**: `(admin)`（游戏内显示为〖银河特警〗），通过
  `adm/daemons/securd.lpc` 的 `restore_list()` 硬编码启动授予。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/sj
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40127**。
