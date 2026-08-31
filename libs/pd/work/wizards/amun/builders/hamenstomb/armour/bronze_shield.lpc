#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("shield");
    set("id", ({ "shield" }) );
    set("short", "%^ORANGE%^Bronze Shield");
    set("long", "There are carvings around the edges that make this shield unique." );
    set_type("shield");
    set_ac(3);
    set_limbs( ({ "right hand", "right arm", "torso" }) );
    set_weight(75);
    set_curr_value("gold", 120); 
    set("read", "\"%^BOLD%^%^BLACK%^The watchers hide in secret and serve the King and Queen.%^RESET%^%^WHITE%^\"");
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
