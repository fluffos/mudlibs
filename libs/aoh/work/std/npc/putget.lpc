/* -------------------------------------------------------------------------
 * /std/npc/putget.c   -- take, put, give, get commands for livings
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 * -------------------------------------------------------------------------
 * 29-Sep-97  Added support for closures in P_NOGET
 */


#include <properties.h>
#include <moving.h>
#include <search.h>
#include <config.h>
#include <npc.h>

#define THIS  this_object()
#define TP    this_player()
#define ENV   environment
#define TMP_WHERE "IntoOnto" // Hack to give right messages in GivePut
#define SF(x) #'x //' Emacs-Hack
#define SYM(x) 'x //' Emacs-Hack

/*--------------------------------------------------------------------------*/

public varargs mixed Search(mixed what, int mode);
                                       // std/living/description
public varargs mixed SearchM(mixed what, int mode, closure pred);
                                       // std/living/description
public string QueryName();             // std/living/description
public string QueryObjective();        // std/living/description
public varargs mixed Set(string pn, mixed arg, int sc); // std/base
public varargs mixed Query(string pn, int sc); //std/base


//--------------------------------------------------------------------------
public mapping sortObjsByEnv (object * what, object me, object * envs) {
  mapping bags;
  object bag, obj;
  int    i;

  // Sort from where the objects were dropped.
  bags = ([]);
  for (i = sizeof(what); i-- > 0; ) {
    obj = what[i];
    bag = ENV(what[i]);
    if (!bags[bag])
      bags[bag] = ({ obj });
    else
      bags[bag] += ({ obj });
  }
  if (bags[me])
    envs = ({ me }) + (m_indices(bags) - ({ me }));
  else
    envs = m_indices(bags);
  return bags;
}

//--------------------------------------------------------------------------
public varargs string makeFromMsg (object me, mapping bags, object * envs, object * what) {
  string msg, part, sh;
  object bag;
  int    i;

  // Construct and output primary drop message
  msg = "";
  for (i = 0; i < sizeof(envs); i++) {
    bag = envs[i];
    if (living(bag))
    {
      sh = ({string})bag->QueryName() || ({string})bag->Short();
      if (!sh || sh == "")
        sh = "someone";
    }
    else
    {
      if (bag)
      {
        sh = ({string})bag->Short();
        if (!sh || sh == "")
          sh = "somewhere";
      }
      else
        sh = 0;
    }
    part = (bag != me && sh) ? (" (from "+sh+")") : "";
    if (pointerp(what))
      part += " "+fold_objlist(bags[bag] & what, 1);
    else
      part += " "+fold_objlist(bags[bag], 1);
    if (0 == i)
      msg += part;
    else if (i < sizeof(envs)-1)
      msg = msg+","+part;
    else
      msg = msg+", and"+part;
  }
  return msg;
}

