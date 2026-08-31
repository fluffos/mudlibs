#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                    						void create() {
    ::create();                                                                        				 set_name("Basilisk Fangs");
    set("id", ({ "fang", "knife", "fangs", "Baslisk Fangs" }) );
    set("short", "%^BOLD%^%^BLACK%^B%^WHITE%^a%^BLACK%^s%^WHITE%^i%^BLACK%^l%^WHITE%^i%^BLACK%^sk F%^WHITE%^a%^BLACK%^ngs%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^These are the fangs of a giant %^BOLD%^%^BLACK%^B%^WHITE%^a%^BLACK%^s%^WHITE%^i%^BLACK%^l%^WHITE%^i%^BLACK%^sk.%^RESET%^" );
    set_type("knife");
    set_weight(10);
    set_curr_value("gold", 50);
    set_wc(7);
    set_type("knife");
    set("skill level", 134);
    add_poisoning(10);
}
int query_auto_load() {
    if (this_player()->query_level() >= 36)
	return 1;
}
