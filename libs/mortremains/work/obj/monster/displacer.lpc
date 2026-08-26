
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "ilzarion");
    set ("short", "displacer beast") ;
    set ("long", "A magical creature that resembles a puma with\n"+
      "two powerful black tentacles growing from its shoulders.\n");
    set ("id", ({ "displacer", "beast", "displacer beast" }) ) ;
    set_size(10);
    set("aggressive", 8);
    set_name ("displacer beast") ;
    set ("gender", "neuter") ;
    set ("race", "displacer beast");
    set_align("le");
    enable_commands() ;
    set_living_name("displacer beast") ;
    set ("base_ac", 2);
    set ("armor_class", 2);
    set ("damage", ({ 2,8 }) ) ;
    set ("weapon_name", "claws") ;
    set ("CLASS", "warrior");
    set_verbs( ({ "slash at", "swing at", "slice at" }) ) ;
    set_level(6);
}

