/* Official Guard Sergeant */

/* Use Base guard */
#include "cityguard.h"
#include <servers.h>
#include "../DEFS.h"

create_guard()
{
    object ob;
    string n;

    n = (string) NAMEGEN_C -> random_name();
    set_name(n);
    n = capitalize(n);
    set_id(({"city_guard", "sergeant"}));
    set_race("guard");
    set_group("cityguard");
    set(NPC_SET_PK_FLAG, 1);
    set_short(n + " the guard sergeant");

    gender = 1 + random(2);

    set_long(n + " is one of the City Guard Sergeants. " +
      capitalize(Pronoun())+" is here to protect the innocent.");
    set_level(12 + random(7));
    /* set_wander(7); */
    set_hp(400 + level * 20);
    money = random(level * 5) + 50;
    set_alignment(29 + random(300));

    if (random(100) < 30)
    {
	ob = WEAPON_SERVER->make_weapon("two handed sword");
	ob->set_long(
	  "An excellent sword, favoured by the City Guard Sergeants.");
	move_object(ob, this_object());
	wield(ob);
    }

    if (random(100) < 30)
    {
	ob = ARMOUR_SERVER->make_armour("banded breastplate");
	ob->set_long(
	  "A banded breastplate marked with the City Guard's insignia.");
	move_object(ob, this_object());
	wear(ob);
    }

    if (random(100) < 30)
    {
	ob = ARMOUR_SERVER->make_armour("plated helmet");
	ob->set_long("A helmet marked with the City Guard's insignia.");
	move_object(ob, this_object());
	wear(ob);
    }

    set_wc(60, 1);
    set_ac(60, 1);
}
