
## WASM 修复摘要（迁移自 meta.json 的 group_note）

闭源 C++ 引擎，不是 LPC。

## Shop + 拜师 (2026-09-04)

Not an LPC/FluffOS mudlib. Archive `重出江湖.rar` is a closed-source
Windows C++ engine (`mud.exe` server + separate client). `meta.json`
already marks `wasm_status: not-mudlib`. The shipped 说明文件 says:
click `mud.exe`, wizard id `1` / password `12345`, player ids
1001–1050, client `127.0.0.1:6600`. `raw/MUDSERVER/data/config.txt`
confirms port 6600. No `.lpc` tree, no `config.fluffos`, no FluffOS
driver path. Shop / 拜师 cannot be exercised on this corpus's native
driver — content lives in opaque save objects under
`raw/MUDSERVER/data/`, not in source we can patch. No programming
bug to fix here.
