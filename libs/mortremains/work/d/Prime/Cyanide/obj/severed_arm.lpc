#include <mudlib.h>
#include "obj.h"

inherit WEAPON ;

void create() {
    set ("author","cyanide");
    set ("id", ({"arm", "limb", "weapon", "severed arm" }) ) ;
    set ("short", "a bloody severed arm (decaying)");
    set ("long", @Endtext
You are holding a bloody stump of an arm severed at the shoulder. It's
very touch causes you to shiver. Its cold skin is cold and clammy, and a
remnant of shattered bone still juts from where it was once attached to
a living body.
Endtext
    ) ;
    set ("weapon" , 12) ;
    set ("damage", ({ 1,8 }) ) ;
    set ("name", "a bloody severed arm") ;
    set_verbs( ({ "attack", "swing at", "thrust at", "bludgeon" }) ) ;
    set_verbs2( ({ "attacks", "swings at", "thrusts at", "bludgeons" }) ) ;
    set ("second", 0) ;
    set ("nosecond",1) ;
    set ("type", "blunt") ;
    set ("hide_type", 1);
    set_weapon_type("club");
}
