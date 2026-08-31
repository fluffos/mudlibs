#include <std.h>;
#include <purgatory.h>;

inherit BOW;

void create() {
  ::create();

  set("id",({"bow"}));
  set_name("bow");
  set_short("%^BOLD%^%^BLACK%^Dark %^BOLD%^%^WHITE%^Longbow%^RESET%^");
  set("long","This bow was crafted by a master woodsman, taller then a man and very hard to draw. Hence the name of a Longbow.");
  set_weight(20+random(25));
    set_curr_value("gold", 80);
  set_ac(1);
  set_wc(11);
  set_type("projectile");
}
int query_auto_load() {
  if (this_player()->query_level() > 30)
  if (this_player()->query_subclass() == "ranger") return 0;
  return 1;
}
