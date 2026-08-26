// Cyanide redid Ilzarion's crap
// 8/22/1999 3:03:30 AM 

#include <mudlib.h>
#include "baator.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Malagard, The Hag Countess of Malbolge") ;
    set ("long", wrap("The powerful lord of the Sixth layer of "+
	"Baator. She appears as an old crippled hag, stooped "+
	"from the weight of the years. She carries immense power "+
	"under her withered exterior, teaching that it's best "+
	"never to judge someone on the basis of appearance.") );
    set ("id", ({ "malagard", "lord", "baatezu"}) );
    set_name ("malagard") ;
    set ("gender", "female") ;
    set ("race", "baatezu");
    enable_commands() ;
    set_living_name("malagard") ;
    set ("stat/constitution", 20);
    set ("stat/strength", 22);
    set ("stat/charisma", 12);
    set ("stat/intelligence", 21);
    set ("stat/dexterity", 19);
    set ("stat/wisdom", 19);
    set ("special", 10);
    set_size(10);
    set ("base_ac", 5);
    set ("armor_class", 5);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "claws") ;
    set ("CLASS", "warrior");
    set ("weap_resist", 4);
    set ("magic_resist", 85);
    set ("resist_type", ([ "cold" : 50, "poison" : 0, "fire" : 0 ]) );
    set_skill("Long Blades", 5, "Strength") ;
    set_skill("Two Handed Style", 2, "Strength") ;
    set_skill("Ambidexterity", 1, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    set("special", 7);
    set_level(36);
    arm(BAATOR+"items/2hflamesword") ;
}

void special_attack() {
    object ob;

    ob = query_current_attacker();
    ob->receive_damage(((random(21)+21)), "crushing", TO, 0);
    tell_object(ob, "Malagard calls boulders from the sky to hit you!\n");
    say("Malagard calls boulders from the sky to hit "+
      ob->query("cap_name")+".\n", ({ ob }) );
    tell_object(TO, "You call boulders from the sky to hit "+
      ob->query("cap_name")+".\n");
}
