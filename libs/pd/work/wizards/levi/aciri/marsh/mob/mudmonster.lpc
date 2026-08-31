#include <std.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("mud monster");
   set_id( ({ "a mud monster", "mud monster", "monster" }) );
   set_short("a hideous mud monster");
   set("aggressive", 150);
  set_level(35);
   set_long("The mud monster is one ugly creature.  It oozes with "
	"mud, constantly trying to pull clumps of itself back together.  "
	"This experience, extremely traumatic and torturing, has pushed "
	"the monster into a highly aggressive state.");
    set_body_type("human");
   set("race", "mud monster");
   if(random(2) == 0) set_gender("male"); else
   set_gender("female");
}

