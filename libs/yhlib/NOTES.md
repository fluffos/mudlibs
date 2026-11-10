# 炎黄2003 (yhlib) — 恢复笔记

## 来源

- `https://github.com/MudRen/YHLib`（炎黄2003 基线）
- Issue：GitHub `#19`
- 与 `yhyxs`（炎黄英雄史）同 70 个 `d/` 域，但 adm 源码哈希不同；作为标注的 2003 基库单独入馆

## Bring-up（2026-11-10）

1. `convert_lib.sh` GB18030→UTF-8、`.c`→`.lpc`
2. `config.fluffos`：port `40393`，mudlib → `work/`，global include 同手足 `yhyxs`
3. §8.1 / §15h：`adm/simul_efun/chinese.lpc` 的 `is_chinese` 改为 CJK 码点；`logind.lpc` 姓名长度/`maxlen/2`；组合名 `strlen(fname)<2`；`named.lpc` `invalid_new_name` 空名门槛与滑动窗口改为字符宽
4. `logind.lpc` `check_ok`：`find_object(MESSAGE_D)` 保护 `find_chatter`（手足同病：MESSAGE_D 未编译时时中断进世界，命令全「什么？」）
5. `clone/user/user.lpc`：`is_killing(ob)` → `is_killing(ob->query("id"))`（§15b 类型）

## 验证

- Boot：`Accepting telnet` on `40393`
- 注册 `yhlibbot` / 张三 → 世外桃源（水笙、狄云）；`look`；`quit`「欢迎下次再来」
- 重登普通密码成功

## 深度功能测试

未做完整 §10.7；登录/重登/起点 look 已过。手足 `yhyxs` 的更多补丁可按需 twin-port。

## §6.10 未知 `#pragma save_binary`（2026-11-10）

- Boot 普查：94 条 `Unknown #pragma, ignored`（`globals.h` 与各 daemon/feature 顶行）。
- 删除 60 个文件中的活动 `#pragma save_binary`（FluffOS 忽略该 MudOS 语用，无行为变化）。
- 证明：工作树 `lpcc --batch` 启动后 0 条 Unknown #pragma；仍有 nosave 函数 / 未用局部等其它类，另轮处理。

## §6.10 机械警告清理（2026-11-10）

- `lpc_warnings.py yhlib --fix`：1530 → 78 诊断（10941 可编 / 60 仍失败）。
- 本轮：`nosave` 函数 32→`protected`；未用局部 1369；`varargs` 补 50；裸 `return` 1。
- 启动证明：`lpcc --batch` 仅剩 1 条「Expression has no side effects」（dns_master），无 Unused local / nosave / Unknown pragma。
- 残留（另轮）：`set_information` 参数类型、questd11/util/damo 语法、`is_killing` 类型、无副作用表达式、全局重声明等。
