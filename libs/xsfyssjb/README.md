# 心声风云四升级版 (xsfyssjb)

风云Ⅳ（Sumxin 风云）是以古龙小说为背景的 MUD（原站点 sumxin.com/bbs、fy.sumxin.com），地图偏重大漠/西域风情——楼兰、新疆、藏北、流沙等场景齐全，和常见的中原门派地图（华山、武当、少林、丐帮等）并存，突出古龙笔下"大漠孤烟"式的江湖；注册时除了性别，还要选择民族（0-3），呼应这种跨民族的世界观设定；档案里还有一个 `dynamic_npc_quest` 目录，暗示带有动态生成 NPC 任务的机制，而非纯手写的固定任务列表。和这一轮的另一个"风云"手足档案 `wqfy` 是同类 bug 模式，不过底层代码库并不相同；和 `fysjmb`（风云四解密版）才是真正同源代码——`d/dreamland/shanding.lpc` 等文件逐字节相同，此前两份档案都没有互相记录这层关系。

## 内容亮点

- 详见上方简介：古龙大漠西域地图、民族选择、动态 NPC 任务目录，以及与 fysjmb 的同源关系。

## 本次修复的关键 bug

**§8.1 GBK 字节区间 `is_chinese()` bug**：`adm/simul_efun/
chinese.lpc` 的 `is_chinese()` 要求字节数是偶数并检查 `str[0]` 的
原始字节区间（161-254），在这个驱动按 UTF8 码点索引字符串的情况
下，奇数字数的合法中文名字会被误判为不合法；`adm/daemons/
logind.lpc` 自己的 `check_legal_name()` 也有对应的 `i%2` 奇偶门槛
和字节数长度上限（2-10，原意是提示文字里说的"一到五个中文字"）。
已把 `is_chinese()` 改成逐码点 0x4e00-0x9fff 区间检查，
`check_legal_name()` 改成逐字符检查，长度上限改成字符数 1-5。

## 管理员账号 / Admin account

这份档案有两个 `securityd.lpc` 候选（`adm/securityd.lpc` 和
`adm/daemons/securityd.lpc`），通过 `SECURITY_D` 宏确认真正生效的
是 `/adm/daemons/securityd`（符合 §7.56 的双档案陷阱模式），
`WIZLIST` 确实会在开机时被读取。

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，
  `wizlist` 命令确认显示"目前权限：(admin)"，且 `fluffos` 出现在
  最高权限组里。

> 警告：对外公开架设前请务必修改此密码。

## 测试注意事项

性别/民族选择紧跟在 `std/char.lpc` 首次编译爆发期之后，和
`xhcii`/`xkyxciii` 记录过的情况一样会有测试客户端的计时竞态。用
`--idle 4` 并多送几次"m"/"0"能稳定通过——这纯粹是测试工具的计时问
题，不是 mudlib 本身的缺陷。

## 本地运行

```
cd libs/xsfyssjb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40149**。
