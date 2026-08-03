# 夕阳再现-炎龙20141231 (xyzxyl201412)

《夕阳再现》家族里改动更大的一个后期版本：自定义巫师阶层一路到
`(boss)`/`(ceo)`，天赋分配之后多了一步十一系魔法天赋选择，还支持
多端口（ZMud/ToMud）连接。

## 本次修复的关键 bug

这份档案发现并修复了 4 个真正会让编译失败的 bug（这次会话里其他
`夕阳再现` 家族档案都没遇到过）：

1. **`adm/daemons/network/dns_master.lpc` 真的还有没被掏空的
   socket 呼叫**（`socket_create()`/`socket_bind()` 等），而且这
   份档案的 `logind.lpc` 会在 `logon()` 里直接呼叫
   `DNS_MASTER->query_doing_end()`（不只是 `preload` 里预加载，是
   运行时真的会呼叫），确认有 29 个外部呼叫者（符合 AGENTS.md
   §7.52 对多用途精灵的例外情形），所以只掏空了两个真正碰 socket
   的入口函式（`startup_udp()`/`send_udp()`），加上
   `send_shutdown()` 里一处残留的 `socket_close()`，没有整个文件
   停用。
2. **`adm/daemons/network/server_2000.lpc`**，一个完全独立的
   socket 文件传输服务器（TCP 监听/接受/连接，约 15 处 socket 呼
   叫），只有一个呼叫者（巫师专用指令 `cmds/bos/send_file3.lpc`）
   ——直接在 `adm/etc/preload` 里把它注释掉整个停用，文件本身没有
   改动。
3. **`adm/daemons/teamd.lpc` 呼叫了一个完全没有定义过的函式**
   `count(count(v,"*",lvl),"/",max_lvl)`（大概原意是想用字串运算
   符调度的方式算 `v*lvl/max_lvl`，但这个 `count()` 辅助函式从来没
   有在这个 mudlib 的任何地方被真正定义过）——这是一个原生环境下也
   会编译失败的真实 bug，不是 WASM 专属问题，改成直接算术运算
   `v * lvl / max_lvl`。
4. **标准 §8.1 `check_legal_name()` 的 `i%2` 奇偶校验/`[i..<0]`
   后缀切片写法**（`is_chinese()` 本身已经是正确的逐码点写法）——
   改成逐码点的 `name[i..i]`；`master.lpc` 的
   `valid_read()`/`valid_write()` 也补上了标准的
   `user == this_object()` 短路判断。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`（这份档案的阶层一路到 `(boss)`/
  `(ceo)`，为了和项目里其他档案保持一致，统一用 `(admin)` 这一
  级），通过 `/adm/etc/wizlist` 授予，登录后自动显示"★ 您目前的权
  限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

英文 ID → `y`（确认创建新角色）→ 中文名字 → 管理密码 + 确认 → 登
陆密码 + 确认 → 天赋菜单（`0` 随机整组，`y` 接受）→ 魔法天赋选择
（`0-10`，任选一个数字，例如 `0`）→ 电子邮件 → 性别（m/f）→ 进入
游戏。

## 本地运行

```
cd libs/xyzxyl201412
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40175**。
