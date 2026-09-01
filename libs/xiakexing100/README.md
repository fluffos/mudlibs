# 侠客行一百 (Xia Ke Xing - Yi Bai)

取材自金庸小说《侠客行》，作者 "Coollizard" 与 "xkx100" 团队自 2001 年起维护，属于本项目"Century 家族"（`adm/single/` 目录结构）武侠 mudlib 分支之一，是这批游戏中文件数量最多的一个（转换后约 1.2 万个 LPC 文件），经比对代码库与本项目另两款同名"侠客行"游戏 xiakexing2017、xiakexing3（二者彼此是关系密切的近亲）截然独立；游戏世界以北京、长安、洛阳、扬州等真实历史地名为骨架，覆盖全国多个"出生地"，新角色从随机分配的出生城市客栈起步，创建时可选择冒险、谨慎、可人、睿智、坚韧五种性格类型，影响初期属性倾向；可通过寺前武僧一类 NPC 拜入少林门下，在木人桩前安全习武过招；此外还有一套与现实时间并行显示的独立"侠客行历法"。

## 内容亮点

- 游戏世界以北京、长安、洛阳、扬州等真实历史地名为骨架，覆盖全国多个
  "出生地"供玩家选择。
- 少林寺设有木人陪练（`d/shaolin/obj/mu-ren.lpc`）。

## 在线试玩

https://mudlibs.fluffos.info/xiakexing100/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)` —— 本 lib 的最高等级，通过
  `adm/etc/wizlist` 授予。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xiakexing100
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40037**。这是本批游戏中体积最大的一个，启动后请稍等片刻
再连接。
