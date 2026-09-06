/*  Raceportal  (Mateese, 11-Apr-96)
 *
 * This is an library module to be inherited into rooms which feature
 * a raceportal between NF-City and the race's homeareal.
 * For an example, see /d/archwiz/common/room/city/pubattic.c .
 *
 * Configurational properties:
 *
 *   string|string* "PortalRace"  (builtin)
 *     The race(s) which may use this portal for free.
 *     See also "PortalMayPass" below.
 *
 *   string "PortalRoom"  (builtin)
 *     The other room to which this portal connects to.
 *
 *   string * "PortalDetail"  (builtin)
 *     An array of strings (or string arrays for the look/exa distinction)
 *     used to implement the portal as room detail.
 *     The used indices are:
 *       0: A non-player looks at the portal.
 *       1: A player of inappropriate race looks at the portal.
 *       2: The other room could not be loaded.
 *       3: The portal description for players of the appropriate race.
 *
 *   string * "PortalSingle"  (builtin)
 *     An array of strings (or string arrays for move()-type messages) used
 *     for the various messages if a single player uses the portal.
 *     Indices are:
 *       0: The move failed, the message is given to notify_fail().
 *       1: The other room could not be loaded.
 *       2: Leave-message for the room (string or ({ string, string }) ).
 *       3: Enter-message for the room (string or ({ string, string }) ).
 *       4: Move-message for the player.
 *
 *   string * "PortalMulti"  (builtin)
 *     An array of strings (or string arrays for move()-type messages) used
 *     for the various messages if a player uses the portal and takes other
 *     players with him.
 *     Indices are:
 *        0: The move failed, the message is given to notify_fail().
 *        1: The other room could not be loaded.
 *     --- Leave-messages for the room, string or ({ string, string })
 *        2: Just the player leaves.
 *     +  3: The player and a small group of people leave.
 *        4: The player and a large group of people leave.
 *     --- Enter-messages for the room, string or ({ string, string })
 *        5: Just the player enters.
 *     +  6: The player and a small group of people enter.
 *        7: The player and a large group of people enter.
 *     --- Messages for the movers.
 *        8: Just the player moves.
 *     +  9: The player and a small group of people move, message for
 *           the player.
 *     + 10: The player and a small group of people move, message for
 *           each of the people.
 *       11: The player and a large group of people move, message for
 *           the player.
 *       12: The player and a large group of people move, message for
 *           the people.
 *     Messages marked with '+' allow to insert the list of names moving
 *     with the player at the place determined by '%%' within the first
 *     (or only) message string. In this cases, an automatic linefeed is
 *     added as well.
 *
 *
 *   closure "PortalMayPass"  (builtin)
 *     A closure taking a living as argument. It has to return 0
 *     if the living may not actively pass through the portal, and
 *     non-zero if it may.
 *     If not set, any living (including NPCs) of appropriate race may
 *     pass the portal.
 *     The closure need not check the race, the portal does this on its
 *     own.
 *
 *
 * Portal exit:
 *
 *   The exit through the portal allows an additional argument
 *   'with <list of names>', with the names being separated by space, comma
 *   or the keyword 'and'.
 *   To add the portal as exit, e.g. 'mirror' resp 'mirror with <names>':
 *
 *     AddExit("mirror", PortalExit());
 *
 *   If the exit requires additional arguments, like 'leave into the gap'
 *   resp. 'leave into the gap with <names>', use:
 *
 *     AddExit("leave", PortalExit( ({"into the gap", "in to the gap"}) ) );
 *
 *   Note that several forms of the same command are given ('into' vs.
 *   'in to').
 *
 *
 * Portal Detail:
 *
 *   The portal is included into the room as 'detail', not as separate object.
 *   To add it's description, use:
 *
 *     AddDetail("portal", #'PortalDetail);
 *
 *   PortalDetail() calls the function PortalMessage(int type, string arg)
 *   with <type> according to the needed message, and <arg> being the detail
 *   looked at. The default PortalMessage() just queries the "PortalDetail"
 *   property, regardless of the given <arg>.
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include <search.h>

#define TP this_player()
#define THIS this_object()

/*------------------------------------------------------------------------*/

/* Our variables */
private nosave string pRoom;
private nosave mixed pRace;
private nosave string * pPDetail, *pPSingle, *pPMulti;
private nosave object counterroom;
private nosave closure pMayPass;

