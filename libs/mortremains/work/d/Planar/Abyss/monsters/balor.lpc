#include "abyss.h"
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("short", "a balor");
    set("long", wrap("The undisputed terror of The Abyss. It is "+
	"a towering humanoid with raging flames surrounding its form and "+
	"great leathery wings protruding from its massive back.") );
    set ("id", ({ "balor", "tanar'ri" }) ) ;
    set_size(12);
    set_name ("balor") ;
    set ("race", "tanar'ri");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("balor") ;
    set("resist_type",([ "cold":50, "fire":0, "poison":0, "electricity":0]));
    set("magic_resist", 70);
    set("weap_resist", 3);
    set("stat/strength", 24);
    set ("base_ac", -8);
    set ("armor_class", -8);
    set("CLASS", "warrior");
    set ("damage", ({ 2,12 }) ) ;
    set ("weapon_name", "claws") ;
    set_skill("Ambidexterity", 1, "Strength");
    set_skill("Two Weapon Style", 2, "Strength");
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set("special", 3);
    set_level(26);
    arm(ABYSS+"items/balorsword") ;
    arm(ABYSS+"items/balorwhip") ;
}
void init(){
    ::init();
    command("wield sword");
    command("wield whip");
}

void special_attack() {
    //this is the spell function for raw excessive damage
    object ob;
    int sv; 
    string target;

    ob = query_current_attacker();
    if (ob->receive_damage(random(20)+5, "fire", TP, 0)) {
	tell_object(ob, "You are burned by the balor's bodily flames!\n");
	say(ob->query("cap_name")+" is burned by the balor's "+
	  "bodily flames!\n", ob);
    }
}