//--------------------------------------------------------------------------
public varargs mixed * DropTake (string verb, mixed what, int mode) {
  string sh, ne_msg, msg, prop;
  mapping bags, found;
  object *nodrop, obj;
  mixed rc, *envs, tmp;
  int i;

  if (stringp(what))
    what = ({ what });

  if (objectp(what))
    what = ({0, ({ what }), 0, 0, 1 });
  else if (pointerp(what)) {
    if (verb == "drop")
      // Drop only objects carried.
      tmp = lambda(({SYM(obj)})
                  , ({SF(||), ({SF(!=), -1
                                  , ({SF(member), quote(deep_inventory(THIS))
                                              , SYM(obj)}) })
                          , ({SF(!), ({SF(environment), SYM(obj)}) })
                     })
                  );
    else
      // Take only objects not directly carried.
      tmp = lambda(({SYM(obj)})
                  , ({SF(||), ({SF(==), -1
			          , ({SF(member)
                                     , quote( ({ THIS })+all_inventory(THIS))
                                     , SYM(obj)}) })
                          , ({SF(!), ({SF(environment), SYM(obj)}) })
                     })
                  );
    // The above filters also accept objects in the void to allow Drop/Take
    // to be used by NPCs to create objects with regards to weights.

    envs = filter(what, SF(objectp));
    what = SearchM( filter(what, SF(stringp))
                  , (verb == "drop" ? SEARCH_INV : SEARCH_ENV_INV)
                    |SM_MULTI|SM_COUNT|WizSearch()
                    |(((mode & PUTGET_REALLY) || verb != "drop") ? 0 : SM_REALLY)
                  , tmp
                  );
    if (sizeof(envs))
      what[FOUND_SINGLE] = envs+(what[FOUND_SINGLE] || ({}));
  }
  else
    what = ({});

  // Sort out 'what' into 'found', with the No<verb> objects collected under
  // index FOUND_NOTHANDLE, and put that back into 'what' and 'nodrop'.

  prop = (verb == "drop" ? P_NODROP : P_NOGET);
  found = sort_findings(what, sort_f_prop(prop));
  what = found[FOUND_SINGLE]||({});
  nodrop = found[FOUND_NOTHANDLE]||({});
  if (found[-FOUND_SINGLE])
    ne_msg = "You did not find as many things as you wanted to "+verb+".\n";

  // If items could not be located, construct the appropriate message in 'msg'.
  // If just some items could not be located, output it immediately.
  if (sizeof(tmp = found[FOUND_IDS])) {
    msg =  (ne_msg||"")
          +implode_list(tmp, "You can't find ", " to "+verb+".", " or");
    ne_msg = 0;
    if (sizeof(what) && !(mode & PUTGET_SILENT))
      tell_object(THIS, msg);
  }
  else if (!sizeof(what) && !sizeof(nodrop))
    msg = "You find nothing to "+verb+".\n";

  // Check the 'nodrop' and output their messages, clobbering 'envs'.
  // Also, output the 'not enough things' messages if still in 'ne_msg'.

  if (!(mode & PUTGET_SILENT) && sizeof(nodrop)) {
    envs = ({});
    for (i = 0; i < sizeof(nodrop); i++ ) {
      obj = nodrop[i];
      sh = (!(mode & PUTGET_SILENT) && ({string})obj->Short());
      tmp = ({mixed})obj->Query(prop);
      if (closurep(tmp))
        tmp = funcall(tmp, obj);
      if (sh && stringp(tmp))
        tell_object(THIS, tmp);
      else if (sh)
        envs += ({ obj });
    }
    if (sizeof(envs)) {
      tmp = capitalize(fold_objlist(envs, 1))
            +" can't be "+(verb == "drop" ? "dropped" : "taken")+".";
      tmp = tmp[0..1]+sprintf("%2s%-73=s", "", tmp[2..])[2..]+"\n";
    }
    if (sizeof(envs) || ne_msg)
      tell_object(THIS, (ne_msg||"")+(tmp||""));
  }

  // Prepare this already
  rc = (mode & PUTGET_FULL) ? ({ ({}), nodrop, ({}), ({}), ({}) }) : ({ });

  // Premature end if there is nothing left to handle.
  if (!sizeof(what)) {
    if (msg) {
      notify_fail(msg, NOTIFY_ILL_ARG);
      return 0;
    }
    return rc;
  }

  // Sort the objects to handle by their environments.
  bags = sortObjsByEnv(what, verb == "drop" ? THIS : ENV(THIS), &envs);
  what = ({});
  for (i = 0; i < sizeof(envs); i++)
    what += bags[envs[i]];

  // Now do the actual movement.
  for (i = 0; i < sizeof(what); i++ ) {
    obj = what[i];
    if (sh = (!(mode & PUTGET_SILENT) && ({string})obj->Short()))
      sh = strip_a(sh);
    switch (({int})obj->move( verb == "drop" ? ENV(THIS) : THIS
                     , verb == "drop" ? M_DROP : M_GET)) {
      case ME_OK:
        if (mode & PUTGET_FULL)
          rc[PUTGET_OK] += ({ obj });
        else
          rc += ({ obj });
        break;
      case ME_NO_DROP:
      case ME_NO_LEAVE:
        if (mode & PUTGET_FULL)
          rc[PUTGET_NOLEAVE] += ({ obj });
        if (sh)
          if (verb == "drop")
            tell_object(THIS, "You can't get rid of the "+sh+".\n");
          else
            tell_object(THIS, "The "+sh+" is stuck.\n");
        break;
      case ME_NO_ENTER:
        if (mode & PUTGET_FULL)
          rc[PUTGET_TOOHEAVY] += ({ obj });
        if (sh)
          tell_object(THIS, "You can't "+verb+" the "+sh+".\n");
        break;
      case ME_TOO_HEAVY:
        if (mode & PUTGET_FULL)
          rc[PUTGET_TOOHEAVY] += ({ obj });
        if (sh)
          if (verb == "drop")
            tell_object(THIS, "There is no space left for the "+sh+".\n");
          else
            tell_object(THIS, "You can't carry the "+sh+" as well.\n");
        break;
      case ME_NO_GET:
	if (mode & PUTGET_FULL)
          rc[PUTGET_NOLEAVE] += ({ obj });
        if (sh)
          tell_object(THIS, "You can't get the "+sh+".\n");
        break;
      case ME_NO_GIVE:
      case ME_NO_MOVE:
        if (sh) tell_object(THIS, "The "+sh+" won't move.\n");
        // FALL THROUGH
      default:
        if (mode & PUTGET_FULL)
          rc[PUTGET_NOMOVE] += ({ obj });
        break;
    }
  }

  // Makeup and output the handle message
  if (!(mode & PUTGET_SILENT)) {
    what = ((mode & PUTGET_FULL) ? rc[PUTGET_OK] : rc) - ({ 0 });
    if (!sizeof(what))
      tell_object(THIS, "You "+verb+" nothing.\n");
    else {
      msg = makeFromMsg(verb == "drop" ? THIS : ENV(THIS), bags, envs, what);
      tmp = "You "+verb+msg+".";
      tmp = tmp[0..1]+sprintf("%2s%-73=s", "", tmp[2..])[2..];
      tell_object(THIS, tmp+"\n");
      tmp = capitalize(QueryName())+" "+verb+"s"+msg+".";
      tmp = tmp[0..1]+sprintf("%2s%-73=s", "", tmp[2..])[2..];
      show_room(ENV(THIS), tmp+"\n", "", ({ THIS })+what);
    }
  }

  return rc;
}

