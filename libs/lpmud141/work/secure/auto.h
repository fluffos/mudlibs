/*
 * auto.h -- global include file, injected before every compile.
 *
 * This archive's original driver (a classic pre-master-object 1990s LPMud)
 * had no such concept at all. FluffOS requires SOME real file for this
 * config slot (an omitted/empty value still gets #include'd, producing
 * "Cannot read #include file" at every single compile).
 *
 * One real thing lives here: a universal move_object(dest) LPC function,
 * given to every single object in the mudlib for free. This archive's
 * whole codebase calls `move_object(item, dest)` -- a genuine 2-argument
 * driver instruction on the original classic driver, moving an ARBITRARY
 * object, not just the caller. FluffOS's real move_object() efun only
 * ever moves current_object (`void move_object(object|string)`), so
 * every call site was mechanically rewritten tree-wide to
 * `item->move_object(dest)` (see NOTES.md) -- the standard LPC idiom for
 * "do this as if you were item". That idiom only works if `item`'s own
 * compiled program actually HAS a function called `move_object` for
 * call_other() to dispatch to (call_other never falls back to efuns) --
 * which nothing in this archive defines. This universal definition,
 * injected into every file via the global-include mechanism, supplies
 * exactly that, and forwards to the real builtin via `efun::` (bare
 * `move_object()` inside this function would just recurse into itself,
 * since a local definition always shadows the same-named efun for plain
 * calls within its own file).
 */
varargs void move_object(mixed dest) {
  efun::move_object(dest);
}

/*
 * create() -- also universal, also forwarding, for a second and unrelated
 * reason: this archive's `reset(arg)` doubles as BOTH first-time setup
 * (arg==0, called synchronously right after an object is created/cloned
 * -- simulate.c: `apply("reset", new_ob, 0)`) AND later periodic re-stock
 * (arg==1, from the driver's backend loop) -- a single-hook convention
 * from an era before create()/reset() split into two separate applies.
 * FluffOS's own object lifecycle calls create() synchronously on every
 * compile/clone (as this driver's own call_create() does), but
 * deliberately does NOT also call reset() synchronously: it sets
 * O_RESET_STATE right after create() returns and schedules next_reset a
 * full `time to reset` interval in the future, so a fresh object's own
 * reset(arg==0) genuinely never fires on this driver until that interval
 * elapses (confirmed by reading vm/internal/base/object.cc's
 * call_create()/set_nextreset() and backend.cc's periodic reset scan --
 * both gate on O_RESET_STATE, which is already set by the time any
 * LPC code could clear it). Every room/NPC/item here that expects its
 * "if (arg) return; ...setup..." branch to run immediately on first load
 * (nearly all of them) would otherwise stay in its uninitialized default
 * state (dark rooms, unstocked shops, absent starting NPCs) until ~15-30
 * minutes after boot. This restores the original synchronous-first-reset
 * behavior for every object, uniformly. `call_other(this_object(), ...)`
 * (not a bare call) because plenty of files -- most plain items -- have
 * no `reset()` of their own at all, and a bare undefined-function call
 * would be a compile error where call_other() just harmlessly returns 0.
 */
void create() {
  call_other(this_object(), "reset", 0);
}
