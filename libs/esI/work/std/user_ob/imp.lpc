// This is the actual user object. All default functions are defined in
// /std/user.c. Only those varies with races are redefined here. The
// inheriting relations are:
//
//   misc... -> body.c -> living.c -> user.c -> human.c ( for example.)
//
// This extension is started by Annihilator Aug 17, 1994.

#include <mudlib.h>

inherit USER;
inherit "/std/races/imp";

void consistency_check()
{
	// Do common check first.
	user::consistency_check();

	// Setup extra properties for Race Imp.
	imp::setup_race_body();
}


void calc_weapon_class()
{
        object ob;
        string type;

        ::calc_weapon_class();
        ob = query("weapon1");

        if( ob ) {
		type = (string)ob->query("type");
		if( type=="axe" || type =="blunt" ) {
			add("weapon_class1", -(int)ob->query("weapon_class") / 5);
			add("max_damage1", -(int)ob->query("max_damage") / 5);
		}
		else 
		if ( type == "dagger" ) {
			add("weapon_class1", (int)ob->query("weapon_class") * query_level() / 125);
			add("max_damage1", (int)ob->query("max_damage") * query_level() / 125);
		}
	}
}
