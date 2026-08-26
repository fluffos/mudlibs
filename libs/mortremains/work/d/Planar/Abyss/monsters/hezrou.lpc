
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2 ;

	::create() ;
seteuid(getuid()) ;
	set ("short", "Hezrou") ;
	set ("long", "A roughly humaniod toad demon.\n") ;
	set ("id", ({ "hezrou", "tanar'ri" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_size(7);
	set_name ("hezrou") ;
	set ("race", "tanar'ri");
	set ("gender", "male") ;
	enable_commands() ;
   	   	set_living_name("hezrou") ;
	set("resist_type",([ "slashing":50, "piercing":50, "bludgeoning":50, "cold":50, "fire":50, "poison":0, "electricity":0]));
	set("magic_resist", 70);
	set("weap_resist", 2);
	set_level(9);
//	set("stat/strength", 20);
	set ("base_ac", -6);
	set ("armor_class", -6);
	set("natt", 2);
	set("CLASS", "warrior");
	set ("damage", ({ 1,6 }) ) ;
	set ("weapon_name", "claws") ;
	set("special", 5);
  
   	}

void special_attack() {
	//this is the spell function for raw excessive damage
object ob;
int sv; 
string target;

 ob = query_current_attacker();
if (!ob->query_save()){
	ob->block_attack(1);
	tell_object(ob, "you gag from the stench of the hezrou!\n");
		say(ob->query("cap_name")+" gags from the stench!\n");
		}
if (this_object()->query_hit(ob)) {	

ob->receive_damage(((random(12)+5)), "piercing");
		tell_object(ob, "the hezrou bites you!\n");
		say("The hezrou bites "+ob->query("cap_name")+"!\n");
	return;
	}
	tell_object(ob, "The hezrou misses you with it's bite!\n");
		say("The hezrou misses "+ob->query("cap_name")+" with it's bite!\n");
	return;
	}