/*  Room 4  */

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
"    You remain on the main pathway heading in a general southwestern\n"+ 
"    direction.  It seem that the terrain is becoming more rocky as the\n"+ 
"    strange pathway winds it way down amongst the formations from the \n"+
"    sea-bed.  The direction of the path is forced to head south when\n"+ 
"    faced with a great jutting wall of stone to your left.\n";

	dest_dir = ({
      WATER + "rm2", "northeast",
      WATER + "rm8", "south",
	});

	items = ({
  "path",
"It is strangely constructed from a netword of sea-weed that is capable "+
"of sustaining your weight quite easily",
  "sea-bed",
"There is a lot of eroded rock in great formations across the bed of this "+
"strange place",
  "wall",
"From what you can see of this wall, it is similar to the cliff you saw "+
"when you first entered this Plane.  It is very tall, and stretches up to "+
"the water surface above you",
  "stone",
"From what you can see of this wall of stone, it is similar to the cliff "+
"you saw when you first entered this Plane.  It is very tall, and stretches "+
"up to the water surface above you",
	});

  }
  float_down();
  ::reset();
}

init() {
  ::init();
  if(!nodanger) extinguish();
  add_action("take_breath", "take");
  AA("_climb",  "climb");
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

int _climb(string str)
{
  if (str == "cliff")
  {
    write("You only make it up a few feet before you fall back down to\n"+
	  "the sea-weed pathway.\n");
      say(TPN+" tries rather stupidly to climb the cliff...\n");

    HIT(12);

    return 1;
  }
  else
  {
    NFAIL("Climb where?\n");
    return 0;
  }
}
