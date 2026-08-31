#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("Beetle");
  set("id",({"bug","beetle","black beetle","monster"}));
  set_level(11);
  set("short","a %^BOLD%^%^BLACK%^Black %^RESET%^Beetle");
  set("long","The beetle flitters around.");
  set("race","insect");
  if (random(50) > 25)
    set_gender("male");
  else
    set_gender("female");
  set_body_type("insect");
  set("aggressive",10);
}
