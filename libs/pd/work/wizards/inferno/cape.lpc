#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_long("A long, white hooded robe.");
   set_short("a long, white robe");
   set_name("robe");
   set_weight(1);
   set_id(({ "robe" }));
   set_value(100);
   set_ac(10);
   set_type("robe");
   set_limbs((string)this_player()->query_limbs());
}

int query_auto_load() { return 1; }
