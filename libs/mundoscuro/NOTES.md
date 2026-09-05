# Mundo Oscuro -- porting notes

Source: `git clone https://github.com/gllort/mud` (commit
`e2511b4fc189cfcdeeac44242d0700b5382c4680`, “Initial commit”,
2016-01-28; cloned 2026-09-04). Config name `Mundo Oscuro`. Author
credits in-tree: Cain@MundoOscuro; error handler is Lima-derived
(“Codigo original de las librerias Lima. Modificado por
Cain@MundoOscuro 10/Jul/2003”). Slug `mundoscuro`, number 965, port
40273.

This collection’s copy is a snapshot, not a live mirror. Local
driver-compat and play-bar fixes mean it has diverged from upstream.

## 0. Layout

Repo root is not the mudlib. Only `lib/` was copied into `raw/`
(~484 `.c`). Ignored: bundled `driver/` (MudOS-era source) and
`lib.20040222.tar.gz`. Original config
`driver/etc/mundooscuro.cfg`: `master : /kernel/master`,
`simul_efun : /kernel/simul_efun`,
`global include : "/include/global.h"`.

`valid_read` / `valid_write` already return 1. FTP/IRC listen paths
were already commented out upstream.

## 1. Encoding: ISO-8859-1, not GB18030

Spanish Latin-1 archive. Default `convert_lib.sh` GB18030 pass would
have silently mojibake’d the 17 Latin-1 `.c` files (same trap as
`ninetears`). Ran `convert_lib.sh` with `ISO-8859-1`:
`already_utf8=591 converted=22 lossy=0`. Non-ASCII identifier tokens
were then folded (ñ→n) and the four files that used them as *names*
were renamed: `daños.h`→`danos.h`, `tablas/daños.lpc`→`danos.lpc`,
`empuñar.lpc`→`empunar.lpc`, `apuñalar.lpc`→`apunalar.lpc`.

## 2. MySQL is mandatory

Accounts, ranks, groups, and channels all go through `db_connect` /
`db_exec`. `kernel/daemons/initd.lpc` `check_database()` calls
`shutdown(-1)` on connect failure, so the mud will not stay up without
a server. Password comes from `valid_database()` in
`kernel/valid.lpc`: `"BN1TKUBr1p7x"`. User `mud`, database
`mundooscuro`.

**Host must be `127.0.0.1`, not `localhost`.** `localhost` uses
`/var/run/mysqld/mysqld.sock`, which does not exist when MariaDB is
in Docker. Set in `include/config.h` (`BD_HOST`).

Docker recipe used on this worker (leave the container running; do
not start the leftover `nitan170911_mysql` container — wrong schema):

```
docker run -d --name mundoscuro_mysql --restart unless-stopped \
  -e MYSQL_DATABASE=mundooscuro -e MYSQL_USER=mud \
  -e MYSQL_PASSWORD=BN1TKUBr1p7x -e MYSQL_RANDOM_ROOT_PASSWORD=1 \
  -p 127.0.0.1:3306:3306 mariadb:10.11

docker exec -i mundoscuro_mysql mysql -umud -pBN1TKUBr1p7x mundooscuro \
  < libs/mundoscuro/work/sql/crea.sql
docker exec -i mundoscuro_mysql mysql -umud -pBN1TKUBr1p7x mundooscuro \
  < libs/mundoscuro/work/sql/inserts.sql
docker exec -i mundoscuro_mysql mysql -umud -pBN1TKUBr1p7x mundooscuro \
  < libs/mundoscuro/work/sql/canales.sql
```

`crea.sql` is the upstream schema with `TYPE=InnoDB` rewritten to
`ENGINE=InnoDB` (MariaDB 10 rejects `TYPE=`). `inserts.sql` is the
upstream seed (`cain`/`admin`, ranks dios/creador/semidios/admin,
…). `canales.sql` registers rank/group channels the seed never
created (grupos were inserted via raw SQL, so `GRUPOS->crear()` never
called `CANALES->register()`).

WASM has no MySQL. `wasm_status` is **limited**. Native play is
fully verified. Do not treat a WASM “connecting…” hang as a mudlib
bug — `initd` will shut the driver down when `db_connect` fails.

