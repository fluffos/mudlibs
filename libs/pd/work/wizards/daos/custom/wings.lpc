#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("wings");
    set("id", ({"wings ", "ethereal wings"}) );
    set_short("%^BOLD%^E%^RESET%^BOLD%^BLACK%^t%^RESET%^BOLD%^h%^RESET%^BOLD%^"
      "%^BLACK%^er%^RESET%^BOLD%^e%^RESET%^BOLD%^BLACK%^a%^RESET%^BOLD%^l%^RESET%^ "
      "%^BOLD%^Wi%^RESET%^BOLD%^BLACK%^n%^RESET%^BOLD%^gs%^RESET%^");
    set_long("The wings are large and translucent giving off a faint %^BLUE%^bluish"
      "%^RESET%^ glow, and just generally look cool.");
    set_type("wing armour");
    set_limbs( ({"right wing", "left wing"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "tsuke")
	return 1;
}
