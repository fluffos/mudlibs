
## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一批里的西游记4.2.rar 是这份档案单纯换行符不同的重复版本（文件树完全一样，每个档案的差异只是 CRLF 对 LF）——只处理了一次，这个 .rar 算作重复，不算独立条目。没有和任何既有档案匹配上 master 哈希。启动干净，不需要任何修复。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc 的 make_body() 里因为多余 seteuid(getuid()) 而把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限；给 securityd.lpc 的 get_status() 加上了防御性保护。另外还发现并修复了 adm/daemons/combatd.lpc 里一个真正的编译阻断问题：一个 switch(random(4)) 代码块里真正的 case 标签全被注释掉了，只剩下一个裸的 default:——这在这个驱动下是非法的（switch 至少要有一个真正的 case，不能只有 default），导致整个档案编译失败，破坏了每一条和战斗相关的代码路径（而且是静默失败，因为错误只在真正有东西调用 combatd 时才会第一次显现）。已把这个 switch 换成一个普通代码块，因为那些被注释掉的 case 本来就从未真正分支过。注册到进入游戏世界、look/score、以及 quit 都已干净验证，没有残留的时序抖动；注意这个血统是先问电子邮件再问性别，和某些手足血统的顺序相反——要读真实的 input_to() 呼叫链，不要假设顺序能照抄。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 24 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 239 live occurrences deleted: 238 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant). 2 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, port 40203 listening, zero new "cannot replace"/"cannot bind" debug.log lines.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.
