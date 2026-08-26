
// A generic monster.
// Ilzarion coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "gargoyle") ;
    set ("long", "A winged monstrosity made of stone.\n") ;
    set ("id", ({ "gargoyle"}) ) ;
    set_size(6);
    set_align("ce");
    set_name ("gargoyle") ;
    set ("gender", "neuter") ;
    set ("race", "gargoyle");
    enable_commands() ;
    set_living_name("gargoyle") ;
    set("weap_resist", 1);
    set ("base_ac", 5);
    set ("armor_class", 5);
    set ("natt", 4);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "claws") ;
    set ("CLASS", "warrior");
    set_verbs( ({ "slash at", "swing at", "slice at" }) ) ;
    set_level(5);
}
