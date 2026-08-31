#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("glaive");
   set_short("a glaive");
   set_long("The weapon consists of a large blade fixed on the end of "
     "steel pole, whose edge is on the outside a vicious curve. It "
     "resembles, in part, a light lance.");
   set_weight(7);
   set_id(({ "glaive" }));
   set_wc(8);
   set_type("projectile");
   set_value(250);
}

int query_auto_load() {
   if (this_player()->query_level() >= 20) return 0;
}
