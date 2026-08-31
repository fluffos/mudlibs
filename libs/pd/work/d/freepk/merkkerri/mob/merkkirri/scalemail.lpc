#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("armor");
set_short("%^BOLD%^%^GREEN%^S%^RESET%^%^GREEN%^cale%^BOLD%^%^GREEN%^M%^RESET%^%^GREEN%^ail%^RESET%^ Armor%^RESET%^");
set_long("A finely crafted suit of scales that is a bit heavy but offers great protection to most of the body.");
set_id(({"armor", "armour", "scalemail", "scalemail armor"}));
set_ac(9);
set_weight(90);
set_curr_value("gold",125);
set_type("armour");
set_limbs(({"torso", "left arm", "right arm", "left leg", "right leg"}));
}
int query_auto_load() {
  if(this_player()->query_level() > 25) return 1;
  return 0;
}
