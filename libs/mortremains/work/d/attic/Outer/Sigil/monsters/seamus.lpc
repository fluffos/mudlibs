
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
   set("short", "Seamus") ;
  set("long", @ENDLONG
Seamusxanthuszenus, more commonly known as Seamus is certainly one of the
oddest looking individuals you've seen in Sigil.  You wouldn't expect
anything less from the propieter of such an unusual store, however.
ENDLONG
  ) ;
	set ("id", ({ "seamusxanthuszenus", "seamus"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 30) ;
        set ("bulk", 25) ;
	set_name ("seamusxanthuszenus") ;
	set ("gender", "male") ;
	enable_commands() ;
	set("race", "mephit");
   	set_living_name("seamus") ;
	set_level(6);
	set("level", 6);
	set("natt", 2);
	set ("thac0", 15);
	set ("damage", ({ 1,6 }) ) ;
	set ("weapon_name", "claws") ;
	set ("damage_type", "slashing");
	set ("CLASS", "warrior");
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	set ("magic_resist", 25);
	set ("resist_type", ([ "slashing" : 50, "piercing" : 50, "fire" : 0 ]) );
	
   	}

