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
