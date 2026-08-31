#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("servant");
   set_short("a servant of the night");
   set_long("A creature of elemental impurity, the servant of the night was "
     "created from the evil of the tower. With a human visage, yet no soul, "
     "the servant lingers within the tower with glee over its victims.");
   set_level(37);
   set_id(({ "servant", "servant of the night" }));
   set_auto(0);
   set_race("human");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"thorns");
   command("wear all");
}
