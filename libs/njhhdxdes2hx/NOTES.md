
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2/xkx 衍生的校园题材构建版。WASM 修复：修好了 check_legal_name() 里 §8.1 长度界限没减半的部分和残留的 i%2==0 字节步进门槛（is_chinese() 本身已经是正确的码点判断）；修复了 feature/team.lpc 里 §7.47 的 origin()==ORIGIN_LOCAL/ORIGIN_CALL_OUT（整数 vs 字符串）问题；修复了 §7.48 的跨档案非法 private 呼叫（treemap.lpc 的 _query/_set/_delete、action.lpc 的 continue_action、attack.lpc 的 attack——private 改成 protected）；修复了 §7.49 的 valid_write() 存档扩展名不匹配导致 quit 失败报"Denied write permission"。通过 adm/etc/wizlist 把 fluffos/Mud@2026 播种为 (admin)。用真实中文名字（秦风）完整注册+look/score/quit 在 WASM 下全程验证，管理员 update 指令也已验证。
