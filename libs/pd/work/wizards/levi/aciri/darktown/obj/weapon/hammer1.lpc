#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("malet");
   set_short("a silver malet");
   set_long("The heavy malet was shaped of an impure type of copper, "
     "greatly lowering it's value. The entire malet is silver, so "
     "it is a fairly good weapon because of it's weight.");
   set_weight(11);
   set_id(({ "malet", "silver malet" }));
   set_wc(5);
   set_type("blunt");
   set_value(150);
}

int query_auto_load() {
   if (this_player()->query_level() >= 15) return 0;
}
