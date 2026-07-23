# mofaleidemuba (archive #101: 魔法类的泥巴.rar)

## Verdict: NOT an LPC mudlib — confirmed compiled EmberMUD (SMAUG/ROM/DikuMUD-derivative) binary distribution, English-language classic fantasy MUD

This archive is **not compatible with the FluffOS/LPC pipeline** used
throughout this project, and is not even source-available — it ships only
a **precompiled Windows binary** plus Diku-format world/data files. No
conversion, port assignment, or driver boot was attempted, following the
same precedent already established for archives #31 (三国歪传), #64
(消失的亞特蘭提斯), and #86-88 (重出江湖 family) — running the LPC pipeline
against this content would produce a meaningless result: this driver's LPC
compiler has literally nothing to compile here, and there is no source at
all to even inspect for hidden LPC content.

## Lineage clarification (per the task's explicit request)

The task flagged this archive's title ("魔法类的泥巴" — "Magic-type Mud",
using "泥巴" as a phonetic loan-transliteration of "mud", not the "泥潭"
character used by the nitan/NT/Lonely lineage) for a lineage check against
`nitan170911`/`nitan6`/`nitan_ceshi`/`nitan_san`. **Confirmed unrelated**:
this is not merely a different LPC lineage, it isn't LPC at all — a
completely different MUD server architecture (compiled C, DikuMUD-family),
an English-language fantasy setting (wizard/mage classes, `Midgaard` zone,
`ROM`/`SMAUG` codebase heritage), not Chinese wuxia/xianxia content. The
title's "泥巴" wording is a coincidental pun/homophone on "mud" (the genre
name), not a reference to the "泥潭" (nitan) game family at all. Zero
shared code, zero shared architecture, zero shared content with any nitan
archive.

## Evidence

- **Full archive contents** (32 entries total, confirmed via `unrar l`):
  `readme.txt`, `config.cfg`, `pemud.exe` (a 684,032-byte **PE32 Windows
  console executable**, confirmed via `file`), `area/*.are` (Diku-format
  world files: `city.are`, `help.are`, `immort.are`, `limbo.are`,
  `school.are`, `clans.are`), `area/area.lst` (zone boot index),
  `area/socials.txt`, `area/factions.dat`, `area/MudProgs.prg` (SMAUG-style
  mob-program script data), `classes/class0`-`class3` (playable-class
  skill/spell lists — `class0` decodes as 法师/mage, listing `magic
  missile`, `ventriloquate`, weapon proficiencies, etc — a classic
  Diku/ROM class definition, not LPC), `gods/Leoh`, `player/Leoh`,
  `player/Zzz` (player save files), `log/1000.log`, `log/1001.log`,
  `notes/` (empty), `clan/` (empty). **There is not a single `.c`/`.lpc`
  file, and not a single `inherit` statement, anywhere in the archive** —
  confirmed via `find -iname '*.c' -o -iname '*inherit*'` (zero hits) and
  a full-tree grep for `inherit` (zero hits) — LPC's single most basic
  keyword is completely absent, the same decisive signal used to rule out
  archives #31/#64/#86-88.
- **`config.cfg` uses `[Section]`/`Key = "value"` INI-style syntax**
  (`[Paths]`, `[Files]`, e.g. `AreaDir = "area"`, `HelpFile = "help.are"`)
  — not the MudOS/FluffOS `key : value` line format documented in
  AGENTS.md's "Config file format" section for every genuine LPC archive
  processed in this project. This alone would already be a strong signal
  this isn't a FluffOS-compatible config, even before checking for source.
- **`strings pemud.exe`** directly identifies the engine:
  `C:\My Documents\EmberMUD\src\db.c`, `Ported to EmberMUD by Thanatos and
  Tyrluk of ToED`, `(Apr. 7, 1995 - ROM mod, Apr 16, 1995) by the SMAUG
  development team`, `Modified for use with ROM 2.3` — this is
  **EmberMUD**, a SMAUG-derivative (itself a ROM 2.3-derivative, itself a
  Merc/DikuMUD-derivative) compiled C MUD engine. `pemud.exe` is simply a
  renamed build of the EmberMUD binary — an entirely different server
  architecture from LPC/MudOS/FluffOS (no LPC compiler, no LPC object
  model, no `inherit`/`efun`/`simul_efun` concepts at all; game logic is
  compiled C, not interpreted LPC).
- **`log/1000.log`** (an actual runtime log shipped with the archive,
  presumably from the original author's own test session) confirms the
  engine self-identifies at boot: `"EmberMUD is ready to rock on port
  5555."` — matching the binary's own embedded strings.
- **`area/help.are`**'s in-game ANSI splash banner (`-1 ANSIGREET~`) also
  self-identifies: `"修改于 EmberMUD v0.9.46"` ("modified from EmberMUD
  v0.9.46"), confirming the specific base version.
- **`readme.txt`** (decoded cleanly with plain `iconv -f GB18030 -t
  UTF-8`, no BIG5 fallback needed) is just two lines of setup
  instructions: `默认连接端口：5555` ("default connection port: 5555"),
  `测试巫师账号： leoh 密码：12345` ("test wizard account: leoh, password:
  12345") — i.e. "run the included binary and connect on port 5555,"
  the standard "here's a compiled server, just run it" release shape, not
  "point an LPC driver's `mudlib directory` at this tree."
- **`.are` file structure** (`#AREADATA`/`#MOBILES` section markers,
  spot-checked in `area/city.are`) is the canonical Diku world-data
  format — `Name { All } Diku Midgaard~`, `VNUMs 3000 3399`, numeric mob
  stat-block lines (`23 0`, `100 0 0 0 1d1+999 1d1+999 1d8+32 19`) — the
  same format documented for archives #31/#64, not any LPC object-tree
  layout (no `std/`, `obj/`, `d/`, `cmds/`, `adm/` directories anywhere in
  this archive at all).
- **Game content is English-language classic fantasy** (Midgaard,
  wizard/baker NPCs, mage/warrior-style classes) — not a Chinese
  wuxia/xianxia setting despite the archive's Chinese filename and the
  Chinese-community distribution source (`readme.txt`'s "小熊泥苑"
  banner/site credit inside the RAR comment is a Chinese download-site's
  branding on the archive itself, unrelated to the game's own content
  language).

## Disposition

No `work/` tree, no `config.fluffos`, no port assignment, no driver boot
attempt — following the established precedent for confirmed non-LPC
archives, spending pipeline effort here would be meaningless (nothing to
compile, nothing to convert). `raw/` (1.1MB, extracted via `unrar x`) is
kept for traceability only. This archive should be recorded in the main
session's non-mudlib list (AGENTS.md / TODO.md), the same section as
archives #31 (三国歪传), #64 (消失的亚特兰提斯), and #86-88 (重出江湖
family).