//--------------------------------------------------------------------------
public varargs mixed * Drop (mixed what, int mode) {
  return DropTake("drop", what, mode);
}

//--------------------------------------------------------------------------
public varargs mixed * Take (mixed what, int mode) {
  return DropTake("take", what, mode);
}

//--------------------------------------------------------------------------
private mixed * takeBefore ( closure action
                           , string verb, mixed what, mixed to, int mode)
{
  mixed *rc, *taken;

  if (sizeof(what)) {
    rc = Take(what, mode);
    if (rc && sizeof(taken = (mode & PUTGET_FULL) ? rc[0] : rc))
      call_out(action, 1, verb, taken, to, mode);
  }
  return rc;
}

//--------------------------------------------------------------------------
public varargs mixed * GivePut (string verb, mixed what, mixed to, int mode)
{
  string to_sh, sh, msg, ne_msg, where;
  mapping bags, found;
  object *nodrop, *notcarried, obj;
  mixed rc, *envs, tmp;
  int i;

  where = Query(TMP_WHERE);
  Set(TMP_WHERE,0);
  tmp = (verb == "give" ? "noone" : "nothing");
  if (stringp(to)) {
    tmp = to;
    to = Search(to, SEARCH_INV_ENV|SEARCH_OBJECT|WizSearch());
  }
  else if (!objectp(to))
    to = 0;

  if (!to) {
    notify_fail("You don't see "+tmp+" to "+verb+" to.\n", NOTIFY_ILL_ARG);
    return 0;
  }

  if (to == ENV(THIS) && verb == "drop")
    return DropTake(verb, what, mode);

  if (verb == "give") {
    if (!living(to)) {
      notify_fail("You can't give items to inanimate objects.\n", NOTIFY_ILL_ARG);
      return 0;
    }
    if (to == THIS) {
      notify_fail("Playing games with yourself?\n", NOTIFY_ILL_ARG);
      return 0;
    }
  }

  if (verb == "give")
    to_sh = (({string})to->QueryName() || ({string})to->Short() || "someone");
  else
    to_sh = (({string})to->Short() || ({string})to->QueryName() || "something");

  if (stringp(what)) {
    what = ({ what });
  }

  if (objectp(what))
    what = ({0, ({ what }), 0, 0, 1 });
  else if (pointerp(what)) {
    envs = filter(what, SF(objectp));
    what = SearchM( filter(what, SF(stringp))
                    , SEARCH_INV_ENV|SM_MULTI|SM_COUNT|WizSearch()
                      |((mode & PUTGET_REALLY) ? 0 : SM_REALLY)
                    , lambda(({SYM(obj)}), ({SF(!=), to, SYM(obj)}))
                    );
    if (sizeof(envs))
      what[FOUND_SINGLE] = envs+(what[FOUND_SINGLE] || ({}));
  }
  else
    what = ({});

  // Sort out 'what' into 'found', with the No<verb> objects collected under
  // index FOUND_NOTHANDLE, and put that back into 'what' and 'nodrop'.
  found = sort_findings(what, sort_f_prop(P_NOGIVE));
  what = found[FOUND_SINGLE]||({});
  nodrop = found[FOUND_NOTHANDLE]||({});
  if (found[-FOUND_SINGLE])
    ne_msg="You did not find as much things as you wanted to "+verb+" away.\n";

  // Objects lying around need an extra action to be taken.
  notcarried = what - deep_inventory(THIS);
  what = what - notcarried;

  // Objects in the void need not be taken (necessary for NPCs giving
  // away items.
  for (tmp = ({ }),i = sizeof(notcarried); i--; )
    if (!environment(notcarried[i]))
      tmp += ({ notcarried[i] });
  what += tmp;
  notcarried -= tmp;

  // If items could not be located, construct the appropriate message in 'msg'.
  // If just some items could not be located, output it immediately.
  if (sizeof(tmp = found[FOUND_IDS])) {
    msg =  (ne_msg||"")
          +implode_list(tmp, "You don't find ", " to "+verb+".", " or");
    ne_msg = 0;
    if (sizeof(what) && !(mode & PUTGET_SILENT))
      tell_object(THIS, msg);
  }
  else if (!sizeof(what) && !sizeof(nodrop))
    msg = "You find nothing to "+verb+".\n";

  // Check the 'nodrop' and output their messages, clobbering 'envs'.
  // Also, output the 'not enough things' messages if still in 'ne_msg'.
  if (!(mode & PUTGET_SILENT) && sizeof(nodrop)) {
    envs = ({});
    for (i = 0; i < sizeof(nodrop); i++ ) {
      obj = nodrop[i];
      sh = (!(mode & PUTGET_SILENT) && ({string})obj->Short());
      tmp = ({mixed})obj->Query(P_NOGIVE);
      if (closurep(tmp))
        tmp = funcall(tmp, obj);
      if (sh && stringp(tmp))
        tell_object(THIS, tmp);
      else if (sh)
        envs += ({ obj });
    }
    if (sizeof(envs)) {
      tmp = capitalize(fold_objlist(envs, 1))
            +" can't be "
            +(verb == "give" ? "given" : verb == "put" ? "put" : "dropped")
            +".";
      tmp = tmp[0..1]+sprintf("%2s%-73=s", "", tmp[2..])[2..]+"\n";
    }
    if (sizeof(envs) || ne_msg)
      tell_object(THIS, (ne_msg||"")+(tmp||""));
  }

  // Prepare this already
  rc = (mode & PUTGET_FULL) ? ({ ({}), nodrop, ({}), ({}), ({}) }) : ({ });

  // Premature end if there is nothing left to handle.
  if (!sizeof(what)) {
    if (msg)
      notify_fail(msg, NOTIFY_ILL_ARG);
    tmp = takeBefore(SF(GivePut), verb, notcarried, to, mode);
    if (!msg && (mode & PUTGET_FULL))
      if (tmp)
        tmp[PUTGET_NODROP] += nodrop;
      else
        tmp = ({ ({}), nodrop, ({}), ({}), ({}) });
    return tmp;
  }

  // Sort the objects to handle by their environments.
  bags = sortObjsByEnv(what, THIS, &envs);
  what = ({});
  for (i = 0; i < sizeof(envs); i++)
    what += bags[envs[i]];

  // Now do the actual giving
  for (i = 0; i < sizeof(what); i++ ) {
    obj = what[i];
    if (sh = (!(mode & PUTGET_SILENT) && ({string})obj->Short()))
      sh = strip_a(sh);
    switch (({int})obj->move(to, verb == "give" ? M_GIVE : M_PUT)) {
      case ME_OK:
        if (mode & PUTGET_FULL)
          rc[PUTGET_OK] += ({ obj });
        else
          rc += ({ obj });
        break;
      case ME_NO_DROP:
      case ME_NO_LEAVE:
        if (mode & PUTGET_FULL)
          rc[PUTGET_NOLEAVE] += ({ obj });
        if (sh)
          tell_object(THIS, "The "+sh+" is stuck.\n");
        break;
      case ME_NO_ENTER:
        if (mode & PUTGET_FULL)
          rc[PUTGET_TOOHEAVY] += ({ obj });
        if (sh) {
          if (verb == "give") {
            tell_object(THIS, "You can't give the "+sh+" to "+to_sh+".\n");
            tell_object(to, capitalize(({string})THIS->QueryName())+" tried to give you "
                            +add_a(sh)+", but failed.\n");
          }
          else
            tell_object(THIS, "You can't put the "+sh+" "+where+" "+to_sh+".\n");
        }
        break;
      case ME_TOO_HEAVY:
        if (mode & PUTGET_FULL)
          rc[PUTGET_TOOHEAVY] += ({ obj });
        if (sh) {
          if (verb == "give") {
            tell_object(THIS, capitalize(to_sh)+" can't carry the "+sh
                              +" as well.\n");
            tell_object(to, capitalize(({string})THIS->QueryName())+" tried to give you "
                            +add_a(sh)+", but you couldn't carry it.\n");
          }
          else
            tell_object(THIS, capitalize(to_sh)
                              +" has no space left for the "+sh+".\n");
        }
        break;
      case ME_NO_GIVE:
        if (mode & PUTGET_FULL)
          rc[PUTGET_TOOHEAVY] += ({ obj });
        if (sh) {
          if (verb == "give") {
            tell_object(THIS,capitalize(sh)+" can't be given to "+to_sh+".\n");
            tell_object(to, capitalize(({string})THIS->QueryName())+" failed to give you "
                            +add_a(sh)+".\n");
          }
          else
            tell_object(THIS, capitalize(to_sh)
                              +" has no space left for the "+sh+".\n");
        }
        break;
      case ME_NO_GET:
      case ME_NO_MOVE:
        if (sh) tell_object(THIS, "The "+sh+" won't move.\n");
        // FALL THROUGH
      default:
        if (mode & PUTGET_FULL)
          rc[PUTGET_NOMOVE] += ({ obj });
        break;
    }
  }

  // Make up and output the handle message
  if (!(mode & PUTGET_SILENT)) {
    what = ((mode & PUTGET_FULL) ? rc[PUTGET_OK] : rc) - ({ 0 });
    if (!sizeof(what))
      tell_object(THIS, "You "+verb+" nothing.\n");
    else {
      msg = makeFromMsg(THIS, bags, envs, what);
      if (verb == "give")
        sh = " to "+to_sh+".";
      else if (verb == "drop")
        sh = " onto "+to_sh+".";
      else
        sh = " "+where+" "+to_sh+".";
      tmp = "You "+verb+msg+sh;
      tmp = tmp[0..1]+sprintf("%2s%-73=s", "", tmp[2..])[2..];
      tell_object(THIS, tmp+"\n");
      tmp = capitalize(QueryName())+" "+verb+"s"+msg+sh;
      tmp = tmp[0..1]+sprintf("%2s%-73=s", "", tmp[2..])[2..];
      show_room(ENV(THIS), tmp+"\n", "", ({ THIS, to })+what);
      if (verb == "give") {
        tmp = capitalize(QueryName())+" gives you"+msg+".";
        tmp = tmp[0..1]+sprintf("%2s%-73=s", "", tmp[2..])[2..];
        show_object(to, tmp+"\n", tmp+"\n");
      }
    }
  }

  // Now take up objects from around and give them away, too.
  tmp = takeBefore(SF(GivePut), verb, notcarried, to, mode);
  if (sizeof(tmp))
    if (mode & PUTGET_FULL)
      for (i = sizeof(rc); i-- > 0; )
        rc[i] += tmp[i];
    else
      rc += tmp;

  return rc;
}

