#include <std.h>
int query_auto_load() {
    if (this_player()->query_level() >= 1)
	return 1;
}
#include <amun.h>
inherit WEAPON;                                                                   
void create() {
    ::create();                                                                       
    set_name("Jagged Rock");
    set("id", ({ "rock" }) );
    set("short", "Jagged Rock");
    set("long", "This is a rock picked up off of the ground." );
    set_type("projectile");
    set_weight(3);
    set_curr_value("gold", 10);
    set_wc(2);
    set_type("projectile");
    set("skill level", 10);
}
