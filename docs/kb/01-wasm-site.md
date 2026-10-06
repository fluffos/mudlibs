# KB 01 — WASM, site pipeline, admin seeding (§1)

## 1. WASM — the primary target

### 1.1 What WASM mode is

The driver compiles to WebAssembly (`build-wasm/src/fluffos.{js,wasm}`).
The mudlib lives in an in-memory filesystem, and connections are
in-process (`wasm_console_connect()`/`fluffos_input()`). The Pages site
(`.github/workflows/pages.yml`, `scripts/build_site.sh`,
`pack_lib_zip.sh`, `write_play_page.sh`, `gen_site_index.py`) packs every
lib for click-to-play. After any push that touches this pipeline, watch
the Actions run and fix failures until it's green.

Build steps (once per machine). The emsdk version is pinned in
`~/src/fluffos/.github/actions/build-wasm/action.yml`:
```
cd ~/.local/opt/emsdk && ./emsdk install <pinned> && ./emsdk activate <pinned>
source ~/.local/opt/emsdk/emsdk_env.sh   # per shell; don't pipe it (a subshell drops PATH)
cd ~/src/fluffos && tools/wasm/build-deps.sh PREFIX=/opt/wasm-deps
cmake --preset native-tools && cmake --build --preset native-tools -- -j8
emcmake cmake --preset wasm && cmake --build --preset wasm -- -j8
```
Gotcha: `build-deps.sh`'s ICU data step needs
`LD_LIBRARY_PATH=$WORK/icu/source/build-host/lib`. Check that all three
ICU `.a` files exist before building the driver.

### 1.2 Testing a lib under WASM

```
node scripts/wasm_client.js ~/src/fluffos/build-wasm/src libs/<slug> \
    --timeout 20 --idle 1.0 --send "" --send "look" --send "quit"
node scripts/wasm_boot_check.js <site/slug> <site/_driver>   # packed bundle
```
- The second argument is the lib **root** (the dir containing
  `config.fluffos`), not `work/`.
- `fluffos_tick()` needs a monotonic clock that starts near 0. Passing
  `Date.now()` replays 100 catch-up ticks at once.
- The harness must recreate the full nested shape of `log/` and other
  runtime dirs. Many old "WASM-only" failures were missing dirs.
- A filename with invalid UTF-8 bytes crashes the harness's `copyDir()`
  (`ENOENT … scandir` with `�` in the path). Find such names with a
  Python walk (`name.encode('utf-8')` raises). Rename them to ASCII
  placeholders; they are never real source. Check redundant backup trees
  inside `work/` too.
- Some libs deliberately disconnect and tell you to reconnect (staggered
  preload gates). Pass `--reconnect-on-disconnect` for those. Leave it
  off by default.

### 1.3 Known WASM gaps and policy

Mudlib-side guards are encouraged. WASM playability outranks
byte-preserving the original behavior.

- **(a) `query_ip_number()` / `resolve()`: fixed in the driver.** WASM
  returns `"127.0.0.1"` / `"localhost"`, and `resolve()` succeeds on the
  next tick. Don't add mudlib workarounds for IP-format or `resolve()`
  crashes. A lib marked `limited` for an IP reason should be re-tested.
- **(b) Loopback-allow patch (standard, fail-closed).** Short-circuit the
  top of each ban, site, and per-IP throttle gate that `logind` actually
  calls:
  ```lpc
  string ip = query_ip_number(ob);
  if (ip == "127.0.0.1" || ip == "::1" || strsrch(ip, "127.") == 0) return 0;
  ```
  **Never** treat a malformed, empty, or non-string IP as loopback; that
  is fail-open. If you find `!stringp(ip) ||` or `sscanf(...) != 4` in an
  "is local" test, tighten it. Record the patch in `NOTES.md`.
