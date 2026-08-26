
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Saure") ;
	set ("long", "A corpse - eating non-believer.\n") ;
	set ("id", ({ "saure", "athar"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 100) ;
      	set_name ("saure") ;
	set ("gender", "female") ;
	enable_commands() ;
	set("race", "gautiere");
   	set_living_name("saure") ;
	set_level(5);
	set("level", 5);
	set("natt", 1);
	set ("thac0", 17);
	set ("stat/constitution", 19);
	set ("stat/strength", 19);
	set ("stat/charisma", 20);
	set ("stat/intelligence", 15);
	set ("stat/dexterity", 15);
	set ("stat/wisdom", 13);
	set ("damage", ({ 3,18 }) ) ;
	set ("weapon_name", "acidic claws") ;
	set ("damage_type", "slashing");
	set ("armor_class", 6);
	set ("base_ac", 1);
	set ("CLASS", "warrior");
		set_verbs( ({ "slash", "scratch", "poke" }) ) ;
	set ("resist_type", ([ "acid" : 0, "fire" : 0 ]) );
}