//--------------------------------------------------------------------------
public varargs mixed * Give (mixed what, mixed to, int mode) {
  return GivePut("give", what, to, mode);
}

//--------------------------------------------------------------------------
public varargs mixed * Put (mixed what, mixed to, int mode) {
  return GivePut("put", what, to, mode);
}

//--------------------------------------------------------------------------
public varargs mixed * EquipLayoff (string verb, mixed what, int mode) {
  string sh, ne_msg, msg;
  mapping bags, found;
  object *nodrop, obj;
  mixed rc, *envs, tmp, pred;
  int i;

  if (stringp(what))
    what = ({ what });

  if (objectp(what))
    what = ({0, ({ what }), 0 });
  else if (pointerp(what)) {
    if (verb == "equip")
      // Equip only objects directly carried.
      tmp = lambda(({SYM(obj)}), ({SF(!=), -1
                                  , ({SF(member), quote(all_inventory(THIS))
                                              , SYM(obj)}) })
                  );
    else
      // Lay off anything but myself.
      tmp = lambda(({SYM(obj)}), ({SF(!=), THIS, SYM(obj) }) );
    envs = filter(what, SF(objectp));
    what = SearchM( filter(what, SF(stringp))
                  , (verb == "equip" ? SEARCH_INV : SEARCH_ENV_INV)
                    |SM_MULTI|SM_COUNT|WizSearch()
                    |(((mode & PUTGET_REALLY) || verb != "equip") ? 0 : SM_REALLY)
                  , tmp
                  );
    if (sizeof(envs))
      what[FOUND_SINGLE] = envs+(what[FOUND_SINGLE] || ({}));
  }
  else
    what = ({});

  // Sort out 'what' into 'found', with the No<verb> objects collected under
  // index FOUND_NOTHANDLE, and put that back into 'what' and 'nodrop'.
  if (verb == "equip")
    pred = lambda(({SYM(o)}), ({SF(==), THIS
                                , ({SF(call_other), SYM(o), "QueryProp", P_EQUIPPED})
                           })
                 );
  else
    pred = lambda(({SYM(o)}), ({SF(!=), THIS
                                , ({SF(call_other), SYM(o), "QueryProp", P_EQUIPPED})
                          })
                 );
  found = sort_findings( what
                       , lambda(({SYM(o), SYM(t), SYM(l), SYM(c)})
                               , ({SF(sort_f_std), SYM(o), SYM(t), SYM(l), SYM(c), pred }))
                       );
  what = found[FOUND_SINGLE]||({});
  nodrop = found[FOUND_NOTHANDLE]||({});
  if (found[-FOUND_SINGLE])
    ne_msg = "You did not find as much things as you wanted to "+verb+".\n";

  // If items could not be located, construct the appropriate message in 'msg'.
  // If just some items could not be located, output it immediately.
  if (sizeof(tmp = found[FOUND_IDS])) {
    msg =  (ne_msg||"")
          +implode_list(tmp, "You don't find ", " to "+verb+".", " or");
    ne_msg = 0;
    if (sizeof(what) && !(mode & PUTGET_SILENT))
      tell_object(THIS, msg);
  }
  else if (!sizeof(what) && !sizeof(nodrop))
    msg = "You find nothing to "+verb+".\n";

  // Check the 'nodrop' and output their message.
  // Also, output the 'not enough things' messages if still in 'ne_msg'.
  if (!(mode & PUTGET_SILENT) && sizeof(nodrop)) {
    if (sizeof(nodrop)) {
      if (verb == "equip")
        tmp = "You are already equipped with "+fold_objlist(nodrop, 1)+".";
      else
        tmp = "You are not equipped with "+fold_objlist(nodrop, 1)+".";
      tmp = tmp[0..1]+sprintf("%2s%-73=s", "", tmp[2..])[2..]+"\n";
    }
    if (sizeof(nodrop) || ne_msg)
      tell_object(THIS, (ne_msg||"")+(tmp||""));
  }

  // Prepare this already
  rc = (mode & PUTGET_FULL) ? ({ ({}), nodrop, ({}) }) : ({ });

  // Premature end if there is nothing left to handle.
  if (!sizeof(what)) {
    if (msg) {
      notify_fail(msg, NOTIFY_ILL_ARG);
      return 0;
    }
    return rc;
  }

  // Sort the objects to handle by their environments.
  bags = sortObjsByEnv(what, verb == "equip" ? THIS : ENV(THIS), &envs);
  what = ({});
  for (i = 0; i < sizeof(envs); i++)
    what += bags[envs[i]];

  // Now do the actual action.
  for (i = 0; i < sizeof(what); i++ ) {
    obj = what[i];
    if (sh = (!(mode & PUTGET_SILENT) && ({string})obj->Short()))
      sh = strip_a(sh);
    if (verb == "equip")
    {
      if (THIS == ({object})obj->Set(P_EQUIPPED, THIS))
        if (mode & PUTGET_FULL)
          rc[EQUIP_OK] += ({ obj });
        else
          rc += ({ obj });
      else
      {
        if (mode & PUTGET_FULL)
          rc[EQUIP_FAIL] += ({ obj });
        if (sh)
          tell_object(THIS, "You can't equip yourself with "+sh+".\n");
      }
    }
    else
    {
      if (!({int})obj->Set(P_EQUIPPED, 0))
        if (mode & PUTGET_FULL)
          rc[EQUIP_OK] += ({ obj });
        else
          rc += ({ obj });
      else
      {
        if (mode & PUTGET_FULL)
          rc[EQUIP_FAIL] += ({ obj });
        if (sh)
          tell_object(THIS, "You can't lay "+sh+" aside.\n");
      }
    }
  }

  // Makeup and output the handle message
  if (!(mode & PUTGET_SILENT)) {
    what = ((mode & PUTGET_FULL) ? rc[EQUIP_OK] : rc) - ({ 0 });
    if (!sizeof(what))
    {
      if (verb == "equip")
        tell_object(THIS, "You don't find any equipment.\n");
      else
        tell_object(THIS, "You lay nothing aside.\n");
    }
    else {
      msg = makeFromMsg(THIS, bags, envs, what);
      if (verb == "equip")
        tmp = "You equip yourself with"+msg+".";
      else
        tmp = "You lay"+msg+" aside.";
      tmp = tmp[0..1]+sprintf("%2s%-73=s", "", tmp[2..])[2..];
      tell_object(THIS, tmp+"\n");
      if (verb == "equip")
        tmp = capitalize(QueryName())+" equips "
              +QueryObjective()+"self with"+msg+".";
      else
        tmp = capitalize(QueryName())+" lays"+msg+" aside.";
      tmp = tmp[0..1]+sprintf("%2s%-73=s", "", tmp[2..])[2..];
      show_room(ENV(THIS), tmp+"\n", "", ({ THIS })+what);
    }
  }

  return rc;
}

