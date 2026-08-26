#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Mane") ;
    set ("long", "A squat, slobbering humanoid demon.\n") ;
    set ("id", ({ "mane", "tanar'ri" }) ) ;
    set_size(3);
    set_name ("mane") ;
    set ("race", "tanar'ri");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("mane") ;
    set("resist_type",([ "cold":50, "fire":50, "poison":0, "electricity":0]));
    set("magic_resist", 10);
    set ("base_ac", 8);
    set ("armor_class", 8);
    set("CLASS", "warrior");
    set ("damage", ({ 1,3 }) ) ;
    set ("weapon_name", "claws") ;
    set("special", 1);
    set_level(1);
}

void special_attack() {
    //this is the spell function for raw excessive damage
    object ob;
    int sv; 
    string target;

    ob = query_current_attacker();

    if (this_object()->query_hit(ob)) {	

	ob->receive_damage(random(4)+2, "piercing", TO, 1);
	tell_object(ob, "the mane bites you!\n");
	say("The mane bites "+ob->query("cap_name")+"!\n", ob);
	return;
    }
    tell_object(ob, "The mane misses you with it's bite!\n");
    say("The mane misses "+ob->query("cap_name")+
      "with its bite!\n", ob);
    return;
}
