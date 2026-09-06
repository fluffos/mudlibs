/* /obj/chest
**
** A simple lockable chest to clone.
**
**  05-Oct-92 [Mateese]
**  21-Jan-93 [Mateese] KeyCode now optional to allow generic keys.
**  10-Jun-93 [Mateese] Now uses /std/lock.
**  13-Aug-93 [Mateese] xxxChestDsc() gone.
**  05-Oct-93 [Mateese] Adapted for new perceptional querying.
**  10-Aug-94 [Mateese] Utilizes new std/lock-Functions.
**  07-Oct-94 [Mateese] Inherits /std/room/items as well.
**  23-Apr-96 [Mateese] Closed chests can't stop ghosts.
*/

#include <properties.h>
#include <lock.h>
#include <moving.h>
#include <search.h>

inherit "/std/room/items"; // reset() is here
inherit "/std/lock";
inherit "/std/container";

#define TP this_player()
#define THIS this_object()
#define TI this_interactive()
#define PO previous_object()

/*-------------------------------------------------------------------------*/

public varargs int QueryTransparency (mixed flag) {
  return (flag || QueryLockState() != LOCK_OPEN)
         ? container::QueryTransparency(flag)
         : 1000;
}

public varargs string InvShort (string what) {
  return ModifyInvShort(container::InvShort(what));
}

public varargs string Long (string what) {
  return ModifyLong(container::Long(what));
}

public varargs string IntLong (string what) {
  return ModifyLong(container::IntLong(what));
}

/*-------------------------------------------------------------------------
** Initialize us.
*/

void create () {
  container::create();
  SetShort ("a chest");
  SetIntShort ("inside a chest");
  SetLong ("This an ordinary chest.\n");
  SetIntLong ("You are inside an ordinary chest.\n");
  SetPreContent ("It contains:\n");
  SetValue (200);
  SetWeight (8000);
  SetMaxWeight (16000);
  SetTransparency(0);          // Opaque when closed
  AddId ("chest");
  SetLockState (LOCK_CLOSED);
  Set(P_HELP_MSG,
"The chest can hold a small things, hiding them away from plain sight.\n"
"Simply put the things into the chest or take them out again.\n"
"To make the contents less obvious, close the chest.\n"
     );
}

/*-------------------------------------------------------------------------
** If the chest is closed, taking things from it is not possible.
** In that case, return ME_NO_LEAVE, else ME_NO_PREVENT.
*/

public int prevent_leave (mixed dest, int method, mixed extra) {
  if (!TP || TP != PO || LSTATE_GHOST != TP->Query(P_LSTATE)) {
    if (QueryLockState() != LOCK_OPEN) {
      if (TP || TI)
        write ("The "+strip_a(QueryShort())+" is closed.\n");
      return ME_NO_LEAVE;
    }
  }
  return container::prevent_leave(dest, method, extra);
}

/*-------------------------------------------------------------------------
** If the chest is closed, putting things into it is not possible.
** In that case, return ME_NO_ENTER.
** If the chest is open, it still might be fulfilled. Ask /std/container
** about that then.
*/

public int allow_enter (int method, mixed extra) {
  if (!TP || TP != PO || LSTATE_GHOST != TP->Query(P_LSTATE)) {
    if (QueryLockState() != LOCK_OPEN) {
      if (TP || TI)
        write ("The "+strip_a(QueryShort())+" is closed.\n");
      return ME_NO_ENTER;
    }
  }
  return container::allow_enter (method, extra);
}

/*-------------------------------------------------------------------------
** If the chest is closed, the player can't find nor see anything through
** it's material (unless of course she's a ghost or the chest is transparent).
*/

public varargs object *Locate (mixed item, int mode) {
  if (QueryLockState() != LOCK_OPEN 
  &&  member(deep_inventory(THIS), TP) == -1
  &&  LSTATE_GHOST != TP->Query(P_LSTATE)
  &&  QueryTransparency() < 500
     ) 
    return (mode & SEARCH_OBJECT) ? 0 : ({});
  return container::Locate (item, mode);
}

/*-------------------------------------------------------------------------
** The content is always visible to the inside, but to the outside only
** if the chest is not closed or transparent.
*/

public varargs string Content (string what, mixed exclude) {
  if (member(deep_inventory(THIS), TP) == -1
   && LSTATE_GHOST != TP->Query(P_LSTATE)
   && QueryLockState() != LOCK_OPEN
   && QueryTransparency() < 500
     )
    return "";
  return container::Content(what, exclude);
}

/*************************************************************************/
