// This was using the 'old' style, most of which has been changed
// quite a bit. I modernized this code and copied the old file
// to blackdog.old
//  Cyanide - 7 July 2000

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "shya");
    set("short", "Barnaby");
    set ("long",
      wrap("Barnaby is only a puppy, but a mean one. His brown eyes "+
	"pin you to the wall with his growl."));
    set("id", ({ "dog", "black dog", "barnaby" }) );
    set("race", "dog");
    set_name("Barnaby");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("Barnaby");
    set ("aggressive", 2 );
    set_alignment("evil");
    set ("damage", ({6,8}) ) ;
    set("weapon_name", "teeth");
    set ("stat/strength", 15) ;
    set_verbs( ({ "slash at", "lunge at", "swipe at" }) ) ;
    set ("moving", 1) ;
    set ("speed", 8) ;
    set_level(8);
}
