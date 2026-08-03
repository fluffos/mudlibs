# 西安交大西游记 (xajdxyj)

"神话世界·西游记"4.50 版，游戏内品牌为《欢乐园》("A Journey to the
West"，大学生版)，西安交大兵马俑 BBS 附属的 MUD。

## 内容亮点

- 严格取材《西游记》神话世界观：地图有高老庄（`d/gao/`，含卧室、
  后院等场景）、三十三天、蟠桃园、蓬莱、南海、天宫等取经沿途的经
  典地标，和"三界神话"系家族（99-101 号）共享的地名风格是巧合，
  代码库并不相同。
- 校园 BBS 背景的"大学生版"定位：游戏内品牌是《欢乐园》，`d/happy`
  场景与之呼应；`task`/`renwu` 目录提供任务系统。
- 开机后有 180 秒的连线保护期，测试或登录必须在第一行送出字面量
  绕过短语 `let me join ok` 才能跳过（详见下方"已记录但不是 bug"
  说明），是这份档案自己特有的防灌水设计。

## 本次修复的关键 bug

1. **损坏的 `convertd.lpc` 字节**：和 `sjsh` 系家族完全相同的损坏
   模式（45 处，同样的 "Illegal character 0xce/0xb2/0xee/0x96/
   0xa3" 特征，出现在第 250 行附近）。用同样的字节级 Python 脚本修
   复。
2. **真正的语法错误**：`adm/daemons/logind.lpc` 的 `banned_name`
   数组字面量里，有一行开头多了一个逗号（上一行结尾的逗号后面紧跟
   `,"欢乐园"...`），产生了一个空数组元素——LPC 不像 JS 那样容忍
   这种写法，直接编译失败，并连锁引发文件后面 5 个额外的解析错误
   （包括"Undefined variable mud_list"，因为解析器再也没能恢复正
   常）。已去掉多余的逗号。
3. **经典 §8.1 GBK 字节配对 bug**：`adm/simul_efun/chinese.lpc` 的
   `is_chinese()` 和 `adm/daemons/logind.lpc` 的
   `check_legal_name()` 都假设每个中文字占两个字节（`strlen%2` 奇
   偶门槛，以及用一个"魔法参考字符串"做原始字节区间比对），在这个
   驱动按 UTF8 码点索引字符串的情况下，奇数字数的合法中文名字会被
   误判为不合法。两处都已改成逐码点的 0x4e00-0x9fff 区间检查，
   `check_legal_name` 的长度上限也从字节数 2-12 改成字符数 1-6。

## 已记录但不是 bug：连线开机保护期

`logind.lpc` 的 `encoding()` 有一个 180 秒的连线保护期——开机后
`CONTROL_CENTER->query("MUD_SRART_TIME")`（原始代码就拼错了
"START"）在 3 分钟内会拒绝所有正常连线，除非**第一行**送出的是字
面量绕过短语 `let me join ok`。这是有意的防灌水/开机稳定期设计，
不是缺陷——测试脚本第一行必须先送这个短语。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设（单一密码 + 确认，没有双密码机
  制）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（原文
  件是空的），`wizlist` 命令确认显示"目前权限：(admin)"。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/xajdxyj
~/src/fluffos/build-debug/src/driver config.fluffos
```

连线时第一行请先输入 `let me join ok` 绕过开机保护期。游戏端口：
**40179**。
