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
      "Each house has a large yard and a hitching post.  Closer inspection shows that"+
      " some of the houses are still under construction.  Occasional for sale signs "+
      "are visible in several yards.  Lots of new residents wander the streets.");
    set_exits( (["west" : ROOMS + "arlonroad5",
	"east" : ROOMS + "arlonroad3" ]) );
    set_listen("default", "Sounds of birds chirping can be heard over the occasional sounds of construction.");
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
