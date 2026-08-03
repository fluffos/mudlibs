
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 138 号 zxty 一样是再现天涯，是 2008 年的修改重新发布版本——master.lpc 内容不同，没有精确哈希匹配，但标题/血统相同；完成了一次中断的转档；重新实现了 efun::tail()（§6.2）；启动干净。完整 WASM 修复：给 band.lpc 加了本地回环放行（这个血统会封禁任何不能严格解析成 4 段点分十进制的地址）；修复了 logind.lpc（create()/make_body()）里同样的因为多余 seteuid(getuid()) 而把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限，去掉了 i%2==0 的字节配对门槛；修复了 named.lpc 的 invalid_new_name() 拒绝单字名字的问题，以及它按字节步进的近似重复名字滑动窗口（重写成按字符步进，和 nt1 的 named.lpc 是同一个 bug 同一种修法——这个血统和 NT/nitan 家族共享 named.lpc/注册房间设计，不只是和 jym 共享）；给 securityd.lpc 的 get_status() 加上了防御性保护（mapp/arrayp 检查，虽然没有实际观察到重入，但这是廉价的保险）。管理员账号通过纯文本的 /adm/etc/wizlist 档案播种（这个血统的 securityd.lpc 每次启动都会直接读取它，不涉及存档档案）。注册到进入游戏世界、look/score/quit（quit 会正确触发这个血统自己的 30 分钟防滥用确认提示，不是 bug），以及管理员身份识别（"您目前权限：(admin)"）都已干净验证。
