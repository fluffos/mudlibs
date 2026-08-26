
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Zadara") ;
    set ("long", "Zadara does what she likes cause she is titanic.\n") ;
    set ("id", ({ "titan", "zadara" }) ) ;
    set ("capacity", 10000) ;
    set ("max_cap", 10000) ;
    set ("max_vol", 10000) ;
    set ("volume", 10000) ;
    set ("mass", 3000) ;
    set ("bulk", 250) ;
    set_size(20);
    set("race", "titan");
    set_name ("zadara") ;
    set ("gender", "female") ;
    enable_commands() ;
    set_living_name("zadara") ;
    set_level(20);
    set("stat/constitution", 25);
    set ("stat/strength", 25);
    set ("stat/charisma", 18);
    set ("stat/intelligence", 17);
    set ("stat/dexterity", 17);
    set ("stat/wisdom", 20);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "claws") ;
    set_skill("Clubbing Weapons", 1, "Strength");
    set ("thac0", 1);
    set("CLASS", "priest");
    set("max_tp", 200);
    set("theurgy_points", 200);
    set("priest_spells", ({ "greaterheal" }) );
    set("deity", "The Titan God");
    set ("natt", 1);
    set ("level", 20);
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(OBJ(titanmaul), "maul") ;
    clone_object(OBJ(priest_ob))->move(TO);
    set("special", 2);
}

void init() {
    ::init();
    command("wield maul");
}

void special_attack() {
    //this is the spell function for raw excessive healing
    object ob;
    int sv; 
    string target;
    if (this_object()->query("invoke_delay") || this_object()->query("theurgy_points")<60) {
	return 0;
    }else{	
	if(this_object()->query("hit_points") < 300) return 0;
	command("invoke greaterheal");
    }
}
