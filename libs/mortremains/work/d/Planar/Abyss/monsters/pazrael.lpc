
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2 ;

	::create() ;
seteuid(getuid()) ;
	set ("short", "Pazrael") ;
	set ("long", "A huge bird-like lord of the abyss with golden wings.\n") ;
	set ("id", ({ "pazrael", "tanar'ri", "lord" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
    set_size(10);
	set_name ("pazrael") ;
	set ("race", "tanar'ri");
	set ("gender", "male") ;
	enable_commands() ;
   	   	set_living_name("nycaloth") ;
	set("resist_type",([  "poison":0, "electricity":0, "cold":50, "fire":50]));
	set("magic_resist", 85);
	set("stat/strength", 22);
	set("stat/constitution", 22);
	set("weap_resist", 4);
	set_level(34);
set("base_ac", -9);
	set ("armor_class", -9);
	set("natt", 2);
	set("CLASS", "warrior");
	set("thac0", 6);
	set_skill("Long Blades", 2, "Strength");
	set ("damage", ({ 9,15 }) ) ;
	set ("weapon_name", "talons") ;
	set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
	
	}
void special_attack() {
	//this is the spell function for raw excessive damage
object ob;
int sv; 
string target;

 ob = query_current_attacker();

if (this_object()->query_hit(ob)) {	

ob->receive_damage(((random(13)+7)), "piercing");
		tell_object(ob, "Pazrael pecks you!\n");
		say("The abyssal lord pecks at "+ob->query("cap_name")+"!\n");
	}else{
	tell_object(ob, "The abyssal lord misses you with it's beak!\n");
		say("The abyssal lord misses "+ob->query("cap_name")+" with it's beak!\n");
		}
}
