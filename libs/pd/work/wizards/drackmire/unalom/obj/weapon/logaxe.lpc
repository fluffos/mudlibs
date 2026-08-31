#include <std.h>
inherit WEAPON;
 
void create() {
    ::create();
   set_id(({ "logging axe", "axe", "ax" }));
   set_name("logging axe");
   set_short("a logging axe");
   set_long("This axe is primarily designed for use in cutting down "
   "trees.  It's long handle and sharp head make it ideal for cutting "
   "thick and hard wood.");
   set_weight(14);
   set_curr_value("silver", 150);
   set_wc(6);
   set_type("axe");
   }


int query_auto_load() { if (this_player()->query_level() > 30) return 1; }
