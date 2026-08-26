// dagger.c
// An example weapon. It is an acceptable second weapon, so it sets its
// "second" property to 1. For full comments on weapon properties, see
// sword.c which should be in the same directory as this file.
// Cyanide soft-coded second weapons, so we don't use the "second"
// property.  This version is compatible with the new lib.

#include <mudlib.h>

inherit WEAPON ;

void create() {
	set ("id", ({ "dagger" }) ) ;
	set ("short", "a wicked dagger") ;
	set ("long", "It has a long blade which is very sharp.\n") ;
        set_weapon_type("dagger");
	set ("name", "dagger") ;
	set_verbs( ({ "stab at", "lunge at" }) ) ;
}
