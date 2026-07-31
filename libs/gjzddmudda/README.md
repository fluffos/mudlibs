# 国家制度的MUD DA

一个 ES2 血统的 MUD（作者自己在横幅中致谢 Annihilator/ES2），游戏内
标题为"葫芦Ⅱ / Demon Angel"（泥潭中国简化版本）。

## 注册流程

英文名字（3-12 个英文字母）→ 确认建立（y/n）→ 中文名字（1-6 个中
文字）→ 密码（≥5 字元）→ 确认密码 → 电子邮件地址 → 性别（m/f）。

## 本次修复的关键 bug

没有发现任何需要修改的 mudlib 代码——在 WASM 下开箱即用。这个档案
的 `is_chinese()`/`check_legal_name()` 本来就是正确的 Unicode 码点
判断，不像本次处理的其他大部分 ES2 血统档案那样有旧版 GBK 字节假
设的问题。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里；账号本身通过正常
注册流程创建。这个版本的 `logind.lpc` 把"目前权限："+ wizhood() 的
状态显示行注释掉了（死代码），所以游戏画面上看不到明确的权限提
示——但 `adm/etc/wizlist` 的格式已经对照 `securityd.lpc` 的解析逻辑
核实过，和本次处理的其他所有 ES2 血统档案完全一致。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/gjzddmudda
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40122**。
