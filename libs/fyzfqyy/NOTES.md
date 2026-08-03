
## WASM 修复摘要（迁移自 meta.json 的 group_note）

风云（古龙小说题材），管理密码+登录密码双密码注册流程。新发现的 bug，已收录进 AGENTS.md §7.60：master.lpc 的 log_error()——每一条普通的编译警告（不只是真正的错误）都会调用它——最后会呼叫 CHANNEL_D->do_channel(...)；如果 CHANNEL_D 这时候还没有被预载（取决于它在 adm/etc/preload 里排第几个），这次呼叫会在调用者自己还在编译的过程中，悄悄触发对 channeld.lpc 的一次新编译——这个驱动禁止这种嵌套编译，于是抛出"*Object cannot be loaded during compilation."，又被 log_error() 自己捕获并重新记录一次，如此循环，把一条本来毫无意义的 pragma 警告变成了几万行重复的错误堆栈输出。这个问题只存在于 CHANNEL_D 加载完成之前的启动窗口内（之后完全正常），但足以把真实输出淹没到没法看，因此还是修了：在广播前先判断 find_object(CHANNEL_D)。另外也修复了 is_chinese() 和 check_legal_name() 里经典的 §8.1 中文名字 bug（长度界限+字节步进循环，会静默拒绝所有真实中文名字）。排版格式化工具的第三类盲点检查在 12 个命中里抓到了两处真正的损坏（一份巫师培训测验文字档案和一份带有未转义尾随中文注释的代码速查表）——两处都已还原。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。
