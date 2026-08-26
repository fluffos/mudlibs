// By Ilzarion.
// Cleaned by Cyanide, 11/27/1998 1:30:41 AM 
// And again, 6/11/00

#include "baator.h"
#include <messages.h>

inherit MONSTER ;

void create () {
    object ob1;

    ::create() ;
    seteuid(getuid()) ;
    set ("short", "cornugon") ;
    set ("long", @EndLong
The cornugon, also called the "horned devil", is 9 feet tall, only vaguely
humanoid, and covered with grotesque scales. Its sharp horns, huge wings 
and snaking, prehensile tail add to its intimidating demeanor. 
EndLong
    );
    set("author", "cyanide");
    set ("id", ({ "cornugon", "baatezu" }) ) ;
    set_size(9);
    set_align("le");
    set_name ("cornugon") ;
    set ("race", "baatezu");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("cornugon") ;
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set("magic_resist", 50);
    set("weap_resist", 2);
    set("stat/strength", 20);
    set("base_ac", -3) ;
    set("armor_class", -3) ;
    set("CLASS", "warrior");
    set ("damage", ({ 2,16 }) ) ;
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set_skill("Whips", 3, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(BAATOR+"items/parawhip") ;
    set("special", 1);
  set_level(15) ;
}

// This is the spell function for raw excessive damage

void special_attack() {
    object ob, wound;

    ob = query_current_attacker();

    if (query_hit(ob, 0) && ob->receive_damage(random(4)+8, "piercing", TO, 1)) {
	message(MSG_COMBAT, "The cornugon bites you viciously!\n", ob);
	message(MSG_COMBAT, "The cornugon viciously bites "+
	  ob->query("cap_name")+"!\n", all_inventory(environment(TO)), ob);
    } else {    
	message(MSG_COMBAT, "The cornugon misss you with its bite.\n", ob);
	message(MSG_COMBAT, "The cornugon misses "+ob->query("cap_name")+
	  " with its bite.\n", all_inventory(environment(TO)), ob);
    }

    if (query_hit(ob, 0) && ob->receive_damage(random(3)+7, "piercing"), TO, 1) {
	message(MSG_COMBAT, "The cornugon pierces you with its tail!\n", ob);
	message(MSG_COMBAT, "The cornugon pierces "+ob->query("cap_name")+
	  " with its tail!\n", all_inventory(environment(TO)), ob);

	wound = present("#WOUND_OB#", ob);
	if (!wound) {
	    wound = clone_object("/d/Ancients/obj/wound_ob");
	    wound -> move(ob) ;
	} else {
	    wound->add("woundlevel", 1);
	}
    } else {    
	message(MSG_COMBAT, "The cornugon misss you with its tail.\n", ob);
	message(MSG_COMBAT, "The cornugon misses "+ob->query("cap_name")+
	  " with its tail.\n", all_inventory(environment(TO)), ob);
    }
}

void heart_beat(){
    ::heart_beat();
    heal_up();
}
