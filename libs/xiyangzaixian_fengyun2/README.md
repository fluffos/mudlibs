# 夕阳再现·风云再起Ⅱ

站点子名"风云再起Ⅱ"（域名 www.zhaoshu.net）。与本项目中的
`xiyangzaixian_fengkuang`（疯狂江湖）同属"夕阳再现"这一支武侠 MUD 引擎
家族——两者共享部分底层文件，但登录、安全、世界内容各自独立开发，是
两个不同站点在同一基础引擎上分别发展出的游戏。

## 内容亮点

- 传统金庸武侠题材：玩家从平民少年少女出发，游历江湖各地城镇，结交
  门派、习练武功、行侠仗义，游戏公开声明不禁止玩家间的 PK 对战。
- 新手出生地点会在多个不同的江湖城镇/据点中随机分配（如北疆小镇、
  铁枪庙等）。
- 注册流程比较特殊：要求同时设置"管理密码"和"登录密码"两套独立密码。
- uptime 启动保护关卡与连线封禁检查现在对本地/回环地址（含 WASM 浏览器
  连线）直接放行，不会再被拒绝连线。

## 在线试玩

https://mudlibs.fluffos.info/xiyangzaixian_fengyun2/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **登录密码 / login password**: `Mud@2026`
- **管理密码 / secondary admin password**: `Adm@2026`
  —— 本 lib 的注册流程强制要求另设一个与普通密码不同的"管理密码"。
  日常登录只需普通密码 `Mud@2026`。
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 本 lib 最高权限（通过 `adm/etc/wizlist`
  授予），可使用 `update`、`goto` 等全部巫师指令。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改以上两个密码。

## 本地运行

```
cd libs/xiyangzaixian_fengyun2
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40041**。服务器刚启动的前 30 秒内会拒绝远程登录，本地/
回环地址不受此限制。
