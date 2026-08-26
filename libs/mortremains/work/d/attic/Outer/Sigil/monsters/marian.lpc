
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Black Marian") ;
	set ("long", "This is Possibly the greatest singer in all Sigil.\n") ;
	set ("id", ({ "black marian", "black", "marian" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_name ("marian") ;
	set("gender", "female");
	enable_commands() ;
   	set_living_name("marian") ;
	set ("stat/constitution", 11);
	set ("stat/strength", 10);
	set ("stat/charisma", 16);
	set ("stat/intelligence", 13);
	set ("stat/dexterity", 12);
	set ("stat/wisdom", 16);
	set("special", 1);
	set("max_tp", 50);
set("theurgy_points", 50);
set("priest_spells", ({ "pin" }) );
set("deity", "Lathander");
	set_level(5);
	set("level", 5);
	set("natt", 1);
	set ("thac0", 17);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "priest");
	set_skill("Clubbing Weapons", 2, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
   arm(OBJ(disruptionmace), "mace") ;
   wear(OBJ(priest_ob), "hi") ;
	}
void special_attack() {
	//this is the spell function for raw excessive healing
object ob;
int sv; 
string target;
if (this_object()->query("invoke_delay") || this_object()->query("theurgy_points")<20) {
	return 0;
}else{	
  if(!random(4)) command("invoke pin");
 }
 return 0;
}
