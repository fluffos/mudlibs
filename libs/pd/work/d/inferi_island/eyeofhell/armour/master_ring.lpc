#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Master Ring");
    set("id", ({ "ring" }) );
    set("short", "%^BOLD%^%^BLACK%^M%^WHITE%^a%^BLACK%^st%^WHITE%^e%^BLACK%^r R%^WHITE%^i%^BLACK%^ng%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^This ring was made by Lucifer, he uses it to command his minions.  This power may not work for mortals.%^RESET%^" );
    set_type("ring");
    set_ac(2);
    set_limbs( ({ "fingers" }) );
    set_weight(10);
    set_curr_value("gold", 175);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
