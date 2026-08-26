
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2 ;

	::create() ;
seteuid(getuid()) ;
	set ("short", "Bar-Lgura") ;
	set ("long", "A skeletal, leathery fiend.\n") ;
	set ("id", ({ "bar lgura", "bar-lgura", "tanar'ri" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_size(5);
	set_name ("bar-lgura") ;
	set ("race", "tanar'ri");
	set ("gender", "male") ;
	enable_commands() ;
   	   	set_living_name("bar-lgura") ;
	set("resist_type",([ "cold":50, "fire":50, "poison":0, "electricity":0]));
	set("magic_resist", 30);
//	set("weap_resist", 1);
	set_level(7);
//	set("stat/strength", 20);
	set ("base_ac", 0);
	set ("armor_class", 0);
	set("natt", 2);
	set("CLASS", "warrior");
	set ("damage", ({ 1,6 }) ) ;
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

ob->receive_damage(((random(9)+4)), "piercing");
		tell_object(ob, "the bar-lgura bites you!\n");
		say("The bar-lgura bites "+ob->query("cap_name")+"!\n");
	return;
	}
	tell_object(ob, "The bar-lgura misses you with it's bite!\n");
		say("The bar-lgura misses "+ob->query("cap_name")+" with it's bite!\n");
	return;
	}