---
name: database
description: Understand and work with the database (SQLite3) system in Oxidus. Covers the DB_D daemon, .tbl table-definition files, REST-style query interface, direct/lazy query APIs, schema creation and extension, and maintenance.
---

# Database Skill

You are helping work with the Oxidus SQLite3 database system. Follow the `lpc-coding-style` skill for all LPC formatting.

## Architecture Overview

```
FluffOS db package (db_connect/db_exec/db_fetch/db_close efuns)
  └── DB_D — /adm/daemons/db.lpc
        ├── REST API: rest(method, url, data, callback)
        ├── Sync API: query(db, q, callback)
        └── Async API: lazyQuery(db, q, callback)
```

- One `DB_D` daemon manages **all** databases
- Each database is a single SQLite3 file under `DB_PATH`
- Tables are declared via `.tbl` companion files and auto-created at boot
- `valid_database()` in `/adm/obj/master/valid.lpc` always returns 1 — DB security is by mudlib convention, not driver enforcement
- DB_D inherits `STD_DAEMON` and `EXT_HTTP` (the latter for `parse_query()`, used to decode REST URL query strings)

## Configuration Keys

All in `/adm/etc/default.lpml`, overridable in `/adm/etc/config.lpml`. Read via `mudConfig()`. See the `mud-configuration` skill.

| Key | Default | Purpose |
|---|---|---|
| `DB_PATH` | `/data/db/` | Directory where `.sqlite3` files and `.tbl` definition files live |
| `DB_SUFFIX` | `.sqlite3` | Extension for the SQLite database file |
| `DB_TABLE_SUFFIX` | `.tbl` | Extension for table-definition files |
| `DB_CHUNK_SIZE` | `100` | Rows per chunk for `lazyQuery()` (LIMIT/OFFSET batching) |

## The `.tbl` Definition Format

Each database has a companion `.tbl` file. The basename of the `.tbl` file is the database name. Example: `/data/db/bank.tbl` defines the database accessed as `"bank"`, stored in `/data/db/bank.sqlite3`.

The format is one table per line:

```
table_name=column_definition_clause
```

The right side is **the contents of the SQLite `CREATE TABLE` parens** — DB_D wraps it in `CREATE TABLE IF NOT EXISTS table_name (...)`. So you write columns, constraints, and foreign keys exactly as you would inside the parens.

Example — `/data/db/bank.tbl`:

```
balance=id INTEGER PRIMARY KEY NOT NULL, name TEXT NOT NULL UNIQUE, amount INTEGER NOT NULL,time INTEGER NOT NULL
activity=id INTEGER PRIMARY KEY NOT NULL, time INTEGER NOT NULL UNIQUE, name TEXT NOT NULL, amount INTEGER NOT NULL, FOREIGN KEY(name) REFERENCES balance(name)
```

### What boot does

`DB_D::setup()`:

1. Reads every `*.tbl` file under `DB_PATH`
2. Parses each line with `sscanf("%s=%s", ...)` — only the **first** `=` is the separator
3. **Skips any database whose `.tbl` parsed to zero tables** (logs to `system/db` and does not register in `__databases`). A `.tbl` file with only blank lines or unparseable lines effectively doesn't exist as far as DB_D is concerned.
4. For each remaining database, opens the `.sqlite3` file (creating it if missing) and runs `CREATE TABLE IF NOT EXISTS` for each declared table
5. Closes the connection

`CREATE TABLE IF NOT EXISTS` means **adding new tables to a `.tbl` file is safe** — they get created on next boot. Modifying or removing existing table definitions does **not** alter or drop existing tables. Schema changes need explicit migration (see below).

## REST-Style API (Preferred)

```lpc
varargs mixed rest(string method, string url, mapping data, mixed *callback)
```

URLs follow `db://<database>/<table>?col=val&col=val&_special=val`.

| HTTP method | SQL | `data` mapping | `where` from query string |
|---|---|---|---|
| `GET` | `SELECT *` | unused | optional |
| `POST` | `INSERT` | required (columns) | unused |
| `PUT` | `UPDATE` | required (SET) | required |
| `DELETE` | `DELETE` | unused | required |

### Special query params (consumed before WHERE)

| Param | Effect |
|---|---|
| `_order` | `col` or `col:asc` / `col:desc` — invalid directions fall back to ASC |
| `_limit` | Integer LIMIT clause |
| `_offset` | Integer OFFSET clause |

### Examples (from `adm/daemons/bank.lpc`)

