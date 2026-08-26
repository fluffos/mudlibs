// Ilz did this.
// Cy cleaned up.

#include <mudlib.h>
#include "defs.h"
inherit MONSTER ;

void create () {
	::create() ;
	seteuid(getuid()) ;
	set ("short", "Factol Alisohn Nilesia") ;
	set ("long", "The Factol of the Mercykillers.\n") ;
	set ("id", ({ "factol", "alisohn", "nilesia"}) ) ;
	set_name ("alisohn") ;
	set ("gender", "female") ;
	enable_commands() ;
   	set_living_name("alisohn") ;
	set ("stat/constitution", 13);
	set ("stat/strength", 10);
	set ("stat/charisma", 17);
	set ("stat/intelligence", 19);
	set ("stat/dexterity", 16);
	set ("stat/wisdom", 12);
	set("natt", 1);
	set ("thac0", 18);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "wizard");
	set_skill("Short Blades", 2, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
  	set ("mage_spells", ({ "missile", "bolt", "shield", 
  	    "fireshield", "enlarge" }) );
    arm(OBJ(greendagger), "dagger") ;
    wear(OBJ(robe4), "robe") ;
    wear("/d/class/wizard/general/obj/book", "book") ; // we arent gonna wear this.
	set ("max_sp", 200);
	set ("spell_points", 200);
	set ("special", 4);
	set_level(8);
	set("wealth", 550);
}
	
void special_attack() {
	//this is the spell function for raw excessive damage

    if (query("power_delay") || ((int)query("spell_points") < 3) ) {
        return;
	}else{	 
		if (!present("#ENLARGE_OB#", this_object())){
            command ("cast enlarge");
		    return;
		}
	    if (!present("#FIRE_SHIELD#", this_object())){
            command ("cast fireshield hot");
	        return;
	    }
		if (!present("#SHIELD_SPELL#", this_object())){
	        command ("cast shield");
	        return;
	    }

        switch (random(3)){
        	case 0 : command("cast missile");break;
        	default : command("cast bolt");break;
    	}
    }

    return;
}

varargs int query_level(string str) { return 8; }

/* EOF */