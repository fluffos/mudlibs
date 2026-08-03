
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和本合集里现有的任何一个"风云"系档案（fy2/fys/fysjmb/jhfy2/jhfy3/fyzfqyy/fy2qh/fy3dz/fy3xd/jhfy/zzfy/zzfy3/fengyun434/fy2005）都没有 master-hash 匹配——虽然标题相似，但是完全不同的代码库；启动干净，零修复。和 fy2mg（151）是同一个"金庸群侠传"/XKX 框架家族——euid 重置 bug 和 check_legal_name 的问题逐字节相同，密码复杂度要求、性别之后的民族选择步骤也相同。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc 的 make_body() 里 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限，去掉了 i%2==0 门槛；给 securityd.lpc 的 get_status() 加上了防御。管理员账号通过纯文本的 adm/etc/wizlist 播种。注册流程到进入游戏世界、look/score/quit、管理员权限识别都已干净验证（这个血统的新手房间有持续的 NPC 心跳对话——不要把 --idle 节奏测试送指令时被岔开的对话误判为回归，测试时要给和已知正常运行时一样多的中间指令）。
