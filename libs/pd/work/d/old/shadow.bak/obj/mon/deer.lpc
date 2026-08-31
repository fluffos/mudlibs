#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("deer");
  set("id",({"deer","white tail deer","monster"}));
  set_level(13);
  set("short","white tail deer");
  set("long","A friendly looking deer with a small white tail.");
  set("race","deer");
  if (random(50) > 25)
    set_gender("male");
  else
    set_gender("female");
  set_body_type("deer");
  set("aggressive",8);
}
