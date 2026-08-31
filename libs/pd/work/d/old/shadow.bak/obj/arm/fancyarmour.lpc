#include <std.h>;
#include <shadow.h>;

inherit ARMOUR;

void create() {
  ::create();

  set_name("Fancy Armour");
  set("id", ({ "armor", "armour", "fancy armour" }) );
  set("short", "Fancy Armour");
  set("long", "The stones on the armour reflect the light in small beams, creating a disco ball effect.");
  set_type("armor");
  set_ac(6);
  set_limbs( ({"torso","left arm", "right arm"}) );
  set_weight(70);
    set_curr_value("gold", 140);
}

int query_auto_load() {
  if (this_player()->query_level() > 30)
  return 1;
}
