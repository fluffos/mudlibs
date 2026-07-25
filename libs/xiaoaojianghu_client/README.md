# 笑傲江湖之重出江湖

作者 AKAI，脱胎自"夕阳再现－江湖风云2－风云再起"引擎（属于"夕阳再现
/XYZX"系列衍生分支，与本项目收录的多部同系列作品——如《侠客风云》
《西阳再现疯狂版》等——师出同门，但游戏内容各自独立开发）。archive
名称中的"服务端+客户端"其实指的是同一套游戏支持两种连线协议（普通
telnet 客户端 和 TOMUD 菜单客户端），并不是额外附带了一个独立的客户端
程序。

## 内容亮点

- 经典金庸《笑傲江湖》题材江湖世界：从南大街的客店起步，从"武庙"
  "铁枪庙"等地展开门派与个人历练。
- 设有膂力、悟性、根骨、身法、福缘、容貌六项天赋（后两项为隐藏属性，
  影响解谜与NPC印象），整体是偏正统武侠养成向的体验。
- 连线时有一道隐藏的"客户端版本号"校验（必须先输入 `2060`），是这款
  游戏自己的连线协议识别机制。
- 比较特殊：设有"普通密码"和"管理密码"两套独立密码。
- 修复过一处历史遗留 bug：原始存档的 `include/command.h` 把巫师指令
  搜索路径定义为空数组，导致任何被提升为巫师权限的账号连 `look`/`quit`
  等最基本指令都会失效；现已指向与普通玩家相同的指令目录。

## 在线试玩

https://mudlibs.fluffos.info/xiaoaojianghu_client/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **管理密码 / Management PIN**: `FluffMgmt1` —— 本 lib 特有的第二套密码
  （"wizpwd"），与巫师权限无关，只是一个自助改密 PIN。
- **显示名 / Display name**: 浮浮
- **权限 / Level**: `(admin)` —— 本 lib `securityd` wiz_levels 中的最高级，
  通过 `adm/etc/wizlist` 授予（`fluffos (admin)`）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此默认密码（以及管理密码 PIN）。

## 本地运行

```
cd libs/xiaoaojianghu_client
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40070**。
