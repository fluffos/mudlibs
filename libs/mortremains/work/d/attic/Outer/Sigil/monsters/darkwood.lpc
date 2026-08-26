
// Ilz coded this.
// Cyanide updated it.

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;

void create () {
	::create() ;
	seteuid(getuid()) ;
	set ("short", "Rowan Darkwood") ;
	set ("long", "This is the imposing Duke Rowan Darkwood.\n") ;
	set ("id", ({ "duke", "rowan", "darkwood" }) ) ;
	set_name ("darkwood") ;
	set ("gender", "male") ;
	enable_commands() ;
   	set_living_name("darkwood") ;
	set ("stat/constitution", 20);
	set ("stat/strength", 20);
	set ("stat/charisma", 18);
	set ("stat/intelligence", 17);
	set ("stat/dexterity", 17);
	set ("stat/wisdom", 20);
	set("special", 10);
    set("CLASS", "warrior");
    set("max_tp", 1000);
    set("theurgy_points", 1000);
    set("priest_spells", ({ "greaterheal", "creepingdoom" }) );
    set("deity", "Heimdall");
    set("wealth", 5000);
	set("level", 20);
	set("natt", 1);
	set ("thac0", 2);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set_skill("Long Blades", 2, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	set_level(39);
    arm(SIGIL+"items/giantslayer", "sword") ;
    wear(SIGIL+"items/splint3", "splint") ;
    wear(SIGIL+"items/ring5", "ring") ;
    wear(SIGIL+"items/priest_ob", "hi") ;
}

void init () {
    ::init();
    command("wield sword");
    command("equip ring");
}

void special_attack() {
	//this is the spell function for raw excessive healing

    if (query("power_delay") || query("theurgy_points")<60) {
        return;
    } else {	
        if((int)query("hit_points") < 700){ 
            command("invoke greaterheal");
        } else {
            if(!random(5)) command("invoke creepingdoom");
        }
        return;
    }
}

/* EOF */