inherit "players/tamina/castle/planes/hostiles/water";

#include "/players/tamina/defs.h"
#include "/players/tamina/castle/planes/water/float.h"
#include "/players/tamina/castle/planes/water/ext.h" 

reset(arg) 
{
  if (!arg) 
  {

    timer  = 6;
    damage = 19;
    survivor = "allows_breathing";
    envname  = "water";
    saymsg   = "seems to be unable to breathe.";
    wrtmsg   = "You can't breathe!";
    property = ({"in_water", "no_teleport" });

    set_light(0);
    short_desc = "In the Moat";
    long_desc = 
"You are under-water in the moat of the castle, Camelot.\n"+
"By the looks of the area now surrounding you, it would be reasonable\n"+
"to think that some large animal made its lair here.  There are clear\n"+
"signs of movement coming from a hole in what would be the bank to your\n"+
"right.\n";
    no_obvious_msg = "";
  
    items = ({
  "weeds",
"Horrible looking green weeds",
  "bottom",
"This is full of mud, and muck, which is making visibility very limited",
    });

  }
  float_down();
  ::reset();
}

init() 
{
  ::init();
  if(!nodanger) extinguish();
  AA("take_breath", "take");
  AA("swim",        "swim");
  AA("swim",        "up");
  AA("no_walk",     "east");
  AA("no_walk",     "west");
}

take_breath(str) 
{
 object air;

  if (!str) 
  {
    notify_fail("Take what?\n");
    return 0;
  }
  if ((str == "breath") || (str == "breath of air") || (str == "a breath")) 
  {
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
    air = CLO ("/players/cashimor/objects/breath");
    transfer (air, TP);
    write("You take a big breath of air.\n");
    say(TPN+" gulps in a big breath of air.\n");
    return 1;
  }
}

int swim(string str)
{
  if (str == "east")
  {
    write("You honestly don't think you can swim in that direction.\n"+
   	  "The strange currents in that direction would likely do you\n"+
	  "some damage.\n");
    return 1;
  }
  if (str == "west")
  {
    write("You paddle your way to the west.\n");

    MPL("swimming west#/players/tamina/castle/rooms/umoat2");

    return 1;
  }
  if (!str || str == "up")
  {
    write("You start to swim back to the surface.\n");

    MPL("swimming upwards#/players/tamina/castle/rooms/moat21");

    return 1;
  }
  if (str == "into hole" || str == "hole" || str == "to hole")
  {
    write("You are too big to swim into the hole.\n");
    return 1;
  }
}

no_walk()
{
  write("You find it very difficult to walk anywhere down here...\n"+
	"Try swimming instead.\n");
    say(TPN+" tries to walk against the current.\n");

  return 1;
}

