#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_short("a mutilated corpse");
   set_name("corpse");
   set_long("The corpse has been brutally stabbed and cut up pretty "
      "bad.");
   set_weight(1);
   set_value(0);
   set_id(({ "corpse", "mutilated corpse" }));
   set_prevent_get("You wouldn't touch it.");
}

int get() { return 0; }

int is_corpse() { return 1; }

int query_corpse() { return 1; }
