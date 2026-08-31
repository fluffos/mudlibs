#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                   
void create() {
    ::create();                                                                       
    set_name("Bow of the Magi");
    set("id", ({ "bow" }) );
    set("short", "%^BOLD%^%^BLACK%^Bow of the Magi%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^Made of leather, %^RESET%^%^ORANGE%^wood %^BOLD%^%^BLACK%^and %^WHITE%^f%^RESET%^%^WHITE%^ea%^BOLD%^%^WHITE%^th%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^rs %^BLACK%^from a falcon, this bow is accurate and strong.%^RESET%^" );
    set_type("bow");
    set_weight(20);
    set_curr_value("gold", 175);
    set_wc(10);
    set_type("ranged");
    set_wield("%^BOLD%^%^BLACK%^You feel the intelligence and the strength of the Magi.%^RESET%^");
    set_unwield("%^BOLD%^%^BLACK%^You feel the intelligence and the strength of the Magi leave you.%^RESET%^");
    set("skill level", 100);
}
int query_auto_load() {
    if (this_player()->query_level() >= 24)
	return 1;
}
