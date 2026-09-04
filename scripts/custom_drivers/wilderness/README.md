Prebuilt custom WASM driver for `wilderness`.

This 2000-era LIMA snapshot needs the same compile-time options as
`lima`/`swmud`/`spacemud` (`NO_ADD_ACTION`, `NO_WIZARDS`, `NO_LIGHT`
defined; `OLD_ED` undefined; `PACKAGE_UIDS` OFF) **plus** the opposite
`ARRAY_RESERVED_WORD` direction (`#define`, not `#undef`). The
lima-flavor binary in `../lima_swmud/` therefore cannot boot this lib
-- `check_config.lpc` fails on that one flag. See AGENTS.md §7.46 and
`libs/wilderness/NOTES.md`.

`fluffos.js`/`fluffos.wasm` here are a one-time build from
`fluffos/fluffos@721878c8aa78c092d1e882265ee374585b2df9a7` (same commit
as the lima-flavor custom driver), in a separate worktree
(`~/src/fluffos-wilderness`, not itself checked in):

```
# worktree already exists for native play; local_options already has
# ARRAY_RESERVED_WORD defined (see libs/wilderness/NOTES.md).
cd ~/src/fluffos-wilderness
source ~/src/emsdk/emsdk_env.sh
cmake --preset native-tools && cmake --build --preset native-tools -- -j8
emcmake cmake --preset wasm -DPACKAGE_UIDS=OFF
cmake --build --preset wasm -- -j8
# -> build-wasm/src/{fluffos.js,fluffos.wasm}
```

Committed here because CI does not carry emsdk (AGENTS.md §1.6).
`telnet.js` and `vendor/xterm.*` stay shared.
