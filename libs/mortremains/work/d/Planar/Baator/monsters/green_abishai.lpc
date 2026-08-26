// By Ilzarion.
// CLeaned by Cyanide, 11/26/1998 11:44:19 PM 

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Green Abishai") ;
    set ("long", "A thin, reptilian gargoyle-like demon of the nine hells.\n") ;
    set ("id", ({ "green abishai",  "abishai", "baatezu" }) ) ;
    set_name ("green abishai") ;
    set("stat", ([
      "strength" : 15,
      "constitution" : 15,
      "dexterity" : 15,
      "intelligence" : 14,
      "wisdom" : 9,
      "charisma" : 4
    ]) );
    set ("race", "baatezu");
    set ("gender", "male") ;
    set_size(5);
    set_align("le");
    enable_commands() ;
    set_living_name("green abishai") ;
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set("magic_resist", 30);
    set("weap_resist", 1);
    set ("base_ac", 3);
    set ("armor_class", 3);
    set("damage_type", "slashing");
    set("natt", 2);
    set("CLASS", "warrior");
    set("class", "fighter");
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set ("special", 1);
    set_level(6);
    credit( query("hit_points") / 2 ); 
}

void special_attack() {
    //this is the spell function for raw excessive damage
    object ob;

    ob = query_current_attacker();
    if (!ob) return ;

    if (query_hit(ob, 0)) {	
	/*
		    if (!ob->save_throw()){	
			ob->receive_damage(((random(25)+26)), "poison", TO, 1);
			tell_object(ob, "You are poisoned by the abishai's bite!\n");
		    }
	*/
	ob->receive_damage(((random(4)+2)), "piercing", TO, 1);
	tell_object(ob, "You are bitten by the abishai!\n");
	say("The abishai bites "+ob->query("cap_name")+"!\n", ({ ob }));
    } else {
	tell_object(ob, "The abishai misses you with it's bite!\n");
	say("The abishai misses "+ob->query("cap_name")+
	  " with its bite!\n", ({ ob }));
    }
    return;
}

/* EOF */
