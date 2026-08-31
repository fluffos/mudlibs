#include <std.h>;
#include <shadow.h>;

inherit ARMOUR;

void create() {
  ::create();

  set_name("quiver");
  set("id", ({ "quiver" }) );
  set("short", "Quiver of %^BOLD%^%^WHITE%^Light%^RESET%^");
  set("long", "This quiver is excellent at storing arrows.");
  set_type("quiver");
  set_ac(1);
  set_limbs( ({ "torso" }) );
  set_weight(5);
    set_curr_value("gold", 40);
}

int query_auto_load() {
  if (this_player()->query_level() > 14)
  return 1;
}
