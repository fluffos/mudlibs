inherit "players/tamina/castle/planes/hostiles/water";
  int searched;

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
"to be a lot of weeds, and moss.  Small frogs and toad occasionally \n"+
"pass you by on their travels.  Further to the east, you can see that\n"+
"the water is becoming increasingly darker, from what you cannot tell.\n\n";
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
  AA("search",      "search");
}

take_breath(str) 
{
 object air;

  if (!str) 
  {
    notify_fail("Take what?\n");
    return 0;
  }
  if ((str != "breath") || (str == "breath of air") || (str == "a breath")) 
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
    write("You paddle your way to the east.\n");

    MPL("swimming east#/players/tamina/castle/rooms/umoat21");

    return 1;
  }
  if (str == "west")
  {
    write("You paddle your way to the west.\n");

    MPL("swimming west#/players/tamina/castle/rooms/umoat");

    return 1;
  }
  if (!str || str == "up")
  {
    write("You start to swim back to the surface.\n");

    MPL("upwards#/players/tamina/castle/rooms/moat2");

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

int search(string str)
{
  object frog,gem;

  if (str == "weeds" || str == "mud" || str == "bottom")
  {
    write("You delve through the muddy weeds at the bottom of the moat.\n"+
          "You do succeed in uncovering an angry frog, but can see a glint\n"+
	  "amidst the dirt...\n");
      say(TPN+" causes more muck and dirt to cloud the water further.\n");

    frog = CLO ("obj/monster");

    frog->set_name("frog");
    frog->set_short("A green frog");
    frog->set_long(" A horrible little frog that eyes you angrily.\n");
    frog->set_level(5);
    frog->set_frog(1);
    frog->set_has_gills(1);   
    frog->set_aggressive(1);

    MO (frog, TO);

    return 1;
  }
  if (str == "dirt")
  {
    if (frog && living(frog))
    {
      write("The little frog prevents you from searching the dirt.\n"+
	    "It manages to get another _SNAP_ at your hand !!\n");
      HIT(10);
      return 1;
    
    }
    if (searched)
    {
      write("There is nothing there.\n");
      return 1;
    }
    else
    {
    write("You search through the dirt, and manage to find the glinting thing.\n"+ 
          "It seems to be a little green gem...\n");
    say(TPN+" looks through the dirt, and finds a little gem...\n");

    gem = CLO ("obj/treasure");
 
    gem->set_name("glowing gem");
    gem->set_alias("gem");
    gem->set_alt_name("glowing");
    gem->set_short("A Glowing Gem");
    gem->set_long("A small glowing gem, with a peculiar weightlessness about it.\n"+
                  "You think that it must be worth something...\n");
    gem->set_weight(-2);
    gem->set_value(500);
    gem->set_light(1);

    TR (gem, TP);

    searched = 1;

    return 1;
    }
  }
  if (!str)
  {
  NFAIL("Search what?\n");
  return 0;
  }
}
