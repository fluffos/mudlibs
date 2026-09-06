#include <equipped_group_npc.h>
#include "/areas/tristeza/DEFS.h"

void
create_monster()
{
    string tmp;
    tmp = (string) (NAMEGEN_C)->random_orc_name();
    set_name(tmp);
    set_id(({ "bvl_guard", "guard" }));
    set_race("half-ogre");
    set_short(capitalize(tmp) + " the Guard");
    set_long(capitalize(tmp) + " " +
      "is an extremely tough and skilled guard of Half-Ogrish blood.");
    set_level(40);
    set_hp(1460 + random(200));
    set_money(50 + random(151));
    set_alignment(AL_NASTY);
    set_gender(random(3));
    set_group("bvl_guards");	// Let's make these be a group.
    add_weapon("heavy bastard sword","heavy bastard sword",0,3,
      "Guard takes the heavy bastard sword.");
    add_armour("plated breastplate","plated breastplate",0,4,
      "Guard takes the plated breastplate.");
    set_wc(30);
    set_ac(20);
    set_ep(1500000);
}

