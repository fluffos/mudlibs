#include <std.h>
#include <petzoo.h>
inherit ROOM;

void create() {
    ::create();
    set_property("outdoors", 1);
    set_property("light", 2);
    set_property("night light", 1);
    set("short", "Along the road of urban renewal");
    set("long",	"You are a road heading east out of Arlon.  The road runs east and "+
      "west and is lined on both sides with number of new, well built houses.  "+ 
      "A number of houses are still under construction.  Quite a few for sale signs "+
      "are visible in the yards.  Lots of new residents wander the streets.");
    set_exits( (["west" : ROOMS + "arlonroad4",
	"east" : ROOMS + "arlonroad2" ]) );
    set_listen("default", "Sounds of construction can be heard everywhere.");
}
void reset() {
    int num_of_mobs = random(MAX_MOB_IN_ZONE)+1;
    int i;
    ::reset();
    if(!present("monster")) {
	for (i=0;i<num_of_mobs;i++){
	    new(MOB"resident")->move(this_object());
	}
    }
}
