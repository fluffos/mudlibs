#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                
void create() {
    ::create();                                                                    
    set_name("lava ring");
    set("id", ({ "ring" }) );
    set("short", "%^RESET%^%^RED%^L%^ORANGE%^a%^RED%^v%^ORANGE%^a %^RED%^R%^ORANGE%^i%^RED%^ng");
    set("long", "%^RESET%^%^ORANGE%^This ring was made from the lava inside the Oculus Inferi." );
    set_type("ring");
    set_ac(1);
    set_limbs( ({ "fingers" }) );
    set_weight(5);
    set_curr_value("gold", 190); 
}
int query_auto_load() {
    if (this_player()->query_level() >= 25)
	return 1;
}
