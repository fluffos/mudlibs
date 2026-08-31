#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                
void create() {
    ::create();                                                                    
    set_name("Ring of Fire");
    set("id", ({ "ring" }) );
    set("short", 
      "%^RESET%^%^ORANGE%^R%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^n%^RED%^g %^ORANGE%^O%^RED%^f %^ORANGE%^F%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^RED%^e%^RESET%^");
    set("long", "%^RESET%^%^RED%^When you wear this ring, it looks as if your finger is on fire.%^RESET%^" );
    set_type("ring");
    set_ac(1);
    set_limbs( ({ "fingers" }) );
    set_weight(5);
    set_curr_value("gold", 175);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 30)
	return 1;
}
