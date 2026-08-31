#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("jerkin");
   set_short("a thick leather jerkin");
   set_long("The thick, studded leather jerkin may be one of the best "
     "pieces of leather armour ever made. It was made to protect "
     "someone who's power matters. It was made to protect.");
   set_weight(5);
   set_id(({ "jerkin" }));
   set_ac(6);
   set_type("armour");
   set_value(200);
   set_limbs(({ "torso" }));
}

int query_auto_load() {
   if (this_player()->query_level() >= 20) return 0;
}
