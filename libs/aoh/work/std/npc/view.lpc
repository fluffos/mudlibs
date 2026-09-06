/* std/npc/view.c
**
** The various sensing commands of a living.
**
** Matrix-Inventory:
**  (c) 1993/03/19 - 1994/08/30 by Taube
**  Idea from Yaro (Tubmud)
**
** TODO:  show_object, show need to be replaced after a solution for the
** TODO:: display filter of the room was found
*/

#include <properties.h>
#include <lock.h>
#include <moving.h>
#include <search.h>
#include <config.h>
#include <npc.h>
#include <msgclass.h>
#include <secure/wizlevels.h>

#define THIS  this_object()
#define TP    this_player()
#define ENV   environment

// Define this for extra code for 'read'
/* #define READCODE */

/*--------------------------------------------------------------------------*/

public varargs mixed Query(string name); // std/base
public varargs int CanSee(object env);   // std/living/description
public varargs int CantSee(object env);  // std/living/description
public varargs mixed Search(mixed what, int mode);
                                         // std/living/description
public varargs mixed SearchM(mixed what, int mode, closure pred);
                                         // std/living/description
public string QueryName();               // std/living/description
public string QueryObjective();          // std/living/description
public string *_weapons (string poss);
public string *_armours ();
public string *_equipment ();
public mapping sortObjsByEnv (object * what, object me, object * envs);
                                       // std/living/putget
private string _make_inv (object cont, int mode, int depth, int width);
//--------------------------------------------------------------------------

public int aBrief, aObvious = 1;

//--------------------------------------------------------------------------

public int QueryBrief()    { return aBrief; }
public int SetBrief(int b) { return aBrief = b; }

public int QueryObvious()    { return aObvious; }
public int SetObvious(int o) { return aObvious = o; }

//--------------------------------------------------------------------------
public int CheckLight () {
  int ct;

  if (Query(P_BLIND)) {
    notify_fail("You are blind.\n", NOTIFY_NOT_VALID);
    return (1<<32);
  }
  if (ct = CantSee())
  {
    if (ct < 0)
      notify_fail("It's too dark.\n", NOTIFY_NOT_VALID);
    else
      notify_fail("It's too bright.\n", NOTIFY_NOT_VALID);
  }
  return ct;
}

//--------------------------------------------------------------------------
public varargs mapping describeEnvs (mixed envs, int str_by_obj)
{
  object *dinv, *denvs, denv, env;
  mixed tmp;
  mapping rc;
  int i, j, alive;
  string msg, sh;

  if (!pointerp(envs))
    envs = ({ envs });

  dinv = ({ THIS })+deep_inventory(THIS);

  denvs = ({});
  for (denv = environment(THIS); denv; denv = environment(denv))
    denvs += ({ denv });

  rc = m_allocate(0,2);
  for (i = 0; i < sizeof(envs); i++)
  {
    if (-1 != member(dinv, env = envs[i]))
    {
      msg = "carried ";
      while (env != THIS) {
        if ("" != (sh = ({string})env->Short()||""))
          msg += "in "+sh+" ";
        env = environment(env);
      }
    }
    else {
      msg = "";
      while (env && -1 == (j = member(denvs, env)))
      {
        if ("" != (sh = ({string})env->Short()||"")) {
          if (living(env)) {
            msg += "carried by "+(({string})env->QueryName())+" ";
            alive = 1;
          }
          else
            msg += "in "+sh+" ";
        }
        env = environment(env);
      }
      if (j)
        msg += "outside ";
      else if (!alive && !str_by_obj)
        msg += "here ";
    }

    j = (-1 != member(dinv, env = envs[i]));
    msg = msg[0..<2];
    if (!str_by_obj)
    {
      tmp = rc[msg,0];
      if (!tmp)
        rc += ([ msg : ({ env }); j ]);
      else if (-1 == member(tmp, env))
        rc[msg,0] = tmp+({ env });
    }
    else
    {
      rc[env,0] = msg;
      rc[env,1] = j;
    }
  }
  return rc;
}

