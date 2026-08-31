#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("collar");
    set("id", ({"collar", "black leather collar"}) );
    set_short("%^BOLD%^BLACK%^a b%^RESET%^l%^RESET%^BOLD%^a%^RESET%^c%^"
      "%^BOLD%^BLACK%^k%^ l%^RESET%^e%^BOLD%^a%^RESET%^BOLD%^BLACK%^t%^RESET%^"
      "h%^BOLD%^e%^RESET%^BOLD%^BLACK%^r%^ c%^RESET%^o%^BOLD%^BLACK%^l%^RESET%^"
      "%^BOLD%^l%^RESET%^a%^BOLD%^BLACK%^r%^RESET%^");
    set_long("%^BOLD%^BLACK%^a black leather collar%^RESET%^");
    set_type("collar");
    set_limbs( ({"head"}) );
}

int query_auto_load() {
    if (this_player()->query_name() == "vian") {
	return 1;
    }
}

