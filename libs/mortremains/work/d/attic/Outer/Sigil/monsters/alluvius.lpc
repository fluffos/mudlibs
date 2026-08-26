
//Yeah, Ilzarion coded this shit
// Cy cleaned.

#include <mudlib.h>
#include "defs.h"
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Alluvius Ruskin") ;
    set ("long", "A small, elderly Tiefling.\n") ;
    set ("id", ({ "alluvius", "ruskin", "tiefling" }) ) ;
    set("inquiry", ([
      "portals" : "Why should I tell you anything about them?",
      "portal feel" : "I will tell you this.  You need Portal Feel.  It's essential!",
      "keys" :"Each portal has a special \"key\" that you need to go though.",
      "nightmask" :"I hear he once trampled an entire army of men with his camel spell.",
      "ilzarion" :"His code is sloppy and inefficient.  Nice guy though.",
      "darkangel" : "Never met the guy.\n",
      "cyanide" :"I hear he's almost as good a coder as Chronos.  Real nice guy.",
      "chronos" :"He can code like a madman.  Real nice guy.",
      "sex" : "Shut up, I don't get any anymore."
    ]) ) ;
    set_name ("alluvius") ;
    set ("gender", "female") ;
    enable_commands() ;
    set_living_name("alluvius") ;
    set ("stat/constitution", 10);
    set ("stat/strength", 18);
    set ("stat/charisma",12);
    set ("stat/intelligence", 17);
    set ("stat/dexterity", 18);
    set ("stat/wisdom", 9);
    set("CLASS", "wizard");
    set("max_sp", 360);
    set ("spell_points", 360);
    set ("mage_spells", ({ "stoneskin", "lightning", "bolt", "prism" }) );
    set ("damage", ({ 4,6 }) ) ;
    set ("weapon_name", "fists") ;
    set_skill("Short Blades", 2, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(OBJ(paralyzewand), "wand") ;
    wear(OBJ(bracers5), "bracers") ;
    wear("/d/class/wizard/general/obj/book", "book") ;
    set ("special", 7);
    set_size(6);
    set_level(14);
    set("wealth", 1000 + random(1000) ) ;
}

void special_attack() {
    //this is the spell function for raw excessive damage

    if (query("power_delay") || query("spell_points")<80) {
	command("say You will die!");
	return ;
    }else{	
	switch (random(3)){
	case 0 : command("cast prism");break;
	case 1 : command("cast bolt");break;
	case 2 : command("cast lightning");break;
	}
    }

    return;
}

varargs int query_level(string str) { return 14; }

/* EOF */