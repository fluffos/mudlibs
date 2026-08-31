#include <std.h>
inherit ARMOUR;

int bonus;
int armour_wear();
int armour_remove();

void create() {
    ::create();
    set_name("chainmail");
    set_short("Chains of Vexgall");
    set_long("These heavy iron chains function both as a protective armour and a method of control. Designed by the Dark Elven armoursmiths specifically to contain Vexgall, they are heavily enchanted to provide him with the best protection in combat possible (for chains) and even greater raw power.");
    set_id( ({"chains","chains of vexgall"}) );
    set_ac(1);
    set_mass(50);
    set_curr_value("gold", 288);
    set_type("body armour");
    set_limbs( ({"torso"}) );
    set_wear((: armour_wear :));
    set_remove((: armour_remove :));
}

int armour_wear()
{

    if(this_player()->query_race() == "half-dragon")
    {
	bonus = 25;
    }
    else if(this_player()->query_race() == "dwarf")
    {
	bonus = 5;
    }
    else
    {
	bonus = 1;
    }
    write("You drape the Chains of Vexgall over your body.");
    message("info",this_player()->query_cap_name()+" drapes the Chains of Vexgall over "+this_player()->query_possessive()+" body.",environment(this_player()),this_player());
    if (!this_player()->query_stat_bonus("strength")) 
    {
	this_player()->add_stat_bonus("strength",bonus);
    }
    return 1;
}

int armour_remove()
{
    write("You find they cannot be removed.");
    return 0;
}

int query_auto_load()
{
    if (wizardp(this_player())) return 1;
    if(this_player()->query_level() < 75) return 0;
    return 1;
}
