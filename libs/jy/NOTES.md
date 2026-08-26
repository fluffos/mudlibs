# jy — `git clone https://github.com/mudchina/jy` → duplicate of `jyqxc`

- Source: `git clone https://github.com/mudchina/jy` (single commit
  `bc60c5c` "create git repo for jy", authored 2016-02-21; ~23MB clone
  incl. `.git`, 3,625 tracked files). Pre-assigned identifiers for this
  entry: number **172**, slug `jy`, port **40219** (reserved but
  unused — see below).

## Duplicate check (done BEFORE any conversion work, per AGENTS.md §2.1)

This project already has a large Jin-Yong-themed family: `jym` (#147,
"金庸梦" / Ode-to-Gallantry lineage — confirmed unrelated, different
codebase), `jyqs` (#911, not a mudlib), `jyqxc` (#086, "金庸群侠传" /
"The Story of Hero"), `jyqxc2` (#087, near-duplicate of jyqxc), and
`jyqxc2013fwq` (#088, independent 2013 server-side snapshot of the
same architecture family). Per AGENTS.md's repeated lesson that
similar titles are not proof of lineage either way, this was checked
by diff, not assumed — and the closest-named sibling turned out to be
an exact match:

1. **The smoking gun**: `jyqxc`'s own raw archive (`金庸群侠传
   (1).rar`) extracts to a top-level directory literally named `jy` —
   i.e. `jyqxc/raw/jy/`. That is the same name as this GitHub repo.
2. **File tree structure**: `find -maxdepth 2` on both trees produced
   near-identical directory listings — same top-level dirs (`doc`,
   `feature`, `kungfu`, `include`, `inherit`, `clone`, `data`, `d`,
   `u`, `adm`, `help`, `home`, `cmds`), same area names under `d/`
   (`baituo`, `emei`, `gaibang`, `huashan`, `mingjiao`, `shaolin`,
   `wudang`, `xiaoyao`, `xingxiu`, `xueshan`, etc.).
3. **Content diff**: `diff -rq` between `jy/raw` and `jyqxc/raw/jy`
   found **zero files that differ in content** across all shared
   files. `jy/raw` has 3,625 tracked files; `jyqxc/raw/jy` has 3,648.
   Every one of the 23 extra entries in `jyqxc/raw/jy` is explained by
   one of two things git doesn't preserve/include:
   - Runtime/leftover state: `adm/tmp`, `log/` (with the classic
     `AUTOLOAD`/`FTPD`/`SNOOP_PLAYER`/etc. runtime logs),
     `doc/efuns/log`, `data/login/g`, `data/user/g` (a leftover test
     account), `PROFILE`.
   - The Windows binary distribution that this archive's uploader
     happened to include at the tree root (`driver.exe`, `MudOS.exe`,
     `despass.dll`, `passdll.dll`, `svrview.exe`, `addr_server.exe`,
     `edit_source.exe`, `config.cfg`/`config.ES2`/`config.xkx`,
     `mud.bat`, `mud.dat`, `MudOS.dsw`, `mudos.etc`, `Howto.Win32`,
     `Readme.txt`) — the git clone has the LPC-relevant subset of
     these organized under `bin/` instead, and simply omits the
     Windows executables/DLLs.
   - Two empty directories (`d/wuguan/npc`, `d/wuguan/obj`) and an
     empty `doc/story` — git does not track empty directories, so
     these vanished from the git mirror even though the LPC-relevant
     content is otherwise identical.
4. **Spot md5 check**: `adm/obj/master.c` — the file this project's
   playbook always calls out first for lineage confirmation — is
   byte-for-byte identical (`7c640d6d8172b23e150a80ac9173aab8`) between
   `jy/raw` and `jyqxc/raw/jy`.

**Conclusion: `jy` is a byte-for-byte identical duplicate of
`jyqxc`'s underlying codebase**, not merely the same lineage — this
GitHub repo is a re-upload of the exact same "jy" snapshot already
preserved here as archive `金庸群侠传 (1).rar` (jyqxc), missing only
non-LPC runtime cruft and Windows binaries that don't affect the
mudlib itself.

## Disposition

Per this project's standing convention for confirmed duplicates
(`duplicate_of` in `meta.json`, e.g. `mhxy2002`→`mhxyqd`,
`nitan3`→`nitan_san`, `xxcqii2`→`xxcqii`) and per
`scripts/gen_site_index.py`'s documented behavior (duplicate-archive
entries never own a libs/ dir for site purposes — they're skipped from
the generated site entirely), this entry is recorded as metadata only:

- **No independent `work/`, `config.fluffos`, or boot/play test was
  produced.** Reproducing the GBK→UTF-8 conversion, driver-compat
  fixes, and boot verification here would exactly reproduce `jyqxc`'s
  already-committed `work/` tree byte-for-byte (same source, same
  fixes would apply identically) — zero new information, pure
  duplicated effort. The `raw/` clone is kept for provenance only
  (gitignored, like every other lib's `raw/`).
- **The live, playable instance for this codebase is `jyqxc`**
  (port 40129, in-game title "The Story of Hero"). Its `NOTES.md`
  documents the full fix catalog that applies equally to this source:
  the `feature/name.lpc` `short()`/`capitalize(query("id"))` crash on
  legacy board-post `.o` saves, the `adm/etc/wizlist`-based admin
  seeding, the `enter_world()` food/water §8.9 fix, and the death/
  revival §7.68 fixes across `d/death/npc/*.lpc`.
- **Port 40219** was pre-assigned to this entry (checked against the
  whole collection to avoid collisions) but is left unused in
  `config.fluffos`-space since no driver instance runs under this
  slug; recorded here so the reservation is documented and the port
  isn't accidentally handed to a future, genuinely-distinct lib.
- `wasm_status` is left `""` (not `"playable"`) since no WASM pack/
  boot test was run under this slug specifically — the WASM-playable
  instance is `jyqxc`'s.

## If a future pass wants an independent build anyway

Nothing above is destructive — `raw/` is present and untouched, so a
future agent could still run the full §2 pipeline here if there's ever
a reason to want two independently-built copies. Given the confirmed
byte-identical source, the expectation is that it would reproduce
`jyqxc`'s `work/` tree and fix list exactly.
