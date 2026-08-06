
## WASM 修复摘要（迁移自 meta.json 的 group_note）

完成了一次中断的转档（多个档案，包括 master.lpc，残留有 static 关键字）；用 read_file+explode+slice 重新实现了 efun::tail()（§6.2）；启动干净。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc（create()/make_body()/howmany_user() 都改成 seteuid(ROOT_UID)）里同样的 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限，去掉了一个毫无意义的 name[j]+=128 变异操作（旧版 GBK 高位字节假设的遗留代码）；给 adm/daemons/securityd.lpc 的 get_status() 加上了防止 wiz_status/wiz_levels 尚未初始化时重入编译崩溃的保护。发现了两个新 bug：cmds/usr/quit.lpc 呼叫 environment(me)->query(...) 没做保护，玩家在环境为空时退出游戏就会崩溃报"*Bad argument 1 to call_other()"（已给全部三处呼叫点加上保护）；adm/simul_efun/message.lpc 的 tell_room(ob,str,exclude) 包装函式把省略的可变参数 exclude 直接以裸整数 0 传给 message() 的第 4 个参数，而不是空数组——导致游戏里第一次 tell_room() 呼叫（欢迎室自己的 create()）就崩溃，这是已收录进 AGENTS.md §7.12 的共享包装函式 bug，已用文档记载的 exclude || ({}) 写法修复。管理员账号播种进了 data/securityd.o 的 wiz_status 映射（这里是 CRLF 配对编码，不是 hy/hy5 那条血统里的纯 CR 逐键编码——出于保险仍用二进制模式编辑）。注册流程到进入游戏世界、look/score/quit、管理员权限识别都干净验证过，没有残留的横幅计时问题。

## 深度功能测试（第二轮，2026-08-03）

此前的验证只做到"注册→look/score/quit→管理员权限识别"的浅层冒烟测
试。本轮在 boot 之前先主动检查了本次会话已经在 `hell`/`zsdsj` 上反
复确认过的两类高价值 bug 模式，直接在源码里发现并提前修复了一处，
随后完整走通了注册、门派加入、`quit` 全流程。

### 主动排查发现并修复：`feature/command.lpc` 的 `private command_hook`

`feature/command.lpc`（`inherit/char/char.lpc` 通过 `F_COMMAND` 继
承，是真正生效的玩家指令分发中枢）把 `command_hook` 声明为
`private nomask int command_hook(string arg)`。这是 AGENTS.md §8.3a
已经记录多次的经典模式：这个驱动上 `private` 一旦被继承就会降级为
`DECL_HIDDEN`，导致 `add_action("command_hook", "", 1)` 这种"捕获全
部指令"的注册方式对 `ORIGIN_EFUN`（其它物件透过 `command()` efun
发起的呼叫，比如 NPC 自己说话）静默失效。已去掉 `private`，保留
`nomask`，和已确立的标准修法一致。

另有一份 `feature/command2.lpc` 也带有完全相同的 `private nomask
command_hook` 声明，但确认它是死代码——全代码库里唯一提到
"command2" 的地方是 `log/static/editfile.lpc`（这不是真正的 LPC 源
码，是一份历史巫师编辑记录日志，纯文本"某巫师在某时间编辑了某文件"
的流水账，文件名后缀 `.lpc` 是历史遗留的误用），没有任何 `inherit`
真正引用 `feature/command2.lpc`——保持原样未做改动，符合"死代码备
份保持原样"的既有惯例。

### 完整验证：从注册到加入门派

用全新账号在原生驱动上完整走通：GB 编码（默认）→ 英文 id（3-8 个
英文字母，注意上限只有 8 个字符，比很多同类档案的 10-12 上限更
严）→ y 确认建立 → 中文名字（1-4 个汉字）→ 使用密码 + 确认 → **保
密密码**（至少 10 位，与使用密码是完全独立的第二套密码，专门用于
密码找回）+ 确认 → 天赋选择（0-4，0 为系统随机，随机结果需要 y/n
二次确认，不满意可以重新摇）→ 电子邮件 → 性别 → 进入"新手的殿堂"。

一进入新手殿堂就有 [1;33m金庸[37;0m（作者本人被拟人化成一个 NPC！）
主动搭话："欢迎光临本ＭＵＤ，本人现在将助你一臂之力"，并列出全部
12 个可加入的门派：丐帮、全真教、武当派、华山派、密宗、星宿派、
白驼山庄、桃花岛、少林派、峨眉派、大理段氏、灵鹫宫——同样是把金庸
小说宇宙里跨多部作品的门派体系（射雕/神雕的全真教丐帮、天龙八部的
星宿派大理段氏灵鹫宫白驼山庄、笑傲江湖的华山派、倚天屠龙记的少林
武当峨眉）揉进同一个游戏世界。`join wudang` 立即成功，触发一条全服
公共频道广播"在下承蒙金庸先生帮助，现已加入武当派！"，金庸 NPC 确
认"现在我已经给你帮助了"，"身体更新完毕"——这一整条 NPC 对话+全服
广播链路，正是 `command_hook` bug 最容易静默破坏的那一类
`command()`-efun 自呼叫路径，本轮完整验证无异常，间接印证了上面那
处修复的必要性。`score` 显示完整角色面板（膂力/悟性/根骨/身法四项
天赋、精/气/食物/饮水四条状态槽全部正确显示，饮水槽满格，没有类似
`zsdsj` 那种初始化缺失的问题）。`quit` 正常触发"开始退出游戏，进行
中..."流程。debug.log 除了驱动自身的启动期诊断信息（找不到旧版二
进制、反向地址解析被拒绝，均为环境噪音，不影响功能）外没有任何来自
本次实际游玩会话的运行时错误。

### 未覆盖范围（诚实说明）

预算集中在验证 `command_hook` 修复的必要性和门派加入这条最容易受
影响的 NPC 对话链路，没有走到：门派内部技能学习、战斗、经济系统。
这些留给下一轮，目前的验证边界如上所述。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 44 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
