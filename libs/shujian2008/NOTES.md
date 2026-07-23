# shujian2008 — 「书剑天下」2008 (ShuJian MUD, 2008 build)

Archive: `书剑2008.rar`. Port: 40029. Status: **done** (boots clean, full
registration flow verified end-to-end including a real Chinese name and
correct rejection of a banned novel-character name).

## What this is

"「书剑天下」" ("ShuJian" / "Book and Sword, the World"), credited to
"ShuJian MUD Wizard Group", hosted at www.cqmud.com ("重庆电信" / Chongqing
Telecom). Same "Century-family" `adm/single/{master,simul_efun}` layout
as `shiji`/`zhonghua2` (archives #32/#34), but with a much more
elaborate, genuinely custom `securityd.lpc` ACL system (directory-based
`trusted_read`/`exclude_read` tables keyed by wizard-status categories)
rather than the simpler `find_object`-only pattern seen in those two —
this turned out to matter a great deal (see below). ~11,714 raw files,
9,936 after `.c`→`.lpc` rename.

## Fixes applied

### Standard §15h Chinese-detection fixes

1. `adm/simul_efun/chinese.lpc`'s `is_chinese()` — a two-specific-byte
   variant (`str[0]` lead-byte range 176-247, `str[1]` trail-byte range
   161-254, plus a reserved-codepoint exclusion for `str[0]==215 &&
   str[1]>249`) — rewritten to the standard single-character CJK
   codepoint check.
2. `adm/daemons/logind.lpc`'s `check_legal_name(object ob, string name)`
   — bound `i<4||i>8||i%2` (byte count, plus an odd-BYTE-count rejection
   that's meaningless for character counts) → `i<2||i>4`; removed the
   `i%2==0` even-byte-offset gate so every character position is
   checked; `name[i..<1]` (a multi-byte suffix, since the old `is_chinese`
   only read the first 2 bytes of whatever it was given) → `name[i..i]`
   (a clean single-character slice, matching the simplified
   single-character `is_chinese`).
3. `adm/daemons/named.lpc`'s `valid_name()` — a banned-substring double
   loop stepping over GBK byte-pair boundaries (`i/j += 2`, `j` starting
   at `i+1`) building substrings of whole 2-byte characters — rewritten
   to step per-character (`i++`/`j` starting at `i`, `j++`).

### Two new architectural bug classes (AGENTS.md §15n, §15o)

These aren't Chinese-detection bugs at all — they're driver-vs-custom-ACL
interaction bugs, and took by far the most diagnostic effort of any lib
this session. **See AGENTS.md §15n/§15o for the full writeup** (this is
the short version):

- **§15n**: this lib's real `securityd.lpc` denies `(player)`-status
  callers from reading `/adm` or `/cmds` at all — correct for actual
  data reads, but the driver ALSO routes compile-time source loading
  (`func=="load_object"`/`"recompile_object"`) and `#include` resolution
  (`func=="include"`) through this exact same `valid_read` gate, and a
  fresh pre-login connection defaults to `(player)` status. Every
  never-preloaded `/adm`/`/cmds` object's first lazy compile — triggered
  incidentally by the registration flow (`BAN_D`, then `UPTIME_CMD`,
  `mudlist`, `sited`, one at a time as each was reached) — crashed with
  "Read access denied" instead of just compiling. **Fixed by adding
  `case "load_object": case "recompile_object": case "include": return
  1;`** to `securityd.lpc`'s `valid_read` switch — compiling/including
  code is routine operation, never a sensitive data read, and should
  never be gated by the caller's status. Also preloaded `/adm/daemons/band`
  as a belt-and-suspenders first attempt (harmless to keep, though the
  securityd fix alone would have covered it).
- **§15o**: `master.lpc` never defined `get_include_path()` at all. Per
  the driver source, a compile with no VM context (preload, bare `lpcc
  --batch`) just uses the config's raw include path; a compile WITH a VM
  context (live, mid-connection, exactly this lib's registration flow)
  calls `master->get_include_path()` instead, and with no apply defined,
  no path gets resolved. Symptom looked identical to §15n at first (a
  compile error mid-registration) but was actually the NEXT layer once
  §15n let the underlying read through — "Cannot #include globals.h",
  a compile error, not "Read access denied", a runtime error. Fixed with
  the same `get_include_path()` shape already used in `es1_win`/`esI`
  (AGENTS.md §8d), returning `({ file's own directory, ":DEFAULT:" })`.
  **Caveat honestly noted**: once §15n's `"include"` case was in place,
  this specific symptom was gone before I got to retest §15o's fix in
  isolation — so it's not proven independently necessary here, just
  applied on the same reasoning that made it necessary in the ES-family
  libs. Future libs: apply §15n first, retest, and only add §15o if
  `Cannot #include <file>` errors persist for mid-connection compiles
  specifically.

### Minor defensive fixes (now likely redundant given the above, harmless to keep)

- `logind.lpc`'s `gb_big5()`: `UPTIME_CMD->main(1)` and `"/cmds/usr/
  mudlist"->main(ob, "all")` wrapped in `catch()`.
- `band.lpc`'s `load_sites()`: the `read_file(BANNED_SITES)` call
  wrapped in `catch()` (the target file doesn't even exist in this
  archive; harmless either way).

## Re-verification pass (2026-07-23) — two new bugs found and fixed

The original pass above never tested a post-login command — exactly the
gap AGENTS.md §15ae's standing policy (adopted after this lib's original
pass) warns about. Re-testing the full flow through `look`/`score`/`quit`
found this lib was actually **fully broken post-registration** (every
command after landing in the game world silently produced `什么？` — "What?"
— with zero output), caused by TWO independent, compounding bugs:

1. **AGENTS.md §15ae**: `feature/command.lpc` declared its central dispatch
   function `private nomask int command_hook(string arg)`, inherited into
   the player body and registered via `add_action("command_hook", "", 1)`.
   This driver treats `private` as hidden from `add_action`'s own external
   dispatch, not just same-file callers — silently breaking every
   post-login command with zero visible error. Fixed by dropping `private`
   (kept `nomask`).
2. **AGENTS.md §15ar**: `adm/daemons/commandd.lpc`'s `rehash()` filters
   `get_dir()`'s listing with `sscanf(cmds[i]+"$", "%s.c$", cmds[i])` to
   strip the old `.c` extension — after this project's blanket
   `.c`→`.lpc` rename, every real command file is `.lpc`, so this pattern
   matched **zero** files, forever, leaving `commandd`'s command-search
   table permanently empty and `find_command()` always failing. This is a
   live runtime `sscanf`, invisible to both the quoted-`".c"`-reference
   fixer and the bare-preload-data-file fixer, and is a SEPARATE root
   cause from #1 above that independently produces the exact same "every
   command does nothing" symptom (per AGENTS.md §15ar's own precedent that
   more than one cause can compound in the same lib). Fixed by changing
   the pattern to `"%s.lpc$"`.

Both bugs had to be fixed before any post-login command worked at all —
fixing only one would still have left the lib fully broken. Re-verified
with a full fresh registration (id `sjqfdd`, real Chinese name `秦风十`,
male) through to `look` (re-displayed the actual starting room, 武馆前院/
Martial-arts-hall Front Courtyard), `score` (real character card with
correct name/stats), and `quit` (clean exit) — all producing genuine,
correct output. `debug.log` for the session has zero `denied`/`cannot`/
`undefined function`/`bad argument`/`error in error handler` lines.

## Interactive test result — full registration flow (original pass)

Verified the complete registration path in one continuous connection,
including an incidental but valuable extra check:

1. `sjbteste` → passes `check_legal_id`, reaches confirmation.
2. `y` → password prompt.
3. `Pass1234` (twice, matching, meets the digit+uppercase requirement) →
   accepted, reaches the Chinese-name prompt.
4. **`萧峰`** → correctly **REJECTED** ("对不起，这种名字会造成其他人的
   困扰" — this name would cause trouble for others) — 萧峰 is a real
   Jin Yong novel character (*Demi-Gods and Semi-Devils*), and this game
   explicitly warns against novel character names. This is CORRECT
   behavior, not a bug — and it incidentally proves the fixed
   `valid_name()`/banned-name check is ALSO working correctly
   post-UTF8-fix (rejecting a real match), not just that legitimate
   names pass.
5. **`秦风`** (an invented, non-novel name) → accepted, proceeds into
   character-attribute selection (根骨/膂力/悟性/身法 stat prompt) — the
   actual proof the full fix chain works end-to-end for a real name.

## lpcc sweep

9,936 files, 9,860 pass / 76 fail (99.2%). Failure tail is the usual
shape (a `is_killing` type-mismatch pattern, a handful of missing
globals/functions, some genuine syntax typos) — not triaged individually
per AGENTS.md §6b/§13, boot + full interactive registration test is the
verification gate. Memory stayed healthy throughout (~16GB free
consistently, no pressure).
