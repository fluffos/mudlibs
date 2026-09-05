# Mundo Oscuro (mundoscuro)

A Spanish-language MudOS v21-era mudlib (Cain@MundoOscuro), cloned from
`https://github.com/gllort/mud` (commit `e2511b4`, 2016-01-28 “Initial
commit”). This collection’s copy is a snapshot as of 2026-09-04, not a
live mirror — local driver-compat fixes mean it has diverged from
upstream. Slug `mundoscuro`, number 965, port 40273.

The real mudlib root is the repo’s `lib/` (~484 `.c`). The bundled
`driver/` tree and `lib.20040222.tar.gz` are ignored; this project uses
its own FluffOS build.

In-game text, commands, and help are entirely in Spanish. English
`look` / `quit` print the configured fail message `¿Qué?`. Use `mirar`,
`score`/`ficha`, and `salir`.

## Registration flow

`Introduce tu apodo:` → confirm nick (`s`/`si`) → password → confirm
password → email (`user@host.domain`) → `varon o hembra? (v/h)` → race
(`humano`, `elfo`, …) → class (`guerrero`, `mago`, …) → lands at
**Entrada a los Reinos** (exit `comun` → Torre del destino: Gran Salón).

Requires a live MariaDB/MySQL with the schema in `work/sql/`. `initd`
calls `shutdown(-1)` if `db_connect` fails. See `NOTES.md` for the
docker recipe. WASM has no MySQL, so browser play cannot register —
`wasm_status: limited`. Native play is fully verified.

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: SQL-promoted to rank `admin` (level 1000, the seeded
  maximum) plus `miembros.grupo = admin`. `find_admin_q()` will not
  auto-promote: the seed already has human immortals (`cain`, …).

Verified live: `who` lists `Fluffos`; `mirar` as immortal prints the
room file path; `ficha` shows Humano / Guerrero.

## Commands (Spanish)

| English habit | This lib |
|---|---|
| look | `mirar` |
| score | `score` or `ficha` |
| inventory | `inventario` |
| quit | `salir` |
| who | `who` |

Movement uses Spanish exit names as verbs (`comun`, `norte`, `este`,
`oeste`).

## Local run

```
# MariaDB must already answer on 127.0.0.1:3306 (see NOTES.md)
cd libs/mundoscuro
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40273**.

```
python3 scripts/mudclient.py 127.0.0.1 40273 --timeout 25 --idle 1.2 \
  --send "fluffos" --send "Mud@2026" \
  --send "mirar" --send "score" --send "salir"
```
