//  Whit

#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("gateway");
    set_short("a gateway");
    set_long("The gateway leads to far away places not yet visted by "
      "anyone.  For a strange reason it seems to glow red unlike before "
      "when the color was blue.  It is big enough that maybe you "
      "could <enter> it.");
    set_id( ({"gateway","a gateway"}) );
    set_prevent_get("You may not take that.\n");
}

void init() {
    ::init();
    add_action("enter", "enter");
}

int enter(string str) {
    if(!str || str != "gateway") return notify_fail("Enter what?\n");
    write("As you near the gateway it seems to pull you into it.\n");
    write("You loose conciousness");
    message("environment", this_player()->query_cap_name()+" steps close to "
      "the gateway and is sucked in.\n", 
      environment(this_player()), ({this_player()}) );
    this_player()->move_player("/d/events/rooms/temp", "portal");
    call_out("release_para", 10);
    return 1;
}

int release_para() {
    write("You are no longer uncouncious.\n");
    this_player()->move("/d/events/rooms/stair1");
    return 1;
}


