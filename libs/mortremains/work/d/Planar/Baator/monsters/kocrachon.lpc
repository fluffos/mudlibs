// Cleaned by Cyanide, 10 Jun 2000

#include <messages.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "a kocrachon") ;
    set ("long", "A loathsome, beetle-like fiend.\n") ;
    set ("id", ({ "kocrachon", "baatezu" }) ) ;
    set_size(5);
    set_name ("kocrachon") ;
    set ("race", "baatezu");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("kocrachon") ;
    set("resist_type",([ "cold":0, "fire":0, "poison":0]));
    set("magic_resist", 30);
    set("weap_resist", 1);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("CLASS", "warrior");
    set ("damage", ({ 1,6 }) ) ;
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set ("special", 1);
    set_level(7);
}


void special_attack() {
    object ob = query_current_attacker();

    if (query_hit(ob)) {
	message(MSG_COMBAT, "The kocrachon bites you savagely!\n", ob);
	message(MSG_COMBAT, "The kocrachon savagely bites "+
	  ob->query("cap_name")+"!\n", all_inventory(environment(TO)), ob);

	ob->receive_damage(random(9) + 4, "piercing", TO, 1);
    }

    return 0;
}
