#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                
void create() {
    ::create();                                                                    
    set_name("Mask of Lava");
    set("id", ({ "mask" }) );
    set("short", "%^RESET%^%^RED%^Lava Mask%^RESET%^");
    set("long", "%^RESET%^%^RED%^This mask was made from the Lava found in the Oculus Ineri.%^RESET%^" );
    set_type("mask");
    set_ac(3);
    set_limbs( ({ "head" }) );
    set_weight(15);
    set_curr_value("gold", 80);
}
int query_auto_load() {
    if (this_player()->query_level() >= 50)
	return 1;
}
