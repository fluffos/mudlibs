#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("snake");
  set("id",({"snake","slithering snake","monster"}));
  set_level(13);
  set("short","a slithering snake");
  set("long","The snake wiggles it's tounge as you look it over.");
  set("race","snake");
  if (random(50) > 25)
    set_gender("male");
  else
    set_gender("female");
  set_body_type("snake");
  set("aggressive",11);
}
