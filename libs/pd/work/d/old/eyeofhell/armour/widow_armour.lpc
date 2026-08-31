#include <std.h>
#include <amun.h>
inherit ARMOUR;   
int can_wear();                                                                  						void create() {
    ::create();                                                                        				set_name("Widow Armour");
    set("id", ({ "armour", "widow" }) );
    set("short", "%^BOLD%^%^BLACK%^W%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^d%^WHITE%^o%^BLACK%^w %^BLACK%^A%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^m%^WHITE%^o%^BLACK%^u%^WHITE%^r%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^This armour was made for the raknids.  It was made in the Oculus Inferi and has a %^BOLD%^%^RED%^hour glass %^BLACK%^on the backside.%^RESET%^" );
    set_type("armour");
    set_ac(13);
    set_limbs( ({ "torso", "abdomen" }) );
    set_weight(80);
    set_curr_value("gold", 300); 
    set_wear( (: can_wear :) );
    set_remove("%^BOLD%^%^BLACK%^You remove your %^BOLD%^%^BLACK%^W%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^d%^WHITE%^o%^BLACK%^w %^BLACK%^A%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^m%^WHITE%^o%^BLACK%^u%^WHITE%^r%^RESET%^.%^RESET%^");
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
int can_wear() {
    if((string)this_player()->query_race() == "raknid") {
	write("%^BOLD%^%^BLACK%^The %^BOLD%^%^BLACK%^W%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^d%^WHITE%^o%^BLACK%^w %^BLACK%^A%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^m%^WHITE%^o%^BLACK%^u%^WHITE%^r%^BLACK%^ slides down your body nicely.%^RESET%^");
	return 1;
    }
    if((string)this_player()->query_race() != "raknid") { 
	write("You are not allowed to wear this armour.");
	say((string)this_player()->query_cap_name() + " screams and drops the armour!");
	this_player()->force_me("drop armour");
	return 0;	
    }
}
