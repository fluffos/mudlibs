/* /obj/door
**
** The standard door to clone. By default it is not lockable.
** It is activated with a call to Aloha()!
**
**  11-Jun-93 [Mateese]
**  05-Oct-93 [Mateese] Adapted for new perceptional querying.
**  10-Aug-94 [Mateese] Utilizes auxiliary functions from /std/lock
**  05-Aug-94 [Mateese] P_HIDDEN now supported.
**  23-Apr-96 [Mateese] Doors can't stop ghosts.
*/

#include <config.h>
#include <properties.h>
#include <doors.h>
#include <moving.h>
#include <search.h>
#include <lock.h>

inherit "/std/door";
inherit "/std/thing";

#define TP    this_player()
#define THIS  this_object()
#define SUBID  (to_string(this_object())+":subid")

/*-------------------------------------------------------------------------*/

private mixed pCheckObj, pCheckNotify;

/*-------------------------------------------------------------------------*/

public mixed QueryCheckObj() { return pCheckObj; }
public mixed SetCheckObj(mixed m) { return pCheckObj = m; }

public mixed QueryCheckNotify() { return pCheckNotify; }
public mixed SetCheckNotify(mixed m) { return pCheckNotify = m; }

public int CheckAction(string action, string verb, string arg) {
  return (action != "block" || (LSTATE_GHOST != ({int})TP->Query(P_LSTATE)));
}

public int DoCheckAction(string action, string verb, string arg)
{
  mixed o;
  int rc;

  o = QueryCheckObj();
  rc = 1;
  if (!o)
    rc = CheckAction(action, verb, arg);
  else if (stringp(o) || objectp(o))
    rc = ({int})call_other(o, "CheckAction", action, verb, arg);
  else if (closurep(o))
    rc = funcall(o, action, verb, arg);

  if (!rc && (o = QueryCheckNotify()))
    notify_fail(o);

  return rc;
}

/*-------------------------------------------------------------------------*/

public varargs string InvShort (string what) {
  // Invisible in their associated room.
  return !QueryDoorRoom() ? ModifyInvShort(thing::Short(what)) : "";
}

private string extend_long(string s) {
  if (QueryDoorRoom()) {
    s += "It is obviously "+LockStateText();
    if (QueryKeyIds())
      s += ", and you notice an interesting lock";
    s += ".\n";
  }
  else if (QueryKeyIds()) {
    s += "You notice an interesting lock";
    if (QueryLockState() == LOCK_LOCKED)
      s += " which seems to be locked";
    s += ".\n";
  }
  return s;
}

varargs string Long (string what) {
  if (TP && ({mapping})TP->QueryCmdData(SUBID))
    return thing::Long(what);
  return extend_long(thing::Long(what));
}

varargs string ExaLong (string what) {
  if (TP && ({mapping})TP->QueryCmdData(SUBID))
    return thing::ExaLong(what);
  return extend_long(thing::ExaLong(what));
}

string HelpMsg() {
  string msg;
  msg =
"This is an ordinary door, which, when installed and closed, may block\n"
"a doorway.";
  if (QueryKeyCode())
    msg += " Having the right keys, one may lock or unlock the door with\n"
"the keys. It is possible to combine the actions: e.g. 'open with <key>' is\n"
"the short way of first unlocking the door, then opening it.";
  return msg+"\n";
}

/*-------------------------------------------------------------------------
** Initialize us.
*/

