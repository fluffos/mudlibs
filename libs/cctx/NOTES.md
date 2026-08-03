
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2/XKX 血统代码库（襄阳关/嘉峪关场景内容）。完整 WASM 修复：（1）过时的 SIMUL_EFUN_OB 和 MASTER_OB 宏都指向了未被使用的 /adm/single/{master,simul_efun}.lpc 死代码副本，而 config.fluffos 实际使用的 master/simul_efun 文件是 /adm/obj/{master,simul_efun}.lpc（真正的 simul_efun.lpc 带有旧版本缺少的 destruct()/remove() 覆写，和 §7.58 类的 bug 是同一类，在它搞坏 quit 之前就被排查出来了）；（2）adm/daemons/httpd.lpc（纯 HTTP 服务器，无条件调用 socket_*）按 §7.52 的整文件入口点掏空模式处理掉了。排版格式化工具的第三类盲点检查（CJK 重新加空格）在约 40 个"误报"（原文本来就有的装饰性房间名/诗词间距）里抓到了一处真正的损坏：d/huashan/map.lpc（一张密集的 ASCII 地图）——已直接还原，没有手工修补。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。
