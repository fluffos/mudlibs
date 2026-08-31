#include <std.h>
#include <petzoo.h>
inherit ROOM;
void create() {
    ::create();
    set_property("outdoors", 1);
    set_property("light", 2);
    set_property("night light", 1);
    set("short", "Along the road of urban renewal");
    set("long", "You are a road heading east out of Arlon.  This part of town
is "+
      "not nearly as trashy as it is a few blocks to the west.  The road
continues"+
      " to the east and full of new housing developments under construction. 
"+
      "Perhaps Arlon is undergoing some urban renewal to try and improve its
image.  "+
      "For sale signs are visible in many yards.  Lots of new residents wander
the streets.");
    set_exits( (["west" : "/d/nopk/newarlon/rooms/roads/12" ,
        "east" : ROOMS + "arlonroad4" ]) );
    set_listen("default", "Sounds of new construction is all around you.");
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
