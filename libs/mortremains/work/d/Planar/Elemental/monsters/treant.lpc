// Ilzarion coded this for use with the priest's "changestaff"
// command.

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Treant") ;
    set ("long", "A large, sentient tree.\n") ;
    set ("id", ({ "treant", "tree" }) ) ;
    set("author", "ilzarion");
    set_name ("treant") ;
    set ("gender", "neuter") ;
    set ("race", "treant");
    enable_commands() ;
    set_living_name("treant") ;
    set ("stat/constitution", 20);
    set ("stat/strength", 20);
    set ("base_ac", 2);
    set("lore_type", "monster");
    set ("armor_class", 2);
    set ("damage", ({ 3,24 }) ) ;
    set ("weapon_name", "branches") ;
    set ("CLASS", "warrior");
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    set("resist_type", ([ "fire" : 200 ]) );
    set_size(10);
    set_level(15);
}
