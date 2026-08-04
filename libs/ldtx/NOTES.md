# 鹿鼎天下.rar → `ludingtianxia`

- Archive: `鹿鼎天下.rar` (from the 2026-07-29 bulk `mudlib.rar` drop).
  "Century / adm-single" family lineage (custom `securityd.lpc` ACLs,
  master at `/adm/single/master` — same shape as `shiji` (021),
  `shujian2008` (024), `xjcq2000` (027), `xkxz2` (028),
  `xiakexing100` (030)). ES II heritage (`master.c` header: "for ES II
  mudlib... rewritten by Annihilator", further "modified by Xiang for
  XKX").
- **Naming quirk** (AGENTS.md §5.1's "don't trust the name field," a new
  instance of it): the archive is named 鹿鼎天下, but the login banner
  brands the game **雄霸天下『西安站』** ("Xi'an station"), while the
  `quit` message still says "离开了鹿鼎天下" — two different in-game
  names coexist in the shipped source, evidence of a rebrand that wasn't
  applied everywhere. Went with 鹿鼎天下 for the slug (matches the
  archive/what the user is most likely to look for) but documented both
  names in the README.
- Mudlib root in archive: `ldtx/ldj/` (two levels down).
- No shipped config file; reconstructed using `shiji`'s config.fluffos
  (same lineage/master path) as the template.
- Port: **40105**.

## Status: DONE — boots clean, full registration with a real Chinese name verified, playable

## What was fixed

1. **Systemic encoding artifact, not caught by `convert_lib.sh`'s normal
   GB18030→UTF-8 pass**: nearly the entire tree (3903 of ~5960 `.lpc`/`.h`
   files) shipped with doubled `\r\r\n` line endings (CRCRLF, doubled —
   worse than the single-CRCRLF quirk `convert_lib.sh`'s own comments
   already document). This silently broke every subsequent string-literal
   edit (exact-match tooling can't find `\r`-embedded lines). Fixed with a
   blanket `sed -i 's/\r//g'` across every `.lpc`/`.h` file before doing
   any further hand-edits.
2. **§7.1 class, simpler variant**: `adm/single/master.lpc`'s
   `valid_read`/`valid_write` did `if (ob = find_object(SECURITY_D)) ...
   return 0;` — no lazy `load_object()` attempt at all, just permanent
   deny until securityd happens to already be loaded. Real driver boot
   preloads securityd first so this never bit in practice, but it made
   `lpcc_check.sh`'s single-VM compile sweep (which doesn't preload)
   deny-everything (2/5960 pass). Added the standard re-entrancy-guarded
   `load_object(SECURITY_D)` fallback from AGENTS.md §7.1 to both
   functions — jumped to 5793/5960 passing.
3. **§8.1 class**: `adm/simul_efun/chinese.lpc`'s `is_chinese()` (GBK
   byte-range test) and `adm/daemons/logind.lpc`'s `check_legal_name()`
   (byte-oriented length bound 2-10 + `i%2==0` sliding window) — same
   fix pattern as every other lib in this catalog entry. Verified: real
   Chinese name 秦风六 registers correctly end-to-end.
4. `/adm/daemons/network/dns_master` and `/adm/daemons/ftpd` were
   actively preloaded (not already commented out, unlike most other
   libs in this collection) — commented out per the standing no-sockets-
   package policy (§1.3c). Confirmed harmless at runtime: login flow
   prints "网路精灵并没有被载入" (network daemon not loaded) and
   continues normally.
5. Admin seeding (§1.5): registered `fluffos` through the normal flow,
   appended `fluffos (admin)` to `adm/etc/wizlist` (same mechanism as
   the Century family generally — `/` is in `securityd.lpc`'s
   `trusted_write` for `(admin)`). Verified: recompiling `/adm/single/
   master` via `update` succeeds as `fluffos` (shows the driver's
   variable-clear side effect, no ACL denial).

## Known issues, NOT fixed (logged, matching the "content bugs" bar)

167 of 5960 files fail `lpcc_check.sh`'s compile sweep, none of them
core-system files (master/simul_efun/logind/securityd/chinesed all
compile and run correctly). Three observed failure shapes, all isolated
to individual content files:
- A handful of `kungfu/skill/*.lpc` files have a genuinely unterminated
  string literal in the original source (e.g. `qingyi-jian.lpc:11`:
  `"skill_name" : "大侠式,` — missing closing quote before the line
  ends), which then swallows the next line and surfaces as a garbled
  "Illegal character" error further down. Pre-existing author typo, not
  a conversion artifact (confirmed the file decodes as valid UTF-8
  throughout).
