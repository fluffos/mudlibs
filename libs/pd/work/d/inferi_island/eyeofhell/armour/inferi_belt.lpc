#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Inferi Belt");
    set("id", ({ "belt" }) );
    set("short", "%^BOLD%^%^BLACK%^Inferi Belt");
    set("long", "%^BOLD%^%^BLACK%^This belt was made by the Inferi for the Eye of Hell.%^RESET%^" );
    set_type("belt");
    set_ac(2);
    set_limbs( ({ "torso" }) );
    set_weight(15);
    set_curr_value("gold", 150);
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
