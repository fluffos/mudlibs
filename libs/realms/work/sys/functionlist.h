// FluffOS PORT: this driver has no functionlist()/RETURN_FUNCTION_NAME
// efun (LDMud-specific; FluffOS's nearest equivalent is the differently-
// shaped functions() efun). The one real (non-test) call site,
// lib/core/events.lpc's registerEvent(), was rewritten to use
// function_exists() against the known validEventHandlers list instead of
// enumerating functions -- see that file's own port note. Kept as an
// empty stub so the handful of lib/tests/ files that still #include it
// continue to parse (they are not part of the boot/compile-sweep scope).
