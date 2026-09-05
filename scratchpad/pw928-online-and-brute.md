# 928/929/932 password hunt (2026-09-05)

User: published/dictionary patterns are unlikely; search the archive
names online; brute-force if needed.

## Online / name hints (fresh pass)

Exact filenames `duobao.7z`, `nitan.7z`, `谁与争锋.7z` still only
appear as this repo’s README rows. No Baidu/lanzou listing, no
extract code, no forum “密码xxxx”.

| Name | What the name actually is | Public source? |
|---|---|---|
| `duobao.7z` | leftover dump name; a live LPC toolkit (`serenez/lpc-server-update`) uses `C:/mud/duobao` as an example path only | no public mudlib tree |
| `nitan.7z` | labeled 加密版; unrelated to already-open `nitan6` / `nitan7` / `nitan170911` | no |
| `谁与争锋.7z` | also a 2000s LPC wizard nick (谁与争锋 / 叮当) and a 2023 mobile MUD (`com.syzf.mud`). Neither publishes this 7z. MudRen/zjmud is 指间争锋, a different game. | no |

They sit in the leftover RAR extract
(`~/.claude/jobs/02c1e635/tmp/mudlib_rar_extract/mudlib/`) with no
readme. Same-day 7z siblings from 2026-02-14 (`hell.7z`,
`nitan170911.7z`, `zjmud.7z`, `地狱源码.7z`, …) are **unlocked**.
The one other locked sibling, `武林群侠传MUDLIB.7z`, had a plaintext
GBK trailer `解压密码： mud.ren` and is already onboarded as
`wlqxcmudlib`. These three trailers are ciphertext — no printed
password. `mud.ren` / `111` / `kvm6` / site names already fail.

## Attack change

Rockyou dictionary was ~57% @ 0/3 when stopped (user: known lists
won’t hit). Session `pw928ry` restore left in place; do not resume
unless asked.

Mask brute started in tmux `pw928-hashcat` via
`~/.cache/pw928/brute_run.sh` (not in git). ~3270 H/s, 3 salts,
7-Zip `-m 11600` cost 2^19. Planned stages:

1. `?d` length 1–7 (~3 h)
2. `?l` length 1–5 (~3 h)
3. `?l?d` length 1–4 then 5 (~15 h for len 5)
4. mixed alnum exactly 4 (~4 h)
5. `?h` length 1–8 (~7 h)
6. `?d` length 8 (~25 h) last

Unconstrained 5+ mixed-case alnum is days-to-weeks at this rate; not
queued. Do not start a second hashcat. Do not commit hashes / pot /
rockyou / recovered plaintext.

## hkmud.com (user hint, 2026-09-05)

Live **香港群俠傳** wiki + telnet (`hkmud.com:8888` UTF-8 / `:5555`
BIG5 / `:6666` GBK). Admin vbman says the current mudlib is **泥潭6**,
not the old 香港金庸群俠傳. Wiki **奪寶** is an in-game treasure-hint
page (大刀, 正氣訣, …), not a source pack and not `duobao.7z`.

Public code: `HKMUD/NT6` (`name : 笑傲江湖`) — same game as collection
`nitan6`. Also `HKMUD/wiki_archive` (dokuwiki data) and a fluffos
fork. `/download` `/src` `/mudlib` are empty wiki stubs. No 7z on the
org. Site-name candidates (hkmud, hkmud.com, 香港群俠傳, vbman, NT6,
奪寶, …) do **not** open 928/929/932. Do not onboard NT6 again.
