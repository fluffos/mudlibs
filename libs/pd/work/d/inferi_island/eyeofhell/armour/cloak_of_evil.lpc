#include <std.h>
#include <amun.h>
inherit ARMOUR;       
int can_wear(); 
void create() {
    ::create();                                                                        				set_name("Cloak of Evil");
    set("id", ({ "cloak" }) );
    set("short", "%^BOLD%^%^BLACK%^Cl%^WHITE%^oa%^BLACK%^k %^WHITE%^o%^BLACK%^f %^WHITE%^E%^BLACK%^v%^WHITE%^i%^BLACK%^l");
    set("long", "%^BOLD%^%^BLACK%^This cloak was made to aide those who wish to stay hidden in the shadows." );
    set_type("cloak");
    set_ac(2);
    set_limbs( ({ "torso", "right arm", "left arm" }) );
    set_weight(30);
    set_curr_value("gold", 130); 
    set_wear( (: can_wear :) );
    set_remove("%^BOLD%^%^BLACK%^The power of evil leaves you.");
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
int can_wear() {
    if((int)this_player()->query_level() >= 50) { 
	write("%^BOLD%^%^BLACK%^You feel the power of evil.");
	return 1;
    }
    if((int)this_player()->query_level() <= 49) { 
	write("You are not allowed to wear this cloak.");
	say((string)this_player()->query_cap_name() + " screams and drops the cloak!");
	this_player()->force_me("drop cloak");
	return 0;	
    }
}
