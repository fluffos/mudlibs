Prebuilt custom WASM driver for `lima`, `swmud`, and `spacemud`
(both Lima-derived; `spacemud`'s `secure/check_config.lpc` flag list
is identical to `lima`'s, including `#undef ARRAY_RESERVED_WORD`).

These three libs need compile-time options this project's shared driver doesn't
provide -- see `libs/lima/NOTES.md`'s "驱动编译选项冲突"/"wasm_status 审计"
sections for the full investigation. `secure/check_config.c` in each lib
requires:

  - `NO_ADD_ACTION`, `NO_WIZARDS`, `NO_LIGHT` -- defined
  - `OLD_ED` -- undefined
  - `PACKAGE_UIDS` -- OFF (CMake option, not a `local_options` define)

`fluffos.js`/`fluffos.wasm` here are a one-time build from
`fluffos/fluffos@721878c8aa78c092d1e882265ee374585b2df9a7` (2026-08-24), in
a separate worktree (`~/src/fluffos-lima`, not itself checked in anywhere
-- rebuild from that same commit if this needs regenerating):

```
git worktree add ~/src/fluffos-lima 721878c8aa78c092d1e882265ee374585b2df9a7
cd ~/src/fluffos-lima
# src/local_options: NO_ADD_ACTION/NO_WIZARDS/NO_LIGHT #undef -> #define,
# OLD_ED #define -> #undef (see libs/lima/NOTES.md for the exact diff)
source ~/src/emsdk/emsdk_env.sh
cmake --preset native-tools && cmake --build --preset native-tools -- -j8
emcmake cmake --preset wasm -DPACKAGE_UIDS=OFF
cmake --build --preset wasm -- -j8
# -> build-wasm/src/{fluffos.js,fluffos.wasm}
```

Committed here (rather than fetched at CI build time like the shared
driver) because building it needs a full separate `local_options` edit +
emsdk toolchain step this project's CI deliberately doesn't carry (see
AGENTS.md §1.6's "no longer needs emsdk in CI at all") -- these two files
are a fixed, rarely-changing build output, not something that needs to
track every upstream fluffos release the way the shared driver does.

Only `fluffos.js`/`fluffos.wasm` are lib-specific here -- `telnet.js` and
`vendor/xterm.*` are driver-config-independent and stay shared (see
`write_play_page.sh`'s `CUSTOM_DRIVER_DIR` handling).
