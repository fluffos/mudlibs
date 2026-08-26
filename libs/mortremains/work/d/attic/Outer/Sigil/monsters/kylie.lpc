// Kylie - who stands outside and waders around a bit.

#include <mudlib.h>
#include "defs.h"
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Kylie") ;
    set ("long", "A free-spirited guide to sigil.\n") ;
    set ("id", ({ "kylie", "tiefling"}) ) ;
    set ("bulk", 250) ;
    set_name ("kylie") ;
    set ("gender", "female") ;
    set ("race", "tiefling");
    enable_commands() ;
    set_living_name("kylie") ;
    set ("stat/constitution", 12);
    set ("stat/strength", 14);
    set ("stat/charisma", 15);
    set ("stat/intelligence", 16);
    set ("stat/dexterity", 18);
    set ("stat/wisdom", 11);
    set_level(8);
    set("natt", 1);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "claws") ;
    set ("CLASS", "rogue");
    set ("resist_type", ([ "cold" : 50 ]) );
    set_skill("Short Blades", 2, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(OBJ(shortsword2), "sword");
    wear(OBJ(earring2), "earring") ;
}
