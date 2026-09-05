# GitHub Spanish-LPC keyword sweep (2026-09-04/05)

User asked to page from the newly onboarded Spanish lib (`mundoscuro` /
`gllort/mud`, Mundo Oscuro) rather than redo the generic
`fluffos`/`mudlib`/`lpmud`/`Mudos` sweep in
`scratchpad/github-keyword-sweep.md`.

## Method

- Source of truth: `gh api search/repositories` at 100/page, plus a
  short `search/code` pass for unique in-tree strings.
- Stagger ~5s between repo queries, ~10s between code queries.
- One transient `hispamud` connect error; retried later (`total_count=0`).
- Two `in:readme …` code queries 422'd (query parse); the same names
  were already covered as repo searches.
- No 429/403 on any completed query.
- Also walked `user:gllort`, `user:unleashed`, `user:maldorne`, their
  forks, and starred-repo lists for mud-ish hits.

## Seed terms (from mundoscuro + the other Spanish lib we already have)

From `libs/mundoscuro`: Cain@MundoOscuro, Zorimeth, essadath, oniria,
suboscuridad, Narbondel, “Entrada a los Reinos”, “Torre del destino”,
“Sala de la Creación”, `crear_ficha`, `mundooscuro.cfg`,
`MudOs driver` (upstream README wording).

From `libs/ninetears` (already onboarded): Calandria, Driade, FFICMUD /
fficmud, Ninetears / Nueve Lágrimas.

Known Spanish LPC names that are *not* in the mundoscuro tree but sit
in the same community: Simauria, Clib, Clon de Simauria, plus generic
`mudos/mudlib/lpmud/lpc español|spanish|hispano|spain`.

## Repo queries (all paged; rare terms are one page)

| Query | total | LPC mudlib hit |
|---|---|---|
| Zorimeth / essadath / oniria mud / suboscuridad | 0 | — |
| Calandria mud / Calandria mudlib / lib calandria | 0 | — |
| Calandria (bare) | 45 | none (voxel game, RH apps, people named Calandria) |
| fficmud / FFICMUD / Driade mud / Driade mudlib / ninetears | 1 | `unleashed/ninetears` **already onboarded** |
| Driade (bare) | 9 | only ninetears |
| simauria / Simauria mud / simauria lpc / simauria lpmud / clon simauria | 0 | — |
| clib mudos / clib mudlib | 0 | — |
| mundo oscuro mud / Cain MundoOscuro / Cain@MundoOscuro / mundooscuro | 0 | `gllort/mud` does not match these (English README) |
| mudos/mudlib/lpmud español; spanish mudlib/mudos/lpmud/lpc mud; mudos spain; lpc español; mudos hispano | 0 | — |
| lpc spanish | 1 | false positive (softcam keys) |
| hispamud / mud hispano / nueve lagrimas | 0 | — |
| aetheria mudos / aetheria mudlib / occidente mud / nandor mud / allanon mud / valinor mudos / endor mud lpc / reinos oscuros mud / inmortales mudlib | 0 | — |
| aetheria mud | 2 | `DevNullInc/AetheriaMUD` is C++/Diku (`area/`,`src/`), not LPC |
| reinos de leyenda | 11 | client scripts (TinTin++/VipMud/Lua). RdL is Diku/Circle, not LPC |
| crear_ficha | 64 | Spanish “ficha” = form/sheet; no mudlib |
| Entrada a los Reinos / Torre del destino / Narbondel | 1–2 | unrelated games / a GitHub profile |
| MudOs driver | 10 | `gllort/mud` **already onboarded**; rest are drivers we know or already-skipped DGD (`maldorne/hexagon`) |
| topic:spanish-language mud | 1 | `unleashed/ninetears` again |
| user:gllort | 9 | only `gllort/mud` is a mudlib |
| user:unleashed | 33 | only `unleashed/ninetears` is a mudlib |
| user:maldorne | 11 | see below |

`gllort/mud` and `unleashed/ninetears` have **zero forks**.

## Code queries

| Query | total | LPC mudlib hit |
|---|---|---|
| Cain@MundoOscuro | 0 | GitHub has not indexed `gllort/mud`’s LPC (or the string is Latin-1) |
| filename:mundooscuro.cfg | 0 | same |
| Zorimeth | 1 | Jupyter notebook, not a mud |
| fficmud | 25 | all real hits are `unleashed/ninetears` |
| “Introduce tu apodo” | 187 | i18n “Enter your nickname” in Teeworlds/etc. |
| “Sala de la Creación” | 22 | museums / LOTRO Spanish loc |

## Related users / adjacent repos (inspected)

- `maldorne/frmudlib` — Final Realms mudlib-only dump (FR 3.5b on a
  branch; master empty). Same game as collection `finalrealms`
  (`quixadhal/fr`). ninetears is the Spanish FR 3.4 + Calandria fork
  we already have. **Not a new onboard.**
- `maldorne/hexagon` — DGD, already skipped.
- `maldorne/mudos` / `maldorne/ldmud` — drivers, not libs.
- `maldorne/awesome-muds` — curated list. Mentions FR / frmudlib /
  FluffOS / Lima / DS / Discworld. **No Simauria, Calandria, Mundo
  Oscuro, Driade, or other Spanish LPC dump.**
- `suxiaojack/MudOS` — “a couple mudlibs” = lima + lil submodules.
- `DevNullInc/AetheriaMUD` — Diku C++.
- Starred lists for gllort / unleashed / maldorne: no extra LPC libs.

## Live Spanish LPC that is *not* on GitHub

**Simauria** (`mud.simauria.org:23`, LDMud 3.2.15, mudlib Simauria
1.6.0.1) is still up. No public git/SourceForge dump turned up under
any of the names above. Discovery triage drops LDMud from the onboard
queue unless someone explicitly wants a `questmud`-style port
(AGENTS.md §7.158). Do not treat “Simauria exists as a live game” as
a queued archive.

Calandria (the Spanish FR-derived lib ninetears credits) has **no**
standalone public repo; it only exists as the delta inside ninetears.

## Deduped new FluffOS/MudOS-compatible LPC

**None.** The only two public Spanish MudOS libs on GitHub are the
ones this collection already has:

1. `gllort/mud` → slug `mundoscuro` (965 / 40273), onboarded 2026-09-04.
2. `unleashed/ninetears` → slug `ninetears` (939 / 40241).

Do not queue frmudlib, hexagon, RdL scripts, AetheriaMUD, or Simauria
(no dump; LDMud).

## On merge

Done 2026-09-05. Queue unchanged by this sweep:
`scratchpad/librarian-next.txt`.
