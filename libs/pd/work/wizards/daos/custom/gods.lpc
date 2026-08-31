#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("ring");
    set("id", ({"ring", "ring of the gods"}) );
    set_short("%^BOLD%^BLUE%^R%^RESET%^BOLD%^YELLOW%^in%^RESET%^%^BOLD%^BLUE%^g "
      "%^RESET%^BOLD%^of%^RESET%^ %^BOLD%^BLUE%^t%^RESET%^BOLD%^YELLOW%^h%^RESET%^"
      "%^BOLD%^BLUE%^e%^RESET%^ %^BOLD%^G%^RESET%^BOLD%^BLUE%^od%^RESET%^"
      "BOLD%^s%^RESET%^");
    set_long("The ring is a gift from the Gods, bestowed upon the most holy "
      "warrior of light for their services to the heavens");
    set_type("ring");
    set_limbs( ({"right hand, left hand"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "scoff")
	return 1;
}
