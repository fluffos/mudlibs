#include <mudlib.h>
inherit MONSTER ;


void create () {
    object ob1;

    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Molikroth") ;
    set ("long", "The Powerful Lord of the Eighth Hell.\n"+
      "The Baron of Cania, the eighth layer of Baator.\n"+
      "Sheer power Radiates from his huge frame.\n") ;
    set ("id", ({ "molikroth", "lord", "baatezu"}) ) ;
    set_name ("molikroth") ;
    set ("gender", "male") ;
    set ("race", "baatezu");
    enable_commands() ;
    set_living_name("molikroth") ;
    set ("stat/constitution", 17);
    set ("stat/strength", 21);
    set ("stat/charisma", 15);
    set ("stat/intelligence", 23);
    set ("stat/dexterity", 18);
    set ("stat/wisdom", 22);
    set_size(8);
    set("level", 40);
    set("natt", 1);
    set ("thac0", 6);
    set ("base_ac", 1);
    set ("armor_class", 1);
    set ("damage", ({ 1,5 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "wizard");
    set ("weap_resist", 4);
    set ("magic_resist", 80);
    set ("mage_spells", ({ "stoneskin", "fireshield", "swarm", "bolt",  "disjunction", "wilting", "globe" }) );
    set ("max_sp", 2000);
    set ("spell_points", 2000);
    set ("resist_type", ([ "cold" : 0, "poison" : 0, "fire" : 0 ]) );
    set_verbs( ({ "slash at", "swing at", "swipe at" }) ) ;
    ob1 = clone_object ("/d/class/wizard/general/obj/book") ;
    ob1->set("invisible", 1);
    ob1 -> move (this_object()) ;
    set ("special", 19);
    set_level(40);
    set("wealth", 60000);
}
void init(){
    ::init();
    command ("cast stoneskin");
}


void special_attack() {
    //this is the spell function for raw excessive damage
    int sv; 
    string target;
    object ob;

    if (this_object()->query("power_delay") || this_object()->query("spell_points")<80) {
	return 0;
    }else{	
	ob = (present("#STONESKIN#", this_object()));
	if ( (ob) || (this_object()->query("wealth") < 1000)){
	    ob = (present("#FIRE_SHIELD#", this_object()));
	    if (ob){
		ob = (present("#GLOBE#", this_object()));
		if (ob){
		    switch (random(4)){
		    case 0 : command("cast bolt at "+(this_object()->query_current_attacker())->query("name"));break;
		    case 1 : command("cast swarm at "+(this_object()->query_current_attacker())->query("name"));break;
		    case 2 : command("cast wilting at "+(this_object()->query_current_attacker())->query("name"));break;
		    case 3 : command("cast disjunction");break;
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
