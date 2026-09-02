// persist player-save state across reloads via a hand-rolled
// IndexedDB overlay, since this driver build has no IDBFS compiled in
// (checked: driver.FS.filesystems.IDBFS is undefined) -- FS.readFile/
// writeFile are always available regardless, so this works with any
// Emscripten build, not just ones built with -lidbfs.js.
//
// Only /mudlib/work/data is persisted (player saves, boards) -- never the
// LPC source/config, which must always come fresh from the zip so a
// returning player can't get stuck on code we've since fixed upstream.
//
// Robustness contract: NOTHING in here may break boot.  If IndexedDB is
// unavailable (some private-browsing modes disable it entirely, and in a
// few the global accessor itself throws), restore()/sync() log one warning
// and return -1 -- the game still plays, just without persistence.
const PersistFS = (() => {
  const DATA_ROOT = '/mudlib/work/data';
  const DB_NAME = 'fluffos-save';
  const STORE = 'files';

  let warned = false;
  function idb() {
    try {
      if (typeof indexedDB !== 'undefined' && indexedDB) return indexedDB;
    } catch (e) { /* accessor itself can throw in some sandboxed contexts */ }
    if (!warned) {
      warned = true;
      console.warn('PersistFS: IndexedDB unavailable -- game will play but ' +
                   'progress will NOT survive a reload. Use the save ' +
                   'download/import buttons to keep progress.');
    }
    return null;
  }

  function openDB(slug) {
    return new Promise((resolve, reject) => {
      const factory = idb();
      if (!factory) return reject(new Error('IndexedDB unavailable'));
      let req;
      try { req = factory.open(DB_NAME + '-' + slug, 1); }
      catch (e) { return reject(e); }  // open() itself throws in some modes
      req.onupgradeneeded = () => req.result.createObjectStore(STORE);
      req.onsuccess = () => resolve(req.result);
      req.onerror = () => reject(req.error);
    });
  }

  // Keys are paths relative to DATA_ROOT.  They normally come from our own
  // sync(), but importZip() feeds this store from user-supplied zips, so
  // treat every key as hostile: no absolute paths, no '..' segments --
  // otherwise a crafted zip could overwrite LPC code outside work/data on
  // the next boot, exactly what the header above promises never happens.
  function safeRel(relpath) {
    if (typeof relpath !== 'string' || relpath === '' || relpath[0] === '/') return null;
    const parts = relpath.split('/');
    if (parts.some((p) => p === '' || p === '.' || p === '..')) return null;
    return relpath;
  }

  function walk(FS, dir) {
    let out = [];
    let entries;
    try { entries = FS.readdir(dir); } catch (e) { return out; }
    for (const e of entries) {
      if (e === '.' || e === '..') continue;
      const p = dir + '/' + e;
      let st;
      try { st = FS.stat(p); } catch (e) { continue; }
      if (FS.isDir(st.mode)) out = out.concat(walk(FS, p));
      else out.push(p);
    }
    return out;
  }

  async function restore(FS, slug) {
    let db;
    try { db = await openDB(slug); }
    catch (e) {
      console.warn('PersistFS.restore skipped:', e && e.message || e);
      return -1;
    }
    try {
      // one readonly transaction: getAllKeys()/getAll() both return in key
      // order per spec, so index i of one corresponds to index i of the
      // other -- and a single tx means they can't diverge mid-read.
      const [keys, vals] = await new Promise((resolve, reject) => {
        const tx = db.transaction(STORE, 'readonly');
        const store = tx.objectStore(STORE);
        const kreq = store.getAllKeys();
        const vreq = store.getAll();
        tx.oncomplete = () => resolve([kreq.result, vreq.result]);
        tx.onerror = () => reject(tx.error);
        tx.onabort = () => reject(tx.error);
      });
      let restored = 0;
      for (let i = 0; i < keys.length; i++) {
        const relpath = safeRel(keys[i]);
        if (relpath === null) {
          console.warn('PersistFS.restore: skipping unsafe key', keys[i]);
          continue;
        }
        const full = DATA_ROOT + '/' + relpath;
        const parts = full.slice(0, full.lastIndexOf('/')).split('/').filter(Boolean);
        let cur = '';
        for (const part of parts) {
          cur += '/' + part;
          try { FS.mkdir(cur); } catch (e) { /* EEXIST is fine */ }
        }
        FS.writeFile(full, vals[i]);
        restored++;
      }
      return restored;
    } finally {
      db.close();
    }
  }

  async function sync(FS, slug) {
    const paths = walk(FS, DATA_ROOT);
    let db;
    try { db = await openDB(slug); }
    catch (e) { return -1; }  // idb() already warned once
    try {
      const live = new Set(paths.map((p) => p.slice(DATA_ROOT.length + 1)));
      await new Promise((resolve, reject) => {
        const tx = db.transaction(STORE, 'readwrite');
        const store = tx.objectStore(STORE);
        // drop keys whose file no longer exists in the live FS (deleted
        // player, cleaned board post) -- otherwise they resurrect on the
        // next boot's restore()
        const kreq = store.getAllKeys();
        kreq.onsuccess = () => {
          for (const k of kreq.result) if (!live.has(k)) store.delete(k);
          for (const full of paths) {
            store.put(FS.readFile(full), full.slice(DATA_ROOT.length + 1));
          }
        };
        tx.oncomplete = resolve;
        tx.onerror = () => reject(tx.error);
        tx.onabort = () => reject(tx.error);
      });
      return paths.length;
    } finally {
      db.close();
    }
  }

  // openDB/safeRel/STORE are exported for save-export.js (import path) and
  // the Reset Data button -- one definition of the DB layout, not three.
  return { restore, sync, openDB, safeRel, STORE, DB_NAME };
})();
