// strength_potion.c
// An example potion which inherits /std/potion.c
// It temporarily raises the user's combat skills by 10 points, using
// the modify_skill lfun.
// Mobydick wrote this.
// The potion object was written by Valkyrie@TMI-2
// The name is slightly misleading, as it doesn't really alter your
// strength. Rename it if you like...
// Note that since these functions are call_outed, this_player() won't
// be defined in them. The variable drinker, set in potion.c, is a pointer to
// the player that drank the potion. So, use that if you need to.

#include <mudlib.h>

inherit "/std/potion" ;

void create() {
   set ("short", "a vial containing a golden potion") ;
    set ("long", "The golden potion sparkles in the crystal vial.\n") ;
    set ("color", "golden") ;
    set ("effect_time", 20) ;
    ::create() ;
}

int do_effect() {
    tell_object(drinker,"Suddenly, your weapons feel more comfortable in your hands.\n") ;
    drinker->modify_skill ("Cutting weapons", 10, 20) ;
    drinker->modify_skill ("Blunt weapons", 10, 20) ;
    drinker->modify_skill ("Thrusting weapons", 10, 20) ;
    return 1 ;
}

int do_wear_off() {
    tell_object(drinker, "Your weapons feel slightly awkward.\n") ;
// modify_skill removes the skill bonus automagically, so we don't
// need to actually do anything here. We could if we needed to though.
    return 1 ;
}
