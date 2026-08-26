
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Factol Rhys") ;
    set ("long", "The Factol of the Transcendant Order.\n") ;
    set ("id", ({ "factol", "rhys"}) ) ;
    set_name ("rhys") ;
    set ("gender", "female") ;
    enable_commands() ;
    set_living_name("rhys") ;
    set ("stat/constitution", 15);
    set ("stat/strength", 17);
    set ("stat/charisma", 18);
    set ("stat/intelligence", 17);
    set ("stat/dexterity", 18);
    set ("stat/wisdom", 12);
    set_level(30);
    set("level", 15);
    set ("thac0", 6);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "wizard");
    set ("spell_points", 410);
    set("max_sp", 410);
    set ("mage_spells", ({ "stoneskin", "coldcone", "bolt", "missile", "haste" }) );
    set_skill("Staves", 4, "Strength") ;
    set_skill("Two Handed Style", 2, "Strength");
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    set ("special", 1);
    set ("wealth", 10000);
    arm(OBJ(magistaff), "staff") ;
    wear("/d/class/wizard/general/obj/book", "hi") ;
    wear(OBJ(archmagirobe), "robe") ;
}

void init() {
    command("cast stoneskin");
    set("power_delay", 0);
}

void special_attack() {
    //this is the spell function for raw excessive damage
    object ob;
    int sv; 
    string target;
    if (this_object()->query("cast_delay") || this_object()->query("spell_points")<80) {
	return 0;
	if (!random(2)) return 0;
    }else{	
	ob = (present("#STONESKIN#", this_object()));
	if ( (ob) || (this_object()->query("wealth") < 1000)){

	    ob = (present("#HASTE#", this_object()));
	    if (ob){
		switch (random(3)){
		case 0 : command("cast bolt");
		case 1 : command("cast missile");
		case 2 : command("cast coldcone");
		}
	    }else{
		command("cast haste");
	    }
	}else{
	    command("cast stoneskin");
	}
    }
}
