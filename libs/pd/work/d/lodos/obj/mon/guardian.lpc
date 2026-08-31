#include <std.h>
#include <lodos.h>
inherit MONSTER;

void create() {
 ::create();
   set_short("a huge guardian");
   set_id( ({ "guardian", "huge guardian", "hugo" }) );
   set_name("guardian");
   set_level(34);
   set_long("Hugo guards the northern doorway of the tower. He is "
     "tall, increadibly strong and even for a giant, there is only one "
     "word to describe him: huge. His muscles are probably about three "
     "feet thick.");
   set_body_type("human");
   set_race("giant");
   set_gender("male");
}

int stop_me() {
  write("Hugo shoves you to the ground and scowls.");
  return 1;
}

void init() {
 ::init();
   add_action("stop_me", "north");
}
