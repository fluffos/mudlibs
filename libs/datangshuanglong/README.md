# 大唐双龙 (DaTangShuangLong)

与 dtsl(大唐双龙传)、llmud_datangshuanglong 同属"大唐双龙"世界观分支,
但代码实现各自独立(共享部分基础道具内容与中文姓名校验逻辑)。

## 简介

「大唐双龙」同样取材自黄易的武侠小说,以大唐初年天下大乱的江湖为背
景。新角色从"大唐学院"起步,可通过 `down` 直接开始江湖生涯,或先
`enter` 进入学院详细了解游戏系统。整体设计偏向系统化、数值化的养成
玩法。

## 如何运行

```
cd libs/datangshuanglong
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口:**40043**。

## 如何连接游玩

```
python3 scripts/mudclient.py 127.0.0.1 40043
```

注册流程(无隐藏前置问题):
1. 英文 ID(3-8 个英文字母)
2. 确认创建新角色(y/n)
3. 中文姓名(请避开寇仲、徐子陵等小说主角姓名,系统会拒绝)
4. 密码
5. 确认密码
6. 电子邮件地址
7. 选择性别(m/f)
8. 分配四项天赋点数(格式如 `20 20 20 20`,总和须为 80,每项 10-30)
9. 确认分配(yes/no)

完成后进入"大唐学院",`look`/`score` 等指令均可正常使用。注意:游戏会
提示新建账号需要连续在线超过一小时才会自动存档,退出时会询问"是否保留
这个账号",属于正常提示,直接回答 y/n 即可。

## 已知问题

- 少数支线任务房间(`job` 相关的部分房间)缺少共用房间模板,只影响个
  别支线,不影响主线注册与基础游玩。
- 个别武器道具(`club`/`WEAPON_COMBO` 相关)因原始 archive 内容缺口而
  暂不可用。
- 本游戏已确认可在 WASM/浏览器模式下完整游玩(注册、登陆、基础指令均
  正常),不受底层驱动 IP 检测限制影响。

## 管理员账号 / Admin account

- **ID**：`fluffos`
- **密码 / Password**：`Mud@2026`
- **中文名 / Display name**：浮浮
- **权限 / Level**：`(admin)`（`adm/etc/wizlist` 最高等级）——已验证
  `update` 巫师指令可用（登录后显示"目前权限：(admin)"）。
- 授权方式：`adm/etc/wizlist` 加入 `fluffos (admin)` 一行（保留原有
  `hpdxxd` 条目），重启后 `securityd.lpc` 的 `create()` 读入生效。
- 存档文件：`work/data/user/f/fluffos.o`、`work/data/login/f/fluffos.o`
  （未被 gitignore，普通 `git add libs/datangshuanglong/` 即可纳入）。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，
> 请先修改此密码。
