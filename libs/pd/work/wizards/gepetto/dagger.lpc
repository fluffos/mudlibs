#include <std.h>
inherit WEAPON;

void create() {
    ::create();
    set_hit((:this_object(), "weapon_hit":));
    set_name("Ebon Dagger");
    set_short("%^BOLD%^%^BLACK%^Ebon Dagger%^RESET%^");
    set_long("The hilt of this dagger is made of pure onyx.  It is connected to the leather wrapped, sapphire handle.  The actual blade is made of pure ebon.  It is wickedly curved and viciously serrated.  This dagger looks to be for only the truly evil.");
    set_id(({"dagger", "ebon dagger"}));
    set_mass(7);
    set_value(218);
    set_type("knife");
    set_hands(1);
    set_wc(10);
    set_ac(1);

}
int weapon_hit()
{
    int res;
    object atk;
    atk = (object)environment()->query_current_attacker();
    if(random(102) > 80) {
	write ("You thrust your dagger into your opponents body and twist the blade before pulling it out leaving a gaping wound.");
	say((string)this_player()->query_cap_name()+
	  " thrusts his dagger into his opponent's body and twists the blade.");
	res=(random(65+random(60)-random(50))*((this_player()->query_level()/20)+1));
	return res;
	return 0;
    }
}


