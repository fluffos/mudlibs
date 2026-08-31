#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Lava Ring");
    set("id", ({ "ring" }) );
    set("short", "%^RESET%^%^RED%^L%^ORANGE%^a%^RED%^v%^ORANGE%^a %^RED%^R%^ORANGE%^i%^RED%^ng");
    set("long", "%^RESET%^%^ORANGE%^This ring was made from the lava inside the Oculus Inferi." );
    set_type("ring");
    set_ac(2);
    set_limbs( ({ "fingers" }) );
    set_weight(5);
    set_curr_value("gold", 250); 
    set_element("fire", 10);
    set_element("ice", -10);
}
int query_auto_load() {
    if (this_player()->query_level() >= 25)
	return 1;
}
