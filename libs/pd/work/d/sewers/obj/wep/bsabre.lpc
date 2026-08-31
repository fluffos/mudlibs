#include <std.h>
inherit WEAPON;

void create() {
  ::create();

    set_name("Blessed Sabre");
    set_id( ({ "sword", "blade", "demon blade" }) );
    set_short("%^BOLD%^%^WHITE%^Bles%^YELLOW%^sed Sa%^WHITE%^bre%^RESET%^");
    set_long("This glimmering blade gleams with a pure, holy cleanliness which "
             "a no being of ill repute would use.  The hilt is of a shiny gold "
             " which sparkles in even the dimmest light.");
    set_type("blade");
    set_wc(7);
    set_weight(12);
    set_curr_value("gold", 20+random(30));
}
int query_auto_load() {
  if(this_player()->query_level() >= 32) return 1;
  return 0;
}
