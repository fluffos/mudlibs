
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2 ;

	::create() ;
seteuid(getuid()) ;
	set ("short", "Death Slaad") ;
	set ("long", "A bipedal, giant, carnivorous frog-like demon from limbo.\n") ;
	set ("id", ({ "death", "slaad", "death slaad" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
    set_size(6);
	set_name ("death slaad") ;
	set ("race", "slaad");
	set ("gender", "male") ;
	enable_commands() ;
   	   	set_living_name("death slaad") ;
	set("resist_type",([  "poison":0]));
	set("magic_resist", 70);
	set("stat/strength", 19);
	set("stat/constitution", 20);
	set("weap_resist", 2);
	set_level(17);
	set ("base_ac", -4);
	set ("armor_class", -4);
	set("natt", 2);
	set("CLASS", "warrior");
	set ("damage", ({ 6,18 }) ) ;
	set ("weapon_name", "claws") ;
	set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
	set ("special", 4);
	}

	
void special_attack() {
	//this is the spell function for raw excessive damage
object ob;
int sv; 
string target;

 ob = query_current_attacker();

if (this_object()->query_hit(ob)) {	

ob->receive_damage(((random(20)+2)), "piercing");
		tell_object(ob, "the slaad bite's you!\n");
		say("The slaad bites "+ob->query("cap_name")+"!\n");
	}else{
	tell_object(ob, "The slaad misses you with it's bite!\n");
		say("The slaad misses "+ob->query("cap_name")+" with it's bite!\n");
		}
}

void heart_beat(){
heal_up();
::heart_beat();
}
