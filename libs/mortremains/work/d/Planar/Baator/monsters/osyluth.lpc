#include <messages.h>

inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "osyluth") ;
    set ("long", @EndText
The osyluth is a bony and wretched thing. Its body is that of a dried husk
of a human form, with a fearsome human skull covered by sickly dried skin
stretched tight. The osyluth has a large scorpion-like tail and carries a
foul stench of decay and rot. 
EndText
    );    
    set ("id", ({ "osyluth", "baatezu" }) ) ;
    set_size(9);
    set_name ("osyluth") ;
    set ("race", "baatezu");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("osyluth") ;
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set("magic_resist", 30);
    set("weap_resist", 1);
    set ("base_ac", 3);
    set ("armor_class", 3);
    set("CLASS", "warrior");
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set ("special", 4);
    set_level(5);
    credit( query("hit_points") / 2 ); 
}


void special_attack() {
    //this is the spell function for raw excessive damage
    object ob;
    int sv; 
    string target;

    ob = query_current_attacker();

    if (query_hit(ob) && ob->receive_damage(random(8)+1, "piercing", TO, 1)) {
	message(MSG_COMBAT, "The osyluth bites you viciously!\n", ob);
	message(MSG_COMBAT, "The osyluth bites "+ob->query("cap_name")+
	  " viciously!\n", all_inventory(environment(TO)), ob );
    } else {
	message(MSG_COMBAT, "The osyluth misses you with its bite.\n", ob);
	message(MSG_COMBAT, "The osyluth misses "+ob->query("cap_name")+
	  " with its bite!\n", all_inventory(environment(TO)), ob );       
    }

    if (query_hit(ob) && ob->receive_damage(random(9)+4, "piercing", TO, 1)) {
	message(MSG_COMBAT, "The osyluth pierces you with its tail!\n", ob);
	message(MSG_COMBAT, "The osyluth pierces "+ob->query("cap_name")+
	  " with its tail!\n", all_inventory(environment(TO)), ob );

	if (!ob->save_throw()){	
	    ob->receive_damage(((random(50)+26)), "poison");
	    message(MSG_COMBAT, "The osyluth has poisoned you!\n", ob);
	    return;
	}
    } else {
	message(MSG_COMBAT, "The osyluth misses you with its tail.\n", ob);
	message(MSG_COMBAT, "The osyluth misses "+ob->query("cap_name")+
	  " with its tail!\n", all_inventory(environment(TO)), ob );       
    }

    return;
}
