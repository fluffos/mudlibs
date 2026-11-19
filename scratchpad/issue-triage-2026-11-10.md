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
| 18 | OSB | **Onboarded & closed** `libs/osb/` (196, port 40401) | `osb-lib-030218.tar.gz` converted (ISO-8859-1 -> UTF-8, 2417 `.lpc`); Strategy A FluffOS catalog + `/etc/WELCOME` (`mudlibs.fluffos.info` stamp) + `/d/login/entrance` -> Silvere harbour (`quay1_2`, `quay1_1`, `quay1_3`, `ntower_enter`, `shipyard`, `street1..3`, `entrance`, `harbour_inn`, `harbourmaster`); `lpcc --batch` 17/17 (0 warnings, 0 errors); native (`testera`) & WASM (`testerw`) verified. `NOTES.md`. |
| 14 | CISTOMS | **Onboarded** `libs/cistoms/` (189, port 40394) | Boot + name → Void; Casimir castle reachable. CVS checkout of testsuite tree. User-named lead. |
| 25 | MofN | **Onboarded as noboot** `libs/mofn/` (191, port 40396) | CVS tree converted; empty `include/` + MySQL `db_connect` auth → `wasm_status=noboot`. |
| 29 | SWLPC 0.9.1 | **Onboarded & closed** `libs/swlpc/` (195, port 40400) | `mlib-0.9.1.tar.bz2` (GPLv2 core) converted; Strategy A FluffOS catalog + `RO/banner` (`mudlibs.fluffos.info` stamp) + `/room/city/inn`, `/room/wiz/noisy_room`, `/room/storage`, `/RO/void`; `lpcc --batch` 8/8 active files (0 warnings, 0 errors); native (`testera`) & WASM (`testerw`) verified. `NOTES.md`. |
| 28 | Heaven7 | **Onboarded & closed** `libs/heaven7/` (192, port 40397) | Boot + register(`hero`) → Tempus square/Town Hall/gardens + WASM `wasm_client.js` + `lpcc --batch` 472/472 (0 warnings, 0 errors). `NOTES.md`. |
| 22 | NannyMUD lib | **Onboarded & closed** `libs/nanny/` (193, port 40398) | `nannylib.tgz` (1996-03-29) converted; `lpcc --batch` 544/544 viable files (0 warnings, 0 errors); native (`guest` + `testera`) & WASM (`testerw`) tested through village/church/guild/shop/Harry; banner stamped. `NOTES.md`. |
| 23 | Silberland | **Onboarded & closed** `libs/silberland/` (198, port 40403) | `silberland-mudlib` (`codeberg.org/lycis/silberland-mudlib`, commit `3a80c370`) converted (`ISO-8859-1` -> UTF-8, `27,063` `.lpc`, runtime logs/stats trimmed); Strategy A FluffOS catalog + `/etc/WELCOME` (`mudlibs.fluffos.info` stamp) + `/gilden/abenteurer` -> `/room/treff` & Midas town (`kapelle`, `kneipe`, `kneipe_saal`, `laden`, `post`, `room_a5..g5/c7..d7`); `lpcc --batch` 23/23 (0 warnings, 0 errors); native (`gast` + `testera`) & WASM (`testerw`) verified. `NOTES.md`. |
| 24 | Tamedhon | **Onboarded & closed** `libs/tamedhon/` (194, port 40399) | `td-mudlib` (GPLv3 open-source release) converted; Strategy A FluffOS catalog + authentic `/gilden/abenteurer` + `/room/{kreuzung,lehrlingsbude,mkz,jail,void,debug,lagerraum}` + `/players/gott/workroom`; `lpcc --batch` 14/14 active files (0 warnings, 0 errors); native & WASM (`testerw`) verified; `WELCOME.localhost` banner stamped. `NOTES.md`. |
| 26 | UNItopia | **Onboarded & closed** `libs/unitopia/` (197, port 40402) | `unitopia-mudlib.tar.gz` converted (130 symlinks dereferenced, 516 `.lpc`); Strategy A FluffOS catalog + `/static/adm/WELCOME` (`mudlibs.fluffos.info` stamp) + Kathedrale Tadmor, Kirchturm, Rathaustreppe/Foyer/Forum/Reinkarnation/Gilden 1–5; `lpcc --batch` 18/18 (0 warnings, 0 errors); native (`gast` + `testera`) & WASM (`testerw`) verified. `NOTES.md`. |
| 13 | Older Dead Souls point releases | **Covered by `006*` stack (closed)** | Audited recovered archives (`ds2.1.1.zip` `1,697` LPC files `2006-07-12`, `ds2.3a1.zip` `2,046` LPC files `2006-11-28`, `dsIIr10.zip` `2009-07-17`); all recoverable 2.x/3.x point releases sit cleanly inside/between existing `dsI` (`006-1`) -> `dsII` (`006-2`) -> `dsIII` (`006-3`) -> `ds386` (`006`) -> `deadsouls_fluffos` (`006-4`). Wayback URLs preserved in issue thread. |

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

1. NannyMUD (`#22`) — lysator tarball on disk.
2. SWLPC (`#29`) — LDMud port.
3. Optional: OSB (`#18`), Silberland (`#23`), Tamedhon (`#24`), UNItopia (`#26`), DS point releases (`#13`).

## Token note

Ask a human with write scope to close #16/#7/#21/#20/#19/#17/#14/#25 and the DGD set with the table rationale above.
