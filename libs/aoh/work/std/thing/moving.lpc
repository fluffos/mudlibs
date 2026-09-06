//---------------------------------------------------------------------------
// thing/moving.c
//
// An general inheritance file for all objects that can move somehow.
// Since 'move' also includes 'remove', the 'cleanup' can be found
// here as well.
//---------------------------------------------------------------------------

#include <config.h>
#include <moving.h>
#include <properties.h>
#include <messages.h>
#include <driver/object_info.h>

#define THIS  this_object()
#define ENV   environment
#define PREV  previous_object()
#define DBG(x)  if(find_player("nostradamus")) tell_object(find_player("nostradamus"), x)

//--- global variables ------------------------------------------------------

private nosave object *Pfollowers;
private nosave mixed Pnofollow, Pnoget, Pnodrop, Pnogive;

//--- object following ------------------------------------------------------

public object *QueryFollowers()         { return Pfollowers; }
public object *SetFollowers(object *fs) {
  if (sizeof(fs))
    map_objects(fs, "Set", P_IS_FOLLOWER, 1);
  return Pfollowers = sizeof(fs) ? fs : 0;
}

public object *AddFollower(object f) {
  if (THIS == f)
    raise_error("AddFollower() done on itself.\n");
  if (f)
    f->Set(P_IS_FOLLOWER, 1);
  return Pfollowers ?
    (member(Pfollowers, f) < 0 ? Pfollowers += ({ f }) : Pfollowers)
    : Pfollowers = ({ f });
}

public object *RemoveFollower(object f) {
  return Pfollowers ?
    (member(Pfollowers, f) >= 0 ? Pfollowers -= ({ f }) : Pfollowers) : 0;
}

//--- follow, give, get and drop preventation -------------------------------

public mixed QueryNoFollow()    { return Pnofollow; }
public mixed QueryNoDrop()      { return Pnodrop; }
public mixed QueryNoGet()    { return Pnoget || query_once_interactive(THIS); }
public mixed QueryNoTake()      { return QueryNoGet(); }
public mixed QueryNoGive()      { return Pnogive; }

public mixed SetNoFollow(mixed i) { return Pnofollow = i; }
public mixed SetNoDrop(mixed i)   { return Pnodrop = i; }
public mixed SetNoGet(mixed i)    { return Pnoget = i; }
public mixed SetNoTake(mixed i)   { return SetNoGet(i); }
public mixed SetNoGive(mixed i)   { return Pnogive = i; }

//---------------------------------------------------------------------------
// int move(string|object dest, void|int method, void|mixed extra)
//
// Move this object into <dest> using given <method> (default is M_SILENT).
// <extra> may contain additional information for the preventation and
// notification.
// Return ME_OK if the move was successful, else an error code.
// Before moving this object, the old environment will be asked for permission
// by:
//
//   old_env->prevent_leave(dest, method, extra)
//
// which may return a code != 0 if leaving is not allowed (this code will then
// be returned by move()).
// Second, the new environment will be asked with:
//
//   new_env->allow_enter(method, extra)
//
// which may return a code != ME_OK if entering is not allowed. If an object
// does not define a allow_enter() function, then moving objects into it will
// not be allowed because a return value of 0 is the standard ME_NO_ENTER
// error code.
// After a successful move, the old environment and the new one will be notifed
// by:
//
//   old_env->notify_leave(new_env, method, extra)
//   new_env->notify_enter(old_env, method, extra)
//
// The notification functions can then give out moving messages or update
// light and weight etc.
// If all this has been performed, all followers (if any) will also be notifed
// of the move.
//---------------------------------------------------------------------------

