#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                         
void create() {
    ::create();                                                         
    set_name("Black Earrings");
    set("id", ({ "black earrings", "earrings"}) );
    set("short", "%^BOLD%^%^BLACK%^%^B%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k %^RESET%^E%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^g%^BOLD%^%^BLACK%^s%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^These %^RESET%^were %^BOLD%^%^BLACK%^once %^RESET%^earrings %^BOLD%^%^BLACK%^powered %^RESET%^by %^BOLD%^%^BLACK%^the %^RESET%^goodenss %^BOLD%^%^BLACK%^of %^RESET%^Heaven. %^BOLD%^%^BLACK%^Now, %^RESET%^they %^BOLD%^%^BLACK%^are %^RESET%^powered %^BOLD%^%^BLACK%^by %^RESET%^the %^BOLD%^%^BLACK%^fallen, %^RESET%^the %^BOLD%^%^BLACK%^damned.%^RESET%^");
    set_type("earrings");
    set_ac(1);
    set_limbs( ({ "head"}) );
    set_weight(3);
    set_curr_value("gold", 50);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
