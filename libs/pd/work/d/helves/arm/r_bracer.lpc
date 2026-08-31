#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Titan Bracers");
    set_short("Titan Bracers");
    set_long("These are the Titan Bracers. They have some writting"
	" on them. There is a faint glow comming from the inside"
	" of them.");
    set_id( ({ "bracer","bracers","titan bracers","titinbracers" }) );
    set_ac(9);
    set_wear("You feel the power of the Titins");
    set_remove("You feel the power of the Peons");
    set_mass(90);
    set_curr_value("gold", 10);
    set_type("bracers");
    set_limbs( ({ "right arm","left arm"}) );

}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
