// dragon.c
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c
// Mobydick, 10-2-92.
// Cyanide updated to the nee NK lib, 26 Apr 98.

#include <mudlib.h>

inherit MONSTER;

void create () {
    seteuid(getuid()) ;
    ::create() ;
    init_commands() ;
    set ("short", "Curly the red dragon") ;
    set ("long", "The dragon has a large red body with powerful silver" +
      " wings. It has\na faint aura of smoke about it. Use caution " +
      "adventurer...\n");
    set ("id", ({ "dragon", "red dragon", "curly" }) ) ;
    set_name ("curly") ;
    set ("gender", "neuter") ;
    enable_commands() ;
    set_living_name("curly") ;
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "paws") ;
    set_size(15);
    set_level(16);
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
}

// This lets you give him a unique movement message.

string query_min() {
    return "Curly the dragon flies in and lands next to you with a sulfurous stench.\n" ;
}

string query_mout (string str) {
    return "Curly the dragon departs, leaving only the smell of kerosene in his wake.\n" ;
}
