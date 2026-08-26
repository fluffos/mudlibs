// dagger.c
// An example weapon. It is an acceptable second weapon, so it sets its
// "second" property to 1. For full comments on weapon properties, see
// sword.c which should be in the same directory as this file.

#include <mudlib.h>

inherit WEAPON ;

void create() {
	set ("id", ({ "dagger" }) ) ;
	set ("short", "a wicked dagger") ;
	set ("long", "It has a long blade which is very sharp.\n") ;
	set ("mass", 20) ;
	set ("bulk", 10) ;
	set ("value", ({ 3, "sludge" }) ) ;
	set ("weapon", 2) ;
	set ("name", "dagger") ;
	set ("second", 1) ;
	set ("damage", ({ 1, 4 }) ) ;
	set ("type", "thrusting") ;
	set_verbs( ({ "stab at", "lunge at" }) ) ;
}
