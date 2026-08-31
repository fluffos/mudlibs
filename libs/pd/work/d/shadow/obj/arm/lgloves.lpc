#include <std.h>;
#include <shadow.h>;

inherit ARMOUR;

void create() {
  ::create();

  set_name("gloves");
  set("id", ({ "gloves", "glove", "light gloves" }) );
  set("short", "%^BOLD%^%^WHITE%^Light Gloves%^RESET%^ of Tenebrae");
  set("long", "These gloves are a %^BOLD%^%^WHITE%^bright bleached white%^RESET%^.");
  set_type("gloves");
  set_ac(3);
  set_limbs( ({ "left hand", "right hand" }) );
  set_weight(9);
    set_curr_value("gold", 90);
}

int query_auto_load() {
  if (this_player()->query_level() > 25)
  return 1;
}
