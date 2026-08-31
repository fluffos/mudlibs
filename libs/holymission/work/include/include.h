// This is the 'auto-include' file. As it's name suggests, it is
// automatically included in any file compiled on the mud. Hence there is
// absolutely NO need to include it yourself.

#ifndef __INCLUDE_H__

#define __INCLUDE_H__

#pragma combine_strings

#include "/include/daemon.h"

// MUD_NAME removed: collides with the driver's own predefine from
// config.fluffos's "name :" field (AGENTS.md §7.39) -- same value
// ("Holy Mission"), the driver's version takes over transparently.
#define MAX_NAME_LENGTH		13

// Driver-compat shim, spliced into EVERY compiled object via this global
// include file (real archive content -- see NOTES.md for why). This
// archive was written for a classic driver dialect where move_object()
// took two arguments (move ANY object, not just the caller) --
// `move_object(item, dest)`, ~1400+ call sites tree-wide. This driver's
// real move_object() efun takes exactly one argument and always moves
// this_object() -- so `item->move_object(dest)` is the correct rewrite
// for a 2-arg call where item isn't already this_object(), but that
// requires item's own object to have a real move_object(dest) method,
// since this driver's call_other() never falls back to a same-named
// efun when the target has none (a confirmed silent-failure class, see
// AGENTS.md). Defining it once here, instead of on every base class
// individually, guarantees every single object in the mudlib has one.
mixed move_object(mixed dest) {
  return efun::move_object(dest);
}

// Driver-compat shim, same reasoning as move_object() above: this
// archive's classic dialect had a 2-arg command(str, ob) ("execute str
// as if ob typed it" -- NPCs auto-wielding weapons, following, fleeing,
// etc., ~40 real call sites). This driver's command() efun is 1-arg
// only (always executes as this_object()) and has no
// impersonation/retargeting mechanism available in this build (see
// secure/simul_efun.lpc). Every 2-arg call site was rewritten to
// `ob->force_me(str)`; spliced into every object here, so the bare
// command(str) inside correctly executes as `ob` via normal call_other
// semantics.
int force_me(string str) {
  return command(str);
}

#endif // __INCLUDE_H__
