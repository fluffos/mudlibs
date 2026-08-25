# IMUD@FluffOS.v2019

FluffOS 项目自己的官方演示（源码：<https://github.com/fluffos/imud>，线上
地址 <https://imud.fluffos.info>）。**这不是一款游戏**——没有角色注册、
没有存档、没有房间地图，只是一个从零开始的最小 FluffOS mudlib 范例，
用来演示驱动自带的 Intermud-3（跨 MUD 聊天/名录协议）支持。

## 内容说明

- 连接后**没有登录/注册流程**：直接把你放进一个匿名会话对象
  （`secure/user.c`），欢迎语之后立刻可用。
- 只支持两个命令：
  - `mudlist` —— 通过真实的 socket 连接到公网上的 Intermud-3 路由器
    （`*i4`, `204.209.44.3:8080`），列出当前在线的、真实存在的其他 MUD。
    这是本演示唯一有实际内容的功能，连接成功后能看到几十个当前挂在
    I3 网络上的真实 MUD（FluffOS/LDMud/CoffeeMud/DGD 等各种驱动）。
  - `update <path>` —— 重新编译/加载指定路径的对象，供演示者热更新代码，
    没有任何权限校验（谁连上来都能用）。
- 仓库里还带了一份基于 xterm.js 的网页客户端（`secure/www/`）和一个
  websocket 监听端口配置，用于给 imud.fluffos.info 网站提供浏览器直连——
  本仓库只用原生 telnet 端口测试，未启用 websocket 监听（详见
  `config.fluffos`）。
- 没有中文内容——这是英文原版驱动作者的演示项目，收录进本项目是作为
  "一个极简 FluffOS mudlib 长什么样" 的参照样本，而非武侠游戏。

## 重要：会连上真实的公网 Intermud-3 网络

启动这个 lib 会让 `secure/imud/imud.c` 立即向真实的、目前仍在运行的
Intermud-3 路由器发起出站连接并完成握手——这不是沙盒模拟，是真实的
公网连接，会让本机的公网 IP 短暂出现在真实 I3 网络的 mudlist 里
（显示名固定为 `IMUD@FluffOS.v2019`）。这是原始演示本来就有的行为，
不是本项目引入的 bug，但和语料库里其它所有 lib（纯本地沙盒）不同，
**在自动化重复开机测试脚本里对这个 lib 要格外小心**——反复重启会反复
向真实第三方服务器发起连接。详见 `NOTES.md`。

## 在线试玩

本地测试端口如下（原始 config.txt 的 websocket 7878 未启用）。

## 管理员账号 / Admin account

不适用——这个 lib 没有账号系统，没有登录/注册流程，也没有
`wizardp()`/ACL 之类的权限分级机制。所有连接者拿到的是同一个匿名会话、
同样的两个命令（含没有任何权限校验的 `update`），因此不存在需要额外
播种的"管理员账号"。详见 `NOTES.md` 的 §2.2/§1.5 检查结论。

## 本地运行

```
cd libs/imud
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40209**。
