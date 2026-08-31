/*  Room 2  */

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

    set_light(1);
    short_desc = "On the Sea-Weed Walkway";
    long_desc = 
"    You frantically paddle your way along the sea-weed pathway.\n"+
"    Here, the water seems to be less turbulent than before, and you\n"+
"    can see specific pathways open to you now.  There is a fork in \n"+
"    the network of weed that will take you to the southeast, and the \n"+
"    other continues on to the southwest.  In both directions, you cannot\n"+ 
"    see much further, as the path winds in between great upthrusts of\n"+ 
"    rock from the sea-bed.\n";

	dest_dir = ({
      WATER + "rm1", "northeast",
      WATER + "rm5", "southeast",
      WATER + "rm4", "southwest",
	});

	items = ({
  "path",
"It is strangely constructed from a netword of sea-weed that is capable "+
"of sustaining your weight quite easily",
  "sea-bed",
"There is a lot of eroded rock in great formations across the bed of this "+
"strange place",
  "rock",
"Great formations of rock that must have been created by some seismic "+
"activitiy in the past",
	});

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
