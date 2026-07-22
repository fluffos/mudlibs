# xiakexinzhuan2 — 侠客新传 (New Legend of the Wandering Swordsman)

Archive: `侠客新传(2).rar`. Port: 40035. Status: **done** (boots clean
and quick, full registration flow verified end-to-end including a real
Chinese name).

## What this is

"「侠客新传」" v0.1b, credited to "Xkxz MUD Wizard Group",
http://xkmud.yeah.net. `config.cfg`'s leftover `MUD_NAME` field still
says "海洋II上海总站" ("Ocean II Shanghai Main Station"), suggesting
this was forked from a 海洋II codebase base and rebranded — but the
actual game per its own connection banner and `游戏说明.TXT` readme is
"侠客新传". Same "Century-family" `adm/single/{master,simul_efun}`
layout as `shiji`/`zhonghua2`/`shujian2008`/`shujianpiaoling2`/
`xianjianchuanqi`. ~7,613 raw files, 6,903 after `.c`→`.lpc` rename.

## Fixes applied

1. **AGENTS.md §15h**: `is_chinese()`'s two-specific-byte GBK check →
   single-character CJK codepoint check. `check_legal_name(string name,
   int maxlen)`'s internal bound `strlen(name) < 2` → `< 1`, and the
   call-site `maxlen` argument (`check_legal_name(arg, 8)`) halved to
   `4`. Note: `is_chinese(name)` here is called on the WHOLE name string
   directly, not per-character in a loop — since `is_chinese` itself
   only ever examines the first character, this means even the
   ORIGINAL GBK-byte-era code only ever validated the first character
   of a multi-character name (a pre-existing permissiveness quirk, not
   something introduced or fixed here beyond making `is_chinese` itself
   correct under UTF-8).
2. **Deep `named.lpc` fix**, same nitan-family shape as `zhonghua2`/
   `shujian2008`: `PATH(name)` macro `name[0..1]` → `name[0..0]`, five
   `strlen(name) < 2` guards → `< 1`, `invalid_new_name()`'s combined
   check `strlen(name) < 4` → `< 2`, sliding-window similar-name
   detection `name[i..i+3]`/`name[i..i+5]` → `name[i..i+1]`/
   `name[i..i+2]` with adjusted loop bounds (`i <= l - 4` → `i <= l -
   2`, `i + 6 <= l` → `i + 3 <= l`).
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively **before the first boot
   attempt**. Booted clean in under 15 seconds, zero compile errors, no
   hang — the policy continues to work as intended.

## Testing gotcha (not a mudlib bug — a scripting trap for future retests)

This lib's connection has an **"Are you using BIG5 font [Y|N]?" prompt
right at the very start**, before the main banner even renders — visually
it blends straight into the connection output with no obvious blank
line or distinct prompt marker, making it very easy to miss when
scripting a `mudclient.py` test. The first `--send` answers THIS prompt,
not the English id. Missing this caused several confusing cascading
"必须是3到8个英文字母"/"只能用英文字母" rejections in early testing
(each subsequent `--send` value was shifted one slot into the id/
password fields, none of which matched their respective validation
rules) before the actual cause was traced. **Lesson reinforced**: when a
registration test produces confusing cascading rejections, first
re-verify with ONE input at a time and read the FULL transcript
carefully for any prompt that might have been missed, before suspecting
the fix logic itself is wrong.

## Interactive test result — full registration flow

Verified the complete registration path in one continuous connection:
BIG5 answer `n` → id `xkxzd` → confirm `y` → password `Pass1234` (twice)
→ **real Chinese name `秦风`** (avoiding "中神通" — a real Jin Yong
character found in this lib's `banned_name` list) → accepted, proceeds
into character-archetype selection (猛士/智慧/耐力/敏捷/均衡 type
prompt).

## lpcc sweep

6,903 files, 6,715 pass / 188 fail (97.3%). Failure tail is the usual
shape (a `set_information` type-mismatch cluster, several `nomask`
function redefinition conflicts, missing `skillN`/`set_ghost` globals)
— not triaged individually per AGENTS.md §6b/§13. Memory stayed healthy
throughout (~13GB free).
