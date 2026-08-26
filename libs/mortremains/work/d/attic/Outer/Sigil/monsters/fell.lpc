// A dubus who will tattoo players in the future.

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("short", "Fell the Tattoo Artist") ;
    set ("long", "This is a dabus who has decided to open a tatoo shop in Sigil.\n") ;
    set ("id", ({ "fell", "dabus" }) ) ;
    set_name ("fell") ;
    set ("gender", "male") ;
    enable_commands() ;
    set_level(7);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "claws") ;
    set_skill("Long Blades", 2, "Strength") ;
    set_verbs( ({ "scratch", "claw" }) );
}