void create () {
  thing::create();
  door::create();
  SetShort ("a door");
  SetLong ("A normal door, made to block doorways.\n");
  SetValue (200);
  SetWeight (8000);
  AddId ("door");
  SetLockState (LOCK_CLOSED);
  Set(P_NOGET, "It doesn't move.\n");
  SetHideExit(HIDE_CLOSED);
  Set(P_HELP_MSG, #'HelpMsg /*'*/);
}

/*-------------------------------------------------------------------------*/

varargs string QueryStatusString () {
  string rc, tmp;
  if (!(rc = ({string})THIS->QueryShort()))
    return 0;
  if (QueryLockState() == LOCK_OPEN)
    tmp = "an open ";
  else
    tmp = "a closed ";
  return tmp+strip_a(rc)+" leading "+QueryDirection()+".\n";
}

/*-------------------------------------------------------------------------*/
// The door mechanic needs to know about the world.

varargs int move (mixed dest, int method, mixed extra) {
  int rc;
  if ((rc = thing::move(dest, method, extra)) == ME_OK)
    notify_move(dest, method, extra);
  return rc;
}

int remove () {
  door::remove();
  return thing::remove();
}

public int clean_up (int ref) {
  int rc;
  // This is not a normal remove(), so don't inform the other door.
  UpMutex();
  rc = ::clean_up(ref);
  DownMutex();
  return rc;
}

/*-------------------------------------------------------------------------*/
// If the door is handled by its remote door, we should give
// out some cute messages.

varargs mixed HandleIDP (int msg, mixed data) {
  int oldstate;
  mixed rc;
  string sh;

  if (!QueryDoorRoom())
    return 0;

  sh = strip_a(QueryShort());

  switch (msg) {
    case IDP_NEWSTATE:
      oldstate = QueryLockState();
      break;
    case IDP_DESTRUCT:
    case IDP_VANISH:
      show("The "+sh+" disappears.\n");
      break;
  }

  rc = door::HandleIDP(msg, data);

  if (msg == IDP_NEWSTATE) {
    switch (QueryLockState()) {
      case LOCK_LOCKED:
        if (oldstate == LOCK_OPEN)
          show ("The "+sh+" closes and you hear a cranking noise.\n",
                "You hear a 'thud', followed by a cranking noise.\n");
        else if (oldstate == LOCK_CLOSED)
          say ("You hear a cranking noise.\n");
        break;
      case LOCK_CLOSED:
        if (oldstate == LOCK_OPEN)
          show ("The "+sh+" is closed.\n",
                "You hear a 'thud' like of a shutting door.\n");
        else if (oldstate == LOCK_LOCKED)
          say ("You hear a cranking noise.\n");
        break;
      case LOCK_OPEN:
        if (oldstate == LOCK_LOCKED)
          show ("You hear a cranking noise and the "+sh+" opens.\n",
                "You hear a cranking noise, followed by a whisp of air.\n");
        else if (oldstate == LOCK_CLOSED)
          show ("The "+sh+" is opened.\n", "You feel a whisp of air.\n");
        break;
    }
  }
  return rc;
}

/*-------------------------------------------------------------------------*/

void init () {
  string dir;
  if (dir = QueryDirection())
    add_action ("fblock", dir);
  door::init();
  add_action ("fknock", "knock");
}

/*-------------------------------------------------------------------------
** Command "<direction>"
**
** If the door is closed/locked, the action is caught and the
** player gets an error message.
*/

int fblock (string arg) {
  string sh;

  if (!QueryDoorRoom() || arg || QueryLockState() == LOCK_OPEN)
    return 0;
  if (CheckActivity() && !DoCheckAction("block", query_verb(), arg))
    return 0;
  if (LSTATE_GHOST == ({int})TP->Query(P_LSTATE))
    return 0;
  sh = strip_a(Short());
  write ("Sorry, that "+sh+" is closed.\n");
  show (capitalize(({string})TP->QueryName())+" tries to leave through "+Short()
        +",\nbut fails painfully.\n", "You hear a muffled 'bonk!'\n");
  SendIDP(IDP_SAY, "You hear a muffled 'bonk' from the "+sh+".\n");
  return 1;
}

/*-------------------------------------------------------------------------*/
public varargs int DoActionFor (int action, int type, object *keys, int kix)

// Do an appropriate user-notifying action for an operation of the lock.
// <action> and <type> denote the operation, <keys> is the keys array in use,
// <kix> the index of the used key.
//
// Valid actions are:
//   LOCK_DO_OPEN, LOCK_DO_CLOSE, LOCK_DO_LOCK, LOCK_DO_UNLOCK
//
// Valid types are:
//   LOCK_ACT_NOKEY   : the player has no keys.
//   LOCK_ACT_WRONGKEY: the player has no matching key.
//   LOCK_ACT_LOCK    : the object is (un)locked with <keys>[<kix>].
//   LOCK_ACT_OPEN    : the object is opened/closed.
//   LOCK_ACT_ALREADY : No actions need to be performed.
//
// Result is the return code:
//   1: Abort action with 1
//   0: Abort action with 0
//  -1: Continue action.
{
  int rc;

  if (type == LOCK_ACT_LOCK && action == LOCK_DO_OPEN && !QueryDoorRoom())
    return -1;

  rc = door::DoActionFor(action, type, keys, kix);

  if (type == LOCK_ACT_OPEN && action == LOCK_DO_OPEN)
    show("", "You feel a whisp of air.\n");
  if (type == LOCK_ACT_OPEN
      && (action == LOCK_DO_OPEN || action == LOCK_DO_LOCK))
    show("", "You hear a 'thud' like of a shutting door.\n");

  return rc;
}

/*-------------------------------------------------------------------------
** Commands "open" and "close"
**
**   "open <door>"
**      Opens the door. If it is locked, and the player has the right key,
**      it is unlocked first.
**   "open <door> with <key>":
**      Opens the door. If it is locked, and the player specified the
**      right key, it is unlocked first.
**   "close <door>"
**   "close <door> with <key>"
**      Closes the door.
*/

varargs int fopen (string str) {
  string sh;

  sh = strip_a(Short());

  if (!ParseArgs (str, 0))
    return 0;

  if (CheckActivity() && !DoCheckAction("door", query_verb(), str))
    return 0;

  if (!QueryDoorRoom()) {
    notify_fail("Quite useless - that "+sh+" leads to nowhere.\n", NOTIFY_NOT_VALID);
    return 0;
  }

  return door::fopen(str);
}

/*-------------------------------------------------------------------------
** Commands "lock" and "unlock"
**
**   "lock <door>"
**      Locks the lock if the player has the right key.
**      If it is open, it is closed first.
**   "lock <door> with <key>"
**      Locks the lock if the player has specified the right key.
**      If it is open, it is closed first.
**   "unlock <door>"
**      Unlocks the lock if the player has the right key.
**   "unlock <door> with <key>"
**      Unlocks the lock if the player has specified the right key.
*/

public varargs int flock (string str) {

  // This notify_fail() is for nil arg-strings, and attempts
  // to (un)lock a lockless object.
  notify_fail(capitalize(query_verb())+" what?\n", NOTIFY_NOT_OBJ);

  if (!ParseArgs (str, 0))
    return 0;

  if (CheckActivity() && !DoCheckAction("lock", query_verb(), str))
    return 0;

  return door::flock(str);
}

/*-------------------------------------------------------------------------
** Commands "knock"
**
**   "knock <door>"
**   "knock at <door>"
**      Knocks at the door.
*/

int fknock (string str) {
  int i;

  if (str && sizeof(str) > 3 && str[0..2] == "at ")
    str = str[3..];

  if (!str || ({mixed})TP->Search (str, SEARCH_ENV_INV|SEARCH_OBJECT) != THIS) {
    if (!str) str = "Knock at what?";
    else {
      str = "You see no "+str+" here.";
      if ((i = ({int})TP->CantSee()) < 0) str += " It's too dark.";
      else if (i > 0)                   str += " It's too bright.";
    }
    return notify_fail (str+"\n", NOTIFY_NOT_OBJ);
  }

  if (CheckActivity() && !DoCheckAction("knock", query_verb(), str))
    return 0;

  if (LSTATE_GHOST == ({int})TP->Query(P_LSTATE))
  {
    write("Your ghostly hand glides into the material of the door.\n");
    return 1;
  }

  write ("KNOCK! KNOCK!\n");
  show ("KNOCK! KNOCK! "+
        capitalize(({string})TP->QueryName())+" knocks at "+Short()+".\n",
        "There is a loud knocking against something.\n");
  SendIDP(IDP_SAY, "You hear a knocking at the door.\n");
  return 1;
}

/*************************************************************************/
