
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Ylem") ;
	set ("long", "A modron dabbler in magic.\n");
	set ("id", ({ "ylem", "modron"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("ylem") ;
	set ("gender", "male") ;
	set ("race", "modron");
	enable_commands() ;
   	set_living_name("ylem") ;
   	set ("stat/constitution", 11);
	set ("stat/strength", 9);
	set ("stat/charisma", 10);
	set ("stat/intelligence", 15);
	set ("stat/dexterity", 12);
	set ("stat/wisdom", 12);
	set_level(5);
	set ("size", 4);
   	set ("SIZE", 4);
	set("level", 5);
	set("natt", 1);
	set ("thac0", 19);
	set ("base_ac", 8);
	set ("armor_class", 8);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "wizard");
	set ("mage_spells", ({ "missile", "bolt", "shield" }) );
	set ("max_sp", 45);
	set ("spell_points", 45);
	set_verbs( ({ "slash at", "swing at", "swipe at" }) ) ;
  clone_object("/d/class/wizard/general/obj/book") -> move(TO) ;
	set ("special", 1);
	}
void init(){
::init();
command ("cast shield");
}
	
	
void special_attack() {
	//this is the spell function for raw excessive damage
object ob;
int sv; 
string target;
if (this_object()->query("cast_delay") || (this_object()->query("spell_points") < 3) ){
		return;
		}else{	 
switch (random(2)){
	case 0 : command("cast missile");break;
	case 1 : command("cast bolt");break;
	}
}
}