- **(c) No `sockets`/`db`/`ffi`/`pcre`/`crypto`/`async`/`compress` in
  WASM.** Guard these shapes on sight:
  - `DNS_MASTER->query_muds()` or a mirror-site check in `logind`: wrap
    in `if (find_object(DNS_MASTER))`; absent means skip.
  - A `VERSION_D->is_version_ok()` gate (中华英雄/终极地狱 lineage): guard
    with `find_object(VERSION_D) &&`; absent means allow.
  - `MESSAGE_D->find_chatter()` in `check_ok()`. MESSAGE_D can't compile
    under WASM, so the unguarded call drops every login. Guard it with
    `find_object`.
  - `resolve()` inside a security daemon's `create()`: initialize state
    before any network call.
  - ident/port-113 lookups: wrap them in `catch()`.
  - Raw `socket_*` calls in **simul_efun** are boot-fatal (`ds386`).
    Check simul_efun first in any new WASM pass.
  - zlib is absent, and GBK/BIG5 `string_encode` raises.
- **(d) No pcre.** If simul_efun uses regex efuns, rewrite them in plain
  LPC, `#ifdef` a fallback, or pass ANSI through unchanged (`zsdsj`).
- **(e) Bypass legacy connection-time gates.**
  - `uptime() < N` startup-grace gates: the harness connects instantly,
    so the gate always fires.
  - Per-IP registration throttles.
  - Wizard-only-loopback gates that block the literal `"new"` keyword:
    exempt the keyword narrowly.
  - Keep in-game timers: quit-retention windows, save gates, cooldowns.
  ```lpc
  if (query_ip_number(ob) != "127.0.0.1" && uptime() < 30) { ...original... }
  ```
