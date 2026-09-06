/* /obj/inroom
**
** A room which can be moved into other rooms. Quite plushy.
**
**  18-Aug-94 [Mateese]
*/

#include <lock.h>
#include <moving.h>
#include <search.h>

inherit "/std/lock";                   // init()
inherit "/std/container/restrictions"; // create(), overloads room/restrictions
inherit "/std/thing/description";
inherit "/std/room";                   // create(), init(), reset(), clean_up()
inherit "/std/thing/moving";           // move(), clean_up()

#define TP this_player()
#define THIS this_object()

private nosave int Puselock;

//-------------------------------------------------------------------------

public int QueryUseLock() { return Puselock; }
public int SetUseLock(int i) { return Puselock = i; }

/*-------------------------------------------------------------------------
** Initialize us.
*/

public varargs void create () {
  room::create(1);
  "restrictions"::create();
  SetShort("a room");
  SetIntShort("inside a room");
  SetLong("This an ordinary room.\n");
  SetIntLong("You are inside an ordinary room.\n");
  SetPreContent(0);
  SetValue(0);
  SetWeight(0);
  SetMaxWeight(1<<30);
  SetTransparency(1000);
  AddId("room");
  SetLockState(LOCK_OPEN);
  SetUseLock(0);
}

public void init () {
  if (QueryUseLock())
    lock::init();
  room::init();
}

/*-------------------------------------------------------------------------
** Dispatch the calls for descriptions and properties appropriately.
** For example, details musn't be visible from outside.
** Nor are the contents if the room is closed.
*/

public int id (string str) {
  return description::id(str) || room::id(str);
}

public int QueryLockState() {
  if (!QueryUseLock())
    return LOCK_OPEN;
  return ::QueryLockState();
}

public varargs int QueryTransparency (mixed flag) {
  return (flag || QueryLockState() != LOCK_OPEN)
         ? (::QueryTransparency(flag))
         : 1000;
}

public varargs string InvShort (string what) {
  if (QueryUseLock())
    return ModifyInvShort(description::InvShort(what));
  return description::InvShort(what);
}

public varargs string IntLong (string what) {
  if (QueryUseLock())
    return ModifyLong(room::IntLong(what));
  return room::IntLong(what);
}

public varargs string Long(string what) {
  if (!what) {
    if (QueryUseLock())
      return ModifyLong(description::Long(what));
    return description::Long(what);
  }
  if (member(deep_inventory(THIS), TP) == -1)
    return description::Long(what);
  return room::Long(what);
}

public varargs string ExaLong(string what) {
  if (!what) {
    if (QueryUseLock())
      return ModifyLong(description::ExaLong(what));
     return description::ExaLong(what);
  }
  if (member(deep_inventory(THIS), TP) == -1)
    return description::ExaLong(what);
  return room::ExaLong(what);
}

public varargs string Smell(string what) {
  if (!what || member(deep_inventory(THIS), TP) == -1)
    return description::Smell(what);
  return room::Smell(what);
}

public varargs string Noise(string what) {
  if (!what || member(deep_inventory(THIS), TP) == -1)
    return description::Noise(what);
  return room::Noise(what);
}

public varargs string Read(string what) {
  if (!what || member(deep_inventory(THIS), TP) == -1)
    return description::Read(what);
  return room::Read(what);
}

public varargs string Content (string what, mixed exclude) {
  if (   member(deep_inventory(THIS), TP) == -1
      && QueryLockState() != LOCK_OPEN)
    return "";
  return ::Content(what, exclude);
}

/*-------------------------------------------------------------------------
** If the room is closed, taking things from it is not possible.
** In that case, return ME_NO_LEAVE, else ME_NO_PREVENT.
*/

public int prevent_leave (mixed dest, int method, mixed extra) {
  if (QueryLockState() != LOCK_OPEN) {
    write ("The "+strip_a(QueryShort())+" is closed.\n");
    return ME_NO_LEAVE;
  }
  return "container/restrictions"::prevent_leave(dest, method, extra);
}

/*-------------------------------------------------------------------------
** If the room is closed, putting things into it is not possible.
** In that case, return ME_NO_ENTER.
** If the room is open, it still might be fulfilled. Ask /std/container
** about that then.
*/

public int allow_enter (int method, mixed extra) {
  if (QueryLockState() != LOCK_OPEN) {
    write ("The "+strip_a(QueryShort())+" is closed.\n");
    return ME_NO_ENTER;
  }
  return "container/restrictions"::allow_enter (method, extra);
}

public int clean_up (int ref) {
  if (environment() && ref != -1)
    return 0;
  return room::clean_up(ref);
}

/*-------------------------------------------------------------------------
** If the room is closed, the player can't find nor see anything through
** it's material.
*/

public varargs object *Locate (mixed item, int mode) {
  if (QueryLockState() != LOCK_OPEN && member(deep_inventory(THIS), TP) == -1)
    return (mode & SEARCH_OBJECT) ? 0 : ({});
  return "container/restrictions"::Locate (item, mode);
}

/*************************************************************************/