//--------------------------------------------------------------------------
public varargs mixed * Equip (mixed what, int mode) {
  return EquipLayoff("equip", what, mode);
}

//--------------------------------------------------------------------------
public varargs mixed * Layoff (mixed what, int mode) {
  return EquipLayoff("layoff", what, mode);
}

//--------------------------------------------------------------------------
public varargs int fdrop (string arg)
{
  string tmp, to;
  mixed rc, i, j;

  notify_fail("Drop what?\n", NOTIFY_NOT_OBJ);
  if (!arg)
    return 0;
  if (   2 == sscanf(arg, "%s into %s", tmp, to)
      || 2 == sscanf(arg, "%s onto %s", tmp, to)
     )
    {
      Set(TMP_WHERE,arg[sizeof(tmp)+1..sizeof(tmp)+4]);
      rc = GivePut("drop", tmp, to, PUTGET_FULL);
    }
  else
    rc = Drop(arg, PUTGET_FULL);
  for (i = j = 0; i < sizeof(rc); i++)
    j += sizeof(rc[i]);
  return j;
}

//--------------------------------------------------------------------------
public varargs int ftake (string arg)
{
  mixed rc, i, j;
  notify_fail("Take what?\n", NOTIFY_NOT_OBJ);
  if (!arg)
    return 0;
  rc = Take(arg, PUTGET_FULL);
  for (i = j = 0; i < sizeof(rc); i++)
    j += sizeof(rc[i]);
  return j;
}