- **(f) A bare `call_other()` on a compilable but non-resident object can
  silently kill the calling function under WASM.** Natively it
  auto-loads. Fix the reproducing site only:
  `if (!find_object(X)) catch(load_object(X));` (`nt7`'s `TIME_D`).
- **(g) WASM ICU has no GBK converter.** A `set_encoding("gbk")` call
  while drawing a login menu kills the connection before the name prompt
  (`fy2005`). Wrap it as `catch(set_encoding("gbk"))` and stay on utf-8.
  See §8.7.

### 1.4 WASM triage playbook

`libs/<slug>/meta.json` `wasm_status` is the only per-lib status.
`gen_site_index.py` re-runs `assemble_numbering.py` and derives the
badges from it. `scripts/wasm_status.json` is an output artifact. It can
lag the live site, so refresh it rather than trusting it.

For each lib that isn't `playable`:
1. Reproduce with the lib's documented login. Read the full transcript
   and the driver output.
2. Classify against §1.3. If nothing matches, check whether it reproduces
   natively.
3. Fix, then re-run the full flow: Chinese name → `look` → `score` →
   `quit`.
4. Update `meta.json`, `NOTES.md`, and the README table.

Known one-offs: `xo` hangs at world entry under WASM only;
`xajhxo`'s finalization is timing-flaky under the harness.

**Site/SEO facts (2026-09-13):**
- English is the default (`/`, `x-default`). Chinese is at `/zh/`.
  `/en/` and `/cn/` are aliases.
- Lib pages:
  - `/<slug>/` is the hub; `/<slug>.html` is an SEO alias.
  - `/<slug>/play.html` and `/<slug>/info.html` each carry their own
    canonical.
  - `/<slug>/llms.txt` exists for every bootable lib.
- Root files: `llms.txt`, `games.json`, sitemap with `lastmod`.
- Index pages are prerendered by Astro (`web/`) from `museum.json`.
  Cards load from `/assets/catalog-{en,zh}.json`.
- `display_name()` strips a trailing `(slug)`. The English name goes in
  an `.aka` line, not the H1.
- **Publish invariant:** `build_site.sh` overlays **every** staging file
  onto `site/`. `scripts/verify_site_publish.py` must pass; it blocks
  deploy. When you add a published URL, extend the verifier. Never
  delete it.

### 1.5 Admin account seeding

Every lib gets an admin account `fluffos` / `Mud@2026`:
1. Register it through the normal flow.
2. Grant it admin through the lineage's own mechanism. Prefer editing
   data (wizlist file, `securityd` save, `(admin)` status) over code.
3. Verify with a real `update <path>`. A `(admin)` banner is not proof.
4. Commit the seed and document it in the lib's README ("管理员账号 /
   Admin account").

Traps:
- **Rank granted but the write ACL is empty.** Century/`adm/single`
  libs keep a separate `trusted_write` table. Seed that too
  (`sanjieshenhua`).
- **The hardcoded bootstrap id is already taken by a real archived
  player.** Add a parallel `set("wiz_status/fluffos","(admin)")` line next
  to it, and never touch the original player (`hy2002`).
- **`wiz_status` is declared `nosave`.** Assign it in `create()` after
  any `restore()` (`nt1`).
- **Dead Souls lineage.** Creator status comes from the save-file
  directory. Add `fluffos` to every `secure/cfg/groups.cfg` line,
  register normally, then with the driver stopped move
  `secure/save/players/f/fluffos.o` to `secure/save/creators/f/`
  (`riftsds`).

### 1.6 Site packing and deploy (zip-based, 2026-09-02)

- **One zip per lib.** Each lib's playable zip is also its download zip
  (`/<slug>/<slug>.zip`, built by `make_source_zips.sh` via
  `pack_lib_zip.sh`). A zip depends only on its lib tree and those two
  scripts, so an edit to the shell or the driver never forces a
  corpus-wide repack.
- **Loading.** `web_shell_override/zip-loader.js` parses the zip and
  calls `Module.FS.writeFile` in `preRun`. Decompression runs in a pool
  of `zip-worker.js` Web Workers sized to `hardwareConcurrency`. The
  corpus median is about 9.9k files and the max about 72k, so main-thread
  decompression took over a minute. Test loader changes against a large
  real lib.
- **Compressed saves (`*.o.gz`) never work on the site.** The WASM driver is
  built without zlib, so `restore_object()` only looks for `<name>.o`, and
  `make_source_zips.sh` drops `*.gz` anyway. A seed stored compressed
  (Discworld's admin `save/players/f/fluffos.o.gz`, `secure/bastards.o.gz`)
  is missing for every visitor: the documented admin password fails or the
  account does not exist, and `Failed to restore bastards.` prints at login.
  Store seeds as plain `.o` (`gzip -d`, byte-identical): the native driver
  reads `.o` when no `.o.gz` exists, and its own later compressed save just
  replaces it. Do not un-exclude `*.o.gz` in the packer (that made the login
  ask for a password it could not check). Detection: `git ls-files
  'libs/*/work/*.o.gz'`; check the inner encoding (a GBK lib's `.o.gz`
  escaped `convert_lib.sh`).
- **Runtime directories.** The zip carries no `log/` and no empty directory.
  `zip-loader.js` creates `work/log` plus every directory
  `scripts/wasm_keep_dirs.txt` lists for the slug (`keepDirs` in the live
  `<slug>/fluffos-boot.js`). A `log/` subdirectory a lib writes into can only
  arrive that way; elsewhere a tracked `.gitkeep` also works. A lib with no
  entry looks fine to a local WASM check and still dies for every visitor
  (Foundation I: the new-character prompt logs to `/log/secure`). Add entries
  with `python3 scripts/gen_keep_dirs.py --merge <slug>...` (seconds). Never
  run it bare to "refresh" the file: a full replace forgets every directory
  the local tree no longer has (it dropped 9.5k lines at once on 2026-10-03),
  and the committed file is not slug-sorted because onboarding commits
  appended their own blocks, so the tool edits blocks in place.
- **Persistence.** `persist.js` is an IndexedDB overlay of
  `/mudlib/work/data` only. `save-export.js` handles export, import, and
  reset; `safeRel()` blocks path traversal on both import and restore.
  `tab-lock.js` uses Web Locks to allow one tab per lib.

### 1.7 Per-lib client protocol adapters (ZJ / 指间MUD)

`zjdyzj`, `zjmudhell`, and `shujian3` use the `work/include/zjmud.h` crypt
handshake. `scripts/web_shell_override/zj-protocol.js` drives it:
- The lib's `logind` `create()` exports
  `js_export("zj_crypt", (: crypt(ZJKEY, $1[0]) :))` under
  `#ifdef __PACKAGE_JSBRIDGE__`.
- `index.html` exposes `window.installSessionAdapter(s)` and
  `s.lineFilter(line)`.
- `write_play_page.sh` autodetects `zjmud.h`.

State-machine rules for any future adapter:
- On a validation retry, restart the whole composite line, not just the
  failed field.
- Set state before `await`.
- Before delivering an async response, check that it's still wanted.
