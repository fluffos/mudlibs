
#include <std.h>

inherit ARMOUR;

object owner;

void setup(object tp, int ac) {
  if (!tp || !ac) return;
  owner=tp;
  set_ac(ac);
}

void create() {
  ::create();
  set_id(({"flesh", "hardened flesh", "wrapping of hardened flesh", "wrapping"}));
  set_name("wrapping of hardened flesh");
  set_weight(6);
  set_curr_value("gold", 0);
  set_type("coat");
  set_limbs( ({ "torso", "head" }) );
  set_short("a wrapping of hardened flesh");
  set_long("This wrapping seems to be made of skin and tendons that have been "
           "magically hardened. It is a little stiff.");
}
