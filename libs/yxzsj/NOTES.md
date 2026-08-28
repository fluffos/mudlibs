
## WASM 修复摘要（迁移自 meta.json 的 group_note）

逸俠之世界（Daniel's World），ES II 血统，台湾出品。是 libs/yxsj 关系很近的手足档案（同样的标题、同样的 daniel@tpts4.seed.net.tw 联系人、同样的 is_killing/check_legal_name bug 指纹、同样的文件布局），但确认不是逐字节相同的重复档案——即使做完空白/CRLF 归一化，内容依然有差异（比如 adm/daemons/combatd.lpc 有大约 80 行不同），而且这份快照的 securityd.lpc 的 save_object() 路径本来就已经修好了（query_save_file()+__SAVE_EXTENSION__），yxsj 那份才需要应用这处修复——是同一血统里不同时间点的构建版本，不是同一套文件的重新打包。先发现并修复了和 yxsj 相同的重大编码 bug：这份档案同样是 BIG5 编码，但最初的 convert_lib.sh 用了整个语料库通用的 GB18030 默认值，产生了静默乱码（合法的 UTF-8，但是真实存在却错误的中文码点），而不是报出转换错误。已用 BIG5 重新跑了 convert_lib.sh（见处理 yxsj 时做的工具扩展提交），并在重新转换出来的代码树上重做了每一处修复。应用的 WASM 专属修复（和 yxsj 完全一致的模式）：（1）经典的 §8.1 is_chinese()/check_legal_name() 字节区间 bug，改成逐码点 0x4e00-0x9fff 检查，界限从 2/12 减半为 1/6。（2）§7.12 类的 tell_room() 裸 exclude 导致的 message() 崩溃，用 exclude || ({}) 保护修复。（3）master.lpc 的 valid_write() 缺少 'user == this_object()' 保护（valid_read() 本来就无条件回传 1；这份快照里 securityd.lpc 的 save_object() 检查本来就是对的，和 yxsj 不同）。（4）§7.50 类的 is_killing(object) 对 is_killing(string id) 修复了和 yxsj 完全相同的 9 处呼叫点（kungfu 类的 roar/nuke 档案、u/d/daniel/ 下的 NPC 档案、cmds/std/surrender.lpc）。（5）data/ 下 45 个 CRLF 换行的 .o 存档档案统一转换成 LF。adm/daemons/ftpd.lpc 和 adm/daemons/network/dns_master.lpc 都处于休眠状态（在 preload 里被注释掉，只有带保护的巫师指令呼叫者），保持原样。和 yxsj 相同的已知非阻断性问题，没有进一步深挖：chinesed.lpc/emoted.lpc 在启动时都会抛出一个被捕获的'Illegal mapping format while restoring dict/emote'；登录过程中会出现一次针对 obj/user 的 command_hook 的短暂'apply() with insufficient permission... needs: private, has: hidden'，但不会阻挡任何功能。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist。注册流程在格式化前后都用一个真实的中文名字完整验证过；管理员权限已通过'目前權限﹕(admin)'确认。LPC 格式化工具对全部 949 个档案运行（写入 919 个，21 个转档之前就存在的错误，9 个未改动）——数字和 yxsj 完全一样，符合这两份是同一代码库不同时间点快照的判断。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 11 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 185 live occurrences deleted: 184 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant — a second, already-commented-out copy of the same template lower in the same file was correctly left untouched). 2 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40170.

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

## Deep functional test (round two) — 2026-08-27

Full live continuous playthrough (`build-debug` driver, port 40170,
raw Python socket client): registered a real character (譚雲/Tanyun),
apprenticed to a sect NPC (柳淳風, 封山劍派/swordsman), learned a skill
via `learn ... from ...`, fought a wild NPC with the safe `fight`
command (ended in unconsciousness with a scheduled `revive()`
call_out, not death — confirmed working, not a soft-lock), did two
separate reconnect cycles (one abrupt-disconnect-then-reconnect while
a `revive()` timer was still pending, one explicit `quit`+fresh
relogin after a real wall-clock gap), and cross-checked `find_player()`
+ `tell` + the admin `call` command between two simultaneous
connections. Registered and confirmed the seeded admin account
(`fluffos`/`Mud@2026`) live for the first time (previously wizlist-only,
no save file existed) — `目前權限﹕(admin)` confirmed, and `score`
correctly showed the admin-only extended attribute block.

Systematically grepped this lib's source for every standing
cross-cutting bug pattern in AGENTS.md (§4.3, §4.4, §7.11, §7.80/118,
§7.86/100, §7.103, §7.112, §7.121–§7.153) rather than spot-checking.
Found and fixed 6 real bugs, all from the already-documented pattern
list — same lineage, same bugs as `yxsj`'s own round-two pass, since
these two libs share the ES2/`daniel` codebase at different points in
its history:

