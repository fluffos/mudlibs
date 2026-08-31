#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("necklace");
    set("id", ({"necklace", "pendant"}) );
    set_short("A %^BOLD%^YELLOW%^glowing%^RESET%^ pendant");
    set_long("The pendant glows a soft %^BLUE%^blue%^RESET%^, and reads "
      "%^BOLD%^'%^RESET%^It provides a soft light that lightens the heart"
      "%^BOLD%^'%^RESET%^.");
    set_type("necklace");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "helena")
	return 1;
}
