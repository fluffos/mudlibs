
## WASM 修复摘要（迁移自 meta.json 的 group_note）

adm/obj/master.lpc 和 jyqxc（086）/jyqxc2（087）/jyqxc2013fwq（088）/xkx2017（112）逐字节相同——同一个"金庸群侠传"/XKX 框架家族，游戏内容不同，按本项目对这个家族已有的惯例单独编号；启动干净，零修复。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc 的 make_body() 里 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限，去掉了 i%2==0 门槛；给 securityd.lpc 的 get_status() 加上了防御。注册流程里有两步是本次会话其它血统档案里没见过的：密码复杂度要求（必须同时包含大小写字母和特殊符号，不只是长度下限），以及性别之后、进入游戏前的民族选择（0-3）——需要照实读取 input_to() 调用链，不能假设它和 jym/hy 系那种更短的流程一样。管理员账号通过纯文本的 adm/etc/wizlist 播种。注册流程到进入游戏世界、look/score/quit、管理员权限识别都已干净验证。
