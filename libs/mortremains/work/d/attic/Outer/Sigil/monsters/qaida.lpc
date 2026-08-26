
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Qaida") ;
    set ("long", "An Evil priestess of death.\n") ;
    set ("id", ({ "qaida", "dustman"}) ) ;
    set_name ("qaida") ;
    set_size(6);
    set ("gender", "female") ;
    enable_commands() ;
    set("race", "aasimar");
    set_living_name("qaida") ;
    set("max_tp", 500);
    set("theurgy_points", 500);
    set("priest_spells", ({  "flamestrike", "pin", "fear", "sunscorch" }) );
    set("deity", "arawn");
    set("special", 5);
    set ("magic_resist", 25);
    set ("resist_type", ([ "cold" : 50, "fire" : 50 ]) );
    set_level(8);
    set("level", 8);
    set("natt", 1);
    set ("thac0", 13);
    set ("stat/constitution", 11);
    set ("stat/strength", 12);
    set ("stat/charisma", 16);
    set ("stat/intelligence", 14);
    set ("stat/dexterity", 15);
    set ("stat/wisdom", 15);
    set ("damage", ({ 1,6 }) ) ;
    set ("weapon_name", "claws") ;
    set ("damage_type", "slashing");
    set ("CLASS", "priest");
    set_skill("Polearms", 2, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(OBJ(flamescythe), "scythe") ;
    wear(OBJ(robeofeyes), "robe") ;
    wear(OBJ(priest_ob), "hi") ;
}
void init () {
    ::init();
    command("wield scythe");
    //command("equip robes");
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
	return 0;
    }
}
