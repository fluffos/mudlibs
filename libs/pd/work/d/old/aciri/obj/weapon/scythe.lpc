#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("scythe");
   set_short("a deadly scythe");
   set_long("The deadly scythe's blade is like that of a knife. The "
     "scythe is a vicious weapon, cutting and gouging at the same "
     "time.");
   set_weight(9);
   set_id(({ "scythe", "deadly scythe" }));
   set_wc(7);
   set_type("knife");
   set_value(160);
}

int query_auto_load() {
   if (this_player()->query_skill("knife") >= 30) return 3;
}