## 3. FluffOS dialect / driver-compat

Catalogued as AGENTS.md §6.9 (`ident?()` + string-macro `->`).

1. **`?` in identifiers is illegal.** Mechanical rename `foo?(` →
   `foo_q(` (171 names). Predicate style is now `inmortal_q()`,
   `nombre_q()`, `inmortales_q()`. A second pass caught leftovers
   after the ñ-fold. One string-literal casualty:
   `"Salir de todos modos? (s/n): "` became `"...modos_q(s/n)"` in
   `comandos/jugador/salir.lpc` — restored. An earlier accidental
   rewrite of the login `hembra?` prompt was also reverted; keep
   `hembra_q()` only as the real predicate in `sexo.lpc`.

2. **`MACRO -> func(` parsed as class member** (`Left argument of ->
   is not a class`). Daemon/table macros rewritten to
   `efun::call_other(MACRO, "func", ...)`. Empty-arg form must be
   `call_other(X, "Y")` with no trailing comma. This lib’s sefun
   `call_other.lpc` overrides `call_other` and routes non-local
   origin through `CALLER->protected_call` — shims must use
   `efun::call_other`. `serror(x)` is
   `efun::call_other(ERROR, "error_message", x)`.

3. **`PACKAGE_UIDS` stubs** in `kernel/master.lpc`: `get_root_uid` /
   `get_bb_uid` / `creator_file` all return `"mudlib"` (matches
   `ROOT` in `config.h`).

4. **`string array` / bare `array` types** → `string *` / `mixed *`
   in `nombres.lpc`, `triggers.lpc`, `verbo.lpc`, `ir.lpc`,
   `base_room.lpc`.

5. **`__HEARTBEAT_INTERVAL__` is missing** on this driver. Hard-coded
   `hb = 1` in `global/personaje/propiedades.lpc`.

6. **FluffOS `db_connect` returns an error string on failure, not 0.**
   New sefun `kernel/simul_efun/system/dbcompat.lpc` (included from
   `simul_efun.lpc`) wraps `db_connect` / `db_exec` (string error →
   store and return -1), plus `db_error` / `db_errno` (1062
   Duplicate, 1216/1452 FK) / `db_affected_rows` / `db_insert_id`
   via `LAST_INSERT_ID()`.

7. **AUTO_INCREMENT inserts** `VALUES('', ...)` rejected by MariaDB
   for INT columns. Changed to `VALUES(NULL, ...)` in
   `canales.lpc`, `users.lpc`, `grupos.lpc`. Same `TYPE=` →
   `ENGINE=` rewrite in `include/sql.h`.

8. **`initd` skips `/kernel/daemons/ftp.lpc`**. It does not compile
   (functionals capture locals). The listen path is already
   commented out upstream. Do not add this lib to a boot loop that
   expects an FTP port.

9. Boot warnings only: unused locals, nested `/*` in comments,
   missing `author_file` / `domain_file` (driver falls back to
   root/bb uid).

## 4. Play-bar bugs (programming, not content)

1. **`crear_ficha()` saved the `.o` before `sexo()` / `raza()` /
   `clase()` / `move()`.** First reconnect then failed
   `cargar_raza()` (implicit 0 when `fichero_raza` is unset) and
   `move(ultimo_lugar_q())` (`MOVE_NO_DEST`). Reordered: apply
   attrs, move to `/global/room/entrada.lpc`, *then* save.

2. **`guardar()` wrote `.lpc` after conversion.** Upstream saved
   `nombre?() + ".c"`; `convert_lib.sh` rewrote that to `.lpc`.
   Login / `crear_ficha` / `cargar_ficha` all use `.o`. Fixed
   `guardar()` to `.o` so `salir` actually updates the ficha
   (`Ficha grabada.` verified live).

3. **`VOID` pointed at `/global/room/void`, which never existed.**
   The room file is `vacio.lpc`. `include/mudlib.h` now points
   `VOID` at `/global/room/vacio`.

4. **Leftover debug `printf`s** dumped object graphs at the player:
   `login.lpc` `crear_clase()`, `mirar.lpc` `can_mirar*`,
   `dominios/cielo/comun.lpc` `create()` (`printf("%O\n", APO)`).
   Removed. These were upstream leftovers, not conversion artifacts.

