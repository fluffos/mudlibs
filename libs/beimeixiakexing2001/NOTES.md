# beimeixiakexing2001 — 侠客行 (The Quest of Oriental Chivalry, North America 2001 build)

Archive: `北美侠客行2001.rar`. Port: 40039. Status: **done** (boots
clean, full registration flow verified end-to-end including a real
Chinese name).

## What this is

"侠客行" / "The Quest of Oriental Chivalry", credited to "XiaKeXing
Gaming Group 1996-1999", MudOS v22b25. Confirmed via `diff` to be the
**same codebase lineage as `xkx2001`** (archive #25, already done):
`adm/simul_efun/chinese.c` and `adm/single/master.c` are byte-identical;
`adm/daemons/logind.c` differs by only a single commented-out IP address
line. However, many peripheral `clone/`/`cmds/` files genuinely differ
— a real, evolved snapshot at the content level, not a byte-identical
archive duplicate — so it still needed its own conversion/boot/test
pass, just with the core registration-path fixes already known.

## Fixes applied

1. **AGENTS.md §15h**: `is_chinese()`'s standard GBK lead-byte check →
   CJK codepoint check.
2. **Ported directly from `xkx2001`'s already-proven fix**:
   `check_legal_name(string name, object ob)` had the exact same
   byte-shift "auto-correct" hack (`name[j]+=128; name[j+1]+=128;`,
   meaningless against Unicode codepoints) — replaced with
   straightforward rejection, matching `xkx2001`'s fixed version
   verbatim. Bound `< 2 || > 8 || i % 2` (byte count + meaningless
   odd-byte rejection) → `< 1 || > 4` (character count).
3. **New instance of AGENTS.md §8e** (`tail` is not a real FluffOS
   efun): `adm/simul_efun/message.lpc`'s `tail(string file)` called
   `efun::tail(file)`. Unlike some other libs where this is a harmless
   dead admin command, here it's **fatal** — this function is compiled
   as part of `simul_efun.lpc` itself, so the compile error
   (`Unknown efun: tail`) took down the ENTIRE simul_efun object,
   which crashed the whole boot (`No program in object
   '/adm/single/simul_efun'!`, `The simul_efun ... and master ...
   objects must be loadable`). Fixed with the standard §8e
   reimplementation (`read_file()` + `explode()` + slice last 10 lines
   + `write(implode(...))`).
4. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. `/adm/daemons/network/http` is ALSO in preload but confirmed
   safe to leave (its socket setup is deferred via `call_out("setup",
   5)`, non-blocking to preload).
5. **Retroactive fix, AGENTS.md §15ae** (added after the original pass
   above — the original registration test here never continued past the
   password prompt, so this was missed): `feature/command.lpc` declared
   its `add_action`-dispatched command hook as `private nomask int
   command_hook(string arg)`. This driver treats `private` as opaque to
   `add_action`'s external dispatch once inherited into the player body
   class, so **every single post-login command silently did nothing at
   all** — no error, no output, indistinguishable from a hung connection.
   Found independently on `xuanjianlu` (archive #70, same underlying
   bug), which flagged this lib as also affected. Fixed by dropping
   `private` (keeping `nomask`). Re-verified with a fresh registration
   (id `hookabcd`, real Chinese name `秦淮`) followed by re-login and
   `look`/`score`, both now producing correct output.

## Interactive test result — full registration flow

This lib has a hidden pre-id prompt: **"Do you want to use BIG5
code?(y/n)"** right after the banner. Verified the complete registration
path in one continuous connection: `n` → id `bmxkxb` → confirm `y` →
**real Chinese name `秦风`** (avoiding "韦小宝"/Wei Xiaobao — a famous
Jin Yong character found in this lib's `banned_name` list) → accepted,
proceeds straight to "请设定您的密码：".

## lpcc sweep

8,145 files, 6,894 pass / 1,251 fail (84.6%). The largest single cluster
(52 failures) is the exact same missing `EDITOR_D` daemon documented in
`xkx2001`'s own NOTES.md (a bulletin-board "compile into archive"
feature, genuinely absent from this archive too — not a typo). The
remaining ~1,199 failures are the usual long tail (illegal-character/
encoding edge cases, syntax typos in individual files) — not triaged
individually per AGENTS.md §6b/§13. Memory stayed healthy throughout
(~12GB free).