//--------------------------------------------------------------------------
public varargs int fgive (string arg) {
  string tmp, to;
  mixed rc, i, j;

  if (!arg || 2 != sscanf(arg, "%s to %s", tmp, to)) {
    notify_fail("Give what to whom?\n", NOTIFY_NOT_OBJ);
    return 0;
  }
  arg = tmp;
  notify_fail("Give what to "+to+"?", NOTIFY_NOT_OBJ);
  if (!arg)
    return 0;
  rc = Give(arg, to, PUTGET_FULL);
  for (i = j = 0; i < sizeof(rc); i++)
    j += sizeof(rc[i]);
  return j;
}

//--------------------------------------------------------------------------
public varargs int fput (string arg) {
  string tmp, to,where;
  mixed rc, i, j;

  if (!arg
   || (   2 != sscanf(arg, "%s into %s", tmp, to)
       && 2 != sscanf(arg, "%s onto %s", tmp, to)
      )
     )
  {
    notify_fail("Put what into or onto what?\n", NOTIFY_NOT_OBJ);
    return 0;
  }
  where = arg[sizeof(tmp)+1..sizeof(tmp)+4];
  arg = tmp;
  notify_fail("Put what "+where+" "+to+"?", NOTIFY_NOT_OBJ);
  if (!arg)
    return 0;
  Set(TMP_WHERE,where);
  rc = Put(arg, to, PUTGET_FULL);
  for (i = j = 0; i < sizeof(rc); i++)
    j += sizeof(rc[i]);
  return j;
}

