// An example axe. It is a two-handed weapon, so it sets its "nosecond"
// property to 1. Full comments on weapon properties are in the sword.c
// file which should be in the same directory as this file.

#include <mudlib.h>

inherit WEAPON ;

void create() {
	set ("id", ({ "axe" }) ) ;
        set ("short", "an iron hand axe");
        set ("long", "An iron hand axe. Previously owned by a guard.\n");
	set ("bulk", 100) ;
	set ("mass", 1000) ;
  set_value(30);
	set ("weapon", 5) ;
	set ("damage", ({ 5, 12 }) ) ;
        set ("nosecond", 0);
        set ("size", 3);
	set ("name", "axe") ;
	set_verbs( ({ "swing at", "chop at", "hack at" }) ) ;
        set_verbs2(({ "swings at", "chops at", "hacks at" }) );
	set ("type", "cutting") ;
  set("size", 9);
}
