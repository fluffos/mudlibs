// An example axe. It is a two-handed weapon, so it sets its "nosecond"
// property to 1. Full comments on weapon properties are in the sword.c
// file which should be in the same directory as this file.

#include <mudlib.h>

inherit WEAPON ;

void create() {
	set ("id", ({ "axe", "battle axe"}) ) ;
	set ("short", "a battle axe") ;
	set ("long", "A gleaming sharp, axe.\n") ;
        set_weapon_type("axe/battle");
	set ("name", "battle axe") ;
	set_verbs( ({ "swing at", "chop at", "hack at" }) ) ;
}
