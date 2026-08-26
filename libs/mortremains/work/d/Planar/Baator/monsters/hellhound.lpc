// Cyanide fixed this, 21 Nov 98.

#include <messages.h>
#include "baator.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "cyanide");
    set ("short", "a hell hound");
    set ("long", @EndText
Hellhounds resemble a large hound with rust-red fur and red, glowing eyes.
Its markings, teeth and tongue are soot black. It stands about three feet
high at the shoulder, and has a distinct odor of smoke and sulfur.
EndText
    ) ;
    set ("id", ({ "hell hound", "hound", "hellhound" }) ) ;
    set_align("le");
    set_size(3);
    set_name ("hell hound") ;
    set ("race", "hell hound");
    set ("gender", "neuter") ;
    enable_commands() ;
    set_living_name("hell hound") ;
    set("resist_type",([ "fire":0 ]));
    set ("base_ac", 4);
    set ("armor_class", 4);
    set("CLASS", "warrior");
    set ("damage", ({ 1, 10 }) ) ;
    set("damage_type", "piercing");
    set ("weapon_name", "fearsome bite") ;
    set_verbs( ({ "chomp" }) ) ;

    set_level(7);
    credit( query("hit_points") / 3 ); 
}

int special_attack() {
    if (!random(4)) {    
	object ob = get_random_attacker();

	message(MSG_COMBAT, "The hellhound belches flame at you!\n",
	  ob);
	message(MSG_COMBAT, "The hellhound belches flame at "+
	  ob->query("cap_name")+"!\n", all_inventory(environment(TO)), ob);
	ob->receive_damage(15, "fire", TO, 0);

	return 1;
    } else {    
	return 0;
    }
}

/* EOF */
