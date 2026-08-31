#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Silver Chainmail");
    set_short("Some Silver Chainmail");	
    set_long("These are some silver chainmail. It is made of pure"
	" silver and weighs several pounds. You don't understand"
	" how anyone can move in these things. They don't provide"
	" you with much protection either.");
    set_id( ({ "chainmail","armour","silver chainmail" }) );
    set_wear("%^CYAN%^You are crushed under the weight!");
    set_remove("%^CYAN%^You feel like a feather right now!");
    set_ac(11);
    set_mass(51);
    set_curr_value("gold", 60);
    set_type("body armour");
    set_limbs( ({ "torso","head","right arm","left arm"
}) );

}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
