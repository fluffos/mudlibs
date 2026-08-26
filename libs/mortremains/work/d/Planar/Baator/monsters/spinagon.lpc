// Cleaned up by Cyanide, 10 June 2000

#include <messages.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "spinagon") ;
    set ("long", @EndLong
Also called the "Spined Devil", the spinagon looks much like a gargoyle: a
small humanoid with wings and a spiked tail. It has long, razor-sharp 
talons on its feet.
EndLong
    );
    set ("id", ({ "spinagon", "baatezu" }) ) ;
    set_size(3);
    set_name ("spinagon") ;
    set ("race", "baatezu");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("spinagon") ;
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set("magic_resist", 15);
    set ("base_ac", 4);
    set ("armor_class", 4);
    set("CLASS", "warrior");
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set ("special", 1);
    set_level(4);
}


void special_attack() {
    object ob = get_random_attacker();

    if (query_hit(ob)) {
	message(MSG_COMBAT, "The spinagon launches fiery spines at you!\n", ob);
	message(MSG_COMBAT, "The spinagon launches flaming spikes at "+
	  ob->query("cap_name")+"!\n", all_inventory(environment(TO)), ob);

	ob->receive_damage(random(3) + 1, "fire", TO, 0);
    }

    return 0;
}
