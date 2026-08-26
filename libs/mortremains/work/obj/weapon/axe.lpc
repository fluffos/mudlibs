// An example axe. It is a two-handed weapon, so it sets its "nosecond"
// property to 1. Full comments on weapon properties are in the sword.c
// file which should be in the same directory as this file.

#include <mudlib.h>

inherit WEAPON ;

void create() {
	set ("id", ({ "axe" }) ) ;
	set ("short", "a gleaming two-handed battle axe") ;
	set ("long", "It is very heavy but extremely lethal.\n") ;
        set_weapon_type("axe/two-handed");
	set ("nosecond",1) ;
	set ("name", "axe") ;
	set_verbs( ({ "swing at", "chop at", "hack at" }) ) ;
}
