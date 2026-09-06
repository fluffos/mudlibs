/* -------------------------------------------------------------------------
 * std/room/exits.c
 *
 * Copyright (C) 1997,1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *
 * DESCRIPTION
 *  The standard exits and commands of a room.
 *  The door info is also put here for thematic coherence.
 *
 * CHANGES
 *  12/01/97 [Softbyte] target room for special exits
 *  06/27/98 [Mica] removed old wrapper-code (sprintf) inside MakeExitString
 *                  added left-right exit code
 *  06/28/98 [Mica] left-right exit code
 */

#include <config.h>
#include <properties.h>
#include <secure/wizlevels.h>
#include <rooms.h>
#include <lock.h>
#include <doors.h>
#include <moving.h>
#include <features.h>

#define TO           this_object()
#define TP           this_player()
#define NAME         ({string})TP->QueryName()
#define PREV         previous_object()

public varargs mixed * AddItem (mixed file, int refr, mapping prop, int n, mixed fun); // from /std/room/items
public varargs int DoExplore (mixed arg); // /std/room/description

//--- global variables ------------------------------------------------------

// Pexits contains the data for simple exits, Pexits2 the extra data for
// complex exits. Index is both the direction. For Pexits2, EXIT_OBJ has
// to be subtracted from all symbolic subindices.

private nosave mapping Pexits, Pexits2, Pcmds;
private nosave mapping Pdoors;
private nosave string Pdefmsg;
private nosave string *Pexitstrs;
private nosave mapping Pnowaymsgs;

//--- auxiliary exit functions ----------------------------------------------

// Remove an exit from one of the mappings
#define DELETE_EXIT(map, dir) if (!map || !sizeof(map = m_delete(map, dir))) map = 0; else

/*--------------------------------------------------------------------------*/
/* Remove all livings in the room again in this room.
 * This fixes the error, that exits/commands are added after NPC items, which
 * left the NPCs with no exits to use.
 * It's a nasty fix, the better would be to junk the whole add_action() stuff.
 */

