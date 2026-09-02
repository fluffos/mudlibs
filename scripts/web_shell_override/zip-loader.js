// replaces mudlib.js (emscripten file_packager output). Fetches the
// SAME per-lib source zip already produced for the site's "Download ZIP"
// links, and populates the driver's in-memory FS from it directly --
// no file_packager / emsdk step needed at build time.
//
// Zip format (APPNOTE.TXT): find the End Of Central Directory record by
// scanning backward from EOF for its signature (comment field makes its
// exact offset unpredictable), walk the central directory it points at
// (one fixed-size record + filename per entry), and for each entry seek to
// its *local* file header to find where the actual data starts (local and
// central extra-field lengths can differ, so the central directory's sizes
// alone aren't enough to locate the bytes).
// document.currentScript is only valid during this script tag's own
// synchronous execution -- capture it now for zip-worker.js's URL, needed
// later inside the preRun callback below (which runs long after this
// script has finished its initial pass).
const ZIP_LOADER_SCRIPT_URL = document.currentScript.src;

Module.preRun = Module.preRun || [];
Module.preRun.push(function () {
  Module.addRunDependency('zip-mudlib');
  (async () => {
    const CFG = window.FLUFFOS_ZIP_BOOT;
    const ZIP_URL = CFG.zip;
    const MOUNT = CFG.mount;
    const STRIP_PREFIX = CFG.slug + '/'; // top-level dir name inside the zip

    const resp = await fetch(ZIP_URL);
    if (!resp.ok) {
      throw new Error('zip-loader: fetch of ' + ZIP_URL + ' failed: HTTP ' + resp.status);
    }
    const buf = new Uint8Array(await resp.arrayBuffer());
    const dv = new DataView(buf.buffer);

    // --- locate EOCD (scan back up to 64KB + comment for the signature) --
    const EOCD_SIG = 0x06054b50;
    let eocd = -1;
    for (let i = buf.length - 22; i >= Math.max(0, buf.length - 22 - 65557); i--) {
      if (dv.getUint32(i, true) === EOCD_SIG) { eocd = i; break; }
    }
    if (eocd < 0) throw new Error('zip-loader: End Of Central Directory not found');
    const cdEntries = dv.getUint16(eocd + 10, true);
    const cdOffset = dv.getUint32(eocd + 16, true);
    // No zip64 support, deliberately: the 0xFFFF/0xFFFFFFFF sentinels only
    // appear past 65535 entries or 4GB -- the site's per-lib source zips
    // top out around 43K files / a few hundred MB, nowhere close.  Fail
    // loudly rather than misparse if one ever does cross the line.
    if (cdEntries === 0xffff || cdOffset === 0xffffffff) {
      throw new Error('zip-loader: zip64 archives are not supported');
    }

    const decoder = new TextDecoder();
    const dirsMade = new Set();
    function ensureDir(path) {
      if (dirsMade.has(path)) return;
      const parts = path.split('/').filter(Boolean);
      let cur = '';
      for (const p of parts) {
        cur += '/' + p;
        if (!dirsMade.has(cur)) {
          try { Module.FS.mkdir(cur); } catch (e) { /* EEXIST is fine */ }
          dirsMade.add(cur);
        }
      }
      dirsMade.add(path);
    }

    // Pass 1: walk the central directory (cheap, synchronous -- just
    // pointer arithmetic over the already-fetched buffer) into a plain
    // list of file entries. Kept separate from pass 2 so the actual
    // per-file work below can run concurrently instead of one entry fully
    // finishing (including its async decompression round-trip) before the
    // next even starts -- see pass 2's comment for why that serial form
    // was a real problem, not just untidy.
    const files = [];
    let p = cdOffset;
    const CD_SIG = 0x02014b50;
    const LFH_SIG = 0x04034b50;
    for (let i = 0; i < cdEntries; i++) {
      if (dv.getUint32(p, true) !== CD_SIG) throw new Error('zip-loader: bad central directory entry at ' + p);
      const method = dv.getUint16(p + 10, true);
      const compSize = dv.getUint32(p + 20, true);
      const uncompSize = dv.getUint32(p + 24, true);
      const nameLen = dv.getUint16(p + 28, true);
      const extraLen = dv.getUint16(p + 30, true);
      const commentLen = dv.getUint16(p + 32, true);
      const lfhOffset = dv.getUint32(p + 42, true);
      const name = decoder.decode(buf.subarray(p + 46, p + 46 + nameLen));

      let vpath = null;
      if (name.startsWith(STRIP_PREFIX)) {
        const rel = name.slice(STRIP_PREFIX.length);
        if (rel !== '') vpath = MOUNT + '/' + rel;
      }
      if (vpath && !name.endsWith('/')) {
        // local file header -> real data start (its name/extra lengths can
        // differ from the central directory's own copy)
        if (dv.getUint32(lfhOffset, true) !== LFH_SIG) {
          throw new Error('zip-loader: bad local file header for ' + name + ' at ' + lfhOffset);
        }
        const lfhNameLen = dv.getUint16(lfhOffset + 26, true);
        const lfhExtraLen = dv.getUint16(lfhOffset + 28, true);
        const dataStart = lfhOffset + 30 + lfhNameLen + lfhExtraLen;
        files.push({ name, vpath, method, uncompSize,
                     raw: buf.subarray(dataStart, dataStart + compSize) });
      } else if (vpath) {
        ensureDir(vpath.replace(/\/$/, ''));
      }

      p = p + 46 + nameLen + extraLen + commentLen;
    }

    // Pass 2: decompress + write. A real lib zip can hold 50-60K+ entries
    // (e.g. one real lib: ~60K files, each its own independent DEFLATE
    // stream) -- an earlier version of this file awaited each one in turn
    // on the main thread, which measured as the driver appearing to hang
    // for well over a minute on a large lib. Running many
    // DecompressionStream calls "concurrently" on the SAME thread doesn't
    // fix that: the per-call JS-side overhead (Blob/stream construction,
    // promise scheduling) is bound to that one thread regardless of how
    // many are in flight, so wall-clock time barely improves no matter the
    // concurrency level. Real multi-core parallelism needs actual threads:
    // zip-worker.js instances, each independently decompressing whatever
    // entry the pool below hands it next. Workers can't reach Module.FS at
    // all, so every filesystem write still happens here, on the main
    // thread, right after collecting a worker's result -- ensureDir()'s
    // mkdir-if-missing is safe under this pattern since it never overlaps
    // with another write (there is only one consumer of worker results).
    const STORED = files.filter((f) => f.method === 0);
    const DEFLATED = files.filter((f) => f.method === 8);
    const badMethod = files.find((f) => f.method !== 0 && f.method !== 8);
    if (badMethod) {
      throw new Error('zip-loader: unsupported compression method ' + badMethod.method + ' for ' + badMethod.name);
    }

    function writeEntry(f, data) {
      if (data.length !== f.uncompSize) {
        throw new Error('zip-loader: size mismatch for ' + f.name + ': got ' + data.length + ' want ' + f.uncompSize);
      }
      const slash = f.vpath.lastIndexOf('/');
      ensureDir(f.vpath.slice(0, slash));
      if (f.vpath === MOUNT + '/config.fluffos') {
        let text = decoder.decode(data);
        text = text.replace(/^(\s*mudlib directory\s*:\s*).*$/m, '$1' + MOUNT + '/work');
        data = new TextEncoder().encode(text);
      }
      Module.FS.writeFile(f.vpath, data);
    }

    // STORED entries need no decompression at all -- handle them directly,
    // no worker round-trip to pay for.
    for (const f of STORED) writeEntry(f, f.raw.slice());

    if (DEFLATED.length > 0) {
      // No upper cap beyond hardwareConcurrency: this is genuinely
      // CPU-bound work (median lib in this corpus: ~10K files; some run
      // past 60K), so a visitor with more cores should get to use them.
      // The pool self-limits to DEFLATED.length for small libs regardless.
      const POOL_SIZE = Math.max(1, navigator.hardwareConcurrency || 4);
      const workers = Array.from(
        { length: Math.min(POOL_SIZE, DEFLATED.length) },
        () => new Worker(new URL('zip-worker.js', ZIP_LOADER_SCRIPT_URL)));
      let next = 0;
      let completed = 0;
      let firstError = null;
      const reportProgress = () => {
        // Throttled: a DOM/style write on every one of 60K+ completions
        // would add its own real overhead on top of the work being
        // measured. Indeterminate before the first batch reports back --
        // no numbers are better than a bar that jumps from 0 straight to
        // done for a fast-enough lib.
        if (completed === 0) return;
        if (typeof BootProgress !== 'undefined') {
          BootProgress.set('loading game files — ' + completed + ' / ' + DEFLATED.length,
                           completed / DEFLATED.length);
        }
      };
      const progressTimer = setInterval(reportProgress, 200);
      await Promise.all(workers.map((w) => new Promise((resolve) => {
        const dispatchNext = () => {
          if (firstError || next >= DEFLATED.length) { w.terminate(); resolve(); return; }
          const idx = next++;
          const view = DEFLATED[idx].raw;
          // raw is a Uint8Array VIEW into the whole zip's shared buffer
          // (from .subarray()) -- copy just this entry's bytes into their
          // own ArrayBuffer first, since transferring a slice of a shared
          // buffer isn't possible (it would neuter every other entry's
          // view into the same buffer). The Uint8Array wrapping that new
          // buffer survives the transfer intact (structured clone relinks
          // it to the moved buffer on the worker side).
          const owned = view.buffer.slice(view.byteOffset, view.byteOffset + view.byteLength);
          w.postMessage({ id: idx, raw: new Uint8Array(owned) }, [owned]);
        };
        w.onmessage = (ev) => {
          const { id, ok, data, error } = ev.data;
          completed++;
          if (!ok) { firstError = firstError || new Error('zip-worker: ' + error + ' for ' + DEFLATED[id].name); dispatchNext(); return; }
          try { writeEntry(DEFLATED[id], data); }
          catch (e) { firstError = firstError || e; }
          dispatchNext();
        };
        w.onerror = (ev) => {
          firstError = firstError || new Error('zip-worker crashed: ' + ev.message);
          dispatchNext();
        };
        dispatchNext();
      })));
      clearInterval(progressTimer);
      if (firstError) throw firstError;
    }

    // The zip excludes /log/ (same trim as make_source_zips.sh), but many
    // libs' log_file()/write_file() calls crash on a missing directory --
    // see pack_lib_for_web.sh's own "config's `log directory : /log`"
    // fallback, and its wasm_keep_dirs.txt mechanism for the other
    // git-doesn't-track-empty-dirs cases (data/board, daemon/class, ...).
    ensureDir(MOUNT + '/work/log');
    for (const rel of (CFG.keepDirs || [])) ensureDir(MOUNT + '/work/' + rel);

    // Persistence must never block boot: restore() returns -1 (after its
    // own warning) when IndexedDB is unavailable, and the belt-and-braces
    // try/catch covers anything unexpected it might still throw.
    let restored = -1;
    try { restored = await PersistFS.restore(Module.FS, CFG.slug); }
    catch (e) { console.warn('zip-loader: save restore failed, booting fresh:', e); }
    console.log('zip-loader: populated ' + MOUNT + ' from ' + ZIP_URL +
                ', restored ' + restored + ' saved file(s) from IndexedDB');
  })().then(
    () => Module.removeRunDependency('zip-mudlib'),
    (e) => {
      // Deliberately do NOT removeRunDependency here: letting the driver
      // boot on a half-populated FS produces far more confusing LPC-level
      // errors than a clearly-stopped boot with a visible cause.
      console.error('zip-loader failed:', e);
      if (typeof ErrorModal !== 'undefined') {
        ErrorModal.show('Failed to load game files', e,
                        'zip: ' + window.FLUFFOS_ZIP_BOOT.zip);
      }
    });
});
