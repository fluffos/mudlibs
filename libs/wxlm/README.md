# 武侠黎明 (Martial Arts Dawn / Wuxia Liming)

基于炎黄 / 地狱（指文游之终极地狱）一系持续演进的中文武侠 MUD，新人自扬州「醉仙客栈」起步，可在扬州、北京、成都、关外四处出生地之间择一入世，并在门口江湖大使的新手指引下逐步开启江湖历程。世界涵盖少林寺、武当派、丐帮、全真教、华山派、古墓派、桃花岛、日月神教、移花宫等二十五个武林门派，配套门派声望、五绝、首席弟子、天机阁、帮派庄园与占领、大逃杀、金兵入侵、魔窟与常规副本、自创武学、装备词条、宝石回收及科举等丰富玩法。

## 内容亮点

- 门派与江湖体系：内置 25 个门派及声望、仇恨、五绝、首席弟子与天机阁榜单（`adm/daemons/familyd.lpc`），支持多门派历练与门客/自创武学玩法（`adm/special_ob/create_skill/`、`menke/`）。
- 城池与副本探索：除传统金庸武侠江湖城池与门派驻地外，还包含新手试炼（`d/newbie/`）、帮派农田与种植（`d/bangpai/`）、各类单人/多人副本（`d/fuben/`、`d/new_fuben/`、`d/fuben_moku/`）及大逃杀玩法（`adm/special_ob/dadaosha/`）。
- 养成与活动系统：具备装备词条洗练（`citiao_master.lpc`）、宝石回收（`system/baoshi_huishou.lpc`）、真意系统（`system/wusheng/`）、科举考试（`adm/special_ob/keju/`）、金兵入侵、守卫襄阳、春节/端午/疯狂星期三等定时江湖事件。
- 交互方式：原生支持客户端 JSON 结构化状态与指令提示，同时兼容传统 telnet / 网页端命令行交互登录与创建角色。

## 在线试玩

https://mudlibs.fluffos.info/wxlm/

## 管理员账号 / Admin account

- **ID**：`fluffos`
- **密码 / Password**：`Mud@2026`
- **中文名 / Display name**：柳随风
- **权限 / Level**：`(admin)`（`adm/etc/wizlist` 中授予的最高等级）

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，请先修改此密码。

## 本地运行

```
cd libs/wxlm
~/src/fluffos/build-debug/src/driver config.fluffos
```
