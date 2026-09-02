// export the persisted /mudlib/work/data tree as a downloadable .zip
// (same format as everything else in this pipeline -- a player can inspect
// it with any zip tool), and import a previously-downloaded one back in.
// IndexedDB is per-browser-profile and gets wiped by private browsing,
// "clear site data", or storage-pressure eviction -- this is the escape
// hatch: move a save between browsers/devices, or just keep an offline
// backup, the same way web-based emulators let you export/import save
// states.
const SaveExport = (() => {
  function crc32(bytes) {
    let c, crc = 0xffffffff;
    for (let i = 0; i < bytes.length; i++) {
      c = (crc ^ bytes[i]) & 0xff;
      for (let k = 0; k < 8; k++) c = (c & 1) ? (0xedb88320 ^ (c >>> 1)) : (c >>> 1);
      crc = (crc >>> 8) ^ c;
    }
    return (crc ^ 0xffffffff) >>> 0;
  }

  async function deflateRaw(bytes) {
    const ds = new CompressionStream('deflate-raw');
    const stream = new Blob([bytes]).stream().pipeThrough(ds);
    return new Uint8Array(await new Response(stream).arrayBuffer());
  }

  function dosDateTime(d) {
    const time = ((d.getHours() & 0x1f) << 11) | ((d.getMinutes() & 0x3f) << 5) | ((d.getSeconds() >> 1) & 0x1f);
    const date = (((d.getFullYear() - 1980) & 0x7f) << 9) | (((d.getMonth() + 1) & 0xf) << 5) | (d.getDate() & 0x1f);
    return { time, date };
  }

  // files: [{name, bytes}], name is the path INSIDE the zip (e.g. "data/user/f/x.o")
  async function buildZip(files) {
    // EOCD entry counts are 16-bit and this writer has no zip64 support;
    // save trees are a few hundred files at most, so just refuse rather
    // than silently truncate the counts if that assumption ever breaks.
    if (files.length > 0xffff) {
      throw new Error('buildZip: too many files for a non-zip64 archive (' + files.length + ')');
    }
    const encoder = new TextEncoder();
    const { time, date } = dosDateTime(new Date());
    const localParts = [];
    const centralParts = [];
    let offset = 0;
    let cdSize = 0;

    for (const { name, bytes } of files) {
      const nameBytes = encoder.encode(name);
      const crc = crc32(bytes);
      const compressed = await deflateRaw(bytes);
      // only use the compressed form if it's actually smaller (small/random
      // save files sometimes aren't) -- store the raw bytes otherwise
      const useDeflate = compressed.length < bytes.length;
      const method = useDeflate ? 8 : 0;
      const data = useDeflate ? compressed : bytes;

      const lfh = new DataView(new ArrayBuffer(30));
      lfh.setUint32(0, 0x04034b50, true);
      lfh.setUint16(4, 20, true);           // version needed
      lfh.setUint16(6, 0, true);            // flags
      lfh.setUint16(8, method, true);
      lfh.setUint16(10, time, true);
      lfh.setUint16(12, date, true);
      lfh.setUint32(14, crc, true);
      lfh.setUint32(18, data.length, true); // compressed size
      lfh.setUint32(22, bytes.length, true);// uncompressed size
      lfh.setUint16(26, nameBytes.length, true);
      lfh.setUint16(28, 0, true);           // extra length
      localParts.push(new Uint8Array(lfh.buffer), nameBytes, data);

      const cdh = new DataView(new ArrayBuffer(46));
      cdh.setUint32(0, 0x02014b50, true);
      cdh.setUint16(4, 20, true);
      cdh.setUint16(6, 20, true);
      cdh.setUint16(8, 0, true);
      cdh.setUint16(10, method, true);
      cdh.setUint16(12, time, true);
      cdh.setUint16(14, date, true);
      cdh.setUint32(16, crc, true);
      cdh.setUint32(20, data.length, true);
      cdh.setUint32(24, bytes.length, true);
      cdh.setUint16(28, nameBytes.length, true);
      cdh.setUint16(30, 0, true);           // extra length
      cdh.setUint16(32, 0, true);           // comment length
      cdh.setUint16(34, 0, true);           // disk number
      cdh.setUint16(36, 0, true);           // internal attrs
      cdh.setUint32(38, 0, true);           // external attrs
      cdh.setUint32(42, offset, true);      // local header offset
      centralParts.push(new Uint8Array(cdh.buffer), nameBytes);

      offset += 30 + nameBytes.length + data.length;
      cdSize += 46 + nameBytes.length;
    }

    const cdStart = offset;

    const eocd = new DataView(new ArrayBuffer(22));
    eocd.setUint32(0, 0x06054b50, true);
    eocd.setUint16(4, 0, true);
    eocd.setUint16(6, 0, true);
    eocd.setUint16(8, files.length, true);
    eocd.setUint16(10, files.length, true);
    eocd.setUint32(12, cdSize, true);
    eocd.setUint32(16, cdStart, true);
    eocd.setUint16(20, 0, true);

    return new Blob([...localParts, ...centralParts, new Uint8Array(eocd.buffer)],
                     { type: 'application/zip' });
  }

  async function download(FS, slug) {
    const files = [];
    (function walk(dir) {
      let entries;
      try { entries = FS.readdir(dir); } catch (e) { return; }
      for (const e of entries) {
        if (e === '.' || e === '..') continue;
        const p = dir + '/' + e;
        let st;
        try { st = FS.stat(p); } catch (e) { continue; }
        if (FS.isDir(st.mode)) walk(p);
        else files.push({ name: p.slice('/mudlib/work/'.length), bytes: FS.readFile(p) });
      }
    })('/mudlib/work/data');

    const blob = await buildZip(files);
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = slug + '-save-' + new Date().toISOString().slice(0, 10) + '.zip';
    document.body.appendChild(a);
    a.click();
    a.remove();
    setTimeout(() => URL.revokeObjectURL(url), 5000);
    return files.length;
  }

  // Parses an uploaded zip (same format read logic as zip-loader.js, kept
  // separate rather than shared: this one has no --preload directory
  // prefix to strip and writes into IndexedDB, not the live FS) and stores
  // every entry into IndexedDB, keyed the same way PersistFS.sync uses
  // (relative to work/data/), so the next boot's restore() picks it up.
  // This one parses hostile input (any file the user picks), so it
  // validates everything the boot-time loader can afford to assume about
  // our own zips: signatures, encryption/zip64 flags, CRCs, and -- most
  // important -- entry names, which become IndexedDB keys that
  // PersistFS.restore() turns into FS paths at next boot.  Only entries
  // under "data/" are accepted (the only prefix download() ever writes);
  // anything else in the zip is counted and skipped, and a zip with zero
  // data/ entries is rejected as "not a save export".
  async function importZip(file, slug) {
    const buf = new Uint8Array(await file.arrayBuffer());
    const dv = new DataView(buf.buffer);
    const decoder = new TextDecoder();

    const EOCD_SIG = 0x06054b50;
    let eocd = -1;
    for (let i = buf.length - 22; i >= Math.max(0, buf.length - 22 - 65557); i--) {
      if (dv.getUint32(i, true) === EOCD_SIG) { eocd = i; break; }
    }
    if (eocd < 0) throw new Error('importZip: not a valid zip (no EOCD)');
    const cdEntries = dv.getUint16(eocd + 10, true);
    let p = dv.getUint32(eocd + 16, true);
    if (cdEntries === 0xffff || p === 0xffffffff) {
      throw new Error('importZip: zip64 archives are not supported');
    }

    // Parse and decompress everything BEFORE opening the write transaction
    // (an IDB tx auto-commits when the event loop runs dry, and awaiting
    // DecompressionStream mid-transaction would do exactly that).
    const entries = [];
    let skipped = 0;
    for (let i = 0; i < cdEntries; i++) {
      if (p + 46 > buf.length || dv.getUint32(p, true) !== 0x02014b50) {
        throw new Error('importZip: bad central directory entry at ' + p);
      }
      const flags = dv.getUint16(p + 8, true);
      const method = dv.getUint16(p + 10, true);
      const wantCrc = dv.getUint32(p + 16, true);
      const compSize = dv.getUint32(p + 20, true);
      const uncompSize = dv.getUint32(p + 24, true);
      const nameLen = dv.getUint16(p + 28, true);
      const extraLen = dv.getUint16(p + 30, true);
      const commentLen = dv.getUint16(p + 32, true);
      const lfhOffset = dv.getUint32(p + 42, true);
      const name = decoder.decode(buf.subarray(p + 46, p + 46 + nameLen));
      p = p + 46 + nameLen + extraLen + commentLen;
      if (name.endsWith('/')) continue;                 // directory entry
      if (flags & 0x1) throw new Error('importZip: encrypted zips are not supported');
      const rel = name.startsWith('data/') ? PersistFS.safeRel(name.slice('data/'.length)) : null;
      if (rel === null) { skipped++; continue; }        // not save data / unsafe path
      if (lfhOffset + 30 > buf.length || dv.getUint32(lfhOffset, true) !== 0x04034b50) {
        throw new Error('importZip: bad local file header for ' + name);
      }
      const lfhNameLen = dv.getUint16(lfhOffset + 26, true);
      const lfhExtraLen = dv.getUint16(lfhOffset + 28, true);
      const dataStart = lfhOffset + 30 + lfhNameLen + lfhExtraLen;
      if (dataStart + compSize > buf.length) {
        throw new Error('importZip: truncated data for ' + name);
      }
      const raw = buf.subarray(dataStart, dataStart + compSize);
      let data;
      if (method === 0) data = raw.slice();
      else if (method === 8) {
        const ds = new DecompressionStream('deflate-raw');
        const stream = new Blob([raw]).stream().pipeThrough(ds);
        data = new Uint8Array(await new Response(stream).arrayBuffer());
      } else throw new Error('importZip: unsupported method ' + method + ' for ' + name);
      if (data.length !== uncompSize) throw new Error('importZip: size mismatch for ' + name);
      if (crc32(data) !== wantCrc) throw new Error('importZip: CRC mismatch for ' + name + ' (corrupt file?)');
      entries.push({ rel, data });
    }
    if (entries.length === 0) {
      throw new Error('importZip: no data/ entries found -- this does not look ' +
                      'like a save exported from this page' +
                      (skipped ? ' (' + skipped + ' other entr' + (skipped === 1 ? 'y' : 'ies') + ' ignored)' : ''));
    }
    if (skipped) console.warn('importZip: ignored ' + skipped + ' non-save entr' + (skipped === 1 ? 'y' : 'ies'));

    const db = await PersistFS.openDB(slug);  // throws if IndexedDB unavailable
    try {
      await new Promise((resolve, reject) => {
        const tx = db.transaction(PersistFS.STORE, 'readwrite');
        const store = tx.objectStore(PersistFS.STORE);
        for (const { rel, data } of entries) store.put(data, rel);
        tx.oncomplete = resolve;
        tx.onerror = () => reject(tx.error);
        tx.onabort = () => reject(tx.error);
      });
    } finally {
      db.close();
    }
    return entries.length;
  }

  return { download, importZip };
})();
