/* /std/door
**
** The basic magic of a door.
**
**  05-Oct-94 [Mateese]
*/

#include <moving.h>
#include <doors.h>
#include <rooms.h>
#include <classes.h>

#define THIS this_object()
#define ENV  environment

inherit "/std/lock";

private nosave int mutex;        // To lock SendIDP
private nosave int mutex2;       // To lock Aloha
private nosave string Pdir;      // the command, also adjective
private nosave object Proom;     // the room of the door; used as flag
private nosave string Poroom;    // filename of the remote room
private nosave string Podoor;    // filename of the remote door
private nosave string Pdoorcode; // door id
private nosave int Phidedoor, Phideexit;  // non-obviousility
private nosave int Pchkdoor;     // non-useability

public object OtherDoor (); // forward

/*-------------------------------------------------------------------------*/

public string SetDirection (string dir) {
  THIS->AddAdjective(dir);
  return Pdir = dir;
}
public string QueryDirection () { return Pdir; }

public string SetDoorCode (string code) {
  THIS->AddId(code);
  return Pdoorcode = code;
}
public string QueryDoorCode () { return Pdoorcode; }

public string SetOtherRoom (string name) { return Poroom = name; }
public string QueryOtherRoom () { return Poroom; }

public object SetDoorRoom (object obj) { return Proom = obj; }
public object QueryDoorRoom () { return Proom; }

public int SetHideDoor (int v) {
  object door;
  Phidedoor = v & ~HIDE_BOTH;
  if ((v & HIDE_BOTH) && (door = OtherDoor()))
    door->SetHideDoor(Phidedoor);
  return Phidedoor;
}
public int QueryHideDoor () { return Phidedoor; }

public int SetCheckDoor (int v) {
  object door;
  Pchkdoor = v & ~DACT_BOTH;
  if ((v & DACT_BOTH) && (door = OtherDoor()))
    door->SetCheckDoor(Pchkdoor);
  return Pchkdoor;
}
public int QueryCheckDoor () { return Pchkdoor; }

public int SetHideExit (int v) {
  object door;
  Phideexit = v & ~HIDE_BOTH;
  if ((v & HIDE_BOTH) && (door = OtherDoor()))
    door->SetHideExit(Phideexit);
  return Phideexit;
}
public int QueryHideExit () { return Phideexit; }

/*-------------------------------------------------------------------------*/

public int UpMutex() { return ++mutex; }
public int DownMutex() { return --mutex; }
public int ZeroMutex() { return mutex = 0; }
public int QueryMutex() { return mutex; }

public object OtherDoor () {
  object room, door;
  mixed  proom, poroom, pdoorcode;

  if (!(proom = QueryDoorRoom()))
    return 0;
  if (proom != ENV())
    raise_error ("Proom invalid.\n");

  if (   !(poroom=QueryOtherRoom())
      || !(pdoorcode = QueryDoorCode())
      || !(room = (objectp(poroom) ? poroom : find_object(poroom)))
      || !(door = present(pdoorcode, room))
     )
    return 0;
  return door;
}

public mixed CallOtherDoor (string fun, mixed data) {
  object room, door;
  mixed  proom, poroom, pdoorcode;

  if (!(proom=QueryDoorRoom()))
    return 0;
  if (proom != ENV())
    raise_error ("Proom invalid.\n");

  if (   !(poroom=QueryOtherRoom())
      || !(pdoorcode=QueryDoorCode())
      || !(room = (objectp(poroom) ? poroom : find_object(poroom)))
      || !(door = present(pdoorcode, room))
     )
    return 0;
  return ({mixed})call_other(door, fun, data);
}

public varargs mixed SendIDP (int msg, mixed data) {
  object room, door;
  mixed proom, poroom, pdoorcode;

  if (!(proom=QueryDoorRoom()) || mutex > 0)
    return 0;
  if (proom != ENV())
    raise_error ("Proom invalid.\n");

  if (   !(poroom=QueryOtherRoom())
      || !(pdoorcode=QueryDoorCode())
      || !(room = (objectp(poroom) ? poroom : find_object(poroom)))
      || !(door = present(pdoorcode, room))
     )
    return 0;
  return ({mixed})door->HandleIDP(msg, data);
}

