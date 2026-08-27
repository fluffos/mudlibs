// This is the actual user object. All default functions are defined in
// /std/user.c. Only those varies with races are redefined here. The
// inheriting relations are:
//
//   misc... -> body.c -> living.c -> user.c -> human.c ( for example.)
//
// This extension is started by Annihilator Aug 17, 1994.

#include <mudlib.h>

inherit USER;
inherit "/std/races/human";

void consistency_check()
{
	// Do common check first.
	user::consistency_check();

	// Setup extra properties for Race Human.
	human::setup_race_body();
}

int gain_experience(int i)
{
	i *= ( 1 + query_level()/200 );
	user::gain_experience(i);
}