/*------------------------------------------------------------------------*/

public string SetPortalRace (string s) { return pRace = s; }
public string QueryPortalRace ()       { return pRace; }

public mixed SetPortalRoom (mixed s) { counterroom = 0; return pRoom = s; }
public mixed QueryPortalRoom ()       { return pRoom; }

public string * SetPortalDetail (string * s) { return pPDetail = s; }
public string * QueryPortalDetail ()         { return pPDetail; }

public string * SetPortalSingle (string * s) { return pPSingle = s; }
public string * QueryPortalSingle ()         { return pPSingle; }

public string * SetPortalMulti (string * s) { return pPMulti = s; }
public string * QueryPortalMulti ()         { return pPMulti; }

public closure SetPortalMayPass (closure c ) { return pMayPass = c; }
public closure QueryPortalMayPass ()         { return pMayPass; }

/*------------------------------------------------------------------------*/
protected void logit (string * others)
{
  string msg;

  if (sizeof(others))
    msg = sprintf("%2s%-73=s", "", implode(others, "\n"))+"\n";
  else
    msg = "";

  log_file(({int})TP->QueryIsPlayer() ? "portal" : "portal.npc"
          , ctime()+" "+object_name(TP)+"\n  "+object_name(THIS)
                     +"->"+QueryPortalRoom()+"\n"+msg);
}

/*------------------------------------------------------------------------*/
protected int CheckRace(object player)
{
  mixed r;
  r = QueryPortalRace();
  if (stringp(r))
    return ({string})player->QueryRace() == r;
  return -1 != member(r, ({string})player->QueryRace());
}

/*------------------------------------------------------------------------*/
protected object GetOtherRoom()
{
  if (counterroom || !QueryPortalRoom())
    return counterroom;
  catch(counterroom = load_object(QueryPortalRoom()));
  return counterroom;
}

/*------------------------------------------------------------------------*/
protected void ChangeSP (object who, int amount)

// Subtract amount SP from who, not caring about limits, but starting its
// healing if necessary.

{
  int sp;
  sp = ({int})who->QuerySP();
  who->ChangeSP(-amount, sp-amount);
}

/*------------------------------------------------------------------------*/
private int SinglePort ()

// Let this_player() exit through the mirror (assume it is allowed to do
// so). Result is the result for the whole command.

{
  object there;
  int rc;

  there = GetOtherRoom();
  if (!there)
  {
    write(pPSingle[1]);
    return 1;
  }

  logit(0);

  rc = ({int})TP->move(there, M_SPECIAL
               , ({ pPSingle[2], (({string *})GetOtherRoom()->QueryPortalSingle())[3]
                  , pPSingle[4] })
               );
  if (rc != ME_OK)
  {
    string msg;

    notify_fail(pPSingle[0]);
    msg = object_name(THIS)+" failed to move "+object_name(TP)+" to "
          +QueryPortalRoom()+", code "+rc+"\n";
    catch(load_object(CHANNEL_D)->SendTell("error", "RACEPORTAL", msg, 1));
  }
  return rc == ME_OK;
}

/*------------------------------------------------------------------------*/
private varargs mixed MakeMsg (mixed msg, string *names, int noname)

// Work on the message <msg> retrieved from pPMulti.

{
  string msg1;
  string msg2;

  if (stringp(msg))
  {
    msg1 = msg;
    msg2 = 0;
  }
  else
  {
    msg1 = msg[0];
    msg2 = msg[1];
  }

  if (!noname)
  {
    if (msg1[0] != ' ') msg1 = " "+msg1;
    msg1 = ({string})TP->Query(P_NAME)+msg1;
  }

  if (sizeof(names))
  {
    string *tmp;
    tmp = explode(msg1, "%%");
    if (sizeof(tmp) >= 2)
    {
      if (tmp[0][<1] != ' ') tmp[0] += " ";
      if (tmp[1][0] != ' ') tmp[1] = " "+tmp[1];
      msg1 = implode_list(names, tmp[0], implode(tmp[1..], "%%"));
    }
  }

  if (-1 == member("\n.?!", msg1[<1])) msg1 = msg1+".\n";
  if (msg1[<1] != '\n') msg1 = msg1+"\n";

  if (msg2 && -1 == member("\n.?!", msg2[<1])) msg2 = msg2+".\n";
  if (msg2 && msg2[<1] != '\n') msg2 = msg2+"\n";

  if (!msg2)
    return msg1;
  return ({ msg1, msg2 });
}

