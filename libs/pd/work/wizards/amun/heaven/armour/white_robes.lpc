#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("White Robes");
    set("id", ({ "robe", "robes", "white robes", "white robe" }) );
    set("short", "%^BOLD%^%^WHITE%^White Robes%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^These robes were made out of pure holiness and love.%^RESET%^" );
    set_type("robes");
    set_ac(3);
    set_limbs( ({ "torso", "right arm", "left arm", "left leg", "right leg" }) );
    set_weight(30);
    set_curr_value("gold", 200); 
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
