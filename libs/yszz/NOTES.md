
## WASM 修复摘要（迁移自 meta.json 的 group_note）

WASM 修复：修好了 §8.1 GBK 字节区间 is_chinese()/check_legal_name() bug（这个驱动下 str[i] 是一个码点，不是一个 GBK 字节——真实的中文名字会被静默拒绝）；给 band.lpc 的 is_banned()/create_char_banned() 打上了本地回环放行补丁；通过 adm/etc/wizlist 把 fluffos/Mud@2026 播种为 (admin)。在 WASM 下用一个真实的中文名字（秦风）完整验证了注册+look/score/quit，管理员账号的 update 指令也验证可用。
