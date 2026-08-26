
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Factol Skall") ;
    set ("long", "The Factol of the Dustmen.\n") ;
    set ("id", ({ "factol", "skall", "lich"}) ) ;
    set ("capacity", 10000) ;
    set ("max_cap", 10000) ;
    set ("max_vol", 10000) ;
    set ("volume", 200) ;
    set ("mass", 300) ;
    set ("bulk", 250) ;
    set_name ("skall") ;
    set ("gender", "male") ;
    set ("race", "lich");
    enable_commands() ;
    set_living_name("skall") ;
    set ("race", "lich");
    set ("stat/constitution", 20);
    set ("stat/strength", 12);
    set ("stat/charisma", 10);
    set ("stat/intelligence", 20);
    set ("stat/dexterity", 11);
    set ("stat/wisdom", 20);
    set ("special", 15);
    set ("wealth", 40000);
    set ("spell_points", 900);
    set("max_sp", 900);
    set ("mage_spells", ({ "stoneskin", "lightning", "bolt", "missile",
      "feeblemind", "fireshield", "globe", "swarm",  "finger", "prism", "disjunction" }) );
    set("natt", 1);
    set("undead", 1);
    set("weap_resist", 1);
    set("resist_type",([ "cold":0, "necromancy":-100, "electrical":0]));
    set ("thac0", 5);
    set ("damage", ({ 3,30 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "wizard");
    set("base_ac", 1);
    set_level(19);
    set("level", 19);
    set_skill("Short Blades", 2, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    wear(OBJ(bracers0), "bracers") ;
    clone_object("/d/class/wizard/general/obj/book")->move(TO) ;
}
void init () {
    ::init();
    command("cast stoneskin");
}
void heart_beat() {
    ::heart_beat();
    if (this_object()->query("hit_points") < this_object()->query("max_hp")){
	this_object()->set("hit_points", (int)query("hit_points")+5);
    }
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
		ob = (present("#GLOBE#", this_object()));
		if (ob){
		    command("say Now you will pay for your insolence!");
		    switch (random(5)){
		    case 0 : command("cast swarm at "+(this_object()->query_current_attacker())->query("name"));break;
		    case 1 : command("cast prism at "+(this_object()->query_current_attacker())->query("name"));break;
		    case 2 : command("cast finger at "+(this_object()->query_current_attacker())->query("name"));break;
		    case 3 : command("cast feeblemind at "+(this_object()->query_current_attacker())->query("name"));break;
		    case 4 : command("cast disjunction");break;
		    }
		}else{
		    command("cast globe");
		}
	    }else{
		command("cast fireshield cold");
	    }
	}else{
	    command("cast stoneskin");
	}
    }
}
