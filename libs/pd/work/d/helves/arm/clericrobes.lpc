#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Cleric Robes");
    set_short("A Cleric Robes");	
    set_long("These are the garments used by clerics. It is light"
	" and has a slight glow to them. You feel like walking"
	" armound and healing someone, maybe even a little walking"
	" on water.");
    set_id( ({ "robes","cleric robes" }) );
    set_wear("%^YELLOW%^WOW! Clerics have it made!");
    set_remove("%^YELLOW%^Aww! Too bad you can't keep it!");
    set_ac(7);
    set_mass(22);
    set_curr_value("gold", 10);
    set_type("robe");
    set_limbs( ({ "torso","head","left leg","right leg","right arm","left arm"
}) );

}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
