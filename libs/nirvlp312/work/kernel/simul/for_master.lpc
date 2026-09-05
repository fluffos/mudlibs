/*
 * /kernel/simul/for_master.c
 *
 * This file contains the simul_efuns which are also used by the master.
 * Both (kernel/simul_efun and kernel/master) should inherit this file.
 *
 */

#include "/sys/kernel.h"  // this path has to be absolute because this file
                          // is inherited by the master!
inherit "/kernel/simul/security";


mixed creator_file(string object_name) {
  string *path;

  if (strstr(object_name,"//")>=0 || member(object_name,'#')>=0)
    return 0;
  path = explode(object_name,"/")-({"","."});
  switch (sizeof(path) && path[0]) {
    case "open":
    case "ftp":
    case "log":
    case "newlib":
    case "oldlib":
      return 0;
    case "players":
      if (sizeof(path)<3)
        return 0;
      return path[1];
    case "domains":
      if (sizeof(path)<3)
        return 0;
      return capitalize(path[1]);
    default:
      return 1;
  }
  return 1;
}

mixed get_protection(string file, string mode) {
  int rw;

  switch (mode[0]) {
    case 'w':
      rw = 1;
      break;
    case 'r':
      rw = 0;
      break;
    default:
      raise_error("Bad argument 2 to get_protection()\n");
      break;
  }
  switch (mode[1]) {
    case 'f':
      file += "foo";
      break;
    case 'd':
      if (file[<1]=='/')
        file += "foo";
      else
        file += "/foo";
      break;
    default:
      raise_error("Bad argument 2 to get_protection()\n");
      break;
  }
  return SECURITY->query_protection(file,rw);
}

int check_privilege(mixed priv) {
  return SECURITY->check_privilege(priv,1);
}

/*
 * this following move_object() code migrated herewards from game.c
 */

private void log_move_error(string where,string error,
                            object ob,object from,object to) {
  __MASTER_OBJECT__->runtime_error(error + " in notify_" + where +
                                   "() called by moving " + to_string(ob) +
                                   " from " + to_string(from) + " to " +
                                   to_string(to) + "\n", __FILE__,
                                   object_name(this_object()),__LINE__);
}

