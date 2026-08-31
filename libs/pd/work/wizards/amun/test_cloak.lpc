#include <std.h>
#include <amun.h>
inherit ARMOUR;       
int can_wear(); 
void create() {
    ::create();                                                                
    set_name("Cloak of Evil");
    set("id", ({ "cloak" }) );
    set("short", "Cloak of Evil");
    set("long", "This cloak was made to aide those who wish to stay hidden in the shadows." );
    set_type("cloak");
    set_ac(4);
    set_limbs( ({ "torso", "right arm", "left arm" }) );
    set_weight(30);
    set_curr_value("gold", 200); 
    set_wear( ( : can_wear : ) );
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
int can_wear() {
    if((int)this_player()->query_level() >= 50) { 
	write("You feel the power of evil.");
	return 1;
    }
    write("You feel the power of evil leave you.\n");
    say((string)this_player()->query_cap_name() + " feel the evil leave her.");
    if((int)this_player()->query_level() >= 50) {  
	write("You are not allowed to wear this cloak.");
	say((string)this_player()->query_cap_name() + " screams and drops the cloak!");
	this_player()->force_me("drop cloak");
	return 0;   
    }
}
