// seeker
#include <rain.h>
#include <std.h>
inherit ROOM;
int climb_up(string str);
/* void init()
{
 ::init();
 add_action("climb_up", "climb");
} */
void create()
{
 ::create();
set_short("in the forest");
set_long("The forest is very humid. The ground is scattered with "
          "decaying leaves which are spoungy underfoot. Trees tower above blocking "
         "out the sky. Mildew and mold cover the side of the trees. ");
set_items( 
          ([ "vines" : "The vines go from tree to tree.",
             "trees" : "The trees tower over you.",
             "ground": "The grounds full of leaves and is soggy." ]) );
set_property("light", 3);
    set_property("forest", 1);
set_property("night light", 2);
set_smell("default", "The humid air stifils your senses.");
set_listen("default", "You hear animals scattering to run away from you.");
set_exits( ([ "west" : "/d/nopk/standard/rain_forest",
              "east" : ROOMS"path1" ]) );
}
/*
int climb_up(string str)
{
 if (!str || str=="") 
   {
    message("info", "Climb what?", this_player());
    return 1;
   }
 if (str!="vines") return 0;
 message("info", "You make a jump for a vine and grab it.", this_player());
 message("info", "You pull yourself up and find yourself on a platform.", this_player());
 this_player()->move_player(ROOMS"tree", "into the trees.");
 return 1;
} */
