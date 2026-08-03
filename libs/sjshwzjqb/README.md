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

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **管理密码 / Admin password**: 注册时自设（至少 5 位，且不能与
  普通密码相同）
- **普通密码 / Regular password**: 注册时自设（双密码机制）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（这份
  档案的 wizlist 原本是空文件，本次重新写入），登录横幅直接显示
  "您的系统权限目前是：(admin)"确认生效。

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
