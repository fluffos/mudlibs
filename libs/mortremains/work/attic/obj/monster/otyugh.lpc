
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "otyugh") ;
	set ("long", "A vile creature which are lurks in heaps of dung and decay,\n"+
	"waiting for something to disturb it.\n") ;
	set ("id", ({ "otyugh", "it"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("mass", 500) ;
    set_name ("otyugh") ;
	set ("gender", "male") ;
	set ("race", "otyugh");
	enable_commands() ;
   	set_living_name("otyugh") ;
	set ("stat/constitution", 20);
	set ("stat/strength", 16);
	set ("base_ac", 3);
	set ("armor_class", 3);
	set("natt",3);
	set ("damage", ({ 1,8 }) ) ;
	set ("weapon_name", "tentacle filled maw") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "smashes at", "chomps on", "swipe at" }) ) ;
	set_level(8);

}
