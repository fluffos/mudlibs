#include <std.h>
#include <petzoo.h>
inherit ROOM;

void create() {
    ::create();
    set_property("outdoors", 1);
    set_property("light", 2);
    set_property("night light", 1);
    set("short", "Along the road of urban renewal");
    set("long",	"You are a road heading east out of Arlon.  The road widens a bit "+
      "here and turns to the north.  A number of new, well built houses line both"+ 
      " sides of road.  Each house has a large yard and a hitching post.  A couple "+
      "of for sale signs are in sight.  Something large is visible to the north.  "+
      "Lots of new residents wander the streets.");
    set_exits( (["west" : ROOMS + "arlonroad2",
	"north" : ROOMS + "zooentrance" ]) );
    set_listen("default", "To the north comes the faint sounds of crowds gathering.");
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
