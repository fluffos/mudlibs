
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2 血统代码库（作者自己的横幅致谢 Annihilator/ES2），游戏内标题为"葫芦Ⅱ/Demon Angel"（"泥潭中国简化版本"）。没有发现 mudlib bug——WASM 下开箱即用，全程零修改；is_chinese()/check_legal_name() 本来就是正确的码点判断，和本次会话处理过的大多数 ES2 衍生分支不同。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种（格式已对照 securityd.lpc 的解析器核实，和本次会话处理过的其它 ES2 血统档案一致）——这个分支的 logind.lpc 把"目前权限："+ wizhood() 状态行显示注释掉当作死代码，所以在对话记录里看不到直接的管理员权限确认，只能从 wizlist 格式正确来推断。
