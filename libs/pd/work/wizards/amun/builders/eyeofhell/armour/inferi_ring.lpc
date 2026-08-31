#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Inferi Ring");
    set("id", ({ "ring" }) );
    set("short", "%^BOLD%^%^BLACK%^Inferi Ring");
    set("long", "%^BOLD%^%^BLACK%^This ring is made by the inferi for the Eye of Hell." );
    set_type("ring");
    set_ac(1);
    set_limbs( ({ "fingers" }) );
    set_weight(5);
    set_curr_value("gold", 150); 
}
int query_auto_load() {
    if (this_player()->query_level() >= 20)
	return 1;
}
