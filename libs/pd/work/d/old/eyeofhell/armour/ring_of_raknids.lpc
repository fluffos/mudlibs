#include <std.h>
#include <amun.h>
inherit ARMOUR;   
int can_wear();                                                                  
void create() {
    ::create();                                                                        
    set_name("Ring of Fire");
    set("id", ({ "ring" }) );
    set("short", "%^RESET%^%^ORANGE%^R%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^n%^RED%^g %^ORANGE%^O%^RED%^f %^ORANGE%^F%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^RED%^e%^RESET%^");
    set("long", "%^RESET%^%^RED%^When you wear this ring, it looks as if your finger is on fire.%^RESET%^" );
    set_type("ring");
    set_ac(2);
    set_limbs( ({ "first hand", "second hand", "third hand", "fourth hand" }) );
    set_weight(5);
    set_curr_value("gold", 250); 
    set_wear( (: can_wear :) );
    set_remove("%^RESET%^%^ORANGE%^You remove your ring of raknids.%^RESET%^");
}
int query_auto_load() {
    if (this_player()->query_level() >= 36)
	return 1;
}
int can_wear() {
    if((string)this_player()->query_race() == "raknid") {
	write("%^BOLD%^%^BLACK%^The rings slips over your finger.");
	return 1;
    }
    if((string)this_player()->query_race() != "raknid") { 
	write("You are not allowed to wear this ring.");
	say((string)this_player()->query_cap_name() + " screams and drops the ring!");
	this_player()->force_me("drop ring");
	return 0;	
    }
}
