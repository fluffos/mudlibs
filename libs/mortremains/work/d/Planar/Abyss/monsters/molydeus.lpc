
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2 ;

	::create() ;
seteuid(getuid()) ;
	set ("short", "Molydeus") ;
	set ("long", "A powerful humanoid demon with both a dog head and snake head.\n"+
	"It carries a deadly-looking axe.\n") ;
	set ("id", ({ "molydeus", "tanar'ri" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_size(12);
	set_name ("molydeus") ;
	set ("race", "tanar'ri");
	set ("gender", "male") ;
	enable_commands() ;
   	   	set_living_name("molydeus") ;
	set("resist_type",([ "cold":50, "fire":50, "poison":0, "electricity":0]));
	set("magic_resist", 90);
	set("weap_resist", 6);
	set_level(13);
	set("stat/strength", 20);
	set ("base_ac", -5);
	set ("armor_class", -5);
	set("natt", 1);
	set("CLASS", "warrior");
	set ("damage", ({ 2,12 }) ) ;
	set ("weapon_name", "claws") ;
	set_skill("Axes", 1, "Strength") ;
	set_skill("Two Handed Style", 2, "Strength");
	set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
	set("special", 18);
   	ob1 = clone_object ("/d/Outer/Abyss/items/molyaxe") ;
    ob1 -> move (this_object()) ;
   	}

void init(){
::init();
command("wield axe");
}
	
void special_attack() {
	//this is the spell function for raw excessive damage
object ob;
int sv; 
string target;

 ob = query_current_attacker();

if (this_object()->query_hit(ob)) {	
	if (!ob->query_save()){	
		  	ob->receive_damage(((random(25)+26)), "poison");
		tell_object(ob, "You are poisoned by the snake head!\n");
		say("The snake head bite's "+ob->query("cap_name")+"!\n");
		}else{
ob->receive_damage(((random(6)+1)), "piercing");
		tell_object(ob, "You are bitten by the snake head!\n");
		say("The snake head bite's "+ob->query("cap_name")+"!\n");
		}
		}else{
	tell_object(ob, "The snake head misses you!\n");
		say("The snake head misses "+ob->query("cap_name")+"!\n");
		}

if (this_object()->query_hit(ob)) {	
	
ob->receive_damage(((random(11)+2)), "piercing");
		tell_object(ob, "You are bitten by the dog head!\n");
		say("The dog head bite's "+ob->query("cap_name")+"!\n");
	return;
	}else{
	tell_object(ob, "The dog head misses you with it's bite!\n");
		say("The dog head misses "+ob->query("cap_name")+" with it's bite!\n");
	return;
	}
	}
	