/*------------------------------------------------------------------------*/
private int MultiPort (string *who)

// Let this_player() exit through the mirror (assume it is allowed to do
// so), taking *who with him.
// The *whos are checked, proper outputs are made, result is the result
// for the whole command.

{
  string msg;
  mixed *found, *tmp, *tmp2;
  object there;
  int rc, i, j;

  there = GetOtherRoom();
  if (!there)
  {
    write(pPMulti[1]);
    return 1;
  }

  found = searchm(TP, who, SEARCH_ENV|SM_OBJECT|WizSearch());
  // founds -> tmp := all strings, found := all non-strings
  tmp = filter(found, #'stringp /*'*/);
  found -= tmp;
  // found, tmp ->
  //   tmp := tmp + Shorts of all non-livings
  //   founds := all livings
  tmp2 = filter(found, #'living /*'*/);
  tmp += map_objects(found-tmp2, "Short");
  tmp -= ({ 0, "" });
  found = tmp2;

  if (sizeof(tmp))
  {
    write(implode_list(tmp, "You can only take livings with you, but "
                          , sizeof(tmp) > 1 ? " aren't." : " isn't one."));
  }
  if (!sizeof(found))
  {
    return SinglePort();
  }

  // Move the found livings, the failers are removed from the array into tmp.
  // tmp2 := names of the moved ones.
  tmp = ({});
  rc = ({int})TP->move(there, M_SILENT);
  if (rc != ME_OK)
  {
    notify_fail(pPMulti[0]);
    msg = object_name(THIS)+" failed to move "+object_name(TP)+" to "
          +QueryPortalRoom()+", code "+rc+"\n";
    catch(load_object(CHANNEL_D)->SendTell("error", "RACEPORTAL", msg, 1));
    return 0;
  }

  for (j = 0, i = sizeof(found); i--; )
  {
    rc = ({int})found[i]->move(there, M_SILENT);
    if (ME_OK != rc)
    {
      msg = object_name(THIS)+" failed to move "+object_name(found[i])+" to "
            +QueryPortalRoom()+", code "+rc+"\n";
      catch(load_object(CHANNEL_D)->SendTell("error", "RACEPORTAL", msg, 1));
      tmp += ({ found[i] });
      found[i] = 0;
    }
    else if (!CheckRace(found[i]))
    {
      ChangeSP(found[i], 10);
      j++;
    }
  }
  ChangeSP(TP, j);
  logit(map(found, #'object_name /*'*/));
  tmp2 = map_objects(found, "Query", P_NAME) - ({ "Someone" });

  // Leave-message for the room.
  switch(sizeof(found))
  {
  case 0:
    if (!({int})TP->Query(P_INVIS))
      show(MakeMsg(pPMulti[2]), ({ TP }) +found);
    break;
  case 1: case 2: case 3: case 4:
    show(MakeMsg(pPMulti[3], tmp2), ({ TP }) +found);
    break;
  default:
    show(MakeMsg(pPMulti[4]), ({ TP }) +found);
    break;
  }

  // Enter-message for the room.
  switch(sizeof(found))
  {
  case 0:
    if (!({int})TP->Query(P_INVIS))
      show(MakeMsg((({string *})GetOtherRoom()->QueryPortalMulti())[5]), ({ TP })+found);
    break;
  case 1: case 2: case 3: case 4:
    show(MakeMsg((({string *})GetOtherRoom()->QueryPortalMulti())[6]), ({ TP })+found);
    break;
  default:
    show(MakeMsg((({string *})GetOtherRoom()->QueryPortalMulti())[7]), ({ TP })+found);
    break;
  }

  // Move-message for the movers.
  switch(sizeof(found))
  {
  case 0:
    tell_object(TP, pPMulti[8]);
    break;
  case 1: case 2: case 3: case 4:
    tell_object(TP, MakeMsg(pPMulti[9], tmp2, 1));
    for (i = sizeof(found); i--; )
    {
      tell_object(found[i]
                 , MakeMsg(pPMulti[10], tmp2[0..i-1]+tmp2[i+1..]+({ "you" }))
                 );
    }
    break;
  default:
    tell_object(TP, pPMulti[11]);
    map(found[i], #'tell_object /*'*/, MakeMsg(pPMulti[12]));
    break;
  }

  // Look at the room
  map_objects(({ TP })+found, "LookAfterMove", M_SILENT, 0);

  // Other Notifications.
  if (sizeof(tmp))
  {
    tmp2 = map_objects(tmp, "Query", P_NAME) - ({ "Someone" });
    tell_object(TP, implode_list(tmp2, "", " did not make it."));
  }
  if (({int})TP->QuerySP() < 0)
    tell_object(TP, "You feel mentally exhausted.\n");
  else if (({int})TP->QuerySP() < 5)
    tell_object(TP, "You feel mentally tired.\n");
  for (i = sizeof(found); i--; )
  {
    if (({int})found[i]->QuerySP() < 0)
      tell_object(found[i], "You feel mentally exhausted.\n");
    else if (({int})found[i]->QuerySP() < 5)
      tell_object(found[i], "You feel mentally tired.\n");
  }

  return 1;
}

/*------------------------------------------------------------------------*/
protected mixed SplitArg (string arg)

// Check the 'arg' string for the keyword 'with' and return an appropriate
// split of it:
//
//  ({ ({ words before 'with' }), ({ words after 'with' }) })
//
// Each of the two subarrays mey be empty. The words are made lowercase.
// If the keyword 'with' did not appear, the second subarray is 0.
// The function returns 0 if this_player() is of the wrong race.

{
  string *tmp, *tmp2;
  closure c;
  int with;

  if (!TP || !CheckRace(TP))
    return 0;

  c = QueryPortalMayPass();
  if (closurep(c) && !funcall(c, TP))
    return 0;

  if (!arg)
    return ({ ({}), 0 });

  tmp = map(explode(arg, " ") - ({ "", 0 }), #'lower_case /*'*/);
  with = member(tmp, "with");
  if (with < 0)
    return ({ tmp, 0 });

  tmp2 = explode(implode(tmp[with+1..], ","), ",") - ({ "and", "", 0 });
  return ({ tmp[0..with-1], tmp2 });
}

/*------------------------------------------------------------------------*/
public varargs int PortalExitFun(string arg, string * argwords)

// Take the portal exit.
//
//   <verb> {<argwords>} [with <list of names>]

{
  mixed * tmp;

  tmp = SplitArg(arg);
  if (!tmp || (sizeof(argwords) && !arg))
    return 0;

  if (sizeof(argwords))
    tmp[0] = tmp[0] - argwords;

  if (sizeof(tmp[0]) || (tmp[1] && !sizeof(tmp[1])))
  {
    notify_fail("What?\n", NOTIFY_ILL_ARG);
    return 0;
  }

  if (tmp[1])
    return MultiPort(tmp[1]);

  return SinglePort();
}

/*------------------------------------------------------------------------*/
protected varargs closure PortalExit(mixed args)

// Create a closure which calls PortalExitFun() with an appropriate
// argwords parameter.
// <args> determines the additional args needed after the command verb.

{
  string * tmp;
  int i;

  if (!args)
    return lambda(({'a /*'*/}), ({#'PortalExitFun /*'*/, 'a /*'*/, 0 }));

  if (!pointerp(args))
    args = ({ args });

  tmp = ({});
  for (i = sizeof(args); i--; )
    tmp += explode(args[i], " ") - ({ "", 0 });

  tmp = map(tmp, #'lower_case /*'*/);

  return lambda(({'a /*'*/}), ({#'PortalExitFun /*'*/, 'a /*'*/, quote(tmp) }));
}

/*------------------------------------------------------------------------*/
public mixed PortalMessage (int type, string arg)

/* The PortalDetail()-function calls this function to retrieve the messages
 * to be shown as result of the examination of <arg>.
 */

{
  if (type >= sizeof(pPDetail))
  {
    raise_error("Portal detail '"+arg+"' t"+type+" required, just "
                +sizeof(pPDetail)+" details given.\n");
    return "<Unimplemented Detail>.\n";
  }
  return pPDetail[type];
}

/*------------------------------------------------------------------------*/
protected mixed PortalDetail(string arg)

// Return the Roomdetail string for the portal.

{
  if (!TP)
    return PortalMessage(0, arg);

  if (!CheckRace(TP))
    return PortalMessage(1, arg);

  if (!GetOtherRoom())
    return PortalMessage(2, arg);

  return PortalMessage(3, arg);
}

/*========================================================================*/
