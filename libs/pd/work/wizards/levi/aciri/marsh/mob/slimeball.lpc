#include <std.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("slime ball");
   set_id( ({ "ball", "slime ball" }) );
   set_short("a slime ball");
   set("aggressive", 100);
  set_level(10);
   set_long("The slime ball rolls around the marsh looking for life "
	"to consume.  It is a green ball with slime oozing out of it "
	"constantly.");
    set_body_type("blob");
   set("race", "slime");
   if(random(2) == 0) set_gender("male"); else
   set_gender("female");
}

