
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Factol Sarin") ;
    set ("long", "The Factol of the Harmonium.\n") ;
    set ("id", ({ "factol", "sarin"}) ) ;
    set_name ("sarin") ;
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("sarin") ;
    set ("stat/constitution", 17);
    set ("stat/strength", 17);
    set ("stat/charisma", 17);
    set ("stat/intelligence", 13);
    set ("stat/dexterity", 15);
    set ("stat/wisdom", 13);
    set_level(16);
    set("level", 16);
    set("natt", 1);
    set ("thac0", 5);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "warrior");
    set_skill("Long Blades", 2, "Strength") ;
    set_skill("Two Weapon Style", 2, "Strength") ;
    set_skill("Ambidexterity", 1, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(OBJ(scimitar2), "scimitar") ;
    arm(OBJ(scimitar2), "scimitar") ;
    wear(OBJ(redplate), "plate") ;
    wear(OBJ(ogregauntlets), "gauntlets") ;
    wear(OBJ(firering), "ring") ;
}
