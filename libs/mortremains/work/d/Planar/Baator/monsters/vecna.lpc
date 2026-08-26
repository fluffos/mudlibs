// Fixed by Cyanide - 11/26/1998 10:46:15 PM 

#include <mudlib.h>
inherit MONSTER ;

void create () {
    object ob1, ob2;

    ::create() ;
    seteuid(getuid()) ;
    set("author", "ilzarion");
    set ("short", "Vecna") ;
    set ("long", "The most terrible and foul necromancer ever.\n") ;
    set ("id", ({ "vecna", "lord", "lich"}) ) ;
    set_name ("vecna") ;
    set ("gender", "male") ;
    set ("race", "god");
    set ("undead", 1000);
    set_align("le");
    enable_commands() ;
    set("stat", ([
      "strength" : 25,
      "constitution" : 25,
      "dexterity" : 25,
      "intelligence" : 25,
      "wisdom" : 25,
      "charisma" : 25
    ]) );
    set_living_name("vecna") ;
    set_size(6);
    set ("thac0", 1);
    set ("base_ac", -10);
    set ("armor_class", -10);
    set ("damage", ({ 4,40 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "wizard");
    set ("weap_resist", 6);
    set ("magic_resist", 140);
    set ("mage_spells", ({ "stoneskin", "fireshield", "swarm", 
      "timestop",  "disjunction", "wilting", "prismsphere",
      "deadlyaim", "mordsword", "tellblow", "wilting", "kill",
      "finger", "disintegrate", "imprison", "enlarge" }) );
    set ("max_sp", 5000);
    set ("spell_points", 5000);
    set ("resist_type", ([ "cold" : 0, "poison" : 0, "electricity" : 0, "necromancy" : -100 ]) );
    set_verbs( ({ "slash at", "swing at", "swipe at" }) ) ;
    set_skill("Short Blades", 2, "Strength");
    set_skill("Unarmed", 3, "Strength");
    set_skill("One Weapon Style", 2, "Strength");
    ob1 = clone_object ("/d/class/wizard/general/obj/book") ;
    ob1 -> move (this_object()) ;
    set("prevent_summon", 1);
    set ("special", 50);
    set_level(40);
    set("wealth", 100000);
}


void special_attack() {
    //this is the vecna spell function 
    object ob;
    int sv; 
    string target;
    if (this_object()->query("power_delay") || this_object()->query("spell_points")<120) {
	return 0;
    }else{	

	ob = (present("#FIRE_SHIELD#", this_object()));
	if (ob){
	    switch (random(5)){
	    case 0 : command("cast timestop");
		this_object()->delete("power_delay");
		this_object()->delete("stop_attack");
		command("cast swarm at "+(query_current_attacker())->query("name"));break;
	    case 1 : command("cast mordsword");
		command("wield sword");
		this_object()->delete("power_delay");
		this_object()->delete("stop_attack");
		command("cast enlarge");break;
	    case 2 : command("cast tellblow");
		this_object()->delete("power_delay");
		this_object()->delete("stop_attack");
		command("cast kill");break;
	    case 3 : command("cast disjunction");
		this_object()->delete("power_delay");
		this_object()->delete("stop_attack");
		command("cast imprison");break;
	    case 4 : command("cast prismsphere");
		this_object()->delete("power_delay");
		this_object()->delete("stop_attack");
		command("cast finger");break;
	    }
	}else{
	    command("cast fireshield hot");
	    this_object()->delete("power_delay"); 
	    this_object()->delete("stop_attack"); 
	    command("cast stoneskin");
	}

    }
}
