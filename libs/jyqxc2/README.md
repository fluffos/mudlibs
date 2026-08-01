# 金庸群侠传 (jyqxc2)

[jyqxc](../jyqxc/) 的姊妹版本，同一套架构衍生的另一份存档（编号
086/087），大部分文件内容不同，但整体结构和 bug 面几乎一致。

## 注册流程

英文名字（3-12 个英文字母）→ 确认建立新角色（y/n）→ 中文名字（1-6
个中文字）→ 密码（至少 5 位）→ 确认密码 → 系统自动产生一组天赋数
值（膂力、悟性、根骨、身法），直接询问是否接受（y/n，不接受会重新
产生一组）→ 电子邮件地址 → 性别（m/f）→ 进入游戏世界。

## 本次修复的关键 bug

和 [jyqxc](../jyqxc/) 完全相同的 bug：`feature/name.lpc` 的
`short()` 在没有设定 `"short"` 属性时会用
`capitalize(query("id"))` 拼出预设显示名称，但没检查
`query("id")` 是否为字符串。这个 lib 里约 18 个留言板（clone 自
`inherit/misc/bboard.lpc`）的存档文件 `data/board/*.o` 用的是同一
种旧式紧凑二进制存档格式（`#inh`/`?inh` 魔术字节），本驱动的
`restore_object()` 无法解析，抛出例外前会把该物件的整个 dbase 属
性表清空（包括刚设定好的 `"id"`），于是只要房间里摆了留言板，一
进房间 `look` 就会崩溃。修法同 jyqxc：让 `short()` 在 `id` 不是字
符串时优雅降级。

没有发现 Chinese 姓名判断、宏定义或指令表相关的 bug。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud2026Adm`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist`（LF 换行，与档案里原
有条目格式一致）里；账号本身通过正常注册流程创建，已在游戏内确认
"目前权限：(admin)" 显示正确。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/jyqxc2
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40172**。