public varargs int move(mixed dest, int method, mixed extra) {
  mixed err1;
  object oldenv;

  switch(method) {
    case M_GET:
      if (Pnoget) return ME_NO_GET;
      break;
    case M_DROP:
      if (Pnodrop) return ME_NO_DROP;
      break;
    case M_GIVE:
      if (Pnogive) return ME_NO_GIVE;
      break;
  }
  oldenv = ENV();
  if(M_NOCHECK != method) { // In all other cases ask for permissions.

    // Ask if we perhaps are not allowed to leave the current environment.
    // We do not want to catch an error because we have not yet moved the
    // object and so no inconsistency can occur. Just let the error happen
    // so we can fix it. We still can escape with a M_NOCHECK move
    // if we are a player (and somebody helps us).

    if(ENV() && (err1 = ({mixed})ENV()->prevent_leave(dest, method, extra)))
      return err1;

    // Check for permission to enter the new environment. We also do not
    // need to catch an error for the same we reason we did not when asking
    // for permission to leave. Just let the error happen.

    if (!objectp(dest) && !stringp(dest))
      raise_error(sprintf("Variable dest is invalid: %O\n", dest));

    if((err1 = ({mixed})dest->allow_enter(method, extra)) != ME_OK)
      return err1 || ME_NO_ENTER;

    if(!THIS) return ME_DESTRUCTED_SELF; // Have we been destructed?
  }

  // if we come to this point everything seams to be o.k. for moving.
  // We also do not want to catch an error for the same reasons as
  // above. Just let it happen.

  move_object(THIS, dest);

  // We now want to notify the environments of the successful move so they
  // can update the weight etc. The problem here is that an error will
  // lead into inconsistency. Especially when notifying the old env we
  // still want to give the new env the chance to update. Therefore we
  // catch possible errors and send a error message.

  err1 = 0;
#if 0
  if(oldenv && dest != oldenv
  && (err1 = catch(oldenv->notify_leave(dest, method, extra))))
    MASTER->runtime_error("Error on calling " + to_string(oldenv) +
                          "->notify_leave(): " + err1,
                          __FILE__, object_name(), __LINE__);

  if(dest != oldenv
  && (err2 = catch(dest->notify_enter(oldenv, method, extra))))
    MASTER->runtime_error("Error on calling " + to_string(dest) +
                          "->notify_enter(): " + err2,
                          __FILE__, object_name(), __LINE__);

  if (err1 || err2)
    return ME_CAUGHT_ERR;
#else
  if (oldenv)
    oldenv->notify_leave(dest, method, extra);
  dest->notify_enter(oldenv, method, extra);
#endif

  // It showed to be useful that the moving is announced to the
  // living objects in both rooms.
  if (oldenv)
    tell_room(oldenv, ({MSG_MOVE, oldenv, ENV(), method, extra}), ({ THIS }));
  say(({MSG_MOVE, oldenv, ENV(), method, extra }), ({ THIS }));

  // Now tell all our followers about it. Take care of recursions by using
  // an increment/decrement counter.
  if (Pfollowers) {
    Pnofollow++;
    filter_objects(Pfollowers, "follow", dest, method, extra);
    Pnofollow--;
  }

  return ME_OK;
}

//--- object following ------------------------------------------------------

public void follow (mixed dest, int method, mixed extra) {
  if(!Pnofollow && ENV(PREV) != ENV()) move(dest, method, extra);
}

//---------------------------------------------------------------------------
// Cleanup handling:
//
// ref < 0: our environment calls us to clean up.
//   In each contained object call 'clean_up(-1)'. If after that no object
//   remains, self destruct, else return 1.
// ref = 0: we are a clone, or a blueprint with replaced program.
//   Selfdestruct if we have no environment(). On selfdestruct, call
//   'remove()' in contained objects, even on nested inventories.
// ref = 1: we are a swapped and/or unreferenced blueprint.
//   Do not selfdestruct if we have an environment.
//   Else call 'clean_up(-1)' in each contained object. If no object remains
//   after that, self destruct.
// ref > 1: we are a non-swapped blueprint in use.
//   Try again later.
// Objects carried by once interactive objects (players) aren't cleaned up.

public int clean_up(int ref) {
  mixed rc;
//  DBG(sprintf("%O->clean_up(ref:%O)\n", this_object(), ref));
  if ((call_resolved(&rc, THIS, "QueryProp", P_CLEAN_UP) && !rc)
      || (ENV() && query_once_interactive(ENV()))
     )
    return 1;
  switch(ref) {
    case 0:
      if (environment())
        return 1;
      filter_objects(deep_inventory(), "remove");
      break;
    case 1:
      if (environment())
        return 1;
      /* FALL THROUGH */
    case -1:
      filter_objects(all_inventory(), "clean_up", -1);
      if (first_inventory())
        return 1;
      break;
    default:
      return 1;
  }
  THIS->remove();
  return THIS && 1;
}
