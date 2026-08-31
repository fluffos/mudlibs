#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("jacket");
    set("id", ({"jacket", "black leather jacket"}) );
    set_short("%^BOLD%^BLACK%^A Worn Black Leather Jacket%^RESET%^");
    set_long("This is a rather beat up black leather jacket adorned in "
      "patches of various bands.  It appears to have many knife holes in it, "
      "too clean to have been worn through.");
    set_type("coat");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "junkie")
	return 1;
}
