
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
  set_id(({"bones", "bone shield", "shield of bones", "shield"}));
  set_name("shield of bones");
  set_weight(14);
  set_curr_value("gold", 0);
  set_type("shield");
  set_limbs( ({ "torso", "left arm", "right arm" }) );
  set_short("a shield of bones");
  set_long("The shield is made of many different bones arranged in a rough "
           "squarish shape.");
  set_property("no auction", 1);
}

int move(mixed dest) {
  if (objectp(dest) && living(dest)) {
    switch (dest->query_race()) {
      case "raknid":
        set_limbs(({"torso","first arm","second arm"}));
      break;
      default:
        set_limbs(({"torso","left arm","right arm"}));
    }
  }
  return ::move(dest);
}

