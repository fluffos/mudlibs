
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "defs.h"
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Harys Hatchis") ;
    set ("long", "The great entrepenuer and promoter of shoppes.\n") ;
    set ("id", ({ "harys", "hatchis"}) ) ;
    set_name ("harys") ;
    set ("race", "human");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("harys") ;
    set ("stat/constitution", 11);
    set ("stat/strength", 10);
    set ("stat/charisma", 16);
    set ("stat/intelligence", 15);
    set ("stat/dexterity", 12);
    set ("stat/wisdom", 14);
    set_level(8);
    set("level", 8);
    set("natt", 1);
    set ("thac0", 18);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "wizard");
    set_skill("Short Blades", 2, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;

    arm(OBJ(greendagger), "dagger") ;
}
