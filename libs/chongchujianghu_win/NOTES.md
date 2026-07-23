# chongchujianghu_win — archive #87 (重出江湖WIN完全版.rar)

## Status: **not mudlib** — no FluffOS/LPC pipeline work possible

This archive is **not an LPC/MudOS/FluffOS mudlib**. Like archive #86
(`重出江湖.rar`, see `libs/chongchujianghu/NOTES.md`), it is a compiled,
closed-architecture **Windows MUD server + client bundle** ("WIN完全版" =
"Windows complete edition") built on the same custom C++/MFC engine. No
`.c`/`.lpc` source of any kind exists anywhere in the archive. Same category
as archives #24, #31, #64, #86 in AGENTS.md's "Non-mudlib" list — a
different, incompatible server architecture, not something the
GBK→UTF-8/`.c`→`.lpc`/driver-compat pipeline applies to.

## What's actually in `archives/重出江湖WIN完全版.rar`

Extracted to `libs/chongchujianghu_win/raw/` (194 files). Top-level is a
single `MUDSERVER/` directory plus a loose `说明.txt` at archive root.

### Extension histogram (whole tree, 194 files)
```
    109 .o     (save-data, LPC-style mapping-literal text — see below)
     52 .lgn    (login/password files)
      8 .txt
      7 .dll
      4 .mid
      3 .exe
      2 .wav
      2 .rar
      1 each: .pk2 .log .isu .isr .dat .cfg .bmp
```
**Zero `.c`, zero `.lpc`, zero `.h`/`.cpp` even** — this release doesn't even
ship the C++ source seen in #88, just the compiled binaries and their
runtime data.

### Binaries (`file` confirms all are native Windows PE32, not ELF/FluffOS)
```
MUDSERVER/mud.exe                              PE32 executable (GUI) Intel 80386, for MS Windows
MUDSERVER/MSVCRTD.DLL                          PE32 executable (DLL) (GUI) Intel 80386
MUDSERVER/MSVCP60D.DLL                         PE32 executable (DLL) (GUI) Intel 80386
MUDSERVER/MFCO42D.DLL                          PE32 executable (DLL) (GUI) Intel 80386
MUDSERVER/MFC42D.DLL                           PE32 executable (DLL) (GUI) Intel 80386
MUDSERVER/MFCN42D.DLL                          PE32 executable (DLL) (GUI) Intel 80386
MUDSERVER/重出江湖图形版/ccjh.exe               PE32 executable (GUI) Intel 80386   -- graphical client
MUDSERVER/重出江湖图形版/MsgHook.dll            PE32 executable (DLL) (GUI) Intel 80386
MUDSERVER/重出江湖图形版/_ISREG32.DLL           PE32 executable (DLL) (GUI) Intel 80386  -- InstallShield registration DLL
MUDSERVER/文字客户端/X-MUD文字版.exe            PE32 executable (GUI) Intel 80386   -- text client, same as #86's bundled client
```
The `MFC42D.DLL`/`MFCO42D.DLL`/`MFCN42D.DLL` set is the debug-build MFC
runtime — identical fingerprint to #86, confirming this is the same C++/MFC
engine, just a fuller ("完全版") release bundle that also includes a second,
graphical client (`重出江湖图形版/` — "graphical edition", with `ccjh.exe`,
an InstallShield installer log/registration files, `data.pk2` graphics
package, MIDI sound files, `.wav` sound effects) alongside the original
text client (`文字客户端/X-MUD文字版.exe`, `color.txt`, `Users.dat`).

### `grep -r "inherit"` across the entire extracted tree: **0 files**
LPC's most basic keyword does not appear anywhere in this archive (and
there is no text/source file where it plausibly could — every text file is
either save-data, a `.cfg`/`.txt` config, or a `readme`).

### Directory shape
```
MUDSERVER/
  mud.exe, MSVCRTD.DLL, MSVCP60D.DLL, MFC*.DLL   <- compiled server + MFC runtime
  data/
    user/<id>.o        (109 files — player save data)
    login/<id>.lgn      (52 files — password/login records)
    npc/, room/, item/, bak/{0,1,2}, box, config.txt
  文字客户端/            <- bundled Windows GUI text client
    X-MUD文字版.exe, color.txt, Users.dat
  重出江湖图形版/         <- bundled Windows GUI graphical client (installer-packaged)
    ccjh.exe, data.pk2, client.cfg, sound/, *.bmp, *.wav, *.mid, InstallShield artifacts
说明.txt                 <- plain-text release notes (dated 2011-10-15, "BY AKAI"), not source
```
This is **not** an LPC driver directory shape (no `adm/`, `obj/`, `d/`,
`std/`, `cmds/`, no `inherit`-based `.c`/`.lpc` files) — it's a
binary-server-plus-two-GUI-clients release bundle, exactly the
"MUDSERVER + client(s) + save-data" shape already established for #86.

