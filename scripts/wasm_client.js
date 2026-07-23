#!/usr/bin/env node
// Scriptable smoke-test client for a mudlib running under the WASM build
// of the fluffos driver (see ~/src/fluffos/docs/driver/wasm.md). Mirrors
// scripts/mudclient.py's interface/semantics so the two can be used
// interchangeably in test scripts: a scripted list of --send lines, paced
// by --idle silence, with the full transcript dumped to stdout for grepping.
//
// Unlike mudclient.py this doesn't open a real socket -- it boots an
// in-process WASM driver instance, copies the mudlib's work/ directory into
// its in-memory filesystem, opens one fluffos_connect() "connection", and
// wires fluffos_input/onOutput directly (no telnet negotiation needed --
// the wasm driver's connect() path doesn't send IAC option negotiation the
// way a real telnet listener does for a raw loopback connection).
//
// Usage:
//   node wasm_client.js WASM_BUILD_DIR LIB_ROOT_DIR \
//       [--send LINE ...] [--timeout SEC] [--idle SEC]
//
// LIB_ROOT_DIR is a lib's top-level directory (e.g. libs/bxsj) containing
// both config.fluffos and work/, matching this project's native-driver
// convention (`cd work && driver ../config.fluffos`). config.fluffos's
// `mudlib directory : <absolute host path>` line is rewritten to the
// MEMFS-internal path (/mudlib/work) before boot -- the host's absolute
// path is meaningless inside the wasm instance's virtual filesystem.
//
// Example:
//   node scripts/wasm_client.js ~/src/fluffos/build-wasm/src libs/bxsj \
//       --timeout 20 --idle 1.0 --send "" --send "look" --send "quit"
//
// Exit code 0 on a clean run (driver booted, connection opened); nonzero if
// boot failed. A boot failure or the driver never becoming ready is the
// signal to treat as "does not work under wasm" for a given lib -- inspect
// the printed transcript/stderr for the reason.

const fs = require('fs');
const path = require('path');

function parseArgs(argv) {
  const positional = [];
  const sends = [];
  let timeout = 10.0;
  let idle = 1.0;
  for (let i = 0; i < argv.length; i++) {
    const a = argv[i];
    if (a === '--send') { sends.push(argv[++i]); }
    else if (a === '--timeout') { timeout = parseFloat(argv[++i]); }
    else if (a === '--idle') { idle = parseFloat(argv[++i]); }
    else { positional.push(a); }
  }
  if (sends.length === 0) sends.push('', 'look', 'quit');
  return { positional, sends, timeout, idle };
}

function copyDir(Module, src, dst) {
  try { Module.FS.mkdir(dst); } catch (e) { /* exists */ }
  for (const e of fs.readdirSync(src, { withFileTypes: true })) {
    // Skip the CONTENTS of the runtime-churn directories we no longer
    // track in git anyway (see .gitignore) -- copying them into MEMFS
    // wastes time/memory and they aren't needed for a fresh-boot smoke
    // test. Still create the directory itself: several libs' log_file()/
    // write_file() calls throw (and silently abort the caller, per
    // AGENTS.md's missing-directory-swallows-errors pattern) if the
    // directory doesn't exist at all, even for a brand new file.
    if (e.name === 'log' && dst.endsWith('/work') && e.isDirectory()) {
      try { Module.FS.mkdir(dst + '/log'); } catch (err) { /* exists */ }
      continue;
    }
    const s = path.join(src, e.name);
    const d = dst + '/' + e.name;
    if (e.isDirectory()) copyDir(Module, s, d);
    else if (e.isFile()) {
      try { Module.FS.writeFile(d, fs.readFileSync(s)); }
      catch (err) { /* unreadable special file, e.g. a broken symlink -- skip */ }
    }
  }
}

