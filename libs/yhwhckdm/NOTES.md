# yhwhckdm（炎黄武魂参考代码）-- porting notes

原档只有 `d/`、`kungfu/`、`clone/` 三棵树，没有 master，原先标 `not-convertible`。发布说明（薪有所属，2017-03-03）写明这是当时炎黄武魂的参考代码，方便规划 id。

按用户指示接到已转换的 `yanhuangwuhun` 骨架上：

1. `rsync` `libs/yanhuangwuhun/work/` → `libs/yhwhckdm/work/`。
2. `convert_lib.sh` 转好的参考树覆盖 `clone/`、`d/`、`kungfu/`（already_utf8=61 converted=10123 lossy=1）。
3. 引擎仍是 yh 2003 的 `/adm/single/master`。

端口 **40270**。注册流程与 `yanhuangwuhun` 相同（`washto` / `born`）。
骨架带过来的管理员 `fluffos`/`Mud@2026` 可直接登录，落地扬州客店
`/d/city/kedian`（参考树覆盖了原炎黄的世外桃源起点）。`look`/`quit` 正常。

## 商店 + 拜师（2026-09-04 librarian shop slice）

新角度：扬州醉仙楼付费购买。进口笔记只写了骨架落地。参考树覆盖
了 `d/`，但醉仙楼 `/d/city/zuixianlou` 和黎生路径与
`yanhuangwuhun` 2026-09-03 相同。管理员存档从骨架带过来时已经是
丐帮第二十代 / 师父黎生，本轮不再重拜。

本轮没有新的 programming bug。`goto` / `clone` / `MESSAGE_D` 的
`to_int` 和 `log_file assure_file` 已在骨架里。`log directory :
/log` 仍是绝对路径，本机 `debug.log` 不打开。

### 实测过程

`fluffos` / `Mud@2026`，第一输入是英文 id。落地扬州客店
`/d/city/kedian`（北丑、戚长发、店小二在场）。`score`：「丐帮第二
十代传人 浮浮」「师父是黎生」。`goto /d/city/zuixianlou`，店小二
`list` 烤鸡腿八十文。`clone /clone/money/gold`「黄金复制成功」。
`buy jitui`：「你从店小二那里买下了一根烤鸡腿。」`i` 一两黄金 +
九十八两白银 + 四十文铜钱 + 烤鸡腿。`quit` 后再登：门派、黎生、
银钱都在；烤鸡腿是食物，不进档（手足 yh 已知）。

管理员存档未提交。
