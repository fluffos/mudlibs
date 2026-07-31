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
