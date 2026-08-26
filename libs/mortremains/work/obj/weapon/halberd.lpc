// An example halberd. It is a two-handed weapon, so it sets its "nosecond"
// property to 1. Full comments on weapon properties are in the sword.c
// file which should be in the same directory as this file.

#include <mudlib.h>

inherit WEAPON ;

void create() {
	set ("id", ({ "halberd" }) ) ;
	set ("short", "a sturdy halberd") ;
	set ("long", "It is very large but extremely deadly.\n") ;
        set_weapon_type("halberd");
	set ("nosecond",1) ;
	set ("name", "halberd") ;
	set_verbs( ({ "swing at", "chop at", "hack at" }) ) ;
}
