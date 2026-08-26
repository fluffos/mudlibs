// Cleaned up by Cyanide 10 Jun 2000

#include <messages.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Hamatula") ;
    set ("long", @EndLong
The hamatula looks like a large humanoid, covered from head to toe with
sharp, bony barbs right down to its long, nasty tail. 
EndLong
    );
    set ("id", ({ "hamatula", "baatezu" }) ) ;
    set_size(7);
    set("author", "cyanide");
    set_name ("hamatula") ;
    set ("race", "baatezu");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("hamatula") ;
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set("magic_resist", 30);
    set("weap_resist", 1);
    set ("base_ac", 1);
    set ("armor_class", 1);
    set("CLASS", "warrior");
    set ("damage", ({ 2,8 }) ) ;
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set ("special", 1);
    set_level(7);
}


void special_attack() {
    object ob = query_current_attacker();

    if (query_hit(ob)) {
	message(MSG_COMBAT, "The hamatula bites you savagely!\n", ob);
	message(MSG_COMBAT, "The hamatula savagely bites "+
	  ob->query("cap_name")+"!\n", all_inventory(environment(TO)), ob);

	ob->receive_damage(random(9) + 4, "piercing", TO, 1);
    }

    return 0;
}
