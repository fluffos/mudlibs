#include "../defs.h"

inherit LAND;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);

  set_short("Boardwalk Entrance");
  set_long("\
  You step onto a wide wooden path which leads far off to the east.\n\
The path is lined on both sides with tall palm trees that tower above,\n\
providing shade from the blazing sun.  Encircling the base of the palm\n\
trees is a large assortment of exotic plants and flowers, adding to the\n\
already stunning landscape before you.  Just in the distance to the\n\
east you can see stores lining the northern side of the boardwalk, and\n\
to the south the boardwalk opens up to a breathtakingly beautiful\n\
beach.\n");  
  
  add_exit(BWROOMS+"bw2","east");
  add_exit("/players/stardream/workroom","south");
  
  add_item("path","\
  A wooden boardwalk dusted lightly with sand");
  add_item("trees","\
  Tall palm trees which loom overhead providing shade");
  add_item("shade","\
  Cover provided from the sun by the tall palm trees");
  add_item("sun","\
  You really shouldn't look at the sun, it will damage your eyes");
  add_item("plants","\
  Exotic plants of every variety");
  add_item("flowers","\
  Beautiful colorful flowers");
  add_item("landscape","\
  The beautiful beach and crystal blue ocean make a stunning landscape");
  add_item("stores","\
  Various stores lining the northern side of the path");
  add_item("boardwalk","\
  A wide wooden path lined with stores");
  add_item("beach","\
  A beautiful sandy beach");
  
  set_chance(2);
  add_msg("A seagull flies by overhead.");
  add_msg("A piece of newspaper blows idly by.");
  add_msg("A seagull nearly craps on your head.");
  add_msg("A small ratty looking dog runs past.");
  add_msg("The scorching sun beats down upon you.");
  add_msg("The soft wind blows sand up onto the boardwalk.");
  add_msg("\
  A few flecks of sand dust up into your face, temporarily blinding\n\
  you for a few seconds.");
  
  
  add_smell("main", "You can smell the salt from the ocean lingering in the air.");
add_smell("air", "The air smells of sat water.");
  add_smell("water", "The water smells salty.");

  add_listen("main", "You hear seagulls squawking overhead.");
  add_listen(({"seagulls","gulls"}), "SQUAWK SQUAWK");
  
  
  add_exit_msg("east", ({
    "You continue down the boardwalk.\n",
    "walks further down the boardwalk.\n" }));
  add_exit_msg("south", ({
    "You walk back to the workroom.\n",
    "walks back to the workroom.\n", }));
    
}
