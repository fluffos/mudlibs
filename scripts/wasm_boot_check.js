#!/usr/bin/env node
// Boot a PACKED web bundle (mudlib.js + mudlib.data, as produced by
// scripts/pack_lib_for_web.sh) inside the WASM driver under node -- the same
// way tools/wasm/run-testsuite.js boots the testsuite, but through the real
// file_packager image instead of copying files into MEMFS by hand.  This
// proves the trimmed, packed tree actually boots (catches over-aggressive
// trimming and packer regressions) without needing a browser.
//
// Usage:
//   node scripts/wasm_boot_check.js <packed_lib_dir> <driver_dir> [--timeout SEC]
//
//   <packed_lib_dir>  dir with mudlib.js / mudlib.data / fluffos-boot.js
//   <driver_dir>      dir with fluffos.js / fluffos.wasm (e.g. site/_driver)
//
// Exit 0 when fluffos_boot() returns 0 AND a connection opens (output
// received); nonzero otherwise.  The connection transcript goes to stdout,
// driver noise to stderr.

const fs = require('fs');
const path = require('path');
const vm = require('vm');

function parseArgs(argv) {
  const positional = [];
  let timeout = 15.0;
  for (let i = 0; i < argv.length; i++) {
    if (argv[i] === '--timeout') timeout = parseFloat(argv[++i]);
    else positional.push(argv[i]);
  }
  return { positional, timeout };
}

(async () => {
  const { positional, timeout } = parseArgs(process.argv.slice(2));
  const [libDirArg, driverDirArg] = positional;
  if (!libDirArg || !driverDirArg) {
    console.error('usage: wasm_boot_check.js <packed_lib_dir> <driver_dir> [--timeout SEC]');
    process.exit(2);
  }
  const libDir = path.resolve(libDirArg);
  const driverDir = path.resolve(driverDirArg);

  // fluffos-boot.js assigns window.FLUFFOS_BOOT -- evaluate it with a stub.
  const bootSrc = fs.readFileSync(path.join(libDir, 'fluffos-boot.js'), 'utf-8');
  const fakeWindow = {};
  vm.runInNewContext(bootSrc, { window: fakeWindow });
  const BOOT = fakeWindow.FLUFFOS_BOOT;
  if (!BOOT || !BOOT.mount || !BOOT.config) {
    console.error('error: fluffos-boot.js did not define FLUFFOS_BOOT');
    process.exit(1);
  }

  const Module = {
    // Mirrors the patched per-lib page: .wasm from the shared driver dir,
    // everything else (mudlib.data) from the lib dir.  file_packager's node
    // path does require('fs').readFileSync(locateFile(...)).
    locateFile: (f) => f.endsWith('.wasm') ? path.join(driverDir, f)
                                           : path.join(libDir, f),
    print: (s) => process.stderr.write('[stdout] ' + s + '\n'),
    printErr: (s) => process.stderr.write('[stderr] ' + s + '\n'),
  };

  // mudlib.js is browser-style glue: it expects a global `Module` object and
  // uses require() for its node code path.  Feed it both via a function scope.
  const glueSrc = fs.readFileSync(path.join(libDir, 'mudlib.js'), 'utf-8');
  new Function('require', 'Module', glueSrc)(require, Module);

  const createFluffOS = require(path.join(driverDir, 'fluffos.js'));
  const M = await createFluffOS(Module);

  M.FS.chdir(BOOT.mount);
  const transcript = [];
  let gotOutput = false;
  M.fluffos = {
    onOutput: (id, bytes) => { gotOutput = true; transcript.push(Buffer.from(bytes)); },
    onDisconnect: () => {},
  };

  const rc = M.ccall('fluffos_boot', 'number', ['string'], [BOOT.config]);
  if (rc !== 0) {
    console.error('BOOT_FAILED: fluffos_boot returned', rc);
    process.exit(1);
  }
  console.error('boot ok (rc=0), opening connection...');

  // Monotonic near-zero clock for fluffos_tick (see scripts/wasm_client.js).
  const t0 = process.hrtime.bigint();
  const nowMs = () => Number(process.hrtime.bigint() - t0) / 1e6;
  const tick = setInterval(() => {
    try { M.ccall('fluffos_tick', 'number', ['number'], [nowMs()]); } catch (e) {}
  }, 50);

  const connId = M.ccall('fluffos_connect', 'number', [], []);
  const deadline = Date.now() + timeout * 1000;
  await new Promise((resolve) => {
    const poll = setInterval(() => {
      if (gotOutput || Date.now() > deadline) { clearInterval(poll); resolve(); }
    }, 100);
  });
  clearInterval(tick);

  process.stdout.write(Buffer.concat(transcript).toString('utf-8'));
  if (connId < 0) {
    console.error('CHECK_FAILED: fluffos_connect returned ' + connId);
    process.exit(1);
  }
  if (!gotOutput) {
    console.error('CHECK_FAILED: no output received on the connection within '
                  + timeout + 's');
    process.exit(1);
  }
  console.error('\nCHECK_OK: booted from packed image, connection ' + connId
                + ' produced output');
  process.exit(0);
})().catch((e) => {
  if (e && e.name === 'ExitStatus') process.exit(0); // driver exit() after quit
  console.error('wasm_boot_check.js failed:', e);
  process.exit(1);
});
