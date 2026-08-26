// Ilz did this.

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Tripicus") ;
    set ("long", "An Ursinal scholar of some note.\n") ;
    set ("id", ({ "tripicus", "ursinal" }) ) ;
    set_name ("tripicus") ;
    set ("gender", "male") ;
    enable_commands() ;
    set ("race", "guardinal");
    set_living_name("tripicus") ;
    set ("stat/constitution", 16);
    set ("stat/strength", 20);
    set ("stat/charisma", 18);
    set ("stat/intelligence", 19);
    set ("stat/dexterity", 11);
    set ("stat/wisdom", 20);
    set("level", 11);
    set("natt", 3);
    set ("thac0", 11);
    set ("armor_class", -4);
    set ("base_ac", -4);
    set ("damage", ({ 7,18 }) ) ;
    set ("weapon_name", "claws") ;
    set ("CLASS", "wizard");
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    set ("resist_type", ([ "cold" : 50, "poison" : 50, "force" : 50, "electricity" : 0 ]) );
    set ("weap_resist", 3);
    set ("magic_resist", 45);
    set_level(11);
}
