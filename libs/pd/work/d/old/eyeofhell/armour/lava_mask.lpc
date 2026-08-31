#include <std.h>
int query_auto_load() {
    if (this_player()->query_level() >= 50)
	return 1;
}
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Mask of Lava");
    set("id", ({ "mask" }) );
    set("short", "%^RESET%^%^RED%^Lava Mask%^RESET%^");
    set("long", "%^RESET%^%^RED%^This mask was made from the Lava found in the Oculus Ineri.%^RESET%^" );
    set_type("mask");
    set_ac(4);
    set_limbs( ({ "head" }) );
    set_weight(15);
    set_curr_value("gold", 150);
    set_element("fire", 10);
    set_element("ice", -10);
}
