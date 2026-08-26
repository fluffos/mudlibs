
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Goristro") ;
    set ("long", "The largest of the hordes of the abyss, the mighty goristro.\n");
    set ("id", ({ "goristro", "tanar'ri" }) ) ;
    set_size(24);
    set_name ("goristro") ;
    set ("race", "tanar'ri");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("goristro") ;
    set("resist_type",([ "cold":50, "fire":50, "poison":0, "electricity":0]));
    set("magic_resist", 60);
    set("weap_resist", 3);
    set("stat/constitution", 25);
    set("stat/strength", 20);
    set ("base_ac", -2);
    set ("armor_class", -2);
    set("natt", 2);
    set("CLASS", "warrior");
    set ("damage", ({ 12,30 }) ) ;
    set ("weapon_name", "fists") ;
    set_verbs( ({ "pound on", "smash", "pummel" }) ) ;
    set("special", 2);
    set_level(40);
}

void special_attack() {
    //this is the spell function for raw excessive damage
    object ob;
    int sv; 
    string target;

    ob = query_current_attacker();

    if (this_object()->query_hit(ob)) {	

	ob->receive_damage(random(27)+6, "crushing", TO, 1);
	tell_object(ob, "You are stomped upon by the goristro!\n");
	say("The goristro stomps on "+ob->query("cap_name")+"!\n", ob);
    }
}
