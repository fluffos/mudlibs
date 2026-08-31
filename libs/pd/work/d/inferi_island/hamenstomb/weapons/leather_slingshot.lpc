#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                   
void create() {
    ::create();                                                                       
    set_name("Leather Slingshot");
    set("id", ({ "slingshot" }) );
    set("short", "%^BOLD%^%^BLACK%^Leather Slingshot%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^A weapon made and used by the wearied people of Hamen's Tomb.%^RESET%^" );
    set_type("projectile");
    set_weight(5);
    set_curr_value("gold", 75);
    set_wc(4);
    set_type("projectile");
    set("skill level", 75);
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
