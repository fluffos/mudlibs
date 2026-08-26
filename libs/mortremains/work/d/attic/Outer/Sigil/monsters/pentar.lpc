
// A generic monster.

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Factol Pentar") ;
    set ("long", "The Factol of the Doomguard.\n") ;
    set ("id", ({ "factol", "pentar"}) ) ;
    set_name ("pentar") ;
    set ("gender", "female") ;
    enable_commands() ;
    set_living_name("pentar") ;
    set ("stat/constitution", 15);
    set ("stat/strength", 13);
    set ("stat/charisma", 18);
    set ("stat/intelligence", 18);
    set ("stat/dexterity", 14);
    set ("stat/wisdom", 14);
    set ("thac0", 1);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "warrior");
    set_skill("Short Blades", 2, "Strength") ;
    set_skill("Long Blades", 2, "Strength") ;
    set_skill("Two Weapon Style", 2, "Strength") ;
    set_skill("Ambidexterity", 1, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    set_level(20);
    arm(OBJ(planesword), "sword") ;
    arm(OBJ(dustblade), "blade") ;
    wear(OBJ(leather4), "armor") ;
}
