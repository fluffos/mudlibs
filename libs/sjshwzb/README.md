# 三界神话完整版「泉州师院」(sjshwzb)

"三界神话"系列第四个档案（另见 099 `sjsh`/宝鸡站、100 `sjshv150`/紫
藤分站、101 `sjshv2578bb`/测试二区），泉州师范专科学院站点的完整
版内容。这份档案的核心文件（`master.lpc`/`securityd.lpc`/
`logind.lpc`）和前三个档案并非完全同源：`master.lpc` 的
`log_error()`/`standard_trace()` 根本没有呼叫 `CHANNEL_D`，所以
§7.60 那个死锁在这里不存在；`securityd.lpc` 的 `valid_read()` 也
没有覆盖 `user` 参数的问题；这份档案也没有 `sited.lpc`，不存在
本地回环限制。

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

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **管理密码 / Admin password**: 注册时自设（至少 5 位，且不能与
  普通密码相同）
- **普通密码 / Regular password**: 注册时自设（双密码机制）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  横幅直接显示"您的系统权限目前是：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示

注册顺序是：选择内码（GB/BIG5）→ 是否中小学生（回答 no）→ 输入
`new` → 英文 ID → 中文名字 → 管理密码 + 确认 → 普通密码（必须与
管理密码不同）+ 确认 → email（需要 `xxx@xxx.xxx` 格式）→ 个人主页
/ICQ（可留空）→ 性别 → 是否接受赠礼 → 天赋点分配。

## 本地运行

```
cd libs/sjshwzb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40113**。
