// Cleaned by Cyanide, 4 Jan 2000

#include <messages.h>

inherit MONSTER ;

void create () {
    object ob1, ob2 ;

    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Pit Fiend") ;
    set ("long", @EndLong
The pit fiend, the most terrible baatezu is a giant winged humanoid,
gargoylish in appearance, with huge bat-wings that it can wrap around its
body in defense, large fangs that drip with vile, green liquid, and hulking
red, scaly bodies that burst into flame when its angered or excited. 
EndLong
    );
    set("id", ({ "pitfiend", "pit fiend", "pit", "fiend", "baatezu" }));
    set_size(12);
    set_name ("pit fiend") ;
    set ("race", "baatezu");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("pit fiend") ;
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set("magic_resist", 50);
    set("weap_resist", 3);
    set("stat/strength", 24);
    set ("base_ac", -5);
    set ("armor_class", -5);
    set("CLASS", "warrior");
    set ("damage", ({ 1,4 }) ) ;
    set("damage_type", "slashing");
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set("special", 3);
    set_level(15);
    credit( query("hit_points") / 2 ); 
}

int special_attack() {
    object ob;

    ob = query_current_attacker();

    if (query_hit(ob, 0) && 
      ob->receive_damage(random(4)+12, "piercing", TO, 1)) {

	message(MSG_COMBAT, "The pit fiend bites you viciously!\n", ob);
	message(MSG_COMBAT, "The pit fiend viciously bites "+
	  ob->query("cap_name")+"!\n", all_inventory(environment(TO)), ob);

	if (!ob->save_throw()){	
	    ob->receive_damage(((random(25)+26)), "poison");
	    message(MSG_COMBAT, "You are poisoned by the bite.\n", ob);
	}
    } else {    
	message(MSG_COMBAT, "The pit fiend misss you with its bite.\n", ob);
	message(MSG_COMBAT, "The pit fiend misses "+ob->query("cap_name")+
	  " with its bite.\n", all_inventory(environment(TO)), ob);
    }

    if (query_hit(ob, 0) && 
      ob->receive_damage(random(3)+12, "piercing", TO, 1) ) {

	message(MSG_COMBAT, "The pit fiend pierces you with its tail!\n", ob);
	message(MSG_COMBAT, "The pit fiend pierces "+ob->query("cap_name")+
	  " with its tail!\n", all_inventory(environment(TO)), ob);
    } else {    
	message(MSG_COMBAT, "The pit fiend misss you with its tail.\n", ob);
	message(MSG_COMBAT, "The pit fiend misses "+ob->query("cap_name")+
	  " with its tail.\n", all_inventory(environment(TO)), ob);
    }

    if (query_hit(ob, 0) &&
      ob->receive_damage(random(3)+12, "bludgeoning", TO, 1)) {

	message(MSG_COMBAT, "The pit fiend bludgeons you with its wings.\n", ob);
	message(MSG_COMBAT, "The pit fiend bludgeons "+ob->query("cap_name")+
	  " with its wings!\n", all_inventory(environment(TO)), ob);

    } else {    
	message(MSG_COMBAT, "The pit fiend misss you with its wings.\n", ob);
	message(MSG_COMBAT, "The pit fiend misses "+ob->query("cap_name")+
	  " with its wings.\n", all_inventory(environment(TO)), ob);
    }

    return 0;
}

void heart_beat(){
    ::heart_beat();
    heal_up();
}
