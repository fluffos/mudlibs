# Suggestion-issue triage (2026-11-10)

GitHub token is read-only (`gh issue close` / `comment` → Resource not accessible).
Decisions below are verified in-tree; human must close/comment on GitHub.

## Done / ready to close

| # | Title | Decision | Evidence |
|---|---|---|---|
| 16 | TMI-3 Alpha | **Onboarded** `libs/tmi3/` (187, port 40392) | Boot + register + look(void) + quit + relogin. NOTES.md. Distinct from tmi2/lpuni. |
| 7 | Diku Alfa → Dead Souls | **Already covered** by `brassring` (963) `domains/diku-alfa/` | Same conversion line; playable. Archive URL kept in issue thread. |
| 21 | txmud / 天下MUD | **Duplicate** of `tianxia` (034) | NOTES: identical master ACL, 47-entry `d/`, wizard list. |
| 20 | ZHLib / 中华英雄 | **Superseded** by `zhyx` (931) | ZHLib = older/smaller 2006 snapshot; zhyx is live FluffOS line. |
| 19 | YHLib / 炎黄2003 | **Queue onboard** as lineage base | Same 70 `d/` domains as yhyxs but adm sources differ (0/50 hash match). MudRen/YHLib is the labeled 2003 base the derivatives descend from; not yet a museum row. |
| 17 | Fading Summer | **Decline** unfinished Lil alpha | Archive verified. Boot reaches Accepting connections after stubs, but login requires inventing SHELL_D, fixing original syntax bugs in logon_d/newuser_d, missing banners/daemons. Not museum-complete without rewriting the lib. Distinct-from-lil layout exists but content is incomplete. |
| 18 | OSB | **Covered in spirit** by `aoh` (976) | aoh is OSB-based LDMud→FluffOS playable. Full 2003 OSB tarball verified (5.3 MB); defer full second OSB row unless user wants the historic parent as its own number. |
| 14 | CISTOMS | **Decline for now** | SF CVS snapshot is RCS `,v` only (checked out 121 `.c` under testsuite/). Abandoned MudOS testsuite fork; low museum value vs effort. |
| 25 | MofN | **Defer** | CVS snapshot verified; MudOS+MySQL auth design → likely `noboot` without MySQL (realms precedent). |
| 29 | SWLPC 0.9.1 | **Defer (LDMud)** | Archive verified (341 `.lpc`). Amylaar-style (`array`, `reset(arg)`). Needs LDMud→FluffOS campaign, not a quick MudOS bring-up. |
| 22 | NannyMUD lib | **Defer (historic LDMud/Amylaar)** | `nannylib.tgz` from lysator verified. Classic; queue with other Amylaar ports. |
| 28 | Heaven7 | **Defer (compat/Amylaar)** | Inner mudbytes archive fetched & verified (470 `.c`, readme: Amylaar 3.2 compat / 2.4.5 root). Prefer Amylaar/compat port campaign; not a same-day FluffOS native bring-up. |
| 23 | Silberland | **Defer (LDMud/German)** | URL reachable (codeberg); LDMud family. |
| 24 | Tamedhon | **Defer (LDMud)** | codeberg td-mudlib; open-source part only. |
| 26 | UNItopia | **Defer (LDMud)** | Wayback mudlib.tar.gz verified in issue comment (516 `.c`). |
| 13 | Older Dead Souls point releases | **Defer / optional snapshots** | Museum already has dsI/II/III/ds386 stack (006*). Extra point releases are provenance-nice, not required for playable coverage. Wayback links in issue. |

## Out of FluffOS host scope (DGD)

Museum driver is FluffOS. These need DGD; do not onboard as playable FluffOS rows. Archives verified where noted:

| # | Lib | Notes |
|---|---|---|
| 8 | Hexagon | DGD MudOS-alike (`maldorne/hexagon`) |
| 9 | Phantasmal | DGD Kernel; Wayback tarball noted in issue |
| 10 | GurbaLib | DGD; MudRen + Wayback snapshots |
| 11 | Kotaka | `kotaka.dgd` in archive (verified download) |
| 12 | Leprechaun | DGD; GitHub mirror has LICENSE |
| 15 | Windfall | DGD Kernel pre-alpha zip verified |
| 27 | LPMOO | DGD LambdaMOO reimpl; mudbytes inner tar fetched |

## Next onboard queue (when resuming)

1. **YHLib** (`MudRen/YHLib`) — FluffOS-dialect Chinese base; clone already at `/tmp/issue-archives/YHLib`.
2. Heaven7 — Amylaar/compat port (archive on disk).
3. NannyMUD — lysator tarball on disk.
4. SWLPC — LDMud port.
5. Optional: full OSB parent beside aoh; DS point-release provenance packing.

## Token note

Ask a human with write scope to close #16/#7/#21/#20/#19/#17/#14 and the DGD set with the table rationale above.
