
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Morvun") ;
	set ("long", "A Bleaknik Ar-tist.\n") ;
	set ("id", ({ "morvun", "fensir"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("morvun") ;
	set ("gender", "male") ;
	set ("race", "fensir");
	enable_commands() ;
   	set_living_name("morvun") ;
	set_level(4);
	set("level", 4);
	set("natt", 2);
	set ("thac0", 17);
	set ("base_ac", 7);
	set ("armor_class", 7);
	set ("damage", ({ 1,6 }) ) ;
	set ("weapon_name", "stony fists") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;

}
