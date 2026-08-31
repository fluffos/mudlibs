#include <std.h>
#include <amun.h>
inherit ARMOUR;   
int can_wear();                                                                  						void create() {
    ::create();                                                                        				set_name("Ring of Raknids");
    set("id", ({ "ring" }) );
    set("short", "%^BOLD%^%^BLACK%^R%^WHITE%^i%^BLACK%^ng %^WHITE%^O%^BLACK%^f R%^WHITE%^a%^BLACK%^kn%^WHITE%^i%^BLACK%^ds%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^This ring was forged for the She Raknid by Lucy herself.  This ring shows the mark of a black widow inside of a %^RED%^red ruby%^BLACK%^.%^RESET%^" );
    set_type("ring");
    set_ac(2);
    set_limbs( ({ "first hand", "second hand", "third hand", "fourth hand" }) );
    set_weight(5);
    set_curr_value("gold", 200); 
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
