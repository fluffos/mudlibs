# 鹿鼎天下（游戏内实际品牌：雄霸天下『西安站』）

源自 2026-07-29 批量归档 `mudlib.rar` 中的 `鹿鼎天下.rar`。"世纪
(Century) / adm-single" 引擎家族的一支（与 `shiji`、`shujian2008`、
`xjcq2000`、`xkxz2`、`xiakexing100` 同源），ES II 血统。

有趣的是，压缩包本身叫"鹿鼎天下"，但登入画面品牌其实是"雄霸天下
『西安站』"，而 `quit` 退出提示又写着"离开了鹿鼎天下"——两个名字
同时残留在代码里，看起来是曾经改过品牌但没有全部替换干净。

## 内容亮点

- 经典金庸武侠背景的门派/武功养成类泥巴：膂力、悟性、根骨、身法四维
  属性，另有隐藏的福缘、容貌影响解谜与拜师。
- 客栈开局，NPC 店小二和一只可爱的小白狗会互动欢迎新玩家。
- 明确提醒"请尽量不要选择金庸小说中已有人物姓名"，鼓励玩家自创
  角色名而非直接扮演原著人物。
- 死亡机制走的是"原地昏迷→片刻后自动苏醒＋精气属性惩罚"，不是分
  阶段的鬼魂/冥界流程——被打倒后角色留在原地，`look`/`score` 等指
  令短暂被封锁，几秒后自动恢复行动，死亡次数与最后死因会记入档案。

**血统澄清**：游戏内品牌"雄霸天下"同时也是另一份完全不同代码库
`xbtxiii`（雄霸天下III）的品牌名，但逐行核对 `master.lpc`/
`securityd.lpc`/`config.fluffos` 后确认**两者不是同一份代码**——
`ldtx` 的 `master file` 指向 `/adm/single/master`（档头明确写着
"for ES II mudlib... modified by Xiang for XKX"，`securd.lpc`+
`securityd.lpc` 两文件分工），`xbtxiii` 指向 `/adm/obj/master`（无
该血统注释，`securityd.lpc` 是单一文件）。两者 `connect()` 函式体
确实一字不差相同，说明共享更早的"东方故事 ES II"共同祖先（AGENTS.md
§11），但各自独立演化，不属于同一具体分支——"雄霸天下"是被至少两
个互不相关的分支各自沿用的品牌名，与本项目已反复验证的"共享品牌
名≠共享血统"规律（§5.1）再添一例。`ldtx` 真正的血统伙伴是下面已
记录的 Century/adm-single 家族。详见 NOTES.md 深度功能测试小节。

## 注册流程

选择编码 GB 或 BIG5（本地/浏览器测试用 `gb`）→ 按 Enter 跳过跨服
Mud 列表 → 英文名字（3-8 个小写英文字母）→ 确认建立新角色（y/n）
→ 中文名字 → 密码（至少 5 位）→ 确认密码 → 天赋分配（输入 0-4，0
代表全部交给系统随机产生，1-4 代表自己指定该项数值再随机其余项；
一般直接用 0）→ 是否接受这组天赋（y/n）→ 电子邮件地址 → 性别
（m/f）→ 进入游戏世界。

## 本次 WASM 验证修复的关键 bug

- `adm/daemons/network/dns_master.lpc`：`startup_udp()`/`send_udp()`
  用到的 `socket_create()`/`socket_bind()` 在这个 WASM 编译版本里
  是未定义的 efun，导致整个档案编译失败（AGENTS.md §7.52 的
  socket-daemon 模式）。由于连线一开始的编码选择步骤
  `encoding_to_mudlist()` 就会呼叫 `DNS_MASTER->query_muds()`，档
  案编译失败会打断这次呼叫之后的所有逻辑，导致每一次连线都在编码
  选择后卡死。已将 `startup_udp()`/`send_udp()` 清空为直接返回，
  `send_shutdown()` 里的 `socket_close()` 呼叫也一并移除——跨服互
  联在 WASM 试玩范围内本来就用不到。

没有发现 Chinese 姓名判断、宏定义或指令表相关的 bug。

另外发现一个内容缺失（`d/city/npc/xiaobao.lpc` 的 `create()` 引用
了不存在的 `/u/rhxlwd/cloth.lpc`）——WASM 阶段曾误判为"被房间自己
的 catch() 接住、无害"，**后续 §10.7 深度功能测试追查发现并不是
这样**：这个未捕获的例外实际会打断开局客店房间 `create()` 里紧接
在后面的留言板加载语句，导致这份档案的开局留言板每次开机都不会出
现。已用标准防御性守卫修复（不补内容，只挡例外），详见 NOTES.md
和 AGENTS.md §7.73。

## 移植修复（详见 NOTES.md）

姊妹档案 `ldtxii` 深度测试时在 `logind.lpc` 发现两个 bug，逐行核
对后确认这份档案在完全相同的行号有一字不差的同一段代码——已移植
过来：调试残留 `printf("%O\n", ob)`（AGENTS.md §7.34）和食物/饮水
满值初始化误读 `ob->query("age")`（应为 `user->query("age")`，
AGENTS.md §8.9）。两处均已修复并用新角色验证。

## 在线试玩

https://mudlibs.fluffos.info/ludingtianxia/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)`（最高级别），通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/ldtx
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40105**。