//--------------------------------------------------------------------------
public varargs int fequip (string arg)
{
  mixed rc, i, j;

  notify_fail("Equip with what?\n", NOTIFY_NOT_OBJ);
  if (!arg)
    return 0;
  if (sizeof(arg) > 5 && arg[0..4] == "with ")
    arg = arg[5..];
  rc = Equip(arg, PUTGET_FULL);
  for (i = j = 0; i < sizeof(rc); i++)
    j += sizeof(rc[i]);
  return j;
}

//--------------------------------------------------------------------------
public varargs int flayoff (string arg)
{
  mixed rc, i, j;

  notify_fail("Lay what aside?\n", NOTIFY_NOT_OBJ);
  if (!arg)
    return 0;

  i = sizeof(arg);
  if (i > 6 && arg[0..5] == "aside ")
    arg = arg[6..];
  else if (i > 5 && arg[0..4] == "down ")
    arg = arg[5..];
  else if (i > 6 && arg[<6..<1] == " aside")
    arg = arg[0..<7];
  else if (i > 5 && arg[<5..<1] == " down")
    arg = arg[0..<5];
  rc = Layoff(arg, PUTGET_FULL);
  for (i = j = 0; i < sizeof(rc); i++)
    j += sizeof(rc[i]);
  return j;
}

//--------------------------------------------------------------------------
public void add_putget_cmds () {
  add_action("fdrop",   "drop");
  add_action("ftake",   "get");
  add_action("ftake",   "take");
  add_action("fput" ,   "put");
  add_action("fgive",   "give");
  add_action("fequip",  "equip");
  add_action("flayoff", "lay");
}

/****************************************************************************/
