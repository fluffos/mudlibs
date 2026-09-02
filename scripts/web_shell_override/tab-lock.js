// single-tab guard.  Two tabs of the same lib would each boot an
// independent driver, both restore from the SAME IndexedDB state, and both
// sync back to it -- a last-writer-wins race that silently loses progress.
// So: one tab plays, any other tab of the same slug gets a friendly
// blocking screen instead of a driver.
//
// Mechanism: the Web Locks API (navigator.locks), the browser-native
// primitive for exactly this -- locks are scoped per-origin and shared
// across tabs/workers, and are released automatically when the holding
// context dies (tab close, crash, navigation), so there's no stale-lock
// cleanup problem like a localStorage flag would have.
//
//   - acquire with { ifAvailable: true }: resolves immediately with a null
//     lock if another tab already holds it (never queues -- queueing would
//     boot the second tab the moment the first closes, mid-whatever the
//     user is doing).
//   - if acquired: hold for the tab's whole lifetime by returning a promise
//     from the lock callback that only resolves on pagehide (the standard
//     "hold until this tab goes away" idiom).
//   - if not: replace createFluffOS with a stub that shows the blocking
//     overlay and never resolves -- the driver, the zip fetch, the
//     IndexedDB restore and the sync loop all simply never start
//     (sync-hook's doSync() no-ops while `driver` is null).
//
// LOAD ORDER: this file must come AFTER ../_driver/fluffos.js (it wraps
// the createFluffOS global that script defines) and BEFORE the main inline
// boot script that calls createFluffOS(Module).
(function () {
  const SLUG = window.FLUFFOS_ZIP_BOOT.slug;
  const LOCK_NAME = 'fluffos-play-' + SLUG;

  let releaseHold;
  const holdUntilGone = new Promise((res) => { releaseHold = res; });
  window.addEventListener('pagehide', () => releaseHold());

  const acquired = new Promise((resolve) => {
    if (!navigator.locks || !navigator.locks.request) {
      // No Web Locks (very old browser): fail OPEN.  Playing without the
      // guard beats refusing to play at all; the guard is best-effort.
      resolve(true);
      return;
    }
    navigator.locks.request(LOCK_NAME, { mode: 'exclusive', ifAvailable: true },
      (lock) => {
        if (!lock) { resolve(false); return; }   // another tab holds it
        resolve(true);
        return holdUntilGone;                    // keep it until pagehide
      }).catch((e) => {
        console.warn('tab-lock: Web Locks request failed, playing unguarded:', e);
        resolve(true);
      });
  });

  // A page restored from the back/forward cache resumes with its lock long
  // since auto-released (its pagehide already ran) -- reload instead of
  // resuming, so it goes back through the gate like any fresh load.
  window.addEventListener('pageshow', (ev) => {
    if (ev.persisted) location.reload();
  });

  function showBlocked() {
    const boot = document.getElementById('boot');
    if (boot) boot.style.display = 'none';
    const statusEl = document.getElementById('status');
    if (statusEl) statusEl.textContent = 'open in another tab';
    const div = document.createElement('div');
    div.id = 'tabLockBlocked';
    div.style.cssText =
      'position:fixed;inset:0;z-index:10000;display:flex;flex-direction:column;' +
      'align-items:center;justify-content:center;gap:14px;background:#10151c;' +
      'color:#d5dbe5;font:15px/1.6 system-ui,sans-serif;padding:24px;text-align:center;';
    const msg = document.createElement('div');
    msg.style.maxWidth = '34em';
    msg.textContent =
      'This game is already open in another browser tab — playing from ' +
      'two tabs at once can lose your progress. Switch to that tab, or ' +
      'close it and reload this one.';
    const btn = document.createElement('button');
    btn.type = 'button';
    btn.textContent = 'Reload and try again';
    btn.style.cssText =
      'font:inherit;padding:8px 18px;border-radius:6px;border:1px solid #3a4656;' +
      'background:#1d2632;color:inherit;cursor:pointer;';
    btn.addEventListener('click', () => location.reload());
    div.appendChild(msg);
    div.appendChild(btn);
    (document.body || document.documentElement).appendChild(div);
  }

  if (typeof createFluffOS === 'function') {
    const realCreateFluffOS = createFluffOS;
    // eslint-disable-next-line no-global-assign
    createFluffOS = function (moduleArg) {
      return acquired.then((ok) => {
        if (ok) return realCreateFluffOS(moduleArg);
        console.warn('tab-lock: "' + LOCK_NAME + '" held by another tab; not booting');
        showBlocked();
        // Never resolve: the boot .then() chain (and its error modal)
        // simply doesn't run; the overlay owns the page from here.
        return new Promise(() => {});
      });
    };
  } else {
    console.error('tab-lock: createFluffOS not defined -- script order wrong, boot is UNGUARDED');
  }

  window.TabLock = { name: LOCK_NAME, acquired };
})();
