
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2 ;

	::create() ;
seteuid(getuid()) ;
	set ("short", "Chasme") ;
	set ("long", "A horrid, demonic croos between a human and a fly.\n") ;
	set ("id", ({ "chasme", "tanar'ri" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_size(7);
	set_name ("chasme") ;
	set ("race", "tanar'ri");
	set ("gender", "male") ;
	enable_commands() ;
   	   	set_living_name("chasme") ;
	set("resist_type",([ "cold":50, "fire":50, "poison":0, "electricity":0]));
	set("magic_resist", 50);
//	set("weap_resist", 1);
	set_level(9);
//	set("stat/strength", 20);
	set ("base_ac", -5);
	set ("armor_class", -5);
	set("natt", 2);
	set("CLASS", "warrior");
	set ("damage", ({ 2,8 }) ) ;
	set ("weapon_name", "claws") ;
	set("special", 1);
  
   	}

void special_attack() {
	//this is the spell function for raw excessive damage
object ob;
int sv; 
string target;

 ob = query_current_attacker();

if (this_object()->query_hit(ob)) {	

ob->receive_damage(((random(4)+1)), "piercing");
		tell_object(ob, "the chasme bites you!\n");
		say("The chasme bites "+ob->query("cap_name")+"!\n");
	return;
	}
	tell_object(ob, "The chasme misses you with it's bite!\n");
		say("The chasme misses "+ob->query("cap_name")+" with it's bite!\n");
	return;
	}