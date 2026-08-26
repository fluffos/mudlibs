
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Kesto Brighteyes") ;
	set ("long", "The shopkeeper of the parted veil bookstore.\n") ;
	set ("id", ({ "kesto", "brighteyes"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("kesto") ;
	set ("race", "gnome");
		set ("gender", "male") ;
	enable_commands() ;
   	set_living_name("kesto") ;
	set ("stat/constitution", 12);
	set ("stat/strength", 8);
	set ("stat/charisma", 10);
	set ("stat/intelligence", 14);
	set ("stat/dexterity", 16);
	set ("stat/wisdom", 9);
	set_level(12);
	set("level", 12);
	set("natt", 1);
	set ("thac0", 13);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "wizard");
	set_skill("Short Blades", 2, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
  arm(OBJ(dagger2), "dagger") ;
  wear(OBJ(ring2), "ring") ;
   	   	}
void init () {
::init();
command("wield dagger");
command("equip ring");
}
