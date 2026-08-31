//Made using Room generator by Nightshade
#include <std.h>
#include <helgrath.h>
inherit ROOM;
void init() {
    ::init();
    add_action("do_read","read");
}
void create() {
    ::create();
    set_short("Upgrade Store");
    set_properties( (["light" : 2, "night light" : 1, "indoors" : 1, "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" : 1]) );
    set_long("The shack's interior decorations seem a bit odd.  Fish that seem frozen in time hang along the walls.  Fishing hooks and various nick-nacks hang along the walls.  A sign hangs on the north wall.");
    set_exits( (["out" : "/d/helgrath/rooms/forest_pier"
      ]) );
}
int do_read(string str) {
    if(str != "sign") return notify_fail("Read what?\n");
    write("This shop does the following services: \n");
    write("   <upgrade> : This allowed you to upgrade your ship.\n");
    return 1;
}
void reset() {
    ::reset();
    if(!present("jack")) new(MOB"jack")->move(this_object());
}
