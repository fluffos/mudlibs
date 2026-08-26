# 泥潭三 / 《終極魔界》 (nitan3) — 与 nitan_san 完全同源

**这是本项目已收录的 `nitan_san`（archive #61，泥潭三.rar）的一份
确认重复档案**，来源是 GitHub `mudchina` 组织的 `nitan3` 仓库（同一份
"泥潭三"快照，改为 git 托管而非打包成 .rar）。全部 15,236 个共有文件
中 15,235 个逐字节相同（唯一差异是 `config.cfg` 里一处纯装饰性的
Windows 文件夹名字符串），`adm/single/master.c` 逐字节 md5 相同。按本
项目约定，确认重复后仍然完整走完整套上线流程（独立编号/端口/存档），
并在 `meta.json` 里用 `duplicate_of` 字段指向 `nitan_san`，而不是悄悄
跳过——详见 `NOTES.md`。

由于内容确认同源，本次没有重新走一遍 `nitan_san` 那边耗时的独立踩坑
流程，而是直接把 `nitan_san` 已经修好、已经格式化、已经实机验证过的
`work/` 源码树同步了过来（数据/日志目录除外），另外在本档案自己全新
的 `/log` 目录上发现并修复了一个 `nitan_san` 自己从未触发过的潜在
euid 权限顺序 bug（`master.lpc::log_error()` 缺少 `assure_file()` 后
的重新提权）。详见 `NOTES.md`。

## 内容亮点

- 招牌是**《終極魔界》**（"Ultimate Demon Realm"），套在"泥潭"引擎
  上的一层皮肤；登陆横幅本身自称"泥潭三"。
- 新玩家取姓名、选性格、"洗"天赋，由**盘古**在**生命之谷**安排投胎，
  世界观基于盘古开天、转世投胎的神话设定——和 `nitan_san`/
  `nitan_ceshi` 同一门派。
- **不需要外部 MySQL 数据库**，注册、存档全部走本地文件。
- 大型武侠世界：数十个门派/城镇（少林、武当、丐帮、峨嵋、崆峒、
  桃花岛……），完整的门派任务、宠物/坐骑、留言板等系统。

## 在线试玩

（本档案未做 WASM 打包测试，暂无在线试玩链接；`meta.json` 的
`wasm_status` 留空，而非编造状态。）

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **普通密码 / Password**: `Mud@2026`（平时登录用这个）
- **管理密码 / Admin(recovery) password**: `Mud@2026admin`
- **中文名 / Display name**: 浮浮（姓"浮"名"浮"）
- **权限 / Level**: `(admin)`（最高级别），通过 `/adm/etc/wizlist` 授予
  （已随源码同步就位，登录即生效）。已用 `update
  /adm/daemons/band.lpc` 验证成功（重新编译提示"成功！"）。

> 警告：对外公开架设前请务必修改这两个密码。

## 本地运行

```
cd libs/nitan3
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40217**。文件数量较多（13,557 个 `.lpc`），驱动启动后需要
一定时间完成预加载。
