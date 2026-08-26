
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Shemeshka the Marauder") ;
set("long", "The much Feared queen of cross-trade.\n"+
"She glows withmultiple magical protections.\n");
	set ("id", ({ "demon", "shemeshka", "marauder" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("shemeshka") ;
	set ("gender", "female") ;
	enable_commands() ;
	set ("race", "yugoloth");
   	set_living_name("shemeshka") ;
	set ("stat/constitution", 16);
	set ("stat/strength", 18);
	set ("stat/charisma", 18);
	set ("stat/intelligence", 19);
	set ("stat/dexterity", 11);
	set ("stat/wisdom", 20);
	set ("special", 7);
	set ("wealth", 20000);
set("spell_points", 500);
set("max_sp", 500);
	set ("mage_spells", ({ "stoneskin", "lightning", "bolt", "missile",
	 "feeblemind", "fireshield", "globe", "finger", "prism", "disjunction" }) );
		set("natt", 3);
	set ("thac0", 9);
// instead of casting em, i give her ac + blur, armor, and shield
set("armor_class", -16);
set("base_ac", -16);
	set ("damage", ({ 1,6 }) ) ;
	set ("weapon_name", "claws") ;
	set ("CLASS", "wizard");
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	set ("resist_type", ([ "cold" : 200, "poison" : 0, "fire" : 0, "acid" : 0 ]) );
	set ("weap_resist", 3);
	set ("magic_resist", 60);
	set_level(14);
	set("level", 14);
  clone_object("/d/class/wizard/general/obj/book")->move(TO) ;
   	}
void special_attack() {
	//this is the spell function for raw excessive damage
object ob;
int sv; 
string target;
if (this_object()->query("cast_delay") || this_object()->query("spell_points")<80) {
	return 0;
}else{	
 ob = (present("#STONESKIN#", this_object()));
if ( (ob) || (this_object()->query("wealth") < 1000)){
ob = (present("#FIRE_SHIELD#", this_object()));
if (ob){
switch (random(3)){
	case 0 : command("cast bolt at "+(this_object()->query_current_attacker())->query("name"));break;
	case 1 : command("cast missile at "+(this_object()->query_current_attacker())->query("name"));break;
	case 2 : command("cast prism at "+(this_object()->query_current_attacker())->query("name"));break;
	}
	}else{
	command("cast fireshield");
	}
	}else{
	command("cast stoneskin");
}
}
}
