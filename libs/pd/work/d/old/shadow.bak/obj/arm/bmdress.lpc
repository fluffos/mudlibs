#include <std.h>;
#include <shadow.h>;

inherit ARMOUR;

void create() {
  ::create();

  set_name("dress");
  set("id", ({ "dress", "bridesmaid dress", "gown" }) );
  set("short", "Bride's Maid %^YELLOW%^Dress%^RESET%^");
  set("long", "It fits snugly, and is rather low cut.  It is quite alluring, and adds to any figure.");
  set_type("armor");
  set_ac(4);
  set_limbs( ({ "torso" }) );
  set_weight(9);
    set_curr_value("gold", 60);
}

int query_auto_load() {
  if (this_player()->query_level() > 10)
  return 1;
}
