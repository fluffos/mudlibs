# yhwhckdm（炎黄武魂参考代码）-- porting notes

原档只有 `d/`、`kungfu/`、`clone/` 三棵树，没有 master，原先标 `not-convertible`。发布说明（薪有所属，2017-03-03）写明这是当时炎黄武魂的参考代码，方便规划 id。

按用户指示接到已转换的 `yanhuangwuhun` 骨架上：

1. `rsync` `libs/yanhuangwuhun/work/` → `libs/yhwhckdm/work/`。
2. `convert_lib.sh` 转好的参考树覆盖 `clone/`、`d/`、`kungfu/`（already_utf8=61 converted=10123 lossy=1）。
3. 引擎仍是 yh 2003 的 `/adm/single/master`。

端口 **40270**。注册流程与 `yanhuangwuhun` 相同（`washto` / `born`）。
骨架带过来的管理员 `fluffos`/`Mud@2026` 可直接登录，落地扬州客店
`/d/city/kedian`（参考树覆盖了原炎黄的世外桃源起点）。`look`/`quit` 正常。