//--------------------------------------------------------------------------
public varargs mixed LookFor (mixed what, int impl)
{
  mapping bags, envs;
  mixed tmp, found, tmp2, rc;
  string msg, msg2;
  int i, j, k;

  if (stringp(what))
    what = ({ what });

  if (objectp(what))
    what = ({ what });
  else if (pointerp(what)) {
    tmp = filter(what, #'objectp /*'*/);
    what = SearchM( filter(what, #'stringp /*'*/)
                  , SEARCH_INV_ENV|SM_MULTI|SM_COUNT|WizSearch()
                  );
    if (sizeof(tmp))
      what[FOUND_SINGLE] = envs+(what[FOUND_SINGLE] || ({}));
  }
  else
    what = ({});

  msg = "";

  // Merge everything from 'what' into 'found', put the findings
  // back into 'what'
  what[FOUND_SPECS] = 1<<30;
  found = sort_findings(what);
  what = found[FOUND_SINGLE];
  if (sizeof(what) && pointerp(what[0]))
    what = what[0];
  if (found[-FOUND_SINGLE])
    msg = "You did not find as much things as you though you could.\n";

  // Construct the message for the items not being located.
  if (j = sizeof(tmp = found[FOUND_IDS]))
    msg = msg+implode_list(tmp, "You don't find ", ".", " or");
  else if (!sizeof(what))
  {
    if (Query(P_BLIND)) msg += "Being blind doesn't help you.\n";
    else if ((i = CantSee()) < 0) msg += "It is too dark to see anything.\n";
    else if (i > 0) msg += "It is too bright to see anything.\n";
    else msg += "You find nothing appropriate.\n";
  }

  rc = ({ msg });

  // Sort objects by environments, compute the messages for the environments.
  bags = sortObjsByEnv(what, THIS, &tmp);
  envs = describeEnvs(tmp);

  // First, add the carried objects to the output message,
  // then the ones lying around.
  for (k = 0; k < 2; k++)
  {
    tmp = sort_array(m_indices(envs), #'< /*'*/);
    for (i = 0; i < sizeof(tmp); i++)
    {
      if (!envs[tmp[i],1] == !!k)
        continue;
      tmp2 = envs[tmp[i],0];
      found = ({});
      for (j = 0; j < sizeof(tmp2); j++)
        found += bags[tmp2[j]];
      if (sizeof(found))
      {
        msg2 = capitalize(tmp[i])+": "+fold_objlist(found, 1)+".";
        rc += ({ msg2[0..1]+sprintf("%2s%-73=s", "", msg2[2..])[2..]+"\n" });
      }
    }
  }
  if (impl)
    rc = implode(rc, "");
  return rc;
}

//--------------------------------------------------------------------------
public varargs string LookRoom (int flags, object startroom, string type)
{
  int trans, l, brief;
  object obj, exclude, room;
  string ret;

  if (l = CantSee())
    return (l < 0 ? "It is dark." : "It is far too bright.")
           +" You see nothing.\n";

  if (!(SENSE_SILENT & flags) && !Query(P_INVIS))
    show(QueryName()+" looks around.\n");

  ret = "";
  trans = 1000;
  exclude = this_object();
  room = environment();
  if (startroom == room)
    startroom = 0;
  brief = QueryBrief();

  while (room && trans) {
    if (!startroom) {
      if (trans < SEARCH_MIN_TRANSP)
        ret += "Something undefinable.\n";
      else {
        if ((flags & SENSE_MOVE) && brief)
          ret += ({string})room->IntShort()+". ";
        if (type == "examine")
          ret += ({string})room->GetExaIntDesc(exclude, THIS);
        else
          ret += ({string})room->GetIntDesc((flags & SENSE_MOVE) && brief, exclude, THIS);
      }
    }
    exclude = room;
    trans = (trans * ({int})room->QueryTransparent()) / 1000;
    obj = room;
    room = ({object})obj->Query(P_OUTSIDE) || environment(obj);
    if (startroom == room)
      startroom = 0;
    if (!startroom && room && CanSee(room) && trans)
      ret += ({string})obj->Query(P_PREOUTSIDE)||"Outside you can see:\n";
  }
  return ret;
}

//--------------------------------------------------------------------------
public varargs void LookAfterMove (int method, mixed extra)
{
  if (interactive()) {
    if (IS_IMMORTAL(THIS))
      msg_object(THIS, CMSG_GENERIC,
                 (objectp(ENV()) ? to_string(ENV()) : "???")+"\n");
    msg_object(THIS, CMSG_ROOM, LookRoom(SENSE_SILENT|SENSE_MOVE));
  }
}

//--------------------------------------------------------------------------
public varargs string SenseRoom (string type, object room, int flags)
{
  string desc;

  switch(type) {
    case "look":
      return LookRoom(0, room);
    case "examine":
      if (!Query(P_INVIS))
        show(QueryName()+" musters "+QueryObjective()+" surroundings.\n");
      return LookRoom(SENSE_SILENT, room, "examine");
    case "smell":
      if (!Query(P_INVIS))
        show(QueryName()+" sniffs the air.\n");
      desc = ({string})(room || environment(THIS))->IntSmell();
      break;
    case "hear":
      if (!Query(P_INVIS))
        show(QueryName()+" listens.\n");
      desc = ({string})(room || environment(THIS))->IntNoise();
      break;
    default:
      return "You don't sense anything.\n";
  }
  return desc || "You don't "+type+" anything.\n";
}

//--------------------------------------------------------------------------
public varargs mixed Sense (mixed what, string type, int flags)
{
  object env;
  mapping envs, shorts;
  mixed tmp, found, tmp2, rc, *det, msg, msg2, msg3;
  int i, j, k;

  if (!type)
    type = "look";

  if(!(env = environment()))
    msg = "You float in the fabric of space.\n";
  else
    msg = "";

  if (stringp(what))
    what = ({ what });

  if (objectp(what))
    what = ({ what });
  else if (pointerp(what)) {
    tmp = filter(what, #'objectp);
    // tmp2 is needed later for the 'floor'/'ground' hack :-(
    what = SearchM( tmp2 = filter(what, #'stringp /*'*/)
                  , SEARCH_INV_ENV|SM_MULTI|SM_COUNT|WizSearch()
                  );
    if (sizeof(tmp))
      what[FOUND_SINGLE] = envs+(what[FOUND_SINGLE] || ({}));
  }
  else
    what = ({});

  // Merge everything from 'what' into 'found', put the findings
  // back into 'what'

#ifdef READCODE
  if (type != "read")
    found = sort_findings(what);
  else
    found = sort_findings(what, sort_f_nprop(P_READ_MSG));
#else
  found = sort_findings(what);
#endif

  what = found[FOUND_SINGLE];
  if (sizeof(what) && pointerp(what[0]))
    what = what[0];
  if (found[-FOUND_SINGLE])
    msg += "You did not find as much things as you though you could.\n";

  // Construct the message for the items not being located.
  // But first check if they are details from the room.
  // This implies a crude hack: Search() might have found a 'floor' or
  // 'ground', but these may also be details. So explicitely check for them.
  // Second crude hack: details are always found even if objects of same id
  // exist.

  det = ({});
  k = 0; // hidden flag
  if (env && sizeof(what) && -1 != member(what, env)) {
    det = ({mixed *})env->QueryIndoors() ? ({ "floor", "ground" }) : ({ "ground" });
    det = det & tmp2;
    k = sizeof(det); // Hidden flag
  }
  tmp2 -= ({ "floor", "ground" });
  if (env && sizeof(tmp2)) {
    det += (tmp2-det);
    k = sizeof(det); // Hidden flag
  }
  tmp = det+((found[FOUND_IDS]||({}))-det);
  if (env && (j = sizeof(tmp)))
  {
    det = allocate(j);
    for (i = 0; i < j; i++)
    {
      switch(type) {
      case "look":
        msg2 = ({mixed})env->GetDetail(tmp[i]);
        if (pointerp(msg2))
          msg2 = msg2[0];
        break;
      case "examine":
        msg2 = ({mixed})env->GetDetail(tmp[i]);
        if (pointerp(msg2)) {
          if ( sizeof( msg2 ) >=2 )
            msg2 = msg2[1];
          else
            msg2 = msg2[0];
        }
        break;
      case "hear":
        msg2 = ({mixed})env->GetNoise(tmp[i]);
        break;
      case "smell":
        msg2 = ({mixed})env->GetSmell(tmp[i]);
        break;
      case "read":
        msg2 = ({mixed})env->GetReadMsg(tmp[i]);
        break;
      }
      if (msg2) {
        det[i] = ({ msg2, tmp[i] });
        tmp[i] = 0;
      }
    }
    while (k--)
      if (!det[k])
        tmp[k] = 0;
      else if (pointerp(what))
        what -= ({ env });
    det -= ({ 0 });
    tmp -= ({ 0 });
  }

  if (   !sizeof(what) && !sizeof(det)
#ifdef READCODE
      && (type != "read" || !sizeof(found[FOUND_NOTHANDLE]))
#endif
     )
  {
    if (Query(P_BLIND)) msg += "Being blind doesn't help you.\n";
    else if ((i = CantSee()) < 0) msg += "It is too dark to see anything.\n";
    else if (i > 0) msg += "It is too bright to see anything.\n";
    else msg += "You see nothing appropriate.\n";
  }
  else if (j = sizeof(tmp))
    msg = msg+implode_list(tmp, "You don't see ", ".", " or");

#ifdef READCODE
  if (type == "read" && (j = sizeof(tmp = found[FOUND_NOTHANDLE])))
  {
    tmp = "There is nothing to read on "+fold_objlist(tmp, 1)+".";
    msg += tmp[0..1]+sprintf("%2s%-73=s", "", tmp[2..])[2..]+"\n";
  }
#endif

  rc = ({ msg });

  // Sort objects by environments, compute the messages for the environments.
  sortObjsByEnv(what, THIS, &tmp);
  envs = describeEnvs(tmp, 1);

  // Construct the message. If there are several objects, prepend the
  // looked at objects short and its location before each description.
  // To reduce the output, found is used to fold equal descriptions
  // into just one, recording their location within rc.
  // shorts collects for each objects' short which objects have it.

  found = ([]);
  shorts = ([]);
  j = (sizeof(what)+sizeof(det)) > 1;
  for (i = 0; i < sizeof(what); i++)
  {
    if (what[i] != THIS)
    {
      tmp = (({mixed})what[i]->QueryIds()||({"something"}))[<1];
      msg = 0;
      if ("" == (msg2 = ({mixed})what[i]->Short(tmp)))
        msg2 = 0;
      else
        msg = msg2;
    }
    else
    {
      msg2 = "yourself";
      msg = QueryObjective()+"self";
      tmp = "yourself";
    }

    if ("" != (msg3 = envs[environment(what[i]),0]))
    {
      if (msg)
        msg += " ("+msg3+")";
      msg3 = ", "+msg3;
    }

    if (msg) {
      if (!shorts[msg])
        shorts[msg] = ({ what[i] });
      else
        shorts[msg] += ({ what[i] });
    }

    msg = "";
    if (j && msg2)
      msg += "  ("+msg2+msg3+")\n";

    // If we are in the thing we looked at, look at it from within.
    // Else construct its external view.
    if (
#ifdef READCODE
        type != "read" &&
#endif
        -1 != member(deep_inventory(what[i]), THIS)
       )
    {
      tmp2 = SenseRoom(type, what[i]);
    }
    else if (msg2)
    {
      switch(type) {
      case "read":
        tmp2 = ({mixed})what[i]->Read(tmp) || "There is nothing to read.\n";
        break;
      case "look":
        tmp2 = ({mixed})what[i]->Long(tmp)+(living(what[i])?
          "":({mixed})what[i]->Content(type, 1) || "");
        break;
      case "examine":
        tmp2 = ({mixed})what[i]->ExaLong(tmp)+(({mixed})what[i]->Content(type, 1) || "");
        break;
      case "hear":
        tmp2 = ({mixed})what[i]->Noise(tmp) || "You hear nothing.\n";
        break;
      case "smell":
        tmp2 = ({mixed})what[i]->Smell(tmp) || "You smell nothing.\n";
        break;
      }
    }

    msg += tmp2;

    if (!m_contains(&k, found, msg)) {
      rc += ({ ({ 1, msg2, msg3, tmp2 }) });
      found[msg] = sizeof(rc)-1;
    }
    else
      rc[k][0]++;
  }

  // Resort the collected outputs in rc into an array of strings.
  for (i = 1; i < sizeof(rc); i++)
  {
    msg = "";
    if (j && rc[i][1])
    {
      msg += "  ("+rc[i][1];
      if (rc[i][0] > 1)
        msg += "["+rc[i][0]+"]";
      msg += rc[i][2]+")\n";
    }
    rc[i] = msg+rc[i][3];
  }

  // Add the details to rc. Also collect them in msg3 in case
  // messages shall be issued.
  msg3 = ({});
  for (i = 0; i < sizeof(det); i++)
  {
    rc += ({ (j ? "  ("+det[i][1]+", here)\n" : "")+det[i][0] });
    msg3 += ({ det[i][1] });
  }

  // If wanted, implode rc into just one string.
  if (flags & SENSE_IMPL)
  {
    if (sizeof(rc) > 2)
      rc = rc[0]+implode(rc[1..], "\n");
    else
      rc = implode(rc, "");
  }

  // If wanted, issue appropriate messages to the surrounding.
  // (this is another biggy as livings need a special treatment).
  if (!(flags & SENSE_SILENT) && !Query(P_INVIS)
      && (sizeof(msg3) || sizeof(what))
     )
  {
    msg = QueryName()+" ";
    switch(type) {
    case "read":
      msg += "reads ";
      break;
    case "look":
      msg += "looks at ";
      break;
    case "examine":
      msg += "examines ";
      break;
    case "hear":
      msg += "listens to ";
      break;
    case "smell":
      msg += "sniffs at ";
      break;
    }

    tmp2 = m_indices(shorts);

    // tmp becomes the list of all livings which get extra messages.
    // THIS is included and stands for the default message.
    if (sizeof(what))
      tmp = filter(what, #'living /*'*/) - ({ THIS }) + ({ THIS });
    else
      tmp = ({ THIS });

    for (i = sizeof(tmp); i--; )
    {
      msg2 = msg3+({});
      for (j = sizeof(tmp2); j--; ) {
        found = shorts[tmp2[j]];
        if (   tmp[i] != THIS && -1 != member(found, tmp[i]))
          found -= ({ tmp[i] });
        if (sizeof(found)) {
          if (sizeof(found) > 1)
            msg2 += ({ tmp2[j]+"["+sizeof(found)+"]" });
          else
            msg2 += ({ tmp2[j] });
        }
      }
      if (tmp[i] != THIS)
        msg2 += ({ "you" });
      if (sizeof(msg2))
      {
        if (sizeof(msg2) > 1)
          msg2 = implode(msg2[0..<2], ", ")+" and "+msg2[<1];
        else
          msg2 = msg2[<1];
        msg2 = msg+msg2+".";
        msg2 = msg2[0..1]+sprintf("%2s%-73=s", "", msg2[2..])[2..]+"\n";
        if (tmp[i] != THIS)
          show_object(tmp[i], msg2);
        else
          show(msg2, tmp);
      }
    }
  }

  return rc;
}

//--------------------------------------------------------------------------
public varargs int flook (string arg)
{
  string to;

  if (   !arg
      || -1 != member(({"","room","here","around","at room"}), norm_id(arg))
     ) {
    msg_write( CMSG_ROOM, LookRoom());
    return 1;
  }
  if (1 == sscanf(arg, "for %s", to))
  {
    msg_write( CMSG_ROOM, LookFor(to, 1));
    return 1;
  }

  if (   1 == sscanf(arg, "at %s", to)
      || (to = arg)
     )
  {
    msg_write( CMSG_ROOM, Sense(to, "look", 1));
    return 1;
  }

  notify_fail("Look what?\n", NOTIFY_NOT_CMD);
  return 0;
}

public varargs int flooka (string arg)
{
  if (   (sizeof(query_verb()) > sizeof("look"))
      || (query_verb() != "look"[0..sizeof(query_verb())-1])
     )
    return 0;
  return flook(arg);
}

//--------------------------------------------------------------------------
public varargs int fexamine (string arg)
{
  if (   !arg
      || -1 != member(({"","room"}), norm_id(arg))
     ) {
    if (!Query(P_INVIS))
      show(QueryName()+" musters its surroundings.\n");
    msg_write( CMSG_ROOM, LookRoom(SENSE_SILENT, 0, "examine"));
    return 1;
  }
  msg_write(CMSG_ROOM,Sense(arg, "examine", SENSE_IMPL));
  return 1;
}

public varargs int fexaminea (string arg)
{
  if (   (sizeof(query_verb()) > sizeof("examine"))
      || (query_verb() != "examine"[0..sizeof(query_verb())-1])
     )
    return 0;
  return fexamine(arg);
}

//--------------------------------------------------------------------------
public varargs int flisten (string arg)
{
  string to;

  if (   !arg
      || -1 != member(({"","room","to room"}), norm_id(arg))
     ) {
    msg_write( CMSG_ROOM|MMSG_HEAR,SenseRoom("hear"));
    return 1;
  }
  if (   1 == sscanf(arg, "to %s", to)
      || (to = arg)
     )
  {
    msg_write( CMSG_ROOM|MMSG_HEAR, Sense(to, "hear", SENSE_IMPL));
    return 1;
  }

  notify_fail("Listen to what?\n", NOTIFY_NOT_CMD);
  return 0;
}

//--------------------------------------------------------------------------
public varargs int fsmell (string arg)
{
  string to;

  if (   !arg
      || -1 != member(({"","room","at room"}), norm_id(arg))
     ) {
    msg_write( CMSG_ROOM|MMSG_SMELL, SenseRoom("smell"));
    return 1;
  }
  if (   1 == sscanf(arg, "at %s", to)
      || (to = arg)
     )
  {
    msg_write( CMSG_ROOM|MMSG_SMELL, Sense(to, "smell", SENSE_IMPL));
    return 1;
  }

  notify_fail("Smell what?\n", NOTIFY_NOT_CMD);
  return 0;
}

//--------------------------------------------------------------------------
public varargs int fread (string arg)
{
  if (!arg || arg == "") {
    notify_fail("Read what?\n", NOTIFY_NOT_CMD);
    return 0;
  }
  msg_write( CMSG_GENERIC, Sense(arg, "read", SENSE_IMPL));
  return 1;
}

//--------------------------------------------------------------------------
private string
_make_inv (object cont, int mode, int depth, int width) {
  string list, sh;
  mixed  *inv;
  object *sep;
  int i, j, indent;

  indent = 2*depth+2;

  // For long listing, fake the unique_array(), else group
  // the inventories items together by their InvShort().
  if (INV_LONG & mode)
    inv = ({ all_inventory(cont) });
  else
    inv = unique_array(all_inventory(cont), "InvShort", "");
  // Thragor suggested further grouping by object_name()s here, but
  // that would need to be done manually, and the resulting output
  // is likely to not be very logical to the player.

  list = "";
  for (i = 0; i < sizeof(inv); i++) {

    // Move all objects from inv[i] which may not be listed in just
    // one entry.
    sep = ({}); // Default for non-long, non-deep mode.
    if (INV_LONG & mode) { // Force long listing.
      sep = inv[i];
      inv[i] = ({ });
    }
    else if (!(INV_FLAT & mode)) { // Check for items with inventory
      sep = allocate(sizeof(inv[i]));
      for (j = sizeof(inv[i]); j--; )
        if (first_inventory(inv[i][j])) {
          sep[j] = inv[i][j];
          inv[i][j] = 0;
        }
    }

    inv[i] -= ({ 0 });
    sep    -= ({ 0 });

    // Construct summed up entry for the items in inv[i], if any.
    // inv[i] can't contain invisible items.
    if (sizeof(inv[i])) {
      sh = ({string})inv[i][0]->InvShort();
      if (sizeof(inv[i]) > 1)
        sh = sprintf("%*s- %s [%d]\n", indent-2, "", sh, sizeof(inv[i]));
      else
        sh = sprintf("%*s- %s\n", indent-2, "", sh);
      list += sh[0..indent-1]+sprintf("%*s%-*=s", indent, "", width-indent
                                     , sh[indent..])[indent..];
    }

    // Add the separate entries from sep[], if any.
    // Note that sep[] may contain invisible items.
    for (j = 0; j < sizeof(sep); j++) {
      if ("" == (sh = ({string})sep[j]->InvShort()))
        continue;
      sh = sprintf("%*s- %s\n", indent-2, "", sh);
      list += sh[0..indent-1]+sprintf("%*s%-*=s", indent, "", width-indent
                                     , sh[indent..])[indent..];
      if (!(INV_FLAT & mode) && LOCK_OPEN == ({int})sep[j]->Query(P_LOCKSTATE))
        list += _make_inv(sep[j], mode, depth+1, width);
    }
  }
  if (list[<1] != '\n')
    list += "\n";
  return list;
}

//--------------------------------------------------------------------------
public varargs string Inventory (int mode) {
  return _make_inv(THIS, mode, 0, (mode & INV_NARROW) ? 38 : 78);
}

//--------------------------------------------------------------------------
public int finventory (string arg) {
  string *list;
  int mode, low, high;

  mode = INV_NARROW;
  list = ({});
  if (arg) {
    list = explode(lower_case(arg), " ");
    if (member(list, "flat") != -1)
      mode |= INV_FLAT;
    if (member(list, "long") != -1)
      mode |= INV_LONG;
    if (member(list, "list") != -1)
      mode ^= INV_NARROW;
  }

  if (CheckLight())
    return 0;

  if (   !first_inventory(THIS)
      || !sizeof(map_objects(all_inventory(THIS), "InvShort")-({ 0, "" }))
     )
    msg_write( CMSG_GENERIC, "You don't possess anything.\n");
  if (member(list, "equip") != -1 || member(list, "equipment") != -1)
  {
    string str, *strs;

    str = "";
    strs = _armours();
    if (sizeof(strs))
      str = implode_list(strs, "You wear ");
    strs = _weapons("your");
    if (sizeof(strs))
      str += "You wield "+implode(strs, ".\nYou wield ")+".\n";
    if (!sizeof(str) )
      str = "You neither wield nor wear anything.\n";
    msg_write( CMSG_GENERIC, str);
    strs = _equipment();
    if (sizeof(strs))
      msg_write( CMSG_GENERIC, implode_list(strs, "You are equipped with "));
    return 1;
  }
  if (!(mode & INV_NARROW))
    msg_write( CMSG_GENERIC, Inventory(mode));
  else {
    string str;
    list = explode(Inventory(mode), "\n") - ({ "" });
    if (sizeof(list) & 1)
      list += ({ "" });
    high = (sizeof(list)+1)/2;
    str = "";
    for (low = 0; low < high; low++)
      str += sprintf("%-40s%-s\n", list[low], list[high+low]);
    msg_write( CMSG_GENERIC, str);
  }
  return 1;
}

//--------------------------------------------------------------------------
public void add_view_cmds ()
{
  add_action("fexaminea", "exa", 1);
  add_action("finventory", "i");
  add_action("finventory", "inventory");
  add_action("flooka", "l", 1);
  add_action("fread", "read");
  add_action("flisten", "listen");
  add_action("fsmell", "smell");
}

/****************************************************************************/
