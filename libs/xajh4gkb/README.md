# 笑傲江湖4公开版 (xajh4gkb)

游戏内品牌为「夕阳再现」之「笑傲江湖Ⅳ」，作者阿飞在"炎龙"内核基础
上修改的第四代版本。这份档案在 WASM 下**完全无需修复**——没有编
译错误，没有执行时段错误，整个注册流程一次跑通。

## 本次处理内容

没有发现需要修复的程序 bug。唯一做的事情是在 `/adm/etc/wizlist`
里加入管理员账号（已有 `afei`/`tianya` 两个 `(boss)` 级创始人账
号；权限阶梯最高是 `(ceo)` > `(boss)` > `(admin)`，但 `(admin)` 已
经足够获得 `/` 的完整写入权限，和本轮其他档案的惯例一致；
`SECURITY_D` 正确指向 `/adm/daemons/securityd`，`globals.h` 里有一
条注释掉的 `securd` 分身档案备用行，未启用）。

注册流程比较特别：除了普通密码之外，还要单独设置一个"身份标识"
（自杀、找回密码时使用，不可修改）。游戏内会夹杂一些
`lbadd0`/`lbclear0` 之类的自定义地图协议标记，这是给专属客户端用
的标记，不是错误。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **身份标识**: 注册时自设（不可修改，请妥善保管）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  后横幅显示"★ 您目前的权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/xajh4gkb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40154**。
