
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {
  object ob2 ;


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Glabrezu") ;
	set ("long", "This is a powerful lower planar creature.\n") ;
	set ("id", ({ "glabrezu", "tanar'ri", "demon" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("glabrezu") ;
	set ("gender", "male") ;
	enable_commands() ;
	set ("race", "tanar'i");
   	set_living_name("glabrezu") ;
	set ("stat/constitution", 16);
	set ("stat/strength", 20);
	set ("stat/charisma", 18);
	set ("stat/intelligence", 19);
	set ("stat/dexterity", 11);
	set ("stat/wisdom", 20);
	set_level(10);
	set("level", 10);
	set("natt", 5);
	set ("thac0", 11);
	set ("armor_class", -7);
	set ("base_ac", -7);
	set ("damage", ({ 2,7 }) ) ;
	set ("weapon_name", "claws") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	set ("resist_type", ([ "cold" : 50, "poison" : 0, "fire" : 50, "electricity" : 0 ]) );
	set ("weap_resist", 2);
	set ("magic_resist", 60);
	set ("spell_points", 560);
	set ("mage_spells", ({ "stun" }) );
	ob2 = clone_object ("/d/class/wizard/general/obj/book") ;
    ob2 -> set("invisible", 1);
    ob2 -> move (this_object()) ; 
	set ("special", 1);
       	}

void init () {
::init();

command("protect skall");
}

void special_attack() {
	//this is the spell function for raw excessive damage
object ob, targ;
int sv; 
if (this_object()->query("cast_delay") || this_object()->query("spell_points")<80) {
	return 0;
}else{	
targ = (this_object()->query_current_attacker());
if (targ->query("stop_attack") || (targ->query("hit_points") > 270) ) return 1;

	command("cast stun");
}
	}