(async () => {
  const { positional, sends, timeout, idle } = parseArgs(process.argv.slice(2));
  const [buildDirArg, libRootArg] = positional;
  if (!buildDirArg || !libRootArg) {
    console.error('usage: wasm_client.js BUILD_DIR LIB_ROOT_DIR [--send LINE ...] [--timeout SEC] [--idle SEC]');
    process.exit(2);
  }
  const buildDir = path.resolve(buildDirArg);
  const libRoot = path.resolve(libRootArg);
  const mudlibDir = path.join(libRoot, 'work');
  const hostConfigPath = path.join(libRoot, 'config.fluffos');
  const createFluffOS = require(path.join(buildDir, 'fluffos.js'));

  let configText = fs.readFileSync(hostConfigPath, 'utf-8');
  configText = configText.replace(
    /^(\s*mudlib directory\s*:\s*).*$/m, '$1/mudlib/work');

  const transcriptChunks = [];
  let lastOutputAt = Date.now();
  let connId = null;
  let disconnected = false;
  // fluffos_tick() expects a monotonic clock that starts near 0 (it mirrors
  // the browser's performance.now(), used directly in the driver's own
  // docs example) -- NOT Date.now()'s absolute epoch milliseconds. Passing
  // epoch time makes the very first tick call compute a multi-decade
  // "pending ticks" backlog, which the driver's catch-up cap (100
  // gameticks) then replays all at once, fast-forwarding ~100 simulated
  // seconds before the harness has sent a single line.
  const t0 = process.hrtime.bigint();
  const nowMs = () => Number(process.hrtime.bigint() - t0) / 1e6;

  const Module = await createFluffOS({
    wasmBinary: fs.readFileSync(path.join(buildDir, 'fluffos.wasm')),
    print: (s) => process.stderr.write('[stdout] ' + s + '\n'),
    printErr: (s) => process.stderr.write('[stderr] ' + s + '\n'),
  });

  try { Module.FS.mkdir('/mudlib'); } catch (e) { /* exists */ }
  copyDir(Module, mudlibDir, '/mudlib/work');
  Module.FS.writeFile('/mudlib/config.fluffos', configText);
  Module.FS.chdir('/mudlib');
  Module.fluffos = {
    onOutput: (id, bytes) => {
      transcriptChunks.push(Buffer.from(bytes));
      lastOutputAt = Date.now();
    },
    onDisconnect: (id) => { disconnected = true; },
  };

  const rc = Module.ccall('fluffos_boot', 'number', ['string'], ['config.fluffos']);
  if (rc !== 0) {
    console.error('BOOT_FAILED: fluffos_boot returned', rc);
    process.exit(1);
  }

  const tickTimer = setInterval(() => {
    try { Module.ccall('fluffos_tick', 'number', ['number'], [nowMs()]); }
    catch (e) { /* driver may have shut itself down (quit) */ }
  }, 50);

  connId = Module.ccall('fluffos_connect', 'number', [], []);

  const start = Date.now();
  let sendIdx = 0;
  await new Promise((resolve) => {
    const pump = setInterval(() => {
      const elapsed = (Date.now() - start) / 1000;
      const idleFor = (Date.now() - lastOutputAt) / 1000;
      if (elapsed >= timeout || disconnected && sendIdx >= sends.length) {
        clearInterval(pump);
        resolve();
        return;
      }
      if (sendIdx < sends.length && idleFor >= idle) {
        const line = sends[sendIdx] + '\r\n';
        const bytes = Array.from(Buffer.from(line, 'utf-8'));
        try {
          Module.ccall('fluffos_input', null, ['number', 'array', 'number'],
            [connId, bytes, bytes.length]);
        } catch (e) { /* connection already gone */ }
        sendIdx++;
        lastOutputAt = Date.now();
      } else if (sendIdx >= sends.length && idleFor >= idle) {
        clearInterval(pump);
        resolve();
      }
    }, 100);
  });

  clearInterval(tickTimer);
  const text = Buffer.concat(transcriptChunks).toString('utf-8');
  process.stdout.write(text);
  if (!text.trim()) {
    console.error('NOTE: empty transcript (driver produced no output)');
  }
  process.exit(0);
})().catch((e) => {
  if (e && e.name === 'ExitStatus') {
    // The driver called exit() (e.g. shutdown after quit) -- not a harness error.
    process.exit(0);
  }
  console.error('wasm_client.js failed:', e);
  process.exit(1);
});
