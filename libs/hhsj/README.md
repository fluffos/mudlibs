# 洪荒世界

源自 2026-07-29 批量归档 `mudlib.rar` 中的 `洪荒世界(自连数据库)`。与
`nitan170911`（仙剑奇侠传）、`nitan6`（笑傲江湖）同源的 NT/nitan/Lonely
引擎家族成员，这次以《封神演义》/盘古开天为背景重新设计。

## 内容亮点

- 开局即是盘古开天地的创世场景，需要在"生命之谷"面见盘古，选择角色
  性格与种族，再经由阎罗殿"投胎"完成真正的降生仪式——比这批归档
  里大多数泥潭更有仪式感的新手引导。
- 采用自带客户端协议（"自连数据库"即"自行连接数据库"之意），登录
  握手会显示版本校验信息；用普通 telnet 客户端也能玩，只是账号注册
  需要单行输入"账号,密码,密文,email"格式。
- 投胎仪式完整指令顺序：`zz <编号>`（选种族）→ `xuan 1`-`2`（选性
  别）→ `choose 1`-`4`（选性格）→ `washto 数字 数字 数字 数字`（按
  膂力/悟性/根骨/身法分配 80 点属性，每项 13-30——跟同血统的 xfbhh
  数值区间不同，是设计差异不是 bug）。
- 深度测试修复了与 xfbhh 同源的 CHARACTER mixin 裸 `set()`/`query()`
  解析失败问题（AGENTS.md §7.78 的第二个确认实例），以及一个此前被
  错误归因为"只影响巫师账号"、实际影响每个新角色的 `enter_world()`
  崩溃（`efun::message()` 拒绝字面 `exclude=0`）。详见 NOTES.md。

## 在线试玩

https://mudlibs.fluffos.info/honghuangshijie/

## WASM pass修复的 bug

`adm/daemons/named.lpc`（记录所有玩家名字的精灵）的 `create()` 直接调
用未加保护的 `restore()`，而它自己保存的档案（约 168KB）里有一处非法
的 mapping 格式，导致 `restore()` 抛出未捕获的异常。这个驱动的实现下，
`create()` 抛出异常会让这个物件永远无法真正加载成功，而后续代码里对
它的隐式呼叫（`NAME_D->invalid_new_name(...)`）在物件未加载成功时会
静默地什么都不做——不报错、不重试、直接卡住。而这个函数正好是每次新
角色建立时 `get_char()` 必经的一步，于是每一次新建角色都会在这里默默
卡死，`enter_world()` 永远不会被呼叫，导致此后所有指令（包括
`look`/`score`/巫师的 `update` 等）全部落到驱动通用的失败提示"什么？"
——此前的原生模式测试遇到的正是这个问题，当时被误判为"巫师指令的搜
索路径问题"（见 NOTES.md），实际上是这个更底层、与 WASM 无关的真实
bug。已按 AGENTS.md §7.41 的标准做法修复：`create()` 里把 `restore()`
包一层 `catch()`。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(boss)`，通过 `/adm/etc/wizlist` 授予——这份档案
  的 `wiz_levels` 把 `(boss)` 排在 `(admin)` 之上作为真正的最高权限，
  且 `securityd.lpc` 的 `trusted_read`/`trusted_write["/"]` 都包含
  `(boss)`。已验证 `update` 指令可正常执行。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/hhsj
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40106**。