```lpc
// Insert
DB_D->rest("POST", "db://bank/balance", ([
  "name": name,
  "time": time(),
  "amount": 0,
]));

// Select with filter
DB_D->rest("GET", sprintf("db://bank/balance?name=%s", name));

// Update by name
DB_D->rest("PUT", "db://bank/balance?name=" + name, ([
  "time": time(),
  "amount": new_balance,
]));

// Recent activity, ordered, limited
DB_D->rest("GET", sprintf(
  "db://bank/activity?name=%s&_order=time:desc&_limit=%d",
  name, limit
));
```

### Return values

- `mapping *` — array of column-keyed mappings (one per row) on success
- `string` — error message
- `0` — connection or fetch failure (also logged)
- `1` — when a callback was passed (the callback receives the result)

`rest()` `error()`s for invalid URL, unknown db/table, missing data on POST/PUT, missing WHERE on PUT/DELETE, or unknown method. Catch with `catch{}` if those conditions are possible at runtime.

### Security caveat — REST is NOT prepared statements

`rest()` builds raw SQL by string concatenation. Identifiers (table names, column names, `_order` columns) are quoted via `escapeIdent()` using SQLite's `"..."` form with embedded `"` doubled. Values are escaped via `escapeValue()`: strings get `'...'` with `'` doubled, numbers are coerced via `"" + v`, anything else (arrays, mappings, objects) produces malformed SQL. So:

- **Values from user input in WHERE/SET are safe** for strings and integers.
- **Identifiers from user input are quoted** but SQLite still treats `"x"` as a literal column reference, so a malicious column name can't escape syntax — but it can refer to a *real* column the caller didn't intend. If column names come from untrusted input, validate against an explicit whitelist.
- **Do not pass arrays/mappings/objects as values** — `escapeValue` doesn't handle them.

## Direct Query API

```lpc
mixed query(string db, string q, mixed *callback)
```

Runs an arbitrary SQL statement. `q` is auto-suffixed with `;` if missing. Returns:

- `mapping *` — collated rows on success
- `0` — no usable data. Covers bad input, connection failure, SQL error, or a query that produced zero rows (any INSERT/UPDATE/DELETE, or SELECT with no matches). All failure causes are logged to `/log/system/db` so the caller doesn't need to disambiguate them.
- `1` — when callback was passed (callback receives the collated rows)

The contract is intentionally narrow: **callers only ask "did I get rows?"** — `pointerp(result)` says yes, anything else says no. There is no string-error return; failures are DB_D's responsibility to log, not the caller's to surface.

The callback form uses `assemble_call_back()` from `simul_efun/function.lpc`:

```lpc
DB_D->query("bank", "SELECT * FROM balance", assemble_call_back(
  (: handle_rows :), this_body()
));
```

Use `query()` directly when REST doesn't fit — joins, aggregates, GROUP BY, complex SELECT, raw SQL.

### Row collation

DB_D's internal `collateData()` turns `db_fetch()` output (row 0 = column names, rows 1..N = values) into an array of mappings keyed by column name. Callers always get `({ ([ "col": val, ... ]), ... })` — never the raw efun shape.

## Lazy (Chunked) Queries

```lpc
void lazyQuery(string db, string q, mixed *callback)
```

For large result sets. DB_D appends `LIMIT DB_CHUNK_SIZE OFFSET N` and recursively re-issues via `call_out("executeQuery", 1, ...)` until a partial chunk is returned. Results accumulate in `__handle[queryId]`, then the callback fires once with the full result.

**Failure semantics match `query()`** — the callback receives `0` on any failure (connect, exec, fetch, close), all logged to `/log/system/db`. Partial accumulated data is discarded on failure rather than passed up looking complete. Caller checks `pointerp(result)`.

**The callback shape on success differs from `query()`.** The callback receives the raw stitched `db_fetch()` output, **not** collated mappings. Specifically: each chunk's portion of the array starts with `db_fetch(fd, 0)` (the column-name row) followed by data rows. So for a 350-row query with `DB_CHUNK_SIZE=100`, the callback gets 4 chunks worth of `({ headers, row1..row100 })` concatenated — that's **4 header rows** interleaved with 350 data rows, not one. Concretely:

```
({
  ({"id","name","amount"}),    // headers from chunk 1
  ({1,"Alice",100}),
  ...
  ({"id","name","amount"}),    // headers AGAIN from chunk 2
  ({101,"Bob",50}),
  ...
})
```

If you need column-keyed mappings, you must dedupe headers and apply `collateData`-style post-processing yourself. For result sets that fit in memory, prefer `query()` — it does the collation for you.

Don't `lazyQuery` a query that already has its own `LIMIT`/`OFFSET` — DB_D will append a second one and SQLite will reject it.

## Helper Functions on DB_D

| Function | Purpose |
|---|---|
| `validDb(db)` | Is `db` a registered database name? |
| `validTable(db, table)` | Does `table` exist in `db` (queries `sqlite_master`)? |
| `sqliteVersion(db)` | Returns version as `({ "3", "39", "0" })` |
| `allowUpsert(db)` | 1 if SQLite ≥ 3.24 (UPSERT / ON CONFLICT support) |
| `queryDatabases()` | Mapping of registered db name → file path |
| `queryTables(db)` | Mapping of table name → its `.tbl` definition string |
| `statementFromMapping(m)` | Builds `(col1,col2) VALUES (v1,v2)` from a mapping |

## Common Workflows

### Create a new database

1. Create `/data/db/<name>.tbl` with one `table=cols` line per table
2. Either:
   - Reboot the MUD, **or**
   - Destruct DB_D and reload it: `destruct(find_object(DB_D)); load_object(DB_D);`
3. The `.sqlite3` file is created on first connect inside `setup()`

DB_D doesn't expose a `rehash` — destructing and reloading re-runs `setup()`, which scans `.tbl` files.

### Add a table to an existing database

1. Append `new_table=cols` to the `.tbl` file
2. Reload DB_D — `CREATE TABLE IF NOT EXISTS` runs for every table, no-op for existing ones
3. Use the new table immediately via `rest()` or `query()`

### Add a column to an existing table

`CREATE TABLE IF NOT EXISTS` will **not** modify a table that already exists. To migrate:

```lpc
DB_D->query("bank", "ALTER TABLE balance ADD COLUMN frozen INTEGER DEFAULT 0");
```

Then update the `.tbl` file so future fresh installs match. Order: run the `ALTER` first, then sync the `.tbl` file.

For more complex schema changes (rename column, change type, drop column on older SQLite), follow the standard SQLite recipe: create new table, copy data, drop old, rename new. Run each statement as its own `query()` call — `db_exec`'s behavior with multi-statement SQL in one call is not verified, and DB_D opens/closes a connection per call so a `BEGIN`/`COMMIT` won't span calls anyway. Validate carefully after each step.

### Drop a database

1. Stop using it
2. Delete `<name>.tbl` and `<name>.sqlite3` from `DB_PATH`
3. Reload DB_D so its `__databases` mapping forgets it

### Indexes

Indexes are not expressed in the `.tbl` format. Create them manually after table creation:

```lpc
void setup() {
  // ... after DB_D is up
  DB_D->query("bank", "CREATE INDEX IF NOT EXISTS idx_activity_name ON activity(name)");
}
```

Put this in the consuming daemon's `setup()` (e.g. `bank.lpc`). `IF NOT EXISTS` makes it idempotent.

## Calling Patterns

### Synchronous — returns rows

```lpc
mixed result = DB_D->rest("GET", "db://bank/balance?name=" + name);

