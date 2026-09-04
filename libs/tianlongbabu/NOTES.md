# tianlongbabu（天龙八部）-- porting notes

`天龙八部.tgz`（编号 907）实际是 ZIP（`PK\x03\x04`），不是 gzip。内容是 2000-01 的 TLBB 残档：`DAEMONS/` `FEATURE/` `OBJ/` `INCLUDE/` 加上开封/洛阳/聚贤庄等地域，**没有** `master.c` / `simul_efun.c` 源码（只有 `BINARIES/ADM/OBJ/MASTER.B` 与 `simul_efun.b`），也没有 `cmds/`、`std/`、`/t/tutor`。FluffOS 不能加载 MudOS BINARIES。

按用户指示把残档接到已转换的 `es2` 骨架上：

1. `rsync` `libs/es2/work/` → `libs/tianlongbabu/work/`（带上 `/adm/obj/master`、`simul_efun`、`cmds/`、`std/`）。
2. DOS 大写树小写后叠上去：`DAEMONS`→`/adm/daemons`，`FEATURE`→`/feature`，`OBJ`→`/obj`，地域→`/t/<area>`。`convert_lib.sh` 只认小写 `.c`，大写 `.C` 先被当成 `.c` 再改成 `.lpc`（752 个），并补了 `.c"` 引用。
3. `LOGIN.H` 要的 `/t/tutor/start` 原先不存在，写了一间临时驿站，东门接到 `/t/kaifeng/temple`。

`LOGIN.H` 的 `START_ROOM`/`DEATH_ROOM`/`REVIVE_ROOM` 叠到
`work/include/login.h`。es2 的 `globals.h` 补了 TLBB 要的 `MAPDATA`、
`REGISTER_D`、`TOPTEN_D`，否则 overlay 上来的 `securityd.lpc` 编不过。

端口 **40269**。这是骨架嫁接，不是完整原站。已有 es2 管理员
`fluffos`/`Mud@2026` 可登录；`goto /t/tutor/start` 再 `east` 进开封
城隍庙（`/t/kaifeng/temple`，庙祝在场）。旧号落地仍是 es2 的
`/d/snow/inn`（存档位置），新号走 TLBB 起点。
