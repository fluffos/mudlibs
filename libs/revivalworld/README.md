# 重生的世界 (RevivalWorld)

台湾出品的正体中文（BIG5）经营/建设类文字 MUD，源码自称 RWlib，基于 MudOS v22.2b14 打造。与本收藏中占多数的大陆简体武侠对战类 MUD 家族完全不同宗——世界观、指令、地图/城市/任务名称均为英文（例如 "Suphia and Benjamin" 任务链），游戏内容围绕占地建城、 组织政府、经营商店仓库、农业转工业转知识时代的生产链，以及一套简单的股票市场展开，而非门派武功对战。

## 内容亮点

- 本项目在这个库上做了这个收藏至今最深的一轮驱动兼容性修复：
  原始档案基于一套重度自定义过的 MudOS 驱动，提供了一整套本项目
  标准 FluffOS 驱动没有的私有 efun——F_DBASE 式的 `set`/`query`/
  `delete`/`addn`（及 `_temp` 版本）属性存储系统、`ansi`/
  `remove_ansi`/`kill_repeat_ansi` 等 ANSI 处理函数、大数字符串
  运算 `count()`、以及中文断行 `cwrap()`——全部以 simul_efun 形式
  移植重建。
- 最高影响的单一 bug：`creator.lpc`（开机自动执行）自带的
  `#define` 头文件生成器，因为沿用了旧版"去掉 2 字符 `.c` 后缀"
  的字符串切片宽度，在改名为 4 字符的 `.lpc` 后再也匹配不到任何
  文件——导致每次开机都把全库几乎所有档案都要用到的四份头文件
  （`daemon.h`/`feature.h`/`inherit.h`/`condition.h`）静默清空成
  只剩注释的空壳，进而让 `simul_efun.lpc` 本身都编译失败、
  级联导致批量编译扫描里 800 多个档案几乎全部报错。同一处切片
  宽度 bug 还独立出现在指令派发表（`command_d.lpc`，导致全部
  玩家指令永远无法注册）和开机预载清单过滤器
  （`system_d.lpc`，导致连"必须最先载入"的城市系统都被静默跳过）
  里，一并修正。
- 另有一处更隐蔽的联动 bug：开机时懒加载的表情精灵
  （`emote_d.lpc`）尝试还原一份与本驱动格式不兼容的存档，
  抛出的错误未被捕获、又恰好是在指令系统（`command_d.lpc`）
  重建指令表的过程中被间接触发——导致指令表重建整个中断，
  全站玩家指令（`look`/`score`/`quit`……）从开机第一刻起就全部
  失效，直到补上 `catch()` 才修复。
- `intermud2_d.lpc` 会真实绑定一个 UDP 端口并向存档中的其它站点
  发送/接收真实的 Intermud-2 风格广播封包——本收藏中少数几个会
  产生真实对外网络流量的档案之一。

详见 `NOTES.md`（英文，含完整移植细节）。

## 在线试玩

https://mudlibs.fluffos.info/revivalworld/

## 管理员账号 / Admin account

- 账号 id：`fluffos`　密码：`Mud@2026`
- 权限：通过直接编辑持久化存档 `system/kernel/data/secure.o`
  （纯文本 `mapping wizards` 格式）追加 `"fluffos":"admin"`
  授予，与档案自带的 `clode`/`msr` 两个默认管理员账号采用同一
  机制。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放
> 主机，请先修改此密码（或删除该账号及存档中的授权项）。

## 本地运行

```
cd libs/revivalworld
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40238**。

> 注意：`intermud2_d.lpc` 在启动时会绑定一个真实 UDP 端口并与公网
> 上的其它 MUD 交换广播包，不建议高频率自动重启此档案；开机预载
> 会持续约 2-3 分钟（`html_d.lpc` 渲染世界地图耗时较久，属已知的
> 单次开机成本，详见 `NOTES.md`），属正常现象而非卡死。