- A handful of `clone/misc/*_cloth.lpc` (clothing item) files reference
  the `YEL`/`NOR` ANSI color macros without the header that defines them
  being reachable from that specific file — compile error, item is
  simply unusable in-game.
- A couple of room/NPC files (e.g. `/d/city2/tian_anm`) throw a runtime
  "Bad argument 1 to call_other()" (got int 0) — a null-object reference
  in that room's own logic, likely a stale/removed NPC or item reference
  from the original game's development.

None of these affect the core registration/look/score/quit loop verified
above; logging here rather than auditing all 167 individually.

## Not yet done (out of scope for this pass)

WASM export / GitHub Pages packaging — deferred to a later batch pass.

## 移植修复（2026-08-03，来自姊妹档案 ldtxii 的深度测试）

`ldtxii` 深度功能测试（§10.7）在其 `logind.lpc` 里发现两个 bug，
逐行核对后确认 `ldtx` 这份档案在完全相同的行号上有一字不差的同一
段代码——是共享血统里从未修过的祖传问题，不是 `ldtxii` 自己引入
的。按 AGENTS.md §2.1 的"跨手足档案移植已验证修复"惯例，直接把两
个修复移植了过来：

1. `get_name()` 里紧跟在中文名字设定之前的调试残留
   `printf("%O\n", ob)`（AGENTS.md §7.34）——删除。
2. 食物/饮水满值初始化误读 `ob->query("age")` 而不是
   `user->query("age")`（AGENTS.md §8.9）——已改正。

用一个全新角色（`ldtxdive`）验证：注册流程无调试残留输出，
`score`显示食物/饮水槽创建时即为满值（16/16格），`look`/`score`/
`quit`均正常。重启后 debug.log 里出现的两条报错都是本档案早就记录
过的既有内容缺口（`xiaobao.lpc` 引用不存在的 `/u/rhxlwd/cloth.lpc`
的老问题，以及和 `ldtxii`一样的 `chatroom.lpc`/`/u/mouse/` 缺口），
不是这次改动引入的新问题。未做完整的第二轮深度功能测试（本次是移
植已验证的修复，不是从头深挖这个档案）。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

Century/adm-single 家族（shiji/shujian2008/xjcq2000/xkxz2/xiakexing100），游戏内标题为"雄霸天下『西安站』"。WASM 修复：把 adm/daemons/network/dns_master.lpc 的 startup_udp()/send_udp()/send_shutdown() 里那行 socket_close() 掏空（§7.52 socket 精灵掏空）——这个 WASM 构建下 socket_create()/socket_bind() 是未定义的 efun，导致编译失败，进而破坏了每一个中途呼叫进这个档案的 call_other()，包括每次连线在英文名字提示之前就会跑的 encoding_to_mudlist() 步骤。没有中文名字/宏定义/指令表相关的 bug（is_chinese() 本来就是正确的码点判断）。管理员账号"fluffos"/"Mud@2026"其实早在这份档案更早、WASM 之前的一轮里就已经播种进 adm/etc/wizlist 了（这份档案的 README 里已经提到过一个真实上线过的部署）——已验证既有凭据依然能登录并正确显示 (admin)，不需要新账号（一开始误以为这是 §1.5 那种引导 id 冲突的模式，多加了一个多余的并行账号"fladmin"，后来发现这份档案自己既有的 README 早就记录过可用的 fluffos 凭据，已撤销这个多余的添加）。留下一处真实存在、不阻断的内容缺口未修：d/city/npc/xiaobao.lpc 的 create() 引用了一个不存在的 /u/rhxlwd/cloth.lpc（这个巫师目录在整个档案里根本不存在）——对结果为 0 的物件做 call_other() 会抛出"Bad argument 1 to EFUN call_other()"，但被房间自己的 setup()/reset() 包装函式捕获了，从未传到玩家那里；按"不凭空捏造内容"的先例保持原样（和 ffxymud/jhfy2/jhfy3 的 d/city/sj.lpc 是同一类情况）。完整的注册（选 gb 编码→id→确认→中文名字→密码→确认→天赋选'0'→接受'y'→电子邮件→性别）和 look→score→quit 流程在排版格式化前后都验证过；格式化工具没有引入任何损坏（三类盲点检查都干净）。