5. **Immortal login died on a missing rank channel.** Seed created
   grupos/rangos via SQL, so `admin` had no row in `canales`.
   `inmortal.lpc` `cargar_ficha()` treated `add_channel()` failure
   as fatal. Softened to a warning; `grupos.start()` now registers
   a channel for every loaded group that `CANALES` doesn’t already
   know.

## 5. Admin seeding

`find_admin_q()` only auto-promotes when
`sizeof(inmortales) <= sizeof(SYSTEM_USERS)` (`mudlib`, `nobody`).
The seed already has human immortals, so the first `fluffos`
registration stays mortal unless SQL-promoted:

```
INSERT INTO inmortales (nombre, rango) VALUES ('fluffos', 'admin');
INSERT INTO miembros (nombre, grupo) VALUES ('fluffos', 'admin');
UPDATE jugadores SET passwd='Mud@2026' WHERE nombre='fluffos';
```

Then reboot (USERS loads `inmortales` into memory at `start()`).
Existing seed account `cain` / password `a` is below
`LOGIN_MIN_PASS` 5; leftover from upstream, not used here.

Player body for immortals is `/kernel/inmortal` (inherits
`/global/jugador`). `who` prints `Fluffos`. `mirar` prefixes
`[file_name]` for immortals.

## 6. Live verification (2026-09-04, after §9 formatter)

Driver: `~/src/fluffos/build-debug/src/driver config.fluffos`
(cwd `libs/mundoscuro/work`), port 40273. MariaDB container
`mundoscuro_mysql` on `127.0.0.1:3306`.

- Boot: warnings only. `Accepting telnet connections on
  0.0.0.0:40273.` `work/log/{catch,runtime,error}` were never
  created (error_handler writes those; a missing file here means
  no caught/runtime errors, not a dead log — `log/debug.log` *did*
  receive this boot’s compiler warnings).
- Login `fluffos` / `Mud@2026` → prompt `>`.
- `mirar`: `[/dominios/cielo/comun]` / **Torre del destino: Gran
  Salón** / Sala de la Creación text / exits este, norte, oeste.
  (Reconnect after a previous `comun` walk; first-ever landing is
  Entrada a los Reinos, exit `comun`.)
- `score`: `Puntos de Vida: 1/1  Energia: 1/1`.
- `ficha`: Humano / Guerrero, six attributes, guild Ninguno.
- `who`: `Fluffos`.
- `inventario`: `No llevas nada encima.`
- `salir`: `Ficha grabada.` / `Gracias por jugar!`
- English `look` / `quit` print `¿Qué?` (config `default fail
  message`). That is the parser, not a broken command hook.

New-character registration was exercised earlier the same day
(varón / humano / guerrero) before the `crear_ficha` save-order
fix; the leftover `crear_clase` `%O` dump was visible then and is
now gone.

§9 formatter: 485 `.lpc`, 482 rewritten, 0 errors. Blind-spot
greps (`: : func(`, `\\ n`, spaced CJK) clean. Re-boot +
`mirar`/`score`/`salir` still clean after the format pass.

## 7. Known leftover / not fixed

- Starting HP/energy are 1/1 until the player spends time in
  `ajustar` (chargen attribute assignment). Content, not a port
  bug.
- `entrada.lpc` still has the placeholder `DESCRIPCION` string —
  upstream never wrote a room desc for the landing room.
- `/kernel/daemons/ftp.lpc` still does not compile; skipped at
  preload.
- Large unfinished Zorimeth Underdark (`dominios/suboscuridad/`,
  ~290 `ciudad_*.lpc`) was not play-walked this pass.
- Do not commit `work/fichas/<letter>/*.o` player saves, `log/`,
  or `raw/`.
- 928/929/932 header-encrypted 7z and leftover Dead Souls drivers
  on this worker are unrelated; do not touch them.

## 8. Config

`libs/mundoscuro/config.fluffos`: `external_port_1 : telnet 40273`,
no binary port. `mudlib directory` is the absolute `work/` path.
`fichas/{a..z}/` created for player saves.
