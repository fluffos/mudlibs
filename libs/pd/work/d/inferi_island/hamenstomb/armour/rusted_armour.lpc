#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Rusted Armour");
    set("id", ({ "vest", "armour" }) );
    set("short", "%^ORANGE%^Rusted Armour%^RESET%^");
    set("long", "%^ORANGE%^Used in battle many times, this armour is beginning to show its age.%^RESET%^" );
    set_type("vest");
    set_ac(2);
    set_limbs( ({ "torso" }) );
    set_weight(20);
    set_curr_value("gold", 65);
}
int query_auto_load() {
    if (this_player()->query_level() >= 8)
	return 1;
}
