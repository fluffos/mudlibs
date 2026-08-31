#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("pike");
   set_short("a long pike");
   set_long("The pike has a long, wooden shaft tipped with a metal "
     "spike of some sort. It has the potential to be a deadly weapon "
     "in the right hands.");
   set_weight(6);
   set_id(({ "pike", "long pike" }));
   set_wc(5);
   set_type("projectile");
   set_value(160);
}

int query_auto_load() {
   if (this_player()->query_level() >= 18) return 3;
}
