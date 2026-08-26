
//Ilz

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Sly Nye") ;
	set ("long", "A chaotic lawman.\n") ;
	set ("id", ({ "sly", "nye", "sly nye",  "tiefling" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_name ("nye") ;
	set ("gender", "male") ;
	set ("race", "tiefling");
	enable_commands() ;
   	set_living_name("nye") ;
	set ("stat/constitution", 9);
	set ("stat/strength", 8);
	set ("stat/charisma", 18);
	set ("stat/intelligence", 17);
	set ("stat/dexterity", 15);
	set ("stat/wisdom", 10);
	set_level(4);
	set("level", 4);
	set ("thac0", 19);
	set ("damage", ({ 1,6 }) ) ;
	set ("weapon_name", "claws") ;
	set ("CLASS", "thief");
	set_skill("Short Blades", 1, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
   arm(OBJ(greendagger), "dagger") ;
  wear(OBJ(bracers7), "bracers") ;
   	}
