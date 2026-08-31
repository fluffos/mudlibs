#include <std.h>;
#include <shadow.h>;

inherit ARMOUR;

void create() {
  ::create();

  set_name("gown");
  set("id", ({ "gown", "dress" }) );
  set("short", "A Gown");
  set("long", "The gown %^BOLD%^%^WHITE%^shimmers%^RESET%^ in the light.");
  set_type("dress");
  set_ac(1);
  set_limbs( ({ "torso" }) );
  set_weight(8);
    set_curr_value("gold", 75);
}

int query_auto_load() {
  if (this_player()->query_level() > 17){
  return 1;}
else return 0;
}
