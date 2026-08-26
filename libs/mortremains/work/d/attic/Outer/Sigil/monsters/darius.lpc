// Ilz created this.

#include "../sigil.h"

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Factol Darius") ;
    set ("long", "The Factol of the Sign of One.\n") ;
    set ("id", ({ "factol", "darius"}) ) ;
    set_name ("darius") ;
    set_align("tn");
    set ("gender", "female") ;
    enable_commands() ;
    set_living_name("darius") ;
    set ("stat/constitution", 14);
    set ("stat/strength", 10);
    set ("stat/charisma", 16);
    set ("stat/intelligence", 17);
    set ("stat/dexterity", 12);
    set ("stat/wisdom", 16);
    set ("special", 5);
    set("wealth", random(12000));
    set ("spell_points", 310);
    set ("mage_spells", ({ "stoneskin", "lightning", "bolt", "missile",
      "feeblemind", "fireshield" }) );
    set("natt", 1);
    set ("thac0", 17);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "wizard");
    set_skill("Short Blades", 1, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    wear("/d/class/wizard/general/obj/book", "book");
    arm(SIGIL+"items/greendagger", "dagger") ;
    wear(SIGIL+"items/protpendant", "pendant") ;
    set_level(11);
}
void init () {
    ::init();
    command("cast stoneskin");
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
		case 2 : command("cast lightning at "+(this_object()->query_current_attacker())->query("name"));break;
		}
	    }else{
		command("cast fireshield");
	    }
	}else{
	    command("cast stoneskin");
	}
    }
}
