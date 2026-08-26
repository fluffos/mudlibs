
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "defs.h"
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Autochon the Bellringer") ;
    set ("long", "A powerful warrior in dark plate armor.\n") ;
    set ("id", ({ "autochon", "bellringer"}) ) ;
    set ("capacity", 10000) ;
    set ("max_cap", 10000) ;
    set ("max_vol", 10000) ;
    set ("volume", 200) ;
    set ("mass", 300) ;
    set ("bulk", 250) ;
    set_name ("autochon") ;
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("autochon") ;
    set ("stat/constitution", 16);
    set ("stat/strength", 16);
    set ("stat/charisma", 8);
    set ("stat/intelligence", 14);
    set ("stat/dexterity", 10);
    set ("stat/wisdom", 10);
    set_level(12);
    set("level", 12);
    set("natt", 1);
    set ("thac0", 9);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "warrior");
    set_skill("Long Blades", 4, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(OBJ(scimitarspeed3), "scimitar") ;
    wear(OBJ(wasteplate), "plate") ;
}