mixed move_object(mixed ob, mixed to) {
  object from;
  mixed error;
  closure call_from_previous;

  call_from_previous = bind_lambda(#'call_other,previous_object());
  
  if (stringp(ob)) {
    from = find_object(ob);
    if (!from) {
      load_object(ob);
      from = find_object(ob);
    }
    ob = from;
  }
  from = environment(ob);
  if (stringp(to))
    to = load_object(to);
  if (from == to) {
    efun::move_object(ob,to);
    return 0;
  }
  if (from && (error = funcall(call_from_previous,from,"prevent_leave",ob,to)))
    return error;
  if (ob && (error = funcall(call_from_previous,ob,"prevent_move",from,to)))
    return error;
  if (to && (error = funcall(call_from_previous,to,"prevent_enter",ob,from)))
    return error;
  efun::move_object(ob,to);
  if (from)
    if (error = catch(funcall(call_from_previous,from,"notify_leave",ob,to)))
      log_move_error("leave",error,ob,from,to);
  if (ob &&
      (error = catch(funcall(call_from_previous,ob,"notify_move",from,to))))
    log_move_error("move",error,ob,from,to);
  if (ob &&
      (error = catch(funcall(call_from_previous,to,"notify_enter",ob,from))))
    log_move_error("enter",error,ob,from,to);
  return 0;
}

// The aim of this function is to support moves of *objects without
// recomputing light after each particular object.
// It installs a simpler move hook and re-establishes the standard hook
// when the given closure is evaluated.
varargs mixed with_delayed_light(closure code, varargs mixed* args) {
  closure call_from_previous;
  mixed result, error;
  object h, ob;

  call_from_previous = bind_lambda(code, previous_object());

  __MASTER_OBJECT__->set_simple_move_hook();
  // catch, because this MUST NOT fail.
  error = catch((result = apply(call_from_previous, args)); publish);
  __MASTER_OBJECT__->reset_simple_move_hook();
  if ((ob = this_player())) {
    __MASTER_OBJECT__->notify_move_light(this_player());
  }
  return result;
}

void move_object_group(mixed *obs, object to) {
  mixed ob;
  closure call_from_previous;

  call_from_previous = bind_lambda(#'efun::move_object, previous_object());
  foreach (ob : obs) {
    funcall(call_from_previous, ob, to);
  }
}

// #define TRANSFER_WITH_ENCUMBRANCE
#ifdef TRANSFER_WITH_ENCUMBRANCE
mixed transfer(mixed ob,mixed to) {
  object from;
  int encumbrance;
  mixed ret;
  if (stringp(ob)) {
    call_other(ob,"-");  // load it or raise an error
    ob = find_object(ob);
  }
  else if (!objectp(ob))
    raise_error("Bad argument 1 to transfer()\n");
  if (stringp(to)) {
    call_other(to,"-");  // load it or raise an error
    to = find_object(to);
  }
  else if (!objectp(to))
    raise_error("Bad argument 2 to transfer()\n");
  from = environment(ob);
  /*
   * Get the encumbrance of the object
   */
  encumbrance = ob->query_encumbrance(ob) || 2500 * ob->query_weight();
  if (!intp(encumbrance))
    encumbrance = 0;
  if (!ob)  // did get_encumbrance() destruct ob?
    return 3;  // can't take it out of its container
  /*
   * If the original place of the object is a living object,
   * then we must call drop() to check that the object can be dropped.
   */
  if (from && living(from))
    if (ob->drop(1) || !ob)  // did ob->drop() destruct ob?
      return 2;  // can't be dropped
  /*
   * If 'from' is not a room and not a player, check that we may
   * remove things out of it.
   */
  if (from && environment(from) && !living(from))
    if (!from->can_put_and_get() || !ob || !to)
      return 3;  // can't take it out of its container
  /*
   * If the destination is not a room, and not a player,
   * Then we must test 'prevent_insert', and 'can_put_and_get'.
   */
  if (environment(to) && !living(to)) {
    if (ob->prevent_insert() || !ob || !to)
      return 4;  // can't be inserted into containers
    if (!to->can_put_and_get() || !ob || !to)
      return 5;  // destination doesn't allow insertion
  }
  /*
   * If the destination is a player, check that he can pick it up.
   */
  if (living(to))
    if (!ob->get() || !ob || !to)
      return 6;  // can't be picked up
  /*
   * If it is not a room, correct the total weight in the destination.
   */
  if (environment(to) && encumbrance)
    if (!to->add_encumbrance(encumbrance) || !ob || !to)
      return 1;  // too heavy for destination
  /*
   * If it is not a room, correct the weight in the 'from' object.
   */
  if (from && environment(from) && encumbrance)
    from->add_encumbrance(-encumbrance);
  return move_object(ob,to);
}
#else
mixed transfer(mixed ob,object to) {
  object from;
  mixed error;

  set_this_object(previous_object());

  if (stringp(ob)) {
    from = find_object(ob);
    if (!from) {
      call_other(ob,"-");
      from = find_object(ob);
    }
    ob = from;
  }
  from = environment(ob);
  if (from==to)
    return efun::transfer(ob,to);
  if (from && (error = (mixed)from->prevent_leave(ob,to)))
    return error;
  if (ob && (error = (mixed)ob->prevent_move(from,to)))
    return error;
  if (to && (error = (mixed)to->prevent_enter(ob,from)))
    return error;
  if (error = efun::transfer(ob,to))
    return error;
  if (from)
    catch(from->notify_leave(ob,to));
  catch(ob->notify_move(from,to));
  catch(to->notify_enter(ob,from));
  return 0;
}
#endif