if(!pointerp(result))
  return null;         // no data — failure or no match (already logged)

return result[0]["amount"];
```

### Asynchronous — callback

```lpc
DB_D->rest("GET", "db://bank/activity?_order=time:desc",
  assemble_call_back((: process_activity :), this_body()));

void process_activity(mapping *rows, object who) {
  // rows is the collated result
}
```

### Building a daemon that owns a database

Example skeleton — see `adm/daemons/bank.lpc` for the canonical reference:

```lpc
inherit STD_DAEMON;

public mixed new_account(string name) {
  if(!nullp(query_balance(name)))
    return "Account already exists.";

  return DB_D->rest("POST", "db://bank/balance", ([
    "name": name,
    "time": time(),
    "amount": 0,
  ]));
}

public mixed query_balance(string name) {
  mixed result = DB_D->rest("GET",
    sprintf("db://bank/balance?name=%s", name));

  if(!pointerp(result))
    return null;

  return result[0]["amount"];
}
```

Domain daemons should **never** open `db_connect()` directly. Always go through DB_D so the connection lifecycle, error logging, and chunking stay centralised.

## Maintenance

### Logs

DB_D writes errors to `/log/system/db` via `log_file()`. Connection failures, query failures, and fetch failures are all logged with the database name, query, and SQLite error message.

### Vacuum / integrity check

Run on demand from a developer tool:

```lpc
DB_D->query("bank", "VACUUM");
DB_D->query("bank", "PRAGMA integrity_check");
```

`VACUUM` reclaims space after large deletes. `integrity_check` returns `({ ([ "integrity_check": "ok" ]) })` on a healthy database.

### Backups

Each database is a single file at `DB_PATH + dbName + DB_SUFFIX`. Plain file copy is safe **when no writes are in flight**. For consistent online backups, use SQLite's online backup pragma:

```lpc
DB_D->query("bank", "VACUUM INTO '/data/db/backup/bank-2026-05-02.sqlite3'");
```

(`VACUUM INTO` requires SQLite ≥ 3.27 — check with `allowUpsert()` as a rough proxy, or call `sqliteVersion()` directly.)

### Inspecting state from a developer command

```lpc
mapping dbs = DB_D->queryDatabases();         // names → file paths
mapping tables = DB_D->queryTables("bank");   // table → DDL
mixed v = DB_D->sqliteVersion("bank");        // ({ "3","39","0" })
```

## Gotchas

- **`.tbl` parsing is line-based** — newlines split records. Don't include literal newlines in column definitions; SQLite allows them but DB_D will split on them.
- **`sscanf("%s=%s", ...)` splits on the first `=`** — column definitions that include `=` (uncommon but possible in CHECK constraints or default expressions) may parse oddly. Prefer simple definitions in `.tbl`; do exotic schema work via explicit `query()` calls.
- **`__USE_SQLITE3__` and `__PACKAGE_DB__`** — the entire daemon body, including forward declarations, is gated on these compile-time defines. If the FluffOS build was made without `PACKAGE_DB_SQLITE`, none of the DB_D methods exist. Calls like `DB_D->query(...)` return the LPC "undefined" sentinel — distinguishable from an explicit `0` return via `nullp(result)` (true for undefined, false for `0`).
- **No connection pooling** — every `query()` and `rest()` opens and closes a fresh connection. This means SQLite transactions **cannot span multiple `query()` calls**: a `BEGIN` in one call is implicitly rolled back when the connection closes. Combining `BEGIN; ...; COMMIT;` in a single `query()` *may* work, but `db_exec` semantics around multi-statement SQL are not verified — treat any cross-statement transaction as untested and validate before relying on it.
- **Foreign keys are off by default in SQLite.** If you declare `FOREIGN KEY` in a `.tbl` and rely on enforcement, run `PRAGMA foreign_keys = ON` per connection — but DB_D opens a fresh connection each query, so the pragma must be issued at the start of every transaction-bearing `query()`.
- **`escapeValue()` only handles strings and numbers.** Passing arrays, mappings, or objects into a REST `data` mapping or as a query-string value will produce malformed SQL.
- **`lazyQuery` callback shape differs from `query`** — see the lazy section above.
- **No automatic schema migration.** Editing a `.tbl` line for an existing table does nothing on reboot. Migrations are manual via `ALTER TABLE` / `CREATE TABLE ... INSERT SELECT ... DROP ... RENAME`.

## Async Callbacks and DB_D

`DB_D` fires query callbacks through the `call_back()` sefun. That sefun is
**not async-aware**: it returns `catch(fun(...))`, so if the callback is an
`async` function it reports success the moment the body parks — before the
callback has done anything — and discards the promise it returned. A rejection
then surfaces only as an unhandled-rejection line in the debug log.

So a callback handed to `DB_D` must be an ordinary synchronous function. If it
needs to await something, keep the callback sync and have it call an async
helper fire-and-forget:

```lpc
void handle_rows(mixed *rows) {          // the callback DB_D fires
  process_rows(rows);                    // async helper, deliberately not awaited
}

private async void process_rows(mixed *rows) {
  mixed err = acatch {
    foreach(mixed *row in rows)
      cache_entry(row);

    await async_write(REPORT_FILE, render(rows), 0);
  };

  if(err)
    debug_message(`db report: ${err}\n`);
}
```

Note the `foreach` in that helper contains no `await` — an `await` cannot
suspend inside a `foreach` **body**, so use an indexed `for` if the loop body
itself must await. Awaiting in the header is fine (`foreach(mixed *row in await
fetch())`), since it is evaluated before the loop pins anything.

`async_call_back()` is the async-aware sibling of `call_back()`: it delivers the
callback's actual return value through a promise, adopting the callback's own
promise when it is async. It is available for new code that wants to await a
callback's completion; `DB_D` itself still uses `call_back()`.
