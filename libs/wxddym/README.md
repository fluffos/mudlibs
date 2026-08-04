# 武学大道

一款以「世外桃源」为起点的武侠 MUD，采用非标准的移动端客户端协议
（非纯文字 telnet 提示语）。

## 内容亮点

- **注册协议**（非常规 telnet 提示）：连线后先回车一次触发握手，登录行
  格式为 `英文id║密码║密文║邮箱`（`║` 为 U+2551 全直线字符，非逗号），
  新角色创建行格式为 `性别║头像║昵称`（如 `0║0║秦风`）。
  实际字段来自直接阅读 `adm/daemons/logind.lpc` 的
  `jiance()`/`get_user()`/`get_char()` 回调链得出。
- `score` 会提示"还没有出生呐，察看什么？"——这不是 bug，是与
  `hhsj`（洪荒世界）同宗的"降生"仪式设计，需要在游戏内完成特定
  NPC 互动后才会"出生"。**完整流程（详见下方"深度功能测试"）**：
  "世外桃源"→"阎罗殿"→在忘忧池洗四项属性点（`washto`）→刷新天赋
  （`pianshu msx`）→选性格（`knock`）→投胎选籍贯（`born`，扬州人
  氏/段氏皇族/唐门世家/中原苗家/关外胡家/慕容世家/欧阳世家七选
  一）——本项目第一次真正把这类"nitan 血统降生仪式"走到底（`hhsj`
  那轮明确说超出首次验收范围没有走完）。

## 深度功能测试新发现的 bug（详见 NOTES.md）

`d/newbie/npc/laocunzhang.lpc`（投胎后进入新手村会遇到的"老村长"
NPC）编译失败，`query("id", me)` 把物件当成整数传给了
`query(prop, raw)` 的第二个参数（这份代码库里 `query()` 统一是
"属性名+是否原始值"两个参数，不是"属性名+目标物件"）——已改成
`me->query("id")`。这一处修复是完成整条投胎流程的关键拦路石。**同
一种写法在全库另外 161 个档案里也有出现**（`grep -rlP
'query\("[a-zA-Z_/]+",\s*(me|ob|user|this_player\(\)|this_object\(\))\)'`
命中 162 个档案），规模明显超出单次深挖会话，只修了这一处实测拦
路的，其余留给未来专门的系统性排查（新增 AGENTS.md §7.70）。

## 在线试玩

https://mudlibs.fluffos.info/wxddym/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 系统管理员
- **权限 / level**: `(admin)` —— 通过 `/adm/etc/wizlist` 授予，
  `SECURITY_D->get_status()` 据此判定。
- 登录时请使用上述"注册协议"格式（`fluffos║Mud@2026║x║x@example.com`），
  而非直接输入 id。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/wxddym
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40189**。
