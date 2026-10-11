# wllz3 — 武林列传Ⅲ（186）

档案：`wllz.rar`（33,366,348 字节，2026-10-11 上传到 Drive `backup-mud`）。`config.cfg` 里的名字是「武林列传Ⅲ」，
mudlib 目录 `/root/wllz/world`。文件时间 1999-10-24 到 2009-03-02，中位数 2008-09-07；`nohup.out` 记录 2009-03-02 最后一次启动。

## 二进制发行（binary-pending-tooling）

源码被有意抹掉：14,242 个 `.c` 里有 7,589 个内容只剩一个字节 `1`（包括 `adm/single/master.c`、
`kungfu/skill` 596 个、`kungfu/class` 345 个、大部分房间）。真正的代码只留在 `binaries/` 下的 9,365 个
MudOS `.b`（`MUDB` 魔数）里：
- 被抹掉的 7,589 个里有 7,588 个有对应 `.b`；唯一缺的是 `d/shaolin/da-shou`。
- 另有 547 个 `.b` 根本没有 `.c`：542 个在 `data/founding`，4 个在 `data/room`，1 个在 `cmds/apr`。
- 6,653 个 `.c` 是完整源码，可直接读。

驱动 `driver`（2007-11-12，ELF 32 位 i386，**未 strip**）：符号表里有 `predefs`、`efun_table`、`instrs`、
`save_binary`、`locate_out`、`disassemble`，所以 efun 编号可以直接从二进制里读出来，不必猜。启动行把版本号
改成了中文字串，`.b` 头和 033-3（MudOS v22pre11）同属 v22 系列格式，具体子版本待从符号表确认。

`backup/2008-9-7` … `backup/2008-9-13` 是 7 天的玩家存档备份，每天约 3,300 个 `.o`。

## 血统

`d/`、`kungfu/`、`clone/`、`cmds/` 的路径和侠客行（xkx）家族重合 61–65%（hymud、hy5、haiyang2、yxxcii、
fqyy2、hy2002、hy、xkxyb 等），但不比其中任何一个更接近，所以单独编号，不算衍生版。