### `data/config.txt` (4 lines, identical shape to #86)
```
6600
烟雨红尘
1
0
```
Port `6600` hardcoded, mud name "烟雨红尘" (same in-game brand name as #86)
— confirms this is the same underlying game, just a different release
package.

### Save data (`.o` files) — confirmed genuine LPC-style `save_object()` text
Sampled `MUDSERVER/data/user/1001.o` etc.:
```
(["skill_map":(["sword":"pixie_jian",]),"dbase":(["reward":(["exp":1,]),
"channels":({"chat","rumor","party","corps","ad",}),"grant":30,"con":20,
"start_city":"house_华山_1001","hp":9605,"level":157,...
```
Same conclusion as #86: the **save-data format** is genuine LPC
`save_object()` mapping-literal text (this engine's compiled C++ driver
clearly implements/emulates LPC-style serialization for its own state), but
that doesn't mean there's an LPC interpreter or LPC source anywhere — the
`.c`/`.lpc` room/npc/skill definitions that would have produced this shape
are simply **not present** in this archive; only the compiled `mud.exe` and
its runtime output are. (Archive #88's C++ source — see
`libs/chongchujianghu_linux_src/NOTES.md` — shows exactly how such a
compiled C++ engine can implement its own `Mapping`-style save format and a
`ROOM_BEGIN`/`NPC_BEGIN`/`SKILL_BEGIN` macro convention that looks
LPC-flavored on the surface without there being any actual LPC involved.)

## Why no pipeline step could proceed

1. **Extract** (step 1) — done; see above (194 files).
2. **Convert `.c`→`.lpc`** (step 2) — **N/A, zero `.c`/`.lpc` files exist**
   anywhere (`find raw -iname '*.c' -o -iname '*.lpc'` — empty).
3. **Port/`config.fluffos`** (step 3) — **not written**. Port **40081 is
   NOT consumed** by this archive; it remains free for the next archive
   with actual LPC source.
4. **Proactive AGENTS.md fix patterns** (step 4) — N/A, no LPC source.
5. **Boot the driver** (step 5) — **not attempted**. `mud.exe`/`ccjh.exe`/
   `X-MUD文字版.exe` are all Windows PE32 binaries; none can be executed by
   or converted into our FluffOS Linux driver build. No `master.lpc`/
   `simul_efun.lpc` entry point exists anywhere.
6. **Registration-flow test via mudclient.py** (step 6) — **not possible**,
   same reason.
7. **`lpcc_check.sh` sweep** (step 7) — **not run**, zero `.lpc`/`.c` files
   under any `work/` tree (none exists) to sweep.
8. **Kill driver** (step 8) — N/A, nothing was ever started.

No scratch files (`boot_stdout.log`, `trace_lpcc.json`, etc.) were created,
since no boot/compile step was ever attempted.

## Relationship to #86 and #88

- **#86 (重出江湖.rar)** — same compiled Windows C++/MFC engine
  (`mud.exe`, same MFC DLL set, same `config.txt` shape, same
  `mud_name`/port), same "MUDSERVER + client + save-data" archive shape,
  just a smaller bundle (no graphical client, no InstallShield extras).
  #87 is best understood as a fuller ("完全版" = "complete edition")
  release of the exact same server build, bundling both a text client and
  a separate graphical client on top.
- **#88 (重出江湖完整源码linunx_2.71原版.rar)** — the genuine C++ *source*
  for this engine (see `libs/chongchujianghu_linux_src/NOTES.md`),
  confirming `mud.exe` here is a Windows/MFC compile of that same
  codebase (or a close sibling version of it) rather than any
  MudOS/FluffOS-family driver.

## Recommendation for TODO.md (not edited by this session, per instructions)

- Archive #87 (重出江湖WIN完全版.rar): status **`not mudlib`** (compiled
  Windows C++/MFC binary + two bundled GUI clients + save data only, no
  LPC source anywhere — see detail above).
- Port **not assigned/consumed** — next free port stays available for the
  next archive with actual LPC source.

## Testing performed

None of the mandatory registration-flow / post-login-command tests
(§15ae policy) apply — there is no driver to boot and no LPC code to run.
This is documented explicitly rather than skipped silently: this lib is
not "done", it is **not a convertible mudlib at all**.
