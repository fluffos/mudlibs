/* Advent - Chasm Room -- Mateese, 24-Aug-96
 * 
 * Standard room for the North-East and South-West side of the chasm.
 * It contains the extra code for the Rickety Bridge management.
 * Both create() and setup() need to be called.
 * (Noticed? This is a replica of i/fissure :-)
 * 
 * Properties:
 *   "RicketyBidge": set when the bridge exists.
 *   "ChasmRoom":  set to the filename of the other fissure room.
 *   "ChasmExit":  direction for the Rickety Bridge.
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include <doors.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

#define P_BRIDGE  "RicketyBridge"
#define P_CROOM   "ChasmRoom"
#define P_CEXIT   "ChasmExit"

/*-----------------------------------------------------------------------*/
public string BridgeExtraLong ()

{
  if (Query(P_BRIDGE))
  {
    string msg;
    msg = 
"A rickety bridge extends across the chasm, vanishing into the mist.\n"
"A sign posted on the bridge reads, 'Stop! Pay troll!'\n";
    if (!present(ADV_TROLL, this_object()))
      msg += "The troll is nowhere to be seen.\n";
    return msg;
  }
  return 
"The wreckage of the troll bridge (and a dead bear) can be seen at "
"the bottom of the chasm.\n";
}

/*-----------------------------------------------------------------------*/
public varargs void create(int noreplace)
{
  ::create(noreplace);

  SetExtraEntry("ricketybridge", P_INT_LONG, #'BridgeExtraLong);
  Set(P_BRIDGE, 1);
  AddNowayMsg("down", "The chasm is too terrifying.\n");

  AddOrigDetail( ({ "bridge", "rickety bridge", "wreckage" }), #'BridgeExtraLong);
  AddOrigDetail( ({" fissure", "wide" })
	   , "The chasm looks far too wide to jump.\n");
  AddOrigDetail(({ "mist", "wisps", "white mist", "white wisps" }),
"Mist is a white vapor, usually water, seen from time to time in caverns. "
"It can be found anywhere but is frequently a sign of a deep pit leading "
"down to water.\n"
	   );

 AddRoomCmd("jump", "fjump");
}

/*-----------------------------------------------------------------------*/
public void setup (string cexit, string croom)

/* Setup P_CEXIT and P_CROOM and initialise the bridge.
 */

{
  object room;
  int    bridge;
    
  Set(P_CEXIT, cexit);
  Set(P_CROOM, croom);
  AddExit(cexit, croom);
  CheckExit(cexit, DACT_CHECK);
  room = find_object(croom);
  if (room)
    bridge = room->Query(P_BRIDGE);
  else
    bridge = 1;
    
  Set(P_BRIDGE, bridge);
  if (!bridge)
    HideExit(cexit, HIDE_ALWAYS);
}

/*-----------------------------------------------------------------------*/
public int CheckAction (string action, string verb, string arg, int method)

/* We interfere with the movement if the player tries to go over the
 * non-existing bridge or if the troll hasn't been paid.
 */
{
  if ("exit" == action && Query(P_CEXIT) == verb && !Query(P_BRIDGE))
  {
    notify_fail("The chasm is too wide.\n");
    return 0;
  }
  if ("exit" == action && Query(P_CEXIT) == verb
   && present(ADV_TROLL, this_object())
   && !QueryFlag(F_TROLL, this_player())
     )
  {
    notify_fail("The troll refuses to let you cross.\n");
    return 0;
  }
  return ::CheckAction(action, verb, arg, method);
}

/*-----------------------------------------------------------------------*/
public void ToggleBridge()

/* Toggle the state of the bridge. The other room is not updated!
 */

{
  if (Query(P_BRIDGE))
  {
    Set(P_BRIDGE, 0);
    HideExit(Query(P_CEXIT), HIDE_ALWAYS);
    show_room(this_object(), 
	      "The rickety bridge collapses and falls into the chasm.\n"
	     );
  }
  else
  {
    Set(P_BRIDGE, 1);
    HideExit(Query(P_CEXIT), HIDE_NOT);
    show_room(this_object(), "A rickety bridge extends across the chasm.\n");
  }
}

/*-----------------------------------------------------------------------*/
public void reset()
{
  object room;
    
  ::reset();
  if (!Query(P_BRIDGE))
  {
    ToggleBridge();
    room = find_object(Query(P_CROOM));
    if (room)
      room->ToggleBridge();
  }
}

/*-----------------------------------------------------------------------*/
public int BearOnBridge(object from)

/* This function is called when the bear enters the bridge.
 * We simply let the bridge cumble.
 */

{
  object room;

  if (!Query(P_BRIDGE) || to_string(from) != Query(P_CROOM))
    return 0;
  show_room(this_object(),
"The bridge buckles underneath the weight of the bear, which was still "
"following. It nearly reached the other side, but as the bridge starts "
"breaking apart, it stumbles back and falls into the chasm.\n"
	   );
  ToggleBridge();
  room = find_object(Query(P_CROOM));
  if (room)
  {
    show_room(room,
"The bridge buckles underneath the weight of the bear, which was still "
"following. It nearly reached the other side, but as the bridge starts "
"breaking apart, it stumbles back and falls into the chasm.\n"
             );
    room->ToggleBridge();
  }
  return 1;
}

/*-----------------------------------------------------------------------*/
public int fjump (string arg)

/* Don't jump (the original game killed you!).
 */
{
  if (!arg || -1 == strstr(arg, "chasm"))
    return 0;
  if (!Query(P_BRIDGE))
    write(
"You speed towards the chasm, but stop in the last second.\n"
"The chasm is too terrifying.\n"
	 );
  else
    write("You better use the bridge instead of jumping.\n");
  return 1;
}

/*************************************************************************/
