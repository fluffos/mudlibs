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
"Around you is a lot of murky water, which is making it quite \n"+
"difficult for you to see very far.  Along the muddy bottom seems\n"+
"to be a lot of weeds, and moss. \n"+
    no_obvious_msg = "";
  
    items = ({
  "weeds",
"Horrible looking green weeds",
  "bottom",
"This is full of mud, and muck, which is making visibility very limited",
  "frogs",
"Little green amphibians that swim past you, doing you no harm",
  "toads",
"Little green amphibians that swim past you, doing you no harm",
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
  if (str == "east" || str == "e")
  {
    write("You paddle your way to the east.\n");

    MPL("swimming east#/players/tamina/castle/rooms/umoat");

    return 1;
  }
  if (str == "west" || str == "w")
  {
    write("You paddle your way to the west.\n");

    MPL("swimming west#/players/tamina/castle/rooms/umoat31");

    return 1;
  }
  if (!str || str == "up" || str == "w")
  {
    write("You start to swim back to the surface.\n");

    MPL("upwards#/players/tamina/castle/rooms/moat3");

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
