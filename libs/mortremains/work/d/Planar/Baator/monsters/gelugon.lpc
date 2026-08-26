// Ilzarion coded it.
// Cyanide cleaned up, 8/22/1999 2:04:44 AM 

#include <messages.h>
#include "baator.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "gelugon") ;
    set ("long", @EndLong
The gelugon, also referred to as the "ice devil" is a 12 foot tall insect,
with claws on its hands and feet and sharp pincers at the mouth. Its head
bulges with multifaceted eyes. It has a long, thick tail covered with
razor-sharp spikes. 
EndLong
    );
    set ("id", ({ "gelugon", "baatezu" }) ) ;
    set("author", "ilzarion");
    set_size(12);
    set_name ("gelugon") ;
    set ("race", "baatezu");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("gelugon") ;
    set("resist_type",([ "cold":0, "fire":0, "poison":0]));
    set("magic_resist", 50);
    set("weap_resist", 2);
    set("stat/strength", 19);
    set ("base_ac", -3);
    set ("armor_class", -3);
    set("CLASS", "warrior");
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set_skill("Polearms", 2, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    set("special", 4);
    credit(500+random(1000));
    set_level(11);
    arm(BAATOR+"items/paraspear") ;
}

void special_attack() {
    object ob = query_current_attacker();

    if (query_hit(ob, 0) && ob->receive_damage(((random(2)+7)), "piercing")) {
        message(MSG_COMBAT, "The gelugon bites you viciously with its pincers!\n", ob);
        message(MSG_COMBAT, "The gelugon viciously bites "+
            ob->query("cap_name")+" with its pincers!\n", 
            all_inventory(environment(TO)), ob);
    } else {    
        message(MSG_COMBAT, "The gelugon misses you with its pincers.\n", ob);
        message(MSG_COMBAT, "The gelugon misses "+ob->query("cap_name")+
        " with its pincers.\n", all_inventory(environment(TO)), ob);
    }

    if (query_hit(ob, 0) && ob->receive_damage(((random(3)+7)), "piercing")) {
        message(MSG_COMBAT, "The gelugon pierces you with its tail!\n", ob);
        message(MSG_COMBAT, "The gelugon pierces "+ob->query("cap_name")+
            " with its tail!\n", all_inventory(environment(TO)), ob);
    } else {    
        message(MSG_COMBAT, "The gelugon misss you with its tail.\n", ob);
        message(MSG_COMBAT, "The gelugon misses "+ob->query("cap_name")+
        " with its tail.\n", all_inventory(environment(TO)), ob);
    }

    if ( !random(5) && !ob->query_save() ) {
        message(MSG_COMBAT, "The cold of Cania washes over you, numbing "+
            "your body!\n", ob);
		ob->block_attack(random(6)+1);
	}
}

void heart_beat(){
    ::heart_beat();
    heal_up();
}

/* EOF */
