# 银河英雄传说.zip → `yinhexiongxiongchuanshuo`

- Archive: `银河英雄传说.zip` (from the 2026-07-29 bulk `mudlib.rar` drop,
  not the original numbered archive batch). ES-II-lineage MudOS lib
  (`master.c` header: "for ES II mudlib, original from Lil, rewritten by
  Annihilator (11/07/94)") reskinned as a sci-fi setting based on the
  novel/anime *Legend of the Galactic Heroes* (银河英雄传说) — 2001-era
  snapshot (file dates Aug 2001), ships a Windows `mudos.exe` binary
  (ignored; this repo always uses its own driver).
- Mudlib root in archive: `new/` (one level down from archive top).
- No shipped config file at all (unusual for this collection — most
  archives ship *some* `config.*`); `config.fluffos` reconstructed from
  scratch using another lib's config as a template + this lib's own
  `master file`/`simulated efun file` paths.
- Port: **40104**.

## Status: DONE — boots clean, full registration with a real Chinese name verified, playable

## What was fixed

1. Standard encoding (GB18030→UTF-8, 786 converted) + `.c`→`.lpc` rename
   (834 files) via `convert_lib.sh`; 134 literal `.c` refs fixed
   automatically.
2. **§7.3 class**: `master.lpc`'s `create()` had the old MudOS
   force-reload trick — `efun::destruct(find_object(SIMUL_EFUN_OB))`
   followed by `call_other(SIMUL_EFUN_OB, "???")` to force a recompile.
   Segfaults this driver instantly on boot (raw C++ stack dump, master_ob
   not yet set during its own `create()`). Deleted; serves no purpose here.
3. **§8.1 class**: `adm/simul_efun/chinese.lpc`'s `is_chinese()` used the
   GBK lead-byte range test (`str[0] > 160 && str[0] < 255`) — never true
   for a real Unicode codepoint. Fixed to `str[0] >= 0x4e00 && str[0] <=
   0x9fff`. `adm/daemons/logind.lpc`'s `check_legal_name()` had the
   matching byte-oriented bugs: a `strlen(name) < 2 || > 12` bound (should
   be 1-6, the error message already says "一到六个中文字") and an
   `i%2==0` sliding-window gate that only ever tested every OTHER
   codepoint (landing on what used to be GBK lead bytes) — dropped the
   `i%2==0` gate entirely and fixed the bound to 1/6. Verified: real
   Chinese name 秦风二 now registers correctly end-to-end into the game
   world (previously any Chinese name would have been rejected).
4. **Pre-existing archive typo**: the whole `/feature/` tree (skills,
   damage, movement, etc. — inherited by `std/char` and dozens of other
   files) was shipped on disk as `/teature/` (not `/feature/`) — a typo
   baked into the original archive's directory name, invisible on the
   original case-insensitive Windows filesystem, fatal here. Renamed the
   directory; fixed ~745 of 745 initial "Inherited file does not exist"
   compile failures in one move (745 fail → 24 fail).
5. `/obj/id_card.lpc` and `/obj/task/id_card.lpc` (identical duplicate
   content, different locations) both declare `void geton_taxi(...)` but
   `return 1;` from two early-exit branches inside it — hard compile
   error on this driver (old MudOS tolerated returning a value from a
   void function). Changed both to bare `return;`. This was also the root
   cause of a reproducible "Too deep recursion" in
   `securityd.lpc:143`/`valid_write()` on nearly every `quit` and
   registration — the never-successfully-compiled `/obj/id_card` object
   kept getting reloaded/retried inside a security check, tripping the
   recursion guard instead of a clean compile error. Fixing the compile
   error resolved the recursion on `quit` for a normal player id_card.
6. Admin seeding (AGENTS.md §1.5): registered `fluffos` through the
   normal flow, appended `fluffos (admin)` to `adm/etc/wizlist` (this
   lineage's `securityd.lpc` reads it directly, and `/` is already in
   `trusted_write` for `(admin)`/`(arch)`, so no separate ACL table
   needed). Verified: `update /obj/id_card` succeeds as `fluffos`.

## Known issue, NOT fixed (logged per §7.15's spirit, not blocking)

`feature/dbase.lpc`'s `query(prop)` falls through to
`default_ob->query(prop, 1)` when a property is undefined locally and
`default_ob` is set (a prototype/template-object pattern used broadly by
this lineage for NPC/item base classes). `/obj/login.lpc`'s
`query_save_file()` calls `query("id", 1)` and reproducibly hits "Too
deep recursion" in `securityd.lpc`'s `valid_write` on **every** login
object's save (both mid-registration and normal reconnect) — but it is
NOT fatal: the farewell message still prints and the save file is still
written correctly (confirmed: `data/login/q/qinfengtest.o` and
`data/user/q/qinfengtest.o` both exist and are loadable on relogin). Did
not chase down which specific object's `default_ob` chain is implicated
(this is a shared/global mechanism touching many files) — real fix would
need auditing every `set_default_object()` call site for a cycle or
self-reference; out of scope for a first bring-up pass. Cosmetic log
noise only; does not affect play.

## Not yet done (out of scope for this pass)

WASM export / GitHub Pages packaging — deferred to a later batch pass
across all newly-added libs.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES II 血统，独立档案（来自 2026-07-29 批量上传的 mudlib.rar）；游戏内重新包装成了银河英雄传说题材。之前一次会话对原生驱动的适配过程（记载在这份档案自己的 NOTES.md 里）已经修好了 master.lpc 的 create() 里那个会段错误的强制重新加载技巧、标准的 §8.1 GBK 字节区间 is_chinese()/check_legal_name() bug、/teature/ → /feature/ 的目录名拼写错误，以及 id_card.lpc 里一处 void 函式却 return 了值的编译错误，还播种了 fluffos (admin) 的 wizlist 条目——这些都没有在本轮重做。这次 WASM 修复覆盖了剩余的 §7.x 类检查：（1）三个碰 socket 的精灵（adm/daemons/ftpd.lpc、adm/daemons/network/ftpd.lpc、adm/daemons/network/dns_master.lpc）都完全处于休眠状态——在 adm/etc/preload 里被注释掉，而 DNS_MASTER 仅有的两个呼叫者（cmds/adm/shutdown.lpc、cmds/wiz/mudlist.lpc）都是巫师指令，已经带有 find_object() 检查保护——保持原样，不需要掏空。（2）master.lpc 的 valid_read() 本来就无条件回传 1（完全没有转发给 SECURITY_D，所以那种 new() 注册卡死的 bug 模式在这里不适用）；还是在 valid_write() 上加了标准的 'user == this_object()' 短路判断，和本次会话其它档案保持一致。（3）§7.50 类的 is_killing(object) 对 is_killing(string id) 修复了 cmds/std/surrender.lpc 里唯一一处呼叫点。is_chinese()/check_legal_name() 本来就已经正确（在更早的原生启动那一轮修好了，本轮没有重新处理）。原生启动那一轮留下的唯一悬而未决问题——securityd.lpc 的 valid_write() 里一个不会阻断的'Too deep recursion'，在每一次登录物件存档时都会通过 feature/dbase.lpc 的 default_ob 兜底链复现——在 WASM 下再次复现（错误签名/行号完全一致），依然只是外观问题：注册、进入游戏世界、以及 quit 都能围绕它正常完成。注册流程在格式化前后都用一个真实的中文名字完整验证过（id→y 确认→中文名字→密码+确认→电子邮件→性别→进入费沙中央宇宙港）。管理员权限已通过既有的 fluffos/Mud@2026 凭据确认：'目前权限：(admin)'。LPC 格式化工具对全部 834 个档案运行（写入 821 个，2 个转档之前就存在的错误，11 个未改动）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选，没有 CJK 重新加空格/转义损坏命中。
