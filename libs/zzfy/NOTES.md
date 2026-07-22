# zzfy — 郑州风云3 (Zhengzhou Fengyun 3)

Archive: `zzfy (full).rar`. Port: 40025. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese name).

## What this is

Same 风云 (Fengyun) lineage as `fy2`/`fy2005`/`fengyun434` (archives #14,
#16, #17) — `adm/obj/master.lpc`/`adm/obj/simul_efun.lpc` layout, same
`adm/daemons/chinesed.lpc` + `adm/simul_efun/chinese.lpc` shape. Mudlib
root at `zzfy/fy3/`, config at `zzfy/config.fy3`. `readme.txt` says this
build ("郑州风云3") is provided by "长孙无情", described as one of the
more stable/established 风云-family sites, admin access via ID `xgchen`.
~10,293 raw files.

Registration flow here is architecturally simpler than the TMI-2/nitan
family processed earlier: there's no separate `new` keyword branch in
`get_id()` — every English id typed goes straight through
`check_legal_id()`, and if no save file exists for it, straight to the
"create new character?" confirmation. `"new"` is itself in the
`banned_id` list (line 20 of `logind.lpc`), so typing literal `new` is
correctly rejected as an illegal id, not a special command — don't
mistake this for a bug when retesting.

## Fixes applied

**AGENTS.md §15h (GBK byte-range Chinese detection)**, applied proactively
before first boot, same shape as the other fengyun-family libs:
- `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte range check
  (`str[0] > 160 && str[0] < 255`) → CJK Unicode codepoint range check
  (`str[0] >= 0x4e00 && str[0] <= 0x9fff`).
- `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count length bound
  (`< 2 || > 12`, "1 到 6 个中文字") halved to character count
  (`< 1 || > 6`); removed the `i%2==0` even-byte-offset gate so every
  character position is actually checked (not just every other one).

**§4 (lazy security-daemon load)**: not needed — `master.lpc`'s
`valid_write`/`valid_read` already gate `load_object(SECURITY_D)` behind
`find_object()` in this build.

## Interactive test result — full registration flow

Verified the complete registration path in one continuous connection:

1. Connect → banner → English-id prompt.
2. `zzfytest` → passes `check_legal_id`, reaches "使用 zzfytest
   这个名字将会创造一个新的人物，您确定吗(y/n)？".
3. `y` → reaches the Chinese-name prompt.
4. **Real Chinese name `萧峰`** → accepted by the fixed `check_legal_name`
   (no rejection message), proceeds straight to "请设定您的密码：" — the
   actual proof the §15h fix works, not just that the prompt renders.

Noted, not a bug: `get_name()` has a pre-existing `printf("%O\n", ob);`
debug line (prints the login object's default toString, e.g.
`/obj/login#0`) that fires right before the password prompt on a
successful name — leftover debug output from the original author,
harmless, left as-is (out of scope for a UTF-8 compatibility pass).

## lpcc sweep

9223 files, 8251 pass / 972 fail (89.5%). Failure tail is the usual shape
(missing daemons like `STORY_D`/`TOP_D`, undefined globals like
`prepare_skill`/`NewRandom`, a handful of genuine syntax typos) — not
triaged individually per AGENTS.md §6b/§13, boot + full interactive
registration test is the verification gate. Memory stayed healthy
throughout the sweep (~17-18GB free the whole time, no pressure).
