# 清华笑傲江湖 (qhxajh)

和 019（xo，迷你版）、019-1（xo_final，最终版）同属 TMI-2/ES2/Falcon 系
引擎家族，是清华大学版本的《笑傲江湖》，门派/剧情内容与前两者不同。

## 本次修复的关键 bug

1. **经典 §8.1 GBK 字节区间 `is_chinese()` 判断错误**，已改成正确的码
   点区间检查。
2. **姓名长度上限没有减半**：`logind.lpc` 的 `check_legal_name()` 用
   `(strlen(arg) < 4) || (strlen(arg) > 10)`，但这是字节数时代的旧上
   限；提示语写的是"2 到 5 个中文字"，已改成 `(< 2) || (> 5)`。
3. **闭包形式的 `input_to` 在这个驱动下静默失效**：`get_id()` 里唯一
   一处用 `input_to( (: get_id :), ob )`（闭包），和同一份档案里其他
   所有调用点用的字符串形式不一致，已统一改成
   `input_to("get_id", ob)`。
4. **§7.52 socket 精灵编译失败**：`secure/daemon/ftpd.lpc` 用了这个驱
   动未定义的 socket efun，100+ 处调用点，且没有任何外部档案调用它的
   非 socket 功能——直接从 `secure/etc/preload` 里移除这一条预加载项。
5. **§7.1 `master.lpc` 的 `valid_read`/`valid_write` 自举死锁——一种此
   前未记录的"静默"变体**：AGENTS.md 已有的 §7.1 描述的是这个 bug 崩
   溃成堆栈溢出的形式；这份驱动构建把 `load_object()` 失败降级成一个
   被 `catch()` 吞掉的 "Object cannot be loaded during compilation" 错
   误而不是崩溃，于是 bug 表现成完全无声的一种：`securityd.lpc` 自己
   的 `create()` 读取 `wizlist` 文件时触发 `valid_read()`，后者（缺少
   重入保护）又尝试 `load_object(SECURITY_D)`——但此时 `securityd.lpc`
   自己还在编译中，编译它需要的每一次嵌套读取（自身源码、`#include`、
   `inherit` 的档案）都会同样地递归回 `valid_read()`，没有一次能真正
   完成，`securityd` 永远无法成功加载，`wiz_status` 永远是空 mapping,
   于是包括 wizlist 文件里已有的账号在内，所有 id 都被判定成
   `(player)`。用 `previous_object() == securityd` 这种写法特判**修不
   好**这个变体——编译器触发的这些嵌套读取里，`previous_object()` 报
   告的永远是 master 自己（谁调用的 `load_object()`），不是
   securityd。唯一有效的修法是 §7.1 文档里给出的重入标志位。已把这个
   新变体补充进 AGENTS.md §7.1。
6. **缺失的 `log/nosave` 目录**（§7.11，已在本地创建，按项目惯例不纳
   入版本控制）：`log_login()` 的 `log_file()` 调用因为目录不存在而
   崩溃，导致每次注册时 `get_gender()` 静默失败。

另外把 `config.fluffos` 的 `maximum evaluation cost` 从 `700000` 调高
到 `5000000000`——原来的极小上限会把 preload 拆成约 150 次各被打断
700 步求值成本的恢复，总耗时约 100 秒；这不是 bug，只是慢，调高后
preload 一次性顺畅完成。

## 注册流程

英文 id → 确认建立新角色（y/n）→ 中文名字（2-5 个汉字，会过滤金庸小
说人物名等敏感词）→ 密码（至少 6 位）→ 确认密码 → 电子邮件（可随意
填）→ 性别（m/f）→ 进入游戏世界。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **权限 / level**: `(admin)` —— 通过 `/secure/etc/wizlist` 授予，
  `SECURITY_D->get_status()` 据此判定。
- 首次连线会走上面的注册流程；密码由你在注册时自己设定。

## 本地运行

```
cd libs/qhxajh
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40195**。
