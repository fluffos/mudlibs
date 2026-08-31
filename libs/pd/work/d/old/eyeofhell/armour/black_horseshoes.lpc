#include <std.h>
#include <amun.h>
inherit ARMOUR;   
int can_wear();                                                                  						void create() {
    ::create();                                                                        				set_name("Black Horsehoes");
    set("id", ({ "horseshoes", "shoes" }) );
    set("short", "%^BOLD%^%^BLACK%^Black Horseshoes%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^These horseshoes were made by the headless horseman for his mount.%^RESET%^" );
    set_type("boots");
    set_ac(6);
    set_limbs( ({ "right fore hoof", "left fore hoof", "right rear hoof", "left rear hoof" }) );
    set_weight(15);
    set_curr_value("gold", 250); 
    set_wear( (: can_wear :) );
    set_remove("%^BOLD%^%^BLACK%^Your hoofs feel more free as you slip off your horseshoes.%^RESET%^");
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
int can_wear() {
    if((string)this_player()->query_race() == "centaur") {
	write("%^BOLD%^%^BLACK%^Youre hoofs feel more protected.%^RESET%^");
	return 1;
    }
    if((string)this_player()->query_race() != "centaur") { 
	write("You do not have 4 hoofs!.");
	say((string)this_player()->query_cap_name() + " screams and drops the horseshoes!");
	this_player()->force_me("drop shoes");
	return 0;	
    }
}
