#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("wings");
    set("id", ({"wings", "torn and bloody angel wings"}) );
    set_short("Torn and %^RED%^bloody%^RESET%^ angel wings");
    set_long("These were once the wings of an angel.  They have been "
      "ripped off and desecrated in horrible ways.  Blood still clings to "
      "the scraggly feathers.");
    set_type("wing armour");
    set_limbs( ({"right wing", "left wing"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "nulvect")
	return 1;
}
