// Ilz did this, too.

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Prisine") ;
    set ("long", "The leader of the Will of the One.\n") ;
    set ("id", ({ "prisine", "genasi"}) ) ;
    set_name ("prisine") ;
    set ("race", "genasi");
    set ("gender", "female") ;
    enable_commands() ;
    set_living_name("prisine") ;
    set ("stat/constitution", 9);
    set ("stat/strength", 11);
    set ("stat/charisma", 16);
    set ("stat/intelligence", 16);
    set ("stat/dexterity", 12);
    set ("stat/wisdom", 10);
    set("natt", 1);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "rogue");
    set_skill("Short Blades", 2, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(OBJ(dagger3), "dagger") ;
    set_level(9);
}
