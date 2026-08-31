#include <std.h>
#include <amun.h>
inherit ARMOUR;   
int can_wear();                                                                  						void create() {
    ::create();                                                                        				set_name("Black Centaur Leggings");
    set("id", ({ "leggings", "centaur leggings" }) );
    set("short", "%^BOLD%^%^BLACK%^Black Centaur Leggings%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^These leggings were made by the headless horseman for his mount.%^RESET%^" );
    set_type("leggings");
    set_ac(5);
    set_limbs( ({ "left foreleg", "right foreleg", "left rear leg", "right rear leg" }) );
    set_weight(15);
    set_curr_value("gold", 100); 
    set_wear( (: can_wear :) );
    set_remove("%^BOLD%^%^BLACK%^Your legs feel less protected.%^RESET%^");
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
int can_wear() {
    if((string)this_player()->query_race() == "centaur") {
	write("%^BOLD%^%^BLACK%^Your legs feel more protected.%^RESET%^");
	return 1;
    }
    if((string)this_player()->query_race() != "centaur") { 
	write("You do not have 4 hoofs!.");
	say((string)this_player()->query_cap_name() + " screams and drops the leggings!");
	this_player()->force_me("drop leggings");
	return 0;	
    }
}
