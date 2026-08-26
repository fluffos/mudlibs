
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Factol Terrance") ;
    set ("long", "The Factol of the Athar.\n") ;
    set ("id", ({ "factol", "terrance"}) ) ;
    set ("capacity", 10000) ;
    set ("max_cap", 10000) ;
    set ("max_vol", 10000) ;
    set ("volume", 200) ;
    set ("mass", 300) ;
    set ("bulk", 250) ;
    set_name ("terrance") ;
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("terrance") ;
    set ("stat/constitution", 12);
    set ("stat/strength", 13);
    set ("stat/charisma", 16);
    set ("stat/intelligence", 14);
    set ("stat/dexterity", 10);
    set ("stat/wisdom", 18);
    set("max_tp", 1000);
    set("theurgy_points", 1000);
    set("priest_spells", ({ "greaterheal", "entropyshield", "summonearth", "hold", "miscast", "aid" }) );
    set("deity", "Greater Unknown");
    set("special", 5);
    set_level(19);
    set("level", 19);
    set("natt", 1);
    set ("thac0", 8);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "priest");
    set_skill("Clubbing Weapons", 2, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(OBJ(hammer3), "hammer") ;
    wear(OBJ(cloak4), "cloak") ;
    clone_object(OBJ(priest_ob))->move(TO) ;
}

void special_attack() {
    //this is the spell function for raw excessive healing
    object ob;
    int sv; 
    string target;
    if (this_object()->query("invoke_delay") || this_object()->query("theurgy_points")<60) {
	return 0;
    }else{	
	if(this_object()->query("hit_points") < 300){ 
	    command("invoke greaterheal");
	}else{
	    if (!random(2)){
		switch(random(5)){
		case 0 : command("invoke miscast");break;
		case 1 : command("invoke hold");break;
		case 2 : command("invoke summonearth");break;
		case 3 : command("invoke entropyshield");break;
		case 4 : command("invoke aid");break;
		}
	    }
	}
	return 0;
    }
}
