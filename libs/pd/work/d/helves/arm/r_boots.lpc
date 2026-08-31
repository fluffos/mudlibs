#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Dark Boots");
    set_short("Dark Taininted Boots");
    set_long("These are boots of the high elf assassins. They are"
	" made of what seems like the skins of an animal that you"
	" have never seen. You are not sure what it was that was"
	" killed but you are sure that it put up a fight. There"
	" is a type of dye coloring the boots.");
    set_id( ({ "boots" , "tainted boots","leather boots" }) );
    set_ac(5);
    set_wear("You seem to be able to walk wouthout making noise");
    set_remove("You make noise trying to get them off");
    set_mass(9);
    set_curr_value("gold", 40);
    set_type("boots");

    set_limbs( ({ "right foot","left foot" }) );
}
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
