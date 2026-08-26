
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	::create() ;
	seteuid(getuid()) ;
	set ("short", "THE King") ;
set("long", @Long
  Before you stands a big and muscular king.  He has a frown
that seems a bit out of place.  You don't know why but you start
to feel sorry for him.
@Long
   );
      set("id", "king");
	set_name ("King") ;
	set ("gender", "male") ;
	set ("race", "human");
	enable_commands() ;
   	set_living_name("king") ;
	set ("damage", ({ 2,20 }) ) ;
	set_verbs( ({ "pummel on", "swing at", "swipe at" }) ) ;
	set ("weap_resist", 2);
	set_level(12);
}
