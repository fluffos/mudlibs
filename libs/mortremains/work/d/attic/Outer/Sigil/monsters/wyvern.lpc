
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
seteuid(getuid()) ;
	set ("short", "Wyvern") ;
	set ("long", "A flying lizard with a poisonous tail.\n") ;
	set ("id", ({ "wyvern",  "lizard" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_name ("wyvern") ;
	set ("race", "dragon");
	set ("gender", "male") ;
	enable_commands() ;
   	   	set_living_name("wyvern") ;
	set("resist_type",([  "poison":0]));
	set ("base_ac", 3);
	set ("armor_class", 3);
	set("natt", 1);
	set("CLASS", "warrior");
	set("damage_type", "slashing");
	set ("damage", ({ 2,16 }) ) ;
	set ("weapon_name", "bite") ;
	set_verbs( ({ "rip", "slash at", "lunge at" }) ) ;
	set ("special", 1);
        set_level(8);   
	}

	
void special_attack() {
	//this is the spell function for raw excessive damage
object ob;
int sv; 
string target;

 ob = query_current_attacker();
if (this_object()->query_hit(ob)) {	
	if (!ob->save_throw()){	
		  	ob->receive_damage(((random(25)+26)), "poison");
		tell_object(ob, "You are poisoned by the wyvern's stinger!\n");
	return;
	}
ob->receive_damage(((random(6)+1)), "piercing");
		tell_object(ob, "You are stung by the wyvern's tail!\n");
                say("The wyvern stings "+ob->query("cap_name")+"!\n", ({ ob }) );
	return;
	}
	tell_object(ob, "The wyvern misses you with it's stinger!\n");
		say("The wyvern misses "+ob->query("cap_name")+" with it's stinger!\n");
	return;
	}
