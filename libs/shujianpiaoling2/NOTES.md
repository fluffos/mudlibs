# shujianpiaoling2 — 「书剑飘零」Ⅱ ("Stray Book & Sword" II)

Archive: `书剑飘零II .zip`. Port: 40031. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese
name).

## What this is

"【书剑飘零Ⅱ】", English tagline "Stray Book & Sword", credited to
"飞白工作室" (Feibai Studio), http://sjpl.sq.sh.cn. Mudlib root at the
archive top level (`config.wd` at the root, not nested in a subfolder).
Uses `adm/obj/{master,simul_efun}` — despite the similarly-named "书剑"
title, this is a genuinely **different, unrelated codebase** from
`shujian2008`/`shujiantianxia` (archives #35/#36, `adm/single/` layout):
different directory convention, no `named.c` daemon, and a `securityd.c`
with different internal logic. Don't assume shared lineage from a
similar Chinese title alone — always verify via layout/file diff.
~13,022 raw files, 12,349 after `.c`→`.lpc` rename.

## Fixes applied

1. **AGENTS.md §15h (GBK byte-range Chinese detection)**, standard
   shape: `adm/simul_efun/chinese.lpc`'s `is_chinese()` (GBK lead-byte
   range → CJK codepoint range) and `adm/daemons/logind.lpc`'s
   `check_legal_name()` (byte-count bound `< 2 || > 12` → character-count
   bound `< 1 || > 6`, removed the `i%2==0` even-byte-offset gate). The
   `name[i..<0]` slice syntax was already a clean single-character-to-end
   slice — no change needed there, unlike some other libs that used a
   multi-byte suffix relying on `is_chinese` reading only the first 2
   bytes.
2. **Proactively added `get_include_path()` to `master.lpc`** (the
   standard §15o/§8d shape) as cheap insurance, even though this specific
   symptom was never actually observed — the lib booted clean and the
   full registration flow worked without it being strictly proven
   necessary. Left in as prophylactic protection for any future
   mid-connection lazy compile.
3. **Confirmed NOT needed, verified via source reading rather than by
   hitting and diagnosing a crash**:
   - **§4** (lazy security-daemon load): `master.lpc`'s
     `valid_write`/`valid_read` already gate via `find_object(SECURITY_D)`
     only (no unconditional `load_object`).
   - **§15n** (custom-securityd func-discrimination gap): this lib's
     `securityd.c`'s `valid_read` does NOT override the `user` parameter
     with `this_player()` (unlike `shujian2008`'s), so compile-time reads
     (which the driver attributes to `master_ob`, per
     `check_valid_path(..., master_ob, "load_object"/"include", ...)`)
     see `master_ob`'s own euid — presumably Root — and hit this
     `securityd`'s early `if (euid==ROOT_UID) return 1;` check before any
     directory-based ACL is even consulted. Confirmed by reading the
     source rather than needing to reproduce the crash first, per the
     lesson learned on `shujian2008`.

## Interactive test result — full registration flow

Verified the complete registration path in one continuous connection:

1. `sjplbtest` → passes `check_legal_id`, reaches the "确定吗(y/n)？"
   confirmation.
2. `y` → reaches the Chinese-name prompt.
3. **Real Chinese name `秦风`** → accepted (no rejection message),
   proceeds straight to "请设定您的密码：" — the actual proof the §15h
   fix works. No novel-character-name restriction found in this lib's
   `banned_name` list (unlike `shujian2008`) — just game-title words
   ("书剑", "书剑飘零", "飘零", "飞白") and pronouns.

## lpcc sweep

12,349 files, 11,772 pass / 577 fail (95.3%). Failure tail is the usual
shape (a large syntax-error cluster, missing `MONEY_D`/`prepare_skill`
globals, a handful of type-mismatch returns) — not triaged individually
per AGENTS.md §6b/§13, boot + full interactive registration test is the
verification gate. Memory stayed healthy throughout (~15GB free
consistently, no pressure).
