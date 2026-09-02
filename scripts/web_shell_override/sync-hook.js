// periodic + on-hide flush of /mudlib/work/data to IndexedDB.
// `driver` and `Module` are top-level `let`/`var` bindings from the main
// inline script earlier in this page -- classic (non-module) scripts in one
// document share a global scope for those, so this reaches them directly.
//
// Flush points: a 5s interval, visibilitychange->hidden (the reliable
// "user may be leaving" signal -- fires on tab switch, minimize, and
// before every pagehide), and pagehide itself as a final best-effort.
// An async IndexedDB write started in pagehide is NOT guaranteed to
// commit before the page dies; the hidden-flush + interval mean the
// window for lost progress is at most one interval of play.
(function () {
  const SLUG = window.FLUFFOS_ZIP_BOOT.slug;
  let syncing = false;
  let stopped = false;   // set by the Reset Data flow so a late interval
                         // tick can't re-create the DB it just deleted
  async function doSync(reason) {
    if (!driver || syncing || stopped) return;
    syncing = true;
    try {
      const n = await PersistFS.sync(driver.FS, SLUG);
      if (n >= 0) {
        console.log('sync-hook: saved ' + n + ' file(s) to IndexedDB (' + reason + ')');
      } // n < 0: IndexedDB unavailable; PersistFS already warned once
    } catch (e) {
      console.error('sync-hook: sync failed', e);
    } finally {
      syncing = false;
    }
  }
  const timer = setInterval(() => doSync('interval'), 5000);
  document.addEventListener('visibilitychange', () => {
    if (document.visibilityState === 'hidden') doSync('hidden');
  });
  window.addEventListener('pagehide', () => doSync('pagehide'));
  window.__forceSync = () => doSync('manual');
  window.__stopSync = () => { stopped = true; clearInterval(timer); };
})();
