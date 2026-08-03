# 小雨西游utf8 (xyxyutf8)

《小雨西游》/《小雨西游Ⅱ》引擎的另一份独立压缩包，档案名带
"utf8" 暗示已经预先转成 UTF-8。和本项目已有的 003
`unknownlib20150716`（20150716未知lib）、003-1 `xiaoyuxiyou`（小雨
西游）同属一个引擎家族，但经过内容哈希比对**不是**字节级重复
（8753 对 11149 个 `.lpc` 档案，是不同时间点的快照，不只是重新编
码而已），所以独立完整处理。

## 本次修复的关键 bug

这两个 bug 都是"环境限制/残留内容问题"，不是 mudlib 逻辑本身的
错：

1. **`uptime()` 开机保护闸门**（AGENTS.md §1.3(e) 的既定处理方
   针）：`logon()` 里 `if(uptime() < 30) { ...拒绝连线... }` 会在
   驱动刚开机的 30 秒内拒绝所有连线；这个引擎家族（`xiaoyuxiyou`、
   `unknownlib20150716`）在 AGENTS.md 里被明确点名为"已知受影响"，
   但两个姊妹档案似乎都还没有真的被修掉（至今都还标记 `limited`）。
   按标准处理方式，改成只对非 loopback 连线生效：
   `query_ip_number(ob) != "127.0.0.1" && uptime() < 30`。
2. **`encoding()` 呼叫驱动原生 `set_encoding("GBK")`/
   `set_encoding("big5")` 在 WASM 下失败**：报"Fail to set encoding
   to 'GBK', error: U_FILE_ACCESS_ERROR"——WASM 驱动内建的 ICU 数据
   包没有 GBK 转码器。既然这份档案本身就是预先转好的 UTF-8 版本，
   这个转码呼叫其实已经没有实际作用了；用 `catch()` 包起来（没有
   直接删掉，以防其他地方的 `query_encoding()` 依赖这个物件"曾经
   尝试设定过"这件事）。

另外，GB/BIG5 选择完之后会多一个"请您做出选择：① 进入游戏(Enter)
② 立即退出(Exit)"的提示，这一步在同宗的其他档案里不一定存在，纯粹
是这份快照自己的流程差异，不是 bug。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设（账号密码 + 管理密码双密码机
  制，两者不能相同）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/notices` 授予（这个
  引擎家族的 `WIZLIST` 宏指向 `notices` 而不是常见的 `wizlist`），
  登录后自动显示"目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

`gb` → 回车（进入游戏，跳过退出选项）→ `new` → 英文 ID → 中文名字
→ 管理密码 + 确认 → 登陆密码 + 确认 → 电子邮件 → 性别（m/f）→
天赋点数菜单（`9` 接受默认值，`y` 二次确认）→ 进入游戏。

## 本地运行

```
cd libs/xyxyutf8
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40168**。
