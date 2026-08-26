// An example axe. It is a two-handed weapon, so it sets its "nosecond"
// property to 1. Full comments on weapon properties are in the sword.c
// file which should be in the same directory as this file.

#include <mudlib.h>

inherit WEAPON ;

void create() {
	set ("id", ({ "sword", "two handed sword", "two-handed sword"}) ) ;
	set ("short", "a two-handed sword") ;
	set ("long", "The Weapon for a large, violent warrior.\n") ;
        set_weapon_type("sword/two-handed");
	set ("name", "two handed sword") ;
	set ("nosecond", 1);
	set_verbs( ({ "swing at", "chop at", "hack at" }) ) ;
}
