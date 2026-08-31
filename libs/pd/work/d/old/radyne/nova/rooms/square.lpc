// Radyne Nova Square 
#include <std.h>
#include <radyne.h>
inherit ROOM;

int cmd_start(string str);

void init() {
   ::init();
   add_action("cmd_start","start");
}

void create() {
   ::create();
   set_properties( ([
     "no attack" : 1,
     "no magic"  : 1,
     "no bump"   : 1,
     "outdoors"  : 1,
     "light"     : 2,
     "no steal"  : 1,
     "night light": 2,
     "town"      : 1,
   ]) );
   set_listen("default","A low hustle of city life echoes here.");
   set_short("Radyne Nova Commons");
   set_long(
     "%^BOLD%^%^BLUE%^Radyne Nova Commons%^RESET%^\n"
     "The heart of the Radyne Nova in this large open circle of "
     "white stone. Placed evenly around the commons are large, "
     "stone, pillars holding flames like great torches. "
     "There is a peace here even in the center of a busy capital "
     "like this. To the north the Radyne Palace can be seen, "
     "nestled in the ageless bounty of Pinnacle Heights. "
     "There is a statue of The Great Beast towering over the area. "
   );
   set_night_long(
     "%^BOLD%^%^BLUE%^Radyne Nova Commons%^RESET%^\n"
     "In the center of the Radyne Empire's capital city all "
     "is quiet, few people are out at this hour. "
     "The pillars radiate their fiery glow dimly over the commons "
     "and the surrounding streets, providing enough light "
    "to see just fine, but not enough to be very disturbing to "
    "the residents. The Great Beast's statue casts an ominous "
     "penumbra to each pillar. The palace is only an "
    "outline in the distance in shades of black. "
   );
   set_items( ([
     ({ "circle","stone","white stone"}) :
        "Well fitted, smooth white stone used as a road.",
     ({ "pillars","columns","torches"}) :
        "High towers with flames set atop to light commons.",
     ({ "pillar","column" }) :
        "A tall stone tower carrying a flame in its crown.",
     "palace" : "The beautiful Radyne Palace lies to the north.",
     ({ "mountains","mountain","heights","pinnacle heights" }) :
       "An age old mountain topped with snow, wraps around Radyne Palace.",
   ]) );
   set_exits( ([
     "north" : ROOMS "nsquare1",
     "east" : ROOMS "esquare1",
     "west" : ROOMS "wsquare1",
     "southwest" : ROOMS "lsquare1",
     "southeast" : ROOMS "rsquare1",
     "south" : ROOMS "ssquare1",
   ]) );

}
int cmd_start(string str) {
   if(!str || str=="") {
   notify_fail("Start where?\n");
   return 0;
   }
   if(str != "here") {
     notify_fail("You cannot start there.\n");
     return 0;
     }
   this_player()->set_primary_start("/d/radyne/nova/rooms/square");
   write("You are now set to start in%^BOLD%^%^BLUE%^ Radyne Nova Commons%^RESET%^.");
   return 1;
}

void reset() {
   ::reset();
   if(!present("beast statue"))
   new("/d/radyne/obj/r_statue")->move(this_object());
}


