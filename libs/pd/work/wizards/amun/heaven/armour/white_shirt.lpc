#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                                                              set_name("White Leather Shirt");
    set("id", ({ "shirt", "white leather shirt" }) );
    set("short", "%^BOLD%^%^WHITE%^White Leather Shirt%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^This shirt was made out of pure holiness, love and of course leather.%^RESET%^");
    set_type("shirt");
    set_ac(5);
    set_limbs( ({ "right arm", "left arm", "torso" }) );
    set_weight(20);
    set_curr_value("gold", 200);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
