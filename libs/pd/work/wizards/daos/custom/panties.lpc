#include <std.h>

inherit ARMOUR;

void create() {    
    ::create();
    set_properties( (["no steal" : 1 ]) );
    set_name("panties");
    set("id", ({"panties", "blue panties"}) );
    set_short("%^BOLD%^BLUE%^B%^RESET%^BOLD%^l%^RESET%^BOLD%^BLUE%^u%^RESET%^"
      "%^BOLD%^e%^RESET%^ %^BOLD%^BLUE%^P%^RESET%^BOLD%^a%^RESET%^BOLD%^BLUE%^n%^"
      "%^RESET%^BOLD%^t%^RESET%^BOLD%^BLUE%^i%^RESET%^BOLD%^e%^RESET%^BOLD%^BLUE%^s%^"
      "%^RESET%^");
    set_long("A pair of blue panties.");
    set_type("garter");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "kumi")
	return 1;
}
