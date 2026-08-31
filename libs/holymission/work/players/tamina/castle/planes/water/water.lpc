/*
 *   This is the basis of the rooms in the Elemental Plane of Water.
 *   It is coded with the help of Cashimor's inherits and includes
 *   for alien environments, which are inherently harmful to 
 *   players.  Here, the water on the Plane of course is so that
 *   without the protection of the enchanted Pipe (found in Camelot)
 *   the player is hit because he cannot breathe, frequency of damage
 *   being dependant on the value of the timer.
 */

inherit "room/room";

#include "/players/tamina/defs.h"
#include "/players/tamina/castle/planes/water/float.h"
#include "/players/tamina/castle/planes/water/ext.h" 

reset(arg) 
{
  if (!arg) 
  {

    timer  = 4;
    damage = 25;
    survivor = "pipe";
    envname  = "water";
    saymsg   = "seems to be unable to breathe.";
    wrtmsg   = "You can't breathe!";
    property = ({"in_water", "no_teleport" });

  /*
   *  In here you can put the normal configurations of "room/room"
   *  such as :
   *  set_light();
   *  short_desc;
   *  long_desc;
   *    etc...
   */
    set_light(1);
    short_desc = "On the Sea-Weed Walkway";
    long_desc = 
"    You are walking along the walkway of sea-weed.\n";

  }
  float_down();
  ::reset();
}

init() {
  ::init();
  if(!nodanger) extinguish();
  add_action("take_breath", "take");
}

take_breath(str) 
{
 object air;

  if (!str) 
  {
    notify_fail("Take what?\n");
    return 0;
  }
  if ((str != "breath") && (str != "breath of air") && (str != "a breath")) 
  {
    notify_fail("Take what?\n");
    return 0;
  }
  if (present("breath_of_air", TP)) 
  {
    write("You already have your lungs full!\n");
    return 1;
  }
  if (nodanger)  
  {
    write("That would be very stupid!\n");
    return 1;
  }
  air = CLO (WATER + "breath");
  transfer (air, TP);
  write("You take a big breath of air.\n");
  say(TPN+" gulps in a big breath of air.\n");
  return 1;
}
