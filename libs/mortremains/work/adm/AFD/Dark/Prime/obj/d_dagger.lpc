// dagger.c
// An example weapon. It is an acceptable second weapon, so it sets its
// "second" property to 1. For full comments on weapon properties, see
// sword.c which should be in the same directory as this file.

#include <mudlib.h>

inherit WEAPON ;

void create() {
	set ("id", ({ "dagger" }) ) ;
	set ("short", "a wicked dagger") ;
        set ("long", "This is a short, but nasty-looking dagger.\n");
	set ("mass", 20) ;
	set ("bulk", 10) ;
 set_value(100) ;
	set ("weapon", 2) ;
	set ("name", "dagger") ;
	set ("second", 1) ;
	set ("damage", ({ 1, 4 }) ) ;
 set_type("cutting") ;
 set_verbs( ({ "stab at", "lunge at", "attack", "cut at" }) ) ;
  set("size", 3) ;
}
