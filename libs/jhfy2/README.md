# 江湖风云2 (jhfy2)

游戏内标题为"江湖风云II 之 辽宁风云再起"，金庸题材 mudlib。

## 注册流程

英文名字（3-10 个英文字母）→ 确认建立新角色（y/n）→ 中文名字（可
留空让系统自动跳过取中文名，本次用真实中文姓名验证通过）→ 密码
（至少 5 位）→ 确认密码 → 天赋数值（六项属性，其中福缘、容貌为隐
藏属性；输入 0 交由系统随机产生，随后需再输入 y 确认这组数值）→
电子邮件地址 → 性别（m/f）→ 进入游戏世界。

## 本次修复的关键 bug

没有发现任何需要修改的 mudlib 代码——`MASTER_OB`/`SIMUL_EFUN_OB`
宏本来就和 `config.fluffos` 一致，`is_chinese()`/
`check_legal_name()` 本来就是正确的 Unicode 码点判断，指令表
（`commandd.lpc`）开箱即用，也没有发现 `this_player()`/
`previous_object()` 顶替 root 身份一类的 ACL 问题。完整的注册→
`look`→`score`→`quit` 流程第一次真实连线测试就顺利通过。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `loginpass1`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist`（CRLF 换行）里；账号
本身通过正常注册流程创建，已在游戏内确认 "★ 您目前权限：(admin)"
显示正确。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/jhfy2
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40137**。
