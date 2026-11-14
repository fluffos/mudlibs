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
| 19 | YHLib / 炎黄2003 | **Onboarded** `libs/yhlib/` (188, port 40393) | Boot + register(张三) → 世外桃源 + look + quit + relogin. §8.1/MESSAGE_D/is_killing fixes. |
| 17 | Fading Summer | **Onboarded** `libs/fadingsummer/` (190, port 40395) | Boot + register → void + look + quit. Museum stubs for missing SHELL_D/BANISH_D/globals; syntax/precedence fixes. Alpha-only (no world). |
| 18 | OSB | **Covered in spirit** by `aoh` (976) | aoh is OSB-based LDMud→FluffOS playable. Full 2003 OSB tarball verified (5.3 MB); defer full second OSB row unless user wants the historic parent as its own number. |
| 14 | CISTOMS | **Onboarded** `libs/cistoms/` (189, port 40394) | Boot + name → Void; Casimir castle reachable. CVS checkout of testsuite tree. User-named lead. |
| 25 | MofN | **Onboarded as noboot** `libs/mofn/` (191, port 40396) | CVS tree converted; empty `include/` + MySQL `db_connect` auth → `wasm_status=noboot`. |
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

1. Heaven7 — Amylaar/compat port (archive on disk).
3. NannyMUD — lysator tarball on disk.
4. SWLPC — LDMud port.
5. Optional: full OSB parent beside aoh; DS point-release provenance packing.

## Token note

Ask a human with write scope to close #16/#7/#21/#20/#19/#17/#14/#25 and the DGD set with the table rationale above.