public varargs mixed HandleIDP (int msg, mixed data) {
  mixed proom;

  if (!(proom=QueryDoorRoom()))
    return 0;
  if (proom != ENV())
    raise_error ("Proom invalid.\n");

  mutex++;
  switch (msg) {
    case IDP_NEWSTATE:  // to give us a chance to mutex
      SetLockState(data);
      break;
    case IDP_DESTRUCT:
    case IDP_VANISH:
      proom->RemoveDoorData();
      THIS->remove();
      break;
    case IDP_SAY:
      tell_room (ENV(), data);
      break;
    case IDP_SHOW:
      if (!pointerp(data))
        show_room(ENV(), data);
      else
        show_room(ENV(), data[0], data[1], sizeof(data)<3 ? 0 : data[2]);
      break;
  }
  mutex--;
  return 0;
}

/*-------------------------------------------------------------------------*/

public int SetLockState (int state) {
  mixed proom;

  state = lock::SetLockState (state);
  SendIDP (IDP_NEWSTATE, state);
  if ((proom=QueryDoorRoom()) && proom == ENV())
    proom->SetDoorState(state, THIS);
  else
    SetDoorRoom(0);
  return state;
}

/*-------------------------------------------------------------------------*/

public void Aloha (int refresh) {
  object room, door;
  int state, check;
  mapping data;
  mixed proom, poroom, pdoorcode, pdir, target;

  if (mutex2 > 0) return;
  SetDoorRoom(proom = ENV());
  if (refresh < 0 || !proom) return;

  mutex2++;

  if (   !(poroom=QueryOtherRoom())
      || !(room = (objectp(poroom) ? poroom : find_object(poroom)))
     ) {
      // The Set...() in case it got inited before P_DOOR_CODE
    pdir = QueryDirection();
    proom->NewDoor(pdir, SetLockState(QueryLockState()));
    if (    sizeof(data = ({mapping})proom->QueryExitsData())
         && m_contains(&room, &door, &state, &check, &target, data, Pdir)
       )
      SetHideExit(state);
    mutex2--;
    return;  // Either no remote door, or its room is not loaded yet.
  }
  if (!(door = present((pdoorcode=QueryDoorCode()), room))) {
    // If this is a refresh, also refresh the remote door.
    // Else the remote door was destructed before we go into life,
    // so selfdestruct to keep consistent.
    if (refresh) {
      room->reset(); // If its not there now, it isn't.
      door = present(pdoorcode, room);
    }
    else {
      THIS->remove();
      mutex2--;
      return;
    }
  }
  if (    sizeof(data = ({mapping})proom->QueryExitsData())
       && m_contains(&room, &door, &state, &check, &target, data, Pdir)
     )
    SetHideExit(state);
  proom->NewDoor(Pdir, SetLockState(door ? ({int})door->QueryLockState()
                                         : QueryLockState()));
  mutex2--;
}

/*-------------------------------------------------------------------------*/

public varargs int CheckHidden (int check_exit) {
  return
      (check_exit ? QueryHideExit() : QueryHideDoor())
    & (QueryLockState() == LOCK_OPEN ? HIDE_OPEN : HIDE_CLOSED)
  ;
}

public int CheckActivity () {
  int val, hidden;

  val = QueryCheckDoor();
  hidden = CheckHidden(0);
  if (val & DACT_HIDE)
    return (val & DACT_CHECK) ? !hidden : hidden;
  return (val & DACT_CHECK);
}

public varargs string QueryStatusString () {
  string rc;

  if (!(rc = ({string})THIS->QueryShort()))
    return 0;

  rc += " leading "+QueryDirection()+" (";
  if (QueryLockState() == LOCK_OPEN)
    rc +="open";
  else
    rc += "closed";
  return rc+").\n";
}

/*-------------------------------------------------------------------------*/

public void create () {
  ::create();
  THIS->AddClassId(C_DOOR);
}

public varargs void notify_move (mixed dest, int method, mixed extra) {
  mixed proom;
  if (proom=QueryDoorRoom()) {
    proom->RemoveDoorData();
    SetDoorRoom(ENV()); // Sooth SendIDP() :-)
    SendIDP(IDP_VANISH);
    SetDoorRoom(0);
  }
}

public int remove () {
  mixed proom;
  if (!(proom=QueryDoorRoom())) return 1;
  proom->RemoveDoorData();
  SendIDP(IDP_DESTRUCT);
  SetDoorRoom(0);
  return 1;
}

/*************************************************************************/
