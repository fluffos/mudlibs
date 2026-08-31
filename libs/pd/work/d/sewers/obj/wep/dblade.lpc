#include <std.h>
inherit WEAPON;

void create() {
  ::create();

    set_name("Demon Blade");
    set_id( ({ "sword", "blade", "demon blade" }) );
    set_short("%^BOLD%^%^BLACK%^Dem%^RESET%^%^ORANGE%^on Bl%^BOLD%^%^BLACK%^ade%^RESET%^");
    set_long("The dull black blade never shines, refusing to become clean.  The"
             " silver hilt is in the designs of the flames of the underworld, encrusted"
             " with the occasional glimmering ruby.");
    set_type("blade");
    set_wc(7);
    set_weight(12);
    set_curr_value("gold", 20+random(30));
}
int query_auto_load() {
  if(this_player()->query_level() >= 32) return 1;
  return 0;
}
