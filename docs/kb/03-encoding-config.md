# KB 03 — Encoding, `.c`→`.lpc` fallout, config files (§4–§5)

## 4. Encoding and conversion

### 4.1 Encoding rules

- **Encoding conversion always runs first**, before any sed, rename, or
  edit. Editing GBK bytes with UTF-8 tools plants U+FFFD, which later
  turns into unrecoverable 锟斤拷. This applies to `config.fluffos` too.
- The default is `iconv -f GB18030 -t UTF-8`. Some files are already
  UTF-8; check with a round-trip decode first.
- **A pure-BIG5 archive decodes "cleanly" as GB18030 into mojibake**,
  often Bopomofo-range characters. No error is raised, and
  `convert_lib.sh` reports zero lossy files.
  - Detect: trial-decode 2–3 raw files as big5, gbk, gb18030, and cp950,
    and **read** the results.
  - Fix: re-run the whole conversion with BIG5. First check git for
    fixes already committed to `work/`, because regenerating wipes them
    (`dfgsiiv13b`).
- **Convert every text file, not just source.** Extensionless help text,
  `motd`, `adm/etc/*`, `doc/`, and plain-text `.o` saves are all GBK
  too.
  - `file(1)` misclassifies files (`data`, even "COM executable for DOS").
  - Uppercase `.C` files escape case-sensitive globs.
  - Run a whole-tree Python UTF-8 decode scan over `work/`. Filter real
    binaries out by inspecting content.
  - Typical misses: `help/rules`, `clone/game/{8,21}_hlp`
    (yh2003 siblings), `adm/etc/banned_name`, `doc/help/*`, and
    `adm/etc/nature/day_phase`.
  - **If a play session creates an unexpected new file in `adm/etc/`,
    check `raw/` for a same-path original.** A self-seeding fallback may
    have quietly replaced unconverted content with a weaker default
    (`syxjl`'s 137-entry `banned_name` became a 6-entry default).
- **`iconv -c` can eat a real byte next to an invalid one**: a newline,
  a quote, or a heredoc close tag.
  - Symptoms: "End of file in text block", a missing quote, or a `//`
    comment swallowing the next line's code. The swallowed code can
    silently delete a function or a `set_name()`, with no compile error.
  - Diff the bytes against `raw/` and re-insert the dropped character.
    For the heredoc terminator (`...。LONG`, the newline before `LONG` gone with a lone GBK
    lead byte) `scripts/lpc_fix_heredoc_terminator.py` does that for the whole corpus
    (2026-10-04: 269 glued and 107 indented terminators, KB 04 §6.10); the half character
    itself cannot be restored in UTF-8, the raw bytes show it as the lone byte before `\n`.
    For the closing quote (`"发作身亡了\xf7";` became `"发作身亡了;`), `scripts/lpc_fix_eaten_quote.py`
    puts the `"` back before a line-final `;`/`);` when the line's last string is unterminated
    (2026-10-15: 68 lines in 55 libs; the nitan family's `/inherit/condition/damo.lpc`, so every
    达摩 poison condition, had not loaded).
  - A file flagged LOSSY in the conversion log is suspect even if it
    compiles. Combat and movement exercise many lazily compiled files.
- **One file can mix encodings.** BIG5 lines inside a GBK file decode
  validly into wrong text. Only reading user-facing strings catches it.
  Re-decode the affected lines as BIG5.
- **Strip DOS Ctrl-Z (`0x1a`) bytes.**
- **Grep `raw/` with `grep -a`**. GNU grep treats GBK as binary.
- **GBK and CRLF in `.o` saves need a quote-aware fix.**
  - `save_object()` stores an embedded newline as a bare `\r`.
    `restore_object()` splits strictly on `\n`.
  - Collapse `\r\n`→`\r` **only inside string literals**. Outside a
    string, `\r\n` is a real statement boundary.
  - A blind collapse merges variables and silently restores empty
    mappings.
  - Symptoms: `Invalid utf8 string`, `Illegal file format`, or
    `Illegal mapping format` (`fy2`, `xyj451`).

### 4.2 The `.c` → `.lpc` rename and its long tail

An explicit extension is resolved exactly. An extensionless path tries
`.lpc` and then `.c`. Fallout to check:
1. Quoted refs inside `.h` macros (`#define F_DBASE "/feature/dbase.c"`).
   Grep `.lpc` and `.h` files together.
2. Bare `/path.c` lines in plain-text data files: `adm/etc/preload`,
   room-pool tables, scenery tables. Preload failures are silent. Verify
   every row in a data file with a script, not just a sample.
3. Runtime `sscanf(f+"$", "%s.c$", f)` filters (§8.3b).
4. Fixed-width slices (`[0..<3]`, `len-2..len-1`, `f[<2..] == ".lpc"`
   compared against `".lpc"`). See §7.80, §7.118 and §7.238
   (`scripts/lpc_lpc_suffix_slice.py`).
5. An extensionless live file plus a same-named `.c` backup: after the
   rename the backup can win. Diff every pair.
6. A *directory* named `x.c`. Rename it to something that doesn't look
   like a source file.
7. Uppercase `.C` files are missed by both the rename and the transcode.
   Run `find -name '*.C'`, then check macros whose case no longer
   matches; §4.5 for the tool that renames them and every wrong-case path.
8. Orphaned non-LPC `.c` files (ASCII maps): rename them to `.txt`.
9. Save files (`.o`) that name code files with `.c`: a table restored at boot or a room / NPC save names `"/x/y.c"`, the archive's `y` is `y.lpc`, an explicit extension is resolved exactly and the load finds nothing; most callers skip the failure (`if (!ob) continue;`), so the data is lost without a message. Cases: sgzmudsgz `data/daemons/obj.o` (`OBJ_D->clone_obj()` answered an error string whose `->move()` raised `call_other() couldn't find object 'this object files is an illegual file '`); xlqy_new2007's three pawnshops (`new_shopbox` restored 1 item at HEAD, 360 after); naruto `data/questd.o` (0 of 66 keys existed at HEAD, 66 after: `getItemFile()` already builds `.lpc` names). `scripts/lpc_fix_save_dotc.py --apply` (2026-10-21): 874 tracked `.o` files, 3,185 strings, 84 libs of daemon / NPC / room data (`"/x/y.c"` -> `"/x/y.lpc"` only where `y.lpc` exists and `y.c` does not). Left alone: player data (5,668 files in `data/user`, `data/login`, backups, boards, wizard homes: the census of the tracked `.o` files found 6,558 files with such a string, 45 libs before the exclusions), the file-index caches (Dead Souls `secure/save/files.o` is rebuilt by the file daemon, Discworld `secure/rcs_handler.o`) and headers carrying an `.o` name (`include/globals.h.o`). Detection: the same script without `--apply`; a daemon table whose keys or values are paths: `file_size(key)` over `keys()` in an `lpcc` probe (`lpcc_eval`-style, KB 08 10.16).

A lib may keep non-critical `.c` files as long as the master and login
path are `.lpc`.

### 4.3 `static` → `nosave`, and its collisions

This driver has no `static` keyword at all (variables or functions).
Replace `\bstatic\b` on a *variable* with `nosave`. On a *function* it meant
"not callable from other objects": write `protected`, or just `private` if it
is already private. A blanket `static`→`nosave` also hits functions, and
`nosave` on a function compiles with a warning ("Illegal to declare nosave
function", hundreds per lib); `scripts/lpc_warnings.py --fix` repairs it (KB 04
§6.10). After that:
- **String literals.** `log_file("static/CRASHES")` becomes
  `"nosave/..."`, which orphans the real `log/static/` history and
  crashes on the missing `log/nosave/` dir.
  - Grep `"nosave/` and confirm each hit against `raw/`.
  - Revert real hits to `"static/..."`. Don't just create
    `log/nosave/`.
  - Also harden `log_file()` with `assure_file()` (§7.11).
  - Confirmed across 3+ lineages (`yxsj`/`yxzsj`, `hxxtjqb`,
    `jyqxc2013fwq`), so a corpus sweep is warranted.
- **Compat shims.** `#define nosave static` / `#define protected static`
  become aliases after the sed. Neutralize them; both keywords are real
  on this driver.
- **A parameter or local named `nosave`.** `string nosave` is a syntax error on this driver (`unexpected L_TYPE_MODIFIER`) because `nosave` is a
  modifier here: Discworld v1/v2 `std/shops/print_shop.lpc` (`add_auto_load_info(string nosave, string dynamic)`, v3 had already renamed it to
  `nosave_arg`) never compiled, and the sweep saw it only through the `temperature` command's console line. `rg '(string|int|mixed|object) nosave\b'`
  finds the declaration; the kxkj family's `!(nosave)` is a global int and compiles.

### 4.4 BIG5 characters whose second byte is `0x5C` (`\`)

- `功` (A5 5C) and `許` (B3 5C) were byte-escaped (`5C 5C`) by the old
  driver's `save_object()`. A naive iconv leaves a stray `\` after the
  character.
- Mid-string this is cosmetic (`Unknown escape sequence`). Before a
  closing quote it escapes the quote and breaks the `.o` file:
  `Illegal mapping format`. The variable restores as `0`, and an
  indexing crash follows (`chinesed` dict → `learn`/`skills` broken on
  `yxsj`/`yxzsj`).
- Fix: re-derive the `.o` from `raw/` with an escape-aware decoder.
  Tokenize each string, un-double `\\`, decode BIG5, then re-escape.
- Detect: grep `功\`/`許\`, and grep boot output for `Illegal mapping
  format`. This applies to any genuinely BIG5-sourced lib.
- Source files carry the same stray `\` (UTF-8 after the conversion, so also after `許`->`许`, `縷`->`缕`, `髏`->`髅`,
  `擺`->`摆`, `蓋`->`盖`): `esI` had 438. The driver drops it and prints `Unknown escape sequence '\<byte>'` at the *end of
  the string or statement*, not at the backslash, so `scripts/lpc_warnings.py --fix` deletes every `\` before a
  multi-byte character in each file that reports one (an escaped `\\` pair is kept).
- **Before a closing quote in a source file the stray `\` is not a warning but a compile error**: `"force": "内功\",`,
  `set_name("豹\", ...)`, `if (temp == "功\") ...` escape the quote and the string runs into the next line.
  `cmds/std/enable.lpc` of yxsj, yxzsj, kxkj1 and dfgs2 did not load for that (the `enable` command), and neither did
  NPCs of dreamofseven, kxkj, kxkj1, kxkjii2 and the ES libs: 39 sites in 10 libs, found by a corpus scan 2026-10-04.
  `scripts/lpc_fix_big5_quote_backslash.py [--apply] SLUG...|--all` deletes the backslash when the character before it
  encodes to cp950 with 0x5C as second byte and the quote ends an expression. Two backslashes (`功\\"`, yxsj
  `bullets.lpc`) are not handled; read those by hand.
- **The GB18030 mirror image in save files: a stray half character in front of `\"`.** MudOS saves wrote a quote as `\"`; a
  text that held half of a GBK character right before a quote (`“` + `0xBA` + `\"` in the xyj/sjsh family's `nokiss` emote) was
  transcoded with the `0xBA 0x5C` pair as one character (`篭`), the backslash is gone, the bare quote ends the string and
  `restore_object()` stops: `Illegal mapping format while restoring emote`, so the emote daemon starts with no emotes at all.
  Repair: turn such a character (GB18030 second byte `0x5C`) back into `\` when a `"` follows it, accepting a line only if it then
  parses. 2026-10-06: 32 save files (`data/emoted.o` of 20 libs: mhxy, mhxyqd, shenmo, sjsh*, xiaoyuxiyou, xlqy*, xo*, xyj20032,
  yueyingqiyuan, ...; `xyj2000*/data/doc/1997/Dec/doc12.22.o`). Detection: parse every `#/`-headed save; a failing line with a CJK
  character directly before a `"`.
- **Whole save files that were never transcoded.** The conversion pass covered sources, not every `.o`: 341 text saves in 33
  libs (emote tables, bulletin boards, toplists, player and login saves; es1/esI/es1_win attic boards, xkm backups, kxkj boards,
  `data/emoted.o` of fys, sje, sjpl*, sjshv150) still held the archive's GBK bytes, so `restore_object()` stops with
  `Invalid utf8 string while restoring <var>` and the object starts empty -- an emote daemon without emotes, a board without
  posts. `scripts/lpc_save_encoding.py [--apply] SLUG...|--all` transcodes each tracked text save that is not UTF-8 and keeps it
  only when the result parses as a save. The encoding is chosen per file, against the lib's own UTF-8 sources: GB18030 and
  BIG5 both "succeed" on each other's bytes, but the wrong one yields rare characters (dreamofseven's `網咖管理器` read as GBK is
  `呼〡恨瞶竟`), and a lib without CJK sources (questmud, Finnish) has Latin-1 bytes. BBS colour art splits a double-byte
  character with an ANSI code (lead byte, `ESC[1m`, trail byte: dreamofseven, hc, naruto boards); the script rejoins it and
  drops a lone lead byte, and strips trailing zero padding. Saves with zeroed blocks in the middle (disk damage: jym
  `drop/user_bak/`, shenmo `nancheng_b.o`, the shiji/sj/xkxyb/xzyx `topten.o`) or broken literals are listed and left. Detection: `git ls-files 'libs/*/work/*.o'`, starting with `#`, not valid UTF-8.
- **Saves the onboarding transcode broke (2026-10-15).** They are UTF-8, so the pass above skips them, but
  `restore_object()` refuses them: 166 tracked `#/` saves in 42 libs (jym player saves, the dreamofseven, kxkj, hc, naruto
  and nt1 boards, xkm's room map and its 25 backups, huoying's and yxzsj/yxsj's emote tables, pkuxkx news). Causes:
  `iconv -f gb18030 -t utf-8 -c` dropped a lone lead byte *together with the quote after it* (`"short":"棋室\xb0",` became
  `"short":"棋室,`); a GB copy of a BIG5 save keeps the stray backslash after a 0x5C character (`成功\",`), or the quote
  that MudOS read as escaped by that byte (`出\"俞" >`); GBK has 0x5C characters too (`賊` D9 5C); and some originals
  were damaged in the archive (a truncated `farmd.o`, a mapping that ends `]),]`, a lost key mid-emote).
  `scripts/lpc_save_restore_check.py SLUG...|--all` asks the driver (a throwaway mudlib, each save restored into an object
  that declares its variables); `scripts/lpc_save_encoding.py --from-raw [--apply] ...` re-decodes a save from raw/ when
  iconv of raw/ still gives the tracked bytes (66 files), else moves only backslashes after 0x5C characters until it parses
  (17). The parser alone over-reports: 22 of its 795 suspects restored fine. Nine archive-damaged live saves were repaired
  by hand (see the libs' NOTES); 53 are left, nearly all backups (`backup/`, `login_bak/`, `board back/`) and wizard
  copies.
- **What `restore_object()` refuses that a lenient parser accepts (2026-10-15).** It reads the file line by line, so
  (1) a raw newline inside a string ends the line and the string never closes: `save_object()` writes one as `\r` and
  restore turns `\r` back into a newline (`src/vm/internal/base/object.cc`), but 159 tracked saves in 59 libs carry raw
  newlines, mostly from the archives themselves (xjcq2000's boards and NPC saves, fys); (2) a blank line, even a trailing
  one, is `Illegal file format - 1 ()`; (3) every array and mapping element must end with a comma (`"whip":60])` is
  `Illegal mapping format`). A line cut off at the end of the file, with no newline, is skipped without an error: the
  variable is silently lost. `lpc_save_encoding.parses()` now refuses (1)-(3), and `lf_to_cr()` writes the newlines as
  `\r` and drops blank lines (172 saves; all driver-checked).

---

### 4.5 Paths the code names in another case than the archive stores them

**Symptom.** A room is "missing" although its file is there: an exit leads nowhere, `carry_object("/d/city/npc/tea/longjing")`
returns 0 (`Bad argument 1 to call_other` two lines later), `#include "bagua.h"` is `Cannot #include`, a whole directory
(`d/SHAOLIN/BAMBOO1.C`, `d/Mojie/`, `HELLZhen/`) is unreachable. The scan does not see it: a `.C` file is not an `.lpc` file, and a
reference that does not resolve is a run-time failure of the *caller*.
**Cause.** The archives come from DOS / Windows hosts that ignore case. Files are stored as `BAGUA0.lpc`, `longjing.C`, `ANSI.h`,
`d/SHAOLIN/`; the code says `__DIR__ "bagua0"`, `"tea/longjing"`, `#include "ansi.h"`, `"/d/shaolin/..."`, often both spellings in the same
lib. The extraction renamed `.c` -> `.lpc` but not `.C` (§4.2 item 7), and 15 of the 3274 uppercase-extension files were never transcoded.
**Fix.** `python3 scripts/lpc_case_paths.py [--convert] [--apply] [--list FILE] SLUG` (gitlink libs refused): resolves every path
literal of every code file (`"/d/x/y"`, `"d/x/y.c"`, `__DIR__ "y"`, `#include "x.h"` / `<x.h>`; comments, strings in heredocs and `#if 0` are
masked) as the driver would, treats a reference that resolves only when case (and `.C` / `.c` / `.LPC`) is ignored as a wrong-case
name, renames every such file and directory to lower case (`.C` -> `.lpc`, `.H` -> `.h`), staging the moves, and rewrites **every** reference
to a path that moved (the right ones in the old spelling too), changing only the components that were renamed. A target that exists, two
renames with one target, a reference that two real paths could mean and a non-UTF-8 `.C` file (`--convert` transcodes GB18030) are listed
and left. `--list` writes the objects to load-check (renamed, edited, naming a renamed path): `scripts/lpc_listcheck.sh` on that list, HEAD
against the tree.
`--dos` also renames what the references cannot show: in every directory that holds an upper-case-extension file or something the first phase renamed, the
remaining `.C` / `.H` / `.LPC` files, the code files with an all-upper-case stem and the all-upper-case directory names (the skills of the Journey-to-the-West libs are looked up
as `SKILL_D + name`: `daemon/skill/MAHAYANA.C` is invisible to a scan of literals). **Side effect to plan for:** an NPC that was unreachable behind a wrong-case path exists
for the first time and may raise in `create()` (a skill file or a `carry_object()` item that this archive never had); the room that holds it then stops loading (`sjshwzjqb`, `sjcs`).
`scripts/lpc_resilient_room.py SLUG` makes the room base's `make_inventory()` `catch` the `new(file)`, so the room loads without that NPC, as it did before.
**Detection.** Run the tool without `--apply`; `Cannot #include X` in a scan where a file of another case exists;
`git ls-files | grep -E '\.(C|H)$'`. After the rename run `scripts/lpc_warnings.py` again: files that never loaded show errors
of their own. Computed paths (`"/d/" + zone + "/NPC/"`) are invisible to the tool; it prints the old upper-case directory names that
still occur in string literals so they can be read. Commit with a pathspec: the moves are already staged (AGENTS.md section 13.3).

### 4.6 A quote lost to a lone lead byte in a source file (2026-10-18)
**Symptom:** `Illegal character 0xe5` (or `0xe6`, `0xef`) on a line of Chinese text, and the object never loads: `d/moon/obj/poem` (32 libs: `"...广寒宫阙。,` and `"...潇潇雨。,`), `kungfu/skill/qingyi-jian` (18 libs: `"skill_name" : "大悲式,`), `d/shendian/obj/niepan` (23 libs: `符号<U+E4D4>NOR);`).
**Cause:** the original text held half a character (a lone lead byte) in front of the closing quote; `iconv -c` dropped both, or turned the pair into a private-use character (`U+E4D4`); the next line's opening quote then closes the string and its text is read as code. The same mechanism as the save-file case above.
**Fix:** put the quote back: a string line that lost it before `,` (`。,` -> `。",`), the private-use character -> `"`; load the object (`scripts/lpc_listcheck.sh`). Full-width punctuation typed in code (`，` `；`) becomes its ASCII twin. When the file survives intact in a sibling lib, take the quote from there (`qingyi-jian` has six intact copies).
**Detection:** `scripts/lpc_scan_high_bytes.py [SLUG...] [--summary]`; it masks `@TEXT` here-docs, because a `"` in ASCII art flips a plain mask for the rest of the file and makes every later string look like code. What is left after these families is damage every copy of the archive carries (`d/dntg/sky/npc/yuhuang1`: a file stripped of every quote and semicolon, 19 libs) or not code at all (ASCII maps, the encrypted `clone/obj/job.sav`, binary dumps named `.lpc`).

**Second round (2026-10-19): `d/yixing/doc/set_bang.h`, nine libs.** Lines 82 and 84 (`ob->set("inquiry/" + "帮主", "我对我们" + name[0..01] + "帮主的景仰之情<garbage>);`) lost the closing quote with the last half character, so the next line's quote closed the string and its Chinese text was read as code (`Illegal character 0xe8`): the Yixing gang leader `d/yixing/npc/bangzhu.lpc` never loaded in hhsj, nitan170911, nitan6, nt6, nt6nitan6win, xfbhh, xiakexing100, xkx100 (and a wizard copy in shenzhou). The scanner had skipped `/doc/`, but in the xkx family `d/*/doc/*.h` are code headers: `lpc_scan_high_bytes.py` scans them now. The intact text was in nt7 (a gitlink lib, never part of the sibling comparison): when a lib's damaged file has an intact copy in nt7, xkx100utf8, sanguozhi or nightmare3, take the text from there. Once the file compiled, the real warnings of the header surfaced (a float stored in an int, `info_*.h` without include guards in xkx100 and xiakexing100, a `clean_up()` overlap in `bangzhu.lpc`: KB 04 6.10).

**Third round (2026-10-19): the opening quote too, punctuation of any kind, the end of the file.** A lost *opening* quote has the same effect (`d/quanzhen/hudi6.lpc`, 17 libs: `set("long",` then `\t\t这里是小湖底，...` with the quote gone, the string closes where the text ends and the text is code), as does a quote lost before `,` (`"action" :"$N牵着MM的手，...一式,`) or before the next line's `+` (`feature/vendor_sale.lpc`), and the conversion dropped `;` `,` `)` `}` as well. Count the damage by the driver, not by the scanner: 930 files in 137 libs fail with `Illegal character 0xNN` (the scanner flags 558 of them: its mask is fooled the same way as the eye), and a lost `;` or `}` shows only as `syntax error` (16,583 files with a syntax-type error in 238 libs, most of them in wizard and backup directories or archive losses).
- `scripts/lpc_restore_from_twin.py (SLUG... | --list FILE) [--any] [--extra N] [--diff] [--apply] [--backup DIR]` compares a damaged file with the file at the same path in every other lib that has no raw byte in code and whose own scan did not fail on it, ignoring white space (a copy that went through the formatter still matches); when the damaged file is the donor's code *minus a few short runs* the runs go back where the donor has them (attached to the character before for a `;` `)` or closing quote, before the next one for an opening quote or a `}` on its own line). Only runs of `; , ( ) { } [ ]` `"` or the last letters of a keyword (`els` -> `else`) are taken: a donor that differs by `/* */`, `:1` or a letter is another version, not the same file after damage. The result is the donor's code character for character, and every one-line string literal that differs from the donor's only by white space (the formatter's `/ d / eastland / data`) takes the donor's text (`--refine`). `--tail`: a file that ends in garbage (`locate_quest(this_player(), arg  厀) 鲦 ~m #  烎`) takes the donor's end from the point where the two stop agreeing. 271 files in ~100 libs (hudi3-6, guxing-sword, `fyue_room`, `qlist3`, `huang`, `zhengmen`, `jiang`, `bowl`, `sunguanshi`, `shuijingqiu`, ...).
- `scripts/lpc_fix_eaten_quote.py --comma`: a line that ends in text and `,` gets its closing quote when the next line starts like the next entry (`"force"`, `]`): 39 files (the skills `kunlun-zhang`, `emperor-unarmed`, `awenzhang-unarmed`, `qingyi-jian` of the nested hy copies, quest tables). The same lines inside a `/* */` block (`jueqingbian.lpc`) are left.
- `scripts/lpc_fix_eof_braces.py`: a file that stops one or two `}` short (160 + 32 in the corpus), braces appended with the file's line ending when parentheses balance and the last code character is `;` or `}`: 113 files.
Every tool changes only files that fail; after each run the files went through `scripts/lpc_listcheck.sh` at HEAD and in the tree and the ones that did not go from FAIL to PASS were put back (14 of the twin and comma files, 46 of the brace files: another error remains behind the first, or the file was already fine). What is left (930 - 271 - 39 and the syntax-only ones): a different version of the file at every donor, a lost half character with no donor, garbage in the middle, a file stripped of every quote and semicolon (`d/city/sj.lpc`, `yuhuang1`), files that are not code (`clone/obj/job/func.lpc` is a documentation text named .lpc); done by hand when the object matters, otherwise listed in the queue file.

**Fourth round (2026-10-19): a variant of the intact copy, lost runs close together, a statement moved (`feature/vendor_sale.lpc`, 14 libs).** The player-shop mixin of the `xiaoer` NPC (`kungfu/class/xiake/xiaoer`, one per lib; jhfy, jhfy2, jhfy3, xyzx, xyzx3, xyzxfk, xyzxfy2, xyzxiiylzymh, xysylmhb, yzxiiizylfy, bixiecanyang, hc, ffxymud, xajhzcjh) lost the last character of about 160 lines from `pay_back` on (`;` `)` `{` `}`, `els` + `e{` for `else {`, `ms` + `g` for `msg`), and one line, `if(wizardp(who) || getuid(who)==owner_id)`, sits spliced into a `log_file(` call 700 bytes before the `do_status` block it opens. The only intact copies (ldtx, ldtxii, xhcii, syxjl, hy3) are another version: they lack the author's bid announcement (`string mesg;`, `mesg = ...; message("channel:chat", ...)`), so the donor's code is not the damaged file's code plus punctuation and the greedy tool refuses it. `lpc_restore_from_twin.py --diff --extra N --any-run`: the alignment comes from a diff of the white-space-free texts (difflib, common beginning and end trimmed) instead of the 12-byte resync window, so runs that sit closer together than the window (`els` + `e{`, `ms` + `g` + `]);`) are found; text the damaged file has and the donor lacks stays as it is (a stretch of at most N bytes, printed by `--verbose`: `string mesg;`, the announcement), only what the donor has and the file lacks goes back. Two edits by hand before the tool, because they are not lost punctuation: the spliced `if(...)` goes back in front of the `write("\n盈利` line the donor has it at, and the `"channel:chat", ` that was typed as the first argument of `message_vision(string, object, object)` (a runtime error on every `bid`, after the bidder's money is taken) is dropped. Result: the feature and `xiaoer` load in all 14 libs, no warning, the code is the donor's plus the two extras (checked per file by removing the extras from the squeezed text). Three fixes to the tool came out of it: a run is split where the donor's comment ends (a `}` that was a line of its own, behind a comment line that lost its `;`, was attached to the comment and the function never closed: runs inside a comment stay in it, code goes before the next code character), runs at one offset merge in order, and `main()` had overwritten `tail` (the `--tail` flag) with the donor's path, so after `--tail` was added the greedy pass and `--refine` never ran (`--tail` results only); the part-16 files had been restored before that, 39 of 40 sampled reproduce byte for byte with the fixed tool (the 40th is the `jueqing-chenfa` file put back on purpose).
**Donors under another path (2026-10-19):** `--by-name` takes, when no lib has the file at the same path, the twelve same-named files nearest in size anywhere in the corpus (a lineage moved the file: xajh2's `system/skill/misc/taizu-quan.lpc`, whose intact copy is xo_final's `system/skill/unarmed/level2/taizu-quan.lpc`; the two lost quotes were put back by hand from it). Over all 3,389 failing files with a syntax-type first error (shadowgate and sunshadow aside) it found five restorable files, two of them the hymud skills `huanhe-dao` and `kunlun-zhang` (hy5's copies; the local variable declarations the donor lacks stay as `--extra` keeps them and the warning rows of the newly loading objects take them out), and three `zoulang_1.lpc` rooms that still failed their load check and were put back: the damage that is left is not "an intact copy under another path".

### 4.7 NUL bytes and raw GBK bytes in a source: UTF-16 files, blanked files, octal escapes, a NUL inside a string (2026-10-19)
**Symptom:** `Illegal embedded NUL byte (0x00) in source` (the lexer stops at the first NUL) or `Invalid UTF8 codepoint in string literal`; the object never loads and nothing else is printed: the hy family's Hangzhou escort NPC `d/hangzhou/npc/tangzi` (6 libs), xkxyb's `guanjia` / `jiading` / `wolfdog`, xkx100's Shenlong island rooms `d/shenlong/{jushi,sea,sea2}` (5 libs; the reach census from the start room does not meet them), mhxy's `cuixin` skill and `yuanpinzhu`, shenmo's `dugu-jiujian`, `d/sky/npc/zz-tianwang` of xyj2000 and xyj2000f.
**Cause, four shapes:**
- The file is UTF-16 (a NUL between all characters). Ten files are nothing but UTF-16 spaces: the author blanked the object (713 spaces for `tangzi`) and the old driver compiled an empty program. `scripts/lpc_fix_utf16.py`: blank -> one line break (an empty program again; the intact twin NPC of xkx100 is *not* copied in, the blanking looks deliberate), real UTF-16 text -> UTF-8 when it decodes cleanly. Left alone: a blank prefix with a few shifted bytes of code behind it (shenmo and three copies, `u/stey/u/vikee`), fy2mg's wizard copy of `attack.c` (big-endian ASCII that changes byte alignment at its first Chinese comment), binaries that kept their `.lpc` name.
- GBK bytes written as octal escapes in a string (`"\241\243"` = `。`), legal for the old driver, which sent the bytes to a GBK client: replace the escape pair by the character.
- A half character became a NUL (`"...接着\0:"`, `"$n\0?l"` for `的$l`, a garbled run behind a NUL in `dugu-jiujian`): take the text from an intact sibling (`dugu-jiujian` has copies in cctx, bxsj, chidi ...), else delete the NUL.
- A file the conversion skipped (raw GBK) whose tail is an `iconv` message (`iconv: incomplete character or shift sequence at end of buffer`): convert the intact part and end the function like the sibling copies (`zz-tianwang`, byte for byte the sibling's last three lines).
**Detection:** `git grep -l -a -P '\x00' -- 'libs/*/work/*.lpc'`; a strict UTF-8 decode of every tracked source (27 files in the corpus, 22 of them the encrypted `clone/obj/job.sav` / `jobaa` groups of bmxkx2001, xkx2001, xkm, shenzhou and `d/city/weapon/weapon-{2,3,4}.lpc` of the bxsj family, which are binary and stay); `git grep -c -a -P '\\[23][0-7][0-7]'` for octal escapes above `\200` (`clone/misc/tang.lpc` of the bxsj family writes a telnet negotiation that way on purpose and stays).

## 5. Config files

### 5.1 Format

The `key : value` format is unchanged (canonical example:
`~/src/fluffos/testsuite/etc/config.test`).
- Convert the encoding first.
- Point `mudlib directory` at `libs/<slug>/work`.
- Assign a unique port.
- Prune keys the driver rejects.
- Never trust the shipped absolute paths or `name:`; they are often
  copy-pasted from other muds.
- The driver prints a message for every key it does not take, and every
  one is a fix (2026-10-04 sweep: 371 messages in 277 configs, none left).
  `python3 scripts/lint_configs.py [SLUG]` prints them (it parses a copy of each config whose `mudlib
  directory` is an empty scratch dir; running `lpcc config.fluffos` inside `libs/S` boots the lib in place and
  rewrites tracked save files):
  `*Warning: obsolete line in config file, please delete:` (`address server
  ip/port`, `binary directory`, `reserved size`, `swap file`, `wombles`,
  `warn tab`: delete the line and the comment above it);
  `living hash table size: invalid new value` (must be 4, 16, 64, 256, 1024
  or 4096: the old generator wrote `100`; `docs/driver/config.md` has the
  minimums of `hash table size` 7001 and `object table size` 1024); and
  `external_port_1 already defined ... by the line 'port number : N'` (the
  `port number` line is the telnet port, so a second `external_port_1 :
  telnet N` is ignored: delete it). Every invalid value was already being
  reset to the default, so the fix keeps the effective setting.
  `scripts/lib_write_config.py` writes new configs without them.

### 5.2 `log directory` resolves against the launch CWD

Always launch with `cd libs/<slug> && …/driver config.fluffos`. See also
§10.9: debug.log can be silently dead under this convention.

### 5.3 Ports hardcoded in mudlib source

A `MUD_PORT`/`PORTNO` constant checked in `master::connect()` rejects
every connection when it doesn't match: the log looks clean, but the
server is dead (`huoying`, `dfgsiiv13b`). Read what the constant gates.
Some are cosmetic only.

### 5.4 `call_out(0) nest level : 10` copied from the testsuite config (2026-10-15)

**Symptom:** a multi-stage perform (`call_out("perform2", 0, me, target)`) dies with `Nesting call_out(0) level limit
exceeded: 10` on a busy server, or in any batch that runs many performs in one tick. **Cause:** the driver counts every
`call_out(0)` scheduled in the same gametick across the whole game (`src/packages/core/call_out.cc`), not the depth of
one chain. `testsuite/etc/config.test` sets 10 to exercise that guard, and configs built from it carried the 10 into
MudOS-era games that had no such limit (nitan3, nitan_san, nitan170911, nitan_ceshi, 100 ms gameticks). **Fix:** the
driver default, 1000. Keep a value the lib's own FluffOS config chose (aoxiangtianji's 2019 `config.cfg` sets 10).
**Detection:** `grep -h 'call_out(0) nest level' libs/*/config.fluffos`, then check the raw config.

### `T array a, b` became `T * a, b`: only the first name stays an array (2026-10-05)

**Symptom:** a variable that should hold an array is declared as a plain type. Most of the time nothing shows, because the driver does
not enforce local types at run time. A global restored from a save file is different: nightmare4's finger daemon read the player's
`Religion` as a string, so `Religion[1]` was a character code and every finger said `Agnostic`; the scan reports
`Types in ?: do not match ( int vs string )`. **Cause:** in MudOS `array` belongs to the type (`string array a, b` makes two
arrays), while `*` belongs to one declarator. A conversion that rewrote `array` as `*` starred only the first name.
**Fix:** star every later name. **Detection:** compare against raw/ (`scripts/lpc_array_decl_scan.py [slug...]`, which needs raw/
extracted). Found in nightmare4 (4: `Religion`, `send_to`, `fun`, `ots`), sgzmudsgz (`nation_menu.lpc` x4) and swmud (1).

### A Latin-1 lib decoded as GB18030 (questmud, 2026-10-05)

**Symptom:** Finnish text turns into CJK (`ensimm鋓nen paikka on tyhj`), and an odd high byte swallows the ASCII byte after it,
often a space or a closing quote, so strings never end, save files fail `restore_object()` (`surname "牋牋`), and aliases lose
their keys. **Cause:** the onboarding transcoded a Latin-1 archive with the Chinese default. **Fix:**
`scripts/latin1_misdecode_repair.py SLUG [--apply]` aligns work lines with the raw ones and replaces a line by its true
Latin-1 decoding only when the two ASCII skeletons differ by nothing but bytes deleted next to a high byte (an edited line is kept).
Run it on save files *before* converting their mappings. **Detection:** a non-Chinese lib whose work tree has CJK characters
(`grep -rlP "[\x{4e00}-\x{9fff}]" libs/SLUG/work`); a raw file that is not valid GB18030. pd (2026-10-06) is Windows text:
`--encoding cp1252` (smart quotes `’`); its LPC textbook chapter is Mac Roman (`0xD5` = `’`, not `Õ`). Check what the repair
adds before committing: tally the new non-ASCII characters per file, and revert a file that really was GB2312 (full-width
spaces `A1A1` in ASCII art came out as `¡¡`). For lines the script keeps because they were edited, a CJK character whose
GB18030 second byte is ASCII maps back to `cp1252(first byte)` plus that byte (`抯` -> `’s`). cp437 block art in old letters stays.

### `\` + CR CR LF: a doubled DOS conversion ends macros and strings early (holymission, 2026-10-06)

**Symptom:** a multi-line `#define` stops at its first line (`syntax error, unexpected L_IF` in the header that uses it), and
a `"...\` string continuation keeps a CR and a hard line break mid-description. **Cause:** the archive went through CRLF
conversion twice (`\r\r\n`); the lexer joins `\` + `\r\n` but takes `\` + `\r` as an escape. **Fix:** drop the extra CRs
after an odd run of backslashes, outside `@`/`@@` text blocks (ASCII art there ends in `\` on purpose). **Detection:**
`grep -rlP '\\\r+\r\n'`; 170 files in holymission; the Chinese hits (help.h in five xyj/sjpl libs) sit inside `/* */`.

### LDMud save files: multi-value and width-0 mappings (questmud, 2026-10-05)

`([k:v1;v2;v3])` (wide), `(["a","b",])` (width 0, a key set) and `([:5])` (empty, width 5) do not parse in FluffOS, so a player
file, mail folder or daemon save holding one never restores. `scripts/ldmud_wide_save_convert.py [--apply] FILE.o...` rewrites
them as `([k:({v1,v2,v3})])`, `(["a":1,"b":1])` and `([])`, the layout of the ported code (`m[k][N]`, `m[k] = 1`); the code that
writes them needs the same change (`m[k, N]` -> `m[k][N]`, `m += ([ k ])` -> `m[k] = 1`, `m -= ([ k ])` -> `map_delete`).
Check with a probe that calls `restore_variable()` on every saved value.


### LDMud save files: `\n` in a string restores as a literal `n` (questmud, holymission, 2026-10-06)

**Symptom:** board posts, mail and player descriptions from old saves print `nn Sehän on…!!!n`: every newline is an `n`.
**Cause:** LDMud's `save_object()` writes a newline inside a string as the escape `\n` (a tab as `\t`); FluffOS writes a
raw CR byte instead, and its `restore_object()` turns any `\X` into a plain `X`. **Fix:**
`scripts/ldmud_save_newlines.py [--apply] PATH...` rewrites, inside quoted strings of files with LDMud's `#N:M` header,
`\n` to a CR byte and `\t` to a tab (`\"` and `\\` mean the same in both drivers). A `\r` cannot be kept: a raw CR restores
as a newline. **Detection:** `\n` escapes in `.o` files that start with `#N:M`; only questmud (41,888) and holymission
(72,364) have them. Many `.o` files in the Chinese libs are LPC sources with a `.o` name; ignore them.
LDMud saves can also share a value: `<1>=({})` defines it and a later `<1>` in the same file refers back; FluffOS stops with
`restore_object(): Illegal array format` (holymission's 40 player houses). `ldmud_wide_save_convert.py` expands each reference into a
copy (`grep -rlP '[,(\[:]<\d+>' --include='*.o'`; only holymission has them).

A related trap in the same saves: the 2026-10-05 Latin-1 line repair skips a line that was changed later, and a save line
whose mapping was converted counts as changed. Rebuild such lines from `raw/` by emulating the bad decode exactly (a
GB18030 pair, or an invalid pair dropped together with the byte after it); replace a work line only when it equals that
emulation, then run the same mapping conversion on the correct decoding.

### A file the conversion skipped hides behind a wrong-line warning (yszz, dtxyzjb, 2026-10-11)
**Symptom:** a warning or error reported at a line that has nothing wrong (yszz `xuerengui.lpc:66` "no side effects" on a plain declaration), or Chinese text shown as mojibake. **Cause:** one `.h`/`.lpc` stayed GBK through `convert_lib.sh` (a trailing junk byte made the whole-file decode fail); GBK bytes inside string literals derail the lexer of every file that includes it. **Fix:** decode that file as GB18030 (drop trailing junk first) and re-check. **Detection:** a strict per-file `iconv -f UTF-8 -t UTF-8` over every `.lpc`/`.h` (2026-10-11 corpus: 28 files; 2 were real GBK, 26 binary dumps or truncated archive copies with NUL bytes or garbage tails, left as is).

- **Private-use characters on blank code lines** (2026-10-14). Lines holding only U+F8F5 (or another U+E000-U+F8FF character), left by the GBK conversion. The first error is `Illegal character 0xef` (or 0xee), at column 1. Blank those lines when they are code, but not inside strings, comments or `@` here-documents (fy2's `to.lpc` keeps one in its help text). This made 96 of xyxyutf8's 99 files load. PUA bytes mixed into otherwise unreadable text are encrypted files read as text (xkm's `clone/obj/job*`): leave them.
