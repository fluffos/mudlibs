/* Advent - Fissure Room -- Mateese, 04-Aug-96
 * 
 * Standard room for the East and West side of the fissure.
 * It contains the extra code for the Crystal Bridge management.
 * Both create() and setup() need to be called.
 * 
 * Properties:
 *   "CrystalBridge": set when the bridge exists.
 *   "FissureRoom":  set to the filename of the other fissure room.
 *   "FissureExit":  direction for the Crystal Bridge.
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include <doors.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

#define P_BRIDGE  "CrystalBridge"
#define P_FROOM   "FissureRoom"
#define P_FEXIT   "FissureExit"

/*-----------------------------------------------------------------------*/
public string BridgeExtraLong ()

{
  if (Query(P_BRIDGE))
    return "A crystal bridge spans the fissure.\n";
  return "";
}

public string DetailBridge()
{
  if (Query(P_BRIDGE))
    return "It spans the fissure, thereby providing you a way across.\n";
  return "You see no bridge here.\n";
}

/*-----------------------------------------------------------------------*/
public varargs void create(int noreplace)
{
  ::create(noreplace);

  SetExtraEntry("fissurebridge", P_INT_LONG, #'BridgeExtraLong);
  Set(P_BRIDGE, 0);
  AddNowayMsg("down", "The fissure is too terrifying.\n");

  AddOrigDetail( ({ "bridge", "crystal bridge" }), #'DetailBridge);
  AddOrigDetail( ({" fissure", "wide" })
	   , "The fissure looks far too wide to jump.\n");
  AddOrigDetail(({ "mist", "wisps", "white mist", "white wisps" }),
"Mist is a white vapor, usually water, seen from time to time in caverns. "
"It can be found anywhere but is frequently a sign of a deep pit leading "
"down to water.\n"
	   );

 AddRoomCmd("jump", "fjump");
}

/*-----------------------------------------------------------------------*/
public void setup (string fexit, string froom)

/* Setup P_FEXIT and P_FROOM and initialise the bridge.
 */

{
  object room;
  int    bridge;
    
  Set(P_FEXIT, fexit);
  Set(P_FROOM, froom);
  AddExit(fexit, froom);
  CheckExit(fexit, DACT_CHECK);
  room = find_object(froom);
  if (room)
    bridge = room->Query(P_BRIDGE);
  else
    bridge = 0;
    
  Set(P_BRIDGE, bridge);
  if (!bridge)
    HideExit(fexit, HIDE_ALWAYS);
}

/*-----------------------------------------------------------------------*/
public int CheckAction (string action, string verb, string arg, int method)

/* We interfere with the movement if the player tries to go over the
 * non-existing bridge.
 */
{
  if ("exit" == action && Query(P_FEXIT) == verb && !Query(P_BRIDGE))
  {
    notify_fail("The fissure is too wide.\n");
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
    HideExit(Query(P_FEXIT), HIDE_ALWAYS);
    show_room(this_object(), "The crystal bridge flickers and disappears.\n");
  }
  else
  {
    Set(P_BRIDGE, 1);
    HideExit(Query(P_FEXIT), HIDE_NOT);
    show_room(this_object(), "A crystal bridge now spans the fissure.\n");
  }
}

/*-----------------------------------------------------------------------*/
public void reset()
{
  object room;
    
  ::reset();
  if (Query(P_BRIDGE))
  {
    ToggleBridge();
    room = find_object(Query(P_FROOM));
    if (room)
      room->ToggleBridge();
  }
}

/*-----------------------------------------------------------------------*/
public int WaveRod()

/* This function is called when the black rod is waved. We simply turn
 * the bridge on and off.
 */

{
  object room;

  ToggleBridge();
  room = find_object(Query(P_FROOM));
  if (room)
    room->ToggleBridge();
  return 1;
}

/*-----------------------------------------------------------------------*/
public int fjump (string arg)

/* Don't jump (the original game killed you!).
 */
{
  if (!arg || -1 == strstr(arg, "fissure"))
    return 0;
  if (!Query(P_BRIDGE))
    write(
"You speed towards the fissure, but stop in the last second.\n"
"The fissure is too terrifying.\n"
	 );
  else
    write("You better use the bridge instead of jumping.\n");
  return 1;
}

/*************************************************************************/
