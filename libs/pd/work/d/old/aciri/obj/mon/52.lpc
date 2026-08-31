#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("snake");
   set_short("a giant snake");
   set_long("The snakes monsterous body wraps about itself, in a deadly coil. "
     "It's head is poised upwards, ready to strike it's foe dead. This snake "
     "won't settle for mice, it want you!");
   set_level(46);
   set_id(({ "snake", "giant snake" }));
   set_auto(20);
   set_race("snake");
   set_body_type("snake");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"fangs");
   command("wield fangs");
}
