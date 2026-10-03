# KB 02 — Per-lib bring-up pipeline and archive extraction (§2–§3)

## 2. The per-lib pipeline (bring-up from a raw archive)

1. **Extract:** `scripts/extract.sh archives/<file> libs/<slug>/raw/`
   (traps in §3).
2. **Find the mudlib root.** Grep `master file`/`mudlib directory` or
   find `master.c`. The real master defines `object connect(` (§7.42).
3. **Convert:** `scripts/convert_lib.sh`. Encoding first, then
   `.c`→`.lpc`, then reference fixups. Run the §4 post-checks.
4. **Write `config.fluffos`** (§5) with a fresh port.
5. **Apply the §2.2 checklist.**
6. **Compile sweep:** `scripts/lpcc_check.sh <config> <work>`, after
   master and simul_efun compile. Compile the core base classes cleanly
   first (§10.4).
7. **Boot and play:** `cd libs/<slug> && ~/src/fluffos/build-debug/src/driver
   config.fluffos`, then a full registration with `mudclient.py`.
8. **Record:** `NOTES.md`, `README.md`, this file, status, then the WASM
   pass (§1.4).

**Definition of done:**
- Clean boot.
- A real Chinese name registers all the way into a room.
- `look`, `score`, and `quit` are all correct.
- A re-login works.
- WASM status is recorded.
- `debug.log` and the mudlib's own error log are reviewed (§10.7 item 5).

### 2.1 Recognize the lineage first

`md5sum`/`diff` the core files (`master`, `chinesed`, `logind`, `named`,
`securityd`) against processed libs. A match means you can port the
sibling's fix list. Caveats:
- Similar titles prove nothing in either direction.
- Siblings drift independently, so verify each ported fix per instance.
- See the §11 lineage map.

### 2.2 Proactive on-sight checklist

```
grep -n "load_object\|get_root_uid\|get_bb_uid\|get_include_path\|valid_override\|creator_file" <master>   # §7.1/7.2/6.1/7.175
grep -n "destruct" <master> | grep -i "simul_efun"                        # §7.3
grep -n "this_player()" <securityd>                                       # §7.4/7.59
grep -n "dns_master\|intermud" adm/etc/preload                            # §7.6
grep -rn "is_chinese\|check_legal_name" adm/ secure/                      # §8.1
rg -n '^[ \t]*(nomask[ \t]+)?(private|static)[ \t]+(nomask[ \t]+)?int[ \t]+(command_hook|cmd_hook)\s*\(' --glob '*.lpc'   # §8.3a
grep -rn 'sscanf.*\.c[$"]\|\[0\.\.<3\]\|strlen(.*)-3' adm/ daemon/ secure/ # §8.3b/7.80/7.118
grep -rn "MUD_PORT\|PORTNO" include/                                      # §5.3
grep -rn "shutdown\|rm(\|unlink" <securityd>                              # §7.13
grep -rn "\bstatic\b\|\bstatus\b" --include='*.lpc' --include='*.h' . | head  # §4.3/§6.8
grep -rn "ed_start\|ed_cmd\|query_ed_mode\|efun::set(\|efun::query(" .    # §6.2/§7.15
grep -rn "switch\s*([^)]*)\s*{\s*default:" .                              # §6.3
grep -rn 'replace_program(' --include='*.lpc' . | wc -l                   # §7.86/§7.100
grep -rn 'maximum evaluation cost' config.fluffos                         # §7.90 (use >= 5000000)
```
Also apply the WASM standards: §1.3b, §1.3e, and §1.5.

### 2.3 Hosting modes and already-git-hosted sources

- **`vendored`** (default): no live upstream, so `work/` is the source
  of truth in this repo.
- **`submodule-patch`**: the upstream is active. `work/` is a submodule
  pinned by `upstream.commit`, keeping upstream's own conventions.
  - Catalog-only compat lives in `libs/<slug>/patches/NNNN-name.patch`,
    applied by `scripts/apply_lib_patches.py`.
  - `rebase_upstreams.py` bumps the pin only when every patch still
    `git apply --check`s.
  - `upstream.auto_rebase: false` holds the pin.
  - `upstream.branch` overrides the compare branch (`sagenwelt` uses
    `feature/player`).
- **`fluffos-upstream`**: a live `github.com/fluffos/<repo>`. It uses a
  submodule with **empty** `patches/`. The remote itself follows this
  catalog's conventions (`.lpc`, §9-formatted), so land LPC fixes there.
  - Current: `imud`, `sanguozhi`, `xkx100utf8`, `nt7`, `nightmare3`
    (`work/lib`), `deadsouls_fluffos` (`work/lib`).
  - An archived fluffos-org repo is not a hosting target. `lima` tracks
    `limalib/lima` as `submodule-patch`.
- The site zip contains the **patched playable tree** plus `patches/`
  and `meta.json`.
- `scripts/check_upstream_rebase.py` regenerates
  `scripts/upstream_status.json`. Never hand-edit it.

Lessons from onboarding git-hosted sources (`imud`):
- Still run `convert_lib.sh`.
- A failing file that is upstream's own disabled scaffolding is fine.
- A thin, intentional surface (no rooms, no accounts) is a valid
  "playable".
- **`imud` makes a real outbound Intermud-3 connection at boot.** Keep
  it out of high-frequency reboot loops. Flag any lib that dials out
  from `create()` prominently in its `NOTES.md`.

LDMud-to-FluffOS porting: see `docs/ldmud-to-fluffos.md` and §7.158.
Policy (2026-09-11):
- A port is done when every archive-shipped room, object, and command
  loads and plays. Fix trivial load failures of existing objects.
- **Never invent missing content.**
- A pure skeleton framework with no rooms may add one void/example room
  so it can come online. Never let such a room hide a real world.

---

## 3. Archive extraction traps

- `unrar x -y`, `7z`, `unzip`, and `tar` all work. A self-extracting
  `.exe` opens with `unrar`/`7z`.
- **`7z` can report success while writing all-zero-byte files.**
  Spot-check sizes and retry with `unrar`.
- **A `.rar` that is really a tar with `../` members:** GNU tar refuses
  those members. Extract with Python `tarfile` and strip the `../`.
  `ls | grep` for exact filenames (some have trailing spaces).
- A bare `.gz` can be a tar. Some archives nest the mudlib in an inner
  archive.
- **Binary-only (`.b`, `MUDB` magic) archives** get
  `wasm_status: "binary-pending-tooling"`, never `not-convertible`. Look
  for a 源码版 sibling.
- **A `d/`/`npc/` directory shape is not evidence of LPC.** If
  `grep -rIl inherit` finds nothing, it's a C engine. Don't create a
  `libs/` dir for it.
