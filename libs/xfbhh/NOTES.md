
## WASM 修复摘要（迁移自 meta.json 的 group_note）

NT/nitan/Lonely 血统，master.c 和 hhsj（014-1）以及 nitan170911 逐字节相同。WASM 修复：给 clone/user/user.lpc、inherit/room/room.lpc、adm/daemons/giftd.lpc 应用了 §7.15 的 efun::set/query/delete/addn 修复（这次是按内容逐一修的，不是直接复制档案）；修复了 check_legal_name() 里长度界限没减半的部分（2-4 字符，原来还是按字节数校准的 4-8）；修复了 efun::message() 对 exc_target=0 的拒绝。登录协议：get_user 用逗号分隔（"id,password,ciphertext,email"，逗号内部会自动替换成 U+2551），但 get_char 需要字面的 ║ 分隔符（"gender║img║nickname"）——这是通过直接阅读 logind.lpc 逆向工程得出的。通过 adm/etc/wizlist 把 fluffos/Mud@2026 播种为 (admin)。用真实中文名字（秦风）的完整注册+look/score/quit+管理员 update（针对 clone/user/login.lpc，不是 /obj/login）已全程验证。
