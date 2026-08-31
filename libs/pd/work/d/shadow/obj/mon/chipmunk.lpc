#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("chipmunk");
  set("id",({"chipmunk","small chipmunk","monster"}));
  set_level(12);
  set("short","a small chipmunk");
  set("long","A qute looking chipmunk with stuffed cheeks.");
  set("race","chipmunk");
  if (random(50) > 25)
    set_gender("male");
  else
    set_gender("female");
  set_body_type("feline");
  set("aggressive",6);
}
