
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Factol Erin Darkflame Montgomery") ;
    set ("long", "The Factol of the Sensates.\n") ;
    set ("id", ({ "factol", "erin", "darkflame", "montgomery"}) ) ;
    set_name ("erin") ;
    set ("gender", "female") ;
    enable_commands() ;
    set_living_name("erin") ;
    set ("stat/constitution", 13);
    set ("stat/strength", 9);
    set ("stat/charisma", 18);
    set ("stat/intelligence", 14);
    set ("stat/dexterity", 14);
    set ("stat/wisdom", 17);
    set("max_tp", 1000);
    set("theurgy_points", 500);
    set("priest_spells", ({  "flamestrike", "pin", "hold", "fear" }) );
    set("deity", "Diancecht");
    set("special", 5);
    set_level(9);
    set("natt", 1);
    set ("thac0", 16);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "priest");
    set_skill("Clubbing Weapons", 2, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(SIGIL+"items/crystalmace", "mace") ;
    wear(SIGIL+"items/greenchain", "chain") ;
    wear(SIGIL+"items/priest_ob", "priest_ob") ;
}

void special_attack() {
    //this is the spell function for raw excessive healing
    object ob;
    int sv; 
    string target;
    if (this_object()->query("invoke_delay") || this_object()->query("theurgy_points")<60) {
       return 0;
    }else{	

	if (!random(2)){
	    switch(random(5)){
	    case 0 : command("invoke pin");break;
	    case 1 : command("invoke hold");break;
	    case 2 : command("invoke fear");break;
	    case 3 : command("invoke flamestrike");break;


	    }
	}
	return 1;
    }
}
