
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "neo otyugh") ;
	set ("long", "A vile creature which are lurks in heaps of dung and decay,\n"+
	"waiting for something to disturb it.\n") ;
	set ("id", ({ "otyugh", "neo", "neo otyugh"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("mass", 500) ;
    set_name ("neo otyugh") ;
	set ("gender", "male") ;
	set ("race", "neo otyugh");
	enable_commands() ;
   	set_living_name("neo otyugh") ;
	set ("stat/constitution", 22);
	set ("stat/strength", 18);
	set ("base_ac", 0);
	set ("armor_class", 0);
	set("natt",3);
	set ("damage", ({ 2,12 }) ) ;
	set ("weapon_name", "tentacle filled maw") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "smashes at", "chomps on", "swipe at" }) ) ;
	set_level(12);

}
