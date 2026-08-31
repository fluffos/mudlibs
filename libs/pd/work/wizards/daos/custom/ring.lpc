#include <std.h>                                                       

inherit ARMOUR;

void create() {
    ::create();
    set_name("ring");
    set("id", ({"ring", "assassins ring"}) );
    set_short("%^BOLD%^%^BLACK%^A%^RESET%^%^BOLD%^%^BLUE%^s%^RESET%^"
      "%^BOLD%^%^BLACK%^s%^RESET%^%^BOLD%^%^BLUE%^a%^RESET%^"
      "%^BOLD%^%^BLACK%^s%^RESET%^%^BOLD%^%^BLUE%^s%^RESET%^"
      "%^BOLD%^%^BLACK%^i%^RESET%^%^BOLD%^%^BLUE%^n%^RESET%^"
      "%^BOLD%^%^BLACK%^'s%^RESET%^  %^BOLD%^%^BLACK%^Ring%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This ring belongs to the great shadow lord "
      "Endbringer.  The band is made from a black diamond and it has a pale "
      "%^BOLD%^%^BLUE%^blue%^RESET%^ %^BOLD%^%^BLACK%^gem on it.  It is said "
      "Endbringer looted this ring from her first kill%^RESET%^.");
    set_type("ring");
    set_limbs( ({"right hand", "left hand"}) );
}

int query_auto_load() {
    if (this_player()->query_name() == "endbringer")
	return 1;
}
