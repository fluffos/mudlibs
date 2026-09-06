/* Official Guard Lieutenant */

/* Use Base guard */
#include "cityguard.h"
#include <generic_items.h>

#include "../DEFS.h"

#include <servers.h>

void
create_guard()
{
    object ob;
    string n;

    n = (string) NAMEGEN_C -> random_name();
    set_name(n);
    n = capitalize(n);
    set_id(({"city_guard","lieutenant"}));
    set(NPC_SET_PK_FLAG, 1);
    set_group("cityguard");
    set_race("guard");
    set_short(n + " the guard lieutenant");

    gender=random(3);

    set_long(
      n + " is one of the few City Guard Lieutenants. "+
      capitalize(Pronoun())+" is here to protect the innocent.");
    set_level(20 + random(5));
    /*   set_wander(7); */
    set_hp(400 + level * 20);
    money = level * 25 + random(100) + 199;
    set_alignment(399 + random(800));

    if (random(100) < 40)
    {
	ob = WEAPON_SERVER->make_weapon("heavy bastard sword");
	ob->set_long(
	  "An excellent sword, favoured by the City Guard Lieutenants.");
	move_object(ob, this_object());
	wield(ob);
    }

    if (random(100) < 40)
    {
	ob = ARMOUR_SERVER->make_armour("plated breastplate");
	ob->set_long(
	  "A plated breastplate marked with the City Guard's insignia.");
	move_object(ob, this_object());
	wear(ob);
    }

    if (random(100) < 40)
    {
	ob = ARMOUR_SERVER->make_armour("mithril helmet");
	ob->set_long(
	  "A helmet marked with the City Guard's insignia.");
	move_object(ob, this_object());
	wear(ob);
    }

    if (random(100) < 40)
    {
	ob = ARMOUR_SERVER->make_armour("plate mail leggings");
	ob->set_long(
	  "Very fine leggings marked with the City Guard's insignia.");
	move_object(ob, this_object());
	wear(ob);
    }

    if (random(100) < 40)
    {
	ob = ARMOUR_SERVER->make_armour("plate mail bracers");
	ob->set_long(
	  "Very fine bracers marked with the City Guard's insignia.\n");
	move_object(ob, this_object());
	wear(ob);
    }

    /* The Shadow Cloak - an item coveted especially by thieves. */
    /* Doesn't exist all the time. */
    if (random(100) < 85) {
	ob = clone_object(GENERIC_SHADOW_CLOAK);
	move_object(ob, this_object());
	wear(ob);
    }

    set_wc(60, 1);
    set_ac(70, 1);
}
