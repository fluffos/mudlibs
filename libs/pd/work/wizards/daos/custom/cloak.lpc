#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("cloak");
    set("id", ({"cloak, assassins cloak"}) );
    set_short("%^BOLD%^BLACK%^A%^RESET%^BOLD%^ss%^RESET%^BOLD%^BLACK%^a%^RESET%^"
      "%^BOLD%^ss%^BOLD%^BLACK%^in%^RESET%^BOLD%^'%^RESET%^BOLD%^BLACK%^s%^RESET%^ "
      "%^BOLD%^BLACK%^C%^RESET%^BOLD%^loa%^RESET%^BOLD%^BLACK%^k%^RESET%^");
    set_long("The %^BOLD%^BLACK%^cloak%^RESET%^ was made for the master "
      "%^BOLD%^BLACK%^a%^RESET%^BOLD%^ss%^RESET%^BOLD%^BLACK%^a%^RESET%^BOLD%^ss%^"
      "%^RESET%^BOLD%^BLACK%^in%^RESET%^... Scamp.");
    set_type("cloak");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "scamp")
	return 1;
}
