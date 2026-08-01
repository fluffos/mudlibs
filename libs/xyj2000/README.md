# 西游记2000 (xyj2000)

西游记（"Journey to the West"，又名"西游记之新纪元"），以吴承恩原
著为背景的一套老牌 MudOS mudlib，注册流程带有"不欢迎中小学生玩家"
的年龄声明问答，属于原始设计的一部分，不是 bug。

## 本次修复的关键 bug

1. **`adm/daemons/convertd.lpc` 的字节级损坏**：GB/BIG5 转码用的
   `inittable` 初始数组，本应是每个元素一个符号的字符串数组，实际
   存档内容里大量元素被压成了一整行、符号之间互相粘连（和这批档案
   里 `sjsh` 系列同款的转档损坏），已用标准修复脚本按码位重新切
   分（约 45 行受影响）。
2. **`adm/daemons/network/dns_master.lpc` 的 §7.52 socket 依赖**：
   这是一个真正的多用途互联互通精灵（`query_mud_name()`/`muds`
   mapping 等被 `mudlist_a`/`mudlist_q`/`gtell`/`gchannel`/`rwho`
   等约 28 个其他服务文件呼叫），按 AGENTS.md §7.52 对多用途精灵的
   例外处理，**没有**整个文件停用：只把两个真正碰 socket 的入口函
   式掏空（`startup_udp()` 现在直接 `return 0`，正好符合它原本失败
   时的返回惯例，`create()` 里 `if (startup_udp())
   init_database();` 不需要改动就会自然跳过依赖 socket 的资料库初
   始化；`send_udp()` 变成空函式），并清掉了 `send_shutdown()` 里一
   处残留的 `socket_close()` 呼叫。
3. **由上一条引出的连锁 bug——`adm/etc/preload` 里 `dns_master` 被
   注释掉了**：这份档案的 `preload` 文件里 `#/adm/daemons/
   network/dns_master` 这一行被人为注释掉（原始压缩包里是启用状态；
   多半是有人在 socket 兼容性 bug 修好之前，为了让整个 mudlib 能开
   机而临时关掉的权宜之计），导致 `DNS_MASTER` 精灵永远不会在开机
   时被预加载。`adm/daemons/logind.lpc` 的 `encoding()` 在选完编码
   后第一次连线会检查 `if(!find_object(DNS_MASTER) || ...)
   shutdown(1);`——`find_object()` 只对已加载的对象返回真，精灵没
   被预加载所以这个检查恒真，**每一次连线都会在选完编码后立刻触发
   `shutdown(1)`**，导致注册流程在编码选择之后彻底卡死（所有后续
   输入都显示"什么？"）。这不是编码选择本身的 bug，是 `shutdown(1)`
   调用之后连线对象再也没有注册任何 `input_to()`，所以后续输入落
   进了没有挂钩的通用解析器。既然 §7.52 的编译修复已经让
   `dns_master.lpc` 能正常载入，把 `preload` 里那一行重新启用即可，
   不需要改动 `logind.lpc` 本身的检查逻辑。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（
  `adm/daemons/securityd.lpc` 真的会在开机时读取 `WIZLIST`），登录
  后自动显示"目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

编码选择（`gb`/`big5`）之后会先问"您是否是中小学学生或年龄更小？
(yes/no)"，答 `no` 才能继续到英文 ID 提示；新玩家在英文 ID 提示处
键入 `new` 才会进入取中文名字/设密码/设 email/选性别的完整创角流
程；创角最后一步是天赋点数分配菜单，键入 `9` 接受默认值后还会有一
次 `[y/n]` 二次确认。

## 本地运行

```
cd libs/xyj2000
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40155**。