- **`data/chinese.o` (§4.4, BIG5 `0x5C`-collision)**: this snapshot's
  BIG5→UTF-8 conversion had the exact same collision as `yxsj`, but
  WORSE — not just the one trailing dict entry, but **10 separate
  string values** ended in a `0x5C`-final BIG5 character (功/許)
  immediately before their closing quote (e.g. `"move":"...輕功\"`,
  `"celestial":"...神功\"`, plus 3 more mid-string cosmetic instances
  like `"force":"內功\心法"`). Confirmed via boot: before the fix,
  `chinesed`'s dict restore silently zeroed (same `Illegal mapping
  format while restoring dict` class as `yxsj`, though this boot didn't
  even surface the warning — the corruption ran past EOF differently
  given the extra breaks), and `learn`/`skills` crash-risked on any
  entry past the first broken string. Re-derived the whole file from
  `raw/mudos/es2lib/data/chinese.o` with a custom escape-aware BIG5
  decoder (unescape `\`-doubling byte-for-byte, THEN BIG5-decode, THEN
  re-escape for LPC string syntax) rather than a blind `iconv` — diffed
  byte-for-byte against the naive conversion and confirmed the ONLY
  changes were removal of the 13 spurious backslashes, nothing else.
  Verified live: fresh boot showed no `chinesed` restore warning at
  all, and `learn sword from master` / `skills` both worked
  crash-free on the test character.
- **§4.3 `static`→`nosave` collision, 7 call sites / 4 files**
  (`cmds/wiz/call.lpc`'s `CALL_PLAYER`, `adm/obj/master.lpc`'s
  `CRASHES` ×3, `cmds/arch/purge.lpc`'s `PURGE` ×2,
  `adm/daemons/securityd.lpc`'s `promotion`) — identical shape and
  identical files to `yxsj`'s fix, confirmed against `raw/`'s
  `"static/..."` literals. Reverted all 7, and hardened
  `adm/simul_efun/file.lpc`'s shared `log_file()` with an
  `assure_file()` call before `write_file()`, matching `yxsj`. Verified
  live: logged in as admin (`fluffos`), ran `call tanyun->query("name")`
  and `call tanyun->query("class")` against the live test character —
  both executed cleanly and appended correctly to the pre-existing
  (real 2000-era) `log/static/CALL_PLAYER` history file with no crash.
- **§7.103 `log_error()` broadcasting raw compile warnings**
  (`adm/obj/master.lpc`): added the `strsrch(message,"warning:") == -1`
  guard. Verified live: a lazy first-compile of `cmds/usr/quit.lpc`
  during testing threw multiple `Unknown escape sequence` warnings (the
  ~129-instance cosmetic tail of the same §4.4 BIG5 collision, left
  unfixed here exactly as documented for `yxsj` — none of these are
  crash-causing) and none of them leaked to the connected test
  player's screen.
- **§7.86/§7.100 redundant `replace_program()`**
  (`obj/board/wizard_j.lpc`): `inherit "/std/jboard"` +
  `replace_program("/std/jboard")` in `create()` — same file, same
  shape as `yxsj`'s fix (missed by the earlier macro-based corpus
  sweep since this board uses a literal path). Deleted the redundant
  `replace_program()` call. Verified live as the admin test character:
  navigated to `/d/wiz/jobroom`, the board loaded without the "cannot
  bind an lfun fp to an object with a pending replace_program()"
  crash, and `project`/`read new` both worked end-to-end.
- **§7.153 `std/jboard.lpc do_read()`**: identical missing-`else` shape
  to `yxsj` — `read new`/`read next` computed the correct index, then
  fell through into the unconditional `sscanf(arg, "%d", num)` numeric
  parse, which always failed on the literal string `"new"`/`"next"`
  and returned "你要讀第幾個計畫的簡報﹖" instead of showing the note.
  Fixed by chaining it into the existing `if/else if` instead of a
  bare trailing `if`. Verified live: `project <title>` followed by
  `read new` now correctly displays the just-posted note instead of
  erroring.

No other cross-cutting pattern from the AGENTS.md checklist matched
live source in this lib (checked explicitly, not just assumed clean):
§7.121 (no float-typed economy function found), §7.122/§7.132/§7.134/
§7.135/§7.136/§7.139/§7.144/§7.145/§7.146/§7.147/§7.148/§7.149/§7.151
(no matching shape found by grep), §7.129 (`tell_room()` wrapper
already has the `exclude || ({})` guard from the earlier §7.12-class
onboarding fix), §7.133 (`net_dead()` IS defined on `obj/user.lpc`),
§7.150 (the login-verification object restores directly onto itself,
no throwaway clone; the leftover post-`exec()` shell object is
destructed lazily on the player's *next* disconnect/quit/wizard
`update`, confirmed via code read of `obj/user.lpc`'s own `net_dead()`
and `cmds/usr/quit.lpc`/`cmds/wiz/update.lpc` — no active heart_beat on
the orphan in the meantime, so no resave-corruption path), §7.152 (no
`remove_living_name()`/`unset_living_name` call exists anywhere in this
codebase, so the living-name registration from initial login persists
across `reconnect()` without needing to be reset — confirmed
empirically: cross-connection `tell tanyun ...` from the admin account
worked immediately after `tanyun` had already gone through one full
netdead→revive→reconnect cycle).

Two harmless, pre-existing oddities noted but explicitly NOT touched
(design/leftover, not crashes): `d/snow/schoolhall.lpc` and
`d/wiz/jobroom.lpc` both end their `create()` with a
`"obj/board/xxx"->foo()`/`->???()` call to an undefined function on a
board object — apparently a preload idiom from the original codebase;
call_other to an undefined function is a silent no-op on this driver
(confirmed no error in either boot output or the caught-error handler
across this whole session), not a crash. Also: `cmds/usr/recall.lpc`
sends players to `/d/wiz/entrance` while `cmds/usr/recall2.lpc` (a
distinct, separately-registered command) sends players to
`/d/snow/inn` — both work correctly, left as-is since choosing which
should be "the" recall command is a content decision, not a bug.

This lib's actual playable world is a much smaller custom build (a
"school" starting zone plus a 雪亭鎮/snow-town zone with the ES2 sect
system) than `doc/help/newbie`'s text describes (which lists many
more locations/sects than are reachable from the actual map) — a
content/documentation mismatch, not a programming bug, left unfixed
per the scope boundary.

Admin account `fluffos`/`Mud@2026` confirmed seeded and working
(kept, with its live-registered save file). Test character `譚雲`
(`tanyun`) and its test bulletin-board post removed before commit.
