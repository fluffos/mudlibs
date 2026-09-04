# Lima

FluffOS 驱动项目自己维护的官方参考 mudlib（源码： <https://github.com/fluffos/lima>，官网 <https://limalib.dev>）。这不是一款武侠/仙侠游戏——和本项目收录的其它中文 mudlib 不是同一个宗谱，是一个独立的、英文的、面向开发者的现代 LPC 框架，收录进本项目是作为 "当代 FluffOS mudlib 长什么样"的参照样本。

## 架构说明

Lima 在几乎每个层面都和本项目里的经典 LPMud 系 mudlib 不同：

- **集中式自然语言命令解析**，而不是逐个动词 `add_action` 注册——能
  理解 `take the red potion from the box` 这样的完整英语句子。
- **能力（capability）式安全系统**（`secure/daemons/secure_d.lpc`），
  基于 `privileges`/`domains`/`protections` 而不是传统的 uid/root 模型。
- **巫师用的是类 Unix shell**（`? for shell help>` 提示符），支持
  变量、管道、globbing，而不是一张固定的巫师指令表。
- **`AUTO_WIZ` 默认开启**——任何新建角色都会立即获得巫师权限，这是
  上游仓库自己的默认设置（Lima 本来就是给开发者当框架/演示用的），
  不是本项目引入的开局漏洞。

详见 `NOTES.md`，里面有完整的转换记录、发现并修复的驱动兼容性 bug、
以及为什么这个 lib 需要一个专门编译的驱动。

## 特殊要求：需要专用驱动

这个 lib **不能**用本项目其它 ~240 个 lib 共用的默认驱动
（`~/src/fluffos/build-debug`）启动——Lima 自带的
`secure/check_config.c` 会在启动时检查驱动是否按它要求的编译期开关
（`NO_LIGHT`/`NO_ADD_ACTION`/`NO_WIZARDS` 已定义，`OLD_ED`/
`PACKAGE_UIDS` 未定义）编译，不满足就直接报错中止，而本项目的共享
驱动是按相反的开关编译的（其余所有 lib 都需要那一套）。

已经在 `~/src/fluffos-lima`（`~/src/fluffos` 的一个独立 `git worktree`，
同一份源码不同的编译配置）按 Lima 的要求单独编译出了一份驱动，运行
时要用：

```
cd libs/lima
~/src/fluffos-lima/build-debug/src/driver config.fluffos
```

（如果 `~/src/fluffos-lima` 不存在，`NOTES.md` 里有完整的重建步骤，
一次性编译大约 5-10 分钟。）

游戏端口：**40212**。原生（native）驱动已验证。站点现在按 lib 覆盖
WASM 驱动（`scripts/custom_drivers/lima_swmud/`，与 `swmud` 共用），
浏览器试玩已走通注册→选种族→进入 Grand Hall，`wasm_status` 为
**playable**。详见 `NOTES.md`「站点基础设施缺口已补上」。

## 本地运行

```
cd libs/lima
~/src/fluffos-lima/build-debug/src/driver config.fluffos
```

连接后按提示注册（英文 id + 密码 + 性别/邮箱/真实姓名等基本信息），
在用户菜单里用 `c` 创建角色、选择种族，`s` 选中、`p` 进入游戏。核心
指令：`look`、`score`（状态面板）、`inventory`、`who`、`quit`。

## 管理员账号 / Admin account

- **id**: `fluffos`  **密码 / password**: `Mud@2026`
- **权限 / level**: `Admin`（`SECURE_D` 的 `domains["admin"]` 领域领主，
  外加 `wizards` 表里的巫师身份）——通过直接编辑
  `data/secure/access.o`（Lima 自己的能力式安全存档文件）播种，因为
  这套安全模型的正常自举方式是"全新安装后第一个创建角色的真人自动
  成为 admin"，本项目用固定账号覆盖了这个时序依赖。
- 由于 `AUTO_WIZ` 默认开启，**其实任何新注册的角色都会自动拿到巫师
  权限**——`fluffos` 这个种子账号额外拿到的是更高一级的 `Admin`
  （领域领主）身份，能使用 `admtool`（管理菜单）等更高权限功能。
- 播种细节、验证过程见 `NOTES.md`「管理员账号播种」一节。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。
