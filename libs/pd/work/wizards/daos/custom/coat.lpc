#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("coat");
    set("id", ({"coat", "black trench coat"}) );
    set_short("%^BOLD%^%^BLACK%^Black trench coat%^RESET%^");
    set_long("This is a Black trench coat, with the TCM insignia "
      "emblazoned on the right shoulder.");
    set_type("coat");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "bellos")
	return 1;
}
