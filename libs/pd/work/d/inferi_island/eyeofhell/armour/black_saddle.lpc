#include <std.h>
#include <amun.h>
inherit ARMOUR;   
int can_wear();                                                                  						void create() {
    ::create();                                                                        				set_name("Black Saddle");
    set("id", ({ "black saddle", "saddle" }) );
    set("short", "%^BOLD%^%^BLACK%^Black Saddle%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^This saddle was made by the headless horseman for his mount.%^RESET%^" );
    set_type("leggings");
    set_ac(2);
    set_limbs( ({ "horse torso" }) );
    set_weight(25);
    set_curr_value("gold", 65); 
    set_wear( (: can_wear :) );
    set_remove("%^BOLD%^%^BLACK%^Your horse torso feels less protected.%^RESET%^");
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
int can_wear() {
    if((string)this_player()->query_race() == "centaur") {
	write("%^BOLD%^%^BLACK%^Your horse torso feels more protected.%^RESET%^");
	return 1;
    }
    if((string)this_player()->query_race() != "centaur") { 
	write("You do not have a horse torso!.");
	say((string)this_player()->query_cap_name() + " screams and drops the saddle!");
	this_player()->force_me("drop saddle");
	return 0;	
    }
}
