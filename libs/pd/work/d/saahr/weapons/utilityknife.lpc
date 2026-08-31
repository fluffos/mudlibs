
#include <std.h>

inherit WEAPON;

void create() {
  ::create();
  set_name("utility knife");
  set_id(({"knife","utility knife"}));
  set_short("a utility knife");
  set_long("The handle of the knife looks as if it was whittled "
           "not too long ago. It is mostly smooth, with a rich "
	   "brown color and interspersed lighter stripes. The blade "
	   "is very sharp and large enough to cut and clean just "
	   "about anything a person could catch.");
  set_weight(8);
  set_curr_value("gold", 30+random(11));
  set_wc(9);
  set_type("knife");
}

int query_auto_load() { return 1; }
