
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
  set_id(({"skull", "skull helm", "skull helmet", "helmet", "helm"}));
  set_name("skull helmet");
  set_weight(3);
  set_curr_value("gold", 0);
  set_type("helmet");
  set_limbs( ({ "head" }) );
  set_short("a skull helmet");
  set_long("A skull that has been magically altered to fit over one's "
           "head and protect it.");
  set_property("no auction", 1);
}
