/* Mega-tough bastard! A guard captain! */

/* Use Base guard */
#include "cityguard.h"
#include "../DEFS.h"

#include <generic_items.h>
#include <servers.h>

void
create_guard()
{
    object ob;
    string n;

    n = (string) NAMEGEN_C -> random_name();
    set_name(n);
    n = capitalize(n);
    set_id(({ "city_guard", "captain" }));
    set_race("guard");
    set(NPC_SET_PK_FLAG, 1);
    set_group("cityguard");
    set_short(n + " the guard captain");

    gender=random(3);

    set_long(n + " is one of the elite City Guard Captains. " +
      capitalize(Pronoun())+" is here to protect the innocent.");
    set_level(30 + random(8));
    /*   set_wander(7); */
    set_hp(600 + level * 20);
    set_money(random(level * 40));
    set_alignment(100 + random(800));

    if (random(100) < 45)
    {
	ob = WEAPON_SERVER->make_weapon("heavy bastard sword");
	ob->set_short("Guard Captain's heavy bastard sword");
	ob->set_long(
	  "An truly excellent sword of a City Guard Captain.");
	move_object(ob, this_object());
	wield(ob);
    }

    if (random(100) < 45)
    {
	ob = ARMOUR_SERVER->make_armour("plated breastplate");
	ob->set_short("Guard Captain's plated breastplate");
	ob->set_long(
	  "A plated breastplate marked with Guard Captain's insignia.");
	move_object(ob, this_object());
	wear(ob);
    }

    if (random(100) < 45)
    {
	ob = ARMOUR_SERVER->make_armour("mithril helmet");
	ob->set_short("Guard Captain's mithril helmet");
	ob->set_long("A helmet marked with Guard Captain's insignia.");
	move_object(ob, this_object());
	wear(ob);
    }

    if (random(100) < 45)
    {
	ob = ARMOUR_SERVER->make_armour("plate mail leggings");
	ob->set_short("Guard Captain's plate mail leggings");
	ob->set_long("Very fine leggings marked with Guard Captain's insignia.");
	move_object(ob, this_object());
	wear(ob);
    }

    if (random(100) < 45)
    {
	ob = ARMOUR_SERVER->make_armour("plate mail bracers");
	ob->set_short("Guard Captain's plate mail bracers");
	ob->set_long(
	  "Very fine bracers marked with Guard Captain's insignia.");
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

    set_ac(100, 1);
    set_wc(70, 1);
}