public void RefreshItemCmds()
{
  map_objects(filter(all_inventory(this_object()), #'living /*'*/)
             , "move", this_object(), M_SILENT
             );
}

//--- querying and setting functions for the properties ---------------------

private void _merge_exits(string dir, mixed dest, mapping rc) {
  rc[dir, EXIT_DEST] = dest;
}

private void _merge_exits2(string dir, mixed obj, mixed door
                          , mixed hidden, mixed check, mixed target, mapping rc)
{
  if (rc[dir, EXIT_DEST]) {
    rc[dir, EXIT_OBJ] = obj;
    rc[dir, EXIT_DOOR] = door;
    rc[dir, EXIT_HIDDEN] = hidden;
    rc[dir, EXIT_CHECK] = check;
    rc[dir, EXIT_TARGET] = target;
  }
}

public mapping QueryExits() {
  mapping rc;
  rc = m_allocate(sizeof(Pexits),EXIT_COUNT);
  if (Pexits)
    walk_mapping(Pexits, #'_merge_exits /*'*/, &rc);
  if (Pexits2)
    walk_mapping(Pexits2, #'_merge_exits2 /*'*/, &rc);
  return rc;
}

private void _split_exits( string dir, mixed dest, mixed obj, mixed door
                         , mixed hidden, mixed check, mixed target
                         , mapping rc1, mapping rc2
                         )
{
  if (dest) {
    rc1[dir] = dest;
    if (!obj || !door || !hidden) {
      rc2[dir, EXIT_OBJ-EXIT_OBJ] = obj;
      rc2[dir, EXIT_DOOR-EXIT_OBJ] = door;
      rc2[dir, EXIT_HIDDEN-EXIT_OBJ] = hidden;
      rc2[dir, EXIT_CHECK-EXIT_OBJ] = check;
      rc2[dir, EXIT_TARGET-EXIT_OBJ] = target;
    }
  }
}

public mapping SetExits (mapping e) {
  if (!e)
    Pexits = Pexits2 = 0;
  else {
    Pexits  = m_allocate(sizeof(e), 1);
    Pexits2 = m_allocate(sizeof(e), EXIT_COUNT-1);
    walk_mapping(e, #'_split_exits /*'*/, &Pexits, &Pexits2);
    if (!sizeof(Pexits))
      Pexits = 0;
    if (!sizeof(Pexits2))
      Pexits2 = 0;
  }
  RefreshItemCmds();
  return QueryExits();
}

public mapping QueryExitsDest ()          { return Pexits || ([]); }
public mapping SetExitsDest (mapping d) {
  Pexits = sizeof(d) ? d : 0;
  RefreshItemCmds();
  return d;
}

public mapping QueryPlainExits () {
  mapping rc;
  string *dirs, dir;
  int i;

  if (!Pexits)
    return ([]);
  rc = copy(Pexits);
  dirs = m_indices(rc);
  for (i = sizeof(rc); i--; ) {
    dir = dirs[i];
    if (closurep(rc[dir]) || (Pexits2 && Pexits2[dir, EXIT_OBJ-EXIT_OBJ]))
      rc = m_delete(rc, dir);
  }
  return rc;
}

public mixed * QueryExit(string dir) {
  mixed *rc;
  if (!Pexits)
    return 0;
//  rc = allocate(EXIT_HIDDEN);
  rc = allocate(EXIT_COUNT);
  rc[EXIT_DEST] = Pexits[dir];
  if (!rc[EXIT_DEST])
    return 0;
  if (Pexits2)
    m_contains(&(rc[EXIT_OBJ]), &(rc[EXIT_DOOR]), &(rc[EXIT_HIDDEN])
                    , &(rc[EXIT_CHECK]), &(rc[EXIT_TARGET])
                    , Pexits2, dir);
  if (closurep(rc[EXIT_DEST])) {
    rc[EXIT_OBJ]  = rc[EXIT_DEST];
    rc[EXIT_DEST] = 0;
  }
  else if (rc[EXIT_OBJ]) {
    rc[EXIT_OBJ]  = ({ rc[EXIT_OBJ], rc[EXIT_DEST] });
    rc[EXIT_DEST] = 0;
  }
  return rc;
}

public mapping QueryExitsData () { return Pexits2 || ([]); }
public mapping SetExitsData (mapping d) {
  Pexits2 = sizeof(d) ? d : 0;
  RefreshItemCmds();
  return d;
}

// Returns the room file|object into which the exit into 'dir' will
// (most likely) lead to
public mixed QueryTarget(string dir)
{
mixed target;

  if (Pexits2 && member(Pexits2,dir) )
  {
    target=Pexits2[dir,EXIT_TARGET-EXIT_OBJ];
  }
  else target=0;

  if (!target)
  {
    if (!Pexits || !member(Pexits,dir) ) return 0;
    target=Pexits[dir];
  }


  if (target && closurep(target))
    return funcall(target,dir,EXIT_QUERY_ONLY);

  return target;
}

public mapping QueryDoors()                { return Pdoors; }
public mapping SetDoors(mapping d)         { return Pdoors = d; }

public mapping QueryCommands()            { return Pcmds; }
public mapping SetCommands(mixed c)     {
  if (!c || mappingp(c))
    Pcmds = c;
  else
    Pcmds = mkmapping(c[0], c[1]);
  RefreshItemCmds();
  return Pcmds;
}

public mapping QueryNowayMsgs() { return Pnowaymsgs; }
public mapping SetNowayMsgs(mapping m) { return Pnowaymsgs = m; }

public void AddNowayMsg (mixed arg, string msg)
{
  int i;
  if (msg[<1] == '\n')
    msg = msg[0..<2];
  if (-1 == member("!.?", msg[<1]))
    msg += ".";
  msg += "\n";
  if (!Pnowaymsgs)
    Pnowaymsgs = ([]);
  if (stringp(arg))
    Pnowaymsgs[arg] = msg;
  else for (i = 0; i < sizeof(arg); i++)
    Pnowaymsgs[arg[i]] = msg;
}

public void RemoveNowayMsg (mixed arg)
{
  int i;
  if (!Pnowaymsgs || !sizeof(Pnowaymsgs))
    return;
  if (stringp(arg))
    m_delete(Pnowaymsgs, arg);
  else for (i = 0; i < sizeof(arg); i++)
    m_delete(Pnowaymsgs , arg[i]);
}

public varargs string QueryNowayMsg(string verb, string arg) {
  string msg;

  if (verb && Pnowaymsgs && sizeof(Pnowaymsgs)
  && m_contains(&msg, Pnowaymsgs, verb))
    return msg;

  return Pdefmsg;
}
public string SetNowayMsg(string s)              { return Pdefmsg = s; }

//--- find the door for a direction ----------------------------------------

private void _door_to_dir ( object door
                          , string ddir
                          , int    state
                          , string dir
                          , object rc
                          )
{
  if (ddir == dir) rc = door;
}

private object door_to_dir (string dir) {
  object door;
  if (!Pdoors) return 0;
  door = 0;
  walk_mapping (Pdoors, #'_door_to_dir /*'*/, dir, &door);
  return door;
}

private void _door_to ( object door
                      , string ddir
                      , int    state
                      , string txt
                      , object rc
                      )
{
  if (!rc && (ddir == txt || ({int})door->id(txt)))
    rc = door;
}

private object door_to (string txt) {
  object door;
  if (!Pdoors) return 0;
  door = 0;
  walk_mapping (Pdoors, #'_door_to /*'*/, txt, &door);
  return door;
}

//--- adding exits and commands----------------------------------------------
#if __VERSION__ > "3.5.0"
public varargs void AddExit(string|string * dir, mixed dest, mixed obj, mixed target)
#else
public varargs void AddExit(string * dir, mixed dest, mixed obj, mixed target)
#endif
{
  mixed door;
  string tdir;
  int i;

  if (stringp(dest) || objectp(dest))
  {
    if (!obj && stringp(dest))
      dest = resolve_file(dest);
    if (stringp(obj))
      obj = resolve_file(obj);
    else if (objectp(obj) && obj == TO)
    {
      dest = symbol_function(dest, TO);
      obj = 0;
    }
  }
  else if (closurep(dest))
  {
    target=obj;   // target room is 3. argument in case of closure
    obj = 0;
  }
  if ( target  && stringp(target)) target=resolve_file(target);
  if (!pointerp(dir))
    dir = ({ dir });

  for (i = sizeof(dir); i-- > 0; ) {
    DELETE_EXIT(Pexits, dir[i]);
    DELETE_EXIT(Pexits2, dir[i]);
  }

  for (i = sizeof(dir); i-- > 0; ) {
    tdir = dir[i];
    if (stringp(dest) || objectp(dest))
      door = door_to_dir(tdir);
    else if (closurep(dest))
      door = door_to_dir(tdir);
    else
      continue;

    if (!Pexits)
      Pexits = ([ tdir:dest ]);
    else
      Pexits[tdir] = dest;

    if (obj || door || target)
    {
      if (!Pexits2)
        Pexits2 = ([ tdir:obj;door;0;0;target ]);
      else {
        Pexits2[tdir, EXIT_OBJ-EXIT_OBJ]  = obj;
        Pexits2[tdir, EXIT_DOOR-EXIT_OBJ] = door;
        Pexits2[tdir, EXIT_HIDDEN-EXIT_OBJ] = 0;
        Pexits2[tdir, EXIT_TARGET-EXIT_OBJ] = target;
      }
    }
  }
  RefreshItemCmds();
}

#if __VERSION__ > "3.5.0"
public int HideExit (string|mixed * dirs, int new) {
#else
public int HideExit (mixed * dirs, int new) {
#endif
  int old, i;
  string dir;
  mixed dest;
  mixed obj;
  mixed door;
  mixed check;
  mixed target;

  if (!Pexits)
    return 0;

  if (!pointerp(dirs))
    dirs = ({ dirs });

  for (i = sizeof(dirs); i--; ) {
    dir = dirs[i];

    // Don't hide non-existant exits.
    if (!m_contains(&dest, Pexits, dir))
      continue;

    // If there's no special data, handling is easy.
    if (!Pexits2 ) {
      if (new)
        Pexits2 = ([ dir:0;0;new;0;0 ]);
      continue;
    }

    // Get the old entries.
    // If there are none, and the exit is unhidden: done.
    if (!m_contains(&obj, &door, &old, &check, &target, Pexits2, dir) && !new)
      continue;

    // If there is a door, update its P_HIDEEXIT
    if (door)
      door->SetHideExit(new);

    // Delete the special data if possible, else set the new value.
    if (!new && !obj && !door && !check && !target)
      DELETE_EXIT(Pexits2, dir);
    else
      Pexits2[dir, EXIT_HIDDEN-EXIT_OBJ] = new;
  }

  return old;
}

public int HideDoor (string dir, int new) {
  int old;
  mixed obj;
  mixed door;
  mixed check;
  mixed target;

  // Don't hide non-existant doors.
  if (    !Pexits2
       || !m_contains(&obj, &door, &old, &check, &target, Pexits2, dir)
       || !door
     )
    return 0;

  old = ({int})door->QueryHideDoor();
  door->SetHideDoor(new);
  return old;
}

#if __VERSION__ > "3.5.0"
public int CheckExit (string *|string dirs, int new) {
#else
public int CheckExit (mixed * dirs, int new) {
#endif
  int old, i;
  string dir;
  mixed dest;
  mixed obj;
  mixed door;
  mixed hidden;
  mixed target;

  if (!Pexits)
    return 0;

  if (!pointerp(dirs))
    dirs = ({ dirs });

  for (i = sizeof(dirs); i--; ) {
    dir = dirs[i];

    // Don't modify non-existant exits.
    if (!m_contains(&dest, Pexits, dir))
      continue;

    // If there's no special data, handling is easy.
    if (!Pexits2 ) {
      if (new)
        Pexits2 = ([ dir:0;0;0;new;0 ]);
      continue;
    }

    // Get the old entries.
    // If there are none, and the exit is unhidden: done.
    if (!m_contains(&obj, &door, &hidden, &old, &target, Pexits2, dir) && !new)
      continue;

    // Delete the special data if possible, else set the new value.
    if (!new && !obj && !door)
      DELETE_EXIT(Pexits2, dir);
    else
      Pexits2[dir, EXIT_CHECK-EXIT_OBJ] = new;
  }

  return old;
}

public int CheckDoor (string dir, int new) {
  int old;
  mixed obj;
  mixed door;
  mixed hidden;
  mixed target;

  // Don't modify non-existant doors.
  if (    !Pexits2
       || !m_contains(&obj, &door, &hidden, &old, &target, Pexits2, dir)
       || !door
     )
    return 0;

  old = ({int})door->QueryCheckDoor();
  door->SetCheckDoor(new);
  return old;
}

public void RemoveExit(string * dir) {
  int i;

  if (!pointerp(dir)) {
    DELETE_EXIT(Pexits, dir);
    DELETE_EXIT(Pexits2, dir);
  }
  else
    for (i = sizeof(dir); i-- > 0; ) {
      DELETE_EXIT(Pexits, dir[i]);
      DELETE_EXIT(Pexits2, dir[i]);
    }
}

public void AddRoomCmd(mixed cmd, mixed func) {
  int s;

  if(stringp(cmd)) {
    if(Pcmds) {
      if(func) Pcmds[cmd] = func;
      else if(!sizeof(Pcmds = m_delete(Pcmds, cmd)))
        Pcmds = 0;
    } else if(func) Pcmds = ([ cmd : func ]);
  } else if(s = sizeof(cmd)) {
    if(Pcmds) {
      if(func) while(s--) Pcmds[cmd[s]] = func;
      else {
        while(s--) Pcmds = m_delete(Pcmds, cmd[s]);
        if(!sizeof(Pcmds)) Pcmds = 0;
      }
    } else if(func) {
      Pcmds = ([ ]);
      while(s--) Pcmds[cmd[s]] = func;
    }
  }
  RefreshItemCmds();
}

public void RemoveRoomCmd(mixed cmd, mixed func) {
  int s;

  if (!Pcmds)
    return;
  if (stringp(cmd))
    Pcmds = m_delete(Pcmds, cmd);
  else if(s = sizeof(cmd))
    while(s--)
      Pcmds = m_delete(Pcmds, cmd[s]);
  if (!sizeof(Pcmds))
    Pcmds = 0;
  RefreshItemCmds();
}

//--- door information handling ---------------------------------------------

public varargs void SetDoorData (string dir, int state, object door) {
  if (!door && !(door = PREV))
    return;

  if (!Pdoors)
    Pdoors = ([ door: dir; state ]);
  else {
    // Remove the former doorobject from the Pexits array
    if (member(m_values(Pdoors), door) != -1 && Pexits)
      Pexits[Pdoors[door, DOOR_DIR], EXIT_DOOR] = 0;

    Pdoors[door, DOOR_DIR] = dir;
    Pdoors[door, DOOR_STATE] = state;
  }
  if (!Pexits2)
    Pexits2 = ([ dir: 0;door;0;0;0 ]);
  else
    Pexits2[dir, EXIT_DOOR-EXIT_OBJ] = door;
}

public varargs void SetDoorState (int state, object door) {
  if (!door && !(door = PREV))
    return;

  if (!Pdoors)
    return;

  Pdoors[door, DOOR_STATE] = state;
}

// Allow the room to differentiate between adding new doors
// and the state change of known doors.
public varargs void NewDoor (string dir, int state, object door) {
  SetDoorData (dir, state, door || PREV);
}

public varargs void RemoveDoorData (object door) {
  if (!Pdoors || (!door && !(door = PREV))) return;
  if (member(m_values(Pdoors), door) && Pexits2)
    Pexits2[Pdoors[door,DOOR_DIR],EXIT_DOOR-EXIT_OBJ] = 0;
  if (!sizeof(Pdoors = m_delete (Pdoors, door)))
    Pdoors = 0;
}

// Search for an door object, or a door into the given direction
public mixed * DoorInfo (mixed door) {
  if (stringp(door)) door = door_to(door);
  if (!Pdoors || !door || !objectp(door)) return 0;
  return ({ Pdoors[door,DOOR_DIR], Pdoors[door,DOOR_STATE], door });
}

public varargs mixed AddDoor ( string dir, mixed dest
                      , mixed doorid, mixed doorlong
                      , mixed * keyid, int state
                      )
{
  string   doorobj;
  mixed    keycode;
  string   doorshort, *doorids, *doorads;
  object  *door;

  AddExit(({ dir }), dest);
  dest = Pexits[dir];

  if (mappingp(doorid)) {
    mapping props;
    mixed   ids;

    props = doorid;
    doorobj = to_string(doorlong || "/obj/door");
    ids = (  (props[P_IDS] || ({ }))
           + (({string *})doorobj->QueryIds() || ({}))
           + ({ props[P_DOORCODE] })
          ) - ({ 0, "" });
    ;
    if (sizeof(ids))
      props[P_IDS] = ids;
    if (!m_contains(&ids, props, P_OTHERROOM))
      props[P_OTHERROOM] = stringp(dest) ? dest : 0;
    props[P_DIRECTION] = dir;
    // The doorobject itself calls NewDoor().
    return AddItem(doorobj, REFRESH_REMOVE, props)[0];
  }

  // Compatibility for stupid doors.

  if (!keyid) {
    keycode = 0;
    keyid = 0;
  }
  else if (stringp(keyid))
    keyid = ({ keyid });
  else {
    keycode = keyid[0];
    keyid = keyid[1..];
  }
  if (member("aeiou", doorid[0]) != -1)
    doorshort = "an "+doorid;
  else
    doorshort = "a "+doorid;

  doorids = explode(doorid, " ") - ({ "" });
  doorads = doorids[0..<2] + ({ dir });
  doorids = doorids[<1..<1] - ({ "door" });

  door = AddItem( "/obj/door", REFRESH_REMOVE
		 , ([
		   P_SHORT: doorshort,
		   P_LONG: doorlong,
		   P_KEYIDS: keyid,
		   P_KEYCODE: keycode,
		   P_LOCKSTATE: state,
		   P_DIRECTION: dir,
		   P_DOORCODE: doorid,
		   P_OTHERROOM: stringp(dest) ? dest : 0,
                   P_ADS: doorads,
                   P_IDS: doorids+({"door"}),
		   P_CHECKOBJ: TO
	           ])
                );
  // The doorobject itself calls NewDoor().
  return door[0];
}

public int SetDoor (string doorid, int new)
{
  mixed doorinfo;
  doorinfo = DoorInfo(doorid);
  if (doorinfo)
    return ({int})doorinfo[DOOR_OBJECT]->SetLockState(new);
  return -1;
}

//--- description handling of exits and doors -------------------------------

public string * QueryExitStrings () { return Pexitstrs; }
public string * SetExitStrings (string * tokens) {
  return Pexitstrs = tokens;
}

#define NUMBER(x) ({"two", "three", "four", "five", "six",\
                    "seven", "eight", "nine", "ten"})[x-2]

public string map_brief_exit (string exit) {
  switch(exit) {
  case "north":
  case "south":
  case "west" :
  case "east" :
  case "up"   :
  case "down" :
    return exit[0..0];
  case "southwest":
    return "sw";
  case "northwest":
    return "nw";
  case "southeast":
    return "se";
  case "northeast":
    return "ne";
  default:
    return exit;
  }
  return exit;
}

public varargs string MakeExitString (int brief, string * dirs, string kind) {
  int s, i;
  string str, *tok, *sort;

  if (kind && kind != "")
    kind += " ";

  // Sort of sort the exits.
  tok = dirs;
  dirs = ({});
  sort = ({ "north", "northeast", "east", "southeast", "south", "southwest"
          , "west", "northwest", "up", "down", "enter", "leave" });
  for (i = 0; i < sizeof(sort); i++)
  {
    s = member(tok, sort[i]);
    if (s >= 0)
    {
      dirs += sort[i..i];
      tok[s] = 0;
    }
  }
  dirs += (tok - ({ 0 }));

  if (brief) {
    dirs = map(dirs, #'map_brief_exit /*'*/);
    return implode(dirs, ",");
  }

  tok = QueryExitStrings() || ({});
  if (sizeof(tok) < 4)
    tok += ({"There is", "exit", "There are", "exits"})[sizeof(tok)..];

  switch(s = sizeof(dirs)) {
    case 0: return tok[2]+" no "+kind+tok[3]+".\n";
    case 1: return tok[0]+" one "+kind+tok[1]+": " + dirs[0] + ".\n";
    case 2..10:
      str = tok[2]+" "+NUMBER(s)+" "+kind+tok[3]+": ";
      break;
    default:
      str = tok[2]+" many "+kind+tok[3]+": ";
  }
  return str+implode(dirs[0..<2], ", ")+" and "+dirs[<1]+"."+"\n";
}

public varargs string MakeDoorString(int brief, object * doors, string kind) {
  string str, *strs;
  int cnt;

  if (kind && kind != "")
    kind += " ";

  // Obvious doors
  strs = map_objects(doors, "QueryStatusString") - ({ 0, "" });
  cnt = sizeof(strs);
  switch(cnt) {
    case 0:
      if (!brief)
        str =  "There are no "+kind+"doors.\n";
      else
        str = "";
      break;
    case 1:
      str = "There is "+kind;
      break;
    case 2..10:
      str = "There are " + NUMBER(cnt) + " "+kind+"doors:\n";
      break;
    default:
      str = "There are many "+kind+"doors:\n";
  }
  str += (sizeof(strs) > 1 ? "  " : "")+implode(strs, "  ");

  return str;
}

public mixed * ExitList () {
  string str, *dirs, *hidden, *mx;
  object door, *doors;
  int s;

  mx = m_indices(Pexits2 || ([]));
  dirs = m_indices(Pexits || ([]));
  dirs = dirs - mx;
  if (sizeof (Pdoors))
    doors = m_indices(Pdoors);
  hidden = ({ });
  for (s = sizeof(Pexits2); s--;) {
    str = mx[s];
    if ((    doors
          && (door = Pexits2[str, EXIT_DOOR-EXIT_OBJ])
          && member(doors, door) != -1
          && (    ({int})door->CheckHidden(1)
               || (({int})door->QueryLockState()) != LOCK_OPEN
             )
        )
       )
      if (({int})door->QueryLockState() == LOCK_OPEN)
        hidden += ({ str });
      else;
    else if (Pexits2[str, EXIT_HIDDEN-EXIT_OBJ] & HIDE_OPEN)
      hidden += ({ str });
    else
      dirs += ({ str });
  }
  return ({ dirs, hidden });
}

public mixed * DoorList() {
  string str, *strs;
  object * hidden, * doors, door;
  int s;

  hidden = ({ });
  if (sizeof (Pdoors)) {
    doors = m_indices(Pdoors);
    if (sizeof(Pexits2)) {
      strs = m_indices(Pexits2);
      for (s = sizeof(strs); s-- > 0; ) {
        str = strs[s];
        door = Pexits2[str, EXIT_DOOR-EXIT_OBJ];
        if (   door
            && member(doors, door) != -1
            && ({int})door->CheckHidden(0)
           )
          hidden += ({ door });
      }
      doors -= hidden;
    }
  }
  else
    doors = ({ });
  return ({ doors, hidden });
}

public varargs string Exits (int brief, object pl) {
  string str;
  mixed *exits;

  if (!pl)
    pl = TP;

  exits = ExitList();

  if ((   (IS_WIZARD(pl) && !({int})pl->Query(P_NOWIZ))
       || LSTATE_GHOST == ({int})pl->Query(P_LSTATE))
  && sizeof(exits[1]))
  {
    str = MakeExitString(brief, exits[1], "hidden");
    if (brief)
      str = "]["+str;
  }
  else
    str = "";
  return MakeExitString(brief, exits[0], "")+str;
}

public varargs string Doors(int verbose, object pl) {
  mixed * doors;
  string str;

  if (!pl)
    pl = TP;

  doors = DoorList();

  // Obvious doors
  str = MakeDoorString(!verbose, doors[0], "");

  // Hidden doors
  if ((   (IS_WIZARD(pl) && !({int})pl->Query(P_NOWIZ))
       || LSTATE_GHOST == ({int})pl->Query(P_LSTATE))
  && sizeof(doors[1]))
  {
    str += MakeDoorString(!verbose, doors[1], "hidden");
  }
  return str;
}

// Compatibility

public string GetExits()      { return Exits(0); }
public string GetBriefExits() { return "["+Exits(1)+"]"; }
public string GetDoors()      { return Doors(); }
public string GetDoorDesc (string doorid) {
  object door;
  door = door_to(doorid);
  return door ? ({string})door->Long() : 0;
}

//--- add_actions() for the commands ----------------------------------------

public void init() {
  string *cmd, *def;
  mixed *func;
  int s;

  DoExplore(1);
  if (Pexits) {
    // we add all possible directions as commands here,
    // and we add all possible non-compass movements
#ifdef FEATURES_LREXITS
    def = COMPASS_DIRECTIONS + LR_DIRECTIONS + OTHER_DIRECTIONS;
#else
    def = COMPASS_DIRECTIONS + OTHER_DIRECTIONS;
#endif
    cmd = m_indices(Pexits || ([]));
    cmd -= def;
    cmd += def;
    for(s = sizeof(cmd); s--;)
      add_action("exitfunc", cmd[s]);
  }
  if(Pcmds)
    for(s = sizeof(cmd = m_indices(Pcmds)), func = m_values(Pcmds); s--;)
      if (stringp(func[s]))
        add_action(func[s], cmd[s]);
      else
        add_action("closurecmd", cmd[s]);
}

//--- the functions behind the add_actions() --------------------------------

public int CheckAction(string action, string verb, string arg, int method)
{
  return (action != "block" || (LSTATE_GHOST != ({int})TP->Query(P_LSTATE)));
}

#ifdef FEATURES_LREXITS
public int UseExit(string verb2, string arg, int method) {
#else
public int UseExit(string verb, string arg, int method) {
#endif
  mixed dest, obj;
  int   chk, hide, rval;
#ifdef FEATURES_LREXITS
  int dpos, d2pos, d3pos;
  string verb, dir;
#endif

#ifdef FEATURES_LREXITS
  if ( ( dpos = member( LR_DIRECTIONS, verb2 ) ) != -1 ) {
    // need to translate to compass direction, this bases on a ringbuffer
    // of compass-directions

    // player does not look anywhere .)
    if ( ! stringp( dir = ({string})(TP||PREV)->Query( P_LOOKINGTO ) ) ) {
      dir = "north"; // TODO: this has to be set during logon
      (TP||PREV)->Set( P_LOOKINGTO, dir );
    }

    if ( ( d2pos = member( COMPASS_DIRECTIONS, dir ) ) == -1 ) {
      // TODO: PANIC!
      dir = "north"; // TODO: this has to be set during logon
      (TP||PREV)->Set( P_LOOKINGTO, dir );
      d2pos = 0;
    }

   d3pos = (dpos+d2pos)%sizeof( COMPASS_DIRECTIONS );

   verb = COMPASS_DIRECTIONS[d3pos];
  } else {
    // no need to translate
    verb = verb2;
  }
#endif

  notify_fail(QueryNowayMsg(verb, arg) || "No way.\n");

  if ( !Pexits || !(dest = Pexits[verb,EXIT_DEST]))
    return 0;

  if (Pexits2)
  {
    if (obj = Pexits2[verb, EXIT_DOOR-EXIT_OBJ])
      hide = (({int})obj->QueryHideExit(verb)) & HIDE_OPEN;
    else
      hide = Pexits2[verb, EXIT_HIDDEN-EXIT_OBJ];

    chk = Pexits2[verb, EXIT_CHECK-EXIT_OBJ];

    if (chk & DACT_HIDE)
      chk = (chk & DACT_CHECK) ? !hide : hide;
    else
      chk = (chk & DACT_CHECK);

    if (chk && !CheckAction("exit", verb, arg, method))
      return 0;
  }
  if (closurep(dest)) {
    rval = funcall(dest, arg);

#ifdef FEATURES_LREXITS
    if ( rval ) {
       // adjust direction player is looking now, in fact that is the direction
       // the player really used, but only for compass directions
       if ( member( COMPASS_DIRECTIONS, verb ) != -1 ) {
         (TP||PREV)->Set( P_LOOKINGTO, verb );
       }
    }
#endif

    return rval;
  }

  if (Pexits2 && (obj = Pexits2[verb, EXIT_OBJ-EXIT_OBJ])) {
    rval = closurep(dest) ? funcall(dest, arg)
                          : ({int})call_other (obj, dest, arg);

#ifdef FEATURES_LREXITS
    if ( rval ) {
       // adjust direction player is looking now, in fact that is the direction
       // the player really used, but only for compass directions
       if ( member( COMPASS_DIRECTIONS, verb ) != -1 ) {
         (TP||PREV)->Set( P_LOOKINGTO, verb );
       }
    }
#endif

    return rval;
  }

  if (arg || environment(TP||PREV) != TO)
    return 0;

  switch (({int})(TP||PREV)->move(dest, method, verb))
  {
   case ME_OK:
   case ME_NO_MOVE:
   case ME_DESTRUCTED_SELF:
#ifdef FEATURES_LREXITS
       // adjust direction player is looking now, in fact that is the direction
       // the player really used, but only for compass directions
       if ( member( COMPASS_DIRECTIONS, verb ) != -1 ) {
         (TP||PREV)->Set( P_LOOKINGTO, verb );
       }
#endif
     break;
   default:
   case ME_NO_LEAVE:
     tell_object((TP||PREV), "You can't leave.\n");
     break;
   case ME_NO_ENTER:
     tell_object((TP||PREV), "You can't go there.\n");
     break;
   case ME_TOO_HEAVY:
     tell_object((TP||PREV), "You don't fit in.\n");
     break;
   case ME_CAUGHT_ERR:
     tell_object((TP||PREV), "A wrongness in the fabric of space blocks your way.\n");
     break;
  }
  return 1;
}

public int exitfunc(string arg) { return UseExit(query_verb(), arg, M_GO); }
public int closurecmd(string arg) { return funcall(Pcmds[query_verb()], arg); }
