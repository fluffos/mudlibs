#include <std.h>;
#include <shadow.h>;

inherit ARMOUR;

void create() {
  ::create();

  set_name("armour");
  set("id", ({ "armour", "armor", "light armor" }) );
  set("short", "%^BOLD%^%^WHITE%^Light Armour%^RESET%^ of Tenebrae");
  set("long", "This bright armour is emblazoned with the crest of Tenebrae.");
  set_type("armour");
  set_ac(5);
  set_limbs( ({"torso","right arm","left arm"}) );
  set_weight(50);
    set_curr_value("gold", 140);
}

int query_auto_load() {
  if (this_player()->query_level() > 30)
  return 1;
}
