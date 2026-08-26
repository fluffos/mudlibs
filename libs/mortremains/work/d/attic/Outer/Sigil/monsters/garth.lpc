#include <mudlib.h>
#include "defs.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Garth the Shopkeep") ;
    set ("long", "A tall, elderly human.\n") ;
    set ("id", ({ "human", "shopkeep", "garth" }) ) ;
    set_name ("garth") ;
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("garth") ;
    set ("stat/constitution", 12);
    set ("stat/strength", 13);
    set ("stat/charisma",16);
    set ("stat/intelligence", 12);
    set ("stat/dexterity", 15);
    set ("stat/wisdom", 16);
    set("CLASS", "fighter");
    set ("damage", ({ 4,6 }) ) ;
    set ("weapon_name", "fists") ;
    set_skill("Short Blades", 2, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    set_size(6);
    set_level(14);
    set("wealth", 1000 + random(1000) ) ;
}

varargs int query_level(string str) { return 14; }

/* EOF */
