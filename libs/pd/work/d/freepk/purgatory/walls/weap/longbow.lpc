#include <std.h>;
#include <castlewall.h>;

inherit WEAPON;

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
  set_type("ranged");
}
int query_auto_load() {
  if (this_player()->query_level() > 30)
  if (this_player()->query_subclass() == "ranger") return 0;
  return 1;
}

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 50) return 0;
   write("This belongs to the %^BOLD%^%^BLACK%^Dark %^WHITE%^Archers%^RESET%^!!");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
