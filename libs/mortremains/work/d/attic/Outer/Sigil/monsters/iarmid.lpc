// Iarmid - the master of the baths n Sigil.

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;

void create () {
	::create() ;
	seteuid(getuid()) ;
	set ("short", "Iarmid") ;
	set ("long", wrap("Iarmid is reknowned far and wide for his "+
	  "abilities as a masseuse, and it is said that he could relax "+
	  "a tanar'ri, if one would let him close enough.\nIarmid has "+
	  "silverish skin, and snow white hair which betray his "+
	  "half-human, half angelic parentage.") );
	set ("id", ({ "iarmid", "aasimar"}) ) ;
	set_name ("iarmid") ;
	set ("gender", "male") ;
	set ("race", "aasimar");
	enable_commands() ;
   	set_living_name("iarmid") ;
	set ("stat/constitution", 12);
	set ("stat/strength", 16);
	set ("stat/charisma", 7);
	set ("stat/intelligence", 14);
	set ("stat/dexterity", 16);
	set ("stat/wisdom", 16);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	set ("resist_type", ([ "cold" : 50,  "fire" : 50]) );
	set_skill("Staves", 2, "Strength") ;
	set_skill("Two Handed Style", 2, "Strength");
	set ("magic_resist", 10);
	set_verbs( ({ "slash at", "swing at", "swipe at" }) ) ;
	set_level(6);
	arm("/obj/weapon/staff", "staff") ;
  	wear(OBJ(cloak1), "cloak");
}

/* EOF */
