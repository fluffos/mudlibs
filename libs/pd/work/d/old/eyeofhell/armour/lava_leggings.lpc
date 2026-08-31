#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Lava Leggings");
    set("id", ({ "leggings" }) );
    set("short", "%^RESET%^%^RED%^L%^ORANGE%^a%^RED%^va L%^ORANGE%^e%^RED%^gg%^ORANGE%^i%^RED%^ngs%^RESET%^");
    set("long", "%^RESET%^%^RED%^Forged by the sinners, these leggings offer great protection.%^RESET%^" );
    set_type("leggings");
    set_ac(5);
    set_limbs( ({ "right leg", "left leg" }) );
    set_weight(15);
    set_curr_value("gold", 100);
}
int query_auto_load() {
    if (this_player()->query_level() >= 36)
	return 1;
}
