# 碧血残阳 之「豪侠晚歌」

属于"夕阳再现"引擎家族（与 xyzxfk、xyzxfy2、
wmkj、jhfy 同宗，核心工具文件字节级相同），作者自述
基于"夕阳再现－江湖风云 2－风云再起"开发而成。这一支和另一轮处理过的
`xyzx`（夕阳再现）/`jhfy3`（江湖风云3）/`xajh4gkb`（笑傲江湖4公开版）/
`xyzxyl201412`（夕阳再现-炎龙20141231）是同一个真正的"夕阳再现"血统
（`d/city/sj.lpc` 逐字节相同）——注意本项目里还有另一批同样打着"夕阳
再现"招牌、但地图其实是完全不同的"天涯"家族的档案（`xysylmhb`/
`xyzxiiylzymh`/`yzxiiizylfy`/`xyzx3`/`tianxiawuxue`/
`yxcs`），品牌名称不能作为判断血统的依据。

## 内容亮点

- 江湖跨越嘉兴、扬州等多个地点，新角色会随机分配到其中之一（如"铁枪
  庙""北疆小镇"等）作为起点，场景描写按性别区分称谓（如"少年侠士"/
  "妙龄少女"），细节比较讲究。
- 注册流程独立设置"管理密码"与"普通密码"两组口令，管理密码专用于找回
  丢失的普通密码。
- 天赋分配环节允许针对单项属性重投，也可以一次性全部随机，系统会展示
  结果并请求二次确认。
- 死亡后有完整的鬼门关/白无常复活体验，与同一 ES2 大家族的 `yszz`/
  `bmxkx2001` 共享同一套阴曹地府子系统；不少 NPC 是 friendly 属性、
  `fight` 指令会被拒绝，但 `kill` 指令可以绕过这层同意判定直接开战。

## 深度功能测试新发现的 bug（详见 NOTES.md）

`adm/daemons/logind.lpc` 里有两处调试用的 `printf("%O\n", ob)`
（AGENTS.md §7.34，两条平行的姓名输入路径各一处）和一处食物/饮水初
始化误判对象的 bug（`ob->query("age")` 应为 `user->query("age")`，
AGENTS.md §8.9）——已全部修复。另外在死亡/复活系统里发现并修复了
AGENTS.md §7.68 归档的复活软锁死 bug 类的又一实例：`d/death/npc/
{wgargoyle,bgargoyle}.lpc` 的 `death_stage()` 用 `if (!ob ||
!present(ob)) return;` 同时处理"对象已销毁"和"此刻不在场"两种情况，
后者本该重试却被当成永久放弃处理，导致复活序列一旦被打断就会让角色
永久卡成鬼魂。已按已验证的修法拆分为两段判断，此刻不在场改为 5 秒后
重试。

## 在线试玩

https://mudlibs.fluffos.info/bixiecanyang/

## 管理员账号 / Admin account

- **ID**：`fluffos`
- **密码 / Password**：`Mud@2026`（登录密码）；**管理密码(wizpwd)**：`Wiz@2026`
  （本游戏注册时要求单独设置一组"管理密码"，找回/重置密码时使用）
- **中文名 / Display name**：浮浮
- **权限 / Level**：`(admin)`（ACL 表使用的最高常用等级）
- 授权方式：`adm/etc/wizlist` 加入 `fluffos (admin)` 一行（保留原有
  afei/addisjeams/akai 条目）。

> 警告：`Mud@2026` / `Wiz@2026` 是本地游玩用的公开默认密码。若要正式对
> 外开放主机，请先修改。

## 本地运行

```
cd libs/bixiecanyang
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40065**。启动后请稍等几秒再连接。
