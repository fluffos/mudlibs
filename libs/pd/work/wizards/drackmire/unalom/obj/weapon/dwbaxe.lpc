#include <std.h>
inherit WEAPON;
 
void create() {
    ::create();
   set_id(({ "battleaxe", "battleax", "ax", "axe", "dwarven battleaxe" }));
   set_name("dwarven battleaxe");
   set_short("a dwarven battleaxe");
   set_long("A standard issue for dwarven soldiers, this battle axe "
   "features a sturdy steel construction with a short handle and "
   "a double headed blade.");
   set_weight(14);
   set_curr_value("silver", 100);
   set_wc(6);
   set_type("axe");
   }


int query_auto_load() { if (this_player()->query_level() > 30) return 1; }
