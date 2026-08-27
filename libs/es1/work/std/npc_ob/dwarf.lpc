// This is the actual user object. All default functions are defined in
// /std/user.c. Only those varies with races are redefined here. The
// inheriting relations are:
//
//   misc... -> body.c -> living.c -> npc.c -> monster.c ( for example.)
//
// This extension is started by Annihilator Aug 17, 1994.

#include <mudlib.h>

inherit NPC;
inherit "/std/races/dwarf";

void create()
{
	npc::create();

	// Setup extra properties for Race Dwarf.
	dwarf::setup_race_body();
}
